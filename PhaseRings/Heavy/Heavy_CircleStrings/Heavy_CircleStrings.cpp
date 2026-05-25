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
  numBytes += sTabread_init(&sTabread_JSK4IKt8, &hTable_PGxZkRq1, true);
  numBytes += sRPole_init(&sRPole_UwYDMQbB);
  numBytes += sLine_init(&sLine_VicTFzL3);
  numBytes += sTabwrite_init(&sTabwrite_maoto4bW, &hTable_PGxZkRq1);
  numBytes += sLine_init(&sLine_W66TbSEA);
  numBytes += sLine_init(&sLine_hGytK1rW);
  numBytes += sLine_init(&sLine_bUJ0KEq2);
  numBytes += sPhasor_k_init(&sPhasor_o2Vo770j, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_r0pAWIsr);
  numBytes += sTabread_init(&sTabread_IpnSBpqv, &hTable_HcXuXSOk, true);
  numBytes += sRPole_init(&sRPole_rRZ935iv);
  numBytes += sLine_init(&sLine_AbMquuSV);
  numBytes += sTabwrite_init(&sTabwrite_thDVVsNa, &hTable_HcXuXSOk);
  numBytes += sLine_init(&sLine_DZNhnwOk);
  numBytes += sLine_init(&sLine_MSkv0IgG);
  numBytes += sLine_init(&sLine_n6BDuCJz);
  numBytes += sPhasor_k_init(&sPhasor_W6DHDMHs, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_3Albz6Ft);
  numBytes += sTabread_init(&sTabread_uGZ4KzVj, &hTable_pvpd4J9a, true);
  numBytes += sRPole_init(&sRPole_36FaZwky);
  numBytes += sLine_init(&sLine_jZFy9ZEb);
  numBytes += sTabwrite_init(&sTabwrite_AwXOSOOS, &hTable_pvpd4J9a);
  numBytes += sLine_init(&sLine_Nsluba0W);
  numBytes += sLine_init(&sLine_bIYsxWWc);
  numBytes += sLine_init(&sLine_A0Mqvzya);
  numBytes += sPhasor_k_init(&sPhasor_MdzInlKa, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_2vOArhQj);
  numBytes += sTabread_init(&sTabread_CdfGyxk0, &hTable_DCGCrjpW, true);
  numBytes += sRPole_init(&sRPole_i9lBhpTM);
  numBytes += sLine_init(&sLine_wNRRhgUU);
  numBytes += sTabwrite_init(&sTabwrite_9NtayjcT, &hTable_DCGCrjpW);
  numBytes += sLine_init(&sLine_AFw14lx8);
  numBytes += sLine_init(&sLine_Yo1naduW);
  numBytes += sLine_init(&sLine_RDBwfT6n);
  numBytes += sPhasor_k_init(&sPhasor_FXaTQbAM, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_sHaLLgCs);
  numBytes += sLine_init(&sLine_kHpzps7D);
  numBytes += sTabread_init(&sTabread_oA8UdyFZ, &hTable_zHYNTfQ2, true);
  numBytes += sRPole_init(&sRPole_BtZSQn8L);
  numBytes += sLine_init(&sLine_C56762ew);
  numBytes += sTabwrite_init(&sTabwrite_LHhSYrvr, &hTable_zHYNTfQ2);
  numBytes += sLine_init(&sLine_9eiuNI4J);
  numBytes += sLine_init(&sLine_pGUo3l3A);
  numBytes += sRPole_init(&sRPole_kx9fY67c);
  numBytes += sDel1_init(&sDel1_Jb9Ff3zq);
  numBytes += sLine_init(&sLine_XDSWxmry);
  numBytes += sLine_init(&sLine_4dQbVpWx);
  numBytes += sLine_init(&sLine_Fpyw1Bul);
  numBytes += sTabread_init(&sTabread_vF8jA4oT, &hTable_Ohm0hokt, true);
  numBytes += sRPole_init(&sRPole_VLlNANUn);
  numBytes += sLine_init(&sLine_RSnnUeg9);
  numBytes += sLine_init(&sLine_LdjwLzWr);
  numBytes += sTabread_init(&sTabread_s9frQrjK, &hTable_4q4El3xx, true);
  numBytes += sTabread_init(&sTabread_UaTcgfZJ, &hTable_R5Orrj0z, true);
  numBytes += sTabread_init(&sTabread_bHt6HYwn, &hTable_jE20V2t5, true);
  numBytes += sTabread_init(&sTabread_Yyf3yfZY, &hTable_ys24awdF, true);
  numBytes += sTabread_init(&sTabread_9yNExyvS, &hTable_gsDd3hqv, true);
  numBytes += sTabwrite_init(&sTabwrite_J5xvzRJl, &hTable_JVMiFZGC);
  numBytes += sTabwrite_init(&sTabwrite_h1URavD2, &hTable_gsDd3hqv);
  numBytes += sTabwrite_init(&sTabwrite_7Lft8yI6, &hTable_ys24awdF);
  numBytes += sTabwrite_init(&sTabwrite_d4L2GaBr, &hTable_jE20V2t5);
  numBytes += sTabwrite_init(&sTabwrite_PKgvwBUX, &hTable_R5Orrj0z);
  numBytes += sTabwrite_init(&sTabwrite_Wj6AdG4V, &hTable_4q4El3xx);
  numBytes += sTabread_init(&sTabread_x09EXuAJ, &hTable_JVMiFZGC, true);
  numBytes += sTabread_init(&sTabread_7on1nhss, &hTable_UpKUZgJo, true);
  numBytes += sRPole_init(&sRPole_GpoHkWPi);
  numBytes += sTabread_init(&sTabread_eNfWaxkU, &hTable_RVmx7Zx7, true);
  numBytes += sRPole_init(&sRPole_Ivz0dYXp);
  numBytes += sTabread_init(&sTabread_BTfVSBtQ, &hTable_MOC6tDsa, true);
  numBytes += sRPole_init(&sRPole_FVm3BBn6);
  numBytes += sTabwrite_init(&sTabwrite_PKySz5yC, &hTable_Ohm0hokt);
  numBytes += sTabwrite_init(&sTabwrite_Xy0HUy0H, &hTable_UpKUZgJo);
  numBytes += sTabwrite_init(&sTabwrite_hefPizER, &hTable_RVmx7Zx7);
  numBytes += sTabwrite_init(&sTabwrite_Y1R9JQ77, &hTable_MOC6tDsa);
  numBytes += sLine_init(&sLine_MeGrBbyJ);
  numBytes += sLine_init(&sLine_u9S7JWC0);
  numBytes += sTabwrite_init(&sTabwrite_g7lKG4ma, &hTable_xtoVBvL3);
  numBytes += sLine_init(&sLine_N4B165GY);
  numBytes += sPhasor_init(&sPhasor_2L12jo48, sampleRate);
  numBytes += sLine_init(&sLine_FOuZgC9t);
  numBytes += sLine_init(&sLine_WhvUAi9Y);
  numBytes += sTabhead_init(&sTabhead_d7yvsakr, &hTable_xtoVBvL3);
  numBytes += sTabread_init(&sTabread_wvJ9cIQx, &hTable_xtoVBvL3, false);
  numBytes += sTabread_init(&sTabread_K2qPC7oE, &hTable_xtoVBvL3, false);
  numBytes += sTabhead_init(&sTabhead_P2uCfiAW, &hTable_xtoVBvL3);
  numBytes += sTabread_init(&sTabread_J16CaHbV, &hTable_xtoVBvL3, false);
  numBytes += sTabread_init(&sTabread_tpwO3wmW, &hTable_xtoVBvL3, false);
  numBytes += sTabhead_init(&sTabhead_TbmsB1q1, &hTable_II1ikMgh);
  numBytes += sTabread_init(&sTabread_TN963iyn, &hTable_II1ikMgh, false);
  numBytes += sTabread_init(&sTabread_66aBnkDc, &hTable_II1ikMgh, false);
  numBytes += sRPole_init(&sRPole_56yxhRwk);
  numBytes += sDel1_init(&sDel1_xTm9adan);
  numBytes += sLine_init(&sLine_TWR4wN7V);
  numBytes += sRPole_init(&sRPole_Wr8Ci93t);
  numBytes += sTabwrite_init(&sTabwrite_zyInRbYq, &hTable_II1ikMgh);
  numBytes += sCPole_init(&sCPole_siFGCWQQ);
  numBytes += sRPole_init(&sRPole_cSwtbMzV);
  numBytes += sRPole_init(&sRPole_oetr6OTz);
  numBytes += sRPole_init(&sRPole_lMQUzRo1);
  numBytes += sTabread_init(&sTabread_u9PkanES, &hTable_N1Do4ZF4, true);
  numBytes += sRPole_init(&sRPole_XQyBeZlK);
  numBytes += sLine_init(&sLine_N6p4nVym);
  numBytes += sLine_init(&sLine_uebfVKhu);
  numBytes += sTabread_init(&sTabread_OJZ4H1g2, &hTable_jrFYetRt, true);
  numBytes += sTabread_init(&sTabread_cQkiSUwi, &hTable_yhmdKCjm, true);
  numBytes += sTabread_init(&sTabread_8Nidq2pQ, &hTable_NQMvacjK, true);
  numBytes += sTabread_init(&sTabread_WPhyFpth, &hTable_1IyPiLjw, true);
  numBytes += sTabread_init(&sTabread_Phlx229A, &hTable_TF9cUA1F, true);
  numBytes += sTabwrite_init(&sTabwrite_e4MtuBhD, &hTable_gdqDQNUs);
  numBytes += sTabwrite_init(&sTabwrite_oniTGu3h, &hTable_TF9cUA1F);
  numBytes += sTabwrite_init(&sTabwrite_e6ok9I4D, &hTable_1IyPiLjw);
  numBytes += sTabwrite_init(&sTabwrite_p5nKzR9R, &hTable_NQMvacjK);
  numBytes += sTabwrite_init(&sTabwrite_TneWhgkR, &hTable_yhmdKCjm);
  numBytes += sTabwrite_init(&sTabwrite_XPR4i9p7, &hTable_jrFYetRt);
  numBytes += sTabread_init(&sTabread_YG5PfQtP, &hTable_gdqDQNUs, true);
  numBytes += sTabread_init(&sTabread_noZSmxnG, &hTable_Yvxcqs7Z, true);
  numBytes += sRPole_init(&sRPole_sPlK1kFf);
  numBytes += sTabread_init(&sTabread_HweGePPZ, &hTable_w1FkbIwz, true);
  numBytes += sRPole_init(&sRPole_pjagcIN8);
  numBytes += sTabread_init(&sTabread_zv0NvSj1, &hTable_H7TQt9AK, true);
  numBytes += sRPole_init(&sRPole_6BPIL5Oz);
  numBytes += sTabwrite_init(&sTabwrite_uKt61kn1, &hTable_N1Do4ZF4);
  numBytes += sTabwrite_init(&sTabwrite_u9SfTECT, &hTable_Yvxcqs7Z);
  numBytes += sTabwrite_init(&sTabwrite_OPnP2c62, &hTable_w1FkbIwz);
  numBytes += sTabwrite_init(&sTabwrite_THYJzW9h, &hTable_H7TQt9AK);
  numBytes += sLine_init(&sLine_LA7KpQ16);
  numBytes += sLine_init(&sLine_xIYrVkH7);
  numBytes += sTabwrite_init(&sTabwrite_fWWz3GnM, &hTable_rFdRAEVz);
  numBytes += sLine_init(&sLine_4rSQg1y0);
  numBytes += sPhasor_init(&sPhasor_1xI7Ukfi, sampleRate);
  numBytes += sLine_init(&sLine_6AysHDid);
  numBytes += sLine_init(&sLine_RcxqwAGM);
  numBytes += sTabhead_init(&sTabhead_emTROHNu, &hTable_rFdRAEVz);
  numBytes += sTabread_init(&sTabread_6xPqzE1X, &hTable_rFdRAEVz, false);
  numBytes += sTabread_init(&sTabread_GYgyLzej, &hTable_rFdRAEVz, false);
  numBytes += sTabhead_init(&sTabhead_tHwFUGAi, &hTable_rFdRAEVz);
  numBytes += sTabread_init(&sTabread_kXDcDMcF, &hTable_rFdRAEVz, false);
  numBytes += sTabread_init(&sTabread_VSAqjMpt, &hTable_rFdRAEVz, false);
  numBytes += sTabhead_init(&sTabhead_GzuvpdU8, &hTable_4zsVnGpw);
  numBytes += sTabread_init(&sTabread_aAcnRmjP, &hTable_4zsVnGpw, false);
  numBytes += sTabread_init(&sTabread_8tUVx4sf, &hTable_4zsVnGpw, false);
  numBytes += sRPole_init(&sRPole_gsiAptgh);
  numBytes += sDel1_init(&sDel1_saf2yALZ);
  numBytes += sLine_init(&sLine_oL3VrOOc);
  numBytes += sRPole_init(&sRPole_5ycQ8Lm8);
  numBytes += sTabwrite_init(&sTabwrite_oFIjphYF, &hTable_4zsVnGpw);
  numBytes += sLine_init(&sLine_2faw2Ms7);
  numBytes += sLine_init(&sLine_lXKOU52A);
  numBytes += cSlice_init(&cSlice_oztOtzI7, 2, 1);
  numBytes += cSlice_init(&cSlice_ygW4IiFR, 1, 1);
  numBytes += cSlice_init(&cSlice_xzOhFdSU, 0, 1);
  numBytes += cVar_init_f(&cVar_mnsDYdLi, 0.0f);
  numBytes += cIf_init(&cIf_z8OJrArv, false);
  numBytes += cIf_init(&cIf_6dTQvQAK, false);
  numBytes += cIf_init(&cIf_F3hn9SFm, false);
  numBytes += cIf_init(&cIf_WEiwESCo, false);
  numBytes += cIf_init(&cIf_Ldi4JImE, false);
  numBytes += cBinop_init(&cBinop_AXhW9KuH, 0.0f); // __eq
  numBytes += cTabhead_init(&cTabhead_OhETtZ3C, &hTable_Ohm0hokt);
  numBytes += cVar_init_s(&cVar_bfjrYQig, "del-1011-del1");
  numBytes += cDelay_init(this, &cDelay_Jb4NlA2J, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_Cx3cyPKl, 0.0f);
  numBytes += cBinop_init(&cBinop_FWnQVq2M, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_5pKV81vI, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_TLSvdI6E, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_gXLTwrl7, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_wPpYvZtI, &hTable_UpKUZgJo);
  numBytes += cVar_init_s(&cVar_v4AbJkKd, "del-1011-del2");
  numBytes += cDelay_init(this, &cDelay_5Ym7uWrg, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_y73UItuY, 0.0f);
  numBytes += cBinop_init(&cBinop_5eloesaw, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_AW2FiSyn, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_e1v5WZrN, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_r9CPMA8B, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_3LptR8uW, &hTable_RVmx7Zx7);
  numBytes += cVar_init_s(&cVar_ugZC1k5a, "del-1011-del3");
  numBytes += cDelay_init(this, &cDelay_IHkrPC3i, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_4zIILafd, 0.0f);
  numBytes += cBinop_init(&cBinop_iyTuJsrF, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_lkWomSgj, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3XamnOSF, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_kHLd8Fvu, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_HzoAA5Zg, &hTable_MOC6tDsa);
  numBytes += cVar_init_s(&cVar_qOLfHs8M, "del-1011-del4");
  numBytes += cDelay_init(this, &cDelay_i5q2Hhzi, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_pTuCtuGG, 0.0f);
  numBytes += cBinop_init(&cBinop_SLZXL74w, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_CpxspCjp, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_XjDJugAH, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_4KslX7i0, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_mB2dl1c0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_jh9lvbMz, 0.0f);
  numBytes += hTable_init(&hTable_Ohm0hokt, 256);
  numBytes += cDelay_init(this, &cDelay_nrVLLlY1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_m8wCPrl9, 0.0f);
  numBytes += hTable_init(&hTable_UpKUZgJo, 256);
  numBytes += cDelay_init(this, &cDelay_2r077o5M, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2d1L75dl, 0.0f);
  numBytes += hTable_init(&hTable_RVmx7Zx7, 256);
  numBytes += cDelay_init(this, &cDelay_n49qp1mH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UhjjQJZy, 0.0f);
  numBytes += hTable_init(&hTable_MOC6tDsa, 256);
  numBytes += cIf_init(&cIf_UBXFCR4l, false);
  numBytes += cBinop_init(&cBinop_Fz7vCqYU, 0.0f); // __pow
  numBytes += cPack_init(&cPack_tRfDYkVG, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_FTTsOLAf, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_3tS9eshW, 22050.0f);
  numBytes += cBinop_init(&cBinop_ag66imTS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_MW6AEA72, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pRf6uupF, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mFUQuxBp, 95.0f);
  numBytes += cVar_init_f(&cVar_aMck80M5, 90.0f);
  numBytes += cVar_init_f(&cVar_fkA3ZK9h, 6000.0f);
  numBytes += cVar_init_f(&cVar_mlcYFQEB, 60.0f);
  numBytes += cIf_init(&cIf_NRY4IS4w, false);
  numBytes += cTabhead_init(&cTabhead_IPGyyXtZ, &hTable_JVMiFZGC);
  numBytes += cVar_init_s(&cVar_F7BxyhZW, "del-1011-ref6");
  numBytes += cDelay_init(this, &cDelay_WPia0yT2, 13.645f);
  numBytes += cDelay_init(this, &cDelay_1iETFbXc, 0.0f);
  numBytes += cBinop_init(&cBinop_lqHH5Kan, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_PBR2MlFZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_rDfRyEft, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_iWn7CzHu, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_sop3yjxG, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Agcuxfqm, 0.0f);
  numBytes += hTable_init(&hTable_JVMiFZGC, 256);
  numBytes += cTabhead_init(&cTabhead_YCr8qba4, &hTable_gsDd3hqv);
  numBytes += cVar_init_s(&cVar_JAVoiuNw, "del-1011-ref5");
  numBytes += cDelay_init(this, &cDelay_hnV09xUp, 16.364f);
  numBytes += cDelay_init(this, &cDelay_cBauw0wQ, 0.0f);
  numBytes += cBinop_init(&cBinop_5bob6RNC, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_0p7KdTJw, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NvtFRbNM, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_LnHaCvOe, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_DdpaYfRB, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DjN7YO7J, 0.0f);
  numBytes += hTable_init(&hTable_gsDd3hqv, 256);
  numBytes += cTabhead_init(&cTabhead_A9nNmf3d, &hTable_ys24awdF);
  numBytes += cVar_init_s(&cVar_FtSLFjCT, "del-1011-ref4");
  numBytes += cDelay_init(this, &cDelay_q4J09Ty1, 19.392f);
  numBytes += cDelay_init(this, &cDelay_07r6V6pB, 0.0f);
  numBytes += cBinop_init(&cBinop_LblE0XCJ, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_j2PrqYDP, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_wB2WAWtP, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_U9UhS71i, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_wALcQ2bu, 0.0f);
  numBytes += cDelay_init(this, &cDelay_dErD2F63, 0.0f);
  numBytes += hTable_init(&hTable_ys24awdF, 256);
  numBytes += cTabhead_init(&cTabhead_gVYNU4CM, &hTable_jE20V2t5);
  numBytes += cVar_init_s(&cVar_Cx09uEGP, "del-1011-ref3");
  numBytes += cDelay_init(this, &cDelay_BVpmswiW, 25.796f);
  numBytes += cDelay_init(this, &cDelay_V2jNJ22k, 0.0f);
  numBytes += cBinop_init(&cBinop_vqqbLitF, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_8hCOX65E, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_OexIOzk3, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_6N69gnjm, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_EofgqkqE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Sp6WEEsU, 0.0f);
  numBytes += hTable_init(&hTable_jE20V2t5, 256);
  numBytes += cTabhead_init(&cTabhead_tjCiFHQd, &hTable_R5Orrj0z);
  numBytes += cVar_init_s(&cVar_TfXe9wyE, "del-1011-ref2");
  numBytes += cDelay_init(this, &cDelay_nGJGMQUA, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_fxaHI9Ad, 0.0f);
  numBytes += cBinop_init(&cBinop_KKlFYf5D, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_SegciK1p, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_s96r2QbU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_lA7Eb9yb, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_l04AykXk, 0.0f);
  numBytes += cDelay_init(this, &cDelay_mP4RKVHl, 0.0f);
  numBytes += hTable_init(&hTable_R5Orrj0z, 256);
  numBytes += cTabhead_init(&cTabhead_IPLmjjI5, &hTable_4q4El3xx);
  numBytes += cVar_init_s(&cVar_drspUFZO, "del-1011-ref1");
  numBytes += cDelay_init(this, &cDelay_Ba8N8kQ9, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_NVNRHviJ, 0.0f);
  numBytes += cBinop_init(&cBinop_kgLHvzfo, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_hq3tcvRi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_EkMkGU9g, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_tJOwuC6Z, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_oTzS0hhX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_m6WgKhtg, 0.0f);
  numBytes += hTable_init(&hTable_4q4El3xx, 256);
  numBytes += cVar_init_f(&cVar_xY3fWPIa, 0.0f);
  numBytes += cVar_init_f(&cVar_VhRPU3sy, 0.0f);
  numBytes += cPack_init(&cPack_qJNt1E2j, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_xO0rjc0C, 22050.0f);
  numBytes += cBinop_init(&cBinop_XFJ6fcEx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_yTULe0gK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ry63o3TX, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_rBhchbRu, 22050.0f);
  numBytes += cBinop_init(&cBinop_Nmwfxwk8, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_sQJ8VEya, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VVnOKafp, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_AYY8j1VC, 22050.0f);
  numBytes += cBinop_init(&cBinop_IewrL0YV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_acJo6RJ9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_45mK77DY, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_B6y403k3, false);
  numBytes += cDelay_init(this, &cDelay_CzJ1AVkE, 50.0f);
  numBytes += cVar_init_f(&cVar_KhhfLswt, 0.0f);
  numBytes += cVar_init_f(&cVar_ew5o4KWg, 12.0f);
  numBytes += cVar_init_s(&cVar_c212H3Ru, "floatatom");
  numBytes += cPack_init(&cPack_r728iCDn, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_FhtpVoZR, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_6J8CuTNX, "floatatom");
  numBytes += cDelay_init(this, &cDelay_tMy2rirt, 0.0f);
  numBytes += cDelay_init(this, &cDelay_w8Ma3rzQ, 0.0f);
  numBytes += hTable_init(&hTable_xtoVBvL3, 256);
  numBytes += cVar_init_s(&cVar_pGGQCzXC, "del-1118-del");
  numBytes += sVarf_init(&sVarf_pX6aonFn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OjSCSR0W, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7rVpbpeH, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Bz5xCYnV, "del-1118-del");
  numBytes += sVarf_init(&sVarf_Eb7r8I2G, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WaVofjBH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xF1lIzpJ, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_ZAZzjtH2, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_dZzjUefw, 4720.0f);
  numBytes += cBinop_init(&cBinop_3ggdAoBO, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_IDfDOAl2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_I4HtKDfe, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_uni0ffev, 4720.0f);
  numBytes += cBinop_init(&cBinop_muW5ZF2F, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_B83GtxXR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_640hQgGR, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8ldKbgG6, 4720.0f);
  numBytes += cBinop_init(&cBinop_hbcWRZuA, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_cUZcUXq3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yJswFEqk, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kHQ6wZvL, 1.0f);
  numBytes += cIf_init(&cIf_kmnw9Acd, false);
  numBytes += sVarf_init(&sVarf_mbwGlwt0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cttibhUr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aWWNuf6l, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NBL5jg2d, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PeUIbHJS, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_yDHNe3QP, &hTable_N1Do4ZF4);
  numBytes += cVar_init_s(&cVar_PYIAUgPj, "del-1181-del1");
  numBytes += cDelay_init(this, &cDelay_n6F9MdPF, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_eoRqhbMW, 0.0f);
  numBytes += cBinop_init(&cBinop_VtKxXHzf, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_0qZpVV8I, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_52s5yh2V, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_DM8B4maE, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_TiloUlwC, &hTable_Yvxcqs7Z);
  numBytes += cVar_init_s(&cVar_G1CGkE0p, "del-1181-del2");
  numBytes += cDelay_init(this, &cDelay_mxH2gEtw, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_BrkOseAe, 0.0f);
  numBytes += cBinop_init(&cBinop_WujZvpnz, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_y9dT7IGn, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_smVayDGV, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Jzvwj1c4, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_D1u9waqI, &hTable_w1FkbIwz);
  numBytes += cVar_init_s(&cVar_id8JNbCJ, "del-1181-del3");
  numBytes += cDelay_init(this, &cDelay_OLsjew0m, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_RFP6K0wq, 0.0f);
  numBytes += cBinop_init(&cBinop_rllv9EJd, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_WWXbdsjV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Ay84sB9N, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_KEf0oS4S, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_bkYjbYhY, &hTable_H7TQt9AK);
  numBytes += cVar_init_s(&cVar_1BhP2wXc, "del-1181-del4");
  numBytes += cDelay_init(this, &cDelay_YWgCIpwG, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_eGHasjS0, 0.0f);
  numBytes += cBinop_init(&cBinop_woP4cBPB, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_zp1pfoC9, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eQU9ReCE, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_IaqQvTpi, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Ir0Def7e, 0.0f);
  numBytes += cDelay_init(this, &cDelay_y4uuSRse, 0.0f);
  numBytes += hTable_init(&hTable_N1Do4ZF4, 256);
  numBytes += cDelay_init(this, &cDelay_VyrAnkCE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UQzFzsnO, 0.0f);
  numBytes += hTable_init(&hTable_Yvxcqs7Z, 256);
  numBytes += cDelay_init(this, &cDelay_vqdJtCom, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gtVaTb7r, 0.0f);
  numBytes += hTable_init(&hTable_w1FkbIwz, 256);
  numBytes += cDelay_init(this, &cDelay_eliVQO3r, 0.0f);
  numBytes += cDelay_init(this, &cDelay_NWU7TDXx, 0.0f);
  numBytes += hTable_init(&hTable_H7TQt9AK, 256);
  numBytes += cIf_init(&cIf_s7odA0a3, false);
  numBytes += cBinop_init(&cBinop_QjzC0ND9, 0.0f); // __pow
  numBytes += cPack_init(&cPack_naduErNi, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_U7XV9pWd, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_YVCceG8T, 22050.0f);
  numBytes += cBinop_init(&cBinop_9KnJcpdm, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_TyscVM2J, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_H75rthim, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_jV4rJmGT, 100.0f);
  numBytes += cVar_init_f(&cVar_gx5SzHcF, 95.0f);
  numBytes += cVar_init_f(&cVar_vx5Lx6GN, 14400.0f);
  numBytes += cVar_init_f(&cVar_iWK6SRJ1, 60.0f);
  numBytes += cIf_init(&cIf_Y4Oa88sh, false);
  numBytes += cTabhead_init(&cTabhead_NpzO6w9n, &hTable_gdqDQNUs);
  numBytes += cVar_init_s(&cVar_qqNayhTq, "del-1181-ref6");
  numBytes += cDelay_init(this, &cDelay_WrzryUgo, 13.645f);
  numBytes += cDelay_init(this, &cDelay_U9IdfXGK, 0.0f);
  numBytes += cBinop_init(&cBinop_LMtPTvu2, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_LzqTeeiA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9SLX6CgC, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_I0dbLQYn, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_xza53Mzx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kYq1fPwB, 0.0f);
  numBytes += hTable_init(&hTable_gdqDQNUs, 256);
  numBytes += cTabhead_init(&cTabhead_Pyt1uMVH, &hTable_TF9cUA1F);
  numBytes += cVar_init_s(&cVar_7PWK4b2c, "del-1181-ref5");
  numBytes += cDelay_init(this, &cDelay_a6pivUz4, 16.364f);
  numBytes += cDelay_init(this, &cDelay_kUqTwINy, 0.0f);
  numBytes += cBinop_init(&cBinop_Hb87fLhE, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_295DO3qE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ketOeagw, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_2fiviAJO, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_jw5vHr48, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1LrkWNj9, 0.0f);
  numBytes += hTable_init(&hTable_TF9cUA1F, 256);
  numBytes += cTabhead_init(&cTabhead_nDd37fCv, &hTable_1IyPiLjw);
  numBytes += cVar_init_s(&cVar_feRkohwo, "del-1181-ref4");
  numBytes += cDelay_init(this, &cDelay_Fdcw98hE, 19.392f);
  numBytes += cDelay_init(this, &cDelay_BuG9lf0c, 0.0f);
  numBytes += cBinop_init(&cBinop_h5YLsKqu, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_C2wnbg99, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_IG3cfXEk, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_e37kAw1X, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_mRR5Z1V3, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Kxdg5uX4, 0.0f);
  numBytes += hTable_init(&hTable_1IyPiLjw, 256);
  numBytes += cTabhead_init(&cTabhead_ItJwIs5I, &hTable_NQMvacjK);
  numBytes += cVar_init_s(&cVar_qwMi1E7y, "del-1181-ref3");
  numBytes += cDelay_init(this, &cDelay_jIxhAhQf, 25.796f);
  numBytes += cDelay_init(this, &cDelay_vv5i5GpJ, 0.0f);
  numBytes += cBinop_init(&cBinop_EOWvKytc, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_WQs3BtMk, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_QjCUzKys, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_5GtfAtR7, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_uSsGTTPB, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gTAvxQHn, 0.0f);
  numBytes += hTable_init(&hTable_NQMvacjK, 256);
  numBytes += cTabhead_init(&cTabhead_ICOwZe2j, &hTable_yhmdKCjm);
  numBytes += cVar_init_s(&cVar_gJxj81Jt, "del-1181-ref2");
  numBytes += cDelay_init(this, &cDelay_8UgiGqi9, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_U512mxs8, 0.0f);
  numBytes += cBinop_init(&cBinop_66XxsLv1, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_MfykjDvJ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_rG58zcmi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_xeXxErpf, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_LGkI8mrh, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WnMg6fj1, 0.0f);
  numBytes += hTable_init(&hTable_yhmdKCjm, 256);
  numBytes += cTabhead_init(&cTabhead_WXjO9ZQr, &hTable_jrFYetRt);
  numBytes += cVar_init_s(&cVar_wKNcvn0L, "del-1181-ref1");
  numBytes += cDelay_init(this, &cDelay_oQ87xSQ0, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_SJP0bFdq, 0.0f);
  numBytes += cBinop_init(&cBinop_Gb0AnyML, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_OknfrXzN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_no78YeHx, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_31Tcjtr6, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_D4wWHpQ1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_jq4trc2U, 0.0f);
  numBytes += hTable_init(&hTable_jrFYetRt, 256);
  numBytes += cVar_init_f(&cVar_kUNPvE6N, 0.0f);
  numBytes += cVar_init_f(&cVar_UEDzTp9w, 0.0f);
  numBytes += cPack_init(&cPack_Z2u3Ykeb, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_VfGQc1d4, 22050.0f);
  numBytes += cBinop_init(&cBinop_tHZzAZjl, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_u2EAJiQ7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EDUAgIXE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_IemS5MsI, 22050.0f);
  numBytes += cBinop_init(&cBinop_xr5wRE0M, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_qJQ6uhSI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_75BE69WV, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_MEWRxRwf, 22050.0f);
  numBytes += cBinop_init(&cBinop_tPXoTent, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ZK1L3VRX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wooYlybz, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_91yl8Gta, "del-1280-del1");
  numBytes += sVarf_init(&sVarf_dhi2ax7Z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_t5UdQyCM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VrBDfl6D, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5wBpilFf, 10000.0f);
  numBytes += cBinop_init(&cBinop_y2jaGcKK, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wd6gq4RM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UuFC3M6c, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jKQqvB3L, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8Ic7bcIK, 10.0f);
  numBytes += cBinop_init(&cBinop_mujxcxdA, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_rjchOTv1, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_SSGN3iuQ, "floatatom");
  numBytes += sVarf_init(&sVarf_rlwqUzFu, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_YHjmxGZ4, 0.0f);
  numBytes += cDelay_init(this, &cDelay_IFdQHfGH, 0.0f);
  numBytes += hTable_init(&hTable_II1ikMgh, 256);
  numBytes += sVarf_init(&sVarf_Pum6MStC, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_uYedG795, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_LiLlKnno, 1196446176);
  numBytes += cSlice_init(&cSlice_T0O4d14r, 1, 1);
  numBytes += cRandom_init(&cRandom_Po2m533I, 1437178881);
  numBytes += cSlice_init(&cSlice_kQiJTqc2, 1, 1);
  numBytes += cVar_init_s(&cVar_JPbSI8om, "floatatom");
  numBytes += cPack_init(&cPack_AAcwLXcx, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_JFjepkEL, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_hoTMPCzr, "floatatom");
  numBytes += cDelay_init(this, &cDelay_63a5HLmT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Qc6W3W9n, 0.0f);
  numBytes += hTable_init(&hTable_rFdRAEVz, 256);
  numBytes += cVar_init_s(&cVar_p3Fea6N1, "del-1311-del");
  numBytes += sVarf_init(&sVarf_IJ4UWDfs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aTGnahLi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TFSPRgPI, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_VzqP7kSv, "del-1311-del");
  numBytes += sVarf_init(&sVarf_U7RJcLxh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wVgd2iFq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_49JgxUZF, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_SgmAujCc, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_DYZvLs8F, "del-1340-del1");
  numBytes += sVarf_init(&sVarf_HUMExlBT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iqLR9ako, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Rymz08w1, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lDIoQcFQ, 10000.0f);
  numBytes += cBinop_init(&cBinop_EkAuViHy, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ecj6eNGv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bp2q5nQP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_s3EHt4tr, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_apMxCtU9, 10.0f);
  numBytes += cBinop_init(&cBinop_i1Q31y4g, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_dAS8Zvpc, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_6iiGrCPV, "floatatom");
  numBytes += sVarf_init(&sVarf_NSmbYmM6, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_1zdqCr6O, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ZzsBulQO, 0.0f);
  numBytes += hTable_init(&hTable_4zsVnGpw, 256);
  numBytes += sVarf_init(&sVarf_ux9rIswl, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_GzbqHShH, "floatatom");
  numBytes += cDelay_init(this, &cDelay_cDsJD5Ul, 0.0f);
  numBytes += cVar_init_f(&cVar_Vquy3exB, 20.0f);
  numBytes += cBinop_init(&cBinop_VtnBXEUz, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Jlh1KjsJ, 0.0f);
  numBytes += cSlice_init(&cSlice_MVNtCIG3, 1, -1);
  numBytes += cSlice_init(&cSlice_QWgt38LO, 1, -1);
  numBytes += cVar_init_f(&cVar_i4L1zkmH, 0.0f);
  numBytes += cVar_init_f(&cVar_BLRHJtYX, 20.0f);
  numBytes += cVar_init_f(&cVar_8W0AnBcs, 0.0f);
  numBytes += cVar_init_f(&cVar_bTxypiiy, 0.0f);
  numBytes += cVar_init_f(&cVar_849Yfp40, 0.0f);
  numBytes += cSlice_init(&cSlice_q7RczXOE, 1, 1);
  numBytes += cSlice_init(&cSlice_a3hhL6n8, 0, 1);
  numBytes += cBinop_init(&cBinop_jtPqQX1r, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KoO3DBjS, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_cqprurle, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_U5jbamss, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_tl7NRVHd, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_XTg3fl3w, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_28x329e3, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_TxrzZRts, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_ORnZLAug, "floatatom");
  numBytes += cPack_init(&cPack_ZYnNyGW8, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_6kCcF4h7, 0.0f);
  numBytes += cVar_init_f(&cVar_vkHJZu37, 20.0f);
  numBytes += cBinop_init(&cBinop_PwJNIPFq, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_dzY1zz7N, 0.0f);
  numBytes += cSlice_init(&cSlice_jzA4fdLk, 1, -1);
  numBytes += cSlice_init(&cSlice_hMPZlwxa, 1, -1);
  numBytes += cVar_init_f(&cVar_FIP5Y9RT, 0.0f);
  numBytes += cVar_init_f(&cVar_gAHza7Qx, 20.0f);
  numBytes += cVar_init_f(&cVar_F8T2ZkxU, 0.0f);
  numBytes += cVar_init_f(&cVar_Lu8vOR82, 0.0f);
  numBytes += cVar_init_f(&cVar_NPxXbOtX, 0.0f);
  numBytes += cSlice_init(&cSlice_OJRoP9L4, 1, 1);
  numBytes += cSlice_init(&cSlice_JrsistFK, 0, 1);
  numBytes += cBinop_init(&cBinop_GrzwiFJj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RraCo6PL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_kO5Fp9H5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Ikd2cihX, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_lRMSBrst, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_KADqEhOV, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_AUJ53NRl, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_kUDRPTol, 0.0f); // __sub
  numBytes += cPack_init(&cPack_9FA0JaGg, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_5YSfjLBV, 2, 0.0f, 1000.0f);
  numBytes += sVarf_init(&sVarf_xrnIUr7u, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_V7kyJfco, 5.0f);
  numBytes += cBinop_init(&cBinop_yVzV0KSD, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_fVxFHmwF, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_dNGPfOIa, "floatatom");
  numBytes += cIf_init(&cIf_YnlRTBiX, false);
  numBytes += cIf_init(&cIf_mO1OVLoR, false);
  numBytes += cIf_init(&cIf_hczIIiyX, false);
  numBytes += cIf_init(&cIf_memw5FiQ, false);
  numBytes += cRandom_init(&cRandom_F0YzOkMj, -875154597);
  numBytes += cSlice_init(&cSlice_ShM2A8Zx, 1, 1);
  numBytes += sVari_init(&sVari_dQA9YIbP, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_wN9b2bSN, &hTable_zHYNTfQ2);
  numBytes += cVar_init_s(&cVar_rQPWw6sS, "del-1418-delay");
  numBytes += cDelay_init(this, &cDelay_oEQVMsH0, 12.0f);
  numBytes += cDelay_init(this, &cDelay_im5SXYmo, 0.0f);
  numBytes += cBinop_init(&cBinop_QhTed0dF, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_Y5TCWRWZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Ng9Nw46Y, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_wi8gNNjZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_AJbu7uEN, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_5dqAr9Bf, "floatatom");
  numBytes += cDelay_init(this, &cDelay_f6p13CCa, 5.0f);
  numBytes += cVar_init_f(&cVar_5Dld9cBI, 3800.0f);
  numBytes += cBinop_init(&cBinop_jI6W2oad, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_5nHH891Y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yhVHCMdh, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_EGmnYijP, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Ybu8a3HI, 0.0f);
  numBytes += hTable_init(&hTable_zHYNTfQ2, 256);
  numBytes += cBinop_init(&cBinop_5HlNL2DU, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_505TfUai, 0.999f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_nXv8FmXU, 1.0f);
  numBytes += cDelay_init(this, &cDelay_z323DXuN, 0.0f);
  numBytes += cVar_init_f(&cVar_co4Hzb1S, 2000.0f);
  numBytes += cBinop_init(&cBinop_YLsAPHkM, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_gWNwPjkS, 60.0f);
  numBytes += cRandom_init(&cRandom_TT4749JH, 610804460);
  numBytes += cSlice_init(&cSlice_GzoDx2Cn, 1, 1);
  numBytes += cVar_init_f(&cVar_LSWYAbwG, 0.0f);
  numBytes += cIf_init(&cIf_e8mlZLoM, false);
  numBytes += cIf_init(&cIf_DYOf3D8O, false);
  numBytes += cIf_init(&cIf_x0MHgz8x, false);
  numBytes += cIf_init(&cIf_SKH8zsuU, false);
  numBytes += cPack_init(&cPack_kOGpQlh2, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_ITXvyMhM, 2, 0.0f, 80.0f);
  numBytes += cVar_init_s(&cVar_2YwpGOLg, "floatatom");
  numBytes += cRandom_init(&cRandom_6C0RwNuj, -1735555899);
  numBytes += cSlice_init(&cSlice_twmScljw, 1, 1);
  numBytes += cVar_init_s(&cVar_8mlziwtC, "floatatom");
  numBytes += cVar_init_f(&cVar_YSLdePib, 1.0f);
  numBytes += cVar_init_f(&cVar_jAF19BZ0, 0.0f);
  numBytes += cVar_init_f(&cVar_Bpn8Flne, 0.0f);
  numBytes += cRandom_init(&cRandom_OkmvNt7p, 492896747);
  numBytes += cSlice_init(&cSlice_fXiPVR1q, 1, 1);
  numBytes += cRandom_init(&cRandom_SvQb4IFB, 1801919921);
  numBytes += cSlice_init(&cSlice_6e3DNPyL, 1, 1);
  numBytes += cRandom_init(&cRandom_wGCSafaY, 388701617);
  numBytes += cSlice_init(&cSlice_FlcM4Zwx, 1, 1);
  numBytes += cBinop_init(&cBinop_Pk7TX1Ss, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_SgqH4mel, -1131273253);
  numBytes += cSlice_init(&cSlice_dtiTTweu, 1, 1);
  numBytes += cPack_init(&cPack_9kg6kSQx, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_YM0y7ptV, "floatatom");
  numBytes += cVar_init_s(&cVar_muI03Z9H, "floatatom");
  numBytes += cVar_init_f(&cVar_JFvUyX7r, 0.0f);
  numBytes += cVar_init_s(&cVar_RElm2Xcl, "floatatom");
  numBytes += cVar_init_s(&cVar_hs27Y2nn, "floatatom");
  numBytes += cVar_init_s(&cVar_ZXgnFGYU, "floatatom");
  numBytes += cDelay_init(this, &cDelay_0EDJ59Y2, 25.0f);
  numBytes += cVar_init_f(&cVar_jcWqCJRt, 0.0f);
  numBytes += sVarf_init(&sVarf_pzCgjnJg, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_wUNYVvAH, -970725156);
  numBytes += cSlice_init(&cSlice_YWLw0x4A, 1, 1);
  numBytes += sVari_init(&sVari_fwiR6eR4, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_xOOmjLlF, &hTable_PGxZkRq1);
  numBytes += cVar_init_s(&cVar_r3HVk9z5, "del-1497-delay");
  numBytes += cDelay_init(this, &cDelay_MWcCdZ2m, 12.0f);
  numBytes += cDelay_init(this, &cDelay_wx4nVgsi, 0.0f);
  numBytes += cBinop_init(&cBinop_NaQvba0p, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_YxP3eUWY, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FQKnYi5l, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_JjBU5GKe, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_bCArJOZ8, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_o0ULGc0P, "floatatom");
  numBytes += cDelay_init(this, &cDelay_FLhf84rJ, 5.0f);
  numBytes += cVar_init_f(&cVar_tojINI2A, 3800.0f);
  numBytes += cBinop_init(&cBinop_dGCKZqhs, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_V9QkXh2V, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hehXzPac, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_4dPf2TbC, 0.0f);
  numBytes += cDelay_init(this, &cDelay_tsVmrAIz, 0.0f);
  numBytes += hTable_init(&hTable_PGxZkRq1, 256);
  numBytes += cBinop_init(&cBinop_yBt0mBOO, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_DYSmLFfa, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_9RR4uVQK, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_KlHj5l7j, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_VEyJlx6i, 1, 1);
  numBytes += cSlice_init(&cSlice_YI3lADQ2, 0, 1);
  numBytes += cBinop_init(&cBinop_49TOHZLy, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_QmIkjyOo, 98.0f);
  numBytes += cIf_init(&cIf_f6HUVMf6, false);
  numBytes += cBinop_init(&cBinop_OalZWtuM, 0.0f); // __pow
  numBytes += cPack_init(&cPack_SleIBuem, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_dVG2yshl, 0.0f);
  numBytes += cVar_init_f(&cVar_Aubq0qw4, 98.0f);
  numBytes += cIf_init(&cIf_4mQW1KGy, false);
  numBytes += cBinop_init(&cBinop_rG1mdjaM, 0.0f); // __pow
  numBytes += cPack_init(&cPack_ShCLTuhP, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_uoF0ohFT, 0.0f);
  numBytes += cRandom_init(&cRandom_SqilYJP1, -1457424887);
  numBytes += cSlice_init(&cSlice_TU8neTQl, 1, 1);
  numBytes += cBinop_init(&cBinop_xYg5PlzA, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_9pAEcSOG, 1772806614);
  numBytes += cSlice_init(&cSlice_zlB4tLX0, 1, 1);
  numBytes += cPack_init(&cPack_vwaBKhCT, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_WYupnRwv, "floatatom");
  numBytes += cVar_init_s(&cVar_iEIT6Yhd, "floatatom");
  numBytes += cVar_init_f(&cVar_70Q7bjez, 0.0f);
  numBytes += cVar_init_s(&cVar_YW3vIOb2, "floatatom");
  numBytes += cVar_init_s(&cVar_EMb709YL, "floatatom");
  numBytes += cVar_init_s(&cVar_HaouavX3, "floatatom");
  numBytes += cDelay_init(this, &cDelay_8EKBzdOf, 25.0f);
  numBytes += cVar_init_f(&cVar_cGLRwaWD, 0.0f);
  numBytes += sVarf_init(&sVarf_u8l5QpF1, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_kVQpYTRP, -607112122);
  numBytes += cSlice_init(&cSlice_KIQ5yFts, 1, 1);
  numBytes += sVari_init(&sVari_jzjJCKDI, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_w3Fp2vx1, &hTable_HcXuXSOk);
  numBytes += cVar_init_s(&cVar_8YEXrUri, "del-1565-delay");
  numBytes += cDelay_init(this, &cDelay_FC1VxYTn, 12.0f);
  numBytes += cDelay_init(this, &cDelay_HnT9vJmK, 0.0f);
  numBytes += cBinop_init(&cBinop_bV8SxJxq, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_UW6dJFlC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_U0Kt3gC4, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_dsMI974g, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_JoW0NqFL, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_eubTpqP2, "floatatom");
  numBytes += cDelay_init(this, &cDelay_9dInqXHc, 5.0f);
  numBytes += cVar_init_f(&cVar_sZZWwuQO, 3800.0f);
  numBytes += cBinop_init(&cBinop_3lt6XccC, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_0KvrXAaS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_F5zuLuDQ, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_gUOVcPRz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ACpE0rsX, 0.0f);
  numBytes += hTable_init(&hTable_HcXuXSOk, 256);
  numBytes += cBinop_init(&cBinop_IcCYrDUD, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_QODljzuj, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_lv8AqE0l, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_llHOjMsL, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_pERPQs4V, 1, 1);
  numBytes += cSlice_init(&cSlice_wKr3KvmA, 0, 1);
  numBytes += cBinop_init(&cBinop_ZchGwplf, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_VAYwYXkM, -20522656);
  numBytes += cSlice_init(&cSlice_eODZgkRd, 1, 1);
  numBytes += cBinop_init(&cBinop_GsA9Ail7, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_ybkr62Pm, 301288762);
  numBytes += cSlice_init(&cSlice_jkv4v8Vj, 1, 1);
  numBytes += cPack_init(&cPack_7UPbZEyv, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_GCqO9Xw9, "floatatom");
  numBytes += cVar_init_s(&cVar_sx7bE0As, "floatatom");
  numBytes += cVar_init_f(&cVar_qR1kBAnt, 0.0f);
  numBytes += cVar_init_s(&cVar_4CU5KJ0O, "floatatom");
  numBytes += cVar_init_s(&cVar_xARu31Lc, "floatatom");
  numBytes += cVar_init_s(&cVar_7bKsQ6FI, "floatatom");
  numBytes += cDelay_init(this, &cDelay_omWwlX5a, 25.0f);
  numBytes += cVar_init_f(&cVar_6gfSoMrd, 0.0f);
  numBytes += sVarf_init(&sVarf_QKB3RaNY, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_lLEBndJt, -734187793);
  numBytes += cSlice_init(&cSlice_nRjopsNn, 1, 1);
  numBytes += sVari_init(&sVari_8oAxT5QU, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_8NzvLAKx, &hTable_pvpd4J9a);
  numBytes += cVar_init_s(&cVar_bIMKyMWe, "del-1616-delay");
  numBytes += cDelay_init(this, &cDelay_8VK2Dnja, 12.0f);
  numBytes += cDelay_init(this, &cDelay_htHfWy4u, 0.0f);
  numBytes += cBinop_init(&cBinop_45XC7vmT, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_5wh7njll, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_yg2OE2D3, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_uAA32wHb, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_OnDduVan, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_fFWMUuYC, "floatatom");
  numBytes += cDelay_init(this, &cDelay_nxSuhIsJ, 5.0f);
  numBytes += cVar_init_f(&cVar_20gnBhli, 3800.0f);
  numBytes += cBinop_init(&cBinop_Pnx3AuMO, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_v2s8gWUH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_V5rJiyTG, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_dGw3AGMQ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cInhNouY, 0.0f);
  numBytes += hTable_init(&hTable_pvpd4J9a, 256);
  numBytes += cBinop_init(&cBinop_uYtXZ8iQ, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_MBNyl61Q, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_5y7AtNMC, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_CJtfYMcr, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_o1jHa5YZ, 1, 1);
  numBytes += cSlice_init(&cSlice_SDBn9QnO, 0, 1);
  numBytes += cBinop_init(&cBinop_6eMKx1bH, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_Ui69rqIM, -51696963);
  numBytes += cSlice_init(&cSlice_lpW9XVB8, 1, 1);
  numBytes += cBinop_init(&cBinop_Ioicey9L, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_dsgusB0s, 1249719076);
  numBytes += cSlice_init(&cSlice_JFNre4Ln, 1, 1);
  numBytes += cPack_init(&cPack_nwhd7nVK, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_X4utlX6u, "floatatom");
  numBytes += cVar_init_s(&cVar_KKNniKiX, "floatatom");
  numBytes += cVar_init_f(&cVar_L5CTqsBy, 0.0f);
  numBytes += cVar_init_s(&cVar_SVoMTWeq, "floatatom");
  numBytes += cVar_init_s(&cVar_lWrCeEfM, "floatatom");
  numBytes += cVar_init_s(&cVar_WHuz6Syw, "floatatom");
  numBytes += cDelay_init(this, &cDelay_OVJV2EWj, 25.0f);
  numBytes += cVar_init_f(&cVar_K1sT4Noq, 0.0f);
  numBytes += sVarf_init(&sVarf_wrUbSciL, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_56ii3zGI, 1775829730);
  numBytes += cSlice_init(&cSlice_YietMgtj, 1, 1);
  numBytes += sVari_init(&sVari_oA6MA27z, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_rVZc4tAx, &hTable_DCGCrjpW);
  numBytes += cVar_init_s(&cVar_vDRIuxsO, "del-1667-delay");
  numBytes += cDelay_init(this, &cDelay_xdxC85Aj, 12.0f);
  numBytes += cDelay_init(this, &cDelay_wknQ6TkK, 0.0f);
  numBytes += cBinop_init(&cBinop_8hCLJPq4, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_hlS5Ss8o, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_EYLTHCzY, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0syxJAOD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_JqeMXq6F, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_13Mlpflt, "floatatom");
  numBytes += cDelay_init(this, &cDelay_0XAr3P21, 5.0f);
  numBytes += cVar_init_f(&cVar_gqQhRQqu, 3800.0f);
  numBytes += cBinop_init(&cBinop_cMfCJWyT, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_bXbHQR9y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ja3r94A4, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_PVUzXNkm, 0.0f);
  numBytes += cDelay_init(this, &cDelay_RfiF60ko, 0.0f);
  numBytes += hTable_init(&hTable_DCGCrjpW, 256);
  numBytes += cBinop_init(&cBinop_FYMYBLdv, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_3Ugyc5CU, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_HijIPRWN, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_8bRWH4K8, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_9kzd4qw3, 1, 1);
  numBytes += cSlice_init(&cSlice_swxRZ9pb, 0, 1);
  numBytes += cBinop_init(&cBinop_5jGmUKCT, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_8RPOPWbf, 100.0f);
  numBytes += cIf_init(&cIf_FjAf9k6X, false);
  numBytes += cBinop_init(&cBinop_7eIZJ9cz, 0.0f); // __pow
  numBytes += cPack_init(&cPack_2iZvvVMJ, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_ozNFEFEU, 0.0f);
  numBytes += cVar_init_f(&cVar_1pPDI4cD, 100.0f);
  numBytes += cIf_init(&cIf_owpbKHAq, false);
  numBytes += cBinop_init(&cBinop_AODEktD2, 0.0f); // __pow
  numBytes += cPack_init(&cPack_H8oS241C, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_mmK7GLJ5, 0.0f);
  numBytes += cVar_init_f(&cVar_HilTTVMk, 98.0f);
  numBytes += cIf_init(&cIf_b2w3jChM, false);
  numBytes += cBinop_init(&cBinop_ZHoJBRzc, 0.0f); // __pow
  numBytes += cPack_init(&cPack_rO9GPyr6, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_vyua7Yc2, 0.0f);
  numBytes += cIf_init(&cIf_8qKJNVvx, false);
  numBytes += cIf_init(&cIf_Y68UUWba, false);
  numBytes += cVar_init_f(&cVar_Bs1qFXGO, 89.0f);
  numBytes += cIf_init(&cIf_sUgsXWQE, false);
  numBytes += cBinop_init(&cBinop_q5saU67P, 0.0f); // __pow
  numBytes += cPack_init(&cPack_MbEje83s, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_QeRwSO4q, 0.0f);
  numBytes += cPack_init(&cPack_j949lUAk, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_NKhSGRqQ, 1, 1);
  numBytes += cSlice_init(&cSlice_N9ewK21o, 0, 1);
  numBytes += cIf_init(&cIf_Y1VO59hg, false);
  numBytes += cIf_init(&cIf_PEndkoVi, false);
  numBytes += cIf_init(&cIf_XovLH2YC, false);
  numBytes += cSlice_init(&cSlice_qfzLa1Hd, 1, 1);
  numBytes += cSlice_init(&cSlice_A0vSgSvQ, 0, 1);
  numBytes += cVar_init_f(&cVar_TudsweYL, 0.0f);
  numBytes += cIf_init(&cIf_5oezjAOE, false);
  numBytes += cPack_init(&cPack_gtAi5N5J, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_GtAMpbAP, 1, -1);
  numBytes += cSlice_init(&cSlice_pudsVKGB, 1, -1);
  numBytes += cSlice_init(&cSlice_qHXn9TQI, 1, -1);
  numBytes += cSlice_init(&cSlice_rp2nKw9s, 1, -1);
  numBytes += cIf_init(&cIf_S7i8X3CB, false);
  numBytes += cVar_init_f(&cVar_vQ0stwpg, 1.0f);
  numBytes += cPack_init(&cPack_pzJ0g39m, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_WONrFDuz, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_CircleStrings::~Heavy_CircleStrings() {
  hTable_free(&hTable_Ohm0hokt);
  hTable_free(&hTable_UpKUZgJo);
  hTable_free(&hTable_RVmx7Zx7);
  hTable_free(&hTable_MOC6tDsa);
  cPack_free(&cPack_tRfDYkVG);
  cPack_free(&cPack_FTTsOLAf);
  hTable_free(&hTable_JVMiFZGC);
  hTable_free(&hTable_gsDd3hqv);
  hTable_free(&hTable_ys24awdF);
  hTable_free(&hTable_jE20V2t5);
  hTable_free(&hTable_R5Orrj0z);
  hTable_free(&hTable_4q4El3xx);
  cPack_free(&cPack_qJNt1E2j);
  cPack_free(&cPack_r728iCDn);
  cPack_free(&cPack_FhtpVoZR);
  hTable_free(&hTable_xtoVBvL3);
  hTable_free(&hTable_N1Do4ZF4);
  hTable_free(&hTable_Yvxcqs7Z);
  hTable_free(&hTable_w1FkbIwz);
  hTable_free(&hTable_H7TQt9AK);
  cPack_free(&cPack_naduErNi);
  cPack_free(&cPack_U7XV9pWd);
  hTable_free(&hTable_gdqDQNUs);
  hTable_free(&hTable_TF9cUA1F);
  hTable_free(&hTable_1IyPiLjw);
  hTable_free(&hTable_NQMvacjK);
  hTable_free(&hTable_yhmdKCjm);
  hTable_free(&hTable_jrFYetRt);
  cPack_free(&cPack_Z2u3Ykeb);
  hTable_free(&hTable_II1ikMgh);
  cPack_free(&cPack_uYedG795);
  cPack_free(&cPack_AAcwLXcx);
  cPack_free(&cPack_JFjepkEL);
  hTable_free(&hTable_rFdRAEVz);
  hTable_free(&hTable_4zsVnGpw);
  cPack_free(&cPack_ZYnNyGW8);
  cPack_free(&cPack_9FA0JaGg);
  cPack_free(&cPack_5YSfjLBV);
  hTable_free(&hTable_zHYNTfQ2);
  cPack_free(&cPack_kOGpQlh2);
  cPack_free(&cPack_ITXvyMhM);
  cPack_free(&cPack_9kg6kSQx);
  hTable_free(&hTable_PGxZkRq1);
  cPack_free(&cPack_9RR4uVQK);
  cPack_free(&cPack_KlHj5l7j);
  cPack_free(&cPack_SleIBuem);
  cPack_free(&cPack_ShCLTuhP);
  cPack_free(&cPack_vwaBKhCT);
  hTable_free(&hTable_HcXuXSOk);
  cPack_free(&cPack_lv8AqE0l);
  cPack_free(&cPack_llHOjMsL);
  cPack_free(&cPack_7UPbZEyv);
  hTable_free(&hTable_pvpd4J9a);
  cPack_free(&cPack_5y7AtNMC);
  cPack_free(&cPack_CJtfYMcr);
  cPack_free(&cPack_nwhd7nVK);
  hTable_free(&hTable_DCGCrjpW);
  cPack_free(&cPack_HijIPRWN);
  cPack_free(&cPack_8bRWH4K8);
  cPack_free(&cPack_2iZvvVMJ);
  cPack_free(&cPack_H8oS241C);
  cPack_free(&cPack_rO9GPyr6);
  cPack_free(&cPack_MbEje83s);
  cPack_free(&cPack_j949lUAk);
  cPack_free(&cPack_gtAi5N5J);
  cPack_free(&cPack_pzJ0g39m);
}

HvTable *Heavy_CircleStrings::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xCA4BE954: return &hTable_Ohm0hokt; // del-1011-del1
    case 0x244CE923: return &hTable_UpKUZgJo; // del-1011-del2
    case 0xBF68886F: return &hTable_RVmx7Zx7; // del-1011-del3
    case 0x55632928: return &hTable_MOC6tDsa; // del-1011-del4
    case 0x96995032: return &hTable_JVMiFZGC; // del-1011-ref6
    case 0xBDA899C7: return &hTable_gsDd3hqv; // del-1011-ref5
    case 0xC66C0031: return &hTable_ys24awdF; // del-1011-ref4
    case 0x87263188: return &hTable_jE20V2t5; // del-1011-ref3
    case 0xABC596E9: return &hTable_R5Orrj0z; // del-1011-ref2
    case 0x4E55A0D9: return &hTable_4q4El3xx; // del-1011-ref1
    case 0x1F09EB02: return &hTable_xtoVBvL3; // del-1118-del
    case 0xB5F303E3: return &hTable_N1Do4ZF4; // del-1181-del1
    case 0x6E18225F: return &hTable_Yvxcqs7Z; // del-1181-del2
    case 0x272AEAC5: return &hTable_w1FkbIwz; // del-1181-del3
    case 0x1EF3B8AB: return &hTable_H7TQt9AK; // del-1181-del4
    case 0x908630F0: return &hTable_gdqDQNUs; // del-1181-ref6
    case 0x571D5EBB: return &hTable_TF9cUA1F; // del-1181-ref5
    case 0xCD1DF3EE: return &hTable_1IyPiLjw; // del-1181-ref4
    case 0x32F70D4: return &hTable_NQMvacjK; // del-1181-ref3
    case 0x2649C1A0: return &hTable_yhmdKCjm; // del-1181-ref2
    case 0x2A4E9F1A: return &hTable_jrFYetRt; // del-1181-ref1
    case 0xCDA70ACE: return &hTable_II1ikMgh; // del-1280-del1
    case 0x1880FCC4: return &hTable_rFdRAEVz; // del-1311-del
    case 0xDA0DD3E: return &hTable_4zsVnGpw; // del-1340-del1
    case 0xF059E6C5: return &hTable_zHYNTfQ2; // del-1418-delay
    case 0x1B841D52: return &hTable_PGxZkRq1; // del-1497-delay
    case 0xDE86E2B1: return &hTable_HcXuXSOk; // del-1565-delay
    case 0x308D60F2: return &hTable_pvpd4J9a; // del-1616-delay
    case 0x4D4CF87C: return &hTable_DCGCrjpW; // del-1667-delay
    default: return nullptr;
  }
}

void Heavy_CircleStrings::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE9CDF196: { // 1474-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jOmxXUcu_sendMessage);
      break;
    }
    case 0x318534AD: { // 1474-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YkbKmOx0_sendMessage);
      break;
    }
    case 0x73BE02B2: { // 1474-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZkZHESny_sendMessage);
      break;
    }
    case 0x20FBEFA2: { // 1474-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Icnr8TPq_sendMessage);
      break;
    }
    case 0xB3D2781B: { // 1474-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2uZB8NFN_sendMessage);
      break;
    }
    case 0xEB419491: { // 1474-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_m0tGDAVD_sendMessage);
      break;
    }
    case 0x49301F33: { // 1526-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mExnN4mg_sendMessage);
      break;
    }
    case 0x3EA097: { // 1526-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7UCtbV99_sendMessage);
      break;
    }
    case 0x1D57784C: { // 1534-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4JdvG5kg_sendMessage);
      break;
    }
    case 0xB6B2C532: { // 1534-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fYquvUnA_sendMessage);
      break;
    }
    case 0xEA6E47A2: { // 1542-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_skQMsfJ9_sendMessage);
      break;
    }
    case 0x39641416: { // 1542-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PkmucRAG_sendMessage);
      break;
    }
    case 0xD0ED04C0: { // 1542-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Mx9UBL4w_sendMessage);
      break;
    }
    case 0x1E007032: { // 1542-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_d0uKRNHZ_sendMessage);
      break;
    }
    case 0x20600A8E: { // 1542-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xbpqAgs5_sendMessage);
      break;
    }
    case 0xEB9D289: { // 1542-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_c8QMPVwb_sendMessage);
      break;
    }
    case 0x12164925: { // 1593-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WX5as8MH_sendMessage);
      break;
    }
    case 0x9F106978: { // 1593-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6zHqNegb_sendMessage);
      break;
    }
    case 0xF8CC5130: { // 1593-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_W7LqAjxU_sendMessage);
      break;
    }
    case 0xCF824326: { // 1593-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oUizUuqK_sendMessage);
      break;
    }
    case 0x57F149E1: { // 1593-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qQf1Sj8t_sendMessage);
      break;
    }
    case 0x7BCAFFC2: { // 1593-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qdZua97G_sendMessage);
      break;
    }
    case 0xCCAC5F0A: { // 1644-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HSkDjts7_sendMessage);
      break;
    }
    case 0x19A77C92: { // 1644-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oVtyx6ag_sendMessage);
      break;
    }
    case 0xD26C853B: { // 1644-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WX73Qn7b_sendMessage);
      break;
    }
    case 0x76816227: { // 1644-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XJ6T1u7z_sendMessage);
      break;
    }
    case 0xE6DAD6CC: { // 1644-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4RPCBEA4_sendMessage);
      break;
    }
    case 0xDDDC8674: { // 1644-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_68t2IYqN_sendMessage);
      break;
    }
    case 0x9D74C17D: { // 1695-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3ekvhXA7_sendMessage);
      break;
    }
    case 0x990B713A: { // 1695-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_B20vMJW5_sendMessage);
      break;
    }
    case 0x212BD48C: { // 1703-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tKIQJoSo_sendMessage);
      break;
    }
    case 0x485D1082: { // 1703-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_opvFtmTy_sendMessage);
      break;
    }
    case 0x18B0FC6F: { // 1711-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_plAmcubq_sendMessage);
      break;
    }
    case 0x300E52C6: { // 1711-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Bj3bGHrp_sendMessage);
      break;
    }
    case 0x7B6E4E54: { // 1723-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xzTuggGI_sendMessage);
      break;
    }
    case 0x64AF31A5: { // 1723-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dstYVEvJ_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ogbrL805_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TUaaSjax_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_knOAPrx9_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NnJajyov_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EY8Mu6Z7_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_foVKG66j_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0Zh0qZMd_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jvkTwu3B_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ow0WVRnB_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UYK8y7t5_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZmNTFkml_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UR0PloFB_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zJYPv9vR_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DGV4kCga_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_p9t09Q5A_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZCCQa56L_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FVLn8lfV_sendMessage);
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


void Heavy_CircleStrings::cSlice_oztOtzI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_L0d6l2HP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_ygW4IiFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_WEiwESCo, 0, m, &cIf_WEiwESCo_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_6dTQvQAK, 0, m, &cIf_6dTQvQAK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_xzOhFdSU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_Ldi4JImE, 0, m, &cIf_Ldi4JImE_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_F3hn9SFm, 0, m, &cIf_F3hn9SFm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_mnsDYdLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_6VgJPlwK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_z8OJrArv, 0, m, &cIf_z8OJrArv_sendMessage);
}

void Heavy_CircleStrings::cUnop_LwHwRox1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_hiUVwIfj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AXhW9KuH, HV_BINOP_EQ, 1, m, &cBinop_AXhW9KuH_sendMessage);
}

void Heavy_CircleStrings::cUnop_m713FtSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_hiUVwIfj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AXhW9KuH, HV_BINOP_EQ, 1, m, &cBinop_AXhW9KuH_sendMessage);
}

void Heavy_CircleStrings::cIf_z8OJrArv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_m713FtSt_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LwHwRox1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_6VgJPlwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_z8OJrArv, 1, m, &cIf_z8OJrArv_sendMessage);
}

void Heavy_CircleStrings::cIf_6dTQvQAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_uK8dxdnc_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_F3hn9SFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Kxuv9kbN_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_WEiwESCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_uK8dxdnc_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_Ldi4JImE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Kxuv9kbN_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_L0d6l2HP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AXhW9KuH, HV_BINOP_EQ, 0, m, &cBinop_AXhW9KuH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_6hUd62LT_sendMessage);
}

void Heavy_CircleStrings::cBinop_hiUVwIfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cbeWbn6q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0zx7rmFJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_AXhW9KuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JQRUJxVs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aLLmY76A_sendMessage);
}

void Heavy_CircleStrings::cCast_JQRUJxVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6dTQvQAK, 1, m, &cIf_6dTQvQAK_sendMessage);
}

void Heavy_CircleStrings::cCast_aLLmY76A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ldi4JImE, 1, m, &cIf_Ldi4JImE_sendMessage);
}

void Heavy_CircleStrings::cCast_cbeWbn6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WEiwESCo, 1, m, &cIf_WEiwESCo_sendMessage);
}

void Heavy_CircleStrings::cCast_0zx7rmFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_F3hn9SFm, 1, m, &cIf_F3hn9SFm_sendMessage);
}

void Heavy_CircleStrings::cBinop_6hUd62LT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tWTYneeU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cTabhead_OhETtZ3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5pKV81vI, HV_BINOP_SUBTRACT, 0, m, &cBinop_5pKV81vI_sendMessage);
}

void Heavy_CircleStrings::cMsg_wBqdCLkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2JrFOPw1_sendMessage);
}

void Heavy_CircleStrings::cSystem_2JrFOPw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_x6j7tcaj_sendMessage);
}

void Heavy_CircleStrings::cVar_bfjrYQig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d3MUKSTu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Jb4NlA2J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Jb4NlA2J, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cx3cyPKl, 0, m, &cDelay_Cx3cyPKl_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vF8jA4oT, 0, m, &sTabread_vF8jA4oT_sendMessage);
}

void Heavy_CircleStrings::cDelay_Cx3cyPKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Cx3cyPKl, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vF8jA4oT, 0, m, &sTabread_vF8jA4oT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cx3cyPKl, 0, m, &cDelay_Cx3cyPKl_sendMessage);
}

void Heavy_CircleStrings::sTabread_vF8jA4oT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gXLTwrl7, HV_BINOP_SUBTRACT, 0, m, &cBinop_gXLTwrl7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_FWnQVq2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TLSvdI6E, HV_BINOP_MAX, 0, m, &cBinop_TLSvdI6E_sendMessage);
}

void Heavy_CircleStrings::cBinop_x6j7tcaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FWnQVq2M, HV_BINOP_MULTIPLY, 0, m, &cBinop_FWnQVq2M_sendMessage);
}

void Heavy_CircleStrings::cBinop_5pKV81vI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eN0Fa1cq_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vF8jA4oT, 0, m, &sTabread_vF8jA4oT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cxZCcdxU_sendMessage);
}

void Heavy_CircleStrings::cSystem_E2kz4W36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gXLTwrl7, HV_BINOP_SUBTRACT, 1, m, &cBinop_gXLTwrl7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cx3cyPKl, 2, m, &cDelay_Cx3cyPKl_sendMessage);
}

void Heavy_CircleStrings::cMsg_d3MUKSTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E2kz4W36_sendMessage);
}

void Heavy_CircleStrings::cMsg_eN0Fa1cq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Jb4NlA2J, 0, m, &cDelay_Jb4NlA2J_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cx3cyPKl, 0, m, &cDelay_Cx3cyPKl_sendMessage);
}

void Heavy_CircleStrings::cMsg_qhsnurn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_TLSvdI6E, HV_BINOP_MAX, 1, m, &cBinop_TLSvdI6E_sendMessage);
}

void Heavy_CircleStrings::cBinop_TLSvdI6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5pKV81vI, HV_BINOP_SUBTRACT, 1, m, &cBinop_5pKV81vI_sendMessage);
}

void Heavy_CircleStrings::cCast_cxZCcdxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Jb4NlA2J, 0, m, &cDelay_Jb4NlA2J_sendMessage);
}

void Heavy_CircleStrings::cBinop_JpEWsCTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Jb4NlA2J, 2, m, &cDelay_Jb4NlA2J_sendMessage);
}

void Heavy_CircleStrings::cBinop_gXLTwrl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JpEWsCTQ_sendMessage);
}

void Heavy_CircleStrings::cCast_hEuu3lU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bfjrYQig, 0, m, &cVar_bfjrYQig_sendMessage);
  cMsg_wBqdCLkR_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OhETtZ3C, 0, m, &cTabhead_OhETtZ3C_sendMessage);
}

void Heavy_CircleStrings::cTabhead_wPpYvZtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AW2FiSyn, HV_BINOP_SUBTRACT, 0, m, &cBinop_AW2FiSyn_sendMessage);
}

void Heavy_CircleStrings::cMsg_o0UyRx9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TFLnXLfV_sendMessage);
}

void Heavy_CircleStrings::cSystem_TFLnXLfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rWsxG0ng_sendMessage);
}

void Heavy_CircleStrings::cVar_v4AbJkKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R0XVbJjk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_5Ym7uWrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5Ym7uWrg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_y73UItuY, 0, m, &cDelay_y73UItuY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7on1nhss, 0, m, &sTabread_7on1nhss_sendMessage);
}

void Heavy_CircleStrings::cDelay_y73UItuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_y73UItuY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7on1nhss, 0, m, &sTabread_7on1nhss_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_y73UItuY, 0, m, &cDelay_y73UItuY_sendMessage);
}

void Heavy_CircleStrings::sTabread_7on1nhss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_r9CPMA8B, HV_BINOP_SUBTRACT, 0, m, &cBinop_r9CPMA8B_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_5eloesaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e1v5WZrN, HV_BINOP_MAX, 0, m, &cBinop_e1v5WZrN_sendMessage);
}

void Heavy_CircleStrings::cBinop_rWsxG0ng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5eloesaw, HV_BINOP_MULTIPLY, 0, m, &cBinop_5eloesaw_sendMessage);
}

void Heavy_CircleStrings::cBinop_AW2FiSyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O9QteekQ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7on1nhss, 0, m, &sTabread_7on1nhss_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hdvW3GA5_sendMessage);
}

void Heavy_CircleStrings::cSystem_8sVV3vLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r9CPMA8B, HV_BINOP_SUBTRACT, 1, m, &cBinop_r9CPMA8B_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_y73UItuY, 2, m, &cDelay_y73UItuY_sendMessage);
}

void Heavy_CircleStrings::cMsg_R0XVbJjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8sVV3vLU_sendMessage);
}

void Heavy_CircleStrings::cMsg_O9QteekQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5Ym7uWrg, 0, m, &cDelay_5Ym7uWrg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_y73UItuY, 0, m, &cDelay_y73UItuY_sendMessage);
}

void Heavy_CircleStrings::cMsg_Sr2yAb1K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_e1v5WZrN, HV_BINOP_MAX, 1, m, &cBinop_e1v5WZrN_sendMessage);
}

void Heavy_CircleStrings::cBinop_e1v5WZrN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AW2FiSyn, HV_BINOP_SUBTRACT, 1, m, &cBinop_AW2FiSyn_sendMessage);
}

void Heavy_CircleStrings::cCast_hdvW3GA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5Ym7uWrg, 0, m, &cDelay_5Ym7uWrg_sendMessage);
}

void Heavy_CircleStrings::cBinop_XAkZQw8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5Ym7uWrg, 2, m, &cDelay_5Ym7uWrg_sendMessage);
}

void Heavy_CircleStrings::cBinop_r9CPMA8B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XAkZQw8u_sendMessage);
}

void Heavy_CircleStrings::cCast_Wk4drSsN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v4AbJkKd, 0, m, &cVar_v4AbJkKd_sendMessage);
  cMsg_o0UyRx9y_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wPpYvZtI, 0, m, &cTabhead_wPpYvZtI_sendMessage);
}

void Heavy_CircleStrings::cTabhead_3LptR8uW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lkWomSgj, HV_BINOP_SUBTRACT, 0, m, &cBinop_lkWomSgj_sendMessage);
}

void Heavy_CircleStrings::cMsg_era1qfhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JnyqlxZb_sendMessage);
}

void Heavy_CircleStrings::cSystem_JnyqlxZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ydrRLJtw_sendMessage);
}

void Heavy_CircleStrings::cVar_ugZC1k5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5kHhG5SM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_IHkrPC3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IHkrPC3i, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4zIILafd, 0, m, &cDelay_4zIILafd_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eNfWaxkU, 0, m, &sTabread_eNfWaxkU_sendMessage);
}

void Heavy_CircleStrings::cDelay_4zIILafd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4zIILafd, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eNfWaxkU, 0, m, &sTabread_eNfWaxkU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4zIILafd, 0, m, &cDelay_4zIILafd_sendMessage);
}

void Heavy_CircleStrings::sTabread_eNfWaxkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kHLd8Fvu, HV_BINOP_SUBTRACT, 0, m, &cBinop_kHLd8Fvu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_iyTuJsrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3XamnOSF, HV_BINOP_MAX, 0, m, &cBinop_3XamnOSF_sendMessage);
}

void Heavy_CircleStrings::cBinop_ydrRLJtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iyTuJsrF, HV_BINOP_MULTIPLY, 0, m, &cBinop_iyTuJsrF_sendMessage);
}

void Heavy_CircleStrings::cBinop_lkWomSgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1XAP6xjl_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eNfWaxkU, 0, m, &sTabread_eNfWaxkU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NaRqUJOi_sendMessage);
}

void Heavy_CircleStrings::cSystem_ycNYH4lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kHLd8Fvu, HV_BINOP_SUBTRACT, 1, m, &cBinop_kHLd8Fvu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4zIILafd, 2, m, &cDelay_4zIILafd_sendMessage);
}

void Heavy_CircleStrings::cMsg_5kHhG5SM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ycNYH4lb_sendMessage);
}

void Heavy_CircleStrings::cMsg_1XAP6xjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IHkrPC3i, 0, m, &cDelay_IHkrPC3i_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4zIILafd, 0, m, &cDelay_4zIILafd_sendMessage);
}

void Heavy_CircleStrings::cMsg_WGXSZkhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_3XamnOSF, HV_BINOP_MAX, 1, m, &cBinop_3XamnOSF_sendMessage);
}

void Heavy_CircleStrings::cBinop_3XamnOSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lkWomSgj, HV_BINOP_SUBTRACT, 1, m, &cBinop_lkWomSgj_sendMessage);
}

void Heavy_CircleStrings::cCast_NaRqUJOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IHkrPC3i, 0, m, &cDelay_IHkrPC3i_sendMessage);
}

void Heavy_CircleStrings::cBinop_0z1lMNWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IHkrPC3i, 2, m, &cDelay_IHkrPC3i_sendMessage);
}

void Heavy_CircleStrings::cBinop_kHLd8Fvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0z1lMNWO_sendMessage);
}

void Heavy_CircleStrings::cCast_DOnFLG7g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ugZC1k5a, 0, m, &cVar_ugZC1k5a_sendMessage);
  cMsg_era1qfhc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3LptR8uW, 0, m, &cTabhead_3LptR8uW_sendMessage);
}

void Heavy_CircleStrings::cTabhead_HzoAA5Zg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CpxspCjp, HV_BINOP_SUBTRACT, 0, m, &cBinop_CpxspCjp_sendMessage);
}

void Heavy_CircleStrings::cMsg_Xs1OEevI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_47NmYHEg_sendMessage);
}

void Heavy_CircleStrings::cSystem_47NmYHEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_S0HERpgR_sendMessage);
}

void Heavy_CircleStrings::cVar_qOLfHs8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MLQOJNor_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_i5q2Hhzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_i5q2Hhzi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pTuCtuGG, 0, m, &cDelay_pTuCtuGG_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_BTfVSBtQ, 0, m, &sTabread_BTfVSBtQ_sendMessage);
}

void Heavy_CircleStrings::cDelay_pTuCtuGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pTuCtuGG, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_BTfVSBtQ, 0, m, &sTabread_BTfVSBtQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pTuCtuGG, 0, m, &cDelay_pTuCtuGG_sendMessage);
}

void Heavy_CircleStrings::sTabread_BTfVSBtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4KslX7i0, HV_BINOP_SUBTRACT, 0, m, &cBinop_4KslX7i0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_SLZXL74w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XjDJugAH, HV_BINOP_MAX, 0, m, &cBinop_XjDJugAH_sendMessage);
}

void Heavy_CircleStrings::cBinop_S0HERpgR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SLZXL74w, HV_BINOP_MULTIPLY, 0, m, &cBinop_SLZXL74w_sendMessage);
}

void Heavy_CircleStrings::cBinop_CpxspCjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iQ9y0ppW_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_BTfVSBtQ, 0, m, &sTabread_BTfVSBtQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zXljXUJK_sendMessage);
}

void Heavy_CircleStrings::cSystem_ouso8JSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4KslX7i0, HV_BINOP_SUBTRACT, 1, m, &cBinop_4KslX7i0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pTuCtuGG, 2, m, &cDelay_pTuCtuGG_sendMessage);
}

void Heavy_CircleStrings::cMsg_MLQOJNor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ouso8JSf_sendMessage);
}

void Heavy_CircleStrings::cMsg_iQ9y0ppW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_i5q2Hhzi, 0, m, &cDelay_i5q2Hhzi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pTuCtuGG, 0, m, &cDelay_pTuCtuGG_sendMessage);
}

void Heavy_CircleStrings::cMsg_OSNG26LA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_XjDJugAH, HV_BINOP_MAX, 1, m, &cBinop_XjDJugAH_sendMessage);
}

void Heavy_CircleStrings::cBinop_XjDJugAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CpxspCjp, HV_BINOP_SUBTRACT, 1, m, &cBinop_CpxspCjp_sendMessage);
}

void Heavy_CircleStrings::cCast_zXljXUJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_i5q2Hhzi, 0, m, &cDelay_i5q2Hhzi_sendMessage);
}

void Heavy_CircleStrings::cBinop_caUOEX0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_i5q2Hhzi, 2, m, &cDelay_i5q2Hhzi_sendMessage);
}

void Heavy_CircleStrings::cBinop_4KslX7i0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_caUOEX0O_sendMessage);
}

void Heavy_CircleStrings::cCast_Ni6XENNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qOLfHs8M, 0, m, &cVar_qOLfHs8M_sendMessage);
  cMsg_Xs1OEevI_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HzoAA5Zg, 0, m, &cTabhead_HzoAA5Zg_sendMessage);
}

void Heavy_CircleStrings::cMsg_T8BtSvjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_90XxhW8Y_sendMessage);
}

void Heavy_CircleStrings::cSystem_90XxhW8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yc5jiQNK_sendMessage);
}

void Heavy_CircleStrings::cDelay_mB2dl1c0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mB2dl1c0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jh9lvbMz, 0, m, &cDelay_jh9lvbMz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mB2dl1c0, 0, m, &cDelay_mB2dl1c0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PKySz5yC, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_jh9lvbMz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jh9lvbMz, m);
  cMsg_I4pZ0GQk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_7cFyF4yQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_irMQimbW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_i5f3poPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TMhfrnMT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Ohm0hokt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cCCDHfSX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mB2dl1c0, 2, m, &cDelay_mB2dl1c0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A1NgZTRr_sendMessage);
}

void Heavy_CircleStrings::cMsg_TMhfrnMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Ohm0hokt, 0, m, &hTable_Ohm0hokt_sendMessage);
}

void Heavy_CircleStrings::cBinop_yc5jiQNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_i5f3poPy_sendMessage);
}

void Heavy_CircleStrings::cMsg_I4pZ0GQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Ohm0hokt, 0, m, &hTable_Ohm0hokt_sendMessage);
}

void Heavy_CircleStrings::cCast_A1NgZTRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mB2dl1c0, 0, m, &cDelay_mB2dl1c0_sendMessage);
}

void Heavy_CircleStrings::cMsg_cCCDHfSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_jh9lvbMz, 2, m, &cDelay_jh9lvbMz_sendMessage);
}

void Heavy_CircleStrings::cMsg_irMQimbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PKySz5yC, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_GYPCLLSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_btrb6Fn0_sendMessage);
}

void Heavy_CircleStrings::cSystem_btrb6Fn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eDMpa2IB_sendMessage);
}

void Heavy_CircleStrings::cDelay_nrVLLlY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nrVLLlY1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m8wCPrl9, 0, m, &cDelay_m8wCPrl9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nrVLLlY1, 0, m, &cDelay_nrVLLlY1_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Xy0HUy0H, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_m8wCPrl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_m8wCPrl9, m);
  cMsg_zwVyhuxQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_KkAK9tDD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_HlnDByEw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_umJVNczs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_giLMsum3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_UpKUZgJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PHdvsn8q_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nrVLLlY1, 2, m, &cDelay_nrVLLlY1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4siBZXPS_sendMessage);
}

void Heavy_CircleStrings::cMsg_giLMsum3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_UpKUZgJo, 0, m, &hTable_UpKUZgJo_sendMessage);
}

void Heavy_CircleStrings::cBinop_eDMpa2IB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_umJVNczs_sendMessage);
}

void Heavy_CircleStrings::cMsg_zwVyhuxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_UpKUZgJo, 0, m, &hTable_UpKUZgJo_sendMessage);
}

void Heavy_CircleStrings::cCast_4siBZXPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nrVLLlY1, 0, m, &cDelay_nrVLLlY1_sendMessage);
}

void Heavy_CircleStrings::cMsg_PHdvsn8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_m8wCPrl9, 2, m, &cDelay_m8wCPrl9_sendMessage);
}

void Heavy_CircleStrings::cMsg_HlnDByEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Xy0HUy0H, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_voS5M3uR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l9tEXoIR_sendMessage);
}

void Heavy_CircleStrings::cSystem_l9tEXoIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_svVw7d7a_sendMessage);
}

void Heavy_CircleStrings::cDelay_2r077o5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2r077o5M, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2d1L75dl, 0, m, &cDelay_2d1L75dl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2r077o5M, 0, m, &cDelay_2r077o5M_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hefPizER, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_2d1L75dl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2d1L75dl, m);
  cMsg_vFuWAXQA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_2yyEuhub_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_UUIG10OH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_EHnMZ3gX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kHQo4I1c_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_RVmx7Zx7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mxWXhOO8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2r077o5M, 2, m, &cDelay_2r077o5M_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sWbEVqti_sendMessage);
}

void Heavy_CircleStrings::cMsg_kHQo4I1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_RVmx7Zx7, 0, m, &hTable_RVmx7Zx7_sendMessage);
}

void Heavy_CircleStrings::cBinop_svVw7d7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_EHnMZ3gX_sendMessage);
}

void Heavy_CircleStrings::cMsg_vFuWAXQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_RVmx7Zx7, 0, m, &hTable_RVmx7Zx7_sendMessage);
}

void Heavy_CircleStrings::cCast_sWbEVqti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2r077o5M, 0, m, &cDelay_2r077o5M_sendMessage);
}

void Heavy_CircleStrings::cMsg_mxWXhOO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2d1L75dl, 2, m, &cDelay_2d1L75dl_sendMessage);
}

void Heavy_CircleStrings::cMsg_UUIG10OH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hefPizER, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_DlJvBiP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4URAwqqg_sendMessage);
}

void Heavy_CircleStrings::cSystem_4URAwqqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xyytEhpl_sendMessage);
}

void Heavy_CircleStrings::cDelay_n49qp1mH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n49qp1mH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UhjjQJZy, 0, m, &cDelay_UhjjQJZy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n49qp1mH, 0, m, &cDelay_n49qp1mH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y1R9JQ77, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_UhjjQJZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UhjjQJZy, m);
  cMsg_latOzJHV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_kjxpwiie_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_SnWFVZ8Y_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_vb2bAgds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qoqBTjab_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_MOC6tDsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PDgAmmbs_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n49qp1mH, 2, m, &cDelay_n49qp1mH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_APNGv0k7_sendMessage);
}

void Heavy_CircleStrings::cMsg_qoqBTjab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_MOC6tDsa, 0, m, &hTable_MOC6tDsa_sendMessage);
}

void Heavy_CircleStrings::cBinop_xyytEhpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_vb2bAgds_sendMessage);
}

void Heavy_CircleStrings::cMsg_latOzJHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_MOC6tDsa, 0, m, &hTable_MOC6tDsa_sendMessage);
}

void Heavy_CircleStrings::cCast_APNGv0k7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_n49qp1mH, 0, m, &cDelay_n49qp1mH_sendMessage);
}

void Heavy_CircleStrings::cMsg_PDgAmmbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_UhjjQJZy, 2, m, &cDelay_UhjjQJZy_sendMessage);
}

void Heavy_CircleStrings::cMsg_SnWFVZ8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y1R9JQ77, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_UBXFCR4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_wIl1dRGf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_2h96SYnU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_ek9IlOOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fz7vCqYU, HV_BINOP_POW, 0, m, &cBinop_Fz7vCqYU_sendMessage);
}

void Heavy_CircleStrings::cBinop_Fz7vCqYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_JfuaYpnh_sendMessage);
}

void Heavy_CircleStrings::cBinop_4DOfVqdK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_7G6ORZiX_sendMessage);
}

void Heavy_CircleStrings::cCast_UnqNwp4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UBXFCR4l, 0, m, &cIf_UBXFCR4l_sendMessage);
}

void Heavy_CircleStrings::cCast_nQtkb7Ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_LAEIR681_sendMessage);
}

void Heavy_CircleStrings::cBinop_LAEIR681_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UBXFCR4l, 1, m, &cIf_UBXFCR4l_sendMessage);
}

void Heavy_CircleStrings::cBinop_2h96SYnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_4DOfVqdK_sendMessage);
}

void Heavy_CircleStrings::cMsg_wIl1dRGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_JfuaYpnh_sendMessage);
}

void Heavy_CircleStrings::cBinop_7G6ORZiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fz7vCqYU, HV_BINOP_POW, 1, m, &cBinop_Fz7vCqYU_sendMessage);
  cMsg_ek9IlOOr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_tRfDYkVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MeGrBbyJ, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_FTTsOLAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LdjwLzWr, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_LHEtYng2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZrNHkCG9_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZrNHkCG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_bus2eawT_sendMessage);
}

void Heavy_CircleStrings::cVar_3tS9eshW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ag66imTS, HV_BINOP_MULTIPLY, 0, m, &cBinop_ag66imTS_sendMessage);
}

void Heavy_CircleStrings::cMsg_JlSiSGxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QeOEVhlD_sendMessage);
}

void Heavy_CircleStrings::cSystem_QeOEVhlD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tkV2PLSA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_ag66imTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RAplxjVz_sendMessage);
}

void Heavy_CircleStrings::cBinop_QYCw7pk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ag66imTS, HV_BINOP_MULTIPLY, 1, m, &cBinop_ag66imTS_sendMessage);
}

void Heavy_CircleStrings::cMsg_tkV2PLSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QYCw7pk7_sendMessage);
}

void Heavy_CircleStrings::cBinop_RAplxjVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_hxdfk7e0_sendMessage);
}

void Heavy_CircleStrings::cBinop_hxdfk7e0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wGpruqM0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pRf6uupF, m);
}

void Heavy_CircleStrings::cBinop_wGpruqM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MW6AEA72, m);
}

void Heavy_CircleStrings::cVar_mFUQuxBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nQtkb7Ow_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UnqNwp4h_sendMessage);
}

void Heavy_CircleStrings::cVar_aMck80M5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_LHEtYng2_sendMessage);
}

void Heavy_CircleStrings::cVar_fkA3ZK9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_TNJ4hGUJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NRY4IS4w, 0, m, &cIf_NRY4IS4w_sendMessage);
}

void Heavy_CircleStrings::cVar_mlcYFQEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_YgdSKLhN_sendMessage);
}

void Heavy_CircleStrings::cIf_NRY4IS4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_F9FdiM1o_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_xY3fWPIa, 0, m, &cVar_xY3fWPIa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_TNJ4hGUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NRY4IS4w, 1, m, &cIf_NRY4IS4w_sendMessage);
}

void Heavy_CircleStrings::cBinop_YgdSKLhN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IgV9AWSd_sendMessage);
}

void Heavy_CircleStrings::cBinop_IgV9AWSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VhRPU3sy, 0, m, &cVar_VhRPU3sy_sendMessage);
}

void Heavy_CircleStrings::cTabhead_IPGyyXtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PBR2MlFZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_PBR2MlFZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_fKhapxFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_67DgVMG1_sendMessage);
}

void Heavy_CircleStrings::cSystem_67DgVMG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qpMNJG2L_sendMessage);
}

void Heavy_CircleStrings::cVar_F7BxyhZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CPsWu2Fb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_WPia0yT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WPia0yT2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1iETFbXc, 0, m, &cDelay_1iETFbXc_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_x09EXuAJ, 0, m, &sTabread_x09EXuAJ_sendMessage);
}

void Heavy_CircleStrings::cDelay_1iETFbXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1iETFbXc, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_x09EXuAJ, 0, m, &sTabread_x09EXuAJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1iETFbXc, 0, m, &cDelay_1iETFbXc_sendMessage);
}

void Heavy_CircleStrings::sTabread_x09EXuAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_iWn7CzHu, HV_BINOP_SUBTRACT, 0, m, &cBinop_iWn7CzHu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_lqHH5Kan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rDfRyEft, HV_BINOP_MAX, 0, m, &cBinop_rDfRyEft_sendMessage);
}

void Heavy_CircleStrings::cBinop_qpMNJG2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lqHH5Kan, HV_BINOP_MULTIPLY, 0, m, &cBinop_lqHH5Kan_sendMessage);
}

void Heavy_CircleStrings::cBinop_PBR2MlFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ER7Xg9do_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_x09EXuAJ, 0, m, &sTabread_x09EXuAJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RHKJNTLH_sendMessage);
}

void Heavy_CircleStrings::cSystem_12oFAP0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iWn7CzHu, HV_BINOP_SUBTRACT, 1, m, &cBinop_iWn7CzHu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1iETFbXc, 2, m, &cDelay_1iETFbXc_sendMessage);
}

void Heavy_CircleStrings::cMsg_CPsWu2Fb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_12oFAP0D_sendMessage);
}

void Heavy_CircleStrings::cMsg_ER7Xg9do_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WPia0yT2, 0, m, &cDelay_WPia0yT2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1iETFbXc, 0, m, &cDelay_1iETFbXc_sendMessage);
}

void Heavy_CircleStrings::cMsg_a9PJEENs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_rDfRyEft, HV_BINOP_MAX, 1, m, &cBinop_rDfRyEft_sendMessage);
}

void Heavy_CircleStrings::cBinop_rDfRyEft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PBR2MlFZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_PBR2MlFZ_sendMessage);
}

void Heavy_CircleStrings::cCast_RHKJNTLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WPia0yT2, 0, m, &cDelay_WPia0yT2_sendMessage);
}

void Heavy_CircleStrings::cBinop_ABNzJybI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WPia0yT2, 2, m, &cDelay_WPia0yT2_sendMessage);
}

void Heavy_CircleStrings::cBinop_iWn7CzHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ABNzJybI_sendMessage);
}

void Heavy_CircleStrings::cCast_I93bhCnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F7BxyhZW, 0, m, &cVar_F7BxyhZW_sendMessage);
  cMsg_fKhapxFv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IPGyyXtZ, 0, m, &cTabhead_IPGyyXtZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_rCwsEbzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_z2PFwVfv_sendMessage);
}

void Heavy_CircleStrings::cSystem_z2PFwVfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CWqsYL9y_sendMessage);
}

void Heavy_CircleStrings::cDelay_sop3yjxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sop3yjxG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Agcuxfqm, 0, m, &cDelay_Agcuxfqm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sop3yjxG, 0, m, &cDelay_sop3yjxG_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_J5xvzRJl, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Agcuxfqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Agcuxfqm, m);
  cMsg_y5C6wP53_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_VeX9A3g8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mD65mStD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Ama6gPXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oCQrUKMJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_JVMiFZGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xoS9Cybl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sop3yjxG, 2, m, &cDelay_sop3yjxG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pljjsJFF_sendMessage);
}

void Heavy_CircleStrings::cMsg_oCQrUKMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_JVMiFZGC, 0, m, &hTable_JVMiFZGC_sendMessage);
}

void Heavy_CircleStrings::cBinop_CWqsYL9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_Ama6gPXE_sendMessage);
}

void Heavy_CircleStrings::cMsg_y5C6wP53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_JVMiFZGC, 0, m, &hTable_JVMiFZGC_sendMessage);
}

void Heavy_CircleStrings::cCast_pljjsJFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sop3yjxG, 0, m, &cDelay_sop3yjxG_sendMessage);
}

void Heavy_CircleStrings::cMsg_xoS9Cybl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Agcuxfqm, 2, m, &cDelay_Agcuxfqm_sendMessage);
}

void Heavy_CircleStrings::cMsg_mD65mStD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_J5xvzRJl, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_YCr8qba4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0p7KdTJw, HV_BINOP_SUBTRACT, 0, m, &cBinop_0p7KdTJw_sendMessage);
}

void Heavy_CircleStrings::cMsg_XpW7vur6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Sx7gFhb9_sendMessage);
}

void Heavy_CircleStrings::cSystem_Sx7gFhb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FmBKqhKm_sendMessage);
}

void Heavy_CircleStrings::cVar_JAVoiuNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AReZBRts_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_hnV09xUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hnV09xUp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cBauw0wQ, 0, m, &cDelay_cBauw0wQ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9yNExyvS, 0, m, &sTabread_9yNExyvS_sendMessage);
}

void Heavy_CircleStrings::cDelay_cBauw0wQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cBauw0wQ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9yNExyvS, 0, m, &sTabread_9yNExyvS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cBauw0wQ, 0, m, &cDelay_cBauw0wQ_sendMessage);
}

void Heavy_CircleStrings::sTabread_9yNExyvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LnHaCvOe, HV_BINOP_SUBTRACT, 0, m, &cBinop_LnHaCvOe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_5bob6RNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NvtFRbNM, HV_BINOP_MAX, 0, m, &cBinop_NvtFRbNM_sendMessage);
}

void Heavy_CircleStrings::cBinop_FmBKqhKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5bob6RNC, HV_BINOP_MULTIPLY, 0, m, &cBinop_5bob6RNC_sendMessage);
}

void Heavy_CircleStrings::cBinop_0p7KdTJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QkgbanxZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9yNExyvS, 0, m, &sTabread_9yNExyvS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8YDFALWU_sendMessage);
}

void Heavy_CircleStrings::cSystem_OBp6hbPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LnHaCvOe, HV_BINOP_SUBTRACT, 1, m, &cBinop_LnHaCvOe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cBauw0wQ, 2, m, &cDelay_cBauw0wQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_AReZBRts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OBp6hbPR_sendMessage);
}

void Heavy_CircleStrings::cMsg_QkgbanxZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hnV09xUp, 0, m, &cDelay_hnV09xUp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cBauw0wQ, 0, m, &cDelay_cBauw0wQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_ISiln9El_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_NvtFRbNM, HV_BINOP_MAX, 1, m, &cBinop_NvtFRbNM_sendMessage);
}

void Heavy_CircleStrings::cBinop_NvtFRbNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0p7KdTJw, HV_BINOP_SUBTRACT, 1, m, &cBinop_0p7KdTJw_sendMessage);
}

void Heavy_CircleStrings::cCast_8YDFALWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hnV09xUp, 0, m, &cDelay_hnV09xUp_sendMessage);
}

void Heavy_CircleStrings::cBinop_np8NRnZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hnV09xUp, 2, m, &cDelay_hnV09xUp_sendMessage);
}

void Heavy_CircleStrings::cBinop_LnHaCvOe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_np8NRnZZ_sendMessage);
}

void Heavy_CircleStrings::cCast_wDOk2RQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JAVoiuNw, 0, m, &cVar_JAVoiuNw_sendMessage);
  cMsg_XpW7vur6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YCr8qba4, 0, m, &cTabhead_YCr8qba4_sendMessage);
}

void Heavy_CircleStrings::cMsg_hJC8dSAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nz32fddm_sendMessage);
}

void Heavy_CircleStrings::cSystem_nz32fddm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eXcftRJy_sendMessage);
}

void Heavy_CircleStrings::cDelay_DdpaYfRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DdpaYfRB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DjN7YO7J, 0, m, &cDelay_DjN7YO7J_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DdpaYfRB, 0, m, &cDelay_DdpaYfRB_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_h1URavD2, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_DjN7YO7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DjN7YO7J, m);
  cMsg_UMWgpKrF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_15JC9rKT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_TJa2OwE8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_3LD4hpsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CY6ayXdC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_gsDd3hqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4JlIhAgr_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DdpaYfRB, 2, m, &cDelay_DdpaYfRB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rrPygjMi_sendMessage);
}

void Heavy_CircleStrings::cMsg_CY6ayXdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gsDd3hqv, 0, m, &hTable_gsDd3hqv_sendMessage);
}

void Heavy_CircleStrings::cBinop_eXcftRJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_3LD4hpsl_sendMessage);
}

void Heavy_CircleStrings::cMsg_UMWgpKrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gsDd3hqv, 0, m, &hTable_gsDd3hqv_sendMessage);
}

void Heavy_CircleStrings::cCast_rrPygjMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DdpaYfRB, 0, m, &cDelay_DdpaYfRB_sendMessage);
}

void Heavy_CircleStrings::cMsg_4JlIhAgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_DjN7YO7J, 2, m, &cDelay_DjN7YO7J_sendMessage);
}

void Heavy_CircleStrings::cMsg_TJa2OwE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_h1URavD2, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_A9nNmf3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j2PrqYDP, HV_BINOP_SUBTRACT, 0, m, &cBinop_j2PrqYDP_sendMessage);
}

void Heavy_CircleStrings::cMsg_9XDYKkKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZSBtV6Gr_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZSBtV6Gr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hwsygbYb_sendMessage);
}

void Heavy_CircleStrings::cVar_FtSLFjCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VhYFfOcK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_q4J09Ty1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_q4J09Ty1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_07r6V6pB, 0, m, &cDelay_07r6V6pB_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Yyf3yfZY, 0, m, &sTabread_Yyf3yfZY_sendMessage);
}

void Heavy_CircleStrings::cDelay_07r6V6pB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_07r6V6pB, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Yyf3yfZY, 0, m, &sTabread_Yyf3yfZY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_07r6V6pB, 0, m, &cDelay_07r6V6pB_sendMessage);
}

void Heavy_CircleStrings::sTabread_Yyf3yfZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_U9UhS71i, HV_BINOP_SUBTRACT, 0, m, &cBinop_U9UhS71i_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_LblE0XCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wB2WAWtP, HV_BINOP_MAX, 0, m, &cBinop_wB2WAWtP_sendMessage);
}

void Heavy_CircleStrings::cBinop_hwsygbYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LblE0XCJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_LblE0XCJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_j2PrqYDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BJJbrQlY_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Yyf3yfZY, 0, m, &sTabread_Yyf3yfZY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KfkOaER5_sendMessage);
}

void Heavy_CircleStrings::cSystem_mn7nBqZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U9UhS71i, HV_BINOP_SUBTRACT, 1, m, &cBinop_U9UhS71i_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_07r6V6pB, 2, m, &cDelay_07r6V6pB_sendMessage);
}

void Heavy_CircleStrings::cMsg_VhYFfOcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mn7nBqZ7_sendMessage);
}

void Heavy_CircleStrings::cMsg_BJJbrQlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_q4J09Ty1, 0, m, &cDelay_q4J09Ty1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_07r6V6pB, 0, m, &cDelay_07r6V6pB_sendMessage);
}

void Heavy_CircleStrings::cMsg_jO3hjnK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_wB2WAWtP, HV_BINOP_MAX, 1, m, &cBinop_wB2WAWtP_sendMessage);
}

void Heavy_CircleStrings::cBinop_wB2WAWtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j2PrqYDP, HV_BINOP_SUBTRACT, 1, m, &cBinop_j2PrqYDP_sendMessage);
}

void Heavy_CircleStrings::cCast_KfkOaER5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q4J09Ty1, 0, m, &cDelay_q4J09Ty1_sendMessage);
}

void Heavy_CircleStrings::cBinop_MZ2aOR0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q4J09Ty1, 2, m, &cDelay_q4J09Ty1_sendMessage);
}

void Heavy_CircleStrings::cBinop_U9UhS71i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MZ2aOR0d_sendMessage);
}

void Heavy_CircleStrings::cCast_Im0amkCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FtSLFjCT, 0, m, &cVar_FtSLFjCT_sendMessage);
  cMsg_9XDYKkKo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_A9nNmf3d, 0, m, &cTabhead_A9nNmf3d_sendMessage);
}

void Heavy_CircleStrings::cMsg_xKZ6gHtp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JCUIiIYz_sendMessage);
}

void Heavy_CircleStrings::cSystem_JCUIiIYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FvCRnL7V_sendMessage);
}

void Heavy_CircleStrings::cDelay_wALcQ2bu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wALcQ2bu, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dErD2F63, 0, m, &cDelay_dErD2F63_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wALcQ2bu, 0, m, &cDelay_wALcQ2bu_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7Lft8yI6, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_dErD2F63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dErD2F63, m);
  cMsg_1mBaJZjw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_mVYMD0c7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LdwckXKo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_zmk2Ocqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7gcnbh20_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_ys24awdF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I4kI0jhh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wALcQ2bu, 2, m, &cDelay_wALcQ2bu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ePNw5mmE_sendMessage);
}

void Heavy_CircleStrings::cMsg_7gcnbh20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ys24awdF, 0, m, &hTable_ys24awdF_sendMessage);
}

void Heavy_CircleStrings::cBinop_FvCRnL7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_zmk2Ocqq_sendMessage);
}

void Heavy_CircleStrings::cMsg_1mBaJZjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ys24awdF, 0, m, &hTable_ys24awdF_sendMessage);
}

void Heavy_CircleStrings::cCast_ePNw5mmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wALcQ2bu, 0, m, &cDelay_wALcQ2bu_sendMessage);
}

void Heavy_CircleStrings::cMsg_I4kI0jhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_dErD2F63, 2, m, &cDelay_dErD2F63_sendMessage);
}

void Heavy_CircleStrings::cMsg_LdwckXKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7Lft8yI6, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_gVYNU4CM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8hCOX65E, HV_BINOP_SUBTRACT, 0, m, &cBinop_8hCOX65E_sendMessage);
}

void Heavy_CircleStrings::cMsg_O7wALQAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K20s4s3Q_sendMessage);
}

void Heavy_CircleStrings::cSystem_K20s4s3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xK7WM2SD_sendMessage);
}

void Heavy_CircleStrings::cVar_Cx09uEGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M2rToJMg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_BVpmswiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BVpmswiW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V2jNJ22k, 0, m, &cDelay_V2jNJ22k_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bHt6HYwn, 0, m, &sTabread_bHt6HYwn_sendMessage);
}

void Heavy_CircleStrings::cDelay_V2jNJ22k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V2jNJ22k, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bHt6HYwn, 0, m, &sTabread_bHt6HYwn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V2jNJ22k, 0, m, &cDelay_V2jNJ22k_sendMessage);
}

void Heavy_CircleStrings::sTabread_bHt6HYwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6N69gnjm, HV_BINOP_SUBTRACT, 0, m, &cBinop_6N69gnjm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_vqqbLitF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OexIOzk3, HV_BINOP_MAX, 0, m, &cBinop_OexIOzk3_sendMessage);
}

void Heavy_CircleStrings::cBinop_xK7WM2SD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vqqbLitF, HV_BINOP_MULTIPLY, 0, m, &cBinop_vqqbLitF_sendMessage);
}

void Heavy_CircleStrings::cBinop_8hCOX65E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nEkBgzJG_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bHt6HYwn, 0, m, &sTabread_bHt6HYwn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7HRuE6aI_sendMessage);
}

void Heavy_CircleStrings::cSystem_L4XkuxDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6N69gnjm, HV_BINOP_SUBTRACT, 1, m, &cBinop_6N69gnjm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V2jNJ22k, 2, m, &cDelay_V2jNJ22k_sendMessage);
}

void Heavy_CircleStrings::cMsg_M2rToJMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L4XkuxDJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_nEkBgzJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BVpmswiW, 0, m, &cDelay_BVpmswiW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V2jNJ22k, 0, m, &cDelay_V2jNJ22k_sendMessage);
}

void Heavy_CircleStrings::cMsg_lQjvEb2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_OexIOzk3, HV_BINOP_MAX, 1, m, &cBinop_OexIOzk3_sendMessage);
}

void Heavy_CircleStrings::cBinop_OexIOzk3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8hCOX65E, HV_BINOP_SUBTRACT, 1, m, &cBinop_8hCOX65E_sendMessage);
}

void Heavy_CircleStrings::cCast_7HRuE6aI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BVpmswiW, 0, m, &cDelay_BVpmswiW_sendMessage);
}

void Heavy_CircleStrings::cBinop_Oah62lUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BVpmswiW, 2, m, &cDelay_BVpmswiW_sendMessage);
}

void Heavy_CircleStrings::cBinop_6N69gnjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Oah62lUf_sendMessage);
}

void Heavy_CircleStrings::cCast_eVQjafqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Cx09uEGP, 0, m, &cVar_Cx09uEGP_sendMessage);
  cMsg_O7wALQAZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_gVYNU4CM, 0, m, &cTabhead_gVYNU4CM_sendMessage);
}

void Heavy_CircleStrings::cMsg_h0DXSyXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ESmiWX4W_sendMessage);
}

void Heavy_CircleStrings::cSystem_ESmiWX4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gt2DLxe8_sendMessage);
}

void Heavy_CircleStrings::cDelay_EofgqkqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EofgqkqE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Sp6WEEsU, 0, m, &cDelay_Sp6WEEsU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EofgqkqE, 0, m, &cDelay_EofgqkqE_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_d4L2GaBr, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Sp6WEEsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Sp6WEEsU, m);
  cMsg_cjLXftl6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_RjnYFEvf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_20jRxkTx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_GZsoL30E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p5q8B9aP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_jE20V2t5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RNsSDACD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EofgqkqE, 2, m, &cDelay_EofgqkqE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oFoFUyWr_sendMessage);
}

void Heavy_CircleStrings::cMsg_p5q8B9aP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jE20V2t5, 0, m, &hTable_jE20V2t5_sendMessage);
}

void Heavy_CircleStrings::cBinop_gt2DLxe8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_GZsoL30E_sendMessage);
}

void Heavy_CircleStrings::cMsg_cjLXftl6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jE20V2t5, 0, m, &hTable_jE20V2t5_sendMessage);
}

void Heavy_CircleStrings::cCast_oFoFUyWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EofgqkqE, 0, m, &cDelay_EofgqkqE_sendMessage);
}

void Heavy_CircleStrings::cMsg_RNsSDACD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Sp6WEEsU, 2, m, &cDelay_Sp6WEEsU_sendMessage);
}

void Heavy_CircleStrings::cMsg_20jRxkTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_d4L2GaBr, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_tjCiFHQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SegciK1p, HV_BINOP_SUBTRACT, 0, m, &cBinop_SegciK1p_sendMessage);
}

void Heavy_CircleStrings::cMsg_fvUisdR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kyh2NCuX_sendMessage);
}

void Heavy_CircleStrings::cSystem_kyh2NCuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7nSFm2Vf_sendMessage);
}

void Heavy_CircleStrings::cVar_TfXe9wyE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QFMv52iq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_nGJGMQUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nGJGMQUA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fxaHI9Ad, 0, m, &cDelay_fxaHI9Ad_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_UaTcgfZJ, 0, m, &sTabread_UaTcgfZJ_sendMessage);
}

void Heavy_CircleStrings::cDelay_fxaHI9Ad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fxaHI9Ad, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_UaTcgfZJ, 0, m, &sTabread_UaTcgfZJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fxaHI9Ad, 0, m, &cDelay_fxaHI9Ad_sendMessage);
}

void Heavy_CircleStrings::sTabread_UaTcgfZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_lA7Eb9yb, HV_BINOP_SUBTRACT, 0, m, &cBinop_lA7Eb9yb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KKlFYf5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s96r2QbU, HV_BINOP_MAX, 0, m, &cBinop_s96r2QbU_sendMessage);
}

void Heavy_CircleStrings::cBinop_7nSFm2Vf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KKlFYf5D, HV_BINOP_MULTIPLY, 0, m, &cBinop_KKlFYf5D_sendMessage);
}

void Heavy_CircleStrings::cBinop_SegciK1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mXhQdzNG_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_UaTcgfZJ, 0, m, &sTabread_UaTcgfZJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DK1dtRJv_sendMessage);
}

void Heavy_CircleStrings::cSystem_gQGyhl44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lA7Eb9yb, HV_BINOP_SUBTRACT, 1, m, &cBinop_lA7Eb9yb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fxaHI9Ad, 2, m, &cDelay_fxaHI9Ad_sendMessage);
}

void Heavy_CircleStrings::cMsg_QFMv52iq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gQGyhl44_sendMessage);
}

void Heavy_CircleStrings::cMsg_mXhQdzNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nGJGMQUA, 0, m, &cDelay_nGJGMQUA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fxaHI9Ad, 0, m, &cDelay_fxaHI9Ad_sendMessage);
}

void Heavy_CircleStrings::cMsg_b2w8c18C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_s96r2QbU, HV_BINOP_MAX, 1, m, &cBinop_s96r2QbU_sendMessage);
}

void Heavy_CircleStrings::cBinop_s96r2QbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SegciK1p, HV_BINOP_SUBTRACT, 1, m, &cBinop_SegciK1p_sendMessage);
}

void Heavy_CircleStrings::cCast_DK1dtRJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nGJGMQUA, 0, m, &cDelay_nGJGMQUA_sendMessage);
}

void Heavy_CircleStrings::cBinop_rqlbnfrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nGJGMQUA, 2, m, &cDelay_nGJGMQUA_sendMessage);
}

void Heavy_CircleStrings::cBinop_lA7Eb9yb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rqlbnfrf_sendMessage);
}

void Heavy_CircleStrings::cCast_e8nIXl6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TfXe9wyE, 0, m, &cVar_TfXe9wyE_sendMessage);
  cMsg_fvUisdR6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_tjCiFHQd, 0, m, &cTabhead_tjCiFHQd_sendMessage);
}

void Heavy_CircleStrings::cMsg_PYwNSVk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kKaU2E8g_sendMessage);
}

void Heavy_CircleStrings::cSystem_kKaU2E8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_76jyJaun_sendMessage);
}

void Heavy_CircleStrings::cDelay_l04AykXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_l04AykXk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mP4RKVHl, 0, m, &cDelay_mP4RKVHl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l04AykXk, 0, m, &cDelay_l04AykXk_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PKgvwBUX, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_mP4RKVHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mP4RKVHl, m);
  cMsg_kHtN9kjg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_NjIkGh2O_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_EvM9d1dt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_QPZiffDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_seaNCo3f_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_R5Orrj0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Su6SIiDu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l04AykXk, 2, m, &cDelay_l04AykXk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C12750Fl_sendMessage);
}

void Heavy_CircleStrings::cMsg_seaNCo3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_R5Orrj0z, 0, m, &hTable_R5Orrj0z_sendMessage);
}

void Heavy_CircleStrings::cBinop_76jyJaun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_QPZiffDL_sendMessage);
}

void Heavy_CircleStrings::cMsg_kHtN9kjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_R5Orrj0z, 0, m, &hTable_R5Orrj0z_sendMessage);
}

void Heavy_CircleStrings::cCast_C12750Fl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_l04AykXk, 0, m, &cDelay_l04AykXk_sendMessage);
}

void Heavy_CircleStrings::cMsg_Su6SIiDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_mP4RKVHl, 2, m, &cDelay_mP4RKVHl_sendMessage);
}

void Heavy_CircleStrings::cMsg_EvM9d1dt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PKgvwBUX, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_IPLmjjI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hq3tcvRi, HV_BINOP_SUBTRACT, 0, m, &cBinop_hq3tcvRi_sendMessage);
}

void Heavy_CircleStrings::cMsg_KFglmPdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rAmlm9cK_sendMessage);
}

void Heavy_CircleStrings::cSystem_rAmlm9cK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XqcUclJf_sendMessage);
}

void Heavy_CircleStrings::cVar_drspUFZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LWR3yK4e_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Ba8N8kQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ba8N8kQ9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NVNRHviJ, 0, m, &cDelay_NVNRHviJ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_s9frQrjK, 0, m, &sTabread_s9frQrjK_sendMessage);
}

void Heavy_CircleStrings::cDelay_NVNRHviJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NVNRHviJ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_s9frQrjK, 0, m, &sTabread_s9frQrjK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NVNRHviJ, 0, m, &cDelay_NVNRHviJ_sendMessage);
}

void Heavy_CircleStrings::sTabread_s9frQrjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_tJOwuC6Z, HV_BINOP_SUBTRACT, 0, m, &cBinop_tJOwuC6Z_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_kgLHvzfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EkMkGU9g, HV_BINOP_MAX, 0, m, &cBinop_EkMkGU9g_sendMessage);
}

void Heavy_CircleStrings::cBinop_XqcUclJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kgLHvzfo, HV_BINOP_MULTIPLY, 0, m, &cBinop_kgLHvzfo_sendMessage);
}

void Heavy_CircleStrings::cBinop_hq3tcvRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QbUbhnyF_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_s9frQrjK, 0, m, &sTabread_s9frQrjK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SVN7d4QZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_5Z51Xso2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tJOwuC6Z, HV_BINOP_SUBTRACT, 1, m, &cBinop_tJOwuC6Z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NVNRHviJ, 2, m, &cDelay_NVNRHviJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_LWR3yK4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5Z51Xso2_sendMessage);
}

void Heavy_CircleStrings::cMsg_QbUbhnyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ba8N8kQ9, 0, m, &cDelay_Ba8N8kQ9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NVNRHviJ, 0, m, &cDelay_NVNRHviJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_bHVsO9WV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_EkMkGU9g, HV_BINOP_MAX, 1, m, &cBinop_EkMkGU9g_sendMessage);
}

void Heavy_CircleStrings::cBinop_EkMkGU9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hq3tcvRi, HV_BINOP_SUBTRACT, 1, m, &cBinop_hq3tcvRi_sendMessage);
}

void Heavy_CircleStrings::cCast_SVN7d4QZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ba8N8kQ9, 0, m, &cDelay_Ba8N8kQ9_sendMessage);
}

void Heavy_CircleStrings::cBinop_0K0YztZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ba8N8kQ9, 2, m, &cDelay_Ba8N8kQ9_sendMessage);
}

void Heavy_CircleStrings::cBinop_tJOwuC6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0K0YztZg_sendMessage);
}

void Heavy_CircleStrings::cCast_pbzF9ROK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_drspUFZO, 0, m, &cVar_drspUFZO_sendMessage);
  cMsg_KFglmPdg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IPLmjjI5, 0, m, &cTabhead_IPLmjjI5_sendMessage);
}

void Heavy_CircleStrings::cMsg_KaPy31CN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D452SEDp_sendMessage);
}

void Heavy_CircleStrings::cSystem_D452SEDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8qUwajYO_sendMessage);
}

void Heavy_CircleStrings::cDelay_oTzS0hhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oTzS0hhX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m6WgKhtg, 0, m, &cDelay_m6WgKhtg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oTzS0hhX, 0, m, &cDelay_oTzS0hhX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Wj6AdG4V, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_m6WgKhtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_m6WgKhtg, m);
  cMsg_fG36rkYd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_uf0Qsovf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_G7YMH9r4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_mThF3r2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FhtzH71K_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_4q4El3xx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4RpH7vCc_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oTzS0hhX, 2, m, &cDelay_oTzS0hhX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ski6vuDT_sendMessage);
}

void Heavy_CircleStrings::cMsg_FhtzH71K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_4q4El3xx, 0, m, &hTable_4q4El3xx_sendMessage);
}

void Heavy_CircleStrings::cBinop_8qUwajYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_mThF3r2W_sendMessage);
}

void Heavy_CircleStrings::cMsg_fG36rkYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_4q4El3xx, 0, m, &hTable_4q4El3xx_sendMessage);
}

void Heavy_CircleStrings::cCast_Ski6vuDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oTzS0hhX, 0, m, &cDelay_oTzS0hhX_sendMessage);
}

void Heavy_CircleStrings::cMsg_4RpH7vCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_m6WgKhtg, 2, m, &cDelay_m6WgKhtg_sendMessage);
}

void Heavy_CircleStrings::cMsg_G7YMH9r4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Wj6AdG4V, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_xY3fWPIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3tS9eshW, 0, m, &cVar_3tS9eshW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xO0rjc0C, 0, m, &cVar_xO0rjc0C_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rBhchbRu, 0, m, &cVar_rBhchbRu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AYY8j1VC, 0, m, &cVar_AYY8j1VC_sendMessage);
}

void Heavy_CircleStrings::cVar_VhRPU3sy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_R6NkgnwP_sendMessage);
}

void Heavy_CircleStrings::cPack_qJNt1E2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RSnnUeg9, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_xO0rjc0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XFJ6fcEx, HV_BINOP_MULTIPLY, 0, m, &cBinop_XFJ6fcEx_sendMessage);
}

void Heavy_CircleStrings::cMsg_3muTb6UM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jbrlIqGl_sendMessage);
}

void Heavy_CircleStrings::cSystem_jbrlIqGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Od1tcHTZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_XFJ6fcEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_52QgCEIX_sendMessage);
}

void Heavy_CircleStrings::cBinop_zNA9pmeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XFJ6fcEx, HV_BINOP_MULTIPLY, 1, m, &cBinop_XFJ6fcEx_sendMessage);
}

void Heavy_CircleStrings::cMsg_Od1tcHTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zNA9pmeF_sendMessage);
}

void Heavy_CircleStrings::cBinop_52QgCEIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GT8zfExa_sendMessage);
}

void Heavy_CircleStrings::cBinop_GT8zfExa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_NeLzGRjT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ry63o3TX, m);
}

void Heavy_CircleStrings::cBinop_NeLzGRjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yTULe0gK, m);
}

void Heavy_CircleStrings::cVar_rBhchbRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nmwfxwk8, HV_BINOP_MULTIPLY, 0, m, &cBinop_Nmwfxwk8_sendMessage);
}

void Heavy_CircleStrings::cMsg_XoWpQDt4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qf9uFAQR_sendMessage);
}

void Heavy_CircleStrings::cSystem_Qf9uFAQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dEP3mc5a_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Nmwfxwk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fPKT6Tpm_sendMessage);
}

void Heavy_CircleStrings::cBinop_4BJj9ZdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nmwfxwk8, HV_BINOP_MULTIPLY, 1, m, &cBinop_Nmwfxwk8_sendMessage);
}

void Heavy_CircleStrings::cMsg_dEP3mc5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4BJj9ZdC_sendMessage);
}

void Heavy_CircleStrings::cBinop_fPKT6Tpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WFfJGNFP_sendMessage);
}

void Heavy_CircleStrings::cBinop_WFfJGNFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fx0ZjrBJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VVnOKafp, m);
}

void Heavy_CircleStrings::cBinop_fx0ZjrBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sQJ8VEya, m);
}

void Heavy_CircleStrings::cVar_AYY8j1VC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IewrL0YV, HV_BINOP_MULTIPLY, 0, m, &cBinop_IewrL0YV_sendMessage);
}

void Heavy_CircleStrings::cMsg_tYKRTQM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9D6Zvd5X_sendMessage);
}

void Heavy_CircleStrings::cSystem_9D6Zvd5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PNHVkIkf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_IewrL0YV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0VjOXyYT_sendMessage);
}

void Heavy_CircleStrings::cBinop_MG3mgvbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IewrL0YV, HV_BINOP_MULTIPLY, 1, m, &cBinop_IewrL0YV_sendMessage);
}

void Heavy_CircleStrings::cMsg_PNHVkIkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MG3mgvbp_sendMessage);
}

void Heavy_CircleStrings::cBinop_0VjOXyYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kZ6w49Tn_sendMessage);
}

void Heavy_CircleStrings::cBinop_kZ6w49Tn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_PjxhTlv4_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_45mK77DY, m);
}

void Heavy_CircleStrings::cBinop_PjxhTlv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_acJo6RJ9, m);
}

void Heavy_CircleStrings::cBinop_bus2eawT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FTTsOLAf, 0, m, &cPack_FTTsOLAf_sendMessage);
}

void Heavy_CircleStrings::cMsg_F9FdiM1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_xY3fWPIa, 0, m, &cVar_xY3fWPIa_sendMessage);
}

void Heavy_CircleStrings::cBinop_R6NkgnwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qJNt1E2j, 0, m, &cPack_qJNt1E2j_sendMessage);
}

void Heavy_CircleStrings::cBinop_JfuaYpnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tRfDYkVG, 0, m, &cPack_tRfDYkVG_sendMessage);
}

void Heavy_CircleStrings::cIf_B6y403k3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_yvGDsK2G_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_vf8cS8ZL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_vf8cS8ZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_95AFGAyb_sendMessage);
}

void Heavy_CircleStrings::cCast_ulw4G7QH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_B6y403k3, 0, m, &cIf_B6y403k3_sendMessage);
}

void Heavy_CircleStrings::cCast_1qKTPYYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_3XWENlRm_sendMessage);
}

void Heavy_CircleStrings::cMsg_yvGDsK2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_mFUQuxBp, 0, m, &cVar_mFUQuxBp_sendMessage);
}

void Heavy_CircleStrings::cBinop_95AFGAyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_m2QwppXB_sendMessage);
}

void Heavy_CircleStrings::cBinop_m2QwppXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Be6aEano_sendMessage);
}

void Heavy_CircleStrings::cBinop_Be6aEano_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mFUQuxBp, 0, m, &cVar_mFUQuxBp_sendMessage);
}

void Heavy_CircleStrings::cBinop_3XWENlRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_B6y403k3, 1, m, &cIf_B6y403k3_sendMessage);
}

void Heavy_CircleStrings::cBinop_8JOAQ08A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1qKTPYYg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ulw4G7QH_sendMessage);
}

void Heavy_CircleStrings::cBinop_zvFm2J64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8JOAQ08A_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_hybV6izI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_rNo3OZaC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_rNo3OZaC_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_CzJ1AVkE, 1, m, &cDelay_CzJ1AVkE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cTo6xJeu_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_CzJ1AVkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CzJ1AVkE, m);
  cMsg_SwBw0d4y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_rNo3OZaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CzJ1AVkE, 0, m, &cDelay_CzJ1AVkE_sendMessage);
}

void Heavy_CircleStrings::cCast_cTo6xJeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CzJ1AVkE, 0, m, &cDelay_CzJ1AVkE_sendMessage);
}

void Heavy_CircleStrings::cVar_KhhfLswt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uYedG795, 0, m, &cPack_uYedG795_sendMessage);
}

void Heavy_CircleStrings::cVar_ew5o4KWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_D87KSqJV_sendMessage);
}

void Heavy_CircleStrings::cVar_c212H3Ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_JYyyiKVH_sendMessage);
}

void Heavy_CircleStrings::cPack_r728iCDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_FOuZgC9t, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_7uTXbUNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QUTJ0ZUB_sendMessage);
}

void Heavy_CircleStrings::cBinop_xuwi8xNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_7uTXbUNn_sendMessage);
}

void Heavy_CircleStrings::cPack_FhtpVoZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_WhvUAi9Y, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_6J8CuTNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_TQ1nmaq5_sendMessage);
}

void Heavy_CircleStrings::cMsg_RGz1axTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WhJyMTCA_sendMessage);
}

void Heavy_CircleStrings::cSystem_WhJyMTCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YjpYK9YF_sendMessage);
}

void Heavy_CircleStrings::cDelay_tMy2rirt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tMy2rirt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_w8Ma3rzQ, 0, m, &cDelay_w8Ma3rzQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tMy2rirt, 0, m, &cDelay_tMy2rirt_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_g7lKG4ma, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_w8Ma3rzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_w8Ma3rzQ, m);
  cMsg_ZALRYPzW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_EuaNaTXQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_JTW89aXI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_xpWfXiNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MrT1iY0I_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_xtoVBvL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8HB6TD6A_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tMy2rirt, 2, m, &cDelay_tMy2rirt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TKGUHnoY_sendMessage);
}

void Heavy_CircleStrings::cMsg_MrT1iY0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_xtoVBvL3, 0, m, &hTable_xtoVBvL3_sendMessage);
}

void Heavy_CircleStrings::cBinop_YjpYK9YF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_xpWfXiNF_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZALRYPzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_xtoVBvL3, 0, m, &hTable_xtoVBvL3_sendMessage);
}

void Heavy_CircleStrings::cCast_TKGUHnoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tMy2rirt, 0, m, &cDelay_tMy2rirt_sendMessage);
}

void Heavy_CircleStrings::cMsg_8HB6TD6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_w8Ma3rzQ, 2, m, &cDelay_w8Ma3rzQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_JTW89aXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_g7lKG4ma, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_0d609Fm1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tRC6L0X5_sendMessage);
}

void Heavy_CircleStrings::cSystem_tRC6L0X5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_i3dp16an_sendMessage);
}

void Heavy_CircleStrings::cVar_pGGQCzXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b8gGr1VJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_za37Bgci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rvzeh6Ly_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pX6aonFn, m);
}

void Heavy_CircleStrings::cBinop_i3dp16an_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OjSCSR0W, m);
}

void Heavy_CircleStrings::cMsg_b8gGr1VJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_za37Bgci_sendMessage);
}

void Heavy_CircleStrings::cBinop_rvzeh6Ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7rVpbpeH, m);
}

void Heavy_CircleStrings::cMsg_aQZaRvPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lXZOCyVe_sendMessage);
}

void Heavy_CircleStrings::cSystem_lXZOCyVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tNIYDqLe_sendMessage);
}

void Heavy_CircleStrings::cVar_Bz5xCYnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z2oQYEQS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_4VxaahsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_xO1mRtkj_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Eb7r8I2G, m);
}

void Heavy_CircleStrings::cBinop_tNIYDqLe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WaVofjBH, m);
}

void Heavy_CircleStrings::cMsg_z2oQYEQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4VxaahsZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_xO1mRtkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xF1lIzpJ, m);
}

void Heavy_CircleStrings::cBinop_ZAZzjtH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_etPUsJ4p_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_vtejI5HQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7aBIoypZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mwQ0zK9B_sendMessage);
}

void Heavy_CircleStrings::cCast_7aBIoypZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZAZzjtH2, HV_BINOP_DIVIDE, 1, m, &cBinop_ZAZzjtH2_sendMessage);
}

void Heavy_CircleStrings::cCast_mwQ0zK9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZAZzjtH2, HV_BINOP_DIVIDE, 0, m, &cBinop_ZAZzjtH2_sendMessage);
}

void Heavy_CircleStrings::cBinop_QUTJ0ZUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jAkE87zy_sendMessage);
}

void Heavy_CircleStrings::cBinop_D87KSqJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_xuwi8xNh_sendMessage);
}

void Heavy_CircleStrings::cBinop_jAkE87zy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZAZzjtH2, HV_BINOP_DIVIDE, 0, m, &cBinop_ZAZzjtH2_sendMessage);
}

void Heavy_CircleStrings::cBinop_TQ1nmaq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FhtpVoZR, 0, m, &cPack_FhtpVoZR_sendMessage);
}

void Heavy_CircleStrings::cBinop_JYyyiKVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_vtejI5HQ_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_r728iCDn, 0, m, &cPack_r728iCDn_sendMessage);
}

void Heavy_CircleStrings::cMsg_rgaoeZpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_c212H3Ru, 0, m, &cVar_c212H3Ru_sendMessage);
}

void Heavy_CircleStrings::cMsg_Tc5mq5yN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_6J8CuTNX, 0, m, &cVar_6J8CuTNX_sendMessage);
}

void Heavy_CircleStrings::cMsg_etPUsJ4p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_N4B165GY, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_dZzjUefw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3ggdAoBO, HV_BINOP_MULTIPLY, 0, m, &cBinop_3ggdAoBO_sendMessage);
}

void Heavy_CircleStrings::cMsg_tP6ylKjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r2YAox1Z_sendMessage);
}

void Heavy_CircleStrings::cSystem_r2YAox1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KuHPsyye_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_3ggdAoBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_b2gbaMtg_sendMessage);
}

void Heavy_CircleStrings::cBinop_Nsf3DVF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3ggdAoBO, HV_BINOP_MULTIPLY, 1, m, &cBinop_3ggdAoBO_sendMessage);
}

void Heavy_CircleStrings::cMsg_KuHPsyye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Nsf3DVF0_sendMessage);
}

void Heavy_CircleStrings::cBinop_b2gbaMtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FpXqSMqf_sendMessage);
}

void Heavy_CircleStrings::cBinop_FpXqSMqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_e4a2yFSJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_I4HtKDfe, m);
}

void Heavy_CircleStrings::cBinop_e4a2yFSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IDfDOAl2, m);
}

void Heavy_CircleStrings::cVar_uni0ffev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_muW5ZF2F, HV_BINOP_MULTIPLY, 0, m, &cBinop_muW5ZF2F_sendMessage);
}

void Heavy_CircleStrings::cMsg_VWV770OB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PUGaOosF_sendMessage);
}

void Heavy_CircleStrings::cSystem_PUGaOosF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RwFhgIpV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_muW5ZF2F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iTbWdQiA_sendMessage);
}

void Heavy_CircleStrings::cBinop_JTtbcCZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_muW5ZF2F, HV_BINOP_MULTIPLY, 1, m, &cBinop_muW5ZF2F_sendMessage);
}

void Heavy_CircleStrings::cMsg_RwFhgIpV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JTtbcCZ3_sendMessage);
}

void Heavy_CircleStrings::cBinop_iTbWdQiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UmTUcTRu_sendMessage);
}

void Heavy_CircleStrings::cBinop_UmTUcTRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_shQReWfK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_640hQgGR, m);
}

void Heavy_CircleStrings::cBinop_shQReWfK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_B83GtxXR, m);
}

void Heavy_CircleStrings::cVar_8ldKbgG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hbcWRZuA, HV_BINOP_MULTIPLY, 0, m, &cBinop_hbcWRZuA_sendMessage);
}

void Heavy_CircleStrings::cMsg_PeSyHenk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KcjsXPVk_sendMessage);
}

void Heavy_CircleStrings::cSystem_KcjsXPVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_60GoU4Dl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_hbcWRZuA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xyB8tA3M_sendMessage);
}

void Heavy_CircleStrings::cBinop_f3qhlQd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hbcWRZuA, HV_BINOP_MULTIPLY, 1, m, &cBinop_hbcWRZuA_sendMessage);
}

void Heavy_CircleStrings::cMsg_60GoU4Dl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_f3qhlQd4_sendMessage);
}

void Heavy_CircleStrings::cBinop_xyB8tA3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6uRm7KaZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_6uRm7KaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_H72XwtvP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_yJswFEqk, m);
}

void Heavy_CircleStrings::cBinop_H72XwtvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cUZcUXq3, m);
}

void Heavy_CircleStrings::cMsg_rMWURiSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jMEN0OdY_sendMessage);
}

void Heavy_CircleStrings::cSystem_jMEN0OdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OAt4ns3C_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_kHQ6wZvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_wYQSIn8T_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_kmnw9Acd, 0, m, &cIf_kmnw9Acd_sendMessage);
}

void Heavy_CircleStrings::cIf_kmnw9Acd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Hb5gA5XQ_sendMessage(_c, 0, m);
      cMsg_bBYmwqOL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_XSc20dJN_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_CCV2GmAi_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_NBL5jg2d, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_wYQSIn8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kmnw9Acd, 1, m, &cIf_kmnw9Acd_sendMessage);
}

void Heavy_CircleStrings::cMsg_XSc20dJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5QK2lnQB_sendMessage);
}

void Heavy_CircleStrings::cBinop_5QK2lnQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cttibhUr, m);
}

void Heavy_CircleStrings::cBinop_CCV2GmAi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_52PJsDT0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_52PJsDT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IUN34Uhl_sendMessage);
}

void Heavy_CircleStrings::cBinop_IUN34Uhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dE1BgPEv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_dE1BgPEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_xQPU1zXQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_xQPU1zXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aWWNuf6l, m);
}

void Heavy_CircleStrings::cBinop_1QYf4Bhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mbwGlwt0, m);
}

void Heavy_CircleStrings::cMsg_OAt4ns3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1QYf4Bhk_sendMessage);
}

void Heavy_CircleStrings::cMsg_Hb5gA5XQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_CCV2GmAi_sendMessage);
}

void Heavy_CircleStrings::cMsg_bBYmwqOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cttibhUr, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NBL5jg2d, m);
}

void Heavy_CircleStrings::cBinop_2WV4WwTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uni0ffev, 0, m, &cVar_uni0ffev_sendMessage);
}

void Heavy_CircleStrings::cBinop_LL1hHSPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dZzjUefw, 0, m, &cVar_dZzjUefw_sendMessage);
}

void Heavy_CircleStrings::cBinop_YzjoBaNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8ldKbgG6, 0, m, &cVar_8ldKbgG6_sendMessage);
}

void Heavy_CircleStrings::cCast_BhVXD7sY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_YzjoBaNl_sendMessage);
}

void Heavy_CircleStrings::cCast_N7xVvPqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_LL1hHSPR_sendMessage);
}

void Heavy_CircleStrings::cCast_gdj7U52A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_2WV4WwTe_sendMessage);
}

void Heavy_CircleStrings::cCast_NKSFK1eA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PeUIbHJS, m);
}

void Heavy_CircleStrings::cTabhead_yDHNe3QP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qZpVV8I, HV_BINOP_SUBTRACT, 0, m, &cBinop_0qZpVV8I_sendMessage);
}

void Heavy_CircleStrings::cMsg_m84AQ9ll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_njXKfR21_sendMessage);
}

void Heavy_CircleStrings::cSystem_njXKfR21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LENPrjKm_sendMessage);
}

void Heavy_CircleStrings::cVar_PYIAUgPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zwH0hpNV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_n6F9MdPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n6F9MdPF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eoRqhbMW, 0, m, &cDelay_eoRqhbMW_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u9PkanES, 0, m, &sTabread_u9PkanES_sendMessage);
}

void Heavy_CircleStrings::cDelay_eoRqhbMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eoRqhbMW, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u9PkanES, 0, m, &sTabread_u9PkanES_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eoRqhbMW, 0, m, &cDelay_eoRqhbMW_sendMessage);
}

void Heavy_CircleStrings::sTabread_u9PkanES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DM8B4maE, HV_BINOP_SUBTRACT, 0, m, &cBinop_DM8B4maE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_VtKxXHzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_52s5yh2V, HV_BINOP_MAX, 0, m, &cBinop_52s5yh2V_sendMessage);
}

void Heavy_CircleStrings::cBinop_LENPrjKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VtKxXHzf, HV_BINOP_MULTIPLY, 0, m, &cBinop_VtKxXHzf_sendMessage);
}

void Heavy_CircleStrings::cBinop_0qZpVV8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J9KSAo0B_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u9PkanES, 0, m, &sTabread_u9PkanES_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_td9PND6i_sendMessage);
}

void Heavy_CircleStrings::cSystem_efRqVRJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DM8B4maE, HV_BINOP_SUBTRACT, 1, m, &cBinop_DM8B4maE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eoRqhbMW, 2, m, &cDelay_eoRqhbMW_sendMessage);
}

void Heavy_CircleStrings::cMsg_zwH0hpNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_efRqVRJ5_sendMessage);
}

void Heavy_CircleStrings::cMsg_J9KSAo0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_n6F9MdPF, 0, m, &cDelay_n6F9MdPF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eoRqhbMW, 0, m, &cDelay_eoRqhbMW_sendMessage);
}

void Heavy_CircleStrings::cMsg_p6NG9zJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_52s5yh2V, HV_BINOP_MAX, 1, m, &cBinop_52s5yh2V_sendMessage);
}

void Heavy_CircleStrings::cBinop_52s5yh2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qZpVV8I, HV_BINOP_SUBTRACT, 1, m, &cBinop_0qZpVV8I_sendMessage);
}

void Heavy_CircleStrings::cCast_td9PND6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_n6F9MdPF, 0, m, &cDelay_n6F9MdPF_sendMessage);
}

void Heavy_CircleStrings::cBinop_JH7TgoSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_n6F9MdPF, 2, m, &cDelay_n6F9MdPF_sendMessage);
}

void Heavy_CircleStrings::cBinop_DM8B4maE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JH7TgoSb_sendMessage);
}

void Heavy_CircleStrings::cCast_Z552Sqa7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PYIAUgPj, 0, m, &cVar_PYIAUgPj_sendMessage);
  cMsg_m84AQ9ll_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yDHNe3QP, 0, m, &cTabhead_yDHNe3QP_sendMessage);
}

void Heavy_CircleStrings::cTabhead_TiloUlwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9dT7IGn, HV_BINOP_SUBTRACT, 0, m, &cBinop_y9dT7IGn_sendMessage);
}

void Heavy_CircleStrings::cMsg_cshRlktW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Suo4TCRF_sendMessage);
}

void Heavy_CircleStrings::cSystem_Suo4TCRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AyJGHjbn_sendMessage);
}

void Heavy_CircleStrings::cVar_G1CGkE0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M1DllOur_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_mxH2gEtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mxH2gEtw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BrkOseAe, 0, m, &cDelay_BrkOseAe_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_noZSmxnG, 0, m, &sTabread_noZSmxnG_sendMessage);
}

void Heavy_CircleStrings::cDelay_BrkOseAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BrkOseAe, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_noZSmxnG, 0, m, &sTabread_noZSmxnG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BrkOseAe, 0, m, &cDelay_BrkOseAe_sendMessage);
}

void Heavy_CircleStrings::sTabread_noZSmxnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Jzvwj1c4, HV_BINOP_SUBTRACT, 0, m, &cBinop_Jzvwj1c4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_WujZvpnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_smVayDGV, HV_BINOP_MAX, 0, m, &cBinop_smVayDGV_sendMessage);
}

void Heavy_CircleStrings::cBinop_AyJGHjbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WujZvpnz, HV_BINOP_MULTIPLY, 0, m, &cBinop_WujZvpnz_sendMessage);
}

void Heavy_CircleStrings::cBinop_y9dT7IGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dznfrm9m_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_noZSmxnG, 0, m, &sTabread_noZSmxnG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Al7Kq94y_sendMessage);
}

void Heavy_CircleStrings::cSystem_eHpnTQvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jzvwj1c4, HV_BINOP_SUBTRACT, 1, m, &cBinop_Jzvwj1c4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BrkOseAe, 2, m, &cDelay_BrkOseAe_sendMessage);
}

void Heavy_CircleStrings::cMsg_M1DllOur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eHpnTQvx_sendMessage);
}

void Heavy_CircleStrings::cMsg_Dznfrm9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mxH2gEtw, 0, m, &cDelay_mxH2gEtw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BrkOseAe, 0, m, &cDelay_BrkOseAe_sendMessage);
}

void Heavy_CircleStrings::cMsg_3mZA5t0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_smVayDGV, HV_BINOP_MAX, 1, m, &cBinop_smVayDGV_sendMessage);
}

void Heavy_CircleStrings::cBinop_smVayDGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9dT7IGn, HV_BINOP_SUBTRACT, 1, m, &cBinop_y9dT7IGn_sendMessage);
}

void Heavy_CircleStrings::cCast_Al7Kq94y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mxH2gEtw, 0, m, &cDelay_mxH2gEtw_sendMessage);
}

void Heavy_CircleStrings::cBinop_ID39inyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mxH2gEtw, 2, m, &cDelay_mxH2gEtw_sendMessage);
}

void Heavy_CircleStrings::cBinop_Jzvwj1c4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ID39inyh_sendMessage);
}

void Heavy_CircleStrings::cCast_WnZAhIR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_G1CGkE0p, 0, m, &cVar_G1CGkE0p_sendMessage);
  cMsg_cshRlktW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TiloUlwC, 0, m, &cTabhead_TiloUlwC_sendMessage);
}

void Heavy_CircleStrings::cTabhead_D1u9waqI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WWXbdsjV, HV_BINOP_SUBTRACT, 0, m, &cBinop_WWXbdsjV_sendMessage);
}

void Heavy_CircleStrings::cMsg_LqwtpDWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ECV383QI_sendMessage);
}

void Heavy_CircleStrings::cSystem_ECV383QI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iPdQYrmP_sendMessage);
}

void Heavy_CircleStrings::cVar_id8JNbCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S3sg6QbB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_OLsjew0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OLsjew0m, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RFP6K0wq, 0, m, &cDelay_RFP6K0wq_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HweGePPZ, 0, m, &sTabread_HweGePPZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_RFP6K0wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RFP6K0wq, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HweGePPZ, 0, m, &sTabread_HweGePPZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RFP6K0wq, 0, m, &cDelay_RFP6K0wq_sendMessage);
}

void Heavy_CircleStrings::sTabread_HweGePPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KEf0oS4S, HV_BINOP_SUBTRACT, 0, m, &cBinop_KEf0oS4S_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_rllv9EJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ay84sB9N, HV_BINOP_MAX, 0, m, &cBinop_Ay84sB9N_sendMessage);
}

void Heavy_CircleStrings::cBinop_iPdQYrmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rllv9EJd, HV_BINOP_MULTIPLY, 0, m, &cBinop_rllv9EJd_sendMessage);
}

void Heavy_CircleStrings::cBinop_WWXbdsjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dFRHPyOZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HweGePPZ, 0, m, &sTabread_HweGePPZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BPfmBecx_sendMessage);
}

void Heavy_CircleStrings::cSystem_2SVnbGyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KEf0oS4S, HV_BINOP_SUBTRACT, 1, m, &cBinop_KEf0oS4S_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RFP6K0wq, 2, m, &cDelay_RFP6K0wq_sendMessage);
}

void Heavy_CircleStrings::cMsg_S3sg6QbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2SVnbGyX_sendMessage);
}

void Heavy_CircleStrings::cMsg_dFRHPyOZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_OLsjew0m, 0, m, &cDelay_OLsjew0m_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RFP6K0wq, 0, m, &cDelay_RFP6K0wq_sendMessage);
}

void Heavy_CircleStrings::cMsg_TBgE2est_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ay84sB9N, HV_BINOP_MAX, 1, m, &cBinop_Ay84sB9N_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ay84sB9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WWXbdsjV, HV_BINOP_SUBTRACT, 1, m, &cBinop_WWXbdsjV_sendMessage);
}

void Heavy_CircleStrings::cCast_BPfmBecx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OLsjew0m, 0, m, &cDelay_OLsjew0m_sendMessage);
}

void Heavy_CircleStrings::cBinop_IrCMs6cC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OLsjew0m, 2, m, &cDelay_OLsjew0m_sendMessage);
}

void Heavy_CircleStrings::cBinop_KEf0oS4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IrCMs6cC_sendMessage);
}

void Heavy_CircleStrings::cCast_ipBnhdaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_id8JNbCJ, 0, m, &cVar_id8JNbCJ_sendMessage);
  cMsg_LqwtpDWX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_D1u9waqI, 0, m, &cTabhead_D1u9waqI_sendMessage);
}

void Heavy_CircleStrings::cTabhead_bkYjbYhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zp1pfoC9, HV_BINOP_SUBTRACT, 0, m, &cBinop_zp1pfoC9_sendMessage);
}

void Heavy_CircleStrings::cMsg_aCQOnmYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3kybFijd_sendMessage);
}

void Heavy_CircleStrings::cSystem_3kybFijd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BRfqajp0_sendMessage);
}

void Heavy_CircleStrings::cVar_1BhP2wXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zndvByhm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_YWgCIpwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YWgCIpwG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eGHasjS0, 0, m, &cDelay_eGHasjS0_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zv0NvSj1, 0, m, &sTabread_zv0NvSj1_sendMessage);
}

void Heavy_CircleStrings::cDelay_eGHasjS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eGHasjS0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zv0NvSj1, 0, m, &sTabread_zv0NvSj1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eGHasjS0, 0, m, &cDelay_eGHasjS0_sendMessage);
}

void Heavy_CircleStrings::sTabread_zv0NvSj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IaqQvTpi, HV_BINOP_SUBTRACT, 0, m, &cBinop_IaqQvTpi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_woP4cBPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQU9ReCE, HV_BINOP_MAX, 0, m, &cBinop_eQU9ReCE_sendMessage);
}

void Heavy_CircleStrings::cBinop_BRfqajp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_woP4cBPB, HV_BINOP_MULTIPLY, 0, m, &cBinop_woP4cBPB_sendMessage);
}

void Heavy_CircleStrings::cBinop_zp1pfoC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_47VnGJMP_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zv0NvSj1, 0, m, &sTabread_zv0NvSj1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jdMGeISe_sendMessage);
}

void Heavy_CircleStrings::cSystem_W3FZOmVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IaqQvTpi, HV_BINOP_SUBTRACT, 1, m, &cBinop_IaqQvTpi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eGHasjS0, 2, m, &cDelay_eGHasjS0_sendMessage);
}

void Heavy_CircleStrings::cMsg_zndvByhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W3FZOmVP_sendMessage);
}

void Heavy_CircleStrings::cMsg_47VnGJMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YWgCIpwG, 0, m, &cDelay_YWgCIpwG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eGHasjS0, 0, m, &cDelay_eGHasjS0_sendMessage);
}

void Heavy_CircleStrings::cMsg_6W2ELpj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQU9ReCE, HV_BINOP_MAX, 1, m, &cBinop_eQU9ReCE_sendMessage);
}

void Heavy_CircleStrings::cBinop_eQU9ReCE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zp1pfoC9, HV_BINOP_SUBTRACT, 1, m, &cBinop_zp1pfoC9_sendMessage);
}

void Heavy_CircleStrings::cCast_jdMGeISe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YWgCIpwG, 0, m, &cDelay_YWgCIpwG_sendMessage);
}

void Heavy_CircleStrings::cBinop_lQibHlEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YWgCIpwG, 2, m, &cDelay_YWgCIpwG_sendMessage);
}

void Heavy_CircleStrings::cBinop_IaqQvTpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_lQibHlEc_sendMessage);
}

void Heavy_CircleStrings::cCast_8Z83Wv7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1BhP2wXc, 0, m, &cVar_1BhP2wXc_sendMessage);
  cMsg_aCQOnmYm_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bkYjbYhY, 0, m, &cTabhead_bkYjbYhY_sendMessage);
}

void Heavy_CircleStrings::cMsg_QA4Vd7ep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_luLwcYJZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_luLwcYJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pmOaFyRV_sendMessage);
}

void Heavy_CircleStrings::cDelay_Ir0Def7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ir0Def7e, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_y4uuSRse, 0, m, &cDelay_y4uuSRse_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ir0Def7e, 0, m, &cDelay_Ir0Def7e_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uKt61kn1, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_y4uuSRse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_y4uuSRse, m);
  cMsg_3iq5QVyq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_KFGaPS6q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_GaXOdim2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_K8Kn3wlW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YgP7RcsT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_N1Do4ZF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sB4CAqlE_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ir0Def7e, 2, m, &cDelay_Ir0Def7e_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8FZXhtgp_sendMessage);
}

void Heavy_CircleStrings::cMsg_YgP7RcsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_N1Do4ZF4, 0, m, &hTable_N1Do4ZF4_sendMessage);
}

void Heavy_CircleStrings::cBinop_pmOaFyRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_K8Kn3wlW_sendMessage);
}

void Heavy_CircleStrings::cMsg_3iq5QVyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_N1Do4ZF4, 0, m, &hTable_N1Do4ZF4_sendMessage);
}

void Heavy_CircleStrings::cCast_8FZXhtgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ir0Def7e, 0, m, &cDelay_Ir0Def7e_sendMessage);
}

void Heavy_CircleStrings::cMsg_sB4CAqlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_y4uuSRse, 2, m, &cDelay_y4uuSRse_sendMessage);
}

void Heavy_CircleStrings::cMsg_GaXOdim2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uKt61kn1, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_JmYFKsCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vBhxEZFV_sendMessage);
}

void Heavy_CircleStrings::cSystem_vBhxEZFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MJEzJygC_sendMessage);
}

void Heavy_CircleStrings::cDelay_VyrAnkCE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VyrAnkCE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UQzFzsnO, 0, m, &cDelay_UQzFzsnO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VyrAnkCE, 0, m, &cDelay_VyrAnkCE_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_u9SfTECT, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_UQzFzsnO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UQzFzsnO, m);
  cMsg_4jWmu212_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_37sCduJl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_XOpjXRm5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_PmHvEBXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UeqELWr8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Yvxcqs7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5LCFBL3y_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VyrAnkCE, 2, m, &cDelay_VyrAnkCE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0uoEFiha_sendMessage);
}

void Heavy_CircleStrings::cMsg_UeqELWr8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Yvxcqs7Z, 0, m, &hTable_Yvxcqs7Z_sendMessage);
}

void Heavy_CircleStrings::cBinop_MJEzJygC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_PmHvEBXq_sendMessage);
}

void Heavy_CircleStrings::cMsg_4jWmu212_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Yvxcqs7Z, 0, m, &hTable_Yvxcqs7Z_sendMessage);
}

void Heavy_CircleStrings::cCast_0uoEFiha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VyrAnkCE, 0, m, &cDelay_VyrAnkCE_sendMessage);
}

void Heavy_CircleStrings::cMsg_5LCFBL3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_UQzFzsnO, 2, m, &cDelay_UQzFzsnO_sendMessage);
}

void Heavy_CircleStrings::cMsg_XOpjXRm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_u9SfTECT, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_rRFTvh5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KCulQSu6_sendMessage);
}

void Heavy_CircleStrings::cSystem_KCulQSu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7qnlGZHz_sendMessage);
}

void Heavy_CircleStrings::cDelay_vqdJtCom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vqdJtCom, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gtVaTb7r, 0, m, &cDelay_gtVaTb7r_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vqdJtCom, 0, m, &cDelay_vqdJtCom_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OPnP2c62, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_gtVaTb7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gtVaTb7r, m);
  cMsg_4YHjdvbm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_17yYVFtl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_fyuieOyc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_gXyvuI9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H53E9JgH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_w1FkbIwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s7AbfWLd_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vqdJtCom, 2, m, &cDelay_vqdJtCom_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kredYHga_sendMessage);
}

void Heavy_CircleStrings::cMsg_H53E9JgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_w1FkbIwz, 0, m, &hTable_w1FkbIwz_sendMessage);
}

void Heavy_CircleStrings::cBinop_7qnlGZHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_gXyvuI9Z_sendMessage);
}

void Heavy_CircleStrings::cMsg_4YHjdvbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_w1FkbIwz, 0, m, &hTable_w1FkbIwz_sendMessage);
}

void Heavy_CircleStrings::cCast_kredYHga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vqdJtCom, 0, m, &cDelay_vqdJtCom_sendMessage);
}

void Heavy_CircleStrings::cMsg_s7AbfWLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_gtVaTb7r, 2, m, &cDelay_gtVaTb7r_sendMessage);
}

void Heavy_CircleStrings::cMsg_fyuieOyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OPnP2c62, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_s4vAoabH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gkf9sjVZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_gkf9sjVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_j6YeOQtt_sendMessage);
}

void Heavy_CircleStrings::cDelay_eliVQO3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eliVQO3r, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NWU7TDXx, 0, m, &cDelay_NWU7TDXx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eliVQO3r, 0, m, &cDelay_eliVQO3r_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_THYJzW9h, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_NWU7TDXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NWU7TDXx, m);
  cMsg_cqj0CbZy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_JrsAcjIJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ecsPhNjF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_fyiz6ZXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TplokVtL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_H7TQt9AK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hEtzyQZE_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eliVQO3r, 2, m, &cDelay_eliVQO3r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ypdsqkny_sendMessage);
}

void Heavy_CircleStrings::cMsg_TplokVtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_H7TQt9AK, 0, m, &hTable_H7TQt9AK_sendMessage);
}

void Heavy_CircleStrings::cBinop_j6YeOQtt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_fyiz6ZXa_sendMessage);
}

void Heavy_CircleStrings::cMsg_cqj0CbZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_H7TQt9AK, 0, m, &hTable_H7TQt9AK_sendMessage);
}

void Heavy_CircleStrings::cCast_ypdsqkny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eliVQO3r, 0, m, &cDelay_eliVQO3r_sendMessage);
}

void Heavy_CircleStrings::cMsg_hEtzyQZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_NWU7TDXx, 2, m, &cDelay_NWU7TDXx_sendMessage);
}

void Heavy_CircleStrings::cMsg_ecsPhNjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_THYJzW9h, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_s7odA0a3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_B1vG8hYE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_7Yqtymo7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_QdQV2E4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QjzC0ND9, HV_BINOP_POW, 0, m, &cBinop_QjzC0ND9_sendMessage);
}

void Heavy_CircleStrings::cBinop_QjzC0ND9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_7hvcmCp4_sendMessage);
}

void Heavy_CircleStrings::cBinop_DWkPq4la_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_1ukVLDlr_sendMessage);
}

void Heavy_CircleStrings::cCast_JDtpwasq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_CuUQMOlI_sendMessage);
}

void Heavy_CircleStrings::cCast_9BBUUwlR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_s7odA0a3, 0, m, &cIf_s7odA0a3_sendMessage);
}

void Heavy_CircleStrings::cBinop_CuUQMOlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_s7odA0a3, 1, m, &cIf_s7odA0a3_sendMessage);
}

void Heavy_CircleStrings::cBinop_7Yqtymo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_DWkPq4la_sendMessage);
}

void Heavy_CircleStrings::cMsg_B1vG8hYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_7hvcmCp4_sendMessage);
}

void Heavy_CircleStrings::cBinop_1ukVLDlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QjzC0ND9, HV_BINOP_POW, 1, m, &cBinop_QjzC0ND9_sendMessage);
  cMsg_QdQV2E4o_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_naduErNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LA7KpQ16, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_U7XV9pWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uebfVKhu, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_MAyIhNu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7Xch0YWq_sendMessage);
}

void Heavy_CircleStrings::cBinop_7Xch0YWq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_V3r0FkZ8_sendMessage);
}

void Heavy_CircleStrings::cVar_YVCceG8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9KnJcpdm, HV_BINOP_MULTIPLY, 0, m, &cBinop_9KnJcpdm_sendMessage);
}

void Heavy_CircleStrings::cMsg_hIpAEjDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qmt4gUXy_sendMessage);
}

void Heavy_CircleStrings::cSystem_Qmt4gUXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gQLPYkSd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_9KnJcpdm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_vMrAPRx6_sendMessage);
}

void Heavy_CircleStrings::cBinop_xGfXyNNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9KnJcpdm, HV_BINOP_MULTIPLY, 1, m, &cBinop_9KnJcpdm_sendMessage);
}

void Heavy_CircleStrings::cMsg_gQLPYkSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xGfXyNNl_sendMessage);
}

void Heavy_CircleStrings::cBinop_vMrAPRx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LGeEajqr_sendMessage);
}

void Heavy_CircleStrings::cBinop_LGeEajqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_gmNmf4Ha_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_H75rthim, m);
}

void Heavy_CircleStrings::cBinop_gmNmf4Ha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TyscVM2J, m);
}

void Heavy_CircleStrings::cVar_jV4rJmGT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JDtpwasq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9BBUUwlR_sendMessage);
}

void Heavy_CircleStrings::cVar_gx5SzHcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_MAyIhNu4_sendMessage);
}

void Heavy_CircleStrings::cVar_vx5Lx6GN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_7GjWu6UJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Y4Oa88sh, 0, m, &cIf_Y4Oa88sh_sendMessage);
}

void Heavy_CircleStrings::cVar_iWK6SRJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_kRAiWQtb_sendMessage);
}

void Heavy_CircleStrings::cIf_Y4Oa88sh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DElYKlBV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_kUNPvE6N, 0, m, &cVar_kUNPvE6N_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_7GjWu6UJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Y4Oa88sh, 1, m, &cIf_Y4Oa88sh_sendMessage);
}

void Heavy_CircleStrings::cBinop_kRAiWQtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_L56CGOhz_sendMessage);
}

void Heavy_CircleStrings::cBinop_L56CGOhz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UEDzTp9w, 0, m, &cVar_UEDzTp9w_sendMessage);
}

void Heavy_CircleStrings::cTabhead_NpzO6w9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LzqTeeiA, HV_BINOP_SUBTRACT, 0, m, &cBinop_LzqTeeiA_sendMessage);
}

void Heavy_CircleStrings::cMsg_8ZH4N7r5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3lrAL6Xd_sendMessage);
}

void Heavy_CircleStrings::cSystem_3lrAL6Xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TYa5UuUz_sendMessage);
}

void Heavy_CircleStrings::cVar_qqNayhTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fakEmlFL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_WrzryUgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WrzryUgo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U9IdfXGK, 0, m, &cDelay_U9IdfXGK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_YG5PfQtP, 0, m, &sTabread_YG5PfQtP_sendMessage);
}

void Heavy_CircleStrings::cDelay_U9IdfXGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_U9IdfXGK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_YG5PfQtP, 0, m, &sTabread_YG5PfQtP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U9IdfXGK, 0, m, &cDelay_U9IdfXGK_sendMessage);
}

void Heavy_CircleStrings::sTabread_YG5PfQtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_I0dbLQYn, HV_BINOP_SUBTRACT, 0, m, &cBinop_I0dbLQYn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_LMtPTvu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9SLX6CgC, HV_BINOP_MAX, 0, m, &cBinop_9SLX6CgC_sendMessage);
}

void Heavy_CircleStrings::cBinop_TYa5UuUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LMtPTvu2, HV_BINOP_MULTIPLY, 0, m, &cBinop_LMtPTvu2_sendMessage);
}

void Heavy_CircleStrings::cBinop_LzqTeeiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8EuCC4UI_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_YG5PfQtP, 0, m, &sTabread_YG5PfQtP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wjPrGY1A_sendMessage);
}

void Heavy_CircleStrings::cSystem_ynYvYd5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I0dbLQYn, HV_BINOP_SUBTRACT, 1, m, &cBinop_I0dbLQYn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U9IdfXGK, 2, m, &cDelay_U9IdfXGK_sendMessage);
}

void Heavy_CircleStrings::cMsg_fakEmlFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ynYvYd5Z_sendMessage);
}

void Heavy_CircleStrings::cMsg_8EuCC4UI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WrzryUgo, 0, m, &cDelay_WrzryUgo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U9IdfXGK, 0, m, &cDelay_U9IdfXGK_sendMessage);
}

void Heavy_CircleStrings::cMsg_J8pqvqUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9SLX6CgC, HV_BINOP_MAX, 1, m, &cBinop_9SLX6CgC_sendMessage);
}

void Heavy_CircleStrings::cBinop_9SLX6CgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LzqTeeiA, HV_BINOP_SUBTRACT, 1, m, &cBinop_LzqTeeiA_sendMessage);
}

void Heavy_CircleStrings::cCast_wjPrGY1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WrzryUgo, 0, m, &cDelay_WrzryUgo_sendMessage);
}

void Heavy_CircleStrings::cBinop_qts9n1yF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WrzryUgo, 2, m, &cDelay_WrzryUgo_sendMessage);
}

void Heavy_CircleStrings::cBinop_I0dbLQYn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qts9n1yF_sendMessage);
}

void Heavy_CircleStrings::cCast_1WHUtzcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qqNayhTq, 0, m, &cVar_qqNayhTq_sendMessage);
  cMsg_8ZH4N7r5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_NpzO6w9n, 0, m, &cTabhead_NpzO6w9n_sendMessage);
}

void Heavy_CircleStrings::cMsg_jpoGaqnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cJKaYS83_sendMessage);
}

void Heavy_CircleStrings::cSystem_cJKaYS83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UdcMWOow_sendMessage);
}

void Heavy_CircleStrings::cDelay_xza53Mzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xza53Mzx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kYq1fPwB, 0, m, &cDelay_kYq1fPwB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xza53Mzx, 0, m, &cDelay_xza53Mzx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_e4MtuBhD, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_kYq1fPwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kYq1fPwB, m);
  cMsg_ptuHpBrj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_dnyr17kf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_u8UduUmG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_ThpKy06N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8MHV7Ouj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_gdqDQNUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xjwklptY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xza53Mzx, 2, m, &cDelay_xza53Mzx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8hWbjcbw_sendMessage);
}

void Heavy_CircleStrings::cMsg_8MHV7Ouj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gdqDQNUs, 0, m, &hTable_gdqDQNUs_sendMessage);
}

void Heavy_CircleStrings::cBinop_UdcMWOow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_ThpKy06N_sendMessage);
}

void Heavy_CircleStrings::cMsg_ptuHpBrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gdqDQNUs, 0, m, &hTable_gdqDQNUs_sendMessage);
}

void Heavy_CircleStrings::cCast_8hWbjcbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xza53Mzx, 0, m, &cDelay_xza53Mzx_sendMessage);
}

void Heavy_CircleStrings::cMsg_xjwklptY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kYq1fPwB, 2, m, &cDelay_kYq1fPwB_sendMessage);
}

void Heavy_CircleStrings::cMsg_u8UduUmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_e4MtuBhD, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_Pyt1uMVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_295DO3qE, HV_BINOP_SUBTRACT, 0, m, &cBinop_295DO3qE_sendMessage);
}

void Heavy_CircleStrings::cMsg_9qI9VSuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kT5xhtN4_sendMessage);
}

void Heavy_CircleStrings::cSystem_kT5xhtN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lXkm1aDk_sendMessage);
}

void Heavy_CircleStrings::cVar_7PWK4b2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oXH3fQz6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_a6pivUz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_a6pivUz4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kUqTwINy, 0, m, &cDelay_kUqTwINy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Phlx229A, 0, m, &sTabread_Phlx229A_sendMessage);
}

void Heavy_CircleStrings::cDelay_kUqTwINy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kUqTwINy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Phlx229A, 0, m, &sTabread_Phlx229A_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kUqTwINy, 0, m, &cDelay_kUqTwINy_sendMessage);
}

void Heavy_CircleStrings::sTabread_Phlx229A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2fiviAJO, HV_BINOP_SUBTRACT, 0, m, &cBinop_2fiviAJO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Hb87fLhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ketOeagw, HV_BINOP_MAX, 0, m, &cBinop_ketOeagw_sendMessage);
}

void Heavy_CircleStrings::cBinop_lXkm1aDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hb87fLhE, HV_BINOP_MULTIPLY, 0, m, &cBinop_Hb87fLhE_sendMessage);
}

void Heavy_CircleStrings::cBinop_295DO3qE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dSyn1kXJ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Phlx229A, 0, m, &sTabread_Phlx229A_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yHCMKdvG_sendMessage);
}

void Heavy_CircleStrings::cSystem_kC52h3Y2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2fiviAJO, HV_BINOP_SUBTRACT, 1, m, &cBinop_2fiviAJO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kUqTwINy, 2, m, &cDelay_kUqTwINy_sendMessage);
}

void Heavy_CircleStrings::cMsg_oXH3fQz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kC52h3Y2_sendMessage);
}

void Heavy_CircleStrings::cMsg_dSyn1kXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_a6pivUz4, 0, m, &cDelay_a6pivUz4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kUqTwINy, 0, m, &cDelay_kUqTwINy_sendMessage);
}

void Heavy_CircleStrings::cMsg_7QSm4x9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ketOeagw, HV_BINOP_MAX, 1, m, &cBinop_ketOeagw_sendMessage);
}

void Heavy_CircleStrings::cBinop_ketOeagw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_295DO3qE, HV_BINOP_SUBTRACT, 1, m, &cBinop_295DO3qE_sendMessage);
}

void Heavy_CircleStrings::cCast_yHCMKdvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_a6pivUz4, 0, m, &cDelay_a6pivUz4_sendMessage);
}

void Heavy_CircleStrings::cBinop_7szfkECJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_a6pivUz4, 2, m, &cDelay_a6pivUz4_sendMessage);
}

void Heavy_CircleStrings::cBinop_2fiviAJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7szfkECJ_sendMessage);
}

void Heavy_CircleStrings::cCast_bt27UB4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7PWK4b2c, 0, m, &cVar_7PWK4b2c_sendMessage);
  cMsg_9qI9VSuw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Pyt1uMVH, 0, m, &cTabhead_Pyt1uMVH_sendMessage);
}

void Heavy_CircleStrings::cMsg_MIESHuUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ejIKyAmT_sendMessage);
}

void Heavy_CircleStrings::cSystem_ejIKyAmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9p3odO5d_sendMessage);
}

void Heavy_CircleStrings::cDelay_jw5vHr48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jw5vHr48, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1LrkWNj9, 0, m, &cDelay_1LrkWNj9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jw5vHr48, 0, m, &cDelay_jw5vHr48_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oniTGu3h, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_1LrkWNj9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1LrkWNj9, m);
  cMsg_TMhDlz7K_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_WW1CZOu5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ESqjftHv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_H5dA8rwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZUvc34DW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_TF9cUA1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WzGA7xg6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jw5vHr48, 2, m, &cDelay_jw5vHr48_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VnSwcHi3_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZUvc34DW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TF9cUA1F, 0, m, &hTable_TF9cUA1F_sendMessage);
}

void Heavy_CircleStrings::cBinop_9p3odO5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_H5dA8rwC_sendMessage);
}

void Heavy_CircleStrings::cMsg_TMhDlz7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TF9cUA1F, 0, m, &hTable_TF9cUA1F_sendMessage);
}

void Heavy_CircleStrings::cCast_VnSwcHi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jw5vHr48, 0, m, &cDelay_jw5vHr48_sendMessage);
}

void Heavy_CircleStrings::cMsg_WzGA7xg6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_1LrkWNj9, 2, m, &cDelay_1LrkWNj9_sendMessage);
}

void Heavy_CircleStrings::cMsg_ESqjftHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oniTGu3h, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_nDd37fCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C2wnbg99, HV_BINOP_SUBTRACT, 0, m, &cBinop_C2wnbg99_sendMessage);
}

void Heavy_CircleStrings::cMsg_XPyPH0pd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uGbp3JD2_sendMessage);
}

void Heavy_CircleStrings::cSystem_uGbp3JD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2f5QHCr7_sendMessage);
}

void Heavy_CircleStrings::cVar_feRkohwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k7N1bOCu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Fdcw98hE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Fdcw98hE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BuG9lf0c, 0, m, &cDelay_BuG9lf0c_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WPhyFpth, 0, m, &sTabread_WPhyFpth_sendMessage);
}

void Heavy_CircleStrings::cDelay_BuG9lf0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BuG9lf0c, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WPhyFpth, 0, m, &sTabread_WPhyFpth_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BuG9lf0c, 0, m, &cDelay_BuG9lf0c_sendMessage);
}

void Heavy_CircleStrings::sTabread_WPhyFpth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_e37kAw1X, HV_BINOP_SUBTRACT, 0, m, &cBinop_e37kAw1X_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_h5YLsKqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IG3cfXEk, HV_BINOP_MAX, 0, m, &cBinop_IG3cfXEk_sendMessage);
}

void Heavy_CircleStrings::cBinop_2f5QHCr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h5YLsKqu, HV_BINOP_MULTIPLY, 0, m, &cBinop_h5YLsKqu_sendMessage);
}

void Heavy_CircleStrings::cBinop_C2wnbg99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_62HX0mvX_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WPhyFpth, 0, m, &sTabread_WPhyFpth_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h94NQkAT_sendMessage);
}

void Heavy_CircleStrings::cSystem_bew1cNfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e37kAw1X, HV_BINOP_SUBTRACT, 1, m, &cBinop_e37kAw1X_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BuG9lf0c, 2, m, &cDelay_BuG9lf0c_sendMessage);
}

void Heavy_CircleStrings::cMsg_k7N1bOCu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bew1cNfL_sendMessage);
}

void Heavy_CircleStrings::cMsg_62HX0mvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fdcw98hE, 0, m, &cDelay_Fdcw98hE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BuG9lf0c, 0, m, &cDelay_BuG9lf0c_sendMessage);
}

void Heavy_CircleStrings::cMsg_LtR1Rwos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_IG3cfXEk, HV_BINOP_MAX, 1, m, &cBinop_IG3cfXEk_sendMessage);
}

void Heavy_CircleStrings::cBinop_IG3cfXEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C2wnbg99, HV_BINOP_SUBTRACT, 1, m, &cBinop_C2wnbg99_sendMessage);
}

void Heavy_CircleStrings::cCast_h94NQkAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fdcw98hE, 0, m, &cDelay_Fdcw98hE_sendMessage);
}

void Heavy_CircleStrings::cBinop_pnJq7Lhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fdcw98hE, 2, m, &cDelay_Fdcw98hE_sendMessage);
}

void Heavy_CircleStrings::cBinop_e37kAw1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pnJq7Lhw_sendMessage);
}

void Heavy_CircleStrings::cCast_L80UtO5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_feRkohwo, 0, m, &cVar_feRkohwo_sendMessage);
  cMsg_XPyPH0pd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nDd37fCv, 0, m, &cTabhead_nDd37fCv_sendMessage);
}

void Heavy_CircleStrings::cMsg_0HkgVW86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3qAQ2SZ6_sendMessage);
}

void Heavy_CircleStrings::cSystem_3qAQ2SZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4C7MvVTA_sendMessage);
}

void Heavy_CircleStrings::cDelay_mRR5Z1V3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mRR5Z1V3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kxdg5uX4, 0, m, &cDelay_Kxdg5uX4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mRR5Z1V3, 0, m, &cDelay_mRR5Z1V3_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_e6ok9I4D, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Kxdg5uX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Kxdg5uX4, m);
  cMsg_j10oTYW6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Xj2bwxFT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_pZAjT8B2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_cuJkGsZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0iwsE5Up_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_1IyPiLjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_92r7H1wu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mRR5Z1V3, 2, m, &cDelay_mRR5Z1V3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Vb5sOCf0_sendMessage);
}

void Heavy_CircleStrings::cMsg_0iwsE5Up_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_1IyPiLjw, 0, m, &hTable_1IyPiLjw_sendMessage);
}

void Heavy_CircleStrings::cBinop_4C7MvVTA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_cuJkGsZZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_j10oTYW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_1IyPiLjw, 0, m, &hTable_1IyPiLjw_sendMessage);
}

void Heavy_CircleStrings::cCast_Vb5sOCf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mRR5Z1V3, 0, m, &cDelay_mRR5Z1V3_sendMessage);
}

void Heavy_CircleStrings::cMsg_92r7H1wu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kxdg5uX4, 2, m, &cDelay_Kxdg5uX4_sendMessage);
}

void Heavy_CircleStrings::cMsg_pZAjT8B2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_e6ok9I4D, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_ItJwIs5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WQs3BtMk, HV_BINOP_SUBTRACT, 0, m, &cBinop_WQs3BtMk_sendMessage);
}

void Heavy_CircleStrings::cMsg_SIMqWZLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1BXui80J_sendMessage);
}

void Heavy_CircleStrings::cSystem_1BXui80J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mC8IF8yI_sendMessage);
}

void Heavy_CircleStrings::cVar_qwMi1E7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wdh0CGMo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_jIxhAhQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jIxhAhQf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vv5i5GpJ, 0, m, &cDelay_vv5i5GpJ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8Nidq2pQ, 0, m, &sTabread_8Nidq2pQ_sendMessage);
}

void Heavy_CircleStrings::cDelay_vv5i5GpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vv5i5GpJ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8Nidq2pQ, 0, m, &sTabread_8Nidq2pQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vv5i5GpJ, 0, m, &cDelay_vv5i5GpJ_sendMessage);
}

void Heavy_CircleStrings::sTabread_8Nidq2pQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_5GtfAtR7, HV_BINOP_SUBTRACT, 0, m, &cBinop_5GtfAtR7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_EOWvKytc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QjCUzKys, HV_BINOP_MAX, 0, m, &cBinop_QjCUzKys_sendMessage);
}

void Heavy_CircleStrings::cBinop_mC8IF8yI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EOWvKytc, HV_BINOP_MULTIPLY, 0, m, &cBinop_EOWvKytc_sendMessage);
}

void Heavy_CircleStrings::cBinop_WQs3BtMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_usNZrXss_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8Nidq2pQ, 0, m, &sTabread_8Nidq2pQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2JChdN4R_sendMessage);
}

void Heavy_CircleStrings::cSystem_5LuyUjzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5GtfAtR7, HV_BINOP_SUBTRACT, 1, m, &cBinop_5GtfAtR7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vv5i5GpJ, 2, m, &cDelay_vv5i5GpJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_wdh0CGMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5LuyUjzm_sendMessage);
}

void Heavy_CircleStrings::cMsg_usNZrXss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jIxhAhQf, 0, m, &cDelay_jIxhAhQf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vv5i5GpJ, 0, m, &cDelay_vv5i5GpJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_kDR9iOsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_QjCUzKys, HV_BINOP_MAX, 1, m, &cBinop_QjCUzKys_sendMessage);
}

void Heavy_CircleStrings::cBinop_QjCUzKys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WQs3BtMk, HV_BINOP_SUBTRACT, 1, m, &cBinop_WQs3BtMk_sendMessage);
}

void Heavy_CircleStrings::cCast_2JChdN4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jIxhAhQf, 0, m, &cDelay_jIxhAhQf_sendMessage);
}

void Heavy_CircleStrings::cBinop_l1N0e0aE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jIxhAhQf, 2, m, &cDelay_jIxhAhQf_sendMessage);
}

void Heavy_CircleStrings::cBinop_5GtfAtR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_l1N0e0aE_sendMessage);
}

void Heavy_CircleStrings::cCast_2dLErNjq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qwMi1E7y, 0, m, &cVar_qwMi1E7y_sendMessage);
  cMsg_SIMqWZLa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ItJwIs5I, 0, m, &cTabhead_ItJwIs5I_sendMessage);
}

void Heavy_CircleStrings::cMsg_gAMHFrDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XpxAIeNB_sendMessage);
}

void Heavy_CircleStrings::cSystem_XpxAIeNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iGXNm8uX_sendMessage);
}

void Heavy_CircleStrings::cDelay_uSsGTTPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uSsGTTPB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gTAvxQHn, 0, m, &cDelay_gTAvxQHn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uSsGTTPB, 0, m, &cDelay_uSsGTTPB_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_p5nKzR9R, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_gTAvxQHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gTAvxQHn, m);
  cMsg_QVRJlI8D_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_yeDH3VRE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_auvKYPuf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_p7DN6KwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pOPFJy7F_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_NQMvacjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hLdjUef5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uSsGTTPB, 2, m, &cDelay_uSsGTTPB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EtKuLQMZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_pOPFJy7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_NQMvacjK, 0, m, &hTable_NQMvacjK_sendMessage);
}

void Heavy_CircleStrings::cBinop_iGXNm8uX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_p7DN6KwK_sendMessage);
}

void Heavy_CircleStrings::cMsg_QVRJlI8D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_NQMvacjK, 0, m, &hTable_NQMvacjK_sendMessage);
}

void Heavy_CircleStrings::cCast_EtKuLQMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uSsGTTPB, 0, m, &cDelay_uSsGTTPB_sendMessage);
}

void Heavy_CircleStrings::cMsg_hLdjUef5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_gTAvxQHn, 2, m, &cDelay_gTAvxQHn_sendMessage);
}

void Heavy_CircleStrings::cMsg_auvKYPuf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_p5nKzR9R, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_ICOwZe2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MfykjDvJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_MfykjDvJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_is38xJNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KuTXrQrI_sendMessage);
}

void Heavy_CircleStrings::cSystem_KuTXrQrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GCMvYUWc_sendMessage);
}

void Heavy_CircleStrings::cVar_gJxj81Jt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lldvnVsY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_8UgiGqi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8UgiGqi9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U512mxs8, 0, m, &cDelay_U512mxs8_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cQkiSUwi, 0, m, &sTabread_cQkiSUwi_sendMessage);
}

void Heavy_CircleStrings::cDelay_U512mxs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_U512mxs8, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cQkiSUwi, 0, m, &sTabread_cQkiSUwi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U512mxs8, 0, m, &cDelay_U512mxs8_sendMessage);
}

void Heavy_CircleStrings::sTabread_cQkiSUwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xeXxErpf, HV_BINOP_SUBTRACT, 0, m, &cBinop_xeXxErpf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_66XxsLv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rG58zcmi, HV_BINOP_MAX, 0, m, &cBinop_rG58zcmi_sendMessage);
}

void Heavy_CircleStrings::cBinop_GCMvYUWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_66XxsLv1, HV_BINOP_MULTIPLY, 0, m, &cBinop_66XxsLv1_sendMessage);
}

void Heavy_CircleStrings::cBinop_MfykjDvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U2GOU4v3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cQkiSUwi, 0, m, &sTabread_cQkiSUwi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OdRepPew_sendMessage);
}

void Heavy_CircleStrings::cSystem_UUYvjbyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xeXxErpf, HV_BINOP_SUBTRACT, 1, m, &cBinop_xeXxErpf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U512mxs8, 2, m, &cDelay_U512mxs8_sendMessage);
}

void Heavy_CircleStrings::cMsg_lldvnVsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UUYvjbyy_sendMessage);
}

void Heavy_CircleStrings::cMsg_U2GOU4v3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8UgiGqi9, 0, m, &cDelay_8UgiGqi9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U512mxs8, 0, m, &cDelay_U512mxs8_sendMessage);
}

void Heavy_CircleStrings::cMsg_c10HUcSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_rG58zcmi, HV_BINOP_MAX, 1, m, &cBinop_rG58zcmi_sendMessage);
}

void Heavy_CircleStrings::cBinop_rG58zcmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MfykjDvJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_MfykjDvJ_sendMessage);
}

void Heavy_CircleStrings::cCast_OdRepPew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8UgiGqi9, 0, m, &cDelay_8UgiGqi9_sendMessage);
}

void Heavy_CircleStrings::cBinop_Q9EegnWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8UgiGqi9, 2, m, &cDelay_8UgiGqi9_sendMessage);
}

void Heavy_CircleStrings::cBinop_xeXxErpf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Q9EegnWn_sendMessage);
}

void Heavy_CircleStrings::cCast_JzVzRSXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gJxj81Jt, 0, m, &cVar_gJxj81Jt_sendMessage);
  cMsg_is38xJNd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ICOwZe2j, 0, m, &cTabhead_ICOwZe2j_sendMessage);
}

void Heavy_CircleStrings::cMsg_uPu08k8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7ujtySoP_sendMessage);
}

void Heavy_CircleStrings::cSystem_7ujtySoP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EUDYHco5_sendMessage);
}

void Heavy_CircleStrings::cDelay_LGkI8mrh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LGkI8mrh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WnMg6fj1, 0, m, &cDelay_WnMg6fj1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LGkI8mrh, 0, m, &cDelay_LGkI8mrh_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TneWhgkR, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_WnMg6fj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WnMg6fj1, m);
  cMsg_TOkXU86S_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_UXDOBYJW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_bOgg2YDH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_t9pDfkft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ar7glH3J_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_yhmdKCjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZzCIFFFP_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LGkI8mrh, 2, m, &cDelay_LGkI8mrh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SZYWG2m3_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ar7glH3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_yhmdKCjm, 0, m, &hTable_yhmdKCjm_sendMessage);
}

void Heavy_CircleStrings::cBinop_EUDYHco5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_t9pDfkft_sendMessage);
}

void Heavy_CircleStrings::cMsg_TOkXU86S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_yhmdKCjm, 0, m, &hTable_yhmdKCjm_sendMessage);
}

void Heavy_CircleStrings::cCast_SZYWG2m3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LGkI8mrh, 0, m, &cDelay_LGkI8mrh_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZzCIFFFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WnMg6fj1, 2, m, &cDelay_WnMg6fj1_sendMessage);
}

void Heavy_CircleStrings::cMsg_bOgg2YDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TneWhgkR, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_WXjO9ZQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OknfrXzN, HV_BINOP_SUBTRACT, 0, m, &cBinop_OknfrXzN_sendMessage);
}

void Heavy_CircleStrings::cMsg_QyFjgtnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mh22iVjP_sendMessage);
}

void Heavy_CircleStrings::cSystem_mh22iVjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NwuX3bCK_sendMessage);
}

void Heavy_CircleStrings::cVar_wKNcvn0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Br4m8PAe_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_oQ87xSQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oQ87xSQ0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SJP0bFdq, 0, m, &cDelay_SJP0bFdq_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OJZ4H1g2, 0, m, &sTabread_OJZ4H1g2_sendMessage);
}

void Heavy_CircleStrings::cDelay_SJP0bFdq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SJP0bFdq, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OJZ4H1g2, 0, m, &sTabread_OJZ4H1g2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SJP0bFdq, 0, m, &cDelay_SJP0bFdq_sendMessage);
}

void Heavy_CircleStrings::sTabread_OJZ4H1g2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_31Tcjtr6, HV_BINOP_SUBTRACT, 0, m, &cBinop_31Tcjtr6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Gb0AnyML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_no78YeHx, HV_BINOP_MAX, 0, m, &cBinop_no78YeHx_sendMessage);
}

void Heavy_CircleStrings::cBinop_NwuX3bCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gb0AnyML, HV_BINOP_MULTIPLY, 0, m, &cBinop_Gb0AnyML_sendMessage);
}

void Heavy_CircleStrings::cBinop_OknfrXzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eTvSjhir_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OJZ4H1g2, 0, m, &sTabread_OJZ4H1g2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LgSFQbEx_sendMessage);
}

void Heavy_CircleStrings::cSystem_5dYR5Doa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_31Tcjtr6, HV_BINOP_SUBTRACT, 1, m, &cBinop_31Tcjtr6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SJP0bFdq, 2, m, &cDelay_SJP0bFdq_sendMessage);
}

void Heavy_CircleStrings::cMsg_Br4m8PAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5dYR5Doa_sendMessage);
}

void Heavy_CircleStrings::cMsg_eTvSjhir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQ87xSQ0, 0, m, &cDelay_oQ87xSQ0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SJP0bFdq, 0, m, &cDelay_SJP0bFdq_sendMessage);
}

void Heavy_CircleStrings::cMsg_N6ytcKhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_no78YeHx, HV_BINOP_MAX, 1, m, &cBinop_no78YeHx_sendMessage);
}

void Heavy_CircleStrings::cBinop_no78YeHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OknfrXzN, HV_BINOP_SUBTRACT, 1, m, &cBinop_OknfrXzN_sendMessage);
}

void Heavy_CircleStrings::cCast_LgSFQbEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQ87xSQ0, 0, m, &cDelay_oQ87xSQ0_sendMessage);
}

void Heavy_CircleStrings::cBinop_4giDshok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQ87xSQ0, 2, m, &cDelay_oQ87xSQ0_sendMessage);
}

void Heavy_CircleStrings::cBinop_31Tcjtr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4giDshok_sendMessage);
}

void Heavy_CircleStrings::cCast_uovhGRVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wKNcvn0L, 0, m, &cVar_wKNcvn0L_sendMessage);
  cMsg_QyFjgtnu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WXjO9ZQr, 0, m, &cTabhead_WXjO9ZQr_sendMessage);
}

void Heavy_CircleStrings::cMsg_tDjrFSdK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0IC8JQPy_sendMessage);
}

void Heavy_CircleStrings::cSystem_0IC8JQPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Wm4zkjAr_sendMessage);
}

void Heavy_CircleStrings::cDelay_D4wWHpQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_D4wWHpQ1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jq4trc2U, 0, m, &cDelay_jq4trc2U_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_D4wWHpQ1, 0, m, &cDelay_D4wWHpQ1_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_XPR4i9p7, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_jq4trc2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jq4trc2U, m);
  cMsg_K6sdNM7k_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_pQaU02T0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_qZ0WfBAG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_qdGwSTNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pB1Y5TGM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_jrFYetRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EhVv94Ba_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_D4wWHpQ1, 2, m, &cDelay_D4wWHpQ1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KlFtFBNl_sendMessage);
}

void Heavy_CircleStrings::cMsg_pB1Y5TGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jrFYetRt, 0, m, &hTable_jrFYetRt_sendMessage);
}

void Heavy_CircleStrings::cBinop_Wm4zkjAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_qdGwSTNt_sendMessage);
}

void Heavy_CircleStrings::cMsg_K6sdNM7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jrFYetRt, 0, m, &hTable_jrFYetRt_sendMessage);
}

void Heavy_CircleStrings::cCast_KlFtFBNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_D4wWHpQ1, 0, m, &cDelay_D4wWHpQ1_sendMessage);
}

void Heavy_CircleStrings::cMsg_EhVv94Ba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_jq4trc2U, 2, m, &cDelay_jq4trc2U_sendMessage);
}

void Heavy_CircleStrings::cMsg_qZ0WfBAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_XPR4i9p7, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_kUNPvE6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YVCceG8T, 0, m, &cVar_YVCceG8T_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VfGQc1d4, 0, m, &cVar_VfGQc1d4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IemS5MsI, 0, m, &cVar_IemS5MsI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MEWRxRwf, 0, m, &cVar_MEWRxRwf_sendMessage);
}

void Heavy_CircleStrings::cVar_UEDzTp9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_IfOoMDOk_sendMessage);
}

void Heavy_CircleStrings::cPack_Z2u3Ykeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_N6p4nVym, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_VfGQc1d4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tHZzAZjl, HV_BINOP_MULTIPLY, 0, m, &cBinop_tHZzAZjl_sendMessage);
}

void Heavy_CircleStrings::cMsg_DHZQVDbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kn8IL1cW_sendMessage);
}

void Heavy_CircleStrings::cSystem_kn8IL1cW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pJGZAVuS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_tHZzAZjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2tJSuT0V_sendMessage);
}

void Heavy_CircleStrings::cBinop_ehsHX0tv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tHZzAZjl, HV_BINOP_MULTIPLY, 1, m, &cBinop_tHZzAZjl_sendMessage);
}

void Heavy_CircleStrings::cMsg_pJGZAVuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ehsHX0tv_sendMessage);
}

void Heavy_CircleStrings::cBinop_2tJSuT0V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ySAhxjYC_sendMessage);
}

void Heavy_CircleStrings::cBinop_ySAhxjYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mZ7ECj75_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EDUAgIXE, m);
}

void Heavy_CircleStrings::cBinop_mZ7ECj75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_u2EAJiQ7, m);
}

void Heavy_CircleStrings::cVar_IemS5MsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xr5wRE0M, HV_BINOP_MULTIPLY, 0, m, &cBinop_xr5wRE0M_sendMessage);
}

void Heavy_CircleStrings::cMsg_AvtEXuPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IxiGvHSw_sendMessage);
}

void Heavy_CircleStrings::cSystem_IxiGvHSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_648URXK7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_xr5wRE0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_3ZnzydAq_sendMessage);
}

void Heavy_CircleStrings::cBinop_XQJKjEBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xr5wRE0M, HV_BINOP_MULTIPLY, 1, m, &cBinop_xr5wRE0M_sendMessage);
}

void Heavy_CircleStrings::cMsg_648URXK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XQJKjEBk_sendMessage);
}

void Heavy_CircleStrings::cBinop_3ZnzydAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GMPNYRIx_sendMessage);
}

void Heavy_CircleStrings::cBinop_GMPNYRIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_IffDmoXo_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_75BE69WV, m);
}

void Heavy_CircleStrings::cBinop_IffDmoXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qJQ6uhSI, m);
}

void Heavy_CircleStrings::cVar_MEWRxRwf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tPXoTent, HV_BINOP_MULTIPLY, 0, m, &cBinop_tPXoTent_sendMessage);
}

void Heavy_CircleStrings::cMsg_rKd1ZkwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RBOnbdsX_sendMessage);
}

void Heavy_CircleStrings::cSystem_RBOnbdsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wwzurj3i_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_tPXoTent_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0wMrcuD8_sendMessage);
}

void Heavy_CircleStrings::cBinop_LMif6RwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tPXoTent, HV_BINOP_MULTIPLY, 1, m, &cBinop_tPXoTent_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wwzurj3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_LMif6RwC_sendMessage);
}

void Heavy_CircleStrings::cBinop_0wMrcuD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PYDM7SwC_sendMessage);
}

void Heavy_CircleStrings::cBinop_PYDM7SwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_R4qW9qd4_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wooYlybz, m);
}

void Heavy_CircleStrings::cBinop_R4qW9qd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZK1L3VRX, m);
}

void Heavy_CircleStrings::cBinop_V3r0FkZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_U7XV9pWd, 0, m, &cPack_U7XV9pWd_sendMessage);
}

void Heavy_CircleStrings::cMsg_DElYKlBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kUNPvE6N, 0, m, &cVar_kUNPvE6N_sendMessage);
}

void Heavy_CircleStrings::cBinop_IfOoMDOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Z2u3Ykeb, 0, m, &cPack_Z2u3Ykeb_sendMessage);
}

void Heavy_CircleStrings::cBinop_7hvcmCp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_naduErNi, 0, m, &cPack_naduErNi_sendMessage);
}

void Heavy_CircleStrings::cMsg_mdrShoJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hp7FcxDO_sendMessage);
}

void Heavy_CircleStrings::cSystem_hp7FcxDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d5BRYS9Q_sendMessage);
}

void Heavy_CircleStrings::cVar_91yl8Gta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rYHGtrDd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_1Bluaki1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RJUJgnV8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dhi2ax7Z, m);
}

void Heavy_CircleStrings::cBinop_d5BRYS9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_t5UdQyCM, m);
}

void Heavy_CircleStrings::cMsg_rYHGtrDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1Bluaki1_sendMessage);
}

void Heavy_CircleStrings::cBinop_RJUJgnV8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VrBDfl6D, m);
}

void Heavy_CircleStrings::cVar_5wBpilFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y2jaGcKK, HV_BINOP_MULTIPLY, 0, m, &cBinop_y2jaGcKK_sendMessage);
}

void Heavy_CircleStrings::cMsg_RfUxRlQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CuXj8seq_sendMessage);
}

void Heavy_CircleStrings::cSystem_CuXj8seq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v15U0xOz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_y2jaGcKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Caf98POg_sendMessage);
}

void Heavy_CircleStrings::cBinop_SND9iAfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y2jaGcKK, HV_BINOP_MULTIPLY, 1, m, &cBinop_y2jaGcKK_sendMessage);
}

void Heavy_CircleStrings::cMsg_v15U0xOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SND9iAfs_sendMessage);
}

void Heavy_CircleStrings::cBinop_Caf98POg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_faKUIsmd_sendMessage);
}

void Heavy_CircleStrings::cBinop_faKUIsmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_M8BWd7q6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_UuFC3M6c, m);
}

void Heavy_CircleStrings::cBinop_M8BWd7q6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wd6gq4RM, m);
}

void Heavy_CircleStrings::cBinop_5laMyoo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_ck3oZFJM_sendMessage);
}

void Heavy_CircleStrings::cBinop_ck3oZFJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Pum6MStC, m);
}

void Heavy_CircleStrings::cBinop_Q1DI930H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9QBjiI5x_sendMessage);
}

void Heavy_CircleStrings::cBinop_9QBjiI5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_KjigIDaV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2TX6DfpR_sendMessage);
}

void Heavy_CircleStrings::cVar_8Ic7bcIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_861guc85_sendMessage);
}

void Heavy_CircleStrings::cMsg_k9JehG4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MIYnfRGQ_sendMessage);
}

void Heavy_CircleStrings::cSystem_MIYnfRGQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mujxcxdA, HV_BINOP_DIVIDE, 1, m, &cBinop_mujxcxdA_sendMessage);
}

void Heavy_CircleStrings::cBinop_KjigIDaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_8c7VRNDg_sendMessage);
}

void Heavy_CircleStrings::cBinop_8c7VRNDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rjchOTv1, m);
}

void Heavy_CircleStrings::cMsg_8kZ9DiWR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_QvyuIgiB_sendMessage);
}

void Heavy_CircleStrings::cBinop_QvyuIgiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Q1DI930H_sendMessage);
}

void Heavy_CircleStrings::cBinop_2TX6DfpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jKQqvB3L, m);
}

void Heavy_CircleStrings::cBinop_861guc85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_H1RwG0iB_sendMessage);
}

void Heavy_CircleStrings::cBinop_H1RwG0iB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mujxcxdA, HV_BINOP_DIVIDE, 0, m, &cBinop_mujxcxdA_sendMessage);
}

void Heavy_CircleStrings::cBinop_mujxcxdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8kZ9DiWR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_SSGN3iuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XJsDqWP5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ZAlwokAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FvD005ex_sendMessage);
}

void Heavy_CircleStrings::cSystem_FvD005ex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4CbCKica_sendMessage);
}

void Heavy_CircleStrings::cDelay_YHjmxGZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YHjmxGZ4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IFdQHfGH, 0, m, &cDelay_IFdQHfGH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YHjmxGZ4, 0, m, &cDelay_YHjmxGZ4_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zyInRbYq, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_IFdQHfGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IFdQHfGH, m);
  cMsg_Vp5f7M7d_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_7ii7zZop_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_hlcfy4Sj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_FcirKf7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h2nHZ85D_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_II1ikMgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HCBlK93D_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YHjmxGZ4, 2, m, &cDelay_YHjmxGZ4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a97yj6KS_sendMessage);
}

void Heavy_CircleStrings::cMsg_h2nHZ85D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_II1ikMgh, 0, m, &hTable_II1ikMgh_sendMessage);
}

void Heavy_CircleStrings::cBinop_4CbCKica_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_FcirKf7C_sendMessage);
}

void Heavy_CircleStrings::cMsg_Vp5f7M7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_II1ikMgh, 0, m, &hTable_II1ikMgh_sendMessage);
}

void Heavy_CircleStrings::cCast_a97yj6KS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YHjmxGZ4, 0, m, &cDelay_YHjmxGZ4_sendMessage);
}

void Heavy_CircleStrings::cMsg_HCBlK93D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_IFdQHfGH, 2, m, &cDelay_IFdQHfGH_sendMessage);
}

void Heavy_CircleStrings::cMsg_hlcfy4Sj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zyInRbYq, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_cdIzmBn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_XJsDqWP5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_XJsDqWP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_TWR4wN7V, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_uYedG795_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_u9S7JWC0, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_UyfLw4BK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_hybV6izI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_g62rnJFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uYedG795, 0, m, &cPack_uYedG795_sendMessage);
}

void Heavy_CircleStrings::cMsg_SwBw0d4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_u9S7JWC0, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_ZrgLUHzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rlwqUzFu, m);
}

void Heavy_CircleStrings::cMsg_PaPIZLjx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5laMyoo0_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_bzIxUs5k_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_T0O4d14r, 0, m, &cSlice_T0O4d14r_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LiLlKnno, 0, m, &cRandom_LiLlKnno_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_SGTWzMMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LeJVg0JV_sendMessage);
}

void Heavy_CircleStrings::cUnop_LeJVg0JV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_oC8ovUE7_sendMessage);
}

void Heavy_CircleStrings::cRandom_LiLlKnno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_SGTWzMMm_sendMessage);
}

void Heavy_CircleStrings::cSlice_T0O4d14r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LiLlKnno, 1, m, &cRandom_LiLlKnno_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_fkqHH3yT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kQiJTqc2, 0, m, &cSlice_kQiJTqc2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Po2m533I, 0, m, &cRandom_Po2m533I_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_EBwd9xuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qsUlP2lv_sendMessage);
}

void Heavy_CircleStrings::cUnop_qsUlP2lv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9FA0JaGg, 0, m, &cPack_9FA0JaGg_sendMessage);
}

void Heavy_CircleStrings::cRandom_Po2m533I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_EBwd9xuE_sendMessage);
}

void Heavy_CircleStrings::cSlice_kQiJTqc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Po2m533I, 1, m, &cRandom_Po2m533I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_JPbSI8om_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_DJdUPhDN_sendMessage);
}

void Heavy_CircleStrings::cPack_AAcwLXcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6AysHDid, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_0VyQPxE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tBr2iVHT_sendMessage);
}

void Heavy_CircleStrings::cBinop_sTkVyLs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_0VyQPxE8_sendMessage);
}

void Heavy_CircleStrings::cPack_JFjepkEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RcxqwAGM, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_hoTMPCzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_N7UoLwI9_sendMessage);
}

void Heavy_CircleStrings::cMsg_TEM1w6QG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1Q9GZEoz_sendMessage);
}

void Heavy_CircleStrings::cSystem_1Q9GZEoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uR2sBL1A_sendMessage);
}

void Heavy_CircleStrings::cDelay_63a5HLmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_63a5HLmT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qc6W3W9n, 0, m, &cDelay_Qc6W3W9n_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_63a5HLmT, 0, m, &cDelay_63a5HLmT_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fWWz3GnM, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Qc6W3W9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Qc6W3W9n, m);
  cMsg_tApuq3Ze_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_LWePc5O4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jl0dXsU1_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_woOWV3gG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OJzcqE2S_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_rFdRAEVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JbYwQFHj_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_63a5HLmT, 2, m, &cDelay_63a5HLmT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iyIBjpIS_sendMessage);
}

void Heavy_CircleStrings::cMsg_OJzcqE2S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rFdRAEVz, 0, m, &hTable_rFdRAEVz_sendMessage);
}

void Heavy_CircleStrings::cBinop_uR2sBL1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_woOWV3gG_sendMessage);
}

void Heavy_CircleStrings::cMsg_tApuq3Ze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rFdRAEVz, 0, m, &hTable_rFdRAEVz_sendMessage);
}

void Heavy_CircleStrings::cCast_iyIBjpIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_63a5HLmT, 0, m, &cDelay_63a5HLmT_sendMessage);
}

void Heavy_CircleStrings::cMsg_JbYwQFHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qc6W3W9n, 2, m, &cDelay_Qc6W3W9n_sendMessage);
}

void Heavy_CircleStrings::cMsg_jl0dXsU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fWWz3GnM, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_poarQBtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l3MU6mB6_sendMessage);
}

void Heavy_CircleStrings::cSystem_l3MU6mB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_19T5acID_sendMessage);
}

void Heavy_CircleStrings::cVar_p3Fea6N1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y92jRpYU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_Px1RWwP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KzlYoug1_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IJ4UWDfs, m);
}

void Heavy_CircleStrings::cBinop_19T5acID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aTGnahLi, m);
}

void Heavy_CircleStrings::cMsg_y92jRpYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Px1RWwP1_sendMessage);
}

void Heavy_CircleStrings::cBinop_KzlYoug1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TFSPRgPI, m);
}

void Heavy_CircleStrings::cMsg_GReGWCvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kDMFVKj1_sendMessage);
}

void Heavy_CircleStrings::cSystem_kDMFVKj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Fo7LbzzB_sendMessage);
}

void Heavy_CircleStrings::cVar_VzqP7kSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ig75CraO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_JGNsorGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_PvFx7GKQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_U7RJcLxh, m);
}

void Heavy_CircleStrings::cBinop_Fo7LbzzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wVgd2iFq, m);
}

void Heavy_CircleStrings::cMsg_Ig75CraO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JGNsorGb_sendMessage);
}

void Heavy_CircleStrings::cBinop_PvFx7GKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_49JgxUZF, m);
}

void Heavy_CircleStrings::cBinop_SgmAujCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wrh4foj7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_2xLKrMHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JH5h6ErN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tZysj6yN_sendMessage);
}

void Heavy_CircleStrings::cCast_JH5h6ErN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SgmAujCc, HV_BINOP_DIVIDE, 1, m, &cBinop_SgmAujCc_sendMessage);
}

void Heavy_CircleStrings::cCast_tZysj6yN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SgmAujCc, HV_BINOP_DIVIDE, 0, m, &cBinop_SgmAujCc_sendMessage);
}

void Heavy_CircleStrings::cBinop_tBr2iVHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zbM35RxD_sendMessage);
}

void Heavy_CircleStrings::cBinop_9LLFA5ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_sTkVyLs6_sendMessage);
}

void Heavy_CircleStrings::cBinop_zbM35RxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SgmAujCc, HV_BINOP_DIVIDE, 0, m, &cBinop_SgmAujCc_sendMessage);
}

void Heavy_CircleStrings::cBinop_N7UoLwI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JFjepkEL, 0, m, &cPack_JFjepkEL_sendMessage);
}

void Heavy_CircleStrings::cBinop_DJdUPhDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_2xLKrMHY_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_AAcwLXcx, 0, m, &cPack_AAcwLXcx_sendMessage);
}

void Heavy_CircleStrings::cMsg_pLpYE0MY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_JPbSI8om, 0, m, &cVar_JPbSI8om_sendMessage);
}

void Heavy_CircleStrings::cMsg_xo3vDOW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_hoTMPCzr, 0, m, &cVar_hoTMPCzr_sendMessage);
}

void Heavy_CircleStrings::cMsg_wrh4foj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_4rSQg1y0, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_Yuai6U5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6hVnSqlq_sendMessage);
}

void Heavy_CircleStrings::cSystem_6hVnSqlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iOgVrMcm_sendMessage);
}

void Heavy_CircleStrings::cVar_DYZvLs8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N7KLMP9x_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_vUctybPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KbAnzSNp_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HUMExlBT, m);
}

void Heavy_CircleStrings::cBinop_iOgVrMcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iqLR9ako, m);
}

void Heavy_CircleStrings::cMsg_N7KLMP9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vUctybPy_sendMessage);
}

void Heavy_CircleStrings::cBinop_KbAnzSNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Rymz08w1, m);
}

void Heavy_CircleStrings::cVar_lDIoQcFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EkAuViHy, HV_BINOP_MULTIPLY, 0, m, &cBinop_EkAuViHy_sendMessage);
}

void Heavy_CircleStrings::cMsg_nzVKibc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IYgtBezD_sendMessage);
}

void Heavy_CircleStrings::cSystem_IYgtBezD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TYkjxQL6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_EkAuViHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7iFvIgg9_sendMessage);
}

void Heavy_CircleStrings::cBinop_fRN9fi1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EkAuViHy, HV_BINOP_MULTIPLY, 1, m, &cBinop_EkAuViHy_sendMessage);
}

void Heavy_CircleStrings::cMsg_TYkjxQL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_fRN9fi1Z_sendMessage);
}

void Heavy_CircleStrings::cBinop_7iFvIgg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9tAm5S9N_sendMessage);
}

void Heavy_CircleStrings::cBinop_9tAm5S9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_PltgnVXf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bp2q5nQP, m);
}

void Heavy_CircleStrings::cBinop_PltgnVXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ecj6eNGv, m);
}

void Heavy_CircleStrings::cBinop_Ejeqyn7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_Yv0BVkEL_sendMessage);
}

void Heavy_CircleStrings::cBinop_Yv0BVkEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ux9rIswl, m);
}

void Heavy_CircleStrings::cBinop_bpmnIBt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0SRC6CO3_sendMessage);
}

void Heavy_CircleStrings::cBinop_0SRC6CO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_eswx0CCH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3lR7U6gc_sendMessage);
}

void Heavy_CircleStrings::cVar_apMxCtU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_6KPdZXOU_sendMessage);
}

void Heavy_CircleStrings::cMsg_zlfgGabQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Sj6v6Zav_sendMessage);
}

void Heavy_CircleStrings::cSystem_Sj6v6Zav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i1Q31y4g, HV_BINOP_DIVIDE, 1, m, &cBinop_i1Q31y4g_sendMessage);
}

void Heavy_CircleStrings::cBinop_eswx0CCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_n4H4k4TS_sendMessage);
}

void Heavy_CircleStrings::cBinop_n4H4k4TS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dAS8Zvpc, m);
}

void Heavy_CircleStrings::cMsg_zbV4DZzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_jgDP9eht_sendMessage);
}

void Heavy_CircleStrings::cBinop_jgDP9eht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_bpmnIBt2_sendMessage);
}

void Heavy_CircleStrings::cBinop_3lR7U6gc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_s3EHt4tr, m);
}

void Heavy_CircleStrings::cBinop_6KPdZXOU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_OD0CKp32_sendMessage);
}

void Heavy_CircleStrings::cBinop_OD0CKp32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i1Q31y4g, HV_BINOP_DIVIDE, 0, m, &cBinop_i1Q31y4g_sendMessage);
}

void Heavy_CircleStrings::cBinop_i1Q31y4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zbV4DZzI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_6iiGrCPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QyvlPBRd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_5I5IZ1pW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yeiUE257_sendMessage);
}

void Heavy_CircleStrings::cSystem_yeiUE257_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UrsEH0Nr_sendMessage);
}

void Heavy_CircleStrings::cDelay_1zdqCr6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1zdqCr6O, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZzsBulQO, 0, m, &cDelay_ZzsBulQO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1zdqCr6O, 0, m, &cDelay_1zdqCr6O_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oFIjphYF, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_ZzsBulQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZzsBulQO, m);
  cMsg_6w78YDxu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_KvfQjNrg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_0ZVbbKmB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_RN3gjHvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9f8mYRmw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_4zsVnGpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GpxFYcQh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1zdqCr6O, 2, m, &cDelay_1zdqCr6O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zl6gUEAB_sendMessage);
}

void Heavy_CircleStrings::cMsg_9f8mYRmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_4zsVnGpw, 0, m, &hTable_4zsVnGpw_sendMessage);
}

void Heavy_CircleStrings::cBinop_UrsEH0Nr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_RN3gjHvg_sendMessage);
}

void Heavy_CircleStrings::cMsg_6w78YDxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_4zsVnGpw, 0, m, &hTable_4zsVnGpw_sendMessage);
}

void Heavy_CircleStrings::cCast_Zl6gUEAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1zdqCr6O, 0, m, &cDelay_1zdqCr6O_sendMessage);
}

void Heavy_CircleStrings::cMsg_GpxFYcQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZzsBulQO, 2, m, &cDelay_ZzsBulQO_sendMessage);
}

void Heavy_CircleStrings::cMsg_0ZVbbKmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oFIjphYF, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_YvkoeVMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_QyvlPBRd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_QyvlPBRd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_oL3VrOOc, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_GzbqHShH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_E030jJS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6ftYT6zY_sendMessage);
}

void Heavy_CircleStrings::cSystem_6ftYT6zY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KoO3DBjS, HV_BINOP_MULTIPLY, 1, m, &cBinop_KoO3DBjS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jtPqQX1r, HV_BINOP_MULTIPLY, 1, m, &cBinop_jtPqQX1r_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_f86OpdKG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_HrMrMyM0_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HrMrMyM0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d8bkmohX_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_cDsJD5Ul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cDsJD5Ul, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cDsJD5Ul, 0, m, &cDelay_cDsJD5Ul_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Jlh1KjsJ, 0, m, &cVar_Jlh1KjsJ_sendMessage);
}

void Heavy_CircleStrings::cCast_d8bkmohX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HrMrMyM0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cDsJD5Ul, 0, m, &cDelay_cDsJD5Ul_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Jlh1KjsJ, 0, m, &cVar_Jlh1KjsJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_EVlhq7Un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TH2kx2Ms_sendMessage);
}

void Heavy_CircleStrings::cSystem_TH2kx2Ms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xszKnDxL_sendMessage);
}

void Heavy_CircleStrings::cVar_Vquy3exB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VtnBXEUz, HV_BINOP_MULTIPLY, 0, m, &cBinop_VtnBXEUz_sendMessage);
}

void Heavy_CircleStrings::cMsg_HrMrMyM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cDsJD5Ul, 0, m, &cDelay_cDsJD5Ul_sendMessage);
}

void Heavy_CircleStrings::cBinop_FXRH0OvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cDsJD5Ul, 2, m, &cDelay_cDsJD5Ul_sendMessage);
}

void Heavy_CircleStrings::cBinop_xszKnDxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VtnBXEUz, HV_BINOP_MULTIPLY, 1, m, &cBinop_VtnBXEUz_sendMessage);
}

void Heavy_CircleStrings::cBinop_VtnBXEUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_FXRH0OvZ_sendMessage);
}

void Heavy_CircleStrings::cVar_Jlh1KjsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cqprurle, HV_BINOP_SUBTRACT, 0, m, &cBinop_cqprurle_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_NTCdrYiL_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_Ti697pEU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fMFrS23H_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ozJF0c7a_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_fMFrS23H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_849Yfp40, 0, m, &cVar_849Yfp40_sendMessage);
}

void Heavy_CircleStrings::cCast_ozJF0c7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_saBkndUe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KPdt2HNT_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_sBOzVzfA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MVNtCIG3, 0, m, &cSlice_MVNtCIG3_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QWgt38LO, 0, m, &cSlice_QWgt38LO_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HLj0TbOY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_q7RczXOE, 0, m, &cSlice_q7RczXOE_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_a3hhL6n8, 0, m, &cSlice_a3hhL6n8_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mjKBASCv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dcYUL8hW_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_MVNtCIG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_MU5qzdw8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_MU5qzdw8_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_QWgt38LO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ASwrQA1a_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4AorfmpA_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ASwrQA1a_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4AorfmpA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_i4L1zkmH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SN1Q5l3r_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3gdEp95d_sendMessage);
}

void Heavy_CircleStrings::cVar_BLRHJtYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Z0jdXZlE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_Z0jdXZlE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zcBbqERS_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KoO3DBjS, HV_BINOP_MULTIPLY, 0, m, &cBinop_KoO3DBjS_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_tl7NRVHd, HV_BINOP_DIVIDE, 1, m, &cBinop_tl7NRVHd_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Vquy3exB, 0, m, &cVar_Vquy3exB_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_zcBbqERS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bX10CLvo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_8W0AnBcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TxrzZRts, HV_BINOP_SUBTRACT, 1, m, &cBinop_TxrzZRts_sendMessage);
}

void Heavy_CircleStrings::cVar_bTxypiiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_849Yfp40, 0, m, &cVar_849Yfp40_sendMessage);
}

void Heavy_CircleStrings::cVar_849Yfp40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U5jbamss, HV_BINOP_ADD, 0, m, &cBinop_U5jbamss_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_28x329e3, HV_BINOP_ADD, 0, m, &cBinop_28x329e3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ORnZLAug, 0, m, &cVar_ORnZLAug_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_9LLFA5ae_sendMessage);
}

void Heavy_CircleStrings::cSlice_q7RczXOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SN1Q5l3r_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3gdEp95d_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_a3hhL6n8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fcpGnPuY_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UtVc78Ar_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_40o5KYK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Jlh1KjsJ, 1, m, &cVar_Jlh1KjsJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_jtPqQX1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_40o5KYK3_sendMessage);
}

void Heavy_CircleStrings::cBinop_KoO3DBjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WQtRp1F4_sendMessage);
}

void Heavy_CircleStrings::cBinop_WQtRp1F4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cqprurle, HV_BINOP_SUBTRACT, 1, m, &cBinop_cqprurle_sendMessage);
}

void Heavy_CircleStrings::cBinop_cqprurle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Jlh1KjsJ, 1, m, &cVar_Jlh1KjsJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_USRE5ynK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_f86OpdKG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_hDHyrgBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_f86OpdKG_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_28x329e3, HV_BINOP_ADD, 1, m, &cBinop_28x329e3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_U5jbamss, HV_BINOP_ADD, 1, m, &cBinop_U5jbamss_sendMessage);
}

void Heavy_CircleStrings::cBinop_NTCdrYiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ti697pEU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_U5jbamss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_849Yfp40, 1, m, &cVar_849Yfp40_sendMessage);
}

void Heavy_CircleStrings::cBinop_tl7NRVHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XTg3fl3w, HV_BINOP_DIVIDE, 1, m, &cBinop_XTg3fl3w_sendMessage);
}

void Heavy_CircleStrings::cBinop_XTg3fl3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_28x329e3, HV_BINOP_ADD, 1, m, &cBinop_28x329e3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_U5jbamss, HV_BINOP_ADD, 1, m, &cBinop_U5jbamss_sendMessage);
}

void Heavy_CircleStrings::cCast_3gdEp95d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tl7NRVHd, HV_BINOP_DIVIDE, 0, m, &cBinop_tl7NRVHd_sendMessage);
}

void Heavy_CircleStrings::cCast_SN1Q5l3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jtPqQX1r, HV_BINOP_MULTIPLY, 0, m, &cBinop_jtPqQX1r_sendMessage);
}

void Heavy_CircleStrings::cCast_fcpGnPuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bTxypiiy, 1, m, &cVar_bTxypiiy_sendMessage);
}

void Heavy_CircleStrings::cCast_UtVc78Ar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TxrzZRts, HV_BINOP_SUBTRACT, 0, m, &cBinop_TxrzZRts_sendMessage);
}

void Heavy_CircleStrings::cCast_KPdt2HNT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bTxypiiy, 0, m, &cVar_bTxypiiy_sendMessage);
}

void Heavy_CircleStrings::cCast_saBkndUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hDHyrgBu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_28x329e3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8W0AnBcs, 0, m, &cVar_8W0AnBcs_sendMessage);
}

void Heavy_CircleStrings::cMsg_MU5qzdw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_f86OpdKG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_dTdlmySd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_i4L1zkmH, 1, m, &cVar_i4L1zkmH_sendMessage);
}

void Heavy_CircleStrings::cMsg_bX10CLvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KoO3DBjS, HV_BINOP_MULTIPLY, 0, m, &cBinop_KoO3DBjS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tl7NRVHd, HV_BINOP_DIVIDE, 1, m, &cBinop_tl7NRVHd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Vquy3exB, 0, m, &cVar_Vquy3exB_sendMessage);
}

void Heavy_CircleStrings::cCast_4AorfmpA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6uxX7Qt5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_28x329e3, HV_BINOP_ADD, 0, m, &cBinop_28x329e3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_849Yfp40, 1, m, &cVar_849Yfp40_sendMessage);
}

void Heavy_CircleStrings::cCast_ASwrQA1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MU5qzdw8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_TxrzZRts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XTg3fl3w, HV_BINOP_DIVIDE, 0, m, &cBinop_XTg3fl3w_sendMessage);
}

void Heavy_CircleStrings::cCast_6uxX7Qt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hDHyrgBu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_dcYUL8hW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dTdlmySd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_HLj0TbOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_i4L1zkmH, 0, m, &cVar_i4L1zkmH_sendMessage);
}

void Heavy_CircleStrings::cCast_mjKBASCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_USRE5ynK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_ORnZLAug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cPack_ZYnNyGW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sBOzVzfA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_fDD0A3FT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4OwBFN07_sendMessage);
}

void Heavy_CircleStrings::cSystem_4OwBFN07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RraCo6PL, HV_BINOP_MULTIPLY, 1, m, &cBinop_RraCo6PL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GrzwiFJj, HV_BINOP_MULTIPLY, 1, m, &cBinop_GrzwiFJj_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_k0fu5SjA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_QAEKPSOu_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_QAEKPSOu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gHGJtcMC_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_6kCcF4h7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6kCcF4h7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6kCcF4h7, 0, m, &cDelay_6kCcF4h7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dzY1zz7N, 0, m, &cVar_dzY1zz7N_sendMessage);
}

void Heavy_CircleStrings::cCast_gHGJtcMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QAEKPSOu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6kCcF4h7, 0, m, &cDelay_6kCcF4h7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dzY1zz7N, 0, m, &cVar_dzY1zz7N_sendMessage);
}

void Heavy_CircleStrings::cMsg_hIiPdr2a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n13E0Ist_sendMessage);
}

void Heavy_CircleStrings::cSystem_n13E0Ist_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MTt7PErz_sendMessage);
}

void Heavy_CircleStrings::cVar_vkHJZu37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PwJNIPFq, HV_BINOP_MULTIPLY, 0, m, &cBinop_PwJNIPFq_sendMessage);
}

void Heavy_CircleStrings::cMsg_QAEKPSOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6kCcF4h7, 0, m, &cDelay_6kCcF4h7_sendMessage);
}

void Heavy_CircleStrings::cBinop_3AtLho8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6kCcF4h7, 2, m, &cDelay_6kCcF4h7_sendMessage);
}

void Heavy_CircleStrings::cBinop_MTt7PErz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PwJNIPFq, HV_BINOP_MULTIPLY, 1, m, &cBinop_PwJNIPFq_sendMessage);
}

void Heavy_CircleStrings::cBinop_PwJNIPFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_3AtLho8U_sendMessage);
}

void Heavy_CircleStrings::cVar_dzY1zz7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kO5Fp9H5, HV_BINOP_SUBTRACT, 0, m, &cBinop_kO5Fp9H5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_cN87oeVd_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_FbXhQTII_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jxh4A8gr_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xSB6LXJe_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_jxh4A8gr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NPxXbOtX, 0, m, &cVar_NPxXbOtX_sendMessage);
}

void Heavy_CircleStrings::cCast_xSB6LXJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ThodOk3q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aNMXhGrZ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_iGMBoNMB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jzA4fdLk, 0, m, &cSlice_jzA4fdLk_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hMPZlwxa, 0, m, &cSlice_hMPZlwxa_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_taAaRb5K_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_OJRoP9L4, 0, m, &cSlice_OJRoP9L4_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_JrsistFK, 0, m, &cSlice_JrsistFK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZOK3mXHd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2cO6vxRi_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_jzA4fdLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_v2v33kT5_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_v2v33kT5_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_hMPZlwxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aV9kRASt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZiiVsM3u_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aV9kRASt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZiiVsM3u_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_FIP5Y9RT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fb3Xma1M_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8e0SfpAN_sendMessage);
}

void Heavy_CircleStrings::cVar_gAHza7Qx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8qwCClf1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_8qwCClf1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UpPEisxk_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RraCo6PL, HV_BINOP_MULTIPLY, 0, m, &cBinop_RraCo6PL_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_lRMSBrst, HV_BINOP_DIVIDE, 1, m, &cBinop_lRMSBrst_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_vkHJZu37, 0, m, &cVar_vkHJZu37_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_UpPEisxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NOGplFoo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_F8T2ZkxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kUDRPTol, HV_BINOP_SUBTRACT, 1, m, &cBinop_kUDRPTol_sendMessage);
}

void Heavy_CircleStrings::cVar_Lu8vOR82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NPxXbOtX, 0, m, &cVar_NPxXbOtX_sendMessage);
}

void Heavy_CircleStrings::cVar_NPxXbOtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ikd2cihX, HV_BINOP_ADD, 0, m, &cBinop_Ikd2cihX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AUJ53NRl, HV_BINOP_ADD, 0, m, &cBinop_AUJ53NRl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GzbqHShH, 0, m, &cVar_GzbqHShH_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NSmbYmM6, m);
}

void Heavy_CircleStrings::cSlice_OJRoP9L4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fb3Xma1M_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8e0SfpAN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_JrsistFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_y664XzpL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_D5J7xTwl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_C8QGmG4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dzY1zz7N, 1, m, &cVar_dzY1zz7N_sendMessage);
}

void Heavy_CircleStrings::cBinop_GrzwiFJj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_C8QGmG4F_sendMessage);
}

void Heavy_CircleStrings::cBinop_RraCo6PL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1Ne0WTTV_sendMessage);
}

void Heavy_CircleStrings::cBinop_1Ne0WTTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kO5Fp9H5, HV_BINOP_SUBTRACT, 1, m, &cBinop_kO5Fp9H5_sendMessage);
}

void Heavy_CircleStrings::cBinop_kO5Fp9H5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dzY1zz7N, 1, m, &cVar_dzY1zz7N_sendMessage);
}

void Heavy_CircleStrings::cMsg_nc4O75Ez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_k0fu5SjA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_CPqytFkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_k0fu5SjA_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AUJ53NRl, HV_BINOP_ADD, 1, m, &cBinop_AUJ53NRl_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ikd2cihX, HV_BINOP_ADD, 1, m, &cBinop_Ikd2cihX_sendMessage);
}

void Heavy_CircleStrings::cBinop_cN87oeVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_FbXhQTII_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_Ikd2cihX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NPxXbOtX, 1, m, &cVar_NPxXbOtX_sendMessage);
}

void Heavy_CircleStrings::cBinop_lRMSBrst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KADqEhOV, HV_BINOP_DIVIDE, 1, m, &cBinop_KADqEhOV_sendMessage);
}

void Heavy_CircleStrings::cBinop_KADqEhOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AUJ53NRl, HV_BINOP_ADD, 1, m, &cBinop_AUJ53NRl_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ikd2cihX, HV_BINOP_ADD, 1, m, &cBinop_Ikd2cihX_sendMessage);
}

void Heavy_CircleStrings::cCast_8e0SfpAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lRMSBrst, HV_BINOP_DIVIDE, 0, m, &cBinop_lRMSBrst_sendMessage);
}

void Heavy_CircleStrings::cCast_Fb3Xma1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GrzwiFJj, HV_BINOP_MULTIPLY, 0, m, &cBinop_GrzwiFJj_sendMessage);
}

void Heavy_CircleStrings::cCast_y664XzpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Lu8vOR82, 1, m, &cVar_Lu8vOR82_sendMessage);
}

void Heavy_CircleStrings::cCast_D5J7xTwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kUDRPTol, HV_BINOP_SUBTRACT, 0, m, &cBinop_kUDRPTol_sendMessage);
}

void Heavy_CircleStrings::cCast_ThodOk3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CPqytFkg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_aNMXhGrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Lu8vOR82, 0, m, &cVar_Lu8vOR82_sendMessage);
}

void Heavy_CircleStrings::cBinop_AUJ53NRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F8T2ZkxU, 0, m, &cVar_F8T2ZkxU_sendMessage);
}

void Heavy_CircleStrings::cMsg_v2v33kT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_k0fu5SjA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_251vyl2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_FIP5Y9RT, 1, m, &cVar_FIP5Y9RT_sendMessage);
}

void Heavy_CircleStrings::cMsg_NOGplFoo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RraCo6PL, HV_BINOP_MULTIPLY, 0, m, &cBinop_RraCo6PL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lRMSBrst, HV_BINOP_DIVIDE, 1, m, &cBinop_lRMSBrst_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vkHJZu37, 0, m, &cVar_vkHJZu37_sendMessage);
}

void Heavy_CircleStrings::cCast_ZiiVsM3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aOG4Vqp4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AUJ53NRl, HV_BINOP_ADD, 0, m, &cBinop_AUJ53NRl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NPxXbOtX, 1, m, &cVar_NPxXbOtX_sendMessage);
}

void Heavy_CircleStrings::cCast_aV9kRASt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v2v33kT5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_kUDRPTol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KADqEhOV, HV_BINOP_DIVIDE, 0, m, &cBinop_KADqEhOV_sendMessage);
}

void Heavy_CircleStrings::cCast_aOG4Vqp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CPqytFkg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ZOK3mXHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nc4O75Ez_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_taAaRb5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FIP5Y9RT, 0, m, &cVar_FIP5Y9RT_sendMessage);
}

void Heavy_CircleStrings::cCast_2cO6vxRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_251vyl2q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_9FA0JaGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_iGMBoNMB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_5YSfjLBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xIYrVkH7, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_alxz5rVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_pKhn7TjQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_pKhn7TjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ZYnNyGW8, 0, m, &cPack_ZYnNyGW8_sendMessage);
}

void Heavy_CircleStrings::cBinop_oC8ovUE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_alxz5rVc_sendMessage);
}

void Heavy_CircleStrings::cCast_hGYy3EAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fkqHH3yT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_BeU9WGrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bzIxUs5k_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_2NSHVnN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Ejeqyn7r_sendMessage);
}

void Heavy_CircleStrings::cBinop_PvZ3Cv1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Xfir6P1P_sendMessage);
}

void Heavy_CircleStrings::cBinop_Xfir6P1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MTRpxoMS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Ir829FV5_sendMessage);
}

void Heavy_CircleStrings::cVar_V7kyJfco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_px8ZwNsm_sendMessage);
}

void Heavy_CircleStrings::cMsg_KHg20dOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8weCkdgS_sendMessage);
}

void Heavy_CircleStrings::cSystem_8weCkdgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVzV0KSD, HV_BINOP_DIVIDE, 1, m, &cBinop_yVzV0KSD_sendMessage);
}

void Heavy_CircleStrings::cBinop_MTRpxoMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ilJOi9pw_sendMessage);
}

void Heavy_CircleStrings::cBinop_ilJOi9pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fVxFHmwF, m);
}

void Heavy_CircleStrings::cMsg_qOIX1Vnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_WoSmJWPi_sendMessage);
}

void Heavy_CircleStrings::cBinop_WoSmJWPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_PvZ3Cv1G_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ir829FV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xrnIUr7u, m);
}

void Heavy_CircleStrings::cBinop_px8ZwNsm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_zRoJ654v_sendMessage);
}

void Heavy_CircleStrings::cBinop_zRoJ654v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVzV0KSD, HV_BINOP_DIVIDE, 0, m, &cBinop_yVzV0KSD_sendMessage);
}

void Heavy_CircleStrings::cBinop_yVzV0KSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qOIX1Vnw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_dNGPfOIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_YnlRTBiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_5ik61nNv_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_mO1OVLoR, 0, m, &cIf_mO1OVLoR_sendMessage);
      break;
    }
    case 1: {
      cMsg_joNbSxZP_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_0hbnQ6uH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YnlRTBiX, 1, m, &cIf_YnlRTBiX_sendMessage);
}

void Heavy_CircleStrings::cIf_mO1OVLoR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_S4REcjcq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_9RRE0qpK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_5ik61nNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mO1OVLoR, 1, m, &cIf_mO1OVLoR_sendMessage);
}

void Heavy_CircleStrings::cMsg_joNbSxZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_9RRE0qpK_sendMessage);
}

void Heavy_CircleStrings::cMsg_S4REcjcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_9RRE0qpK_sendMessage);
}

void Heavy_CircleStrings::cIf_hczIIiyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_ZLAADEYi_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_memw5FiQ, 0, m, &cIf_memw5FiQ_sendMessage);
      break;
    }
    case 1: {
      cMsg_aufHLuMx_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_dKlnITfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hczIIiyX, 1, m, &cIf_hczIIiyX_sendMessage);
}

void Heavy_CircleStrings::cIf_memw5FiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_r4mv3Z43_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_ITXvyMhM, 0, m, &cPack_ITXvyMhM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ZLAADEYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_memw5FiQ, 1, m, &cIf_memw5FiQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_aufHLuMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_ITXvyMhM, 0, m, &cPack_ITXvyMhM_sendMessage);
}

void Heavy_CircleStrings::cMsg_r4mv3Z43_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_ITXvyMhM, 0, m, &cPack_ITXvyMhM_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_YsaqIORJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ShM2A8Zx, 0, m, &cSlice_ShM2A8Zx_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_F0YzOkMj, 0, m, &cRandom_F0YzOkMj_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_9izfOija_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_s34IglDT_sendMessage);
}

void Heavy_CircleStrings::cUnop_s34IglDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tElxJ8BL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_F0YzOkMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_9izfOija_sendMessage);
}

void Heavy_CircleStrings::cSlice_ShM2A8Zx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_F0YzOkMj, 1, m, &cRandom_F0YzOkMj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_tElxJ8BL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_dQA9YIbP, m);
}

void Heavy_CircleStrings::cTabhead_wN9b2bSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y5TCWRWZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_Y5TCWRWZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_Lnax4NEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_t0mnKecU_sendMessage);
}

void Heavy_CircleStrings::cSystem_t0mnKecU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PIG49HeZ_sendMessage);
}

void Heavy_CircleStrings::cVar_rQPWw6sS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gERjSe19_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_oEQVMsH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oEQVMsH0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_im5SXYmo, 0, m, &cDelay_im5SXYmo_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oA8UdyFZ, 0, m, &sTabread_oA8UdyFZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_im5SXYmo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_im5SXYmo, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oA8UdyFZ, 0, m, &sTabread_oA8UdyFZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_im5SXYmo, 0, m, &cDelay_im5SXYmo_sendMessage);
}

void Heavy_CircleStrings::sTabread_oA8UdyFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_wi8gNNjZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_wi8gNNjZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_QhTed0dF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ng9Nw46Y, HV_BINOP_MAX, 0, m, &cBinop_Ng9Nw46Y_sendMessage);
}

void Heavy_CircleStrings::cBinop_PIG49HeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QhTed0dF, HV_BINOP_MULTIPLY, 0, m, &cBinop_QhTed0dF_sendMessage);
}

void Heavy_CircleStrings::cBinop_Y5TCWRWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n7rFNAqC_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oA8UdyFZ, 0, m, &sTabread_oA8UdyFZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mpUtKKcz_sendMessage);
}

void Heavy_CircleStrings::cSystem_elT4qkVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wi8gNNjZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_wi8gNNjZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_im5SXYmo, 2, m, &cDelay_im5SXYmo_sendMessage);
}

void Heavy_CircleStrings::cMsg_gERjSe19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_elT4qkVD_sendMessage);
}

void Heavy_CircleStrings::cMsg_n7rFNAqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_oEQVMsH0, 0, m, &cDelay_oEQVMsH0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_im5SXYmo, 0, m, &cDelay_im5SXYmo_sendMessage);
}

void Heavy_CircleStrings::cMsg_q7oKi97F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ng9Nw46Y, HV_BINOP_MAX, 1, m, &cBinop_Ng9Nw46Y_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ng9Nw46Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y5TCWRWZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_Y5TCWRWZ_sendMessage);
}

void Heavy_CircleStrings::cCast_mpUtKKcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oEQVMsH0, 0, m, &cDelay_oEQVMsH0_sendMessage);
}

void Heavy_CircleStrings::cBinop_nExlD02i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oEQVMsH0, 2, m, &cDelay_oEQVMsH0_sendMessage);
}

void Heavy_CircleStrings::cBinop_wi8gNNjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nExlD02i_sendMessage);
}

void Heavy_CircleStrings::cCast_jY1p1Mih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rQPWw6sS, 0, m, &cVar_rQPWw6sS_sendMessage);
  cMsg_Lnax4NEu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wN9b2bSN, 0, m, &cTabhead_wN9b2bSN_sendMessage);
}

void Heavy_CircleStrings::cBinop_qThZZYIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zJrXWyYj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jJZsMVDU_sendMessage);
}

void Heavy_CircleStrings::cBinop_zMOvFwTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_OrdPSkHz_sendMessage);
}

void Heavy_CircleStrings::cBinop_OrdPSkHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AJbu7uEN, HV_BINOP_POW, 1, m, &cBinop_AJbu7uEN_sendMessage);
  cMsg_kao0T6nz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_AJbu7uEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_qThZZYIT_sendMessage);
}

void Heavy_CircleStrings::cMsg_kao0T6nz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AJbu7uEN, HV_BINOP_POW, 0, m, &cBinop_AJbu7uEN_sendMessage);
}

void Heavy_CircleStrings::cVar_5dqAr9Bf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_zMOvFwTt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4HEYs6yV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yVyJmSNQ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_dUYDInqU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_gtMnN5be_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_gtMnN5be_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_f6p13CCa, 1, m, &cDelay_f6p13CCa_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_la82mU8G_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_f6p13CCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_f6p13CCa, m);
  cMsg_zBqg5tn8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_gtMnN5be_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_f6p13CCa, 0, m, &cDelay_f6p13CCa_sendMessage);
}

void Heavy_CircleStrings::cCast_la82mU8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_f6p13CCa, 0, m, &cDelay_f6p13CCa_sendMessage);
}

void Heavy_CircleStrings::cVar_5Dld9cBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jI6W2oad, HV_BINOP_MULTIPLY, 0, m, &cBinop_jI6W2oad_sendMessage);
}

void Heavy_CircleStrings::cMsg_wOXNh29l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_icjwH2ni_sendMessage);
}

void Heavy_CircleStrings::cSystem_icjwH2ni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HWjhdYwj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_jI6W2oad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_gqpEvxYR_sendMessage);
}

void Heavy_CircleStrings::cBinop_kT7jDaXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jI6W2oad, HV_BINOP_MULTIPLY, 1, m, &cBinop_jI6W2oad_sendMessage);
}

void Heavy_CircleStrings::cMsg_HWjhdYwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kT7jDaXZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_gqpEvxYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9zKYAUgt_sendMessage);
}

void Heavy_CircleStrings::cBinop_9zKYAUgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZTfBsf8X_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_yhVHCMdh, m);
}

void Heavy_CircleStrings::cBinop_ZTfBsf8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5nHH891Y, m);
}

void Heavy_CircleStrings::cMsg_zbB1PeXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_U7Ygy2YX_sendMessage);
}

void Heavy_CircleStrings::cSystem_U7Ygy2YX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4ScPV3Vw_sendMessage);
}

void Heavy_CircleStrings::cDelay_EGmnYijP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EGmnYijP, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ybu8a3HI, 0, m, &cDelay_Ybu8a3HI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGmnYijP, 0, m, &cDelay_EGmnYijP_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_LHhSYrvr, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Ybu8a3HI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ybu8a3HI, m);
  cMsg_cBALRn8A_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_XcL3k7O2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ZdNgd3wJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_G94G5XFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f4x2mDGe_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_zHYNTfQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8cxKG1Rn_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGmnYijP, 2, m, &cDelay_EGmnYijP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cWsTLrIq_sendMessage);
}

void Heavy_CircleStrings::cMsg_f4x2mDGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_zHYNTfQ2, 0, m, &hTable_zHYNTfQ2_sendMessage);
}

void Heavy_CircleStrings::cBinop_4ScPV3Vw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_G94G5XFD_sendMessage);
}

void Heavy_CircleStrings::cMsg_cBALRn8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_zHYNTfQ2, 0, m, &hTable_zHYNTfQ2_sendMessage);
}

void Heavy_CircleStrings::cCast_cWsTLrIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGmnYijP, 0, m, &cDelay_EGmnYijP_sendMessage);
}

void Heavy_CircleStrings::cMsg_8cxKG1Rn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ybu8a3HI, 2, m, &cDelay_Ybu8a3HI_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZdNgd3wJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_LHhSYrvr, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_oUdigR8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_C56762ew, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_zBqg5tn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_C56762ew, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_4HEYs6yV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dUYDInqU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_yVyJmSNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oUdigR8K_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_BiCWPQfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_zMOvFwTt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4HEYs6yV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yVyJmSNQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_5HlNL2DU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QhTed0dF, HV_BINOP_MULTIPLY, 1, m, &cBinop_QhTed0dF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jY1p1Mih_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f6p13CCa, 1, m, &cDelay_f6p13CCa_sendMessage);
}

void Heavy_CircleStrings::cMsg_33u1kr5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5HlNL2DU, HV_BINOP_DIVIDE, 0, m, &cBinop_5HlNL2DU_sendMessage);
}

void Heavy_CircleStrings::cCast_zJrXWyYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5HlNL2DU, HV_BINOP_DIVIDE, 1, m, &cBinop_5HlNL2DU_sendMessage);
}

void Heavy_CircleStrings::cCast_jJZsMVDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_33u1kr5L_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_nXv8FmXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_MXfp76av_sendMessage);
  cSwitchcase_lOLCIWDO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_MXfp76av_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nXv8FmXU, 1, m, &cVar_nXv8FmXU_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_lOLCIWDO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_63fVWVPz_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_63fVWVPz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0tzNHJNZ_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_z323DXuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z323DXuN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z323DXuN, 0, m, &cDelay_z323DXuN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gWNwPjkS, 0, m, &cVar_gWNwPjkS_sendMessage);
  cSwitchcase_SrKUhtP5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_0tzNHJNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_63fVWVPz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z323DXuN, 0, m, &cDelay_z323DXuN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gWNwPjkS, 0, m, &cVar_gWNwPjkS_sendMessage);
  cSwitchcase_SrKUhtP5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_lYXz99lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RnPzP5QE_sendMessage);
}

void Heavy_CircleStrings::cSystem_RnPzP5QE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_z45WnluR_sendMessage);
}

void Heavy_CircleStrings::cVar_co4Hzb1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YLsAPHkM, HV_BINOP_MULTIPLY, 0, m, &cBinop_YLsAPHkM_sendMessage);
}

void Heavy_CircleStrings::cMsg_63fVWVPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_z323DXuN, 0, m, &cDelay_z323DXuN_sendMessage);
}

void Heavy_CircleStrings::cBinop_VI3NzUVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z323DXuN, 2, m, &cDelay_z323DXuN_sendMessage);
}

void Heavy_CircleStrings::cBinop_z45WnluR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YLsAPHkM, HV_BINOP_MULTIPLY, 1, m, &cBinop_YLsAPHkM_sendMessage);
}

void Heavy_CircleStrings::cBinop_YLsAPHkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_VI3NzUVl_sendMessage);
}

void Heavy_CircleStrings::cVar_gWNwPjkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_zMOvFwTt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4HEYs6yV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yVyJmSNQ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_SrKUhtP5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GzoDx2Cn, 0, m, &cSlice_GzoDx2Cn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TT4749JH, 0, m, &cRandom_TT4749JH_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_ZDiq6vsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_axGDVcoJ_sendMessage);
}

void Heavy_CircleStrings::cUnop_axGDVcoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_6fdicPx6_sendMessage);
}

void Heavy_CircleStrings::cRandom_TT4749JH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_ZDiq6vsH_sendMessage);
}

void Heavy_CircleStrings::cSlice_GzoDx2Cn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TT4749JH, 1, m, &cRandom_TT4749JH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_LSWYAbwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_e8mlZLoM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, -1.0f, 0, m, &cBinop_ZSuci7CK_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_DYOf3D8O, 0, m, &cIf_DYOf3D8O_sendMessage);
      break;
    }
    case 1: {
      cMsg_8EJyBfG6_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_zhuzTywH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_e8mlZLoM, 1, m, &cIf_e8mlZLoM_sendMessage);
}

void Heavy_CircleStrings::cIf_DYOf3D8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_SzQPZDVA_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_t0SBigIz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ZSuci7CK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DYOf3D8O, 1, m, &cIf_DYOf3D8O_sendMessage);
}

void Heavy_CircleStrings::cMsg_8EJyBfG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_t0SBigIz_sendMessage);
}

void Heavy_CircleStrings::cMsg_SzQPZDVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_t0SBigIz_sendMessage);
}

void Heavy_CircleStrings::cIf_x0MHgz8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_eiptyidI_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_SKH8zsuU, 0, m, &cIf_SKH8zsuU_sendMessage);
      break;
    }
    case 1: {
      cMsg_xTabWc0o_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_QqFRsAeG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_x0MHgz8x, 1, m, &cIf_x0MHgz8x_sendMessage);
}

void Heavy_CircleStrings::cIf_SKH8zsuU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_HjFJ00WW_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_Jrjm5lke_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_eiptyidI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SKH8zsuU, 1, m, &cIf_SKH8zsuU_sendMessage);
}

void Heavy_CircleStrings::cMsg_xTabWc0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_Jrjm5lke_sendMessage);
}

void Heavy_CircleStrings::cMsg_HjFJ00WW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_Jrjm5lke_sendMessage);
}

void Heavy_CircleStrings::cPack_kOGpQlh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_pGUo3l3A, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_ITXvyMhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9eiuNI4J, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_vCk9epHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dNGPfOIa, 0, m, &cVar_dNGPfOIa_sendMessage);
}

void Heavy_CircleStrings::cBinop_9RRE0qpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_cyVvIf4G_sendMessage);
}

void Heavy_CircleStrings::cBinop_cyVvIf4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_dKlnITfV_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hczIIiyX, 0, m, &cIf_hczIIiyX_sendMessage);
}

void Heavy_CircleStrings::cBinop_6fdicPx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_co4Hzb1S, 0, m, &cVar_co4Hzb1S_sendMessage);
}

void Heavy_CircleStrings::cBinop_6uN9t5OD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_505TfUai, m);
}

void Heavy_CircleStrings::cBinop_t0SBigIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.95f, 0, m, &cBinop_6uN9t5OD_sendMessage);
}

void Heavy_CircleStrings::cBinop_dxhBg5xc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5Dld9cBI, 0, m, &cVar_5Dld9cBI_sendMessage);
}

void Heavy_CircleStrings::cBinop_Jrjm5lke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2200.0f, 0, m, &cBinop_dxhBg5xc_sendMessage);
}

void Heavy_CircleStrings::cCast_zQJOyXTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_21fpvXeX_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_pnY4uwoH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_2YwpGOLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BY5SkCK9_sendMessage(_c, 0, m);
  cSend_7U3e3WlT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_21fpvXeX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_twmScljw, 0, m, &cSlice_twmScljw_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6C0RwNuj, 0, m, &cRandom_6C0RwNuj_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_4WG15ILt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RlNIBDTB_sendMessage);
}

void Heavy_CircleStrings::cUnop_RlNIBDTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_oKnXvT43_sendMessage);
  cSend_a9M3jO0U_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_6C0RwNuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_4WG15ILt_sendMessage);
}

void Heavy_CircleStrings::cSlice_twmScljw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6C0RwNuj, 1, m, &cRandom_6C0RwNuj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_8mlziwtC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_S0B0IE4Y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_YSLdePib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_0qTo0EIV_sendMessage);
}

void Heavy_CircleStrings::cBinop_0qTo0EIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YSLdePib, 1, m, &cVar_YSLdePib_sendMessage);
}

void Heavy_CircleStrings::cCast_puTNyZRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_jAF19BZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_Bpn8Flne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cCast_5h94TE2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NJ9lvnkF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_pnY4uwoH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fXiPVR1q, 0, m, &cSlice_fXiPVR1q_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OkmvNt7p, 0, m, &cRandom_OkmvNt7p_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_qgLtbqTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_CHmVhjqw_sendMessage);
}

void Heavy_CircleStrings::cUnop_CHmVhjqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 20.0f, 0, m, &cBinop_bzLNWZpB_sendMessage);
}

void Heavy_CircleStrings::cRandom_OkmvNt7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_qgLtbqTD_sendMessage);
}

void Heavy_CircleStrings::cSlice_fXiPVR1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OkmvNt7p, 1, m, &cRandom_OkmvNt7p_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_Rt3vymnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xEhwtVAB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0BOfXAUb_sendMessage);
}

void Heavy_CircleStrings::cBinop_oKnXvT43_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8mlziwtC, 0, m, &cVar_8mlziwtC_sendMessage);
}

void Heavy_CircleStrings::cSend_S0B0IE4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DGV4kCga_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_BY5SkCK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jvkTwu3B_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_a9M3jO0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FVLn8lfV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_7U3e3WlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_p9t09Q5A_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_SuvcDTaa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_mh6epebz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_mh6epebz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_foVKG66j_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_AgWst8VD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_mh6epebz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_NJ9lvnkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_knOAPrx9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_bzLNWZpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2YwpGOLg, 0, m, &cVar_2YwpGOLg_sendMessage);
}

void Heavy_CircleStrings::cCast_xEhwtVAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9VwBMidY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_0BOfXAUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CZYCRJvX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_CZYCRJvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 64.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_2YwpGOLg, 0, m, &cVar_2YwpGOLg_sendMessage);
}

void Heavy_CircleStrings::cMsg_9VwBMidY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 127.0f);
  cSend_a9M3jO0U_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_oKnXvT43_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_r4MKvULf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6e3DNPyL, 0, m, &cSlice_6e3DNPyL_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SvQb4IFB, 0, m, &cRandom_SvQb4IFB_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_NizM1Pq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pKbpDMdO_sendMessage);
}

void Heavy_CircleStrings::cUnop_pKbpDMdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_pMF2RuRT_sendMessage);
}

void Heavy_CircleStrings::cRandom_SvQb4IFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_NizM1Pq7_sendMessage);
}

void Heavy_CircleStrings::cSlice_6e3DNPyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SvQb4IFB, 1, m, &cRandom_SvQb4IFB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_Hvd95kzz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FlcM4Zwx, 0, m, &cSlice_FlcM4Zwx_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wGCSafaY, 0, m, &cRandom_wGCSafaY_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Hl3m7Aol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_UDsv1GOV_sendMessage);
}

void Heavy_CircleStrings::cUnop_UDsv1GOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_kkpP1fA8_sendMessage);
}

void Heavy_CircleStrings::cRandom_wGCSafaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_Hl3m7Aol_sendMessage);
}

void Heavy_CircleStrings::cSlice_FlcM4Zwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wGCSafaY, 1, m, &cRandom_wGCSafaY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_OO5Yan8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_49TOHZLy, HV_BINOP_MULTIPLY, 0, m, &cBinop_49TOHZLy_sendMessage);
}

void Heavy_CircleStrings::cBinop_cgXjieeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_qhBK3REg_sendMessage);
}

void Heavy_CircleStrings::cBinop_qhBK3REg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pk7TX1Ss, HV_BINOP_POW, 1, m, &cBinop_Pk7TX1Ss_sendMessage);
  cMsg_hc2UyElP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Pk7TX1Ss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_OO5Yan8h_sendMessage);
}

void Heavy_CircleStrings::cMsg_hc2UyElP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pk7TX1Ss, HV_BINOP_POW, 0, m, &cBinop_Pk7TX1Ss_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_5nPcex5h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dtiTTweu, 0, m, &cSlice_dtiTTweu_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SgqH4mel, 0, m, &cRandom_SgqH4mel_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_8NlwZai4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OQ4nqxrX_sendMessage);
}

void Heavy_CircleStrings::cUnop_OQ4nqxrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ccGgnbHh_sendMessage);
}

void Heavy_CircleStrings::cRandom_SgqH4mel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_8NlwZai4_sendMessage);
}

void Heavy_CircleStrings::cSlice_dtiTTweu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SgqH4mel, 1, m, &cRandom_SgqH4mel_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_9kg6kSQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_r0pAWIsr, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_YM0y7ptV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_lSHosb4L_sendMessage);
}

void Heavy_CircleStrings::cVar_muI03Z9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_o2Vo770j, 0, m);
}

void Heavy_CircleStrings::cVar_JFvUyX7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mL0Rhf5Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_447BF6c9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ltS4N7ma_sendMessage);
}

void Heavy_CircleStrings::cVar_RElm2Xcl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_hs27Y2nn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_ZXgnFGYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_jEML1HEF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_oVqZe088_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_oVqZe088_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_0EDJ59Y2, 1, m, &cDelay_0EDJ59Y2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uFMk9Ewp_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_0EDJ59Y2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0EDJ59Y2, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jcWqCJRt, 0, m, &cVar_jcWqCJRt_sendMessage);
}

void Heavy_CircleStrings::cMsg_oVqZe088_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0EDJ59Y2, 0, m, &cDelay_0EDJ59Y2_sendMessage);
}

void Heavy_CircleStrings::cCast_uFMk9Ewp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0EDJ59Y2, 0, m, &cDelay_0EDJ59Y2_sendMessage);
}

void Heavy_CircleStrings::cVar_jcWqCJRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YpJT7tF5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_DLT4Q8BP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JFvUyX7r, 0, m, &cVar_JFvUyX7r_sendMessage);
}

void Heavy_CircleStrings::cMsg_VX47NP15_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_37l4gRJW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_OUq1jWav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_vF6DG9Si_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ChtXRskB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_66QB21go_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_ZPTVbEST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YkbKmOx0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_LIvlQVhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_1rqXUaZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZkZHESny_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_37l4gRJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_vF6DG9Si_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YkbKmOx0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_66QB21go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZkZHESny_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_oaSL1alF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_W66TbSEA, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_YpJT7tF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_W66TbSEA, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_447BF6c9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jcWqCJRt, 1, m, &cVar_jcWqCJRt_sendMessage);
}

void Heavy_CircleStrings::cCast_ltS4N7ma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jEML1HEF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_mL0Rhf5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oaSL1alF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_rIz6F3ob_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YWLw0x4A, 0, m, &cSlice_YWLw0x4A_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wUNYVvAH, 0, m, &cRandom_wUNYVvAH_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_syKm7TVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_t8AqPTom_sendMessage);
}

void Heavy_CircleStrings::cUnop_t8AqPTom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EgO5GIJf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_wUNYVvAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_syKm7TVT_sendMessage);
}

void Heavy_CircleStrings::cSlice_YWLw0x4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wUNYVvAH, 1, m, &cRandom_wUNYVvAH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_EgO5GIJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_fwiR6eR4, m);
}

void Heavy_CircleStrings::cTabhead_xOOmjLlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YxP3eUWY, HV_BINOP_SUBTRACT, 0, m, &cBinop_YxP3eUWY_sendMessage);
}

void Heavy_CircleStrings::cMsg_nzs1psmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZW2l1zk0_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZW2l1zk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iRBmvWHh_sendMessage);
}

void Heavy_CircleStrings::cVar_r3HVk9z5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DEYdmcx2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_MWcCdZ2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MWcCdZ2m, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wx4nVgsi, 0, m, &cDelay_wx4nVgsi_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JSK4IKt8, 0, m, &sTabread_JSK4IKt8_sendMessage);
}

void Heavy_CircleStrings::cDelay_wx4nVgsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wx4nVgsi, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JSK4IKt8, 0, m, &sTabread_JSK4IKt8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wx4nVgsi, 0, m, &cDelay_wx4nVgsi_sendMessage);
}

void Heavy_CircleStrings::sTabread_JSK4IKt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JjBU5GKe, HV_BINOP_SUBTRACT, 0, m, &cBinop_JjBU5GKe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_NaQvba0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FQKnYi5l, HV_BINOP_MAX, 0, m, &cBinop_FQKnYi5l_sendMessage);
}

void Heavy_CircleStrings::cBinop_iRBmvWHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NaQvba0p, HV_BINOP_MULTIPLY, 0, m, &cBinop_NaQvba0p_sendMessage);
}

void Heavy_CircleStrings::cBinop_YxP3eUWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hDCWyihZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JSK4IKt8, 0, m, &sTabread_JSK4IKt8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LkjjAHTe_sendMessage);
}

void Heavy_CircleStrings::cSystem_cVSOavZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JjBU5GKe, HV_BINOP_SUBTRACT, 1, m, &cBinop_JjBU5GKe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wx4nVgsi, 2, m, &cDelay_wx4nVgsi_sendMessage);
}

void Heavy_CircleStrings::cMsg_DEYdmcx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cVSOavZT_sendMessage);
}

void Heavy_CircleStrings::cMsg_hDCWyihZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_MWcCdZ2m, 0, m, &cDelay_MWcCdZ2m_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wx4nVgsi, 0, m, &cDelay_wx4nVgsi_sendMessage);
}

void Heavy_CircleStrings::cMsg_gIOMDfT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_FQKnYi5l, HV_BINOP_MAX, 1, m, &cBinop_FQKnYi5l_sendMessage);
}

void Heavy_CircleStrings::cBinop_FQKnYi5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YxP3eUWY, HV_BINOP_SUBTRACT, 1, m, &cBinop_YxP3eUWY_sendMessage);
}

void Heavy_CircleStrings::cCast_LkjjAHTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MWcCdZ2m, 0, m, &cDelay_MWcCdZ2m_sendMessage);
}

void Heavy_CircleStrings::cBinop_Yd52aBOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MWcCdZ2m, 2, m, &cDelay_MWcCdZ2m_sendMessage);
}

void Heavy_CircleStrings::cBinop_JjBU5GKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Yd52aBOx_sendMessage);
}

void Heavy_CircleStrings::cCast_yMKsPev8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r3HVk9z5, 0, m, &cVar_r3HVk9z5_sendMessage);
  cMsg_nzs1psmu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_xOOmjLlF, 0, m, &cTabhead_xOOmjLlF_sendMessage);
}

void Heavy_CircleStrings::cBinop_CLtVcqVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4jtW2BXb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L9DpnCf8_sendMessage);
}

void Heavy_CircleStrings::cBinop_41ANvuDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_EG7gqLqQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_EG7gqLqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bCArJOZ8, HV_BINOP_POW, 1, m, &cBinop_bCArJOZ8_sendMessage);
  cMsg_WO79uDig_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_bCArJOZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_CLtVcqVw_sendMessage);
}

void Heavy_CircleStrings::cMsg_WO79uDig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bCArJOZ8, HV_BINOP_POW, 0, m, &cBinop_bCArJOZ8_sendMessage);
}

void Heavy_CircleStrings::cVar_o0ULGc0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_41ANvuDO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S4oPIreL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qj5uiMkq_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_kDUy2FMo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_TqAvlCYr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_TqAvlCYr_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_FLhf84rJ, 1, m, &cDelay_FLhf84rJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zK2GQrqB_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_FLhf84rJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FLhf84rJ, m);
  cMsg_ql58BOE7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_TqAvlCYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FLhf84rJ, 0, m, &cDelay_FLhf84rJ_sendMessage);
}

void Heavy_CircleStrings::cCast_zK2GQrqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FLhf84rJ, 0, m, &cDelay_FLhf84rJ_sendMessage);
}

void Heavy_CircleStrings::cVar_tojINI2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dGCKZqhs, HV_BINOP_MULTIPLY, 0, m, &cBinop_dGCKZqhs_sendMessage);
}

void Heavy_CircleStrings::cMsg_rPHNFrWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xwt792Hs_sendMessage);
}

void Heavy_CircleStrings::cSystem_xwt792Hs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i7K11IxD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_dGCKZqhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_PQZ3br8w_sendMessage);
}

void Heavy_CircleStrings::cBinop_Lb9jgDy4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dGCKZqhs, HV_BINOP_MULTIPLY, 1, m, &cBinop_dGCKZqhs_sendMessage);
}

void Heavy_CircleStrings::cMsg_i7K11IxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Lb9jgDy4_sendMessage);
}

void Heavy_CircleStrings::cBinop_PQZ3br8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_C6faC2sM_sendMessage);
}

void Heavy_CircleStrings::cBinop_C6faC2sM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_65ikSZnt_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hehXzPac, m);
}

void Heavy_CircleStrings::cBinop_65ikSZnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_V9QkXh2V, m);
}

void Heavy_CircleStrings::cMsg_xUK9nve0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FFOvqxxs_sendMessage);
}

void Heavy_CircleStrings::cSystem_FFOvqxxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ik6zHE13_sendMessage);
}

void Heavy_CircleStrings::cDelay_4dPf2TbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4dPf2TbC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tsVmrAIz, 0, m, &cDelay_tsVmrAIz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4dPf2TbC, 0, m, &cDelay_4dPf2TbC_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_maoto4bW, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_tsVmrAIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tsVmrAIz, m);
  cMsg_UNn7fd8c_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_fk7wUhVh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LGpgvQ0C_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_DQSc1Gnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eb0j29zH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_PGxZkRq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vxnsrNBl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4dPf2TbC, 2, m, &cDelay_4dPf2TbC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cJbELoVI_sendMessage);
}

void Heavy_CircleStrings::cMsg_eb0j29zH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_PGxZkRq1, 0, m, &hTable_PGxZkRq1_sendMessage);
}

void Heavy_CircleStrings::cBinop_ik6zHE13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_DQSc1Gnj_sendMessage);
}

void Heavy_CircleStrings::cMsg_UNn7fd8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_PGxZkRq1, 0, m, &hTable_PGxZkRq1_sendMessage);
}

void Heavy_CircleStrings::cCast_cJbELoVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4dPf2TbC, 0, m, &cDelay_4dPf2TbC_sendMessage);
}

void Heavy_CircleStrings::cMsg_vxnsrNBl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_tsVmrAIz, 2, m, &cDelay_tsVmrAIz_sendMessage);
}

void Heavy_CircleStrings::cMsg_LGpgvQ0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_maoto4bW, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_fzV8msfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VicTFzL3, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_ql58BOE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VicTFzL3, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_qj5uiMkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fzV8msfJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_S4oPIreL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kDUy2FMo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_BRaRMBj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_41ANvuDO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S4oPIreL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qj5uiMkq_sendMessage);
}

void Heavy_CircleStrings::cBinop_yBt0mBOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NaQvba0p, HV_BINOP_MULTIPLY, 1, m, &cBinop_NaQvba0p_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yMKsPev8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FLhf84rJ, 1, m, &cDelay_FLhf84rJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_uPyIqxd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBt0mBOO, HV_BINOP_DIVIDE, 0, m, &cBinop_yBt0mBOO_sendMessage);
}

void Heavy_CircleStrings::cCast_L9DpnCf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uPyIqxd7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_4jtW2BXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBt0mBOO, HV_BINOP_DIVIDE, 1, m, &cBinop_yBt0mBOO_sendMessage);
}

void Heavy_CircleStrings::cUnop_k5DXyPAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KlHj5l7j, 0, m, &cPack_KlHj5l7j_sendMessage);
}

void Heavy_CircleStrings::cUnop_MDrKfxBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9RR4uVQK, 0, m, &cPack_9RR4uVQK_sendMessage);
}

void Heavy_CircleStrings::cPack_9RR4uVQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_bUJ0KEq2, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_KlHj5l7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hGytK1rW, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_K1fTWDBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_k5DXyPAk_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_MDrKfxBR_sendMessage);
}

void Heavy_CircleStrings::cMsg_jW01iCg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_K1fTWDBk_sendMessage);
}

void Heavy_CircleStrings::cSlice_VEyJlx6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_55T7qhY1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_YI3lADQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6ad5OD1N_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_cgXjieeM_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_41ANvuDO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S4oPIreL_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qj5uiMkq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_kkpP1fA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_7RBzRTd3_sendMessage);
}

void Heavy_CircleStrings::cBinop_7RBzRTd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_K1fTWDBk_sendMessage);
}

void Heavy_CircleStrings::cBinop_55T7qhY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SuKhnwid_sendMessage(_c, 0, m);
  cSend_yiFVdD95_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_49TOHZLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JRrZXxtf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tgQL9RFW_sendMessage);
}

void Heavy_CircleStrings::cBinop_ccGgnbHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_DR4J35BG_sendMessage);
}

void Heavy_CircleStrings::cBinop_DR4J35BG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_49TOHZLy, HV_BINOP_MULTIPLY, 1, m, &cBinop_49TOHZLy_sendMessage);
}

void Heavy_CircleStrings::cSend_SuKhnwid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_m0tGDAVD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_tgQL9RFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DLT4Q8BP_sendMessage);
}

void Heavy_CircleStrings::cCast_JRrZXxtf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Hvd95kzz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_lSHosb4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9kg6kSQx, 0, m, &cPack_9kg6kSQx_sendMessage);
}

void Heavy_CircleStrings::cSend_yiFVdD95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Icnr8TPq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_6rXJdIhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2uZB8NFN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_bIaEdykg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_6rXJdIhS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_6LVRNwDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_DYSmLFfa, m);
}

void Heavy_CircleStrings::cCast_6ad5OD1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5nPcex5h_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_QmIkjyOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tcPHsKBX_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8ApldTp7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IiLIt9K6_sendMessage);
}

void Heavy_CircleStrings::cIf_f6HUVMf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_sjYlewTn_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ZSRQMbuu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_OcQsRRyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OalZWtuM, HV_BINOP_POW, 0, m, &cBinop_OalZWtuM_sendMessage);
}

void Heavy_CircleStrings::cBinop_OalZWtuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SleIBuem, 0, m, &cPack_SleIBuem_sendMessage);
}

void Heavy_CircleStrings::cBinop_CW7ouuWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_VPEkKbjs_sendMessage);
}

void Heavy_CircleStrings::cCast_IiLIt9K6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f6HUVMf6, 0, m, &cIf_f6HUVMf6_sendMessage);
}

void Heavy_CircleStrings::cCast_8ApldTp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_mYnYz6Px_sendMessage);
}

void Heavy_CircleStrings::cBinop_mYnYz6Px_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f6HUVMf6, 1, m, &cIf_f6HUVMf6_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZSRQMbuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_CW7ouuWT_sendMessage);
}

void Heavy_CircleStrings::cMsg_sjYlewTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_SleIBuem, 0, m, &cPack_SleIBuem_sendMessage);
}

void Heavy_CircleStrings::cBinop_VPEkKbjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OalZWtuM, HV_BINOP_POW, 1, m, &cBinop_OalZWtuM_sendMessage);
  cMsg_OcQsRRyY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_SleIBuem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_kHpzps7D, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_dVG2yshl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yRiTazpn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_tcPHsKBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_Nc9cnbIW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Nc9cnbIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mExnN4mg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_yRiTazpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7UCtbV99_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_Aubq0qw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O1hvVqCx_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1xpycOXa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HqEepMzQ_sendMessage);
}

void Heavy_CircleStrings::cIf_4mQW1KGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VhsKftEv_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_b4nlI2Ww_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_2bBA22sa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rG1mdjaM, HV_BINOP_POW, 0, m, &cBinop_rG1mdjaM_sendMessage);
}

void Heavy_CircleStrings::cBinop_rG1mdjaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ShCLTuhP, 0, m, &cPack_ShCLTuhP_sendMessage);
}

void Heavy_CircleStrings::cBinop_BG1CnoGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_loYbM5zL_sendMessage);
}

void Heavy_CircleStrings::cCast_HqEepMzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4mQW1KGy, 0, m, &cIf_4mQW1KGy_sendMessage);
}

void Heavy_CircleStrings::cCast_1xpycOXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_jDc5v7vz_sendMessage);
}

void Heavy_CircleStrings::cBinop_jDc5v7vz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4mQW1KGy, 1, m, &cIf_4mQW1KGy_sendMessage);
}

void Heavy_CircleStrings::cBinop_b4nlI2Ww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_BG1CnoGX_sendMessage);
}

void Heavy_CircleStrings::cMsg_VhsKftEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_ShCLTuhP, 0, m, &cPack_ShCLTuhP_sendMessage);
}

void Heavy_CircleStrings::cBinop_loYbM5zL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rG1mdjaM, HV_BINOP_POW, 1, m, &cBinop_rG1mdjaM_sendMessage);
  cMsg_2bBA22sa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_ShCLTuhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_4dQbVpWx, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_uoF0ohFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GLJxazpo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_O1hvVqCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_5DVkuD7L_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_5DVkuD7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4JdvG5kg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_GLJxazpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fYquvUnA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_ssAgnZsL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TU8neTQl, 0, m, &cSlice_TU8neTQl_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SqilYJP1, 0, m, &cRandom_SqilYJP1_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_2bX3JJa8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_eeCtu0Uv_sendMessage);
}

void Heavy_CircleStrings::cUnop_eeCtu0Uv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_JSgaPHqS_sendMessage);
}

void Heavy_CircleStrings::cRandom_SqilYJP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_2bX3JJa8_sendMessage);
}

void Heavy_CircleStrings::cSlice_TU8neTQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SqilYJP1, 1, m, &cRandom_SqilYJP1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_VgzYnubg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZchGwplf, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZchGwplf_sendMessage);
}

void Heavy_CircleStrings::cBinop_tWXmXOhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_SHPa2RgG_sendMessage);
}

void Heavy_CircleStrings::cBinop_SHPa2RgG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xYg5PlzA, HV_BINOP_POW, 1, m, &cBinop_xYg5PlzA_sendMessage);
  cMsg_80BdzMDF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_xYg5PlzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_VgzYnubg_sendMessage);
}

void Heavy_CircleStrings::cMsg_80BdzMDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xYg5PlzA, HV_BINOP_POW, 0, m, &cBinop_xYg5PlzA_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_0UbIzx43_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zlB4tLX0, 0, m, &cSlice_zlB4tLX0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9pAEcSOG, 0, m, &cRandom_9pAEcSOG_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_0guQngwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_D4BTCELR_sendMessage);
}

void Heavy_CircleStrings::cUnop_D4BTCELR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_E54GwWt8_sendMessage);
}

void Heavy_CircleStrings::cRandom_9pAEcSOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_0guQngwQ_sendMessage);
}

void Heavy_CircleStrings::cSlice_zlB4tLX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9pAEcSOG, 1, m, &cRandom_9pAEcSOG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_vwaBKhCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_3Albz6Ft, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_WYupnRwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_O5cm7Jax_sendMessage);
}

void Heavy_CircleStrings::cVar_iEIT6Yhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_W6DHDMHs, 0, m);
}

void Heavy_CircleStrings::cVar_70Q7bjez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lnU1gs1G_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2XTv0x22_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_peKcfyjF_sendMessage);
}

void Heavy_CircleStrings::cVar_YW3vIOb2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_EMb709YL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_HaouavX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_Ihvdnoyo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_mxvIobk0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_mxvIobk0_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_8EKBzdOf, 1, m, &cDelay_8EKBzdOf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xAsJDeiV_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_8EKBzdOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8EKBzdOf, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cGLRwaWD, 0, m, &cVar_cGLRwaWD_sendMessage);
}

void Heavy_CircleStrings::cMsg_mxvIobk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8EKBzdOf, 0, m, &cDelay_8EKBzdOf_sendMessage);
}

void Heavy_CircleStrings::cCast_xAsJDeiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8EKBzdOf, 0, m, &cDelay_8EKBzdOf_sendMessage);
}

void Heavy_CircleStrings::cVar_cGLRwaWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uAtNOBWg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_PWArT79B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_70Q7bjez, 0, m, &cVar_70Q7bjez_sendMessage);
}

void Heavy_CircleStrings::cMsg_aHURajxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_kk1NdOxV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_NQepEDFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_hHFh25GD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_NLUhcsfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_5xRPXSmX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_T5JosO37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PkmucRAG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_UqLy6P3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_7RG4mTZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Mx9UBL4w_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_kk1NdOxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_hHFh25GD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PkmucRAG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_5xRPXSmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Mx9UBL4w_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_7qQtBY1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_DZNhnwOk, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_uAtNOBWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_DZNhnwOk, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_peKcfyjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ihvdnoyo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_2XTv0x22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cGLRwaWD, 1, m, &cVar_cGLRwaWD_sendMessage);
}

void Heavy_CircleStrings::cCast_lnU1gs1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7qQtBY1q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Snld6P3L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KIQ5yFts, 0, m, &cSlice_KIQ5yFts_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kVQpYTRP, 0, m, &cRandom_kVQpYTRP_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_c90R4lHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KQh482ta_sendMessage);
}

void Heavy_CircleStrings::cUnop_KQh482ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vOGVD4EZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_kVQpYTRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_c90R4lHk_sendMessage);
}

void Heavy_CircleStrings::cSlice_KIQ5yFts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kVQpYTRP, 1, m, &cRandom_kVQpYTRP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_vOGVD4EZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_jzjJCKDI, m);
}

void Heavy_CircleStrings::cTabhead_w3Fp2vx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UW6dJFlC, HV_BINOP_SUBTRACT, 0, m, &cBinop_UW6dJFlC_sendMessage);
}

void Heavy_CircleStrings::cMsg_1A55a6fy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CBPmVPUu_sendMessage);
}

void Heavy_CircleStrings::cSystem_CBPmVPUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uxgxSfqF_sendMessage);
}

void Heavy_CircleStrings::cVar_8YEXrUri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y0b5YBqV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_FC1VxYTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FC1VxYTn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HnT9vJmK, 0, m, &cDelay_HnT9vJmK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_IpnSBpqv, 0, m, &sTabread_IpnSBpqv_sendMessage);
}

void Heavy_CircleStrings::cDelay_HnT9vJmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HnT9vJmK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_IpnSBpqv, 0, m, &sTabread_IpnSBpqv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HnT9vJmK, 0, m, &cDelay_HnT9vJmK_sendMessage);
}

void Heavy_CircleStrings::sTabread_IpnSBpqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_dsMI974g, HV_BINOP_SUBTRACT, 0, m, &cBinop_dsMI974g_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_bV8SxJxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U0Kt3gC4, HV_BINOP_MAX, 0, m, &cBinop_U0Kt3gC4_sendMessage);
}

void Heavy_CircleStrings::cBinop_uxgxSfqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bV8SxJxq, HV_BINOP_MULTIPLY, 0, m, &cBinop_bV8SxJxq_sendMessage);
}

void Heavy_CircleStrings::cBinop_UW6dJFlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MMBOgZCg_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_IpnSBpqv, 0, m, &sTabread_IpnSBpqv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gDMzB4Lu_sendMessage);
}

void Heavy_CircleStrings::cSystem_ODDaebsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dsMI974g, HV_BINOP_SUBTRACT, 1, m, &cBinop_dsMI974g_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HnT9vJmK, 2, m, &cDelay_HnT9vJmK_sendMessage);
}

void Heavy_CircleStrings::cMsg_y0b5YBqV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ODDaebsM_sendMessage);
}

void Heavy_CircleStrings::cMsg_MMBOgZCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FC1VxYTn, 0, m, &cDelay_FC1VxYTn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HnT9vJmK, 0, m, &cDelay_HnT9vJmK_sendMessage);
}

void Heavy_CircleStrings::cMsg_OfMcqRk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_U0Kt3gC4, HV_BINOP_MAX, 1, m, &cBinop_U0Kt3gC4_sendMessage);
}

void Heavy_CircleStrings::cBinop_U0Kt3gC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UW6dJFlC, HV_BINOP_SUBTRACT, 1, m, &cBinop_UW6dJFlC_sendMessage);
}

void Heavy_CircleStrings::cCast_gDMzB4Lu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FC1VxYTn, 0, m, &cDelay_FC1VxYTn_sendMessage);
}

void Heavy_CircleStrings::cBinop_a4go0ica_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FC1VxYTn, 2, m, &cDelay_FC1VxYTn_sendMessage);
}

void Heavy_CircleStrings::cBinop_dsMI974g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_a4go0ica_sendMessage);
}

void Heavy_CircleStrings::cCast_Gw3IXRrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8YEXrUri, 0, m, &cVar_8YEXrUri_sendMessage);
  cMsg_1A55a6fy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_w3Fp2vx1, 0, m, &cTabhead_w3Fp2vx1_sendMessage);
}

void Heavy_CircleStrings::cBinop_Cnxs5c0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LXryIUP5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H8j2mEDA_sendMessage);
}

void Heavy_CircleStrings::cBinop_ijmL7B0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_0QG6y83w_sendMessage);
}

void Heavy_CircleStrings::cBinop_0QG6y83w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JoW0NqFL, HV_BINOP_POW, 1, m, &cBinop_JoW0NqFL_sendMessage);
  cMsg_cOB4AAeQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_JoW0NqFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Cnxs5c0a_sendMessage);
}

void Heavy_CircleStrings::cMsg_cOB4AAeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JoW0NqFL, HV_BINOP_POW, 0, m, &cBinop_JoW0NqFL_sendMessage);
}

void Heavy_CircleStrings::cVar_eubTpqP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ijmL7B0F_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5l3bSs41_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kTST3XzD_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_YHzcyhVp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_U26rFJdj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_U26rFJdj_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_9dInqXHc, 1, m, &cDelay_9dInqXHc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pd8zzKXe_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_9dInqXHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9dInqXHc, m);
  cMsg_qcK3rWYi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_U26rFJdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9dInqXHc, 0, m, &cDelay_9dInqXHc_sendMessage);
}

void Heavy_CircleStrings::cCast_pd8zzKXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9dInqXHc, 0, m, &cDelay_9dInqXHc_sendMessage);
}

void Heavy_CircleStrings::cVar_sZZWwuQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3lt6XccC, HV_BINOP_MULTIPLY, 0, m, &cBinop_3lt6XccC_sendMessage);
}

void Heavy_CircleStrings::cMsg_wiJ90f2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mTzwxKbb_sendMessage);
}

void Heavy_CircleStrings::cSystem_mTzwxKbb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nFtoU8oB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_3lt6XccC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_87u1Ql3I_sendMessage);
}

void Heavy_CircleStrings::cBinop_KTtvFljg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3lt6XccC, HV_BINOP_MULTIPLY, 1, m, &cBinop_3lt6XccC_sendMessage);
}

void Heavy_CircleStrings::cMsg_nFtoU8oB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KTtvFljg_sendMessage);
}

void Heavy_CircleStrings::cBinop_87u1Ql3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LmksmjbN_sendMessage);
}

void Heavy_CircleStrings::cBinop_LmksmjbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fxMPSDWl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_F5zuLuDQ, m);
}

void Heavy_CircleStrings::cBinop_fxMPSDWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0KvrXAaS, m);
}

void Heavy_CircleStrings::cMsg_Uc7vqGEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Db4qJCZC_sendMessage);
}

void Heavy_CircleStrings::cSystem_Db4qJCZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_W1jCU5BB_sendMessage);
}

void Heavy_CircleStrings::cDelay_gUOVcPRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gUOVcPRz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ACpE0rsX, 0, m, &cDelay_ACpE0rsX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gUOVcPRz, 0, m, &cDelay_gUOVcPRz_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_thDVVsNa, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_ACpE0rsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ACpE0rsX, m);
  cMsg_VFawohls_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_XUNrIIL1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_kt5mQaS5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_fn7afZfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3X87KXDY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_HcXuXSOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vG6nb43T_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gUOVcPRz, 2, m, &cDelay_gUOVcPRz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Jp8xcBZN_sendMessage);
}

void Heavy_CircleStrings::cMsg_3X87KXDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_HcXuXSOk, 0, m, &hTable_HcXuXSOk_sendMessage);
}

void Heavy_CircleStrings::cBinop_W1jCU5BB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_fn7afZfp_sendMessage);
}

void Heavy_CircleStrings::cMsg_VFawohls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_HcXuXSOk, 0, m, &hTable_HcXuXSOk_sendMessage);
}

void Heavy_CircleStrings::cCast_Jp8xcBZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gUOVcPRz, 0, m, &cDelay_gUOVcPRz_sendMessage);
}

void Heavy_CircleStrings::cMsg_vG6nb43T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ACpE0rsX, 2, m, &cDelay_ACpE0rsX_sendMessage);
}

void Heavy_CircleStrings::cMsg_kt5mQaS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_thDVVsNa, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_VVEKxyZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_AbMquuSV, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_qcK3rWYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_AbMquuSV, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_kTST3XzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VVEKxyZO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_5l3bSs41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_YHzcyhVp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_VTvhkges_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ijmL7B0F_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5l3bSs41_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kTST3XzD_sendMessage);
}

void Heavy_CircleStrings::cBinop_IcCYrDUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bV8SxJxq, HV_BINOP_MULTIPLY, 1, m, &cBinop_bV8SxJxq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Gw3IXRrz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9dInqXHc, 1, m, &cDelay_9dInqXHc_sendMessage);
}

void Heavy_CircleStrings::cMsg_WvxiCjTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IcCYrDUD, HV_BINOP_DIVIDE, 0, m, &cBinop_IcCYrDUD_sendMessage);
}

void Heavy_CircleStrings::cCast_LXryIUP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IcCYrDUD, HV_BINOP_DIVIDE, 1, m, &cBinop_IcCYrDUD_sendMessage);
}

void Heavy_CircleStrings::cCast_H8j2mEDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WvxiCjTG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_F1TIMScr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_llHOjMsL, 0, m, &cPack_llHOjMsL_sendMessage);
}

void Heavy_CircleStrings::cUnop_nnWAdcyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lv8AqE0l, 0, m, &cPack_lv8AqE0l_sendMessage);
}

void Heavy_CircleStrings::cPack_lv8AqE0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_n6BDuCJz, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_llHOjMsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MSkv0IgG, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_5hwT4TPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_F1TIMScr_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_nnWAdcyq_sendMessage);
}

void Heavy_CircleStrings::cMsg_f8P1V08R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_5hwT4TPQ_sendMessage);
}

void Heavy_CircleStrings::cSlice_pERPQs4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_RnOY25SQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_wKr3KvmA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_35v3vVDt_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tWXmXOhY_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ijmL7B0F_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5l3bSs41_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kTST3XzD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_JSgaPHqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_r2hWd2Mh_sendMessage);
}

void Heavy_CircleStrings::cBinop_r2hWd2Mh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_5hwT4TPQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_RnOY25SQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rpGKztkK_sendMessage(_c, 0, m);
  cSend_OiuKg2ZP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_ZchGwplf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XkWfbPCN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3mymheNE_sendMessage);
}

void Heavy_CircleStrings::cBinop_E54GwWt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_EKAiQfYo_sendMessage);
}

void Heavy_CircleStrings::cBinop_EKAiQfYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZchGwplf, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZchGwplf_sendMessage);
}

void Heavy_CircleStrings::cSend_rpGKztkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_c8QMPVwb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_XkWfbPCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ssAgnZsL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_3mymheNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PWArT79B_sendMessage);
}

void Heavy_CircleStrings::cBinop_O5cm7Jax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vwaBKhCT, 0, m, &cPack_vwaBKhCT_sendMessage);
}

void Heavy_CircleStrings::cSend_OiuKg2ZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_d0uKRNHZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_P6RYv8ZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xbpqAgs5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_12GSOaKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_P6RYv8ZE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Oth9GRXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QODljzuj, m);
}

void Heavy_CircleStrings::cCast_35v3vVDt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0UbIzx43_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_MuJJWaxm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_eODZgkRd, 0, m, &cSlice_eODZgkRd_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VAYwYXkM, 0, m, &cRandom_VAYwYXkM_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_kRq5PQ4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_18BSekFS_sendMessage);
}

void Heavy_CircleStrings::cUnop_18BSekFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_c38Zelwf_sendMessage);
}

void Heavy_CircleStrings::cRandom_VAYwYXkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_kRq5PQ4j_sendMessage);
}

void Heavy_CircleStrings::cSlice_eODZgkRd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VAYwYXkM, 1, m, &cRandom_VAYwYXkM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_c5ypAU4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6eMKx1bH, HV_BINOP_MULTIPLY, 0, m, &cBinop_6eMKx1bH_sendMessage);
}

void Heavy_CircleStrings::cBinop_H29g7ngX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_U1ZwNeG3_sendMessage);
}

void Heavy_CircleStrings::cBinop_U1ZwNeG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GsA9Ail7, HV_BINOP_POW, 1, m, &cBinop_GsA9Ail7_sendMessage);
  cMsg_opnazqlW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_GsA9Ail7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_c5ypAU4I_sendMessage);
}

void Heavy_CircleStrings::cMsg_opnazqlW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GsA9Ail7, HV_BINOP_POW, 0, m, &cBinop_GsA9Ail7_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_49YrkNGb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jkv4v8Vj, 0, m, &cSlice_jkv4v8Vj_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ybkr62Pm, 0, m, &cRandom_ybkr62Pm_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Riz68kFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NE22NLSr_sendMessage);
}

void Heavy_CircleStrings::cUnop_NE22NLSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Iu6ESS4O_sendMessage);
}

void Heavy_CircleStrings::cRandom_ybkr62Pm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_Riz68kFE_sendMessage);
}

void Heavy_CircleStrings::cSlice_jkv4v8Vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ybkr62Pm, 1, m, &cRandom_ybkr62Pm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_7UPbZEyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2vOArhQj, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_GCqO9Xw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_GpJ4llGp_sendMessage);
}

void Heavy_CircleStrings::cVar_sx7bE0As_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_MdzInlKa, 0, m);
}

void Heavy_CircleStrings::cVar_qR1kBAnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rm6vFRS8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aEQdLEKt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s0grR4Su_sendMessage);
}

void Heavy_CircleStrings::cVar_4CU5KJ0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_xARu31Lc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_7bKsQ6FI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_DjEJVuUx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Wpl4ihLu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Wpl4ihLu_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_omWwlX5a, 1, m, &cDelay_omWwlX5a_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vpNX7txj_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_omWwlX5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_omWwlX5a, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6gfSoMrd, 0, m, &cVar_6gfSoMrd_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wpl4ihLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_omWwlX5a, 0, m, &cDelay_omWwlX5a_sendMessage);
}

void Heavy_CircleStrings::cCast_vpNX7txj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_omWwlX5a, 0, m, &cDelay_omWwlX5a_sendMessage);
}

void Heavy_CircleStrings::cVar_6gfSoMrd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aglGUW3M_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_hNQ6zPaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qR1kBAnt, 0, m, &cVar_qR1kBAnt_sendMessage);
}

void Heavy_CircleStrings::cMsg_y59cmSRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_C4fnvGq8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_vD7VMFbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_qRPmM02Q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_UlFvlo4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_T82PJDMB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_lTH8KwXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6zHqNegb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_6M5uPJ4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_MMyM2v2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_W7LqAjxU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_C4fnvGq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_qRPmM02Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6zHqNegb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_T82PJDMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_W7LqAjxU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_6NyfgN5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Nsluba0W, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_aglGUW3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_Nsluba0W, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_Rm6vFRS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6NyfgN5C_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_aEQdLEKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6gfSoMrd, 1, m, &cVar_6gfSoMrd_sendMessage);
}

void Heavy_CircleStrings::cCast_s0grR4Su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DjEJVuUx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_g2QF0UN9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nRjopsNn, 0, m, &cSlice_nRjopsNn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lLEBndJt, 0, m, &cRandom_lLEBndJt_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_CWhF8Tpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_SbemCiGR_sendMessage);
}

void Heavy_CircleStrings::cUnop_SbemCiGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3FqyRheX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_lLEBndJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_CWhF8Tpz_sendMessage);
}

void Heavy_CircleStrings::cSlice_nRjopsNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lLEBndJt, 1, m, &cRandom_lLEBndJt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_3FqyRheX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_8oAxT5QU, m);
}

void Heavy_CircleStrings::cTabhead_8NzvLAKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5wh7njll, HV_BINOP_SUBTRACT, 0, m, &cBinop_5wh7njll_sendMessage);
}

void Heavy_CircleStrings::cMsg_89I7csyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_o2C3WxsT_sendMessage);
}

void Heavy_CircleStrings::cSystem_o2C3WxsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gBAfAsfp_sendMessage);
}

void Heavy_CircleStrings::cVar_bIMKyMWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_79vBEoS0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_8VK2Dnja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8VK2Dnja, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_htHfWy4u, 0, m, &cDelay_htHfWy4u_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uGZ4KzVj, 0, m, &sTabread_uGZ4KzVj_sendMessage);
}

void Heavy_CircleStrings::cDelay_htHfWy4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_htHfWy4u, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uGZ4KzVj, 0, m, &sTabread_uGZ4KzVj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_htHfWy4u, 0, m, &cDelay_htHfWy4u_sendMessage);
}

void Heavy_CircleStrings::sTabread_uGZ4KzVj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_uAA32wHb, HV_BINOP_SUBTRACT, 0, m, &cBinop_uAA32wHb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_45XC7vmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yg2OE2D3, HV_BINOP_MAX, 0, m, &cBinop_yg2OE2D3_sendMessage);
}

void Heavy_CircleStrings::cBinop_gBAfAsfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_45XC7vmT, HV_BINOP_MULTIPLY, 0, m, &cBinop_45XC7vmT_sendMessage);
}

void Heavy_CircleStrings::cBinop_5wh7njll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6Vs41Eao_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uGZ4KzVj, 0, m, &sTabread_uGZ4KzVj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CT3N8uqY_sendMessage);
}

void Heavy_CircleStrings::cSystem_65BbOzfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uAA32wHb, HV_BINOP_SUBTRACT, 1, m, &cBinop_uAA32wHb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_htHfWy4u, 2, m, &cDelay_htHfWy4u_sendMessage);
}

void Heavy_CircleStrings::cMsg_79vBEoS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_65BbOzfi_sendMessage);
}

void Heavy_CircleStrings::cMsg_6Vs41Eao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8VK2Dnja, 0, m, &cDelay_8VK2Dnja_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_htHfWy4u, 0, m, &cDelay_htHfWy4u_sendMessage);
}

void Heavy_CircleStrings::cMsg_jFR1gXlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_yg2OE2D3, HV_BINOP_MAX, 1, m, &cBinop_yg2OE2D3_sendMessage);
}

void Heavy_CircleStrings::cBinop_yg2OE2D3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5wh7njll, HV_BINOP_SUBTRACT, 1, m, &cBinop_5wh7njll_sendMessage);
}

void Heavy_CircleStrings::cCast_CT3N8uqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8VK2Dnja, 0, m, &cDelay_8VK2Dnja_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ip5cE7Zq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8VK2Dnja, 2, m, &cDelay_8VK2Dnja_sendMessage);
}

void Heavy_CircleStrings::cBinop_uAA32wHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Ip5cE7Zq_sendMessage);
}

void Heavy_CircleStrings::cCast_64Pm0qkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bIMKyMWe, 0, m, &cVar_bIMKyMWe_sendMessage);
  cMsg_89I7csyi_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8NzvLAKx, 0, m, &cTabhead_8NzvLAKx_sendMessage);
}

void Heavy_CircleStrings::cBinop_INZsvwpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_75ke9kiC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6RhoNJIN_sendMessage);
}

void Heavy_CircleStrings::cBinop_k1K2h8CE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Quhe7eBJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_Quhe7eBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OnDduVan, HV_BINOP_POW, 1, m, &cBinop_OnDduVan_sendMessage);
  cMsg_htA4iGT9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_OnDduVan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_INZsvwpQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_htA4iGT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OnDduVan, HV_BINOP_POW, 0, m, &cBinop_OnDduVan_sendMessage);
}

void Heavy_CircleStrings::cVar_fFWMUuYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_k1K2h8CE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RKrNF6KC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k0XRWR9h_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_1To9ihoN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_qS4dOMpz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_qS4dOMpz_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_nxSuhIsJ, 1, m, &cDelay_nxSuhIsJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lsdEoRtJ_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_nxSuhIsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nxSuhIsJ, m);
  cMsg_809bVGYs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_qS4dOMpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nxSuhIsJ, 0, m, &cDelay_nxSuhIsJ_sendMessage);
}

void Heavy_CircleStrings::cCast_lsdEoRtJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nxSuhIsJ, 0, m, &cDelay_nxSuhIsJ_sendMessage);
}

void Heavy_CircleStrings::cVar_20gnBhli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pnx3AuMO, HV_BINOP_MULTIPLY, 0, m, &cBinop_Pnx3AuMO_sendMessage);
}

void Heavy_CircleStrings::cMsg_VhakaLQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FSiS1ysc_sendMessage);
}

void Heavy_CircleStrings::cSystem_FSiS1ysc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hssJkc1t_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Pnx3AuMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_T9eKXgMo_sendMessage);
}

void Heavy_CircleStrings::cBinop_WevOeRGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pnx3AuMO, HV_BINOP_MULTIPLY, 1, m, &cBinop_Pnx3AuMO_sendMessage);
}

void Heavy_CircleStrings::cMsg_hssJkc1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_WevOeRGi_sendMessage);
}

void Heavy_CircleStrings::cBinop_T9eKXgMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_s9yD2cKd_sendMessage);
}

void Heavy_CircleStrings::cBinop_s9yD2cKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_xtuyW6ky_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_V5rJiyTG, m);
}

void Heavy_CircleStrings::cBinop_xtuyW6ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_v2s8gWUH, m);
}

void Heavy_CircleStrings::cMsg_lrQYBNDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uDLoiK6V_sendMessage);
}

void Heavy_CircleStrings::cSystem_uDLoiK6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_c3WJhrbr_sendMessage);
}

void Heavy_CircleStrings::cDelay_dGw3AGMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dGw3AGMQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cInhNouY, 0, m, &cDelay_cInhNouY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dGw3AGMQ, 0, m, &cDelay_dGw3AGMQ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AwXOSOOS, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_cInhNouY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cInhNouY, m);
  cMsg_QmXvAqrK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_mTMlYfe4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_T9dBnH5h_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_8sFe1fV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sHD0qvKm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_pvpd4J9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qtOWS0Os_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dGw3AGMQ, 2, m, &cDelay_dGw3AGMQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lDa9Qi4m_sendMessage);
}

void Heavy_CircleStrings::cMsg_sHD0qvKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_pvpd4J9a, 0, m, &hTable_pvpd4J9a_sendMessage);
}

void Heavy_CircleStrings::cBinop_c3WJhrbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_8sFe1fV1_sendMessage);
}

void Heavy_CircleStrings::cMsg_QmXvAqrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_pvpd4J9a, 0, m, &hTable_pvpd4J9a_sendMessage);
}

void Heavy_CircleStrings::cCast_lDa9Qi4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dGw3AGMQ, 0, m, &cDelay_dGw3AGMQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_qtOWS0Os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cInhNouY, 2, m, &cDelay_cInhNouY_sendMessage);
}

void Heavy_CircleStrings::cMsg_T9dBnH5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AwXOSOOS, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_H6VLyICT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_jZFy9ZEb, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_809bVGYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_jZFy9ZEb, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_RKrNF6KC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1To9ihoN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_k0XRWR9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H6VLyICT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_EAiBQYJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_k1K2h8CE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RKrNF6KC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k0XRWR9h_sendMessage);
}

void Heavy_CircleStrings::cBinop_uYtXZ8iQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_45XC7vmT, HV_BINOP_MULTIPLY, 1, m, &cBinop_45XC7vmT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_64Pm0qkc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nxSuhIsJ, 1, m, &cDelay_nxSuhIsJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_b79vekh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uYtXZ8iQ, HV_BINOP_DIVIDE, 0, m, &cBinop_uYtXZ8iQ_sendMessage);
}

void Heavy_CircleStrings::cCast_6RhoNJIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b79vekh6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_75ke9kiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uYtXZ8iQ, HV_BINOP_DIVIDE, 1, m, &cBinop_uYtXZ8iQ_sendMessage);
}

void Heavy_CircleStrings::cUnop_WRSrjFYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CJtfYMcr, 0, m, &cPack_CJtfYMcr_sendMessage);
}

void Heavy_CircleStrings::cUnop_tkQXnaRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5y7AtNMC, 0, m, &cPack_5y7AtNMC_sendMessage);
}

void Heavy_CircleStrings::cPack_5y7AtNMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_A0Mqvzya, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_CJtfYMcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_bIYsxWWc, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_y5Ijj4Ol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_WRSrjFYP_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_tkQXnaRK_sendMessage);
}

void Heavy_CircleStrings::cMsg_iVsHysxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_y5Ijj4Ol_sendMessage);
}

void Heavy_CircleStrings::cSlice_o1jHa5YZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_f2iqSlgy_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_SDBn9QnO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jsZSttuC_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_H29g7ngX_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_k1K2h8CE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RKrNF6KC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k0XRWR9h_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_c38Zelwf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_vmdQ2Xs4_sendMessage);
}

void Heavy_CircleStrings::cBinop_vmdQ2Xs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_y5Ijj4Ol_sendMessage);
}

void Heavy_CircleStrings::cBinop_f2iqSlgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cWvBMNJh_sendMessage(_c, 0, m);
  cSend_G8XAtyvA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_6eMKx1bH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8yCLjxT1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oFegC5OZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_Iu6ESS4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_KeTJxNzN_sendMessage);
}

void Heavy_CircleStrings::cBinop_KeTJxNzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6eMKx1bH, HV_BINOP_MULTIPLY, 1, m, &cBinop_6eMKx1bH_sendMessage);
}

void Heavy_CircleStrings::cSend_cWvBMNJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qdZua97G_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_oFegC5OZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hNQ6zPaF_sendMessage);
}

void Heavy_CircleStrings::cCast_8yCLjxT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MuJJWaxm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_GpJ4llGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7UPbZEyv, 0, m, &cPack_7UPbZEyv_sendMessage);
}

void Heavy_CircleStrings::cSend_G8XAtyvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oUizUuqK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_6wfTxc3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qQf1Sj8t_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_S2BLM4zb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_6wfTxc3q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_AVgY8tjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_MBNyl61Q, m);
}

void Heavy_CircleStrings::cCast_jsZSttuC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_49YrkNGb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_IExIe62K_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lpW9XVB8, 0, m, &cSlice_lpW9XVB8_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ui69rqIM, 0, m, &cRandom_Ui69rqIM_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_44mekG7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HhIm3z9U_sendMessage);
}

void Heavy_CircleStrings::cUnop_HhIm3z9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_oB80vVJ6_sendMessage);
}

void Heavy_CircleStrings::cRandom_Ui69rqIM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_44mekG7P_sendMessage);
}

void Heavy_CircleStrings::cSlice_lpW9XVB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ui69rqIM, 1, m, &cRandom_Ui69rqIM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_QIaEHUYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5jGmUKCT, HV_BINOP_MULTIPLY, 0, m, &cBinop_5jGmUKCT_sendMessage);
}

void Heavy_CircleStrings::cBinop_0QsOADFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_jVRYVazq_sendMessage);
}

void Heavy_CircleStrings::cBinop_jVRYVazq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ioicey9L, HV_BINOP_POW, 1, m, &cBinop_Ioicey9L_sendMessage);
  cMsg_sW9O6cyU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Ioicey9L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_QIaEHUYx_sendMessage);
}

void Heavy_CircleStrings::cMsg_sW9O6cyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ioicey9L, HV_BINOP_POW, 0, m, &cBinop_Ioicey9L_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_bOZiXmfU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JFNre4Ln, 0, m, &cSlice_JFNre4Ln_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dsgusB0s, 0, m, &cRandom_dsgusB0s_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_V949coBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9oXVDOpH_sendMessage);
}

void Heavy_CircleStrings::cUnop_9oXVDOpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pNcGMsAS_sendMessage);
}

void Heavy_CircleStrings::cRandom_dsgusB0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_V949coBJ_sendMessage);
}

void Heavy_CircleStrings::cSlice_JFNre4Ln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dsgusB0s, 1, m, &cRandom_dsgusB0s_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_nwhd7nVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_sHaLLgCs, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_X4utlX6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_3it1n4es_sendMessage);
}

void Heavy_CircleStrings::cVar_KKNniKiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_FXaTQbAM, 0, m);
}

void Heavy_CircleStrings::cVar_L5CTqsBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_riAf36Yb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5uo8gQVu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ruiTjpzs_sendMessage);
}

void Heavy_CircleStrings::cVar_SVoMTWeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_lWrCeEfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_WHuz6Syw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_y6cOTYHz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_RyNf2eJf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_RyNf2eJf_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_OVJV2EWj, 1, m, &cDelay_OVJV2EWj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ANSZdbLT_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_OVJV2EWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OVJV2EWj, m);
  cVar_onMessage(_c, &Context(_c)->cVar_K1sT4Noq, 0, m, &cVar_K1sT4Noq_sendMessage);
}

void Heavy_CircleStrings::cMsg_RyNf2eJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_OVJV2EWj, 0, m, &cDelay_OVJV2EWj_sendMessage);
}

void Heavy_CircleStrings::cCast_ANSZdbLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OVJV2EWj, 0, m, &cDelay_OVJV2EWj_sendMessage);
}

void Heavy_CircleStrings::cVar_K1sT4Noq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hj8pEj3K_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Np5HqRyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L5CTqsBy, 0, m, &cVar_L5CTqsBy_sendMessage);
}

void Heavy_CircleStrings::cMsg_yScQwlbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_XTNwEtVg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Y2ng3G8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_ehAvKB74_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_5JgHy7ai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_SYXcvfkH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_rGEbazTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oVtyx6ag_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_QSCUnKSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_cKbVkHXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WX73Qn7b_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_XTNwEtVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_ehAvKB74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oVtyx6ag_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_SYXcvfkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WX73Qn7b_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_HD87vPhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_AFw14lx8, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_hj8pEj3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_AFw14lx8, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_5uo8gQVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K1sT4Noq, 1, m, &cVar_K1sT4Noq_sendMessage);
}

void Heavy_CircleStrings::cCast_riAf36Yb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HD87vPhA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ruiTjpzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_y6cOTYHz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_GcSHmiaw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YietMgtj, 0, m, &cSlice_YietMgtj_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_56ii3zGI, 0, m, &cRandom_56ii3zGI_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_aAOkxwiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xA8hofDf_sendMessage);
}

void Heavy_CircleStrings::cUnop_xA8hofDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XDgMHOT9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_56ii3zGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_aAOkxwiI_sendMessage);
}

void Heavy_CircleStrings::cSlice_YietMgtj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_56ii3zGI, 1, m, &cRandom_56ii3zGI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_XDgMHOT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_oA6MA27z, m);
}

void Heavy_CircleStrings::cTabhead_rVZc4tAx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hlS5Ss8o, HV_BINOP_SUBTRACT, 0, m, &cBinop_hlS5Ss8o_sendMessage);
}

void Heavy_CircleStrings::cMsg_C1dNOCHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xoV2zl0E_sendMessage);
}

void Heavy_CircleStrings::cSystem_xoV2zl0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uVwbPdND_sendMessage);
}

void Heavy_CircleStrings::cVar_vDRIuxsO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WO78GsE9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_xdxC85Aj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xdxC85Aj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wknQ6TkK, 0, m, &cDelay_wknQ6TkK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CdfGyxk0, 0, m, &sTabread_CdfGyxk0_sendMessage);
}

void Heavy_CircleStrings::cDelay_wknQ6TkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wknQ6TkK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CdfGyxk0, 0, m, &sTabread_CdfGyxk0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wknQ6TkK, 0, m, &cDelay_wknQ6TkK_sendMessage);
}

void Heavy_CircleStrings::sTabread_CdfGyxk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0syxJAOD, HV_BINOP_SUBTRACT, 0, m, &cBinop_0syxJAOD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_8hCLJPq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EYLTHCzY, HV_BINOP_MAX, 0, m, &cBinop_EYLTHCzY_sendMessage);
}

void Heavy_CircleStrings::cBinop_uVwbPdND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8hCLJPq4, HV_BINOP_MULTIPLY, 0, m, &cBinop_8hCLJPq4_sendMessage);
}

void Heavy_CircleStrings::cBinop_hlS5Ss8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vKibam3c_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CdfGyxk0, 0, m, &sTabread_CdfGyxk0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dnLDOGkN_sendMessage);
}

void Heavy_CircleStrings::cSystem_JmpOuxAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0syxJAOD, HV_BINOP_SUBTRACT, 1, m, &cBinop_0syxJAOD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wknQ6TkK, 2, m, &cDelay_wknQ6TkK_sendMessage);
}

void Heavy_CircleStrings::cMsg_WO78GsE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JmpOuxAf_sendMessage);
}

void Heavy_CircleStrings::cMsg_vKibam3c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xdxC85Aj, 0, m, &cDelay_xdxC85Aj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wknQ6TkK, 0, m, &cDelay_wknQ6TkK_sendMessage);
}

void Heavy_CircleStrings::cMsg_CMKfaMiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_EYLTHCzY, HV_BINOP_MAX, 1, m, &cBinop_EYLTHCzY_sendMessage);
}

void Heavy_CircleStrings::cBinop_EYLTHCzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hlS5Ss8o, HV_BINOP_SUBTRACT, 1, m, &cBinop_hlS5Ss8o_sendMessage);
}

void Heavy_CircleStrings::cCast_dnLDOGkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xdxC85Aj, 0, m, &cDelay_xdxC85Aj_sendMessage);
}

void Heavy_CircleStrings::cBinop_I3oA44sz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xdxC85Aj, 2, m, &cDelay_xdxC85Aj_sendMessage);
}

void Heavy_CircleStrings::cBinop_0syxJAOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_I3oA44sz_sendMessage);
}

void Heavy_CircleStrings::cCast_HndSs6MM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vDRIuxsO, 0, m, &cVar_vDRIuxsO_sendMessage);
  cMsg_C1dNOCHz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_rVZc4tAx, 0, m, &cTabhead_rVZc4tAx_sendMessage);
}

void Heavy_CircleStrings::cBinop_nWGQdZSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DgibEhYn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XOmczAT3_sendMessage);
}

void Heavy_CircleStrings::cBinop_jvepTmEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_9lCtAjzO_sendMessage);
}

void Heavy_CircleStrings::cBinop_9lCtAjzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JqeMXq6F, HV_BINOP_POW, 1, m, &cBinop_JqeMXq6F_sendMessage);
  cMsg_a4lf7BM2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_JqeMXq6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_nWGQdZSc_sendMessage);
}

void Heavy_CircleStrings::cMsg_a4lf7BM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JqeMXq6F, HV_BINOP_POW, 0, m, &cBinop_JqeMXq6F_sendMessage);
}

void Heavy_CircleStrings::cVar_13Mlpflt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_jvepTmEZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7a1QKgYz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tZZXf1sh_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_Ivw6mrFU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_NjsrJDR8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_NjsrJDR8_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_0XAr3P21, 1, m, &cDelay_0XAr3P21_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uvc7pqvY_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_0XAr3P21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0XAr3P21, m);
  cMsg_5yOunLV5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_NjsrJDR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0XAr3P21, 0, m, &cDelay_0XAr3P21_sendMessage);
}

void Heavy_CircleStrings::cCast_uvc7pqvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0XAr3P21, 0, m, &cDelay_0XAr3P21_sendMessage);
}

void Heavy_CircleStrings::cVar_gqQhRQqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cMfCJWyT, HV_BINOP_MULTIPLY, 0, m, &cBinop_cMfCJWyT_sendMessage);
}

void Heavy_CircleStrings::cMsg_qvJZdUBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iCD5nDAf_sendMessage);
}

void Heavy_CircleStrings::cSystem_iCD5nDAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sWI8kmir_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_cMfCJWyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_yxQQjRVL_sendMessage);
}

void Heavy_CircleStrings::cBinop_R1gKhK5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cMfCJWyT, HV_BINOP_MULTIPLY, 1, m, &cBinop_cMfCJWyT_sendMessage);
}

void Heavy_CircleStrings::cMsg_sWI8kmir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_R1gKhK5W_sendMessage);
}

void Heavy_CircleStrings::cBinop_yxQQjRVL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GXbUx1dc_sendMessage);
}

void Heavy_CircleStrings::cBinop_GXbUx1dc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_kPJr4pkD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ja3r94A4, m);
}

void Heavy_CircleStrings::cBinop_kPJr4pkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bXbHQR9y, m);
}

void Heavy_CircleStrings::cMsg_yakNLEN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k3o5L8gc_sendMessage);
}

void Heavy_CircleStrings::cSystem_k3o5L8gc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tAiWwCeW_sendMessage);
}

void Heavy_CircleStrings::cDelay_PVUzXNkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PVUzXNkm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RfiF60ko, 0, m, &cDelay_RfiF60ko_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PVUzXNkm, 0, m, &cDelay_PVUzXNkm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9NtayjcT, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_RfiF60ko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RfiF60ko, m);
  cMsg_IogJxLb9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_IhwPEpIi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3gni1nG4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Gi3AniR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jW7GxvTT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_DCGCrjpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NnJVQmaU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PVUzXNkm, 2, m, &cDelay_PVUzXNkm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XnV17TTW_sendMessage);
}

void Heavy_CircleStrings::cMsg_jW7GxvTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_DCGCrjpW, 0, m, &hTable_DCGCrjpW_sendMessage);
}

void Heavy_CircleStrings::cBinop_tAiWwCeW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_Gi3AniR5_sendMessage);
}

void Heavy_CircleStrings::cMsg_IogJxLb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_DCGCrjpW, 0, m, &hTable_DCGCrjpW_sendMessage);
}

void Heavy_CircleStrings::cCast_XnV17TTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PVUzXNkm, 0, m, &cDelay_PVUzXNkm_sendMessage);
}

void Heavy_CircleStrings::cMsg_NnJVQmaU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_RfiF60ko, 2, m, &cDelay_RfiF60ko_sendMessage);
}

void Heavy_CircleStrings::cMsg_3gni1nG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9NtayjcT, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_gATYnWG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wNRRhgUU, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_5yOunLV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wNRRhgUU, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_tZZXf1sh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gATYnWG0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_7a1QKgYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ivw6mrFU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_4DeykmFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_jvepTmEZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7a1QKgYz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tZZXf1sh_sendMessage);
}

void Heavy_CircleStrings::cBinop_FYMYBLdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8hCLJPq4, HV_BINOP_MULTIPLY, 1, m, &cBinop_8hCLJPq4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HndSs6MM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0XAr3P21, 1, m, &cDelay_0XAr3P21_sendMessage);
}

void Heavy_CircleStrings::cMsg_jXpQqASa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FYMYBLdv, HV_BINOP_DIVIDE, 0, m, &cBinop_FYMYBLdv_sendMessage);
}

void Heavy_CircleStrings::cCast_DgibEhYn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FYMYBLdv, HV_BINOP_DIVIDE, 1, m, &cBinop_FYMYBLdv_sendMessage);
}

void Heavy_CircleStrings::cCast_XOmczAT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jXpQqASa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_38psvrGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8bRWH4K8, 0, m, &cPack_8bRWH4K8_sendMessage);
}

void Heavy_CircleStrings::cUnop_WlvzGBLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HijIPRWN, 0, m, &cPack_HijIPRWN_sendMessage);
}

void Heavy_CircleStrings::cPack_HijIPRWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RDBwfT6n, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_8bRWH4K8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Yo1naduW, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_EL1KLrtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_38psvrGP_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_WlvzGBLa_sendMessage);
}

void Heavy_CircleStrings::cMsg_sNPgUQZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_EL1KLrtG_sendMessage);
}

void Heavy_CircleStrings::cSlice_9kzd4qw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_oGe5DutZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_swxRZ9pb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h05xAH6K_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_0QsOADFO_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_jvepTmEZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7a1QKgYz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tZZXf1sh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_oB80vVJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_7rT75xbM_sendMessage);
}

void Heavy_CircleStrings::cBinop_7rT75xbM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_EL1KLrtG_sendMessage);
}

void Heavy_CircleStrings::cBinop_oGe5DutZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Y0X5RNYg_sendMessage(_c, 0, m);
  cSend_GwvEylOM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_5jGmUKCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1MevrPMe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7f2k9Z1g_sendMessage);
}

void Heavy_CircleStrings::cBinop_pNcGMsAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_DCjFxMld_sendMessage);
}

void Heavy_CircleStrings::cBinop_DCjFxMld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5jGmUKCT, HV_BINOP_MULTIPLY, 1, m, &cBinop_5jGmUKCT_sendMessage);
}

void Heavy_CircleStrings::cSend_Y0X5RNYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_68t2IYqN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_1MevrPMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_IExIe62K_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_7f2k9Z1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Np5HqRyV_sendMessage);
}

void Heavy_CircleStrings::cBinop_3it1n4es_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nwhd7nVK, 0, m, &cPack_nwhd7nVK_sendMessage);
}

void Heavy_CircleStrings::cSend_GwvEylOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XJ6T1u7z_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_OlqyJoSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4RPCBEA4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_W6fSWqQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_OlqyJoSm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ESjLjI4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3Ugyc5CU, m);
}

void Heavy_CircleStrings::cCast_h05xAH6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bOZiXmfU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_8RPOPWbf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8mEq6PLl_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3B36KL3I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IuhYx9Ve_sendMessage);
}

void Heavy_CircleStrings::cIf_FjAf9k6X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_lD77QAt0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_nkN1u0hf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_OgltmoDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7eIZJ9cz, HV_BINOP_POW, 0, m, &cBinop_7eIZJ9cz_sendMessage);
}

void Heavy_CircleStrings::cBinop_7eIZJ9cz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2iZvvVMJ, 0, m, &cPack_2iZvvVMJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_P7RKrzBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_UahWko2v_sendMessage);
}

void Heavy_CircleStrings::cCast_3B36KL3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_g9D5TSOs_sendMessage);
}

void Heavy_CircleStrings::cCast_IuhYx9Ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FjAf9k6X, 0, m, &cIf_FjAf9k6X_sendMessage);
}

void Heavy_CircleStrings::cBinop_g9D5TSOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FjAf9k6X, 1, m, &cIf_FjAf9k6X_sendMessage);
}

void Heavy_CircleStrings::cBinop_nkN1u0hf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_P7RKrzBt_sendMessage);
}

void Heavy_CircleStrings::cMsg_lD77QAt0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_2iZvvVMJ, 0, m, &cPack_2iZvvVMJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_UahWko2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7eIZJ9cz, HV_BINOP_POW, 1, m, &cBinop_7eIZJ9cz_sendMessage);
  cMsg_OgltmoDU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_2iZvvVMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Fpyw1Bul, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_ozNFEFEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_m0BitOYF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_8mEq6PLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_pcULhxnG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_pcULhxnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3ekvhXA7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_m0BitOYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_B20vMJW5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_1pPDI4cD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4BTzgZUK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dx2MEV1u_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IrG9yXC7_sendMessage);
}

void Heavy_CircleStrings::cIf_owpbKHAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_wxymSBLm_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_MRO1arHa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_fld8DpJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AODEktD2, HV_BINOP_POW, 0, m, &cBinop_AODEktD2_sendMessage);
}

void Heavy_CircleStrings::cBinop_AODEktD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_H8oS241C, 0, m, &cPack_H8oS241C_sendMessage);
}

void Heavy_CircleStrings::cBinop_Zldfq1gc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_0Fp1xr0O_sendMessage);
}

void Heavy_CircleStrings::cCast_IrG9yXC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_owpbKHAq, 0, m, &cIf_owpbKHAq_sendMessage);
}

void Heavy_CircleStrings::cCast_dx2MEV1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_vsW9AaJv_sendMessage);
}

void Heavy_CircleStrings::cBinop_vsW9AaJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_owpbKHAq, 1, m, &cIf_owpbKHAq_sendMessage);
}

void Heavy_CircleStrings::cBinop_MRO1arHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_Zldfq1gc_sendMessage);
}

void Heavy_CircleStrings::cMsg_wxymSBLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_H8oS241C, 0, m, &cPack_H8oS241C_sendMessage);
}

void Heavy_CircleStrings::cBinop_0Fp1xr0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AODEktD2, HV_BINOP_POW, 1, m, &cBinop_AODEktD2_sendMessage);
  cMsg_fld8DpJt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_H8oS241C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lXKOU52A, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_mmK7GLJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9Anv2eLt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_4BTzgZUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_piepEQ0P_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_piepEQ0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tKIQJoSo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_9Anv2eLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_opvFtmTy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_HilTTVMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o02G1nSP_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_geib8ygD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ej3CSkVG_sendMessage);
}

void Heavy_CircleStrings::cIf_b2w3jChM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_zvr2vxIK_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_p2BINhpC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_RwWc92xy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZHoJBRzc, HV_BINOP_POW, 0, m, &cBinop_ZHoJBRzc_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZHoJBRzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rO9GPyr6, 0, m, &cPack_rO9GPyr6_sendMessage);
}

void Heavy_CircleStrings::cBinop_THrtr0F3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_SbWgESkI_sendMessage);
}

void Heavy_CircleStrings::cCast_ej3CSkVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b2w3jChM, 0, m, &cIf_b2w3jChM_sendMessage);
}

void Heavy_CircleStrings::cCast_geib8ygD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_0xzqI4Ui_sendMessage);
}

void Heavy_CircleStrings::cBinop_0xzqI4Ui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b2w3jChM, 1, m, &cIf_b2w3jChM_sendMessage);
}

void Heavy_CircleStrings::cBinop_p2BINhpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_THrtr0F3_sendMessage);
}

void Heavy_CircleStrings::cMsg_zvr2vxIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_rO9GPyr6, 0, m, &cPack_rO9GPyr6_sendMessage);
}

void Heavy_CircleStrings::cBinop_SbWgESkI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZHoJBRzc, HV_BINOP_POW, 1, m, &cBinop_ZHoJBRzc_sendMessage);
  cMsg_RwWc92xy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_rO9GPyr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2faw2Ms7, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_vyua7Yc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SQooo83U_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_o02G1nSP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_g3HVfby8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_g3HVfby8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_plAmcubq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_SQooo83U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Bj3bGHrp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_8qKJNVvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VrTGJkRc_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_0mtv6amU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_0mtv6amU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_2jXt9B3A_sendMessage);
}

void Heavy_CircleStrings::cCast_xYQR0llH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8qKJNVvx, 0, m, &cIf_8qKJNVvx_sendMessage);
}

void Heavy_CircleStrings::cCast_HuSf5cSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_0MY24hip_sendMessage);
}

void Heavy_CircleStrings::cMsg_VrTGJkRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_8mEq6PLl_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3B36KL3I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IuhYx9Ve_sendMessage);
}

void Heavy_CircleStrings::cBinop_2jXt9B3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_Z79no2V7_sendMessage);
}

void Heavy_CircleStrings::cBinop_Z79no2V7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_SfrPiRG1_sendMessage);
}

void Heavy_CircleStrings::cBinop_SfrPiRG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8mEq6PLl_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3B36KL3I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IuhYx9Ve_sendMessage);
}

void Heavy_CircleStrings::cBinop_0MY24hip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8qKJNVvx, 1, m, &cIf_8qKJNVvx_sendMessage);
}

void Heavy_CircleStrings::cBinop_1V22yEOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HuSf5cSN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xYQR0llH_sendMessage);
}

void Heavy_CircleStrings::cBinop_xSlCedvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_1V22yEOR_sendMessage);
}

void Heavy_CircleStrings::cIf_Y68UUWba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_2VPJuGLc_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_XA3OCsNi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_XA3OCsNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_Ka1ZPwpO_sendMessage);
}

void Heavy_CircleStrings::cCast_2kZohJPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_zEALpCjj_sendMessage);
}

void Heavy_CircleStrings::cCast_E5DU8pTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Y68UUWba, 0, m, &cIf_Y68UUWba_sendMessage);
}

void Heavy_CircleStrings::cMsg_2VPJuGLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_4BTzgZUK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dx2MEV1u_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IrG9yXC7_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ka1ZPwpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_WdDkIFfs_sendMessage);
}

void Heavy_CircleStrings::cBinop_WdDkIFfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Z2d3sxNP_sendMessage);
}

void Heavy_CircleStrings::cBinop_Z2d3sxNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4BTzgZUK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dx2MEV1u_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IrG9yXC7_sendMessage);
}

void Heavy_CircleStrings::cBinop_zEALpCjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Y68UUWba, 1, m, &cIf_Y68UUWba_sendMessage);
}

void Heavy_CircleStrings::cBinop_c7QuKcgI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2kZohJPd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_E5DU8pTB_sendMessage);
}

void Heavy_CircleStrings::cBinop_9kN5Sndr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_c7QuKcgI_sendMessage);
}

void Heavy_CircleStrings::cVar_Bs1qFXGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8vYbXBW9_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sl3saqHi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AuLNDnm6_sendMessage);
}

void Heavy_CircleStrings::cIf_sUgsXWQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_f9Xli2iG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_eOEimfcn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_JArru3Kn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_q5saU67P, HV_BINOP_POW, 0, m, &cBinop_q5saU67P_sendMessage);
}

void Heavy_CircleStrings::cBinop_q5saU67P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_MbEje83s, 0, m, &cPack_MbEje83s_sendMessage);
}

void Heavy_CircleStrings::cBinop_hYiXcUP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ulAWz3DV_sendMessage);
}

void Heavy_CircleStrings::cCast_sl3saqHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_nzP6KJDM_sendMessage);
}

void Heavy_CircleStrings::cCast_AuLNDnm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sUgsXWQE, 0, m, &cIf_sUgsXWQE_sendMessage);
}

void Heavy_CircleStrings::cBinop_nzP6KJDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sUgsXWQE, 1, m, &cIf_sUgsXWQE_sendMessage);
}

void Heavy_CircleStrings::cBinop_eOEimfcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_hYiXcUP2_sendMessage);
}

void Heavy_CircleStrings::cMsg_f9Xli2iG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_MbEje83s, 0, m, &cPack_MbEje83s_sendMessage);
}

void Heavy_CircleStrings::cBinop_ulAWz3DV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q5saU67P, HV_BINOP_POW, 1, m, &cBinop_q5saU67P_sendMessage);
  cMsg_JArru3Kn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_MbEje83s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_XDSWxmry, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_QeRwSO4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Rrljc78s_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_8vYbXBW9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_0gAv9BQP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_0gAv9BQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xzTuggGI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Rrljc78s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dstYVEvJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_j949lUAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_S7i8X3CB, 0, m, &cIf_S7i8X3CB_sendMessage);
}

void Heavy_CircleStrings::cSlice_NKhSGRqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8xbGair1_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HebPWztp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_N9ewK21o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_Y1VO59hg, 0, m, &cIf_Y1VO59hg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_Y1VO59hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xgnnFscl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iZYbYVop_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_PEndkoVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_pzJ0g39m, 2, m, &cPack_pzJ0g39m_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_gtAi5N5J, 1, m, &cPack_gtAi5N5J_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_XovLH2YC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_NKhSGRqQ, 0, m, &cSlice_NKhSGRqQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_N9ewK21o, 0, m, &cSlice_N9ewK21o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_qfzLa1Hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_akqClUVA_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_A0vSgSvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hSj1hbuV_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7PIbKwCa_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kuYwvBy0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_TudsweYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5oezjAOE, 1, m, &cIf_5oezjAOE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_8CPs6j55_sendMessage);
}

void Heavy_CircleStrings::cIf_5oezjAOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_NKhSGRqQ, 0, m, &cSlice_NKhSGRqQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_N9ewK21o, 0, m, &cSlice_N9ewK21o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_gtAi5N5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XovLH2YC, 0, m, &cIf_XovLH2YC_sendMessage);
}

void Heavy_CircleStrings::cBinop_sAlLRjYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Y1VO59hg, 1, m, &cIf_Y1VO59hg_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_PEndkoVi, 1, m, &cIf_PEndkoVi_sendMessage);
}

void Heavy_CircleStrings::cCast_8xbGair1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_sAlLRjYz_sendMessage);
}

void Heavy_CircleStrings::cCast_HebPWztp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PEndkoVi, 0, m, &cIf_PEndkoVi_sendMessage);
}

void Heavy_CircleStrings::cMsg_xvnHuQSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_TudsweYL, 1, m, &cVar_TudsweYL_sendMessage);
}

void Heavy_CircleStrings::cMsg_akqClUVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_TudsweYL, 1, m, &cVar_TudsweYL_sendMessage);
}

void Heavy_CircleStrings::cCast_7PIbKwCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gtAi5N5J, 0, m, &cPack_gtAi5N5J_sendMessage);
}

void Heavy_CircleStrings::cCast_kuYwvBy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xvnHuQSb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_hSj1hbuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TudsweYL, 0, m, &cVar_TudsweYL_sendMessage);
}

void Heavy_CircleStrings::cBinop_8CPs6j55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XovLH2YC, 1, m, &cIf_XovLH2YC_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_moD2J8MS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GtAMpbAP, 0, m, &cSlice_GtAMpbAP_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pudsVKGB, 0, m, &cSlice_pudsVKGB_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qHXn9TQI, 0, m, &cSlice_qHXn9TQI_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rp2nKw9s, 0, m, &cSlice_rp2nKw9s_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_GtAMpbAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_VEyJlx6i, 0, m, &cSlice_VEyJlx6i_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_YI3lADQ2, 0, m, &cSlice_YI3lADQ2_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_VEyJlx6i, 0, m, &cSlice_VEyJlx6i_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_YI3lADQ2, 0, m, &cSlice_YI3lADQ2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_pudsVKGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_o1jHa5YZ, 0, m, &cSlice_o1jHa5YZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_SDBn9QnO, 0, m, &cSlice_SDBn9QnO_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_o1jHa5YZ, 0, m, &cSlice_o1jHa5YZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_SDBn9QnO, 0, m, &cSlice_SDBn9QnO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_qHXn9TQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_9kzd4qw3, 0, m, &cSlice_9kzd4qw3_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_swxRZ9pb, 0, m, &cSlice_swxRZ9pb_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_9kzd4qw3, 0, m, &cSlice_9kzd4qw3_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_swxRZ9pb, 0, m, &cSlice_swxRZ9pb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_rp2nKw9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_pERPQs4V, 0, m, &cSlice_pERPQs4V_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wKr3KvmA, 0, m, &cSlice_wKr3KvmA_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_pERPQs4V, 0, m, &cSlice_pERPQs4V_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wKr3KvmA, 0, m, &cSlice_wKr3KvmA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_rZo5wMKL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ab5OygS9_sendMessage);
      break;
    }
    default: {
      cMsg_pGdTC6CS_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_Ab5OygS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YhWWengX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_S7i8X3CB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qfzLa1Hd, 0, m, &cSlice_qfzLa1Hd_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_A0vSgSvQ, 0, m, &cSlice_A0vSgSvQ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_5oezjAOE, 0, m, &cIf_5oezjAOE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_vQ0stwpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_JSkoKhH7_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_S7i8X3CB, 1, m, &cIf_S7i8X3CB_sendMessage);
}

void Heavy_CircleStrings::cBinop_JSkoKhH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vQ0stwpg, 1, m, &cVar_vQ0stwpg_sendMessage);
}

void Heavy_CircleStrings::cMsg_YhWWengX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_vQ0stwpg, 0, m, &cVar_vQ0stwpg_sendMessage);
}

void Heavy_CircleStrings::cMsg_pGdTC6CS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_vQ0stwpg, 0, m, &cVar_vQ0stwpg_sendMessage);
}

void Heavy_CircleStrings::cPack_pzJ0g39m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_moD2J8MS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_WONrFDuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pzJ0g39m, 0, m, &cPack_pzJ0g39m_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_hUISobLv_sendMessage);
}

void Heavy_CircleStrings::cBinop_hUISobLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_Ra7j8pLT_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ra7j8pLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WONrFDuz, 1, m, &cVar_WONrFDuz_sendMessage);
}

void Heavy_CircleStrings::cMsg_WbUaIZFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_rZo5wMKL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_iZYbYVop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WONrFDuz, 0, m, &cVar_WONrFDuz_sendMessage);
}

void Heavy_CircleStrings::cCast_xgnnFscl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pzJ0g39m, 1, m, &cPack_pzJ0g39m_sendMessage);
}

void Heavy_CircleStrings::cSend_Kxuv9kbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jvkTwu3B_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_uK8dxdnc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FVLn8lfV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_tWTYneeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cBinop_pMF2RuRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IKm4tRuK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_IKm4tRuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0Zh0qZMd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_aI3hFZSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_r4MKvULf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cReceive_ogbrL805_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rCwsEbzr_sendMessage(_c, 0, m);
  cMsg_hJC8dSAy_sendMessage(_c, 0, m);
  cMsg_xKZ6gHtp_sendMessage(_c, 0, m);
  cMsg_h0DXSyXC_sendMessage(_c, 0, m);
  cMsg_PYwNSVk9_sendMessage(_c, 0, m);
  cMsg_KaPy31CN_sendMessage(_c, 0, m);
  cMsg_jpoGaqnN_sendMessage(_c, 0, m);
  cMsg_MIESHuUk_sendMessage(_c, 0, m);
  cMsg_0HkgVW86_sendMessage(_c, 0, m);
  cMsg_gAMHFrDj_sendMessage(_c, 0, m);
  cMsg_uPu08k8k_sendMessage(_c, 0, m);
  cMsg_tDjrFSdK_sendMessage(_c, 0, m);
  cMsg_T8BtSvjQ_sendMessage(_c, 0, m);
  cMsg_GYPCLLSm_sendMessage(_c, 0, m);
  cMsg_voS5M3uR_sendMessage(_c, 0, m);
  cMsg_DlJvBiP7_sendMessage(_c, 0, m);
  cMsg_JlSiSGxI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3tS9eshW, 0, m, &cVar_3tS9eshW_sendMessage);
  cMsg_3muTb6UM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xO0rjc0C, 0, m, &cVar_xO0rjc0C_sendMessage);
  cMsg_XoWpQDt4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rBhchbRu, 0, m, &cVar_rBhchbRu_sendMessage);
  cMsg_tYKRTQM8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AYY8j1VC, 0, m, &cVar_AYY8j1VC_sendMessage);
  cMsg_RGz1axTH_sendMessage(_c, 0, m);
  cMsg_tP6ylKjp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dZzjUefw, 0, m, &cVar_dZzjUefw_sendMessage);
  cMsg_VWV770OB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uni0ffev, 0, m, &cVar_uni0ffev_sendMessage);
  cMsg_PeSyHenk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8ldKbgG6, 0, m, &cVar_8ldKbgG6_sendMessage);
  cMsg_rMWURiSc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kHQ6wZvL, 0, m, &cVar_kHQ6wZvL_sendMessage);
  cMsg_QA4Vd7ep_sendMessage(_c, 0, m);
  cMsg_JmYFKsCs_sendMessage(_c, 0, m);
  cMsg_rRFTvh5v_sendMessage(_c, 0, m);
  cMsg_s4vAoabH_sendMessage(_c, 0, m);
  cMsg_hIpAEjDj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YVCceG8T, 0, m, &cVar_YVCceG8T_sendMessage);
  cMsg_DHZQVDbm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VfGQc1d4, 0, m, &cVar_VfGQc1d4_sendMessage);
  cMsg_AvtEXuPl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IemS5MsI, 0, m, &cVar_IemS5MsI_sendMessage);
  cMsg_rKd1ZkwR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MEWRxRwf, 0, m, &cVar_MEWRxRwf_sendMessage);
  cMsg_RfUxRlQ0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5wBpilFf, 0, m, &cVar_5wBpilFf_sendMessage);
  cMsg_k9JehG4H_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8Ic7bcIK, 0, m, &cVar_8Ic7bcIK_sendMessage);
  cMsg_ZAlwokAr_sendMessage(_c, 0, m);
  cMsg_TEM1w6QG_sendMessage(_c, 0, m);
  cMsg_nzVKibc0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lDIoQcFQ, 0, m, &cVar_lDIoQcFQ_sendMessage);
  cMsg_zlfgGabQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_apMxCtU9, 0, m, &cVar_apMxCtU9_sendMessage);
  cMsg_5I5IZ1pW_sendMessage(_c, 0, m);
  cMsg_EVlhq7Un_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Vquy3exB, 0, m, &cVar_Vquy3exB_sendMessage);
  cMsg_hIiPdr2a_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vkHJZu37, 0, m, &cVar_vkHJZu37_sendMessage);
  cSwitchcase_YsaqIORJ_onMessage(_c, NULL, 0, m, NULL);
  cMsg_wOXNh29l_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5Dld9cBI, 0, m, &cVar_5Dld9cBI_sendMessage);
  cMsg_zbB1PeXK_sendMessage(_c, 0, m);
  cSwitchcase_rIz6F3ob_onMessage(_c, NULL, 0, m, NULL);
  cMsg_rPHNFrWK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tojINI2A, 0, m, &cVar_tojINI2A_sendMessage);
  cMsg_xUK9nve0_sendMessage(_c, 0, m);
  cSwitchcase_Snld6P3L_onMessage(_c, NULL, 0, m, NULL);
  cMsg_wiJ90f2b_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sZZWwuQO, 0, m, &cVar_sZZWwuQO_sendMessage);
  cMsg_Uc7vqGEf_sendMessage(_c, 0, m);
  cSwitchcase_g2QF0UN9_onMessage(_c, NULL, 0, m, NULL);
  cMsg_VhakaLQf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_20gnBhli, 0, m, &cVar_20gnBhli_sendMessage);
  cMsg_lrQYBNDf_sendMessage(_c, 0, m);
  cSwitchcase_GcSHmiaw_onMessage(_c, NULL, 0, m, NULL);
  cMsg_qvJZdUBV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gqQhRQqu, 0, m, &cVar_gqQhRQqu_sendMessage);
  cMsg_yakNLEN4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mFUQuxBp, 0, m, &cVar_mFUQuxBp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aMck80M5, 0, m, &cVar_aMck80M5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fkA3ZK9h, 0, m, &cVar_fkA3ZK9h_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mlcYFQEB, 0, m, &cVar_mlcYFQEB_sendMessage);
  cMsg_rgaoeZpo_sendMessage(_c, 0, m);
  cMsg_Tc5mq5yN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jV4rJmGT, 0, m, &cVar_jV4rJmGT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gx5SzHcF, 0, m, &cVar_gx5SzHcF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vx5Lx6GN, 0, m, &cVar_vx5Lx6GN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iWK6SRJ1, 0, m, &cVar_iWK6SRJ1_sendMessage);
  cMsg_cdIzmBn0_sendMessage(_c, 0, m);
  cMsg_pLpYE0MY_sendMessage(_c, 0, m);
  cMsg_xo3vDOW1_sendMessage(_c, 0, m);
  cMsg_YvkoeVMu_sendMessage(_c, 0, m);
  cMsg_E030jJS8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8W0AnBcs, 0, m, &cVar_8W0AnBcs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BLRHJtYX, 0, m, &cVar_BLRHJtYX_sendMessage);
  cMsg_fDD0A3FT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_F8T2ZkxU, 0, m, &cVar_F8T2ZkxU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gAHza7Qx, 0, m, &cVar_gAHza7Qx_sendMessage);
  cMsg_KHg20dOy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_V7kyJfco, 0, m, &cVar_V7kyJfco_sendMessage);
  cMsg_lYXz99lb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_co4Hzb1S, 0, m, &cVar_co4Hzb1S_sendMessage);
  cMsg_VX47NP15_sendMessage(_c, 0, m);
  cMsg_OUq1jWav_sendMessage(_c, 0, m);
  cMsg_ChtXRskB_sendMessage(_c, 0, m);
  cMsg_jW01iCg4_sendMessage(_c, 0, m);
  cMsg_aHURajxT_sendMessage(_c, 0, m);
  cMsg_NQepEDFu_sendMessage(_c, 0, m);
  cMsg_NLUhcsfS_sendMessage(_c, 0, m);
  cMsg_f8P1V08R_sendMessage(_c, 0, m);
  cMsg_y59cmSRt_sendMessage(_c, 0, m);
  cMsg_vD7VMFbp_sendMessage(_c, 0, m);
  cMsg_UlFvlo4m_sendMessage(_c, 0, m);
  cMsg_iVsHysxv_sendMessage(_c, 0, m);
  cMsg_yScQwlbD_sendMessage(_c, 0, m);
  cMsg_Y2ng3G8V_sendMessage(_c, 0, m);
  cMsg_5JgHy7ai_sendMessage(_c, 0, m);
  cMsg_sNPgUQZK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mnsDYdLi, 0, m, &cVar_mnsDYdLi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ew5o4KWg, 0, m, &cVar_ew5o4KWg_sendMessage);
  cMsg_ZrgLUHzF_sendMessage(_c, 0, m);
  cMsg_PaPIZLjx_sendMessage(_c, 0, m);
  cMsg_2NSHVnN4_sendMessage(_c, 0, m);
  cMsg_bIaEdykg_sendMessage(_c, 0, m);
  cMsg_6LVRNwDx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QmIkjyOo, 0, m, &cVar_QmIkjyOo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Aubq0qw4, 0, m, &cVar_Aubq0qw4_sendMessage);
  cMsg_12GSOaKy_sendMessage(_c, 0, m);
  cMsg_Oth9GRXm_sendMessage(_c, 0, m);
  cMsg_S2BLM4zb_sendMessage(_c, 0, m);
  cMsg_AVgY8tjF_sendMessage(_c, 0, m);
  cMsg_W6fSWqQA_sendMessage(_c, 0, m);
  cMsg_ESjLjI4q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8RPOPWbf, 0, m, &cVar_8RPOPWbf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1pPDI4cD, 0, m, &cVar_1pPDI4cD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HilTTVMk, 0, m, &cVar_HilTTVMk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Bs1qFXGO, 0, m, &cVar_Bs1qFXGO_sendMessage);
  cMsg_WbUaIZFs_sendMessage(_c, 0, m);
  cSwitchcase_r4MKvULf_onMessage(_c, NULL, 0, m, NULL);
  cMsg_qhsnurn4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bfjrYQig, 0, m, &cVar_bfjrYQig_sendMessage);
  cMsg_wBqdCLkR_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OhETtZ3C, 0, m, &cTabhead_OhETtZ3C_sendMessage);
  cMsg_Sr2yAb1K_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_v4AbJkKd, 0, m, &cVar_v4AbJkKd_sendMessage);
  cMsg_o0UyRx9y_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wPpYvZtI, 0, m, &cTabhead_wPpYvZtI_sendMessage);
  cMsg_WGXSZkhI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ugZC1k5a, 0, m, &cVar_ugZC1k5a_sendMessage);
  cMsg_era1qfhc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3LptR8uW, 0, m, &cTabhead_3LptR8uW_sendMessage);
  cMsg_OSNG26LA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qOLfHs8M, 0, m, &cVar_qOLfHs8M_sendMessage);
  cMsg_Xs1OEevI_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HzoAA5Zg, 0, m, &cTabhead_HzoAA5Zg_sendMessage);
  cMsg_a9PJEENs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_F7BxyhZW, 0, m, &cVar_F7BxyhZW_sendMessage);
  cMsg_fKhapxFv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IPGyyXtZ, 0, m, &cTabhead_IPGyyXtZ_sendMessage);
  cMsg_ISiln9El_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JAVoiuNw, 0, m, &cVar_JAVoiuNw_sendMessage);
  cMsg_XpW7vur6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YCr8qba4, 0, m, &cTabhead_YCr8qba4_sendMessage);
  cMsg_jO3hjnK8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FtSLFjCT, 0, m, &cVar_FtSLFjCT_sendMessage);
  cMsg_9XDYKkKo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_A9nNmf3d, 0, m, &cTabhead_A9nNmf3d_sendMessage);
  cMsg_lQjvEb2z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Cx09uEGP, 0, m, &cVar_Cx09uEGP_sendMessage);
  cMsg_O7wALQAZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_gVYNU4CM, 0, m, &cTabhead_gVYNU4CM_sendMessage);
  cMsg_b2w8c18C_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TfXe9wyE, 0, m, &cVar_TfXe9wyE_sendMessage);
  cMsg_fvUisdR6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_tjCiFHQd, 0, m, &cTabhead_tjCiFHQd_sendMessage);
  cMsg_bHVsO9WV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_drspUFZO, 0, m, &cVar_drspUFZO_sendMessage);
  cMsg_KFglmPdg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IPLmjjI5, 0, m, &cTabhead_IPLmjjI5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pGGQCzXC, 0, m, &cVar_pGGQCzXC_sendMessage);
  cMsg_0d609Fm1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Bz5xCYnV, 0, m, &cVar_Bz5xCYnV_sendMessage);
  cMsg_aQZaRvPX_sendMessage(_c, 0, m);
  cMsg_p6NG9zJp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PYIAUgPj, 0, m, &cVar_PYIAUgPj_sendMessage);
  cMsg_m84AQ9ll_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yDHNe3QP, 0, m, &cTabhead_yDHNe3QP_sendMessage);
  cMsg_3mZA5t0K_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_G1CGkE0p, 0, m, &cVar_G1CGkE0p_sendMessage);
  cMsg_cshRlktW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TiloUlwC, 0, m, &cTabhead_TiloUlwC_sendMessage);
  cMsg_TBgE2est_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_id8JNbCJ, 0, m, &cVar_id8JNbCJ_sendMessage);
  cMsg_LqwtpDWX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_D1u9waqI, 0, m, &cTabhead_D1u9waqI_sendMessage);
  cMsg_6W2ELpj6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1BhP2wXc, 0, m, &cVar_1BhP2wXc_sendMessage);
  cMsg_aCQOnmYm_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bkYjbYhY, 0, m, &cTabhead_bkYjbYhY_sendMessage);
  cMsg_J8pqvqUe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qqNayhTq, 0, m, &cVar_qqNayhTq_sendMessage);
  cMsg_8ZH4N7r5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_NpzO6w9n, 0, m, &cTabhead_NpzO6w9n_sendMessage);
  cMsg_7QSm4x9P_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7PWK4b2c, 0, m, &cVar_7PWK4b2c_sendMessage);
  cMsg_9qI9VSuw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Pyt1uMVH, 0, m, &cTabhead_Pyt1uMVH_sendMessage);
  cMsg_LtR1Rwos_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_feRkohwo, 0, m, &cVar_feRkohwo_sendMessage);
  cMsg_XPyPH0pd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nDd37fCv, 0, m, &cTabhead_nDd37fCv_sendMessage);
  cMsg_kDR9iOsi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qwMi1E7y, 0, m, &cVar_qwMi1E7y_sendMessage);
  cMsg_SIMqWZLa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ItJwIs5I, 0, m, &cTabhead_ItJwIs5I_sendMessage);
  cMsg_c10HUcSF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gJxj81Jt, 0, m, &cVar_gJxj81Jt_sendMessage);
  cMsg_is38xJNd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ICOwZe2j, 0, m, &cTabhead_ICOwZe2j_sendMessage);
  cMsg_N6ytcKhE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wKNcvn0L, 0, m, &cVar_wKNcvn0L_sendMessage);
  cMsg_QyFjgtnu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WXjO9ZQr, 0, m, &cTabhead_WXjO9ZQr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_91yl8Gta, 0, m, &cVar_91yl8Gta_sendMessage);
  cMsg_mdrShoJe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_p3Fea6N1, 0, m, &cVar_p3Fea6N1_sendMessage);
  cMsg_poarQBtb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VzqP7kSv, 0, m, &cVar_VzqP7kSv_sendMessage);
  cMsg_GReGWCvZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DYZvLs8F, 0, m, &cVar_DYZvLs8F_sendMessage);
  cMsg_Yuai6U5G_sendMessage(_c, 0, m);
  cMsg_q7oKi97F_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rQPWw6sS, 0, m, &cVar_rQPWw6sS_sendMessage);
  cMsg_Lnax4NEu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wN9b2bSN, 0, m, &cTabhead_wN9b2bSN_sendMessage);
  cMsg_gIOMDfT7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_r3HVk9z5, 0, m, &cVar_r3HVk9z5_sendMessage);
  cMsg_nzs1psmu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_xOOmjLlF, 0, m, &cTabhead_xOOmjLlF_sendMessage);
  cMsg_OfMcqRk5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8YEXrUri, 0, m, &cVar_8YEXrUri_sendMessage);
  cMsg_1A55a6fy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_w3Fp2vx1, 0, m, &cTabhead_w3Fp2vx1_sendMessage);
  cMsg_jFR1gXlT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bIMKyMWe, 0, m, &cVar_bIMKyMWe_sendMessage);
  cMsg_89I7csyi_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8NzvLAKx, 0, m, &cTabhead_8NzvLAKx_sendMessage);
  cMsg_CMKfaMiI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vDRIuxsO, 0, m, &cVar_vDRIuxsO_sendMessage);
  cMsg_C1dNOCHz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_rVZc4tAx, 0, m, &cTabhead_rVZc4tAx_sendMessage);
}

void Heavy_CircleStrings::cReceive_TUaaSjax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_oztOtzI7, 0, m, &cSlice_oztOtzI7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ygW4IiFR, 0, m, &cSlice_ygW4IiFR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_xzOhFdSU, 0, m, &cSlice_xzOhFdSU_sendMessage);
}

void Heavy_CircleStrings::cReceive_jvkTwu3B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_j949lUAk, 0, m, &cPack_j949lUAk_sendMessage);
}

void Heavy_CircleStrings::cReceive_FVLn8lfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_j949lUAk, 1, m, &cPack_j949lUAk_sendMessage);
}

void Heavy_CircleStrings::cReceive_ZmNTFkml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_zvFm2J64_sendMessage);
}

void Heavy_CircleStrings::cReceive_foVKG66j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_g62rnJFP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UyfLw4BK_sendMessage);
}

void Heavy_CircleStrings::cReceive_NnJajyov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hGYy3EAm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BeU9WGrV_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_5YSfjLBV, 0, m, &cPack_5YSfjLBV_sendMessage);
}

void Heavy_CircleStrings::cReceive_DGV4kCga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_0hbnQ6uH_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_YnlRTBiX, 0, m, &cIf_YnlRTBiX_sendMessage);
}

void Heavy_CircleStrings::cReceive_p9t09Q5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gWNwPjkS, 1, m, &cVar_gWNwPjkS_sendMessage);
}

void Heavy_CircleStrings::cReceive_zJYPv9vR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nXv8FmXU, 0, m, &cVar_nXv8FmXU_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_kOGpQlh2, 0, m, &cPack_kOGpQlh2_sendMessage);
}

void Heavy_CircleStrings::cReceive_UR0PloFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_vCk9epHz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_QqFRsAeG_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_x0MHgz8x, 0, m, &cIf_x0MHgz8x_sendMessage);
}

void Heavy_CircleStrings::cReceive_UYK8y7t5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cReceive_ZCCQa56L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zQJOyXTW_sendMessage);
}

void Heavy_CircleStrings::cReceive_knOAPrx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aI3hFZSr_sendMessage);
}

void Heavy_CircleStrings::cReceive_0Zh0qZMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_muI03Z9H, 0, m, &cVar_muI03Z9H_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iEIT6Yhd, 0, m, &cVar_iEIT6Yhd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sx7bE0As, 0, m, &cVar_sx7bE0As_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KKNniKiX, 0, m, &cVar_KKNniKiX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_zhuzTywH_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_e8mlZLoM, 0, m, &cIf_e8mlZLoM_sendMessage);
}

void Heavy_CircleStrings::cReceive_m0tGDAVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1rqXUaZY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RElm2Xcl, 0, m, &cVar_RElm2Xcl_sendMessage);
}

void Heavy_CircleStrings::cReceive_Icnr8TPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9kg6kSQx, 0, m, &cPack_9kg6kSQx_sendMessage);
}

void Heavy_CircleStrings::cReceive_YkbKmOx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JFvUyX7r, 1, m, &cVar_JFvUyX7r_sendMessage);
}

void Heavy_CircleStrings::cReceive_ZkZHESny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pzCgjnJg, m);
}

void Heavy_CircleStrings::cReceive_jOmxXUcu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_LIvlQVhs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hs27Y2nn, 0, m, &cVar_hs27Y2nn_sendMessage);
}

void Heavy_CircleStrings::cReceive_2uZB8NFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZPTVbEST_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZXgnFGYU, 0, m, &cVar_ZXgnFGYU_sendMessage);
}

void Heavy_CircleStrings::cReceive_mExnN4mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dVG2yshl, 0, m, &cVar_dVG2yshl_sendMessage);
}

void Heavy_CircleStrings::cReceive_7UCtbV99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8ApldTp7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IiLIt9K6_sendMessage);
}

void Heavy_CircleStrings::cReceive_4JdvG5kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uoF0ohFT, 0, m, &cVar_uoF0ohFT_sendMessage);
}

void Heavy_CircleStrings::cReceive_fYquvUnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1xpycOXa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HqEepMzQ_sendMessage);
}

void Heavy_CircleStrings::cReceive_c8QMPVwb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7RG4mTZs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YW3vIOb2, 0, m, &cVar_YW3vIOb2_sendMessage);
}

void Heavy_CircleStrings::cReceive_d0uKRNHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vwaBKhCT, 0, m, &cPack_vwaBKhCT_sendMessage);
}

void Heavy_CircleStrings::cReceive_PkmucRAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_70Q7bjez, 1, m, &cVar_70Q7bjez_sendMessage);
}

void Heavy_CircleStrings::cReceive_Mx9UBL4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_u8l5QpF1, m);
}

void Heavy_CircleStrings::cReceive_skQMsfJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_UqLy6P3z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EMb709YL, 0, m, &cVar_EMb709YL_sendMessage);
}

void Heavy_CircleStrings::cReceive_xbpqAgs5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_T5JosO37_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HaouavX3, 0, m, &cVar_HaouavX3_sendMessage);
}

void Heavy_CircleStrings::cReceive_qdZua97G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MMyM2v2m_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4CU5KJ0O, 0, m, &cVar_4CU5KJ0O_sendMessage);
}

void Heavy_CircleStrings::cReceive_oUizUuqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7UPbZEyv, 0, m, &cPack_7UPbZEyv_sendMessage);
}

void Heavy_CircleStrings::cReceive_6zHqNegb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qR1kBAnt, 1, m, &cVar_qR1kBAnt_sendMessage);
}

void Heavy_CircleStrings::cReceive_W7LqAjxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QKB3RaNY, m);
}

void Heavy_CircleStrings::cReceive_WX5as8MH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6M5uPJ4m_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xARu31Lc, 0, m, &cVar_xARu31Lc_sendMessage);
}

void Heavy_CircleStrings::cReceive_qQf1Sj8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lTH8KwXi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7bKsQ6FI, 0, m, &cVar_7bKsQ6FI_sendMessage);
}

void Heavy_CircleStrings::cReceive_68t2IYqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cKbVkHXM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SVoMTWeq, 0, m, &cVar_SVoMTWeq_sendMessage);
}

void Heavy_CircleStrings::cReceive_XJ6T1u7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nwhd7nVK, 0, m, &cPack_nwhd7nVK_sendMessage);
}

void Heavy_CircleStrings::cReceive_oVtyx6ag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L5CTqsBy, 1, m, &cVar_L5CTqsBy_sendMessage);
}

void Heavy_CircleStrings::cReceive_WX73Qn7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wrUbSciL, m);
}

void Heavy_CircleStrings::cReceive_HSkDjts7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_QSCUnKSR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lWrCeEfM, 0, m, &cVar_lWrCeEfM_sendMessage);
}

void Heavy_CircleStrings::cReceive_4RPCBEA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rGEbazTe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WHuz6Syw, 0, m, &cVar_WHuz6Syw_sendMessage);
}

void Heavy_CircleStrings::cReceive_3ekvhXA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ozNFEFEU, 0, m, &cVar_ozNFEFEU_sendMessage);
}

void Heavy_CircleStrings::cReceive_B20vMJW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3B36KL3I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IuhYx9Ve_sendMessage);
}

void Heavy_CircleStrings::cReceive_ow0WVRnB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_xSlCedvd_sendMessage);
}

void Heavy_CircleStrings::cReceive_tKIQJoSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mmK7GLJ5, 0, m, &cVar_mmK7GLJ5_sendMessage);
}

void Heavy_CircleStrings::cReceive_opvFtmTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dx2MEV1u_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IrG9yXC7_sendMessage);
}

void Heavy_CircleStrings::cReceive_EY8Mu6Z7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_9kN5Sndr_sendMessage);
}

void Heavy_CircleStrings::cReceive_plAmcubq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vyua7Yc2, 0, m, &cVar_vyua7Yc2_sendMessage);
}

void Heavy_CircleStrings::cReceive_Bj3bGHrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_geib8ygD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ej3CSkVG_sendMessage);
}

void Heavy_CircleStrings::cReceive_xzTuggGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QeRwSO4q, 0, m, &cVar_QeRwSO4q_sendMessage);
}

void Heavy_CircleStrings::cReceive_dstYVEvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sl3saqHi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AuLNDnm6_sendMessage);
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
    __hv_tabread_f(&sTabread_JSK4IKt8, VOf(Bf0));
    __hv_varread_f(&sVarf_hehXzPac, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_V9QkXh2V, VOf(Bf0));
    __hv_rpole_f(&sRPole_UwYDMQbB, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_DYSmLFfa, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_VicTFzL3, VOf(Bf0));
    __hv_varread_i(&sVari_fwiR6eR4, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_i(&sVari_fwiR6eR4, VIi(Bi1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_maoto4bW, VIf(Bf3));
    __hv_line_f(&sLine_W66TbSEA, VOf(Bf3));
    __hv_varread_f(&sVarf_pzCgjnJg, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_hGytK1rW, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_bUJ0KEq2, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_o2Vo770j, VOf(Bf0));
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
    __hv_line_f(&sLine_r0pAWIsr, VOf(Bf2));
    __hv_tabread_f(&sTabread_IpnSBpqv, VOf(Bf2));
    __hv_varread_f(&sVarf_F5zuLuDQ, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_0KvrXAaS, VOf(Bf2));
    __hv_rpole_f(&sRPole_rRZ935iv, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_QODljzuj, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_AbMquuSV, VOf(Bf2));
    __hv_varread_i(&sVari_jzjJCKDI, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_i(&sVari_jzjJCKDI, VIi(Bi0));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf5), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_thDVVsNa, VIf(Bf6));
    __hv_line_f(&sLine_DZNhnwOk, VOf(Bf6));
    __hv_varread_f(&sVarf_u8l5QpF1, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_MSkv0IgG, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_n6BDuCJz, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_phasor_k_f(&sPhasor_W6DHDMHs, VOf(Bf2));
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
    __hv_line_f(&sLine_3Albz6Ft, VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_tabread_f(&sTabread_uGZ4KzVj, VOf(Bf1));
    __hv_varread_f(&sVarf_V5rJiyTG, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_v2s8gWUH, VOf(Bf1));
    __hv_rpole_f(&sRPole_36FaZwky, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_MBNyl61Q, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_jZFy9ZEb, VOf(Bf1));
    __hv_varread_i(&sVari_8oAxT5QU, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_i(&sVari_8oAxT5QU, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_AwXOSOOS, VIf(Bf2));
    __hv_line_f(&sLine_Nsluba0W, VOf(Bf2));
    __hv_varread_f(&sVarf_QKB3RaNY, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_bIYsxWWc, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_A0Mqvzya, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_MdzInlKa, VOf(Bf1));
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
    __hv_line_f(&sLine_2vOArhQj, VOf(Bf7));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_CdfGyxk0, VOf(Bf5));
    __hv_varread_f(&sVarf_Ja3r94A4, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_bXbHQR9y, VOf(Bf5));
    __hv_rpole_f(&sRPole_i9lBhpTM, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_3Ugyc5CU, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_wNRRhgUU, VOf(Bf5));
    __hv_varread_i(&sVari_oA6MA27z, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_oA6MA27z, VIi(Bi0));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf7), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_9NtayjcT, VIf(Bf1));
    __hv_line_f(&sLine_AFw14lx8, VOf(Bf1));
    __hv_varread_f(&sVarf_wrUbSciL, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_Yo1naduW, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_RDBwfT6n, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_FXaTQbAM, VOf(Bf5));
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
    __hv_line_f(&sLine_sHaLLgCs, VOf(Bf4));
    __hv_add_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_kHpzps7D, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_oA8UdyFZ, VOf(Bf1));
    __hv_varread_f(&sVarf_yhVHCMdh, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_5nHH891Y, VOf(Bf1));
    __hv_rpole_f(&sRPole_BtZSQn8L, VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_505TfUai, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_C56762ew, VOf(Bf1));
    __hv_varread_i(&sVari_dQA9YIbP, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_i(&sVari_dQA9YIbP, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_LHhSYrvr, VIf(Bf0));
    __hv_line_f(&sLine_9eiuNI4J, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_pGUo3l3A, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_xrnIUr7u, VOf(Bf0));
    __hv_rpole_f(&sRPole_kx9fY67c, VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Jb9Ff3zq, VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_fVxFHmwF, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_XDSWxmry, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf0));
    __hv_line_f(&sLine_4dQbVpWx, VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_Fpyw1Bul, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_vF8jA4oT, VOf(Bf6));
    __hv_varread_f(&sVarf_pRf6uupF, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_MW6AEA72, VOf(Bf3));
    __hv_rpole_f(&sRPole_VLlNANUn, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf3));
    __hv_line_f(&sLine_RSnnUeg9, VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_LdjwLzWr, VOf(Bf3));
    __hv_tabread_f(&sTabread_s9frQrjK, VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf8));
    __hv_tabread_f(&sTabread_UaTcgfZJ, VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf5), VOf(Bf10));
    __hv_tabread_f(&sTabread_bHt6HYwn, VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf11));
    __hv_tabread_f(&sTabread_Yyf3yfZY, VOf(Bf12));
    __hv_add_f(VIf(Bf11), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_9yNExyvS, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_J5xvzRJl, VIf(Bf15));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_h1URavD2, VIf(Bf12));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_7Lft8yI6, VIf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_d4L2GaBr, VIf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_PKgvwBUX, VIf(Bf4));
    __hv_tabwrite_f(&sTabwrite_Wj6AdG4V, VIf(Bf2));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_x09EXuAJ, VOf(Bf13));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_7on1nhss, VOf(Bf6));
    __hv_varread_f(&sVarf_Ry63o3TX, VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_yTULe0gK, VOf(Bf5));
    __hv_rpole_f(&sRPole_GpoHkWPi, VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf6));
    __hv_tabread_f(&sTabread_eNfWaxkU, VOf(Bf5));
    __hv_varread_f(&sVarf_VVnOKafp, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_sQJ8VEya, VOf(Bf8));
    __hv_rpole_f(&sRPole_Ivz0dYXp, VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf5));
    __hv_tabread_f(&sTabread_BTfVSBtQ, VOf(Bf8));
    __hv_varread_f(&sVarf_45mK77DY, VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_acJo6RJ9, VOf(Bf9));
    __hv_rpole_f(&sRPole_FVm3BBn6, VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf8));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_PKySz5yC, VIf(Bf0));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_Xy0HUy0H, VIf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_hefPizER, VIf(Bf8));
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_Y1R9JQ77, VIf(Bf9));
    __hv_line_f(&sLine_MeGrBbyJ, VOf(Bf9));
    __hv_mul_f(VIf(Bf14), VIf(Bf9), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_u9S7JWC0, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_g7lKG4ma, VIf(Bf5));
    __hv_line_f(&sLine_N4B165GY, VOf(Bf9));
    __hv_phasor_f(&sPhasor_2L12jo48, VIf(Bf9), VOf(Bf9));
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
    __hv_line_f(&sLine_FOuZgC9t, VOf(Bf10));
    __hv_line_f(&sLine_WhvUAi9Y, VOf(Bf3));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf3), VOf(Bf11));
    __hv_tabhead_f(&sTabhead_d7yvsakr, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf6), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_OjSCSR0W, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_7rVpbpeH, VOf(Bf11));
    __hv_min_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf6));
    __hv_varread_f(&sVarf_pX6aonFn, VOf(Bf11));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_wvJ9cIQx, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_K2qPC7oE, VIi(Bi1), VOf(Bf11));
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
    __hv_tabhead_f(&sTabhead_P2uCfiAW, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_WaVofjBH, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_xF1lIzpJ, VOf(Bf3));
    __hv_min_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf9));
    __hv_varread_f(&sVarf_Eb7r8I2G, VOf(Bf3));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_J16CaHbV, VIi(Bi0), VOf(Bf16));
    __hv_tabread_if(&sTabread_tpwO3wmW, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf16), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_rlwqUzFu, VOf(Bf11));
    __hv_tabhead_f(&sTabhead_TbmsB1q1, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_t5UdQyCM, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_VrBDfl6D, VOf(Bf11));
    __hv_min_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_dhi2ax7Z, VOf(Bf11));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_TN963iyn, VIi(Bi0), VOf(Bf9));
    __hv_tabread_if(&sTabread_66aBnkDc, VIi(Bi1), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf9));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf9), VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_jKQqvB3L, VOf(Bf17));
    __hv_rpole_f(&sRPole_56yxhRwk, VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_xTm9adan, VIf(Bf17), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_rjchOTv1, VOf(Bf17));
    __hv_mul_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_Pum6MStC, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf11), VOf(Bf17));
    __hv_line_f(&sLine_TWR4wN7V, VOf(Bf9));
    __hv_varread_f(&sVarf_UuFC3M6c, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_wd6gq4RM, VOf(Bf11));
    __hv_rpole_f(&sRPole_Wr8Ci93t, VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_zyInRbYq, VIf(Bf11));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_PeUIbHJS, VOf(Bf17));
    __hv_varread_f(&sVarf_mbwGlwt0, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_NBL5jg2d, VOf(Bf11));
    __hv_min_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_cttibhUr, VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_varread_f(&sVarf_aWWNuf6l, VOf(Bf11));
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
    __hv_cpole_f(&sCPole_siFGCWQQ, VIf(Bf11), VIf(ZERO), VIf(Bf3), VIf(Bf17), VOf(Bf17), VOf(Bf3));
    __hv_varread_f(&sVarf_I4HtKDfe, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_IDfDOAl2, VOf(Bf17));
    __hv_rpole_f(&sRPole_cSwtbMzV, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_640hQgGR, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_B83GtxXR, VOf(Bf17));
    __hv_rpole_f(&sRPole_oetr6OTz, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_yJswFEqk, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_cUZcUXq3, VOf(Bf17));
    __hv_rpole_f(&sRPole_lMQUzRo1, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_u9PkanES, VOf(Bf3));
    __hv_varread_f(&sVarf_H75rthim, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_TyscVM2J, VOf(Bf9));
    __hv_rpole_f(&sRPole_XQyBeZlK, VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf9));
    __hv_line_f(&sLine_N6p4nVym, VOf(Bf11));
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_uebfVKhu, VOf(Bf9));
    __hv_tabread_f(&sTabread_OJZ4H1g2, VOf(Bf5));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf12));
    __hv_tabread_f(&sTabread_cQkiSUwi, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf10));
    __hv_tabread_f(&sTabread_8Nidq2pQ, VOf(Bf6));
    __hv_add_f(VIf(Bf10), VIf(Bf6), VOf(Bf18));
    __hv_tabread_f(&sTabread_WPhyFpth, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf8));
    __hv_tabread_f(&sTabread_Phlx229A, VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_e4MtuBhD, VIf(Bf4));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_oniTGu3h, VIf(Bf15));
    __hv_sub_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_e6ok9I4D, VIf(Bf6));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_p5nKzR9R, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_TneWhgkR, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_XPR4i9p7, VIf(Bf17));
    __hv_add_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_YG5PfQtP, VOf(Bf8));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_noZSmxnG, VOf(Bf3));
    __hv_varread_f(&sVarf_EDUAgIXE, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_u2EAJiQ7, VOf(Bf16));
    __hv_rpole_f(&sRPole_sPlK1kFf, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf0), VIf(Bf8), VOf(Bf3));
    __hv_tabread_f(&sTabread_HweGePPZ, VOf(Bf16));
    __hv_varread_f(&sVarf_75BE69WV, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_qJQ6uhSI, VOf(Bf12));
    __hv_rpole_f(&sRPole_pjagcIN8, VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf9), VOf(Bf16));
    __hv_tabread_f(&sTabread_zv0NvSj1, VOf(Bf12));
    __hv_varread_f(&sVarf_wooYlybz, VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_ZK1L3VRX, VOf(Bf6));
    __hv_rpole_f(&sRPole_6BPIL5Oz, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf12), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf16), VIf(Bf9), VOf(Bf12));
    __hv_add_f(VIf(Bf3), VIf(Bf12), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_uKt61kn1, VIf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf11));
    __hv_sub_f(VIf(Bf16), VIf(Bf9), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_u9SfTECT, VIf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_OPnP2c62, VIf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_THYJzW9h, VIf(Bf6));
    __hv_line_f(&sLine_LA7KpQ16, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf16));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_xIYrVkH7, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_fWWz3GnM, VIf(Bf0));
    __hv_line_f(&sLine_4rSQg1y0, VOf(Bf0));
    __hv_phasor_f(&sPhasor_1xI7Ukfi, VIf(Bf0), VOf(Bf0));
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
    __hv_line_f(&sLine_6AysHDid, VOf(Bf11));
    __hv_line_f(&sLine_RcxqwAGM, VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf11), VIf(Bf2), VOf(Bf3));
    __hv_tabhead_f(&sTabhead_emTROHNu, VOf(Bf9));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_aTGnahLi, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_TFSPRgPI, VOf(Bf3));
    __hv_min_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf8));
    __hv_varread_f(&sVarf_IJ4UWDfs, VOf(Bf3));
    __hv_zero_f(VOf(Bf6));
    __hv_lt_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_6xPqzE1X, VIi(Bi0), VOf(Bf6));
    __hv_tabread_if(&sTabread_GYgyLzej, VIi(Bi1), VOf(Bf3));
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
    __hv_tabhead_f(&sTabhead_tHwFUGAi, VOf(Bf11));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_wVgd2iFq, VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_49JgxUZF, VOf(Bf2));
    __hv_min_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf11));
    __hv_max_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf0));
    __hv_varread_f(&sVarf_U7RJcLxh, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_kXDcDMcF, VIi(Bi0), VOf(Bf10));
    __hv_tabread_if(&sTabread_VSAqjMpt, VIi(Bi1), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf10), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf12), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_NSmbYmM6, VOf(Bf3));
    __hv_tabhead_f(&sTabhead_GzuvpdU8, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_iqLR9ako, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_Rymz08w1, VOf(Bf3));
    __hv_min_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_HUMExlBT, VOf(Bf3));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_aAcnRmjP, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_8tUVx4sf, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf0));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf0), VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_s3EHt4tr, VOf(Bf15));
    __hv_rpole_f(&sRPole_gsiAptgh, VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_saf2yALZ, VIf(Bf15), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_dAS8Zvpc, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_ux9rIswl, VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf15));
    __hv_line_f(&sLine_oL3VrOOc, VOf(Bf0));
    __hv_varread_f(&sVarf_bp2q5nQP, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_ecj6eNGv, VOf(Bf3));
    __hv_rpole_f(&sRPole_5ycQ8Lm8, VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_oFIjphYF, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf14), VIf(Bf3), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_2faw2Ms7, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_lXKOU52A, VOf(Bf1));
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

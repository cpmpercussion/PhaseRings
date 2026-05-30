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
  numBytes += sTabread_init(&sTabread_GYXlYRcm, &hTable_AG33Nc1W, true);
  numBytes += sRPole_init(&sRPole_qtKjBJHy);
  numBytes += sLine_init(&sLine_Pj4QS8W0);
  numBytes += sTabwrite_init(&sTabwrite_vrh8RkrH, &hTable_AG33Nc1W);
  numBytes += sLine_init(&sLine_964ec3Hj);
  numBytes += sLine_init(&sLine_l9fmtAyJ);
  numBytes += sLine_init(&sLine_BHW7nLyY);
  numBytes += sPhasor_k_init(&sPhasor_hZGe92G2, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_w8L8FYXi);
  numBytes += sTabread_init(&sTabread_1aCCkw6G, &hTable_0JR0CnnU, true);
  numBytes += sRPole_init(&sRPole_69cmL7iO);
  numBytes += sLine_init(&sLine_vCCpnqjj);
  numBytes += sTabwrite_init(&sTabwrite_KvpKG1Gm, &hTable_0JR0CnnU);
  numBytes += sLine_init(&sLine_5zbd8vEX);
  numBytes += sLine_init(&sLine_zQg6bCvl);
  numBytes += sLine_init(&sLine_X3VQJ0O6);
  numBytes += sPhasor_k_init(&sPhasor_3EyaiDYY, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_Euvi18F8);
  numBytes += sTabread_init(&sTabread_N5fSY17U, &hTable_pPXD0eHb, true);
  numBytes += sRPole_init(&sRPole_HvBuzrxF);
  numBytes += sLine_init(&sLine_0lBOVxmG);
  numBytes += sTabwrite_init(&sTabwrite_lcGYQI2C, &hTable_pPXD0eHb);
  numBytes += sLine_init(&sLine_cqQWPtnv);
  numBytes += sLine_init(&sLine_ZWduZLcc);
  numBytes += sLine_init(&sLine_jggvrXTT);
  numBytes += sPhasor_k_init(&sPhasor_ekdPoVtd, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_mqYiiRZh);
  numBytes += sTabread_init(&sTabread_W7LYHhEe, &hTable_gd59mUEY, true);
  numBytes += sRPole_init(&sRPole_J4FJZ7Zg);
  numBytes += sLine_init(&sLine_G9y6Bk1z);
  numBytes += sTabwrite_init(&sTabwrite_ciS6I4s5, &hTable_gd59mUEY);
  numBytes += sLine_init(&sLine_vhqu07wb);
  numBytes += sLine_init(&sLine_E1UYqvL7);
  numBytes += sLine_init(&sLine_cvDW0it2);
  numBytes += sPhasor_k_init(&sPhasor_oApnp92K, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_jCzzFIa2);
  numBytes += sLine_init(&sLine_Vhv0DGli);
  numBytes += sTabread_init(&sTabread_vV6XeVsB, &hTable_H2ZqmK2S, true);
  numBytes += sRPole_init(&sRPole_I4Oni5cP);
  numBytes += sLine_init(&sLine_Suu54cO4);
  numBytes += sTabwrite_init(&sTabwrite_Y67LdaFm, &hTable_H2ZqmK2S);
  numBytes += sLine_init(&sLine_6uGgHRhC);
  numBytes += sLine_init(&sLine_yBLxNPSA);
  numBytes += sRPole_init(&sRPole_FR7GFxCN);
  numBytes += sDel1_init(&sDel1_FxrAjuSF);
  numBytes += sLine_init(&sLine_xgyzHgyk);
  numBytes += sLine_init(&sLine_OH37p02E);
  numBytes += sLine_init(&sLine_S9z7G4QB);
  numBytes += sTabread_init(&sTabread_5wzI9Ouq, &hTable_lFgY6udj, true);
  numBytes += sRPole_init(&sRPole_BbMjKCPS);
  numBytes += sLine_init(&sLine_UGi5IRnl);
  numBytes += sLine_init(&sLine_xkMaD7Gw);
  numBytes += sTabread_init(&sTabread_rRDj5oBk, &hTable_ctUYpoNB, true);
  numBytes += sTabread_init(&sTabread_qGZvrzA1, &hTable_Vr4L87pS, true);
  numBytes += sTabread_init(&sTabread_WxIVxT4O, &hTable_fZ5w8oEv, true);
  numBytes += sTabread_init(&sTabread_ML7AvYC4, &hTable_SUZvKEGd, true);
  numBytes += sTabread_init(&sTabread_gPSVfwSP, &hTable_u6Hxx1K6, true);
  numBytes += sTabwrite_init(&sTabwrite_QPJgHarV, &hTable_SM4QXQeF);
  numBytes += sTabwrite_init(&sTabwrite_uCGIefpB, &hTable_u6Hxx1K6);
  numBytes += sTabwrite_init(&sTabwrite_37eaUNFL, &hTable_SUZvKEGd);
  numBytes += sTabwrite_init(&sTabwrite_uz9Jpa5M, &hTable_fZ5w8oEv);
  numBytes += sTabwrite_init(&sTabwrite_dr04uzNw, &hTable_Vr4L87pS);
  numBytes += sTabwrite_init(&sTabwrite_vZOYBlLw, &hTable_ctUYpoNB);
  numBytes += sTabread_init(&sTabread_DDrOibzj, &hTable_SM4QXQeF, true);
  numBytes += sTabread_init(&sTabread_J80Ll0xd, &hTable_P6kA6W4b, true);
  numBytes += sRPole_init(&sRPole_HniYE8nY);
  numBytes += sTabread_init(&sTabread_TIxPr7Di, &hTable_TLpzu4kl, true);
  numBytes += sRPole_init(&sRPole_8e1qhgIW);
  numBytes += sTabread_init(&sTabread_USQh9C7D, &hTable_ZcXVbtE0, true);
  numBytes += sRPole_init(&sRPole_b4JjOZLh);
  numBytes += sTabwrite_init(&sTabwrite_RIPwGPXw, &hTable_lFgY6udj);
  numBytes += sTabwrite_init(&sTabwrite_4hh8ppP2, &hTable_P6kA6W4b);
  numBytes += sTabwrite_init(&sTabwrite_7JNh6oma, &hTable_TLpzu4kl);
  numBytes += sTabwrite_init(&sTabwrite_4Fh1eyl8, &hTable_ZcXVbtE0);
  numBytes += sLine_init(&sLine_cIS5LomB);
  numBytes += sLine_init(&sLine_5ZcapK5C);
  numBytes += sTabwrite_init(&sTabwrite_bzM0tjah, &hTable_MrhoiJQN);
  numBytes += sLine_init(&sLine_v12SfsfY);
  numBytes += sPhasor_init(&sPhasor_eZSZYeSj, sampleRate);
  numBytes += sLine_init(&sLine_LerpTV8g);
  numBytes += sLine_init(&sLine_bo2adHae);
  numBytes += sTabhead_init(&sTabhead_Fg7MAI0b, &hTable_MrhoiJQN);
  numBytes += sTabread_init(&sTabread_Y5TcnGFR, &hTable_MrhoiJQN, false);
  numBytes += sTabread_init(&sTabread_G75a3hd6, &hTable_MrhoiJQN, false);
  numBytes += sTabhead_init(&sTabhead_oxxAcLDQ, &hTable_MrhoiJQN);
  numBytes += sTabread_init(&sTabread_FMAoJnef, &hTable_MrhoiJQN, false);
  numBytes += sTabread_init(&sTabread_qAnwLvTX, &hTable_MrhoiJQN, false);
  numBytes += sTabhead_init(&sTabhead_wC1XvSLf, &hTable_fhgnzNi0);
  numBytes += sTabread_init(&sTabread_x1WnWumW, &hTable_fhgnzNi0, false);
  numBytes += sTabread_init(&sTabread_CiFdjMq7, &hTable_fhgnzNi0, false);
  numBytes += sRPole_init(&sRPole_Z7EOpCWT);
  numBytes += sDel1_init(&sDel1_CwOxysEy);
  numBytes += sLine_init(&sLine_Tf4T9HN7);
  numBytes += sRPole_init(&sRPole_BPycBdHb);
  numBytes += sTabwrite_init(&sTabwrite_unvYRlum, &hTable_fhgnzNi0);
  numBytes += sCPole_init(&sCPole_o6T1B6Fo);
  numBytes += sRPole_init(&sRPole_AQ5bE6Be);
  numBytes += sRPole_init(&sRPole_ewDYnW2L);
  numBytes += sRPole_init(&sRPole_PbpS9CNw);
  numBytes += sTabread_init(&sTabread_EJBvAau9, &hTable_hTWSoF5b, true);
  numBytes += sRPole_init(&sRPole_grzpI5YF);
  numBytes += sLine_init(&sLine_krZgnHvS);
  numBytes += sLine_init(&sLine_mm0zyZRY);
  numBytes += sTabread_init(&sTabread_GQLCq0LD, &hTable_CRvEyM5B, true);
  numBytes += sTabread_init(&sTabread_yMXSZikX, &hTable_9lqzuT7e, true);
  numBytes += sTabread_init(&sTabread_4tLx6s3e, &hTable_Sfmze7cf, true);
  numBytes += sTabread_init(&sTabread_CC1C7bS9, &hTable_EVwlXk0j, true);
  numBytes += sTabread_init(&sTabread_RvsieZMa, &hTable_ruwuNmbR, true);
  numBytes += sTabwrite_init(&sTabwrite_5quX7Z2l, &hTable_wfdQB7fw);
  numBytes += sTabwrite_init(&sTabwrite_m7BKq9Lz, &hTable_ruwuNmbR);
  numBytes += sTabwrite_init(&sTabwrite_pl1PuYP5, &hTable_EVwlXk0j);
  numBytes += sTabwrite_init(&sTabwrite_rgeK7yZK, &hTable_Sfmze7cf);
  numBytes += sTabwrite_init(&sTabwrite_cLldnAlw, &hTable_9lqzuT7e);
  numBytes += sTabwrite_init(&sTabwrite_vzaH69qg, &hTable_CRvEyM5B);
  numBytes += sTabread_init(&sTabread_Z2yN6k4g, &hTable_wfdQB7fw, true);
  numBytes += sTabread_init(&sTabread_l2D07D0n, &hTable_COEgQSwC, true);
  numBytes += sRPole_init(&sRPole_6jWoOgYz);
  numBytes += sTabread_init(&sTabread_v5JWWHtr, &hTable_mCl2Tskq, true);
  numBytes += sRPole_init(&sRPole_IjpnJMkQ);
  numBytes += sTabread_init(&sTabread_gy8b0rpi, &hTable_DrpcdFvR, true);
  numBytes += sRPole_init(&sRPole_30ghtA40);
  numBytes += sTabwrite_init(&sTabwrite_tnrQ1xv0, &hTable_hTWSoF5b);
  numBytes += sTabwrite_init(&sTabwrite_urgLMwdS, &hTable_COEgQSwC);
  numBytes += sTabwrite_init(&sTabwrite_ip1N1KtB, &hTable_mCl2Tskq);
  numBytes += sTabwrite_init(&sTabwrite_BTZrwd7U, &hTable_DrpcdFvR);
  numBytes += sLine_init(&sLine_VjsKZ0ko);
  numBytes += sLine_init(&sLine_PTG8xNxi);
  numBytes += sTabwrite_init(&sTabwrite_7JDZLfHq, &hTable_Lck3uK01);
  numBytes += sLine_init(&sLine_mnnJyNt9);
  numBytes += sPhasor_init(&sPhasor_3IpYVicw, sampleRate);
  numBytes += sLine_init(&sLine_j3HXZ1jf);
  numBytes += sLine_init(&sLine_XQ5Orvf1);
  numBytes += sTabhead_init(&sTabhead_LHG91B4J, &hTable_Lck3uK01);
  numBytes += sTabread_init(&sTabread_VWN0RC4X, &hTable_Lck3uK01, false);
  numBytes += sTabread_init(&sTabread_zM26yptp, &hTable_Lck3uK01, false);
  numBytes += sTabhead_init(&sTabhead_1tCj90Eq, &hTable_Lck3uK01);
  numBytes += sTabread_init(&sTabread_xV6t9t0R, &hTable_Lck3uK01, false);
  numBytes += sTabread_init(&sTabread_kLDiyCA1, &hTable_Lck3uK01, false);
  numBytes += sTabhead_init(&sTabhead_1L9pipPW, &hTable_ABZ5l3v7);
  numBytes += sTabread_init(&sTabread_WVu8eObS, &hTable_ABZ5l3v7, false);
  numBytes += sTabread_init(&sTabread_ehYMeO6w, &hTable_ABZ5l3v7, false);
  numBytes += sRPole_init(&sRPole_6ng4ulmN);
  numBytes += sDel1_init(&sDel1_4gB9hQrn);
  numBytes += sLine_init(&sLine_0OIEmVkv);
  numBytes += sRPole_init(&sRPole_6fqtrnLN);
  numBytes += sTabwrite_init(&sTabwrite_AF0TMShV, &hTable_ABZ5l3v7);
  numBytes += sLine_init(&sLine_cFH7Mude);
  numBytes += sLine_init(&sLine_0jZKEEOX);
  numBytes += cSlice_init(&cSlice_LY3f9PMI, 2, 1);
  numBytes += cSlice_init(&cSlice_uuE4MNpe, 1, 1);
  numBytes += cSlice_init(&cSlice_rocHjDut, 0, 1);
  numBytes += cVar_init_f(&cVar_OcCTe9XT, 0.0f);
  numBytes += cIf_init(&cIf_SVsAqZVb, false);
  numBytes += cIf_init(&cIf_lI059xX7, false);
  numBytes += cIf_init(&cIf_7pJchwav, false);
  numBytes += cIf_init(&cIf_AHXIDYs9, false);
  numBytes += cIf_init(&cIf_tJ7m0OsX, false);
  numBytes += cBinop_init(&cBinop_ulweURXf, 0.0f); // __eq
  numBytes += cTabhead_init(&cTabhead_8iWTsgsC, &hTable_lFgY6udj);
  numBytes += cVar_init_s(&cVar_ItOKZudJ, "del-1011-del1");
  numBytes += cDelay_init(this, &cDelay_XlXndBw0, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_CnppRdeg, 0.0f);
  numBytes += cBinop_init(&cBinop_o8chowuA, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_sFpoqbmd, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_o4RaCYJi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_7VPvpehd, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_uCcmDMEB, &hTable_P6kA6W4b);
  numBytes += cVar_init_s(&cVar_qHIxkDY6, "del-1011-del2");
  numBytes += cDelay_init(this, &cDelay_DT8kLJZD, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_kMwM1hI8, 0.0f);
  numBytes += cBinop_init(&cBinop_fKI4g3Gi, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_y9mSLYTp, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_CRGCl1mN, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_wqsuutXg, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_PC81NOqb, &hTable_TLpzu4kl);
  numBytes += cVar_init_s(&cVar_vc2GdaqP, "del-1011-del3");
  numBytes += cDelay_init(this, &cDelay_Yc156bgZ, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_0oNtmTkT, 0.0f);
  numBytes += cBinop_init(&cBinop_bDrDFXca, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_uALorA04, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Zx8ku5Pi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_2MtBSSg6, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_1VlZJewa, &hTable_ZcXVbtE0);
  numBytes += cVar_init_s(&cVar_WLBevVxy, "del-1011-del4");
  numBytes += cDelay_init(this, &cDelay_HuTPJdv9, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_p9eVasew, 0.0f);
  numBytes += cBinop_init(&cBinop_FnQWYCgl, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_IXV7JTud, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_nUC8HV26, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_hwyAhTxL, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_CsMKacQZ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UUbYsZv6, 0.0f);
  numBytes += hTable_init(&hTable_lFgY6udj, 256);
  numBytes += cDelay_init(this, &cDelay_HP9ZsRuL, 0.0f);
  numBytes += cDelay_init(this, &cDelay_uO7Uj04D, 0.0f);
  numBytes += hTable_init(&hTable_P6kA6W4b, 256);
  numBytes += cDelay_init(this, &cDelay_jyTiyGau, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zUA43mUD, 0.0f);
  numBytes += hTable_init(&hTable_TLpzu4kl, 256);
  numBytes += cDelay_init(this, &cDelay_1cEit97S, 0.0f);
  numBytes += cDelay_init(this, &cDelay_L8fSaoeQ, 0.0f);
  numBytes += hTable_init(&hTable_ZcXVbtE0, 256);
  numBytes += cIf_init(&cIf_A9sUbgiT, false);
  numBytes += cBinop_init(&cBinop_AjotDPvh, 0.0f); // __pow
  numBytes += cPack_init(&cPack_QdIEk6Pf, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_3rjzdrYq, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_xMFd6Umd, 22050.0f);
  numBytes += cBinop_init(&cBinop_VQfctqdd, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_BmZqn46h, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8m6kUpjO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VfzSWenc, 95.0f);
  numBytes += cVar_init_f(&cVar_foddyUI2, 90.0f);
  numBytes += cVar_init_f(&cVar_hdnpOuid, 6000.0f);
  numBytes += cVar_init_f(&cVar_4RwKe4Fe, 60.0f);
  numBytes += cIf_init(&cIf_P3zg6Uio, false);
  numBytes += cTabhead_init(&cTabhead_gIVXQonp, &hTable_SM4QXQeF);
  numBytes += cVar_init_s(&cVar_EziZOGF9, "del-1011-ref6");
  numBytes += cDelay_init(this, &cDelay_gJnQYmEs, 13.645f);
  numBytes += cDelay_init(this, &cDelay_atnZYavH, 0.0f);
  numBytes += cBinop_init(&cBinop_QneGOJaZ, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_qA0QjDd1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_tqqhzgqB, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_N93mpBJp, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ZklSaH43, 0.0f);
  numBytes += cDelay_init(this, &cDelay_tWI8qTSb, 0.0f);
  numBytes += hTable_init(&hTable_SM4QXQeF, 256);
  numBytes += cTabhead_init(&cTabhead_niXRBrpL, &hTable_u6Hxx1K6);
  numBytes += cVar_init_s(&cVar_3qsIGoPK, "del-1011-ref5");
  numBytes += cDelay_init(this, &cDelay_Cvs1TfsM, 16.364f);
  numBytes += cDelay_init(this, &cDelay_0ZPU5AkL, 0.0f);
  numBytes += cBinop_init(&cBinop_rT0zxiSG, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_XMGccKo9, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_r2fZ5r3h, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_G9mhQs8M, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_8MzLN8XH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CI6uHoK3, 0.0f);
  numBytes += hTable_init(&hTable_u6Hxx1K6, 256);
  numBytes += cTabhead_init(&cTabhead_tJpUn0Ui, &hTable_SUZvKEGd);
  numBytes += cVar_init_s(&cVar_0FKAwyID, "del-1011-ref4");
  numBytes += cDelay_init(this, &cDelay_ph5p10w0, 19.392f);
  numBytes += cDelay_init(this, &cDelay_sY3vu1Dy, 0.0f);
  numBytes += cBinop_init(&cBinop_KVMrm8V2, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_6Q8hBtxA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9ahWNTzN, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_8oBiams5, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_tGuxLMk2, 0.0f);
  numBytes += cDelay_init(this, &cDelay_MCtAZlD1, 0.0f);
  numBytes += hTable_init(&hTable_SUZvKEGd, 256);
  numBytes += cTabhead_init(&cTabhead_ahClQidq, &hTable_fZ5w8oEv);
  numBytes += cVar_init_s(&cVar_s0FJfxtI, "del-1011-ref3");
  numBytes += cDelay_init(this, &cDelay_qRtSDF9T, 25.796f);
  numBytes += cDelay_init(this, &cDelay_VMg2Ba3F, 0.0f);
  numBytes += cBinop_init(&cBinop_wAgveC5g, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_aHLCIKsy, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_tPZsoAQs, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_3iGfqqzM, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_TAH5LvHl, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vblUNzP5, 0.0f);
  numBytes += hTable_init(&hTable_fZ5w8oEv, 256);
  numBytes += cTabhead_init(&cTabhead_igCz614T, &hTable_Vr4L87pS);
  numBytes += cVar_init_s(&cVar_8ViM6zyz, "del-1011-ref2");
  numBytes += cDelay_init(this, &cDelay_cEbkewMW, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_P0yu7sHB, 0.0f);
  numBytes += cBinop_init(&cBinop_Efyedv8i, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_vBGBj4DF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_aOdCszXR, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_3Fb4mbld, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_mhZFYoIb, 0.0f);
  numBytes += cDelay_init(this, &cDelay_YVfv9Kn3, 0.0f);
  numBytes += hTable_init(&hTable_Vr4L87pS, 256);
  numBytes += cTabhead_init(&cTabhead_3pxL6LtA, &hTable_ctUYpoNB);
  numBytes += cVar_init_s(&cVar_YeFadlNb, "del-1011-ref1");
  numBytes += cDelay_init(this, &cDelay_AOq2H3Vc, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_mCLqiNoD, 0.0f);
  numBytes += cBinop_init(&cBinop_28W0WgpF, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_gU40wdjm, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_lNTamTY1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_hUULaHQs, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_KK3DNTlh, 0.0f);
  numBytes += cDelay_init(this, &cDelay_afP5Uxk6, 0.0f);
  numBytes += hTable_init(&hTable_ctUYpoNB, 256);
  numBytes += cVar_init_f(&cVar_hUHRGyTy, 0.0f);
  numBytes += cVar_init_f(&cVar_e1OxD7Or, 0.0f);
  numBytes += cPack_init(&cPack_YH09VJnt, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_p5nP1Vsb, 22050.0f);
  numBytes += cBinop_init(&cBinop_PV2MTk9R, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_d10dqNNT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vTIe5vMR, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4zAHoDyb, 22050.0f);
  numBytes += cBinop_init(&cBinop_35pFbTmX, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_g2hPNVDq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_b4TNpUI7, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_e5pvmiNV, 22050.0f);
  numBytes += cBinop_init(&cBinop_97cha1yw, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_s8UdZm21, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mmqL9MSY, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_nI1hM6dO, false);
  numBytes += cDelay_init(this, &cDelay_DWXnXF13, 50.0f);
  numBytes += cVar_init_f(&cVar_9WfADkx4, 0.0f);
  numBytes += cVar_init_f(&cVar_w8oJaENN, 12.0f);
  numBytes += cVar_init_s(&cVar_w2VsFbcN, "floatatom");
  numBytes += cPack_init(&cPack_u9Dd3idu, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_4acrvLYW, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_lWNDLYiQ, "floatatom");
  numBytes += cDelay_init(this, &cDelay_ffwLYDn8, 0.0f);
  numBytes += cDelay_init(this, &cDelay_B1c8Zooj, 0.0f);
  numBytes += hTable_init(&hTable_MrhoiJQN, 256);
  numBytes += cVar_init_s(&cVar_KN5K6XkS, "del-1118-del");
  numBytes += sVarf_init(&sVarf_pCmpeTQ1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0OA4xBf8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_09g6lkS6, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ubSwnGwZ, "del-1118-del");
  numBytes += sVarf_init(&sVarf_OTuclQyF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cBxpEWJD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ad5Jgohh, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_Nu2evNtT, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_qsfQZoTZ, 4720.0f);
  numBytes += cBinop_init(&cBinop_PXqxehlR, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Q3ZbbXIh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_N1aJPsXy, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kVzvChjD, 4720.0f);
  numBytes += cBinop_init(&cBinop_FI020eRN, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_2Sq9vG0p, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4EleNNMn, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_sNT2Yjov, 4720.0f);
  numBytes += cBinop_init(&cBinop_3VjF5LU2, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_zo7qlgpD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ya1pw3Ca, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_c4fBgUqN, 1.0f);
  numBytes += cIf_init(&cIf_CQiF2sk6, false);
  numBytes += sVarf_init(&sVarf_40TbTNja, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6AjpsSlO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sGjm4a1G, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_N1n5CvGJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jb63r1RP, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_DNPChEQS, &hTable_hTWSoF5b);
  numBytes += cVar_init_s(&cVar_2YE88RwP, "del-1181-del1");
  numBytes += cDelay_init(this, &cDelay_AK9vDhUq, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_wEHmn4Hf, 0.0f);
  numBytes += cBinop_init(&cBinop_FJGPJk0p, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_CeQkL94V, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ai1Ac0Xi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_yFNlFPoW, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_g1MpEJ9G, &hTable_COEgQSwC);
  numBytes += cVar_init_s(&cVar_lTy1gy5J, "del-1181-del2");
  numBytes += cDelay_init(this, &cDelay_8W39j2Fd, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_eg4S9P2U, 0.0f);
  numBytes += cBinop_init(&cBinop_QMZ4hwDb, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_Cev1rstu, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cl17xvlf, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Hb1NQpW1, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_5z6vlxjx, &hTable_mCl2Tskq);
  numBytes += cVar_init_s(&cVar_I6cwotqR, "del-1181-del3");
  numBytes += cDelay_init(this, &cDelay_52Rc1E32, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_dZBnQnj9, 0.0f);
  numBytes += cBinop_init(&cBinop_KvSl98vH, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_LqmnWAhc, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_1AOnfvdA, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_10xVHTxJ, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_OdTKQRDD, &hTable_DrpcdFvR);
  numBytes += cVar_init_s(&cVar_11iJBhOP, "del-1181-del4");
  numBytes += cDelay_init(this, &cDelay_pP89vFbX, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_OeKCIhRO, 0.0f);
  numBytes += cBinop_init(&cBinop_1eVGcvXW, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_Isiv2AMa, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NN9BU77s, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_frFHJgtL, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Vp96MMtq, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4FGIwCBf, 0.0f);
  numBytes += hTable_init(&hTable_hTWSoF5b, 256);
  numBytes += cDelay_init(this, &cDelay_94I6yV7L, 0.0f);
  numBytes += cDelay_init(this, &cDelay_SXGb7vJq, 0.0f);
  numBytes += hTable_init(&hTable_COEgQSwC, 256);
  numBytes += cDelay_init(this, &cDelay_KQdAotWJ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TL5Ir6Gl, 0.0f);
  numBytes += hTable_init(&hTable_mCl2Tskq, 256);
  numBytes += cDelay_init(this, &cDelay_4sPu91QU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WSiuzNXa, 0.0f);
  numBytes += hTable_init(&hTable_DrpcdFvR, 256);
  numBytes += cIf_init(&cIf_HjIZsVBe, false);
  numBytes += cBinop_init(&cBinop_fgc1Ix6S, 0.0f); // __pow
  numBytes += cPack_init(&cPack_y24qzzD4, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_RouwySvR, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_jRn8pWdq, 22050.0f);
  numBytes += cBinop_init(&cBinop_MW1jpzf3, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_9Mz48IAi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_viDEo7qO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_f3KbwAXh, 100.0f);
  numBytes += cVar_init_f(&cVar_ILlCWeWz, 95.0f);
  numBytes += cVar_init_f(&cVar_GS2Txx5o, 14400.0f);
  numBytes += cVar_init_f(&cVar_svFC7d6u, 60.0f);
  numBytes += cIf_init(&cIf_vfx1ARau, false);
  numBytes += cTabhead_init(&cTabhead_4YIczY6w, &hTable_wfdQB7fw);
  numBytes += cVar_init_s(&cVar_RgIxsLhs, "del-1181-ref6");
  numBytes += cDelay_init(this, &cDelay_Cum0BQXk, 13.645f);
  numBytes += cDelay_init(this, &cDelay_NZ3p0tME, 0.0f);
  numBytes += cBinop_init(&cBinop_pkaKvpCG, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_6a7cTgj8, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9mViH9Ss, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_lCTFlBPx, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_unFh1kFF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_09mrZMOk, 0.0f);
  numBytes += hTable_init(&hTable_wfdQB7fw, 256);
  numBytes += cTabhead_init(&cTabhead_4zLK3R6B, &hTable_ruwuNmbR);
  numBytes += cVar_init_s(&cVar_QpjsCjK5, "del-1181-ref5");
  numBytes += cDelay_init(this, &cDelay_3V3i8DQQ, 16.364f);
  numBytes += cDelay_init(this, &cDelay_cFNpl819, 0.0f);
  numBytes += cBinop_init(&cBinop_cewLunxt, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_jxSDnTx4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_l2AM6Zl7, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_iEbdzmdq, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_RHkBDHuY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_KqTqcmpp, 0.0f);
  numBytes += hTable_init(&hTable_ruwuNmbR, 256);
  numBytes += cTabhead_init(&cTabhead_TRZ2wRZx, &hTable_EVwlXk0j);
  numBytes += cVar_init_s(&cVar_JKvsrGUU, "del-1181-ref4");
  numBytes += cDelay_init(this, &cDelay_pD1H74Zc, 19.392f);
  numBytes += cDelay_init(this, &cDelay_Li0To2E6, 0.0f);
  numBytes += cBinop_init(&cBinop_ICqsNSnP, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_LYLmpZxm, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ZGENqCUk, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NIlHaJGs, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_7carcQBO, 0.0f);
  numBytes += cDelay_init(this, &cDelay_pTinuFAb, 0.0f);
  numBytes += hTable_init(&hTable_EVwlXk0j, 256);
  numBytes += cTabhead_init(&cTabhead_OUdihqpP, &hTable_Sfmze7cf);
  numBytes += cVar_init_s(&cVar_pEYKoDcr, "del-1181-ref3");
  numBytes += cDelay_init(this, &cDelay_5LASUPPY, 25.796f);
  numBytes += cDelay_init(this, &cDelay_wN2rGhkN, 0.0f);
  numBytes += cBinop_init(&cBinop_oZIlZtRB, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_el8bDd5R, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_lY0YGjB3, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_50t5QWjy, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_9gN7WDoE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kV1D7jPp, 0.0f);
  numBytes += hTable_init(&hTable_Sfmze7cf, 256);
  numBytes += cTabhead_init(&cTabhead_B55Qe9Eb, &hTable_9lqzuT7e);
  numBytes += cVar_init_s(&cVar_74zal9Yw, "del-1181-ref2");
  numBytes += cDelay_init(this, &cDelay_wTZJq7CT, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_M9OGY3hL, 0.0f);
  numBytes += cBinop_init(&cBinop_Pd9VS8qX, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_k8ftE8CS, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Xq7xJwnW, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_GkG9ZCdO, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_9fbdMlK2, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1iVLPiYu, 0.0f);
  numBytes += hTable_init(&hTable_9lqzuT7e, 256);
  numBytes += cTabhead_init(&cTabhead_bnmehkil, &hTable_CRvEyM5B);
  numBytes += cVar_init_s(&cVar_YQxs3hBC, "del-1181-ref1");
  numBytes += cDelay_init(this, &cDelay_zwep5mwK, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_LVnWlTJF, 0.0f);
  numBytes += cBinop_init(&cBinop_9fZT930l, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_0pqbSOsQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_SZiW92Xy, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_5cmCn9aQ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_UN4gSh1U, 0.0f);
  numBytes += cDelay_init(this, &cDelay_QpQig58n, 0.0f);
  numBytes += hTable_init(&hTable_CRvEyM5B, 256);
  numBytes += cVar_init_f(&cVar_bC8I2zA7, 0.0f);
  numBytes += cVar_init_f(&cVar_kodk0uv4, 0.0f);
  numBytes += cPack_init(&cPack_EvJAzXQ5, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_Wi1q81Cr, 22050.0f);
  numBytes += cBinop_init(&cBinop_gMFauTHM, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_FThq7u62, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HclWugYq, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_TVHb62C3, 22050.0f);
  numBytes += cBinop_init(&cBinop_tKjxhwBE, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_brOFQHvC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mP9b6bqJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_WOt6tR1Q, 22050.0f);
  numBytes += cBinop_init(&cBinop_RgpaPNVS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Oza60i9N, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ekxgst84, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_el6yAg9k, "del-1280-del1");
  numBytes += sVarf_init(&sVarf_IbD0B43N, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GbJH217E, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QCyPaNwg, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mjI5T66C, 10000.0f);
  numBytes += cBinop_init(&cBinop_khYJpEtE, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_nuJFmSvc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZqUayoeQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Bp4zUvhW, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_67Lojftk, 10.0f);
  numBytes += cBinop_init(&cBinop_zB21165B, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_2LWAfMYm, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_w4ds3ML9, "floatatom");
  numBytes += sVarf_init(&sVarf_FM4REvIk, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_9Jo58TpW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Iqbl3FIK, 0.0f);
  numBytes += hTable_init(&hTable_fhgnzNi0, 256);
  numBytes += sVarf_init(&sVarf_RrENqtYY, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_hCok8V62, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_bqZLNVMS, 600785145);
  numBytes += cSlice_init(&cSlice_OvDVt5hn, 1, 1);
  numBytes += cRandom_init(&cRandom_ZxUNNBbx, -534323148);
  numBytes += cSlice_init(&cSlice_2etwRpfB, 1, 1);
  numBytes += cVar_init_s(&cVar_kiePaLYJ, "floatatom");
  numBytes += cPack_init(&cPack_6EVh9KuK, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_zIKPpQNg, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_Ii9cWaJD, "floatatom");
  numBytes += cDelay_init(this, &cDelay_qSkcK69S, 0.0f);
  numBytes += cDelay_init(this, &cDelay_f7cz8D93, 0.0f);
  numBytes += hTable_init(&hTable_Lck3uK01, 256);
  numBytes += cVar_init_s(&cVar_QYjbEVes, "del-1311-del");
  numBytes += sVarf_init(&sVarf_JmbYI3q5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lhzz1dz7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_so1RV3cw, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_j1XlI59V, "del-1311-del");
  numBytes += sVarf_init(&sVarf_nHhJzQBE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MAlaLCPo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_z1F6TqrN, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_heCPxf59, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_vO2JddHY, "del-1340-del1");
  numBytes += sVarf_init(&sVarf_J1BCJR0D, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hotVM8YE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_H39jlROv, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ZjhXHiok, 10000.0f);
  numBytes += cBinop_init(&cBinop_LPZ6ZvsM, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_c3hjuZuw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eFHEnv6b, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9gj4DHD9, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Y60I3yiR, 10.0f);
  numBytes += cBinop_init(&cBinop_A72SBX04, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_RDs9J6VZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_DEoxQB6v, "floatatom");
  numBytes += sVarf_init(&sVarf_9B9Ou6MK, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_P1zgzLS3, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OIMNYAwL, 0.0f);
  numBytes += hTable_init(&hTable_ABZ5l3v7, 256);
  numBytes += sVarf_init(&sVarf_5vWGMIw3, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_qBDVf7gD, "floatatom");
  numBytes += cDelay_init(this, &cDelay_NBtUcIfQ, 0.0f);
  numBytes += cVar_init_f(&cVar_HPJ7bT7r, 20.0f);
  numBytes += cBinop_init(&cBinop_z89iZ4K8, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_rwbz0puP, 0.0f);
  numBytes += cSlice_init(&cSlice_ohHWeI9F, 1, -1);
  numBytes += cSlice_init(&cSlice_elAjwJm3, 1, -1);
  numBytes += cVar_init_f(&cVar_nLpv6Vbk, 0.0f);
  numBytes += cVar_init_f(&cVar_vHaQPU7n, 20.0f);
  numBytes += cVar_init_f(&cVar_jCWndMnn, 0.0f);
  numBytes += cVar_init_f(&cVar_LIx9aVyy, 0.0f);
  numBytes += cVar_init_f(&cVar_BOcCzIhO, 0.0f);
  numBytes += cSlice_init(&cSlice_fpMZzzjQ, 1, 1);
  numBytes += cSlice_init(&cSlice_NSw7YvFs, 0, 1);
  numBytes += cBinop_init(&cBinop_bxRkoYNQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_aoe2aMgZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HwcOuPV2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_E02W9zeN, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_6c2V1l54, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_jNxooIL2, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_lV1TafU4, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_pqPgl29g, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_U1EeHDQs, "floatatom");
  numBytes += cPack_init(&cPack_zpKpeqG9, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_wfT2BpKU, 0.0f);
  numBytes += cVar_init_f(&cVar_G3SB9YNs, 20.0f);
  numBytes += cBinop_init(&cBinop_Bl3rIzEJ, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_KM2E0mOL, 0.0f);
  numBytes += cSlice_init(&cSlice_GmaqwSWF, 1, -1);
  numBytes += cSlice_init(&cSlice_lM2PfTOH, 1, -1);
  numBytes += cVar_init_f(&cVar_v3A6MYgN, 0.0f);
  numBytes += cVar_init_f(&cVar_Wng5FOpP, 20.0f);
  numBytes += cVar_init_f(&cVar_3NltcsXK, 0.0f);
  numBytes += cVar_init_f(&cVar_Rx0wagHI, 0.0f);
  numBytes += cVar_init_f(&cVar_Ft4SIHUq, 0.0f);
  numBytes += cSlice_init(&cSlice_LiWQk285, 1, 1);
  numBytes += cSlice_init(&cSlice_0Ox2CErJ, 0, 1);
  numBytes += cBinop_init(&cBinop_E2BbVhON, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9t1P1nri, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_AWkYnKjM, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_GK1yIq8E, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_3nIzqW90, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_mWYDyA03, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_cpD3aeit, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_36Gj8aGr, 0.0f); // __sub
  numBytes += cPack_init(&cPack_WFr5NKHE, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_zthvGC3f, 2, 0.0f, 1000.0f);
  numBytes += sVarf_init(&sVarf_bUZWOmbv, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YANBlYTm, 5.0f);
  numBytes += cBinop_init(&cBinop_jT6ibkLq, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_6FNy6t81, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_T6QfnJgn, "floatatom");
  numBytes += cIf_init(&cIf_rddh4osX, false);
  numBytes += cIf_init(&cIf_lr2bWN5q, false);
  numBytes += cIf_init(&cIf_3zLUoZmp, false);
  numBytes += cIf_init(&cIf_L54Fe0XB, false);
  numBytes += cRandom_init(&cRandom_MyfIbL8m, -612489035);
  numBytes += cSlice_init(&cSlice_H5queybS, 1, 1);
  numBytes += sVari_init(&sVari_a5h7BKRR, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_m99Kv6c6, &hTable_H2ZqmK2S);
  numBytes += cVar_init_s(&cVar_zdSa9Ytr, "del-1418-delay");
  numBytes += cDelay_init(this, &cDelay_l8Zb45YC, 12.0f);
  numBytes += cDelay_init(this, &cDelay_lSbXo8kT, 0.0f);
  numBytes += cBinop_init(&cBinop_x3gmPT3J, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_DAtPUvjC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_c4FHUhiQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_qYKLlnyO, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BZGNNKYG, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_rTV0cnf9, "floatatom");
  numBytes += cDelay_init(this, &cDelay_tapd5va6, 5.0f);
  numBytes += cVar_init_f(&cVar_HmaC2b4o, 3800.0f);
  numBytes += cBinop_init(&cBinop_m0yizbzM, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hSUK4UMu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IRrweIw6, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_A0uMea6k, 0.0f);
  numBytes += cDelay_init(this, &cDelay_RLFAUdbz, 0.0f);
  numBytes += hTable_init(&hTable_H2ZqmK2S, 256);
  numBytes += cBinop_init(&cBinop_C7l83JGc, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_NUFMr1zH, 0.999f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Qk5wgHIG, 1.0f);
  numBytes += cDelay_init(this, &cDelay_mfNbgjsw, 0.0f);
  numBytes += cVar_init_f(&cVar_eQGzO0WU, 2000.0f);
  numBytes += cBinop_init(&cBinop_2507H0fe, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_G7kPt8UZ, 60.0f);
  numBytes += cRandom_init(&cRandom_64wA5T5W, -754019797);
  numBytes += cSlice_init(&cSlice_mxYYtN18, 1, 1);
  numBytes += cVar_init_f(&cVar_H60UPPGG, 0.0f);
  numBytes += cIf_init(&cIf_GbQb6zob, false);
  numBytes += cIf_init(&cIf_3qy7sCg9, false);
  numBytes += cIf_init(&cIf_CVNk8DoK, false);
  numBytes += cIf_init(&cIf_yveNhkrF, false);
  numBytes += cPack_init(&cPack_QJ7s57YO, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_QxHT9LxP, 2, 0.0f, 80.0f);
  numBytes += cVar_init_s(&cVar_3gYG4Lu7, "floatatom");
  numBytes += cRandom_init(&cRandom_FwtxF8MZ, 2140725749);
  numBytes += cSlice_init(&cSlice_oVOCePRd, 1, 1);
  numBytes += cVar_init_s(&cVar_ndtHWPwh, "floatatom");
  numBytes += cVar_init_f(&cVar_6JdDI1vD, 1.0f);
  numBytes += cVar_init_f(&cVar_NTwA4EOa, 0.0f);
  numBytes += cVar_init_f(&cVar_jPyGA2sY, 0.0f);
  numBytes += cRandom_init(&cRandom_hKFncde8, -89275432);
  numBytes += cSlice_init(&cSlice_ZHBjo0O9, 1, 1);
  numBytes += cRandom_init(&cRandom_tTcu2TaK, 1118675815);
  numBytes += cSlice_init(&cSlice_qsAuLOag, 1, 1);
  numBytes += cRandom_init(&cRandom_MHqymPpo, -1792287903);
  numBytes += cSlice_init(&cSlice_2n1wWTGw, 1, 1);
  numBytes += cBinop_init(&cBinop_OWhBA4MI, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_Km6t7NKj, 1054631906);
  numBytes += cSlice_init(&cSlice_fphTKkLP, 1, 1);
  numBytes += cPack_init(&cPack_B4OSk6Bi, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_Vlr0LmHj, "floatatom");
  numBytes += cVar_init_s(&cVar_eNZp7z3M, "floatatom");
  numBytes += cVar_init_f(&cVar_vL4ksuZB, 0.0f);
  numBytes += cVar_init_s(&cVar_5Mq56m6C, "floatatom");
  numBytes += cVar_init_s(&cVar_2r4etoyn, "floatatom");
  numBytes += cVar_init_s(&cVar_2SBSiAIp, "floatatom");
  numBytes += cDelay_init(this, &cDelay_1BrC8OKv, 25.0f);
  numBytes += cVar_init_f(&cVar_YpEFFqUn, 0.0f);
  numBytes += sVarf_init(&sVarf_5EWhrGDY, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_HS8OObJA, -1999742341);
  numBytes += cSlice_init(&cSlice_D0tUm4sJ, 1, 1);
  numBytes += sVari_init(&sVari_86awwOFU, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_L6l0vtmE, &hTable_AG33Nc1W);
  numBytes += cVar_init_s(&cVar_moFhwctb, "del-1497-delay");
  numBytes += cDelay_init(this, &cDelay_EIrnOnk1, 12.0f);
  numBytes += cDelay_init(this, &cDelay_arErv4vd, 0.0f);
  numBytes += cBinop_init(&cBinop_qYMzRDD0, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_CKGBlLQo, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_HtoEPK5J, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_nkxX6Ikf, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ZQGbLzrV, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_SvRFj9NO, "floatatom");
  numBytes += cDelay_init(this, &cDelay_6sFVeQUc, 5.0f);
  numBytes += cVar_init_f(&cVar_zoXTuhOu, 3800.0f);
  numBytes += cBinop_init(&cBinop_Lz10Mxf7, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_TokwBxRx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZHYUlze1, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_a5BJR1MF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_IFu76mCM, 0.0f);
  numBytes += hTable_init(&hTable_AG33Nc1W, 256);
  numBytes += cBinop_init(&cBinop_SQf3MLnv, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_kT2b3zGO, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_j9AErNuL, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_e7S6G6mQ, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_DNi3mEdl, 1, 1);
  numBytes += cSlice_init(&cSlice_CxhP4gwK, 0, 1);
  numBytes += cBinop_init(&cBinop_Q1c8fD6M, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_mZAIGs13, 98.0f);
  numBytes += cIf_init(&cIf_kznQKbup, false);
  numBytes += cBinop_init(&cBinop_Wz4b4wg1, 0.0f); // __pow
  numBytes += cPack_init(&cPack_LLSvipAK, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_Vngma2UP, 0.0f);
  numBytes += cVar_init_f(&cVar_VH5XJ4Pi, 98.0f);
  numBytes += cIf_init(&cIf_IMU4fKg8, false);
  numBytes += cBinop_init(&cBinop_9EVsgGCe, 0.0f); // __pow
  numBytes += cPack_init(&cPack_QG75d8Kc, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_Na1HGBpl, 0.0f);
  numBytes += cRandom_init(&cRandom_SHjTfHio, 265475190);
  numBytes += cSlice_init(&cSlice_pUYHO3Ap, 1, 1);
  numBytes += cBinop_init(&cBinop_2XkvzzZK, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_adWwT3mK, -2113137317);
  numBytes += cSlice_init(&cSlice_y1wRNRDN, 1, 1);
  numBytes += cPack_init(&cPack_XXwv7GDb, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_ZkTyOhq6, "floatatom");
  numBytes += cVar_init_s(&cVar_LzAbDq2B, "floatatom");
  numBytes += cVar_init_f(&cVar_XCDt9fiR, 0.0f);
  numBytes += cVar_init_s(&cVar_P4hoSHQL, "floatatom");
  numBytes += cVar_init_s(&cVar_sbfhSN5v, "floatatom");
  numBytes += cVar_init_s(&cVar_HMxCN95O, "floatatom");
  numBytes += cDelay_init(this, &cDelay_MBoOUoYc, 25.0f);
  numBytes += cVar_init_f(&cVar_iKmE3Hbg, 0.0f);
  numBytes += sVarf_init(&sVarf_JGHsOizA, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_BUVlQ14G, 1381034957);
  numBytes += cSlice_init(&cSlice_yqPdIBEr, 1, 1);
  numBytes += sVari_init(&sVari_s4GXElM2, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_3Ry4iUeT, &hTable_0JR0CnnU);
  numBytes += cVar_init_s(&cVar_2yX8b2SI, "del-1564-delay");
  numBytes += cDelay_init(this, &cDelay_rMYRqUCE, 12.0f);
  numBytes += cDelay_init(this, &cDelay_BKn7Rwl5, 0.0f);
  numBytes += cBinop_init(&cBinop_DlwQAemn, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_fW7D2eSQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BV38kTlv, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Cl1ExGCt, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Wccnz9kr, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_VcG7V7jh, "floatatom");
  numBytes += cDelay_init(this, &cDelay_C6VSmyqh, 5.0f);
  numBytes += cVar_init_f(&cVar_aeL9JXfQ, 3800.0f);
  numBytes += cBinop_init(&cBinop_GsUwJ2yW, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_VJzAFhB9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IM1d81Zv, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_6QJiBLol, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iSjzkI8p, 0.0f);
  numBytes += hTable_init(&hTable_0JR0CnnU, 256);
  numBytes += cBinop_init(&cBinop_sNcoUjfr, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_vFX25tA7, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_IiqL7wlu, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_tI4J4088, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_3BFnNE9Q, 1, 1);
  numBytes += cSlice_init(&cSlice_sR83pIAp, 0, 1);
  numBytes += cBinop_init(&cBinop_jLrpx2dW, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_NoTJM03w, -903407888);
  numBytes += cSlice_init(&cSlice_4aq2q8Yg, 1, 1);
  numBytes += cBinop_init(&cBinop_EJpyK6Wq, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_7CHCGHH9, -1542452558);
  numBytes += cSlice_init(&cSlice_0Qy3gyDT, 1, 1);
  numBytes += cPack_init(&cPack_3CrlaE0w, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_g5xTJrD1, "floatatom");
  numBytes += cVar_init_s(&cVar_A3RkeXKq, "floatatom");
  numBytes += cVar_init_f(&cVar_ezduzPWL, 0.0f);
  numBytes += cVar_init_s(&cVar_fwZmkAh3, "floatatom");
  numBytes += cVar_init_s(&cVar_aRmGFL5E, "floatatom");
  numBytes += cVar_init_s(&cVar_3OM1AKjv, "floatatom");
  numBytes += cDelay_init(this, &cDelay_1LR0uTQk, 25.0f);
  numBytes += cVar_init_f(&cVar_N1d8i0o1, 0.0f);
  numBytes += sVarf_init(&sVarf_fulbbcJz, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_4BNJCCOM, 428486128);
  numBytes += cSlice_init(&cSlice_m8BCeyw0, 1, 1);
  numBytes += sVari_init(&sVari_P0KwOnwe, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_Na6R33QA, &hTable_pPXD0eHb);
  numBytes += cVar_init_s(&cVar_uh4L2ung, "del-1615-delay");
  numBytes += cDelay_init(this, &cDelay_9mk6gQPb, 12.0f);
  numBytes += cDelay_init(this, &cDelay_Hylt5tNo, 0.0f);
  numBytes += cBinop_init(&cBinop_2QXHpTQQ, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_ypOoxgmt, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_PG2MlhF9, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_xZMAjOfS, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_yEHzl3nj, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_OJucAKYs, "floatatom");
  numBytes += cDelay_init(this, &cDelay_LFpm4xOG, 5.0f);
  numBytes += cVar_init_f(&cVar_fHuTs3vg, 3800.0f);
  numBytes += cBinop_init(&cBinop_SJ06ojst, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wFdXt49n, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BE6Uws89, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_52X6l21J, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OWQW318v, 0.0f);
  numBytes += hTable_init(&hTable_pPXD0eHb, 256);
  numBytes += cBinop_init(&cBinop_3jW0W2DO, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_XaJi2hat, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_1Jt11iTs, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_BlPYpO87, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_zGkZsTus, 1, 1);
  numBytes += cSlice_init(&cSlice_AVb4qfw3, 0, 1);
  numBytes += cBinop_init(&cBinop_wAgExA8f, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_Dv5Q1At7, 2102621729);
  numBytes += cSlice_init(&cSlice_8OtsqTSr, 1, 1);
  numBytes += cBinop_init(&cBinop_cVGoa8YS, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_adNdPHvh, 1657592168);
  numBytes += cSlice_init(&cSlice_s2yEDok7, 1, 1);
  numBytes += cPack_init(&cPack_8ESaVNdy, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_25o5ZdWn, "floatatom");
  numBytes += cVar_init_s(&cVar_kvuXtFqg, "floatatom");
  numBytes += cVar_init_f(&cVar_lD4uuGr5, 0.0f);
  numBytes += cVar_init_s(&cVar_Kk9SmMbq, "floatatom");
  numBytes += cVar_init_s(&cVar_hzUb5fCZ, "floatatom");
  numBytes += cVar_init_s(&cVar_K1KQ4OwV, "floatatom");
  numBytes += cDelay_init(this, &cDelay_B2FsxtFu, 25.0f);
  numBytes += cVar_init_f(&cVar_mxGEmfbK, 0.0f);
  numBytes += sVarf_init(&sVarf_GbVnLugv, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_NvKKTQ4I, -428601266);
  numBytes += cSlice_init(&cSlice_ryaxyvoE, 1, 1);
  numBytes += sVari_init(&sVari_B3LqpK8Z, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_JnJhxyt3, &hTable_gd59mUEY);
  numBytes += cVar_init_s(&cVar_Da34SNGd, "del-1666-delay");
  numBytes += cDelay_init(this, &cDelay_sLKCjTbG, 12.0f);
  numBytes += cDelay_init(this, &cDelay_FgyCcqV7, 0.0f);
  numBytes += cBinop_init(&cBinop_qwGXZAzh, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_kaY5vEIk, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fvYpuf9y, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0qIumF31, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_GkVh6ZHd, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_W1BNX4au, "floatatom");
  numBytes += cDelay_init(this, &cDelay_EXwFVcC4, 5.0f);
  numBytes += cVar_init_f(&cVar_FrZebKWY, 3800.0f);
  numBytes += cBinop_init(&cBinop_dOwqSVqD, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_pinR2d10, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Tqm2CRXI, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_Af8KGCUW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OkSduMyy, 0.0f);
  numBytes += hTable_init(&hTable_gd59mUEY, 256);
  numBytes += cBinop_init(&cBinop_q5pAjV6j, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_jEe7pjPw, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_sT2nExBM, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_oaaMHZ2v, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_MqeQdi4A, 1, 1);
  numBytes += cSlice_init(&cSlice_613QnGjQ, 0, 1);
  numBytes += cBinop_init(&cBinop_GWmSCsAJ, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_Qk1Btk43, 100.0f);
  numBytes += cIf_init(&cIf_5CvhPinc, false);
  numBytes += cBinop_init(&cBinop_hun4ErkT, 0.0f); // __pow
  numBytes += cPack_init(&cPack_v4Enanaz, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_iv0lqcFe, 0.0f);
  numBytes += cVar_init_f(&cVar_NCZKq1p0, 100.0f);
  numBytes += cIf_init(&cIf_TfqB6Zk2, false);
  numBytes += cBinop_init(&cBinop_qGj2c85k, 0.0f); // __pow
  numBytes += cPack_init(&cPack_vaJLk8ah, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_RoCiCtFT, 0.0f);
  numBytes += cVar_init_f(&cVar_WYgicqGp, 98.0f);
  numBytes += cIf_init(&cIf_uSDnXr4R, false);
  numBytes += cBinop_init(&cBinop_lqHxDAX5, 0.0f); // __pow
  numBytes += cPack_init(&cPack_TJnjVF3M, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_fCLCkWHM, 0.0f);
  numBytes += cIf_init(&cIf_X7h5BQZ2, false);
  numBytes += cIf_init(&cIf_EK064cfR, false);
  numBytes += cVar_init_f(&cVar_rLWDtpno, 89.0f);
  numBytes += cIf_init(&cIf_sq8eS9Yo, false);
  numBytes += cBinop_init(&cBinop_4EbAuJcL, 0.0f); // __pow
  numBytes += cPack_init(&cPack_hTaUVW9A, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_9pVj4ORn, 0.0f);
  numBytes += cPack_init(&cPack_maV9bBvI, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_CwDdWYOH, 1, 1);
  numBytes += cSlice_init(&cSlice_Cti7Q8DI, 0, 1);
  numBytes += cIf_init(&cIf_hRKl9kiv, false);
  numBytes += cIf_init(&cIf_uWjh2lVo, false);
  numBytes += cIf_init(&cIf_xRhCnpD6, false);
  numBytes += cSlice_init(&cSlice_BpxrWBs9, 1, 1);
  numBytes += cSlice_init(&cSlice_HcCAXWiK, 0, 1);
  numBytes += cVar_init_f(&cVar_IZbjxrZs, 0.0f);
  numBytes += cIf_init(&cIf_n9cFTIGx, false);
  numBytes += cPack_init(&cPack_qu54pwU9, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_S43m9Zrx, 1, -1);
  numBytes += cSlice_init(&cSlice_dh1O0Sih, 1, -1);
  numBytes += cSlice_init(&cSlice_Mv7P9nxj, 1, -1);
  numBytes += cSlice_init(&cSlice_ejn07aSq, 1, -1);
  numBytes += cIf_init(&cIf_He3QGBV6, false);
  numBytes += cVar_init_f(&cVar_ydZug0AI, 1.0f);
  numBytes += cPack_init(&cPack_FBz81L0q, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_zUSzJZek, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_CircleStrings::~Heavy_CircleStrings() {
  hTable_free(&hTable_lFgY6udj);
  hTable_free(&hTable_P6kA6W4b);
  hTable_free(&hTable_TLpzu4kl);
  hTable_free(&hTable_ZcXVbtE0);
  cPack_free(&cPack_QdIEk6Pf);
  cPack_free(&cPack_3rjzdrYq);
  hTable_free(&hTable_SM4QXQeF);
  hTable_free(&hTable_u6Hxx1K6);
  hTable_free(&hTable_SUZvKEGd);
  hTable_free(&hTable_fZ5w8oEv);
  hTable_free(&hTable_Vr4L87pS);
  hTable_free(&hTable_ctUYpoNB);
  cPack_free(&cPack_YH09VJnt);
  cPack_free(&cPack_u9Dd3idu);
  cPack_free(&cPack_4acrvLYW);
  hTable_free(&hTable_MrhoiJQN);
  hTable_free(&hTable_hTWSoF5b);
  hTable_free(&hTable_COEgQSwC);
  hTable_free(&hTable_mCl2Tskq);
  hTable_free(&hTable_DrpcdFvR);
  cPack_free(&cPack_y24qzzD4);
  cPack_free(&cPack_RouwySvR);
  hTable_free(&hTable_wfdQB7fw);
  hTable_free(&hTable_ruwuNmbR);
  hTable_free(&hTable_EVwlXk0j);
  hTable_free(&hTable_Sfmze7cf);
  hTable_free(&hTable_9lqzuT7e);
  hTable_free(&hTable_CRvEyM5B);
  cPack_free(&cPack_EvJAzXQ5);
  hTable_free(&hTable_fhgnzNi0);
  cPack_free(&cPack_hCok8V62);
  cPack_free(&cPack_6EVh9KuK);
  cPack_free(&cPack_zIKPpQNg);
  hTable_free(&hTable_Lck3uK01);
  hTable_free(&hTable_ABZ5l3v7);
  cPack_free(&cPack_zpKpeqG9);
  cPack_free(&cPack_WFr5NKHE);
  cPack_free(&cPack_zthvGC3f);
  hTable_free(&hTable_H2ZqmK2S);
  cPack_free(&cPack_QJ7s57YO);
  cPack_free(&cPack_QxHT9LxP);
  cPack_free(&cPack_B4OSk6Bi);
  hTable_free(&hTable_AG33Nc1W);
  cPack_free(&cPack_j9AErNuL);
  cPack_free(&cPack_e7S6G6mQ);
  cPack_free(&cPack_LLSvipAK);
  cPack_free(&cPack_QG75d8Kc);
  cPack_free(&cPack_XXwv7GDb);
  hTable_free(&hTable_0JR0CnnU);
  cPack_free(&cPack_IiqL7wlu);
  cPack_free(&cPack_tI4J4088);
  cPack_free(&cPack_3CrlaE0w);
  hTable_free(&hTable_pPXD0eHb);
  cPack_free(&cPack_1Jt11iTs);
  cPack_free(&cPack_BlPYpO87);
  cPack_free(&cPack_8ESaVNdy);
  hTable_free(&hTable_gd59mUEY);
  cPack_free(&cPack_sT2nExBM);
  cPack_free(&cPack_oaaMHZ2v);
  cPack_free(&cPack_v4Enanaz);
  cPack_free(&cPack_vaJLk8ah);
  cPack_free(&cPack_TJnjVF3M);
  cPack_free(&cPack_hTaUVW9A);
  cPack_free(&cPack_maV9bBvI);
  cPack_free(&cPack_qu54pwU9);
  cPack_free(&cPack_FBz81L0q);
}

HvTable *Heavy_CircleStrings::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xCA4BE954: return &hTable_lFgY6udj; // del-1011-del1
    case 0x244CE923: return &hTable_P6kA6W4b; // del-1011-del2
    case 0xBF68886F: return &hTable_TLpzu4kl; // del-1011-del3
    case 0x55632928: return &hTable_ZcXVbtE0; // del-1011-del4
    case 0x96995032: return &hTable_SM4QXQeF; // del-1011-ref6
    case 0xBDA899C7: return &hTable_u6Hxx1K6; // del-1011-ref5
    case 0xC66C0031: return &hTable_SUZvKEGd; // del-1011-ref4
    case 0x87263188: return &hTable_fZ5w8oEv; // del-1011-ref3
    case 0xABC596E9: return &hTable_Vr4L87pS; // del-1011-ref2
    case 0x4E55A0D9: return &hTable_ctUYpoNB; // del-1011-ref1
    case 0x1F09EB02: return &hTable_MrhoiJQN; // del-1118-del
    case 0xB5F303E3: return &hTable_hTWSoF5b; // del-1181-del1
    case 0x6E18225F: return &hTable_COEgQSwC; // del-1181-del2
    case 0x272AEAC5: return &hTable_mCl2Tskq; // del-1181-del3
    case 0x1EF3B8AB: return &hTable_DrpcdFvR; // del-1181-del4
    case 0x908630F0: return &hTable_wfdQB7fw; // del-1181-ref6
    case 0x571D5EBB: return &hTable_ruwuNmbR; // del-1181-ref5
    case 0xCD1DF3EE: return &hTable_EVwlXk0j; // del-1181-ref4
    case 0x32F70D4: return &hTable_Sfmze7cf; // del-1181-ref3
    case 0x2649C1A0: return &hTable_9lqzuT7e; // del-1181-ref2
    case 0x2A4E9F1A: return &hTable_CRvEyM5B; // del-1181-ref1
    case 0xCDA70ACE: return &hTable_fhgnzNi0; // del-1280-del1
    case 0x1880FCC4: return &hTable_Lck3uK01; // del-1311-del
    case 0xDA0DD3E: return &hTable_ABZ5l3v7; // del-1340-del1
    case 0xF059E6C5: return &hTable_H2ZqmK2S; // del-1418-delay
    case 0x1B841D52: return &hTable_AG33Nc1W; // del-1497-delay
    case 0xDDCE7CE3: return &hTable_0JR0CnnU; // del-1564-delay
    case 0x267B6FA5: return &hTable_pPXD0eHb; // del-1615-delay
    case 0xA939BCAF: return &hTable_gd59mUEY; // del-1666-delay
    default: return nullptr;
  }
}

void Heavy_CircleStrings::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE9CDF196: { // 1474-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_I0KUwktY_sendMessage);
      break;
    }
    case 0x318534AD: { // 1474-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9gBXmyIj_sendMessage);
      break;
    }
    case 0x73BE02B2: { // 1474-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UuFhNhpg_sendMessage);
      break;
    }
    case 0x20FBEFA2: { // 1474-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rPLLZSoQ_sendMessage);
      break;
    }
    case 0xB3D2781B: { // 1474-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_voLTETyR_sendMessage);
      break;
    }
    case 0xEB419491: { // 1474-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iZs0339h_sendMessage);
      break;
    }
    case 0x287969C8: { // 1525-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ae1fK3UB_sendMessage);
      break;
    }
    case 0xF758C0B7: { // 1525-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NopesP73_sendMessage);
      break;
    }
    case 0xEC622ADF: { // 1533-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7Xh37HGI_sendMessage);
      break;
    }
    case 0x706EBE7F: { // 1533-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_F19zfk9g_sendMessage);
      break;
    }
    case 0x961222E8: { // 1541-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XjPlYGvo_sendMessage);
      break;
    }
    case 0x5DFAB282: { // 1541-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fL7WIF1a_sendMessage);
      break;
    }
    case 0xA73CF987: { // 1541-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xyFYFaXb_sendMessage);
      break;
    }
    case 0xDE176410: { // 1541-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sDGITZ0v_sendMessage);
      break;
    }
    case 0x8027D6B0: { // 1541-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DlThSkZj_sendMessage);
      break;
    }
    case 0x5F30AB7: { // 1541-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j7cY7eko_sendMessage);
      break;
    }
    case 0xDAF501EE: { // 1592-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_09FF6qn7_sendMessage);
      break;
    }
    case 0x97DF0634: { // 1592-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RfpieZ96_sendMessage);
      break;
    }
    case 0xED939F1D: { // 1592-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zHi8b9ZY_sendMessage);
      break;
    }
    case 0x6824A5FB: { // 1592-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uhw617Gy_sendMessage);
      break;
    }
    case 0xD73B2171: { // 1592-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cLDgQhOR_sendMessage);
      break;
    }
    case 0x42AF91EE: { // 1592-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AQ4lxFlf_sendMessage);
      break;
    }
    case 0xA1F992A3: { // 1643-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GDyXouKT_sendMessage);
      break;
    }
    case 0x3A383FAD: { // 1643-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Trui00ow_sendMessage);
      break;
    }
    case 0x5381C841: { // 1643-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VVPgUsCD_sendMessage);
      break;
    }
    case 0x17698774: { // 1643-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DuSJ5FW1_sendMessage);
      break;
    }
    case 0xB064A0B2: { // 1643-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jONNuo7Y_sendMessage);
      break;
    }
    case 0x48B0D745: { // 1643-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WpAwdrL6_sendMessage);
      break;
    }
    case 0xA97D2594: { // 1694-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_74xPJo1e_sendMessage);
      break;
    }
    case 0x17BA9CFD: { // 1694-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7aFj9XWO_sendMessage);
      break;
    }
    case 0x563C50D1: { // 1702-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZHPUw2jf_sendMessage);
      break;
    }
    case 0x50C55BB2: { // 1702-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vqYwP32U_sendMessage);
      break;
    }
    case 0x60821E7E: { // 1710-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yCivK9mR_sendMessage);
      break;
    }
    case 0x2917EC99: { // 1710-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CHQ1g4FG_sendMessage);
      break;
    }
    case 0xA773C924: { // 1722-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_X4bVaKCf_sendMessage);
      break;
    }
    case 0xCA11C605: { // 1722-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Xblvs9oi_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_f6pC40dN_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_G8d49Z4R_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ijzEOQ4z_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8QYuQKll_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3NNPuLRQ_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Sfbdnzv2_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IqM0aObO_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_seFUm3TM_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Gy8UdtWl_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wR3DZeDr_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E9CnU4LC_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6G8hamK1_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ML0XEK3x_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IuHMkwR7_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RPWcUIkk_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QnzRUWvP_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eVKiQ93V_sendMessage);
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


void Heavy_CircleStrings::cSlice_LY3f9PMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UtFSog6S_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_uuE4MNpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_AHXIDYs9, 0, m, &cIf_AHXIDYs9_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_lI059xX7, 0, m, &cIf_lI059xX7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_rocHjDut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_tJ7m0OsX, 0, m, &cIf_tJ7m0OsX_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_7pJchwav, 0, m, &cIf_7pJchwav_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_OcCTe9XT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_p6PROfCJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_SVsAqZVb, 0, m, &cIf_SVsAqZVb_sendMessage);
}

void Heavy_CircleStrings::cUnop_uLbweFxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_lBVict1F_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulweURXf, HV_BINOP_EQ, 1, m, &cBinop_ulweURXf_sendMessage);
}

void Heavy_CircleStrings::cUnop_ACnlVuII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_lBVict1F_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulweURXf, HV_BINOP_EQ, 1, m, &cBinop_ulweURXf_sendMessage);
}

void Heavy_CircleStrings::cIf_SVsAqZVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_ACnlVuII_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uLbweFxy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_p6PROfCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SVsAqZVb, 1, m, &cIf_SVsAqZVb_sendMessage);
}

void Heavy_CircleStrings::cIf_lI059xX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_TeL3Yu2L_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_7pJchwav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_DTv2FXX9_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_AHXIDYs9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_TeL3Yu2L_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_tJ7m0OsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_DTv2FXX9_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_UtFSog6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulweURXf, HV_BINOP_EQ, 0, m, &cBinop_ulweURXf_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_tnGE47Qg_sendMessage);
}

void Heavy_CircleStrings::cBinop_lBVict1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BqPkFHj1_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SNBd8Gce_sendMessage);
}

void Heavy_CircleStrings::cBinop_ulweURXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EMHEFg0u_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kl3NTG7M_sendMessage);
}

void Heavy_CircleStrings::cCast_EMHEFg0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lI059xX7, 1, m, &cIf_lI059xX7_sendMessage);
}

void Heavy_CircleStrings::cCast_Kl3NTG7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tJ7m0OsX, 1, m, &cIf_tJ7m0OsX_sendMessage);
}

void Heavy_CircleStrings::cCast_BqPkFHj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_AHXIDYs9, 1, m, &cIf_AHXIDYs9_sendMessage);
}

void Heavy_CircleStrings::cCast_SNBd8Gce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7pJchwav, 1, m, &cIf_7pJchwav_sendMessage);
}

void Heavy_CircleStrings::cBinop_tnGE47Qg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_05512Jdv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cTabhead_8iWTsgsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sFpoqbmd, HV_BINOP_SUBTRACT, 0, m, &cBinop_sFpoqbmd_sendMessage);
}

void Heavy_CircleStrings::cMsg_dJvhvrdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9VDl4LQg_sendMessage);
}

void Heavy_CircleStrings::cSystem_9VDl4LQg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SJb4sxOW_sendMessage);
}

void Heavy_CircleStrings::cVar_ItOKZudJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Cgw7yMD7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_XlXndBw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XlXndBw0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CnppRdeg, 0, m, &cDelay_CnppRdeg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5wzI9Ouq, 0, m, &sTabread_5wzI9Ouq_sendMessage);
}

void Heavy_CircleStrings::cDelay_CnppRdeg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CnppRdeg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5wzI9Ouq, 0, m, &sTabread_5wzI9Ouq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CnppRdeg, 0, m, &cDelay_CnppRdeg_sendMessage);
}

void Heavy_CircleStrings::sTabread_5wzI9Ouq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_7VPvpehd, HV_BINOP_SUBTRACT, 0, m, &cBinop_7VPvpehd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_o8chowuA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o4RaCYJi, HV_BINOP_MAX, 0, m, &cBinop_o4RaCYJi_sendMessage);
}

void Heavy_CircleStrings::cBinop_SJb4sxOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o8chowuA, HV_BINOP_MULTIPLY, 0, m, &cBinop_o8chowuA_sendMessage);
}

void Heavy_CircleStrings::cBinop_sFpoqbmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qZjEknvD_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5wzI9Ouq, 0, m, &sTabread_5wzI9Ouq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CN0uze0A_sendMessage);
}

void Heavy_CircleStrings::cSystem_4r8W4jrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7VPvpehd, HV_BINOP_SUBTRACT, 1, m, &cBinop_7VPvpehd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CnppRdeg, 2, m, &cDelay_CnppRdeg_sendMessage);
}

void Heavy_CircleStrings::cMsg_Cgw7yMD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4r8W4jrC_sendMessage);
}

void Heavy_CircleStrings::cMsg_qZjEknvD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XlXndBw0, 0, m, &cDelay_XlXndBw0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CnppRdeg, 0, m, &cDelay_CnppRdeg_sendMessage);
}

void Heavy_CircleStrings::cMsg_ncdsauos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_o4RaCYJi, HV_BINOP_MAX, 1, m, &cBinop_o4RaCYJi_sendMessage);
}

void Heavy_CircleStrings::cBinop_o4RaCYJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sFpoqbmd, HV_BINOP_SUBTRACT, 1, m, &cBinop_sFpoqbmd_sendMessage);
}

void Heavy_CircleStrings::cCast_CN0uze0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XlXndBw0, 0, m, &cDelay_XlXndBw0_sendMessage);
}

void Heavy_CircleStrings::cBinop_7o4XJz1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XlXndBw0, 2, m, &cDelay_XlXndBw0_sendMessage);
}

void Heavy_CircleStrings::cBinop_7VPvpehd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7o4XJz1e_sendMessage);
}

void Heavy_CircleStrings::cCast_09hZdQey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ItOKZudJ, 0, m, &cVar_ItOKZudJ_sendMessage);
  cMsg_dJvhvrdJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8iWTsgsC, 0, m, &cTabhead_8iWTsgsC_sendMessage);
}

void Heavy_CircleStrings::cTabhead_uCcmDMEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9mSLYTp, HV_BINOP_SUBTRACT, 0, m, &cBinop_y9mSLYTp_sendMessage);
}

void Heavy_CircleStrings::cMsg_butCDDt7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hbqykufR_sendMessage);
}

void Heavy_CircleStrings::cSystem_hbqykufR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_m4RfXvTk_sendMessage);
}

void Heavy_CircleStrings::cVar_qHIxkDY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fBNvUSnF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_DT8kLJZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DT8kLJZD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kMwM1hI8, 0, m, &cDelay_kMwM1hI8_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_J80Ll0xd, 0, m, &sTabread_J80Ll0xd_sendMessage);
}

void Heavy_CircleStrings::cDelay_kMwM1hI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kMwM1hI8, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_J80Ll0xd, 0, m, &sTabread_J80Ll0xd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kMwM1hI8, 0, m, &cDelay_kMwM1hI8_sendMessage);
}

void Heavy_CircleStrings::sTabread_J80Ll0xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_wqsuutXg, HV_BINOP_SUBTRACT, 0, m, &cBinop_wqsuutXg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_fKI4g3Gi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CRGCl1mN, HV_BINOP_MAX, 0, m, &cBinop_CRGCl1mN_sendMessage);
}

void Heavy_CircleStrings::cBinop_m4RfXvTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fKI4g3Gi, HV_BINOP_MULTIPLY, 0, m, &cBinop_fKI4g3Gi_sendMessage);
}

void Heavy_CircleStrings::cBinop_y9mSLYTp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6ymBJwlK_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_J80Ll0xd, 0, m, &sTabread_J80Ll0xd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_t9rIjup8_sendMessage);
}

void Heavy_CircleStrings::cSystem_rYBCWcky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wqsuutXg, HV_BINOP_SUBTRACT, 1, m, &cBinop_wqsuutXg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kMwM1hI8, 2, m, &cDelay_kMwM1hI8_sendMessage);
}

void Heavy_CircleStrings::cMsg_fBNvUSnF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rYBCWcky_sendMessage);
}

void Heavy_CircleStrings::cMsg_6ymBJwlK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DT8kLJZD, 0, m, &cDelay_DT8kLJZD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kMwM1hI8, 0, m, &cDelay_kMwM1hI8_sendMessage);
}

void Heavy_CircleStrings::cMsg_1ynJDr1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_CRGCl1mN, HV_BINOP_MAX, 1, m, &cBinop_CRGCl1mN_sendMessage);
}

void Heavy_CircleStrings::cBinop_CRGCl1mN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9mSLYTp, HV_BINOP_SUBTRACT, 1, m, &cBinop_y9mSLYTp_sendMessage);
}

void Heavy_CircleStrings::cCast_t9rIjup8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DT8kLJZD, 0, m, &cDelay_DT8kLJZD_sendMessage);
}

void Heavy_CircleStrings::cBinop_oK0TylQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DT8kLJZD, 2, m, &cDelay_DT8kLJZD_sendMessage);
}

void Heavy_CircleStrings::cBinop_wqsuutXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oK0TylQm_sendMessage);
}

void Heavy_CircleStrings::cCast_5buvFfnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qHIxkDY6, 0, m, &cVar_qHIxkDY6_sendMessage);
  cMsg_butCDDt7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uCcmDMEB, 0, m, &cTabhead_uCcmDMEB_sendMessage);
}

void Heavy_CircleStrings::cTabhead_PC81NOqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uALorA04, HV_BINOP_SUBTRACT, 0, m, &cBinop_uALorA04_sendMessage);
}

void Heavy_CircleStrings::cMsg_9jFGPMbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oO1RqU4L_sendMessage);
}

void Heavy_CircleStrings::cSystem_oO1RqU4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OtbhBTi9_sendMessage);
}

void Heavy_CircleStrings::cVar_vc2GdaqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Pn7MQTQL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Yc156bgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Yc156bgZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0oNtmTkT, 0, m, &cDelay_0oNtmTkT_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TIxPr7Di, 0, m, &sTabread_TIxPr7Di_sendMessage);
}

void Heavy_CircleStrings::cDelay_0oNtmTkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0oNtmTkT, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TIxPr7Di, 0, m, &sTabread_TIxPr7Di_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0oNtmTkT, 0, m, &cDelay_0oNtmTkT_sendMessage);
}

void Heavy_CircleStrings::sTabread_TIxPr7Di_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2MtBSSg6, HV_BINOP_SUBTRACT, 0, m, &cBinop_2MtBSSg6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_bDrDFXca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zx8ku5Pi, HV_BINOP_MAX, 0, m, &cBinop_Zx8ku5Pi_sendMessage);
}

void Heavy_CircleStrings::cBinop_OtbhBTi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bDrDFXca, HV_BINOP_MULTIPLY, 0, m, &cBinop_bDrDFXca_sendMessage);
}

void Heavy_CircleStrings::cBinop_uALorA04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DxMWsdxh_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TIxPr7Di, 0, m, &sTabread_TIxPr7Di_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YgdouHM4_sendMessage);
}

void Heavy_CircleStrings::cSystem_gN7ExRXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2MtBSSg6, HV_BINOP_SUBTRACT, 1, m, &cBinop_2MtBSSg6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0oNtmTkT, 2, m, &cDelay_0oNtmTkT_sendMessage);
}

void Heavy_CircleStrings::cMsg_Pn7MQTQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gN7ExRXE_sendMessage);
}

void Heavy_CircleStrings::cMsg_DxMWsdxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yc156bgZ, 0, m, &cDelay_Yc156bgZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0oNtmTkT, 0, m, &cDelay_0oNtmTkT_sendMessage);
}

void Heavy_CircleStrings::cMsg_5CttTGTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zx8ku5Pi, HV_BINOP_MAX, 1, m, &cBinop_Zx8ku5Pi_sendMessage);
}

void Heavy_CircleStrings::cBinop_Zx8ku5Pi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uALorA04, HV_BINOP_SUBTRACT, 1, m, &cBinop_uALorA04_sendMessage);
}

void Heavy_CircleStrings::cCast_YgdouHM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yc156bgZ, 0, m, &cDelay_Yc156bgZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_SDAyGstD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yc156bgZ, 2, m, &cDelay_Yc156bgZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_2MtBSSg6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SDAyGstD_sendMessage);
}

void Heavy_CircleStrings::cCast_oq6Vre2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vc2GdaqP, 0, m, &cVar_vc2GdaqP_sendMessage);
  cMsg_9jFGPMbX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_PC81NOqb, 0, m, &cTabhead_PC81NOqb_sendMessage);
}

void Heavy_CircleStrings::cTabhead_1VlZJewa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IXV7JTud, HV_BINOP_SUBTRACT, 0, m, &cBinop_IXV7JTud_sendMessage);
}

void Heavy_CircleStrings::cMsg_JOdLAWed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_If5ICcdA_sendMessage);
}

void Heavy_CircleStrings::cSystem_If5ICcdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iEgctGuz_sendMessage);
}

void Heavy_CircleStrings::cVar_WLBevVxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JfPHt7xT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_HuTPJdv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HuTPJdv9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p9eVasew, 0, m, &cDelay_p9eVasew_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_USQh9C7D, 0, m, &sTabread_USQh9C7D_sendMessage);
}

void Heavy_CircleStrings::cDelay_p9eVasew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_p9eVasew, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_USQh9C7D, 0, m, &sTabread_USQh9C7D_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p9eVasew, 0, m, &cDelay_p9eVasew_sendMessage);
}

void Heavy_CircleStrings::sTabread_USQh9C7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hwyAhTxL, HV_BINOP_SUBTRACT, 0, m, &cBinop_hwyAhTxL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_FnQWYCgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nUC8HV26, HV_BINOP_MAX, 0, m, &cBinop_nUC8HV26_sendMessage);
}

void Heavy_CircleStrings::cBinop_iEgctGuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FnQWYCgl, HV_BINOP_MULTIPLY, 0, m, &cBinop_FnQWYCgl_sendMessage);
}

void Heavy_CircleStrings::cBinop_IXV7JTud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P6wy1oPW_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_USQh9C7D, 0, m, &sTabread_USQh9C7D_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_prodZdWB_sendMessage);
}

void Heavy_CircleStrings::cSystem_v0wD7OQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hwyAhTxL, HV_BINOP_SUBTRACT, 1, m, &cBinop_hwyAhTxL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p9eVasew, 2, m, &cDelay_p9eVasew_sendMessage);
}

void Heavy_CircleStrings::cMsg_JfPHt7xT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v0wD7OQl_sendMessage);
}

void Heavy_CircleStrings::cMsg_P6wy1oPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HuTPJdv9, 0, m, &cDelay_HuTPJdv9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p9eVasew, 0, m, &cDelay_p9eVasew_sendMessage);
}

void Heavy_CircleStrings::cMsg_J1bP2JSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_nUC8HV26, HV_BINOP_MAX, 1, m, &cBinop_nUC8HV26_sendMessage);
}

void Heavy_CircleStrings::cBinop_nUC8HV26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IXV7JTud, HV_BINOP_SUBTRACT, 1, m, &cBinop_IXV7JTud_sendMessage);
}

void Heavy_CircleStrings::cCast_prodZdWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HuTPJdv9, 0, m, &cDelay_HuTPJdv9_sendMessage);
}

void Heavy_CircleStrings::cBinop_HvdnhJJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HuTPJdv9, 2, m, &cDelay_HuTPJdv9_sendMessage);
}

void Heavy_CircleStrings::cBinop_hwyAhTxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HvdnhJJD_sendMessage);
}

void Heavy_CircleStrings::cCast_NpRDJ9u0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WLBevVxy, 0, m, &cVar_WLBevVxy_sendMessage);
  cMsg_JOdLAWed_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1VlZJewa, 0, m, &cTabhead_1VlZJewa_sendMessage);
}

void Heavy_CircleStrings::cMsg_Yu52ZNIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xCsOUyaZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_xCsOUyaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_28e0Vb3p_sendMessage);
}

void Heavy_CircleStrings::cDelay_CsMKacQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CsMKacQZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UUbYsZv6, 0, m, &cDelay_UUbYsZv6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CsMKacQZ, 0, m, &cDelay_CsMKacQZ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RIPwGPXw, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_UUbYsZv6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UUbYsZv6, m);
  cMsg_RH558uoc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_nICJMP8M_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_7Pe07nl9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_P79Eu52j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jnI2TNti_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_lFgY6udj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FedmTDW8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CsMKacQZ, 2, m, &cDelay_CsMKacQZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6V0gakGo_sendMessage);
}

void Heavy_CircleStrings::cMsg_jnI2TNti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_lFgY6udj, 0, m, &hTable_lFgY6udj_sendMessage);
}

void Heavy_CircleStrings::cBinop_28e0Vb3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_P79Eu52j_sendMessage);
}

void Heavy_CircleStrings::cMsg_RH558uoc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_lFgY6udj, 0, m, &hTable_lFgY6udj_sendMessage);
}

void Heavy_CircleStrings::cCast_6V0gakGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CsMKacQZ, 0, m, &cDelay_CsMKacQZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_FedmTDW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_UUbYsZv6, 2, m, &cDelay_UUbYsZv6_sendMessage);
}

void Heavy_CircleStrings::cMsg_7Pe07nl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RIPwGPXw, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_2S64sLr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GfYjvoX7_sendMessage);
}

void Heavy_CircleStrings::cSystem_GfYjvoX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SbvfiOmU_sendMessage);
}

void Heavy_CircleStrings::cDelay_HP9ZsRuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HP9ZsRuL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uO7Uj04D, 0, m, &cDelay_uO7Uj04D_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HP9ZsRuL, 0, m, &cDelay_HP9ZsRuL_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4hh8ppP2, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_uO7Uj04D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uO7Uj04D, m);
  cMsg_1on5bTbB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_CmSafn9k_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_f97ufRr4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_JM5vPUyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rpSu1DPF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_P6kA6W4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XJmaxU0z_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HP9ZsRuL, 2, m, &cDelay_HP9ZsRuL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L2ZaB1aw_sendMessage);
}

void Heavy_CircleStrings::cMsg_rpSu1DPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_P6kA6W4b, 0, m, &hTable_P6kA6W4b_sendMessage);
}

void Heavy_CircleStrings::cBinop_SbvfiOmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_JM5vPUyh_sendMessage);
}

void Heavy_CircleStrings::cMsg_1on5bTbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_P6kA6W4b, 0, m, &hTable_P6kA6W4b_sendMessage);
}

void Heavy_CircleStrings::cCast_L2ZaB1aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HP9ZsRuL, 0, m, &cDelay_HP9ZsRuL_sendMessage);
}

void Heavy_CircleStrings::cMsg_XJmaxU0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_uO7Uj04D, 2, m, &cDelay_uO7Uj04D_sendMessage);
}

void Heavy_CircleStrings::cMsg_f97ufRr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4hh8ppP2, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_XNujj9P6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ETipElVE_sendMessage);
}

void Heavy_CircleStrings::cSystem_ETipElVE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_34CmqWaY_sendMessage);
}

void Heavy_CircleStrings::cDelay_jyTiyGau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jyTiyGau, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zUA43mUD, 0, m, &cDelay_zUA43mUD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jyTiyGau, 0, m, &cDelay_jyTiyGau_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7JNh6oma, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_zUA43mUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zUA43mUD, m);
  cMsg_EBpCFJQB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_5lMHwRso_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_XlI7emI5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_mjpm1eok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QV31fZAM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_TLpzu4kl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Yfbz3Smv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jyTiyGau, 2, m, &cDelay_jyTiyGau_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RjJfpyyJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_QV31fZAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TLpzu4kl, 0, m, &hTable_TLpzu4kl_sendMessage);
}

void Heavy_CircleStrings::cBinop_34CmqWaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_mjpm1eok_sendMessage);
}

void Heavy_CircleStrings::cMsg_EBpCFJQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TLpzu4kl, 0, m, &hTable_TLpzu4kl_sendMessage);
}

void Heavy_CircleStrings::cCast_RjJfpyyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jyTiyGau, 0, m, &cDelay_jyTiyGau_sendMessage);
}

void Heavy_CircleStrings::cMsg_Yfbz3Smv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_zUA43mUD, 2, m, &cDelay_zUA43mUD_sendMessage);
}

void Heavy_CircleStrings::cMsg_XlI7emI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7JNh6oma, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_CJGuYwnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3zwFxGUd_sendMessage);
}

void Heavy_CircleStrings::cSystem_3zwFxGUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hqF5SMaD_sendMessage);
}

void Heavy_CircleStrings::cDelay_1cEit97S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1cEit97S, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L8fSaoeQ, 0, m, &cDelay_L8fSaoeQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1cEit97S, 0, m, &cDelay_1cEit97S_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4Fh1eyl8, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_L8fSaoeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_L8fSaoeQ, m);
  cMsg_94lMeUIP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_5gfNY1Pr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_a3v5ftlZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_BTEzewWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LDye1ZRW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_ZcXVbtE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XavRbDPq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1cEit97S, 2, m, &cDelay_1cEit97S_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZOTlmYYZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_LDye1ZRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ZcXVbtE0, 0, m, &hTable_ZcXVbtE0_sendMessage);
}

void Heavy_CircleStrings::cBinop_hqF5SMaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_BTEzewWj_sendMessage);
}

void Heavy_CircleStrings::cMsg_94lMeUIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ZcXVbtE0, 0, m, &hTable_ZcXVbtE0_sendMessage);
}

void Heavy_CircleStrings::cCast_ZOTlmYYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1cEit97S, 0, m, &cDelay_1cEit97S_sendMessage);
}

void Heavy_CircleStrings::cMsg_XavRbDPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_L8fSaoeQ, 2, m, &cDelay_L8fSaoeQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_a3v5ftlZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4Fh1eyl8, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_A9sUbgiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_zVtbHeJg_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_eSv9v7DQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_Od0Q5KbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AjotDPvh, HV_BINOP_POW, 0, m, &cBinop_AjotDPvh_sendMessage);
}

void Heavy_CircleStrings::cBinop_AjotDPvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_oaEw1vc4_sendMessage);
}

void Heavy_CircleStrings::cBinop_NK28ByCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_jNs2KmGE_sendMessage);
}

void Heavy_CircleStrings::cCast_u4j89cBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_A9sUbgiT, 0, m, &cIf_A9sUbgiT_sendMessage);
}

void Heavy_CircleStrings::cCast_z1m5Adl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Pj2frNJV_sendMessage);
}

void Heavy_CircleStrings::cBinop_Pj2frNJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_A9sUbgiT, 1, m, &cIf_A9sUbgiT_sendMessage);
}

void Heavy_CircleStrings::cBinop_eSv9v7DQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_NK28ByCT_sendMessage);
}

void Heavy_CircleStrings::cMsg_zVtbHeJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_oaEw1vc4_sendMessage);
}

void Heavy_CircleStrings::cBinop_jNs2KmGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AjotDPvh, HV_BINOP_POW, 1, m, &cBinop_AjotDPvh_sendMessage);
  cMsg_Od0Q5KbC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_QdIEk6Pf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cIS5LomB, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_3rjzdrYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xkMaD7Gw, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_fwl0Z3bk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5gWBS4m2_sendMessage);
}

void Heavy_CircleStrings::cBinop_5gWBS4m2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_V2uWsLBe_sendMessage);
}

void Heavy_CircleStrings::cVar_xMFd6Umd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VQfctqdd, HV_BINOP_MULTIPLY, 0, m, &cBinop_VQfctqdd_sendMessage);
}

void Heavy_CircleStrings::cMsg_qTWKzuR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_74FOPoQq_sendMessage);
}

void Heavy_CircleStrings::cSystem_74FOPoQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BCK5PUYA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_VQfctqdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_qKbpZeyY_sendMessage);
}

void Heavy_CircleStrings::cBinop_O3BAPUPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VQfctqdd, HV_BINOP_MULTIPLY, 1, m, &cBinop_VQfctqdd_sendMessage);
}

void Heavy_CircleStrings::cMsg_BCK5PUYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_O3BAPUPw_sendMessage);
}

void Heavy_CircleStrings::cBinop_qKbpZeyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oP7d4xlR_sendMessage);
}

void Heavy_CircleStrings::cBinop_oP7d4xlR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Rc5ABkCQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8m6kUpjO, m);
}

void Heavy_CircleStrings::cBinop_Rc5ABkCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BmZqn46h, m);
}

void Heavy_CircleStrings::cVar_VfzSWenc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z1m5Adl3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u4j89cBt_sendMessage);
}

void Heavy_CircleStrings::cVar_foddyUI2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_fwl0Z3bk_sendMessage);
}

void Heavy_CircleStrings::cVar_hdnpOuid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_7Gqpvsjj_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_P3zg6Uio, 0, m, &cIf_P3zg6Uio_sendMessage);
}

void Heavy_CircleStrings::cVar_4RwKe4Fe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_esk23Cua_sendMessage);
}

void Heavy_CircleStrings::cIf_P3zg6Uio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DdLJVeN7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_hUHRGyTy, 0, m, &cVar_hUHRGyTy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_7Gqpvsjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_P3zg6Uio, 1, m, &cIf_P3zg6Uio_sendMessage);
}

void Heavy_CircleStrings::cBinop_esk23Cua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ccNFFzcU_sendMessage);
}

void Heavy_CircleStrings::cBinop_ccNFFzcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e1OxD7Or, 0, m, &cVar_e1OxD7Or_sendMessage);
}

void Heavy_CircleStrings::cTabhead_gIVXQonp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qA0QjDd1, HV_BINOP_SUBTRACT, 0, m, &cBinop_qA0QjDd1_sendMessage);
}

void Heavy_CircleStrings::cMsg_B3K9Ckjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yzDg5Ufj_sendMessage);
}

void Heavy_CircleStrings::cSystem_yzDg5Ufj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uGKISSdI_sendMessage);
}

void Heavy_CircleStrings::cVar_EziZOGF9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BDSD1HrB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_gJnQYmEs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gJnQYmEs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_atnZYavH, 0, m, &cDelay_atnZYavH_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_DDrOibzj, 0, m, &sTabread_DDrOibzj_sendMessage);
}

void Heavy_CircleStrings::cDelay_atnZYavH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_atnZYavH, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_DDrOibzj, 0, m, &sTabread_DDrOibzj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_atnZYavH, 0, m, &cDelay_atnZYavH_sendMessage);
}

void Heavy_CircleStrings::sTabread_DDrOibzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_N93mpBJp, HV_BINOP_SUBTRACT, 0, m, &cBinop_N93mpBJp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_QneGOJaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tqqhzgqB, HV_BINOP_MAX, 0, m, &cBinop_tqqhzgqB_sendMessage);
}

void Heavy_CircleStrings::cBinop_uGKISSdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QneGOJaZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_QneGOJaZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_qA0QjDd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RQWeRvFR_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_DDrOibzj, 0, m, &sTabread_DDrOibzj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mZGDbVXc_sendMessage);
}

void Heavy_CircleStrings::cSystem_AoLtZ2GX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N93mpBJp, HV_BINOP_SUBTRACT, 1, m, &cBinop_N93mpBJp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_atnZYavH, 2, m, &cDelay_atnZYavH_sendMessage);
}

void Heavy_CircleStrings::cMsg_BDSD1HrB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AoLtZ2GX_sendMessage);
}

void Heavy_CircleStrings::cMsg_RQWeRvFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gJnQYmEs, 0, m, &cDelay_gJnQYmEs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_atnZYavH, 0, m, &cDelay_atnZYavH_sendMessage);
}

void Heavy_CircleStrings::cMsg_8DKPbrlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_tqqhzgqB, HV_BINOP_MAX, 1, m, &cBinop_tqqhzgqB_sendMessage);
}

void Heavy_CircleStrings::cBinop_tqqhzgqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qA0QjDd1, HV_BINOP_SUBTRACT, 1, m, &cBinop_qA0QjDd1_sendMessage);
}

void Heavy_CircleStrings::cCast_mZGDbVXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gJnQYmEs, 0, m, &cDelay_gJnQYmEs_sendMessage);
}

void Heavy_CircleStrings::cBinop_l5i4EqKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gJnQYmEs, 2, m, &cDelay_gJnQYmEs_sendMessage);
}

void Heavy_CircleStrings::cBinop_N93mpBJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_l5i4EqKv_sendMessage);
}

void Heavy_CircleStrings::cCast_Rm1nxXJE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EziZOGF9, 0, m, &cVar_EziZOGF9_sendMessage);
  cMsg_B3K9Ckjh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_gIVXQonp, 0, m, &cTabhead_gIVXQonp_sendMessage);
}

void Heavy_CircleStrings::cMsg_YHlIQu2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KP3VYErM_sendMessage);
}

void Heavy_CircleStrings::cSystem_KP3VYErM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_U7VYasrY_sendMessage);
}

void Heavy_CircleStrings::cDelay_ZklSaH43_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZklSaH43, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tWI8qTSb, 0, m, &cDelay_tWI8qTSb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZklSaH43, 0, m, &cDelay_ZklSaH43_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QPJgHarV, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_tWI8qTSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tWI8qTSb, m);
  cMsg_vWovS6yX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_6E9qN4R8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ln5QrSTt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_eULF8996_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PGibPoDe_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_SM4QXQeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U5eQEYaC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZklSaH43, 2, m, &cDelay_ZklSaH43_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tZK6ZpKD_sendMessage);
}

void Heavy_CircleStrings::cMsg_PGibPoDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_SM4QXQeF, 0, m, &hTable_SM4QXQeF_sendMessage);
}

void Heavy_CircleStrings::cBinop_U7VYasrY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_eULF8996_sendMessage);
}

void Heavy_CircleStrings::cMsg_vWovS6yX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_SM4QXQeF, 0, m, &hTable_SM4QXQeF_sendMessage);
}

void Heavy_CircleStrings::cCast_tZK6ZpKD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZklSaH43, 0, m, &cDelay_ZklSaH43_sendMessage);
}

void Heavy_CircleStrings::cMsg_U5eQEYaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_tWI8qTSb, 2, m, &cDelay_tWI8qTSb_sendMessage);
}

void Heavy_CircleStrings::cMsg_ln5QrSTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QPJgHarV, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_niXRBrpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XMGccKo9, HV_BINOP_SUBTRACT, 0, m, &cBinop_XMGccKo9_sendMessage);
}

void Heavy_CircleStrings::cMsg_TE4pymhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FB0QJKPa_sendMessage);
}

void Heavy_CircleStrings::cSystem_FB0QJKPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OiSINa0m_sendMessage);
}

void Heavy_CircleStrings::cVar_3qsIGoPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sVAC3jkh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Cvs1TfsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Cvs1TfsM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0ZPU5AkL, 0, m, &cDelay_0ZPU5AkL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gPSVfwSP, 0, m, &sTabread_gPSVfwSP_sendMessage);
}

void Heavy_CircleStrings::cDelay_0ZPU5AkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0ZPU5AkL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gPSVfwSP, 0, m, &sTabread_gPSVfwSP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0ZPU5AkL, 0, m, &cDelay_0ZPU5AkL_sendMessage);
}

void Heavy_CircleStrings::sTabread_gPSVfwSP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_G9mhQs8M, HV_BINOP_SUBTRACT, 0, m, &cBinop_G9mhQs8M_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_rT0zxiSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r2fZ5r3h, HV_BINOP_MAX, 0, m, &cBinop_r2fZ5r3h_sendMessage);
}

void Heavy_CircleStrings::cBinop_OiSINa0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rT0zxiSG, HV_BINOP_MULTIPLY, 0, m, &cBinop_rT0zxiSG_sendMessage);
}

void Heavy_CircleStrings::cBinop_XMGccKo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M5841Q95_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gPSVfwSP, 0, m, &sTabread_gPSVfwSP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y0FtAFMx_sendMessage);
}

void Heavy_CircleStrings::cSystem_NNRKIX4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G9mhQs8M, HV_BINOP_SUBTRACT, 1, m, &cBinop_G9mhQs8M_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0ZPU5AkL, 2, m, &cDelay_0ZPU5AkL_sendMessage);
}

void Heavy_CircleStrings::cMsg_sVAC3jkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NNRKIX4h_sendMessage);
}

void Heavy_CircleStrings::cMsg_M5841Q95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cvs1TfsM, 0, m, &cDelay_Cvs1TfsM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0ZPU5AkL, 0, m, &cDelay_0ZPU5AkL_sendMessage);
}

void Heavy_CircleStrings::cMsg_QjhWylaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_r2fZ5r3h, HV_BINOP_MAX, 1, m, &cBinop_r2fZ5r3h_sendMessage);
}

void Heavy_CircleStrings::cBinop_r2fZ5r3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XMGccKo9, HV_BINOP_SUBTRACT, 1, m, &cBinop_XMGccKo9_sendMessage);
}

void Heavy_CircleStrings::cCast_y0FtAFMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cvs1TfsM, 0, m, &cDelay_Cvs1TfsM_sendMessage);
}

void Heavy_CircleStrings::cBinop_uDQxnp3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cvs1TfsM, 2, m, &cDelay_Cvs1TfsM_sendMessage);
}

void Heavy_CircleStrings::cBinop_G9mhQs8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uDQxnp3u_sendMessage);
}

void Heavy_CircleStrings::cCast_3906J9Wg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3qsIGoPK, 0, m, &cVar_3qsIGoPK_sendMessage);
  cMsg_TE4pymhX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_niXRBrpL, 0, m, &cTabhead_niXRBrpL_sendMessage);
}

void Heavy_CircleStrings::cMsg_Qac9hG85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xEbQ9WpT_sendMessage);
}

void Heavy_CircleStrings::cSystem_xEbQ9WpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OgsLLY3o_sendMessage);
}

void Heavy_CircleStrings::cDelay_8MzLN8XH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8MzLN8XH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CI6uHoK3, 0, m, &cDelay_CI6uHoK3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8MzLN8XH, 0, m, &cDelay_8MzLN8XH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uCGIefpB, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_CI6uHoK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CI6uHoK3, m);
  cMsg_CQ1i0dXf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_KrpOk6mt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_lQLImlIZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Jd2zdMTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ibwsZwV5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_u6Hxx1K6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fuyn3r2w_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8MzLN8XH, 2, m, &cDelay_8MzLN8XH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V1gtwAmi_sendMessage);
}

void Heavy_CircleStrings::cMsg_ibwsZwV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_u6Hxx1K6, 0, m, &hTable_u6Hxx1K6_sendMessage);
}

void Heavy_CircleStrings::cBinop_OgsLLY3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_Jd2zdMTK_sendMessage);
}

void Heavy_CircleStrings::cMsg_CQ1i0dXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_u6Hxx1K6, 0, m, &hTable_u6Hxx1K6_sendMessage);
}

void Heavy_CircleStrings::cCast_V1gtwAmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8MzLN8XH, 0, m, &cDelay_8MzLN8XH_sendMessage);
}

void Heavy_CircleStrings::cMsg_Fuyn3r2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_CI6uHoK3, 2, m, &cDelay_CI6uHoK3_sendMessage);
}

void Heavy_CircleStrings::cMsg_lQLImlIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uCGIefpB, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_tJpUn0Ui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Q8hBtxA, HV_BINOP_SUBTRACT, 0, m, &cBinop_6Q8hBtxA_sendMessage);
}

void Heavy_CircleStrings::cMsg_yAwNWvli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SmW8dnEa_sendMessage);
}

void Heavy_CircleStrings::cSystem_SmW8dnEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_g7wvPFwm_sendMessage);
}

void Heavy_CircleStrings::cVar_0FKAwyID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LzpYJhlk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_ph5p10w0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ph5p10w0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sY3vu1Dy, 0, m, &cDelay_sY3vu1Dy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ML7AvYC4, 0, m, &sTabread_ML7AvYC4_sendMessage);
}

void Heavy_CircleStrings::cDelay_sY3vu1Dy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sY3vu1Dy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ML7AvYC4, 0, m, &sTabread_ML7AvYC4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sY3vu1Dy, 0, m, &cDelay_sY3vu1Dy_sendMessage);
}

void Heavy_CircleStrings::sTabread_ML7AvYC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_8oBiams5, HV_BINOP_SUBTRACT, 0, m, &cBinop_8oBiams5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KVMrm8V2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ahWNTzN, HV_BINOP_MAX, 0, m, &cBinop_9ahWNTzN_sendMessage);
}

void Heavy_CircleStrings::cBinop_g7wvPFwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KVMrm8V2, HV_BINOP_MULTIPLY, 0, m, &cBinop_KVMrm8V2_sendMessage);
}

void Heavy_CircleStrings::cBinop_6Q8hBtxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vsFQIEvL_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ML7AvYC4, 0, m, &sTabread_ML7AvYC4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PYJYJsWX_sendMessage);
}

void Heavy_CircleStrings::cSystem_LKCPMHdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8oBiams5, HV_BINOP_SUBTRACT, 1, m, &cBinop_8oBiams5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sY3vu1Dy, 2, m, &cDelay_sY3vu1Dy_sendMessage);
}

void Heavy_CircleStrings::cMsg_LzpYJhlk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LKCPMHdG_sendMessage);
}

void Heavy_CircleStrings::cMsg_vsFQIEvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ph5p10w0, 0, m, &cDelay_ph5p10w0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sY3vu1Dy, 0, m, &cDelay_sY3vu1Dy_sendMessage);
}

void Heavy_CircleStrings::cMsg_y0H6DHZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ahWNTzN, HV_BINOP_MAX, 1, m, &cBinop_9ahWNTzN_sendMessage);
}

void Heavy_CircleStrings::cBinop_9ahWNTzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Q8hBtxA, HV_BINOP_SUBTRACT, 1, m, &cBinop_6Q8hBtxA_sendMessage);
}

void Heavy_CircleStrings::cCast_PYJYJsWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ph5p10w0, 0, m, &cDelay_ph5p10w0_sendMessage);
}

void Heavy_CircleStrings::cBinop_uJzNaKtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ph5p10w0, 2, m, &cDelay_ph5p10w0_sendMessage);
}

void Heavy_CircleStrings::cBinop_8oBiams5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uJzNaKtk_sendMessage);
}

void Heavy_CircleStrings::cCast_ib0DBWFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0FKAwyID, 0, m, &cVar_0FKAwyID_sendMessage);
  cMsg_yAwNWvli_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_tJpUn0Ui, 0, m, &cTabhead_tJpUn0Ui_sendMessage);
}

void Heavy_CircleStrings::cMsg_rBD5Gd6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KfZ7A93p_sendMessage);
}

void Heavy_CircleStrings::cSystem_KfZ7A93p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_O9e6eUEJ_sendMessage);
}

void Heavy_CircleStrings::cDelay_tGuxLMk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tGuxLMk2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MCtAZlD1, 0, m, &cDelay_MCtAZlD1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGuxLMk2, 0, m, &cDelay_tGuxLMk2_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_37eaUNFL, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_MCtAZlD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MCtAZlD1, m);
  cMsg_Bbybv83y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_HSSbAtXO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_5srg7u9r_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_ycfVXhns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n7svPUED_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_SUZvKEGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fni5glPT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGuxLMk2, 2, m, &cDelay_tGuxLMk2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XeLavwuX_sendMessage);
}

void Heavy_CircleStrings::cMsg_n7svPUED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_SUZvKEGd, 0, m, &hTable_SUZvKEGd_sendMessage);
}

void Heavy_CircleStrings::cBinop_O9e6eUEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_ycfVXhns_sendMessage);
}

void Heavy_CircleStrings::cMsg_Bbybv83y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_SUZvKEGd, 0, m, &hTable_SUZvKEGd_sendMessage);
}

void Heavy_CircleStrings::cCast_XeLavwuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGuxLMk2, 0, m, &cDelay_tGuxLMk2_sendMessage);
}

void Heavy_CircleStrings::cMsg_fni5glPT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_MCtAZlD1, 2, m, &cDelay_MCtAZlD1_sendMessage);
}

void Heavy_CircleStrings::cMsg_5srg7u9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_37eaUNFL, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_ahClQidq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aHLCIKsy, HV_BINOP_SUBTRACT, 0, m, &cBinop_aHLCIKsy_sendMessage);
}

void Heavy_CircleStrings::cMsg_CTXjXire_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pLIVK53S_sendMessage);
}

void Heavy_CircleStrings::cSystem_pLIVK53S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wYKtXJ9h_sendMessage);
}

void Heavy_CircleStrings::cVar_s0FJfxtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lqNJPVeK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_qRtSDF9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qRtSDF9T, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VMg2Ba3F, 0, m, &cDelay_VMg2Ba3F_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WxIVxT4O, 0, m, &sTabread_WxIVxT4O_sendMessage);
}

void Heavy_CircleStrings::cDelay_VMg2Ba3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VMg2Ba3F, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WxIVxT4O, 0, m, &sTabread_WxIVxT4O_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VMg2Ba3F, 0, m, &cDelay_VMg2Ba3F_sendMessage);
}

void Heavy_CircleStrings::sTabread_WxIVxT4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3iGfqqzM, HV_BINOP_SUBTRACT, 0, m, &cBinop_3iGfqqzM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_wAgveC5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tPZsoAQs, HV_BINOP_MAX, 0, m, &cBinop_tPZsoAQs_sendMessage);
}

void Heavy_CircleStrings::cBinop_wYKtXJ9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wAgveC5g, HV_BINOP_MULTIPLY, 0, m, &cBinop_wAgveC5g_sendMessage);
}

void Heavy_CircleStrings::cBinop_aHLCIKsy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w3dfp69P_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WxIVxT4O, 0, m, &sTabread_WxIVxT4O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PIUXOkyY_sendMessage);
}

void Heavy_CircleStrings::cSystem_YM9PFuTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3iGfqqzM, HV_BINOP_SUBTRACT, 1, m, &cBinop_3iGfqqzM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VMg2Ba3F, 2, m, &cDelay_VMg2Ba3F_sendMessage);
}

void Heavy_CircleStrings::cMsg_lqNJPVeK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YM9PFuTv_sendMessage);
}

void Heavy_CircleStrings::cMsg_w3dfp69P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qRtSDF9T, 0, m, &cDelay_qRtSDF9T_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VMg2Ba3F, 0, m, &cDelay_VMg2Ba3F_sendMessage);
}

void Heavy_CircleStrings::cMsg_BckEHZ5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_tPZsoAQs, HV_BINOP_MAX, 1, m, &cBinop_tPZsoAQs_sendMessage);
}

void Heavy_CircleStrings::cBinop_tPZsoAQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aHLCIKsy, HV_BINOP_SUBTRACT, 1, m, &cBinop_aHLCIKsy_sendMessage);
}

void Heavy_CircleStrings::cCast_PIUXOkyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qRtSDF9T, 0, m, &cDelay_qRtSDF9T_sendMessage);
}

void Heavy_CircleStrings::cBinop_3yt5Dcwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qRtSDF9T, 2, m, &cDelay_qRtSDF9T_sendMessage);
}

void Heavy_CircleStrings::cBinop_3iGfqqzM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3yt5Dcwk_sendMessage);
}

void Heavy_CircleStrings::cCast_bNThgR3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s0FJfxtI, 0, m, &cVar_s0FJfxtI_sendMessage);
  cMsg_CTXjXire_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ahClQidq, 0, m, &cTabhead_ahClQidq_sendMessage);
}

void Heavy_CircleStrings::cMsg_6Tm4PJhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_54kiTlA6_sendMessage);
}

void Heavy_CircleStrings::cSystem_54kiTlA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_S9V572C0_sendMessage);
}

void Heavy_CircleStrings::cDelay_TAH5LvHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TAH5LvHl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vblUNzP5, 0, m, &cDelay_vblUNzP5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TAH5LvHl, 0, m, &cDelay_TAH5LvHl_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uz9Jpa5M, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_vblUNzP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vblUNzP5, m);
  cMsg_VgXeWVSa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_CZzssE9x_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Zo82EPCA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_9B4xY2Ue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YxFidugJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_fZ5w8oEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tOR7Hu5o_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TAH5LvHl, 2, m, &cDelay_TAH5LvHl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hTJ4fL4k_sendMessage);
}

void Heavy_CircleStrings::cMsg_YxFidugJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_fZ5w8oEv, 0, m, &hTable_fZ5w8oEv_sendMessage);
}

void Heavy_CircleStrings::cBinop_S9V572C0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_9B4xY2Ue_sendMessage);
}

void Heavy_CircleStrings::cMsg_VgXeWVSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_fZ5w8oEv, 0, m, &hTable_fZ5w8oEv_sendMessage);
}

void Heavy_CircleStrings::cCast_hTJ4fL4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TAH5LvHl, 0, m, &cDelay_TAH5LvHl_sendMessage);
}

void Heavy_CircleStrings::cMsg_tOR7Hu5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vblUNzP5, 2, m, &cDelay_vblUNzP5_sendMessage);
}

void Heavy_CircleStrings::cMsg_Zo82EPCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uz9Jpa5M, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_igCz614T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vBGBj4DF, HV_BINOP_SUBTRACT, 0, m, &cBinop_vBGBj4DF_sendMessage);
}

void Heavy_CircleStrings::cMsg_Qyugvq4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4B2TQTc9_sendMessage);
}

void Heavy_CircleStrings::cSystem_4B2TQTc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_c6IIDToB_sendMessage);
}

void Heavy_CircleStrings::cVar_8ViM6zyz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D5emPeA2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_cEbkewMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cEbkewMW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0yu7sHB, 0, m, &cDelay_P0yu7sHB_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qGZvrzA1, 0, m, &sTabread_qGZvrzA1_sendMessage);
}

void Heavy_CircleStrings::cDelay_P0yu7sHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_P0yu7sHB, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qGZvrzA1, 0, m, &sTabread_qGZvrzA1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0yu7sHB, 0, m, &cDelay_P0yu7sHB_sendMessage);
}

void Heavy_CircleStrings::sTabread_qGZvrzA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3Fb4mbld, HV_BINOP_SUBTRACT, 0, m, &cBinop_3Fb4mbld_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Efyedv8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aOdCszXR, HV_BINOP_MAX, 0, m, &cBinop_aOdCszXR_sendMessage);
}

void Heavy_CircleStrings::cBinop_c6IIDToB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Efyedv8i, HV_BINOP_MULTIPLY, 0, m, &cBinop_Efyedv8i_sendMessage);
}

void Heavy_CircleStrings::cBinop_vBGBj4DF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OK3aZXwQ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qGZvrzA1, 0, m, &sTabread_qGZvrzA1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nBW9hGTM_sendMessage);
}

void Heavy_CircleStrings::cSystem_9bKmZPQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Fb4mbld, HV_BINOP_SUBTRACT, 1, m, &cBinop_3Fb4mbld_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0yu7sHB, 2, m, &cDelay_P0yu7sHB_sendMessage);
}

void Heavy_CircleStrings::cMsg_D5emPeA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9bKmZPQm_sendMessage);
}

void Heavy_CircleStrings::cMsg_OK3aZXwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cEbkewMW, 0, m, &cDelay_cEbkewMW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0yu7sHB, 0, m, &cDelay_P0yu7sHB_sendMessage);
}

void Heavy_CircleStrings::cMsg_vxrjQWcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_aOdCszXR, HV_BINOP_MAX, 1, m, &cBinop_aOdCszXR_sendMessage);
}

void Heavy_CircleStrings::cBinop_aOdCszXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vBGBj4DF, HV_BINOP_SUBTRACT, 1, m, &cBinop_vBGBj4DF_sendMessage);
}

void Heavy_CircleStrings::cCast_nBW9hGTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cEbkewMW, 0, m, &cDelay_cEbkewMW_sendMessage);
}

void Heavy_CircleStrings::cBinop_nAja1C3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cEbkewMW, 2, m, &cDelay_cEbkewMW_sendMessage);
}

void Heavy_CircleStrings::cBinop_3Fb4mbld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nAja1C3w_sendMessage);
}

void Heavy_CircleStrings::cCast_lVzG98VI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8ViM6zyz, 0, m, &cVar_8ViM6zyz_sendMessage);
  cMsg_Qyugvq4V_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_igCz614T, 0, m, &cTabhead_igCz614T_sendMessage);
}

void Heavy_CircleStrings::cMsg_lfI8mxPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zysJIb7q_sendMessage);
}

void Heavy_CircleStrings::cSystem_zysJIb7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_w8kuh69C_sendMessage);
}

void Heavy_CircleStrings::cDelay_mhZFYoIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mhZFYoIb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YVfv9Kn3, 0, m, &cDelay_YVfv9Kn3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mhZFYoIb, 0, m, &cDelay_mhZFYoIb_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dr04uzNw, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_YVfv9Kn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YVfv9Kn3, m);
  cMsg_3vEpdk4B_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_BIGAR1Ze_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_XntVexPW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_NCb03QVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tPJds6qg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Vr4L87pS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gnUgUmkX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mhZFYoIb, 2, m, &cDelay_mhZFYoIb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xeJS38Q2_sendMessage);
}

void Heavy_CircleStrings::cMsg_tPJds6qg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Vr4L87pS, 0, m, &hTable_Vr4L87pS_sendMessage);
}

void Heavy_CircleStrings::cBinop_w8kuh69C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_NCb03QVc_sendMessage);
}

void Heavy_CircleStrings::cMsg_3vEpdk4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Vr4L87pS, 0, m, &hTable_Vr4L87pS_sendMessage);
}

void Heavy_CircleStrings::cCast_xeJS38Q2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mhZFYoIb, 0, m, &cDelay_mhZFYoIb_sendMessage);
}

void Heavy_CircleStrings::cMsg_gnUgUmkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_YVfv9Kn3, 2, m, &cDelay_YVfv9Kn3_sendMessage);
}

void Heavy_CircleStrings::cMsg_XntVexPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dr04uzNw, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_3pxL6LtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gU40wdjm, HV_BINOP_SUBTRACT, 0, m, &cBinop_gU40wdjm_sendMessage);
}

void Heavy_CircleStrings::cMsg_nP4K7X24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SLuPPZKK_sendMessage);
}

void Heavy_CircleStrings::cSystem_SLuPPZKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wiUtqHsz_sendMessage);
}

void Heavy_CircleStrings::cVar_YeFadlNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_swefcxOh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_AOq2H3Vc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AOq2H3Vc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCLqiNoD, 0, m, &cDelay_mCLqiNoD_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_rRDj5oBk, 0, m, &sTabread_rRDj5oBk_sendMessage);
}

void Heavy_CircleStrings::cDelay_mCLqiNoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mCLqiNoD, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_rRDj5oBk, 0, m, &sTabread_rRDj5oBk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCLqiNoD, 0, m, &cDelay_mCLqiNoD_sendMessage);
}

void Heavy_CircleStrings::sTabread_rRDj5oBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hUULaHQs, HV_BINOP_SUBTRACT, 0, m, &cBinop_hUULaHQs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_28W0WgpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lNTamTY1, HV_BINOP_MAX, 0, m, &cBinop_lNTamTY1_sendMessage);
}

void Heavy_CircleStrings::cBinop_wiUtqHsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_28W0WgpF, HV_BINOP_MULTIPLY, 0, m, &cBinop_28W0WgpF_sendMessage);
}

void Heavy_CircleStrings::cBinop_gU40wdjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4FtAJsZi_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_rRDj5oBk, 0, m, &sTabread_rRDj5oBk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y4LGgoSI_sendMessage);
}

void Heavy_CircleStrings::cSystem_mebicJWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hUULaHQs, HV_BINOP_SUBTRACT, 1, m, &cBinop_hUULaHQs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCLqiNoD, 2, m, &cDelay_mCLqiNoD_sendMessage);
}

void Heavy_CircleStrings::cMsg_swefcxOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mebicJWI_sendMessage);
}

void Heavy_CircleStrings::cMsg_4FtAJsZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_AOq2H3Vc, 0, m, &cDelay_AOq2H3Vc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCLqiNoD, 0, m, &cDelay_mCLqiNoD_sendMessage);
}

void Heavy_CircleStrings::cMsg_WcewjlGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_lNTamTY1, HV_BINOP_MAX, 1, m, &cBinop_lNTamTY1_sendMessage);
}

void Heavy_CircleStrings::cBinop_lNTamTY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gU40wdjm, HV_BINOP_SUBTRACT, 1, m, &cBinop_gU40wdjm_sendMessage);
}

void Heavy_CircleStrings::cCast_Y4LGgoSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AOq2H3Vc, 0, m, &cDelay_AOq2H3Vc_sendMessage);
}

void Heavy_CircleStrings::cBinop_vancRoOe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AOq2H3Vc, 2, m, &cDelay_AOq2H3Vc_sendMessage);
}

void Heavy_CircleStrings::cBinop_hUULaHQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vancRoOe_sendMessage);
}

void Heavy_CircleStrings::cCast_8YTXfjXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YeFadlNb, 0, m, &cVar_YeFadlNb_sendMessage);
  cMsg_nP4K7X24_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3pxL6LtA, 0, m, &cTabhead_3pxL6LtA_sendMessage);
}

void Heavy_CircleStrings::cMsg_nx541emA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zoItcwg1_sendMessage);
}

void Heavy_CircleStrings::cSystem_zoItcwg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sei5k8b7_sendMessage);
}

void Heavy_CircleStrings::cDelay_KK3DNTlh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KK3DNTlh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_afP5Uxk6, 0, m, &cDelay_afP5Uxk6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KK3DNTlh, 0, m, &cDelay_KK3DNTlh_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vZOYBlLw, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_afP5Uxk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_afP5Uxk6, m);
  cMsg_4bKIyAHG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_AeTVnepH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_F1EXTljS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_G4s5hSFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VhN3LnY1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_ctUYpoNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_48f2UoMN_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KK3DNTlh, 2, m, &cDelay_KK3DNTlh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WLtDU85o_sendMessage);
}

void Heavy_CircleStrings::cMsg_VhN3LnY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ctUYpoNB, 0, m, &hTable_ctUYpoNB_sendMessage);
}

void Heavy_CircleStrings::cBinop_sei5k8b7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_G4s5hSFj_sendMessage);
}

void Heavy_CircleStrings::cMsg_4bKIyAHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ctUYpoNB, 0, m, &hTable_ctUYpoNB_sendMessage);
}

void Heavy_CircleStrings::cCast_WLtDU85o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KK3DNTlh, 0, m, &cDelay_KK3DNTlh_sendMessage);
}

void Heavy_CircleStrings::cMsg_48f2UoMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_afP5Uxk6, 2, m, &cDelay_afP5Uxk6_sendMessage);
}

void Heavy_CircleStrings::cMsg_F1EXTljS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vZOYBlLw, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_hUHRGyTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xMFd6Umd, 0, m, &cVar_xMFd6Umd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_p5nP1Vsb, 0, m, &cVar_p5nP1Vsb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4zAHoDyb, 0, m, &cVar_4zAHoDyb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_e5pvmiNV, 0, m, &cVar_e5pvmiNV_sendMessage);
}

void Heavy_CircleStrings::cVar_e1OxD7Or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_8a0YAPtS_sendMessage);
}

void Heavy_CircleStrings::cPack_YH09VJnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_UGi5IRnl, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_p5nP1Vsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PV2MTk9R, HV_BINOP_MULTIPLY, 0, m, &cBinop_PV2MTk9R_sendMessage);
}

void Heavy_CircleStrings::cMsg_8ce2Ha80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hnsc0pJa_sendMessage);
}

void Heavy_CircleStrings::cSystem_hnsc0pJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n2APZZV1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_PV2MTk9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KjvotLCs_sendMessage);
}

void Heavy_CircleStrings::cBinop_1ZnduN08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PV2MTk9R, HV_BINOP_MULTIPLY, 1, m, &cBinop_PV2MTk9R_sendMessage);
}

void Heavy_CircleStrings::cMsg_n2APZZV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1ZnduN08_sendMessage);
}

void Heavy_CircleStrings::cBinop_KjvotLCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Ajj9lcp5_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ajj9lcp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_YAbHj1hg_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vTIe5vMR, m);
}

void Heavy_CircleStrings::cBinop_YAbHj1hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_d10dqNNT, m);
}

void Heavy_CircleStrings::cVar_4zAHoDyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_35pFbTmX, HV_BINOP_MULTIPLY, 0, m, &cBinop_35pFbTmX_sendMessage);
}

void Heavy_CircleStrings::cMsg_wnBJKrsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mGmPT67t_sendMessage);
}

void Heavy_CircleStrings::cSystem_mGmPT67t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8WoSKlCb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_35pFbTmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_hpNQYF9B_sendMessage);
}

void Heavy_CircleStrings::cBinop_3FcKWZhb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_35pFbTmX, HV_BINOP_MULTIPLY, 1, m, &cBinop_35pFbTmX_sendMessage);
}

void Heavy_CircleStrings::cMsg_8WoSKlCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_3FcKWZhb_sendMessage);
}

void Heavy_CircleStrings::cBinop_hpNQYF9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FhV4sMkH_sendMessage);
}

void Heavy_CircleStrings::cBinop_FhV4sMkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hiX5BDMq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_b4TNpUI7, m);
}

void Heavy_CircleStrings::cBinop_hiX5BDMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_g2hPNVDq, m);
}

void Heavy_CircleStrings::cVar_e5pvmiNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_97cha1yw, HV_BINOP_MULTIPLY, 0, m, &cBinop_97cha1yw_sendMessage);
}

void Heavy_CircleStrings::cMsg_lu5ndMg5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2vwrSp5l_sendMessage);
}

void Heavy_CircleStrings::cSystem_2vwrSp5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KMSwd55E_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_97cha1yw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1gGfYUpo_sendMessage);
}

void Heavy_CircleStrings::cBinop_hHfMWNze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_97cha1yw, HV_BINOP_MULTIPLY, 1, m, &cBinop_97cha1yw_sendMessage);
}

void Heavy_CircleStrings::cMsg_KMSwd55E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_hHfMWNze_sendMessage);
}

void Heavy_CircleStrings::cBinop_1gGfYUpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bpD5eIDh_sendMessage);
}

void Heavy_CircleStrings::cBinop_bpD5eIDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CAhBQQAr_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mmqL9MSY, m);
}

void Heavy_CircleStrings::cBinop_CAhBQQAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_s8UdZm21, m);
}

void Heavy_CircleStrings::cBinop_V2uWsLBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3rjzdrYq, 0, m, &cPack_3rjzdrYq_sendMessage);
}

void Heavy_CircleStrings::cMsg_DdLJVeN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_hUHRGyTy, 0, m, &cVar_hUHRGyTy_sendMessage);
}

void Heavy_CircleStrings::cBinop_8a0YAPtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YH09VJnt, 0, m, &cPack_YH09VJnt_sendMessage);
}

void Heavy_CircleStrings::cBinop_oaEw1vc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QdIEk6Pf, 0, m, &cPack_QdIEk6Pf_sendMessage);
}

void Heavy_CircleStrings::cIf_nI1hM6dO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_xacm4EqQ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_q33SJfHg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_q33SJfHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_cl6eX79r_sendMessage);
}

void Heavy_CircleStrings::cCast_16vLaW8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hINKogRU_sendMessage);
}

void Heavy_CircleStrings::cCast_7jaK7Hvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nI1hM6dO, 0, m, &cIf_nI1hM6dO_sendMessage);
}

void Heavy_CircleStrings::cMsg_xacm4EqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_VfzSWenc, 0, m, &cVar_VfzSWenc_sendMessage);
}

void Heavy_CircleStrings::cBinop_cl6eX79r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_C8uGr4KP_sendMessage);
}

void Heavy_CircleStrings::cBinop_C8uGr4KP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QopVcqan_sendMessage);
}

void Heavy_CircleStrings::cBinop_QopVcqan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VfzSWenc, 0, m, &cVar_VfzSWenc_sendMessage);
}

void Heavy_CircleStrings::cBinop_hINKogRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nI1hM6dO, 1, m, &cIf_nI1hM6dO_sendMessage);
}

void Heavy_CircleStrings::cBinop_wMH3zFo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_16vLaW8U_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7jaK7Hvn_sendMessage);
}

void Heavy_CircleStrings::cBinop_Xydlevi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wMH3zFo0_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_pWGCE2EC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_vrcUchk9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_vrcUchk9_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_DWXnXF13, 1, m, &cDelay_DWXnXF13_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hZE9NCkm_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_DWXnXF13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DWXnXF13, m);
  cMsg_n2NpkSqp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_vrcUchk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DWXnXF13, 0, m, &cDelay_DWXnXF13_sendMessage);
}

void Heavy_CircleStrings::cCast_hZE9NCkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DWXnXF13, 0, m, &cDelay_DWXnXF13_sendMessage);
}

void Heavy_CircleStrings::cVar_9WfADkx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hCok8V62, 0, m, &cPack_hCok8V62_sendMessage);
}

void Heavy_CircleStrings::cVar_w8oJaENN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_i6OPixhF_sendMessage);
}

void Heavy_CircleStrings::cVar_w2VsFbcN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_CPPyeV6Z_sendMessage);
}

void Heavy_CircleStrings::cPack_u9Dd3idu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LerpTV8g, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_TEQFdWlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_0KEmsfhw_sendMessage);
}

void Heavy_CircleStrings::cBinop_esBn2hZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_TEQFdWlA_sendMessage);
}

void Heavy_CircleStrings::cPack_4acrvLYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_bo2adHae, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_lWNDLYiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_dxJzPCrS_sendMessage);
}

void Heavy_CircleStrings::cMsg_1hFLroJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MVxglGAB_sendMessage);
}

void Heavy_CircleStrings::cSystem_MVxglGAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ScPs6sYr_sendMessage);
}

void Heavy_CircleStrings::cDelay_ffwLYDn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ffwLYDn8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_B1c8Zooj, 0, m, &cDelay_B1c8Zooj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ffwLYDn8, 0, m, &cDelay_ffwLYDn8_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bzM0tjah, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_B1c8Zooj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_B1c8Zooj, m);
  cMsg_hUdMKR3J_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_4UBi9Qx2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_dS82Y3qN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_rQigG13A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CY8Rb36S_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_MrhoiJQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5XC93YUt_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ffwLYDn8, 2, m, &cDelay_ffwLYDn8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8tXzAe8h_sendMessage);
}

void Heavy_CircleStrings::cMsg_CY8Rb36S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_MrhoiJQN, 0, m, &hTable_MrhoiJQN_sendMessage);
}

void Heavy_CircleStrings::cBinop_ScPs6sYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_rQigG13A_sendMessage);
}

void Heavy_CircleStrings::cMsg_hUdMKR3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_MrhoiJQN, 0, m, &hTable_MrhoiJQN_sendMessage);
}

void Heavy_CircleStrings::cCast_8tXzAe8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ffwLYDn8, 0, m, &cDelay_ffwLYDn8_sendMessage);
}

void Heavy_CircleStrings::cMsg_5XC93YUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_B1c8Zooj, 2, m, &cDelay_B1c8Zooj_sendMessage);
}

void Heavy_CircleStrings::cMsg_dS82Y3qN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bzM0tjah, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_33T60Nq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xQyWo7rd_sendMessage);
}

void Heavy_CircleStrings::cSystem_xQyWo7rd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5kJiuXV9_sendMessage);
}

void Heavy_CircleStrings::cVar_KN5K6XkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X3FDPNDA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_swPKFxVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_WdMCqMvs_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pCmpeTQ1, m);
}

void Heavy_CircleStrings::cBinop_5kJiuXV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0OA4xBf8, m);
}

void Heavy_CircleStrings::cMsg_X3FDPNDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_swPKFxVG_sendMessage);
}

void Heavy_CircleStrings::cBinop_WdMCqMvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_09g6lkS6, m);
}

void Heavy_CircleStrings::cMsg_ADjrUxu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0Y5EUXMR_sendMessage);
}

void Heavy_CircleStrings::cSystem_0Y5EUXMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_toJ3UJx7_sendMessage);
}

void Heavy_CircleStrings::cVar_ubSwnGwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZIA5sIpQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_n7wU0P8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hO34Ltuv_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OTuclQyF, m);
}

void Heavy_CircleStrings::cBinop_toJ3UJx7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cBxpEWJD, m);
}

void Heavy_CircleStrings::cMsg_ZIA5sIpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n7wU0P8A_sendMessage);
}

void Heavy_CircleStrings::cBinop_hO34Ltuv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ad5Jgohh, m);
}

void Heavy_CircleStrings::cBinop_Nu2evNtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6KTYFthe_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_kRKKzlsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_irHfeGO1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jUkwFvXz_sendMessage);
}

void Heavy_CircleStrings::cCast_irHfeGO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nu2evNtT, HV_BINOP_DIVIDE, 1, m, &cBinop_Nu2evNtT_sendMessage);
}

void Heavy_CircleStrings::cCast_jUkwFvXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nu2evNtT, HV_BINOP_DIVIDE, 0, m, &cBinop_Nu2evNtT_sendMessage);
}

void Heavy_CircleStrings::cBinop_0KEmsfhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DFnkBCIO_sendMessage);
}

void Heavy_CircleStrings::cBinop_i6OPixhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_esBn2hZL_sendMessage);
}

void Heavy_CircleStrings::cBinop_DFnkBCIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nu2evNtT, HV_BINOP_DIVIDE, 0, m, &cBinop_Nu2evNtT_sendMessage);
}

void Heavy_CircleStrings::cBinop_dxJzPCrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4acrvLYW, 0, m, &cPack_4acrvLYW_sendMessage);
}

void Heavy_CircleStrings::cBinop_CPPyeV6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_kRKKzlsZ_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_u9Dd3idu, 0, m, &cPack_u9Dd3idu_sendMessage);
}

void Heavy_CircleStrings::cMsg_7NlH8KGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_w2VsFbcN, 0, m, &cVar_w2VsFbcN_sendMessage);
}

void Heavy_CircleStrings::cMsg_k8fup9no_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_lWNDLYiQ, 0, m, &cVar_lWNDLYiQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_6KTYFthe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_v12SfsfY, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_qsfQZoTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PXqxehlR, HV_BINOP_MULTIPLY, 0, m, &cBinop_PXqxehlR_sendMessage);
}

void Heavy_CircleStrings::cMsg_unY1mZkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Bxsyz9ul_sendMessage);
}

void Heavy_CircleStrings::cSystem_Bxsyz9ul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KbDAtD1n_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_PXqxehlR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_injXVC1B_sendMessage);
}

void Heavy_CircleStrings::cBinop_91x0dd3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PXqxehlR, HV_BINOP_MULTIPLY, 1, m, &cBinop_PXqxehlR_sendMessage);
}

void Heavy_CircleStrings::cMsg_KbDAtD1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_91x0dd3w_sendMessage);
}

void Heavy_CircleStrings::cBinop_injXVC1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qOGBknLe_sendMessage);
}

void Heavy_CircleStrings::cBinop_qOGBknLe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nmfvyVK6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_N1aJPsXy, m);
}

void Heavy_CircleStrings::cBinop_nmfvyVK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q3ZbbXIh, m);
}

void Heavy_CircleStrings::cVar_kVzvChjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FI020eRN, HV_BINOP_MULTIPLY, 0, m, &cBinop_FI020eRN_sendMessage);
}

void Heavy_CircleStrings::cMsg_76vrh53M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZUDy7BT3_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZUDy7BT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dfVCCxNj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_FI020eRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_j7JPjbvX_sendMessage);
}

void Heavy_CircleStrings::cBinop_JGPavsrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FI020eRN, HV_BINOP_MULTIPLY, 1, m, &cBinop_FI020eRN_sendMessage);
}

void Heavy_CircleStrings::cMsg_dfVCCxNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JGPavsrx_sendMessage);
}

void Heavy_CircleStrings::cBinop_j7JPjbvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tfoxpxiJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_tfoxpxiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZD50iu4y_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_4EleNNMn, m);
}

void Heavy_CircleStrings::cBinop_ZD50iu4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2Sq9vG0p, m);
}

void Heavy_CircleStrings::cVar_sNT2Yjov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3VjF5LU2, HV_BINOP_MULTIPLY, 0, m, &cBinop_3VjF5LU2_sendMessage);
}

void Heavy_CircleStrings::cMsg_2LIkPi0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RCjxl3KM_sendMessage);
}

void Heavy_CircleStrings::cSystem_RCjxl3KM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XhtK9yKp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_3VjF5LU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2nj1wx5P_sendMessage);
}

void Heavy_CircleStrings::cBinop_lEFpMVS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3VjF5LU2, HV_BINOP_MULTIPLY, 1, m, &cBinop_3VjF5LU2_sendMessage);
}

void Heavy_CircleStrings::cMsg_XhtK9yKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lEFpMVS2_sendMessage);
}

void Heavy_CircleStrings::cBinop_2nj1wx5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lAKhUxEy_sendMessage);
}

void Heavy_CircleStrings::cBinop_lAKhUxEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_gPEOkKGE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ya1pw3Ca, m);
}

void Heavy_CircleStrings::cBinop_gPEOkKGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zo7qlgpD, m);
}

void Heavy_CircleStrings::cMsg_IOL5iGd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_z8BB1YGw_sendMessage);
}

void Heavy_CircleStrings::cSystem_z8BB1YGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_StJbEJX2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_c4fBgUqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_c1bfuMLR_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CQiF2sk6, 0, m, &cIf_CQiF2sk6_sendMessage);
}

void Heavy_CircleStrings::cIf_CQiF2sk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9Vy00TGV_sendMessage(_c, 0, m);
      cMsg_8OTUZFan_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_zIOLMqyW_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Rhv9rxy5_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_N1n5CvGJ, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_c1bfuMLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CQiF2sk6, 1, m, &cIf_CQiF2sk6_sendMessage);
}

void Heavy_CircleStrings::cMsg_zIOLMqyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_73HQ9cXa_sendMessage);
}

void Heavy_CircleStrings::cBinop_73HQ9cXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6AjpsSlO, m);
}

void Heavy_CircleStrings::cBinop_Rhv9rxy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_akmfh45D_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_akmfh45D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_e3dLQqGL_sendMessage);
}

void Heavy_CircleStrings::cBinop_e3dLQqGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LYa8taBx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_LYa8taBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_NzgpbkXk_sendMessage);
}

void Heavy_CircleStrings::cBinop_NzgpbkXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sGjm4a1G, m);
}

void Heavy_CircleStrings::cBinop_lX69gLXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_40TbTNja, m);
}

void Heavy_CircleStrings::cMsg_StJbEJX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lX69gLXb_sendMessage);
}

void Heavy_CircleStrings::cMsg_9Vy00TGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Rhv9rxy5_sendMessage);
}

void Heavy_CircleStrings::cMsg_8OTUZFan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6AjpsSlO, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_N1n5CvGJ, m);
}

void Heavy_CircleStrings::cBinop_9q3lMW40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kVzvChjD, 0, m, &cVar_kVzvChjD_sendMessage);
}

void Heavy_CircleStrings::cBinop_frNzYrHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qsfQZoTZ, 0, m, &cVar_qsfQZoTZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_2XyBkidx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sNT2Yjov, 0, m, &cVar_sNT2Yjov_sendMessage);
}

void Heavy_CircleStrings::cCast_vbmQTpGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_9q3lMW40_sendMessage);
}

void Heavy_CircleStrings::cCast_8dd8rxeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_frNzYrHV_sendMessage);
}

void Heavy_CircleStrings::cCast_6hDdJbFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_2XyBkidx_sendMessage);
}

void Heavy_CircleStrings::cCast_bJmUPqk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jb63r1RP, m);
}

void Heavy_CircleStrings::cTabhead_DNPChEQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CeQkL94V, HV_BINOP_SUBTRACT, 0, m, &cBinop_CeQkL94V_sendMessage);
}

void Heavy_CircleStrings::cMsg_UTRkXPAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_unHxhH6f_sendMessage);
}

void Heavy_CircleStrings::cSystem_unHxhH6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sGt5WAk3_sendMessage);
}

void Heavy_CircleStrings::cVar_2YE88RwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O3txeruS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_AK9vDhUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AK9vDhUq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wEHmn4Hf, 0, m, &cDelay_wEHmn4Hf_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EJBvAau9, 0, m, &sTabread_EJBvAau9_sendMessage);
}

void Heavy_CircleStrings::cDelay_wEHmn4Hf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wEHmn4Hf, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EJBvAau9, 0, m, &sTabread_EJBvAau9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wEHmn4Hf, 0, m, &cDelay_wEHmn4Hf_sendMessage);
}

void Heavy_CircleStrings::sTabread_EJBvAau9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yFNlFPoW, HV_BINOP_SUBTRACT, 0, m, &cBinop_yFNlFPoW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_FJGPJk0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ai1Ac0Xi, HV_BINOP_MAX, 0, m, &cBinop_ai1Ac0Xi_sendMessage);
}

void Heavy_CircleStrings::cBinop_sGt5WAk3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FJGPJk0p, HV_BINOP_MULTIPLY, 0, m, &cBinop_FJGPJk0p_sendMessage);
}

void Heavy_CircleStrings::cBinop_CeQkL94V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f96AONd5_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EJBvAau9, 0, m, &sTabread_EJBvAau9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E7RztKi5_sendMessage);
}

void Heavy_CircleStrings::cSystem_cLZ7d3As_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yFNlFPoW, HV_BINOP_SUBTRACT, 1, m, &cBinop_yFNlFPoW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wEHmn4Hf, 2, m, &cDelay_wEHmn4Hf_sendMessage);
}

void Heavy_CircleStrings::cMsg_O3txeruS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cLZ7d3As_sendMessage);
}

void Heavy_CircleStrings::cMsg_f96AONd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_AK9vDhUq, 0, m, &cDelay_AK9vDhUq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wEHmn4Hf, 0, m, &cDelay_wEHmn4Hf_sendMessage);
}

void Heavy_CircleStrings::cMsg_NBvopWRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ai1Ac0Xi, HV_BINOP_MAX, 1, m, &cBinop_ai1Ac0Xi_sendMessage);
}

void Heavy_CircleStrings::cBinop_ai1Ac0Xi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CeQkL94V, HV_BINOP_SUBTRACT, 1, m, &cBinop_CeQkL94V_sendMessage);
}

void Heavy_CircleStrings::cCast_E7RztKi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AK9vDhUq, 0, m, &cDelay_AK9vDhUq_sendMessage);
}

void Heavy_CircleStrings::cBinop_kSy1YBcl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AK9vDhUq, 2, m, &cDelay_AK9vDhUq_sendMessage);
}

void Heavy_CircleStrings::cBinop_yFNlFPoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kSy1YBcl_sendMessage);
}

void Heavy_CircleStrings::cCast_2kUY4fHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2YE88RwP, 0, m, &cVar_2YE88RwP_sendMessage);
  cMsg_UTRkXPAK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DNPChEQS, 0, m, &cTabhead_DNPChEQS_sendMessage);
}

void Heavy_CircleStrings::cTabhead_g1MpEJ9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cev1rstu, HV_BINOP_SUBTRACT, 0, m, &cBinop_Cev1rstu_sendMessage);
}

void Heavy_CircleStrings::cMsg_jI14kHCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hXUKS3PP_sendMessage);
}

void Heavy_CircleStrings::cSystem_hXUKS3PP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mUEHktf6_sendMessage);
}

void Heavy_CircleStrings::cVar_lTy1gy5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lMwLTiYc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_8W39j2Fd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8W39j2Fd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eg4S9P2U, 0, m, &cDelay_eg4S9P2U_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_l2D07D0n, 0, m, &sTabread_l2D07D0n_sendMessage);
}

void Heavy_CircleStrings::cDelay_eg4S9P2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eg4S9P2U, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_l2D07D0n, 0, m, &sTabread_l2D07D0n_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eg4S9P2U, 0, m, &cDelay_eg4S9P2U_sendMessage);
}

void Heavy_CircleStrings::sTabread_l2D07D0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Hb1NQpW1, HV_BINOP_SUBTRACT, 0, m, &cBinop_Hb1NQpW1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_QMZ4hwDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cl17xvlf, HV_BINOP_MAX, 0, m, &cBinop_cl17xvlf_sendMessage);
}

void Heavy_CircleStrings::cBinop_mUEHktf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QMZ4hwDb, HV_BINOP_MULTIPLY, 0, m, &cBinop_QMZ4hwDb_sendMessage);
}

void Heavy_CircleStrings::cBinop_Cev1rstu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4OSIW8pj_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_l2D07D0n, 0, m, &sTabread_l2D07D0n_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e3PqariR_sendMessage);
}

void Heavy_CircleStrings::cSystem_WpO9BcHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hb1NQpW1, HV_BINOP_SUBTRACT, 1, m, &cBinop_Hb1NQpW1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eg4S9P2U, 2, m, &cDelay_eg4S9P2U_sendMessage);
}

void Heavy_CircleStrings::cMsg_lMwLTiYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WpO9BcHY_sendMessage);
}

void Heavy_CircleStrings::cMsg_4OSIW8pj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8W39j2Fd, 0, m, &cDelay_8W39j2Fd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eg4S9P2U, 0, m, &cDelay_eg4S9P2U_sendMessage);
}

void Heavy_CircleStrings::cMsg_bAhOeku0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cl17xvlf, HV_BINOP_MAX, 1, m, &cBinop_cl17xvlf_sendMessage);
}

void Heavy_CircleStrings::cBinop_cl17xvlf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cev1rstu, HV_BINOP_SUBTRACT, 1, m, &cBinop_Cev1rstu_sendMessage);
}

void Heavy_CircleStrings::cCast_e3PqariR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8W39j2Fd, 0, m, &cDelay_8W39j2Fd_sendMessage);
}

void Heavy_CircleStrings::cBinop_l8RbHaXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8W39j2Fd, 2, m, &cDelay_8W39j2Fd_sendMessage);
}

void Heavy_CircleStrings::cBinop_Hb1NQpW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_l8RbHaXn_sendMessage);
}

void Heavy_CircleStrings::cCast_LCsZSwv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lTy1gy5J, 0, m, &cVar_lTy1gy5J_sendMessage);
  cMsg_jI14kHCx_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g1MpEJ9G, 0, m, &cTabhead_g1MpEJ9G_sendMessage);
}

void Heavy_CircleStrings::cTabhead_5z6vlxjx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LqmnWAhc, HV_BINOP_SUBTRACT, 0, m, &cBinop_LqmnWAhc_sendMessage);
}

void Heavy_CircleStrings::cMsg_r8tYlXz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_i8QqAaGo_sendMessage);
}

void Heavy_CircleStrings::cSystem_i8QqAaGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZhrpCMsv_sendMessage);
}

void Heavy_CircleStrings::cVar_I6cwotqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8jyVhvry_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_52Rc1E32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_52Rc1E32, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dZBnQnj9, 0, m, &cDelay_dZBnQnj9_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_v5JWWHtr, 0, m, &sTabread_v5JWWHtr_sendMessage);
}

void Heavy_CircleStrings::cDelay_dZBnQnj9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dZBnQnj9, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_v5JWWHtr, 0, m, &sTabread_v5JWWHtr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dZBnQnj9, 0, m, &cDelay_dZBnQnj9_sendMessage);
}

void Heavy_CircleStrings::sTabread_v5JWWHtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_10xVHTxJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_10xVHTxJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KvSl98vH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1AOnfvdA, HV_BINOP_MAX, 0, m, &cBinop_1AOnfvdA_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZhrpCMsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KvSl98vH, HV_BINOP_MULTIPLY, 0, m, &cBinop_KvSl98vH_sendMessage);
}

void Heavy_CircleStrings::cBinop_LqmnWAhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EjSNQgtc_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_v5JWWHtr, 0, m, &sTabread_v5JWWHtr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZObi2bl1_sendMessage);
}

void Heavy_CircleStrings::cSystem_G5lzsfnQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_10xVHTxJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_10xVHTxJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dZBnQnj9, 2, m, &cDelay_dZBnQnj9_sendMessage);
}

void Heavy_CircleStrings::cMsg_8jyVhvry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_G5lzsfnQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_EjSNQgtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_52Rc1E32, 0, m, &cDelay_52Rc1E32_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dZBnQnj9, 0, m, &cDelay_dZBnQnj9_sendMessage);
}

void Heavy_CircleStrings::cMsg_fGLXeP1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_1AOnfvdA, HV_BINOP_MAX, 1, m, &cBinop_1AOnfvdA_sendMessage);
}

void Heavy_CircleStrings::cBinop_1AOnfvdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LqmnWAhc, HV_BINOP_SUBTRACT, 1, m, &cBinop_LqmnWAhc_sendMessage);
}

void Heavy_CircleStrings::cCast_ZObi2bl1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_52Rc1E32, 0, m, &cDelay_52Rc1E32_sendMessage);
}

void Heavy_CircleStrings::cBinop_YkAQ4nkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_52Rc1E32, 2, m, &cDelay_52Rc1E32_sendMessage);
}

void Heavy_CircleStrings::cBinop_10xVHTxJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YkAQ4nkv_sendMessage);
}

void Heavy_CircleStrings::cCast_PuEJG8qs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I6cwotqR, 0, m, &cVar_I6cwotqR_sendMessage);
  cMsg_r8tYlXz5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5z6vlxjx, 0, m, &cTabhead_5z6vlxjx_sendMessage);
}

void Heavy_CircleStrings::cTabhead_OdTKQRDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Isiv2AMa, HV_BINOP_SUBTRACT, 0, m, &cBinop_Isiv2AMa_sendMessage);
}

void Heavy_CircleStrings::cMsg_988gaDam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aTVTcnnn_sendMessage);
}

void Heavy_CircleStrings::cSystem_aTVTcnnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4yruufgG_sendMessage);
}

void Heavy_CircleStrings::cVar_11iJBhOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1AuMtfrV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_pP89vFbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pP89vFbX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OeKCIhRO, 0, m, &cDelay_OeKCIhRO_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gy8b0rpi, 0, m, &sTabread_gy8b0rpi_sendMessage);
}

void Heavy_CircleStrings::cDelay_OeKCIhRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OeKCIhRO, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gy8b0rpi, 0, m, &sTabread_gy8b0rpi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OeKCIhRO, 0, m, &cDelay_OeKCIhRO_sendMessage);
}

void Heavy_CircleStrings::sTabread_gy8b0rpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_frFHJgtL, HV_BINOP_SUBTRACT, 0, m, &cBinop_frFHJgtL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_1eVGcvXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NN9BU77s, HV_BINOP_MAX, 0, m, &cBinop_NN9BU77s_sendMessage);
}

void Heavy_CircleStrings::cBinop_4yruufgG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1eVGcvXW, HV_BINOP_MULTIPLY, 0, m, &cBinop_1eVGcvXW_sendMessage);
}

void Heavy_CircleStrings::cBinop_Isiv2AMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZqNepi9N_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gy8b0rpi, 0, m, &sTabread_gy8b0rpi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fHFaVJe7_sendMessage);
}

void Heavy_CircleStrings::cSystem_vy0Vjp24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_frFHJgtL, HV_BINOP_SUBTRACT, 1, m, &cBinop_frFHJgtL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OeKCIhRO, 2, m, &cDelay_OeKCIhRO_sendMessage);
}

void Heavy_CircleStrings::cMsg_1AuMtfrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vy0Vjp24_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZqNepi9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pP89vFbX, 0, m, &cDelay_pP89vFbX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OeKCIhRO, 0, m, &cDelay_OeKCIhRO_sendMessage);
}

void Heavy_CircleStrings::cMsg_qCJ9LNfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_NN9BU77s, HV_BINOP_MAX, 1, m, &cBinop_NN9BU77s_sendMessage);
}

void Heavy_CircleStrings::cBinop_NN9BU77s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Isiv2AMa, HV_BINOP_SUBTRACT, 1, m, &cBinop_Isiv2AMa_sendMessage);
}

void Heavy_CircleStrings::cCast_fHFaVJe7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pP89vFbX, 0, m, &cDelay_pP89vFbX_sendMessage);
}

void Heavy_CircleStrings::cBinop_A2yTwUve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pP89vFbX, 2, m, &cDelay_pP89vFbX_sendMessage);
}

void Heavy_CircleStrings::cBinop_frFHJgtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_A2yTwUve_sendMessage);
}

void Heavy_CircleStrings::cCast_PA6Swah0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_11iJBhOP, 0, m, &cVar_11iJBhOP_sendMessage);
  cMsg_988gaDam_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OdTKQRDD, 0, m, &cTabhead_OdTKQRDD_sendMessage);
}

void Heavy_CircleStrings::cMsg_klCiuYm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4C3tsdzu_sendMessage);
}

void Heavy_CircleStrings::cSystem_4C3tsdzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_D2nhJDdd_sendMessage);
}

void Heavy_CircleStrings::cDelay_Vp96MMtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Vp96MMtq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4FGIwCBf, 0, m, &cDelay_4FGIwCBf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Vp96MMtq, 0, m, &cDelay_Vp96MMtq_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tnrQ1xv0, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_4FGIwCBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4FGIwCBf, m);
  cMsg_ghtIvTsz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_MY006gn1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_msHy8fV2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_arf54YYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V2DYNWUD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_hTWSoF5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6YHT13sf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Vp96MMtq, 2, m, &cDelay_Vp96MMtq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ipOYvbp2_sendMessage);
}

void Heavy_CircleStrings::cMsg_V2DYNWUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_hTWSoF5b, 0, m, &hTable_hTWSoF5b_sendMessage);
}

void Heavy_CircleStrings::cBinop_D2nhJDdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_arf54YYU_sendMessage);
}

void Heavy_CircleStrings::cMsg_ghtIvTsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_hTWSoF5b, 0, m, &hTable_hTWSoF5b_sendMessage);
}

void Heavy_CircleStrings::cCast_ipOYvbp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Vp96MMtq, 0, m, &cDelay_Vp96MMtq_sendMessage);
}

void Heavy_CircleStrings::cMsg_6YHT13sf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_4FGIwCBf, 2, m, &cDelay_4FGIwCBf_sendMessage);
}

void Heavy_CircleStrings::cMsg_msHy8fV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tnrQ1xv0, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_LnBqmdIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yEi6v522_sendMessage);
}

void Heavy_CircleStrings::cSystem_yEi6v522_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aVG91UwE_sendMessage);
}

void Heavy_CircleStrings::cDelay_94I6yV7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_94I6yV7L, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SXGb7vJq, 0, m, &cDelay_SXGb7vJq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_94I6yV7L, 0, m, &cDelay_94I6yV7L_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_urgLMwdS, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_SXGb7vJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SXGb7vJq, m);
  cMsg_luNbazSi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_V8khkVcm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_1MDwCHqd_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_mxGyjGOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_32UZAntG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_COEgQSwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nf2M5rGy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_94I6yV7L, 2, m, &cDelay_94I6yV7L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JYxqxdwr_sendMessage);
}

void Heavy_CircleStrings::cMsg_32UZAntG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_COEgQSwC, 0, m, &hTable_COEgQSwC_sendMessage);
}

void Heavy_CircleStrings::cBinop_aVG91UwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_mxGyjGOY_sendMessage);
}

void Heavy_CircleStrings::cMsg_luNbazSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_COEgQSwC, 0, m, &hTable_COEgQSwC_sendMessage);
}

void Heavy_CircleStrings::cCast_JYxqxdwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_94I6yV7L, 0, m, &cDelay_94I6yV7L_sendMessage);
}

void Heavy_CircleStrings::cMsg_nf2M5rGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_SXGb7vJq, 2, m, &cDelay_SXGb7vJq_sendMessage);
}

void Heavy_CircleStrings::cMsg_1MDwCHqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_urgLMwdS, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_gm69viNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fZX6syxU_sendMessage);
}

void Heavy_CircleStrings::cSystem_fZX6syxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ua2vs4Ge_sendMessage);
}

void Heavy_CircleStrings::cDelay_KQdAotWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KQdAotWJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TL5Ir6Gl, 0, m, &cDelay_TL5Ir6Gl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KQdAotWJ, 0, m, &cDelay_KQdAotWJ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ip1N1KtB, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_TL5Ir6Gl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TL5Ir6Gl, m);
  cMsg_rPTyO4Ev_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_UYY1VUSz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jnMK24mB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_qR5Ecoza_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EM8GsH4h_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_mCl2Tskq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZB0608qK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KQdAotWJ, 2, m, &cDelay_KQdAotWJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZqskxnyT_sendMessage);
}

void Heavy_CircleStrings::cMsg_EM8GsH4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_mCl2Tskq, 0, m, &hTable_mCl2Tskq_sendMessage);
}

void Heavy_CircleStrings::cBinop_ua2vs4Ge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_qR5Ecoza_sendMessage);
}

void Heavy_CircleStrings::cMsg_rPTyO4Ev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_mCl2Tskq, 0, m, &hTable_mCl2Tskq_sendMessage);
}

void Heavy_CircleStrings::cCast_ZqskxnyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KQdAotWJ, 0, m, &cDelay_KQdAotWJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZB0608qK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_TL5Ir6Gl, 2, m, &cDelay_TL5Ir6Gl_sendMessage);
}

void Heavy_CircleStrings::cMsg_jnMK24mB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ip1N1KtB, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_75NmRBVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jrfz4F1e_sendMessage);
}

void Heavy_CircleStrings::cSystem_jrfz4F1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dF2SGAcS_sendMessage);
}

void Heavy_CircleStrings::cDelay_4sPu91QU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4sPu91QU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WSiuzNXa, 0, m, &cDelay_WSiuzNXa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4sPu91QU, 0, m, &cDelay_4sPu91QU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BTZrwd7U, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_WSiuzNXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WSiuzNXa, m);
  cMsg_mCY6s2vf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_SkSxPXbb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_lReAqPGJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_wEhX42q5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OYFcxBJm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_DrpcdFvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K467EtN3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4sPu91QU, 2, m, &cDelay_4sPu91QU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SrTVc1vK_sendMessage);
}

void Heavy_CircleStrings::cMsg_OYFcxBJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_DrpcdFvR, 0, m, &hTable_DrpcdFvR_sendMessage);
}

void Heavy_CircleStrings::cBinop_dF2SGAcS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_wEhX42q5_sendMessage);
}

void Heavy_CircleStrings::cMsg_mCY6s2vf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_DrpcdFvR, 0, m, &hTable_DrpcdFvR_sendMessage);
}

void Heavy_CircleStrings::cCast_SrTVc1vK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4sPu91QU, 0, m, &cDelay_4sPu91QU_sendMessage);
}

void Heavy_CircleStrings::cMsg_K467EtN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WSiuzNXa, 2, m, &cDelay_WSiuzNXa_sendMessage);
}

void Heavy_CircleStrings::cMsg_lReAqPGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BTZrwd7U, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_HjIZsVBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gY0Ga5Zk_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_15VQITMf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_qGMAy2Gd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fgc1Ix6S, HV_BINOP_POW, 0, m, &cBinop_fgc1Ix6S_sendMessage);
}

void Heavy_CircleStrings::cBinop_fgc1Ix6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_jbg7kqCU_sendMessage);
}

void Heavy_CircleStrings::cBinop_WdpYTvst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_dW0mGcD2_sendMessage);
}

void Heavy_CircleStrings::cCast_mV5amkgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_NUBc4gET_sendMessage);
}

void Heavy_CircleStrings::cCast_tRKiQQ5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HjIZsVBe, 0, m, &cIf_HjIZsVBe_sendMessage);
}

void Heavy_CircleStrings::cBinop_NUBc4gET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HjIZsVBe, 1, m, &cIf_HjIZsVBe_sendMessage);
}

void Heavy_CircleStrings::cBinop_15VQITMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_WdpYTvst_sendMessage);
}

void Heavy_CircleStrings::cMsg_gY0Ga5Zk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_jbg7kqCU_sendMessage);
}

void Heavy_CircleStrings::cBinop_dW0mGcD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fgc1Ix6S, HV_BINOP_POW, 1, m, &cBinop_fgc1Ix6S_sendMessage);
  cMsg_qGMAy2Gd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_y24qzzD4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VjsKZ0ko, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_RouwySvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mm0zyZRY, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_OPTb0sKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gi1cxohq_sendMessage);
}

void Heavy_CircleStrings::cBinop_gi1cxohq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_9bET2Ijg_sendMessage);
}

void Heavy_CircleStrings::cVar_jRn8pWdq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MW1jpzf3, HV_BINOP_MULTIPLY, 0, m, &cBinop_MW1jpzf3_sendMessage);
}

void Heavy_CircleStrings::cMsg_6ZDniLVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_phEQsNyI_sendMessage);
}

void Heavy_CircleStrings::cSystem_phEQsNyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9CaOEvRW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_MW1jpzf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_TgBEFW7V_sendMessage);
}

void Heavy_CircleStrings::cBinop_CkgPOAX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MW1jpzf3, HV_BINOP_MULTIPLY, 1, m, &cBinop_MW1jpzf3_sendMessage);
}

void Heavy_CircleStrings::cMsg_9CaOEvRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CkgPOAX2_sendMessage);
}

void Heavy_CircleStrings::cBinop_TgBEFW7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Xzx9Uhud_sendMessage);
}

void Heavy_CircleStrings::cBinop_Xzx9Uhud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tTIkMaey_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_viDEo7qO, m);
}

void Heavy_CircleStrings::cBinop_tTIkMaey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9Mz48IAi, m);
}

void Heavy_CircleStrings::cVar_f3KbwAXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mV5amkgq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tRKiQQ5E_sendMessage);
}

void Heavy_CircleStrings::cVar_ILlCWeWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_OPTb0sKI_sendMessage);
}

void Heavy_CircleStrings::cVar_GS2Txx5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_zMCyK9ro_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vfx1ARau, 0, m, &cIf_vfx1ARau_sendMessage);
}

void Heavy_CircleStrings::cVar_svFC7d6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_aWkLC4fd_sendMessage);
}

void Heavy_CircleStrings::cIf_vfx1ARau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_l4136WKZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_bC8I2zA7, 0, m, &cVar_bC8I2zA7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_zMCyK9ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vfx1ARau, 1, m, &cIf_vfx1ARau_sendMessage);
}

void Heavy_CircleStrings::cBinop_aWkLC4fd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_D1JNrMiD_sendMessage);
}

void Heavy_CircleStrings::cBinop_D1JNrMiD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kodk0uv4, 0, m, &cVar_kodk0uv4_sendMessage);
}

void Heavy_CircleStrings::cTabhead_4YIczY6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6a7cTgj8, HV_BINOP_SUBTRACT, 0, m, &cBinop_6a7cTgj8_sendMessage);
}

void Heavy_CircleStrings::cMsg_XVzg1Xz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YNcgm0JB_sendMessage);
}

void Heavy_CircleStrings::cSystem_YNcgm0JB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cPrTlV9I_sendMessage);
}

void Heavy_CircleStrings::cVar_RgIxsLhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vqgV55xi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Cum0BQXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Cum0BQXk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NZ3p0tME, 0, m, &cDelay_NZ3p0tME_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Z2yN6k4g, 0, m, &sTabread_Z2yN6k4g_sendMessage);
}

void Heavy_CircleStrings::cDelay_NZ3p0tME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NZ3p0tME, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Z2yN6k4g, 0, m, &sTabread_Z2yN6k4g_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NZ3p0tME, 0, m, &cDelay_NZ3p0tME_sendMessage);
}

void Heavy_CircleStrings::sTabread_Z2yN6k4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_lCTFlBPx, HV_BINOP_SUBTRACT, 0, m, &cBinop_lCTFlBPx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_pkaKvpCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9mViH9Ss, HV_BINOP_MAX, 0, m, &cBinop_9mViH9Ss_sendMessage);
}

void Heavy_CircleStrings::cBinop_cPrTlV9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pkaKvpCG, HV_BINOP_MULTIPLY, 0, m, &cBinop_pkaKvpCG_sendMessage);
}

void Heavy_CircleStrings::cBinop_6a7cTgj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VR1mtY1d_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Z2yN6k4g, 0, m, &sTabread_Z2yN6k4g_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KvUiklB5_sendMessage);
}

void Heavy_CircleStrings::cSystem_488OgWfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lCTFlBPx, HV_BINOP_SUBTRACT, 1, m, &cBinop_lCTFlBPx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NZ3p0tME, 2, m, &cDelay_NZ3p0tME_sendMessage);
}

void Heavy_CircleStrings::cMsg_vqgV55xi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_488OgWfD_sendMessage);
}

void Heavy_CircleStrings::cMsg_VR1mtY1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cum0BQXk, 0, m, &cDelay_Cum0BQXk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NZ3p0tME, 0, m, &cDelay_NZ3p0tME_sendMessage);
}

void Heavy_CircleStrings::cMsg_Lr3XVXGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9mViH9Ss, HV_BINOP_MAX, 1, m, &cBinop_9mViH9Ss_sendMessage);
}

void Heavy_CircleStrings::cBinop_9mViH9Ss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6a7cTgj8, HV_BINOP_SUBTRACT, 1, m, &cBinop_6a7cTgj8_sendMessage);
}

void Heavy_CircleStrings::cCast_KvUiklB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cum0BQXk, 0, m, &cDelay_Cum0BQXk_sendMessage);
}

void Heavy_CircleStrings::cBinop_4vs1fVR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cum0BQXk, 2, m, &cDelay_Cum0BQXk_sendMessage);
}

void Heavy_CircleStrings::cBinop_lCTFlBPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4vs1fVR9_sendMessage);
}

void Heavy_CircleStrings::cCast_KKZLQhsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RgIxsLhs, 0, m, &cVar_RgIxsLhs_sendMessage);
  cMsg_XVzg1Xz6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4YIczY6w, 0, m, &cTabhead_4YIczY6w_sendMessage);
}

void Heavy_CircleStrings::cMsg_6FAY6VdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DQFnBncf_sendMessage);
}

void Heavy_CircleStrings::cSystem_DQFnBncf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_g8yyzdsm_sendMessage);
}

void Heavy_CircleStrings::cDelay_unFh1kFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_unFh1kFF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09mrZMOk, 0, m, &cDelay_09mrZMOk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_unFh1kFF, 0, m, &cDelay_unFh1kFF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5quX7Z2l, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_09mrZMOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_09mrZMOk, m);
  cMsg_aJmuCiDv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_JELoZurs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_hv0akAfV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_tu9JWV4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ITfmXa3O_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_wfdQB7fw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oo9WtJOn_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_unFh1kFF, 2, m, &cDelay_unFh1kFF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f3DD08Ss_sendMessage);
}

void Heavy_CircleStrings::cMsg_ITfmXa3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_wfdQB7fw, 0, m, &hTable_wfdQB7fw_sendMessage);
}

void Heavy_CircleStrings::cBinop_g8yyzdsm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_tu9JWV4j_sendMessage);
}

void Heavy_CircleStrings::cMsg_aJmuCiDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_wfdQB7fw, 0, m, &hTable_wfdQB7fw_sendMessage);
}

void Heavy_CircleStrings::cCast_f3DD08Ss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_unFh1kFF, 0, m, &cDelay_unFh1kFF_sendMessage);
}

void Heavy_CircleStrings::cMsg_oo9WtJOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_09mrZMOk, 2, m, &cDelay_09mrZMOk_sendMessage);
}

void Heavy_CircleStrings::cMsg_hv0akAfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5quX7Z2l, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_4zLK3R6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jxSDnTx4, HV_BINOP_SUBTRACT, 0, m, &cBinop_jxSDnTx4_sendMessage);
}

void Heavy_CircleStrings::cMsg_rvO91F9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JtAqEohA_sendMessage);
}

void Heavy_CircleStrings::cSystem_JtAqEohA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uQ9tvHS6_sendMessage);
}

void Heavy_CircleStrings::cVar_QpjsCjK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aq3L6Pn8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_3V3i8DQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3V3i8DQQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cFNpl819, 0, m, &cDelay_cFNpl819_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RvsieZMa, 0, m, &sTabread_RvsieZMa_sendMessage);
}

void Heavy_CircleStrings::cDelay_cFNpl819_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cFNpl819, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RvsieZMa, 0, m, &sTabread_RvsieZMa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cFNpl819, 0, m, &cDelay_cFNpl819_sendMessage);
}

void Heavy_CircleStrings::sTabread_RvsieZMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_iEbdzmdq, HV_BINOP_SUBTRACT, 0, m, &cBinop_iEbdzmdq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_cewLunxt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l2AM6Zl7, HV_BINOP_MAX, 0, m, &cBinop_l2AM6Zl7_sendMessage);
}

void Heavy_CircleStrings::cBinop_uQ9tvHS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cewLunxt, HV_BINOP_MULTIPLY, 0, m, &cBinop_cewLunxt_sendMessage);
}

void Heavy_CircleStrings::cBinop_jxSDnTx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pwVrEH4G_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RvsieZMa, 0, m, &sTabread_RvsieZMa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1l9Y8jDU_sendMessage);
}

void Heavy_CircleStrings::cSystem_SMjTlEBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iEbdzmdq, HV_BINOP_SUBTRACT, 1, m, &cBinop_iEbdzmdq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cFNpl819, 2, m, &cDelay_cFNpl819_sendMessage);
}

void Heavy_CircleStrings::cMsg_aq3L6Pn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SMjTlEBg_sendMessage);
}

void Heavy_CircleStrings::cMsg_pwVrEH4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3V3i8DQQ, 0, m, &cDelay_3V3i8DQQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cFNpl819, 0, m, &cDelay_cFNpl819_sendMessage);
}

void Heavy_CircleStrings::cMsg_BqBosZ1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_l2AM6Zl7, HV_BINOP_MAX, 1, m, &cBinop_l2AM6Zl7_sendMessage);
}

void Heavy_CircleStrings::cBinop_l2AM6Zl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jxSDnTx4, HV_BINOP_SUBTRACT, 1, m, &cBinop_jxSDnTx4_sendMessage);
}

void Heavy_CircleStrings::cCast_1l9Y8jDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3V3i8DQQ, 0, m, &cDelay_3V3i8DQQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_OGUu7j4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3V3i8DQQ, 2, m, &cDelay_3V3i8DQQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_iEbdzmdq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OGUu7j4u_sendMessage);
}

void Heavy_CircleStrings::cCast_unt5gN32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QpjsCjK5, 0, m, &cVar_QpjsCjK5_sendMessage);
  cMsg_rvO91F9p_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4zLK3R6B, 0, m, &cTabhead_4zLK3R6B_sendMessage);
}

void Heavy_CircleStrings::cMsg_LF5ChtdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_b4e6kWxQ_sendMessage);
}

void Heavy_CircleStrings::cSystem_b4e6kWxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VJ34y2P1_sendMessage);
}

void Heavy_CircleStrings::cDelay_RHkBDHuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RHkBDHuY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KqTqcmpp, 0, m, &cDelay_KqTqcmpp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RHkBDHuY, 0, m, &cDelay_RHkBDHuY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_m7BKq9Lz, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_KqTqcmpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KqTqcmpp, m);
  cMsg_OogXBxU5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_IvsxSnnL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_A71bUCta_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_nm6wH3Bk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QxhI5fMH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_ruwuNmbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BXuMwmVR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RHkBDHuY, 2, m, &cDelay_RHkBDHuY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C9rhQibX_sendMessage);
}

void Heavy_CircleStrings::cMsg_QxhI5fMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ruwuNmbR, 0, m, &hTable_ruwuNmbR_sendMessage);
}

void Heavy_CircleStrings::cBinop_VJ34y2P1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_nm6wH3Bk_sendMessage);
}

void Heavy_CircleStrings::cMsg_OogXBxU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ruwuNmbR, 0, m, &hTable_ruwuNmbR_sendMessage);
}

void Heavy_CircleStrings::cCast_C9rhQibX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RHkBDHuY, 0, m, &cDelay_RHkBDHuY_sendMessage);
}

void Heavy_CircleStrings::cMsg_BXuMwmVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_KqTqcmpp, 2, m, &cDelay_KqTqcmpp_sendMessage);
}

void Heavy_CircleStrings::cMsg_A71bUCta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_m7BKq9Lz, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_TRZ2wRZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LYLmpZxm, HV_BINOP_SUBTRACT, 0, m, &cBinop_LYLmpZxm_sendMessage);
}

void Heavy_CircleStrings::cMsg_805P5UQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vCtrrl31_sendMessage);
}

void Heavy_CircleStrings::cSystem_vCtrrl31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kgNrefeE_sendMessage);
}

void Heavy_CircleStrings::cVar_JKvsrGUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QSA4PcyY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_pD1H74Zc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pD1H74Zc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Li0To2E6, 0, m, &cDelay_Li0To2E6_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CC1C7bS9, 0, m, &sTabread_CC1C7bS9_sendMessage);
}

void Heavy_CircleStrings::cDelay_Li0To2E6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Li0To2E6, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CC1C7bS9, 0, m, &sTabread_CC1C7bS9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Li0To2E6, 0, m, &cDelay_Li0To2E6_sendMessage);
}

void Heavy_CircleStrings::sTabread_CC1C7bS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NIlHaJGs, HV_BINOP_SUBTRACT, 0, m, &cBinop_NIlHaJGs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ICqsNSnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZGENqCUk, HV_BINOP_MAX, 0, m, &cBinop_ZGENqCUk_sendMessage);
}

void Heavy_CircleStrings::cBinop_kgNrefeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ICqsNSnP, HV_BINOP_MULTIPLY, 0, m, &cBinop_ICqsNSnP_sendMessage);
}

void Heavy_CircleStrings::cBinop_LYLmpZxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gUa7hEK7_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CC1C7bS9, 0, m, &sTabread_CC1C7bS9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_05uZ4wZJ_sendMessage);
}

void Heavy_CircleStrings::cSystem_VmPG0kcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NIlHaJGs, HV_BINOP_SUBTRACT, 1, m, &cBinop_NIlHaJGs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Li0To2E6, 2, m, &cDelay_Li0To2E6_sendMessage);
}

void Heavy_CircleStrings::cMsg_QSA4PcyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VmPG0kcs_sendMessage);
}

void Heavy_CircleStrings::cMsg_gUa7hEK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pD1H74Zc, 0, m, &cDelay_pD1H74Zc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Li0To2E6, 0, m, &cDelay_Li0To2E6_sendMessage);
}

void Heavy_CircleStrings::cMsg_1PpU7Efv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZGENqCUk, HV_BINOP_MAX, 1, m, &cBinop_ZGENqCUk_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZGENqCUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LYLmpZxm, HV_BINOP_SUBTRACT, 1, m, &cBinop_LYLmpZxm_sendMessage);
}

void Heavy_CircleStrings::cCast_05uZ4wZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pD1H74Zc, 0, m, &cDelay_pD1H74Zc_sendMessage);
}

void Heavy_CircleStrings::cBinop_gzukDLjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pD1H74Zc, 2, m, &cDelay_pD1H74Zc_sendMessage);
}

void Heavy_CircleStrings::cBinop_NIlHaJGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gzukDLjl_sendMessage);
}

void Heavy_CircleStrings::cCast_9O1jG5t5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JKvsrGUU, 0, m, &cVar_JKvsrGUU_sendMessage);
  cMsg_805P5UQS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TRZ2wRZx, 0, m, &cTabhead_TRZ2wRZx_sendMessage);
}

void Heavy_CircleStrings::cMsg_uwri34rw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l15HR71L_sendMessage);
}

void Heavy_CircleStrings::cSystem_l15HR71L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LCTO3uYs_sendMessage);
}

void Heavy_CircleStrings::cDelay_7carcQBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7carcQBO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pTinuFAb, 0, m, &cDelay_pTinuFAb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7carcQBO, 0, m, &cDelay_7carcQBO_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pl1PuYP5, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_pTinuFAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pTinuFAb, m);
  cMsg_K17Ba5IY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_VOl1dY7g_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_G7cFCVqF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_G1GWA0Fo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BifOkidV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_EVwlXk0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_67NETLnB_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7carcQBO, 2, m, &cDelay_7carcQBO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6L9K2PI6_sendMessage);
}

void Heavy_CircleStrings::cMsg_BifOkidV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EVwlXk0j, 0, m, &hTable_EVwlXk0j_sendMessage);
}

void Heavy_CircleStrings::cBinop_LCTO3uYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_G1GWA0Fo_sendMessage);
}

void Heavy_CircleStrings::cMsg_K17Ba5IY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EVwlXk0j, 0, m, &hTable_EVwlXk0j_sendMessage);
}

void Heavy_CircleStrings::cCast_6L9K2PI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7carcQBO, 0, m, &cDelay_7carcQBO_sendMessage);
}

void Heavy_CircleStrings::cMsg_67NETLnB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_pTinuFAb, 2, m, &cDelay_pTinuFAb_sendMessage);
}

void Heavy_CircleStrings::cMsg_G7cFCVqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pl1PuYP5, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_OUdihqpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_el8bDd5R, HV_BINOP_SUBTRACT, 0, m, &cBinop_el8bDd5R_sendMessage);
}

void Heavy_CircleStrings::cMsg_XeHzLdgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DaqXbDq8_sendMessage);
}

void Heavy_CircleStrings::cSystem_DaqXbDq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_I3c5avuI_sendMessage);
}

void Heavy_CircleStrings::cVar_pEYKoDcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N9YGGa3K_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_5LASUPPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5LASUPPY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wN2rGhkN, 0, m, &cDelay_wN2rGhkN_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4tLx6s3e, 0, m, &sTabread_4tLx6s3e_sendMessage);
}

void Heavy_CircleStrings::cDelay_wN2rGhkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wN2rGhkN, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4tLx6s3e, 0, m, &sTabread_4tLx6s3e_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wN2rGhkN, 0, m, &cDelay_wN2rGhkN_sendMessage);
}

void Heavy_CircleStrings::sTabread_4tLx6s3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_50t5QWjy, HV_BINOP_SUBTRACT, 0, m, &cBinop_50t5QWjy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_oZIlZtRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lY0YGjB3, HV_BINOP_MAX, 0, m, &cBinop_lY0YGjB3_sendMessage);
}

void Heavy_CircleStrings::cBinop_I3c5avuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oZIlZtRB, HV_BINOP_MULTIPLY, 0, m, &cBinop_oZIlZtRB_sendMessage);
}

void Heavy_CircleStrings::cBinop_el8bDd5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rj6g8pJO_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4tLx6s3e, 0, m, &sTabread_4tLx6s3e_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RqD2BnbF_sendMessage);
}

void Heavy_CircleStrings::cSystem_PoHnA8Ln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_50t5QWjy, HV_BINOP_SUBTRACT, 1, m, &cBinop_50t5QWjy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wN2rGhkN, 2, m, &cDelay_wN2rGhkN_sendMessage);
}

void Heavy_CircleStrings::cMsg_N9YGGa3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PoHnA8Ln_sendMessage);
}

void Heavy_CircleStrings::cMsg_rj6g8pJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5LASUPPY, 0, m, &cDelay_5LASUPPY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wN2rGhkN, 0, m, &cDelay_wN2rGhkN_sendMessage);
}

void Heavy_CircleStrings::cMsg_QMbHjG17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_lY0YGjB3, HV_BINOP_MAX, 1, m, &cBinop_lY0YGjB3_sendMessage);
}

void Heavy_CircleStrings::cBinop_lY0YGjB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_el8bDd5R, HV_BINOP_SUBTRACT, 1, m, &cBinop_el8bDd5R_sendMessage);
}

void Heavy_CircleStrings::cCast_RqD2BnbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5LASUPPY, 0, m, &cDelay_5LASUPPY_sendMessage);
}

void Heavy_CircleStrings::cBinop_GCXblBPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5LASUPPY, 2, m, &cDelay_5LASUPPY_sendMessage);
}

void Heavy_CircleStrings::cBinop_50t5QWjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GCXblBPA_sendMessage);
}

void Heavy_CircleStrings::cCast_nkylz1mC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pEYKoDcr, 0, m, &cVar_pEYKoDcr_sendMessage);
  cMsg_XeHzLdgD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OUdihqpP, 0, m, &cTabhead_OUdihqpP_sendMessage);
}

void Heavy_CircleStrings::cMsg_iCb6wOwb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ROJQjErT_sendMessage);
}

void Heavy_CircleStrings::cSystem_ROJQjErT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PfMsMa76_sendMessage);
}

void Heavy_CircleStrings::cDelay_9gN7WDoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9gN7WDoE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kV1D7jPp, 0, m, &cDelay_kV1D7jPp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9gN7WDoE, 0, m, &cDelay_9gN7WDoE_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rgeK7yZK, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_kV1D7jPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kV1D7jPp, m);
  cMsg_arpPrpaR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Fl1Vja2h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_7xoI6NKo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_c39NYn7i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IWBZZk0e_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Sfmze7cf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C9hNNIju_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9gN7WDoE, 2, m, &cDelay_9gN7WDoE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SKF5PIVe_sendMessage);
}

void Heavy_CircleStrings::cMsg_IWBZZk0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Sfmze7cf, 0, m, &hTable_Sfmze7cf_sendMessage);
}

void Heavy_CircleStrings::cBinop_PfMsMa76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_c39NYn7i_sendMessage);
}

void Heavy_CircleStrings::cMsg_arpPrpaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Sfmze7cf, 0, m, &hTable_Sfmze7cf_sendMessage);
}

void Heavy_CircleStrings::cCast_SKF5PIVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9gN7WDoE, 0, m, &cDelay_9gN7WDoE_sendMessage);
}

void Heavy_CircleStrings::cMsg_C9hNNIju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kV1D7jPp, 2, m, &cDelay_kV1D7jPp_sendMessage);
}

void Heavy_CircleStrings::cMsg_7xoI6NKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rgeK7yZK, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_B55Qe9Eb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k8ftE8CS, HV_BINOP_SUBTRACT, 0, m, &cBinop_k8ftE8CS_sendMessage);
}

void Heavy_CircleStrings::cMsg_5Use5nJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NZ4ErO9f_sendMessage);
}

void Heavy_CircleStrings::cSystem_NZ4ErO9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rJFNc4Uo_sendMessage);
}

void Heavy_CircleStrings::cVar_74zal9Yw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vl0CFznM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_wTZJq7CT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wTZJq7CT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M9OGY3hL, 0, m, &cDelay_M9OGY3hL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yMXSZikX, 0, m, &sTabread_yMXSZikX_sendMessage);
}

void Heavy_CircleStrings::cDelay_M9OGY3hL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M9OGY3hL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yMXSZikX, 0, m, &sTabread_yMXSZikX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M9OGY3hL, 0, m, &cDelay_M9OGY3hL_sendMessage);
}

void Heavy_CircleStrings::sTabread_yMXSZikX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_GkG9ZCdO, HV_BINOP_SUBTRACT, 0, m, &cBinop_GkG9ZCdO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Pd9VS8qX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xq7xJwnW, HV_BINOP_MAX, 0, m, &cBinop_Xq7xJwnW_sendMessage);
}

void Heavy_CircleStrings::cBinop_rJFNc4Uo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pd9VS8qX, HV_BINOP_MULTIPLY, 0, m, &cBinop_Pd9VS8qX_sendMessage);
}

void Heavy_CircleStrings::cBinop_k8ftE8CS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Oxn4AhyN_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yMXSZikX, 0, m, &sTabread_yMXSZikX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ywstDAS5_sendMessage);
}

void Heavy_CircleStrings::cSystem_O25fi8YR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GkG9ZCdO, HV_BINOP_SUBTRACT, 1, m, &cBinop_GkG9ZCdO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M9OGY3hL, 2, m, &cDelay_M9OGY3hL_sendMessage);
}

void Heavy_CircleStrings::cMsg_vl0CFznM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_O25fi8YR_sendMessage);
}

void Heavy_CircleStrings::cMsg_Oxn4AhyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wTZJq7CT, 0, m, &cDelay_wTZJq7CT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M9OGY3hL, 0, m, &cDelay_M9OGY3hL_sendMessage);
}

void Heavy_CircleStrings::cMsg_kd6CZMHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xq7xJwnW, HV_BINOP_MAX, 1, m, &cBinop_Xq7xJwnW_sendMessage);
}

void Heavy_CircleStrings::cBinop_Xq7xJwnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k8ftE8CS, HV_BINOP_SUBTRACT, 1, m, &cBinop_k8ftE8CS_sendMessage);
}

void Heavy_CircleStrings::cCast_ywstDAS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wTZJq7CT, 0, m, &cDelay_wTZJq7CT_sendMessage);
}

void Heavy_CircleStrings::cBinop_cT5P9aX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wTZJq7CT, 2, m, &cDelay_wTZJq7CT_sendMessage);
}

void Heavy_CircleStrings::cBinop_GkG9ZCdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cT5P9aX6_sendMessage);
}

void Heavy_CircleStrings::cCast_DF0sOoZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_74zal9Yw, 0, m, &cVar_74zal9Yw_sendMessage);
  cMsg_5Use5nJ3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_B55Qe9Eb, 0, m, &cTabhead_B55Qe9Eb_sendMessage);
}

void Heavy_CircleStrings::cMsg_QqYTaElI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kOBMblIH_sendMessage);
}

void Heavy_CircleStrings::cSystem_kOBMblIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9NMnGX1X_sendMessage);
}

void Heavy_CircleStrings::cDelay_9fbdMlK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9fbdMlK2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1iVLPiYu, 0, m, &cDelay_1iVLPiYu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9fbdMlK2, 0, m, &cDelay_9fbdMlK2_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cLldnAlw, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_1iVLPiYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1iVLPiYu, m);
  cMsg_Ere92qds_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_f5W7G9uo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_usyePwiN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_NtSEUJo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w41Qco86_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_9lqzuT7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3wAxShsS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9fbdMlK2, 2, m, &cDelay_9fbdMlK2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IJzZ99Ov_sendMessage);
}

void Heavy_CircleStrings::cMsg_w41Qco86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_9lqzuT7e, 0, m, &hTable_9lqzuT7e_sendMessage);
}

void Heavy_CircleStrings::cBinop_9NMnGX1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_NtSEUJo7_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ere92qds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_9lqzuT7e, 0, m, &hTable_9lqzuT7e_sendMessage);
}

void Heavy_CircleStrings::cCast_IJzZ99Ov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9fbdMlK2, 0, m, &cDelay_9fbdMlK2_sendMessage);
}

void Heavy_CircleStrings::cMsg_3wAxShsS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_1iVLPiYu, 2, m, &cDelay_1iVLPiYu_sendMessage);
}

void Heavy_CircleStrings::cMsg_usyePwiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cLldnAlw, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_bnmehkil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0pqbSOsQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_0pqbSOsQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_ArsWEbAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M5Qm4AP4_sendMessage);
}

void Heavy_CircleStrings::cSystem_M5Qm4AP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3oX9yzux_sendMessage);
}

void Heavy_CircleStrings::cVar_YQxs3hBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rUIukESM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_zwep5mwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zwep5mwK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LVnWlTJF, 0, m, &cDelay_LVnWlTJF_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GQLCq0LD, 0, m, &sTabread_GQLCq0LD_sendMessage);
}

void Heavy_CircleStrings::cDelay_LVnWlTJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LVnWlTJF, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GQLCq0LD, 0, m, &sTabread_GQLCq0LD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LVnWlTJF, 0, m, &cDelay_LVnWlTJF_sendMessage);
}

void Heavy_CircleStrings::sTabread_GQLCq0LD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_5cmCn9aQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_5cmCn9aQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_9fZT930l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZiW92Xy, HV_BINOP_MAX, 0, m, &cBinop_SZiW92Xy_sendMessage);
}

void Heavy_CircleStrings::cBinop_3oX9yzux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9fZT930l, HV_BINOP_MULTIPLY, 0, m, &cBinop_9fZT930l_sendMessage);
}

void Heavy_CircleStrings::cBinop_0pqbSOsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DMxaA2sZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GQLCq0LD, 0, m, &sTabread_GQLCq0LD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vNQjDmtZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_hQVEYJoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5cmCn9aQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_5cmCn9aQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LVnWlTJF, 2, m, &cDelay_LVnWlTJF_sendMessage);
}

void Heavy_CircleStrings::cMsg_rUIukESM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hQVEYJoC_sendMessage);
}

void Heavy_CircleStrings::cMsg_DMxaA2sZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zwep5mwK, 0, m, &cDelay_zwep5mwK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LVnWlTJF, 0, m, &cDelay_LVnWlTJF_sendMessage);
}

void Heavy_CircleStrings::cMsg_vowNP2XH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZiW92Xy, HV_BINOP_MAX, 1, m, &cBinop_SZiW92Xy_sendMessage);
}

void Heavy_CircleStrings::cBinop_SZiW92Xy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0pqbSOsQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_0pqbSOsQ_sendMessage);
}

void Heavy_CircleStrings::cCast_vNQjDmtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zwep5mwK, 0, m, &cDelay_zwep5mwK_sendMessage);
}

void Heavy_CircleStrings::cBinop_j5Zk7f6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zwep5mwK, 2, m, &cDelay_zwep5mwK_sendMessage);
}

void Heavy_CircleStrings::cBinop_5cmCn9aQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_j5Zk7f6j_sendMessage);
}

void Heavy_CircleStrings::cCast_ZeEahqwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YQxs3hBC, 0, m, &cVar_YQxs3hBC_sendMessage);
  cMsg_ArsWEbAX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bnmehkil, 0, m, &cTabhead_bnmehkil_sendMessage);
}

void Heavy_CircleStrings::cMsg_6J2ipDAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UEnOpmDq_sendMessage);
}

void Heavy_CircleStrings::cSystem_UEnOpmDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_F4wNKfQ0_sendMessage);
}

void Heavy_CircleStrings::cDelay_UN4gSh1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UN4gSh1U, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QpQig58n, 0, m, &cDelay_QpQig58n_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UN4gSh1U, 0, m, &cDelay_UN4gSh1U_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vzaH69qg, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_QpQig58n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QpQig58n, m);
  cMsg_yO8qLKnC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_dOarCNXn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_HCviASqU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_DkLeApOv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AbztDVxI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_CRvEyM5B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DXd1W6eH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UN4gSh1U, 2, m, &cDelay_UN4gSh1U_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uICRZqju_sendMessage);
}

void Heavy_CircleStrings::cMsg_AbztDVxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_CRvEyM5B, 0, m, &hTable_CRvEyM5B_sendMessage);
}

void Heavy_CircleStrings::cBinop_F4wNKfQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_DkLeApOv_sendMessage);
}

void Heavy_CircleStrings::cMsg_yO8qLKnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_CRvEyM5B, 0, m, &hTable_CRvEyM5B_sendMessage);
}

void Heavy_CircleStrings::cCast_uICRZqju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UN4gSh1U, 0, m, &cDelay_UN4gSh1U_sendMessage);
}

void Heavy_CircleStrings::cMsg_DXd1W6eH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_QpQig58n, 2, m, &cDelay_QpQig58n_sendMessage);
}

void Heavy_CircleStrings::cMsg_HCviASqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vzaH69qg, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_bC8I2zA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jRn8pWdq, 0, m, &cVar_jRn8pWdq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Wi1q81Cr, 0, m, &cVar_Wi1q81Cr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TVHb62C3, 0, m, &cVar_TVHb62C3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WOt6tR1Q, 0, m, &cVar_WOt6tR1Q_sendMessage);
}

void Heavy_CircleStrings::cVar_kodk0uv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_r6CEcZzy_sendMessage);
}

void Heavy_CircleStrings::cPack_EvJAzXQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_krZgnHvS, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_Wi1q81Cr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gMFauTHM, HV_BINOP_MULTIPLY, 0, m, &cBinop_gMFauTHM_sendMessage);
}

void Heavy_CircleStrings::cMsg_W72aZQ7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1z9JVm4x_sendMessage);
}

void Heavy_CircleStrings::cSystem_1z9JVm4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_usf9DnFg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_gMFauTHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_N5M6sozB_sendMessage);
}

void Heavy_CircleStrings::cBinop_KXeKzJ7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gMFauTHM, HV_BINOP_MULTIPLY, 1, m, &cBinop_gMFauTHM_sendMessage);
}

void Heavy_CircleStrings::cMsg_usf9DnFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KXeKzJ7t_sendMessage);
}

void Heavy_CircleStrings::cBinop_N5M6sozB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_uEmnP4Cu_sendMessage);
}

void Heavy_CircleStrings::cBinop_uEmnP4Cu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5Ea66rXA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HclWugYq, m);
}

void Heavy_CircleStrings::cBinop_5Ea66rXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FThq7u62, m);
}

void Heavy_CircleStrings::cVar_TVHb62C3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tKjxhwBE, HV_BINOP_MULTIPLY, 0, m, &cBinop_tKjxhwBE_sendMessage);
}

void Heavy_CircleStrings::cMsg_sSf4qxXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XmuQNfYM_sendMessage);
}

void Heavy_CircleStrings::cSystem_XmuQNfYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8wlTH3y9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_tKjxhwBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_s3Bbd5Cf_sendMessage);
}

void Heavy_CircleStrings::cBinop_i7rbkZNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tKjxhwBE, HV_BINOP_MULTIPLY, 1, m, &cBinop_tKjxhwBE_sendMessage);
}

void Heavy_CircleStrings::cMsg_8wlTH3y9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_i7rbkZNu_sendMessage);
}

void Heavy_CircleStrings::cBinop_s3Bbd5Cf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0soLMvMZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_0soLMvMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_0wnIf3x7_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mP9b6bqJ, m);
}

void Heavy_CircleStrings::cBinop_0wnIf3x7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_brOFQHvC, m);
}

void Heavy_CircleStrings::cVar_WOt6tR1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RgpaPNVS, HV_BINOP_MULTIPLY, 0, m, &cBinop_RgpaPNVS_sendMessage);
}

void Heavy_CircleStrings::cMsg_m51O26q9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Viwrz4lJ_sendMessage);
}

void Heavy_CircleStrings::cSystem_Viwrz4lJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TQy72hr2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_RgpaPNVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_bpoA3SMC_sendMessage);
}

void Heavy_CircleStrings::cBinop_eCutgBuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RgpaPNVS, HV_BINOP_MULTIPLY, 1, m, &cBinop_RgpaPNVS_sendMessage);
}

void Heavy_CircleStrings::cMsg_TQy72hr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_eCutgBuK_sendMessage);
}

void Heavy_CircleStrings::cBinop_bpoA3SMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_XXPNdKwK_sendMessage);
}

void Heavy_CircleStrings::cBinop_XXPNdKwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Kp58Jfxf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ekxgst84, m);
}

void Heavy_CircleStrings::cBinop_Kp58Jfxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Oza60i9N, m);
}

void Heavy_CircleStrings::cBinop_9bET2Ijg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RouwySvR, 0, m, &cPack_RouwySvR_sendMessage);
}

void Heavy_CircleStrings::cMsg_l4136WKZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_bC8I2zA7, 0, m, &cVar_bC8I2zA7_sendMessage);
}

void Heavy_CircleStrings::cBinop_r6CEcZzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EvJAzXQ5, 0, m, &cPack_EvJAzXQ5_sendMessage);
}

void Heavy_CircleStrings::cBinop_jbg7kqCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_y24qzzD4, 0, m, &cPack_y24qzzD4_sendMessage);
}

void Heavy_CircleStrings::cMsg_nWWzTEB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3SQE7d4N_sendMessage);
}

void Heavy_CircleStrings::cSystem_3SQE7d4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kEkAFUsp_sendMessage);
}

void Heavy_CircleStrings::cVar_el6yAg9k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jmvpMnnR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_sc90LX9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_y1HXE4ef_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IbD0B43N, m);
}

void Heavy_CircleStrings::cBinop_kEkAFUsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GbJH217E, m);
}

void Heavy_CircleStrings::cMsg_jmvpMnnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sc90LX9A_sendMessage);
}

void Heavy_CircleStrings::cBinop_y1HXE4ef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QCyPaNwg, m);
}

void Heavy_CircleStrings::cVar_mjI5T66C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_khYJpEtE, HV_BINOP_MULTIPLY, 0, m, &cBinop_khYJpEtE_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ea4wnHRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uInIKC7R_sendMessage);
}

void Heavy_CircleStrings::cSystem_uInIKC7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BwUncQbg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_khYJpEtE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AkDwI5yx_sendMessage);
}

void Heavy_CircleStrings::cBinop_njF8XRSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_khYJpEtE, HV_BINOP_MULTIPLY, 1, m, &cBinop_khYJpEtE_sendMessage);
}

void Heavy_CircleStrings::cMsg_BwUncQbg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_njF8XRSt_sendMessage);
}

void Heavy_CircleStrings::cBinop_AkDwI5yx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lIK8lNfz_sendMessage);
}

void Heavy_CircleStrings::cBinop_lIK8lNfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_o8ub0grQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZqUayoeQ, m);
}

void Heavy_CircleStrings::cBinop_o8ub0grQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nuJFmSvc, m);
}

void Heavy_CircleStrings::cBinop_YyaCQLKZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_9enYXLPe_sendMessage);
}

void Heavy_CircleStrings::cBinop_9enYXLPe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RrENqtYY, m);
}

void Heavy_CircleStrings::cBinop_luVTstTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cRJpwHZ7_sendMessage);
}

void Heavy_CircleStrings::cBinop_cRJpwHZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YUg5BGYT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fiBgjgi0_sendMessage);
}

void Heavy_CircleStrings::cVar_67Lojftk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_x2h0aVMi_sendMessage);
}

void Heavy_CircleStrings::cMsg_oIpDV7IU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cW4KYJSA_sendMessage);
}

void Heavy_CircleStrings::cSystem_cW4KYJSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zB21165B, HV_BINOP_DIVIDE, 1, m, &cBinop_zB21165B_sendMessage);
}

void Heavy_CircleStrings::cBinop_YUg5BGYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ZhsNrR9L_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZhsNrR9L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2LWAfMYm, m);
}

void Heavy_CircleStrings::cMsg_n4Y62z7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_QB880ptn_sendMessage);
}

void Heavy_CircleStrings::cBinop_QB880ptn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_luVTstTm_sendMessage);
}

void Heavy_CircleStrings::cBinop_fiBgjgi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Bp4zUvhW, m);
}

void Heavy_CircleStrings::cBinop_x2h0aVMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_RvoODLSR_sendMessage);
}

void Heavy_CircleStrings::cBinop_RvoODLSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zB21165B, HV_BINOP_DIVIDE, 0, m, &cBinop_zB21165B_sendMessage);
}

void Heavy_CircleStrings::cBinop_zB21165B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n4Y62z7m_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_w4ds3ML9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AEt3sSIj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_5vvbgTXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Os5IOJ3Y_sendMessage);
}

void Heavy_CircleStrings::cSystem_Os5IOJ3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xQIw7y0A_sendMessage);
}

void Heavy_CircleStrings::cDelay_9Jo58TpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9Jo58TpW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Iqbl3FIK, 0, m, &cDelay_Iqbl3FIK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Jo58TpW, 0, m, &cDelay_9Jo58TpW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_unvYRlum, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Iqbl3FIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Iqbl3FIK, m);
  cMsg_USdRBvbG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_p3lC0quy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_lmRxzaEf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Liy0Knlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_59xeKToY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_fhgnzNi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z4gPFsjX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Jo58TpW, 2, m, &cDelay_9Jo58TpW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7gBQgLZc_sendMessage);
}

void Heavy_CircleStrings::cMsg_59xeKToY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_fhgnzNi0, 0, m, &hTable_fhgnzNi0_sendMessage);
}

void Heavy_CircleStrings::cBinop_xQIw7y0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_Liy0Knlu_sendMessage);
}

void Heavy_CircleStrings::cMsg_USdRBvbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_fhgnzNi0, 0, m, &hTable_fhgnzNi0_sendMessage);
}

void Heavy_CircleStrings::cCast_7gBQgLZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Jo58TpW, 0, m, &cDelay_9Jo58TpW_sendMessage);
}

void Heavy_CircleStrings::cMsg_z4gPFsjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Iqbl3FIK, 2, m, &cDelay_Iqbl3FIK_sendMessage);
}

void Heavy_CircleStrings::cMsg_lmRxzaEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_unvYRlum, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_nb7EDyCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_AEt3sSIj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_AEt3sSIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Tf4T9HN7, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_hCok8V62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5ZcapK5C, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_7XG9CAOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pWGCE2EC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_c85hXIom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hCok8V62, 0, m, &cPack_hCok8V62_sendMessage);
}

void Heavy_CircleStrings::cMsg_n2NpkSqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5ZcapK5C, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_Rey2qj3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FM4REvIk, m);
}

void Heavy_CircleStrings::cMsg_2PA50jzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_YyaCQLKZ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_8tde8xXJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OvDVt5hn, 0, m, &cSlice_OvDVt5hn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bqZLNVMS, 0, m, &cRandom_bqZLNVMS_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_qV4k47tm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_gEenOyy7_sendMessage);
}

void Heavy_CircleStrings::cUnop_gEenOyy7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_ja8ewGoD_sendMessage);
}

void Heavy_CircleStrings::cRandom_bqZLNVMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_qV4k47tm_sendMessage);
}

void Heavy_CircleStrings::cSlice_OvDVt5hn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bqZLNVMS, 1, m, &cRandom_bqZLNVMS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_34h9ssqe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2etwRpfB, 0, m, &cSlice_2etwRpfB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZxUNNBbx, 0, m, &cRandom_ZxUNNBbx_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_DZOvSpMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wc6gRykW_sendMessage);
}

void Heavy_CircleStrings::cUnop_wc6gRykW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WFr5NKHE, 0, m, &cPack_WFr5NKHE_sendMessage);
}

void Heavy_CircleStrings::cRandom_ZxUNNBbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_DZOvSpMp_sendMessage);
}

void Heavy_CircleStrings::cSlice_2etwRpfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZxUNNBbx, 1, m, &cRandom_ZxUNNBbx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_kiePaLYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_lNNQHx5t_sendMessage);
}

void Heavy_CircleStrings::cPack_6EVh9KuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_j3HXZ1jf, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_FcUlHb27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_U6f1h7Ma_sendMessage);
}

void Heavy_CircleStrings::cBinop_08ovFFzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_FcUlHb27_sendMessage);
}

void Heavy_CircleStrings::cPack_zIKPpQNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_XQ5Orvf1, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_Ii9cWaJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_2hHwmMSD_sendMessage);
}

void Heavy_CircleStrings::cMsg_RCWbpsu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RcD9P3Dg_sendMessage);
}

void Heavy_CircleStrings::cSystem_RcD9P3Dg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YPJsj1aZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_qSkcK69S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qSkcK69S, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f7cz8D93, 0, m, &cDelay_f7cz8D93_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qSkcK69S, 0, m, &cDelay_qSkcK69S_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7JDZLfHq, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_f7cz8D93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_f7cz8D93, m);
  cMsg_tOYkyTKl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_ImTDZDx6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ztGb34MU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_nljenAVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z4ZuRHHY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Lck3uK01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CUgbeQ1r_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qSkcK69S, 2, m, &cDelay_qSkcK69S_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_im6Qy3K8_sendMessage);
}

void Heavy_CircleStrings::cMsg_z4ZuRHHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Lck3uK01, 0, m, &hTable_Lck3uK01_sendMessage);
}

void Heavy_CircleStrings::cBinop_YPJsj1aZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_nljenAVY_sendMessage);
}

void Heavy_CircleStrings::cMsg_tOYkyTKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Lck3uK01, 0, m, &hTable_Lck3uK01_sendMessage);
}

void Heavy_CircleStrings::cCast_im6Qy3K8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qSkcK69S, 0, m, &cDelay_qSkcK69S_sendMessage);
}

void Heavy_CircleStrings::cMsg_CUgbeQ1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_f7cz8D93, 2, m, &cDelay_f7cz8D93_sendMessage);
}

void Heavy_CircleStrings::cMsg_ztGb34MU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7JDZLfHq, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_rsJOrYT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FjRJJdWR_sendMessage);
}

void Heavy_CircleStrings::cSystem_FjRJJdWR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZQDaz82B_sendMessage);
}

void Heavy_CircleStrings::cVar_QYjbEVes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uD7IwuAL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_Rs5YM1kt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6lVDOyHU_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JmbYI3q5, m);
}

void Heavy_CircleStrings::cBinop_ZQDaz82B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lhzz1dz7, m);
}

void Heavy_CircleStrings::cMsg_uD7IwuAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Rs5YM1kt_sendMessage);
}

void Heavy_CircleStrings::cBinop_6lVDOyHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_so1RV3cw, m);
}

void Heavy_CircleStrings::cMsg_Iu3IDPGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5TyzHtrn_sendMessage);
}

void Heavy_CircleStrings::cSystem_5TyzHtrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IGDJhCZp_sendMessage);
}

void Heavy_CircleStrings::cVar_j1XlI59V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ymG3sxF0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_Yy1Th8E6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qO8tUW4A_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nHhJzQBE, m);
}

void Heavy_CircleStrings::cBinop_IGDJhCZp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MAlaLCPo, m);
}

void Heavy_CircleStrings::cMsg_ymG3sxF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Yy1Th8E6_sendMessage);
}

void Heavy_CircleStrings::cBinop_qO8tUW4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_z1F6TqrN, m);
}

void Heavy_CircleStrings::cBinop_heCPxf59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q09aqlsv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_4tri240s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tjfkxtRs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cE9NIieG_sendMessage);
}

void Heavy_CircleStrings::cCast_tjfkxtRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_heCPxf59, HV_BINOP_DIVIDE, 1, m, &cBinop_heCPxf59_sendMessage);
}

void Heavy_CircleStrings::cCast_cE9NIieG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_heCPxf59, HV_BINOP_DIVIDE, 0, m, &cBinop_heCPxf59_sendMessage);
}

void Heavy_CircleStrings::cBinop_U6f1h7Ma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nzcEWRlM_sendMessage);
}

void Heavy_CircleStrings::cBinop_bs6tlq78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_08ovFFzf_sendMessage);
}

void Heavy_CircleStrings::cBinop_nzcEWRlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_heCPxf59, HV_BINOP_DIVIDE, 0, m, &cBinop_heCPxf59_sendMessage);
}

void Heavy_CircleStrings::cBinop_2hHwmMSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zIKPpQNg, 0, m, &cPack_zIKPpQNg_sendMessage);
}

void Heavy_CircleStrings::cBinop_lNNQHx5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_4tri240s_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_6EVh9KuK, 0, m, &cPack_6EVh9KuK_sendMessage);
}

void Heavy_CircleStrings::cMsg_rFuH59aW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kiePaLYJ, 0, m, &cVar_kiePaLYJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_EZGXmZ4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_Ii9cWaJD, 0, m, &cVar_Ii9cWaJD_sendMessage);
}

void Heavy_CircleStrings::cMsg_q09aqlsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mnnJyNt9, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_fDhYf1dR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_N96Bt1Zf_sendMessage);
}

void Heavy_CircleStrings::cSystem_N96Bt1Zf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_p7VfeiJ2_sendMessage);
}

void Heavy_CircleStrings::cVar_vO2JddHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5B2uHKkq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_RvgFk6fs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bQS3Pu9E_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_J1BCJR0D, m);
}

void Heavy_CircleStrings::cBinop_p7VfeiJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hotVM8YE, m);
}

void Heavy_CircleStrings::cMsg_5B2uHKkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RvgFk6fs_sendMessage);
}

void Heavy_CircleStrings::cBinop_bQS3Pu9E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_H39jlROv, m);
}

void Heavy_CircleStrings::cVar_ZjhXHiok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LPZ6ZvsM, HV_BINOP_MULTIPLY, 0, m, &cBinop_LPZ6ZvsM_sendMessage);
}

void Heavy_CircleStrings::cMsg_a6y2atQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NTvvCkWi_sendMessage);
}

void Heavy_CircleStrings::cSystem_NTvvCkWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JodmKTfT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_LPZ6ZvsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_8mnahLOz_sendMessage);
}

void Heavy_CircleStrings::cBinop_7dLMhHa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LPZ6ZvsM, HV_BINOP_MULTIPLY, 1, m, &cBinop_LPZ6ZvsM_sendMessage);
}

void Heavy_CircleStrings::cMsg_JodmKTfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7dLMhHa1_sendMessage);
}

void Heavy_CircleStrings::cBinop_8mnahLOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AZoafc9K_sendMessage);
}

void Heavy_CircleStrings::cBinop_AZoafc9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Yuiyo1kK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eFHEnv6b, m);
}

void Heavy_CircleStrings::cBinop_Yuiyo1kK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_c3hjuZuw, m);
}

void Heavy_CircleStrings::cBinop_SblS8RSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_J7QXPuXq_sendMessage);
}

void Heavy_CircleStrings::cBinop_J7QXPuXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5vWGMIw3, m);
}

void Heavy_CircleStrings::cBinop_CAwOuOJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mltuVTkf_sendMessage);
}

void Heavy_CircleStrings::cBinop_mltuVTkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ldEuOAG3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_V1NqpfRo_sendMessage);
}

void Heavy_CircleStrings::cVar_Y60I3yiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_TCA31NWC_sendMessage);
}

void Heavy_CircleStrings::cMsg_EDOYRfUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XJdoLbMF_sendMessage);
}

void Heavy_CircleStrings::cSystem_XJdoLbMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A72SBX04, HV_BINOP_DIVIDE, 1, m, &cBinop_A72SBX04_sendMessage);
}

void Heavy_CircleStrings::cBinop_ldEuOAG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_6iX28nr2_sendMessage);
}

void Heavy_CircleStrings::cBinop_6iX28nr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RDs9J6VZ, m);
}

void Heavy_CircleStrings::cMsg_1v4scpe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ElCnkxNr_sendMessage);
}

void Heavy_CircleStrings::cBinop_ElCnkxNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_CAwOuOJa_sendMessage);
}

void Heavy_CircleStrings::cBinop_V1NqpfRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9gj4DHD9, m);
}

void Heavy_CircleStrings::cBinop_TCA31NWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Aw5i2QQU_sendMessage);
}

void Heavy_CircleStrings::cBinop_Aw5i2QQU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A72SBX04, HV_BINOP_DIVIDE, 0, m, &cBinop_A72SBX04_sendMessage);
}

void Heavy_CircleStrings::cBinop_A72SBX04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1v4scpe0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_DEoxQB6v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ay4IyzE1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_7MumD4Ze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ug250zc0_sendMessage);
}

void Heavy_CircleStrings::cSystem_ug250zc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QCPEZOC9_sendMessage);
}

void Heavy_CircleStrings::cDelay_P1zgzLS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_P1zgzLS3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OIMNYAwL, 0, m, &cDelay_OIMNYAwL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P1zgzLS3, 0, m, &cDelay_P1zgzLS3_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AF0TMShV, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_OIMNYAwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OIMNYAwL, m);
  cMsg_7Vhdm1yE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_iNJ3jqnS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_bAnyYV3S_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_HwQ0tVWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HDAyesau_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_ABZ5l3v7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YSNi5QaI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P1zgzLS3, 2, m, &cDelay_P1zgzLS3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nSlZqZx5_sendMessage);
}

void Heavy_CircleStrings::cMsg_HDAyesau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ABZ5l3v7, 0, m, &hTable_ABZ5l3v7_sendMessage);
}

void Heavy_CircleStrings::cBinop_QCPEZOC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_HwQ0tVWt_sendMessage);
}

void Heavy_CircleStrings::cMsg_7Vhdm1yE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ABZ5l3v7, 0, m, &hTable_ABZ5l3v7_sendMessage);
}

void Heavy_CircleStrings::cCast_nSlZqZx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P1zgzLS3, 0, m, &cDelay_P1zgzLS3_sendMessage);
}

void Heavy_CircleStrings::cMsg_YSNi5QaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OIMNYAwL, 2, m, &cDelay_OIMNYAwL_sendMessage);
}

void Heavy_CircleStrings::cMsg_bAnyYV3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AF0TMShV, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_0zw6daIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_ay4IyzE1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ay4IyzE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0OIEmVkv, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_qBDVf7gD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_CbBxUlYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VeHJQsvK_sendMessage);
}

void Heavy_CircleStrings::cSystem_VeHJQsvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aoe2aMgZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_aoe2aMgZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bxRkoYNQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_bxRkoYNQ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_W0wfz1Ov_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_QneKHSoy_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_QneKHSoy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VKXlel4U_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_NBtUcIfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NBtUcIfQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NBtUcIfQ, 0, m, &cDelay_NBtUcIfQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rwbz0puP, 0, m, &cVar_rwbz0puP_sendMessage);
}

void Heavy_CircleStrings::cCast_VKXlel4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QneKHSoy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NBtUcIfQ, 0, m, &cDelay_NBtUcIfQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rwbz0puP, 0, m, &cVar_rwbz0puP_sendMessage);
}

void Heavy_CircleStrings::cMsg_lOT3SDVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a4wAryJz_sendMessage);
}

void Heavy_CircleStrings::cSystem_a4wAryJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1RQqcNyN_sendMessage);
}

void Heavy_CircleStrings::cVar_HPJ7bT7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z89iZ4K8, HV_BINOP_MULTIPLY, 0, m, &cBinop_z89iZ4K8_sendMessage);
}

void Heavy_CircleStrings::cMsg_QneKHSoy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NBtUcIfQ, 0, m, &cDelay_NBtUcIfQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_vOJ39Xgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NBtUcIfQ, 2, m, &cDelay_NBtUcIfQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_1RQqcNyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z89iZ4K8, HV_BINOP_MULTIPLY, 1, m, &cBinop_z89iZ4K8_sendMessage);
}

void Heavy_CircleStrings::cBinop_z89iZ4K8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_vOJ39Xgz_sendMessage);
}

void Heavy_CircleStrings::cVar_rwbz0puP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HwcOuPV2, HV_BINOP_SUBTRACT, 0, m, &cBinop_HwcOuPV2_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_U9hIa9zH_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_kmcuLxFX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3QF7HEGo_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lmNSVKzB_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_3QF7HEGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BOcCzIhO, 0, m, &cVar_BOcCzIhO_sendMessage);
}

void Heavy_CircleStrings::cCast_lmNSVKzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vcUu9HJM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5ibsSJQQ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_eKqEKTI9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ohHWeI9F, 0, m, &cSlice_ohHWeI9F_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_elAjwJm3, 0, m, &cSlice_elAjwJm3_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Eq5mYSkq_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fpMZzzjQ, 0, m, &cSlice_fpMZzzjQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_NSw7YvFs, 0, m, &cSlice_NSw7YvFs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4bDQyRs2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cifbhOFC_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_ohHWeI9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_4dsVUxd3_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_4dsVUxd3_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_elAjwJm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_43BOpDQO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_torZ5E62_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_43BOpDQO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_torZ5E62_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_nLpv6Vbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3DANUWVT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Qcvx4jF_sendMessage);
}

void Heavy_CircleStrings::cVar_vHaQPU7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qRSFZoCF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_qRSFZoCF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wC6RkMqr_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aoe2aMgZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_aoe2aMgZ_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_6c2V1l54, HV_BINOP_DIVIDE, 1, m, &cBinop_6c2V1l54_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_HPJ7bT7r, 0, m, &cVar_HPJ7bT7r_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_wC6RkMqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ao6SlBoN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_jCWndMnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pqPgl29g, HV_BINOP_SUBTRACT, 1, m, &cBinop_pqPgl29g_sendMessage);
}

void Heavy_CircleStrings::cVar_LIx9aVyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BOcCzIhO, 0, m, &cVar_BOcCzIhO_sendMessage);
}

void Heavy_CircleStrings::cVar_BOcCzIhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E02W9zeN, HV_BINOP_ADD, 0, m, &cBinop_E02W9zeN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lV1TafU4, HV_BINOP_ADD, 0, m, &cBinop_lV1TafU4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_U1EeHDQs, 0, m, &cVar_U1EeHDQs_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_bs6tlq78_sendMessage);
}

void Heavy_CircleStrings::cSlice_fpMZzzjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3DANUWVT_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Qcvx4jF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_NSw7YvFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mh5hoopL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Bd4Ar39I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_L9mQhqTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rwbz0puP, 1, m, &cVar_rwbz0puP_sendMessage);
}

void Heavy_CircleStrings::cBinop_bxRkoYNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_L9mQhqTb_sendMessage);
}

void Heavy_CircleStrings::cBinop_aoe2aMgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eBbN18xK_sendMessage);
}

void Heavy_CircleStrings::cBinop_eBbN18xK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HwcOuPV2, HV_BINOP_SUBTRACT, 1, m, &cBinop_HwcOuPV2_sendMessage);
}

void Heavy_CircleStrings::cBinop_HwcOuPV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rwbz0puP, 1, m, &cVar_rwbz0puP_sendMessage);
}

void Heavy_CircleStrings::cMsg_2SrrK2eZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_W0wfz1Ov_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_MsTiQEkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_W0wfz1Ov_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lV1TafU4, HV_BINOP_ADD, 1, m, &cBinop_lV1TafU4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_E02W9zeN, HV_BINOP_ADD, 1, m, &cBinop_E02W9zeN_sendMessage);
}

void Heavy_CircleStrings::cBinop_U9hIa9zH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kmcuLxFX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_E02W9zeN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BOcCzIhO, 1, m, &cVar_BOcCzIhO_sendMessage);
}

void Heavy_CircleStrings::cBinop_6c2V1l54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jNxooIL2, HV_BINOP_DIVIDE, 1, m, &cBinop_jNxooIL2_sendMessage);
}

void Heavy_CircleStrings::cBinop_jNxooIL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lV1TafU4, HV_BINOP_ADD, 1, m, &cBinop_lV1TafU4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_E02W9zeN, HV_BINOP_ADD, 1, m, &cBinop_E02W9zeN_sendMessage);
}

void Heavy_CircleStrings::cCast_1Qcvx4jF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6c2V1l54, HV_BINOP_DIVIDE, 0, m, &cBinop_6c2V1l54_sendMessage);
}

void Heavy_CircleStrings::cCast_3DANUWVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bxRkoYNQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_bxRkoYNQ_sendMessage);
}

void Heavy_CircleStrings::cCast_Bd4Ar39I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pqPgl29g, HV_BINOP_SUBTRACT, 0, m, &cBinop_pqPgl29g_sendMessage);
}

void Heavy_CircleStrings::cCast_mh5hoopL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LIx9aVyy, 1, m, &cVar_LIx9aVyy_sendMessage);
}

void Heavy_CircleStrings::cCast_vcUu9HJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MsTiQEkL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_5ibsSJQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LIx9aVyy, 0, m, &cVar_LIx9aVyy_sendMessage);
}

void Heavy_CircleStrings::cBinop_lV1TafU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jCWndMnn, 0, m, &cVar_jCWndMnn_sendMessage);
}

void Heavy_CircleStrings::cMsg_4dsVUxd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_W0wfz1Ov_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_QRhSglOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_nLpv6Vbk, 1, m, &cVar_nLpv6Vbk_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ao6SlBoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aoe2aMgZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_aoe2aMgZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6c2V1l54, HV_BINOP_DIVIDE, 1, m, &cBinop_6c2V1l54_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HPJ7bT7r, 0, m, &cVar_HPJ7bT7r_sendMessage);
}

void Heavy_CircleStrings::cCast_43BOpDQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4dsVUxd3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_torZ5E62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5tr6PxQz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lV1TafU4, HV_BINOP_ADD, 0, m, &cBinop_lV1TafU4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BOcCzIhO, 1, m, &cVar_BOcCzIhO_sendMessage);
}

void Heavy_CircleStrings::cBinop_pqPgl29g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jNxooIL2, HV_BINOP_DIVIDE, 0, m, &cBinop_jNxooIL2_sendMessage);
}

void Heavy_CircleStrings::cCast_5tr6PxQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MsTiQEkL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Eq5mYSkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nLpv6Vbk, 0, m, &cVar_nLpv6Vbk_sendMessage);
}

void Heavy_CircleStrings::cCast_cifbhOFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QRhSglOf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_4bDQyRs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2SrrK2eZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_U1EeHDQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cPack_zpKpeqG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_eKqEKTI9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_Mwf69qSO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RSxRp1Rj_sendMessage);
}

void Heavy_CircleStrings::cSystem_RSxRp1Rj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9t1P1nri, HV_BINOP_MULTIPLY, 1, m, &cBinop_9t1P1nri_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_E2BbVhON, HV_BINOP_MULTIPLY, 1, m, &cBinop_E2BbVhON_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_OPdmw103_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_j6iq7U72_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_j6iq7U72_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_na61mEYF_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_wfT2BpKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wfT2BpKU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wfT2BpKU, 0, m, &cDelay_wfT2BpKU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KM2E0mOL, 0, m, &cVar_KM2E0mOL_sendMessage);
}

void Heavy_CircleStrings::cCast_na61mEYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j6iq7U72_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wfT2BpKU, 0, m, &cDelay_wfT2BpKU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KM2E0mOL, 0, m, &cVar_KM2E0mOL_sendMessage);
}

void Heavy_CircleStrings::cMsg_Yd7VEKAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wRG6LK7b_sendMessage);
}

void Heavy_CircleStrings::cSystem_wRG6LK7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WFWEwqXZ_sendMessage);
}

void Heavy_CircleStrings::cVar_G3SB9YNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bl3rIzEJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Bl3rIzEJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_j6iq7U72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wfT2BpKU, 0, m, &cDelay_wfT2BpKU_sendMessage);
}

void Heavy_CircleStrings::cBinop_Xj169yYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wfT2BpKU, 2, m, &cDelay_wfT2BpKU_sendMessage);
}

void Heavy_CircleStrings::cBinop_WFWEwqXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bl3rIzEJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Bl3rIzEJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_Bl3rIzEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Xj169yYz_sendMessage);
}

void Heavy_CircleStrings::cVar_KM2E0mOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AWkYnKjM, HV_BINOP_SUBTRACT, 0, m, &cBinop_AWkYnKjM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_uV34ok54_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_WALfGC4g_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xZDNlYIG_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b3nNWTSI_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_xZDNlYIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ft4SIHUq, 0, m, &cVar_Ft4SIHUq_sendMessage);
}

void Heavy_CircleStrings::cCast_b3nNWTSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CTPR9h5f_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bqyCIYVz_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_94za4Xcp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GmaqwSWF, 0, m, &cSlice_GmaqwSWF_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lM2PfTOH, 0, m, &cSlice_lM2PfTOH_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aYYex8je_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_LiWQk285, 0, m, &cSlice_LiWQk285_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_0Ox2CErJ, 0, m, &cSlice_0Ox2CErJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lvcpr1wV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NICqSOVr_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_GmaqwSWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WGnnQiFw_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_WGnnQiFw_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_lM2PfTOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FiGnj5vN_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eBDOSMWQ_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FiGnj5vN_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eBDOSMWQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_v3A6MYgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4aR9EFhg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jEX9MJmH_sendMessage);
}

void Heavy_CircleStrings::cVar_Wng5FOpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4dWoMjL5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_4dWoMjL5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yrhky9d7_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9t1P1nri, HV_BINOP_MULTIPLY, 0, m, &cBinop_9t1P1nri_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_3nIzqW90, HV_BINOP_DIVIDE, 1, m, &cBinop_3nIzqW90_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_G3SB9YNs, 0, m, &cVar_G3SB9YNs_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_yrhky9d7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cCJEHP0G_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_3NltcsXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_36Gj8aGr, HV_BINOP_SUBTRACT, 1, m, &cBinop_36Gj8aGr_sendMessage);
}

void Heavy_CircleStrings::cVar_Rx0wagHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ft4SIHUq, 0, m, &cVar_Ft4SIHUq_sendMessage);
}

void Heavy_CircleStrings::cVar_Ft4SIHUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GK1yIq8E, HV_BINOP_ADD, 0, m, &cBinop_GK1yIq8E_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cpD3aeit, HV_BINOP_ADD, 0, m, &cBinop_cpD3aeit_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qBDVf7gD, 0, m, &cVar_qBDVf7gD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9B9Ou6MK, m);
}

void Heavy_CircleStrings::cSlice_LiWQk285_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4aR9EFhg_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jEX9MJmH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_0Ox2CErJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wpyafEwP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xYhovafQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_22AwAwYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KM2E0mOL, 1, m, &cVar_KM2E0mOL_sendMessage);
}

void Heavy_CircleStrings::cBinop_E2BbVhON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_22AwAwYh_sendMessage);
}

void Heavy_CircleStrings::cBinop_9t1P1nri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GBaVUue6_sendMessage);
}

void Heavy_CircleStrings::cBinop_GBaVUue6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AWkYnKjM, HV_BINOP_SUBTRACT, 1, m, &cBinop_AWkYnKjM_sendMessage);
}

void Heavy_CircleStrings::cBinop_AWkYnKjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KM2E0mOL, 1, m, &cVar_KM2E0mOL_sendMessage);
}

void Heavy_CircleStrings::cMsg_mZZ8AnOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_OPdmw103_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_1OFlOlwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_OPdmw103_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cpD3aeit, HV_BINOP_ADD, 1, m, &cBinop_cpD3aeit_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GK1yIq8E, HV_BINOP_ADD, 1, m, &cBinop_GK1yIq8E_sendMessage);
}

void Heavy_CircleStrings::cBinop_uV34ok54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WALfGC4g_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_GK1yIq8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ft4SIHUq, 1, m, &cVar_Ft4SIHUq_sendMessage);
}

void Heavy_CircleStrings::cBinop_3nIzqW90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mWYDyA03, HV_BINOP_DIVIDE, 1, m, &cBinop_mWYDyA03_sendMessage);
}

void Heavy_CircleStrings::cBinop_mWYDyA03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cpD3aeit, HV_BINOP_ADD, 1, m, &cBinop_cpD3aeit_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GK1yIq8E, HV_BINOP_ADD, 1, m, &cBinop_GK1yIq8E_sendMessage);
}

void Heavy_CircleStrings::cCast_jEX9MJmH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3nIzqW90, HV_BINOP_DIVIDE, 0, m, &cBinop_3nIzqW90_sendMessage);
}

void Heavy_CircleStrings::cCast_4aR9EFhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E2BbVhON, HV_BINOP_MULTIPLY, 0, m, &cBinop_E2BbVhON_sendMessage);
}

void Heavy_CircleStrings::cCast_wpyafEwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Rx0wagHI, 1, m, &cVar_Rx0wagHI_sendMessage);
}

void Heavy_CircleStrings::cCast_xYhovafQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_36Gj8aGr, HV_BINOP_SUBTRACT, 0, m, &cBinop_36Gj8aGr_sendMessage);
}

void Heavy_CircleStrings::cCast_CTPR9h5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1OFlOlwm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_bqyCIYVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Rx0wagHI, 0, m, &cVar_Rx0wagHI_sendMessage);
}

void Heavy_CircleStrings::cBinop_cpD3aeit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3NltcsXK, 0, m, &cVar_3NltcsXK_sendMessage);
}

void Heavy_CircleStrings::cMsg_WGnnQiFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_OPdmw103_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_L9j5T17L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_v3A6MYgN, 1, m, &cVar_v3A6MYgN_sendMessage);
}

void Heavy_CircleStrings::cMsg_cCJEHP0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9t1P1nri, HV_BINOP_MULTIPLY, 0, m, &cBinop_9t1P1nri_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3nIzqW90, HV_BINOP_DIVIDE, 1, m, &cBinop_3nIzqW90_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_G3SB9YNs, 0, m, &cVar_G3SB9YNs_sendMessage);
}

void Heavy_CircleStrings::cCast_FiGnj5vN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WGnnQiFw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_eBDOSMWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YUjM3eNP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cpD3aeit, HV_BINOP_ADD, 0, m, &cBinop_cpD3aeit_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ft4SIHUq, 1, m, &cVar_Ft4SIHUq_sendMessage);
}

void Heavy_CircleStrings::cBinop_36Gj8aGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mWYDyA03, HV_BINOP_DIVIDE, 0, m, &cBinop_mWYDyA03_sendMessage);
}

void Heavy_CircleStrings::cCast_YUjM3eNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1OFlOlwm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_aYYex8je_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v3A6MYgN, 0, m, &cVar_v3A6MYgN_sendMessage);
}

void Heavy_CircleStrings::cCast_Lvcpr1wV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mZZ8AnOw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_NICqSOVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L9j5T17L_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_WFr5NKHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_94za4Xcp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_zthvGC3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PTG8xNxi, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_52o25ZtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_2TXzMfyA_sendMessage);
}

void Heavy_CircleStrings::cBinop_2TXzMfyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zpKpeqG9, 0, m, &cPack_zpKpeqG9_sendMessage);
}

void Heavy_CircleStrings::cBinop_ja8ewGoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_52o25ZtN_sendMessage);
}

void Heavy_CircleStrings::cCast_cU2cjvhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8tde8xXJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_yeEVVgYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_34h9ssqe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_EfT8rMYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_SblS8RSZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_dTsfOFij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gEMsW9eL_sendMessage);
}

void Heavy_CircleStrings::cBinop_gEMsW9eL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MjRUZaZ3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cGLSYhV6_sendMessage);
}

void Heavy_CircleStrings::cVar_YANBlYTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_HZDEpKmZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_stf4b0Pj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ytw9CIux_sendMessage);
}

void Heavy_CircleStrings::cSystem_ytw9CIux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jT6ibkLq, HV_BINOP_DIVIDE, 1, m, &cBinop_jT6ibkLq_sendMessage);
}

void Heavy_CircleStrings::cBinop_MjRUZaZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_6p45ifsA_sendMessage);
}

void Heavy_CircleStrings::cBinop_6p45ifsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6FNy6t81, m);
}

void Heavy_CircleStrings::cMsg_JL3SRxpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_gDcwAkCe_sendMessage);
}

void Heavy_CircleStrings::cBinop_gDcwAkCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dTsfOFij_sendMessage);
}

void Heavy_CircleStrings::cBinop_cGLSYhV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bUZWOmbv, m);
}

void Heavy_CircleStrings::cBinop_HZDEpKmZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_GoYBA54h_sendMessage);
}

void Heavy_CircleStrings::cBinop_GoYBA54h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jT6ibkLq, HV_BINOP_DIVIDE, 0, m, &cBinop_jT6ibkLq_sendMessage);
}

void Heavy_CircleStrings::cBinop_jT6ibkLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JL3SRxpp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_T6QfnJgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_rddh4osX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_HP3CUZxI_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_lr2bWN5q, 0, m, &cIf_lr2bWN5q_sendMessage);
      break;
    }
    case 1: {
      cMsg_oWq3BxpM_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_IsQSlBYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rddh4osX, 1, m, &cIf_rddh4osX_sendMessage);
}

void Heavy_CircleStrings::cIf_lr2bWN5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_HHBGS2mG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_WFUS8OVz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_HP3CUZxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lr2bWN5q, 1, m, &cIf_lr2bWN5q_sendMessage);
}

void Heavy_CircleStrings::cMsg_oWq3BxpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_WFUS8OVz_sendMessage);
}

void Heavy_CircleStrings::cMsg_HHBGS2mG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_WFUS8OVz_sendMessage);
}

void Heavy_CircleStrings::cIf_3zLUoZmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_5lYKt5wC_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_L54Fe0XB, 0, m, &cIf_L54Fe0XB_sendMessage);
      break;
    }
    case 1: {
      cMsg_7GqYVOh2_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_eoSqOASA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3zLUoZmp, 1, m, &cIf_3zLUoZmp_sendMessage);
}

void Heavy_CircleStrings::cIf_L54Fe0XB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_nDut1pW5_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_QxHT9LxP, 0, m, &cPack_QxHT9LxP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_5lYKt5wC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_L54Fe0XB, 1, m, &cIf_L54Fe0XB_sendMessage);
}

void Heavy_CircleStrings::cMsg_7GqYVOh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_QxHT9LxP, 0, m, &cPack_QxHT9LxP_sendMessage);
}

void Heavy_CircleStrings::cMsg_nDut1pW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_QxHT9LxP, 0, m, &cPack_QxHT9LxP_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_WLZRLWkv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_H5queybS, 0, m, &cSlice_H5queybS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MyfIbL8m, 0, m, &cRandom_MyfIbL8m_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_VK5JKMNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_aJZDVppr_sendMessage);
}

void Heavy_CircleStrings::cUnop_aJZDVppr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ezoU1tZE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_MyfIbL8m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_VK5JKMNi_sendMessage);
}

void Heavy_CircleStrings::cSlice_H5queybS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MyfIbL8m, 1, m, &cRandom_MyfIbL8m_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_ezoU1tZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_a5h7BKRR, m);
}

void Heavy_CircleStrings::cTabhead_m99Kv6c6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DAtPUvjC, HV_BINOP_SUBTRACT, 0, m, &cBinop_DAtPUvjC_sendMessage);
}

void Heavy_CircleStrings::cMsg_WLrmsSrw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TLOIZLpG_sendMessage);
}

void Heavy_CircleStrings::cSystem_TLOIZLpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tsOIana9_sendMessage);
}

void Heavy_CircleStrings::cVar_zdSa9Ytr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IO8vl1U7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_l8Zb45YC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_l8Zb45YC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lSbXo8kT, 0, m, &cDelay_lSbXo8kT_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vV6XeVsB, 0, m, &sTabread_vV6XeVsB_sendMessage);
}

void Heavy_CircleStrings::cDelay_lSbXo8kT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lSbXo8kT, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vV6XeVsB, 0, m, &sTabread_vV6XeVsB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lSbXo8kT, 0, m, &cDelay_lSbXo8kT_sendMessage);
}

void Heavy_CircleStrings::sTabread_vV6XeVsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qYKLlnyO, HV_BINOP_SUBTRACT, 0, m, &cBinop_qYKLlnyO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_x3gmPT3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c4FHUhiQ, HV_BINOP_MAX, 0, m, &cBinop_c4FHUhiQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_tsOIana9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x3gmPT3J, HV_BINOP_MULTIPLY, 0, m, &cBinop_x3gmPT3J_sendMessage);
}

void Heavy_CircleStrings::cBinop_DAtPUvjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ff9Co7Ub_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vV6XeVsB, 0, m, &sTabread_vV6XeVsB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fzxWszCJ_sendMessage);
}

void Heavy_CircleStrings::cSystem_A0oVR0pr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qYKLlnyO, HV_BINOP_SUBTRACT, 1, m, &cBinop_qYKLlnyO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lSbXo8kT, 2, m, &cDelay_lSbXo8kT_sendMessage);
}

void Heavy_CircleStrings::cMsg_IO8vl1U7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A0oVR0pr_sendMessage);
}

void Heavy_CircleStrings::cMsg_ff9Co7Ub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_l8Zb45YC, 0, m, &cDelay_l8Zb45YC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lSbXo8kT, 0, m, &cDelay_lSbXo8kT_sendMessage);
}

void Heavy_CircleStrings::cMsg_DmCylmfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_c4FHUhiQ, HV_BINOP_MAX, 1, m, &cBinop_c4FHUhiQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_c4FHUhiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DAtPUvjC, HV_BINOP_SUBTRACT, 1, m, &cBinop_DAtPUvjC_sendMessage);
}

void Heavy_CircleStrings::cCast_fzxWszCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_l8Zb45YC, 0, m, &cDelay_l8Zb45YC_sendMessage);
}

void Heavy_CircleStrings::cBinop_KK0p85s6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_l8Zb45YC, 2, m, &cDelay_l8Zb45YC_sendMessage);
}

void Heavy_CircleStrings::cBinop_qYKLlnyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KK0p85s6_sendMessage);
}

void Heavy_CircleStrings::cCast_MY6VAnDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zdSa9Ytr, 0, m, &cVar_zdSa9Ytr_sendMessage);
  cMsg_WLrmsSrw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_m99Kv6c6, 0, m, &cTabhead_m99Kv6c6_sendMessage);
}

void Heavy_CircleStrings::cBinop_zLiuIgJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LogmTUOg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O15hlNnn_sendMessage);
}

void Heavy_CircleStrings::cBinop_dE5ZBCHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_WbPzXinB_sendMessage);
}

void Heavy_CircleStrings::cBinop_WbPzXinB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BZGNNKYG, HV_BINOP_POW, 1, m, &cBinop_BZGNNKYG_sendMessage);
  cMsg_4MzCTyA7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_BZGNNKYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_zLiuIgJn_sendMessage);
}

void Heavy_CircleStrings::cMsg_4MzCTyA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BZGNNKYG, HV_BINOP_POW, 0, m, &cBinop_BZGNNKYG_sendMessage);
}

void Heavy_CircleStrings::cVar_rTV0cnf9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_dE5ZBCHO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_19Axrx4s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LNOBI81n_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_47AjLxO3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Ws016mS0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Ws016mS0_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_tapd5va6, 1, m, &cDelay_tapd5va6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eXxemolc_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_tapd5va6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tapd5va6, m);
  cMsg_c1D0Qjwx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Ws016mS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tapd5va6, 0, m, &cDelay_tapd5va6_sendMessage);
}

void Heavy_CircleStrings::cCast_eXxemolc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tapd5va6, 0, m, &cDelay_tapd5va6_sendMessage);
}

void Heavy_CircleStrings::cVar_HmaC2b4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m0yizbzM, HV_BINOP_MULTIPLY, 0, m, &cBinop_m0yizbzM_sendMessage);
}

void Heavy_CircleStrings::cMsg_qzkAtTdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6n7A4mGx_sendMessage);
}

void Heavy_CircleStrings::cSystem_6n7A4mGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mtLvZN9n_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_m0yizbzM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1k31bKmy_sendMessage);
}

void Heavy_CircleStrings::cBinop_MKornjEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m0yizbzM, HV_BINOP_MULTIPLY, 1, m, &cBinop_m0yizbzM_sendMessage);
}

void Heavy_CircleStrings::cMsg_mtLvZN9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MKornjEE_sendMessage);
}

void Heavy_CircleStrings::cBinop_1k31bKmy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_fZ5BAlu9_sendMessage);
}

void Heavy_CircleStrings::cBinop_fZ5BAlu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_f52xy5Qt_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IRrweIw6, m);
}

void Heavy_CircleStrings::cBinop_f52xy5Qt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hSUK4UMu, m);
}

void Heavy_CircleStrings::cMsg_1PM4QiAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oZUeqr4s_sendMessage);
}

void Heavy_CircleStrings::cSystem_oZUeqr4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lIETXoJV_sendMessage);
}

void Heavy_CircleStrings::cDelay_A0uMea6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_A0uMea6k, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RLFAUdbz, 0, m, &cDelay_RLFAUdbz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A0uMea6k, 0, m, &cDelay_A0uMea6k_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y67LdaFm, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_RLFAUdbz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RLFAUdbz, m);
  cMsg_3wmWOFnz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_1Uamul0P_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_QX1FSuOo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_1KIF19ZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fjJujY8a_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_H2ZqmK2S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FbzJO4cl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A0uMea6k, 2, m, &cDelay_A0uMea6k_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bKmEEZND_sendMessage);
}

void Heavy_CircleStrings::cMsg_fjJujY8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_H2ZqmK2S, 0, m, &hTable_H2ZqmK2S_sendMessage);
}

void Heavy_CircleStrings::cBinop_lIETXoJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_1KIF19ZN_sendMessage);
}

void Heavy_CircleStrings::cMsg_3wmWOFnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_H2ZqmK2S, 0, m, &hTable_H2ZqmK2S_sendMessage);
}

void Heavy_CircleStrings::cCast_bKmEEZND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_A0uMea6k, 0, m, &cDelay_A0uMea6k_sendMessage);
}

void Heavy_CircleStrings::cMsg_FbzJO4cl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_RLFAUdbz, 2, m, &cDelay_RLFAUdbz_sendMessage);
}

void Heavy_CircleStrings::cMsg_QX1FSuOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y67LdaFm, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_WHDJVXt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Suu54cO4, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_c1D0Qjwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Suu54cO4, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_LNOBI81n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WHDJVXt2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_19Axrx4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_47AjLxO3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_H2IZSBAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_dE5ZBCHO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_19Axrx4s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LNOBI81n_sendMessage);
}

void Heavy_CircleStrings::cBinop_C7l83JGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x3gmPT3J, HV_BINOP_MULTIPLY, 1, m, &cBinop_x3gmPT3J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MY6VAnDd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tapd5va6, 1, m, &cDelay_tapd5va6_sendMessage);
}

void Heavy_CircleStrings::cMsg_YYrZZpFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_C7l83JGc, HV_BINOP_DIVIDE, 0, m, &cBinop_C7l83JGc_sendMessage);
}

void Heavy_CircleStrings::cCast_LogmTUOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C7l83JGc, HV_BINOP_DIVIDE, 1, m, &cBinop_C7l83JGc_sendMessage);
}

void Heavy_CircleStrings::cCast_O15hlNnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YYrZZpFy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_Qk5wgHIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_03hOnG6S_sendMessage);
  cSwitchcase_atfqGeYH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_03hOnG6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qk5wgHIG, 1, m, &cVar_Qk5wgHIG_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_atfqGeYH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_eH0iKgEc_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_eH0iKgEc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Aj5y5jd_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_mfNbgjsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mfNbgjsw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mfNbgjsw, 0, m, &cDelay_mfNbgjsw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_G7kPt8UZ, 0, m, &cVar_G7kPt8UZ_sendMessage);
  cSwitchcase_2TDE6Rww_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_1Aj5y5jd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eH0iKgEc_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mfNbgjsw, 0, m, &cDelay_mfNbgjsw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_G7kPt8UZ, 0, m, &cVar_G7kPt8UZ_sendMessage);
  cSwitchcase_2TDE6Rww_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_XbIYx698_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nYGm5NyK_sendMessage);
}

void Heavy_CircleStrings::cSystem_nYGm5NyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BO2NeAoD_sendMessage);
}

void Heavy_CircleStrings::cVar_eQGzO0WU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2507H0fe, HV_BINOP_MULTIPLY, 0, m, &cBinop_2507H0fe_sendMessage);
}

void Heavy_CircleStrings::cMsg_eH0iKgEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mfNbgjsw, 0, m, &cDelay_mfNbgjsw_sendMessage);
}

void Heavy_CircleStrings::cBinop_uMuKaufl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mfNbgjsw, 2, m, &cDelay_mfNbgjsw_sendMessage);
}

void Heavy_CircleStrings::cBinop_BO2NeAoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2507H0fe, HV_BINOP_MULTIPLY, 1, m, &cBinop_2507H0fe_sendMessage);
}

void Heavy_CircleStrings::cBinop_2507H0fe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_uMuKaufl_sendMessage);
}

void Heavy_CircleStrings::cVar_G7kPt8UZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_dE5ZBCHO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_19Axrx4s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LNOBI81n_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_2TDE6Rww_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mxYYtN18, 0, m, &cSlice_mxYYtN18_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_64wA5T5W, 0, m, &cRandom_64wA5T5W_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_VztKvWiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tbhYC7q7_sendMessage);
}

void Heavy_CircleStrings::cUnop_tbhYC7q7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_NnPtnkRs_sendMessage);
}

void Heavy_CircleStrings::cRandom_64wA5T5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_VztKvWiy_sendMessage);
}

void Heavy_CircleStrings::cSlice_mxYYtN18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_64wA5T5W, 1, m, &cRandom_64wA5T5W_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_H60UPPGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_GbQb6zob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, -1.0f, 0, m, &cBinop_JFomLV29_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_3qy7sCg9, 0, m, &cIf_3qy7sCg9_sendMessage);
      break;
    }
    case 1: {
      cMsg_xDSQd8Td_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Z2ZYBtH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GbQb6zob, 1, m, &cIf_GbQb6zob_sendMessage);
}

void Heavy_CircleStrings::cIf_3qy7sCg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_NbIgWGog_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_mqjEMZNd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_JFomLV29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3qy7sCg9, 1, m, &cIf_3qy7sCg9_sendMessage);
}

void Heavy_CircleStrings::cMsg_xDSQd8Td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_mqjEMZNd_sendMessage);
}

void Heavy_CircleStrings::cMsg_NbIgWGog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_mqjEMZNd_sendMessage);
}

void Heavy_CircleStrings::cIf_CVNk8DoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_660kc9e8_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_yveNhkrF, 0, m, &cIf_yveNhkrF_sendMessage);
      break;
    }
    case 1: {
      cMsg_dib9Bdhg_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_mixmevJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CVNk8DoK, 1, m, &cIf_CVNk8DoK_sendMessage);
}

void Heavy_CircleStrings::cIf_yveNhkrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_XhyTfkV5_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_gnu8oyQl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_660kc9e8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yveNhkrF, 1, m, &cIf_yveNhkrF_sendMessage);
}

void Heavy_CircleStrings::cMsg_dib9Bdhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_gnu8oyQl_sendMessage);
}

void Heavy_CircleStrings::cMsg_XhyTfkV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_gnu8oyQl_sendMessage);
}

void Heavy_CircleStrings::cPack_QJ7s57YO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yBLxNPSA, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_QxHT9LxP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6uGgHRhC, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_OcCnWFYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T6QfnJgn, 0, m, &cVar_T6QfnJgn_sendMessage);
}

void Heavy_CircleStrings::cBinop_WFUS8OVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_kgRtYvWv_sendMessage);
}

void Heavy_CircleStrings::cBinop_kgRtYvWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_eoSqOASA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_3zLUoZmp, 0, m, &cIf_3zLUoZmp_sendMessage);
}

void Heavy_CircleStrings::cBinop_NnPtnkRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eQGzO0WU, 0, m, &cVar_eQGzO0WU_sendMessage);
}

void Heavy_CircleStrings::cBinop_vcBDx8nD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NUFMr1zH, m);
}

void Heavy_CircleStrings::cBinop_mqjEMZNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.95f, 0, m, &cBinop_vcBDx8nD_sendMessage);
}

void Heavy_CircleStrings::cBinop_0ZzdjALZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HmaC2b4o, 0, m, &cVar_HmaC2b4o_sendMessage);
}

void Heavy_CircleStrings::cBinop_gnu8oyQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2200.0f, 0, m, &cBinop_0ZzdjALZ_sendMessage);
}

void Heavy_CircleStrings::cCast_BdISKzza_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oEeQqFAG_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_djeSzLFU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_3gYG4Lu7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PTzPE5d9_sendMessage(_c, 0, m);
  cSend_4LJWhERV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_oEeQqFAG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oVOCePRd, 0, m, &cSlice_oVOCePRd_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_FwtxF8MZ, 0, m, &cRandom_FwtxF8MZ_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_NZXkzbDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_idFsU5BS_sendMessage);
}

void Heavy_CircleStrings::cUnop_idFsU5BS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_tIF4A2MQ_sendMessage);
  cSend_ctwzmje3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_FwtxF8MZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_NZXkzbDi_sendMessage);
}

void Heavy_CircleStrings::cSlice_oVOCePRd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_FwtxF8MZ, 1, m, &cRandom_FwtxF8MZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_ndtHWPwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_U2BVudPd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_6JdDI1vD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_fHqUDGjS_sendMessage);
}

void Heavy_CircleStrings::cBinop_fHqUDGjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6JdDI1vD, 1, m, &cVar_6JdDI1vD_sendMessage);
}

void Heavy_CircleStrings::cCast_TLlwndhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_NTwA4EOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_jPyGA2sY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cCast_MuX7b8TD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sgfWsDW3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_djeSzLFU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZHBjo0O9, 0, m, &cSlice_ZHBjo0O9_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hKFncde8, 0, m, &cRandom_hKFncde8_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_oPpIO15W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QtLDEVB2_sendMessage);
}

void Heavy_CircleStrings::cUnop_QtLDEVB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 20.0f, 0, m, &cBinop_2d14wucc_sendMessage);
}

void Heavy_CircleStrings::cRandom_hKFncde8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_oPpIO15W_sendMessage);
}

void Heavy_CircleStrings::cSlice_ZHBjo0O9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hKFncde8, 1, m, &cRandom_hKFncde8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_XU8B4x8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aKJN4ug9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xfJpLXXh_sendMessage);
}

void Heavy_CircleStrings::cBinop_tIF4A2MQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ndtHWPwh, 0, m, &cVar_ndtHWPwh_sendMessage);
}

void Heavy_CircleStrings::cSend_U2BVudPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IuHMkwR7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_PTzPE5d9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_seFUm3TM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_ctwzmje3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eVKiQ93V_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_4LJWhERV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RPWcUIkk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_PNMDirFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_MEOai0EY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_MEOai0EY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Sfbdnzv2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_uND5nMGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_MEOai0EY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_sgfWsDW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ijzEOQ4z_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_2d14wucc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3gYG4Lu7, 0, m, &cVar_3gYG4Lu7_sendMessage);
}

void Heavy_CircleStrings::cCast_aKJN4ug9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rbjk8D0b_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_xfJpLXXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VPGaXr2v_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_VPGaXr2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 64.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_3gYG4Lu7, 0, m, &cVar_3gYG4Lu7_sendMessage);
}

void Heavy_CircleStrings::cMsg_rbjk8D0b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 127.0f);
  cSend_ctwzmje3_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_tIF4A2MQ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_MgcOWHZf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qsAuLOag, 0, m, &cSlice_qsAuLOag_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tTcu2TaK, 0, m, &cRandom_tTcu2TaK_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_e6REkogF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hJwzXsC7_sendMessage);
}

void Heavy_CircleStrings::cUnop_hJwzXsC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_NRr8Ef4N_sendMessage);
}

void Heavy_CircleStrings::cRandom_tTcu2TaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_e6REkogF_sendMessage);
}

void Heavy_CircleStrings::cSlice_qsAuLOag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tTcu2TaK, 1, m, &cRandom_tTcu2TaK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_HUJbQUBi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2n1wWTGw, 0, m, &cSlice_2n1wWTGw_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MHqymPpo, 0, m, &cRandom_MHqymPpo_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_giuyN5lk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_EZRm40bE_sendMessage);
}

void Heavy_CircleStrings::cUnop_EZRm40bE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_pCjYggZ4_sendMessage);
}

void Heavy_CircleStrings::cRandom_MHqymPpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_giuyN5lk_sendMessage);
}

void Heavy_CircleStrings::cSlice_2n1wWTGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MHqymPpo, 1, m, &cRandom_MHqymPpo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_grySBecF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q1c8fD6M, HV_BINOP_MULTIPLY, 0, m, &cBinop_Q1c8fD6M_sendMessage);
}

void Heavy_CircleStrings::cBinop_TUMgnglC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_mBSqFgXZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_mBSqFgXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OWhBA4MI, HV_BINOP_POW, 1, m, &cBinop_OWhBA4MI_sendMessage);
  cMsg_K0MYj9pE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_OWhBA4MI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_grySBecF_sendMessage);
}

void Heavy_CircleStrings::cMsg_K0MYj9pE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OWhBA4MI, HV_BINOP_POW, 0, m, &cBinop_OWhBA4MI_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_mr8Q2hH3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fphTKkLP, 0, m, &cSlice_fphTKkLP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Km6t7NKj, 0, m, &cRandom_Km6t7NKj_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_ofvT3eY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WwCRBV1w_sendMessage);
}

void Heavy_CircleStrings::cUnop_WwCRBV1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AA5XxIGl_sendMessage);
}

void Heavy_CircleStrings::cRandom_Km6t7NKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_ofvT3eY5_sendMessage);
}

void Heavy_CircleStrings::cSlice_fphTKkLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Km6t7NKj, 1, m, &cRandom_Km6t7NKj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_B4OSk6Bi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_w8L8FYXi, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_Vlr0LmHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_SlIkk4rp_sendMessage);
}

void Heavy_CircleStrings::cVar_eNZp7z3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_hZGe92G2, 0, m);
}

void Heavy_CircleStrings::cVar_vL4ksuZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ExnIj2eN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vKu537lj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E0WJ6AzL_sendMessage);
}

void Heavy_CircleStrings::cVar_5Mq56m6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_2r4etoyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_2SBSiAIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_Ruzy1vC7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_N5MEbGC8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_N5MEbGC8_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_1BrC8OKv, 1, m, &cDelay_1BrC8OKv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YXP2GTwI_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_1BrC8OKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1BrC8OKv, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YpEFFqUn, 0, m, &cVar_YpEFFqUn_sendMessage);
}

void Heavy_CircleStrings::cMsg_N5MEbGC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1BrC8OKv, 0, m, &cDelay_1BrC8OKv_sendMessage);
}

void Heavy_CircleStrings::cCast_YXP2GTwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1BrC8OKv, 0, m, &cDelay_1BrC8OKv_sendMessage);
}

void Heavy_CircleStrings::cVar_YpEFFqUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZjslJL7F_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_XsorTXHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vL4ksuZB, 0, m, &cVar_vL4ksuZB_sendMessage);
}

void Heavy_CircleStrings::cMsg_5ir8TdyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_JtSacuKh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_JktmHPoc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_D8p4Jv44_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_PxsQj8wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_AKvFXcHG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_tNwgov09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9gBXmyIj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_XddWP5QI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_IGXq3UWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UuFhNhpg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_JtSacuKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_D8p4Jv44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9gBXmyIj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_AKvFXcHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UuFhNhpg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_sFAAryLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_964ec3Hj, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_ZjslJL7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_964ec3Hj, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_ExnIj2eN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sFAAryLO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_vKu537lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YpEFFqUn, 1, m, &cVar_YpEFFqUn_sendMessage);
}

void Heavy_CircleStrings::cCast_E0WJ6AzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ruzy1vC7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_yNFwVVGQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_D0tUm4sJ, 0, m, &cSlice_D0tUm4sJ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HS8OObJA, 0, m, &cRandom_HS8OObJA_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_iQ1XBRMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yFBHmJKG_sendMessage);
}

void Heavy_CircleStrings::cUnop_yFBHmJKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jCzHt4NH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_HS8OObJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_iQ1XBRMK_sendMessage);
}

void Heavy_CircleStrings::cSlice_D0tUm4sJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HS8OObJA, 1, m, &cRandom_HS8OObJA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_jCzHt4NH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_86awwOFU, m);
}

void Heavy_CircleStrings::cTabhead_L6l0vtmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CKGBlLQo, HV_BINOP_SUBTRACT, 0, m, &cBinop_CKGBlLQo_sendMessage);
}

void Heavy_CircleStrings::cMsg_Hy08y92B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xm05r7fM_sendMessage);
}

void Heavy_CircleStrings::cSystem_xm05r7fM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zjGXUoiZ_sendMessage);
}

void Heavy_CircleStrings::cVar_moFhwctb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ryfkARhN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_EIrnOnk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EIrnOnk1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_arErv4vd, 0, m, &cDelay_arErv4vd_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GYXlYRcm, 0, m, &sTabread_GYXlYRcm_sendMessage);
}

void Heavy_CircleStrings::cDelay_arErv4vd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_arErv4vd, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GYXlYRcm, 0, m, &sTabread_GYXlYRcm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_arErv4vd, 0, m, &cDelay_arErv4vd_sendMessage);
}

void Heavy_CircleStrings::sTabread_GYXlYRcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nkxX6Ikf, HV_BINOP_SUBTRACT, 0, m, &cBinop_nkxX6Ikf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_qYMzRDD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HtoEPK5J, HV_BINOP_MAX, 0, m, &cBinop_HtoEPK5J_sendMessage);
}

void Heavy_CircleStrings::cBinop_zjGXUoiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qYMzRDD0, HV_BINOP_MULTIPLY, 0, m, &cBinop_qYMzRDD0_sendMessage);
}

void Heavy_CircleStrings::cBinop_CKGBlLQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zfNnXRO9_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GYXlYRcm, 0, m, &sTabread_GYXlYRcm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5zdnNzqQ_sendMessage);
}

void Heavy_CircleStrings::cSystem_dlKN5111_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nkxX6Ikf, HV_BINOP_SUBTRACT, 1, m, &cBinop_nkxX6Ikf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_arErv4vd, 2, m, &cDelay_arErv4vd_sendMessage);
}

void Heavy_CircleStrings::cMsg_ryfkARhN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dlKN5111_sendMessage);
}

void Heavy_CircleStrings::cMsg_zfNnXRO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EIrnOnk1, 0, m, &cDelay_EIrnOnk1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_arErv4vd, 0, m, &cDelay_arErv4vd_sendMessage);
}

void Heavy_CircleStrings::cMsg_93xtLClp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_HtoEPK5J, HV_BINOP_MAX, 1, m, &cBinop_HtoEPK5J_sendMessage);
}

void Heavy_CircleStrings::cBinop_HtoEPK5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CKGBlLQo, HV_BINOP_SUBTRACT, 1, m, &cBinop_CKGBlLQo_sendMessage);
}

void Heavy_CircleStrings::cCast_5zdnNzqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EIrnOnk1, 0, m, &cDelay_EIrnOnk1_sendMessage);
}

void Heavy_CircleStrings::cBinop_yyixnaYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EIrnOnk1, 2, m, &cDelay_EIrnOnk1_sendMessage);
}

void Heavy_CircleStrings::cBinop_nkxX6Ikf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yyixnaYD_sendMessage);
}

void Heavy_CircleStrings::cCast_N9RQzZuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_moFhwctb, 0, m, &cVar_moFhwctb_sendMessage);
  cMsg_Hy08y92B_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_L6l0vtmE, 0, m, &cTabhead_L6l0vtmE_sendMessage);
}

void Heavy_CircleStrings::cBinop_FgyVfHmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sQprt16M_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B7WupdR7_sendMessage);
}

void Heavy_CircleStrings::cBinop_ymCkwREN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_PhfiRVpd_sendMessage);
}

void Heavy_CircleStrings::cBinop_PhfiRVpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZQGbLzrV, HV_BINOP_POW, 1, m, &cBinop_ZQGbLzrV_sendMessage);
  cMsg_cqt6kd0b_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_ZQGbLzrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_FgyVfHmR_sendMessage);
}

void Heavy_CircleStrings::cMsg_cqt6kd0b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZQGbLzrV, HV_BINOP_POW, 0, m, &cBinop_ZQGbLzrV_sendMessage);
}

void Heavy_CircleStrings::cVar_SvRFj9NO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ymCkwREN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZzIXCcTk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WXvdt4LR_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_N0fnMXrl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_6RtJ2DEv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_6RtJ2DEv_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_6sFVeQUc, 1, m, &cDelay_6sFVeQUc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HsIeg7p5_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_6sFVeQUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6sFVeQUc, m);
  cMsg_cESY7Bkm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_6RtJ2DEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6sFVeQUc, 0, m, &cDelay_6sFVeQUc_sendMessage);
}

void Heavy_CircleStrings::cCast_HsIeg7p5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6sFVeQUc, 0, m, &cDelay_6sFVeQUc_sendMessage);
}

void Heavy_CircleStrings::cVar_zoXTuhOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lz10Mxf7, HV_BINOP_MULTIPLY, 0, m, &cBinop_Lz10Mxf7_sendMessage);
}

void Heavy_CircleStrings::cMsg_lU1Ig6ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3mRFnqIR_sendMessage);
}

void Heavy_CircleStrings::cSystem_3mRFnqIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UhiOjsWE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Lz10Mxf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_DGSNohk0_sendMessage);
}

void Heavy_CircleStrings::cBinop_XUGFrJtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lz10Mxf7, HV_BINOP_MULTIPLY, 1, m, &cBinop_Lz10Mxf7_sendMessage);
}

void Heavy_CircleStrings::cMsg_UhiOjsWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XUGFrJtD_sendMessage);
}

void Heavy_CircleStrings::cBinop_DGSNohk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IcXnL3UJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_IcXnL3UJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KbUJMPqC_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZHYUlze1, m);
}

void Heavy_CircleStrings::cBinop_KbUJMPqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TokwBxRx, m);
}

void Heavy_CircleStrings::cMsg_zs84YcSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_leY8b3pq_sendMessage);
}

void Heavy_CircleStrings::cSystem_leY8b3pq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4dN4juaZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_a5BJR1MF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_a5BJR1MF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IFu76mCM, 0, m, &cDelay_IFu76mCM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_a5BJR1MF, 0, m, &cDelay_a5BJR1MF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vrh8RkrH, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_IFu76mCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IFu76mCM, m);
  cMsg_SFWg3JZ9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_jwznvTYP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mrvC9v8j_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_WMKfsCTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DWN5PDy9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_AG33Nc1W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xbItY4gK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_a5BJR1MF, 2, m, &cDelay_a5BJR1MF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KsQNyNY8_sendMessage);
}

void Heavy_CircleStrings::cMsg_DWN5PDy9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_AG33Nc1W, 0, m, &hTable_AG33Nc1W_sendMessage);
}

void Heavy_CircleStrings::cBinop_4dN4juaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_WMKfsCTB_sendMessage);
}

void Heavy_CircleStrings::cMsg_SFWg3JZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_AG33Nc1W, 0, m, &hTable_AG33Nc1W_sendMessage);
}

void Heavy_CircleStrings::cCast_KsQNyNY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_a5BJR1MF, 0, m, &cDelay_a5BJR1MF_sendMessage);
}

void Heavy_CircleStrings::cMsg_xbItY4gK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_IFu76mCM, 2, m, &cDelay_IFu76mCM_sendMessage);
}

void Heavy_CircleStrings::cMsg_mrvC9v8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vrh8RkrH, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_O9nOGXsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Pj4QS8W0, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_cESY7Bkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Pj4QS8W0, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_ZzIXCcTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_N0fnMXrl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_WXvdt4LR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O9nOGXsb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_dmvQKcaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ymCkwREN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZzIXCcTk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WXvdt4LR_sendMessage);
}

void Heavy_CircleStrings::cBinop_SQf3MLnv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qYMzRDD0, HV_BINOP_MULTIPLY, 1, m, &cBinop_qYMzRDD0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N9RQzZuj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6sFVeQUc, 1, m, &cDelay_6sFVeQUc_sendMessage);
}

void Heavy_CircleStrings::cMsg_6hD9SC6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SQf3MLnv, HV_BINOP_DIVIDE, 0, m, &cBinop_SQf3MLnv_sendMessage);
}

void Heavy_CircleStrings::cCast_sQprt16M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SQf3MLnv, HV_BINOP_DIVIDE, 1, m, &cBinop_SQf3MLnv_sendMessage);
}

void Heavy_CircleStrings::cCast_B7WupdR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6hD9SC6F_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_5JuQp8Gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_e7S6G6mQ, 0, m, &cPack_e7S6G6mQ_sendMessage);
}

void Heavy_CircleStrings::cUnop_gKtxzl0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_j9AErNuL, 0, m, &cPack_j9AErNuL_sendMessage);
}

void Heavy_CircleStrings::cPack_j9AErNuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_BHW7nLyY, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_e7S6G6mQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_l9fmtAyJ, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_VbTQFM57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_5JuQp8Gk_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_gKtxzl0C_sendMessage);
}

void Heavy_CircleStrings::cMsg_r9bUgxLS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_VbTQFM57_sendMessage);
}

void Heavy_CircleStrings::cSlice_DNi3mEdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_aU9W1c4f_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_CxhP4gwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hNZ2QnPv_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_TUMgnglC_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ymCkwREN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZzIXCcTk_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WXvdt4LR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_pCjYggZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_BDk9VThH_sendMessage);
}

void Heavy_CircleStrings::cBinop_BDk9VThH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_VbTQFM57_sendMessage);
}

void Heavy_CircleStrings::cBinop_aU9W1c4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tqz1Glkj_sendMessage(_c, 0, m);
  cSend_LcBjVqXO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Q1c8fD6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KZsQ87vn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pxKbRr0H_sendMessage);
}

void Heavy_CircleStrings::cBinop_AA5XxIGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_WC8EunBx_sendMessage);
}

void Heavy_CircleStrings::cBinop_WC8EunBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q1c8fD6M, HV_BINOP_MULTIPLY, 1, m, &cBinop_Q1c8fD6M_sendMessage);
}

void Heavy_CircleStrings::cSend_tqz1Glkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iZs0339h_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_KZsQ87vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HUJbQUBi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_pxKbRr0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XsorTXHp_sendMessage);
}

void Heavy_CircleStrings::cBinop_SlIkk4rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_B4OSk6Bi, 0, m, &cPack_B4OSk6Bi_sendMessage);
}

void Heavy_CircleStrings::cSend_LcBjVqXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rPLLZSoQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_RlR2pVNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_voLTETyR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_iSU2ZNlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_RlR2pVNj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_d8FQUpZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kT2b3zGO, m);
}

void Heavy_CircleStrings::cCast_hNZ2QnPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mr8Q2hH3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_mZAIGs13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kzs14rTg_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kELBtryh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7OtJjyYp_sendMessage);
}

void Heavy_CircleStrings::cIf_kznQKbup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_w5KQKANl_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_MtVAMMlQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_dAsgtqw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wz4b4wg1, HV_BINOP_POW, 0, m, &cBinop_Wz4b4wg1_sendMessage);
}

void Heavy_CircleStrings::cBinop_Wz4b4wg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LLSvipAK, 0, m, &cPack_LLSvipAK_sendMessage);
}

void Heavy_CircleStrings::cBinop_di3pekR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_MdrWQiZs_sendMessage);
}

void Heavy_CircleStrings::cCast_7OtJjyYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kznQKbup, 0, m, &cIf_kznQKbup_sendMessage);
}

void Heavy_CircleStrings::cCast_kELBtryh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MLiteNdt_sendMessage);
}

void Heavy_CircleStrings::cBinop_MLiteNdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kznQKbup, 1, m, &cIf_kznQKbup_sendMessage);
}

void Heavy_CircleStrings::cBinop_MtVAMMlQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_di3pekR0_sendMessage);
}

void Heavy_CircleStrings::cMsg_w5KQKANl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_LLSvipAK, 0, m, &cPack_LLSvipAK_sendMessage);
}

void Heavy_CircleStrings::cBinop_MdrWQiZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wz4b4wg1, HV_BINOP_POW, 1, m, &cBinop_Wz4b4wg1_sendMessage);
  cMsg_dAsgtqw3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_LLSvipAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Vhv0DGli, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_Vngma2UP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gf6X28yH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Kzs14rTg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_3bRYnUi9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_3bRYnUi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ae1fK3UB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_gf6X28yH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NopesP73_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_VH5XJ4Pi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_See9RdJs_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yuzHGMeu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DQVNxTDj_sendMessage);
}

void Heavy_CircleStrings::cIf_IMU4fKg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Jmnb5Gst_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_KTpqvVlH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_akFcb3H1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9EVsgGCe, HV_BINOP_POW, 0, m, &cBinop_9EVsgGCe_sendMessage);
}

void Heavy_CircleStrings::cBinop_9EVsgGCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QG75d8Kc, 0, m, &cPack_QG75d8Kc_sendMessage);
}

void Heavy_CircleStrings::cBinop_fQF62lZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_7sVDCDaj_sendMessage);
}

void Heavy_CircleStrings::cCast_DQVNxTDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IMU4fKg8, 0, m, &cIf_IMU4fKg8_sendMessage);
}

void Heavy_CircleStrings::cCast_yuzHGMeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_PsHsOsDq_sendMessage);
}

void Heavy_CircleStrings::cBinop_PsHsOsDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IMU4fKg8, 1, m, &cIf_IMU4fKg8_sendMessage);
}

void Heavy_CircleStrings::cBinop_KTpqvVlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_fQF62lZd_sendMessage);
}

void Heavy_CircleStrings::cMsg_Jmnb5Gst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_QG75d8Kc, 0, m, &cPack_QG75d8Kc_sendMessage);
}

void Heavy_CircleStrings::cBinop_7sVDCDaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9EVsgGCe, HV_BINOP_POW, 1, m, &cBinop_9EVsgGCe_sendMessage);
  cMsg_akFcb3H1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_QG75d8Kc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OH37p02E, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_Na1HGBpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sSPP2Fb4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_See9RdJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_qt2Cauk3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_qt2Cauk3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7Xh37HGI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_sSPP2Fb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_F19zfk9g_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_BU1S9aDQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pUYHO3Ap, 0, m, &cSlice_pUYHO3Ap_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SHjTfHio, 0, m, &cRandom_SHjTfHio_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_bOEh2HBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Bwd2mxrq_sendMessage);
}

void Heavy_CircleStrings::cUnop_Bwd2mxrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_t2vP6M1n_sendMessage);
}

void Heavy_CircleStrings::cRandom_SHjTfHio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_bOEh2HBR_sendMessage);
}

void Heavy_CircleStrings::cSlice_pUYHO3Ap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SHjTfHio, 1, m, &cRandom_SHjTfHio_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_GNQmBXMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jLrpx2dW, HV_BINOP_MULTIPLY, 0, m, &cBinop_jLrpx2dW_sendMessage);
}

void Heavy_CircleStrings::cBinop_n7pn4MYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_wBPdjDI6_sendMessage);
}

void Heavy_CircleStrings::cBinop_wBPdjDI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2XkvzzZK, HV_BINOP_POW, 1, m, &cBinop_2XkvzzZK_sendMessage);
  cMsg_MsAaN5Zk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_2XkvzzZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_GNQmBXMo_sendMessage);
}

void Heavy_CircleStrings::cMsg_MsAaN5Zk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2XkvzzZK, HV_BINOP_POW, 0, m, &cBinop_2XkvzzZK_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_4QubbrVm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_y1wRNRDN, 0, m, &cSlice_y1wRNRDN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_adWwT3mK, 0, m, &cRandom_adWwT3mK_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_X1htOAJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tI2GM1H9_sendMessage);
}

void Heavy_CircleStrings::cUnop_tI2GM1H9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Yi1vgy5f_sendMessage);
}

void Heavy_CircleStrings::cRandom_adWwT3mK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_X1htOAJg_sendMessage);
}

void Heavy_CircleStrings::cSlice_y1wRNRDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_adWwT3mK, 1, m, &cRandom_adWwT3mK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_XXwv7GDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Euvi18F8, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_ZkTyOhq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_b2LPw8HL_sendMessage);
}

void Heavy_CircleStrings::cVar_LzAbDq2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_3EyaiDYY, 0, m);
}

void Heavy_CircleStrings::cVar_XCDt9fiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_naxcFjn7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5cpYWcKV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_URHmbGMC_sendMessage);
}

void Heavy_CircleStrings::cVar_P4hoSHQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_sbfhSN5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_HMxCN95O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_Q6njYsM8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_FAndsq0b_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_FAndsq0b_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_MBoOUoYc, 1, m, &cDelay_MBoOUoYc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FS63cR8D_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_MBoOUoYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MBoOUoYc, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iKmE3Hbg, 0, m, &cVar_iKmE3Hbg_sendMessage);
}

void Heavy_CircleStrings::cMsg_FAndsq0b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_MBoOUoYc, 0, m, &cDelay_MBoOUoYc_sendMessage);
}

void Heavy_CircleStrings::cCast_FS63cR8D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MBoOUoYc, 0, m, &cDelay_MBoOUoYc_sendMessage);
}

void Heavy_CircleStrings::cVar_iKmE3Hbg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GwjcAQwo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_POBkk242_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XCDt9fiR, 0, m, &cVar_XCDt9fiR_sendMessage);
}

void Heavy_CircleStrings::cMsg_HnvPqQcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_Pg6vaqWk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_PKdn4C2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_4dmaItID_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_SuJnz0Dy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_M0luBWB6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_gIYObIhD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fL7WIF1a_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_hOe5n6OG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_AyZ2Gbzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xyFYFaXb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Pg6vaqWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_4dmaItID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fL7WIF1a_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_M0luBWB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xyFYFaXb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_MqyGvG2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5zbd8vEX, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_GwjcAQwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_5zbd8vEX, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_URHmbGMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Q6njYsM8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_5cpYWcKV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iKmE3Hbg, 1, m, &cVar_iKmE3Hbg_sendMessage);
}

void Heavy_CircleStrings::cCast_naxcFjn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MqyGvG2m_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_lRgi0EVf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yqPdIBEr, 0, m, &cSlice_yqPdIBEr_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BUVlQ14G, 0, m, &cRandom_BUVlQ14G_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_wlrKwX41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_8BliUL4m_sendMessage);
}

void Heavy_CircleStrings::cUnop_8BliUL4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zwtgdv3D_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_BUVlQ14G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_wlrKwX41_sendMessage);
}

void Heavy_CircleStrings::cSlice_yqPdIBEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BUVlQ14G, 1, m, &cRandom_BUVlQ14G_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_zwtgdv3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_s4GXElM2, m);
}

void Heavy_CircleStrings::cTabhead_3Ry4iUeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fW7D2eSQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_fW7D2eSQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_h3O9mG4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XW0Lv0KW_sendMessage);
}

void Heavy_CircleStrings::cSystem_XW0Lv0KW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IwWWXoaH_sendMessage);
}

void Heavy_CircleStrings::cVar_2yX8b2SI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LhDO0wjm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_rMYRqUCE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rMYRqUCE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BKn7Rwl5, 0, m, &cDelay_BKn7Rwl5_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1aCCkw6G, 0, m, &sTabread_1aCCkw6G_sendMessage);
}

void Heavy_CircleStrings::cDelay_BKn7Rwl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BKn7Rwl5, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1aCCkw6G, 0, m, &sTabread_1aCCkw6G_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BKn7Rwl5, 0, m, &cDelay_BKn7Rwl5_sendMessage);
}

void Heavy_CircleStrings::sTabread_1aCCkw6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Cl1ExGCt, HV_BINOP_SUBTRACT, 0, m, &cBinop_Cl1ExGCt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_DlwQAemn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BV38kTlv, HV_BINOP_MAX, 0, m, &cBinop_BV38kTlv_sendMessage);
}

void Heavy_CircleStrings::cBinop_IwWWXoaH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DlwQAemn, HV_BINOP_MULTIPLY, 0, m, &cBinop_DlwQAemn_sendMessage);
}

void Heavy_CircleStrings::cBinop_fW7D2eSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YbuSIQxd_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1aCCkw6G, 0, m, &sTabread_1aCCkw6G_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CXAKjq9V_sendMessage);
}

void Heavy_CircleStrings::cSystem_eg39hcXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cl1ExGCt, HV_BINOP_SUBTRACT, 1, m, &cBinop_Cl1ExGCt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BKn7Rwl5, 2, m, &cDelay_BKn7Rwl5_sendMessage);
}

void Heavy_CircleStrings::cMsg_LhDO0wjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eg39hcXG_sendMessage);
}

void Heavy_CircleStrings::cMsg_YbuSIQxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rMYRqUCE, 0, m, &cDelay_rMYRqUCE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BKn7Rwl5, 0, m, &cDelay_BKn7Rwl5_sendMessage);
}

void Heavy_CircleStrings::cMsg_PxhMeP1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_BV38kTlv, HV_BINOP_MAX, 1, m, &cBinop_BV38kTlv_sendMessage);
}

void Heavy_CircleStrings::cBinop_BV38kTlv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fW7D2eSQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_fW7D2eSQ_sendMessage);
}

void Heavy_CircleStrings::cCast_CXAKjq9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rMYRqUCE, 0, m, &cDelay_rMYRqUCE_sendMessage);
}

void Heavy_CircleStrings::cBinop_oLXpWiv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rMYRqUCE, 2, m, &cDelay_rMYRqUCE_sendMessage);
}

void Heavy_CircleStrings::cBinop_Cl1ExGCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oLXpWiv4_sendMessage);
}

void Heavy_CircleStrings::cCast_erSHOCm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2yX8b2SI, 0, m, &cVar_2yX8b2SI_sendMessage);
  cMsg_h3O9mG4N_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3Ry4iUeT, 0, m, &cTabhead_3Ry4iUeT_sendMessage);
}

void Heavy_CircleStrings::cBinop_sfMgoaMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PwBbdEZB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JtndDWDT_sendMessage);
}

void Heavy_CircleStrings::cBinop_aePAZHzb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_4hyHUSQT_sendMessage);
}

void Heavy_CircleStrings::cBinop_4hyHUSQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wccnz9kr, HV_BINOP_POW, 1, m, &cBinop_Wccnz9kr_sendMessage);
  cMsg_TtBACAhC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Wccnz9kr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_sfMgoaMu_sendMessage);
}

void Heavy_CircleStrings::cMsg_TtBACAhC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wccnz9kr, HV_BINOP_POW, 0, m, &cBinop_Wccnz9kr_sendMessage);
}

void Heavy_CircleStrings::cVar_VcG7V7jh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_aePAZHzb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U8YZkgic_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JhWj2zII_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_iJFNxbsm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_cacLDsfd_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_cacLDsfd_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_C6VSmyqh, 1, m, &cDelay_C6VSmyqh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8mOrcH4E_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_C6VSmyqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_C6VSmyqh, m);
  cMsg_lvUrhCnE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_cacLDsfd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_C6VSmyqh, 0, m, &cDelay_C6VSmyqh_sendMessage);
}

void Heavy_CircleStrings::cCast_8mOrcH4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_C6VSmyqh, 0, m, &cDelay_C6VSmyqh_sendMessage);
}

void Heavy_CircleStrings::cVar_aeL9JXfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GsUwJ2yW, HV_BINOP_MULTIPLY, 0, m, &cBinop_GsUwJ2yW_sendMessage);
}

void Heavy_CircleStrings::cMsg_mAwJA1Ct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_COgur9ky_sendMessage);
}

void Heavy_CircleStrings::cSystem_COgur9ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v5QVKbrd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_GsUwJ2yW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_aoX7osZT_sendMessage);
}

void Heavy_CircleStrings::cBinop_JKARC0wQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GsUwJ2yW, HV_BINOP_MULTIPLY, 1, m, &cBinop_GsUwJ2yW_sendMessage);
}

void Heavy_CircleStrings::cMsg_v5QVKbrd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JKARC0wQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_aoX7osZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QARKePgX_sendMessage);
}

void Heavy_CircleStrings::cBinop_QARKePgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bnRs5qR9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IM1d81Zv, m);
}

void Heavy_CircleStrings::cBinop_bnRs5qR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VJzAFhB9, m);
}

void Heavy_CircleStrings::cMsg_KloEyMSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5vqu7LsD_sendMessage);
}

void Heavy_CircleStrings::cSystem_5vqu7LsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yMGRauGP_sendMessage);
}

void Heavy_CircleStrings::cDelay_6QJiBLol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6QJiBLol, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iSjzkI8p, 0, m, &cDelay_iSjzkI8p_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6QJiBLol, 0, m, &cDelay_6QJiBLol_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KvpKG1Gm, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_iSjzkI8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iSjzkI8p, m);
  cMsg_NiUoKbzZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_A4A9lt8Y_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_BVjWxs6m_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Dr4NkeuU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R9ByEn7y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_0JR0CnnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CUcMia4U_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6QJiBLol, 2, m, &cDelay_6QJiBLol_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZLJ66E1R_sendMessage);
}

void Heavy_CircleStrings::cMsg_R9ByEn7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_0JR0CnnU, 0, m, &hTable_0JR0CnnU_sendMessage);
}

void Heavy_CircleStrings::cBinop_yMGRauGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_Dr4NkeuU_sendMessage);
}

void Heavy_CircleStrings::cMsg_NiUoKbzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_0JR0CnnU, 0, m, &hTable_0JR0CnnU_sendMessage);
}

void Heavy_CircleStrings::cCast_ZLJ66E1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6QJiBLol, 0, m, &cDelay_6QJiBLol_sendMessage);
}

void Heavy_CircleStrings::cMsg_CUcMia4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_iSjzkI8p, 2, m, &cDelay_iSjzkI8p_sendMessage);
}

void Heavy_CircleStrings::cMsg_BVjWxs6m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KvpKG1Gm, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_tcUBxM9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_vCCpnqjj, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_lvUrhCnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_vCCpnqjj, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_JhWj2zII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tcUBxM9d_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_U8YZkgic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_iJFNxbsm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_BqoGZbCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_aePAZHzb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U8YZkgic_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JhWj2zII_sendMessage);
}

void Heavy_CircleStrings::cBinop_sNcoUjfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DlwQAemn, HV_BINOP_MULTIPLY, 1, m, &cBinop_DlwQAemn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_erSHOCm3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_C6VSmyqh, 1, m, &cDelay_C6VSmyqh_sendMessage);
}

void Heavy_CircleStrings::cMsg_S6UU5cum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sNcoUjfr, HV_BINOP_DIVIDE, 0, m, &cBinop_sNcoUjfr_sendMessage);
}

void Heavy_CircleStrings::cCast_PwBbdEZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sNcoUjfr, HV_BINOP_DIVIDE, 1, m, &cBinop_sNcoUjfr_sendMessage);
}

void Heavy_CircleStrings::cCast_JtndDWDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S6UU5cum_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_3gX5KqQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tI4J4088, 0, m, &cPack_tI4J4088_sendMessage);
}

void Heavy_CircleStrings::cUnop_7prJc2TF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IiqL7wlu, 0, m, &cPack_IiqL7wlu_sendMessage);
}

void Heavy_CircleStrings::cPack_IiqL7wlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_X3VQJ0O6, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_tI4J4088_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zQg6bCvl, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_eMnyFsLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_3gX5KqQM_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_7prJc2TF_sendMessage);
}

void Heavy_CircleStrings::cMsg_3KdbDoss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_eMnyFsLn_sendMessage);
}

void Heavy_CircleStrings::cSlice_3BFnNE9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_ACqYzvo9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_sR83pIAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XBhEmoYc_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_n7pn4MYL_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_aePAZHzb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U8YZkgic_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JhWj2zII_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_t2vP6M1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_hSXKWLQD_sendMessage);
}

void Heavy_CircleStrings::cBinop_hSXKWLQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_eMnyFsLn_sendMessage);
}

void Heavy_CircleStrings::cBinop_ACqYzvo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nco7ZQyP_sendMessage(_c, 0, m);
  cSend_QCOrnzCQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_jLrpx2dW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PzWIgMDf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y771YaKL_sendMessage);
}

void Heavy_CircleStrings::cBinop_Yi1vgy5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_JWn6eyNg_sendMessage);
}

void Heavy_CircleStrings::cBinop_JWn6eyNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jLrpx2dW, HV_BINOP_MULTIPLY, 1, m, &cBinop_jLrpx2dW_sendMessage);
}

void Heavy_CircleStrings::cSend_nco7ZQyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_j7cY7eko_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_PzWIgMDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BU1S9aDQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_Y771YaKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_POBkk242_sendMessage);
}

void Heavy_CircleStrings::cBinop_b2LPw8HL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XXwv7GDb, 0, m, &cPack_XXwv7GDb_sendMessage);
}

void Heavy_CircleStrings::cSend_QCOrnzCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sDGITZ0v_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_MUvdODuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DlThSkZj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_xAi3s4Fm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_MUvdODuX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_wXMaRijc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vFX25tA7, m);
}

void Heavy_CircleStrings::cCast_XBhEmoYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4QubbrVm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_lzUup5Z0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4aq2q8Yg, 0, m, &cSlice_4aq2q8Yg_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NoTJM03w, 0, m, &cRandom_NoTJM03w_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_KaSUPZ2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uJyHs9Qy_sendMessage);
}

void Heavy_CircleStrings::cUnop_uJyHs9Qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_5JBIU1L8_sendMessage);
}

void Heavy_CircleStrings::cRandom_NoTJM03w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_KaSUPZ2x_sendMessage);
}

void Heavy_CircleStrings::cSlice_4aq2q8Yg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NoTJM03w, 1, m, &cRandom_NoTJM03w_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_6J21plNO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wAgExA8f, HV_BINOP_MULTIPLY, 0, m, &cBinop_wAgExA8f_sendMessage);
}

void Heavy_CircleStrings::cBinop_TNWhjEfK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_2r3623e1_sendMessage);
}

void Heavy_CircleStrings::cBinop_2r3623e1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EJpyK6Wq, HV_BINOP_POW, 1, m, &cBinop_EJpyK6Wq_sendMessage);
  cMsg_Eeu2Rpdz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_EJpyK6Wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_6J21plNO_sendMessage);
}

void Heavy_CircleStrings::cMsg_Eeu2Rpdz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EJpyK6Wq, HV_BINOP_POW, 0, m, &cBinop_EJpyK6Wq_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_e0wzkdi9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0Qy3gyDT, 0, m, &cSlice_0Qy3gyDT_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7CHCGHH9, 0, m, &cRandom_7CHCGHH9_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_WB6ZjWyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_srB7sCz0_sendMessage);
}

void Heavy_CircleStrings::cUnop_srB7sCz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rP7safSL_sendMessage);
}

void Heavy_CircleStrings::cRandom_7CHCGHH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_WB6ZjWyX_sendMessage);
}

void Heavy_CircleStrings::cSlice_0Qy3gyDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7CHCGHH9, 1, m, &cRandom_7CHCGHH9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_3CrlaE0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mqYiiRZh, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_g5xTJrD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_BZ2d2Ek1_sendMessage);
}

void Heavy_CircleStrings::cVar_A3RkeXKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ekdPoVtd, 0, m);
}

void Heavy_CircleStrings::cVar_ezduzPWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NewVIBFk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4EIaLjyS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vniqKi4s_sendMessage);
}

void Heavy_CircleStrings::cVar_fwZmkAh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_aRmGFL5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_3OM1AKjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_86K53VSx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_MwwpHlMs_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_MwwpHlMs_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_1LR0uTQk, 1, m, &cDelay_1LR0uTQk_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AYMaZnOI_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_1LR0uTQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1LR0uTQk, m);
  cVar_onMessage(_c, &Context(_c)->cVar_N1d8i0o1, 0, m, &cVar_N1d8i0o1_sendMessage);
}

void Heavy_CircleStrings::cMsg_MwwpHlMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1LR0uTQk, 0, m, &cDelay_1LR0uTQk_sendMessage);
}

void Heavy_CircleStrings::cCast_AYMaZnOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1LR0uTQk, 0, m, &cDelay_1LR0uTQk_sendMessage);
}

void Heavy_CircleStrings::cVar_N1d8i0o1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mS9Pq6WY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_TdkZVToG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ezduzPWL, 0, m, &cVar_ezduzPWL_sendMessage);
}

void Heavy_CircleStrings::cMsg_zRh3ysAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_yfanzbzY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_l1ZUNHVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_EefKWkwg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_fOr99LuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_S8lOOZ27_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_2M3QTzwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RfpieZ96_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Sp7jF8IM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_IuD93B3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zHi8b9ZY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_yfanzbzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_EefKWkwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RfpieZ96_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_S8lOOZ27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zHi8b9ZY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Lm1hqrJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cqQWPtnv, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_mS9Pq6WY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_cqQWPtnv, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_4EIaLjyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N1d8i0o1, 1, m, &cVar_N1d8i0o1_sendMessage);
}

void Heavy_CircleStrings::cCast_vniqKi4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_86K53VSx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_NewVIBFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lm1hqrJS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_hN1p6IjO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_m8BCeyw0, 0, m, &cSlice_m8BCeyw0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4BNJCCOM, 0, m, &cRandom_4BNJCCOM_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_yRkFHcMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_k6t74woD_sendMessage);
}

void Heavy_CircleStrings::cUnop_k6t74woD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XjAfQRtW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_4BNJCCOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_yRkFHcMe_sendMessage);
}

void Heavy_CircleStrings::cSlice_m8BCeyw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4BNJCCOM, 1, m, &cRandom_4BNJCCOM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_XjAfQRtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_P0KwOnwe, m);
}

void Heavy_CircleStrings::cTabhead_Na6R33QA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ypOoxgmt, HV_BINOP_SUBTRACT, 0, m, &cBinop_ypOoxgmt_sendMessage);
}

void Heavy_CircleStrings::cMsg_3ZlHqMR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ylJsO9zo_sendMessage);
}

void Heavy_CircleStrings::cSystem_ylJsO9zo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_chrZCEtb_sendMessage);
}

void Heavy_CircleStrings::cVar_uh4L2ung_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q12YPU79_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_9mk6gQPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9mk6gQPb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hylt5tNo, 0, m, &cDelay_Hylt5tNo_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_N5fSY17U, 0, m, &sTabread_N5fSY17U_sendMessage);
}

void Heavy_CircleStrings::cDelay_Hylt5tNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Hylt5tNo, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_N5fSY17U, 0, m, &sTabread_N5fSY17U_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hylt5tNo, 0, m, &cDelay_Hylt5tNo_sendMessage);
}

void Heavy_CircleStrings::sTabread_N5fSY17U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xZMAjOfS, HV_BINOP_SUBTRACT, 0, m, &cBinop_xZMAjOfS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_2QXHpTQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PG2MlhF9, HV_BINOP_MAX, 0, m, &cBinop_PG2MlhF9_sendMessage);
}

void Heavy_CircleStrings::cBinop_chrZCEtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2QXHpTQQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_2QXHpTQQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_ypOoxgmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VBvRfvm8_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_N5fSY17U, 0, m, &sTabread_N5fSY17U_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MHmFYyRJ_sendMessage);
}

void Heavy_CircleStrings::cSystem_R7K4gEDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xZMAjOfS, HV_BINOP_SUBTRACT, 1, m, &cBinop_xZMAjOfS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hylt5tNo, 2, m, &cDelay_Hylt5tNo_sendMessage);
}

void Heavy_CircleStrings::cMsg_Q12YPU79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R7K4gEDB_sendMessage);
}

void Heavy_CircleStrings::cMsg_VBvRfvm8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9mk6gQPb, 0, m, &cDelay_9mk6gQPb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hylt5tNo, 0, m, &cDelay_Hylt5tNo_sendMessage);
}

void Heavy_CircleStrings::cMsg_LDe51aCk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_PG2MlhF9, HV_BINOP_MAX, 1, m, &cBinop_PG2MlhF9_sendMessage);
}

void Heavy_CircleStrings::cBinop_PG2MlhF9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ypOoxgmt, HV_BINOP_SUBTRACT, 1, m, &cBinop_ypOoxgmt_sendMessage);
}

void Heavy_CircleStrings::cCast_MHmFYyRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9mk6gQPb, 0, m, &cDelay_9mk6gQPb_sendMessage);
}

void Heavy_CircleStrings::cBinop_s9dkkUWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9mk6gQPb, 2, m, &cDelay_9mk6gQPb_sendMessage);
}

void Heavy_CircleStrings::cBinop_xZMAjOfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_s9dkkUWF_sendMessage);
}

void Heavy_CircleStrings::cCast_pdwc6ks5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uh4L2ung, 0, m, &cVar_uh4L2ung_sendMessage);
  cMsg_3ZlHqMR1_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Na6R33QA, 0, m, &cTabhead_Na6R33QA_sendMessage);
}

void Heavy_CircleStrings::cBinop_TSKE39KI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KKNcn0WF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SOI1ZU3w_sendMessage);
}

void Heavy_CircleStrings::cBinop_NjowaA62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_84AUEcP0_sendMessage);
}

void Heavy_CircleStrings::cBinop_84AUEcP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yEHzl3nj, HV_BINOP_POW, 1, m, &cBinop_yEHzl3nj_sendMessage);
  cMsg_QPh5mXUo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_yEHzl3nj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_TSKE39KI_sendMessage);
}

void Heavy_CircleStrings::cMsg_QPh5mXUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yEHzl3nj, HV_BINOP_POW, 0, m, &cBinop_yEHzl3nj_sendMessage);
}

void Heavy_CircleStrings::cVar_OJucAKYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_NjowaA62_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5oyehWlY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AhdV1UqW_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_Wsiuj8ze_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_R8C0zbHH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_R8C0zbHH_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_LFpm4xOG, 1, m, &cDelay_LFpm4xOG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OZcUQqSh_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_LFpm4xOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LFpm4xOG, m);
  cMsg_RAherqtq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_R8C0zbHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LFpm4xOG, 0, m, &cDelay_LFpm4xOG_sendMessage);
}

void Heavy_CircleStrings::cCast_OZcUQqSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LFpm4xOG, 0, m, &cDelay_LFpm4xOG_sendMessage);
}

void Heavy_CircleStrings::cVar_fHuTs3vg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SJ06ojst, HV_BINOP_MULTIPLY, 0, m, &cBinop_SJ06ojst_sendMessage);
}

void Heavy_CircleStrings::cMsg_mP2Qf2r3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_riJVioHo_sendMessage);
}

void Heavy_CircleStrings::cSystem_riJVioHo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_53igsvNV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_SJ06ojst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_rZrL0jgl_sendMessage);
}

void Heavy_CircleStrings::cBinop_jMknupK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SJ06ojst, HV_BINOP_MULTIPLY, 1, m, &cBinop_SJ06ojst_sendMessage);
}

void Heavy_CircleStrings::cMsg_53igsvNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_jMknupK5_sendMessage);
}

void Heavy_CircleStrings::cBinop_rZrL0jgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Zc5JfuHz_sendMessage);
}

void Heavy_CircleStrings::cBinop_Zc5JfuHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yhL1tSHd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BE6Uws89, m);
}

void Heavy_CircleStrings::cBinop_yhL1tSHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wFdXt49n, m);
}

void Heavy_CircleStrings::cMsg_LtQe16sJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AoxhIBZ4_sendMessage);
}

void Heavy_CircleStrings::cSystem_AoxhIBZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GdGiCJG6_sendMessage);
}

void Heavy_CircleStrings::cDelay_52X6l21J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_52X6l21J, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OWQW318v, 0, m, &cDelay_OWQW318v_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_52X6l21J, 0, m, &cDelay_52X6l21J_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lcGYQI2C, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_OWQW318v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OWQW318v, m);
  cMsg_yZqzsh0h_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_tbmI7cZh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_nqITwZoH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_OFq8FGNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qr2ww302_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_pPXD0eHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AWX0d1UE_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_52X6l21J, 2, m, &cDelay_52X6l21J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Toy8fuaG_sendMessage);
}

void Heavy_CircleStrings::cMsg_qr2ww302_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_pPXD0eHb, 0, m, &hTable_pPXD0eHb_sendMessage);
}

void Heavy_CircleStrings::cBinop_GdGiCJG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_OFq8FGNR_sendMessage);
}

void Heavy_CircleStrings::cMsg_yZqzsh0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_pPXD0eHb, 0, m, &hTable_pPXD0eHb_sendMessage);
}

void Heavy_CircleStrings::cCast_Toy8fuaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_52X6l21J, 0, m, &cDelay_52X6l21J_sendMessage);
}

void Heavy_CircleStrings::cMsg_AWX0d1UE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OWQW318v, 2, m, &cDelay_OWQW318v_sendMessage);
}

void Heavy_CircleStrings::cMsg_nqITwZoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lcGYQI2C, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_wexovSJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0lBOVxmG, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_RAherqtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0lBOVxmG, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_5oyehWlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Wsiuj8ze_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_AhdV1UqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wexovSJf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_c6qKQDii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_NjowaA62_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5oyehWlY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AhdV1UqW_sendMessage);
}

void Heavy_CircleStrings::cBinop_3jW0W2DO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2QXHpTQQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_2QXHpTQQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pdwc6ks5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LFpm4xOG, 1, m, &cDelay_LFpm4xOG_sendMessage);
}

void Heavy_CircleStrings::cMsg_nrpCG8Qc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3jW0W2DO, HV_BINOP_DIVIDE, 0, m, &cBinop_3jW0W2DO_sendMessage);
}

void Heavy_CircleStrings::cCast_KKNcn0WF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3jW0W2DO, HV_BINOP_DIVIDE, 1, m, &cBinop_3jW0W2DO_sendMessage);
}

void Heavy_CircleStrings::cCast_SOI1ZU3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nrpCG8Qc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_BMa1nyJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BlPYpO87, 0, m, &cPack_BlPYpO87_sendMessage);
}

void Heavy_CircleStrings::cUnop_ttqL1UBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1Jt11iTs, 0, m, &cPack_1Jt11iTs_sendMessage);
}

void Heavy_CircleStrings::cPack_1Jt11iTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_jggvrXTT, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_BlPYpO87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ZWduZLcc, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_SGw06JW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_BMa1nyJ1_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_ttqL1UBQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_ybkj9Mq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_SGw06JW0_sendMessage);
}

void Heavy_CircleStrings::cSlice_zGkZsTus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_pRDlTbkR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_AVb4qfw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DGqTriBk_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_TNWhjEfK_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_NjowaA62_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5oyehWlY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AhdV1UqW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_5JBIU1L8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_9Tew2K5B_sendMessage);
}

void Heavy_CircleStrings::cBinop_9Tew2K5B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_SGw06JW0_sendMessage);
}

void Heavy_CircleStrings::cBinop_pRDlTbkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VMfbbMLm_sendMessage(_c, 0, m);
  cSend_R8jTlpUv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_wAgExA8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c2hxK0ZS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R7YElIRF_sendMessage);
}

void Heavy_CircleStrings::cBinop_rP7safSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_63viUDl4_sendMessage);
}

void Heavy_CircleStrings::cBinop_63viUDl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wAgExA8f, HV_BINOP_MULTIPLY, 1, m, &cBinop_wAgExA8f_sendMessage);
}

void Heavy_CircleStrings::cSend_VMfbbMLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AQ4lxFlf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_R7YElIRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TdkZVToG_sendMessage);
}

void Heavy_CircleStrings::cCast_c2hxK0ZS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lzUup5Z0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_BZ2d2Ek1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3CrlaE0w, 0, m, &cPack_3CrlaE0w_sendMessage);
}

void Heavy_CircleStrings::cSend_R8jTlpUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uhw617Gy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_YN6jIUR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cLDgQhOR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_xU2ilwyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_YN6jIUR5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Ge2FKmJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_XaJi2hat, m);
}

void Heavy_CircleStrings::cCast_DGqTriBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_e0wzkdi9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_yKw4Aa7S_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8OtsqTSr, 0, m, &cSlice_8OtsqTSr_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Dv5Q1At7, 0, m, &cRandom_Dv5Q1At7_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_KRdWF5SC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ABujUDKq_sendMessage);
}

void Heavy_CircleStrings::cUnop_ABujUDKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_ysfwTut4_sendMessage);
}

void Heavy_CircleStrings::cRandom_Dv5Q1At7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_KRdWF5SC_sendMessage);
}

void Heavy_CircleStrings::cSlice_8OtsqTSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Dv5Q1At7, 1, m, &cRandom_Dv5Q1At7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KiXi5ShD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GWmSCsAJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_GWmSCsAJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_e6W7QMLE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_iRkfgGwK_sendMessage);
}

void Heavy_CircleStrings::cBinop_iRkfgGwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cVGoa8YS, HV_BINOP_POW, 1, m, &cBinop_cVGoa8YS_sendMessage);
  cMsg_EMoZFY60_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_cVGoa8YS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_KiXi5ShD_sendMessage);
}

void Heavy_CircleStrings::cMsg_EMoZFY60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cVGoa8YS, HV_BINOP_POW, 0, m, &cBinop_cVGoa8YS_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_9Q0E3ln0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_s2yEDok7, 0, m, &cSlice_s2yEDok7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_adNdPHvh, 0, m, &cRandom_adNdPHvh_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_NJ7PFn7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_de9C8lJQ_sendMessage);
}

void Heavy_CircleStrings::cUnop_de9C8lJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_c43Vu2b5_sendMessage);
}

void Heavy_CircleStrings::cRandom_adNdPHvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_NJ7PFn7j_sendMessage);
}

void Heavy_CircleStrings::cSlice_s2yEDok7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_adNdPHvh, 1, m, &cRandom_adNdPHvh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_8ESaVNdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_jCzzFIa2, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_25o5ZdWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_NXg76Kma_sendMessage);
}

void Heavy_CircleStrings::cVar_kvuXtFqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_oApnp92K, 0, m);
}

void Heavy_CircleStrings::cVar_lD4uuGr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aBhlrcdf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VQtFs7CT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XVSKuERw_sendMessage);
}

void Heavy_CircleStrings::cVar_Kk9SmMbq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_hzUb5fCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_K1KQ4OwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_WSjnv4Wl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_n1UqzMhQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_n1UqzMhQ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_B2FsxtFu, 1, m, &cDelay_B2FsxtFu_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xvSxw0PE_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_B2FsxtFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_B2FsxtFu, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mxGEmfbK, 0, m, &cVar_mxGEmfbK_sendMessage);
}

void Heavy_CircleStrings::cMsg_n1UqzMhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_B2FsxtFu, 0, m, &cDelay_B2FsxtFu_sendMessage);
}

void Heavy_CircleStrings::cCast_xvSxw0PE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_B2FsxtFu, 0, m, &cDelay_B2FsxtFu_sendMessage);
}

void Heavy_CircleStrings::cVar_mxGEmfbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eUbkyOVt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_YmCSjbrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lD4uuGr5, 0, m, &cVar_lD4uuGr5_sendMessage);
}

void Heavy_CircleStrings::cMsg_ssUrJNd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_cSiJOVRK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_3neHqnre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_zTSCUTNW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_FtWZdccy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_36NA9KHE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_ldyvaD5V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Trui00ow_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_pzdotn1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_xgzgUj1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VVPgUsCD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_cSiJOVRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_zTSCUTNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Trui00ow_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_36NA9KHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VVPgUsCD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_cK7oH7BZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_vhqu07wb, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_eUbkyOVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_vhqu07wb, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_XVSKuERw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WSjnv4Wl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_VQtFs7CT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mxGEmfbK, 1, m, &cVar_mxGEmfbK_sendMessage);
}

void Heavy_CircleStrings::cCast_aBhlrcdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cK7oH7BZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_23jp0d0W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ryaxyvoE, 0, m, &cSlice_ryaxyvoE_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NvKKTQ4I, 0, m, &cRandom_NvKKTQ4I_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_fLhT5GeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qZ1UdlwB_sendMessage);
}

void Heavy_CircleStrings::cUnop_qZ1UdlwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wZdGzpJc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_NvKKTQ4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_fLhT5GeH_sendMessage);
}

void Heavy_CircleStrings::cSlice_ryaxyvoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NvKKTQ4I, 1, m, &cRandom_NvKKTQ4I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_wZdGzpJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_B3LqpK8Z, m);
}

void Heavy_CircleStrings::cTabhead_JnJhxyt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kaY5vEIk, HV_BINOP_SUBTRACT, 0, m, &cBinop_kaY5vEIk_sendMessage);
}

void Heavy_CircleStrings::cMsg_5ePTUIu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vQm0DtlM_sendMessage);
}

void Heavy_CircleStrings::cSystem_vQm0DtlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bdcKP42g_sendMessage);
}

void Heavy_CircleStrings::cVar_Da34SNGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6MnT90CJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_sLKCjTbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sLKCjTbG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FgyCcqV7, 0, m, &cDelay_FgyCcqV7_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_W7LYHhEe, 0, m, &sTabread_W7LYHhEe_sendMessage);
}

void Heavy_CircleStrings::cDelay_FgyCcqV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FgyCcqV7, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_W7LYHhEe, 0, m, &sTabread_W7LYHhEe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FgyCcqV7, 0, m, &cDelay_FgyCcqV7_sendMessage);
}

void Heavy_CircleStrings::sTabread_W7LYHhEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0qIumF31, HV_BINOP_SUBTRACT, 0, m, &cBinop_0qIumF31_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_qwGXZAzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvYpuf9y, HV_BINOP_MAX, 0, m, &cBinop_fvYpuf9y_sendMessage);
}

void Heavy_CircleStrings::cBinop_bdcKP42g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qwGXZAzh, HV_BINOP_MULTIPLY, 0, m, &cBinop_qwGXZAzh_sendMessage);
}

void Heavy_CircleStrings::cBinop_kaY5vEIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ALcmafEC_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_W7LYHhEe, 0, m, &sTabread_W7LYHhEe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dkiYoYsC_sendMessage);
}

void Heavy_CircleStrings::cSystem_4IakXV02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qIumF31, HV_BINOP_SUBTRACT, 1, m, &cBinop_0qIumF31_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FgyCcqV7, 2, m, &cDelay_FgyCcqV7_sendMessage);
}

void Heavy_CircleStrings::cMsg_6MnT90CJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4IakXV02_sendMessage);
}

void Heavy_CircleStrings::cMsg_ALcmafEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sLKCjTbG, 0, m, &cDelay_sLKCjTbG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FgyCcqV7, 0, m, &cDelay_FgyCcqV7_sendMessage);
}

void Heavy_CircleStrings::cMsg_fzd80P7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvYpuf9y, HV_BINOP_MAX, 1, m, &cBinop_fvYpuf9y_sendMessage);
}

void Heavy_CircleStrings::cBinop_fvYpuf9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kaY5vEIk, HV_BINOP_SUBTRACT, 1, m, &cBinop_kaY5vEIk_sendMessage);
}

void Heavy_CircleStrings::cCast_dkiYoYsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sLKCjTbG, 0, m, &cDelay_sLKCjTbG_sendMessage);
}

void Heavy_CircleStrings::cBinop_pmBfOYZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sLKCjTbG, 2, m, &cDelay_sLKCjTbG_sendMessage);
}

void Heavy_CircleStrings::cBinop_0qIumF31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pmBfOYZ5_sendMessage);
}

void Heavy_CircleStrings::cCast_FhQTZldL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Da34SNGd, 0, m, &cVar_Da34SNGd_sendMessage);
  cMsg_5ePTUIu3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_JnJhxyt3, 0, m, &cTabhead_JnJhxyt3_sendMessage);
}

void Heavy_CircleStrings::cBinop_I3dqugvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jOOGIt2b_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Bq9SyNuZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_9NOWKy2J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_eWnjxGUq_sendMessage);
}

void Heavy_CircleStrings::cBinop_eWnjxGUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GkVh6ZHd, HV_BINOP_POW, 1, m, &cBinop_GkVh6ZHd_sendMessage);
  cMsg_JrIhd1o9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_GkVh6ZHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_I3dqugvh_sendMessage);
}

void Heavy_CircleStrings::cMsg_JrIhd1o9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GkVh6ZHd, HV_BINOP_POW, 0, m, &cBinop_GkVh6ZHd_sendMessage);
}

void Heavy_CircleStrings::cVar_W1BNX4au_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_9NOWKy2J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SUKqfjPx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9EXuYrHk_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_VHbeMpBs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ndEaQnvH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ndEaQnvH_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_EXwFVcC4, 1, m, &cDelay_EXwFVcC4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8PNcRNqa_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_EXwFVcC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EXwFVcC4, m);
  cMsg_uNgATNDz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ndEaQnvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EXwFVcC4, 0, m, &cDelay_EXwFVcC4_sendMessage);
}

void Heavy_CircleStrings::cCast_8PNcRNqa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EXwFVcC4, 0, m, &cDelay_EXwFVcC4_sendMessage);
}

void Heavy_CircleStrings::cVar_FrZebKWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dOwqSVqD, HV_BINOP_MULTIPLY, 0, m, &cBinop_dOwqSVqD_sendMessage);
}

void Heavy_CircleStrings::cMsg_6yAUZKF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8H7XQMHA_sendMessage);
}

void Heavy_CircleStrings::cSystem_8H7XQMHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8UrGs3MR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_dOwqSVqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_SYgPTHoM_sendMessage);
}

void Heavy_CircleStrings::cBinop_iNl4pJVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dOwqSVqD, HV_BINOP_MULTIPLY, 1, m, &cBinop_dOwqSVqD_sendMessage);
}

void Heavy_CircleStrings::cMsg_8UrGs3MR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_iNl4pJVX_sendMessage);
}

void Heavy_CircleStrings::cBinop_SYgPTHoM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_owzC7wHX_sendMessage);
}

void Heavy_CircleStrings::cBinop_owzC7wHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_vCqHET3U_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Tqm2CRXI, m);
}

void Heavy_CircleStrings::cBinop_vCqHET3U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pinR2d10, m);
}

void Heavy_CircleStrings::cMsg_JyUp2eR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tWw0XCdo_sendMessage);
}

void Heavy_CircleStrings::cSystem_tWw0XCdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_isbQFZng_sendMessage);
}

void Heavy_CircleStrings::cDelay_Af8KGCUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Af8KGCUW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OkSduMyy, 0, m, &cDelay_OkSduMyy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Af8KGCUW, 0, m, &cDelay_Af8KGCUW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ciS6I4s5, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_OkSduMyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OkSduMyy, m);
  cMsg_QWUJX0l6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Q7y1fPrY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_iz7SwLrj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_VXRCFdQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7t3CmsBa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_gd59mUEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zAMpp4Cs_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Af8KGCUW, 2, m, &cDelay_Af8KGCUW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sNpYkFR0_sendMessage);
}

void Heavy_CircleStrings::cMsg_7t3CmsBa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gd59mUEY, 0, m, &hTable_gd59mUEY_sendMessage);
}

void Heavy_CircleStrings::cBinop_isbQFZng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_VXRCFdQC_sendMessage);
}

void Heavy_CircleStrings::cMsg_QWUJX0l6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gd59mUEY, 0, m, &hTable_gd59mUEY_sendMessage);
}

void Heavy_CircleStrings::cCast_sNpYkFR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Af8KGCUW, 0, m, &cDelay_Af8KGCUW_sendMessage);
}

void Heavy_CircleStrings::cMsg_zAMpp4Cs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OkSduMyy, 2, m, &cDelay_OkSduMyy_sendMessage);
}

void Heavy_CircleStrings::cMsg_iz7SwLrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ciS6I4s5, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_47E2t7O0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_G9y6Bk1z, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_uNgATNDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_G9y6Bk1z, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_9EXuYrHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_47E2t7O0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_SUKqfjPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VHbeMpBs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_HnYNMQE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_9NOWKy2J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SUKqfjPx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9EXuYrHk_sendMessage);
}

void Heavy_CircleStrings::cBinop_q5pAjV6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qwGXZAzh, HV_BINOP_MULTIPLY, 1, m, &cBinop_qwGXZAzh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FhQTZldL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EXwFVcC4, 1, m, &cDelay_EXwFVcC4_sendMessage);
}

void Heavy_CircleStrings::cMsg_WVKSGlwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_q5pAjV6j, HV_BINOP_DIVIDE, 0, m, &cBinop_q5pAjV6j_sendMessage);
}

void Heavy_CircleStrings::cCast_jOOGIt2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q5pAjV6j, HV_BINOP_DIVIDE, 1, m, &cBinop_q5pAjV6j_sendMessage);
}

void Heavy_CircleStrings::cCast_Bq9SyNuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WVKSGlwW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_go3Aeg9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oaaMHZ2v, 0, m, &cPack_oaaMHZ2v_sendMessage);
}

void Heavy_CircleStrings::cUnop_0LVBr4Ch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sT2nExBM, 0, m, &cPack_sT2nExBM_sendMessage);
}

void Heavy_CircleStrings::cPack_sT2nExBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cvDW0it2, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_oaaMHZ2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_E1UYqvL7, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_JZVFSEMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_go3Aeg9a_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_0LVBr4Ch_sendMessage);
}

void Heavy_CircleStrings::cMsg_gxq5RkYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_JZVFSEMJ_sendMessage);
}

void Heavy_CircleStrings::cSlice_MqeQdi4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_FfE4vUpC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_613QnGjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZdPiJTqK_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_e6W7QMLE_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_9NOWKy2J_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SUKqfjPx_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9EXuYrHk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ysfwTut4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_pg1cZ2pG_sendMessage);
}

void Heavy_CircleStrings::cBinop_pg1cZ2pG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_JZVFSEMJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_FfE4vUpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_eSEJiGr9_sendMessage(_c, 0, m);
  cSend_mqmpoCr3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_GWmSCsAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GNR3YtJF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y9aNVf3O_sendMessage);
}

void Heavy_CircleStrings::cBinop_c43Vu2b5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_JhGHCm7w_sendMessage);
}

void Heavy_CircleStrings::cBinop_JhGHCm7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GWmSCsAJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_GWmSCsAJ_sendMessage);
}

void Heavy_CircleStrings::cSend_eSEJiGr9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WpAwdrL6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_GNR3YtJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yKw4Aa7S_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_Y9aNVf3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YmCSjbrr_sendMessage);
}

void Heavy_CircleStrings::cBinop_NXg76Kma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8ESaVNdy, 0, m, &cPack_8ESaVNdy_sendMessage);
}

void Heavy_CircleStrings::cSend_mqmpoCr3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DuSJ5FW1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_KLxWwtqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jONNuo7Y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_79VulMC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_KLxWwtqM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ZCHXff7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jEe7pjPw, m);
}

void Heavy_CircleStrings::cCast_ZdPiJTqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9Q0E3ln0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_Qk1Btk43_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_70f9c8Xd_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8T8jszGv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SCURCgOh_sendMessage);
}

void Heavy_CircleStrings::cIf_5CvhPinc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DlPbNjTd_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_hG4Upjcw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_SDqWGRZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hun4ErkT, HV_BINOP_POW, 0, m, &cBinop_hun4ErkT_sendMessage);
}

void Heavy_CircleStrings::cBinop_hun4ErkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_v4Enanaz, 0, m, &cPack_v4Enanaz_sendMessage);
}

void Heavy_CircleStrings::cBinop_PD2bXdXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_AJEnmDBW_sendMessage);
}

void Heavy_CircleStrings::cCast_SCURCgOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5CvhPinc, 0, m, &cIf_5CvhPinc_sendMessage);
}

void Heavy_CircleStrings::cCast_8T8jszGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_O73tZtQS_sendMessage);
}

void Heavy_CircleStrings::cBinop_O73tZtQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5CvhPinc, 1, m, &cIf_5CvhPinc_sendMessage);
}

void Heavy_CircleStrings::cBinop_hG4Upjcw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_PD2bXdXY_sendMessage);
}

void Heavy_CircleStrings::cMsg_DlPbNjTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_v4Enanaz, 0, m, &cPack_v4Enanaz_sendMessage);
}

void Heavy_CircleStrings::cBinop_AJEnmDBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hun4ErkT, HV_BINOP_POW, 1, m, &cBinop_hun4ErkT_sendMessage);
  cMsg_SDqWGRZ8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_v4Enanaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_S9z7G4QB, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_iv0lqcFe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SnpHk7Rg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_70f9c8Xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_wnDS9gt9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_wnDS9gt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_74xPJo1e_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_SnpHk7Rg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7aFj9XWO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_NCZKq1p0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_38BuWdLF_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q52zal8s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tp3frpqo_sendMessage);
}

void Heavy_CircleStrings::cIf_TfqB6Zk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_wa7rNyx4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Q1qQ6Kyc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_yA9Dlzrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qGj2c85k, HV_BINOP_POW, 0, m, &cBinop_qGj2c85k_sendMessage);
}

void Heavy_CircleStrings::cBinop_qGj2c85k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vaJLk8ah, 0, m, &cPack_vaJLk8ah_sendMessage);
}

void Heavy_CircleStrings::cBinop_uGKCQ6zC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_cX2tlOqk_sendMessage);
}

void Heavy_CircleStrings::cCast_tp3frpqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TfqB6Zk2, 0, m, &cIf_TfqB6Zk2_sendMessage);
}

void Heavy_CircleStrings::cCast_Q52zal8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_W8uTm0Gl_sendMessage);
}

void Heavy_CircleStrings::cBinop_W8uTm0Gl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TfqB6Zk2, 1, m, &cIf_TfqB6Zk2_sendMessage);
}

void Heavy_CircleStrings::cBinop_Q1qQ6Kyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_uGKCQ6zC_sendMessage);
}

void Heavy_CircleStrings::cMsg_wa7rNyx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_vaJLk8ah, 0, m, &cPack_vaJLk8ah_sendMessage);
}

void Heavy_CircleStrings::cBinop_cX2tlOqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qGj2c85k, HV_BINOP_POW, 1, m, &cBinop_qGj2c85k_sendMessage);
  cMsg_yA9Dlzrj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_vaJLk8ah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0jZKEEOX, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_RoCiCtFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_raTezRB6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_38BuWdLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_wAJtWA6R_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_wAJtWA6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZHPUw2jf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_raTezRB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vqYwP32U_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_WYgicqGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JEMuQOLM_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CZ5JTYMb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LUH1HSmh_sendMessage);
}

void Heavy_CircleStrings::cIf_uSDnXr4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ecNPbX6c_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_SzMlRc07_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_uojcD8jA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lqHxDAX5, HV_BINOP_POW, 0, m, &cBinop_lqHxDAX5_sendMessage);
}

void Heavy_CircleStrings::cBinop_lqHxDAX5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TJnjVF3M, 0, m, &cPack_TJnjVF3M_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ne2l7z9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_LZDdSlsr_sendMessage);
}

void Heavy_CircleStrings::cCast_CZ5JTYMb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_lAJPiFk6_sendMessage);
}

void Heavy_CircleStrings::cCast_LUH1HSmh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uSDnXr4R, 0, m, &cIf_uSDnXr4R_sendMessage);
}

void Heavy_CircleStrings::cBinop_lAJPiFk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uSDnXr4R, 1, m, &cIf_uSDnXr4R_sendMessage);
}

void Heavy_CircleStrings::cBinop_SzMlRc07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_Ne2l7z9S_sendMessage);
}

void Heavy_CircleStrings::cMsg_ecNPbX6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_TJnjVF3M, 0, m, &cPack_TJnjVF3M_sendMessage);
}

void Heavy_CircleStrings::cBinop_LZDdSlsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lqHxDAX5, HV_BINOP_POW, 1, m, &cBinop_lqHxDAX5_sendMessage);
  cMsg_uojcD8jA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_TJnjVF3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cFH7Mude, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_fCLCkWHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mMG7WeHq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_JEMuQOLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_8Seg0vOw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_8Seg0vOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yCivK9mR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_mMG7WeHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CHQ1g4FG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_X7h5BQZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Aq1OsJ2m_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_k61IFiNl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_k61IFiNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_l9wV6nfz_sendMessage);
}

void Heavy_CircleStrings::cCast_UCwszEC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_XcrfNUNr_sendMessage);
}

void Heavy_CircleStrings::cCast_rXZmTVxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_X7h5BQZ2, 0, m, &cIf_X7h5BQZ2_sendMessage);
}

void Heavy_CircleStrings::cMsg_Aq1OsJ2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_70f9c8Xd_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8T8jszGv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SCURCgOh_sendMessage);
}

void Heavy_CircleStrings::cBinop_l9wV6nfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_Qyy3HYwe_sendMessage);
}

void Heavy_CircleStrings::cBinop_Qyy3HYwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5ZE7S4ka_sendMessage);
}

void Heavy_CircleStrings::cBinop_5ZE7S4ka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_70f9c8Xd_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8T8jszGv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SCURCgOh_sendMessage);
}

void Heavy_CircleStrings::cBinop_XcrfNUNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_X7h5BQZ2, 1, m, &cIf_X7h5BQZ2_sendMessage);
}

void Heavy_CircleStrings::cBinop_8G50ULcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UCwszEC2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rXZmTVxr_sendMessage);
}

void Heavy_CircleStrings::cBinop_52zAWov1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8G50ULcq_sendMessage);
}

void Heavy_CircleStrings::cIf_EK064cfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_dNQSpjVp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_jC5WDqQQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_jC5WDqQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_gQNu2vm6_sendMessage);
}

void Heavy_CircleStrings::cCast_Q4uX5a5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ULMy89Ux_sendMessage);
}

void Heavy_CircleStrings::cCast_3Gh04kCl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EK064cfR, 0, m, &cIf_EK064cfR_sendMessage);
}

void Heavy_CircleStrings::cMsg_dNQSpjVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_38BuWdLF_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q52zal8s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tp3frpqo_sendMessage);
}

void Heavy_CircleStrings::cBinop_gQNu2vm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_jhiNGYqf_sendMessage);
}

void Heavy_CircleStrings::cBinop_jhiNGYqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_pMs3OJIg_sendMessage);
}

void Heavy_CircleStrings::cBinop_pMs3OJIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_38BuWdLF_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q52zal8s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tp3frpqo_sendMessage);
}

void Heavy_CircleStrings::cBinop_ULMy89Ux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EK064cfR, 1, m, &cIf_EK064cfR_sendMessage);
}

void Heavy_CircleStrings::cBinop_cBKpPB1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q4uX5a5s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3Gh04kCl_sendMessage);
}

void Heavy_CircleStrings::cBinop_kt2gx7xb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cBKpPB1r_sendMessage);
}

void Heavy_CircleStrings::cVar_rLWDtpno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ti6zN0qY_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3woxlkFK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CJgEg6Rj_sendMessage);
}

void Heavy_CircleStrings::cIf_sq8eS9Yo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_hvh9j7Xo_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_GiHMFzDh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_8yD5s3DE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4EbAuJcL, HV_BINOP_POW, 0, m, &cBinop_4EbAuJcL_sendMessage);
}

void Heavy_CircleStrings::cBinop_4EbAuJcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hTaUVW9A, 0, m, &cPack_hTaUVW9A_sendMessage);
}

void Heavy_CircleStrings::cBinop_o0ZD9xmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_uMy8mecP_sendMessage);
}

void Heavy_CircleStrings::cCast_CJgEg6Rj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sq8eS9Yo, 0, m, &cIf_sq8eS9Yo_sendMessage);
}

void Heavy_CircleStrings::cCast_3woxlkFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_WvYCf8oD_sendMessage);
}

void Heavy_CircleStrings::cBinop_WvYCf8oD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sq8eS9Yo, 1, m, &cIf_sq8eS9Yo_sendMessage);
}

void Heavy_CircleStrings::cBinop_GiHMFzDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_o0ZD9xmB_sendMessage);
}

void Heavy_CircleStrings::cMsg_hvh9j7Xo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_hTaUVW9A, 0, m, &cPack_hTaUVW9A_sendMessage);
}

void Heavy_CircleStrings::cBinop_uMy8mecP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4EbAuJcL, HV_BINOP_POW, 1, m, &cBinop_4EbAuJcL_sendMessage);
  cMsg_8yD5s3DE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_hTaUVW9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xgyzHgyk, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_9pVj4ORn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_QKlBXFcm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Ti6zN0qY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_NMlr1ANI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_NMlr1ANI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_X4bVaKCf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_QKlBXFcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Xblvs9oi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_maV9bBvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_He3QGBV6, 0, m, &cIf_He3QGBV6_sendMessage);
}

void Heavy_CircleStrings::cSlice_CwDdWYOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9fhx51iD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S4GB0Xf8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_Cti7Q8DI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_hRKl9kiv, 0, m, &cIf_hRKl9kiv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_hRKl9kiv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IATLRQCn_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_avZjLUhv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_uWjh2lVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_FBz81L0q, 2, m, &cPack_FBz81L0q_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_qu54pwU9, 1, m, &cPack_qu54pwU9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_xRhCnpD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_CwDdWYOH, 0, m, &cSlice_CwDdWYOH_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Cti7Q8DI, 0, m, &cSlice_Cti7Q8DI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_BpxrWBs9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_0prs5RW7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_HcCAXWiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3ArrugpS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FlLC5U6g_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K0Oj56B4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_IZbjxrZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_n9cFTIGx, 1, m, &cIf_n9cFTIGx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_nbaoetzS_sendMessage);
}

void Heavy_CircleStrings::cIf_n9cFTIGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_CwDdWYOH, 0, m, &cSlice_CwDdWYOH_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Cti7Q8DI, 0, m, &cSlice_Cti7Q8DI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_qu54pwU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xRhCnpD6, 0, m, &cIf_xRhCnpD6_sendMessage);
}

void Heavy_CircleStrings::cBinop_z1XZMcBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hRKl9kiv, 1, m, &cIf_hRKl9kiv_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_uWjh2lVo, 1, m, &cIf_uWjh2lVo_sendMessage);
}

void Heavy_CircleStrings::cCast_9fhx51iD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_z1XZMcBp_sendMessage);
}

void Heavy_CircleStrings::cCast_S4GB0Xf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uWjh2lVo, 0, m, &cIf_uWjh2lVo_sendMessage);
}

void Heavy_CircleStrings::cMsg_WBQVoNtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_IZbjxrZs, 1, m, &cVar_IZbjxrZs_sendMessage);
}

void Heavy_CircleStrings::cMsg_0prs5RW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_IZbjxrZs, 1, m, &cVar_IZbjxrZs_sendMessage);
}

void Heavy_CircleStrings::cCast_FlLC5U6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qu54pwU9, 0, m, &cPack_qu54pwU9_sendMessage);
}

void Heavy_CircleStrings::cCast_K0Oj56B4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WBQVoNtr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_3ArrugpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IZbjxrZs, 0, m, &cVar_IZbjxrZs_sendMessage);
}

void Heavy_CircleStrings::cBinop_nbaoetzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xRhCnpD6, 1, m, &cIf_xRhCnpD6_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_ovNlsyTH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_S43m9Zrx, 0, m, &cSlice_S43m9Zrx_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dh1O0Sih, 0, m, &cSlice_dh1O0Sih_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Mv7P9nxj, 0, m, &cSlice_Mv7P9nxj_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ejn07aSq, 0, m, &cSlice_ejn07aSq_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_S43m9Zrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_DNi3mEdl, 0, m, &cSlice_DNi3mEdl_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_CxhP4gwK, 0, m, &cSlice_CxhP4gwK_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_DNi3mEdl, 0, m, &cSlice_DNi3mEdl_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_CxhP4gwK, 0, m, &cSlice_CxhP4gwK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_dh1O0Sih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_zGkZsTus, 0, m, &cSlice_zGkZsTus_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AVb4qfw3, 0, m, &cSlice_AVb4qfw3_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_zGkZsTus, 0, m, &cSlice_zGkZsTus_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AVb4qfw3, 0, m, &cSlice_AVb4qfw3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_Mv7P9nxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_MqeQdi4A, 0, m, &cSlice_MqeQdi4A_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_613QnGjQ, 0, m, &cSlice_613QnGjQ_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_MqeQdi4A, 0, m, &cSlice_MqeQdi4A_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_613QnGjQ, 0, m, &cSlice_613QnGjQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_ejn07aSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_3BFnNE9Q, 0, m, &cSlice_3BFnNE9Q_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sR83pIAp, 0, m, &cSlice_sR83pIAp_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_3BFnNE9Q, 0, m, &cSlice_3BFnNE9Q_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sR83pIAp, 0, m, &cSlice_sR83pIAp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_87YcOzln_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mpJQADBU_sendMessage);
      break;
    }
    default: {
      cMsg_vkbOzJAW_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_mpJQADBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OZFVXCjX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_He3QGBV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_BpxrWBs9, 0, m, &cSlice_BpxrWBs9_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_HcCAXWiK, 0, m, &cSlice_HcCAXWiK_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_n9cFTIGx, 0, m, &cIf_n9cFTIGx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_ydZug0AI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_n64MZrg9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_He3QGBV6, 1, m, &cIf_He3QGBV6_sendMessage);
}

void Heavy_CircleStrings::cBinop_n64MZrg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ydZug0AI, 1, m, &cVar_ydZug0AI_sendMessage);
}

void Heavy_CircleStrings::cMsg_OZFVXCjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ydZug0AI, 0, m, &cVar_ydZug0AI_sendMessage);
}

void Heavy_CircleStrings::cMsg_vkbOzJAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ydZug0AI, 0, m, &cVar_ydZug0AI_sendMessage);
}

void Heavy_CircleStrings::cPack_FBz81L0q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ovNlsyTH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_zUSzJZek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FBz81L0q, 0, m, &cPack_FBz81L0q_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_tF3SBkqY_sendMessage);
}

void Heavy_CircleStrings::cBinop_tF3SBkqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_AT0R9CoU_sendMessage);
}

void Heavy_CircleStrings::cBinop_AT0R9CoU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zUSzJZek, 1, m, &cVar_zUSzJZek_sendMessage);
}

void Heavy_CircleStrings::cMsg_zg3qhWft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_87YcOzln_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_avZjLUhv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zUSzJZek, 0, m, &cVar_zUSzJZek_sendMessage);
}

void Heavy_CircleStrings::cCast_IATLRQCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FBz81L0q, 1, m, &cPack_FBz81L0q_sendMessage);
}

void Heavy_CircleStrings::cSend_DTv2FXX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_seFUm3TM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_TeL3Yu2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eVKiQ93V_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_05512Jdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cBinop_NRr8Ef4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FsGVOCVC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_FsGVOCVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IqM0aObO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_864DsC3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MgcOWHZf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cReceive_f6pC40dN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YHlIQu2c_sendMessage(_c, 0, m);
  cMsg_Qac9hG85_sendMessage(_c, 0, m);
  cMsg_rBD5Gd6Q_sendMessage(_c, 0, m);
  cMsg_6Tm4PJhW_sendMessage(_c, 0, m);
  cMsg_lfI8mxPp_sendMessage(_c, 0, m);
  cMsg_nx541emA_sendMessage(_c, 0, m);
  cMsg_6FAY6VdZ_sendMessage(_c, 0, m);
  cMsg_LF5ChtdR_sendMessage(_c, 0, m);
  cMsg_uwri34rw_sendMessage(_c, 0, m);
  cMsg_iCb6wOwb_sendMessage(_c, 0, m);
  cMsg_QqYTaElI_sendMessage(_c, 0, m);
  cMsg_6J2ipDAK_sendMessage(_c, 0, m);
  cMsg_Yu52ZNIV_sendMessage(_c, 0, m);
  cMsg_2S64sLr6_sendMessage(_c, 0, m);
  cMsg_XNujj9P6_sendMessage(_c, 0, m);
  cMsg_CJGuYwnr_sendMessage(_c, 0, m);
  cMsg_qTWKzuR8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xMFd6Umd, 0, m, &cVar_xMFd6Umd_sendMessage);
  cMsg_8ce2Ha80_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_p5nP1Vsb, 0, m, &cVar_p5nP1Vsb_sendMessage);
  cMsg_wnBJKrsI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4zAHoDyb, 0, m, &cVar_4zAHoDyb_sendMessage);
  cMsg_lu5ndMg5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_e5pvmiNV, 0, m, &cVar_e5pvmiNV_sendMessage);
  cMsg_1hFLroJ4_sendMessage(_c, 0, m);
  cMsg_unY1mZkv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qsfQZoTZ, 0, m, &cVar_qsfQZoTZ_sendMessage);
  cMsg_76vrh53M_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kVzvChjD, 0, m, &cVar_kVzvChjD_sendMessage);
  cMsg_2LIkPi0B_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sNT2Yjov, 0, m, &cVar_sNT2Yjov_sendMessage);
  cMsg_IOL5iGd7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_c4fBgUqN, 0, m, &cVar_c4fBgUqN_sendMessage);
  cMsg_klCiuYm6_sendMessage(_c, 0, m);
  cMsg_LnBqmdIB_sendMessage(_c, 0, m);
  cMsg_gm69viNc_sendMessage(_c, 0, m);
  cMsg_75NmRBVI_sendMessage(_c, 0, m);
  cMsg_6ZDniLVd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jRn8pWdq, 0, m, &cVar_jRn8pWdq_sendMessage);
  cMsg_W72aZQ7w_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Wi1q81Cr, 0, m, &cVar_Wi1q81Cr_sendMessage);
  cMsg_sSf4qxXS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TVHb62C3, 0, m, &cVar_TVHb62C3_sendMessage);
  cMsg_m51O26q9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WOt6tR1Q, 0, m, &cVar_WOt6tR1Q_sendMessage);
  cMsg_Ea4wnHRo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mjI5T66C, 0, m, &cVar_mjI5T66C_sendMessage);
  cMsg_oIpDV7IU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_67Lojftk, 0, m, &cVar_67Lojftk_sendMessage);
  cMsg_5vvbgTXm_sendMessage(_c, 0, m);
  cMsg_RCWbpsu5_sendMessage(_c, 0, m);
  cMsg_a6y2atQ8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZjhXHiok, 0, m, &cVar_ZjhXHiok_sendMessage);
  cMsg_EDOYRfUG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Y60I3yiR, 0, m, &cVar_Y60I3yiR_sendMessage);
  cMsg_7MumD4Ze_sendMessage(_c, 0, m);
  cMsg_lOT3SDVy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HPJ7bT7r, 0, m, &cVar_HPJ7bT7r_sendMessage);
  cMsg_Yd7VEKAH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_G3SB9YNs, 0, m, &cVar_G3SB9YNs_sendMessage);
  cSwitchcase_WLZRLWkv_onMessage(_c, NULL, 0, m, NULL);
  cMsg_qzkAtTdG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HmaC2b4o, 0, m, &cVar_HmaC2b4o_sendMessage);
  cMsg_1PM4QiAJ_sendMessage(_c, 0, m);
  cSwitchcase_yNFwVVGQ_onMessage(_c, NULL, 0, m, NULL);
  cMsg_lU1Ig6ow_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zoXTuhOu, 0, m, &cVar_zoXTuhOu_sendMessage);
  cMsg_zs84YcSb_sendMessage(_c, 0, m);
  cSwitchcase_lRgi0EVf_onMessage(_c, NULL, 0, m, NULL);
  cMsg_mAwJA1Ct_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aeL9JXfQ, 0, m, &cVar_aeL9JXfQ_sendMessage);
  cMsg_KloEyMSI_sendMessage(_c, 0, m);
  cSwitchcase_hN1p6IjO_onMessage(_c, NULL, 0, m, NULL);
  cMsg_mP2Qf2r3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fHuTs3vg, 0, m, &cVar_fHuTs3vg_sendMessage);
  cMsg_LtQe16sJ_sendMessage(_c, 0, m);
  cSwitchcase_23jp0d0W_onMessage(_c, NULL, 0, m, NULL);
  cMsg_6yAUZKF5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FrZebKWY, 0, m, &cVar_FrZebKWY_sendMessage);
  cMsg_JyUp2eR3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VfzSWenc, 0, m, &cVar_VfzSWenc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_foddyUI2, 0, m, &cVar_foddyUI2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hdnpOuid, 0, m, &cVar_hdnpOuid_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4RwKe4Fe, 0, m, &cVar_4RwKe4Fe_sendMessage);
  cMsg_7NlH8KGE_sendMessage(_c, 0, m);
  cMsg_k8fup9no_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_f3KbwAXh, 0, m, &cVar_f3KbwAXh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ILlCWeWz, 0, m, &cVar_ILlCWeWz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GS2Txx5o, 0, m, &cVar_GS2Txx5o_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_svFC7d6u, 0, m, &cVar_svFC7d6u_sendMessage);
  cMsg_nb7EDyCa_sendMessage(_c, 0, m);
  cMsg_rFuH59aW_sendMessage(_c, 0, m);
  cMsg_EZGXmZ4v_sendMessage(_c, 0, m);
  cMsg_0zw6daIC_sendMessage(_c, 0, m);
  cMsg_CbBxUlYq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jCWndMnn, 0, m, &cVar_jCWndMnn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vHaQPU7n, 0, m, &cVar_vHaQPU7n_sendMessage);
  cMsg_Mwf69qSO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3NltcsXK, 0, m, &cVar_3NltcsXK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Wng5FOpP, 0, m, &cVar_Wng5FOpP_sendMessage);
  cMsg_stf4b0Pj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YANBlYTm, 0, m, &cVar_YANBlYTm_sendMessage);
  cMsg_XbIYx698_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eQGzO0WU, 0, m, &cVar_eQGzO0WU_sendMessage);
  cMsg_5ir8TdyB_sendMessage(_c, 0, m);
  cMsg_JktmHPoc_sendMessage(_c, 0, m);
  cMsg_PxsQj8wF_sendMessage(_c, 0, m);
  cMsg_r9bUgxLS_sendMessage(_c, 0, m);
  cMsg_HnvPqQcP_sendMessage(_c, 0, m);
  cMsg_PKdn4C2L_sendMessage(_c, 0, m);
  cMsg_SuJnz0Dy_sendMessage(_c, 0, m);
  cMsg_3KdbDoss_sendMessage(_c, 0, m);
  cMsg_zRh3ysAl_sendMessage(_c, 0, m);
  cMsg_l1ZUNHVA_sendMessage(_c, 0, m);
  cMsg_fOr99LuS_sendMessage(_c, 0, m);
  cMsg_ybkj9Mq8_sendMessage(_c, 0, m);
  cMsg_ssUrJNd6_sendMessage(_c, 0, m);
  cMsg_3neHqnre_sendMessage(_c, 0, m);
  cMsg_FtWZdccy_sendMessage(_c, 0, m);
  cMsg_gxq5RkYW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OcCTe9XT, 0, m, &cVar_OcCTe9XT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_w8oJaENN, 0, m, &cVar_w8oJaENN_sendMessage);
  cMsg_Rey2qj3e_sendMessage(_c, 0, m);
  cMsg_2PA50jzk_sendMessage(_c, 0, m);
  cMsg_EfT8rMYf_sendMessage(_c, 0, m);
  cMsg_iSU2ZNlu_sendMessage(_c, 0, m);
  cMsg_d8FQUpZH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mZAIGs13, 0, m, &cVar_mZAIGs13_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VH5XJ4Pi, 0, m, &cVar_VH5XJ4Pi_sendMessage);
  cMsg_xAi3s4Fm_sendMessage(_c, 0, m);
  cMsg_wXMaRijc_sendMessage(_c, 0, m);
  cMsg_xU2ilwyk_sendMessage(_c, 0, m);
  cMsg_Ge2FKmJw_sendMessage(_c, 0, m);
  cMsg_79VulMC4_sendMessage(_c, 0, m);
  cMsg_ZCHXff7B_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Qk1Btk43, 0, m, &cVar_Qk1Btk43_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NCZKq1p0, 0, m, &cVar_NCZKq1p0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WYgicqGp, 0, m, &cVar_WYgicqGp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rLWDtpno, 0, m, &cVar_rLWDtpno_sendMessage);
  cMsg_zg3qhWft_sendMessage(_c, 0, m);
  cSwitchcase_MgcOWHZf_onMessage(_c, NULL, 0, m, NULL);
  cMsg_ncdsauos_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ItOKZudJ, 0, m, &cVar_ItOKZudJ_sendMessage);
  cMsg_dJvhvrdJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8iWTsgsC, 0, m, &cTabhead_8iWTsgsC_sendMessage);
  cMsg_1ynJDr1Z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qHIxkDY6, 0, m, &cVar_qHIxkDY6_sendMessage);
  cMsg_butCDDt7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uCcmDMEB, 0, m, &cTabhead_uCcmDMEB_sendMessage);
  cMsg_5CttTGTy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vc2GdaqP, 0, m, &cVar_vc2GdaqP_sendMessage);
  cMsg_9jFGPMbX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_PC81NOqb, 0, m, &cTabhead_PC81NOqb_sendMessage);
  cMsg_J1bP2JSL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WLBevVxy, 0, m, &cVar_WLBevVxy_sendMessage);
  cMsg_JOdLAWed_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1VlZJewa, 0, m, &cTabhead_1VlZJewa_sendMessage);
  cMsg_8DKPbrlx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EziZOGF9, 0, m, &cVar_EziZOGF9_sendMessage);
  cMsg_B3K9Ckjh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_gIVXQonp, 0, m, &cTabhead_gIVXQonp_sendMessage);
  cMsg_QjhWylaD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3qsIGoPK, 0, m, &cVar_3qsIGoPK_sendMessage);
  cMsg_TE4pymhX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_niXRBrpL, 0, m, &cTabhead_niXRBrpL_sendMessage);
  cMsg_y0H6DHZ8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0FKAwyID, 0, m, &cVar_0FKAwyID_sendMessage);
  cMsg_yAwNWvli_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_tJpUn0Ui, 0, m, &cTabhead_tJpUn0Ui_sendMessage);
  cMsg_BckEHZ5r_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_s0FJfxtI, 0, m, &cVar_s0FJfxtI_sendMessage);
  cMsg_CTXjXire_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ahClQidq, 0, m, &cTabhead_ahClQidq_sendMessage);
  cMsg_vxrjQWcs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8ViM6zyz, 0, m, &cVar_8ViM6zyz_sendMessage);
  cMsg_Qyugvq4V_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_igCz614T, 0, m, &cTabhead_igCz614T_sendMessage);
  cMsg_WcewjlGR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YeFadlNb, 0, m, &cVar_YeFadlNb_sendMessage);
  cMsg_nP4K7X24_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3pxL6LtA, 0, m, &cTabhead_3pxL6LtA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KN5K6XkS, 0, m, &cVar_KN5K6XkS_sendMessage);
  cMsg_33T60Nq0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ubSwnGwZ, 0, m, &cVar_ubSwnGwZ_sendMessage);
  cMsg_ADjrUxu4_sendMessage(_c, 0, m);
  cMsg_NBvopWRQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2YE88RwP, 0, m, &cVar_2YE88RwP_sendMessage);
  cMsg_UTRkXPAK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DNPChEQS, 0, m, &cTabhead_DNPChEQS_sendMessage);
  cMsg_bAhOeku0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lTy1gy5J, 0, m, &cVar_lTy1gy5J_sendMessage);
  cMsg_jI14kHCx_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g1MpEJ9G, 0, m, &cTabhead_g1MpEJ9G_sendMessage);
  cMsg_fGLXeP1R_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_I6cwotqR, 0, m, &cVar_I6cwotqR_sendMessage);
  cMsg_r8tYlXz5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5z6vlxjx, 0, m, &cTabhead_5z6vlxjx_sendMessage);
  cMsg_qCJ9LNfz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_11iJBhOP, 0, m, &cVar_11iJBhOP_sendMessage);
  cMsg_988gaDam_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OdTKQRDD, 0, m, &cTabhead_OdTKQRDD_sendMessage);
  cMsg_Lr3XVXGw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RgIxsLhs, 0, m, &cVar_RgIxsLhs_sendMessage);
  cMsg_XVzg1Xz6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4YIczY6w, 0, m, &cTabhead_4YIczY6w_sendMessage);
  cMsg_BqBosZ1g_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QpjsCjK5, 0, m, &cVar_QpjsCjK5_sendMessage);
  cMsg_rvO91F9p_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4zLK3R6B, 0, m, &cTabhead_4zLK3R6B_sendMessage);
  cMsg_1PpU7Efv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JKvsrGUU, 0, m, &cVar_JKvsrGUU_sendMessage);
  cMsg_805P5UQS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TRZ2wRZx, 0, m, &cTabhead_TRZ2wRZx_sendMessage);
  cMsg_QMbHjG17_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pEYKoDcr, 0, m, &cVar_pEYKoDcr_sendMessage);
  cMsg_XeHzLdgD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OUdihqpP, 0, m, &cTabhead_OUdihqpP_sendMessage);
  cMsg_kd6CZMHF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_74zal9Yw, 0, m, &cVar_74zal9Yw_sendMessage);
  cMsg_5Use5nJ3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_B55Qe9Eb, 0, m, &cTabhead_B55Qe9Eb_sendMessage);
  cMsg_vowNP2XH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YQxs3hBC, 0, m, &cVar_YQxs3hBC_sendMessage);
  cMsg_ArsWEbAX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bnmehkil, 0, m, &cTabhead_bnmehkil_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_el6yAg9k, 0, m, &cVar_el6yAg9k_sendMessage);
  cMsg_nWWzTEB9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QYjbEVes, 0, m, &cVar_QYjbEVes_sendMessage);
  cMsg_rsJOrYT1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_j1XlI59V, 0, m, &cVar_j1XlI59V_sendMessage);
  cMsg_Iu3IDPGX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vO2JddHY, 0, m, &cVar_vO2JddHY_sendMessage);
  cMsg_fDhYf1dR_sendMessage(_c, 0, m);
  cMsg_DmCylmfc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zdSa9Ytr, 0, m, &cVar_zdSa9Ytr_sendMessage);
  cMsg_WLrmsSrw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_m99Kv6c6, 0, m, &cTabhead_m99Kv6c6_sendMessage);
  cMsg_93xtLClp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_moFhwctb, 0, m, &cVar_moFhwctb_sendMessage);
  cMsg_Hy08y92B_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_L6l0vtmE, 0, m, &cTabhead_L6l0vtmE_sendMessage);
  cMsg_PxhMeP1Z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2yX8b2SI, 0, m, &cVar_2yX8b2SI_sendMessage);
  cMsg_h3O9mG4N_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3Ry4iUeT, 0, m, &cTabhead_3Ry4iUeT_sendMessage);
  cMsg_LDe51aCk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uh4L2ung, 0, m, &cVar_uh4L2ung_sendMessage);
  cMsg_3ZlHqMR1_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Na6R33QA, 0, m, &cTabhead_Na6R33QA_sendMessage);
  cMsg_fzd80P7h_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Da34SNGd, 0, m, &cVar_Da34SNGd_sendMessage);
  cMsg_5ePTUIu3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_JnJhxyt3, 0, m, &cTabhead_JnJhxyt3_sendMessage);
}

void Heavy_CircleStrings::cReceive_G8d49Z4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_LY3f9PMI, 0, m, &cSlice_LY3f9PMI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uuE4MNpe, 0, m, &cSlice_uuE4MNpe_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_rocHjDut, 0, m, &cSlice_rocHjDut_sendMessage);
}

void Heavy_CircleStrings::cReceive_seFUm3TM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_maV9bBvI, 0, m, &cPack_maV9bBvI_sendMessage);
}

void Heavy_CircleStrings::cReceive_eVKiQ93V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_maV9bBvI, 1, m, &cPack_maV9bBvI_sendMessage);
}

void Heavy_CircleStrings::cReceive_E9CnU4LC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_Xydlevi3_sendMessage);
}

void Heavy_CircleStrings::cReceive_Sfbdnzv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_c85hXIom_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7XG9CAOo_sendMessage);
}

void Heavy_CircleStrings::cReceive_8QYuQKll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yeEVVgYF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cU2cjvhL_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_zthvGC3f, 0, m, &cPack_zthvGC3f_sendMessage);
}

void Heavy_CircleStrings::cReceive_IuHMkwR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_IsQSlBYB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rddh4osX, 0, m, &cIf_rddh4osX_sendMessage);
}

void Heavy_CircleStrings::cReceive_RPWcUIkk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_G7kPt8UZ, 1, m, &cVar_G7kPt8UZ_sendMessage);
}

void Heavy_CircleStrings::cReceive_ML0XEK3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qk5wgHIG, 0, m, &cVar_Qk5wgHIG_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_QJ7s57YO, 0, m, &cPack_QJ7s57YO_sendMessage);
}

void Heavy_CircleStrings::cReceive_6G8hamK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_OcCnWFYM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_mixmevJi_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CVNk8DoK, 0, m, &cIf_CVNk8DoK_sendMessage);
}

void Heavy_CircleStrings::cReceive_wR3DZeDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cReceive_QnzRUWvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BdISKzza_sendMessage);
}

void Heavy_CircleStrings::cReceive_ijzEOQ4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_864DsC3O_sendMessage);
}

void Heavy_CircleStrings::cReceive_IqM0aObO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eNZp7z3M, 0, m, &cVar_eNZp7z3M_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LzAbDq2B, 0, m, &cVar_LzAbDq2B_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_A3RkeXKq, 0, m, &cVar_A3RkeXKq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kvuXtFqg, 0, m, &cVar_kvuXtFqg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_Z2ZYBtH1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_GbQb6zob, 0, m, &cIf_GbQb6zob_sendMessage);
}

void Heavy_CircleStrings::cReceive_iZs0339h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IGXq3UWU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5Mq56m6C, 0, m, &cVar_5Mq56m6C_sendMessage);
}

void Heavy_CircleStrings::cReceive_rPLLZSoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_B4OSk6Bi, 0, m, &cPack_B4OSk6Bi_sendMessage);
}

void Heavy_CircleStrings::cReceive_9gBXmyIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vL4ksuZB, 1, m, &cVar_vL4ksuZB_sendMessage);
}

void Heavy_CircleStrings::cReceive_UuFhNhpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5EWhrGDY, m);
}

void Heavy_CircleStrings::cReceive_I0KUwktY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XddWP5QI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2r4etoyn, 0, m, &cVar_2r4etoyn_sendMessage);
}

void Heavy_CircleStrings::cReceive_voLTETyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tNwgov09_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2SBSiAIp, 0, m, &cVar_2SBSiAIp_sendMessage);
}

void Heavy_CircleStrings::cReceive_ae1fK3UB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Vngma2UP, 0, m, &cVar_Vngma2UP_sendMessage);
}

void Heavy_CircleStrings::cReceive_NopesP73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kELBtryh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7OtJjyYp_sendMessage);
}

void Heavy_CircleStrings::cReceive_7Xh37HGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Na1HGBpl, 0, m, &cVar_Na1HGBpl_sendMessage);
}

void Heavy_CircleStrings::cReceive_F19zfk9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yuzHGMeu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DQVNxTDj_sendMessage);
}

void Heavy_CircleStrings::cReceive_j7cY7eko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AyZ2Gbzz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_P4hoSHQL, 0, m, &cVar_P4hoSHQL_sendMessage);
}

void Heavy_CircleStrings::cReceive_sDGITZ0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XXwv7GDb, 0, m, &cPack_XXwv7GDb_sendMessage);
}

void Heavy_CircleStrings::cReceive_fL7WIF1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XCDt9fiR, 1, m, &cVar_XCDt9fiR_sendMessage);
}

void Heavy_CircleStrings::cReceive_xyFYFaXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JGHsOizA, m);
}

void Heavy_CircleStrings::cReceive_XjPlYGvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_hOe5n6OG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sbfhSN5v, 0, m, &cVar_sbfhSN5v_sendMessage);
}

void Heavy_CircleStrings::cReceive_DlThSkZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gIYObIhD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HMxCN95O, 0, m, &cVar_HMxCN95O_sendMessage);
}

void Heavy_CircleStrings::cReceive_AQ4lxFlf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IuD93B3Q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fwZmkAh3, 0, m, &cVar_fwZmkAh3_sendMessage);
}

void Heavy_CircleStrings::cReceive_uhw617Gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3CrlaE0w, 0, m, &cPack_3CrlaE0w_sendMessage);
}

void Heavy_CircleStrings::cReceive_RfpieZ96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ezduzPWL, 1, m, &cVar_ezduzPWL_sendMessage);
}

void Heavy_CircleStrings::cReceive_zHi8b9ZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fulbbcJz, m);
}

void Heavy_CircleStrings::cReceive_09FF6qn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Sp7jF8IM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aRmGFL5E, 0, m, &cVar_aRmGFL5E_sendMessage);
}

void Heavy_CircleStrings::cReceive_cLDgQhOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2M3QTzwm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3OM1AKjv, 0, m, &cVar_3OM1AKjv_sendMessage);
}

void Heavy_CircleStrings::cReceive_WpAwdrL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xgzgUj1Q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Kk9SmMbq, 0, m, &cVar_Kk9SmMbq_sendMessage);
}

void Heavy_CircleStrings::cReceive_DuSJ5FW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8ESaVNdy, 0, m, &cPack_8ESaVNdy_sendMessage);
}

void Heavy_CircleStrings::cReceive_Trui00ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lD4uuGr5, 1, m, &cVar_lD4uuGr5_sendMessage);
}

void Heavy_CircleStrings::cReceive_VVPgUsCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GbVnLugv, m);
}

void Heavy_CircleStrings::cReceive_GDyXouKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pzdotn1a_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hzUb5fCZ, 0, m, &cVar_hzUb5fCZ_sendMessage);
}

void Heavy_CircleStrings::cReceive_jONNuo7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ldyvaD5V_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_K1KQ4OwV, 0, m, &cVar_K1KQ4OwV_sendMessage);
}

void Heavy_CircleStrings::cReceive_74xPJo1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iv0lqcFe, 0, m, &cVar_iv0lqcFe_sendMessage);
}

void Heavy_CircleStrings::cReceive_7aFj9XWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8T8jszGv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SCURCgOh_sendMessage);
}

void Heavy_CircleStrings::cReceive_Gy8UdtWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_52zAWov1_sendMessage);
}

void Heavy_CircleStrings::cReceive_ZHPUw2jf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RoCiCtFT, 0, m, &cVar_RoCiCtFT_sendMessage);
}

void Heavy_CircleStrings::cReceive_vqYwP32U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q52zal8s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tp3frpqo_sendMessage);
}

void Heavy_CircleStrings::cReceive_3NNPuLRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_kt2gx7xb_sendMessage);
}

void Heavy_CircleStrings::cReceive_yCivK9mR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fCLCkWHM, 0, m, &cVar_fCLCkWHM_sendMessage);
}

void Heavy_CircleStrings::cReceive_CHQ1g4FG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CZ5JTYMb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LUH1HSmh_sendMessage);
}

void Heavy_CircleStrings::cReceive_X4bVaKCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9pVj4ORn, 0, m, &cVar_9pVj4ORn_sendMessage);
}

void Heavy_CircleStrings::cReceive_Xblvs9oi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3woxlkFK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CJgEg6Rj_sendMessage);
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
    __hv_tabread_f(&sTabread_GYXlYRcm, VOf(Bf0));
    __hv_varread_f(&sVarf_ZHYUlze1, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_TokwBxRx, VOf(Bf0));
    __hv_rpole_f(&sRPole_qtKjBJHy, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_kT2b3zGO, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_Pj4QS8W0, VOf(Bf0));
    __hv_varread_i(&sVari_86awwOFU, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_i(&sVari_86awwOFU, VIi(Bi1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_vrh8RkrH, VIf(Bf3));
    __hv_line_f(&sLine_964ec3Hj, VOf(Bf3));
    __hv_varread_f(&sVarf_5EWhrGDY, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_l9fmtAyJ, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_BHW7nLyY, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_hZGe92G2, VOf(Bf0));
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
    __hv_line_f(&sLine_w8L8FYXi, VOf(Bf2));
    __hv_tabread_f(&sTabread_1aCCkw6G, VOf(Bf2));
    __hv_varread_f(&sVarf_IM1d81Zv, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_VJzAFhB9, VOf(Bf2));
    __hv_rpole_f(&sRPole_69cmL7iO, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_vFX25tA7, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_vCCpnqjj, VOf(Bf2));
    __hv_varread_i(&sVari_s4GXElM2, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_i(&sVari_s4GXElM2, VIi(Bi0));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf5), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_KvpKG1Gm, VIf(Bf6));
    __hv_line_f(&sLine_5zbd8vEX, VOf(Bf6));
    __hv_varread_f(&sVarf_JGHsOizA, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_zQg6bCvl, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_X3VQJ0O6, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_phasor_k_f(&sPhasor_3EyaiDYY, VOf(Bf2));
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
    __hv_line_f(&sLine_Euvi18F8, VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_tabread_f(&sTabread_N5fSY17U, VOf(Bf1));
    __hv_varread_f(&sVarf_BE6Uws89, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_wFdXt49n, VOf(Bf1));
    __hv_rpole_f(&sRPole_HvBuzrxF, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_XaJi2hat, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_0lBOVxmG, VOf(Bf1));
    __hv_varread_i(&sVari_P0KwOnwe, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_i(&sVari_P0KwOnwe, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_lcGYQI2C, VIf(Bf2));
    __hv_line_f(&sLine_cqQWPtnv, VOf(Bf2));
    __hv_varread_f(&sVarf_fulbbcJz, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_ZWduZLcc, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_jggvrXTT, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_ekdPoVtd, VOf(Bf1));
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
    __hv_line_f(&sLine_mqYiiRZh, VOf(Bf7));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_W7LYHhEe, VOf(Bf5));
    __hv_varread_f(&sVarf_Tqm2CRXI, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_pinR2d10, VOf(Bf5));
    __hv_rpole_f(&sRPole_J4FJZ7Zg, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_jEe7pjPw, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_G9y6Bk1z, VOf(Bf5));
    __hv_varread_i(&sVari_B3LqpK8Z, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_B3LqpK8Z, VIi(Bi0));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf7), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_ciS6I4s5, VIf(Bf1));
    __hv_line_f(&sLine_vhqu07wb, VOf(Bf1));
    __hv_varread_f(&sVarf_GbVnLugv, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_E1UYqvL7, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_cvDW0it2, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_oApnp92K, VOf(Bf5));
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
    __hv_line_f(&sLine_jCzzFIa2, VOf(Bf4));
    __hv_add_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_Vhv0DGli, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_vV6XeVsB, VOf(Bf1));
    __hv_varread_f(&sVarf_IRrweIw6, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_hSUK4UMu, VOf(Bf1));
    __hv_rpole_f(&sRPole_I4Oni5cP, VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_NUFMr1zH, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_Suu54cO4, VOf(Bf1));
    __hv_varread_i(&sVari_a5h7BKRR, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_i(&sVari_a5h7BKRR, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_Y67LdaFm, VIf(Bf0));
    __hv_line_f(&sLine_6uGgHRhC, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_yBLxNPSA, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_bUZWOmbv, VOf(Bf0));
    __hv_rpole_f(&sRPole_FR7GFxCN, VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_FxrAjuSF, VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_6FNy6t81, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_xgyzHgyk, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf0));
    __hv_line_f(&sLine_OH37p02E, VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_S9z7G4QB, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_5wzI9Ouq, VOf(Bf6));
    __hv_varread_f(&sVarf_8m6kUpjO, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_BmZqn46h, VOf(Bf3));
    __hv_rpole_f(&sRPole_BbMjKCPS, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf3));
    __hv_line_f(&sLine_UGi5IRnl, VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_xkMaD7Gw, VOf(Bf3));
    __hv_tabread_f(&sTabread_rRDj5oBk, VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf8));
    __hv_tabread_f(&sTabread_qGZvrzA1, VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf5), VOf(Bf10));
    __hv_tabread_f(&sTabread_WxIVxT4O, VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf11));
    __hv_tabread_f(&sTabread_ML7AvYC4, VOf(Bf12));
    __hv_add_f(VIf(Bf11), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_gPSVfwSP, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_QPJgHarV, VIf(Bf15));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_uCGIefpB, VIf(Bf12));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_37eaUNFL, VIf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_uz9Jpa5M, VIf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_dr04uzNw, VIf(Bf4));
    __hv_tabwrite_f(&sTabwrite_vZOYBlLw, VIf(Bf2));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_DDrOibzj, VOf(Bf13));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_J80Ll0xd, VOf(Bf6));
    __hv_varread_f(&sVarf_vTIe5vMR, VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_d10dqNNT, VOf(Bf5));
    __hv_rpole_f(&sRPole_HniYE8nY, VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf6));
    __hv_tabread_f(&sTabread_TIxPr7Di, VOf(Bf5));
    __hv_varread_f(&sVarf_b4TNpUI7, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_g2hPNVDq, VOf(Bf8));
    __hv_rpole_f(&sRPole_8e1qhgIW, VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf5));
    __hv_tabread_f(&sTabread_USQh9C7D, VOf(Bf8));
    __hv_varread_f(&sVarf_mmqL9MSY, VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_s8UdZm21, VOf(Bf9));
    __hv_rpole_f(&sRPole_b4JjOZLh, VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf8));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_RIPwGPXw, VIf(Bf0));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_4hh8ppP2, VIf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_7JNh6oma, VIf(Bf8));
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_4Fh1eyl8, VIf(Bf9));
    __hv_line_f(&sLine_cIS5LomB, VOf(Bf9));
    __hv_mul_f(VIf(Bf14), VIf(Bf9), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_5ZcapK5C, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_bzM0tjah, VIf(Bf5));
    __hv_line_f(&sLine_v12SfsfY, VOf(Bf9));
    __hv_phasor_f(&sPhasor_eZSZYeSj, VIf(Bf9), VOf(Bf9));
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
    __hv_line_f(&sLine_LerpTV8g, VOf(Bf10));
    __hv_line_f(&sLine_bo2adHae, VOf(Bf3));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf3), VOf(Bf11));
    __hv_tabhead_f(&sTabhead_Fg7MAI0b, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf6), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_0OA4xBf8, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_09g6lkS6, VOf(Bf11));
    __hv_min_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf6));
    __hv_varread_f(&sVarf_pCmpeTQ1, VOf(Bf11));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_Y5TcnGFR, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_G75a3hd6, VIi(Bi1), VOf(Bf11));
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
    __hv_tabhead_f(&sTabhead_oxxAcLDQ, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_cBxpEWJD, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_Ad5Jgohh, VOf(Bf3));
    __hv_min_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf9));
    __hv_varread_f(&sVarf_OTuclQyF, VOf(Bf3));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_FMAoJnef, VIi(Bi0), VOf(Bf16));
    __hv_tabread_if(&sTabread_qAnwLvTX, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf16), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_FM4REvIk, VOf(Bf11));
    __hv_tabhead_f(&sTabhead_wC1XvSLf, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_GbJH217E, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_QCyPaNwg, VOf(Bf11));
    __hv_min_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_IbD0B43N, VOf(Bf11));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_x1WnWumW, VIi(Bi0), VOf(Bf9));
    __hv_tabread_if(&sTabread_CiFdjMq7, VIi(Bi1), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf9));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf9), VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_Bp4zUvhW, VOf(Bf17));
    __hv_rpole_f(&sRPole_Z7EOpCWT, VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_CwOxysEy, VIf(Bf17), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_2LWAfMYm, VOf(Bf17));
    __hv_mul_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_RrENqtYY, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf11), VOf(Bf17));
    __hv_line_f(&sLine_Tf4T9HN7, VOf(Bf9));
    __hv_varread_f(&sVarf_ZqUayoeQ, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_nuJFmSvc, VOf(Bf11));
    __hv_rpole_f(&sRPole_BPycBdHb, VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_unvYRlum, VIf(Bf11));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_jb63r1RP, VOf(Bf17));
    __hv_varread_f(&sVarf_40TbTNja, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_N1n5CvGJ, VOf(Bf11));
    __hv_min_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_6AjpsSlO, VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_varread_f(&sVarf_sGjm4a1G, VOf(Bf11));
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
    __hv_cpole_f(&sCPole_o6T1B6Fo, VIf(Bf11), VIf(ZERO), VIf(Bf3), VIf(Bf17), VOf(Bf17), VOf(Bf3));
    __hv_varread_f(&sVarf_N1aJPsXy, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Q3ZbbXIh, VOf(Bf17));
    __hv_rpole_f(&sRPole_AQ5bE6Be, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_4EleNNMn, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_2Sq9vG0p, VOf(Bf17));
    __hv_rpole_f(&sRPole_ewDYnW2L, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_Ya1pw3Ca, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_zo7qlgpD, VOf(Bf17));
    __hv_rpole_f(&sRPole_PbpS9CNw, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_EJBvAau9, VOf(Bf3));
    __hv_varread_f(&sVarf_viDEo7qO, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_9Mz48IAi, VOf(Bf9));
    __hv_rpole_f(&sRPole_grzpI5YF, VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf9));
    __hv_line_f(&sLine_krZgnHvS, VOf(Bf11));
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_mm0zyZRY, VOf(Bf9));
    __hv_tabread_f(&sTabread_GQLCq0LD, VOf(Bf5));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf12));
    __hv_tabread_f(&sTabread_yMXSZikX, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf10));
    __hv_tabread_f(&sTabread_4tLx6s3e, VOf(Bf6));
    __hv_add_f(VIf(Bf10), VIf(Bf6), VOf(Bf18));
    __hv_tabread_f(&sTabread_CC1C7bS9, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf8));
    __hv_tabread_f(&sTabread_RvsieZMa, VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_5quX7Z2l, VIf(Bf4));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_m7BKq9Lz, VIf(Bf15));
    __hv_sub_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_pl1PuYP5, VIf(Bf6));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_rgeK7yZK, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_cLldnAlw, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_vzaH69qg, VIf(Bf17));
    __hv_add_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_Z2yN6k4g, VOf(Bf8));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_l2D07D0n, VOf(Bf3));
    __hv_varread_f(&sVarf_HclWugYq, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_FThq7u62, VOf(Bf16));
    __hv_rpole_f(&sRPole_6jWoOgYz, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf0), VIf(Bf8), VOf(Bf3));
    __hv_tabread_f(&sTabread_v5JWWHtr, VOf(Bf16));
    __hv_varread_f(&sVarf_mP9b6bqJ, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_brOFQHvC, VOf(Bf12));
    __hv_rpole_f(&sRPole_IjpnJMkQ, VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf9), VOf(Bf16));
    __hv_tabread_f(&sTabread_gy8b0rpi, VOf(Bf12));
    __hv_varread_f(&sVarf_ekxgst84, VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Oza60i9N, VOf(Bf6));
    __hv_rpole_f(&sRPole_30ghtA40, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf12), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf16), VIf(Bf9), VOf(Bf12));
    __hv_add_f(VIf(Bf3), VIf(Bf12), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_tnrQ1xv0, VIf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf11));
    __hv_sub_f(VIf(Bf16), VIf(Bf9), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_urgLMwdS, VIf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_ip1N1KtB, VIf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_BTZrwd7U, VIf(Bf6));
    __hv_line_f(&sLine_VjsKZ0ko, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf16));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_PTG8xNxi, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_7JDZLfHq, VIf(Bf0));
    __hv_line_f(&sLine_mnnJyNt9, VOf(Bf0));
    __hv_phasor_f(&sPhasor_3IpYVicw, VIf(Bf0), VOf(Bf0));
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
    __hv_line_f(&sLine_j3HXZ1jf, VOf(Bf11));
    __hv_line_f(&sLine_XQ5Orvf1, VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf11), VIf(Bf2), VOf(Bf3));
    __hv_tabhead_f(&sTabhead_LHG91B4J, VOf(Bf9));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_lhzz1dz7, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_so1RV3cw, VOf(Bf3));
    __hv_min_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf8));
    __hv_varread_f(&sVarf_JmbYI3q5, VOf(Bf3));
    __hv_zero_f(VOf(Bf6));
    __hv_lt_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_VWN0RC4X, VIi(Bi0), VOf(Bf6));
    __hv_tabread_if(&sTabread_zM26yptp, VIi(Bi1), VOf(Bf3));
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
    __hv_tabhead_f(&sTabhead_1tCj90Eq, VOf(Bf11));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_MAlaLCPo, VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_z1F6TqrN, VOf(Bf2));
    __hv_min_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf11));
    __hv_max_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf0));
    __hv_varread_f(&sVarf_nHhJzQBE, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_xV6t9t0R, VIi(Bi0), VOf(Bf10));
    __hv_tabread_if(&sTabread_kLDiyCA1, VIi(Bi1), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf10), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf12), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_9B9Ou6MK, VOf(Bf3));
    __hv_tabhead_f(&sTabhead_1L9pipPW, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_hotVM8YE, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_H39jlROv, VOf(Bf3));
    __hv_min_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_J1BCJR0D, VOf(Bf3));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_WVu8eObS, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_ehYMeO6w, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf0));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf0), VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_9gj4DHD9, VOf(Bf15));
    __hv_rpole_f(&sRPole_6ng4ulmN, VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_4gB9hQrn, VIf(Bf15), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_RDs9J6VZ, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_5vWGMIw3, VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf15));
    __hv_line_f(&sLine_0OIEmVkv, VOf(Bf0));
    __hv_varread_f(&sVarf_eFHEnv6b, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_c3hjuZuw, VOf(Bf3));
    __hv_rpole_f(&sRPole_6fqtrnLN, VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_AF0TMShV, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf14), VIf(Bf3), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_cFH7Mude, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_0jZKEEOX, VOf(Bf1));
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

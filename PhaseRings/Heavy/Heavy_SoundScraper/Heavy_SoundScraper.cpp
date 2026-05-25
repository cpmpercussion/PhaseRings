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
  numBytes += sRPole_init(&sRPole_5erl0O3i);
  numBytes += sLine_init(&sLine_ouwKXvfr);
  numBytes += sPhasor_k_init(&sPhasor_kzAqhD4D, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_0mbOSzS9);
  numBytes += sSamphold_init(&sSamphold_F9qbsRRX);
  numBytes += sDel1_init(&sDel1_UiYtJKlq);
  numBytes += sSamphold_init(&sSamphold_BvV0Kdcg);
  numBytes += sTabread_init(&sTabread_6cHL06Z7, &hTable_mkrY4Gmu, false);
  numBytes += sTabread_init(&sTabread_gXemxlJn, &hTable_mkrY4Gmu, false);
  numBytes += sDel1_init(&sDel1_PIq2Q6oO);
  numBytes += sSamphold_init(&sSamphold_uLkDsfif);
  numBytes += sDel1_init(&sDel1_AJyGIeKd);
  numBytes += sSamphold_init(&sSamphold_i1o8zcrt);
  numBytes += sTabread_init(&sTabread_sGmFShe2, &hTable_mkrY4Gmu, false);
  numBytes += sTabread_init(&sTabread_dYnHV9Uq, &hTable_mkrY4Gmu, false);
  numBytes += sRPole_init(&sRPole_elWUa40G);
  numBytes += sDel1_init(&sDel1_GT6OdVIi);
  numBytes += sLine_init(&sLine_xm51otue);
  numBytes += sLine_init(&sLine_Ax58MiOs);
  numBytes += sTabread_init(&sTabread_YNp8IIEx, &hTable_mkrY4Gmu, false);
  numBytes += sTabread_init(&sTabread_WlYtYe97, &hTable_mkrY4Gmu, false);
  numBytes += sLine_init(&sLine_ahoDOIU8);
  numBytes += sLine_init(&sLine_AWOvZvHv);
  numBytes += sLine_init(&sLine_3Oe9ttxx);
  numBytes += sLine_init(&sLine_vZWrJGpE);
  numBytes += sLine_init(&sLine_mgjVTqKC);
  numBytes += sTabread_init(&sTabread_3eXZzuzi, &hTable_mkrY4Gmu, false);
  numBytes += sTabread_init(&sTabread_AlK8zS2Z, &hTable_mkrY4Gmu, false);
  numBytes += sLine_init(&sLine_tYlQqpyr);
  numBytes += sLine_init(&sLine_Pgz7rY0l);
  numBytes += sLine_init(&sLine_fYRZYmYC);
  numBytes += sLine_init(&sLine_05eRgPab);
  numBytes += sLine_init(&sLine_UqJ0OItO);
  numBytes += sTabread_init(&sTabread_s9uAqArt, &hTable_mkrY4Gmu, false);
  numBytes += sTabread_init(&sTabread_2xZgpS5z, &hTable_mkrY4Gmu, false);
  numBytes += sLine_init(&sLine_4WEnB2xJ);
  numBytes += sLine_init(&sLine_BoLoW5DV);
  numBytes += sLine_init(&sLine_X8UVgosI);
  numBytes += sLine_init(&sLine_5mjgQ1RK);
  numBytes += sLine_init(&sLine_iSCeTc4t);
  numBytes += sTabread_init(&sTabread_yWgAUCjh, &hTable_mkrY4Gmu, false);
  numBytes += sTabread_init(&sTabread_n1CZftWo, &hTable_mkrY4Gmu, false);
  numBytes += sLine_init(&sLine_SdVEGH4p);
  numBytes += sLine_init(&sLine_SUMTp9A5);
  numBytes += sLine_init(&sLine_wLKjYKtF);
  numBytes += sLine_init(&sLine_kF24xNgR);
  numBytes += sLine_init(&sLine_M7x71X3I);
  numBytes += sLine_init(&sLine_QX53BrJd);
  numBytes += sLine_init(&sLine_EZJEEblW);
  numBytes += sLine_init(&sLine_ukQ3KPzs);
  numBytes += sLine_init(&sLine_grGvWGq3);
  numBytes += sTabwrite_init(&sTabwrite_7i5MYA1m, &hTable_0pw5qmv4);
  numBytes += sLine_init(&sLine_l8yZ8PmG);
  numBytes += sPhasor_init(&sPhasor_32F1xt5U, sampleRate);
  numBytes += sLine_init(&sLine_uOk1bftI);
  numBytes += sLine_init(&sLine_Nx7OK4nw);
  numBytes += sTabhead_init(&sTabhead_7J9nJ7Zx, &hTable_0pw5qmv4);
  numBytes += sTabread_init(&sTabread_t3THQHvt, &hTable_0pw5qmv4, false);
  numBytes += sTabread_init(&sTabread_dMgCef6c, &hTable_0pw5qmv4, false);
  numBytes += sTabhead_init(&sTabhead_htUm7fHG, &hTable_0pw5qmv4);
  numBytes += sTabread_init(&sTabread_kqQskfmc, &hTable_0pw5qmv4, false);
  numBytes += sTabread_init(&sTabread_twivHhtS, &hTable_0pw5qmv4, false);
  numBytes += sTabhead_init(&sTabhead_6e3ywMhl, &hTable_pIje5WwM);
  numBytes += sTabread_init(&sTabread_BIPVfW71, &hTable_pIje5WwM, false);
  numBytes += sTabread_init(&sTabread_E0Z7RCIZ, &hTable_pIje5WwM, false);
  numBytes += sRPole_init(&sRPole_qjdpsafF);
  numBytes += sDel1_init(&sDel1_jb4fyaqO);
  numBytes += sLine_init(&sLine_A1gHAy57);
  numBytes += sRPole_init(&sRPole_9Qd1rBEc);
  numBytes += sTabwrite_init(&sTabwrite_O7x1yznz, &hTable_pIje5WwM);
  numBytes += sTabread_init(&sTabread_Uy2K3pCf, &hTable_N9HZZxsE, true);
  numBytes += sRPole_init(&sRPole_99oqkByn);
  numBytes += sLine_init(&sLine_WWwnhSwT);
  numBytes += sLine_init(&sLine_L0Mri4MD);
  numBytes += sTabread_init(&sTabread_wUW8qMXA, &hTable_edoVP1Zx, true);
  numBytes += sTabread_init(&sTabread_4UhmKvR8, &hTable_QyEdTLTC, true);
  numBytes += sTabread_init(&sTabread_FvaD7CXE, &hTable_H4gx4UDe, true);
  numBytes += sTabread_init(&sTabread_LcaVlVgU, &hTable_SNZe3goA, true);
  numBytes += sTabread_init(&sTabread_ggfxdbHw, &hTable_0HOxNfI7, true);
  numBytes += sTabwrite_init(&sTabwrite_RBetVyja, &hTable_QS6oRB0W);
  numBytes += sTabwrite_init(&sTabwrite_Q8k3vA1z, &hTable_0HOxNfI7);
  numBytes += sTabwrite_init(&sTabwrite_E5p68zQV, &hTable_SNZe3goA);
  numBytes += sTabwrite_init(&sTabwrite_hCbNLFPd, &hTable_H4gx4UDe);
  numBytes += sTabwrite_init(&sTabwrite_p8O038Oy, &hTable_QyEdTLTC);
  numBytes += sTabwrite_init(&sTabwrite_fyfmrotI, &hTable_edoVP1Zx);
  numBytes += sTabread_init(&sTabread_PsBaah8T, &hTable_QS6oRB0W, true);
  numBytes += sTabread_init(&sTabread_qwJqadBw, &hTable_CtaVjDDf, true);
  numBytes += sRPole_init(&sRPole_b6oaT5gP);
  numBytes += sTabread_init(&sTabread_u39yoezc, &hTable_cWZLWzF9, true);
  numBytes += sRPole_init(&sRPole_6sLuhRiO);
  numBytes += sTabread_init(&sTabread_tf6TMInt, &hTable_LzIhUYZh, true);
  numBytes += sRPole_init(&sRPole_rNMzx741);
  numBytes += sTabwrite_init(&sTabwrite_GDROM89T, &hTable_N9HZZxsE);
  numBytes += sTabwrite_init(&sTabwrite_mtYgfeBy, &hTable_CtaVjDDf);
  numBytes += sTabwrite_init(&sTabwrite_S9gJQoGt, &hTable_cWZLWzF9);
  numBytes += sTabwrite_init(&sTabwrite_75vpgRfb, &hTable_LzIhUYZh);
  numBytes += sLine_init(&sLine_I0C2aoof);
  numBytes += sLine_init(&sLine_RBcAbHIH);
  numBytes += sTabwrite_init(&sTabwrite_ct1Wegjp, &hTable_URmk7nqK);
  numBytes += sLine_init(&sLine_Ev0c8Aaf);
  numBytes += sPhasor_init(&sPhasor_ohnOaq85, sampleRate);
  numBytes += sLine_init(&sLine_M9xlmo4f);
  numBytes += sLine_init(&sLine_YTT8XtFC);
  numBytes += sTabhead_init(&sTabhead_CH5E92Y0, &hTable_URmk7nqK);
  numBytes += sTabread_init(&sTabread_wGLauZoR, &hTable_URmk7nqK, false);
  numBytes += sTabread_init(&sTabread_xmwc9cp1, &hTable_URmk7nqK, false);
  numBytes += sTabhead_init(&sTabhead_hNjcgGe6, &hTable_URmk7nqK);
  numBytes += sTabread_init(&sTabread_FURDrYRZ, &hTable_URmk7nqK, false);
  numBytes += sTabread_init(&sTabread_xFjUccNt, &hTable_URmk7nqK, false);
  numBytes += sTabhead_init(&sTabhead_E83eOKwh, &hTable_pu0SzX3H);
  numBytes += sTabread_init(&sTabread_1qccabZm, &hTable_pu0SzX3H, false);
  numBytes += sTabread_init(&sTabread_cF4y7FXx, &hTable_pu0SzX3H, false);
  numBytes += sRPole_init(&sRPole_JbVpK0oo);
  numBytes += sDel1_init(&sDel1_8JgtlQvk);
  numBytes += sLine_init(&sLine_LrVEa7hq);
  numBytes += sRPole_init(&sRPole_SIikIMkx);
  numBytes += sTabwrite_init(&sTabwrite_ZuEGUlfr, &hTable_pu0SzX3H);
  numBytes += sCPole_init(&sCPole_VuTxgN9y);
  numBytes += sRPole_init(&sRPole_WLO0b9vP);
  numBytes += sRPole_init(&sRPole_BpxZqe4j);
  numBytes += sRPole_init(&sRPole_aHocSK0T);
  numBytes += sTabread_init(&sTabread_xx2RUEzx, &hTable_LJrCyPE0, true);
  numBytes += sRPole_init(&sRPole_FhaSnsu8);
  numBytes += sLine_init(&sLine_sYRsyTvl);
  numBytes += sLine_init(&sLine_Ad9WQWGw);
  numBytes += sTabread_init(&sTabread_i0JcSFnt, &hTable_O7V4a1Mb, true);
  numBytes += sTabread_init(&sTabread_J2owhUk5, &hTable_plbZ7cRO, true);
  numBytes += sTabread_init(&sTabread_Brq6KY0F, &hTable_aDFVpMco, true);
  numBytes += sTabread_init(&sTabread_njis9KQS, &hTable_RcY0yvWg, true);
  numBytes += sTabread_init(&sTabread_6O2xxiiV, &hTable_us6eLSN0, true);
  numBytes += sTabwrite_init(&sTabwrite_gO0AoIZk, &hTable_eeTIy2k1);
  numBytes += sTabwrite_init(&sTabwrite_HwGdZfuG, &hTable_us6eLSN0);
  numBytes += sTabwrite_init(&sTabwrite_Unshn8w7, &hTable_RcY0yvWg);
  numBytes += sTabwrite_init(&sTabwrite_B1930N3N, &hTable_aDFVpMco);
  numBytes += sTabwrite_init(&sTabwrite_EnuyWmm3, &hTable_plbZ7cRO);
  numBytes += sTabwrite_init(&sTabwrite_f8rBzpT0, &hTable_O7V4a1Mb);
  numBytes += sTabread_init(&sTabread_Smc2j305, &hTable_eeTIy2k1, true);
  numBytes += sTabread_init(&sTabread_B9pPbqux, &hTable_LO77Vyhx, true);
  numBytes += sRPole_init(&sRPole_0Jgqd4qB);
  numBytes += sTabread_init(&sTabread_pvtbGZJz, &hTable_u47NZ5VP, true);
  numBytes += sRPole_init(&sRPole_WAkwqGBu);
  numBytes += sTabread_init(&sTabread_0Nwpu5zT, &hTable_QRmVDbhG, true);
  numBytes += sRPole_init(&sRPole_59lcMDyM);
  numBytes += sTabwrite_init(&sTabwrite_ZhrvGVHA, &hTable_LJrCyPE0);
  numBytes += sTabwrite_init(&sTabwrite_N9z8Y0Wr, &hTable_LO77Vyhx);
  numBytes += sTabwrite_init(&sTabwrite_yk4PCHwH, &hTable_u47NZ5VP);
  numBytes += sTabwrite_init(&sTabwrite_z1QlnVwa, &hTable_QRmVDbhG);
  numBytes += sLine_init(&sLine_0iVuKQiD);
  numBytes += sLine_init(&sLine_iMAvKVIb);
  numBytes += sLine_init(&sLine_0A2cf6G7);
  numBytes += cSlice_init(&cSlice_13XRqR7h, 2, 1);
  numBytes += cSlice_init(&cSlice_lbpghUeX, 1, 1);
  numBytes += cSlice_init(&cSlice_q718bSyL, 0, 1);
  numBytes += cVar_init_f(&cVar_4EVvJEui, 0.0f);
  numBytes += cIf_init(&cIf_ii1H5MrX, false);
  numBytes += cIf_init(&cIf_PYrAvUld, false);
  numBytes += cIf_init(&cIf_xEhrIDaZ, false);
  numBytes += cIf_init(&cIf_U2EnedUD, false);
  numBytes += cIf_init(&cIf_RCOngieN, false);
  numBytes += cBinop_init(&cBinop_aG3AWbaR, 0.0f); // __eq
  numBytes += cVar_init_s(&cVar_An98gPxa, "floatatom");
  numBytes += cVar_init_s(&cVar_ATLlHaU1, "floatatom");
  numBytes += cVar_init_f(&cVar_VObqW7Rd, 1.0f);
  numBytes += cVar_init_f(&cVar_N1fa7BjL, 0.0f);
  numBytes += cVar_init_f(&cVar_zzCdMh7F, 0.0f);
  numBytes += cVar_init_f(&cVar_JHFMCtq6, 127.0f);
  numBytes += cRandom_init(&cRandom_bRYdKz6J, 1819126643);
  numBytes += cSlice_init(&cSlice_u8ELYnC2, 1, 1);
  numBytes += cVar_init_s(&cVar_5vTXHZS3, "floatatom");
  numBytes += cVar_init_f(&cVar_EV73xJ0A, 98.0f);
  numBytes += cIf_init(&cIf_j3wD3ONA, false);
  numBytes += cBinop_init(&cBinop_mUgR1mMn, 0.0f); // __pow
  numBytes += cPack_init(&cPack_rxYXvI9Y, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_GMsfwqno, 0.0f);
  numBytes += cRandom_init(&cRandom_WDovrO27, -1193996597);
  numBytes += cSlice_init(&cSlice_FpLvtW1E, 1, 1);
  numBytes += cRandom_init(&cRandom_LqWEdriQ, -840624015);
  numBytes += cSlice_init(&cSlice_yAXRMhJh, 1, 1);
  numBytes += cVar_init_s(&cVar_oEcGGobk, "floatatom");
  numBytes += cPack_init(&cPack_zTveEpUe, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_qwbWlHTJ, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_osvAOxH5, "floatatom");
  numBytes += cDelay_init(this, &cDelay_kyxBlKNV, 0.0f);
  numBytes += cDelay_init(this, &cDelay_athLVzzr, 0.0f);
  numBytes += hTable_init(&hTable_0pw5qmv4, 256);
  numBytes += cVar_init_s(&cVar_rkCpV5AF, "del-1040-del");
  numBytes += sVarf_init(&sVarf_1T2THY7r, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qiJScZeT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wPz3fdL5, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_f80TjrWe, "del-1040-del");
  numBytes += sVarf_init(&sVarf_i795IZdH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_R4oHvD5Q, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ygUmyTek, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_zwpeIzaF, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_xpJUWQBu, "del-1069-del1");
  numBytes += sVarf_init(&sVarf_rRRWoka6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZsaRIZxr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BQDCmbEw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wfPwA3yL, 10000.0f);
  numBytes += cBinop_init(&cBinop_im9nidtw, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_rFXlZCME, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eAzeWq1z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Hn0ZGoaR, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_82msUsXF, 10.0f);
  numBytes += cBinop_init(&cBinop_P96y4mrO, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_WAaujEk5, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_fxO1wGQu, "floatatom");
  numBytes += sVarf_init(&sVarf_47HqzkJf, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_XQwFbd6m, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OtBO7KJz, 0.0f);
  numBytes += hTable_init(&hTable_pIje5WwM, 256);
  numBytes += sVarf_init(&sVarf_EJaCbrWF, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_EPI4X7Lh, "floatatom");
  numBytes += cDelay_init(this, &cDelay_9QNQ5Soo, 0.0f);
  numBytes += cVar_init_f(&cVar_zA33dGaX, 20.0f);
  numBytes += cBinop_init(&cBinop_kgsqXjQf, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_96XE8DaX, 0.0f);
  numBytes += cSlice_init(&cSlice_ggybWYkK, 1, -1);
  numBytes += cSlice_init(&cSlice_KYg1Owge, 1, -1);
  numBytes += cVar_init_f(&cVar_iCxlPoMC, 0.0f);
  numBytes += cVar_init_f(&cVar_Xl3EeTDl, 20.0f);
  numBytes += cVar_init_f(&cVar_A0Egmp55, 0.0f);
  numBytes += cVar_init_f(&cVar_Ab5IU5Ni, 0.0f);
  numBytes += cVar_init_f(&cVar_tXq4OrGo, 0.0f);
  numBytes += cSlice_init(&cSlice_MrIpmjwd, 1, 1);
  numBytes += cSlice_init(&cSlice_MaeA1mNv, 0, 1);
  numBytes += cBinop_init(&cBinop_slprhsz3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_LFReCwnL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4GFw9qVO, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_1l7JrMYI, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_xvXbbmbQ, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_56Hgxf9N, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_yVs6isXO, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_3e4Bt1EH, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_c4H6qIOA, "floatatom");
  numBytes += cPack_init(&cPack_djmdksop, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_jbuLXfH6, 0.0f);
  numBytes += cVar_init_f(&cVar_t6k8MfJI, 20.0f);
  numBytes += cBinop_init(&cBinop_pUIfNBDd, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_jVgEmOG7, 0.0f);
  numBytes += cSlice_init(&cSlice_PMsvQ7rk, 1, -1);
  numBytes += cSlice_init(&cSlice_Sk5NGUig, 1, -1);
  numBytes += cVar_init_f(&cVar_CBnqGEL9, 0.0f);
  numBytes += cVar_init_f(&cVar_sgrR3zew, 20.0f);
  numBytes += cVar_init_f(&cVar_VfXwFZY9, 0.0f);
  numBytes += cVar_init_f(&cVar_p8tULMOd, 0.0f);
  numBytes += cVar_init_f(&cVar_qeglyR1K, 0.0f);
  numBytes += cSlice_init(&cSlice_rmHbt3Gz, 1, 1);
  numBytes += cSlice_init(&cSlice_n156S4jd, 0, 1);
  numBytes += cBinop_init(&cBinop_VglGngpY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_XKPYUzZf, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_fJVWDj7y, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FSs39JRb, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_YLxBBs3v, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_sy77Ku1B, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_CBfHgv4k, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_RVa1vljE, 0.0f); // __sub
  numBytes += cPack_init(&cPack_OMpWVvNb, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_5IOyDtUv, 2, 0.0f, 1000.0f);
  numBytes += cTabhead_init(&cTabhead_JkbRmVGZ, &hTable_N9HZZxsE);
  numBytes += cVar_init_s(&cVar_tDo2rNxN, "del-1130-del1");
  numBytes += cDelay_init(this, &cDelay_EhXauGUV, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_EVRt3sqi, 0.0f);
  numBytes += cBinop_init(&cBinop_5yacHnVq, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_7FXr8Gxz, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_EzbYgVuC, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_9Ylc6RXK, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_Hir9LMco, &hTable_CtaVjDDf);
  numBytes += cVar_init_s(&cVar_aoZnCuCn, "del-1130-del2");
  numBytes += cDelay_init(this, &cDelay_QHGrB6o0, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_S4hEoMua, 0.0f);
  numBytes += cBinop_init(&cBinop_2qc8DPWr, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_OhecreKz, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9SJDBfQA, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_COxCNclT, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_OWNyXRSs, &hTable_cWZLWzF9);
  numBytes += cVar_init_s(&cVar_LjyXlIqz, "del-1130-del3");
  numBytes += cDelay_init(this, &cDelay_Ed6s8Egg, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_7mNNQuir, 0.0f);
  numBytes += cBinop_init(&cBinop_4L5x6FK1, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_AzNRJLjm, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_nwRFp0Rd, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_VxyHqaqQ, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_mDulVuSE, &hTable_LzIhUYZh);
  numBytes += cVar_init_s(&cVar_gnZEOEpr, "del-1130-del4");
  numBytes += cDelay_init(this, &cDelay_Y4iPok5W, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_T7n8rKWK, 0.0f);
  numBytes += cBinop_init(&cBinop_zcYR4UY8, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_sig14typ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_J6JjJOgB, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ttI25lId, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_pl2SKrD0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kuvsJItJ, 0.0f);
  numBytes += hTable_init(&hTable_N9HZZxsE, 256);
  numBytes += cDelay_init(this, &cDelay_cxNeWQ8e, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iDcdCeLg, 0.0f);
  numBytes += hTable_init(&hTable_CtaVjDDf, 256);
  numBytes += cDelay_init(this, &cDelay_fePuE3H0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TwT0OYQK, 0.0f);
  numBytes += hTable_init(&hTable_cWZLWzF9, 256);
  numBytes += cDelay_init(this, &cDelay_f21ePFva, 0.0f);
  numBytes += cDelay_init(this, &cDelay_44sHUH4L, 0.0f);
  numBytes += hTable_init(&hTable_LzIhUYZh, 256);
  numBytes += cIf_init(&cIf_YziLJCXL, false);
  numBytes += cBinop_init(&cBinop_Hmtmw9em, 0.0f); // __pow
  numBytes += cPack_init(&cPack_3IU7KAdS, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_xUKQRsOz, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_Gg3wX7s6, 22050.0f);
  numBytes += cBinop_init(&cBinop_Yl9IzLXJ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Vi60KykZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_V8uZMcez, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mP0CCXDG, 95.0f);
  numBytes += cVar_init_f(&cVar_4visTvZD, 90.0f);
  numBytes += cVar_init_f(&cVar_wS6Sat5f, 6000.0f);
  numBytes += cVar_init_f(&cVar_zG44W7DL, 60.0f);
  numBytes += cIf_init(&cIf_MzljrOhT, false);
  numBytes += cTabhead_init(&cTabhead_RgoFn4yl, &hTable_QS6oRB0W);
  numBytes += cVar_init_s(&cVar_Kzxz6EMx, "del-1130-ref6");
  numBytes += cDelay_init(this, &cDelay_SRvEW4Xq, 13.645f);
  numBytes += cDelay_init(this, &cDelay_kneQ2NyS, 0.0f);
  numBytes += cBinop_init(&cBinop_9fzbfx9C, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_6VrGXSPf, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Eqhh9l1N, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zP5hhZJJ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_wlLd6yyI, 0.0f);
  numBytes += cDelay_init(this, &cDelay_QurGnv8D, 0.0f);
  numBytes += hTable_init(&hTable_QS6oRB0W, 256);
  numBytes += cTabhead_init(&cTabhead_5zleY9V1, &hTable_0HOxNfI7);
  numBytes += cVar_init_s(&cVar_EbrPn0lj, "del-1130-ref5");
  numBytes += cDelay_init(this, &cDelay_CnIZR3RP, 16.364f);
  numBytes += cDelay_init(this, &cDelay_rOyxK6g1, 0.0f);
  numBytes += cBinop_init(&cBinop_HtY283V1, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_dp8XddFN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_e40qFHnd, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_WOHJcVPM, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_csNPcvw6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_wxxi4WE2, 0.0f);
  numBytes += hTable_init(&hTable_0HOxNfI7, 256);
  numBytes += cTabhead_init(&cTabhead_dpeliT6G, &hTable_SNZe3goA);
  numBytes += cVar_init_s(&cVar_ukDOVf2S, "del-1130-ref4");
  numBytes += cDelay_init(this, &cDelay_08XaGH1s, 19.392f);
  numBytes += cDelay_init(this, &cDelay_VhNB35ln, 0.0f);
  numBytes += cBinop_init(&cBinop_AdJ7gHlo, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_gf1O6YjE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ka64d9ND, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_RTFEf7wm, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_65DPaNYR, 0.0f);
  numBytes += cDelay_init(this, &cDelay_amSaCWvP, 0.0f);
  numBytes += hTable_init(&hTable_SNZe3goA, 256);
  numBytes += cTabhead_init(&cTabhead_EZOzVat6, &hTable_H4gx4UDe);
  numBytes += cVar_init_s(&cVar_CQcLsCfj, "del-1130-ref3");
  numBytes += cDelay_init(this, &cDelay_3Z19Lses, 25.796f);
  numBytes += cDelay_init(this, &cDelay_e0q8rcyt, 0.0f);
  numBytes += cBinop_init(&cBinop_k9Dzpngh, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_ftt8mzKN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Rl9xNTgB, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_mcqiaPf9, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_bZohRPp4, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CS3V4JCF, 0.0f);
  numBytes += hTable_init(&hTable_H4gx4UDe, 256);
  numBytes += cTabhead_init(&cTabhead_6l2AfMcQ, &hTable_QyEdTLTC);
  numBytes += cVar_init_s(&cVar_Ta4avafL, "del-1130-ref2");
  numBytes += cDelay_init(this, &cDelay_Q0TO7Wu2, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_p3f0znUi, 0.0f);
  numBytes += cBinop_init(&cBinop_IskQbfAR, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_kFzv1wYG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_hx96AGLk, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_rLO6Wf6V, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_S9AxcHtb, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FRKS9Rux, 0.0f);
  numBytes += hTable_init(&hTable_QyEdTLTC, 256);
  numBytes += cTabhead_init(&cTabhead_ycEFOiMW, &hTable_edoVP1Zx);
  numBytes += cVar_init_s(&cVar_ZBBMvkxm, "del-1130-ref1");
  numBytes += cDelay_init(this, &cDelay_pjoII6rT, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_avKGsGP2, 0.0f);
  numBytes += cBinop_init(&cBinop_FIaNk7Df, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_9qO1I8gT, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_oK9qJkE3, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_LiR6s60q, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_mWQlOlS9, 0.0f);
  numBytes += cDelay_init(this, &cDelay_sJc0lShQ, 0.0f);
  numBytes += hTable_init(&hTable_edoVP1Zx, 256);
  numBytes += cVar_init_f(&cVar_eIluss7d, 0.0f);
  numBytes += cVar_init_f(&cVar_B3ivIb7A, 0.0f);
  numBytes += cPack_init(&cPack_54xl4frO, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_wzvDFJQl, 22050.0f);
  numBytes += cBinop_init(&cBinop_oOukCmwi, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_aA9uIeCY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VPtWp3dg, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kTNyIV3i, 22050.0f);
  numBytes += cBinop_init(&cBinop_op6eVGUZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fXOfthC0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aMasXeyY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_P08ow6rl, 22050.0f);
  numBytes += cBinop_init(&cBinop_GTW9ymOj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_M0Ov1nfT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rBmWDtRe, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_GQU6qCzK, 50.0f);
  numBytes += cVar_init_f(&cVar_KsSslCDR, 0.0f);
  numBytes += cVar_init_f(&cVar_GjZgFfXS, 12.0f);
  numBytes += cVar_init_s(&cVar_MqEjonNT, "floatatom");
  numBytes += cPack_init(&cPack_PrhhJfXl, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_DqdwQPVg, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_XPBRfSBb, "floatatom");
  numBytes += cDelay_init(this, &cDelay_nDo88GqF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_uqLsNmNL, 0.0f);
  numBytes += hTable_init(&hTable_URmk7nqK, 256);
  numBytes += cVar_init_s(&cVar_VbxWM3Un, "del-1235-del");
  numBytes += sVarf_init(&sVarf_nVlwjyvd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mMzD57Sg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VdNxmPuz, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_0ge6cK5G, "del-1235-del");
  numBytes += sVarf_init(&sVarf_cgXsj42x, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gEo7sCCx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ogkZbUw8, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_MUQhChzG, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_pU1yHqHv, 4720.0f);
  numBytes += cBinop_init(&cBinop_xQimIlqD, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_KvR0fcp4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GPWWp0o2, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_SHGAn4qe, 4720.0f);
  numBytes += cBinop_init(&cBinop_pkMZtSPb, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_v4Sidap8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ay4de1yY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_e7d3Klab, 4720.0f);
  numBytes += cBinop_init(&cBinop_aacg8GHP, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_BVPHV3Mp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jdt52v7I, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_54QA777q, 1.0f);
  numBytes += cIf_init(&cIf_TC9Y0Qof, false);
  numBytes += sVarf_init(&sVarf_NGNUt5Ug, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eVXfaLfw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WabvFs7s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GXfAEF6D, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_W99TCZJQ, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_oXdYeowc, &hTable_LJrCyPE0);
  numBytes += cVar_init_s(&cVar_8WtLDrD5, "del-1298-del1");
  numBytes += cDelay_init(this, &cDelay_eHYhhKKg, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_8tZIVVF2, 0.0f);
  numBytes += cBinop_init(&cBinop_Ne9FboRm, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_vzS0iUdQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_R2O5OqeP, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_klSqAQ66, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_zAsgvHiv, &hTable_LO77Vyhx);
  numBytes += cVar_init_s(&cVar_aBxFiuMC, "del-1298-del2");
  numBytes += cDelay_init(this, &cDelay_giVG6AVS, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_MwNI8b9s, 0.0f);
  numBytes += cBinop_init(&cBinop_cJemqPTZ, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_0u3jrGcI, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xAhPyUg1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_MpAAlloE, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_oOxd6kPi, &hTable_u47NZ5VP);
  numBytes += cVar_init_s(&cVar_k8YLpKz9, "del-1298-del3");
  numBytes += cDelay_init(this, &cDelay_dSq9Oam3, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_AQpsWmmN, 0.0f);
  numBytes += cBinop_init(&cBinop_c5W9hCVf, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_qy2H4c5Q, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_HDZvLvQv, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_A5bUfx6f, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_YABkOIom, &hTable_QRmVDbhG);
  numBytes += cVar_init_s(&cVar_mq7ADqS6, "del-1298-del4");
  numBytes += cDelay_init(this, &cDelay_q1R8izNI, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_n5OjBVlS, 0.0f);
  numBytes += cBinop_init(&cBinop_8mkGw3RD, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_z1lmnIS9, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_DdEY7gwH, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_q3ZzgX5v, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_wz0MoRzS, 0.0f);
  numBytes += cDelay_init(this, &cDelay_yjaFIf2W, 0.0f);
  numBytes += hTable_init(&hTable_LJrCyPE0, 256);
  numBytes += cDelay_init(this, &cDelay_Ng2BfBzc, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OLWxlg7A, 0.0f);
  numBytes += hTable_init(&hTable_LO77Vyhx, 256);
  numBytes += cDelay_init(this, &cDelay_awPbf4ro, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Mb1Y9ILA, 0.0f);
  numBytes += hTable_init(&hTable_u47NZ5VP, 256);
  numBytes += cDelay_init(this, &cDelay_0EoE3o35, 0.0f);
  numBytes += cDelay_init(this, &cDelay_j93aWClY, 0.0f);
  numBytes += hTable_init(&hTable_QRmVDbhG, 256);
  numBytes += cIf_init(&cIf_au3E9o1j, false);
  numBytes += cBinop_init(&cBinop_zJUK0lc2, 0.0f); // __pow
  numBytes += cPack_init(&cPack_gJ8v7VI2, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_shm7US60, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_yZNhN76s, 22050.0f);
  numBytes += cBinop_init(&cBinop_WDBMQDFw, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_0SaaZjP1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UInjfCfV, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_71N7Wq23, 100.0f);
  numBytes += cVar_init_f(&cVar_pcFIlYhK, 95.0f);
  numBytes += cVar_init_f(&cVar_tdXGgu5C, 14400.0f);
  numBytes += cVar_init_f(&cVar_B3krmBek, 60.0f);
  numBytes += cIf_init(&cIf_CkBgGTS0, false);
  numBytes += cTabhead_init(&cTabhead_bhG4IPjP, &hTable_eeTIy2k1);
  numBytes += cVar_init_s(&cVar_8yeLigtZ, "del-1298-ref6");
  numBytes += cDelay_init(this, &cDelay_p2ny8zTN, 13.645f);
  numBytes += cDelay_init(this, &cDelay_AhThLAke, 0.0f);
  numBytes += cBinop_init(&cBinop_nlQ7kOrx, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_ujR6nGYj, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_KqHwgdBP, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_yvFtGZPc, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_K1GbzwF6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_7KEKnfRL, 0.0f);
  numBytes += hTable_init(&hTable_eeTIy2k1, 256);
  numBytes += cTabhead_init(&cTabhead_HMwr6AVF, &hTable_us6eLSN0);
  numBytes += cVar_init_s(&cVar_KfpeR1u6, "del-1298-ref5");
  numBytes += cDelay_init(this, &cDelay_tnGHJCoC, 16.364f);
  numBytes += cDelay_init(this, &cDelay_oUayEQRR, 0.0f);
  numBytes += cBinop_init(&cBinop_ELsWnrrK, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_oefayF2x, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pykBSg52, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_TSTA5wxO, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_mVkHqPPW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8WcdXQdp, 0.0f);
  numBytes += hTable_init(&hTable_us6eLSN0, 256);
  numBytes += cTabhead_init(&cTabhead_ewq6WUqS, &hTable_RcY0yvWg);
  numBytes += cVar_init_s(&cVar_YdcuhJ0D, "del-1298-ref4");
  numBytes += cDelay_init(this, &cDelay_odnu7puu, 19.392f);
  numBytes += cDelay_init(this, &cDelay_L8vGh30Y, 0.0f);
  numBytes += cBinop_init(&cBinop_CE9CgehL, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_yylCC68p, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_1Kj53k11, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_KJv4iSOw, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_BlHMw3Jc, 0.0f);
  numBytes += cDelay_init(this, &cDelay_auAfBh3L, 0.0f);
  numBytes += hTable_init(&hTable_RcY0yvWg, 256);
  numBytes += cTabhead_init(&cTabhead_YkMqdHnJ, &hTable_aDFVpMco);
  numBytes += cVar_init_s(&cVar_Oze4lTOM, "del-1298-ref3");
  numBytes += cDelay_init(this, &cDelay_fvtHBbHF, 25.796f);
  numBytes += cDelay_init(this, &cDelay_bQmlleNA, 0.0f);
  numBytes += cBinop_init(&cBinop_xRn8rmxC, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_Wqj2ROo5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_THGEC9xY, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_4HB9p6y6, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_xjtpk8uP, 0.0f);
  numBytes += cDelay_init(this, &cDelay_RadWTlZd, 0.0f);
  numBytes += hTable_init(&hTable_aDFVpMco, 256);
  numBytes += cTabhead_init(&cTabhead_EVlkGzkC, &hTable_plbZ7cRO);
  numBytes += cVar_init_s(&cVar_EDmWy7Rk, "del-1298-ref2");
  numBytes += cDelay_init(this, &cDelay_qTGEWcIO, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_E2PUpEkj, 0.0f);
  numBytes += cBinop_init(&cBinop_WmI5OQgI, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_Joe51ZvW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_707ATwk3, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_4Me6p19z, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Fnvyd03O, 0.0f);
  numBytes += cDelay_init(this, &cDelay_NiNZJrp9, 0.0f);
  numBytes += hTable_init(&hTable_plbZ7cRO, 256);
  numBytes += cTabhead_init(&cTabhead_X2RYRf3W, &hTable_O7V4a1Mb);
  numBytes += cVar_init_s(&cVar_oSZotN2e, "del-1298-ref1");
  numBytes += cDelay_init(this, &cDelay_fA0UQEmC, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_x8OIVpjg, 0.0f);
  numBytes += cBinop_init(&cBinop_orkkOlom, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_KHl4n7sf, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_O6g8I43V, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_aIt6ADMS, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_hacfPVPV, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rlujc4uw, 0.0f);
  numBytes += hTable_init(&hTable_O7V4a1Mb, 256);
  numBytes += cVar_init_f(&cVar_yp8tEV7I, 0.0f);
  numBytes += cVar_init_f(&cVar_v632NFJS, 0.0f);
  numBytes += cPack_init(&cPack_UO5cZDeG, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_nWojawMq, 22050.0f);
  numBytes += cBinop_init(&cBinop_VaNG037W, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_EPam9V9c, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hJolvPgs, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_91ipxeix, 22050.0f);
  numBytes += cBinop_init(&cBinop_OC09kgSZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8K8Duhci, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hWrKq9xo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Csrnrx4g, 22050.0f);
  numBytes += cBinop_init(&cBinop_Bt32WKnP, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_PA0Xp42U, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nFdICq5e, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_scFS7rvD, "del-1397-del1");
  numBytes += sVarf_init(&sVarf_6LKgDjQg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_CO3ZVPnp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_be8xJBFC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_g3AY7716, 10000.0f);
  numBytes += cBinop_init(&cBinop_1DLdzFV7, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_LZsKZ7dZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TTnqFH6X, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8qtcMVtS, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9lofG6oX, 10.0f);
  numBytes += cBinop_init(&cBinop_QzN595pi, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_DNyToRCo, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_3lSQyMMC, "floatatom");
  numBytes += sVarf_init(&sVarf_8zPLjoQc, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_rlyYVu0d, 0.0f);
  numBytes += cDelay_init(this, &cDelay_V1N2L3ff, 0.0f);
  numBytes += hTable_init(&hTable_pu0SzX3H, 256);
  numBytes += sVarf_init(&sVarf_spK6gjBk, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_zgGZN6z8, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_48zL3RF4, -631330568);
  numBytes += cSlice_init(&cSlice_0nDtdAwC, 1, 1);
  numBytes += cBinop_init(&cBinop_u2Yni7yZ, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_ThHSouTJ, -872106860);
  numBytes += cSlice_init(&cSlice_7tdyfwLL, 1, 1);
  numBytes += cSlice_init(&cSlice_eM5jN6JG, 1, 1);
  numBytes += cSlice_init(&cSlice_aZfbopva, 0, 1);
  numBytes += cPack_init(&cPack_RUePdS9W, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_IHMwtslY, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_RkkYb3Tl, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TBTaxoqE, 25.0f);
  numBytes += cVar_init_f(&cVar_Su3sbATu, 0.0f);
  numBytes += sVarf_init(&sVarf_67JIqCl7, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_gu6vDZ1z, "crotale");
  numBytes += cSlice_init(&cSlice_9LhRvvsK, 1, 1);
  numBytes += sVarf_init(&sVarf_lUTpKDPn, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_p5nLYLjc, 0.0f);
  numBytes += cVar_init_f(&cVar_7dBvNyLG, 1.0f);
  numBytes += cIf_init(&cIf_lAB9uDtR, false);
  numBytes += cVar_init_f(&cVar_kqZ98AUE, 1.0f);
  numBytes += cVar_init_f(&cVar_RJfd049d, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XYoMzWQA, 2.0f);
  numBytes += cPack_init(&cPack_zWanMZGz, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vXXQolW1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_mCmAGTwm, 2.0f);
  numBytes += cPack_init(&cPack_8X87rs1e, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_6z0di25y, 2, 0.0f, -220500000.0f);
  numBytes += cPack_init(&cPack_XPu4sCbD, 2, 0.0f, 220500000.0f);
  numBytes += cPack_init(&cPack_b0MnaHtg, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_gaF8cQvI, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_918OYDxm, 0.0f);
  numBytes += cVar_init_f(&cVar_GnjBeYxt, 1.0f);
  numBytes += cPack_init(&cPack_P8STOGKQ, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_SPFsJJpt, 1, 1);
  numBytes += cSlice_init(&cSlice_W6ngLFPD, 0, 1);
  numBytes += cSlice_init(&cSlice_2JJ9PHgg, 1, 1);
  numBytes += cSlice_init(&cSlice_yhoml6Su, 0, 1);
  numBytes += cBinop_init(&cBinop_KMyVXarS, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_bl7JRjYx, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_RsVHGeaR, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_mDEKTdKF, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Y4qDKaQM, 22.05f); // __mul
  numBytes += cSlice_init(&cSlice_BAcNX67s, 5, 1);
  numBytes += cSlice_init(&cSlice_ewD5Z4Wq, 4, 1);
  numBytes += cSlice_init(&cSlice_OJ2lH8T5, 3, 1);
  numBytes += cSlice_init(&cSlice_LctWIVdM, 2, 1);
  numBytes += cSlice_init(&cSlice_phOIDWsR, 1, 1);
  numBytes += cSlice_init(&cSlice_IdrThWfS, 0, 1);
  numBytes += cSlice_init(&cSlice_rnwZzIsZ, 1, 1);
  numBytes += cSlice_init(&cSlice_7It9OtHZ, 0, 1);
  numBytes += cPack_init(&cPack_3fOD3mIE, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_pp01XbA2, "floatatom");
  numBytes += cSlice_init(&cSlice_3CNNKj1f, 1, 1);
  numBytes += cSlice_init(&cSlice_zkRf0knm, 0, 1);
  numBytes += cBinop_init(&cBinop_h7mgJUAH, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_CdGKJE3h, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_CRpRDZp4, 1, 1);
  numBytes += cSlice_init(&cSlice_wQ88IDIH, 0, 1);
  numBytes += cVar_init_f(&cVar_7G7dgBiJ, 0.0f);
  numBytes += cVar_init_f(&cVar_dhBNIU1O, 1.0f);
  numBytes += cPack_init(&cPack_utahBbbx, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_cPou3RBd, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_spT2TXtR, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_xH2Mgc0t, -817264342);
  numBytes += cSlice_init(&cSlice_ZexMb6rw, 1, 1);
  numBytes += cBinop_init(&cBinop_S95kbzCu, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_fKI6Pamx, 1751121986);
  numBytes += cSlice_init(&cSlice_QAVtC7su, 1, 1);
  numBytes += cSlice_init(&cSlice_MDZOpyys, 1, 1);
  numBytes += cSlice_init(&cSlice_JfXcUTAR, 0, 1);
  numBytes += cPack_init(&cPack_qCyOjIsj, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_cQSHXkBn, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_UFwJC2AF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3eQmorm7, 25.0f);
  numBytes += cVar_init_f(&cVar_ho34Mnea, 0.0f);
  numBytes += sVarf_init(&sVarf_XnMFYCoH, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_6GqMDbR5, "crotale");
  numBytes += cSlice_init(&cSlice_TW7QmFpq, 1, 1);
  numBytes += sVarf_init(&sVarf_CtDBqqUJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_APX1fTyL, 0.0f);
  numBytes += cVar_init_f(&cVar_DlMyC2zp, 1.0f);
  numBytes += cIf_init(&cIf_MT3h1Ajo, false);
  numBytes += cVar_init_f(&cVar_A13HfCFZ, 1.0f);
  numBytes += cVar_init_f(&cVar_b5hN6RWb, 0.0f);
  numBytes += cDelay_init(this, &cDelay_5yN9BFkt, 2.0f);
  numBytes += cPack_init(&cPack_OD7kXYJD, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UKfe1DLT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ffh97vJ9, 2.0f);
  numBytes += cPack_init(&cPack_dzBc4XHD, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_5dshUpVc, 2, 0.0f, -220500000.0f);
  numBytes += cPack_init(&cPack_ee6eTebv, 2, 0.0f, 220500000.0f);
  numBytes += cPack_init(&cPack_RBLiYKpB, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_oNCvUW49, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_Fxcu6da5, 0.0f);
  numBytes += cVar_init_f(&cVar_Mk8KhKDO, 1.0f);
  numBytes += cPack_init(&cPack_zsICs8u6, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_7iCymHbs, 1, 1);
  numBytes += cSlice_init(&cSlice_ezVM2Yf0, 0, 1);
  numBytes += cSlice_init(&cSlice_Q8seBuOo, 1, 1);
  numBytes += cSlice_init(&cSlice_kb8zdKXb, 0, 1);
  numBytes += cBinop_init(&cBinop_wo5KE4Hd, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ynD61rHp, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_ZLSsrnkU, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_kfcBUUUl, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_AeIxU2zU, 22.05f); // __mul
  numBytes += cSlice_init(&cSlice_CJvzDEls, 5, 1);
  numBytes += cSlice_init(&cSlice_g6OogfSM, 4, 1);
  numBytes += cSlice_init(&cSlice_o61ig3S3, 3, 1);
  numBytes += cSlice_init(&cSlice_EWIt3Ebo, 2, 1);
  numBytes += cSlice_init(&cSlice_j90nH2L4, 1, 1);
  numBytes += cSlice_init(&cSlice_OAVJRPFT, 0, 1);
  numBytes += cSlice_init(&cSlice_sksRBotf, 1, 1);
  numBytes += cSlice_init(&cSlice_0jMafJuY, 0, 1);
  numBytes += cPack_init(&cPack_OXQgGONw, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_q1kMhDET, "floatatom");
  numBytes += cSlice_init(&cSlice_TWdvCnmO, 1, 1);
  numBytes += cSlice_init(&cSlice_EzlEwdTV, 0, 1);
  numBytes += cBinop_init(&cBinop_ftnyEqyz, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_QyEBsvgc, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_Wp2mYhT7, 1, 1);
  numBytes += cSlice_init(&cSlice_RnNfO26i, 0, 1);
  numBytes += cVar_init_f(&cVar_wbs4SlV4, 0.0f);
  numBytes += cVar_init_f(&cVar_YbCCcJ3M, 1.0f);
  numBytes += cPack_init(&cPack_5v1pYC5d, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_MKrjwKu4, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_EUY59TKI, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_ERKEF5Kk, -1403421246);
  numBytes += cSlice_init(&cSlice_f4qbtQQN, 1, 1);
  numBytes += cBinop_init(&cBinop_OOTg5wIx, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_RWD94MNW, -1988040482);
  numBytes += cSlice_init(&cSlice_pGSTU1Zs, 1, 1);
  numBytes += cSlice_init(&cSlice_SvC5V0D8, 1, 1);
  numBytes += cSlice_init(&cSlice_d7PB4q7q, 0, 1);
  numBytes += cPack_init(&cPack_PDFXXZJI, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_32REBZvJ, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_qhvrbskB, 0.0f);
  numBytes += cDelay_init(this, &cDelay_AYzVobbb, 25.0f);
  numBytes += cVar_init_f(&cVar_JLkvDOWY, 0.0f);
  numBytes += sVarf_init(&sVarf_r3rZgjy1, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_wp4dYXVo, "crotale");
  numBytes += cSlice_init(&cSlice_LFxe68t4, 1, 1);
  numBytes += sVarf_init(&sVarf_QaEqDgic, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ZvJnxNl8, 0.0f);
  numBytes += cVar_init_f(&cVar_rNz7A7wg, 1.0f);
  numBytes += cIf_init(&cIf_ViucENg3, false);
  numBytes += cVar_init_f(&cVar_Xsi3TsU8, 1.0f);
  numBytes += cVar_init_f(&cVar_pnmxZ600, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WyYb5taZ, 2.0f);
  numBytes += cPack_init(&cPack_b5ZsnmkP, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8DNjMZRu, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CNeY4TLg, 2.0f);
  numBytes += cPack_init(&cPack_AxeXEpqS, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_LkrizacB, 2, 0.0f, -220500000.0f);
  numBytes += cPack_init(&cPack_T0oOdRGo, 2, 0.0f, 220500000.0f);
  numBytes += cPack_init(&cPack_zHFw0NDn, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_HpbbdZWo, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_hziYS8I6, 0.0f);
  numBytes += cVar_init_f(&cVar_te3YvAnU, 1.0f);
  numBytes += cPack_init(&cPack_BeD7LQxu, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_9n1mUQuT, 1, 1);
  numBytes += cSlice_init(&cSlice_ix3nr9fH, 0, 1);
  numBytes += cSlice_init(&cSlice_MA9nUJ9u, 1, 1);
  numBytes += cSlice_init(&cSlice_WqRO7KF5, 0, 1);
  numBytes += cBinop_init(&cBinop_QYkKjzvO, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_PBVQ9tiP, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_yb4a3e6G, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_EKm6bOhP, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ce4cstnk, 22.05f); // __mul
  numBytes += cSlice_init(&cSlice_YMsz2j2j, 5, 1);
  numBytes += cSlice_init(&cSlice_1Gjqvn7G, 4, 1);
  numBytes += cSlice_init(&cSlice_R0mFhUmq, 3, 1);
  numBytes += cSlice_init(&cSlice_JrJjCzUw, 2, 1);
  numBytes += cSlice_init(&cSlice_pOW8tE6N, 1, 1);
  numBytes += cSlice_init(&cSlice_L06NL0DW, 0, 1);
  numBytes += cSlice_init(&cSlice_goapZnXF, 1, 1);
  numBytes += cSlice_init(&cSlice_mE3B3W7m, 0, 1);
  numBytes += cPack_init(&cPack_1dFy8lgA, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_FteLT3q0, "floatatom");
  numBytes += cSlice_init(&cSlice_zjhEL7va, 1, 1);
  numBytes += cSlice_init(&cSlice_Lmka0sE3, 0, 1);
  numBytes += cBinop_init(&cBinop_w9lwr62S, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_pmtVXjcT, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_GUMAxy6d, 1, 1);
  numBytes += cSlice_init(&cSlice_1fKaZV7G, 0, 1);
  numBytes += cVar_init_f(&cVar_EcFkdkbq, 0.0f);
  numBytes += cVar_init_f(&cVar_q31aMoHN, 1.0f);
  numBytes += cPack_init(&cPack_SXe6wWcW, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_RMs4CMz5, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_p8PcLyHi, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_QoxF3UTh, 1544889202);
  numBytes += cSlice_init(&cSlice_4LWqfyQW, 1, 1);
  numBytes += cBinop_init(&cBinop_CKHIIFyO, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_KUykdbb5, -1049751573);
  numBytes += cSlice_init(&cSlice_aPGcb6h0, 1, 1);
  numBytes += cSlice_init(&cSlice_T1hjmdea, 1, 1);
  numBytes += cSlice_init(&cSlice_f7rHpMFy, 0, 1);
  numBytes += cPack_init(&cPack_T0TsyQXy, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_znLPaQwS, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_T4l79h2i, 0.0f);
  numBytes += cDelay_init(this, &cDelay_7qe9iIzF, 25.0f);
  numBytes += cVar_init_f(&cVar_pIuALVAb, 0.0f);
  numBytes += sVarf_init(&sVarf_SE2ZC0p6, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_unWpXSBQ, "crotale");
  numBytes += cSlice_init(&cSlice_GtXhuqMl, 1, 1);
  numBytes += sVarf_init(&sVarf_p1s4kfxI, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_54hIyrZW, 0.0f);
  numBytes += cVar_init_f(&cVar_tmqqMjIj, 1.0f);
  numBytes += cIf_init(&cIf_5qQgWBVr, false);
  numBytes += cVar_init_f(&cVar_BVf4r6uW, 1.0f);
  numBytes += cVar_init_f(&cVar_5EwjpZRZ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Vj5dk1vY, 2.0f);
  numBytes += cPack_init(&cPack_CLp5Ywbg, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kox6MMYT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iFcRVfYd, 2.0f);
  numBytes += cPack_init(&cPack_tRUylDK6, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_HDwbrxhj, 2, 0.0f, -220500000.0f);
  numBytes += cPack_init(&cPack_dH0jUzML, 2, 0.0f, 220500000.0f);
  numBytes += cPack_init(&cPack_L71iTcIe, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_wAn4lH4T, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_eJFFl7Nh, 0.0f);
  numBytes += cVar_init_f(&cVar_A0Gd4KF8, 1.0f);
  numBytes += cPack_init(&cPack_3TLR4kXG, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_JgHu2BMp, 1, 1);
  numBytes += cSlice_init(&cSlice_XkN1avUg, 0, 1);
  numBytes += cSlice_init(&cSlice_Fgddjiyw, 1, 1);
  numBytes += cSlice_init(&cSlice_onuiAlXM, 0, 1);
  numBytes += cBinop_init(&cBinop_aWQ0kysT, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Dn5MYU4m, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_4jYl8gHV, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_u2oIDdME, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ibL1XD3A, 22.05f); // __mul
  numBytes += cSlice_init(&cSlice_7yHvYkuz, 5, 1);
  numBytes += cSlice_init(&cSlice_OQhQBMo9, 4, 1);
  numBytes += cSlice_init(&cSlice_eETJquNT, 3, 1);
  numBytes += cSlice_init(&cSlice_XxY6Bq4K, 2, 1);
  numBytes += cSlice_init(&cSlice_cQScPy7Y, 1, 1);
  numBytes += cSlice_init(&cSlice_XhcgkbSb, 0, 1);
  numBytes += cSlice_init(&cSlice_0vxLnYsQ, 1, 1);
  numBytes += cSlice_init(&cSlice_hd5wP8RL, 0, 1);
  numBytes += cPack_init(&cPack_QOHp7e6h, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_x3wUdY5Y, "floatatom");
  numBytes += cSlice_init(&cSlice_NK7sq6y2, 1, 1);
  numBytes += cSlice_init(&cSlice_MfxY7e0e, 0, 1);
  numBytes += cBinop_init(&cBinop_O7k5BnZK, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_ziNm3Og8, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_2JuYc5c4, 1, 1);
  numBytes += cSlice_init(&cSlice_44YthkPZ, 0, 1);
  numBytes += cVar_init_f(&cVar_YbJWKSa6, 0.0f);
  numBytes += cVar_init_f(&cVar_9LE4kzgN, 1.0f);
  numBytes += cPack_init(&cPack_AJnWyUYE, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_4PxdUQBf, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_tnpzxqEn, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_oEr2k5HS, -1952174862);
  numBytes += cSlice_init(&cSlice_6qhcJWga, 1, 1);
  numBytes += cVar_init_f(&cVar_Rd0SjDRB, 98.0f);
  numBytes += cIf_init(&cIf_qVdgm8t1, false);
  numBytes += cBinop_init(&cBinop_uyM3byzB, 0.0f); // __pow
  numBytes += cPack_init(&cPack_ID1mQx0C, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_4wygmsSJ, 0.0f);
  numBytes += cVar_init_f(&cVar_sggg9JiS, 100.0f);
  numBytes += cIf_init(&cIf_RZ22kD3C, false);
  numBytes += cBinop_init(&cBinop_lMv4zNZS, 0.0f); // __pow
  numBytes += cPack_init(&cPack_yms4vt8H, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_DGirUXJQ, 0.0f);
  numBytes += cVar_init_f(&cVar_z07tKiea, 100.0f);
  numBytes += cIf_init(&cIf_DTmrjffS, false);
  numBytes += cBinop_init(&cBinop_ZO9pmCzg, 0.0f); // __pow
  numBytes += cPack_init(&cPack_GGi77jW6, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_PsAqwixX, 0.0f);
  numBytes += cIf_init(&cIf_Wg7WQXvE, false);
  numBytes += cIf_init(&cIf_ZiROSUND, false);
  numBytes += cIf_init(&cIf_BLuYOat1, false);
  numBytes += cVar_init_f(&cVar_gJcvrwSO, 97.0f);
  numBytes += cIf_init(&cIf_OW2CMtnU, false);
  numBytes += cBinop_init(&cBinop_6aMV9qa0, 0.0f); // __pow
  numBytes += cPack_init(&cPack_CQ8NkTyX, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_WEPCuDqP, 0.0f);
  numBytes += cVar_init_f(&cVar_W9w4Qjoo, 97.0f);
  numBytes += cIf_init(&cIf_HCj1THsW, false);
  numBytes += cBinop_init(&cBinop_hNipUThQ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_tWgvs5CU, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_yZClcAdi, 0.0f);
  numBytes += cPack_init(&cPack_e7BB4ZUT, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_XAAZJNJQ, 1, 1);
  numBytes += cSlice_init(&cSlice_SRBC8aR8, 0, 1);
  numBytes += cIf_init(&cIf_ZI82poBx, false);
  numBytes += cIf_init(&cIf_ocgD8iNx, false);
  numBytes += cIf_init(&cIf_HSELf4pY, false);
  numBytes += cSlice_init(&cSlice_Ce75JDUE, 1, 1);
  numBytes += cSlice_init(&cSlice_8nrI9qet, 0, 1);
  numBytes += cVar_init_f(&cVar_YSZvf10A, 0.0f);
  numBytes += cIf_init(&cIf_W7tCa7Tf, false);
  numBytes += cPack_init(&cPack_rIy5axC8, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_jbuP6h83, 1, -1);
  numBytes += cSlice_init(&cSlice_QMLLmUVf, 1, -1);
  numBytes += cSlice_init(&cSlice_zEG5pDYG, 1, -1);
  numBytes += cSlice_init(&cSlice_yJRJ57Na, 1, -1);
  numBytes += cIf_init(&cIf_HpnQNTDW, false);
  numBytes += cVar_init_f(&cVar_kJ7Ul6KH, 1.0f);
  numBytes += cPack_init(&cPack_dmKu2Nlx, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_FSUWNLPy, 0.0f);
  numBytes += cVar_init_f(&cVar_OE4y0x2h, 1.0f);
  numBytes += cPack_init(&cPack_PGHoKb3F, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_5bAJ4Gwm, -1821166720);
  numBytes += cSlice_init(&cSlice_I5MePmB8, 1, 1);
  numBytes += cRandom_init(&cRandom_pRqirSh8, -6969062);
  numBytes += cSlice_init(&cSlice_qlcX1D0F, 1, 1);
  numBytes += cRandom_init(&cRandom_KUCCpq0o, -2074232360);
  numBytes += cSlice_init(&cSlice_e4wVPyYe, 1, 1);
  numBytes += cVar_init_s(&cVar_3pnLqvem, "floatatom");
  numBytes += cVar_init_s(&cVar_r6uVkBK3, "floatatom");
  numBytes += cIf_init(&cIf_xvcztYgg, false);
  numBytes += cVar_init_s(&cVar_jHaueP48, "floatatom");
  numBytes += cBinop_init(&cBinop_oJ6HpPLP, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_lFsL0tKR, 72.07f); // __sub
  numBytes += cSlice_init(&cSlice_jjvn5w1N, 1, -1);
  numBytes += cSlice_init(&cSlice_TAjhrge3, 1, -1);
  numBytes += cBinop_init(&cBinop_hBDf2ffS, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_t77GhehL, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_qx98ABq7, 1, 1);
  numBytes += cSlice_init(&cSlice_TWupl5Xj, 0, 1);
  numBytes += cPack_init(&cPack_mSoL7sKG, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_X4SJ8SNX, 0.0f);
  numBytes += cVar_init_f(&cVar_tadTNEgE, 10.0f);
  numBytes += cPack_init(&cPack_uhsJsrqV, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_Hutjys9I, 1, 1);
  numBytes += cSlice_init(&cSlice_bd7e5PtO, 0, 1);
  numBytes += cBinop_init(&cBinop_xDQhsZnq, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_MGi2RJZG, 22.05f); // __mul
  numBytes += cVar_init_f(&cVar_JvmV5DKq, 5.0f);
  numBytes += cBinop_init(&cBinop_VlrrqRAt, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_zLskrljh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_15LJbtGD, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_KOoshTHO, 0.0f);
  numBytes += cIf_init(&cIf_3amOScd7, false);
  numBytes += cSlice_init(&cSlice_z0ZORoXZ, 1, 1);
  numBytes += cSlice_init(&cSlice_JOdwLmRC, 0, 1);
  numBytes += cVar_init_s(&cVar_ezoJ3413, "crotale");
  numBytes += cSlice_init(&cSlice_ZDn7UXZq, 1, 1);
  numBytes += sVarf_init(&sVarf_fhR0eurG, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_mQQApdpN, "crotale");
  numBytes += cSlice_init(&cSlice_esEtEGYb, 1, 1);
  numBytes += sVarf_init(&sVarf_aXEGBLzW, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_EVXhtMwW, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_nJgaRHXX, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_NRJeV8Mi, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_65wmEn4P, 5.0f);
  numBytes += cBinop_init(&cBinop_eK8SfPWv, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_tKsrHMxP, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_ACsSND43, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_VVoDx1Va, 220.5f); // __mul
  numBytes += sVarf_init(&sVarf_ycrCFRyr, 0.0f, 0.0f, false);
  numBytes += hTable_init(&hTable_KYMoiAT0, 200000);
  numBytes += hTable_init(&hTable_mkrY4Gmu, 200000);
  numBytes += hTable_init(&hTable_KKVl99Xc, 200000);
  numBytes += hTable_init(&hTable_oFUFd8F8, 200000);
  numBytes += hTable_init(&hTable_uDeQDSoQ, 200000);
  numBytes += hTable_init(&hTable_1Rgfe6BM, 200000);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_SoundScraper::~Heavy_SoundScraper() {
  cPack_free(&cPack_rxYXvI9Y);
  cPack_free(&cPack_zTveEpUe);
  cPack_free(&cPack_qwbWlHTJ);
  hTable_free(&hTable_0pw5qmv4);
  hTable_free(&hTable_pIje5WwM);
  cPack_free(&cPack_djmdksop);
  cPack_free(&cPack_OMpWVvNb);
  cPack_free(&cPack_5IOyDtUv);
  hTable_free(&hTable_N9HZZxsE);
  hTable_free(&hTable_CtaVjDDf);
  hTable_free(&hTable_cWZLWzF9);
  hTable_free(&hTable_LzIhUYZh);
  cPack_free(&cPack_3IU7KAdS);
  cPack_free(&cPack_xUKQRsOz);
  hTable_free(&hTable_QS6oRB0W);
  hTable_free(&hTable_0HOxNfI7);
  hTable_free(&hTable_SNZe3goA);
  hTable_free(&hTable_H4gx4UDe);
  hTable_free(&hTable_QyEdTLTC);
  hTable_free(&hTable_edoVP1Zx);
  cPack_free(&cPack_54xl4frO);
  cPack_free(&cPack_PrhhJfXl);
  cPack_free(&cPack_DqdwQPVg);
  hTable_free(&hTable_URmk7nqK);
  hTable_free(&hTable_LJrCyPE0);
  hTable_free(&hTable_LO77Vyhx);
  hTable_free(&hTable_u47NZ5VP);
  hTable_free(&hTable_QRmVDbhG);
  cPack_free(&cPack_gJ8v7VI2);
  cPack_free(&cPack_shm7US60);
  hTable_free(&hTable_eeTIy2k1);
  hTable_free(&hTable_us6eLSN0);
  hTable_free(&hTable_RcY0yvWg);
  hTable_free(&hTable_aDFVpMco);
  hTable_free(&hTable_plbZ7cRO);
  hTable_free(&hTable_O7V4a1Mb);
  cPack_free(&cPack_UO5cZDeG);
  hTable_free(&hTable_pu0SzX3H);
  cPack_free(&cPack_zgGZN6z8);
  cPack_free(&cPack_RUePdS9W);
  cPack_free(&cPack_IHMwtslY);
  cPack_free(&cPack_zWanMZGz);
  cPack_free(&cPack_8X87rs1e);
  cPack_free(&cPack_6z0di25y);
  cPack_free(&cPack_XPu4sCbD);
  cPack_free(&cPack_b0MnaHtg);
  cPack_free(&cPack_gaF8cQvI);
  cPack_free(&cPack_P8STOGKQ);
  cPack_free(&cPack_3fOD3mIE);
  cPack_free(&cPack_utahBbbx);
  cPack_free(&cPack_qCyOjIsj);
  cPack_free(&cPack_cQSHXkBn);
  cPack_free(&cPack_OD7kXYJD);
  cPack_free(&cPack_dzBc4XHD);
  cPack_free(&cPack_5dshUpVc);
  cPack_free(&cPack_ee6eTebv);
  cPack_free(&cPack_RBLiYKpB);
  cPack_free(&cPack_oNCvUW49);
  cPack_free(&cPack_zsICs8u6);
  cPack_free(&cPack_OXQgGONw);
  cPack_free(&cPack_5v1pYC5d);
  cPack_free(&cPack_PDFXXZJI);
  cPack_free(&cPack_32REBZvJ);
  cPack_free(&cPack_b5ZsnmkP);
  cPack_free(&cPack_AxeXEpqS);
  cPack_free(&cPack_LkrizacB);
  cPack_free(&cPack_T0oOdRGo);
  cPack_free(&cPack_zHFw0NDn);
  cPack_free(&cPack_HpbbdZWo);
  cPack_free(&cPack_BeD7LQxu);
  cPack_free(&cPack_1dFy8lgA);
  cPack_free(&cPack_SXe6wWcW);
  cPack_free(&cPack_T0TsyQXy);
  cPack_free(&cPack_znLPaQwS);
  cPack_free(&cPack_CLp5Ywbg);
  cPack_free(&cPack_tRUylDK6);
  cPack_free(&cPack_HDwbrxhj);
  cPack_free(&cPack_dH0jUzML);
  cPack_free(&cPack_L71iTcIe);
  cPack_free(&cPack_wAn4lH4T);
  cPack_free(&cPack_3TLR4kXG);
  cPack_free(&cPack_QOHp7e6h);
  cPack_free(&cPack_AJnWyUYE);
  cPack_free(&cPack_ID1mQx0C);
  cPack_free(&cPack_yms4vt8H);
  cPack_free(&cPack_GGi77jW6);
  cPack_free(&cPack_CQ8NkTyX);
  cPack_free(&cPack_tWgvs5CU);
  cPack_free(&cPack_e7BB4ZUT);
  cPack_free(&cPack_rIy5axC8);
  cPack_free(&cPack_dmKu2Nlx);
  cPack_free(&cPack_PGHoKb3F);
  cPack_free(&cPack_mSoL7sKG);
  cPack_free(&cPack_uhsJsrqV);
  hTable_free(&hTable_KYMoiAT0);
  hTable_free(&hTable_mkrY4Gmu);
  hTable_free(&hTable_KKVl99Xc);
  hTable_free(&hTable_oFUFd8F8);
  hTable_free(&hTable_uDeQDSoQ);
  hTable_free(&hTable_1Rgfe6BM);
}

HvTable *Heavy_SoundScraper::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x436A0550: return &hTable_0pw5qmv4; // del-1040-del
    case 0x7F066481: return &hTable_pIje5WwM; // del-1069-del1
    case 0x2FD71841: return &hTable_N9HZZxsE; // del-1130-del1
    case 0x4F984AEF: return &hTable_CtaVjDDf; // del-1130-del2
    case 0xF31DED20: return &hTable_cWZLWzF9; // del-1130-del3
    case 0x43D20BD9: return &hTable_LzIhUYZh; // del-1130-del4
    case 0x1792E9A6: return &hTable_QS6oRB0W; // del-1130-ref6
    case 0xB84BF7D2: return &hTable_0HOxNfI7; // del-1130-ref5
    case 0x695825B7: return &hTable_SNZe3goA; // del-1130-ref4
    case 0x460C1764: return &hTable_H4gx4UDe; // del-1130-ref3
    case 0x46A969C7: return &hTable_QyEdTLTC; // del-1130-ref2
    case 0xC03F1F97: return &hTable_edoVP1Zx; // del-1130-ref1
    case 0xBB7C9AAB: return &hTable_URmk7nqK; // del-1235-del
    case 0xB8603A7: return &hTable_LJrCyPE0; // del-1298-del1
    case 0xFB383A6C: return &hTable_LO77Vyhx; // del-1298-del2
    case 0x4DD59F74: return &hTable_u47NZ5VP; // del-1298-del3
    case 0xEED55635: return &hTable_QRmVDbhG; // del-1298-del4
    case 0x480E74AD: return &hTable_eeTIy2k1; // del-1298-ref6
    case 0x19B4711D: return &hTable_us6eLSN0; // del-1298-ref5
    case 0xC655A199: return &hTable_RcY0yvWg; // del-1298-ref4
    case 0xB6FE6212: return &hTable_aDFVpMco; // del-1298-ref3
    case 0x6E3EF8B1: return &hTable_plbZ7cRO; // del-1298-ref2
    case 0x5D7D44A3: return &hTable_O7V4a1Mb; // del-1298-ref1
    case 0xF89A3E8D: return &hTable_pu0SzX3H; // del-1397-del1
    case 0x9BCAD111: return &hTable_KYMoiAT0; // bowl
    case 0x782CD90: return &hTable_mkrY4Gmu; // crotale
    case 0x53C964B5: return &hTable_KKVl99Xc; // gong
    case 0xAC13AE99: return &hTable_oFUFd8F8; // marimba
    case 0x1FD931DF: return &hTable_uDeQDSoQ; // xylo
    case 0x6F52CA74: return &hTable_1Rgfe6BM; // almglocken
    default: return nullptr;
  }
}

void Heavy_SoundScraper::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE0749F2A: { // 1029-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WVVjU2J2_sendMessage);
      break;
    }
    case 0x560204A8: { // 1029-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uYvfXJ9t_sendMessage);
      break;
    }
    case 0xD247D84C: { // 1425-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_P8SSrDX6_sendMessage);
      break;
    }
    case 0xBDA51D66: { // 1425-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0LYzycFC_sendMessage);
      break;
    }
    case 0x30040A5: { // 1425-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QPfXE6n0_sendMessage);
      break;
    }
    case 0xD148B541: { // 1425-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ac3kk4og_sendMessage);
      break;
    }
    case 0xADA48AA6: { // 1425-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Bhekm82E_sendMessage);
      break;
    }
    case 0xE3A9780D: { // 1425-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OVKAaoWo_sendMessage);
      break;
    }
    case 0xD0D5CEF9: { // 1425-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j9rZjnYX_sendMessage);
      break;
    }
    case 0x5C820E51: { // 1425-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fkdRS3Kk_sendMessage);
      break;
    }
    case 0xF25D44B5: { // 1425-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KU7luaTu_sendMessage);
      break;
    }
    case 0x7285011E: { // 1425-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_F8iOnRlU_sendMessage);
      break;
    }
    case 0xFE26C634: { // 1425-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dLELQr31_sendMessage);
      break;
    }
    case 0x50C83E0E: { // 1425-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xaLHXMlu_sendMessage);
      break;
    }
    case 0x8E3370CC: { // 1425-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MESMY1J5_sendMessage);
      break;
    }
    case 0xA0EFE537: { // 1462-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_s7zg2jA5_sendMessage);
      break;
    }
    case 0xEC20A028: { // 1462-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Xe9pixiI_sendMessage);
      break;
    }
    case 0xBBD44683: { // 1462-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_21vtQCIl_sendMessage);
      break;
    }
    case 0x7BC1F9DF: { // 1462-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4FZHb02U_sendMessage);
      break;
    }
    case 0x4B5BA74: { // 1462-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oYwheUxG_sendMessage);
      break;
    }
    case 0x9C518D6A: { // 1462-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ktIMVuQQ_sendMessage);
      break;
    }
    case 0xCBB7AAE6: { // 1462-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ab4JEDsV_sendMessage);
      break;
    }
    case 0xB8B4037B: { // 1462-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Qalldnu8_sendMessage);
      break;
    }
    case 0xFD5A1B8B: { // 1462-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bE92TkgJ_sendMessage);
      break;
    }
    case 0xC0CD7EA7: { // 1462-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Zo69CGnL_sendMessage);
      break;
    }
    case 0xFF74E5E7: { // 1462-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5IiWOkWl_sendMessage);
      break;
    }
    case 0x94F6ADD2: { // 1462-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9y98ug7I_sendMessage);
      break;
    }
    case 0xACF89C8: { // 1462-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BZr7WEnN_sendMessage);
      break;
    }
    case 0xC9EF10C4: { // 1499-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xc0p3kNi_sendMessage);
      break;
    }
    case 0x650A218A: { // 1499-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gMNpcyJT_sendMessage);
      break;
    }
    case 0x1AEC0FEB: { // 1499-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ClX0blva_sendMessage);
      break;
    }
    case 0x90D3CB6A: { // 1499-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_X49M1KNH_sendMessage);
      break;
    }
    case 0xFB007407: { // 1499-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LE0SR3xP_sendMessage);
      break;
    }
    case 0xD741C2E1: { // 1499-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_m2jgQR82_sendMessage);
      break;
    }
    case 0xB713905B: { // 1499-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2JqrnV2O_sendMessage);
      break;
    }
    case 0xBCB09D65: { // 1499-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5V0y2WGt_sendMessage);
      break;
    }
    case 0x3462CF26: { // 1499-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3yXzJzDF_sendMessage);
      break;
    }
    case 0x7EB71D60: { // 1499-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9ZRw3tV0_sendMessage);
      break;
    }
    case 0xF143DE5C: { // 1499-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M4CEsncm_sendMessage);
      break;
    }
    case 0x69B62A6F: { // 1499-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pFe3BP7R_sendMessage);
      break;
    }
    case 0xDE45E1E5: { // 1499-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DKJzqtTf_sendMessage);
      break;
    }
    case 0xCA7D42C6: { // 1536-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_njjCQh0e_sendMessage);
      break;
    }
    case 0x806FD96F: { // 1536-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_b2SLxpSD_sendMessage);
      break;
    }
    case 0xDCB98A92: { // 1536-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QoEnniYB_sendMessage);
      break;
    }
    case 0x4CE2FD57: { // 1536-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WBb0F73r_sendMessage);
      break;
    }
    case 0x6B909FB9: { // 1536-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fuex8P7L_sendMessage);
      break;
    }
    case 0xF07FBCA: { // 1536-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ghMsBmYI_sendMessage);
      break;
    }
    case 0x849A5730: { // 1536-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_250ijgMz_sendMessage);
      break;
    }
    case 0x36907641: { // 1536-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YnZwHEnA_sendMessage);
      break;
    }
    case 0xB52D4339: { // 1536-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vcn098dE_sendMessage);
      break;
    }
    case 0x12964E75: { // 1536-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_exWYHmPx_sendMessage);
      break;
    }
    case 0x6AA538B: { // 1536-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_F4Eq9OEU_sendMessage);
      break;
    }
    case 0x3E65138: { // 1536-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ba8caV8s_sendMessage);
      break;
    }
    case 0x6681B9BB: { // 1536-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JpjRX77H_sendMessage);
      break;
    }
    case 0x9A67848D: { // 1576-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Yknh3RpC_sendMessage);
      break;
    }
    case 0x28756C44: { // 1576-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mE5z5KCh_sendMessage);
      break;
    }
    case 0xDA3F765E: { // 1584-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Rcs2gv2W_sendMessage);
      break;
    }
    case 0x63BB35B3: { // 1584-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_o2gXhDgi_sendMessage);
      break;
    }
    case 0xBCF12351: { // 1592-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_D3fAxObx_sendMessage);
      break;
    }
    case 0x2C88EFF0: { // 1592-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YbmjBrIS_sendMessage);
      break;
    }
    case 0x24E085E9: { // 1606-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0ZIO0CWu_sendMessage);
      break;
    }
    case 0x379A99BA: { // 1606-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kppGpoQf_sendMessage);
      break;
    }
    case 0xE15D0C40: { // 1614-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NvLgCPBD_sendMessage);
      break;
    }
    case 0xFAB26528: { // 1614-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cPKHPw8v_sendMessage);
      break;
    }
    case 0x67469CDB: { // 1638-bend
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_m3KNyruN_sendMessage);
      break;
    }
    case 0xD2E9EE87: { // 1638-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nFQOgxus_sendMessage);
      break;
    }
    case 0x590B79E7: { // 1638-chunk-size-samples
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_A2l63CYC_sendMessage);
      break;
    }
    case 0x1BD17C37: { // 1638-chunk-size-sec
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SZuPmLYW_sendMessage);
      break;
    }
    case 0x40D20EFE: { // 1638-dur
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OZ7liEPL_sendMessage);
      break;
    }
    case 0x8F1874CE: { // 1638-level
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oGaTqdNh_sendMessage);
      break;
    }
    case 0x3B8EF450: { // 1638-loopstart
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZQK35wun_sendMessage);
      break;
    }
    case 0x52A7D435: { // 1638-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OZhn2DWi_sendMessage);
      break;
    }
    case 0xDD183CF: { // 1638-reset
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kVwnqAvN_sendMessage);
      break;
    }
    case 0x9D1E092: { // 1638-sample
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ArmgaRol_sendMessage);
      break;
    }
    case 0x7ABA477F: { // 1638-sample-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oiHeuAKL_sendMessage);
      break;
    }
    case 0x10C055C1: { // 1638-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZpKlnAGm_sendMessage);
      break;
    }
    case 0x93FD56E6: { // 1638-start
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MhaqFzaO_sendMessage);
      break;
    }
    case 0x8D24D2B6: { // 1638-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EKXbRhyt_sendMessage);
      break;
    }
    case 0xB316C51D: { // 1638-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7B8aCUh2_sendMessage);
      break;
    }
    case 0x34F5B966: { // 1638-transposition
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ud0ydmFv_sendMessage);
      break;
    }
    case 0xAEF9A5F0: { // 1638-vline
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XzJGgUCX_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HgV7ikmg_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_704mUhgb_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MvC4UGib_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tfYtEiB1_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ixH5ysOA_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oaJ3luLN_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LIBb0vEI_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RClODdqQ_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8mC26TIM_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_27LqMN88_sendMessage);
      break;
    }
    case 0x7FFAC478: { // sampleNameFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cTkeA2Uu_sendMessage);
      break;
    }
    case 0x62D6FDDE: { // selectsound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NegdzFGI_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zdSmZkHm_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_D2jBHhby_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2uR4NLIV_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ppna85Gd_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_V3QykzI0_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5U46ADHP_sendMessage);
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


void Heavy_SoundScraper::cSlice_13XRqR7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_atsftGyv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_lbpghUeX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_U2EnedUD, 0, m, &cIf_U2EnedUD_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_PYrAvUld, 0, m, &cIf_PYrAvUld_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_q718bSyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_RCOngieN, 0, m, &cIf_RCOngieN_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_xEhrIDaZ, 0, m, &cIf_xEhrIDaZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_4EVvJEui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Cln9Aj12_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ii1H5MrX, 0, m, &cIf_ii1H5MrX_sendMessage);
}

void Heavy_SoundScraper::cUnop_ocyJewj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_jwFZP6vt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aG3AWbaR, HV_BINOP_EQ, 1, m, &cBinop_aG3AWbaR_sendMessage);
}

void Heavy_SoundScraper::cUnop_8i6y3xon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_jwFZP6vt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aG3AWbaR, HV_BINOP_EQ, 1, m, &cBinop_aG3AWbaR_sendMessage);
}

void Heavy_SoundScraper::cIf_ii1H5MrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_8i6y3xon_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ocyJewj7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Cln9Aj12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ii1H5MrX, 1, m, &cIf_ii1H5MrX_sendMessage);
}

void Heavy_SoundScraper::cIf_PYrAvUld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Ixm1eSLJ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_xEhrIDaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_lq6dsSlL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_U2EnedUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Ixm1eSLJ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_RCOngieN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_lq6dsSlL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_atsftGyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aG3AWbaR, HV_BINOP_EQ, 0, m, &cBinop_aG3AWbaR_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_aUjpGH40_sendMessage);
}

void Heavy_SoundScraper::cBinop_jwFZP6vt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_siWLmOqx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N86nTgTt_sendMessage);
}

void Heavy_SoundScraper::cBinop_aG3AWbaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MYHTeAM3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3GjrfOSf_sendMessage);
}

void Heavy_SoundScraper::cCast_3GjrfOSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RCOngieN, 1, m, &cIf_RCOngieN_sendMessage);
}

void Heavy_SoundScraper::cCast_MYHTeAM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PYrAvUld, 1, m, &cIf_PYrAvUld_sendMessage);
}

void Heavy_SoundScraper::cCast_siWLmOqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_U2EnedUD, 1, m, &cIf_U2EnedUD_sendMessage);
}

void Heavy_SoundScraper::cCast_N86nTgTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xEhrIDaZ, 1, m, &cIf_xEhrIDaZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_aUjpGH40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_a1aZtPQF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_mGoiGFHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JHFMCtq6, 0, m, &cVar_JHFMCtq6_sendMessage);
  cSwitchcase_T36ttdrH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_An98gPxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9z4vsvQT_sendMessage(_c, 0, m);
  cSend_XnNGcod2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_ATLlHaU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_haaa4UjU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_VObqW7Rd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_GkCwdlAF_sendMessage);
}

void Heavy_SoundScraper::cBinop_GkCwdlAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VObqW7Rd, 1, m, &cVar_VObqW7Rd_sendMessage);
}

void Heavy_SoundScraper::cCast_y5s9JKVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_N1fa7BjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_zzCdMh7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_JHFMCtq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ATLlHaU1, 0, m, &cVar_ATLlHaU1_sendMessage);
  cSend_wMtV7vqT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_T36ttdrH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_u8ELYnC2, 0, m, &cSlice_u8ELYnC2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bRYdKz6J, 0, m, &cRandom_bRYdKz6J_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_uC6DXDtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Yts3MKiM_sendMessage);
}

void Heavy_SoundScraper::cUnop_Yts3MKiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 32.0f, 0, m, &cBinop_d5dV3M9X_sendMessage);
}

void Heavy_SoundScraper::cRandom_bRYdKz6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 64.0f, 0, m, &cBinop_uC6DXDtX_sendMessage);
}

void Heavy_SoundScraper::cSlice_u8ELYnC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bRYdKz6J, 1, m, &cRandom_bRYdKz6J_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSend_haaa4UjU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2uR4NLIV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_9z4vsvQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LIBb0vEI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_wMtV7vqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5U46ADHP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_XnNGcod2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ppna85Gd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_DsOLHRKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_YRtDYJqM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_YRtDYJqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oaJ3luLN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_g17VWjQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_YRtDYJqM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_d5dV3M9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_An98gPxa, 0, m, &cVar_An98gPxa_sendMessage);
}

void Heavy_SoundScraper::cMsg_VjWBhpvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 64.0f);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RcRchuCD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_G1Gsd9y7_sendMessage);
}

void Heavy_SoundScraper::cCast_G1Gsd9y7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_An98gPxa, 0, m, &cVar_An98gPxa_sendMessage);
}

void Heavy_SoundScraper::cCast_RcRchuCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JHFMCtq6, 0, m, &cVar_JHFMCtq6_sendMessage);
}

void Heavy_SoundScraper::cVar_5vTXHZS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_EV73xJ0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vMKZAePh_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1VgVnVDj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VM7fqgNo_sendMessage);
}

void Heavy_SoundScraper::cIf_j3wD3ONA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_3EbUOehD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_8h3Djfa2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_Far4iOZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mUgR1mMn, HV_BINOP_POW, 0, m, &cBinop_mUgR1mMn_sendMessage);
}

void Heavy_SoundScraper::cBinop_mUgR1mMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rxYXvI9Y, 0, m, &cPack_rxYXvI9Y_sendMessage);
}

void Heavy_SoundScraper::cBinop_aXnhjTHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_PCFraAnk_sendMessage);
}

void Heavy_SoundScraper::cCast_1VgVnVDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_z8Kyn3Q1_sendMessage);
}

void Heavy_SoundScraper::cCast_VM7fqgNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_j3wD3ONA, 0, m, &cIf_j3wD3ONA_sendMessage);
}

void Heavy_SoundScraper::cBinop_z8Kyn3Q1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_j3wD3ONA, 1, m, &cIf_j3wD3ONA_sendMessage);
}

void Heavy_SoundScraper::cBinop_8h3Djfa2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_aXnhjTHY_sendMessage);
}

void Heavy_SoundScraper::cMsg_3EbUOehD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_rxYXvI9Y, 0, m, &cPack_rxYXvI9Y_sendMessage);
}

void Heavy_SoundScraper::cBinop_PCFraAnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mUgR1mMn, HV_BINOP_POW, 1, m, &cBinop_mUgR1mMn_sendMessage);
  cMsg_Far4iOZT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_rxYXvI9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_EZJEEblW, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_GMsfwqno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Pf3rK4R7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_vMKZAePh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_1YQyCtSQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1YQyCtSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WVVjU2J2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Pf3rK4R7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uYvfXJ9t_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Qq7xx1Cb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FpLvtW1E, 0, m, &cSlice_FpLvtW1E_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WDovrO27, 0, m, &cRandom_WDovrO27_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_c5YCstyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_aj2qBN43_sendMessage);
}

void Heavy_SoundScraper::cUnop_aj2qBN43_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_fNHC6ru2_sendMessage);
}

void Heavy_SoundScraper::cRandom_WDovrO27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_c5YCstyY_sendMessage);
}

void Heavy_SoundScraper::cSlice_FpLvtW1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WDovrO27, 1, m, &cRandom_WDovrO27_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_CN9UxtV9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yAXRMhJh, 0, m, &cSlice_yAXRMhJh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LqWEdriQ, 0, m, &cRandom_LqWEdriQ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_nnj900im_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_U1drxxZY_sendMessage);
}

void Heavy_SoundScraper::cUnop_U1drxxZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_OMpWVvNb, 0, m, &cPack_OMpWVvNb_sendMessage);
}

void Heavy_SoundScraper::cRandom_LqWEdriQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_nnj900im_sendMessage);
}

void Heavy_SoundScraper::cSlice_yAXRMhJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LqWEdriQ, 1, m, &cRandom_LqWEdriQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_oEcGGobk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_9G6OTADo_sendMessage);
}

void Heavy_SoundScraper::cPack_zTveEpUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uOk1bftI, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_r7vcRJhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iIeOEUgx_sendMessage);
}

void Heavy_SoundScraper::cBinop_2Fbyw8NT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_r7vcRJhS_sendMessage);
}

void Heavy_SoundScraper::cPack_qwbWlHTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Nx7OK4nw, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_osvAOxH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_XEzezzl2_sendMessage);
}

void Heavy_SoundScraper::cMsg_kvIk8zqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_axmhw1ls_sendMessage);
}

void Heavy_SoundScraper::cSystem_axmhw1ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Xr9Se3u3_sendMessage);
}

void Heavy_SoundScraper::cDelay_kyxBlKNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kyxBlKNV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_athLVzzr, 0, m, &cDelay_athLVzzr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kyxBlKNV, 0, m, &cDelay_kyxBlKNV_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7i5MYA1m, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_athLVzzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_athLVzzr, m);
  cMsg_2uESOzEr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_tNNSJp0Z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_YlCNWVLW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_XGtOyv1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nK3UAfDX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_0pw5qmv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dSVw0ieH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kyxBlKNV, 2, m, &cDelay_kyxBlKNV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xPEiElxf_sendMessage);
}

void Heavy_SoundScraper::cMsg_nK3UAfDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_0pw5qmv4, 0, m, &hTable_0pw5qmv4_sendMessage);
}

void Heavy_SoundScraper::cBinop_Xr9Se3u3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_XGtOyv1O_sendMessage);
}

void Heavy_SoundScraper::cMsg_2uESOzEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_0pw5qmv4, 0, m, &hTable_0pw5qmv4_sendMessage);
}

void Heavy_SoundScraper::cCast_xPEiElxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kyxBlKNV, 0, m, &cDelay_kyxBlKNV_sendMessage);
}

void Heavy_SoundScraper::cMsg_dSVw0ieH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_athLVzzr, 2, m, &cDelay_athLVzzr_sendMessage);
}

void Heavy_SoundScraper::cMsg_YlCNWVLW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7i5MYA1m, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_3R3g79nR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sQetJpb7_sendMessage);
}

void Heavy_SoundScraper::cSystem_sQetJpb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Jsd46wT8_sendMessage);
}

void Heavy_SoundScraper::cVar_rkCpV5AF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dk212Ucm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_ak2rF5Ja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tc3aVJOR_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1T2THY7r, m);
}

void Heavy_SoundScraper::cBinop_Jsd46wT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qiJScZeT, m);
}

void Heavy_SoundScraper::cMsg_Dk212Ucm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ak2rF5Ja_sendMessage);
}

void Heavy_SoundScraper::cBinop_tc3aVJOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wPz3fdL5, m);
}

void Heavy_SoundScraper::cMsg_CNm2DDlK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kpoqygIm_sendMessage);
}

void Heavy_SoundScraper::cSystem_kpoqygIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MJ9L5ZRL_sendMessage);
}

void Heavy_SoundScraper::cVar_f80TjrWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DQPyY7JX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_YIVSODRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ljOgi4Jh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_i795IZdH, m);
}

void Heavy_SoundScraper::cBinop_MJ9L5ZRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_R4oHvD5Q, m);
}

void Heavy_SoundScraper::cMsg_DQPyY7JX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YIVSODRV_sendMessage);
}

void Heavy_SoundScraper::cBinop_ljOgi4Jh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ygUmyTek, m);
}

void Heavy_SoundScraper::cBinop_zwpeIzaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YYi4eVCY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_P57GStGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_frIlalSx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ssu2Jfy6_sendMessage);
}

void Heavy_SoundScraper::cCast_ssu2Jfy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zwpeIzaF, HV_BINOP_DIVIDE, 0, m, &cBinop_zwpeIzaF_sendMessage);
}

void Heavy_SoundScraper::cCast_frIlalSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zwpeIzaF, HV_BINOP_DIVIDE, 1, m, &cBinop_zwpeIzaF_sendMessage);
}

void Heavy_SoundScraper::cBinop_iIeOEUgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Q7HfK5s4_sendMessage);
}

void Heavy_SoundScraper::cBinop_WffkaZpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_2Fbyw8NT_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q7HfK5s4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zwpeIzaF, HV_BINOP_DIVIDE, 0, m, &cBinop_zwpeIzaF_sendMessage);
}

void Heavy_SoundScraper::cBinop_XEzezzl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qwbWlHTJ, 0, m, &cPack_qwbWlHTJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_9G6OTADo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_P57GStGw_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_zTveEpUe, 0, m, &cPack_zTveEpUe_sendMessage);
}

void Heavy_SoundScraper::cMsg_hSOhMlrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_oEcGGobk, 0, m, &cVar_oEcGGobk_sendMessage);
}

void Heavy_SoundScraper::cMsg_Y6Y7P0mH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_osvAOxH5, 0, m, &cVar_osvAOxH5_sendMessage);
}

void Heavy_SoundScraper::cMsg_YYi4eVCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_l8yZ8PmG, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_Uyfn976R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6h5sECAP_sendMessage);
}

void Heavy_SoundScraper::cSystem_6h5sECAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_teR8RiWv_sendMessage);
}

void Heavy_SoundScraper::cVar_xpJUWQBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dEeq0kWW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_iRvvcWRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HTweODs4_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rRRWoka6, m);
}

void Heavy_SoundScraper::cBinop_teR8RiWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZsaRIZxr, m);
}

void Heavy_SoundScraper::cMsg_dEeq0kWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iRvvcWRu_sendMessage);
}

void Heavy_SoundScraper::cBinop_HTweODs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BQDCmbEw, m);
}

void Heavy_SoundScraper::cVar_wfPwA3yL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_im9nidtw, HV_BINOP_MULTIPLY, 0, m, &cBinop_im9nidtw_sendMessage);
}

void Heavy_SoundScraper::cMsg_sEurtVMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_myhfwV4d_sendMessage);
}

void Heavy_SoundScraper::cSystem_myhfwV4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NgXP5WkV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_im9nidtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_VwePOJ9p_sendMessage);
}

void Heavy_SoundScraper::cBinop_zX60otWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_im9nidtw, HV_BINOP_MULTIPLY, 1, m, &cBinop_im9nidtw_sendMessage);
}

void Heavy_SoundScraper::cMsg_NgXP5WkV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zX60otWC_sendMessage);
}

void Heavy_SoundScraper::cBinop_VwePOJ9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Yqeok7A9_sendMessage);
}

void Heavy_SoundScraper::cBinop_Yqeok7A9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iuKdzevU_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eAzeWq1z, m);
}

void Heavy_SoundScraper::cBinop_iuKdzevU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rFXlZCME, m);
}

void Heavy_SoundScraper::cBinop_Igx1x3Rh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_JUmVCmF1_sendMessage);
}

void Heavy_SoundScraper::cBinop_JUmVCmF1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EJaCbrWF, m);
}

void Heavy_SoundScraper::cBinop_s5izlY8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_s5iAM1lw_sendMessage);
}

void Heavy_SoundScraper::cBinop_s5iAM1lw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_bvdg3K3b_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IDCAZLDM_sendMessage);
}

void Heavy_SoundScraper::cVar_82msUsXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_MtDxdL75_sendMessage);
}

void Heavy_SoundScraper::cMsg_mNn9ri2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dzNzgkds_sendMessage);
}

void Heavy_SoundScraper::cSystem_dzNzgkds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P96y4mrO, HV_BINOP_DIVIDE, 1, m, &cBinop_P96y4mrO_sendMessage);
}

void Heavy_SoundScraper::cBinop_bvdg3K3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_QALLXtgo_sendMessage);
}

void Heavy_SoundScraper::cBinop_QALLXtgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WAaujEk5, m);
}

void Heavy_SoundScraper::cMsg_Mr4K8zjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_jjoVROnA_sendMessage);
}

void Heavy_SoundScraper::cBinop_jjoVROnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_s5izlY8A_sendMessage);
}

void Heavy_SoundScraper::cBinop_IDCAZLDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Hn0ZGoaR, m);
}

void Heavy_SoundScraper::cBinop_MtDxdL75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Oh0p0lvb_sendMessage);
}

void Heavy_SoundScraper::cBinop_Oh0p0lvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P96y4mrO, HV_BINOP_DIVIDE, 0, m, &cBinop_P96y4mrO_sendMessage);
}

void Heavy_SoundScraper::cBinop_P96y4mrO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Mr4K8zjC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_fxO1wGQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kL7Ft6Lk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_LjOrJWZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XGkd2BHJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_XGkd2BHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DV56SwOO_sendMessage);
}

void Heavy_SoundScraper::cDelay_XQwFbd6m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XQwFbd6m, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OtBO7KJz, 0, m, &cDelay_OtBO7KJz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XQwFbd6m, 0, m, &cDelay_XQwFbd6m_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_O7x1yznz, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_OtBO7KJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OtBO7KJz, m);
  cMsg_ooGpxgeO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_AL7veJwk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_uqM0foMZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_mK6xdx5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M3cHsgwg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_pIje5WwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xWH5FQHz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XQwFbd6m, 2, m, &cDelay_XQwFbd6m_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nrA6keaY_sendMessage);
}

void Heavy_SoundScraper::cMsg_M3cHsgwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_pIje5WwM, 0, m, &hTable_pIje5WwM_sendMessage);
}

void Heavy_SoundScraper::cBinop_DV56SwOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_mK6xdx5k_sendMessage);
}

void Heavy_SoundScraper::cMsg_ooGpxgeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_pIje5WwM, 0, m, &hTable_pIje5WwM_sendMessage);
}

void Heavy_SoundScraper::cCast_nrA6keaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XQwFbd6m, 0, m, &cDelay_XQwFbd6m_sendMessage);
}

void Heavy_SoundScraper::cMsg_xWH5FQHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OtBO7KJz, 2, m, &cDelay_OtBO7KJz_sendMessage);
}

void Heavy_SoundScraper::cMsg_uqM0foMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_O7x1yznz, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_qM6GgHrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_kL7Ft6Lk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_kL7Ft6Lk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_A1gHAy57, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_EPI4X7Lh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_e6RSzkHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EjN0aM35_sendMessage);
}

void Heavy_SoundScraper::cSystem_EjN0aM35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LFReCwnL, HV_BINOP_MULTIPLY, 1, m, &cBinop_LFReCwnL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_slprhsz3, HV_BINOP_MULTIPLY, 1, m, &cBinop_slprhsz3_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_zq4omz2F_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_YYtGndzL_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_YYtGndzL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HuVPUmSh_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_9QNQ5Soo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9QNQ5Soo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9QNQ5Soo, 0, m, &cDelay_9QNQ5Soo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_96XE8DaX, 0, m, &cVar_96XE8DaX_sendMessage);
}

void Heavy_SoundScraper::cCast_HuVPUmSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YYtGndzL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9QNQ5Soo, 0, m, &cDelay_9QNQ5Soo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_96XE8DaX, 0, m, &cVar_96XE8DaX_sendMessage);
}

void Heavy_SoundScraper::cMsg_y66hBBhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ixHgxtbE_sendMessage);
}

void Heavy_SoundScraper::cSystem_ixHgxtbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_doA3jfcb_sendMessage);
}

void Heavy_SoundScraper::cVar_zA33dGaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kgsqXjQf, HV_BINOP_MULTIPLY, 0, m, &cBinop_kgsqXjQf_sendMessage);
}

void Heavy_SoundScraper::cMsg_YYtGndzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9QNQ5Soo, 0, m, &cDelay_9QNQ5Soo_sendMessage);
}

void Heavy_SoundScraper::cBinop_LwneTWUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9QNQ5Soo, 2, m, &cDelay_9QNQ5Soo_sendMessage);
}

void Heavy_SoundScraper::cBinop_doA3jfcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kgsqXjQf, HV_BINOP_MULTIPLY, 1, m, &cBinop_kgsqXjQf_sendMessage);
}

void Heavy_SoundScraper::cBinop_kgsqXjQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_LwneTWUu_sendMessage);
}

void Heavy_SoundScraper::cVar_96XE8DaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4GFw9qVO, HV_BINOP_SUBTRACT, 0, m, &cBinop_4GFw9qVO_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_TzWIW26j_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_9GchGTlO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7yP1ZK3y_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9VoAPqsl_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_7yP1ZK3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tXq4OrGo, 0, m, &cVar_tXq4OrGo_sendMessage);
}

void Heavy_SoundScraper::cCast_9VoAPqsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xisIXfb4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qhy5ZQEl_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_nLEfZYev_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ggybWYkK, 0, m, &cSlice_ggybWYkK_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KYg1Owge, 0, m, &cSlice_KYg1Owge_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VmUypIAC_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_MrIpmjwd, 0, m, &cSlice_MrIpmjwd_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_MaeA1mNv, 0, m, &cSlice_MaeA1mNv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qc0zH7kr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H0NiCtOZ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_ggybWYkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ci3ifwMR_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_ci3ifwMR_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_KYg1Owge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dOcc6ttj_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CcqbYUBY_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dOcc6ttj_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CcqbYUBY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_iCxlPoMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PKVcKJrd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zenC24j0_sendMessage);
}

void Heavy_SoundScraper::cVar_Xl3EeTDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BJW5N1jO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_BJW5N1jO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x1chIisH_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LFReCwnL, HV_BINOP_MULTIPLY, 0, m, &cBinop_LFReCwnL_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_xvXbbmbQ, HV_BINOP_DIVIDE, 1, m, &cBinop_xvXbbmbQ_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_zA33dGaX, 0, m, &cVar_zA33dGaX_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_x1chIisH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KtY9avdy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_A0Egmp55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3e4Bt1EH, HV_BINOP_SUBTRACT, 1, m, &cBinop_3e4Bt1EH_sendMessage);
}

void Heavy_SoundScraper::cVar_Ab5IU5Ni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tXq4OrGo, 0, m, &cVar_tXq4OrGo_sendMessage);
}

void Heavy_SoundScraper::cVar_tXq4OrGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1l7JrMYI, HV_BINOP_ADD, 0, m, &cBinop_1l7JrMYI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVs6isXO, HV_BINOP_ADD, 0, m, &cBinop_yVs6isXO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_c4H6qIOA, 0, m, &cVar_c4H6qIOA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_WffkaZpj_sendMessage);
}

void Heavy_SoundScraper::cSlice_MrIpmjwd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PKVcKJrd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zenC24j0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_MaeA1mNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CNJ441Qg_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tQEleXId_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_rMF3uoaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_96XE8DaX, 1, m, &cVar_96XE8DaX_sendMessage);
}

void Heavy_SoundScraper::cBinop_slprhsz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rMF3uoaE_sendMessage);
}

void Heavy_SoundScraper::cBinop_LFReCwnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cf1zAaq7_sendMessage);
}

void Heavy_SoundScraper::cBinop_cf1zAaq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4GFw9qVO, HV_BINOP_SUBTRACT, 1, m, &cBinop_4GFw9qVO_sendMessage);
}

void Heavy_SoundScraper::cBinop_4GFw9qVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_96XE8DaX, 1, m, &cVar_96XE8DaX_sendMessage);
}

void Heavy_SoundScraper::cMsg_OHZbiY6L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_zq4omz2F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_xevDGIa7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_zq4omz2F_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVs6isXO, HV_BINOP_ADD, 1, m, &cBinop_yVs6isXO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1l7JrMYI, HV_BINOP_ADD, 1, m, &cBinop_1l7JrMYI_sendMessage);
}

void Heavy_SoundScraper::cBinop_TzWIW26j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9GchGTlO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_1l7JrMYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tXq4OrGo, 1, m, &cVar_tXq4OrGo_sendMessage);
}

void Heavy_SoundScraper::cBinop_xvXbbmbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_56Hgxf9N, HV_BINOP_DIVIDE, 1, m, &cBinop_56Hgxf9N_sendMessage);
}

void Heavy_SoundScraper::cBinop_56Hgxf9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVs6isXO, HV_BINOP_ADD, 1, m, &cBinop_yVs6isXO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1l7JrMYI, HV_BINOP_ADD, 1, m, &cBinop_1l7JrMYI_sendMessage);
}

void Heavy_SoundScraper::cCast_zenC24j0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xvXbbmbQ, HV_BINOP_DIVIDE, 0, m, &cBinop_xvXbbmbQ_sendMessage);
}

void Heavy_SoundScraper::cCast_PKVcKJrd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_slprhsz3, HV_BINOP_MULTIPLY, 0, m, &cBinop_slprhsz3_sendMessage);
}

void Heavy_SoundScraper::cCast_tQEleXId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3e4Bt1EH, HV_BINOP_SUBTRACT, 0, m, &cBinop_3e4Bt1EH_sendMessage);
}

void Heavy_SoundScraper::cCast_CNJ441Qg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ab5IU5Ni, 1, m, &cVar_Ab5IU5Ni_sendMessage);
}

void Heavy_SoundScraper::cCast_qhy5ZQEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ab5IU5Ni, 0, m, &cVar_Ab5IU5Ni_sendMessage);
}

void Heavy_SoundScraper::cCast_xisIXfb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xevDGIa7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_yVs6isXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A0Egmp55, 0, m, &cVar_A0Egmp55_sendMessage);
}

void Heavy_SoundScraper::cMsg_ci3ifwMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_zq4omz2F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_n8RGuniD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_iCxlPoMC, 1, m, &cVar_iCxlPoMC_sendMessage);
}

void Heavy_SoundScraper::cMsg_KtY9avdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LFReCwnL, HV_BINOP_MULTIPLY, 0, m, &cBinop_LFReCwnL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xvXbbmbQ, HV_BINOP_DIVIDE, 1, m, &cBinop_xvXbbmbQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zA33dGaX, 0, m, &cVar_zA33dGaX_sendMessage);
}

void Heavy_SoundScraper::cCast_dOcc6ttj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ci3ifwMR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_CcqbYUBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RVW39dfV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVs6isXO, HV_BINOP_ADD, 0, m, &cBinop_yVs6isXO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tXq4OrGo, 1, m, &cVar_tXq4OrGo_sendMessage);
}

void Heavy_SoundScraper::cBinop_3e4Bt1EH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_56Hgxf9N, HV_BINOP_DIVIDE, 0, m, &cBinop_56Hgxf9N_sendMessage);
}

void Heavy_SoundScraper::cCast_RVW39dfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xevDGIa7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Qc0zH7kr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OHZbiY6L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_H0NiCtOZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n8RGuniD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_VmUypIAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iCxlPoMC, 0, m, &cVar_iCxlPoMC_sendMessage);
}

void Heavy_SoundScraper::cVar_c4H6qIOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cPack_djmdksop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nLEfZYev_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_tJms4pSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LEXG24S5_sendMessage);
}

void Heavy_SoundScraper::cSystem_LEXG24S5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XKPYUzZf, HV_BINOP_MULTIPLY, 1, m, &cBinop_XKPYUzZf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VglGngpY, HV_BINOP_MULTIPLY, 1, m, &cBinop_VglGngpY_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_gwKd17V4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_HgBABnij_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HgBABnij_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iDsYmbZL_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_jbuLXfH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jbuLXfH6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jbuLXfH6, 0, m, &cDelay_jbuLXfH6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jVgEmOG7, 0, m, &cVar_jVgEmOG7_sendMessage);
}

void Heavy_SoundScraper::cCast_iDsYmbZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HgBABnij_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jbuLXfH6, 0, m, &cDelay_jbuLXfH6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jVgEmOG7, 0, m, &cVar_jVgEmOG7_sendMessage);
}

void Heavy_SoundScraper::cMsg_I4susFis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VyUgYcTq_sendMessage);
}

void Heavy_SoundScraper::cSystem_VyUgYcTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_x0ZpEmk5_sendMessage);
}

void Heavy_SoundScraper::cVar_t6k8MfJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pUIfNBDd, HV_BINOP_MULTIPLY, 0, m, &cBinop_pUIfNBDd_sendMessage);
}

void Heavy_SoundScraper::cMsg_HgBABnij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jbuLXfH6, 0, m, &cDelay_jbuLXfH6_sendMessage);
}

void Heavy_SoundScraper::cBinop_FSQB6y1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jbuLXfH6, 2, m, &cDelay_jbuLXfH6_sendMessage);
}

void Heavy_SoundScraper::cBinop_x0ZpEmk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pUIfNBDd, HV_BINOP_MULTIPLY, 1, m, &cBinop_pUIfNBDd_sendMessage);
}

void Heavy_SoundScraper::cBinop_pUIfNBDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_FSQB6y1r_sendMessage);
}

void Heavy_SoundScraper::cVar_jVgEmOG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fJVWDj7y, HV_BINOP_SUBTRACT, 0, m, &cBinop_fJVWDj7y_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_OoROU7Tp_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_0UmrN1uj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kytuffjn_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mxnJexDl_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_kytuffjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qeglyR1K, 0, m, &cVar_qeglyR1K_sendMessage);
}

void Heavy_SoundScraper::cCast_mxnJexDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pdmEDxWj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QR2LckwI_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_BXoY1rXF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PMsvQ7rk, 0, m, &cSlice_PMsvQ7rk_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Sk5NGUig, 0, m, &cSlice_Sk5NGUig_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L7vpq8Fz_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_rmHbt3Gz, 0, m, &cSlice_rmHbt3Gz_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_n156S4jd, 0, m, &cSlice_n156S4jd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_385VYF1q_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k1d183WH_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_PMsvQ7rk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_3PMK1VkO_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_3PMK1VkO_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Sk5NGUig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qDMloCWJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LjRGFw02_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qDMloCWJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LjRGFw02_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_CBnqGEL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FZJVskri_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_l3GbXkTZ_sendMessage);
}

void Heavy_SoundScraper::cVar_sgrR3zew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_F2fJmnbH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_F2fJmnbH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vhUAq5fs_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XKPYUzZf, HV_BINOP_MULTIPLY, 0, m, &cBinop_XKPYUzZf_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_YLxBBs3v, HV_BINOP_DIVIDE, 1, m, &cBinop_YLxBBs3v_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_t6k8MfJI, 0, m, &cVar_t6k8MfJI_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_vhUAq5fs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p34bRWpl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_VfXwFZY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RVa1vljE, HV_BINOP_SUBTRACT, 1, m, &cBinop_RVa1vljE_sendMessage);
}

void Heavy_SoundScraper::cVar_p8tULMOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qeglyR1K, 0, m, &cVar_qeglyR1K_sendMessage);
}

void Heavy_SoundScraper::cVar_qeglyR1K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FSs39JRb, HV_BINOP_ADD, 0, m, &cBinop_FSs39JRb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CBfHgv4k, HV_BINOP_ADD, 0, m, &cBinop_CBfHgv4k_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EPI4X7Lh, 0, m, &cVar_EPI4X7Lh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_47HqzkJf, m);
}

void Heavy_SoundScraper::cSlice_rmHbt3Gz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FZJVskri_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_l3GbXkTZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_n156S4jd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MzqeLdRm_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6xdoJYzS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_7dMdFbSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jVgEmOG7, 1, m, &cVar_jVgEmOG7_sendMessage);
}

void Heavy_SoundScraper::cBinop_VglGngpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7dMdFbSB_sendMessage);
}

void Heavy_SoundScraper::cBinop_XKPYUzZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QAfK1jH3_sendMessage);
}

void Heavy_SoundScraper::cBinop_QAfK1jH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fJVWDj7y, HV_BINOP_SUBTRACT, 1, m, &cBinop_fJVWDj7y_sendMessage);
}

void Heavy_SoundScraper::cBinop_fJVWDj7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jVgEmOG7, 1, m, &cVar_jVgEmOG7_sendMessage);
}

void Heavy_SoundScraper::cMsg_qQFjqSmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_gwKd17V4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_3Vo0aELW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_gwKd17V4_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CBfHgv4k, HV_BINOP_ADD, 1, m, &cBinop_CBfHgv4k_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FSs39JRb, HV_BINOP_ADD, 1, m, &cBinop_FSs39JRb_sendMessage);
}

void Heavy_SoundScraper::cBinop_OoROU7Tp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0UmrN1uj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_FSs39JRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qeglyR1K, 1, m, &cVar_qeglyR1K_sendMessage);
}

void Heavy_SoundScraper::cBinop_YLxBBs3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sy77Ku1B, HV_BINOP_DIVIDE, 1, m, &cBinop_sy77Ku1B_sendMessage);
}

void Heavy_SoundScraper::cBinop_sy77Ku1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CBfHgv4k, HV_BINOP_ADD, 1, m, &cBinop_CBfHgv4k_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FSs39JRb, HV_BINOP_ADD, 1, m, &cBinop_FSs39JRb_sendMessage);
}

void Heavy_SoundScraper::cCast_FZJVskri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VglGngpY, HV_BINOP_MULTIPLY, 0, m, &cBinop_VglGngpY_sendMessage);
}

void Heavy_SoundScraper::cCast_l3GbXkTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YLxBBs3v, HV_BINOP_DIVIDE, 0, m, &cBinop_YLxBBs3v_sendMessage);
}

void Heavy_SoundScraper::cCast_MzqeLdRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p8tULMOd, 1, m, &cVar_p8tULMOd_sendMessage);
}

void Heavy_SoundScraper::cCast_6xdoJYzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RVa1vljE, HV_BINOP_SUBTRACT, 0, m, &cBinop_RVa1vljE_sendMessage);
}

void Heavy_SoundScraper::cCast_QR2LckwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p8tULMOd, 0, m, &cVar_p8tULMOd_sendMessage);
}

void Heavy_SoundScraper::cCast_pdmEDxWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3Vo0aELW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_CBfHgv4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VfXwFZY9, 0, m, &cVar_VfXwFZY9_sendMessage);
}

void Heavy_SoundScraper::cMsg_3PMK1VkO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_gwKd17V4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_IcMh9Nsu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_CBnqGEL9, 1, m, &cVar_CBnqGEL9_sendMessage);
}

void Heavy_SoundScraper::cMsg_p34bRWpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XKPYUzZf, HV_BINOP_MULTIPLY, 0, m, &cBinop_XKPYUzZf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YLxBBs3v, HV_BINOP_DIVIDE, 1, m, &cBinop_YLxBBs3v_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_t6k8MfJI, 0, m, &cVar_t6k8MfJI_sendMessage);
}

void Heavy_SoundScraper::cCast_qDMloCWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3PMK1VkO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_LjRGFw02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_89BpceEu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CBfHgv4k, HV_BINOP_ADD, 0, m, &cBinop_CBfHgv4k_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qeglyR1K, 1, m, &cVar_qeglyR1K_sendMessage);
}

void Heavy_SoundScraper::cBinop_RVa1vljE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sy77Ku1B, HV_BINOP_DIVIDE, 0, m, &cBinop_sy77Ku1B_sendMessage);
}

void Heavy_SoundScraper::cCast_89BpceEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3Vo0aELW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_385VYF1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qQFjqSmY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_L7vpq8Fz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CBnqGEL9, 0, m, &cVar_CBnqGEL9_sendMessage);
}

void Heavy_SoundScraper::cCast_k1d183WH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IcMh9Nsu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_OMpWVvNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BXoY1rXF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_5IOyDtUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_grGvWGq3, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_BFVjoEZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_CgX5jxof_sendMessage);
}

void Heavy_SoundScraper::cBinop_CgX5jxof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_djmdksop, 0, m, &cPack_djmdksop_sendMessage);
}

void Heavy_SoundScraper::cBinop_fNHC6ru2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BFVjoEZF_sendMessage);
}

void Heavy_SoundScraper::cCast_6YiB3lVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Qq7xx1Cb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_WCeva55D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CN9UxtV9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_aY93zSUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Igx1x3Rh_sendMessage);
}

void Heavy_SoundScraper::cTabhead_JkbRmVGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7FXr8Gxz, HV_BINOP_SUBTRACT, 0, m, &cBinop_7FXr8Gxz_sendMessage);
}

void Heavy_SoundScraper::cMsg_no66iP7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3mrVec1H_sendMessage);
}

void Heavy_SoundScraper::cSystem_3mrVec1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qfHbY1sG_sendMessage);
}

void Heavy_SoundScraper::cVar_tDo2rNxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2cAtkxfg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_EhXauGUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EhXauGUV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EVRt3sqi, 0, m, &cDelay_EVRt3sqi_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Uy2K3pCf, 0, m, &sTabread_Uy2K3pCf_sendMessage);
}

void Heavy_SoundScraper::cDelay_EVRt3sqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EVRt3sqi, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Uy2K3pCf, 0, m, &sTabread_Uy2K3pCf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EVRt3sqi, 0, m, &cDelay_EVRt3sqi_sendMessage);
}

void Heavy_SoundScraper::sTabread_Uy2K3pCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9Ylc6RXK, HV_BINOP_SUBTRACT, 0, m, &cBinop_9Ylc6RXK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_5yacHnVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EzbYgVuC, HV_BINOP_MAX, 0, m, &cBinop_EzbYgVuC_sendMessage);
}

void Heavy_SoundScraper::cBinop_qfHbY1sG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5yacHnVq, HV_BINOP_MULTIPLY, 0, m, &cBinop_5yacHnVq_sendMessage);
}

void Heavy_SoundScraper::cBinop_7FXr8Gxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DyMvy7Ek_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Uy2K3pCf, 0, m, &sTabread_Uy2K3pCf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5soZgzxE_sendMessage);
}

void Heavy_SoundScraper::cSystem_nkYqZe5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9Ylc6RXK, HV_BINOP_SUBTRACT, 1, m, &cBinop_9Ylc6RXK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EVRt3sqi, 2, m, &cDelay_EVRt3sqi_sendMessage);
}

void Heavy_SoundScraper::cMsg_2cAtkxfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nkYqZe5c_sendMessage);
}

void Heavy_SoundScraper::cMsg_DyMvy7Ek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EhXauGUV, 0, m, &cDelay_EhXauGUV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EVRt3sqi, 0, m, &cDelay_EVRt3sqi_sendMessage);
}

void Heavy_SoundScraper::cMsg_Lsd6TrSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_EzbYgVuC, HV_BINOP_MAX, 1, m, &cBinop_EzbYgVuC_sendMessage);
}

void Heavy_SoundScraper::cBinop_EzbYgVuC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7FXr8Gxz, HV_BINOP_SUBTRACT, 1, m, &cBinop_7FXr8Gxz_sendMessage);
}

void Heavy_SoundScraper::cCast_5soZgzxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EhXauGUV, 0, m, &cDelay_EhXauGUV_sendMessage);
}

void Heavy_SoundScraper::cBinop_I1undEqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EhXauGUV, 2, m, &cDelay_EhXauGUV_sendMessage);
}

void Heavy_SoundScraper::cBinop_9Ylc6RXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_I1undEqG_sendMessage);
}

void Heavy_SoundScraper::cCast_gHiKoCG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tDo2rNxN, 0, m, &cVar_tDo2rNxN_sendMessage);
  cMsg_no66iP7z_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_JkbRmVGZ, 0, m, &cTabhead_JkbRmVGZ_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Hir9LMco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OhecreKz, HV_BINOP_SUBTRACT, 0, m, &cBinop_OhecreKz_sendMessage);
}

void Heavy_SoundScraper::cMsg_HW0E7lfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HPQJa1mg_sendMessage);
}

void Heavy_SoundScraper::cSystem_HPQJa1mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Zr6ykFkj_sendMessage);
}

void Heavy_SoundScraper::cVar_aoZnCuCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5nEOQXOm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_QHGrB6o0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QHGrB6o0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S4hEoMua, 0, m, &cDelay_S4hEoMua_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qwJqadBw, 0, m, &sTabread_qwJqadBw_sendMessage);
}

void Heavy_SoundScraper::cDelay_S4hEoMua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_S4hEoMua, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qwJqadBw, 0, m, &sTabread_qwJqadBw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S4hEoMua, 0, m, &cDelay_S4hEoMua_sendMessage);
}

void Heavy_SoundScraper::sTabread_qwJqadBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_COxCNclT, HV_BINOP_SUBTRACT, 0, m, &cBinop_COxCNclT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_2qc8DPWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9SJDBfQA, HV_BINOP_MAX, 0, m, &cBinop_9SJDBfQA_sendMessage);
}

void Heavy_SoundScraper::cBinop_Zr6ykFkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2qc8DPWr, HV_BINOP_MULTIPLY, 0, m, &cBinop_2qc8DPWr_sendMessage);
}

void Heavy_SoundScraper::cBinop_OhecreKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3M1tLNRc_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qwJqadBw, 0, m, &sTabread_qwJqadBw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AHxH94nJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_fYdIfzMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_COxCNclT, HV_BINOP_SUBTRACT, 1, m, &cBinop_COxCNclT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S4hEoMua, 2, m, &cDelay_S4hEoMua_sendMessage);
}

void Heavy_SoundScraper::cMsg_5nEOQXOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fYdIfzMw_sendMessage);
}

void Heavy_SoundScraper::cMsg_3M1tLNRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QHGrB6o0, 0, m, &cDelay_QHGrB6o0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S4hEoMua, 0, m, &cDelay_S4hEoMua_sendMessage);
}

void Heavy_SoundScraper::cMsg_3E5aWTmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9SJDBfQA, HV_BINOP_MAX, 1, m, &cBinop_9SJDBfQA_sendMessage);
}

void Heavy_SoundScraper::cBinop_9SJDBfQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OhecreKz, HV_BINOP_SUBTRACT, 1, m, &cBinop_OhecreKz_sendMessage);
}

void Heavy_SoundScraper::cCast_AHxH94nJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QHGrB6o0, 0, m, &cDelay_QHGrB6o0_sendMessage);
}

void Heavy_SoundScraper::cBinop_HaPSexHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QHGrB6o0, 2, m, &cDelay_QHGrB6o0_sendMessage);
}

void Heavy_SoundScraper::cBinop_COxCNclT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HaPSexHv_sendMessage);
}

void Heavy_SoundScraper::cCast_gWEEIE4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aoZnCuCn, 0, m, &cVar_aoZnCuCn_sendMessage);
  cMsg_HW0E7lfX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Hir9LMco, 0, m, &cTabhead_Hir9LMco_sendMessage);
}

void Heavy_SoundScraper::cTabhead_OWNyXRSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AzNRJLjm, HV_BINOP_SUBTRACT, 0, m, &cBinop_AzNRJLjm_sendMessage);
}

void Heavy_SoundScraper::cMsg_PsBnFpLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_33ZV5nDL_sendMessage);
}

void Heavy_SoundScraper::cSystem_33ZV5nDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_M4XSnlKU_sendMessage);
}

void Heavy_SoundScraper::cVar_LjyXlIqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3yypXClE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_Ed6s8Egg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ed6s8Egg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7mNNQuir, 0, m, &cDelay_7mNNQuir_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u39yoezc, 0, m, &sTabread_u39yoezc_sendMessage);
}

void Heavy_SoundScraper::cDelay_7mNNQuir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7mNNQuir, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u39yoezc, 0, m, &sTabread_u39yoezc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7mNNQuir, 0, m, &cDelay_7mNNQuir_sendMessage);
}

void Heavy_SoundScraper::sTabread_u39yoezc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_VxyHqaqQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_VxyHqaqQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_4L5x6FK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nwRFp0Rd, HV_BINOP_MAX, 0, m, &cBinop_nwRFp0Rd_sendMessage);
}

void Heavy_SoundScraper::cBinop_M4XSnlKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4L5x6FK1, HV_BINOP_MULTIPLY, 0, m, &cBinop_4L5x6FK1_sendMessage);
}

void Heavy_SoundScraper::cBinop_AzNRJLjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QF5QH0Yr_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u39yoezc, 0, m, &sTabread_u39yoezc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vbFxCqWX_sendMessage);
}

void Heavy_SoundScraper::cSystem_S0iGTsWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VxyHqaqQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_VxyHqaqQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7mNNQuir, 2, m, &cDelay_7mNNQuir_sendMessage);
}

void Heavy_SoundScraper::cMsg_3yypXClE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_S0iGTsWv_sendMessage);
}

void Heavy_SoundScraper::cMsg_QF5QH0Yr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ed6s8Egg, 0, m, &cDelay_Ed6s8Egg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7mNNQuir, 0, m, &cDelay_7mNNQuir_sendMessage);
}

void Heavy_SoundScraper::cMsg_yHiwxdAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_nwRFp0Rd, HV_BINOP_MAX, 1, m, &cBinop_nwRFp0Rd_sendMessage);
}

void Heavy_SoundScraper::cBinop_nwRFp0Rd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AzNRJLjm, HV_BINOP_SUBTRACT, 1, m, &cBinop_AzNRJLjm_sendMessage);
}

void Heavy_SoundScraper::cCast_vbFxCqWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ed6s8Egg, 0, m, &cDelay_Ed6s8Egg_sendMessage);
}

void Heavy_SoundScraper::cBinop_BWZ1FsSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ed6s8Egg, 2, m, &cDelay_Ed6s8Egg_sendMessage);
}

void Heavy_SoundScraper::cBinop_VxyHqaqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BWZ1FsSY_sendMessage);
}

void Heavy_SoundScraper::cCast_2VRKaXIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LjyXlIqz, 0, m, &cVar_LjyXlIqz_sendMessage);
  cMsg_PsBnFpLM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OWNyXRSs, 0, m, &cTabhead_OWNyXRSs_sendMessage);
}

void Heavy_SoundScraper::cTabhead_mDulVuSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sig14typ, HV_BINOP_SUBTRACT, 0, m, &cBinop_sig14typ_sendMessage);
}

void Heavy_SoundScraper::cMsg_PeEOMoDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_G6oZryJw_sendMessage);
}

void Heavy_SoundScraper::cSystem_G6oZryJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IM3Ui5GB_sendMessage);
}

void Heavy_SoundScraper::cVar_gnZEOEpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qBtV6r0m_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_Y4iPok5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Y4iPok5W, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T7n8rKWK, 0, m, &cDelay_T7n8rKWK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tf6TMInt, 0, m, &sTabread_tf6TMInt_sendMessage);
}

void Heavy_SoundScraper::cDelay_T7n8rKWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_T7n8rKWK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tf6TMInt, 0, m, &sTabread_tf6TMInt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T7n8rKWK, 0, m, &cDelay_T7n8rKWK_sendMessage);
}

void Heavy_SoundScraper::sTabread_tf6TMInt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ttI25lId, HV_BINOP_SUBTRACT, 0, m, &cBinop_ttI25lId_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_zcYR4UY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J6JjJOgB, HV_BINOP_MAX, 0, m, &cBinop_J6JjJOgB_sendMessage);
}

void Heavy_SoundScraper::cBinop_IM3Ui5GB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zcYR4UY8, HV_BINOP_MULTIPLY, 0, m, &cBinop_zcYR4UY8_sendMessage);
}

void Heavy_SoundScraper::cBinop_sig14typ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m33xNUzO_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tf6TMInt, 0, m, &sTabread_tf6TMInt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SQ3TjFbk_sendMessage);
}

void Heavy_SoundScraper::cSystem_R3VJ2EmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ttI25lId, HV_BINOP_SUBTRACT, 1, m, &cBinop_ttI25lId_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T7n8rKWK, 2, m, &cDelay_T7n8rKWK_sendMessage);
}

void Heavy_SoundScraper::cMsg_qBtV6r0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R3VJ2EmG_sendMessage);
}

void Heavy_SoundScraper::cMsg_m33xNUzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y4iPok5W, 0, m, &cDelay_Y4iPok5W_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T7n8rKWK, 0, m, &cDelay_T7n8rKWK_sendMessage);
}

void Heavy_SoundScraper::cMsg_sDrYMnS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_J6JjJOgB, HV_BINOP_MAX, 1, m, &cBinop_J6JjJOgB_sendMessage);
}

void Heavy_SoundScraper::cBinop_J6JjJOgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sig14typ, HV_BINOP_SUBTRACT, 1, m, &cBinop_sig14typ_sendMessage);
}

void Heavy_SoundScraper::cCast_SQ3TjFbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y4iPok5W, 0, m, &cDelay_Y4iPok5W_sendMessage);
}

void Heavy_SoundScraper::cBinop_XNstUITZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y4iPok5W, 2, m, &cDelay_Y4iPok5W_sendMessage);
}

void Heavy_SoundScraper::cBinop_ttI25lId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XNstUITZ_sendMessage);
}

void Heavy_SoundScraper::cCast_9SdivCzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gnZEOEpr, 0, m, &cVar_gnZEOEpr_sendMessage);
  cMsg_PeEOMoDs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mDulVuSE, 0, m, &cTabhead_mDulVuSE_sendMessage);
}

void Heavy_SoundScraper::cMsg_aSsS99ZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hbRByyVW_sendMessage);
}

void Heavy_SoundScraper::cSystem_hbRByyVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qTzpXcGx_sendMessage);
}

void Heavy_SoundScraper::cDelay_pl2SKrD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pl2SKrD0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kuvsJItJ, 0, m, &cDelay_kuvsJItJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pl2SKrD0, 0, m, &cDelay_pl2SKrD0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GDROM89T, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_kuvsJItJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kuvsJItJ, m);
  cMsg_OQTXhHx1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ldgkF6P5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_9GMFoFjh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_fkQ0N6x3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ra9ZyLG6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_N9HZZxsE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_arWoycWd_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pl2SKrD0, 2, m, &cDelay_pl2SKrD0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qcFXmSGa_sendMessage);
}

void Heavy_SoundScraper::cMsg_ra9ZyLG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_N9HZZxsE, 0, m, &hTable_N9HZZxsE_sendMessage);
}

void Heavy_SoundScraper::cBinop_qTzpXcGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_fkQ0N6x3_sendMessage);
}

void Heavy_SoundScraper::cMsg_OQTXhHx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_N9HZZxsE, 0, m, &hTable_N9HZZxsE_sendMessage);
}

void Heavy_SoundScraper::cCast_qcFXmSGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pl2SKrD0, 0, m, &cDelay_pl2SKrD0_sendMessage);
}

void Heavy_SoundScraper::cMsg_arWoycWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kuvsJItJ, 2, m, &cDelay_kuvsJItJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_9GMFoFjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GDROM89T, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_YWNjHKxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2DXRRrt2_sendMessage);
}

void Heavy_SoundScraper::cSystem_2DXRRrt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FraXShlH_sendMessage);
}

void Heavy_SoundScraper::cDelay_cxNeWQ8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cxNeWQ8e, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iDcdCeLg, 0, m, &cDelay_iDcdCeLg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cxNeWQ8e, 0, m, &cDelay_cxNeWQ8e_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mtYgfeBy, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_iDcdCeLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iDcdCeLg, m);
  cMsg_BqS0wkky_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_FU1ysFto_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_aob0GB4l_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_ozQB3rSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TCH1IpFd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_CtaVjDDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PNxmFpsi_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cxNeWQ8e, 2, m, &cDelay_cxNeWQ8e_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VeyuCPMe_sendMessage);
}

void Heavy_SoundScraper::cMsg_TCH1IpFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_CtaVjDDf, 0, m, &hTable_CtaVjDDf_sendMessage);
}

void Heavy_SoundScraper::cBinop_FraXShlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_ozQB3rSR_sendMessage);
}

void Heavy_SoundScraper::cMsg_BqS0wkky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_CtaVjDDf, 0, m, &hTable_CtaVjDDf_sendMessage);
}

void Heavy_SoundScraper::cCast_VeyuCPMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cxNeWQ8e, 0, m, &cDelay_cxNeWQ8e_sendMessage);
}

void Heavy_SoundScraper::cMsg_PNxmFpsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_iDcdCeLg, 2, m, &cDelay_iDcdCeLg_sendMessage);
}

void Heavy_SoundScraper::cMsg_aob0GB4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mtYgfeBy, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_dzUjOzfy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZvNlA6Rn_sendMessage);
}

void Heavy_SoundScraper::cSystem_ZvNlA6Rn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_klWbEc1h_sendMessage);
}

void Heavy_SoundScraper::cDelay_fePuE3H0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fePuE3H0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TwT0OYQK, 0, m, &cDelay_TwT0OYQK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fePuE3H0, 0, m, &cDelay_fePuE3H0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_S9gJQoGt, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_TwT0OYQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TwT0OYQK, m);
  cMsg_LjX0KfaG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_oHvQWCBY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_To4RRRCw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Rb5bMzWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kbce9aVc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_cWZLWzF9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kVHUwTgU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fePuE3H0, 2, m, &cDelay_fePuE3H0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oq0TPMKK_sendMessage);
}

void Heavy_SoundScraper::cMsg_kbce9aVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_cWZLWzF9, 0, m, &hTable_cWZLWzF9_sendMessage);
}

void Heavy_SoundScraper::cBinop_klWbEc1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_Rb5bMzWO_sendMessage);
}

void Heavy_SoundScraper::cMsg_LjX0KfaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_cWZLWzF9, 0, m, &hTable_cWZLWzF9_sendMessage);
}

void Heavy_SoundScraper::cCast_oq0TPMKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fePuE3H0, 0, m, &cDelay_fePuE3H0_sendMessage);
}

void Heavy_SoundScraper::cMsg_kVHUwTgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_TwT0OYQK, 2, m, &cDelay_TwT0OYQK_sendMessage);
}

void Heavy_SoundScraper::cMsg_To4RRRCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_S9gJQoGt, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Rt1Qrklw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wANPO0h8_sendMessage);
}

void Heavy_SoundScraper::cSystem_wANPO0h8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mEp6N5Wx_sendMessage);
}

void Heavy_SoundScraper::cDelay_f21ePFva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_f21ePFva, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_44sHUH4L, 0, m, &cDelay_44sHUH4L_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f21ePFva, 0, m, &cDelay_f21ePFva_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_75vpgRfb, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_44sHUH4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_44sHUH4L, m);
  cMsg_fJF9OZjL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_9jmFjVXq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Jf2r7JZy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_gY6Y0gba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s3J1rEN4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_LzIhUYZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dZ9snbdA_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f21ePFva, 2, m, &cDelay_f21ePFva_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pDk1GVI3_sendMessage);
}

void Heavy_SoundScraper::cMsg_s3J1rEN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_LzIhUYZh, 0, m, &hTable_LzIhUYZh_sendMessage);
}

void Heavy_SoundScraper::cBinop_mEp6N5Wx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_gY6Y0gba_sendMessage);
}

void Heavy_SoundScraper::cMsg_fJF9OZjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_LzIhUYZh, 0, m, &hTable_LzIhUYZh_sendMessage);
}

void Heavy_SoundScraper::cCast_pDk1GVI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_f21ePFva, 0, m, &cDelay_f21ePFva_sendMessage);
}

void Heavy_SoundScraper::cMsg_dZ9snbdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_44sHUH4L, 2, m, &cDelay_44sHUH4L_sendMessage);
}

void Heavy_SoundScraper::cMsg_Jf2r7JZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_75vpgRfb, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_YziLJCXL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_TnzzhCNu_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ghIYyf2v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_2stLgL9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hmtmw9em, HV_BINOP_POW, 0, m, &cBinop_Hmtmw9em_sendMessage);
}

void Heavy_SoundScraper::cBinop_Hmtmw9em_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_L0JzxtfE_sendMessage);
}

void Heavy_SoundScraper::cBinop_P3bD2bgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_4lXCw0DU_sendMessage);
}

void Heavy_SoundScraper::cCast_Ty8gabpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YziLJCXL, 0, m, &cIf_YziLJCXL_sendMessage);
}

void Heavy_SoundScraper::cCast_w1GvAEsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_qC4SIn9z_sendMessage);
}

void Heavy_SoundScraper::cBinop_qC4SIn9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YziLJCXL, 1, m, &cIf_YziLJCXL_sendMessage);
}

void Heavy_SoundScraper::cBinop_ghIYyf2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_P3bD2bgo_sendMessage);
}

void Heavy_SoundScraper::cMsg_TnzzhCNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_L0JzxtfE_sendMessage);
}

void Heavy_SoundScraper::cBinop_4lXCw0DU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hmtmw9em, HV_BINOP_POW, 1, m, &cBinop_Hmtmw9em_sendMessage);
  cMsg_2stLgL9Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_3IU7KAdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_I0C2aoof, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_xUKQRsOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_L0Mri4MD, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_2OaID9S4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RuRutswp_sendMessage);
}

void Heavy_SoundScraper::cBinop_RuRutswp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_svulPKLL_sendMessage);
}

void Heavy_SoundScraper::cVar_Gg3wX7s6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yl9IzLXJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Yl9IzLXJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_wtuBDsB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nVzQPmKD_sendMessage);
}

void Heavy_SoundScraper::cSystem_nVzQPmKD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kx4kJseg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Yl9IzLXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_67c9kNib_sendMessage);
}

void Heavy_SoundScraper::cBinop_HeuJ9Mj5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yl9IzLXJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Yl9IzLXJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_Kx4kJseg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HeuJ9Mj5_sendMessage);
}

void Heavy_SoundScraper::cBinop_67c9kNib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_eeUwnqq0_sendMessage);
}

void Heavy_SoundScraper::cBinop_eeUwnqq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FoOr93Yc_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_V8uZMcez, m);
}

void Heavy_SoundScraper::cBinop_FoOr93Yc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Vi60KykZ, m);
}

void Heavy_SoundScraper::cVar_mP0CCXDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w1GvAEsU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ty8gabpx_sendMessage);
}

void Heavy_SoundScraper::cVar_4visTvZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_2OaID9S4_sendMessage);
}

void Heavy_SoundScraper::cVar_wS6Sat5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_GxxKsCPj_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_MzljrOhT, 0, m, &cIf_MzljrOhT_sendMessage);
}

void Heavy_SoundScraper::cVar_zG44W7DL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_F4rAfop5_sendMessage);
}

void Heavy_SoundScraper::cIf_MzljrOhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_R7RqbHoC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_eIluss7d, 0, m, &cVar_eIluss7d_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_GxxKsCPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MzljrOhT, 1, m, &cIf_MzljrOhT_sendMessage);
}

void Heavy_SoundScraper::cBinop_F4rAfop5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_j2Roewea_sendMessage);
}

void Heavy_SoundScraper::cBinop_j2Roewea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_B3ivIb7A, 0, m, &cVar_B3ivIb7A_sendMessage);
}

void Heavy_SoundScraper::cTabhead_RgoFn4yl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6VrGXSPf, HV_BINOP_SUBTRACT, 0, m, &cBinop_6VrGXSPf_sendMessage);
}

void Heavy_SoundScraper::cMsg_7Ox1B1QB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KXBetMXr_sendMessage);
}

void Heavy_SoundScraper::cSystem_KXBetMXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PpflMcDX_sendMessage);
}

void Heavy_SoundScraper::cVar_Kzxz6EMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jaAe65HV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_SRvEW4Xq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SRvEW4Xq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kneQ2NyS, 0, m, &cDelay_kneQ2NyS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PsBaah8T, 0, m, &sTabread_PsBaah8T_sendMessage);
}

void Heavy_SoundScraper::cDelay_kneQ2NyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kneQ2NyS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PsBaah8T, 0, m, &sTabread_PsBaah8T_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kneQ2NyS, 0, m, &cDelay_kneQ2NyS_sendMessage);
}

void Heavy_SoundScraper::sTabread_PsBaah8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zP5hhZJJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_zP5hhZJJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_9fzbfx9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Eqhh9l1N, HV_BINOP_MAX, 0, m, &cBinop_Eqhh9l1N_sendMessage);
}

void Heavy_SoundScraper::cBinop_PpflMcDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9fzbfx9C, HV_BINOP_MULTIPLY, 0, m, &cBinop_9fzbfx9C_sendMessage);
}

void Heavy_SoundScraper::cBinop_6VrGXSPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zgp2WYSB_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PsBaah8T, 0, m, &sTabread_PsBaah8T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z0o197UT_sendMessage);
}

void Heavy_SoundScraper::cSystem_xbSM61xp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zP5hhZJJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_zP5hhZJJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kneQ2NyS, 2, m, &cDelay_kneQ2NyS_sendMessage);
}

void Heavy_SoundScraper::cMsg_jaAe65HV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xbSM61xp_sendMessage);
}

void Heavy_SoundScraper::cMsg_zgp2WYSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SRvEW4Xq, 0, m, &cDelay_SRvEW4Xq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kneQ2NyS, 0, m, &cDelay_kneQ2NyS_sendMessage);
}

void Heavy_SoundScraper::cMsg_qU5iHGTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Eqhh9l1N, HV_BINOP_MAX, 1, m, &cBinop_Eqhh9l1N_sendMessage);
}

void Heavy_SoundScraper::cBinop_Eqhh9l1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6VrGXSPf, HV_BINOP_SUBTRACT, 1, m, &cBinop_6VrGXSPf_sendMessage);
}

void Heavy_SoundScraper::cCast_z0o197UT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SRvEW4Xq, 0, m, &cDelay_SRvEW4Xq_sendMessage);
}

void Heavy_SoundScraper::cBinop_7NNNXgwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SRvEW4Xq, 2, m, &cDelay_SRvEW4Xq_sendMessage);
}

void Heavy_SoundScraper::cBinop_zP5hhZJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7NNNXgwY_sendMessage);
}

void Heavy_SoundScraper::cCast_2gCFzLye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Kzxz6EMx, 0, m, &cVar_Kzxz6EMx_sendMessage);
  cMsg_7Ox1B1QB_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RgoFn4yl, 0, m, &cTabhead_RgoFn4yl_sendMessage);
}

void Heavy_SoundScraper::cMsg_DCWFotXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0FI1Q8Tp_sendMessage);
}

void Heavy_SoundScraper::cSystem_0FI1Q8Tp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0xZKS5Rg_sendMessage);
}

void Heavy_SoundScraper::cDelay_wlLd6yyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wlLd6yyI, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QurGnv8D, 0, m, &cDelay_QurGnv8D_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wlLd6yyI, 0, m, &cDelay_wlLd6yyI_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RBetVyja, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_QurGnv8D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QurGnv8D, m);
  cMsg_CFVFQodz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_u9AsiGTO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_VNH0zKBx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_TpB8gGNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r4L1vrPv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_QS6oRB0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OVLbkZCy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wlLd6yyI, 2, m, &cDelay_wlLd6yyI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_18z3hZEz_sendMessage);
}

void Heavy_SoundScraper::cMsg_r4L1vrPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_QS6oRB0W, 0, m, &hTable_QS6oRB0W_sendMessage);
}

void Heavy_SoundScraper::cBinop_0xZKS5Rg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_TpB8gGNp_sendMessage);
}

void Heavy_SoundScraper::cMsg_CFVFQodz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_QS6oRB0W, 0, m, &hTable_QS6oRB0W_sendMessage);
}

void Heavy_SoundScraper::cCast_18z3hZEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wlLd6yyI, 0, m, &cDelay_wlLd6yyI_sendMessage);
}

void Heavy_SoundScraper::cMsg_OVLbkZCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_QurGnv8D, 2, m, &cDelay_QurGnv8D_sendMessage);
}

void Heavy_SoundScraper::cMsg_VNH0zKBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RBetVyja, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_5zleY9V1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dp8XddFN, HV_BINOP_SUBTRACT, 0, m, &cBinop_dp8XddFN_sendMessage);
}

void Heavy_SoundScraper::cMsg_Oa3UoCKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LQAYqJee_sendMessage);
}

void Heavy_SoundScraper::cSystem_LQAYqJee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gobBGuDz_sendMessage);
}

void Heavy_SoundScraper::cVar_EbrPn0lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cnMb6n62_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_CnIZR3RP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CnIZR3RP, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rOyxK6g1, 0, m, &cDelay_rOyxK6g1_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ggfxdbHw, 0, m, &sTabread_ggfxdbHw_sendMessage);
}

void Heavy_SoundScraper::cDelay_rOyxK6g1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rOyxK6g1, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ggfxdbHw, 0, m, &sTabread_ggfxdbHw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rOyxK6g1, 0, m, &cDelay_rOyxK6g1_sendMessage);
}

void Heavy_SoundScraper::sTabread_ggfxdbHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_WOHJcVPM, HV_BINOP_SUBTRACT, 0, m, &cBinop_WOHJcVPM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_HtY283V1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e40qFHnd, HV_BINOP_MAX, 0, m, &cBinop_e40qFHnd_sendMessage);
}

void Heavy_SoundScraper::cBinop_gobBGuDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HtY283V1, HV_BINOP_MULTIPLY, 0, m, &cBinop_HtY283V1_sendMessage);
}

void Heavy_SoundScraper::cBinop_dp8XddFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LHlaGsNk_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ggfxdbHw, 0, m, &sTabread_ggfxdbHw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vduqGOIq_sendMessage);
}

void Heavy_SoundScraper::cSystem_YDFwSqp1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WOHJcVPM, HV_BINOP_SUBTRACT, 1, m, &cBinop_WOHJcVPM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rOyxK6g1, 2, m, &cDelay_rOyxK6g1_sendMessage);
}

void Heavy_SoundScraper::cMsg_cnMb6n62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YDFwSqp1_sendMessage);
}

void Heavy_SoundScraper::cMsg_LHlaGsNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CnIZR3RP, 0, m, &cDelay_CnIZR3RP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rOyxK6g1, 0, m, &cDelay_rOyxK6g1_sendMessage);
}

void Heavy_SoundScraper::cMsg_Uwpcn9LO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_e40qFHnd, HV_BINOP_MAX, 1, m, &cBinop_e40qFHnd_sendMessage);
}

void Heavy_SoundScraper::cBinop_e40qFHnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dp8XddFN, HV_BINOP_SUBTRACT, 1, m, &cBinop_dp8XddFN_sendMessage);
}

void Heavy_SoundScraper::cCast_vduqGOIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CnIZR3RP, 0, m, &cDelay_CnIZR3RP_sendMessage);
}

void Heavy_SoundScraper::cBinop_3dj5Byez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CnIZR3RP, 2, m, &cDelay_CnIZR3RP_sendMessage);
}

void Heavy_SoundScraper::cBinop_WOHJcVPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3dj5Byez_sendMessage);
}

void Heavy_SoundScraper::cCast_Q2bxJcOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EbrPn0lj, 0, m, &cVar_EbrPn0lj_sendMessage);
  cMsg_Oa3UoCKG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5zleY9V1, 0, m, &cTabhead_5zleY9V1_sendMessage);
}

void Heavy_SoundScraper::cMsg_Y5PvF4K4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tuxR2tZk_sendMessage);
}

void Heavy_SoundScraper::cSystem_tuxR2tZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zLxk7RHh_sendMessage);
}

void Heavy_SoundScraper::cDelay_csNPcvw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_csNPcvw6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wxxi4WE2, 0, m, &cDelay_wxxi4WE2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_csNPcvw6, 0, m, &cDelay_csNPcvw6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Q8k3vA1z, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_wxxi4WE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wxxi4WE2, m);
  cMsg_8SlQZytX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_2ljRhNZZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_GOncorIu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_7uQp1cKS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w0r5pE6n_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_0HOxNfI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LJ3n9mkH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_csNPcvw6, 2, m, &cDelay_csNPcvw6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FyLP2nrz_sendMessage);
}

void Heavy_SoundScraper::cMsg_w0r5pE6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_0HOxNfI7, 0, m, &hTable_0HOxNfI7_sendMessage);
}

void Heavy_SoundScraper::cBinop_zLxk7RHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_7uQp1cKS_sendMessage);
}

void Heavy_SoundScraper::cMsg_8SlQZytX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_0HOxNfI7, 0, m, &hTable_0HOxNfI7_sendMessage);
}

void Heavy_SoundScraper::cCast_FyLP2nrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_csNPcvw6, 0, m, &cDelay_csNPcvw6_sendMessage);
}

void Heavy_SoundScraper::cMsg_LJ3n9mkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_wxxi4WE2, 2, m, &cDelay_wxxi4WE2_sendMessage);
}

void Heavy_SoundScraper::cMsg_GOncorIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Q8k3vA1z, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_dpeliT6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gf1O6YjE, HV_BINOP_SUBTRACT, 0, m, &cBinop_gf1O6YjE_sendMessage);
}

void Heavy_SoundScraper::cMsg_AwBLh0Fg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YZeKKyIm_sendMessage);
}

void Heavy_SoundScraper::cSystem_YZeKKyIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0RcIqOkm_sendMessage);
}

void Heavy_SoundScraper::cVar_ukDOVf2S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BGJawrD9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_08XaGH1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_08XaGH1s, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VhNB35ln, 0, m, &cDelay_VhNB35ln_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_LcaVlVgU, 0, m, &sTabread_LcaVlVgU_sendMessage);
}

void Heavy_SoundScraper::cDelay_VhNB35ln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VhNB35ln, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_LcaVlVgU, 0, m, &sTabread_LcaVlVgU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VhNB35ln, 0, m, &cDelay_VhNB35ln_sendMessage);
}

void Heavy_SoundScraper::sTabread_LcaVlVgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RTFEf7wm, HV_BINOP_SUBTRACT, 0, m, &cBinop_RTFEf7wm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_AdJ7gHlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ka64d9ND, HV_BINOP_MAX, 0, m, &cBinop_ka64d9ND_sendMessage);
}

void Heavy_SoundScraper::cBinop_0RcIqOkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AdJ7gHlo, HV_BINOP_MULTIPLY, 0, m, &cBinop_AdJ7gHlo_sendMessage);
}

void Heavy_SoundScraper::cBinop_gf1O6YjE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xIlLA1n2_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_LcaVlVgU, 0, m, &sTabread_LcaVlVgU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6cfVDNhw_sendMessage);
}

void Heavy_SoundScraper::cSystem_Byv5PfSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RTFEf7wm, HV_BINOP_SUBTRACT, 1, m, &cBinop_RTFEf7wm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VhNB35ln, 2, m, &cDelay_VhNB35ln_sendMessage);
}

void Heavy_SoundScraper::cMsg_BGJawrD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Byv5PfSv_sendMessage);
}

void Heavy_SoundScraper::cMsg_xIlLA1n2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_08XaGH1s, 0, m, &cDelay_08XaGH1s_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VhNB35ln, 0, m, &cDelay_VhNB35ln_sendMessage);
}

void Heavy_SoundScraper::cMsg_nUaAEKvl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ka64d9ND, HV_BINOP_MAX, 1, m, &cBinop_ka64d9ND_sendMessage);
}

void Heavy_SoundScraper::cBinop_ka64d9ND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gf1O6YjE, HV_BINOP_SUBTRACT, 1, m, &cBinop_gf1O6YjE_sendMessage);
}

void Heavy_SoundScraper::cCast_6cfVDNhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_08XaGH1s, 0, m, &cDelay_08XaGH1s_sendMessage);
}

void Heavy_SoundScraper::cBinop_2o9oD8FB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_08XaGH1s, 2, m, &cDelay_08XaGH1s_sendMessage);
}

void Heavy_SoundScraper::cBinop_RTFEf7wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2o9oD8FB_sendMessage);
}

void Heavy_SoundScraper::cCast_4WMDJjnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ukDOVf2S, 0, m, &cVar_ukDOVf2S_sendMessage);
  cMsg_AwBLh0Fg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_dpeliT6G, 0, m, &cTabhead_dpeliT6G_sendMessage);
}

void Heavy_SoundScraper::cMsg_JxPlOIhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SuZXmUs0_sendMessage);
}

void Heavy_SoundScraper::cSystem_SuZXmUs0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6nQNnbbs_sendMessage);
}

void Heavy_SoundScraper::cDelay_65DPaNYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_65DPaNYR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_amSaCWvP, 0, m, &cDelay_amSaCWvP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_65DPaNYR, 0, m, &cDelay_65DPaNYR_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_E5p68zQV, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_amSaCWvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_amSaCWvP, m);
  cMsg_th18EbXY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_N3ollojA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ZQVvH8in_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_OzMnvlac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pJmPjoMF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_SNZe3goA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AQWFxVEw_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_65DPaNYR, 2, m, &cDelay_65DPaNYR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_swNq4UzT_sendMessage);
}

void Heavy_SoundScraper::cMsg_pJmPjoMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_SNZe3goA, 0, m, &hTable_SNZe3goA_sendMessage);
}

void Heavy_SoundScraper::cBinop_6nQNnbbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_OzMnvlac_sendMessage);
}

void Heavy_SoundScraper::cMsg_th18EbXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_SNZe3goA, 0, m, &hTable_SNZe3goA_sendMessage);
}

void Heavy_SoundScraper::cCast_swNq4UzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_65DPaNYR, 0, m, &cDelay_65DPaNYR_sendMessage);
}

void Heavy_SoundScraper::cMsg_AQWFxVEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_amSaCWvP, 2, m, &cDelay_amSaCWvP_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZQVvH8in_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_E5p68zQV, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_EZOzVat6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ftt8mzKN, HV_BINOP_SUBTRACT, 0, m, &cBinop_ftt8mzKN_sendMessage);
}

void Heavy_SoundScraper::cMsg_4XfO5Qmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a11MtCB3_sendMessage);
}

void Heavy_SoundScraper::cSystem_a11MtCB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UmK3euqm_sendMessage);
}

void Heavy_SoundScraper::cVar_CQcLsCfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_58e0ZfuV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_3Z19Lses_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3Z19Lses, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_e0q8rcyt, 0, m, &cDelay_e0q8rcyt_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FvaD7CXE, 0, m, &sTabread_FvaD7CXE_sendMessage);
}

void Heavy_SoundScraper::cDelay_e0q8rcyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_e0q8rcyt, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FvaD7CXE, 0, m, &sTabread_FvaD7CXE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_e0q8rcyt, 0, m, &cDelay_e0q8rcyt_sendMessage);
}

void Heavy_SoundScraper::sTabread_FvaD7CXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mcqiaPf9, HV_BINOP_SUBTRACT, 0, m, &cBinop_mcqiaPf9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_k9Dzpngh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rl9xNTgB, HV_BINOP_MAX, 0, m, &cBinop_Rl9xNTgB_sendMessage);
}

void Heavy_SoundScraper::cBinop_UmK3euqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k9Dzpngh, HV_BINOP_MULTIPLY, 0, m, &cBinop_k9Dzpngh_sendMessage);
}

void Heavy_SoundScraper::cBinop_ftt8mzKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7eoMxq9L_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FvaD7CXE, 0, m, &sTabread_FvaD7CXE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ew9TanWD_sendMessage);
}

void Heavy_SoundScraper::cSystem_n5tpdbDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mcqiaPf9, HV_BINOP_SUBTRACT, 1, m, &cBinop_mcqiaPf9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_e0q8rcyt, 2, m, &cDelay_e0q8rcyt_sendMessage);
}

void Heavy_SoundScraper::cMsg_58e0ZfuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n5tpdbDX_sendMessage);
}

void Heavy_SoundScraper::cMsg_7eoMxq9L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3Z19Lses, 0, m, &cDelay_3Z19Lses_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_e0q8rcyt, 0, m, &cDelay_e0q8rcyt_sendMessage);
}

void Heavy_SoundScraper::cMsg_j1ar58IO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rl9xNTgB, HV_BINOP_MAX, 1, m, &cBinop_Rl9xNTgB_sendMessage);
}

void Heavy_SoundScraper::cBinop_Rl9xNTgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ftt8mzKN, HV_BINOP_SUBTRACT, 1, m, &cBinop_ftt8mzKN_sendMessage);
}

void Heavy_SoundScraper::cCast_ew9TanWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3Z19Lses, 0, m, &cDelay_3Z19Lses_sendMessage);
}

void Heavy_SoundScraper::cBinop_uv7QVLsE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3Z19Lses, 2, m, &cDelay_3Z19Lses_sendMessage);
}

void Heavy_SoundScraper::cBinop_mcqiaPf9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uv7QVLsE_sendMessage);
}

void Heavy_SoundScraper::cCast_RUNDXKKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CQcLsCfj, 0, m, &cVar_CQcLsCfj_sendMessage);
  cMsg_4XfO5Qmz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EZOzVat6, 0, m, &cTabhead_EZOzVat6_sendMessage);
}

void Heavy_SoundScraper::cMsg_WGqjqJuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X7ZDnFxw_sendMessage);
}

void Heavy_SoundScraper::cSystem_X7ZDnFxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pskMx1GH_sendMessage);
}

void Heavy_SoundScraper::cDelay_bZohRPp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bZohRPp4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CS3V4JCF, 0, m, &cDelay_CS3V4JCF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bZohRPp4, 0, m, &cDelay_bZohRPp4_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hCbNLFPd, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_CS3V4JCF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CS3V4JCF, m);
  cMsg_eU7cL3wB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_J7bN6K62_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_bFblVpiI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_NzSwbJOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qf9g0vtk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_H4gx4UDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KhUfgW3Y_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bZohRPp4, 2, m, &cDelay_bZohRPp4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xWRNtk1z_sendMessage);
}

void Heavy_SoundScraper::cMsg_qf9g0vtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_H4gx4UDe, 0, m, &hTable_H4gx4UDe_sendMessage);
}

void Heavy_SoundScraper::cBinop_pskMx1GH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_NzSwbJOz_sendMessage);
}

void Heavy_SoundScraper::cMsg_eU7cL3wB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_H4gx4UDe, 0, m, &hTable_H4gx4UDe_sendMessage);
}

void Heavy_SoundScraper::cCast_xWRNtk1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bZohRPp4, 0, m, &cDelay_bZohRPp4_sendMessage);
}

void Heavy_SoundScraper::cMsg_KhUfgW3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_CS3V4JCF, 2, m, &cDelay_CS3V4JCF_sendMessage);
}

void Heavy_SoundScraper::cMsg_bFblVpiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hCbNLFPd, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_6l2AfMcQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kFzv1wYG, HV_BINOP_SUBTRACT, 0, m, &cBinop_kFzv1wYG_sendMessage);
}

void Heavy_SoundScraper::cMsg_54lCjedC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0QbvEPqA_sendMessage);
}

void Heavy_SoundScraper::cSystem_0QbvEPqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vZA4OK2E_sendMessage);
}

void Heavy_SoundScraper::cVar_Ta4avafL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WoRzu3FG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_Q0TO7Wu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Q0TO7Wu2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p3f0znUi, 0, m, &cDelay_p3f0znUi_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4UhmKvR8, 0, m, &sTabread_4UhmKvR8_sendMessage);
}

void Heavy_SoundScraper::cDelay_p3f0znUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_p3f0znUi, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4UhmKvR8, 0, m, &sTabread_4UhmKvR8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p3f0znUi, 0, m, &cDelay_p3f0znUi_sendMessage);
}

void Heavy_SoundScraper::sTabread_4UhmKvR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rLO6Wf6V, HV_BINOP_SUBTRACT, 0, m, &cBinop_rLO6Wf6V_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_IskQbfAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hx96AGLk, HV_BINOP_MAX, 0, m, &cBinop_hx96AGLk_sendMessage);
}

void Heavy_SoundScraper::cBinop_vZA4OK2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IskQbfAR, HV_BINOP_MULTIPLY, 0, m, &cBinop_IskQbfAR_sendMessage);
}

void Heavy_SoundScraper::cBinop_kFzv1wYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MuzWoyQf_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4UhmKvR8, 0, m, &sTabread_4UhmKvR8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SCpkUwFQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_nCremxdT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rLO6Wf6V, HV_BINOP_SUBTRACT, 1, m, &cBinop_rLO6Wf6V_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p3f0znUi, 2, m, &cDelay_p3f0znUi_sendMessage);
}

void Heavy_SoundScraper::cMsg_WoRzu3FG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nCremxdT_sendMessage);
}

void Heavy_SoundScraper::cMsg_MuzWoyQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q0TO7Wu2, 0, m, &cDelay_Q0TO7Wu2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p3f0znUi, 0, m, &cDelay_p3f0znUi_sendMessage);
}

void Heavy_SoundScraper::cMsg_swjZxoUP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_hx96AGLk, HV_BINOP_MAX, 1, m, &cBinop_hx96AGLk_sendMessage);
}

void Heavy_SoundScraper::cBinop_hx96AGLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kFzv1wYG, HV_BINOP_SUBTRACT, 1, m, &cBinop_kFzv1wYG_sendMessage);
}

void Heavy_SoundScraper::cCast_SCpkUwFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q0TO7Wu2, 0, m, &cDelay_Q0TO7Wu2_sendMessage);
}

void Heavy_SoundScraper::cBinop_CPCXaC3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q0TO7Wu2, 2, m, &cDelay_Q0TO7Wu2_sendMessage);
}

void Heavy_SoundScraper::cBinop_rLO6Wf6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_CPCXaC3q_sendMessage);
}

void Heavy_SoundScraper::cCast_CkH1UM5n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ta4avafL, 0, m, &cVar_Ta4avafL_sendMessage);
  cMsg_54lCjedC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6l2AfMcQ, 0, m, &cTabhead_6l2AfMcQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZS4gixRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rMbFCbUT_sendMessage);
}

void Heavy_SoundScraper::cSystem_rMbFCbUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eFYaiYfL_sendMessage);
}

void Heavy_SoundScraper::cDelay_S9AxcHtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_S9AxcHtb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FRKS9Rux, 0, m, &cDelay_FRKS9Rux_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S9AxcHtb, 0, m, &cDelay_S9AxcHtb_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_p8O038Oy, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_FRKS9Rux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FRKS9Rux, m);
  cMsg_ZWl4PxW0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_64zuVmCf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_w7ZSI0mw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_V6iByv7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oUd4Z6Qh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_QyEdTLTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LoxV8IYS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S9AxcHtb, 2, m, &cDelay_S9AxcHtb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T8qFwukv_sendMessage);
}

void Heavy_SoundScraper::cMsg_oUd4Z6Qh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_QyEdTLTC, 0, m, &hTable_QyEdTLTC_sendMessage);
}

void Heavy_SoundScraper::cBinop_eFYaiYfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_V6iByv7d_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZWl4PxW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_QyEdTLTC, 0, m, &hTable_QyEdTLTC_sendMessage);
}

void Heavy_SoundScraper::cCast_T8qFwukv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_S9AxcHtb, 0, m, &cDelay_S9AxcHtb_sendMessage);
}

void Heavy_SoundScraper::cMsg_LoxV8IYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_FRKS9Rux, 2, m, &cDelay_FRKS9Rux_sendMessage);
}

void Heavy_SoundScraper::cMsg_w7ZSI0mw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_p8O038Oy, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_ycEFOiMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9qO1I8gT, HV_BINOP_SUBTRACT, 0, m, &cBinop_9qO1I8gT_sendMessage);
}

void Heavy_SoundScraper::cMsg_gxoBYXch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YQx4bgTB_sendMessage);
}

void Heavy_SoundScraper::cSystem_YQx4bgTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nsLzjboc_sendMessage);
}

void Heavy_SoundScraper::cVar_ZBBMvkxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XLfksd5H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_pjoII6rT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pjoII6rT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_avKGsGP2, 0, m, &cDelay_avKGsGP2_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wUW8qMXA, 0, m, &sTabread_wUW8qMXA_sendMessage);
}

void Heavy_SoundScraper::cDelay_avKGsGP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_avKGsGP2, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wUW8qMXA, 0, m, &sTabread_wUW8qMXA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_avKGsGP2, 0, m, &cDelay_avKGsGP2_sendMessage);
}

void Heavy_SoundScraper::sTabread_wUW8qMXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LiR6s60q, HV_BINOP_SUBTRACT, 0, m, &cBinop_LiR6s60q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_FIaNk7Df_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oK9qJkE3, HV_BINOP_MAX, 0, m, &cBinop_oK9qJkE3_sendMessage);
}

void Heavy_SoundScraper::cBinop_nsLzjboc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FIaNk7Df, HV_BINOP_MULTIPLY, 0, m, &cBinop_FIaNk7Df_sendMessage);
}

void Heavy_SoundScraper::cBinop_9qO1I8gT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iytKg538_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wUW8qMXA, 0, m, &sTabread_wUW8qMXA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S1jJfOQg_sendMessage);
}

void Heavy_SoundScraper::cSystem_1nzxGdI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LiR6s60q, HV_BINOP_SUBTRACT, 1, m, &cBinop_LiR6s60q_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_avKGsGP2, 2, m, &cDelay_avKGsGP2_sendMessage);
}

void Heavy_SoundScraper::cMsg_XLfksd5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1nzxGdI3_sendMessage);
}

void Heavy_SoundScraper::cMsg_iytKg538_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pjoII6rT, 0, m, &cDelay_pjoII6rT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_avKGsGP2, 0, m, &cDelay_avKGsGP2_sendMessage);
}

void Heavy_SoundScraper::cMsg_aegZRSgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_oK9qJkE3, HV_BINOP_MAX, 1, m, &cBinop_oK9qJkE3_sendMessage);
}

void Heavy_SoundScraper::cBinop_oK9qJkE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9qO1I8gT, HV_BINOP_SUBTRACT, 1, m, &cBinop_9qO1I8gT_sendMessage);
}

void Heavy_SoundScraper::cCast_S1jJfOQg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pjoII6rT, 0, m, &cDelay_pjoII6rT_sendMessage);
}

void Heavy_SoundScraper::cBinop_tXt6844q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pjoII6rT, 2, m, &cDelay_pjoII6rT_sendMessage);
}

void Heavy_SoundScraper::cBinop_LiR6s60q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tXt6844q_sendMessage);
}

void Heavy_SoundScraper::cCast_fh5ygA4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZBBMvkxm, 0, m, &cVar_ZBBMvkxm_sendMessage);
  cMsg_gxoBYXch_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ycEFOiMW, 0, m, &cTabhead_ycEFOiMW_sendMessage);
}

void Heavy_SoundScraper::cMsg_JVqs0KQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3G51WmYO_sendMessage);
}

void Heavy_SoundScraper::cSystem_3G51WmYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XfeemtTn_sendMessage);
}

void Heavy_SoundScraper::cDelay_mWQlOlS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mWQlOlS9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sJc0lShQ, 0, m, &cDelay_sJc0lShQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mWQlOlS9, 0, m, &cDelay_mWQlOlS9_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fyfmrotI, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_sJc0lShQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sJc0lShQ, m);
  cMsg_aZgTOgST_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_knnQyp1I_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_vdYN4b3L_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_JsYxNjQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uchScNJd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_edoVP1Zx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1Rd4wtdO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mWQlOlS9, 2, m, &cDelay_mWQlOlS9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4NwiAEXX_sendMessage);
}

void Heavy_SoundScraper::cMsg_uchScNJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_edoVP1Zx, 0, m, &hTable_edoVP1Zx_sendMessage);
}

void Heavy_SoundScraper::cBinop_XfeemtTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_JsYxNjQv_sendMessage);
}

void Heavy_SoundScraper::cMsg_aZgTOgST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_edoVP1Zx, 0, m, &hTable_edoVP1Zx_sendMessage);
}

void Heavy_SoundScraper::cCast_4NwiAEXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mWQlOlS9, 0, m, &cDelay_mWQlOlS9_sendMessage);
}

void Heavy_SoundScraper::cMsg_1Rd4wtdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_sJc0lShQ, 2, m, &cDelay_sJc0lShQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_vdYN4b3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fyfmrotI, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_eIluss7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Gg3wX7s6, 0, m, &cVar_Gg3wX7s6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wzvDFJQl, 0, m, &cVar_wzvDFJQl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kTNyIV3i, 0, m, &cVar_kTNyIV3i_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_P08ow6rl, 0, m, &cVar_P08ow6rl_sendMessage);
}

void Heavy_SoundScraper::cVar_B3ivIb7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_jKMZYGXZ_sendMessage);
}

void Heavy_SoundScraper::cPack_54xl4frO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_WWwnhSwT, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_wzvDFJQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oOukCmwi, HV_BINOP_MULTIPLY, 0, m, &cBinop_oOukCmwi_sendMessage);
}

void Heavy_SoundScraper::cMsg_rjoApHC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gqjUwzzQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_gqjUwzzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nzzfRMD0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_oOukCmwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7Aq5jF2G_sendMessage);
}

void Heavy_SoundScraper::cBinop_MqzWEBfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oOukCmwi, HV_BINOP_MULTIPLY, 1, m, &cBinop_oOukCmwi_sendMessage);
}

void Heavy_SoundScraper::cMsg_nzzfRMD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MqzWEBfH_sendMessage);
}

void Heavy_SoundScraper::cBinop_7Aq5jF2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_voDUp7Xb_sendMessage);
}

void Heavy_SoundScraper::cBinop_voDUp7Xb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GwV4HLUj_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VPtWp3dg, m);
}

void Heavy_SoundScraper::cBinop_GwV4HLUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aA9uIeCY, m);
}

void Heavy_SoundScraper::cVar_kTNyIV3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_op6eVGUZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_op6eVGUZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_R11h8PbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_C8kfN4aH_sendMessage);
}

void Heavy_SoundScraper::cSystem_C8kfN4aH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_acVHcgZU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_op6eVGUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_uBUVkjmu_sendMessage);
}

void Heavy_SoundScraper::cBinop_lzoAQxci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_op6eVGUZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_op6eVGUZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_acVHcgZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lzoAQxci_sendMessage);
}

void Heavy_SoundScraper::cBinop_uBUVkjmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ywy66ORm_sendMessage);
}

void Heavy_SoundScraper::cBinop_ywy66ORm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XUEMvZ4s_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_aMasXeyY, m);
}

void Heavy_SoundScraper::cBinop_XUEMvZ4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fXOfthC0, m);
}

void Heavy_SoundScraper::cVar_P08ow6rl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GTW9ymOj, HV_BINOP_MULTIPLY, 0, m, &cBinop_GTW9ymOj_sendMessage);
}

void Heavy_SoundScraper::cMsg_6B8jjAeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QSUVaoBR_sendMessage);
}

void Heavy_SoundScraper::cSystem_QSUVaoBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TPk8WTxd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_GTW9ymOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5ZDISK2L_sendMessage);
}

void Heavy_SoundScraper::cBinop_MCqHramC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GTW9ymOj, HV_BINOP_MULTIPLY, 1, m, &cBinop_GTW9ymOj_sendMessage);
}

void Heavy_SoundScraper::cMsg_TPk8WTxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MCqHramC_sendMessage);
}

void Heavy_SoundScraper::cBinop_5ZDISK2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6jOwrlPL_sendMessage);
}

void Heavy_SoundScraper::cBinop_6jOwrlPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FUtyEj4R_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rBmWDtRe, m);
}

void Heavy_SoundScraper::cBinop_FUtyEj4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_M0Ov1nfT, m);
}

void Heavy_SoundScraper::cBinop_svulPKLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_xUKQRsOz, 0, m, &cPack_xUKQRsOz_sendMessage);
}

void Heavy_SoundScraper::cMsg_R7RqbHoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_eIluss7d, 0, m, &cVar_eIluss7d_sendMessage);
}

void Heavy_SoundScraper::cBinop_jKMZYGXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_54xl4frO, 0, m, &cPack_54xl4frO_sendMessage);
}

void Heavy_SoundScraper::cBinop_L0JzxtfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3IU7KAdS, 0, m, &cPack_3IU7KAdS_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_o2Exdedo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_xYDYxm18_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_xYDYxm18_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_GQU6qCzK, 1, m, &cDelay_GQU6qCzK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uSDy2tUw_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_GQU6qCzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GQU6qCzK, m);
  cMsg_vivvT3jh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_xYDYxm18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GQU6qCzK, 0, m, &cDelay_GQU6qCzK_sendMessage);
}

void Heavy_SoundScraper::cCast_uSDy2tUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GQU6qCzK, 0, m, &cDelay_GQU6qCzK_sendMessage);
}

void Heavy_SoundScraper::cVar_KsSslCDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zgGZN6z8, 0, m, &cPack_zgGZN6z8_sendMessage);
}

void Heavy_SoundScraper::cVar_GjZgFfXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_m5080FBf_sendMessage);
}

void Heavy_SoundScraper::cVar_MqEjonNT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kAiLGiZq_sendMessage);
}

void Heavy_SoundScraper::cPack_PrhhJfXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_M9xlmo4f, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_C6orfzIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_atiovahP_sendMessage);
}

void Heavy_SoundScraper::cBinop_hxJlxuN9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_C6orfzIG_sendMessage);
}

void Heavy_SoundScraper::cPack_DqdwQPVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_YTT8XtFC, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_XPBRfSBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_geiXcbbx_sendMessage);
}

void Heavy_SoundScraper::cMsg_U5dCsBoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_somsoxtR_sendMessage);
}

void Heavy_SoundScraper::cSystem_somsoxtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tlzxhXZc_sendMessage);
}

void Heavy_SoundScraper::cDelay_nDo88GqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nDo88GqF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uqLsNmNL, 0, m, &cDelay_uqLsNmNL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nDo88GqF, 0, m, &cDelay_nDo88GqF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ct1Wegjp, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_uqLsNmNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uqLsNmNL, m);
  cMsg_hc6a5bRX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_5fcoSHqm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_my5De1CZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_IvuTZ37x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wKCDTP1u_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_URmk7nqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kfN9wYtX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nDo88GqF, 2, m, &cDelay_nDo88GqF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yu4WBvJT_sendMessage);
}

void Heavy_SoundScraper::cMsg_wKCDTP1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_URmk7nqK, 0, m, &hTable_URmk7nqK_sendMessage);
}

void Heavy_SoundScraper::cBinop_tlzxhXZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_IvuTZ37x_sendMessage);
}

void Heavy_SoundScraper::cMsg_hc6a5bRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_URmk7nqK, 0, m, &hTable_URmk7nqK_sendMessage);
}

void Heavy_SoundScraper::cCast_yu4WBvJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nDo88GqF, 0, m, &cDelay_nDo88GqF_sendMessage);
}

void Heavy_SoundScraper::cMsg_kfN9wYtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_uqLsNmNL, 2, m, &cDelay_uqLsNmNL_sendMessage);
}

void Heavy_SoundScraper::cMsg_my5De1CZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ct1Wegjp, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_6Y0BxhdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8Fg8CKEk_sendMessage);
}

void Heavy_SoundScraper::cSystem_8Fg8CKEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UgiYAoGz_sendMessage);
}

void Heavy_SoundScraper::cVar_VbxWM3Un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FLmxTHRp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Dpz6PilY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XhyWrbfx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nVlwjyvd, m);
}

void Heavy_SoundScraper::cBinop_UgiYAoGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mMzD57Sg, m);
}

void Heavy_SoundScraper::cMsg_FLmxTHRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Dpz6PilY_sendMessage);
}

void Heavy_SoundScraper::cBinop_XhyWrbfx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VdNxmPuz, m);
}

void Heavy_SoundScraper::cMsg_O2WkWQeL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XGIgFLZ6_sendMessage);
}

void Heavy_SoundScraper::cSystem_XGIgFLZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kPhYfvQv_sendMessage);
}

void Heavy_SoundScraper::cVar_0ge6cK5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GTCmWIRx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_CiSApxaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ec579aj3_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cgXsj42x, m);
}

void Heavy_SoundScraper::cBinop_kPhYfvQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gEo7sCCx, m);
}

void Heavy_SoundScraper::cMsg_GTCmWIRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CiSApxaI_sendMessage);
}

void Heavy_SoundScraper::cBinop_ec579aj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ogkZbUw8, m);
}

void Heavy_SoundScraper::cBinop_MUQhChzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yWterVqw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_yJHJi8t8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vuAMW5Ii_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qxxLY8WX_sendMessage);
}

void Heavy_SoundScraper::cCast_vuAMW5Ii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MUQhChzG, HV_BINOP_DIVIDE, 1, m, &cBinop_MUQhChzG_sendMessage);
}

void Heavy_SoundScraper::cCast_qxxLY8WX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MUQhChzG, HV_BINOP_DIVIDE, 0, m, &cBinop_MUQhChzG_sendMessage);
}

void Heavy_SoundScraper::cBinop_atiovahP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xZLrfLXn_sendMessage);
}

void Heavy_SoundScraper::cBinop_m5080FBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_hxJlxuN9_sendMessage);
}

void Heavy_SoundScraper::cBinop_xZLrfLXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MUQhChzG, HV_BINOP_DIVIDE, 0, m, &cBinop_MUQhChzG_sendMessage);
}

void Heavy_SoundScraper::cBinop_geiXcbbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DqdwQPVg, 0, m, &cPack_DqdwQPVg_sendMessage);
}

void Heavy_SoundScraper::cBinop_kAiLGiZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_yJHJi8t8_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_PrhhJfXl, 0, m, &cPack_PrhhJfXl_sendMessage);
}

void Heavy_SoundScraper::cMsg_eT8gJYFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_MqEjonNT, 0, m, &cVar_MqEjonNT_sendMessage);
}

void Heavy_SoundScraper::cMsg_JHQOCCoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_XPBRfSBb, 0, m, &cVar_XPBRfSBb_sendMessage);
}

void Heavy_SoundScraper::cMsg_yWterVqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Ev0c8Aaf, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_pU1yHqHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xQimIlqD, HV_BINOP_MULTIPLY, 0, m, &cBinop_xQimIlqD_sendMessage);
}

void Heavy_SoundScraper::cMsg_xtm5i9gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qdfNf2rh_sendMessage);
}

void Heavy_SoundScraper::cSystem_qdfNf2rh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cObLT7nU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_xQimIlqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_VbIZK0EF_sendMessage);
}

void Heavy_SoundScraper::cBinop_bfvMQA67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xQimIlqD, HV_BINOP_MULTIPLY, 1, m, &cBinop_xQimIlqD_sendMessage);
}

void Heavy_SoundScraper::cMsg_cObLT7nU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_bfvMQA67_sendMessage);
}

void Heavy_SoundScraper::cBinop_VbIZK0EF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ks3Vamiv_sendMessage);
}

void Heavy_SoundScraper::cBinop_ks3Vamiv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_crTj2j79_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GPWWp0o2, m);
}

void Heavy_SoundScraper::cBinop_crTj2j79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KvR0fcp4, m);
}

void Heavy_SoundScraper::cVar_SHGAn4qe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pkMZtSPb, HV_BINOP_MULTIPLY, 0, m, &cBinop_pkMZtSPb_sendMessage);
}

void Heavy_SoundScraper::cMsg_HF0ONWLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bQjgnqYl_sendMessage);
}

void Heavy_SoundScraper::cSystem_bQjgnqYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r2lOlUB8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_pkMZtSPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_DurdPG93_sendMessage);
}

void Heavy_SoundScraper::cBinop_lwmyB9H9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pkMZtSPb, HV_BINOP_MULTIPLY, 1, m, &cBinop_pkMZtSPb_sendMessage);
}

void Heavy_SoundScraper::cMsg_r2lOlUB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lwmyB9H9_sendMessage);
}

void Heavy_SoundScraper::cBinop_DurdPG93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rFMKGwOj_sendMessage);
}

void Heavy_SoundScraper::cBinop_rFMKGwOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_jIIbwqZP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ay4de1yY, m);
}

void Heavy_SoundScraper::cBinop_jIIbwqZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_v4Sidap8, m);
}

void Heavy_SoundScraper::cVar_e7d3Klab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aacg8GHP, HV_BINOP_MULTIPLY, 0, m, &cBinop_aacg8GHP_sendMessage);
}

void Heavy_SoundScraper::cMsg_qOYcukM7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mHnwMIPQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_mHnwMIPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xZyYZkwr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_aacg8GHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_OWJ7JESf_sendMessage);
}

void Heavy_SoundScraper::cBinop_8SAjonUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aacg8GHP, HV_BINOP_MULTIPLY, 1, m, &cBinop_aacg8GHP_sendMessage);
}

void Heavy_SoundScraper::cMsg_xZyYZkwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8SAjonUY_sendMessage);
}

void Heavy_SoundScraper::cBinop_OWJ7JESf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FXG8LuzL_sendMessage);
}

void Heavy_SoundScraper::cBinop_FXG8LuzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZGwq1u03_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jdt52v7I, m);
}

void Heavy_SoundScraper::cBinop_ZGwq1u03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BVPHV3Mp, m);
}

void Heavy_SoundScraper::cMsg_454eDPPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K4FKfwd5_sendMessage);
}

void Heavy_SoundScraper::cSystem_K4FKfwd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TETSYhvC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_54QA777q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_WIAXzAFs_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TC9Y0Qof, 0, m, &cIf_TC9Y0Qof_sendMessage);
}

void Heavy_SoundScraper::cIf_TC9Y0Qof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_2yudp8Ut_sendMessage(_c, 0, m);
      cMsg_gFxIZ7IN_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_hwyQRm1J_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_EPESqUBw_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_GXfAEF6D, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_WIAXzAFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TC9Y0Qof, 1, m, &cIf_TC9Y0Qof_sendMessage);
}

void Heavy_SoundScraper::cMsg_hwyQRm1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QArSwopV_sendMessage);
}

void Heavy_SoundScraper::cBinop_QArSwopV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eVXfaLfw, m);
}

void Heavy_SoundScraper::cBinop_EPESqUBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_idMimX7s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_idMimX7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_TvJKX5PB_sendMessage);
}

void Heavy_SoundScraper::cBinop_TvJKX5PB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qHNx0nLt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_qHNx0nLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_wJuW9Q5o_sendMessage);
}

void Heavy_SoundScraper::cBinop_wJuW9Q5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WabvFs7s, m);
}

void Heavy_SoundScraper::cBinop_f2W0U0mE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NGNUt5Ug, m);
}

void Heavy_SoundScraper::cMsg_TETSYhvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_f2W0U0mE_sendMessage);
}

void Heavy_SoundScraper::cMsg_2yudp8Ut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_EPESqUBw_sendMessage);
}

void Heavy_SoundScraper::cMsg_gFxIZ7IN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eVXfaLfw, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GXfAEF6D, m);
}

void Heavy_SoundScraper::cBinop_29HbxcL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SHGAn4qe, 0, m, &cVar_SHGAn4qe_sendMessage);
}

void Heavy_SoundScraper::cBinop_I8oPoEAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pU1yHqHv, 0, m, &cVar_pU1yHqHv_sendMessage);
}

void Heavy_SoundScraper::cBinop_gf1oLw8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e7d3Klab, 0, m, &cVar_e7d3Klab_sendMessage);
}

void Heavy_SoundScraper::cCast_O31skwmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_29HbxcL4_sendMessage);
}

void Heavy_SoundScraper::cCast_fXH9RToM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_I8oPoEAP_sendMessage);
}

void Heavy_SoundScraper::cCast_oMai1R0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_W99TCZJQ, m);
}

void Heavy_SoundScraper::cCast_WQa33QaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_gf1oLw8F_sendMessage);
}

void Heavy_SoundScraper::cTabhead_oXdYeowc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vzS0iUdQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_vzS0iUdQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_wkc58VuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_O5pE0Ezk_sendMessage);
}

void Heavy_SoundScraper::cSystem_O5pE0Ezk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_b5pUMHit_sendMessage);
}

void Heavy_SoundScraper::cVar_8WtLDrD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uIb5ARhd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_eHYhhKKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eHYhhKKg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8tZIVVF2, 0, m, &cDelay_8tZIVVF2_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xx2RUEzx, 0, m, &sTabread_xx2RUEzx_sendMessage);
}

void Heavy_SoundScraper::cDelay_8tZIVVF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8tZIVVF2, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xx2RUEzx, 0, m, &sTabread_xx2RUEzx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8tZIVVF2, 0, m, &cDelay_8tZIVVF2_sendMessage);
}

void Heavy_SoundScraper::sTabread_xx2RUEzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_klSqAQ66, HV_BINOP_SUBTRACT, 0, m, &cBinop_klSqAQ66_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Ne9FboRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R2O5OqeP, HV_BINOP_MAX, 0, m, &cBinop_R2O5OqeP_sendMessage);
}

void Heavy_SoundScraper::cBinop_b5pUMHit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ne9FboRm, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ne9FboRm_sendMessage);
}

void Heavy_SoundScraper::cBinop_vzS0iUdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ngc2Wid6_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xx2RUEzx, 0, m, &sTabread_xx2RUEzx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ATu0HBys_sendMessage);
}

void Heavy_SoundScraper::cSystem_tQBEAEPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_klSqAQ66, HV_BINOP_SUBTRACT, 1, m, &cBinop_klSqAQ66_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8tZIVVF2, 2, m, &cDelay_8tZIVVF2_sendMessage);
}

void Heavy_SoundScraper::cMsg_uIb5ARhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tQBEAEPu_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ngc2Wid6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_eHYhhKKg, 0, m, &cDelay_eHYhhKKg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8tZIVVF2, 0, m, &cDelay_8tZIVVF2_sendMessage);
}

void Heavy_SoundScraper::cMsg_rFtx36UI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_R2O5OqeP, HV_BINOP_MAX, 1, m, &cBinop_R2O5OqeP_sendMessage);
}

void Heavy_SoundScraper::cBinop_R2O5OqeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vzS0iUdQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_vzS0iUdQ_sendMessage);
}

void Heavy_SoundScraper::cCast_ATu0HBys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eHYhhKKg, 0, m, &cDelay_eHYhhKKg_sendMessage);
}

void Heavy_SoundScraper::cBinop_W0waHLvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eHYhhKKg, 2, m, &cDelay_eHYhhKKg_sendMessage);
}

void Heavy_SoundScraper::cBinop_klSqAQ66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_W0waHLvv_sendMessage);
}

void Heavy_SoundScraper::cCast_Azv92QJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8WtLDrD5, 0, m, &cVar_8WtLDrD5_sendMessage);
  cMsg_wkc58VuQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_oXdYeowc, 0, m, &cTabhead_oXdYeowc_sendMessage);
}

void Heavy_SoundScraper::cTabhead_zAsgvHiv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0u3jrGcI, HV_BINOP_SUBTRACT, 0, m, &cBinop_0u3jrGcI_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZKONfjUN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kPXoYbxx_sendMessage);
}

void Heavy_SoundScraper::cSystem_kPXoYbxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Gyc6r1eU_sendMessage);
}

void Heavy_SoundScraper::cVar_aBxFiuMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zGCW6ZJj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_giVG6AVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_giVG6AVS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MwNI8b9s, 0, m, &cDelay_MwNI8b9s_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_B9pPbqux, 0, m, &sTabread_B9pPbqux_sendMessage);
}

void Heavy_SoundScraper::cDelay_MwNI8b9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MwNI8b9s, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_B9pPbqux, 0, m, &sTabread_B9pPbqux_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MwNI8b9s, 0, m, &cDelay_MwNI8b9s_sendMessage);
}

void Heavy_SoundScraper::sTabread_B9pPbqux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MpAAlloE, HV_BINOP_SUBTRACT, 0, m, &cBinop_MpAAlloE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_cJemqPTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xAhPyUg1, HV_BINOP_MAX, 0, m, &cBinop_xAhPyUg1_sendMessage);
}

void Heavy_SoundScraper::cBinop_Gyc6r1eU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cJemqPTZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_cJemqPTZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_0u3jrGcI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bP1fQe9P_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_B9pPbqux, 0, m, &sTabread_B9pPbqux_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lZnfCnw3_sendMessage);
}

void Heavy_SoundScraper::cSystem_o17B6ub4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MpAAlloE, HV_BINOP_SUBTRACT, 1, m, &cBinop_MpAAlloE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MwNI8b9s, 2, m, &cDelay_MwNI8b9s_sendMessage);
}

void Heavy_SoundScraper::cMsg_zGCW6ZJj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_o17B6ub4_sendMessage);
}

void Heavy_SoundScraper::cMsg_bP1fQe9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_giVG6AVS, 0, m, &cDelay_giVG6AVS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MwNI8b9s, 0, m, &cDelay_MwNI8b9s_sendMessage);
}

void Heavy_SoundScraper::cMsg_nuxZPw74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_xAhPyUg1, HV_BINOP_MAX, 1, m, &cBinop_xAhPyUg1_sendMessage);
}

void Heavy_SoundScraper::cBinop_xAhPyUg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0u3jrGcI, HV_BINOP_SUBTRACT, 1, m, &cBinop_0u3jrGcI_sendMessage);
}

void Heavy_SoundScraper::cCast_lZnfCnw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_giVG6AVS, 0, m, &cDelay_giVG6AVS_sendMessage);
}

void Heavy_SoundScraper::cBinop_eioqNKNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_giVG6AVS, 2, m, &cDelay_giVG6AVS_sendMessage);
}

void Heavy_SoundScraper::cBinop_MpAAlloE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_eioqNKNg_sendMessage);
}

void Heavy_SoundScraper::cCast_holOXPuO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aBxFiuMC, 0, m, &cVar_aBxFiuMC_sendMessage);
  cMsg_ZKONfjUN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zAsgvHiv, 0, m, &cTabhead_zAsgvHiv_sendMessage);
}

void Heavy_SoundScraper::cTabhead_oOxd6kPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qy2H4c5Q, HV_BINOP_SUBTRACT, 0, m, &cBinop_qy2H4c5Q_sendMessage);
}

void Heavy_SoundScraper::cMsg_JaC53Jbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uZ2DAkym_sendMessage);
}

void Heavy_SoundScraper::cSystem_uZ2DAkym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Qa2tU9Z1_sendMessage);
}

void Heavy_SoundScraper::cVar_k8YLpKz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9hbOwNER_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_dSq9Oam3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dSq9Oam3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AQpsWmmN, 0, m, &cDelay_AQpsWmmN_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_pvtbGZJz, 0, m, &sTabread_pvtbGZJz_sendMessage);
}

void Heavy_SoundScraper::cDelay_AQpsWmmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AQpsWmmN, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_pvtbGZJz, 0, m, &sTabread_pvtbGZJz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AQpsWmmN, 0, m, &cDelay_AQpsWmmN_sendMessage);
}

void Heavy_SoundScraper::sTabread_pvtbGZJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_A5bUfx6f, HV_BINOP_SUBTRACT, 0, m, &cBinop_A5bUfx6f_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_c5W9hCVf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HDZvLvQv, HV_BINOP_MAX, 0, m, &cBinop_HDZvLvQv_sendMessage);
}

void Heavy_SoundScraper::cBinop_Qa2tU9Z1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c5W9hCVf, HV_BINOP_MULTIPLY, 0, m, &cBinop_c5W9hCVf_sendMessage);
}

void Heavy_SoundScraper::cBinop_qy2H4c5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EGuL6RoL_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_pvtbGZJz, 0, m, &sTabread_pvtbGZJz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NC24kloX_sendMessage);
}

void Heavy_SoundScraper::cSystem_2DDn4Bwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A5bUfx6f, HV_BINOP_SUBTRACT, 1, m, &cBinop_A5bUfx6f_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AQpsWmmN, 2, m, &cDelay_AQpsWmmN_sendMessage);
}

void Heavy_SoundScraper::cMsg_9hbOwNER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2DDn4Bwx_sendMessage);
}

void Heavy_SoundScraper::cMsg_EGuL6RoL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_dSq9Oam3, 0, m, &cDelay_dSq9Oam3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AQpsWmmN, 0, m, &cDelay_AQpsWmmN_sendMessage);
}

void Heavy_SoundScraper::cMsg_RoXblPb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_HDZvLvQv, HV_BINOP_MAX, 1, m, &cBinop_HDZvLvQv_sendMessage);
}

void Heavy_SoundScraper::cBinop_HDZvLvQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qy2H4c5Q, HV_BINOP_SUBTRACT, 1, m, &cBinop_qy2H4c5Q_sendMessage);
}

void Heavy_SoundScraper::cCast_NC24kloX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dSq9Oam3, 0, m, &cDelay_dSq9Oam3_sendMessage);
}

void Heavy_SoundScraper::cBinop_IeqgoG3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dSq9Oam3, 2, m, &cDelay_dSq9Oam3_sendMessage);
}

void Heavy_SoundScraper::cBinop_A5bUfx6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IeqgoG3E_sendMessage);
}

void Heavy_SoundScraper::cCast_tmVqgyo4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k8YLpKz9, 0, m, &cVar_k8YLpKz9_sendMessage);
  cMsg_JaC53Jbs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_oOxd6kPi, 0, m, &cTabhead_oOxd6kPi_sendMessage);
}

void Heavy_SoundScraper::cTabhead_YABkOIom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z1lmnIS9, HV_BINOP_SUBTRACT, 0, m, &cBinop_z1lmnIS9_sendMessage);
}

void Heavy_SoundScraper::cMsg_sqexrfZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PK9TdCNa_sendMessage);
}

void Heavy_SoundScraper::cSystem_PK9TdCNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wiDkuZHJ_sendMessage);
}

void Heavy_SoundScraper::cVar_mq7ADqS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ibd9ULRi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_q1R8izNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_q1R8izNI, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n5OjBVlS, 0, m, &cDelay_n5OjBVlS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0Nwpu5zT, 0, m, &sTabread_0Nwpu5zT_sendMessage);
}

void Heavy_SoundScraper::cDelay_n5OjBVlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n5OjBVlS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0Nwpu5zT, 0, m, &sTabread_0Nwpu5zT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n5OjBVlS, 0, m, &cDelay_n5OjBVlS_sendMessage);
}

void Heavy_SoundScraper::sTabread_0Nwpu5zT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_q3ZzgX5v, HV_BINOP_SUBTRACT, 0, m, &cBinop_q3ZzgX5v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_8mkGw3RD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DdEY7gwH, HV_BINOP_MAX, 0, m, &cBinop_DdEY7gwH_sendMessage);
}

void Heavy_SoundScraper::cBinop_wiDkuZHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8mkGw3RD, HV_BINOP_MULTIPLY, 0, m, &cBinop_8mkGw3RD_sendMessage);
}

void Heavy_SoundScraper::cBinop_z1lmnIS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fmJzSHyL_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0Nwpu5zT, 0, m, &sTabread_0Nwpu5zT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CqWHy73x_sendMessage);
}

void Heavy_SoundScraper::cSystem_vhZp8Bo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q3ZzgX5v, HV_BINOP_SUBTRACT, 1, m, &cBinop_q3ZzgX5v_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n5OjBVlS, 2, m, &cDelay_n5OjBVlS_sendMessage);
}

void Heavy_SoundScraper::cMsg_ibd9ULRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vhZp8Bo8_sendMessage);
}

void Heavy_SoundScraper::cMsg_fmJzSHyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_q1R8izNI, 0, m, &cDelay_q1R8izNI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n5OjBVlS, 0, m, &cDelay_n5OjBVlS_sendMessage);
}

void Heavy_SoundScraper::cMsg_LrNcuQtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_DdEY7gwH, HV_BINOP_MAX, 1, m, &cBinop_DdEY7gwH_sendMessage);
}

void Heavy_SoundScraper::cBinop_DdEY7gwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z1lmnIS9, HV_BINOP_SUBTRACT, 1, m, &cBinop_z1lmnIS9_sendMessage);
}

void Heavy_SoundScraper::cCast_CqWHy73x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q1R8izNI, 0, m, &cDelay_q1R8izNI_sendMessage);
}

void Heavy_SoundScraper::cBinop_y2SVWPew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q1R8izNI, 2, m, &cDelay_q1R8izNI_sendMessage);
}

void Heavy_SoundScraper::cBinop_q3ZzgX5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_y2SVWPew_sendMessage);
}

void Heavy_SoundScraper::cCast_TQ2PsUrJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mq7ADqS6, 0, m, &cVar_mq7ADqS6_sendMessage);
  cMsg_sqexrfZg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YABkOIom, 0, m, &cTabhead_YABkOIom_sendMessage);
}

void Heavy_SoundScraper::cMsg_GdWiyT55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SiGxeQ1L_sendMessage);
}

void Heavy_SoundScraper::cSystem_SiGxeQ1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ysecYdia_sendMessage);
}

void Heavy_SoundScraper::cDelay_wz0MoRzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wz0MoRzS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yjaFIf2W, 0, m, &cDelay_yjaFIf2W_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wz0MoRzS, 0, m, &cDelay_wz0MoRzS_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZhrvGVHA, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_yjaFIf2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yjaFIf2W, m);
  cMsg_1A5frbk8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_daSPabYU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_OrXi3NPB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_bZw0A53j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZEKC1Vox_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_LJrCyPE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5JsxXQRp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wz0MoRzS, 2, m, &cDelay_wz0MoRzS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k7RMRyTG_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZEKC1Vox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_LJrCyPE0, 0, m, &hTable_LJrCyPE0_sendMessage);
}

void Heavy_SoundScraper::cBinop_ysecYdia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_bZw0A53j_sendMessage);
}

void Heavy_SoundScraper::cMsg_1A5frbk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_LJrCyPE0, 0, m, &hTable_LJrCyPE0_sendMessage);
}

void Heavy_SoundScraper::cCast_k7RMRyTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wz0MoRzS, 0, m, &cDelay_wz0MoRzS_sendMessage);
}

void Heavy_SoundScraper::cMsg_5JsxXQRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_yjaFIf2W, 2, m, &cDelay_yjaFIf2W_sendMessage);
}

void Heavy_SoundScraper::cMsg_OrXi3NPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZhrvGVHA, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_kVAr3yfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_s6Vv0t1c_sendMessage);
}

void Heavy_SoundScraper::cSystem_s6Vv0t1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rcmsonex_sendMessage);
}

void Heavy_SoundScraper::cDelay_Ng2BfBzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ng2BfBzc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OLWxlg7A, 0, m, &cDelay_OLWxlg7A_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ng2BfBzc, 0, m, &cDelay_Ng2BfBzc_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_N9z8Y0Wr, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_OLWxlg7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OLWxlg7A, m);
  cMsg_kbxayfyw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_5TbUqxLa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Valzqnjr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_QWCLAkee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_99FiBSpr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_LO77Vyhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6SRdMR3F_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ng2BfBzc, 2, m, &cDelay_Ng2BfBzc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZVG1Ubar_sendMessage);
}

void Heavy_SoundScraper::cMsg_99FiBSpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_LO77Vyhx, 0, m, &hTable_LO77Vyhx_sendMessage);
}

void Heavy_SoundScraper::cBinop_rcmsonex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_QWCLAkee_sendMessage);
}

void Heavy_SoundScraper::cMsg_kbxayfyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_LO77Vyhx, 0, m, &hTable_LO77Vyhx_sendMessage);
}

void Heavy_SoundScraper::cCast_ZVG1Ubar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ng2BfBzc, 0, m, &cDelay_Ng2BfBzc_sendMessage);
}

void Heavy_SoundScraper::cMsg_6SRdMR3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OLWxlg7A, 2, m, &cDelay_OLWxlg7A_sendMessage);
}

void Heavy_SoundScraper::cMsg_Valzqnjr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_N9z8Y0Wr, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_ZxIoh2go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gqAw629h_sendMessage);
}

void Heavy_SoundScraper::cSystem_gqAw629h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AKMBaUue_sendMessage);
}

void Heavy_SoundScraper::cDelay_awPbf4ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_awPbf4ro, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mb1Y9ILA, 0, m, &cDelay_Mb1Y9ILA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_awPbf4ro, 0, m, &cDelay_awPbf4ro_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yk4PCHwH, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_Mb1Y9ILA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Mb1Y9ILA, m);
  cMsg_hYHpKxfv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_4QAwqjP2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_9DDwsAg0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_hZm4Df8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MSrzntgp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_u47NZ5VP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UpodcvkQ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_awPbf4ro, 2, m, &cDelay_awPbf4ro_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PlBfEH5A_sendMessage);
}

void Heavy_SoundScraper::cMsg_MSrzntgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_u47NZ5VP, 0, m, &hTable_u47NZ5VP_sendMessage);
}

void Heavy_SoundScraper::cBinop_AKMBaUue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_hZm4Df8y_sendMessage);
}

void Heavy_SoundScraper::cMsg_hYHpKxfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_u47NZ5VP, 0, m, &hTable_u47NZ5VP_sendMessage);
}

void Heavy_SoundScraper::cCast_PlBfEH5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_awPbf4ro, 0, m, &cDelay_awPbf4ro_sendMessage);
}

void Heavy_SoundScraper::cMsg_UpodcvkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mb1Y9ILA, 2, m, &cDelay_Mb1Y9ILA_sendMessage);
}

void Heavy_SoundScraper::cMsg_9DDwsAg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yk4PCHwH, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_YlZN6zA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5Oe2Vatl_sendMessage);
}

void Heavy_SoundScraper::cSystem_5Oe2Vatl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_epZaz7nW_sendMessage);
}

void Heavy_SoundScraper::cDelay_0EoE3o35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0EoE3o35, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_j93aWClY, 0, m, &cDelay_j93aWClY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0EoE3o35, 0, m, &cDelay_0EoE3o35_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_z1QlnVwa, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_j93aWClY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_j93aWClY, m);
  cMsg_QijSZUXX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_OfzZt4Qv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_C5dPwcL9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_GIDmAV5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_omgrcoLG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_QRmVDbhG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6FUPvR9G_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0EoE3o35, 2, m, &cDelay_0EoE3o35_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8grVweM4_sendMessage);
}

void Heavy_SoundScraper::cMsg_omgrcoLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_QRmVDbhG, 0, m, &hTable_QRmVDbhG_sendMessage);
}

void Heavy_SoundScraper::cBinop_epZaz7nW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_GIDmAV5c_sendMessage);
}

void Heavy_SoundScraper::cMsg_QijSZUXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_QRmVDbhG, 0, m, &hTable_QRmVDbhG_sendMessage);
}

void Heavy_SoundScraper::cCast_8grVweM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0EoE3o35, 0, m, &cDelay_0EoE3o35_sendMessage);
}

void Heavy_SoundScraper::cMsg_6FUPvR9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_j93aWClY, 2, m, &cDelay_j93aWClY_sendMessage);
}

void Heavy_SoundScraper::cMsg_C5dPwcL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_z1QlnVwa, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_au3E9o1j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_dhqZtC0j_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_fBA1eVZl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_S9yDflCd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zJUK0lc2, HV_BINOP_POW, 0, m, &cBinop_zJUK0lc2_sendMessage);
}

void Heavy_SoundScraper::cBinop_zJUK0lc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_o4RmdGWG_sendMessage);
}

void Heavy_SoundScraper::cBinop_GJgyHHq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_hfFB1PoD_sendMessage);
}

void Heavy_SoundScraper::cCast_Uy6lBGHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_aScVeYJD_sendMessage);
}

void Heavy_SoundScraper::cCast_6zIdle2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_au3E9o1j, 0, m, &cIf_au3E9o1j_sendMessage);
}

void Heavy_SoundScraper::cBinop_aScVeYJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_au3E9o1j, 1, m, &cIf_au3E9o1j_sendMessage);
}

void Heavy_SoundScraper::cBinop_fBA1eVZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_GJgyHHq3_sendMessage);
}

void Heavy_SoundScraper::cMsg_dhqZtC0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_o4RmdGWG_sendMessage);
}

void Heavy_SoundScraper::cBinop_hfFB1PoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zJUK0lc2, HV_BINOP_POW, 1, m, &cBinop_zJUK0lc2_sendMessage);
  cMsg_S9yDflCd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_gJ8v7VI2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0iVuKQiD, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_shm7US60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Ad9WQWGw, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_5qhKfEvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tCous30L_sendMessage);
}

void Heavy_SoundScraper::cBinop_tCous30L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_lLlJv1io_sendMessage);
}

void Heavy_SoundScraper::cVar_yZNhN76s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WDBMQDFw, HV_BINOP_MULTIPLY, 0, m, &cBinop_WDBMQDFw_sendMessage);
}

void Heavy_SoundScraper::cMsg_IFc0lD7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gHEVuUTP_sendMessage);
}

void Heavy_SoundScraper::cSystem_gHEVuUTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wI0WIm64_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_WDBMQDFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_hZTLPTmn_sendMessage);
}

void Heavy_SoundScraper::cBinop_qyWZuaPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WDBMQDFw, HV_BINOP_MULTIPLY, 1, m, &cBinop_WDBMQDFw_sendMessage);
}

void Heavy_SoundScraper::cMsg_wI0WIm64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qyWZuaPN_sendMessage);
}

void Heavy_SoundScraper::cBinop_hZTLPTmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_j145BwT5_sendMessage);
}

void Heavy_SoundScraper::cBinop_j145BwT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bfpUThap_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_UInjfCfV, m);
}

void Heavy_SoundScraper::cBinop_bfpUThap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0SaaZjP1, m);
}

void Heavy_SoundScraper::cVar_71N7Wq23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Uy6lBGHt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6zIdle2z_sendMessage);
}

void Heavy_SoundScraper::cVar_pcFIlYhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_5qhKfEvn_sendMessage);
}

void Heavy_SoundScraper::cVar_tdXGgu5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_HM68DM7A_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CkBgGTS0, 0, m, &cIf_CkBgGTS0_sendMessage);
}

void Heavy_SoundScraper::cVar_B3krmBek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_VxPJcLY2_sendMessage);
}

void Heavy_SoundScraper::cIf_CkBgGTS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_FokatoUY_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_yp8tEV7I, 0, m, &cVar_yp8tEV7I_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_HM68DM7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CkBgGTS0, 1, m, &cIf_CkBgGTS0_sendMessage);
}

void Heavy_SoundScraper::cBinop_VxPJcLY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_XIe7MAEq_sendMessage);
}

void Heavy_SoundScraper::cBinop_XIe7MAEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v632NFJS, 0, m, &cVar_v632NFJS_sendMessage);
}

void Heavy_SoundScraper::cTabhead_bhG4IPjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ujR6nGYj, HV_BINOP_SUBTRACT, 0, m, &cBinop_ujR6nGYj_sendMessage);
}

void Heavy_SoundScraper::cMsg_3CvDfynJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HW6PBw6G_sendMessage);
}

void Heavy_SoundScraper::cSystem_HW6PBw6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zTsg9wZP_sendMessage);
}

void Heavy_SoundScraper::cVar_8yeLigtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iUBPEx3x_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_p2ny8zTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_p2ny8zTN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AhThLAke, 0, m, &cDelay_AhThLAke_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Smc2j305, 0, m, &sTabread_Smc2j305_sendMessage);
}

void Heavy_SoundScraper::cDelay_AhThLAke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AhThLAke, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Smc2j305, 0, m, &sTabread_Smc2j305_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AhThLAke, 0, m, &cDelay_AhThLAke_sendMessage);
}

void Heavy_SoundScraper::sTabread_Smc2j305_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yvFtGZPc, HV_BINOP_SUBTRACT, 0, m, &cBinop_yvFtGZPc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_nlQ7kOrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KqHwgdBP, HV_BINOP_MAX, 0, m, &cBinop_KqHwgdBP_sendMessage);
}

void Heavy_SoundScraper::cBinop_zTsg9wZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nlQ7kOrx, HV_BINOP_MULTIPLY, 0, m, &cBinop_nlQ7kOrx_sendMessage);
}

void Heavy_SoundScraper::cBinop_ujR6nGYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UZaUbxoG_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Smc2j305, 0, m, &sTabread_Smc2j305_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FEDa5okV_sendMessage);
}

void Heavy_SoundScraper::cSystem_zluZXkjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yvFtGZPc, HV_BINOP_SUBTRACT, 1, m, &cBinop_yvFtGZPc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AhThLAke, 2, m, &cDelay_AhThLAke_sendMessage);
}

void Heavy_SoundScraper::cMsg_iUBPEx3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zluZXkjI_sendMessage);
}

void Heavy_SoundScraper::cMsg_UZaUbxoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_p2ny8zTN, 0, m, &cDelay_p2ny8zTN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AhThLAke, 0, m, &cDelay_AhThLAke_sendMessage);
}

void Heavy_SoundScraper::cMsg_BjXPuO4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_KqHwgdBP, HV_BINOP_MAX, 1, m, &cBinop_KqHwgdBP_sendMessage);
}

void Heavy_SoundScraper::cBinop_KqHwgdBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ujR6nGYj, HV_BINOP_SUBTRACT, 1, m, &cBinop_ujR6nGYj_sendMessage);
}

void Heavy_SoundScraper::cCast_FEDa5okV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_p2ny8zTN, 0, m, &cDelay_p2ny8zTN_sendMessage);
}

void Heavy_SoundScraper::cBinop_Hrl95aue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_p2ny8zTN, 2, m, &cDelay_p2ny8zTN_sendMessage);
}

void Heavy_SoundScraper::cBinop_yvFtGZPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Hrl95aue_sendMessage);
}

void Heavy_SoundScraper::cCast_MwhrivCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8yeLigtZ, 0, m, &cVar_8yeLigtZ_sendMessage);
  cMsg_3CvDfynJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bhG4IPjP, 0, m, &cTabhead_bhG4IPjP_sendMessage);
}

void Heavy_SoundScraper::cMsg_hum8Fu4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_e07cF2Rs_sendMessage);
}

void Heavy_SoundScraper::cSystem_e07cF2Rs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UZHG81cH_sendMessage);
}

void Heavy_SoundScraper::cDelay_K1GbzwF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_K1GbzwF6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7KEKnfRL, 0, m, &cDelay_7KEKnfRL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_K1GbzwF6, 0, m, &cDelay_K1GbzwF6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gO0AoIZk, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_7KEKnfRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7KEKnfRL, m);
  cMsg_7J54QGKN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_WJUeUYvE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_9CvAtSom_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_LE0HkZVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oDE3YKT4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_eeTIy2k1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FpDPlIHR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_K1GbzwF6, 2, m, &cDelay_K1GbzwF6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_isxGkXBn_sendMessage);
}

void Heavy_SoundScraper::cMsg_oDE3YKT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_eeTIy2k1, 0, m, &hTable_eeTIy2k1_sendMessage);
}

void Heavy_SoundScraper::cBinop_UZHG81cH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_LE0HkZVr_sendMessage);
}

void Heavy_SoundScraper::cMsg_7J54QGKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_eeTIy2k1, 0, m, &hTable_eeTIy2k1_sendMessage);
}

void Heavy_SoundScraper::cCast_isxGkXBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_K1GbzwF6, 0, m, &cDelay_K1GbzwF6_sendMessage);
}

void Heavy_SoundScraper::cMsg_FpDPlIHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_7KEKnfRL, 2, m, &cDelay_7KEKnfRL_sendMessage);
}

void Heavy_SoundScraper::cMsg_9CvAtSom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gO0AoIZk, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_HMwr6AVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oefayF2x, HV_BINOP_SUBTRACT, 0, m, &cBinop_oefayF2x_sendMessage);
}

void Heavy_SoundScraper::cMsg_8YCYsQu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_npWzVJcr_sendMessage);
}

void Heavy_SoundScraper::cSystem_npWzVJcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_orbdl7O6_sendMessage);
}

void Heavy_SoundScraper::cVar_KfpeR1u6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8p5G52bM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_tnGHJCoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tnGHJCoC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oUayEQRR, 0, m, &cDelay_oUayEQRR_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6O2xxiiV, 0, m, &sTabread_6O2xxiiV_sendMessage);
}

void Heavy_SoundScraper::cDelay_oUayEQRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oUayEQRR, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6O2xxiiV, 0, m, &sTabread_6O2xxiiV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oUayEQRR, 0, m, &cDelay_oUayEQRR_sendMessage);
}

void Heavy_SoundScraper::sTabread_6O2xxiiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_TSTA5wxO, HV_BINOP_SUBTRACT, 0, m, &cBinop_TSTA5wxO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ELsWnrrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pykBSg52, HV_BINOP_MAX, 0, m, &cBinop_pykBSg52_sendMessage);
}

void Heavy_SoundScraper::cBinop_orbdl7O6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ELsWnrrK, HV_BINOP_MULTIPLY, 0, m, &cBinop_ELsWnrrK_sendMessage);
}

void Heavy_SoundScraper::cBinop_oefayF2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SPgcePJX_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6O2xxiiV, 0, m, &sTabread_6O2xxiiV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XRsq0ul9_sendMessage);
}

void Heavy_SoundScraper::cSystem_K0aZ4SLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TSTA5wxO, HV_BINOP_SUBTRACT, 1, m, &cBinop_TSTA5wxO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oUayEQRR, 2, m, &cDelay_oUayEQRR_sendMessage);
}

void Heavy_SoundScraper::cMsg_8p5G52bM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K0aZ4SLf_sendMessage);
}

void Heavy_SoundScraper::cMsg_SPgcePJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tnGHJCoC, 0, m, &cDelay_tnGHJCoC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oUayEQRR, 0, m, &cDelay_oUayEQRR_sendMessage);
}

void Heavy_SoundScraper::cMsg_oIOaAnR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_pykBSg52, HV_BINOP_MAX, 1, m, &cBinop_pykBSg52_sendMessage);
}

void Heavy_SoundScraper::cBinop_pykBSg52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oefayF2x, HV_BINOP_SUBTRACT, 1, m, &cBinop_oefayF2x_sendMessage);
}

void Heavy_SoundScraper::cCast_XRsq0ul9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tnGHJCoC, 0, m, &cDelay_tnGHJCoC_sendMessage);
}

void Heavy_SoundScraper::cBinop_JldG4Wnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tnGHJCoC, 2, m, &cDelay_tnGHJCoC_sendMessage);
}

void Heavy_SoundScraper::cBinop_TSTA5wxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JldG4Wnk_sendMessage);
}

void Heavy_SoundScraper::cCast_xLsQj2se_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KfpeR1u6, 0, m, &cVar_KfpeR1u6_sendMessage);
  cMsg_8YCYsQu6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HMwr6AVF, 0, m, &cTabhead_HMwr6AVF_sendMessage);
}

void Heavy_SoundScraper::cMsg_4eHnlmQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JCYHgdNM_sendMessage);
}

void Heavy_SoundScraper::cSystem_JCYHgdNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9qHV8Q0C_sendMessage);
}

void Heavy_SoundScraper::cDelay_mVkHqPPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mVkHqPPW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8WcdXQdp, 0, m, &cDelay_8WcdXQdp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mVkHqPPW, 0, m, &cDelay_mVkHqPPW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HwGdZfuG, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_8WcdXQdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8WcdXQdp, m);
  cMsg_vWiJwvQH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_XcdkxVXR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_vAIiVT63_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_GGjaD3sJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_afDMQo2w_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_us6eLSN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MTVLOGqk_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mVkHqPPW, 2, m, &cDelay_mVkHqPPW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UG7xvEbd_sendMessage);
}

void Heavy_SoundScraper::cMsg_afDMQo2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_us6eLSN0, 0, m, &hTable_us6eLSN0_sendMessage);
}

void Heavy_SoundScraper::cBinop_9qHV8Q0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_GGjaD3sJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_vWiJwvQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_us6eLSN0, 0, m, &hTable_us6eLSN0_sendMessage);
}

void Heavy_SoundScraper::cCast_UG7xvEbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mVkHqPPW, 0, m, &cDelay_mVkHqPPW_sendMessage);
}

void Heavy_SoundScraper::cMsg_MTVLOGqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8WcdXQdp, 2, m, &cDelay_8WcdXQdp_sendMessage);
}

void Heavy_SoundScraper::cMsg_vAIiVT63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HwGdZfuG, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_ewq6WUqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yylCC68p, HV_BINOP_SUBTRACT, 0, m, &cBinop_yylCC68p_sendMessage);
}

void Heavy_SoundScraper::cMsg_yo3U5RO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VNMxYKMi_sendMessage);
}

void Heavy_SoundScraper::cSystem_VNMxYKMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vPhul4vb_sendMessage);
}

void Heavy_SoundScraper::cVar_YdcuhJ0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sUc8UfMg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_odnu7puu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_odnu7puu, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L8vGh30Y, 0, m, &cDelay_L8vGh30Y_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_njis9KQS, 0, m, &sTabread_njis9KQS_sendMessage);
}

void Heavy_SoundScraper::cDelay_L8vGh30Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_L8vGh30Y, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_njis9KQS, 0, m, &sTabread_njis9KQS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L8vGh30Y, 0, m, &cDelay_L8vGh30Y_sendMessage);
}

void Heavy_SoundScraper::sTabread_njis9KQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KJv4iSOw, HV_BINOP_SUBTRACT, 0, m, &cBinop_KJv4iSOw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_CE9CgehL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1Kj53k11, HV_BINOP_MAX, 0, m, &cBinop_1Kj53k11_sendMessage);
}

void Heavy_SoundScraper::cBinop_vPhul4vb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CE9CgehL, HV_BINOP_MULTIPLY, 0, m, &cBinop_CE9CgehL_sendMessage);
}

void Heavy_SoundScraper::cBinop_yylCC68p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1nbID1cw_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_njis9KQS, 0, m, &sTabread_njis9KQS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2mPGfKaS_sendMessage);
}

void Heavy_SoundScraper::cSystem_lr2OtDqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KJv4iSOw, HV_BINOP_SUBTRACT, 1, m, &cBinop_KJv4iSOw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L8vGh30Y, 2, m, &cDelay_L8vGh30Y_sendMessage);
}

void Heavy_SoundScraper::cMsg_sUc8UfMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lr2OtDqy_sendMessage);
}

void Heavy_SoundScraper::cMsg_1nbID1cw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_odnu7puu, 0, m, &cDelay_odnu7puu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L8vGh30Y, 0, m, &cDelay_L8vGh30Y_sendMessage);
}

void Heavy_SoundScraper::cMsg_zg0HiRZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_1Kj53k11, HV_BINOP_MAX, 1, m, &cBinop_1Kj53k11_sendMessage);
}

void Heavy_SoundScraper::cBinop_1Kj53k11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yylCC68p, HV_BINOP_SUBTRACT, 1, m, &cBinop_yylCC68p_sendMessage);
}

void Heavy_SoundScraper::cCast_2mPGfKaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_odnu7puu, 0, m, &cDelay_odnu7puu_sendMessage);
}

void Heavy_SoundScraper::cBinop_aFkh0Gou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_odnu7puu, 2, m, &cDelay_odnu7puu_sendMessage);
}

void Heavy_SoundScraper::cBinop_KJv4iSOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aFkh0Gou_sendMessage);
}

void Heavy_SoundScraper::cCast_iMbFNMHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YdcuhJ0D, 0, m, &cVar_YdcuhJ0D_sendMessage);
  cMsg_yo3U5RO7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ewq6WUqS, 0, m, &cTabhead_ewq6WUqS_sendMessage);
}

void Heavy_SoundScraper::cMsg_p5nEi54s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pvIPouo5_sendMessage);
}

void Heavy_SoundScraper::cSystem_pvIPouo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0Pqb3iwm_sendMessage);
}

void Heavy_SoundScraper::cDelay_BlHMw3Jc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BlHMw3Jc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_auAfBh3L, 0, m, &cDelay_auAfBh3L_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlHMw3Jc, 0, m, &cDelay_BlHMw3Jc_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Unshn8w7, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_auAfBh3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_auAfBh3L, m);
  cMsg_FKnKC1TL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_puLRCIaB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_UZq4vAeL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_mGSRVshi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2WcECOW0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_RcY0yvWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1uVYlRO8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlHMw3Jc, 2, m, &cDelay_BlHMw3Jc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OtLQpUHq_sendMessage);
}

void Heavy_SoundScraper::cMsg_2WcECOW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_RcY0yvWg, 0, m, &hTable_RcY0yvWg_sendMessage);
}

void Heavy_SoundScraper::cBinop_0Pqb3iwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_mGSRVshi_sendMessage);
}

void Heavy_SoundScraper::cMsg_FKnKC1TL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_RcY0yvWg, 0, m, &hTable_RcY0yvWg_sendMessage);
}

void Heavy_SoundScraper::cCast_OtLQpUHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlHMw3Jc, 0, m, &cDelay_BlHMw3Jc_sendMessage);
}

void Heavy_SoundScraper::cMsg_1uVYlRO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_auAfBh3L, 2, m, &cDelay_auAfBh3L_sendMessage);
}

void Heavy_SoundScraper::cMsg_UZq4vAeL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Unshn8w7, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_YkMqdHnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wqj2ROo5, HV_BINOP_SUBTRACT, 0, m, &cBinop_Wqj2ROo5_sendMessage);
}

void Heavy_SoundScraper::cMsg_KSdJpOmQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YHjQuC5e_sendMessage);
}

void Heavy_SoundScraper::cSystem_YHjQuC5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zvzHrTnX_sendMessage);
}

void Heavy_SoundScraper::cVar_Oze4lTOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JJk2sRHI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_fvtHBbHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fvtHBbHF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bQmlleNA, 0, m, &cDelay_bQmlleNA_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Brq6KY0F, 0, m, &sTabread_Brq6KY0F_sendMessage);
}

void Heavy_SoundScraper::cDelay_bQmlleNA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bQmlleNA, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Brq6KY0F, 0, m, &sTabread_Brq6KY0F_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bQmlleNA, 0, m, &cDelay_bQmlleNA_sendMessage);
}

void Heavy_SoundScraper::sTabread_Brq6KY0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4HB9p6y6, HV_BINOP_SUBTRACT, 0, m, &cBinop_4HB9p6y6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_xRn8rmxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_THGEC9xY, HV_BINOP_MAX, 0, m, &cBinop_THGEC9xY_sendMessage);
}

void Heavy_SoundScraper::cBinop_zvzHrTnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xRn8rmxC, HV_BINOP_MULTIPLY, 0, m, &cBinop_xRn8rmxC_sendMessage);
}

void Heavy_SoundScraper::cBinop_Wqj2ROo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_82Hw9mrs_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Brq6KY0F, 0, m, &sTabread_Brq6KY0F_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z9b6kxrj_sendMessage);
}

void Heavy_SoundScraper::cSystem_gdjspEkd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4HB9p6y6, HV_BINOP_SUBTRACT, 1, m, &cBinop_4HB9p6y6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bQmlleNA, 2, m, &cDelay_bQmlleNA_sendMessage);
}

void Heavy_SoundScraper::cMsg_JJk2sRHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gdjspEkd_sendMessage);
}

void Heavy_SoundScraper::cMsg_82Hw9mrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fvtHBbHF, 0, m, &cDelay_fvtHBbHF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bQmlleNA, 0, m, &cDelay_bQmlleNA_sendMessage);
}

void Heavy_SoundScraper::cMsg_aYiSa69P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_THGEC9xY, HV_BINOP_MAX, 1, m, &cBinop_THGEC9xY_sendMessage);
}

void Heavy_SoundScraper::cBinop_THGEC9xY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wqj2ROo5, HV_BINOP_SUBTRACT, 1, m, &cBinop_Wqj2ROo5_sendMessage);
}

void Heavy_SoundScraper::cCast_Z9b6kxrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fvtHBbHF, 0, m, &cDelay_fvtHBbHF_sendMessage);
}

void Heavy_SoundScraper::cBinop_O79Jocko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fvtHBbHF, 2, m, &cDelay_fvtHBbHF_sendMessage);
}

void Heavy_SoundScraper::cBinop_4HB9p6y6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_O79Jocko_sendMessage);
}

void Heavy_SoundScraper::cCast_93D581ZI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Oze4lTOM, 0, m, &cVar_Oze4lTOM_sendMessage);
  cMsg_KSdJpOmQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YkMqdHnJ, 0, m, &cTabhead_YkMqdHnJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_0ukgME4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LhrnNHvx_sendMessage);
}

void Heavy_SoundScraper::cSystem_LhrnNHvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iUNtpAfx_sendMessage);
}

void Heavy_SoundScraper::cDelay_xjtpk8uP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xjtpk8uP, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RadWTlZd, 0, m, &cDelay_RadWTlZd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjtpk8uP, 0, m, &cDelay_xjtpk8uP_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_B1930N3N, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_RadWTlZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RadWTlZd, m);
  cMsg_D0mZvGWn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_KSCo7OH3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_njTaN82w_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_MlpCWTO5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CaGMza7w_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_aDFVpMco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OkYOaDZR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjtpk8uP, 2, m, &cDelay_xjtpk8uP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3HiSM2x7_sendMessage);
}

void Heavy_SoundScraper::cMsg_CaGMza7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_aDFVpMco, 0, m, &hTable_aDFVpMco_sendMessage);
}

void Heavy_SoundScraper::cBinop_iUNtpAfx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_MlpCWTO5_sendMessage);
}

void Heavy_SoundScraper::cMsg_D0mZvGWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_aDFVpMco, 0, m, &hTable_aDFVpMco_sendMessage);
}

void Heavy_SoundScraper::cCast_3HiSM2x7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjtpk8uP, 0, m, &cDelay_xjtpk8uP_sendMessage);
}

void Heavy_SoundScraper::cMsg_OkYOaDZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_RadWTlZd, 2, m, &cDelay_RadWTlZd_sendMessage);
}

void Heavy_SoundScraper::cMsg_njTaN82w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_B1930N3N, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_EVlkGzkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Joe51ZvW, HV_BINOP_SUBTRACT, 0, m, &cBinop_Joe51ZvW_sendMessage);
}

void Heavy_SoundScraper::cMsg_11ALiNhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eFAER4Ot_sendMessage);
}

void Heavy_SoundScraper::cSystem_eFAER4Ot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pU9FWxnU_sendMessage);
}

void Heavy_SoundScraper::cVar_EDmWy7Rk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JzQcd309_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_qTGEWcIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qTGEWcIO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E2PUpEkj, 0, m, &cDelay_E2PUpEkj_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_J2owhUk5, 0, m, &sTabread_J2owhUk5_sendMessage);
}

void Heavy_SoundScraper::cDelay_E2PUpEkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_E2PUpEkj, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_J2owhUk5, 0, m, &sTabread_J2owhUk5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E2PUpEkj, 0, m, &cDelay_E2PUpEkj_sendMessage);
}

void Heavy_SoundScraper::sTabread_J2owhUk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4Me6p19z, HV_BINOP_SUBTRACT, 0, m, &cBinop_4Me6p19z_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_WmI5OQgI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_707ATwk3, HV_BINOP_MAX, 0, m, &cBinop_707ATwk3_sendMessage);
}

void Heavy_SoundScraper::cBinop_pU9FWxnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WmI5OQgI, HV_BINOP_MULTIPLY, 0, m, &cBinop_WmI5OQgI_sendMessage);
}

void Heavy_SoundScraper::cBinop_Joe51ZvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OrP70q4B_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_J2owhUk5, 0, m, &sTabread_J2owhUk5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c1XbZHwz_sendMessage);
}

void Heavy_SoundScraper::cSystem_Id2xNzez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Me6p19z, HV_BINOP_SUBTRACT, 1, m, &cBinop_4Me6p19z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E2PUpEkj, 2, m, &cDelay_E2PUpEkj_sendMessage);
}

void Heavy_SoundScraper::cMsg_JzQcd309_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Id2xNzez_sendMessage);
}

void Heavy_SoundScraper::cMsg_OrP70q4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qTGEWcIO, 0, m, &cDelay_qTGEWcIO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E2PUpEkj, 0, m, &cDelay_E2PUpEkj_sendMessage);
}

void Heavy_SoundScraper::cMsg_sY3weUQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_707ATwk3, HV_BINOP_MAX, 1, m, &cBinop_707ATwk3_sendMessage);
}

void Heavy_SoundScraper::cBinop_707ATwk3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Joe51ZvW, HV_BINOP_SUBTRACT, 1, m, &cBinop_Joe51ZvW_sendMessage);
}

void Heavy_SoundScraper::cCast_c1XbZHwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qTGEWcIO, 0, m, &cDelay_qTGEWcIO_sendMessage);
}

void Heavy_SoundScraper::cBinop_20TFSDGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qTGEWcIO, 2, m, &cDelay_qTGEWcIO_sendMessage);
}

void Heavy_SoundScraper::cBinop_4Me6p19z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_20TFSDGv_sendMessage);
}

void Heavy_SoundScraper::cCast_szjv8TzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EDmWy7Rk, 0, m, &cVar_EDmWy7Rk_sendMessage);
  cMsg_11ALiNhX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EVlkGzkC, 0, m, &cTabhead_EVlkGzkC_sendMessage);
}

void Heavy_SoundScraper::cMsg_XQjqXu2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aPhUmv7n_sendMessage);
}

void Heavy_SoundScraper::cSystem_aPhUmv7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_79UZHp85_sendMessage);
}

void Heavy_SoundScraper::cDelay_Fnvyd03O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Fnvyd03O, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NiNZJrp9, 0, m, &cDelay_NiNZJrp9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fnvyd03O, 0, m, &cDelay_Fnvyd03O_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_EnuyWmm3, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_NiNZJrp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NiNZJrp9, m);
  cMsg_ECqvSxIR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_yZxS47e4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_uqdZKSCQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_IIZyrZyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kUpDF9l7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_plbZ7cRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QK7gXOvo_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fnvyd03O, 2, m, &cDelay_Fnvyd03O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zMjee6fI_sendMessage);
}

void Heavy_SoundScraper::cMsg_kUpDF9l7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_plbZ7cRO, 0, m, &hTable_plbZ7cRO_sendMessage);
}

void Heavy_SoundScraper::cBinop_79UZHp85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_IIZyrZyB_sendMessage);
}

void Heavy_SoundScraper::cMsg_ECqvSxIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_plbZ7cRO, 0, m, &hTable_plbZ7cRO_sendMessage);
}

void Heavy_SoundScraper::cCast_zMjee6fI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fnvyd03O, 0, m, &cDelay_Fnvyd03O_sendMessage);
}

void Heavy_SoundScraper::cMsg_QK7gXOvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_NiNZJrp9, 2, m, &cDelay_NiNZJrp9_sendMessage);
}

void Heavy_SoundScraper::cMsg_uqdZKSCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_EnuyWmm3, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_X2RYRf3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KHl4n7sf, HV_BINOP_SUBTRACT, 0, m, &cBinop_KHl4n7sf_sendMessage);
}

void Heavy_SoundScraper::cMsg_R0NcDQH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gHqW7nI4_sendMessage);
}

void Heavy_SoundScraper::cSystem_gHqW7nI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wRhmpjoO_sendMessage);
}

void Heavy_SoundScraper::cVar_oSZotN2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K80bN2ch_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_fA0UQEmC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fA0UQEmC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_x8OIVpjg, 0, m, &cDelay_x8OIVpjg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_i0JcSFnt, 0, m, &sTabread_i0JcSFnt_sendMessage);
}

void Heavy_SoundScraper::cDelay_x8OIVpjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_x8OIVpjg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_i0JcSFnt, 0, m, &sTabread_i0JcSFnt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_x8OIVpjg, 0, m, &cDelay_x8OIVpjg_sendMessage);
}

void Heavy_SoundScraper::sTabread_i0JcSFnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aIt6ADMS, HV_BINOP_SUBTRACT, 0, m, &cBinop_aIt6ADMS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_orkkOlom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O6g8I43V, HV_BINOP_MAX, 0, m, &cBinop_O6g8I43V_sendMessage);
}

void Heavy_SoundScraper::cBinop_wRhmpjoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_orkkOlom, HV_BINOP_MULTIPLY, 0, m, &cBinop_orkkOlom_sendMessage);
}

void Heavy_SoundScraper::cBinop_KHl4n7sf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CF0oQiZR_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_i0JcSFnt, 0, m, &sTabread_i0JcSFnt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T56ElEu3_sendMessage);
}

void Heavy_SoundScraper::cSystem_mhkWpoFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aIt6ADMS, HV_BINOP_SUBTRACT, 1, m, &cBinop_aIt6ADMS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_x8OIVpjg, 2, m, &cDelay_x8OIVpjg_sendMessage);
}

void Heavy_SoundScraper::cMsg_K80bN2ch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mhkWpoFo_sendMessage);
}

void Heavy_SoundScraper::cMsg_CF0oQiZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fA0UQEmC, 0, m, &cDelay_fA0UQEmC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_x8OIVpjg, 0, m, &cDelay_x8OIVpjg_sendMessage);
}

void Heavy_SoundScraper::cMsg_uxX5zwDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_O6g8I43V, HV_BINOP_MAX, 1, m, &cBinop_O6g8I43V_sendMessage);
}

void Heavy_SoundScraper::cBinop_O6g8I43V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KHl4n7sf, HV_BINOP_SUBTRACT, 1, m, &cBinop_KHl4n7sf_sendMessage);
}

void Heavy_SoundScraper::cCast_T56ElEu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fA0UQEmC, 0, m, &cDelay_fA0UQEmC_sendMessage);
}

void Heavy_SoundScraper::cBinop_dCEFOsnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fA0UQEmC, 2, m, &cDelay_fA0UQEmC_sendMessage);
}

void Heavy_SoundScraper::cBinop_aIt6ADMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dCEFOsnX_sendMessage);
}

void Heavy_SoundScraper::cCast_7cPf5YfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oSZotN2e, 0, m, &cVar_oSZotN2e_sendMessage);
  cMsg_R0NcDQH0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_X2RYRf3W, 0, m, &cTabhead_X2RYRf3W_sendMessage);
}

void Heavy_SoundScraper::cMsg_3Ff1doxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wX7VxEXE_sendMessage);
}

void Heavy_SoundScraper::cSystem_wX7VxEXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zhwSluSj_sendMessage);
}

void Heavy_SoundScraper::cDelay_hacfPVPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hacfPVPV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rlujc4uw, 0, m, &cDelay_rlujc4uw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hacfPVPV, 0, m, &cDelay_hacfPVPV_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_f8rBzpT0, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_rlujc4uw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rlujc4uw, m);
  cMsg_JKUNIIdy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_tY9Zv5sX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_TNOICn5Y_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_OcrsOfmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X4BfPhM4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_O7V4a1Mb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nziF5F5h_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hacfPVPV, 2, m, &cDelay_hacfPVPV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3o3xrM87_sendMessage);
}

void Heavy_SoundScraper::cMsg_X4BfPhM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_O7V4a1Mb, 0, m, &hTable_O7V4a1Mb_sendMessage);
}

void Heavy_SoundScraper::cBinop_zhwSluSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_OcrsOfmw_sendMessage);
}

void Heavy_SoundScraper::cMsg_JKUNIIdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_O7V4a1Mb, 0, m, &hTable_O7V4a1Mb_sendMessage);
}

void Heavy_SoundScraper::cCast_3o3xrM87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hacfPVPV, 0, m, &cDelay_hacfPVPV_sendMessage);
}

void Heavy_SoundScraper::cMsg_nziF5F5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rlujc4uw, 2, m, &cDelay_rlujc4uw_sendMessage);
}

void Heavy_SoundScraper::cMsg_TNOICn5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_f8rBzpT0, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_yp8tEV7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yZNhN76s, 0, m, &cVar_yZNhN76s_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nWojawMq, 0, m, &cVar_nWojawMq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_91ipxeix, 0, m, &cVar_91ipxeix_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Csrnrx4g, 0, m, &cVar_Csrnrx4g_sendMessage);
}

void Heavy_SoundScraper::cVar_v632NFJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_aeAPLq2w_sendMessage);
}

void Heavy_SoundScraper::cPack_UO5cZDeG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_sYRsyTvl, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_nWojawMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VaNG037W, HV_BINOP_MULTIPLY, 0, m, &cBinop_VaNG037W_sendMessage);
}

void Heavy_SoundScraper::cMsg_J9P8Czxc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FHXeV4jO_sendMessage);
}

void Heavy_SoundScraper::cSystem_FHXeV4jO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dq7g2IQ6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_VaNG037W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_CRMIj1Ql_sendMessage);
}

void Heavy_SoundScraper::cBinop_yWgFXGJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VaNG037W, HV_BINOP_MULTIPLY, 1, m, &cBinop_VaNG037W_sendMessage);
}

void Heavy_SoundScraper::cMsg_Dq7g2IQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yWgFXGJf_sendMessage);
}

void Heavy_SoundScraper::cBinop_CRMIj1Ql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FcYzyS3M_sendMessage);
}

void Heavy_SoundScraper::cBinop_FcYzyS3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VSLpDcp9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hJolvPgs, m);
}

void Heavy_SoundScraper::cBinop_VSLpDcp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EPam9V9c, m);
}

void Heavy_SoundScraper::cVar_91ipxeix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OC09kgSZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_OC09kgSZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_JHOE7l2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TzJ7wN4A_sendMessage);
}

void Heavy_SoundScraper::cSystem_TzJ7wN4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9C4bXLxB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_OC09kgSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pLRKPjXR_sendMessage);
}

void Heavy_SoundScraper::cBinop_tAc0Lcbt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OC09kgSZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_OC09kgSZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_9C4bXLxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tAc0Lcbt_sendMessage);
}

void Heavy_SoundScraper::cBinop_pLRKPjXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_x6Sit9dl_sendMessage);
}

void Heavy_SoundScraper::cBinop_x6Sit9dl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_sT3bsvzE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hWrKq9xo, m);
}

void Heavy_SoundScraper::cBinop_sT3bsvzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8K8Duhci, m);
}

void Heavy_SoundScraper::cVar_Csrnrx4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bt32WKnP, HV_BINOP_MULTIPLY, 0, m, &cBinop_Bt32WKnP_sendMessage);
}

void Heavy_SoundScraper::cMsg_iftnKiXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ewfeXJit_sendMessage);
}

void Heavy_SoundScraper::cSystem_ewfeXJit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5J8IFw16_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Bt32WKnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9HKIlnSc_sendMessage);
}

void Heavy_SoundScraper::cBinop_IF3HiJRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bt32WKnP, HV_BINOP_MULTIPLY, 1, m, &cBinop_Bt32WKnP_sendMessage);
}

void Heavy_SoundScraper::cMsg_5J8IFw16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IF3HiJRI_sendMessage);
}

void Heavy_SoundScraper::cBinop_9HKIlnSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zBvVSbO5_sendMessage);
}

void Heavy_SoundScraper::cBinop_zBvVSbO5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_0cDCSuEl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nFdICq5e, m);
}

void Heavy_SoundScraper::cBinop_0cDCSuEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PA0Xp42U, m);
}

void Heavy_SoundScraper::cBinop_lLlJv1io_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_shm7US60, 0, m, &cPack_shm7US60_sendMessage);
}

void Heavy_SoundScraper::cMsg_FokatoUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_yp8tEV7I, 0, m, &cVar_yp8tEV7I_sendMessage);
}

void Heavy_SoundScraper::cBinop_aeAPLq2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UO5cZDeG, 0, m, &cPack_UO5cZDeG_sendMessage);
}

void Heavy_SoundScraper::cBinop_o4RmdGWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gJ8v7VI2, 0, m, &cPack_gJ8v7VI2_sendMessage);
}

void Heavy_SoundScraper::cMsg_Jq5zIY0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ocWw9n3W_sendMessage);
}

void Heavy_SoundScraper::cSystem_ocWw9n3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SzuZ6nH9_sendMessage);
}

void Heavy_SoundScraper::cVar_scFS7rvD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F5fpguHc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_OMQJAfQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_gT0wyYc4_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6LKgDjQg, m);
}

void Heavy_SoundScraper::cBinop_SzuZ6nH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CO3ZVPnp, m);
}

void Heavy_SoundScraper::cMsg_F5fpguHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OMQJAfQ9_sendMessage);
}

void Heavy_SoundScraper::cBinop_gT0wyYc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_be8xJBFC, m);
}

void Heavy_SoundScraper::cVar_g3AY7716_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1DLdzFV7, HV_BINOP_MULTIPLY, 0, m, &cBinop_1DLdzFV7_sendMessage);
}

void Heavy_SoundScraper::cMsg_AlFE28Q7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JmxOpMdh_sendMessage);
}

void Heavy_SoundScraper::cSystem_JmxOpMdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MzBlKOwM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1DLdzFV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fkIIGoVh_sendMessage);
}

void Heavy_SoundScraper::cBinop_GrF0qVc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1DLdzFV7, HV_BINOP_MULTIPLY, 1, m, &cBinop_1DLdzFV7_sendMessage);
}

void Heavy_SoundScraper::cMsg_MzBlKOwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_GrF0qVc9_sendMessage);
}

void Heavy_SoundScraper::cBinop_fkIIGoVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dDPCvlDi_sendMessage);
}

void Heavy_SoundScraper::cBinop_dDPCvlDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wFLqCnwP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TTnqFH6X, m);
}

void Heavy_SoundScraper::cBinop_wFLqCnwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LZsKZ7dZ, m);
}

void Heavy_SoundScraper::cBinop_xNaLdRpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_0T2D7hGX_sendMessage);
}

void Heavy_SoundScraper::cBinop_0T2D7hGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_spK6gjBk, m);
}

void Heavy_SoundScraper::cBinop_472gPmZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_w0O3kxMj_sendMessage);
}

void Heavy_SoundScraper::cBinop_w0O3kxMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ScA4zD5M_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yHyrNsfn_sendMessage);
}

void Heavy_SoundScraper::cVar_9lofG6oX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_vkUc3Woj_sendMessage);
}

void Heavy_SoundScraper::cMsg_z4ONdsLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VPWWhzuy_sendMessage);
}

void Heavy_SoundScraper::cSystem_VPWWhzuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QzN595pi, HV_BINOP_DIVIDE, 1, m, &cBinop_QzN595pi_sendMessage);
}

void Heavy_SoundScraper::cBinop_ScA4zD5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_IVBOTZNw_sendMessage);
}

void Heavy_SoundScraper::cBinop_IVBOTZNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DNyToRCo, m);
}

void Heavy_SoundScraper::cMsg_vT9VitAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_M2OMIByD_sendMessage);
}

void Heavy_SoundScraper::cBinop_M2OMIByD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_472gPmZ7_sendMessage);
}

void Heavy_SoundScraper::cBinop_yHyrNsfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8qtcMVtS, m);
}

void Heavy_SoundScraper::cBinop_vkUc3Woj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_pShWWyS1_sendMessage);
}

void Heavy_SoundScraper::cBinop_pShWWyS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QzN595pi, HV_BINOP_DIVIDE, 0, m, &cBinop_QzN595pi_sendMessage);
}

void Heavy_SoundScraper::cBinop_QzN595pi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vT9VitAn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_3lSQyMMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xQ7to0fS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_aYB0rlYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eajlPBOu_sendMessage);
}

void Heavy_SoundScraper::cSystem_eajlPBOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MNW52oGf_sendMessage);
}

void Heavy_SoundScraper::cDelay_rlyYVu0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rlyYVu0d, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V1N2L3ff, 0, m, &cDelay_V1N2L3ff_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rlyYVu0d, 0, m, &cDelay_rlyYVu0d_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZuEGUlfr, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_V1N2L3ff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V1N2L3ff, m);
  cMsg_eRDbNW9Q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_1r5hcFrZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_NB6Z4wnX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_I43iks7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QqozkIjA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_pu0SzX3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ye9q5Aqx_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rlyYVu0d, 2, m, &cDelay_rlyYVu0d_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qlxfIi27_sendMessage);
}

void Heavy_SoundScraper::cMsg_QqozkIjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_pu0SzX3H, 0, m, &hTable_pu0SzX3H_sendMessage);
}

void Heavy_SoundScraper::cBinop_MNW52oGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_I43iks7l_sendMessage);
}

void Heavy_SoundScraper::cMsg_eRDbNW9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_pu0SzX3H, 0, m, &hTable_pu0SzX3H_sendMessage);
}

void Heavy_SoundScraper::cCast_qlxfIi27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rlyYVu0d, 0, m, &cDelay_rlyYVu0d_sendMessage);
}

void Heavy_SoundScraper::cMsg_ye9q5Aqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_V1N2L3ff, 2, m, &cDelay_V1N2L3ff_sendMessage);
}

void Heavy_SoundScraper::cMsg_NB6Z4wnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZuEGUlfr, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_fEkSmIAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_xQ7to0fS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_xQ7to0fS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_LrVEa7hq, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_zgGZN6z8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RBcAbHIH, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_6HlxZttq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zgGZN6z8, 0, m, &cPack_zgGZN6z8_sendMessage);
}

void Heavy_SoundScraper::cCast_6OfJJtal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_o2Exdedo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_vivvT3jh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_RBcAbHIH, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_UktzKYpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8zPLjoQc, m);
}

void Heavy_SoundScraper::cMsg_nKfCvS3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xNaLdRpM_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_chxjqKUe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0nDtdAwC, 0, m, &cSlice_0nDtdAwC_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_48zL3RF4, 0, m, &cRandom_48zL3RF4_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_W0ZnaLxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7iaD0zLB_sendMessage);
}

void Heavy_SoundScraper::cUnop_7iaD0zLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_my9RCPYa_sendMessage);
}

void Heavy_SoundScraper::cRandom_48zL3RF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_W0ZnaLxi_sendMessage);
}

void Heavy_SoundScraper::cSlice_0nDtdAwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_48zL3RF4, 1, m, &cRandom_48zL3RF4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_6hN0dfIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_spT2TXtR, HV_BINOP_DIVIDE, 0, m, &cBinop_spT2TXtR_sendMessage);
}

void Heavy_SoundScraper::cBinop_D9x0FP7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_I2TnsKQ4_sendMessage);
}

void Heavy_SoundScraper::cBinop_I2TnsKQ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u2Yni7yZ, HV_BINOP_POW, 1, m, &cBinop_u2Yni7yZ_sendMessage);
  cMsg_sLookuyc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_u2Yni7yZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_6hN0dfIh_sendMessage);
}

void Heavy_SoundScraper::cMsg_sLookuyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_u2Yni7yZ, HV_BINOP_POW, 0, m, &cBinop_u2Yni7yZ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_AeIeeYj3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7tdyfwLL, 0, m, &cSlice_7tdyfwLL_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ThHSouTJ, 0, m, &cRandom_ThHSouTJ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_uj0fkRYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GvVCQhmK_sendMessage);
}

void Heavy_SoundScraper::cUnop_GvVCQhmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qljoy100_sendMessage);
}

void Heavy_SoundScraper::cRandom_ThHSouTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_uj0fkRYY_sendMessage);
}

void Heavy_SoundScraper::cSlice_7tdyfwLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ThHSouTJ, 1, m, &cRandom_ThHSouTJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_eM5jN6JG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_ZmLf9F1R_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_aZfbopva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_rs1GWqDq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_3ShrnTBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IHMwtslY, 0, m, &cPack_IHMwtslY_sendMessage);
}

void Heavy_SoundScraper::cUnop_gH4wVctM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RUePdS9W, 0, m, &cPack_RUePdS9W_sendMessage);
}

void Heavy_SoundScraper::cPack_RUePdS9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_vZWrJGpE, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_IHMwtslY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_3Oe9ttxx, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_XhvVly2Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_3ShrnTBt_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_gH4wVctM_sendMessage);
}

void Heavy_SoundScraper::cMsg_DPNEvlq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_XhvVly2Z_sendMessage);
}

void Heavy_SoundScraper::cCast_77fJ83fk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_RkkYb3Tl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H0Yzg7DU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o9kIiaCN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZN07VTSU_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_StPBbwRn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_dGZRMAiR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_dGZRMAiR_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TBTaxoqE, 1, m, &cDelay_TBTaxoqE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5wOUZV6Y_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_TBTaxoqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TBTaxoqE, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Su3sbATu, 0, m, &cVar_Su3sbATu_sendMessage);
}

void Heavy_SoundScraper::cMsg_dGZRMAiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TBTaxoqE, 0, m, &cDelay_TBTaxoqE_sendMessage);
}

void Heavy_SoundScraper::cCast_5wOUZV6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TBTaxoqE, 0, m, &cDelay_TBTaxoqE_sendMessage);
}

void Heavy_SoundScraper::cVar_Su3sbATu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wdU9GiIV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_6d03ONvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RkkYb3Tl, 0, m, &cVar_RkkYb3Tl_sendMessage);
}

void Heavy_SoundScraper::cSend_4JgNqSlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_Letnzars_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OVKAaoWo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Jy6G69oz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_4JgNqSlq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_2zMNhWK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_Letnzars_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_SW867yJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MESMY1J5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Jg9P6Gm8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_SW867yJd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_wsaHEsRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_yQh7gPHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OVKAaoWo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_XdcRzhUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MESMY1J5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_SoT97prj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_AWOvZvHv, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_wdU9GiIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_AWOvZvHv, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_H0Yzg7DU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SoT97prj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_o9kIiaCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Su3sbATu, 1, m, &cVar_Su3sbATu_sendMessage);
}

void Heavy_SoundScraper::cCast_ZN07VTSU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_StPBbwRn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_0FP8lqAe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9LhRvvsK, 0, m, &cSlice_9LhRvvsK_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_gu6vDZ1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7aDk7STI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_tEYdGlqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_n5gpvJON_sendMessage);
}

void Heavy_SoundScraper::cBinop_n5gpvJON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lUTpKDPn, m);
}

void Heavy_SoundScraper::cMsg_7aDk7STI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tEYdGlqD_sendMessage);
}

void Heavy_SoundScraper::cSlice_9LhRvvsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_YNp8IIEx, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_WlYtYe97, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_gu6vDZ1z, 0, m, &cVar_gu6vDZ1z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_p5nLYLjc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_P8STOGKQ, 0, m, &cPack_P8STOGKQ_sendMessage);
}

void Heavy_SoundScraper::cVar_7dBvNyLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_gXhPS0XN_sendMessage);
}

void Heavy_SoundScraper::cIf_lAB9uDtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_gVKanS06_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_7dBvNyLG, 1, m, &cVar_7dBvNyLG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_cgj3Ui8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lAB9uDtR, 1, m, &cIf_lAB9uDtR_sendMessage);
}

void Heavy_SoundScraper::cVar_kqZ98AUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_E3QcEzNH_sendMessage);
}

void Heavy_SoundScraper::cUnop_gVKanS06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kqZ98AUE, 1, m, &cVar_kqZ98AUE_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_OegVZYqh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zcmPwP8G_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ea9Q4Fkl_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_zcmPwP8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7dBvNyLG, 0, m, &cVar_7dBvNyLG_sendMessage);
}

void Heavy_SoundScraper::cCast_Ea9Q4Fkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kqZ98AUE, 0, m, &cVar_kqZ98AUE_sendMessage);
}

void Heavy_SoundScraper::cVar_RJfd049d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_IJKRJHuZ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_8k54TgTZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Uy3uOF01_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Uy3uOF01_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_XYoMzWQA, 1, m, &cDelay_XYoMzWQA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i1SXf7fn_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_XYoMzWQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XYoMzWQA, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iipohoH8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zSkyoGUv_sendMessage);
}

void Heavy_SoundScraper::cMsg_Uy3uOF01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XYoMzWQA, 0, m, &cDelay_XYoMzWQA_sendMessage);
}

void Heavy_SoundScraper::cCast_i1SXf7fn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XYoMzWQA, 0, m, &cDelay_XYoMzWQA_sendMessage);
}

void Heavy_SoundScraper::cPack_zWanMZGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YGO3FFVr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_l1PAMwLz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gfwSnOh3_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bl7JRjYx, HV_BINOP_SUBTRACT, 0, m, &cBinop_bl7JRjYx_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_gfwSnOh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WcBsAhCD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_KQWp1lgt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_JWaYcI3Z_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_JWaYcI3Z_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_vXXQolW1, 1, m, &cDelay_vXXQolW1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oUJFzLwH_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_vXXQolW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vXXQolW1, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_epoOp16I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yWs3PlRT_sendMessage);
}

void Heavy_SoundScraper::cMsg_JWaYcI3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_vXXQolW1, 0, m, &cDelay_vXXQolW1_sendMessage);
}

void Heavy_SoundScraper::cCast_oUJFzLwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vXXQolW1, 0, m, &cDelay_vXXQolW1_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ZoZjLSJ8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_4kYDops8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_4kYDops8_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_mCmAGTwm, 1, m, &cDelay_mCmAGTwm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JCI3bHL1_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_mCmAGTwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mCmAGTwm, m);
}

void Heavy_SoundScraper::cMsg_4kYDops8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCmAGTwm, 0, m, &cDelay_mCmAGTwm_sendMessage);
}

void Heavy_SoundScraper::cCast_JCI3bHL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCmAGTwm, 0, m, &cDelay_mCmAGTwm_sendMessage);
}

void Heavy_SoundScraper::cPack_8X87rs1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BaLeAcxi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_6z0di25y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qTRvtHe2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_XPu4sCbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AjgxaJTG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_b0MnaHtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zQSojvjk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_gaF8cQvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_STrLxzuG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_918OYDxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mDEKTdKF, HV_BINOP_DIVIDE, 1, m, &cBinop_mDEKTdKF_sendMessage);
}

void Heavy_SoundScraper::cVar_GnjBeYxt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mDEKTdKF, HV_BINOP_DIVIDE, 0, m, &cBinop_mDEKTdKF_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_PFapBzgr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_viRBYpLG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G2UrbWtK_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EUtNZVsV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IYBHLEX4_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_viRBYpLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_918OYDxm, 0, m, &cVar_918OYDxm_sendMessage);
}

void Heavy_SoundScraper::cCast_G2UrbWtK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GnjBeYxt, 0, m, &cVar_GnjBeYxt_sendMessage);
}

void Heavy_SoundScraper::cCast_EUtNZVsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_918OYDxm, 0, m, &cVar_918OYDxm_sendMessage);
}

void Heavy_SoundScraper::cCast_IYBHLEX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GnjBeYxt, 0, m, &cVar_GnjBeYxt_sendMessage);
}

void Heavy_SoundScraper::cPack_P8STOGKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_H340dMoZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_SPFsJJpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_zWanMZGz, 1, m, &cPack_zWanMZGz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_W6ngLFPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KMyVXarS, HV_BINOP_ADD, 0, m, &cBinop_KMyVXarS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_2JJ9PHgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_8X87rs1e, 1, m, &cPack_8X87rs1e_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_yhoml6Su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RsVHGeaR, HV_BINOP_ADD, 0, m, &cBinop_RsVHGeaR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_zSkyoGUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p5nLYLjc, 0, m, &cVar_p5nLYLjc_sendMessage);
}

void Heavy_SoundScraper::cCast_iipohoH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RJfd049d, 0, m, &cVar_RJfd049d_sendMessage);
}

void Heavy_SoundScraper::cSend_YGO3FFVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Bhekm82E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_H340dMoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0LYzycFC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_zQSojvjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0LYzycFC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_gl4Wc1L7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8k54TgTZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_GAO7EUnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_b0MnaHtg, 0, m, &cPack_b0MnaHtg_sendMessage);
}

void Heavy_SoundScraper::cBinop_gXhPS0XN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XPu4sCbD, 0, m, &cPack_XPu4sCbD_sendMessage);
}

void Heavy_SoundScraper::cSend_BaLeAcxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Bhekm82E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_E3QcEzNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6z0di25y, 0, m, &cPack_6z0di25y_sendMessage);
}

void Heavy_SoundScraper::cBinop_IJKRJHuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OegVZYqh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_KMyVXarS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zWanMZGz, 0, m, &cPack_zWanMZGz_sendMessage);
}

void Heavy_SoundScraper::cBinop_bl7JRjYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KQWp1lgt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_RsVHGeaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8X87rs1e, 0, m, &cPack_8X87rs1e_sendMessage);
}

void Heavy_SoundScraper::cMsg_WcBsAhCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_KQWp1lgt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_ZbfKYgsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4qDKaQM, HV_BINOP_MULTIPLY, 1, m, &cBinop_Y4qDKaQM_sendMessage);
}

void Heavy_SoundScraper::cMsg_qTRvtHe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_2JJ9PHgg, 0, m, &cSlice_2JJ9PHgg_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yhoml6Su, 0, m, &cSlice_yhoml6Su_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_2JJ9PHgg, 0, m, &cSlice_2JJ9PHgg_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yhoml6Su, 0, m, &cSlice_yhoml6Su_sendMessage);
}

void Heavy_SoundScraper::cBinop_AxRt1PYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6z0di25y, 1, m, &cPack_6z0di25y_sendMessage);
}

void Heavy_SoundScraper::cBinop_QhvPxXfK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XPu4sCbD, 1, m, &cPack_XPu4sCbD_sendMessage);
}

void Heavy_SoundScraper::cMsg_AjgxaJTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SPFsJJpt, 0, m, &cSlice_SPFsJJpt_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_W6ngLFPD, 0, m, &cSlice_W6ngLFPD_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SPFsJJpt, 0, m, &cSlice_SPFsJJpt_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_W6ngLFPD, 0, m, &cSlice_W6ngLFPD_sendMessage);
}

void Heavy_SoundScraper::cSend_STrLxzuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0LYzycFC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_mDEKTdKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_cgj3Ui8X_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_lAB9uDtR, 0, m, &cIf_lAB9uDtR_sendMessage);
}

void Heavy_SoundScraper::cCast_gVx1UEil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XYoMzWQA, 1, m, &cDelay_XYoMzWQA_sendMessage);
}

void Heavy_SoundScraper::cCast_KovtDPqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_b0MnaHtg, 1, m, &cPack_b0MnaHtg_sendMessage);
}

void Heavy_SoundScraper::cCast_5rRVAMWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RsVHGeaR, HV_BINOP_ADD, 1, m, &cBinop_RsVHGeaR_sendMessage);
}

void Heavy_SoundScraper::cCast_2YoQiJNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KMyVXarS, HV_BINOP_ADD, 1, m, &cBinop_KMyVXarS_sendMessage);
}

void Heavy_SoundScraper::cCast_XcHGm8Cj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCmAGTwm, 1, m, &cDelay_mCmAGTwm_sendMessage);
}

void Heavy_SoundScraper::cCast_rHyIGJ2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bl7JRjYx, HV_BINOP_SUBTRACT, 1, m, &cBinop_bl7JRjYx_sendMessage);
}

void Heavy_SoundScraper::cCast_yWs3PlRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gaF8cQvI, 0, m, &cPack_gaF8cQvI_sendMessage);
}

void Heavy_SoundScraper::cCast_epoOp16I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZoZjLSJ8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_yLRqJcCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KQWp1lgt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_l1txTO3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZoZjLSJ8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_Y4qDKaQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5rRVAMWZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2YoQiJNM_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_jTixYCFt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jzLOYAv0_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_p5nLYLjc, 1, m, &cVar_p5nLYLjc_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_jzLOYAv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GxE4xmhR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_KNZUVpXw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FCUcvnZr_sendMessage);
      break;
    }
    default: {
      cSwitchcase_PFapBzgr_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_RJfd049d, 1, m, &cVar_RJfd049d_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_FCUcvnZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bXHcPIXD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_BAcNX67s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_ewD5Z4Wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_l1PAMwLz_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_OJ2lH8T5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Y4qDKaQM, HV_BINOP_MULTIPLY, 0, m, &cBinop_Y4qDKaQM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_LctWIVdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_KNZUVpXw_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_phOIDWsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_IdrThWfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_jTixYCFt_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_GxE4xmhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_p5nLYLjc, 1, m, &cVar_p5nLYLjc_sendMessage);
}

void Heavy_SoundScraper::cCast_ppDryS0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jjR3TrYJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_bXHcPIXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_PFapBzgr_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_RJfd049d, 1, m, &cVar_RJfd049d_sendMessage);
}

void Heavy_SoundScraper::cMsg_jjR3TrYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BAcNX67s, 0, m, &cSlice_BAcNX67s_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ewD5Z4Wq, 0, m, &cSlice_ewD5Z4Wq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OJ2lH8T5, 0, m, &cSlice_OJ2lH8T5_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_LctWIVdM, 0, m, &cSlice_LctWIVdM_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_phOIDWsR, 0, m, &cSlice_phOIDWsR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IdrThWfS, 0, m, &cSlice_IdrThWfS_sendMessage);
}

void Heavy_SoundScraper::cSlice_rnwZzIsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kjX88Zmx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_7It9OtHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FlNk6XvH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_FlNk6XvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_84A8eTN9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_84A8eTN9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QPfXE6n0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_kjX88Zmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tvg2YWzi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_tvg2YWzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ac3kk4og_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_3fOD3mIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S1Mlh5Td_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_pp01XbA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h7mgJUAH, HV_BINOP_MULTIPLY, 1, m, &cBinop_h7mgJUAH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CdGKJE3h, HV_BINOP_MULTIPLY, 1, m, &cBinop_CdGKJE3h_sendMessage);
}

void Heavy_SoundScraper::cSlice_3CNNKj1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_h7mgJUAH, HV_BINOP_MULTIPLY, 0, m, &cBinop_h7mgJUAH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_zkRf0knm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_CdGKJE3h, HV_BINOP_MULTIPLY, 0, m, &cBinop_CdGKJE3h_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_S1Mlh5Td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_hVYveCsE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_hVYveCsE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 220500000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cMsg_mkByFJKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_3CNNKj1f, 0, m, &cSlice_3CNNKj1f_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_zkRf0knm, 0, m, &cSlice_zkRf0knm_sendMessage);
}

void Heavy_SoundScraper::cBinop_h7mgJUAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3fOD3mIE, 1, m, &cPack_3fOD3mIE_sendMessage);
}

void Heavy_SoundScraper::cBinop_CdGKJE3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3fOD3mIE, 0, m, &cPack_3fOD3mIE_sendMessage);
}

void Heavy_SoundScraper::cSend_yCqXCnw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fkdRS3Kk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Yj1oQyTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_0FP8lqAe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_CRpRDZp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_7YGc7yph_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_wQ88IDIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FQwKm54s_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_D9x0FP7G_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_7G7dgBiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_utahBbbx, 1, m, &cPack_utahBbbx_sendMessage);
}

void Heavy_SoundScraper::cVar_dhBNIU1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_utahBbbx, 0, m, &cPack_utahBbbx_sendMessage);
}

void Heavy_SoundScraper::cPack_utahBbbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DprbFun8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dL64hUTZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ppDryS0M_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BAcNX67s, 0, m, &cSlice_BAcNX67s_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ewD5Z4Wq, 0, m, &cSlice_ewD5Z4Wq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OJ2lH8T5, 0, m, &cSlice_OJ2lH8T5_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_LctWIVdM, 0, m, &cSlice_LctWIVdM_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_phOIDWsR, 0, m, &cSlice_phOIDWsR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IdrThWfS, 0, m, &cSlice_IdrThWfS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GAO7EUnr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gl4Wc1L7_sendMessage);
  cMsg_Yj1oQyTC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Q5rFYBYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7G7dgBiJ, 0, m, &cVar_7G7dgBiJ_sendMessage);
}

void Heavy_SoundScraper::cCast_DEbCxj5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_utahBbbx, 2, m, &cPack_utahBbbx_sendMessage);
}

void Heavy_SoundScraper::cCast_TSXQqEE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dhBNIU1O, 0, m, &cVar_dhBNIU1O_sendMessage);
}

void Heavy_SoundScraper::cBinop_my9RCPYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_B9cGRdkz_sendMessage);
}

void Heavy_SoundScraper::cBinop_B9cGRdkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_XhvVly2Z_sendMessage);
}

void Heavy_SoundScraper::cBinop_7YGc7yph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vPCXm7VW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_cPou3RBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DEbCxj5W_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q5rFYBYJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TSXQqEE2_sendMessage);
}

void Heavy_SoundScraper::cBinop_qljoy100_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_kJYZjKyU_sendMessage);
}

void Heavy_SoundScraper::cBinop_kJYZjKyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cPou3RBd, HV_BINOP_MULTIPLY, 1, m, &cBinop_cPou3RBd_sendMessage);
}

void Heavy_SoundScraper::cCast_FQwKm54s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AeIeeYj3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_DprbFun8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_chxjqKUe_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_77fJ83fk_sendMessage);
}

void Heavy_SoundScraper::cCast_dL64hUTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6d03ONvW_sendMessage);
}

void Heavy_SoundScraper::cSend_rs1GWqDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dLELQr31_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ZmLf9F1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_F8iOnRlU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_spT2TXtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cPou3RBd, HV_BINOP_MULTIPLY, 0, m, &cBinop_cPou3RBd_sendMessage);
}

void Heavy_SoundScraper::cSend_vPCXm7VW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xaLHXMlu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_7sjdcym1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_yCqXCnw1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_gMRXVYsQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZexMb6rw, 0, m, &cSlice_ZexMb6rw_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xH2Mgc0t, 0, m, &cRandom_xH2Mgc0t_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_5E1osWFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nyXjJVcL_sendMessage);
}

void Heavy_SoundScraper::cUnop_nyXjJVcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_ObIYIsIE_sendMessage);
}

void Heavy_SoundScraper::cRandom_xH2Mgc0t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_5E1osWFV_sendMessage);
}

void Heavy_SoundScraper::cSlice_ZexMb6rw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xH2Mgc0t, 1, m, &cRandom_xH2Mgc0t_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_MwGSpbin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EUY59TKI, HV_BINOP_DIVIDE, 0, m, &cBinop_EUY59TKI_sendMessage);
}

void Heavy_SoundScraper::cBinop_bweaZCiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_t6CIzgvj_sendMessage);
}

void Heavy_SoundScraper::cBinop_t6CIzgvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S95kbzCu, HV_BINOP_POW, 1, m, &cBinop_S95kbzCu_sendMessage);
  cMsg_zS6lKfes_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_S95kbzCu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_MwGSpbin_sendMessage);
}

void Heavy_SoundScraper::cMsg_zS6lKfes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_S95kbzCu, HV_BINOP_POW, 0, m, &cBinop_S95kbzCu_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_oJyrCG9b_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QAVtC7su, 0, m, &cSlice_QAVtC7su_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fKI6Pamx, 0, m, &cRandom_fKI6Pamx_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_6Dhc3Z37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_koSbMWte_sendMessage);
}

void Heavy_SoundScraper::cUnop_koSbMWte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cY6ksEWF_sendMessage);
}

void Heavy_SoundScraper::cRandom_fKI6Pamx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_6Dhc3Z37_sendMessage);
}

void Heavy_SoundScraper::cSlice_QAVtC7su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fKI6Pamx, 1, m, &cRandom_fKI6Pamx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_MDZOpyys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_8k8Jf2DP_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_JfXcUTAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_9OGzdzb8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_fc1lGOpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cQSHXkBn, 0, m, &cPack_cQSHXkBn_sendMessage);
}

void Heavy_SoundScraper::cUnop_xYTUUiH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qCyOjIsj, 0, m, &cPack_qCyOjIsj_sendMessage);
}

void Heavy_SoundScraper::cPack_qCyOjIsj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_05eRgPab, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_cQSHXkBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_fYRZYmYC, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_DIqwQ4Zd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_fc1lGOpq_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_xYTUUiH9_sendMessage);
}

void Heavy_SoundScraper::cMsg_E2OO8AXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_DIqwQ4Zd_sendMessage);
}

void Heavy_SoundScraper::cCast_IPTJgUkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_UFwJC2AF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q5bNv5ta_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nH2e8Gbm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AgLZsTzg_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_kThS8rwC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_i6zfrDy0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_i6zfrDy0_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_3eQmorm7, 1, m, &cDelay_3eQmorm7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kc6jGAL3_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_3eQmorm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3eQmorm7, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ho34Mnea, 0, m, &cVar_ho34Mnea_sendMessage);
}

void Heavy_SoundScraper::cMsg_i6zfrDy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3eQmorm7, 0, m, &cDelay_3eQmorm7_sendMessage);
}

void Heavy_SoundScraper::cCast_Kc6jGAL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3eQmorm7, 0, m, &cDelay_3eQmorm7_sendMessage);
}

void Heavy_SoundScraper::cVar_ho34Mnea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JWtQYGQf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Cxi0gF7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UFwJC2AF, 0, m, &cVar_UFwJC2AF_sendMessage);
}

void Heavy_SoundScraper::cSend_aH2tMZYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_YAYWrMXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ktIMVuQQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Pw8Wz37N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_aH2tMZYO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_1oqpbjRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_YAYWrMXY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Rw79ZGM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BZr7WEnN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_E7bZbmaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_Rw79ZGM4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1sKo1IPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_3vTkre0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ktIMVuQQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_FRPKQi5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BZr7WEnN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_MBUosks6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Pgz7rY0l, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_JWtQYGQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_Pgz7rY0l, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_Q5bNv5ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MBUosks6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_nH2e8Gbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ho34Mnea, 1, m, &cVar_ho34Mnea_sendMessage);
}

void Heavy_SoundScraper::cCast_AgLZsTzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kThS8rwC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_a9At1H2W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TW7QmFpq, 0, m, &cSlice_TW7QmFpq_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_6GqMDbR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CckItKow_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_jYrQRcnT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_0nOE0uZE_sendMessage);
}

void Heavy_SoundScraper::cBinop_0nOE0uZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CtDBqqUJ, m);
}

void Heavy_SoundScraper::cMsg_CckItKow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jYrQRcnT_sendMessage);
}

void Heavy_SoundScraper::cSlice_TW7QmFpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_3eXZzuzi, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_AlK8zS2Z, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_6GqMDbR5, 0, m, &cVar_6GqMDbR5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_APX1fTyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zsICs8u6, 0, m, &cPack_zsICs8u6_sendMessage);
}

void Heavy_SoundScraper::cVar_DlMyC2zp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_L8hzqseD_sendMessage);
}

void Heavy_SoundScraper::cIf_MT3h1Ajo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_R3ULi7YF_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_DlMyC2zp, 1, m, &cVar_DlMyC2zp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_5BQ9tk72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MT3h1Ajo, 1, m, &cIf_MT3h1Ajo_sendMessage);
}

void Heavy_SoundScraper::cVar_A13HfCFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_i2qO7Lwp_sendMessage);
}

void Heavy_SoundScraper::cUnop_R3ULi7YF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A13HfCFZ, 1, m, &cVar_A13HfCFZ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_P4ZuLb68_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8wHhQSuS_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wfp65e8A_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_8wHhQSuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DlMyC2zp, 0, m, &cVar_DlMyC2zp_sendMessage);
}

void Heavy_SoundScraper::cCast_Wfp65e8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A13HfCFZ, 0, m, &cVar_A13HfCFZ_sendMessage);
}

void Heavy_SoundScraper::cVar_b5hN6RWb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_j1X6C21J_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_nEEf0pWK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_HJ5LMBYL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_HJ5LMBYL_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_5yN9BFkt, 1, m, &cDelay_5yN9BFkt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aB8qs6wN_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_5yN9BFkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5yN9BFkt, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tsh84G97_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dvvICKxs_sendMessage);
}

void Heavy_SoundScraper::cMsg_HJ5LMBYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5yN9BFkt, 0, m, &cDelay_5yN9BFkt_sendMessage);
}

void Heavy_SoundScraper::cCast_aB8qs6wN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5yN9BFkt, 0, m, &cDelay_5yN9BFkt_sendMessage);
}

void Heavy_SoundScraper::cPack_OD7kXYJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MitfYQPC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_uh0Jdbrz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KeZROQmd_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ynD61rHp, HV_BINOP_SUBTRACT, 0, m, &cBinop_ynD61rHp_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_KeZROQmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QukJSkEE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_zaAgfygM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_dbuceppm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_dbuceppm_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_UKfe1DLT, 1, m, &cDelay_UKfe1DLT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kKhavNtE_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_UKfe1DLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UKfe1DLT, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ThsFChFH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Tl8Aord8_sendMessage);
}

void Heavy_SoundScraper::cMsg_dbuceppm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_UKfe1DLT, 0, m, &cDelay_UKfe1DLT_sendMessage);
}

void Heavy_SoundScraper::cCast_kKhavNtE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UKfe1DLT, 0, m, &cDelay_UKfe1DLT_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ZduXLEAZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_jEloawcB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_jEloawcB_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ffh97vJ9, 1, m, &cDelay_ffh97vJ9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sLOCCtK4_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ffh97vJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ffh97vJ9, m);
}

void Heavy_SoundScraper::cMsg_jEloawcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ffh97vJ9, 0, m, &cDelay_ffh97vJ9_sendMessage);
}

void Heavy_SoundScraper::cCast_sLOCCtK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ffh97vJ9, 0, m, &cDelay_ffh97vJ9_sendMessage);
}

void Heavy_SoundScraper::cPack_dzBc4XHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_oAoDigcm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_5dshUpVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HIb9u7DZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_ee6eTebv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ad4vEVSn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_RBLiYKpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1EXfjk5M_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_oNCvUW49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Peniclls_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Fxcu6da5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kfcBUUUl, HV_BINOP_DIVIDE, 1, m, &cBinop_kfcBUUUl_sendMessage);
}

void Heavy_SoundScraper::cVar_Mk8KhKDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kfcBUUUl, HV_BINOP_DIVIDE, 0, m, &cBinop_kfcBUUUl_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_4kZibblo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RgnVz12A_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o68igDGP_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kikz2jcA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hdgTCCNS_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_o68igDGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Mk8KhKDO, 0, m, &cVar_Mk8KhKDO_sendMessage);
}

void Heavy_SoundScraper::cCast_RgnVz12A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Fxcu6da5, 0, m, &cVar_Fxcu6da5_sendMessage);
}

void Heavy_SoundScraper::cCast_Kikz2jcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Fxcu6da5, 0, m, &cVar_Fxcu6da5_sendMessage);
}

void Heavy_SoundScraper::cCast_hdgTCCNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Mk8KhKDO, 0, m, &cVar_Mk8KhKDO_sendMessage);
}

void Heavy_SoundScraper::cPack_zsICs8u6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5BVRQb4V_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_7iCymHbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_OD7kXYJD, 1, m, &cPack_OD7kXYJD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ezVM2Yf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_wo5KE4Hd, HV_BINOP_ADD, 0, m, &cBinop_wo5KE4Hd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Q8seBuOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_dzBc4XHD, 1, m, &cPack_dzBc4XHD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_kb8zdKXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZLSsrnkU, HV_BINOP_ADD, 0, m, &cBinop_ZLSsrnkU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_dvvICKxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_APX1fTyL, 0, m, &cVar_APX1fTyL_sendMessage);
}

void Heavy_SoundScraper::cCast_Tsh84G97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b5hN6RWb, 0, m, &cVar_b5hN6RWb_sendMessage);
}

void Heavy_SoundScraper::cSend_MitfYQPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oYwheUxG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_5BVRQb4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Xe9pixiI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1EXfjk5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Xe9pixiI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_20UtuLOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RBLiYKpB, 0, m, &cPack_RBLiYKpB_sendMessage);
}

void Heavy_SoundScraper::cCast_KhSRRWoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nEEf0pWK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_L8hzqseD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ee6eTebv, 0, m, &cPack_ee6eTebv_sendMessage);
}

void Heavy_SoundScraper::cSend_oAoDigcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oYwheUxG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_i2qO7Lwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5dshUpVc, 0, m, &cPack_5dshUpVc_sendMessage);
}

void Heavy_SoundScraper::cBinop_j1X6C21J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_P4ZuLb68_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_wo5KE4Hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_OD7kXYJD, 0, m, &cPack_OD7kXYJD_sendMessage);
}

void Heavy_SoundScraper::cBinop_ynD61rHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zaAgfygM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_ZLSsrnkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dzBc4XHD, 0, m, &cPack_dzBc4XHD_sendMessage);
}

void Heavy_SoundScraper::cMsg_QukJSkEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_zaAgfygM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_hLoB92tm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AeIxU2zU, HV_BINOP_MULTIPLY, 1, m, &cBinop_AeIxU2zU_sendMessage);
}

void Heavy_SoundScraper::cMsg_HIb9u7DZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Q8seBuOo, 0, m, &cSlice_Q8seBuOo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kb8zdKXb, 0, m, &cSlice_kb8zdKXb_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Q8seBuOo, 0, m, &cSlice_Q8seBuOo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kb8zdKXb, 0, m, &cSlice_kb8zdKXb_sendMessage);
}

void Heavy_SoundScraper::cBinop_LDjQh2gv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5dshUpVc, 1, m, &cPack_5dshUpVc_sendMessage);
}

void Heavy_SoundScraper::cBinop_QfcPdPHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ee6eTebv, 1, m, &cPack_ee6eTebv_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ad4vEVSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_7iCymHbs, 0, m, &cSlice_7iCymHbs_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ezVM2Yf0, 0, m, &cSlice_ezVM2Yf0_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_7iCymHbs, 0, m, &cSlice_7iCymHbs_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ezVM2Yf0, 0, m, &cSlice_ezVM2Yf0_sendMessage);
}

void Heavy_SoundScraper::cSend_Peniclls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Xe9pixiI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_kfcBUUUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_5BQ9tk72_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_MT3h1Ajo, 0, m, &cIf_MT3h1Ajo_sendMessage);
}

void Heavy_SoundScraper::cCast_6cLroPFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5yN9BFkt, 1, m, &cDelay_5yN9BFkt_sendMessage);
}

void Heavy_SoundScraper::cCast_sdHZqB5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RBLiYKpB, 1, m, &cPack_RBLiYKpB_sendMessage);
}

void Heavy_SoundScraper::cCast_qno90EHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZLSsrnkU, HV_BINOP_ADD, 1, m, &cBinop_ZLSsrnkU_sendMessage);
}

void Heavy_SoundScraper::cCast_evcSL9wN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wo5KE4Hd, HV_BINOP_ADD, 1, m, &cBinop_wo5KE4Hd_sendMessage);
}

void Heavy_SoundScraper::cCast_5BQug06V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ynD61rHp, HV_BINOP_SUBTRACT, 1, m, &cBinop_ynD61rHp_sendMessage);
}

void Heavy_SoundScraper::cCast_O6YpXXiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ffh97vJ9, 1, m, &cDelay_ffh97vJ9_sendMessage);
}

void Heavy_SoundScraper::cCast_Tl8Aord8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oNCvUW49, 0, m, &cPack_oNCvUW49_sendMessage);
}

void Heavy_SoundScraper::cCast_ThsFChFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZduXLEAZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_zccu0PDI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZduXLEAZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_b6ZrtfNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zaAgfygM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_AeIxU2zU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qno90EHE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_evcSL9wN_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_K1iaYV8V_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7wx20wIF_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_APX1fTyL, 1, m, &cVar_APX1fTyL_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_7wx20wIF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4NQ64RDp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ou7eFNqy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7crroSzc_sendMessage);
      break;
    }
    default: {
      cSwitchcase_4kZibblo_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_b5hN6RWb, 1, m, &cVar_b5hN6RWb_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_7crroSzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PyRfHWfd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_CJvzDEls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_g6OogfSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_uh0Jdbrz_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_o61ig3S3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_AeIxU2zU, HV_BINOP_MULTIPLY, 0, m, &cBinop_AeIxU2zU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_EWIt3Ebo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_ou7eFNqy_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_j90nH2L4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_OAVJRPFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_K1iaYV8V_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_4NQ64RDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_APX1fTyL, 1, m, &cVar_APX1fTyL_sendMessage);
}

void Heavy_SoundScraper::cCast_L3eibe8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0E7V0khG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_PyRfHWfd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_4kZibblo_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_b5hN6RWb, 1, m, &cVar_b5hN6RWb_sendMessage);
}

void Heavy_SoundScraper::cMsg_0E7V0khG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_CJvzDEls, 0, m, &cSlice_CJvzDEls_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_g6OogfSM, 0, m, &cSlice_g6OogfSM_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_o61ig3S3, 0, m, &cSlice_o61ig3S3_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_EWIt3Ebo, 0, m, &cSlice_EWIt3Ebo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_j90nH2L4, 0, m, &cSlice_j90nH2L4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OAVJRPFT, 0, m, &cSlice_OAVJRPFT_sendMessage);
}

void Heavy_SoundScraper::cSlice_sksRBotf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PTCggSrs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_0jMafJuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zhAKVgRk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_zhAKVgRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9wmifags_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_9wmifags_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_21vtQCIl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_PTCggSrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lyxr824L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_lyxr824L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4FZHb02U_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_OXQgGONw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z1wcF0pw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_q1kMhDET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ftnyEqyz, HV_BINOP_MULTIPLY, 1, m, &cBinop_ftnyEqyz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QyEBsvgc, HV_BINOP_MULTIPLY, 1, m, &cBinop_QyEBsvgc_sendMessage);
}

void Heavy_SoundScraper::cSlice_TWdvCnmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ftnyEqyz, HV_BINOP_MULTIPLY, 0, m, &cBinop_ftnyEqyz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_EzlEwdTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QyEBsvgc, HV_BINOP_MULTIPLY, 0, m, &cBinop_QyEBsvgc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_z1wcF0pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_I9eg5G6F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_I9eg5G6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 220500000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cMsg_eILYuIK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TWdvCnmO, 0, m, &cSlice_TWdvCnmO_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_EzlEwdTV, 0, m, &cSlice_EzlEwdTV_sendMessage);
}

void Heavy_SoundScraper::cBinop_ftnyEqyz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_OXQgGONw, 1, m, &cPack_OXQgGONw_sendMessage);
}

void Heavy_SoundScraper::cBinop_QyEBsvgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_OXQgGONw, 0, m, &cPack_OXQgGONw_sendMessage);
}

void Heavy_SoundScraper::cSend_PDiVUFys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Qalldnu8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_FsXIxJJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_a9At1H2W_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_Wp2mYhT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_LEDLEoZ8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_RnNfO26i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XqfRWv36_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_bweaZCiS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_wbs4SlV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5v1pYC5d, 1, m, &cPack_5v1pYC5d_sendMessage);
}

void Heavy_SoundScraper::cVar_YbCCcJ3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5v1pYC5d, 0, m, &cPack_5v1pYC5d_sendMessage);
}

void Heavy_SoundScraper::cPack_5v1pYC5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g6DQy8HK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iIeTGtwX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L3eibe8y_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_CJvzDEls, 0, m, &cSlice_CJvzDEls_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_g6OogfSM, 0, m, &cSlice_g6OogfSM_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_o61ig3S3, 0, m, &cSlice_o61ig3S3_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_EWIt3Ebo, 0, m, &cSlice_EWIt3Ebo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_j90nH2L4, 0, m, &cSlice_j90nH2L4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OAVJRPFT, 0, m, &cSlice_OAVJRPFT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_20UtuLOq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KhSRRWoj_sendMessage);
  cMsg_FsXIxJJc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_x6ftRe2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5v1pYC5d, 2, m, &cPack_5v1pYC5d_sendMessage);
}

void Heavy_SoundScraper::cCast_7MFqPizE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YbCCcJ3M, 0, m, &cVar_YbCCcJ3M_sendMessage);
}

void Heavy_SoundScraper::cCast_NSOGs0OI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wbs4SlV4, 0, m, &cVar_wbs4SlV4_sendMessage);
}

void Heavy_SoundScraper::cBinop_ObIYIsIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_sS5UUuRJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_sS5UUuRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_DIqwQ4Zd_sendMessage);
}

void Heavy_SoundScraper::cBinop_LEDLEoZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_h3d3lu7l_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_MKrjwKu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x6ftRe2b_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NSOGs0OI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7MFqPizE_sendMessage);
}

void Heavy_SoundScraper::cBinop_cY6ksEWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_HJmc5gQI_sendMessage);
}

void Heavy_SoundScraper::cBinop_HJmc5gQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MKrjwKu4, HV_BINOP_MULTIPLY, 1, m, &cBinop_MKrjwKu4_sendMessage);
}

void Heavy_SoundScraper::cCast_XqfRWv36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oJyrCG9b_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_iIeTGtwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cxi0gF7x_sendMessage);
}

void Heavy_SoundScraper::cCast_g6DQy8HK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_gMRXVYsQ_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IPTJgUkf_sendMessage);
}

void Heavy_SoundScraper::cSend_9OGzdzb8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5IiWOkWl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_8k8Jf2DP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Zo69CGnL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_EUY59TKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MKrjwKu4, HV_BINOP_MULTIPLY, 0, m, &cBinop_MKrjwKu4_sendMessage);
}

void Heavy_SoundScraper::cSend_h3d3lu7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9y98ug7I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_oxir0jAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_PDiVUFys_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_s7YL3Zs6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_f4qbtQQN, 0, m, &cSlice_f4qbtQQN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ERKEF5Kk, 0, m, &cRandom_ERKEF5Kk_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_wZdRpaMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_unwgxgSr_sendMessage);
}

void Heavy_SoundScraper::cUnop_unwgxgSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_arL55pxl_sendMessage);
}

void Heavy_SoundScraper::cRandom_ERKEF5Kk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_wZdRpaMR_sendMessage);
}

void Heavy_SoundScraper::cSlice_f4qbtQQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ERKEF5Kk, 1, m, &cRandom_ERKEF5Kk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_0oNx14Pq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p8PcLyHi, HV_BINOP_DIVIDE, 0, m, &cBinop_p8PcLyHi_sendMessage);
}

void Heavy_SoundScraper::cBinop_3cSqGaLe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_heDTL6Pt_sendMessage);
}

void Heavy_SoundScraper::cBinop_heDTL6Pt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OOTg5wIx, HV_BINOP_POW, 1, m, &cBinop_OOTg5wIx_sendMessage);
  cMsg_GYIEoRvh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_OOTg5wIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_0oNx14Pq_sendMessage);
}

void Heavy_SoundScraper::cMsg_GYIEoRvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OOTg5wIx, HV_BINOP_POW, 0, m, &cBinop_OOTg5wIx_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_cobRrb8r_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pGSTU1Zs, 0, m, &cSlice_pGSTU1Zs_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RWD94MNW, 0, m, &cRandom_RWD94MNW_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_jX7BfqQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AVVT549X_sendMessage);
}

void Heavy_SoundScraper::cUnop_AVVT549X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DtTj55CZ_sendMessage);
}

void Heavy_SoundScraper::cRandom_RWD94MNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_jX7BfqQ7_sendMessage);
}

void Heavy_SoundScraper::cSlice_pGSTU1Zs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RWD94MNW, 1, m, &cRandom_RWD94MNW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_SvC5V0D8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_8reyXVl7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_d7PB4q7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_AomExZg4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_3owckGUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_32REBZvJ, 0, m, &cPack_32REBZvJ_sendMessage);
}

void Heavy_SoundScraper::cUnop_PTvNZ8v6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PDFXXZJI, 0, m, &cPack_PDFXXZJI_sendMessage);
}

void Heavy_SoundScraper::cPack_PDFXXZJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5mjgQ1RK, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_32REBZvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_X8UVgosI, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_27X9fPrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_3owckGUf_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_PTvNZ8v6_sendMessage);
}

void Heavy_SoundScraper::cMsg_7ySBhN73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_27X9fPrU_sendMessage);
}

void Heavy_SoundScraper::cCast_EdSCB9sa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_qhvrbskB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8SuchxnJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6HcLhNDR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CInzMzx6_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ksho7Rbt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ZWKRb1d9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ZWKRb1d9_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_AYzVobbb, 1, m, &cDelay_AYzVobbb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NfG0Kf97_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_AYzVobbb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AYzVobbb, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JLkvDOWY, 0, m, &cVar_JLkvDOWY_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZWKRb1d9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_AYzVobbb, 0, m, &cDelay_AYzVobbb_sendMessage);
}

void Heavy_SoundScraper::cCast_NfG0Kf97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AYzVobbb, 0, m, &cDelay_AYzVobbb_sendMessage);
}

void Heavy_SoundScraper::cVar_JLkvDOWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OEDRAE4V_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ERNg0j1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qhvrbskB, 0, m, &cVar_qhvrbskB_sendMessage);
}

void Heavy_SoundScraper::cSend_zNsXJXvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_u3RQPu2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_m2jgQR82_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_oiToXWze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_zNsXJXvs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_42SGq2as_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_u3RQPu2R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_0jZ9OY6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DKJzqtTf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ey8S0G9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_0jZ9OY6W_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_A45GyRJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_MZt94rAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_m2jgQR82_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_aPcU3KxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DKJzqtTf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_dPlpiyPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_BoLoW5DV, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_OEDRAE4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_BoLoW5DV, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_8SuchxnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dPlpiyPf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_6HcLhNDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JLkvDOWY, 1, m, &cVar_JLkvDOWY_sendMessage);
}

void Heavy_SoundScraper::cCast_CInzMzx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ksho7Rbt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_6FzoMgzo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LFxe68t4, 0, m, &cSlice_LFxe68t4_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_wp4dYXVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I5CAckPO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_AGm2KBZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_t9WKO8NL_sendMessage);
}

void Heavy_SoundScraper::cBinop_t9WKO8NL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QaEqDgic, m);
}

void Heavy_SoundScraper::cMsg_I5CAckPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AGm2KBZM_sendMessage);
}

void Heavy_SoundScraper::cSlice_LFxe68t4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_s9uAqArt, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_2xZgpS5z, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_wp4dYXVo, 0, m, &cVar_wp4dYXVo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_ZvJnxNl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BeD7LQxu, 0, m, &cPack_BeD7LQxu_sendMessage);
}

void Heavy_SoundScraper::cVar_rNz7A7wg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_aml3hSZH_sendMessage);
}

void Heavy_SoundScraper::cIf_ViucENg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_KOHvrZ3d_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_rNz7A7wg, 1, m, &cVar_rNz7A7wg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_qln7UH8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ViucENg3, 1, m, &cIf_ViucENg3_sendMessage);
}

void Heavy_SoundScraper::cVar_Xsi3TsU8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_fYXymKYK_sendMessage);
}

void Heavy_SoundScraper::cUnop_KOHvrZ3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xsi3TsU8, 1, m, &cVar_Xsi3TsU8_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_oDkQKv5V_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oU9vNIkz_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FNVisl9D_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_oU9vNIkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rNz7A7wg, 0, m, &cVar_rNz7A7wg_sendMessage);
}

void Heavy_SoundScraper::cCast_FNVisl9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xsi3TsU8, 0, m, &cVar_Xsi3TsU8_sendMessage);
}

void Heavy_SoundScraper::cVar_pnmxZ600_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_mSohEWaD_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ONXtzs1g_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_tRuAj4g9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_tRuAj4g9_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_WyYb5taZ, 1, m, &cDelay_WyYb5taZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tI7q6hDC_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_WyYb5taZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WyYb5taZ, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hi8eqRf2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TCuwfkn4_sendMessage);
}

void Heavy_SoundScraper::cMsg_tRuAj4g9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WyYb5taZ, 0, m, &cDelay_WyYb5taZ_sendMessage);
}

void Heavy_SoundScraper::cCast_tI7q6hDC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WyYb5taZ, 0, m, &cDelay_WyYb5taZ_sendMessage);
}

void Heavy_SoundScraper::cPack_b5ZsnmkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0RiytUzj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_A7JsFNdE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o1yggAi8_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_PBVQ9tiP, HV_BINOP_SUBTRACT, 0, m, &cBinop_PBVQ9tiP_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_o1yggAi8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_txg6erzY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_CP0oqqkj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_g9PcNFzn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_g9PcNFzn_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_8DNjMZRu, 1, m, &cDelay_8DNjMZRu_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TqRb7puX_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_8DNjMZRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8DNjMZRu, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0MO8RYR8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qq7NoO56_sendMessage);
}

void Heavy_SoundScraper::cMsg_g9PcNFzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8DNjMZRu, 0, m, &cDelay_8DNjMZRu_sendMessage);
}

void Heavy_SoundScraper::cCast_TqRb7puX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8DNjMZRu, 0, m, &cDelay_8DNjMZRu_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_nIQ3x9Ui_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_H0Wwf5xN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_H0Wwf5xN_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_CNeY4TLg, 1, m, &cDelay_CNeY4TLg_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oYvGUoWi_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_CNeY4TLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CNeY4TLg, m);
}

void Heavy_SoundScraper::cMsg_H0Wwf5xN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CNeY4TLg, 0, m, &cDelay_CNeY4TLg_sendMessage);
}

void Heavy_SoundScraper::cCast_oYvGUoWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CNeY4TLg, 0, m, &cDelay_CNeY4TLg_sendMessage);
}

void Heavy_SoundScraper::cPack_AxeXEpqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0jnOgNdl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_LkrizacB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JKSqOoc5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_T0oOdRGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LwUgCNnz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_zHFw0NDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cuEh7pOa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_HpbbdZWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZqVwL75y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_hziYS8I6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EKm6bOhP, HV_BINOP_DIVIDE, 1, m, &cBinop_EKm6bOhP_sendMessage);
}

void Heavy_SoundScraper::cVar_te3YvAnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EKm6bOhP, HV_BINOP_DIVIDE, 0, m, &cBinop_EKm6bOhP_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_pJvC0UxO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oQOmSGGK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xsWiofD1_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2eY4iLQh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_synCzZkZ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_oQOmSGGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hziYS8I6, 0, m, &cVar_hziYS8I6_sendMessage);
}

void Heavy_SoundScraper::cCast_xsWiofD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_te3YvAnU, 0, m, &cVar_te3YvAnU_sendMessage);
}

void Heavy_SoundScraper::cCast_synCzZkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_te3YvAnU, 0, m, &cVar_te3YvAnU_sendMessage);
}

void Heavy_SoundScraper::cCast_2eY4iLQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hziYS8I6, 0, m, &cVar_hziYS8I6_sendMessage);
}

void Heavy_SoundScraper::cPack_BeD7LQxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1Jqs3zHt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_9n1mUQuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_b5ZsnmkP, 1, m, &cPack_b5ZsnmkP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ix3nr9fH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QYkKjzvO, HV_BINOP_ADD, 0, m, &cBinop_QYkKjzvO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_MA9nUJ9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_AxeXEpqS, 1, m, &cPack_AxeXEpqS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_WqRO7KF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yb4a3e6G, HV_BINOP_ADD, 0, m, &cBinop_yb4a3e6G_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_TCuwfkn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZvJnxNl8, 0, m, &cVar_ZvJnxNl8_sendMessage);
}

void Heavy_SoundScraper::cCast_Hi8eqRf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pnmxZ600, 0, m, &cVar_pnmxZ600_sendMessage);
}

void Heavy_SoundScraper::cSend_0RiytUzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LE0SR3xP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1Jqs3zHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gMNpcyJT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cuEh7pOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gMNpcyJT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Y96MxvM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ONXtzs1g_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_UMsf9Pjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zHFw0NDn, 0, m, &cPack_zHFw0NDn_sendMessage);
}

void Heavy_SoundScraper::cBinop_aml3hSZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_T0oOdRGo, 0, m, &cPack_T0oOdRGo_sendMessage);
}

void Heavy_SoundScraper::cSend_0jnOgNdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LE0SR3xP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_fYXymKYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LkrizacB, 0, m, &cPack_LkrizacB_sendMessage);
}

void Heavy_SoundScraper::cBinop_mSohEWaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oDkQKv5V_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_QYkKjzvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_b5ZsnmkP, 0, m, &cPack_b5ZsnmkP_sendMessage);
}

void Heavy_SoundScraper::cBinop_PBVQ9tiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CP0oqqkj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_yb4a3e6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AxeXEpqS, 0, m, &cPack_AxeXEpqS_sendMessage);
}

void Heavy_SoundScraper::cMsg_txg6erzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_CP0oqqkj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_69B3269U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ce4cstnk, HV_BINOP_MULTIPLY, 1, m, &cBinop_ce4cstnk_sendMessage);
}

void Heavy_SoundScraper::cMsg_JKSqOoc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_MA9nUJ9u, 0, m, &cSlice_MA9nUJ9u_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_WqRO7KF5, 0, m, &cSlice_WqRO7KF5_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_MA9nUJ9u, 0, m, &cSlice_MA9nUJ9u_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_WqRO7KF5, 0, m, &cSlice_WqRO7KF5_sendMessage);
}

void Heavy_SoundScraper::cBinop_U8bqcv6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LkrizacB, 1, m, &cPack_LkrizacB_sendMessage);
}

void Heavy_SoundScraper::cBinop_hRxid4Yp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_T0oOdRGo, 1, m, &cPack_T0oOdRGo_sendMessage);
}

void Heavy_SoundScraper::cMsg_LwUgCNnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9n1mUQuT, 0, m, &cSlice_9n1mUQuT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ix3nr9fH, 0, m, &cSlice_ix3nr9fH_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9n1mUQuT, 0, m, &cSlice_9n1mUQuT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ix3nr9fH, 0, m, &cSlice_ix3nr9fH_sendMessage);
}

void Heavy_SoundScraper::cSend_ZqVwL75y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gMNpcyJT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_EKm6bOhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_qln7UH8P_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ViucENg3, 0, m, &cIf_ViucENg3_sendMessage);
}

void Heavy_SoundScraper::cCast_0Z3C4iQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zHFw0NDn, 1, m, &cPack_zHFw0NDn_sendMessage);
}

void Heavy_SoundScraper::cCast_iwLMuLd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WyYb5taZ, 1, m, &cDelay_WyYb5taZ_sendMessage);
}

void Heavy_SoundScraper::cCast_iuRg7D2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QYkKjzvO, HV_BINOP_ADD, 1, m, &cBinop_QYkKjzvO_sendMessage);
}

void Heavy_SoundScraper::cCast_L6I15Orv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yb4a3e6G, HV_BINOP_ADD, 1, m, &cBinop_yb4a3e6G_sendMessage);
}

void Heavy_SoundScraper::cCast_EdrvSEC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PBVQ9tiP, HV_BINOP_SUBTRACT, 1, m, &cBinop_PBVQ9tiP_sendMessage);
}

void Heavy_SoundScraper::cCast_AOhQGrtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CNeY4TLg, 1, m, &cDelay_CNeY4TLg_sendMessage);
}

void Heavy_SoundScraper::cCast_0MO8RYR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nIQ3x9Ui_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_qq7NoO56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HpbbdZWo, 0, m, &cPack_HpbbdZWo_sendMessage);
}

void Heavy_SoundScraper::cCast_lJp25WhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CP0oqqkj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_zLlo8yaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nIQ3x9Ui_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_ce4cstnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_L6I15Orv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iuRg7D2b_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_cnnAZ72w_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EdFurBet_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_ZvJnxNl8, 1, m, &cVar_ZvJnxNl8_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_EdFurBet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t3prMwuk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_SF233dKu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y0GdQciP_sendMessage);
      break;
    }
    default: {
      cSwitchcase_pJvC0UxO_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_pnmxZ600, 1, m, &cVar_pnmxZ600_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Y0GdQciP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4hIQL63Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_YMsz2j2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_1Gjqvn7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_A7JsFNdE_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_R0mFhUmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ce4cstnk, HV_BINOP_MULTIPLY, 0, m, &cBinop_ce4cstnk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_JrJjCzUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_SF233dKu_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_pOW8tE6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_L06NL0DW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_cnnAZ72w_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_t3prMwuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ZvJnxNl8, 1, m, &cVar_ZvJnxNl8_sendMessage);
}

void Heavy_SoundScraper::cCast_XieQbRTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tJGGwaV5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_4hIQL63Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_pJvC0UxO_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_pnmxZ600, 1, m, &cVar_pnmxZ600_sendMessage);
}

void Heavy_SoundScraper::cMsg_tJGGwaV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YMsz2j2j, 0, m, &cSlice_YMsz2j2j_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1Gjqvn7G, 0, m, &cSlice_1Gjqvn7G_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_R0mFhUmq, 0, m, &cSlice_R0mFhUmq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JrJjCzUw, 0, m, &cSlice_JrJjCzUw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_pOW8tE6N, 0, m, &cSlice_pOW8tE6N_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_L06NL0DW, 0, m, &cSlice_L06NL0DW_sendMessage);
}

void Heavy_SoundScraper::cSlice_goapZnXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Al8qhWL3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_mE3B3W7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_k0Pv5Jrn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_k0Pv5Jrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RHEr3wUR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_RHEr3wUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ClX0blva_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Al8qhWL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4dL3TW1O_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_4dL3TW1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_X49M1KNH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_1dFy8lgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fzgggftq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_FteLT3q0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w9lwr62S, HV_BINOP_MULTIPLY, 1, m, &cBinop_w9lwr62S_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pmtVXjcT, HV_BINOP_MULTIPLY, 1, m, &cBinop_pmtVXjcT_sendMessage);
}

void Heavy_SoundScraper::cSlice_zjhEL7va_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_w9lwr62S, HV_BINOP_MULTIPLY, 0, m, &cBinop_w9lwr62S_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Lmka0sE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pmtVXjcT, HV_BINOP_MULTIPLY, 0, m, &cBinop_pmtVXjcT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_fzgggftq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_JyRqgcbK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_JyRqgcbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 220500000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cMsg_wC36uR6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_zjhEL7va, 0, m, &cSlice_zjhEL7va_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Lmka0sE3, 0, m, &cSlice_Lmka0sE3_sendMessage);
}

void Heavy_SoundScraper::cBinop_w9lwr62S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1dFy8lgA, 1, m, &cPack_1dFy8lgA_sendMessage);
}

void Heavy_SoundScraper::cBinop_pmtVXjcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1dFy8lgA, 0, m, &cPack_1dFy8lgA_sendMessage);
}

void Heavy_SoundScraper::cSend_HSAozvES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5V0y2WGt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_YbA6DpTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_6FzoMgzo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_GUMAxy6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_wlRvCXIn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_1fKaZV7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4osgVLiT_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_3cSqGaLe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_EcFkdkbq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SXe6wWcW, 1, m, &cPack_SXe6wWcW_sendMessage);
}

void Heavy_SoundScraper::cVar_q31aMoHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SXe6wWcW, 0, m, &cPack_SXe6wWcW_sendMessage);
}

void Heavy_SoundScraper::cPack_SXe6wWcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Bm1pRDQy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LTRYjrsz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XieQbRTS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YMsz2j2j, 0, m, &cSlice_YMsz2j2j_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1Gjqvn7G, 0, m, &cSlice_1Gjqvn7G_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_R0mFhUmq, 0, m, &cSlice_R0mFhUmq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JrJjCzUw, 0, m, &cSlice_JrJjCzUw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_pOW8tE6N, 0, m, &cSlice_pOW8tE6N_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_L06NL0DW, 0, m, &cSlice_L06NL0DW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UMsf9Pjk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y96MxvM9_sendMessage);
  cMsg_YbA6DpTs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_wWVNywDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_q31aMoHN, 0, m, &cVar_q31aMoHN_sendMessage);
}

void Heavy_SoundScraper::cCast_5KEqwY9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EcFkdkbq, 0, m, &cVar_EcFkdkbq_sendMessage);
}

void Heavy_SoundScraper::cCast_0Hz1MRal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SXe6wWcW, 2, m, &cPack_SXe6wWcW_sendMessage);
}

void Heavy_SoundScraper::cBinop_arL55pxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_ngOIaTCx_sendMessage);
}

void Heavy_SoundScraper::cBinop_ngOIaTCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_27X9fPrU_sendMessage);
}

void Heavy_SoundScraper::cBinop_wlRvCXIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FPCvdv1E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_RMs4CMz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0Hz1MRal_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5KEqwY9O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wWVNywDY_sendMessage);
}

void Heavy_SoundScraper::cBinop_DtTj55CZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_s6AyQluM_sendMessage);
}

void Heavy_SoundScraper::cBinop_s6AyQluM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RMs4CMz5, HV_BINOP_MULTIPLY, 1, m, &cBinop_RMs4CMz5_sendMessage);
}

void Heavy_SoundScraper::cCast_4osgVLiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cobRrb8r_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_LTRYjrsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ERNg0j1s_sendMessage);
}

void Heavy_SoundScraper::cCast_Bm1pRDQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_s7YL3Zs6_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EdSCB9sa_sendMessage);
}

void Heavy_SoundScraper::cSend_AomExZg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_M4CEsncm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_8reyXVl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9ZRw3tV0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_p8PcLyHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RMs4CMz5, HV_BINOP_MULTIPLY, 0, m, &cBinop_RMs4CMz5_sendMessage);
}

void Heavy_SoundScraper::cSend_FPCvdv1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pFe3BP7R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_jcrUjBJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_HSAozvES_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_DQdsO5qe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4LWqfyQW, 0, m, &cSlice_4LWqfyQW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QoxF3UTh, 0, m, &cRandom_QoxF3UTh_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_TjbUxOGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ffdyAAcT_sendMessage);
}

void Heavy_SoundScraper::cUnop_ffdyAAcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_o0B2OUFm_sendMessage);
}

void Heavy_SoundScraper::cRandom_QoxF3UTh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_TjbUxOGJ_sendMessage);
}

void Heavy_SoundScraper::cSlice_4LWqfyQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QoxF3UTh, 1, m, &cRandom_QoxF3UTh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_uNe48nQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tnpzxqEn, HV_BINOP_DIVIDE, 0, m, &cBinop_tnpzxqEn_sendMessage);
}

void Heavy_SoundScraper::cBinop_kKXyweQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_8Sbzc3GL_sendMessage);
}

void Heavy_SoundScraper::cBinop_8Sbzc3GL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CKHIIFyO, HV_BINOP_POW, 1, m, &cBinop_CKHIIFyO_sendMessage);
  cMsg_05PhBZi7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_CKHIIFyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_uNe48nQh_sendMessage);
}

void Heavy_SoundScraper::cMsg_05PhBZi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CKHIIFyO, HV_BINOP_POW, 0, m, &cBinop_CKHIIFyO_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_uj0SZwU2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_aPGcb6h0, 0, m, &cSlice_aPGcb6h0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KUykdbb5, 0, m, &cRandom_KUykdbb5_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_0qsxf6r2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vFh3DFhc_sendMessage);
}

void Heavy_SoundScraper::cUnop_vFh3DFhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bywNS4iB_sendMessage);
}

void Heavy_SoundScraper::cRandom_KUykdbb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_0qsxf6r2_sendMessage);
}

void Heavy_SoundScraper::cSlice_aPGcb6h0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KUykdbb5, 1, m, &cRandom_KUykdbb5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_T1hjmdea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_Bw9UzCB3_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_f7rHpMFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_GuLLnOlK_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_7Jytxh3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_znLPaQwS, 0, m, &cPack_znLPaQwS_sendMessage);
}

void Heavy_SoundScraper::cUnop_5DUh8sPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_T0TsyQXy, 0, m, &cPack_T0TsyQXy_sendMessage);
}

void Heavy_SoundScraper::cPack_T0TsyQXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_kF24xNgR, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_znLPaQwS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wLKjYKtF, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_uNJ49qrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_7Jytxh3I_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_5DUh8sPv_sendMessage);
}

void Heavy_SoundScraper::cMsg_5K4FM6ku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_uNJ49qrX_sendMessage);
}

void Heavy_SoundScraper::cCast_4Fem31Mf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_T4l79h2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rLyrSPrZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H3l9JGq1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bX0gwCGd_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_y5vKIxC2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_y4POlCc0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_y4POlCc0_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_7qe9iIzF, 1, m, &cDelay_7qe9iIzF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aRrm6Ron_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_7qe9iIzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7qe9iIzF, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pIuALVAb, 0, m, &cVar_pIuALVAb_sendMessage);
}

void Heavy_SoundScraper::cMsg_y4POlCc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7qe9iIzF, 0, m, &cDelay_7qe9iIzF_sendMessage);
}

void Heavy_SoundScraper::cCast_aRrm6Ron_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7qe9iIzF, 0, m, &cDelay_7qe9iIzF_sendMessage);
}

void Heavy_SoundScraper::cVar_pIuALVAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ea6JikWD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_yiVLgr6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T4l79h2i, 0, m, &cVar_T4l79h2i_sendMessage);
}

void Heavy_SoundScraper::cSend_xAgBecAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_dRrQnZ9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ghMsBmYI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_hc15PLuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_xAgBecAL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Fd2pzQW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_dRrQnZ9h_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_lqBAcWTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JpjRX77H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_AdXtM0qn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_lqBAcWTe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_XUxItUxP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_g6tCwkZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ghMsBmYI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_pfuPB6j6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JpjRX77H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_CIilcuUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_SUMTp9A5, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_ea6JikWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_SUMTp9A5, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_H3l9JGq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pIuALVAb, 1, m, &cVar_pIuALVAb_sendMessage);
}

void Heavy_SoundScraper::cCast_bX0gwCGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_y5vKIxC2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_rLyrSPrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CIilcuUo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_2BJQxVUg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GtXhuqMl, 0, m, &cSlice_GtXhuqMl_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_unWpXSBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KXegbrSN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_sAuLIDal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_X0GkNl4S_sendMessage);
}

void Heavy_SoundScraper::cBinop_X0GkNl4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p1s4kfxI, m);
}

void Heavy_SoundScraper::cMsg_KXegbrSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sAuLIDal_sendMessage);
}

void Heavy_SoundScraper::cSlice_GtXhuqMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_yWgAUCjh, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_n1CZftWo, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_unWpXSBQ, 0, m, &cVar_unWpXSBQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_54hIyrZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3TLR4kXG, 0, m, &cPack_3TLR4kXG_sendMessage);
}

void Heavy_SoundScraper::cVar_tmqqMjIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_XNJ0kkwA_sendMessage);
}

void Heavy_SoundScraper::cIf_5qQgWBVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_DFjLCrrb_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_tmqqMjIj, 1, m, &cVar_tmqqMjIj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Bt2ZMEdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5qQgWBVr, 1, m, &cIf_5qQgWBVr_sendMessage);
}

void Heavy_SoundScraper::cVar_BVf4r6uW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_YvI0Tus5_sendMessage);
}

void Heavy_SoundScraper::cUnop_DFjLCrrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BVf4r6uW, 1, m, &cVar_BVf4r6uW_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_mNT8cT3Y_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8deklBkj_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DAJVF2c2_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_8deklBkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tmqqMjIj, 0, m, &cVar_tmqqMjIj_sendMessage);
}

void Heavy_SoundScraper::cCast_DAJVF2c2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BVf4r6uW, 0, m, &cVar_BVf4r6uW_sendMessage);
}

void Heavy_SoundScraper::cVar_5EwjpZRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_1USOZJ1w_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_mvF4SncT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ygyg15dh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ygyg15dh_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Vj5dk1vY, 1, m, &cDelay_Vj5dk1vY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bFPSqGj0_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_Vj5dk1vY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Vj5dk1vY, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B8Kev9en_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xmAQ3Iyw_sendMessage);
}

void Heavy_SoundScraper::cMsg_ygyg15dh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Vj5dk1vY, 0, m, &cDelay_Vj5dk1vY_sendMessage);
}

void Heavy_SoundScraper::cCast_bFPSqGj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Vj5dk1vY, 0, m, &cDelay_Vj5dk1vY_sendMessage);
}

void Heavy_SoundScraper::cPack_CLp5Ywbg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BYRX3A5P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_7eUXRKSD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SnJJmreJ_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Dn5MYU4m, HV_BINOP_SUBTRACT, 0, m, &cBinop_Dn5MYU4m_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_SnJJmreJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pAU9ZHhC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_TvFkCxyZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_KyR52mPC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_KyR52mPC_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_kox6MMYT, 1, m, &cDelay_kox6MMYT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WJ0dKRwh_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_kox6MMYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kox6MMYT, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IvOVDVyS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cWQVfWIR_sendMessage);
}

void Heavy_SoundScraper::cMsg_KyR52mPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kox6MMYT, 0, m, &cDelay_kox6MMYT_sendMessage);
}

void Heavy_SoundScraper::cCast_WJ0dKRwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kox6MMYT, 0, m, &cDelay_kox6MMYT_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_sTfRLYBj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_he3yHaLw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_he3yHaLw_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_iFcRVfYd, 1, m, &cDelay_iFcRVfYd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eYue38Cz_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_iFcRVfYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iFcRVfYd, m);
}

void Heavy_SoundScraper::cMsg_he3yHaLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iFcRVfYd, 0, m, &cDelay_iFcRVfYd_sendMessage);
}

void Heavy_SoundScraper::cCast_eYue38Cz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iFcRVfYd, 0, m, &cDelay_iFcRVfYd_sendMessage);
}

void Heavy_SoundScraper::cPack_tRUylDK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Wrqd3g0S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_HDwbrxhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2Q8zAn5P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_dH0jUzML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hUgYeDOi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_L71iTcIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fdCjC9MV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_wAn4lH4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ccPCWlyX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_eJFFl7Nh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u2oIDdME, HV_BINOP_DIVIDE, 1, m, &cBinop_u2oIDdME_sendMessage);
}

void Heavy_SoundScraper::cVar_A0Gd4KF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u2oIDdME, HV_BINOP_DIVIDE, 0, m, &cBinop_u2oIDdME_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Tt46X6Vq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O0iVwM7u_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0G3wuZN2_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HlCtuPj9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N2jMSHeE_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_0G3wuZN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A0Gd4KF8, 0, m, &cVar_A0Gd4KF8_sendMessage);
}

void Heavy_SoundScraper::cCast_O0iVwM7u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eJFFl7Nh, 0, m, &cVar_eJFFl7Nh_sendMessage);
}

void Heavy_SoundScraper::cCast_N2jMSHeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A0Gd4KF8, 0, m, &cVar_A0Gd4KF8_sendMessage);
}

void Heavy_SoundScraper::cCast_HlCtuPj9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eJFFl7Nh, 0, m, &cVar_eJFFl7Nh_sendMessage);
}

void Heavy_SoundScraper::cPack_3TLR4kXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_j3kWKJm0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_JgHu2BMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_CLp5Ywbg, 1, m, &cPack_CLp5Ywbg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_XkN1avUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aWQ0kysT, HV_BINOP_ADD, 0, m, &cBinop_aWQ0kysT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Fgddjiyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_tRUylDK6, 1, m, &cPack_tRUylDK6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_onuiAlXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4jYl8gHV, HV_BINOP_ADD, 0, m, &cBinop_4jYl8gHV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_B8Kev9en_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5EwjpZRZ, 0, m, &cVar_5EwjpZRZ_sendMessage);
}

void Heavy_SoundScraper::cCast_xmAQ3Iyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_54hIyrZW, 0, m, &cVar_54hIyrZW_sendMessage);
}

void Heavy_SoundScraper::cSend_BYRX3A5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fuex8P7L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_j3kWKJm0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_b2SLxpSD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_fdCjC9MV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_b2SLxpSD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ppl6bnEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mvF4SncT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_v4rv5Q6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_L71iTcIe, 0, m, &cPack_L71iTcIe_sendMessage);
}

void Heavy_SoundScraper::cBinop_XNJ0kkwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dH0jUzML, 0, m, &cPack_dH0jUzML_sendMessage);
}

void Heavy_SoundScraper::cSend_Wrqd3g0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fuex8P7L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_YvI0Tus5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HDwbrxhj, 0, m, &cPack_HDwbrxhj_sendMessage);
}

void Heavy_SoundScraper::cBinop_1USOZJ1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mNT8cT3Y_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_aWQ0kysT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CLp5Ywbg, 0, m, &cPack_CLp5Ywbg_sendMessage);
}

void Heavy_SoundScraper::cBinop_Dn5MYU4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TvFkCxyZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_4jYl8gHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tRUylDK6, 0, m, &cPack_tRUylDK6_sendMessage);
}

void Heavy_SoundScraper::cMsg_pAU9ZHhC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_TvFkCxyZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_8OgwBFjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ibL1XD3A, HV_BINOP_MULTIPLY, 1, m, &cBinop_ibL1XD3A_sendMessage);
}

void Heavy_SoundScraper::cMsg_2Q8zAn5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Fgddjiyw, 0, m, &cSlice_Fgddjiyw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_onuiAlXM, 0, m, &cSlice_onuiAlXM_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Fgddjiyw, 0, m, &cSlice_Fgddjiyw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_onuiAlXM, 0, m, &cSlice_onuiAlXM_sendMessage);
}

void Heavy_SoundScraper::cBinop_f9zC1jXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HDwbrxhj, 1, m, &cPack_HDwbrxhj_sendMessage);
}

void Heavy_SoundScraper::cBinop_Kbe8v9NF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dH0jUzML, 1, m, &cPack_dH0jUzML_sendMessage);
}

void Heavy_SoundScraper::cMsg_hUgYeDOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JgHu2BMp, 0, m, &cSlice_JgHu2BMp_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_XkN1avUg, 0, m, &cSlice_XkN1avUg_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JgHu2BMp, 0, m, &cSlice_JgHu2BMp_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_XkN1avUg, 0, m, &cSlice_XkN1avUg_sendMessage);
}

void Heavy_SoundScraper::cSend_ccPCWlyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_b2SLxpSD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_u2oIDdME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_Bt2ZMEdV_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_5qQgWBVr, 0, m, &cIf_5qQgWBVr_sendMessage);
}

void Heavy_SoundScraper::cCast_VarqTGHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Vj5dk1vY, 1, m, &cDelay_Vj5dk1vY_sendMessage);
}

void Heavy_SoundScraper::cCast_nJ9qQbAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_L71iTcIe, 1, m, &cPack_L71iTcIe_sendMessage);
}

void Heavy_SoundScraper::cCast_xB6HOkPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4jYl8gHV, HV_BINOP_ADD, 1, m, &cBinop_4jYl8gHV_sendMessage);
}

void Heavy_SoundScraper::cCast_LrnfVYo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aWQ0kysT, HV_BINOP_ADD, 1, m, &cBinop_aWQ0kysT_sendMessage);
}

void Heavy_SoundScraper::cCast_Yi4qwbXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dn5MYU4m, HV_BINOP_SUBTRACT, 1, m, &cBinop_Dn5MYU4m_sendMessage);
}

void Heavy_SoundScraper::cCast_Kona9MyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iFcRVfYd, 1, m, &cDelay_iFcRVfYd_sendMessage);
}

void Heavy_SoundScraper::cCast_cWQVfWIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wAn4lH4T, 0, m, &cPack_wAn4lH4T_sendMessage);
}

void Heavy_SoundScraper::cCast_IvOVDVyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sTfRLYBj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_0yrZ117R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sTfRLYBj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_U7W3Nrre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TvFkCxyZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_ibL1XD3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xB6HOkPa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LrnfVYo9_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_MsUgMmrY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HWRM7hI1_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_54hIyrZW, 1, m, &cVar_54hIyrZW_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_HWRM7hI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YY5wxhZM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_6aNc2ihF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sxolaq1H_sendMessage);
      break;
    }
    default: {
      cSwitchcase_Tt46X6Vq_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_5EwjpZRZ, 1, m, &cVar_5EwjpZRZ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_sxolaq1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8XV4hTNI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_7yHvYkuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_OQhQBMo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_7eUXRKSD_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_eETJquNT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ibL1XD3A, HV_BINOP_MULTIPLY, 0, m, &cBinop_ibL1XD3A_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_XxY6Bq4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_6aNc2ihF_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_cQScPy7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_XhcgkbSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_MsUgMmrY_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_YY5wxhZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_54hIyrZW, 1, m, &cVar_54hIyrZW_sendMessage);
}

void Heavy_SoundScraper::cCast_bPvairtB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LllakDTV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_8XV4hTNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Tt46X6Vq_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_5EwjpZRZ, 1, m, &cVar_5EwjpZRZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_LllakDTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_7yHvYkuz, 0, m, &cSlice_7yHvYkuz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OQhQBMo9, 0, m, &cSlice_OQhQBMo9_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_eETJquNT, 0, m, &cSlice_eETJquNT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_XxY6Bq4K, 0, m, &cSlice_XxY6Bq4K_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_cQScPy7Y, 0, m, &cSlice_cQScPy7Y_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_XhcgkbSb, 0, m, &cSlice_XhcgkbSb_sendMessage);
}

void Heavy_SoundScraper::cSlice_0vxLnYsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Go5iJPBV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_hd5wP8RL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iRNpZxGi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_iRNpZxGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_d6cLN5An_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_d6cLN5An_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QoEnniYB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Go5iJPBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_EjJB0rpX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_EjJB0rpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WBb0F73r_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_QOHp7e6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hicyjOKG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_x3wUdY5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O7k5BnZK, HV_BINOP_MULTIPLY, 1, m, &cBinop_O7k5BnZK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ziNm3Og8, HV_BINOP_MULTIPLY, 1, m, &cBinop_ziNm3Og8_sendMessage);
}

void Heavy_SoundScraper::cSlice_NK7sq6y2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_O7k5BnZK, HV_BINOP_MULTIPLY, 0, m, &cBinop_O7k5BnZK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_MfxY7e0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ziNm3Og8, HV_BINOP_MULTIPLY, 0, m, &cBinop_ziNm3Og8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_hicyjOKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_KhnUcanc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KhnUcanc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 220500000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cMsg_eyM54fyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NK7sq6y2, 0, m, &cSlice_NK7sq6y2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_MfxY7e0e, 0, m, &cSlice_MfxY7e0e_sendMessage);
}

void Heavy_SoundScraper::cBinop_O7k5BnZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QOHp7e6h, 1, m, &cPack_QOHp7e6h_sendMessage);
}

void Heavy_SoundScraper::cBinop_ziNm3Og8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QOHp7e6h, 0, m, &cPack_QOHp7e6h_sendMessage);
}

void Heavy_SoundScraper::cSend_8hunmMcu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YnZwHEnA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_CUXZgjLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_2BJQxVUg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_2JuYc5c4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_5foXvHvT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_44YthkPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m7PWnjx0_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_kKXyweQ1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_YbJWKSa6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AJnWyUYE, 1, m, &cPack_AJnWyUYE_sendMessage);
}

void Heavy_SoundScraper::cVar_9LE4kzgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AJnWyUYE, 0, m, &cPack_AJnWyUYE_sendMessage);
}

void Heavy_SoundScraper::cPack_AJnWyUYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kGoLTDvM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xxFBtlk2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bPvairtB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_7yHvYkuz, 0, m, &cSlice_7yHvYkuz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OQhQBMo9, 0, m, &cSlice_OQhQBMo9_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_eETJquNT, 0, m, &cSlice_eETJquNT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_XxY6Bq4K, 0, m, &cSlice_XxY6Bq4K_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_cQScPy7Y, 0, m, &cSlice_cQScPy7Y_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_XhcgkbSb, 0, m, &cSlice_XhcgkbSb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v4rv5Q6z_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ppl6bnEO_sendMessage);
  cMsg_CUXZgjLh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_cn1Aj75X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YbJWKSa6, 0, m, &cVar_YbJWKSa6_sendMessage);
}

void Heavy_SoundScraper::cCast_kA3tZkGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AJnWyUYE, 2, m, &cPack_AJnWyUYE_sendMessage);
}

void Heavy_SoundScraper::cCast_5JQWln8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9LE4kzgN, 0, m, &cVar_9LE4kzgN_sendMessage);
}

void Heavy_SoundScraper::cBinop_o0B2OUFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_KcekN2Rg_sendMessage);
}

void Heavy_SoundScraper::cBinop_KcekN2Rg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_uNJ49qrX_sendMessage);
}

void Heavy_SoundScraper::cBinop_5foXvHvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_oSf2Svni_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_4PxdUQBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kA3tZkGE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cn1Aj75X_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5JQWln8s_sendMessage);
}

void Heavy_SoundScraper::cBinop_bywNS4iB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_f0i3Xzt4_sendMessage);
}

void Heavy_SoundScraper::cBinop_f0i3Xzt4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4PxdUQBf, HV_BINOP_MULTIPLY, 1, m, &cBinop_4PxdUQBf_sendMessage);
}

void Heavy_SoundScraper::cCast_m7PWnjx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uj0SZwU2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_xxFBtlk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yiVLgr6D_sendMessage);
}

void Heavy_SoundScraper::cCast_kGoLTDvM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DQdsO5qe_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4Fem31Mf_sendMessage);
}

void Heavy_SoundScraper::cSend_GuLLnOlK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_F4Eq9OEU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Bw9UzCB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_exWYHmPx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_tnpzxqEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4PxdUQBf, HV_BINOP_MULTIPLY, 0, m, &cBinop_4PxdUQBf_sendMessage);
}

void Heavy_SoundScraper::cSend_oSf2Svni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ba8caV8s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_USZ267fk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_8hunmMcu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_jK7Kofun_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6qhcJWga, 0, m, &cSlice_6qhcJWga_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_oEr2k5HS, 0, m, &cRandom_oEr2k5HS_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_X2KTWjNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PkDvdif4_sendMessage);
}

void Heavy_SoundScraper::cUnop_PkDvdif4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Aht5biQT_sendMessage);
}

void Heavy_SoundScraper::cRandom_oEr2k5HS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_X2KTWjNQ_sendMessage);
}

void Heavy_SoundScraper::cSlice_6qhcJWga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_oEr2k5HS, 1, m, &cRandom_oEr2k5HS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_nruLcyEc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I6nWvmdB_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qe0JevRV_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7gEddEU6_sendMessage);
      break;
    }
    case 0x40A00000: { // "5.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xo8rYbW1_sendMessage);
      break;
    }
    case 0x40C00000: { // "6.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G4h4aLgH_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_I6nWvmdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zZdTqPlc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Qe0JevRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K7m4bI6N_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_7gEddEU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cQ2kVYKH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_xo8rYbW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9h7KIKwb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_G4h4aLgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Urj5XPAL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Rd0SjDRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dZGhNSjP_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JHQKbt87_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cDOvdyhd_sendMessage);
}

void Heavy_SoundScraper::cIf_qVdgm8t1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_b4gWwOVf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_PD0BTq3i_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_2gAyCBoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uyM3byzB, HV_BINOP_POW, 0, m, &cBinop_uyM3byzB_sendMessage);
}

void Heavy_SoundScraper::cBinop_uyM3byzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ID1mQx0C, 0, m, &cPack_ID1mQx0C_sendMessage);
}

void Heavy_SoundScraper::cBinop_OljLoQhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_sTPCeuqY_sendMessage);
}

void Heavy_SoundScraper::cCast_JHQKbt87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_OcuLAKJ4_sendMessage);
}

void Heavy_SoundScraper::cCast_cDOvdyhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qVdgm8t1, 0, m, &cIf_qVdgm8t1_sendMessage);
}

void Heavy_SoundScraper::cBinop_OcuLAKJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qVdgm8t1, 1, m, &cIf_qVdgm8t1_sendMessage);
}

void Heavy_SoundScraper::cBinop_PD0BTq3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_OljLoQhh_sendMessage);
}

void Heavy_SoundScraper::cMsg_b4gWwOVf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_ID1mQx0C, 0, m, &cPack_ID1mQx0C_sendMessage);
}

void Heavy_SoundScraper::cBinop_sTPCeuqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uyM3byzB, HV_BINOP_POW, 1, m, &cBinop_uyM3byzB_sendMessage);
  cMsg_2gAyCBoq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_ID1mQx0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_iMAvKVIb, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_4wygmsSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ugOakL0g_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_dZGhNSjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_TAiU7zoM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_TAiU7zoM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Yknh3RpC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ugOakL0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mE5z5KCh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_sggg9JiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OHkei9ds_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MPIGVI0V_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nCAKO1ih_sendMessage);
}

void Heavy_SoundScraper::cIf_RZ22kD3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_s5bLWhF0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_bIKEdVmn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_sTpDWbAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lMv4zNZS, HV_BINOP_POW, 0, m, &cBinop_lMv4zNZS_sendMessage);
}

void Heavy_SoundScraper::cBinop_lMv4zNZS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_yms4vt8H, 0, m, &cPack_yms4vt8H_sendMessage);
}

void Heavy_SoundScraper::cBinop_2LAwlFu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_C0dKS9jC_sendMessage);
}

void Heavy_SoundScraper::cCast_nCAKO1ih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RZ22kD3C, 0, m, &cIf_RZ22kD3C_sendMessage);
}

void Heavy_SoundScraper::cCast_MPIGVI0V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_rCWlygyD_sendMessage);
}

void Heavy_SoundScraper::cBinop_rCWlygyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RZ22kD3C, 1, m, &cIf_RZ22kD3C_sendMessage);
}

void Heavy_SoundScraper::cBinop_bIKEdVmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_2LAwlFu4_sendMessage);
}

void Heavy_SoundScraper::cMsg_s5bLWhF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_yms4vt8H, 0, m, &cPack_yms4vt8H_sendMessage);
}

void Heavy_SoundScraper::cBinop_C0dKS9jC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lMv4zNZS, HV_BINOP_POW, 1, m, &cBinop_lMv4zNZS_sendMessage);
  cMsg_sTpDWbAQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_yms4vt8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ukQ3KPzs, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_DGirUXJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kjRRzbrn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_OHkei9ds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_5waPtnKf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_5waPtnKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Rcs2gv2W_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_kjRRzbrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_o2gXhDgi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_z07tKiea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PB2xN6LL_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_78ySevvy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eGDDYCmd_sendMessage);
}

void Heavy_SoundScraper::cIf_DTmrjffS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_uMd8dbxZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_M7zxrmYh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_CR5LZ7Tf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZO9pmCzg, HV_BINOP_POW, 0, m, &cBinop_ZO9pmCzg_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZO9pmCzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GGi77jW6, 0, m, &cPack_GGi77jW6_sendMessage);
}

void Heavy_SoundScraper::cBinop_C8Qyg9Rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_aA2Y4Cr7_sendMessage);
}

void Heavy_SoundScraper::cCast_eGDDYCmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DTmrjffS, 0, m, &cIf_DTmrjffS_sendMessage);
}

void Heavy_SoundScraper::cCast_78ySevvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_L48FiEF7_sendMessage);
}

void Heavy_SoundScraper::cBinop_L48FiEF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DTmrjffS, 1, m, &cIf_DTmrjffS_sendMessage);
}

void Heavy_SoundScraper::cBinop_M7zxrmYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_C8Qyg9Rt_sendMessage);
}

void Heavy_SoundScraper::cMsg_uMd8dbxZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_GGi77jW6, 0, m, &cPack_GGi77jW6_sendMessage);
}

void Heavy_SoundScraper::cBinop_aA2Y4Cr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZO9pmCzg, HV_BINOP_POW, 1, m, &cBinop_ZO9pmCzg_sendMessage);
  cMsg_CR5LZ7Tf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_GGi77jW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0A2cf6G7, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_PsAqwixX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Al8g8btd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_PB2xN6LL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_gikdOVXg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_gikdOVXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_D3fAxObx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Al8g8btd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YbmjBrIS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_Wg7WQXvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_7eogVMSd_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_vI9z87mY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_vI9z87mY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_1X2HjdQ5_sendMessage);
}

void Heavy_SoundScraper::cCast_IN0lVlkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Wg7WQXvE, 0, m, &cIf_Wg7WQXvE_sendMessage);
}

void Heavy_SoundScraper::cCast_5KkITc14_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_vJiqNH1p_sendMessage);
}

void Heavy_SoundScraper::cMsg_7eogVMSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_PB2xN6LL_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_78ySevvy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eGDDYCmd_sendMessage);
}

void Heavy_SoundScraper::cBinop_1X2HjdQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_UOLAc3Mf_sendMessage);
}

void Heavy_SoundScraper::cBinop_UOLAc3Mf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AJWndQlo_sendMessage);
}

void Heavy_SoundScraper::cBinop_AJWndQlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PB2xN6LL_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_78ySevvy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eGDDYCmd_sendMessage);
}

void Heavy_SoundScraper::cBinop_vJiqNH1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Wg7WQXvE, 1, m, &cIf_Wg7WQXvE_sendMessage);
}

void Heavy_SoundScraper::cBinop_7tDWm5l2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5KkITc14_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IN0lVlkt_sendMessage);
}

void Heavy_SoundScraper::cBinop_ya6hMd5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7tDWm5l2_sendMessage);
}

void Heavy_SoundScraper::cIf_ZiROSUND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_d99EvPpH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_IrWqdJ6M_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_IrWqdJ6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_EIb5cKN3_sendMessage);
}

void Heavy_SoundScraper::cCast_08CNZ5hw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZiROSUND, 0, m, &cIf_ZiROSUND_sendMessage);
}

void Heavy_SoundScraper::cCast_oSAeMPnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_o0bnACUQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_d99EvPpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_mP0CCXDG, 0, m, &cVar_mP0CCXDG_sendMessage);
}

void Heavy_SoundScraper::cBinop_EIb5cKN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_ZQ4kJs5t_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZQ4kJs5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DKzTG4aw_sendMessage);
}

void Heavy_SoundScraper::cBinop_DKzTG4aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mP0CCXDG, 0, m, &cVar_mP0CCXDG_sendMessage);
}

void Heavy_SoundScraper::cBinop_o0bnACUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZiROSUND, 1, m, &cIf_ZiROSUND_sendMessage);
}

void Heavy_SoundScraper::cBinop_w4KQSMxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oSAeMPnx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_08CNZ5hw_sendMessage);
}

void Heavy_SoundScraper::cBinop_qbvEIvjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_w4KQSMxS_sendMessage);
}

void Heavy_SoundScraper::cIf_BLuYOat1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_RqJd4Ask_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_dbXWuy57_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_dbXWuy57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_VvHb6jAs_sendMessage);
}

void Heavy_SoundScraper::cCast_9YegFLnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BLuYOat1, 0, m, &cIf_BLuYOat1_sendMessage);
}

void Heavy_SoundScraper::cCast_RR8VB6kc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_YG8Hd6IE_sendMessage);
}

void Heavy_SoundScraper::cMsg_RqJd4Ask_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_OHkei9ds_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MPIGVI0V_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nCAKO1ih_sendMessage);
}

void Heavy_SoundScraper::cBinop_VvHb6jAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_0doKYnLN_sendMessage);
}

void Heavy_SoundScraper::cBinop_0doKYnLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VRefuqT0_sendMessage);
}

void Heavy_SoundScraper::cBinop_VRefuqT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OHkei9ds_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MPIGVI0V_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nCAKO1ih_sendMessage);
}

void Heavy_SoundScraper::cBinop_YG8Hd6IE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BLuYOat1, 1, m, &cIf_BLuYOat1_sendMessage);
}

void Heavy_SoundScraper::cBinop_VhVCMsBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RR8VB6kc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9YegFLnz_sendMessage);
}

void Heavy_SoundScraper::cBinop_srh6YzbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VhVCMsBC_sendMessage);
}

void Heavy_SoundScraper::cVar_gJcvrwSO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_APER72hP_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_peO42KQa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XlRtWIMw_sendMessage);
}

void Heavy_SoundScraper::cIf_OW2CMtnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ZNSlEGxE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_nTqTehKK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_Qac84zA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6aMV9qa0, HV_BINOP_POW, 0, m, &cBinop_6aMV9qa0_sendMessage);
}

void Heavy_SoundScraper::cBinop_6aMV9qa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CQ8NkTyX, 0, m, &cPack_CQ8NkTyX_sendMessage);
}

void Heavy_SoundScraper::cBinop_NreJY55f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_QkaC84AM_sendMessage);
}

void Heavy_SoundScraper::cCast_XlRtWIMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OW2CMtnU, 0, m, &cIf_OW2CMtnU_sendMessage);
}

void Heavy_SoundScraper::cCast_peO42KQa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_z0LVMNXm_sendMessage);
}

void Heavy_SoundScraper::cBinop_z0LVMNXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OW2CMtnU, 1, m, &cIf_OW2CMtnU_sendMessage);
}

void Heavy_SoundScraper::cBinop_nTqTehKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_NreJY55f_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZNSlEGxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_CQ8NkTyX, 0, m, &cPack_CQ8NkTyX_sendMessage);
}

void Heavy_SoundScraper::cBinop_QkaC84AM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6aMV9qa0, HV_BINOP_POW, 1, m, &cBinop_6aMV9qa0_sendMessage);
  cMsg_Qac84zA9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_CQ8NkTyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_M7x71X3I, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_WEPCuDqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3IfZnvfi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_APER72hP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_Pgrhw0Fk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Pgrhw0Fk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0ZIO0CWu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_3IfZnvfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kppGpoQf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_W9w4Qjoo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hlkhETGV_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cxObTOgw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J8n5r9Uy_sendMessage);
}

void Heavy_SoundScraper::cIf_HCj1THsW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_nBwGI0ny_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Y3H6vweJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_OjgUlSwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hNipUThQ, HV_BINOP_POW, 0, m, &cBinop_hNipUThQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_hNipUThQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tWgvs5CU, 0, m, &cPack_tWgvs5CU_sendMessage);
}

void Heavy_SoundScraper::cBinop_IiG6oFGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_OQS0nIvT_sendMessage);
}

void Heavy_SoundScraper::cCast_cxObTOgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_qCRrMg8J_sendMessage);
}

void Heavy_SoundScraper::cCast_J8n5r9Uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HCj1THsW, 0, m, &cIf_HCj1THsW_sendMessage);
}

void Heavy_SoundScraper::cBinop_qCRrMg8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HCj1THsW, 1, m, &cIf_HCj1THsW_sendMessage);
}

void Heavy_SoundScraper::cBinop_Y3H6vweJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_IiG6oFGA_sendMessage);
}

void Heavy_SoundScraper::cMsg_nBwGI0ny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_tWgvs5CU, 0, m, &cPack_tWgvs5CU_sendMessage);
}

void Heavy_SoundScraper::cBinop_OQS0nIvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hNipUThQ, HV_BINOP_POW, 1, m, &cBinop_hNipUThQ_sendMessage);
  cMsg_OjgUlSwp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_tWgvs5CU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QX53BrJd, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_yZClcAdi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2EScajfA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_hlkhETGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_4P2e5ThL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_4P2e5ThL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NvLgCPBD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_2EScajfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cPKHPw8v_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_e7BB4ZUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HpnQNTDW, 0, m, &cIf_HpnQNTDW_sendMessage);
}

void Heavy_SoundScraper::cSlice_XAAZJNJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZXh0EZHy_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yI67lMgD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_SRBC8aR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_ZI82poBx, 0, m, &cIf_ZI82poBx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_ZI82poBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Zr0V3MXt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4WZB8UNh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_ocgD8iNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_dmKu2Nlx, 2, m, &cPack_dmKu2Nlx_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_rIy5axC8, 1, m, &cPack_rIy5axC8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_HSELf4pY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XAAZJNJQ, 0, m, &cSlice_XAAZJNJQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_SRBC8aR8, 0, m, &cSlice_SRBC8aR8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Ce75JDUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_c4Eh9WIr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_8nrI9qet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YYemzTgE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bGhRL4t4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nG7oNthW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_YSZvf10A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_W7tCa7Tf, 1, m, &cIf_W7tCa7Tf_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_QFOlMJCa_sendMessage);
}

void Heavy_SoundScraper::cIf_W7tCa7Tf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XAAZJNJQ, 0, m, &cSlice_XAAZJNJQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_SRBC8aR8, 0, m, &cSlice_SRBC8aR8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_rIy5axC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HSELf4pY, 0, m, &cIf_HSELf4pY_sendMessage);
}

void Heavy_SoundScraper::cBinop_5NJnQzJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZI82poBx, 1, m, &cIf_ZI82poBx_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ocgD8iNx, 1, m, &cIf_ocgD8iNx_sendMessage);
}

void Heavy_SoundScraper::cCast_ZXh0EZHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_5NJnQzJS_sendMessage);
}

void Heavy_SoundScraper::cCast_yI67lMgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ocgD8iNx, 0, m, &cIf_ocgD8iNx_sendMessage);
}

void Heavy_SoundScraper::cMsg_3id2tEbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_YSZvf10A, 1, m, &cVar_YSZvf10A_sendMessage);
}

void Heavy_SoundScraper::cMsg_c4Eh9WIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_YSZvf10A, 1, m, &cVar_YSZvf10A_sendMessage);
}

void Heavy_SoundScraper::cCast_YYemzTgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YSZvf10A, 0, m, &cVar_YSZvf10A_sendMessage);
}

void Heavy_SoundScraper::cCast_bGhRL4t4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rIy5axC8, 0, m, &cPack_rIy5axC8_sendMessage);
}

void Heavy_SoundScraper::cCast_nG7oNthW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3id2tEbe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_QFOlMJCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HSELf4pY, 1, m, &cIf_HSELf4pY_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_W8Ywoxbe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jbuP6h83, 0, m, &cSlice_jbuP6h83_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QMLLmUVf, 0, m, &cSlice_QMLLmUVf_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zEG5pDYG, 0, m, &cSlice_zEG5pDYG_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yJRJ57Na, 0, m, &cSlice_yJRJ57Na_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_jbuP6h83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_CRpRDZp4, 0, m, &cSlice_CRpRDZp4_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wQ88IDIH, 0, m, &cSlice_wQ88IDIH_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_CRpRDZp4, 0, m, &cSlice_CRpRDZp4_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wQ88IDIH, 0, m, &cSlice_wQ88IDIH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_QMLLmUVf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Wp2mYhT7, 0, m, &cSlice_Wp2mYhT7_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_RnNfO26i, 0, m, &cSlice_RnNfO26i_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Wp2mYhT7, 0, m, &cSlice_Wp2mYhT7_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_RnNfO26i, 0, m, &cSlice_RnNfO26i_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_zEG5pDYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_GUMAxy6d, 0, m, &cSlice_GUMAxy6d_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_1fKaZV7G, 0, m, &cSlice_1fKaZV7G_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_GUMAxy6d, 0, m, &cSlice_GUMAxy6d_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_1fKaZV7G, 0, m, &cSlice_1fKaZV7G_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_yJRJ57Na_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_2JuYc5c4, 0, m, &cSlice_2JuYc5c4_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_44YthkPZ, 0, m, &cSlice_44YthkPZ_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_2JuYc5c4, 0, m, &cSlice_2JuYc5c4_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_44YthkPZ, 0, m, &cSlice_44YthkPZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_lDVsfBnd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_76OoOgpU_sendMessage);
      break;
    }
    default: {
      cMsg_rvGqU4Y4_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_76OoOgpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3USU5pHm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_HpnQNTDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ce75JDUE, 0, m, &cSlice_Ce75JDUE_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8nrI9qet, 0, m, &cSlice_8nrI9qet_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_W7tCa7Tf, 0, m, &cIf_W7tCa7Tf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_kJ7Ul6KH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_01ACbpxP_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_HpnQNTDW, 1, m, &cIf_HpnQNTDW_sendMessage);
}

void Heavy_SoundScraper::cBinop_01ACbpxP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kJ7Ul6KH, 1, m, &cVar_kJ7Ul6KH_sendMessage);
}

void Heavy_SoundScraper::cMsg_3USU5pHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kJ7Ul6KH, 0, m, &cVar_kJ7Ul6KH_sendMessage);
}

void Heavy_SoundScraper::cMsg_rvGqU4Y4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kJ7Ul6KH, 0, m, &cVar_kJ7Ul6KH_sendMessage);
}

void Heavy_SoundScraper::cPack_dmKu2Nlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_W8Ywoxbe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_FSUWNLPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dmKu2Nlx, 0, m, &cPack_dmKu2Nlx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_5cCtf6bQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_5cCtf6bQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_b7qydVmu_sendMessage);
}

void Heavy_SoundScraper::cBinop_b7qydVmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FSUWNLPy, 1, m, &cVar_FSUWNLPy_sendMessage);
}

void Heavy_SoundScraper::cMsg_SbG8afyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_lDVsfBnd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_4WZB8UNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FSUWNLPy, 0, m, &cVar_FSUWNLPy_sendMessage);
}

void Heavy_SoundScraper::cCast_Zr0V3MXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dmKu2Nlx, 1, m, &cPack_dmKu2Nlx_sendMessage);
}

void Heavy_SoundScraper::cVar_OE4y0x2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_D93T8v9r_sendMessage);
  cSend_U6wEd3mv_sendMessage(_c, 0, m);
  cSwitchcase_QLT2Cs8b_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_D93T8v9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OE4y0x2h, 1, m, &cVar_OE4y0x2h_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_HzxP7K02_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xBKVgIGI_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_xBKVgIGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_v01VBK9P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_PGHoKb3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xm51otue, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_nBmG6oeM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_I5MePmB8, 0, m, &cSlice_I5MePmB8_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5bAJ4Gwm, 0, m, &cRandom_5bAJ4Gwm_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_g3MYp203_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uHgyRb45_sendMessage);
}

void Heavy_SoundScraper::cUnop_uHgyRb45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 25.0f, 0, m, &cBinop_iJn2fpdm_sendMessage);
}

void Heavy_SoundScraper::cRandom_5bAJ4Gwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 30.0f, 0, m, &cBinop_g3MYp203_sendMessage);
}

void Heavy_SoundScraper::cSlice_I5MePmB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5bAJ4Gwm, 1, m, &cRandom_5bAJ4Gwm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_woKctjVs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qlcX1D0F, 0, m, &cSlice_qlcX1D0F_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pRqirSh8, 0, m, &cRandom_pRqirSh8_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_1hvLZvjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uJOETLGA_sendMessage);
}

void Heavy_SoundScraper::cUnop_uJOETLGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_Z5U0fjRL_sendMessage);
}

void Heavy_SoundScraper::cRandom_pRqirSh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_1hvLZvjD_sendMessage);
}

void Heavy_SoundScraper::cSlice_qlcX1D0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pRqirSh8, 1, m, &cRandom_pRqirSh8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_jINaWA1W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_e4wVPyYe, 0, m, &cSlice_e4wVPyYe_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KUCCpq0o, 0, m, &cRandom_KUCCpq0o_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_SlgvSmJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nyI1qzNi_sendMessage);
}

void Heavy_SoundScraper::cUnop_nyI1qzNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lRrSqwQ6_sendMessage);
}

void Heavy_SoundScraper::cRandom_KUCCpq0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_SlgvSmJa_sendMessage);
}

void Heavy_SoundScraper::cSlice_e4wVPyYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KUCCpq0o, 1, m, &cRandom_KUCCpq0o_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_iJn2fpdm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uJCuv6Hz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Z5U0fjRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Vj9GuHqw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_lRrSqwQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DjcaonRy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_VgP4nV2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nBmG6oeM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_DhUESetk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_woKctjVs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_MbDHluQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jINaWA1W_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_T9eGiqI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6Yq0EPAt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6Yq0EPAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_wPUuK16G_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_wPUuK16G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_m3KNyruN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_DjcaonRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nFQOgxus_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Vj9GuHqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OZ7liEPL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_uJCuv6Hz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZQK35wun_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_3pnLqvem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DChgVzWv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_r6uVkBK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_diUY99ZG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LXzc7STj_sendMessage);
}

void Heavy_SoundScraper::cIf_xvcztYgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_u7XTCK19_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_V42vFn63_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_UnpTIJWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_UgQ5AvRp_sendMessage);
}

void Heavy_SoundScraper::cBinop_V42vFn63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_UnpTIJWV_sendMessage);
}

void Heavy_SoundScraper::cBinop_UgQ5AvRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_bZhhru71_sendMessage);
}

void Heavy_SoundScraper::cBinop_bZhhru71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jHaueP48, 0, m, &cVar_jHaueP48_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lFsL0tKR, HV_BINOP_SUBTRACT, 1, m, &cBinop_lFsL0tKR_sendMessage);
}

void Heavy_SoundScraper::cCast_LXzc7STj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xvcztYgg, 0, m, &cIf_xvcztYgg_sendMessage);
}

void Heavy_SoundScraper::cCast_diUY99ZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_F6B8zKGw_sendMessage);
}

void Heavy_SoundScraper::cBinop_F6B8zKGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xvcztYgg, 1, m, &cIf_xvcztYgg_sendMessage);
}

void Heavy_SoundScraper::cMsg_u7XTCK19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_jHaueP48, 0, m, &cVar_jHaueP48_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lFsL0tKR, HV_BINOP_SUBTRACT, 1, m, &cBinop_lFsL0tKR_sendMessage);
}

void Heavy_SoundScraper::cVar_jHaueP48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_5PqtnBJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lFsL0tKR, HV_BINOP_SUBTRACT, 0, m, &cBinop_lFsL0tKR_sendMessage);
}

void Heavy_SoundScraper::cBinop_oJ6HpPLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3pnLqvem, 0, m, &cVar_3pnLqvem_sendMessage);
}

void Heavy_SoundScraper::cBinop_XL10NWed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oJ6HpPLP, HV_BINOP_ADD, 1, m, &cBinop_oJ6HpPLP_sendMessage);
}

void Heavy_SoundScraper::cBinop_lFsL0tKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oJ6HpPLP, HV_BINOP_ADD, 0, m, &cBinop_oJ6HpPLP_sendMessage);
}

void Heavy_SoundScraper::cSend_DChgVzWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ud0ydmFv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_QLT2Cs8b_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jjvn5w1N, 0, m, &cSlice_jjvn5w1N_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TAjhrge3, 0, m, &cSlice_TAjhrge3_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_jjvn5w1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5Ddkdkfp_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5Ddkdkfp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_TAjhrge3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VqrblIou_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VqrblIou_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_lsT884Oe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hBDf2ffS, HV_BINOP_SUBTRACT, 1, m, &cBinop_hBDf2ffS_sendMessage);
}

void Heavy_SoundScraper::cMsg_qhgyrmx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lsT884Oe_sendMessage);
}

void Heavy_SoundScraper::cBinop_hBDf2ffS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t77GhehL, HV_BINOP_DIVIDE, 0, m, &cBinop_t77GhehL_sendMessage);
}

void Heavy_SoundScraper::cSystem_7PKgqMoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hBDf2ffS, HV_BINOP_SUBTRACT, 0, m, &cBinop_hBDf2ffS_sendMessage);
}

void Heavy_SoundScraper::cMsg_YaHISjqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7PKgqMoC_sendMessage);
}

void Heavy_SoundScraper::cBinop_t77GhehL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ACsSND43, HV_BINOP_SUBTRACT, 1, m, &cBinop_ACsSND43_sendMessage);
}

void Heavy_SoundScraper::cSystem_rcMW3FJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rMSdTdoc_sendMessage);
}

void Heavy_SoundScraper::cMsg_p9foqD8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rcMW3FJM_sendMessage);
}

void Heavy_SoundScraper::cBinop_rMSdTdoc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t77GhehL, HV_BINOP_DIVIDE, 1, m, &cBinop_t77GhehL_sendMessage);
}

void Heavy_SoundScraper::cSlice_qx98ABq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_t4moHfZ8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_TWupl5Xj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_Gk141ol1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_mSoL7sKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_Hutjys9I, 0, m, &cSlice_Hutjys9I_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_bd7e5PtO, 0, m, &cSlice_bd7e5PtO_sendMessage);
}

void Heavy_SoundScraper::cVar_X4SJ8SNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cHNi8EIp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_di9h1fs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X4SJ8SNX, 0, m, &cVar_X4SJ8SNX_sendMessage);
}

void Heavy_SoundScraper::cMsg_cHNi8EIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qx98ABq7, 0, m, &cSlice_qx98ABq7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TWupl5Xj, 0, m, &cSlice_TWupl5Xj_sendMessage);
}

void Heavy_SoundScraper::cBinop_Gk141ol1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mSoL7sKG, 0, m, &cPack_mSoL7sKG_sendMessage);
}

void Heavy_SoundScraper::cBinop_t4moHfZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mSoL7sKG, 1, m, &cPack_mSoL7sKG_sendMessage);
}

void Heavy_SoundScraper::cMsg_xhySXIgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_X4SJ8SNX, 1, m, &cVar_X4SJ8SNX_sendMessage);
}

void Heavy_SoundScraper::cVar_tadTNEgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3amOScd7, 0, m, &cIf_3amOScd7_sendMessage);
}

void Heavy_SoundScraper::cPack_uhsJsrqV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JEpRh8Ch_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_Hutjys9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_uhsJsrqV, 1, m, &cPack_uhsJsrqV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_bd7e5PtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xDQhsZnq, HV_BINOP_ADD, 0, m, &cBinop_xDQhsZnq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_xDQhsZnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uhsJsrqV, 0, m, &cPack_uhsJsrqV_sendMessage);
}

void Heavy_SoundScraper::cBinop_U875ji3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MGi2RJZG, HV_BINOP_MULTIPLY, 1, m, &cBinop_MGi2RJZG_sendMessage);
}

void Heavy_SoundScraper::cBinop_MGi2RJZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xDQhsZnq, HV_BINOP_ADD, 1, m, &cBinop_xDQhsZnq_sendMessage);
}

void Heavy_SoundScraper::cVar_JvmV5DKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VlrrqRAt, HV_BINOP_MULTIPLY, 0, m, &cBinop_VlrrqRAt_sendMessage);
}

void Heavy_SoundScraper::cMsg_VzixDSnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UEjJgLaB_sendMessage);
}

void Heavy_SoundScraper::cSystem_UEjJgLaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aDeJOS4Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_VlrrqRAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Y8RLdHQY_sendMessage);
}

void Heavy_SoundScraper::cBinop_4kRg6YBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VlrrqRAt, HV_BINOP_MULTIPLY, 1, m, &cBinop_VlrrqRAt_sendMessage);
}

void Heavy_SoundScraper::cMsg_aDeJOS4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4kRg6YBk_sendMessage);
}

void Heavy_SoundScraper::cBinop_Y8RLdHQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NDBRchR2_sendMessage);
}

void Heavy_SoundScraper::cBinop_NDBRchR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_A7ByHZNo_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_15LJbtGD, m);
}

void Heavy_SoundScraper::cBinop_A7ByHZNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zLskrljh, m);
}

void Heavy_SoundScraper::cSwitchcase_ecQZ59KB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_8obgvKU4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_8obgvKU4_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_KOoshTHO, 1, m, &cDelay_KOoshTHO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5v5EBpOs_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_KOoshTHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KOoshTHO, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3AAcMqF1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SUEvH0EL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YRTo8vHe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nOb970P3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rPjG0BeT_sendMessage);
}

void Heavy_SoundScraper::cMsg_8obgvKU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KOoshTHO, 0, m, &cDelay_KOoshTHO_sendMessage);
}

void Heavy_SoundScraper::cCast_5v5EBpOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KOoshTHO, 0, m, &cDelay_KOoshTHO_sendMessage);
}

void Heavy_SoundScraper::cIf_3amOScd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_ecQZ59KB_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_9rKtkbN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_ecQZ59KB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_5UVAJ4Xs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_3amOScd7, 1, m, &cIf_3amOScd7_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ya550V32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_3amOScd7, 1, m, &cIf_3amOScd7_sendMessage);
}

void Heavy_SoundScraper::cCast_OzltpwWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3AAcMqF1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SUEvH0EL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YRTo8vHe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nOb970P3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rPjG0BeT_sendMessage);
}

void Heavy_SoundScraper::cCast_MXv6lOVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5UVAJ4Xs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_8iv7W2N8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9rKtkbN1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ewdi3bup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ya550V32_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_z0ZORoXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_WzsSRkAU_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_JOdwLmRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_37zz8it2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_lDBhQEZM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZDn7UXZq, 0, m, &cSlice_ZDn7UXZq_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_ezoJ3413_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3bKLSSHV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_F6cxwQoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_68UlU3cb_sendMessage);
}

void Heavy_SoundScraper::cBinop_68UlU3cb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fhR0eurG, m);
}

void Heavy_SoundScraper::cMsg_3bKLSSHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_F6cxwQoz_sendMessage);
}

void Heavy_SoundScraper::cSlice_ZDn7UXZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_6cHL06Z7, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_gXemxlJn, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_ezoJ3413, 0, m, &cVar_ezoJ3413_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_rD1FgrpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_lDBhQEZM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_opkagc6t_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_esEtEGYb, 0, m, &cSlice_esEtEGYb_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_mQQApdpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TXnnfY24_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Cx7UVsdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_nYa64NFw_sendMessage);
}

void Heavy_SoundScraper::cBinop_nYa64NFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aXEGBLzW, m);
}

void Heavy_SoundScraper::cMsg_TXnnfY24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Cx7UVsdO_sendMessage);
}

void Heavy_SoundScraper::cSlice_esEtEGYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_sGmFShe2, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_dYnHV9Uq, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_mQQApdpN, 0, m, &cVar_mQQApdpN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_FURk88ku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_opkagc6t_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_EVXhtMwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nJgaRHXX, HV_BINOP_DIVIDE, 0, m, &cBinop_nJgaRHXX_sendMessage);
}

void Heavy_SoundScraper::cCast_a370BLlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LhABPw6o_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_qGJcRfKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EVXhtMwW, HV_BINOP_POW, 1, m, &cBinop_EVXhtMwW_sendMessage);
}

void Heavy_SoundScraper::cMsg_LhABPw6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EVXhtMwW, HV_BINOP_POW, 0, m, &cBinop_EVXhtMwW_sendMessage);
}

void Heavy_SoundScraper::cCast_2iSadCDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nJgaRHXX, HV_BINOP_DIVIDE, 1, m, &cBinop_nJgaRHXX_sendMessage);
}

void Heavy_SoundScraper::cCast_8cK3xhHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nJgaRHXX, HV_BINOP_DIVIDE, 0, m, &cBinop_nJgaRHXX_sendMessage);
}

void Heavy_SoundScraper::cBinop_nJgaRHXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_kzAqhD4D, 0, m);
}

void Heavy_SoundScraper::cBinop_DMXxjyzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qGJcRfKd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a370BLlA_sendMessage);
}

void Heavy_SoundScraper::cMsg_Tm2VT9O2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_x6I2X8AB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_x6I2X8AB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ud0ydmFv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_LAPRuDa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nFQOgxus_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_nEXw5gZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5.0f);
  cSend_LAPRuDa0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_xbyT4kgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_QE09Vrjd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_QE09Vrjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZpKlnAGm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_4GVpPwoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0qS5nhC0_sendMessage);
}

void Heavy_SoundScraper::cBinop_0qS5nhC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ilP5G18V_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_f5Ze8klH_sendMessage);
}

void Heavy_SoundScraper::cVar_65wmEn4P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_6VWIj98W_sendMessage);
}

void Heavy_SoundScraper::cMsg_hjSRdQhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_br71nrsY_sendMessage);
}

void Heavy_SoundScraper::cSystem_br71nrsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eK8SfPWv, HV_BINOP_DIVIDE, 1, m, &cBinop_eK8SfPWv_sendMessage);
}

void Heavy_SoundScraper::cBinop_ilP5G18V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_DWQz84h6_sendMessage);
}

void Heavy_SoundScraper::cBinop_DWQz84h6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tKsrHMxP, m);
}

void Heavy_SoundScraper::cMsg_7X3t6FXL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_gHRYGSgL_sendMessage);
}

void Heavy_SoundScraper::cBinop_gHRYGSgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_4GVpPwoO_sendMessage);
}

void Heavy_SoundScraper::cBinop_f5Ze8klH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NRJeV8Mi, m);
}

void Heavy_SoundScraper::cBinop_6VWIj98W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_BDYmSzLM_sendMessage);
}

void Heavy_SoundScraper::cBinop_BDYmSzLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eK8SfPWv, HV_BINOP_DIVIDE, 0, m, &cBinop_eK8SfPWv_sendMessage);
}

void Heavy_SoundScraper::cBinop_eK8SfPWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7X3t6FXL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_KAGtk9oW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OZhn2DWi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_D3rXMW6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oGaTqdNh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_KlrMfkbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ArmgaRol_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Tb0PLG4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kVwnqAvN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ShQmILfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_m3KNyruN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_hSKlQPvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_REmNND6N_sendMessage);
}

void Heavy_SoundScraper::cBinop_REmNND6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PGHoKb3F, 0, m, &cPack_PGHoKb3F_sendMessage);
}

void Heavy_SoundScraper::cSend_v01VBK9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kVwnqAvN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_U6wEd3mv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_rQSTlOXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MhaqFzaO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_9t8oTXfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EKXbRhyt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_5Ddkdkfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rQSTlOXA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_VqrblIou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9t8oTXfw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ACsSND43_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_eqD5sItL_sendMessage);
}

void Heavy_SoundScraper::cCast_Op5juqFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p9foqD8s_sendMessage(_c, 0, m);
  cMsg_YaHISjqP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_00Ybc8Aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ACsSND43, HV_BINOP_SUBTRACT, 0, m, &cBinop_ACsSND43_sendMessage);
}

void Heavy_SoundScraper::cBinop_eqD5sItL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3amOScd7, 0, m, &cIf_3amOScd7_sendMessage);
}

void Heavy_SoundScraper::cMsg_I6AM9fr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Hutjys9I, 0, m, &cSlice_Hutjys9I_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_bd7e5PtO, 0, m, &cSlice_bd7e5PtO_sendMessage);
}

void Heavy_SoundScraper::cBinop_Y6nRytzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Op5juqFs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_00Ybc8Aw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tadTNEgE, 1, m, &cVar_tadTNEgE_sendMessage);
}

void Heavy_SoundScraper::cMsg_GFAw6jP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ycrCFRyr, m);
}

void Heavy_SoundScraper::cMsg_vrzgYN2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ycrCFRyr, m);
}

void Heavy_SoundScraper::cSend_JEpRh8Ch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XzJGgUCX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_oJ805KjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_ouwKXvfr, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_rPjG0BeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X4SJ8SNX, 0, m, &cVar_X4SJ8SNX_sendMessage);
}

void Heavy_SoundScraper::cCast_YRTo8vHe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_nOb970P3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I6AM9fr1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_3AAcMqF1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qhgyrmx0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_SUEvH0EL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tadTNEgE, 0, m, &cVar_tadTNEgE_sendMessage);
}

void Heavy_SoundScraper::cSend_37zz8it2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7B8aCUh2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_WzsSRkAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oiHeuAKL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_olTkM5VD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_A4XLrV44_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_A4XLrV44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SZuPmLYW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_0TqOcenL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2MVXVmkW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vwQHbsUx_sendMessage);
}

void Heavy_SoundScraper::cCast_2MVXVmkW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VVoDx1Va, HV_BINOP_MULTIPLY, 1, m, &cBinop_VVoDx1Va_sendMessage);
}

void Heavy_SoundScraper::cCast_vwQHbsUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VVoDx1Va, HV_BINOP_MULTIPLY, 0, m, &cBinop_VVoDx1Va_sendMessage);
}

void Heavy_SoundScraper::cBinop_VVoDx1Va_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sMDYS54o_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_sMDYS54o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_A2l63CYC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_KYMoiAT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_mkrY4Gmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_KKVl99Xc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_oFUFd8F8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_uDeQDSoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_1Rgfe6BM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_lq6dsSlL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LIBb0vEI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Ixm1eSLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5U46ADHP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_a1aZtPQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_Urj5XPAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "marimba");
  msg_setFloat(m, 1, 264.0f);
  cSend_GszQO6vG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Vh5iV0kG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "xylo");
  msg_setFloat(m, 1, 2116.9f);
  cSend_GszQO6vG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_zZdTqPlc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "almglocken");
  msg_setFloat(m, 1, 525.57f);
  cSend_GszQO6vG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_9h7KIKwb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "bowl");
  msg_setFloat(m, 1, 705.52f);
  cSend_GszQO6vG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_K7m4bI6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "gong");
  msg_setFloat(m, 1, 179.88f);
  cSend_GszQO6vG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_GszQO6vG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cTkeA2Uu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_cQ2kVYKH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "crotale");
  msg_setFloat(m, 1, 1058.39f);
  cSend_GszQO6vG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Aht5biQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nruLcyEc_onMessage(_c, NULL, 0, m, NULL);
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
}

void Heavy_SoundScraper::cReceive_HgV7ikmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hum8Fu4b_sendMessage(_c, 0, m);
  cMsg_4eHnlmQ0_sendMessage(_c, 0, m);
  cMsg_p5nEi54s_sendMessage(_c, 0, m);
  cMsg_0ukgME4H_sendMessage(_c, 0, m);
  cMsg_XQjqXu2z_sendMessage(_c, 0, m);
  cMsg_3Ff1doxj_sendMessage(_c, 0, m);
  cMsg_kvIk8zqd_sendMessage(_c, 0, m);
  cMsg_sEurtVMT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wfPwA3yL, 0, m, &cVar_wfPwA3yL_sendMessage);
  cMsg_mNn9ri2R_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_82msUsXF, 0, m, &cVar_82msUsXF_sendMessage);
  cMsg_LjOrJWZn_sendMessage(_c, 0, m);
  cMsg_y66hBBhu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zA33dGaX, 0, m, &cVar_zA33dGaX_sendMessage);
  cMsg_I4susFis_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_t6k8MfJI, 0, m, &cVar_t6k8MfJI_sendMessage);
  cMsg_DCWFotXM_sendMessage(_c, 0, m);
  cMsg_Y5PvF4K4_sendMessage(_c, 0, m);
  cMsg_JxPlOIhq_sendMessage(_c, 0, m);
  cMsg_WGqjqJuR_sendMessage(_c, 0, m);
  cMsg_ZS4gixRM_sendMessage(_c, 0, m);
  cMsg_JVqs0KQE_sendMessage(_c, 0, m);
  cMsg_U5dCsBoO_sendMessage(_c, 0, m);
  cMsg_xtm5i9gk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pU1yHqHv, 0, m, &cVar_pU1yHqHv_sendMessage);
  cMsg_HF0ONWLw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SHGAn4qe, 0, m, &cVar_SHGAn4qe_sendMessage);
  cMsg_qOYcukM7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_e7d3Klab, 0, m, &cVar_e7d3Klab_sendMessage);
  cMsg_454eDPPm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_54QA777q, 0, m, &cVar_54QA777q_sendMessage);
  cMsg_GdWiyT55_sendMessage(_c, 0, m);
  cMsg_kVAr3yfE_sendMessage(_c, 0, m);
  cMsg_ZxIoh2go_sendMessage(_c, 0, m);
  cMsg_YlZN6zA7_sendMessage(_c, 0, m);
  cMsg_IFc0lD7Z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yZNhN76s, 0, m, &cVar_yZNhN76s_sendMessage);
  cMsg_J9P8Czxc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nWojawMq, 0, m, &cVar_nWojawMq_sendMessage);
  cMsg_JHOE7l2j_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_91ipxeix, 0, m, &cVar_91ipxeix_sendMessage);
  cMsg_iftnKiXE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Csrnrx4g, 0, m, &cVar_Csrnrx4g_sendMessage);
  cMsg_AlFE28Q7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_g3AY7716, 0, m, &cVar_g3AY7716_sendMessage);
  cMsg_z4ONdsLU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9lofG6oX, 0, m, &cVar_9lofG6oX_sendMessage);
  cMsg_aYB0rlYD_sendMessage(_c, 0, m);
  cMsg_hSOhMlrF_sendMessage(_c, 0, m);
  cMsg_Y6Y7P0mH_sendMessage(_c, 0, m);
  cMsg_qM6GgHrt_sendMessage(_c, 0, m);
  cMsg_e6RSzkHd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_A0Egmp55, 0, m, &cVar_A0Egmp55_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Xl3EeTDl, 0, m, &cVar_Xl3EeTDl_sendMessage);
  cMsg_tJms4pSx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VfXwFZY9, 0, m, &cVar_VfXwFZY9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sgrR3zew, 0, m, &cVar_sgrR3zew_sendMessage);
  cMsg_aSsS99ZA_sendMessage(_c, 0, m);
  cMsg_YWNjHKxA_sendMessage(_c, 0, m);
  cMsg_dzUjOzfy_sendMessage(_c, 0, m);
  cMsg_Rt1Qrklw_sendMessage(_c, 0, m);
  cMsg_wtuBDsB3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Gg3wX7s6, 0, m, &cVar_Gg3wX7s6_sendMessage);
  cMsg_rjoApHC2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wzvDFJQl, 0, m, &cVar_wzvDFJQl_sendMessage);
  cMsg_R11h8PbB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kTNyIV3i, 0, m, &cVar_kTNyIV3i_sendMessage);
  cMsg_6B8jjAeH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_P08ow6rl, 0, m, &cVar_P08ow6rl_sendMessage);
  cMsg_eT8gJYFE_sendMessage(_c, 0, m);
  cMsg_JHQOCCoi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_71N7Wq23, 0, m, &cVar_71N7Wq23_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pcFIlYhK, 0, m, &cVar_pcFIlYhK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tdXGgu5C, 0, m, &cVar_tdXGgu5C_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_B3krmBek, 0, m, &cVar_B3krmBek_sendMessage);
  cMsg_fEkSmIAJ_sendMessage(_c, 0, m);
  cMsg_DPNEvlq8_sendMessage(_c, 0, m);
  cMsg_Jy6G69oz_sendMessage(_c, 0, m);
  cMsg_2zMNhWK3_sendMessage(_c, 0, m);
  cMsg_Jg9P6Gm8_sendMessage(_c, 0, m);
  cMsg_E2OO8AXp_sendMessage(_c, 0, m);
  cMsg_Pw8Wz37N_sendMessage(_c, 0, m);
  cMsg_1oqpbjRk_sendMessage(_c, 0, m);
  cMsg_E7bZbmaj_sendMessage(_c, 0, m);
  cMsg_7ySBhN73_sendMessage(_c, 0, m);
  cMsg_oiToXWze_sendMessage(_c, 0, m);
  cMsg_42SGq2as_sendMessage(_c, 0, m);
  cMsg_ey8S0G9e_sendMessage(_c, 0, m);
  cMsg_5K4FM6ku_sendMessage(_c, 0, m);
  cMsg_hc15PLuy_sendMessage(_c, 0, m);
  cMsg_Fd2pzQW6_sendMessage(_c, 0, m);
  cMsg_AdXtM0qn_sendMessage(_c, 0, m);
  cMsg_VzixDSnL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JvmV5DKq, 0, m, &cVar_JvmV5DKq_sendMessage);
  cMsg_Tm2VT9O2_sendMessage(_c, 0, m);
  cMsg_nEXw5gZD_sendMessage(_c, 0, m);
  cMsg_xbyT4kgg_sendMessage(_c, 0, m);
  cMsg_hjSRdQhM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_65wmEn4P, 0, m, &cVar_65wmEn4P_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4EVvJEui, 0, m, &cVar_4EVvJEui_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EV73xJ0A, 0, m, &cVar_EV73xJ0A_sendMessage);
  cMsg_aY93zSUK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mP0CCXDG, 0, m, &cVar_mP0CCXDG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4visTvZD, 0, m, &cVar_4visTvZD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wS6Sat5f, 0, m, &cVar_wS6Sat5f_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zG44W7DL, 0, m, &cVar_zG44W7DL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GjZgFfXS, 0, m, &cVar_GjZgFfXS_sendMessage);
  cMsg_UktzKYpq_sendMessage(_c, 0, m);
  cMsg_nKfCvS3f_sendMessage(_c, 0, m);
  cMsg_7sjdcym1_sendMessage(_c, 0, m);
  cMsg_oxir0jAN_sendMessage(_c, 0, m);
  cMsg_jcrUjBJx_sendMessage(_c, 0, m);
  cMsg_USZ267fk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Rd0SjDRB, 0, m, &cVar_Rd0SjDRB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sggg9JiS, 0, m, &cVar_sggg9JiS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_z07tKiea, 0, m, &cVar_z07tKiea_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gJcvrwSO, 0, m, &cVar_gJcvrwSO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_W9w4Qjoo, 0, m, &cVar_W9w4Qjoo_sendMessage);
  cMsg_SbG8afyP_sendMessage(_c, 0, m);
  cSend_Tb0PLG4F_sendMessage(_c, 0, m);
  cMsg_Vh5iV0kG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rkCpV5AF, 0, m, &cVar_rkCpV5AF_sendMessage);
  cMsg_3R3g79nR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_f80TjrWe, 0, m, &cVar_f80TjrWe_sendMessage);
  cMsg_CNm2DDlK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xpJUWQBu, 0, m, &cVar_xpJUWQBu_sendMessage);
  cMsg_Uyfn976R_sendMessage(_c, 0, m);
  cMsg_Lsd6TrSo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tDo2rNxN, 0, m, &cVar_tDo2rNxN_sendMessage);
  cMsg_no66iP7z_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_JkbRmVGZ, 0, m, &cTabhead_JkbRmVGZ_sendMessage);
  cMsg_3E5aWTmw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aoZnCuCn, 0, m, &cVar_aoZnCuCn_sendMessage);
  cMsg_HW0E7lfX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Hir9LMco, 0, m, &cTabhead_Hir9LMco_sendMessage);
  cMsg_yHiwxdAV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LjyXlIqz, 0, m, &cVar_LjyXlIqz_sendMessage);
  cMsg_PsBnFpLM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OWNyXRSs, 0, m, &cTabhead_OWNyXRSs_sendMessage);
  cMsg_sDrYMnS7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gnZEOEpr, 0, m, &cVar_gnZEOEpr_sendMessage);
  cMsg_PeEOMoDs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mDulVuSE, 0, m, &cTabhead_mDulVuSE_sendMessage);
  cMsg_qU5iHGTm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Kzxz6EMx, 0, m, &cVar_Kzxz6EMx_sendMessage);
  cMsg_7Ox1B1QB_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RgoFn4yl, 0, m, &cTabhead_RgoFn4yl_sendMessage);
  cMsg_Uwpcn9LO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EbrPn0lj, 0, m, &cVar_EbrPn0lj_sendMessage);
  cMsg_Oa3UoCKG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5zleY9V1, 0, m, &cTabhead_5zleY9V1_sendMessage);
  cMsg_nUaAEKvl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ukDOVf2S, 0, m, &cVar_ukDOVf2S_sendMessage);
  cMsg_AwBLh0Fg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_dpeliT6G, 0, m, &cTabhead_dpeliT6G_sendMessage);
  cMsg_j1ar58IO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CQcLsCfj, 0, m, &cVar_CQcLsCfj_sendMessage);
  cMsg_4XfO5Qmz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EZOzVat6, 0, m, &cTabhead_EZOzVat6_sendMessage);
  cMsg_swjZxoUP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ta4avafL, 0, m, &cVar_Ta4avafL_sendMessage);
  cMsg_54lCjedC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6l2AfMcQ, 0, m, &cTabhead_6l2AfMcQ_sendMessage);
  cMsg_aegZRSgq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZBBMvkxm, 0, m, &cVar_ZBBMvkxm_sendMessage);
  cMsg_gxoBYXch_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ycEFOiMW, 0, m, &cTabhead_ycEFOiMW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VbxWM3Un, 0, m, &cVar_VbxWM3Un_sendMessage);
  cMsg_6Y0BxhdM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0ge6cK5G, 0, m, &cVar_0ge6cK5G_sendMessage);
  cMsg_O2WkWQeL_sendMessage(_c, 0, m);
  cMsg_rFtx36UI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8WtLDrD5, 0, m, &cVar_8WtLDrD5_sendMessage);
  cMsg_wkc58VuQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_oXdYeowc, 0, m, &cTabhead_oXdYeowc_sendMessage);
  cMsg_nuxZPw74_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aBxFiuMC, 0, m, &cVar_aBxFiuMC_sendMessage);
  cMsg_ZKONfjUN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zAsgvHiv, 0, m, &cTabhead_zAsgvHiv_sendMessage);
  cMsg_RoXblPb6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_k8YLpKz9, 0, m, &cVar_k8YLpKz9_sendMessage);
  cMsg_JaC53Jbs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_oOxd6kPi, 0, m, &cTabhead_oOxd6kPi_sendMessage);
  cMsg_LrNcuQtL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mq7ADqS6, 0, m, &cVar_mq7ADqS6_sendMessage);
  cMsg_sqexrfZg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YABkOIom, 0, m, &cTabhead_YABkOIom_sendMessage);
  cMsg_BjXPuO4C_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8yeLigtZ, 0, m, &cVar_8yeLigtZ_sendMessage);
  cMsg_3CvDfynJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bhG4IPjP, 0, m, &cTabhead_bhG4IPjP_sendMessage);
  cMsg_oIOaAnR5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KfpeR1u6, 0, m, &cVar_KfpeR1u6_sendMessage);
  cMsg_8YCYsQu6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HMwr6AVF, 0, m, &cTabhead_HMwr6AVF_sendMessage);
  cMsg_zg0HiRZB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YdcuhJ0D, 0, m, &cVar_YdcuhJ0D_sendMessage);
  cMsg_yo3U5RO7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ewq6WUqS, 0, m, &cTabhead_ewq6WUqS_sendMessage);
  cMsg_aYiSa69P_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Oze4lTOM, 0, m, &cVar_Oze4lTOM_sendMessage);
  cMsg_KSdJpOmQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YkMqdHnJ, 0, m, &cTabhead_YkMqdHnJ_sendMessage);
  cMsg_sY3weUQZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EDmWy7Rk, 0, m, &cVar_EDmWy7Rk_sendMessage);
  cMsg_11ALiNhX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EVlkGzkC, 0, m, &cTabhead_EVlkGzkC_sendMessage);
  cMsg_uxX5zwDQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oSZotN2e, 0, m, &cVar_oSZotN2e_sendMessage);
  cMsg_R0NcDQH0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_X2RYRf3W, 0, m, &cTabhead_X2RYRf3W_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_scFS7rvD, 0, m, &cVar_scFS7rvD_sendMessage);
  cMsg_Jq5zIY0G_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gu6vDZ1z, 0, m, &cVar_gu6vDZ1z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6GqMDbR5, 0, m, &cVar_6GqMDbR5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wp4dYXVo, 0, m, &cVar_wp4dYXVo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_unWpXSBQ, 0, m, &cVar_unWpXSBQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ezoJ3413, 0, m, &cVar_ezoJ3413_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mQQApdpN, 0, m, &cVar_mQQApdpN_sendMessage);
}

void Heavy_SoundScraper::cReceive_704mUhgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_13XRqR7h, 0, m, &cSlice_13XRqR7h_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_lbpghUeX, 0, m, &cSlice_lbpghUeX_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_q718bSyL, 0, m, &cSlice_q718bSyL_sendMessage);
}

void Heavy_SoundScraper::cReceive_LIBb0vEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_e7BB4ZUT, 0, m, &cPack_e7BB4ZUT_sendMessage);
}

void Heavy_SoundScraper::cReceive_5U46ADHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_e7BB4ZUT, 1, m, &cPack_e7BB4ZUT_sendMessage);
}

void Heavy_SoundScraper::cReceive_2uR4NLIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_D3rXMW6p_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_V3QykzI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mGoiGFHV_sendMessage);
}

void Heavy_SoundScraper::cReceive_Ppna85Gd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KAGtk9oW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_oaJ3luLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6HlxZttq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6OfJJtal_sendMessage);
}

void Heavy_SoundScraper::cReceive_cTkeA2Uu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_T1hjmdea, 0, m, &cSlice_T1hjmdea_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_f7rHpMFy, 0, m, &cSlice_f7rHpMFy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_eM5jN6JG, 0, m, &cSlice_eM5jN6JG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_aZfbopva, 0, m, &cSlice_aZfbopva_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_MDZOpyys, 0, m, &cSlice_MDZOpyys_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JfXcUTAR, 0, m, &cSlice_JfXcUTAR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SvC5V0D8, 0, m, &cSlice_SvC5V0D8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_d7PB4q7q, 0, m, &cSlice_d7PB4q7q_sendMessage);
  cSend_KlrMfkbR_sendMessage(_c, 0, m);
  cPrint_onMessage(_c, m, "SCRAPE_SAMPLE");
}

void Heavy_SoundScraper::cReceive_D2jBHhby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HzxP7K02_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_OE4y0x2h, 0, m, &cVar_OE4y0x2h_sendMessage);
}

void Heavy_SoundScraper::cReceive_zdSmZkHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ShQmILfc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_8mC26TIM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Tb0PLG4F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_MvC4UGib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jK7Kofun_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_WVVjU2J2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GMsfwqno, 0, m, &cVar_GMsfwqno_sendMessage);
}

void Heavy_SoundScraper::cReceive_uYvfXJ9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1VgVnVDj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VM7fqgNo_sendMessage);
}

void Heavy_SoundScraper::cReceive_tfYtEiB1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WCeva55D_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6YiB3lVo_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_5IOyDtUv, 0, m, &cPack_5IOyDtUv_sendMessage);
}

void Heavy_SoundScraper::cReceive_dLELQr31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7G7dgBiJ, 1, m, &cVar_7G7dgBiJ_sendMessage);
}

void Heavy_SoundScraper::cReceive_F8iOnRlU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_spT2TXtR, HV_BINOP_DIVIDE, 1, m, &cBinop_spT2TXtR_sendMessage);
}

void Heavy_SoundScraper::cReceive_xaLHXMlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XdcRzhUf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_j9rZjnYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yQh7gPHV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_P8SSrDX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wsaHEsRw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_OVKAaoWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RkkYb3Tl, 1, m, &cVar_RkkYb3Tl_sendMessage);
}

void Heavy_SoundScraper::cReceive_MESMY1J5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_67JIqCl7, m);
}

void Heavy_SoundScraper::cReceive_Bhekm82E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Ax58MiOs, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_0LYzycFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ahoDOIU8, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_fkdRS3Kk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZbfKYgsK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_AxRt1PYE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_QhvPxXfK_sendMessage);
}

void Heavy_SoundScraper::cReceive_KU7luaTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_l1txTO3i_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yLRqJcCX_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_Ax58MiOs, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_Ac3kk4og_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KovtDPqk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gVx1UEil_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_gaF8cQvI, 1, m, &cPack_gaF8cQvI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XcHGm8Cj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rHyIGJ2P_sendMessage);
}

void Heavy_SoundScraper::cReceive_QPfXE6n0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_P8STOGKQ, 1, m, &cPack_P8STOGKQ_sendMessage);
}

void Heavy_SoundScraper::cReceive_5IiWOkWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wbs4SlV4, 1, m, &cVar_wbs4SlV4_sendMessage);
}

void Heavy_SoundScraper::cReceive_Zo69CGnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EUY59TKI, HV_BINOP_DIVIDE, 1, m, &cBinop_EUY59TKI_sendMessage);
}

void Heavy_SoundScraper::cReceive_9y98ug7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FRPKQi5q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_Ab4JEDsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3vTkre0g_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_s7zg2jA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1sKo1IPX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_ktIMVuQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UFwJC2AF, 1, m, &cVar_UFwJC2AF_sendMessage);
}

void Heavy_SoundScraper::cReceive_BZr7WEnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XnMFYCoH, m);
}

void Heavy_SoundScraper::cReceive_oYwheUxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mgjVTqKC, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_Xe9pixiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tYlQqpyr, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_Qalldnu8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hLoB92tm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_LDjQh2gv_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_QfcPdPHZ_sendMessage);
}

void Heavy_SoundScraper::cReceive_bE92TkgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zccu0PDI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b6ZrtfNx_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_mgjVTqKC, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_4FZHb02U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sdHZqB5U_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6cLroPFj_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_oNCvUW49, 1, m, &cPack_oNCvUW49_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O6YpXXiL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5BQug06V_sendMessage);
}

void Heavy_SoundScraper::cReceive_21vtQCIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zsICs8u6, 1, m, &cPack_zsICs8u6_sendMessage);
}

void Heavy_SoundScraper::cReceive_M4CEsncm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EcFkdkbq, 1, m, &cVar_EcFkdkbq_sendMessage);
}

void Heavy_SoundScraper::cReceive_9ZRw3tV0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p8PcLyHi, HV_BINOP_DIVIDE, 1, m, &cBinop_p8PcLyHi_sendMessage);
}

void Heavy_SoundScraper::cReceive_pFe3BP7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aPcU3KxD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_2JqrnV2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MZt94rAe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_xc0p3kNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_A45GyRJg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_m2jgQR82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qhvrbskB, 1, m, &cVar_qhvrbskB_sendMessage);
}

void Heavy_SoundScraper::cReceive_DKJzqtTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_r3rZgjy1, m);
}

void Heavy_SoundScraper::cReceive_LE0SR3xP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_UqJ0OItO, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_gMNpcyJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_4WEnB2xJ, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_5V0y2WGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_69B3269U_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_U8bqcv6S_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_hRxid4Yp_sendMessage);
}

void Heavy_SoundScraper::cReceive_3yXzJzDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zLlo8yaW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lJp25WhZ_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_UqJ0OItO, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_X49M1KNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0Z3C4iQH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iwLMuLd2_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_HpbbdZWo, 1, m, &cPack_HpbbdZWo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AOhQGrtb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EdrvSEC4_sendMessage);
}

void Heavy_SoundScraper::cReceive_ClX0blva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BeD7LQxu, 1, m, &cPack_BeD7LQxu_sendMessage);
}

void Heavy_SoundScraper::cReceive_F4Eq9OEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YbJWKSa6, 1, m, &cVar_YbJWKSa6_sendMessage);
}

void Heavy_SoundScraper::cReceive_exWYHmPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tnpzxqEn, HV_BINOP_DIVIDE, 1, m, &cBinop_tnpzxqEn_sendMessage);
}

void Heavy_SoundScraper::cReceive_Ba8caV8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pfuPB6j6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_250ijgMz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_g6tCwkZ4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_njjCQh0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XUxItUxP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_ghMsBmYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T4l79h2i, 1, m, &cVar_T4l79h2i_sendMessage);
}

void Heavy_SoundScraper::cReceive_JpjRX77H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SE2ZC0p6, m);
}

void Heavy_SoundScraper::cReceive_fuex8P7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_iSCeTc4t, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_b2SLxpSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_SdVEGH4p, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_YnZwHEnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8OgwBFjZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_f9zC1jXJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_Kbe8v9NF_sendMessage);
}

void Heavy_SoundScraper::cReceive_vcn098dE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0yrZ117R_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U7W3Nrre_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_iSCeTc4t, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_WBb0F73r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nJ9qQbAK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VarqTGHV_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_wAn4lH4T, 1, m, &cPack_wAn4lH4T_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kona9MyL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Yi4qwbXw_sendMessage);
}

void Heavy_SoundScraper::cReceive_QoEnniYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3TLR4kXG, 1, m, &cPack_3TLR4kXG_sendMessage);
}

void Heavy_SoundScraper::cReceive_NegdzFGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nruLcyEc_onMessage(_c, NULL, 0, m, NULL);
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
}

void Heavy_SoundScraper::cReceive_27LqMN88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_qbvEIvjz_sendMessage);
}

void Heavy_SoundScraper::cReceive_Yknh3RpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4wygmsSJ, 0, m, &cVar_4wygmsSJ_sendMessage);
}

void Heavy_SoundScraper::cReceive_mE5z5KCh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JHQKbt87_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cDOvdyhd_sendMessage);
}

void Heavy_SoundScraper::cReceive_Rcs2gv2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DGirUXJQ, 0, m, &cVar_DGirUXJQ_sendMessage);
}

void Heavy_SoundScraper::cReceive_o2gXhDgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MPIGVI0V_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nCAKO1ih_sendMessage);
}

void Heavy_SoundScraper::cReceive_RClODdqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_srh6YzbQ_sendMessage);
}

void Heavy_SoundScraper::cReceive_D3fAxObx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PsAqwixX, 0, m, &cVar_PsAqwixX_sendMessage);
}

void Heavy_SoundScraper::cReceive_YbmjBrIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_78ySevvy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eGDDYCmd_sendMessage);
}

void Heavy_SoundScraper::cReceive_ixH5ysOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_ya6hMd5p_sendMessage);
}

void Heavy_SoundScraper::cReceive_0ZIO0CWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WEPCuDqP, 0, m, &cVar_WEPCuDqP_sendMessage);
}

void Heavy_SoundScraper::cReceive_kppGpoQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_peO42KQa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XlRtWIMw_sendMessage);
}

void Heavy_SoundScraper::cReceive_NvLgCPBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yZClcAdi, 0, m, &cVar_yZClcAdi_sendMessage);
}

void Heavy_SoundScraper::cReceive_cPKHPw8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cxObTOgw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J8n5r9Uy_sendMessage);
}

void Heavy_SoundScraper::cReceive_OZhn2DWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lFsL0tKR, HV_BINOP_SUBTRACT, 0, m, &cBinop_lFsL0tKR_sendMessage);
}

void Heavy_SoundScraper::cReceive_oGaTqdNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_hSKlQPvn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5vTXHZS3, 0, m, &cVar_5vTXHZS3_sendMessage);
}

void Heavy_SoundScraper::cReceive_ArmgaRol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_z0ZORoXZ, 0, m, &cSlice_z0ZORoXZ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JOdwLmRC, 0, m, &cSlice_JOdwLmRC_sendMessage);
}

void Heavy_SoundScraper::cReceive_kVwnqAvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T9eGiqI4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MbDHluQd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VgP4nV2G_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DhUESetk_sendMessage);
}

void Heavy_SoundScraper::cReceive_m3KNyruN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_XL10NWed_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5PqtnBJi_sendMessage);
}

void Heavy_SoundScraper::cReceive_nFQOgxus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_olTkM5VD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VVoDx1Va, HV_BINOP_MULTIPLY, 0, m, &cBinop_VVoDx1Va_sendMessage);
}

void Heavy_SoundScraper::cReceive_OZ7liEPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 10.0f, 0, m, &cBinop_Y6nRytzR_sendMessage);
}

void Heavy_SoundScraper::cReceive_ZQK35wun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MGi2RJZG, HV_BINOP_MULTIPLY, 0, m, &cBinop_MGi2RJZG_sendMessage);
}

void Heavy_SoundScraper::cReceive_ud0ydmFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_DMXxjyzo_sendMessage);
}

void Heavy_SoundScraper::cReceive_oiHeuAKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r6uVkBK3, 0, m, &cVar_r6uVkBK3_sendMessage);
}

void Heavy_SoundScraper::cReceive_MhaqFzaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MXv6lOVG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OzltpwWH_sendMessage);
  cMsg_GFAw6jP3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_EKXbRhyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ewdi3bup_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8iv7W2N8_sendMessage);
  cMsg_vrzgYN2D_sendMessage(_c, 0, m);
  cMsg_oJ805KjA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_ZpKlnAGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X4SJ8SNX, 1, m, &cVar_X4SJ8SNX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_U875ji3I_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_0TqOcenL_sendMessage);
}

void Heavy_SoundScraper::cReceive_XzJGgUCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ouwKXvfr, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_7B8aCUh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rD1FgrpS_sendMessage(_c, 0, m);
  cMsg_FURk88ku_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_A2l63CYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cReceive_SZuPmLYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2iSadCDg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8cK3xhHB_sendMessage);
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
    __hv_varread_f(&sVarf_ycrCFRyr, VOf(Bf0));
    __hv_varread_f(&sVarf_15LJbtGD, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_zLskrljh, VOf(Bf0));
    __hv_rpole_f(&sRPole_5erl0O3i, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_ouwKXvfr, VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_kzAqhD4D, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_del1_f(&sDel1_0mbOSzS9, VIf(Bf2), VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_F9qbsRRX, VIf(ZERO), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_del1_f(&sDel1_UiYtJKlq, VIf(Bf2), VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_BvV0Kdcg, VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_fhR0eurG, VOf(Bf5));
    __hv_min_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_6cHL06Z7, VIi(Bi1), VOf(Bf6));
    __hv_tabread_if(&sTabread_gXemxlJn, VIi(Bi0), VOf(Bf7));
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
    __hv_del1_f(&sDel1_PIq2Q6oO, VIf(Bf4), VOf(Bf7));
    __hv_lt_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_samphold_f(&sSamphold_uLkDsfif, VIf(ZERO), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_del1_f(&sDel1_AJyGIeKd, VIf(Bf4), VOf(Bf7));
    __hv_lt_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_samphold_f(&sSamphold_i1o8zcrt, VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_aXEGBLzW, VOf(Bf9));
    __hv_min_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_sGmFShe2, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_dYnHV9Uq, VIi(Bi0), VOf(Bf5));
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
    __hv_varread_f(&sVarf_NRJeV8Mi, VOf(Bf10));
    __hv_rpole_f(&sRPole_elWUa40G, VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_GT6OdVIi, VIf(Bf10), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_tKsrHMxP, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_xm51otue, VOf(Bf0));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_Ax58MiOs, VOf(Bf10));
    __hv_varread_f(&sVarf_lUTpKDPn, VOf(Bf3));
    __hv_min_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_YNp8IIEx, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_WlYtYe97, VIi(Bi0), VOf(Bf8));
    __hv_sub_f(VIf(Bf5), VIf(Bf8), VOf(Bf5));
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_ahoDOIU8, VOf(Bf3));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_AWOvZvHv, VOf(Bf8));
    __hv_varread_f(&sVarf_67JIqCl7, VOf(Bf5));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_3Oe9ttxx, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_vZWrJGpE, VOf(Bf8));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_mgjVTqKC, VOf(Bf5));
    __hv_varread_f(&sVarf_CtDBqqUJ, VOf(Bf10));
    __hv_min_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_3eXZzuzi, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_AlK8zS2Z, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf9));
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_tYlQqpyr, VOf(Bf10));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_Pgz7rY0l, VOf(Bf2));
    __hv_varread_f(&sVarf_XnMFYCoH, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_fYRZYmYC, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_05eRgPab, VOf(Bf2));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_UqJ0OItO, VOf(Bf3));
    __hv_varread_f(&sVarf_QaEqDgic, VOf(Bf9));
    __hv_min_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_s9uAqArt, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_2xZgpS5z, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_4WEnB2xJ, VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_BoLoW5DV, VOf(Bf11));
    __hv_varread_f(&sVarf_r3rZgjy1, VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_X8UVgosI, VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_5mjgQ1RK, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_iSCeTc4t, VOf(Bf10));
    __hv_varread_f(&sVarf_p1s4kfxI, VOf(Bf5));
    __hv_min_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_yWgAUCjh, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_n1CZftWo, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf3), VIf(Bf7), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_SdVEGH4p, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_SUMTp9A5, VOf(Bf7));
    __hv_varread_f(&sVarf_SE2ZC0p6, VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_wLKjYKtF, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_kF24xNgR, VOf(Bf7));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_M7x71X3I, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_QX53BrJd, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf0));
    __hv_add_f(VIf(Bf11), VIf(Bf7), VOf(Bf11));
    __hv_line_f(&sLine_EZJEEblW, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_ukQ3KPzs, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_grGvWGq3, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_7i5MYA1m, VIf(Bf7));
    __hv_line_f(&sLine_l8yZ8PmG, VOf(Bf7));
    __hv_phasor_f(&sPhasor_32F1xt5U, VIf(Bf7), VOf(Bf7));
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
    __hv_line_f(&sLine_uOk1bftI, VOf(Bf4));
    __hv_line_f(&sLine_Nx7OK4nw, VOf(Bf11));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf11), VOf(Bf6));
    __hv_tabhead_f(&sTabhead_7J9nJ7Zx, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf3), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_qiJScZeT, VOf(Bf10));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_wPz3fdL5, VOf(Bf6));
    __hv_min_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf3));
    __hv_varread_f(&sVarf_1T2THY7r, VOf(Bf6));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_t3THQHvt, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_dMgCef6c, VIi(Bi0), VOf(Bf6));
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
    __hv_tabhead_f(&sTabhead_htUm7fHG, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_R4oHvD5Q, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_ygUmyTek, VOf(Bf11));
    __hv_min_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf7));
    __hv_varread_f(&sVarf_i795IZdH, VOf(Bf11));
    __hv_zero_f(VOf(Bf13));
    __hv_lt_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_and_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_cast_fi(VIf(Bf13), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_kqQskfmc, VIi(Bi1), VOf(Bf13));
    __hv_tabread_if(&sTabread_twivHhtS, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf13));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf13), VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_47HqzkJf, VOf(Bf6));
    __hv_tabhead_f(&sTabhead_6e3ywMhl, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf14), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_ZsaRIZxr, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_BQDCmbEw, VOf(Bf6));
    __hv_min_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf14));
    __hv_varread_f(&sVarf_rRRWoka6, VOf(Bf6));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_BIPVfW71, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_E0Z7RCIZ, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf7), VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_Hn0ZGoaR, VOf(Bf14));
    __hv_rpole_f(&sRPole_qjdpsafF, VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_jb4fyaqO, VIf(Bf14), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_WAaujEk5, VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_EJaCbrWF, VOf(Bf6));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf14));
    __hv_line_f(&sLine_A1gHAy57, VOf(Bf7));
    __hv_varread_f(&sVarf_eAzeWq1z, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_rFXlZCME, VOf(Bf6));
    __hv_rpole_f(&sRPole_9Qd1rBEc, VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_O7x1yznz, VIf(Bf6));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_tabread_f(&sTabread_Uy2K3pCf, VOf(Bf14));
    __hv_varread_f(&sVarf_V8uZMcez, VOf(Bf7));
    __hv_mul_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_Vi60KykZ, VOf(Bf11));
    __hv_rpole_f(&sRPole_99oqkByn, VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf11), VIf(Bf14), VOf(Bf11));
    __hv_line_f(&sLine_WWwnhSwT, VOf(Bf7));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_L0Mri4MD, VOf(Bf11));
    __hv_tabread_f(&sTabread_wUW8qMXA, VOf(Bf1));
    __hv_add_f(VIf(Bf5), VIf(Bf1), VOf(Bf13));
    __hv_tabread_f(&sTabread_4UhmKvR8, VOf(Bf4));
    __hv_add_f(VIf(Bf13), VIf(Bf4), VOf(Bf3));
    __hv_tabread_f(&sTabread_FvaD7CXE, VOf(Bf15));
    __hv_add_f(VIf(Bf3), VIf(Bf15), VOf(Bf12));
    __hv_tabread_f(&sTabread_LcaVlVgU, VOf(Bf9));
    __hv_add_f(VIf(Bf12), VIf(Bf9), VOf(Bf8));
    __hv_tabread_f(&sTabread_ggfxdbHw, VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_RBetVyja, VIf(Bf16));
    __hv_sub_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_Q8k3vA1z, VIf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_E5p68zQV, VIf(Bf15));
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_hCbNLFPd, VIf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_p8O038Oy, VIf(Bf1));
    __hv_tabwrite_f(&sTabwrite_fyfmrotI, VIf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_PsBaah8T, VOf(Bf8));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_qwJqadBw, VOf(Bf14));
    __hv_varread_f(&sVarf_VPtWp3dg, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_aA9uIeCY, VOf(Bf4));
    __hv_rpole_f(&sRPole_b6oaT5gP, VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf4), VIf(Bf14), VOf(Bf4));
    __hv_fma_f(VIf(Bf4), VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf14));
    __hv_tabread_f(&sTabread_u39yoezc, VOf(Bf4));
    __hv_varread_f(&sVarf_aMasXeyY, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_fXOfthC0, VOf(Bf13));
    __hv_rpole_f(&sRPole_6sLuhRiO, VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_tabread_f(&sTabread_tf6TMInt, VOf(Bf13));
    __hv_varread_f(&sVarf_rBmWDtRe, VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_M0Ov1nfT, VOf(Bf15));
    __hv_rpole_f(&sRPole_rNMzx741, VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf13), VOf(Bf15));
    __hv_fma_f(VIf(Bf15), VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf4), VIf(Bf11), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_GDROM89T, VIf(Bf7));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf15));
    __hv_add_f(VIf(Bf7), VIf(Bf15), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_mtYgfeBy, VIf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_S9gJQoGt, VIf(Bf13));
    __hv_sub_f(VIf(Bf7), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_75vpgRfb, VIf(Bf15));
    __hv_line_f(&sLine_I0C2aoof, VOf(Bf15));
    __hv_mul_f(VIf(Bf10), VIf(Bf15), VOf(Bf10));
    __hv_mul_f(VIf(Bf8), VIf(Bf15), VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf15), VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_RBcAbHIH, VOf(Bf15));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_ct1Wegjp, VIf(Bf5));
    __hv_line_f(&sLine_Ev0c8Aaf, VOf(Bf15));
    __hv_phasor_f(&sPhasor_ohnOaq85, VIf(Bf15), VOf(Bf15));
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
    __hv_line_f(&sLine_M9xlmo4f, VOf(Bf1));
    __hv_line_f(&sLine_YTT8XtFC, VOf(Bf4));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf4), VOf(Bf9));
    __hv_tabhead_f(&sTabhead_CH5E92Y0, VOf(Bf14));
    __hv_var_k_f_r(VOf(Bf13), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_mMzD57Sg, VOf(Bf14));
    __hv_mul_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_VdNxmPuz, VOf(Bf9));
    __hv_min_f(VIf(Bf14), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf13));
    __hv_varread_f(&sVarf_nVlwjyvd, VOf(Bf9));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_wGLauZoR, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_xmwc9cp1, VIi(Bi0), VOf(Bf9));
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
    __hv_tabhead_f(&sTabhead_hNjcgGe6, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_gEo7sCCx, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_ogkZbUw8, VOf(Bf4));
    __hv_min_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf15));
    __hv_varread_f(&sVarf_cgXsj42x, VOf(Bf4));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_FURDrYRZ, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_xFjUccNt, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf16), VIf(Bf4), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf16), VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_8zPLjoQc, VOf(Bf9));
    __hv_tabhead_f(&sTabhead_E83eOKwh, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_CO3ZVPnp, VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_be8xJBFC, VOf(Bf9));
    __hv_min_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf17));
    __hv_varread_f(&sVarf_6LKgDjQg, VOf(Bf9));
    __hv_zero_f(VOf(Bf15));
    __hv_lt_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_cast_fi(VIf(Bf15), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_1qccabZm, VIi(Bi1), VOf(Bf15));
    __hv_tabread_if(&sTabread_cF4y7FXx, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf15), VIf(Bf9), VOf(Bf15));
    __hv_sub_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf15), VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_8qtcMVtS, VOf(Bf17));
    __hv_rpole_f(&sRPole_JbVpK0oo, VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_8JgtlQvk, VIf(Bf17), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_DNyToRCo, VOf(Bf17));
    __hv_mul_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_spK6gjBk, VOf(Bf9));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf4), VIf(Bf9), VOf(Bf17));
    __hv_line_f(&sLine_LrVEa7hq, VOf(Bf15));
    __hv_varread_f(&sVarf_TTnqFH6X, VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_LZsKZ7dZ, VOf(Bf9));
    __hv_rpole_f(&sRPole_SIikIMkx, VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf4), VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_ZuEGUlfr, VIf(Bf9));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_W99TCZJQ, VOf(Bf17));
    __hv_varread_f(&sVarf_NGNUt5Ug, VOf(Bf9));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_GXfAEF6D, VOf(Bf9));
    __hv_min_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_eVXfaLfw, VOf(Bf15));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf5));
    __hv_varread_f(&sVarf_WabvFs7s, VOf(Bf9));
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
    __hv_cpole_f(&sCPole_VuTxgN9y, VIf(Bf9), VIf(ZERO), VIf(Bf4), VIf(Bf17), VOf(Bf17), VOf(Bf4));
    __hv_varread_f(&sVarf_GPWWp0o2, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_KvR0fcp4, VOf(Bf17));
    __hv_rpole_f(&sRPole_WLO0b9vP, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_ay4de1yY, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_v4Sidap8, VOf(Bf17));
    __hv_rpole_f(&sRPole_BpxZqe4j, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_jdt52v7I, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_BVPHV3Mp, VOf(Bf17));
    __hv_rpole_f(&sRPole_aHocSK0T, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_xx2RUEzx, VOf(Bf4));
    __hv_varread_f(&sVarf_UInjfCfV, VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_0SaaZjP1, VOf(Bf15));
    __hv_rpole_f(&sRPole_FhaSnsu8, VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf15));
    __hv_line_f(&sLine_sYRsyTvl, VOf(Bf9));
    __hv_fma_f(VIf(Bf15), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_Ad9WQWGw, VOf(Bf15));
    __hv_tabread_f(&sTabread_i0JcSFnt, VOf(Bf5));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf3));
    __hv_tabread_f(&sTabread_J2owhUk5, VOf(Bf16));
    __hv_add_f(VIf(Bf3), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_Brq6KY0F, VOf(Bf13));
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf18));
    __hv_tabread_f(&sTabread_njis9KQS, VOf(Bf12));
    __hv_add_f(VIf(Bf18), VIf(Bf12), VOf(Bf7));
    __hv_tabread_f(&sTabread_6O2xxiiV, VOf(Bf11));
    __hv_sub_f(VIf(Bf7), VIf(Bf11), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_gO0AoIZk, VIf(Bf14));
    __hv_sub_f(VIf(Bf18), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_HwGdZfuG, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_Unshn8w7, VIf(Bf13));
    __hv_sub_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_B1930N3N, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_EnuyWmm3, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_f8rBzpT0, VIf(Bf17));
    __hv_add_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_Smc2j305, VOf(Bf7));
    __hv_fma_f(VIf(Bf4), VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_B9pPbqux, VOf(Bf4));
    __hv_varread_f(&sVarf_hJolvPgs, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_EPam9V9c, VOf(Bf16));
    __hv_rpole_f(&sRPole_0Jgqd4qB, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf4), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf4), VIf(Bf15), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf11), VIf(Bf7), VOf(Bf4));
    __hv_tabread_f(&sTabread_pvtbGZJz, VOf(Bf16));
    __hv_varread_f(&sVarf_hWrKq9xo, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_8K8Duhci, VOf(Bf3));
    __hv_rpole_f(&sRPole_WAkwqGBu, VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf16), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf16));
    __hv_tabread_f(&sTabread_0Nwpu5zT, VOf(Bf3));
    __hv_varread_f(&sVarf_nFdICq5e, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_PA0Xp42U, VOf(Bf13));
    __hv_rpole_f(&sRPole_59lcMDyM, VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf3), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf16), VIf(Bf15), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_ZhrvGVHA, VIf(Bf9));
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf9));
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf13));
    __hv_add_f(VIf(Bf9), VIf(Bf13), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_N9z8Y0Wr, VIf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_yk4PCHwH, VIf(Bf3));
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_z1QlnVwa, VIf(Bf13));
    __hv_line_f(&sLine_0iVuKQiD, VOf(Bf13));
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
    __hv_line_f(&sLine_iMAvKVIb, VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf10));
    __hv_mul_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_0A2cf6G7, VOf(Bf2));
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

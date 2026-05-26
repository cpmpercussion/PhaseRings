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
  numBytes += sPhasor_k_init(&sPhasor_OHvna8xd, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_ANAXPbTF);
  numBytes += sPhasor_k_init(&sPhasor_sOanNndz, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_CQ6KitrP);
  numBytes += sLine_init(&sLine_joylSmui);
  numBytes += sLine_init(&sLine_8G7YlD6E);
  numBytes += sPhasor_k_init(&sPhasor_4XdVwZGx, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_2lHNZe7S);
  numBytes += sPhasor_k_init(&sPhasor_ZolYEEGx, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_atdJS5Fg);
  numBytes += sLine_init(&sLine_6m8TWZV9);
  numBytes += sLine_init(&sLine_XH4gVXQ1);
  numBytes += sPhasor_k_init(&sPhasor_QE5CoEJC, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_PZxgQ4vv);
  numBytes += sPhasor_k_init(&sPhasor_Ws99x1Vb, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_3JzKuFzn);
  numBytes += sLine_init(&sLine_W9zwNLeY);
  numBytes += sLine_init(&sLine_iDc9BMa0);
  numBytes += sPhasor_k_init(&sPhasor_kAUPrDFI, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_AAlfaxyd);
  numBytes += sPhasor_k_init(&sPhasor_92im5H1J, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_jiu98xgY);
  numBytes += sLine_init(&sLine_tFaKUTQ1);
  numBytes += sLine_init(&sLine_jdBRTLys);
  numBytes += sLine_init(&sLine_0i6WrGJS);
  numBytes += sLine_init(&sLine_9EgVUUQA);
  numBytes += sPhasor_init(&sPhasor_kOSMOFiw, sampleRate);
  numBytes += sLine_init(&sLine_AdIVMSVN);
  numBytes += sPhasor_k_init(&sPhasor_QiBGcMM7, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_CkCYmdco);
  numBytes += sLine_init(&sLine_X2lphywz);
  numBytes += sRPole_init(&sRPole_tO99yYz4);
  numBytes += sDel1_init(&sDel1_AGOAwoLv);
  numBytes += sLine_init(&sLine_lZ7zgSzw);
  numBytes += sLine_init(&sLine_pkRaBx80);
  numBytes += sLine_init(&sLine_a3969af3);
  numBytes += sTabread_init(&sTabread_ZggRA7SG, &hTable_y1MeZAkG, true);
  numBytes += sRPole_init(&sRPole_KRYOr11w);
  numBytes += sLine_init(&sLine_9PeTh1xu);
  numBytes += sLine_init(&sLine_hqq5T9bD);
  numBytes += sTabread_init(&sTabread_aSfpeIZ0, &hTable_q9Y5tQmo, true);
  numBytes += sTabread_init(&sTabread_vmArbZ7O, &hTable_ESGkFV4S, true);
  numBytes += sTabread_init(&sTabread_MjvOKsH4, &hTable_usOFQLK0, true);
  numBytes += sTabread_init(&sTabread_hfYqkB9J, &hTable_EAyjGHbb, true);
  numBytes += sTabread_init(&sTabread_Jc6umH7j, &hTable_SQbnfU0T, true);
  numBytes += sTabwrite_init(&sTabwrite_fAgtdIR4, &hTable_zb1j4ZzD);
  numBytes += sTabwrite_init(&sTabwrite_2XqCi3im, &hTable_SQbnfU0T);
  numBytes += sTabwrite_init(&sTabwrite_G0xOtQci, &hTable_EAyjGHbb);
  numBytes += sTabwrite_init(&sTabwrite_AHXOGdjc, &hTable_usOFQLK0);
  numBytes += sTabwrite_init(&sTabwrite_N6QpS2QX, &hTable_ESGkFV4S);
  numBytes += sTabwrite_init(&sTabwrite_7m4vRAFI, &hTable_q9Y5tQmo);
  numBytes += sTabread_init(&sTabread_vcfVl5kT, &hTable_zb1j4ZzD, true);
  numBytes += sTabread_init(&sTabread_9OrIB1ve, &hTable_yigFpQR5, true);
  numBytes += sRPole_init(&sRPole_th6oNTP6);
  numBytes += sTabread_init(&sTabread_oL3oXAzL, &hTable_ZxLjdfs4, true);
  numBytes += sRPole_init(&sRPole_5pvLm6CJ);
  numBytes += sTabread_init(&sTabread_QkcD7kLi, &hTable_oqNTpXpC, true);
  numBytes += sRPole_init(&sRPole_4cw6x8fy);
  numBytes += sTabwrite_init(&sTabwrite_2LT0CmVD, &hTable_y1MeZAkG);
  numBytes += sTabwrite_init(&sTabwrite_oOFBrGBM, &hTable_yigFpQR5);
  numBytes += sTabwrite_init(&sTabwrite_UHLTxjB1, &hTable_ZxLjdfs4);
  numBytes += sTabwrite_init(&sTabwrite_rDLu65vc, &hTable_oqNTpXpC);
  numBytes += sLine_init(&sLine_uczCl8Bb);
  numBytes += sLine_init(&sLine_11F9nC2y);
  numBytes += sTabwrite_init(&sTabwrite_NNNHp52Y, &hTable_3MB9R521);
  numBytes += sLine_init(&sLine_ra2t3iLt);
  numBytes += sPhasor_init(&sPhasor_VjQFrNUs, sampleRate);
  numBytes += sLine_init(&sLine_znxv5TKK);
  numBytes += sLine_init(&sLine_m7UoZwKy);
  numBytes += sTabhead_init(&sTabhead_Ir3fgzsS, &hTable_3MB9R521);
  numBytes += sTabread_init(&sTabread_qo88IZXw, &hTable_3MB9R521, false);
  numBytes += sTabread_init(&sTabread_sbTiUdTK, &hTable_3MB9R521, false);
  numBytes += sTabhead_init(&sTabhead_rZ9FNpNx, &hTable_3MB9R521);
  numBytes += sTabread_init(&sTabread_MIydgMei, &hTable_3MB9R521, false);
  numBytes += sTabread_init(&sTabread_7lCwCbsB, &hTable_3MB9R521, false);
  numBytes += sTabhead_init(&sTabhead_GPC5HALu, &hTable_T9jAKNOt);
  numBytes += sTabread_init(&sTabread_jlLWdWEq, &hTable_T9jAKNOt, false);
  numBytes += sTabread_init(&sTabread_mFehtGPf, &hTable_T9jAKNOt, false);
  numBytes += sRPole_init(&sRPole_ZbaGCCYH);
  numBytes += sDel1_init(&sDel1_uFpPVIsl);
  numBytes += sLine_init(&sLine_DinFcQxm);
  numBytes += sRPole_init(&sRPole_18Kud4jJ);
  numBytes += sTabwrite_init(&sTabwrite_tO3dLHQB, &hTable_T9jAKNOt);
  numBytes += sCPole_init(&sCPole_b45m8lnX);
  numBytes += sRPole_init(&sRPole_CSJ1RoMW);
  numBytes += sRPole_init(&sRPole_94lHuSv4);
  numBytes += sRPole_init(&sRPole_tO5wkHAm);
  numBytes += sTabread_init(&sTabread_PXyDu9RO, &hTable_5ioMphG8, true);
  numBytes += sRPole_init(&sRPole_XOU7T7r0);
  numBytes += sLine_init(&sLine_zo3ZvJuV);
  numBytes += sLine_init(&sLine_gsHEdUib);
  numBytes += sTabread_init(&sTabread_JO88ZHSN, &hTable_PavbqHbh, true);
  numBytes += sTabread_init(&sTabread_1BtsQpNq, &hTable_1wru8MHW, true);
  numBytes += sTabread_init(&sTabread_XHsUMFug, &hTable_vh7RD3Lg, true);
  numBytes += sTabread_init(&sTabread_f4mOLfF2, &hTable_Kk9ndx4m, true);
  numBytes += sTabread_init(&sTabread_DaGuuQMZ, &hTable_6TQwTNEC, true);
  numBytes += sTabwrite_init(&sTabwrite_GCCTafgW, &hTable_bbTFkl2o);
  numBytes += sTabwrite_init(&sTabwrite_sMxLbsQB, &hTable_6TQwTNEC);
  numBytes += sTabwrite_init(&sTabwrite_RR0X2HCm, &hTable_Kk9ndx4m);
  numBytes += sTabwrite_init(&sTabwrite_t0iQBUbP, &hTable_vh7RD3Lg);
  numBytes += sTabwrite_init(&sTabwrite_tfNspXeb, &hTable_1wru8MHW);
  numBytes += sTabwrite_init(&sTabwrite_TNUGkcbb, &hTable_PavbqHbh);
  numBytes += sTabread_init(&sTabread_JmFOVfVI, &hTable_bbTFkl2o, true);
  numBytes += sTabread_init(&sTabread_flr2zEpX, &hTable_RW3zd5nF, true);
  numBytes += sRPole_init(&sRPole_LZPkfJj5);
  numBytes += sTabread_init(&sTabread_XWgTHeQf, &hTable_a8GDILoc, true);
  numBytes += sRPole_init(&sRPole_RzfG4IYL);
  numBytes += sTabread_init(&sTabread_tkvhO79D, &hTable_M2AxBj05, true);
  numBytes += sRPole_init(&sRPole_xSpAzXc7);
  numBytes += sTabwrite_init(&sTabwrite_0DYm3TJV, &hTable_5ioMphG8);
  numBytes += sTabwrite_init(&sTabwrite_hNA8U5MH, &hTable_RW3zd5nF);
  numBytes += sTabwrite_init(&sTabwrite_CL1NrIq1, &hTable_a8GDILoc);
  numBytes += sTabwrite_init(&sTabwrite_nwjshKbH, &hTable_M2AxBj05);
  numBytes += sLine_init(&sLine_BWCIt3KP);
  numBytes += sLine_init(&sLine_t3Uzaxmb);
  numBytes += sTabwrite_init(&sTabwrite_tnd0hLZl, &hTable_7GuvTMSA);
  numBytes += sLine_init(&sLine_LOsz3tmd);
  numBytes += sPhasor_init(&sPhasor_K4gw19Pv, sampleRate);
  numBytes += sLine_init(&sLine_RxSDlkHs);
  numBytes += sLine_init(&sLine_dgmmG0t8);
  numBytes += sTabhead_init(&sTabhead_SmYrbpBM, &hTable_7GuvTMSA);
  numBytes += sTabread_init(&sTabread_0K71SMO4, &hTable_7GuvTMSA, false);
  numBytes += sTabread_init(&sTabread_EbVmp8J3, &hTable_7GuvTMSA, false);
  numBytes += sTabhead_init(&sTabhead_yG1WKB2f, &hTable_7GuvTMSA);
  numBytes += sTabread_init(&sTabread_xYP1PdmQ, &hTable_7GuvTMSA, false);
  numBytes += sTabread_init(&sTabread_eK4hUs6O, &hTable_7GuvTMSA, false);
  numBytes += sTabhead_init(&sTabhead_ZkYou3SO, &hTable_BRVG0Edd);
  numBytes += sTabread_init(&sTabread_5Qza54DK, &hTable_BRVG0Edd, false);
  numBytes += sTabread_init(&sTabread_ov3xDB6f, &hTable_BRVG0Edd, false);
  numBytes += sRPole_init(&sRPole_dFKIJdij);
  numBytes += sDel1_init(&sDel1_lELfXtI3);
  numBytes += sLine_init(&sLine_dvxg473t);
  numBytes += sRPole_init(&sRPole_F7mx2iYS);
  numBytes += sTabwrite_init(&sTabwrite_dNzPEqGw, &hTable_BRVG0Edd);
  numBytes += sLine_init(&sLine_rMs0vHVo);
  numBytes += sLine_init(&sLine_Y7iZe6LJ);
  numBytes += cSlice_init(&cSlice_2oyQdFcN, 2, 1);
  numBytes += cSlice_init(&cSlice_tX1hGAss, 1, 1);
  numBytes += cSlice_init(&cSlice_xuJ9oz5l, 0, 1);
  numBytes += cVar_init_f(&cVar_tfkrxusq, 0.0f);
  numBytes += cIf_init(&cIf_lBJINygR, false);
  numBytes += cIf_init(&cIf_Gsug0npx, false);
  numBytes += cIf_init(&cIf_HUOukaLS, false);
  numBytes += cIf_init(&cIf_39Bm0yUK, false);
  numBytes += cIf_init(&cIf_tKvytw7H, false);
  numBytes += cBinop_init(&cBinop_Ra0rbDtN, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_VQsXEwP5, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_mCTN3Dzg, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_fZPigCv4, 5.0f);
  numBytes += cBinop_init(&cBinop_tYARirDf, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_aY444rQY, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_a8gY6we0, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_yuHpy6hF, "floatatom");
  numBytes += cVar_init_s(&cVar_3b8EmXBc, "floatatom");
  numBytes += cIf_init(&cIf_CNr6rz7z, false);
  numBytes += cIf_init(&cIf_F3SkYADp, false);
  numBytes += cIf_init(&cIf_06ote1vU, false);
  numBytes += cIf_init(&cIf_qEc55J7O, false);
  numBytes += cPack_init(&cPack_3W1w5ygR, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_M8pqQz9i, 2, 0.0f, 80.0f);
  numBytes += cPack_init(&cPack_l0NchqdR, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_3AdDP3qQ, 1493569608);
  numBytes += cSlice_init(&cSlice_8p6foZ8N, 1, 1);
  numBytes += cVar_init_s(&cVar_kzg536HY, "floatatom");
  numBytes += cRandom_init(&cRandom_S5WVvOVd, 1738294212);
  numBytes += cSlice_init(&cSlice_x0uBtTM9, 1, 1);
  numBytes += cVar_init_s(&cVar_DUjak1ss, "floatatom");
  numBytes += cVar_init_f(&cVar_udKML2px, 1.0f);
  numBytes += cVar_init_f(&cVar_fspRBm1w, 0.0f);
  numBytes += cVar_init_f(&cVar_eLswbPGf, 0.0f);
  numBytes += cRandom_init(&cRandom_ZVW3RdFd, -1318019603);
  numBytes += cSlice_init(&cSlice_oL8ldI27, 1, 1);
  numBytes += cRandom_init(&cRandom_Whe0zFdc, 1099007245);
  numBytes += cSlice_init(&cSlice_MCSQPpqm, 1, 1);
  numBytes += cRandom_init(&cRandom_T6aNSyhw, 152783285);
  numBytes += cSlice_init(&cSlice_UZ8V0srQ, 1, 1);
  numBytes += cBinop_init(&cBinop_Vwn1AXLn, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_xII7mQfR, 1468096707);
  numBytes += cSlice_init(&cSlice_joJ9ric1, 1, 1);
  numBytes += cPack_init(&cPack_lhMufdE7, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_YbkcH7vs, "floatatom");
  numBytes += cVar_init_s(&cVar_HJ3kqbgo, "floatatom");
  numBytes += cVar_init_s(&cVar_f6n2VHgC, "floatatom");
  numBytes += cVar_init_f(&cVar_WUAMruOx, 0.0f);
  numBytes += cVar_init_s(&cVar_XXHVOvgh, "floatatom");
  numBytes += cVar_init_s(&cVar_Qs1lsJhA, "floatatom");
  numBytes += cVar_init_s(&cVar_oZtNQz54, "floatatom");
  numBytes += cDelay_init(this, &cDelay_qHRI3QgK, 25.0f);
  numBytes += cVar_init_f(&cVar_IfhE7iy3, 0.0f);
  numBytes += sVarf_init(&sVarf_mjhR6lcz, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_AJHNDtyX, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_F5tPvQRz, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_6GOdge2Y, 1, 1);
  numBytes += cSlice_init(&cSlice_2lqEEzGp, 0, 1);
  numBytes += cBinop_init(&cBinop_KmiEs60q, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_9KbWwkEh, 98.0f);
  numBytes += cIf_init(&cIf_09s2cu00, false);
  numBytes += cBinop_init(&cBinop_I1amgWX4, 0.0f); // __pow
  numBytes += cPack_init(&cPack_gKbAVDl8, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_DGYNmb7R, 0.0f);
  numBytes += cRandom_init(&cRandom_6pC19TVI, -1229318560);
  numBytes += cSlice_init(&cSlice_5v2mEr9D, 1, 1);
  numBytes += cBinop_init(&cBinop_QjjS4yPR, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_DL3f9JCw, -2130114452);
  numBytes += cSlice_init(&cSlice_Kt4IdsDL, 1, 1);
  numBytes += cPack_init(&cPack_urDhOzsa, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_qVnsr15i, "floatatom");
  numBytes += cVar_init_s(&cVar_FumicZVE, "floatatom");
  numBytes += cVar_init_s(&cVar_9zqIzjd8, "floatatom");
  numBytes += cVar_init_f(&cVar_kX3NH6kf, 0.0f);
  numBytes += cVar_init_s(&cVar_BUICChbe, "floatatom");
  numBytes += cVar_init_s(&cVar_AmIqoQeM, "floatatom");
  numBytes += cVar_init_s(&cVar_ZI1KbELp, "floatatom");
  numBytes += cDelay_init(this, &cDelay_rrSTtoo2, 25.0f);
  numBytes += cVar_init_f(&cVar_FBsE2Zn0, 0.0f);
  numBytes += sVarf_init(&sVarf_zNXHzklq, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_5APBNPUX, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_3RKZFYe6, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_ulfDVX9H, 1, 1);
  numBytes += cSlice_init(&cSlice_OQFhrboO, 0, 1);
  numBytes += cBinop_init(&cBinop_3bosWtYg, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_4wBiVbHq, 922021644);
  numBytes += cSlice_init(&cSlice_HKeY9tmf, 1, 1);
  numBytes += cBinop_init(&cBinop_fmzaWCDf, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_SQzJ3ALU, 1325411588);
  numBytes += cSlice_init(&cSlice_yLDhKY2W, 1, 1);
  numBytes += cPack_init(&cPack_9YGrzVqQ, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_4ytsUVfy, "floatatom");
  numBytes += cVar_init_s(&cVar_4nuv8CIp, "floatatom");
  numBytes += cVar_init_s(&cVar_GzBwM73L, "floatatom");
  numBytes += cVar_init_f(&cVar_hshT62i2, 0.0f);
  numBytes += cVar_init_s(&cVar_7TesBYpa, "floatatom");
  numBytes += cVar_init_s(&cVar_7FDqAdTM, "floatatom");
  numBytes += cVar_init_s(&cVar_n4r7QlB4, "floatatom");
  numBytes += cDelay_init(this, &cDelay_TGkQ4UaQ, 25.0f);
  numBytes += cVar_init_f(&cVar_RsRVvDso, 0.0f);
  numBytes += sVarf_init(&sVarf_rtoHHS8W, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_Xjx4MR0z, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_Qjbcz811, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_jrRvuiG1, 1, 1);
  numBytes += cSlice_init(&cSlice_ycmGfEiE, 0, 1);
  numBytes += cBinop_init(&cBinop_BrIJR0G5, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_mUjLz6ri, -625787376);
  numBytes += cSlice_init(&cSlice_UPp5RqqQ, 1, 1);
  numBytes += cBinop_init(&cBinop_bCn7425k, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_gSdLACQ0, -145004182);
  numBytes += cSlice_init(&cSlice_IoR4twpE, 1, 1);
  numBytes += cPack_init(&cPack_LuSlkY39, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_mX9qHu8O, "floatatom");
  numBytes += cVar_init_s(&cVar_ihIMxsS6, "floatatom");
  numBytes += cVar_init_s(&cVar_JkJAE8Y7, "floatatom");
  numBytes += cVar_init_f(&cVar_8LikXWEL, 0.0f);
  numBytes += cVar_init_s(&cVar_1Kf2iKJO, "floatatom");
  numBytes += cVar_init_s(&cVar_bws95Xck, "floatatom");
  numBytes += cVar_init_s(&cVar_4HXd6OpD, "floatatom");
  numBytes += cDelay_init(this, &cDelay_IgWx7hOq, 25.0f);
  numBytes += cVar_init_f(&cVar_a0C5t57D, 0.0f);
  numBytes += sVarf_init(&sVarf_4IEbLrSU, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_qo3rLzyF, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_vXO1Y0w5, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_qF8NwXkf, 1, 1);
  numBytes += cSlice_init(&cSlice_Yux3D6Rp, 0, 1);
  numBytes += cBinop_init(&cBinop_sKFclUIO, 1.0f); // __mul
  numBytes += cTabhead_init(&cTabhead_BYgux5Oq, &hTable_y1MeZAkG);
  numBytes += cVar_init_s(&cVar_GEdf6bpL, "del-1209-del1");
  numBytes += cDelay_init(this, &cDelay_hgT3NW6r, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_IBidMiKv, 0.0f);
  numBytes += cBinop_init(&cBinop_O45KNWag, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_QTZ8M9xp, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eKZnIbVg, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ZkzYmhCP, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_6K2XfYQA, &hTable_yigFpQR5);
  numBytes += cVar_init_s(&cVar_kVzlv21K, "del-1209-del2");
  numBytes += cDelay_init(this, &cDelay_0eWO4dtB, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_bodLRQnp, 0.0f);
  numBytes += cBinop_init(&cBinop_f18bIhPM, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_Nosz5xHw, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_0Hlv3E3N, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_s1zHoFGI, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_WySMg7df, &hTable_ZxLjdfs4);
  numBytes += cVar_init_s(&cVar_2wGQoAAH, "del-1209-del3");
  numBytes += cDelay_init(this, &cDelay_3gynYtVx, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_4Jp2AHes, 0.0f);
  numBytes += cBinop_init(&cBinop_DX4rPrzK, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_Fw85Oy8a, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Z2d0c0oU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_bBwkbdfA, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_FgFI6c4S, &hTable_oqNTpXpC);
  numBytes += cVar_init_s(&cVar_TtrsrRUz, "del-1209-del4");
  numBytes += cDelay_init(this, &cDelay_izGum2nb, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_XQGrskAa, 0.0f);
  numBytes += cBinop_init(&cBinop_NemRpaIO, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_2u6FhgjV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eZbJNWdR, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_aYyvgtUe, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Sf9xbtun, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rut3Wyf9, 0.0f);
  numBytes += hTable_init(&hTable_y1MeZAkG, 256);
  numBytes += cDelay_init(this, &cDelay_bXWugKGV, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kPlAJNHX, 0.0f);
  numBytes += hTable_init(&hTable_yigFpQR5, 256);
  numBytes += cDelay_init(this, &cDelay_ymEt5vAC, 0.0f);
  numBytes += cDelay_init(this, &cDelay_SaZyNKPa, 0.0f);
  numBytes += hTable_init(&hTable_ZxLjdfs4, 256);
  numBytes += cDelay_init(this, &cDelay_OY4hgbW5, 0.0f);
  numBytes += cDelay_init(this, &cDelay_LwkCRlrs, 0.0f);
  numBytes += hTable_init(&hTable_oqNTpXpC, 256);
  numBytes += cIf_init(&cIf_nxG0vYAO, false);
  numBytes += cBinop_init(&cBinop_M8GTCZXo, 0.0f); // __pow
  numBytes += cPack_init(&cPack_3AWggFEO, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_3r0DAcAE, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_wDbWzIo5, 22050.0f);
  numBytes += cBinop_init(&cBinop_ii2zWj5D, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Wi3Pu2Va, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_O2HDUS1L, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iptQFL2n, 95.0f);
  numBytes += cVar_init_f(&cVar_b1EcaFfL, 90.0f);
  numBytes += cVar_init_f(&cVar_i23Hm69o, 6000.0f);
  numBytes += cVar_init_f(&cVar_qDBY6K7j, 60.0f);
  numBytes += cIf_init(&cIf_HBCc6rVn, false);
  numBytes += cTabhead_init(&cTabhead_LXChfygy, &hTable_zb1j4ZzD);
  numBytes += cVar_init_s(&cVar_cEXPc9kM, "del-1209-ref6");
  numBytes += cDelay_init(this, &cDelay_zJATlGww, 13.645f);
  numBytes += cDelay_init(this, &cDelay_BZHBFkW6, 0.0f);
  numBytes += cBinop_init(&cBinop_cRYIaxcp, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_vv26S1sg, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_SVyw6Qgd, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_KyCYslyP, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_rvsMNb54, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3V59cZIB, 0.0f);
  numBytes += hTable_init(&hTable_zb1j4ZzD, 256);
  numBytes += cTabhead_init(&cTabhead_ggO7hi4g, &hTable_SQbnfU0T);
  numBytes += cVar_init_s(&cVar_mJ0OorsZ, "del-1209-ref5");
  numBytes += cDelay_init(this, &cDelay_Anzcazll, 16.364f);
  numBytes += cDelay_init(this, &cDelay_bqeEH4DY, 0.0f);
  numBytes += cBinop_init(&cBinop_n4WUtnTv, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_xEvw6OBE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_RIuZIUXv, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_JOK63hrr, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_pUkbWCoB, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ZuI8pMie, 0.0f);
  numBytes += hTable_init(&hTable_SQbnfU0T, 256);
  numBytes += cTabhead_init(&cTabhead_udg83ApF, &hTable_EAyjGHbb);
  numBytes += cVar_init_s(&cVar_Gwt1SnHS, "del-1209-ref4");
  numBytes += cDelay_init(this, &cDelay_FvDlChTZ, 19.392f);
  numBytes += cDelay_init(this, &cDelay_wcLoSYT4, 0.0f);
  numBytes += cBinop_init(&cBinop_QQf1nRhb, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_E6BfF2qa, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9RhtbeH4, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_JsL97K5f, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_NZTHSGjx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cuvfTpcL, 0.0f);
  numBytes += hTable_init(&hTable_EAyjGHbb, 256);
  numBytes += cTabhead_init(&cTabhead_YKHEZJwr, &hTable_usOFQLK0);
  numBytes += cVar_init_s(&cVar_RBftZ2Bb, "del-1209-ref3");
  numBytes += cDelay_init(this, &cDelay_JThtMW5N, 25.796f);
  numBytes += cDelay_init(this, &cDelay_lryKgDks, 0.0f);
  numBytes += cBinop_init(&cBinop_izXiUbcQ, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_yzmlC2hh, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_a7UdzStv, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_EnifgKdV, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_vtmqkqXf, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TmZZs2UG, 0.0f);
  numBytes += hTable_init(&hTable_usOFQLK0, 256);
  numBytes += cTabhead_init(&cTabhead_TOKDBC1h, &hTable_ESGkFV4S);
  numBytes += cVar_init_s(&cVar_KNKreDi4, "del-1209-ref2");
  numBytes += cDelay_init(this, &cDelay_dEWsQpeX, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_nv5UMYvg, 0.0f);
  numBytes += cBinop_init(&cBinop_f9icJ1ME, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_YCvdQHEE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_sY2qTzQ4, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_AjE6Iafk, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_OlSSbLWC, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2joOFbZo, 0.0f);
  numBytes += hTable_init(&hTable_ESGkFV4S, 256);
  numBytes += cTabhead_init(&cTabhead_gfjZHwzk, &hTable_q9Y5tQmo);
  numBytes += cVar_init_s(&cVar_JjLZDyxy, "del-1209-ref1");
  numBytes += cDelay_init(this, &cDelay_vTOOvAEb, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_nRRssa8x, 0.0f);
  numBytes += cBinop_init(&cBinop_J8fVevAF, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_lqDGvsWQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_4OPIvG2F, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_iNAjqnLt, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_T3krYsxd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XchXaKTx, 0.0f);
  numBytes += hTable_init(&hTable_q9Y5tQmo, 256);
  numBytes += cVar_init_f(&cVar_2OBOFhSR, 0.0f);
  numBytes += cVar_init_f(&cVar_aAxVeNc5, 0.0f);
  numBytes += cPack_init(&cPack_Is1pAcj0, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_YLkeXdUk, 22050.0f);
  numBytes += cBinop_init(&cBinop_QLbDGXFm, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_FWoONJ3y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oUVcobdg, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_T04K6Uie, 22050.0f);
  numBytes += cBinop_init(&cBinop_ZCM1X2Vh, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_qZtS7PNG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GPiYUsYW, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_feJloJKb, 22050.0f);
  numBytes += cBinop_init(&cBinop_oezJlZH1, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Px7mloIV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tRl2p4MC, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_l2IUnkog, false);
  numBytes += cDelay_init(this, &cDelay_wMlynhaG, 50.0f);
  numBytes += cVar_init_f(&cVar_aHWjUdmj, 0.0f);
  numBytes += cVar_init_f(&cVar_5FMJR5Jq, 12.0f);
  numBytes += cVar_init_s(&cVar_FK7oAEXk, "floatatom");
  numBytes += cPack_init(&cPack_JfnhsHEM, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_C9iKp8bl, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_THhh7Y18, "floatatom");
  numBytes += cDelay_init(this, &cDelay_Xca23ZRy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_K9B2wZ7E, 0.0f);
  numBytes += hTable_init(&hTable_3MB9R521, 256);
  numBytes += cVar_init_s(&cVar_jgKpSud8, "del-1316-del");
  numBytes += sVarf_init(&sVarf_l4sLowaT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZB32bdQj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cYA0F3X4, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_CH6ToqHl, "del-1316-del");
  numBytes += sVarf_init(&sVarf_X2sBVcX1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fP53xb6r, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_M4ZiY05L, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_U2aT025m, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_tBrgNhqW, 4720.0f);
  numBytes += cBinop_init(&cBinop_fCsXl3J0, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_csx4kkkj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vMGE5MHf, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_a8cm4Ru2, 4720.0f);
  numBytes += cBinop_init(&cBinop_BmBRUCWQ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_p5ETkzlj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uzb0pbpk, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_XtibPGgI, 4720.0f);
  numBytes += cBinop_init(&cBinop_iU7XPlfE, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_GZr2zu12, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nnyHuAJH, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ths80PqV, 1.0f);
  numBytes += cIf_init(&cIf_3ko6GJxo, false);
  numBytes += sVarf_init(&sVarf_Zdg4sOPP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZdWfz8f6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FZirLyJW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_E3fPsydy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TdL6ZguY, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_EHXlnLo5, &hTable_5ioMphG8);
  numBytes += cVar_init_s(&cVar_lEjLV3Ym, "del-1379-del1");
  numBytes += cDelay_init(this, &cDelay_NQGZA977, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_bR7FqG9C, 0.0f);
  numBytes += cBinop_init(&cBinop_HxzDBnxq, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_354Kspg7, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6LcBPG5y, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_WPHUBC8y, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_wJo875kz, &hTable_RW3zd5nF);
  numBytes += cVar_init_s(&cVar_1t1QHggq, "del-1379-del2");
  numBytes += cDelay_init(this, &cDelay_3AbXEH01, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_V3hcXL8A, 0.0f);
  numBytes += cBinop_init(&cBinop_Xc3rAzSr, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_xyAXwb4O, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_0nUOCHZL, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NC6umlQj, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_uMseitWH, &hTable_a8GDILoc);
  numBytes += cVar_init_s(&cVar_Q876LdX3, "del-1379-del3");
  numBytes += cDelay_init(this, &cDelay_htUJXMF6, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_zR3zevyN, 0.0f);
  numBytes += cBinop_init(&cBinop_iQMcQev3, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_Lvs0MGei, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_clmYgYaa, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_3S3Yk7W2, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_G9yt3Hww, &hTable_M2AxBj05);
  numBytes += cVar_init_s(&cVar_MrcEnfDs, "del-1379-del4");
  numBytes += cDelay_init(this, &cDelay_Ly1VcRQj, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_Qz6rf7IW, 0.0f);
  numBytes += cBinop_init(&cBinop_VoMKxmdl, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_9RMod5mw, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_UNkutTaK, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_poOmSGf6, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_aa4Pno8v, 0.0f);
  numBytes += cDelay_init(this, &cDelay_b1Nt1EnY, 0.0f);
  numBytes += hTable_init(&hTable_5ioMphG8, 256);
  numBytes += cDelay_init(this, &cDelay_XqT4VSRt, 0.0f);
  numBytes += cDelay_init(this, &cDelay_hQJrnsx8, 0.0f);
  numBytes += hTable_init(&hTable_RW3zd5nF, 256);
  numBytes += cDelay_init(this, &cDelay_CjlsgyoY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_D0vGZPm7, 0.0f);
  numBytes += hTable_init(&hTable_a8GDILoc, 256);
  numBytes += cDelay_init(this, &cDelay_G7K1QHJe, 0.0f);
  numBytes += cDelay_init(this, &cDelay_NHxsGGxW, 0.0f);
  numBytes += hTable_init(&hTable_M2AxBj05, 256);
  numBytes += cIf_init(&cIf_MMZrngKC, false);
  numBytes += cBinop_init(&cBinop_P0jJNQmP, 0.0f); // __pow
  numBytes += cPack_init(&cPack_rEYD88aI, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_FIz5w5G4, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_5LMTsEU1, 22050.0f);
  numBytes += cBinop_init(&cBinop_MusqmsQq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ANKhHPoX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mM61I41T, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_rANLmejJ, 100.0f);
  numBytes += cVar_init_f(&cVar_Ywmnnyys, 95.0f);
  numBytes += cVar_init_f(&cVar_jR1PMCeb, 14400.0f);
  numBytes += cVar_init_f(&cVar_N5qZjaMz, 60.0f);
  numBytes += cIf_init(&cIf_Mex5YPg8, false);
  numBytes += cTabhead_init(&cTabhead_8l89wQDU, &hTable_bbTFkl2o);
  numBytes += cVar_init_s(&cVar_dnqkOPaL, "del-1379-ref6");
  numBytes += cDelay_init(this, &cDelay_iQHl1VdU, 13.645f);
  numBytes += cDelay_init(this, &cDelay_ljnKCDim, 0.0f);
  numBytes += cBinop_init(&cBinop_8iKqQeVt, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_aWyTqvEo, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_MhLjqBPt, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_jtCgEiHH, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ubuhKJZJ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WzECrtFb, 0.0f);
  numBytes += hTable_init(&hTable_bbTFkl2o, 256);
  numBytes += cTabhead_init(&cTabhead_1WKT09kq, &hTable_6TQwTNEC);
  numBytes += cVar_init_s(&cVar_0tS7ik3A, "del-1379-ref5");
  numBytes += cDelay_init(this, &cDelay_3xD5TCeA, 16.364f);
  numBytes += cDelay_init(this, &cDelay_yLJ0kKUF, 0.0f);
  numBytes += cBinop_init(&cBinop_OqKX8tU1, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_FJh9NdKz, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_sg5hXio5, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_czo0shkj, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ODlXItyk, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8aynC0x0, 0.0f);
  numBytes += hTable_init(&hTable_6TQwTNEC, 256);
  numBytes += cTabhead_init(&cTabhead_f5cUl7Xf, &hTable_Kk9ndx4m);
  numBytes += cVar_init_s(&cVar_2zIVBgYl, "del-1379-ref4");
  numBytes += cDelay_init(this, &cDelay_K3z66y12, 19.392f);
  numBytes += cDelay_init(this, &cDelay_9vKHsOxt, 0.0f);
  numBytes += cBinop_init(&cBinop_9o9vVh51, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_okVqhnt3, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cNlr4xnw, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_56TYM670, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_sD1QqS0v, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DmmVHF9R, 0.0f);
  numBytes += hTable_init(&hTable_Kk9ndx4m, 256);
  numBytes += cTabhead_init(&cTabhead_mzetk4Vv, &hTable_vh7RD3Lg);
  numBytes += cVar_init_s(&cVar_hHWxpwwe, "del-1379-ref3");
  numBytes += cDelay_init(this, &cDelay_ngMrLHA1, 25.796f);
  numBytes += cDelay_init(this, &cDelay_aqm2r4JH, 0.0f);
  numBytes += cBinop_init(&cBinop_FCT697CN, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_cx4OtOSE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_sbrQ4hCX, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_R5U2N8wq, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_mokxzJXS, 0.0f);
  numBytes += cDelay_init(this, &cDelay_qdlnubbr, 0.0f);
  numBytes += hTable_init(&hTable_vh7RD3Lg, 256);
  numBytes += cTabhead_init(&cTabhead_rERg4Liv, &hTable_1wru8MHW);
  numBytes += cVar_init_s(&cVar_dYNNhLpj, "del-1379-ref2");
  numBytes += cDelay_init(this, &cDelay_93wShjTF, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_okTg6dys, 0.0f);
  numBytes += cBinop_init(&cBinop_6td1YrXQ, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_DF9paIA4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ODMXiAlH, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_xxXxNYUs, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_5BKOqaS2, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3O5EV52U, 0.0f);
  numBytes += hTable_init(&hTable_1wru8MHW, 256);
  numBytes += cTabhead_init(&cTabhead_lyMX9Vqq, &hTable_PavbqHbh);
  numBytes += cVar_init_s(&cVar_TQxYDTLG, "del-1379-ref1");
  numBytes += cDelay_init(this, &cDelay_P7ubHVOe, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_bDG8bUgh, 0.0f);
  numBytes += cBinop_init(&cBinop_8PdJ2dIU, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_Ld25pwKY, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_QbMDrJ5D, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_tSvYVgmm, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_tB5NZr4E, 0.0f);
  numBytes += cDelay_init(this, &cDelay_hGsue7Jz, 0.0f);
  numBytes += hTable_init(&hTable_PavbqHbh, 256);
  numBytes += cVar_init_f(&cVar_VSjKuOI6, 0.0f);
  numBytes += cVar_init_f(&cVar_RLyMWiFF, 0.0f);
  numBytes += cPack_init(&cPack_VPR0Oyw5, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_CDX6aypC, 22050.0f);
  numBytes += cBinop_init(&cBinop_2aCi1Z79, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_xcWUBgW7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fwaft1NL, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VrH9KxJW, 22050.0f);
  numBytes += cBinop_init(&cBinop_NKEbzBYs, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_tntaR9Sq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WRIyWlnY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_v4TOZ2fz, 22050.0f);
  numBytes += cBinop_init(&cBinop_hgMJ4t71, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fxzFrkbz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GKaTfz83, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_B6eyIehi, "del-1478-del1");
  numBytes += sVarf_init(&sVarf_FAim4t1n, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NxdC7Wh7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yCVKRnXZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_KVzdF0qM, 10000.0f);
  numBytes += cBinop_init(&cBinop_IQFT6Jx2, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_PwVR65dU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Bzq9t0uV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bItwYSzW, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lUgV589c, 10.0f);
  numBytes += cBinop_init(&cBinop_A4U4v2mk, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_kcnAdkui, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_kBPXvb21, "floatatom");
  numBytes += sVarf_init(&sVarf_Rq44zWcE, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_WXHuVXot, 0.0f);
  numBytes += cDelay_init(this, &cDelay_9R3DgsoH, 0.0f);
  numBytes += hTable_init(&hTable_T9jAKNOt, 256);
  numBytes += sVarf_init(&sVarf_ZANEuPlt, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_FyA1UY0E, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_8DFLrIJe, 85258430);
  numBytes += cSlice_init(&cSlice_pociiKCb, 1, 1);
  numBytes += cRandom_init(&cRandom_nSle3PgA, 125721887);
  numBytes += cSlice_init(&cSlice_StVkbkdC, 1, 1);
  numBytes += cVar_init_s(&cVar_fYSkS6T0, "floatatom");
  numBytes += cPack_init(&cPack_ELiExiSB, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_zHbILivG, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_9yBeSKfN, "floatatom");
  numBytes += cDelay_init(this, &cDelay_8K7vf75r, 0.0f);
  numBytes += cDelay_init(this, &cDelay_F1wZrRjN, 0.0f);
  numBytes += hTable_init(&hTable_7GuvTMSA, 256);
  numBytes += cVar_init_s(&cVar_m4vdGBeV, "del-1509-del");
  numBytes += sVarf_init(&sVarf_JA0AGxfo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wxsmK5Ta, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RqhgoR3A, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_3gJgXJtB, "del-1509-del");
  numBytes += sVarf_init(&sVarf_dkOteZzn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9NODZsot, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JFW85uH9, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_FLQJd8SI, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_7MjhLhbF, "del-1538-del1");
  numBytes += sVarf_init(&sVarf_Vnlz4DVC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jSJqeU5r, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IaLQBw4s, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_s3SXLxzX, 10000.0f);
  numBytes += cBinop_init(&cBinop_zkuPRZN6, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8sIvH1e6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RQtlcfhh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XKpgWGaM, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5fyFYwxj, 10.0f);
  numBytes += cBinop_init(&cBinop_Y7Ol9vyP, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_rRPfTKuk, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_KpNo94y7, "floatatom");
  numBytes += sVarf_init(&sVarf_fng3KQbh, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_b9MvT5AB, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Wd429Bd4, 0.0f);
  numBytes += hTable_init(&hTable_BRVG0Edd, 256);
  numBytes += sVarf_init(&sVarf_xcxvsYac, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_wjFrCnRx, "floatatom");
  numBytes += cDelay_init(this, &cDelay_tGoOzEZE, 0.0f);
  numBytes += cVar_init_f(&cVar_8CRKRHuo, 20.0f);
  numBytes += cBinop_init(&cBinop_t1Vk3P8l, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_jQ2PKway, 0.0f);
  numBytes += cSlice_init(&cSlice_nvRUROO6, 1, -1);
  numBytes += cSlice_init(&cSlice_BVblME9o, 1, -1);
  numBytes += cVar_init_f(&cVar_HiwtXj4v, 0.0f);
  numBytes += cVar_init_f(&cVar_kqxlJ3sZ, 20.0f);
  numBytes += cVar_init_f(&cVar_3s9WM3nx, 0.0f);
  numBytes += cVar_init_f(&cVar_RgeZUcOg, 0.0f);
  numBytes += cVar_init_f(&cVar_Ux5c8vAm, 0.0f);
  numBytes += cSlice_init(&cSlice_dfP92UzD, 1, 1);
  numBytes += cSlice_init(&cSlice_tgwEM8gv, 0, 1);
  numBytes += cBinop_init(&cBinop_dBAIq5zf, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_y4nhF3kl, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_eHU5LfkQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_OT5uZDkJ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_da9NdIzf, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_lXVMcWzE, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_FhuYEvja, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_NtYfrCJv, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_x6DpVOEB, "floatatom");
  numBytes += cDelay_init(this, &cDelay_csytpbCe, 0.0f);
  numBytes += cVar_init_f(&cVar_M969CT5o, 20.0f);
  numBytes += cBinop_init(&cBinop_5KYiGRTu, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_qtVulrrs, 0.0f);
  numBytes += cSlice_init(&cSlice_sSTjRaP3, 1, -1);
  numBytes += cSlice_init(&cSlice_59pei6Ik, 1, -1);
  numBytes += cVar_init_f(&cVar_yaJ5IQoG, 0.0f);
  numBytes += cVar_init_f(&cVar_cXidXB74, 20.0f);
  numBytes += cVar_init_f(&cVar_k0UU3g9m, 0.0f);
  numBytes += cVar_init_f(&cVar_H7iuF1EU, 0.0f);
  numBytes += cVar_init_f(&cVar_0J9Bc3Z6, 0.0f);
  numBytes += cSlice_init(&cSlice_lZhF3YbG, 1, 1);
  numBytes += cSlice_init(&cSlice_ss8VoQMF, 0, 1);
  numBytes += cBinop_init(&cBinop_a76BC4DE, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_vlm7BGqs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nAaeMzxo, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_whlr7eYj, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dPPORfjY, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_4iVbTpYQ, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_l7Rzy6Wz, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_oM7E0VMt, 0.0f); // __sub
  numBytes += cPack_init(&cPack_lj3CVp5m, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_nBhvg53r, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_nbBuuQ5x, 2, 0.0f, 1000.0f);
  numBytes += cVar_init_f(&cVar_yy7u2DPM, 100.0f);
  numBytes += cIf_init(&cIf_ktDIzt8g, false);
  numBytes += cBinop_init(&cBinop_nEN4eHhT, 0.0f); // __pow
  numBytes += cPack_init(&cPack_8xMASgQt, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_kGp7c0Ky, 0.0f);
  numBytes += cVar_init_f(&cVar_wm0wVmwR, 100.0f);
  numBytes += cIf_init(&cIf_zxf3sfnV, false);
  numBytes += cBinop_init(&cBinop_VbRuF6q3, 0.0f); // __pow
  numBytes += cPack_init(&cPack_hPYcf5jS, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_836UydQs, 0.0f);
  numBytes += cIf_init(&cIf_efq16Bf3, false);
  numBytes += cIf_init(&cIf_ZehOVtjS, false);
  numBytes += cVar_init_f(&cVar_vgNw3AV9, 97.0f);
  numBytes += cIf_init(&cIf_6TUkv7BL, false);
  numBytes += cBinop_init(&cBinop_rrvflGKn, 0.0f); // __pow
  numBytes += cPack_init(&cPack_mawjhgeE, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_zmUQx012, 0.0f);
  numBytes += cVar_init_f(&cVar_CoQ2QmcJ, 89.0f);
  numBytes += cIf_init(&cIf_GY6gzMjG, false);
  numBytes += cBinop_init(&cBinop_UXZqsQOt, 0.0f); // __pow
  numBytes += cPack_init(&cPack_q53Zlbry, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_26iW6huZ, 0.0f);
  numBytes += cVar_init_f(&cVar_XYNJNEsX, 97.0f);
  numBytes += cIf_init(&cIf_L3FuPtI6, false);
  numBytes += cBinop_init(&cBinop_mp6KMkpD, 0.0f); // __pow
  numBytes += cPack_init(&cPack_3NlgJCQH, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_mL16X60G, 0.0f);
  numBytes += cPack_init(&cPack_TOzuRusS, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_rP2DqFDa, 1, 1);
  numBytes += cSlice_init(&cSlice_dFOkW6fv, 0, 1);
  numBytes += cIf_init(&cIf_uhJfd3ds, false);
  numBytes += cIf_init(&cIf_49YgxZV7, false);
  numBytes += cIf_init(&cIf_Kf0nzgJ7, false);
  numBytes += cSlice_init(&cSlice_11knuROK, 1, 1);
  numBytes += cSlice_init(&cSlice_iOVw4Kwd, 0, 1);
  numBytes += cVar_init_f(&cVar_nXjuoZsi, 0.0f);
  numBytes += cIf_init(&cIf_e4IK4MES, false);
  numBytes += cPack_init(&cPack_wCas8DYj, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_UgR7IaJY, 1, -1);
  numBytes += cSlice_init(&cSlice_UhU3P1Xu, 1, -1);
  numBytes += cSlice_init(&cSlice_TYaivwTL, 1, -1);
  numBytes += cSlice_init(&cSlice_K2ZUL236, 1, -1);
  numBytes += cIf_init(&cIf_gbhQn5d6, false);
  numBytes += cVar_init_f(&cVar_7GT4fARz, 1.0f);
  numBytes += cPack_init(&cPack_K8jbMucM, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_90bllaDa, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_PhaseRing::~Heavy_PhaseRing() {
  cPack_free(&cPack_a8gY6we0);
  cPack_free(&cPack_3W1w5ygR);
  cPack_free(&cPack_M8pqQz9i);
  cPack_free(&cPack_l0NchqdR);
  cPack_free(&cPack_lhMufdE7);
  cPack_free(&cPack_AJHNDtyX);
  cPack_free(&cPack_F5tPvQRz);
  cPack_free(&cPack_gKbAVDl8);
  cPack_free(&cPack_urDhOzsa);
  cPack_free(&cPack_5APBNPUX);
  cPack_free(&cPack_3RKZFYe6);
  cPack_free(&cPack_9YGrzVqQ);
  cPack_free(&cPack_Xjx4MR0z);
  cPack_free(&cPack_Qjbcz811);
  cPack_free(&cPack_LuSlkY39);
  cPack_free(&cPack_qo3rLzyF);
  cPack_free(&cPack_vXO1Y0w5);
  hTable_free(&hTable_y1MeZAkG);
  hTable_free(&hTable_yigFpQR5);
  hTable_free(&hTable_ZxLjdfs4);
  hTable_free(&hTable_oqNTpXpC);
  cPack_free(&cPack_3AWggFEO);
  cPack_free(&cPack_3r0DAcAE);
  hTable_free(&hTable_zb1j4ZzD);
  hTable_free(&hTable_SQbnfU0T);
  hTable_free(&hTable_EAyjGHbb);
  hTable_free(&hTable_usOFQLK0);
  hTable_free(&hTable_ESGkFV4S);
  hTable_free(&hTable_q9Y5tQmo);
  cPack_free(&cPack_Is1pAcj0);
  cPack_free(&cPack_JfnhsHEM);
  cPack_free(&cPack_C9iKp8bl);
  hTable_free(&hTable_3MB9R521);
  hTable_free(&hTable_5ioMphG8);
  hTable_free(&hTable_RW3zd5nF);
  hTable_free(&hTable_a8GDILoc);
  hTable_free(&hTable_M2AxBj05);
  cPack_free(&cPack_rEYD88aI);
  cPack_free(&cPack_FIz5w5G4);
  hTable_free(&hTable_bbTFkl2o);
  hTable_free(&hTable_6TQwTNEC);
  hTable_free(&hTable_Kk9ndx4m);
  hTable_free(&hTable_vh7RD3Lg);
  hTable_free(&hTable_1wru8MHW);
  hTable_free(&hTable_PavbqHbh);
  cPack_free(&cPack_VPR0Oyw5);
  hTable_free(&hTable_T9jAKNOt);
  cPack_free(&cPack_FyA1UY0E);
  cPack_free(&cPack_ELiExiSB);
  cPack_free(&cPack_zHbILivG);
  hTable_free(&hTable_7GuvTMSA);
  hTable_free(&hTable_BRVG0Edd);
  cPack_free(&cPack_lj3CVp5m);
  cPack_free(&cPack_nBhvg53r);
  cPack_free(&cPack_nbBuuQ5x);
  cPack_free(&cPack_8xMASgQt);
  cPack_free(&cPack_hPYcf5jS);
  cPack_free(&cPack_mawjhgeE);
  cPack_free(&cPack_q53Zlbry);
  cPack_free(&cPack_3NlgJCQH);
  cPack_free(&cPack_TOzuRusS);
  cPack_free(&cPack_wCas8DYj);
  cPack_free(&cPack_K8jbMucM);
}

HvTable *Heavy_PhaseRing::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xF96F9CBC: return &hTable_y1MeZAkG; // del-1209-del1
    case 0xEAD79ADF: return &hTable_yigFpQR5; // del-1209-del2
    case 0xB1129AA0: return &hTable_ZxLjdfs4; // del-1209-del3
    case 0x4F62B33F: return &hTable_oqNTpXpC; // del-1209-del4
    case 0x36047BDC: return &hTable_zb1j4ZzD; // del-1209-ref6
    case 0x66BE8A1D: return &hTable_SQbnfU0T; // del-1209-ref5
    case 0xD4C64222: return &hTable_EAyjGHbb; // del-1209-ref4
    case 0xC5A2B81B: return &hTable_usOFQLK0; // del-1209-ref3
    case 0xE629D5: return &hTable_ESGkFV4S; // del-1209-ref2
    case 0x912EE503: return &hTable_q9Y5tQmo; // del-1209-ref1
    case 0xFBB0E240: return &hTable_3MB9R521; // del-1316-del
    case 0xDB23006E: return &hTable_5ioMphG8; // del-1379-del1
    case 0x71D4109E: return &hTable_RW3zd5nF; // del-1379-del2
    case 0x3209AF80: return &hTable_a8GDILoc; // del-1379-del3
    case 0x243F6DE3: return &hTable_M2AxBj05; // del-1379-del4
    case 0x57CE1FFD: return &hTable_bbTFkl2o; // del-1379-ref6
    case 0xE6EB4810: return &hTable_6TQwTNEC; // del-1379-ref5
    case 0x1A778356: return &hTable_Kk9ndx4m; // del-1379-ref4
    case 0xEAC5B9C7: return &hTable_vh7RD3Lg; // del-1379-ref3
    case 0x59B93D98: return &hTable_1wru8MHW; // del-1379-ref2
    case 0x29741CDA: return &hTable_PavbqHbh; // del-1379-ref1
    case 0xE6E7333E: return &hTable_T9jAKNOt; // del-1478-del1
    case 0x37C7A3A7: return &hTable_7GuvTMSA; // del-1509-del
    case 0x55F6486C: return &hTable_BRVG0Edd; // del-1538-del1
    default: return nullptr;
  }
}

void Heavy_PhaseRing::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x9DBB052E: { // 1057-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cOSoz3ld_sendMessage);
      break;
    }
    case 0xF1DE93DD: { // 1057-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1HJaDRvr_sendMessage);
      break;
    }
    case 0x6CD381D4: { // 1057-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kDFF6b8N_sendMessage);
      break;
    }
    case 0xCF6D3C3F: { // 1057-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JDAibMQp_sendMessage);
      break;
    }
    case 0xEDDFD30D: { // 1057-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_n7PYZmlr_sendMessage);
      break;
    }
    case 0xF2BA3B2A: { // 1057-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_coSdfKdS_sendMessage);
      break;
    }
    case 0x4408E690: { // 1093-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6GJtIX7G_sendMessage);
      break;
    }
    case 0x8AB98019: { // 1093-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_U9KYS8R0_sendMessage);
      break;
    }
    case 0x27A42126: { // 1101-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ovloK2rB_sendMessage);
      break;
    }
    case 0xB5E9A65D: { // 1101-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oBan5v2r_sendMessage);
      break;
    }
    case 0x56934ECA: { // 1101-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NG604mFM_sendMessage);
      break;
    }
    case 0x7514C9B6: { // 1101-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4YrMBk81_sendMessage);
      break;
    }
    case 0xCB831B98: { // 1101-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qDQNTXVg_sendMessage);
      break;
    }
    case 0x3A687221: { // 1101-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Bhcwg8cr_sendMessage);
      break;
    }
    case 0x68EAABD0: { // 1137-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RBP0MJ3N_sendMessage);
      break;
    }
    case 0x20D6E4AD: { // 1137-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Iz7o3IDQ_sendMessage);
      break;
    }
    case 0x4BE05FC6: { // 1137-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LFG0ETsK_sendMessage);
      break;
    }
    case 0xD8FD070D: { // 1137-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FW6QmXIL_sendMessage);
      break;
    }
    case 0xC65E45B8: { // 1137-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_t2ZV0rAN_sendMessage);
      break;
    }
    case 0x9349BDCA: { // 1137-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OulqKMcS_sendMessage);
      break;
    }
    case 0x8A2C77AE: { // 1173-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BCpPJ7NN_sendMessage);
      break;
    }
    case 0xD6F86CC3: { // 1173-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mmeYbl8N_sendMessage);
      break;
    }
    case 0x2A29490B: { // 1173-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Cwgdtnjr_sendMessage);
      break;
    }
    case 0xFAE8AB: { // 1173-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9C9lwhQe_sendMessage);
      break;
    }
    case 0xBFDBA4A2: { // 1173-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jQ4SCrIi_sendMessage);
      break;
    }
    case 0x7638E91B: { // 1173-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zWSW9c6q_sendMessage);
      break;
    }
    case 0x83D209A2: { // 1599-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_F5dEd7ti_sendMessage);
      break;
    }
    case 0x62CA542E: { // 1599-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_i9hE7C9l_sendMessage);
      break;
    }
    case 0xF8E41A5F: { // 1607-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UgACIFTM_sendMessage);
      break;
    }
    case 0x9164CD41: { // 1607-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EHYKwga2_sendMessage);
      break;
    }
    case 0x78060116: { // 1619-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1yQIaM5Y_sendMessage);
      break;
    }
    case 0xDDEDC45: { // 1619-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sz1syj4D_sendMessage);
      break;
    }
    case 0x3FF54ADC: { // 1627-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_I0Gfc08Y_sendMessage);
      break;
    }
    case 0x613389B1: { // 1627-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4UjoCW5G_sendMessage);
      break;
    }
    case 0xCA661AA: { // 1635-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YT4AJVHt_sendMessage);
      break;
    }
    case 0x33695BEA: { // 1635-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BR1JSnsx_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tyFrrbKO_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_O2r0FHQN_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0FPsuEQs_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0izWBkMU_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PvIc2szs_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZPghyLhU_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UdySrlo1_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_V8dBMxMs_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_O3UozzMQ_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xfuITMBf_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UMGUVQmJ_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qjnKTty8_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DQRtVvLR_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6CjJwVWX_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bbvv3O2p_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0NjDKsU6_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8rAR96T3_sendMessage);
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


void Heavy_PhaseRing::cSlice_2oyQdFcN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Tf7QWv1Z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_tX1hGAss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_39Bm0yUK, 0, m, &cIf_39Bm0yUK_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_Gsug0npx, 0, m, &cIf_Gsug0npx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_xuJ9oz5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_tKvytw7H, 0, m, &cIf_tKvytw7H_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_HUOukaLS, 0, m, &cIf_HUOukaLS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_tfkrxusq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_l1XHXk7B_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_lBJINygR, 0, m, &cIf_lBJINygR_sendMessage);
}

void Heavy_PhaseRing::cUnop_vURQPwzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_0Ifjiska_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ra0rbDtN, HV_BINOP_EQ, 1, m, &cBinop_Ra0rbDtN_sendMessage);
}

void Heavy_PhaseRing::cUnop_96LL9EUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_0Ifjiska_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ra0rbDtN, HV_BINOP_EQ, 1, m, &cBinop_Ra0rbDtN_sendMessage);
}

void Heavy_PhaseRing::cIf_lBJINygR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_96LL9EUV_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vURQPwzW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_l1XHXk7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lBJINygR, 1, m, &cIf_lBJINygR_sendMessage);
}

void Heavy_PhaseRing::cIf_Gsug0npx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_eFQAQBx3_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_HUOukaLS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_8eceagcz_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_39Bm0yUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_eFQAQBx3_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_tKvytw7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_8eceagcz_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Tf7QWv1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ra0rbDtN, HV_BINOP_EQ, 0, m, &cBinop_Ra0rbDtN_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_lDFPoZS9_sendMessage);
}

void Heavy_PhaseRing::cBinop_0Ifjiska_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eajL7spF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mxN1uPss_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ra0rbDtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O3q4YFBI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2Z2yorUD_sendMessage);
}

void Heavy_PhaseRing::cCast_O3q4YFBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Gsug0npx, 1, m, &cIf_Gsug0npx_sendMessage);
}

void Heavy_PhaseRing::cCast_2Z2yorUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tKvytw7H, 1, m, &cIf_tKvytw7H_sendMessage);
}

void Heavy_PhaseRing::cCast_eajL7spF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_39Bm0yUK, 1, m, &cIf_39Bm0yUK_sendMessage);
}

void Heavy_PhaseRing::cCast_mxN1uPss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HUOukaLS, 1, m, &cIf_HUOukaLS_sendMessage);
}

void Heavy_PhaseRing::cBinop_lDFPoZS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_eLdaU0ik_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_9G8PHALm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3b8EmXBc, 0, m, &cVar_3b8EmXBc_sendMessage);
}

void Heavy_PhaseRing::cBinop_TI0lVUsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_bN67agRP_sendMessage);
}

void Heavy_PhaseRing::cBinop_bN67agRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VQsXEwP5, HV_BINOP_POW, 1, m, &cBinop_VQsXEwP5_sendMessage);
  cMsg_7QGzuro4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_VQsXEwP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_9G8PHALm_sendMessage);
}

void Heavy_PhaseRing::cMsg_7QGzuro4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VQsXEwP5, HV_BINOP_POW, 0, m, &cBinop_VQsXEwP5_sendMessage);
}

void Heavy_PhaseRing::cBinop_vfk36evj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ENrn1R5f_sendMessage);
}

void Heavy_PhaseRing::cBinop_ENrn1R5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qOvV3VZd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NgSRehEa_sendMessage);
}

void Heavy_PhaseRing::cVar_fZPigCv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_RAAuTsj1_sendMessage);
}

void Heavy_PhaseRing::cMsg_b59zLMmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bT4Ip7mc_sendMessage);
}

void Heavy_PhaseRing::cSystem_bT4Ip7mc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tYARirDf, HV_BINOP_DIVIDE, 1, m, &cBinop_tYARirDf_sendMessage);
}

void Heavy_PhaseRing::cBinop_qOvV3VZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_fkpN2Jzb_sendMessage);
}

void Heavy_PhaseRing::cBinop_fkpN2Jzb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aY444rQY, m);
}

void Heavy_PhaseRing::cMsg_WIeU99rj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_BvC6vZCO_sendMessage);
}

void Heavy_PhaseRing::cBinop_BvC6vZCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_vfk36evj_sendMessage);
}

void Heavy_PhaseRing::cBinop_NgSRehEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mCTN3Dzg, m);
}

void Heavy_PhaseRing::cBinop_RAAuTsj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_R9JBK4Qs_sendMessage);
}

void Heavy_PhaseRing::cBinop_R9JBK4Qs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tYARirDf, HV_BINOP_DIVIDE, 0, m, &cBinop_tYARirDf_sendMessage);
}

void Heavy_PhaseRing::cBinop_tYARirDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WIeU99rj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_a8gY6we0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AdIVMSVN, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_yuHpy6hF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_P0DyhIYS_sendMessage);
}

void Heavy_PhaseRing::cVar_3b8EmXBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_QiBGcMM7, 0, m);
}

void Heavy_PhaseRing::cIf_CNr6rz7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_8DcjDQEV_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_F3SkYADp, 0, m, &cIf_F3SkYADp_sendMessage);
      break;
    }
    case 1: {
      cMsg_QEKQPaDv_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_fA0ISshA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CNr6rz7z, 1, m, &cIf_CNr6rz7z_sendMessage);
}

void Heavy_PhaseRing::cIf_F3SkYADp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_JVhWMUd7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_tprb7vMP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_8DcjDQEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_F3SkYADp, 1, m, &cIf_F3SkYADp_sendMessage);
}

void Heavy_PhaseRing::cMsg_QEKQPaDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_tprb7vMP_sendMessage);
}

void Heavy_PhaseRing::cMsg_JVhWMUd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_tprb7vMP_sendMessage);
}

void Heavy_PhaseRing::cIf_06ote1vU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_mOmdRO4L_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_qEc55J7O, 0, m, &cIf_qEc55J7O_sendMessage);
      break;
    }
    case 1: {
      cMsg_UoVSvFEA_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Z54GtYHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_06ote1vU, 1, m, &cIf_06ote1vU_sendMessage);
}

void Heavy_PhaseRing::cIf_qEc55J7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_hMVv1vwA_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_M8pqQz9i, 0, m, &cPack_M8pqQz9i_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_mOmdRO4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qEc55J7O, 1, m, &cIf_qEc55J7O_sendMessage);
}

void Heavy_PhaseRing::cMsg_UoVSvFEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_M8pqQz9i, 0, m, &cPack_M8pqQz9i_sendMessage);
}

void Heavy_PhaseRing::cMsg_hMVv1vwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_M8pqQz9i, 0, m, &cPack_M8pqQz9i_sendMessage);
}

void Heavy_PhaseRing::cPack_3W1w5ygR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9EgVUUQA, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_M8pqQz9i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_CkCYmdco, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_l0NchqdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_X2lphywz, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_P0DyhIYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.1f, 0, m, &cBinop_O21o2xzD_sendMessage);
}

void Heavy_PhaseRing::cBinop_qOAE8hKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yuHpy6hF, 0, m, &cVar_yuHpy6hF_sendMessage);
}

void Heavy_PhaseRing::cBinop_O21o2xzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_a8gY6we0, 0, m, &cPack_a8gY6we0_sendMessage);
}

void Heavy_PhaseRing::cBinop_tprb7vMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_wnp5LWXS_sendMessage);
}

void Heavy_PhaseRing::cBinop_wnp5LWXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_Z54GtYHu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_06ote1vU, 0, m, &cIf_06ote1vU_sendMessage);
}

void Heavy_PhaseRing::cCast_0QFNIltJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XGhuvZWa_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Gf9tVojF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_XGhuvZWa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8p6foZ8N, 0, m, &cSlice_8p6foZ8N_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3AdDP3qQ, 0, m, &cRandom_3AdDP3qQ_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_a0yNMSF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FJGSvnFo_sendMessage);
}

void Heavy_PhaseRing::cUnop_FJGSvnFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kzg536HY, 0, m, &cVar_kzg536HY_sendMessage);
}

void Heavy_PhaseRing::cRandom_3AdDP3qQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_a0yNMSF3_sendMessage);
}

void Heavy_PhaseRing::cSlice_8p6foZ8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3AdDP3qQ, 1, m, &cRandom_3AdDP3qQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_kzg536HY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_c3061VV6_sendMessage(_c, 0, m);
  cSend_N3PNhdJn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Gf9tVojF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_x0uBtTM9, 0, m, &cSlice_x0uBtTM9_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_S5WVvOVd, 0, m, &cRandom_S5WVvOVd_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_efom8sNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_bzYamcl2_sendMessage);
}

void Heavy_PhaseRing::cUnop_bzYamcl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_ZvP5OQmW_sendMessage);
  cSend_0oGAgCmK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cRandom_S5WVvOVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_efom8sNr_sendMessage);
}

void Heavy_PhaseRing::cSlice_x0uBtTM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_S5WVvOVd, 1, m, &cRandom_S5WVvOVd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_DUjak1ss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nRQ9WRdt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_udKML2px_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Xku80sX2_sendMessage);
}

void Heavy_PhaseRing::cBinop_Xku80sX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_udKML2px, 1, m, &cVar_udKML2px_sendMessage);
}

void Heavy_PhaseRing::cCast_77NVDtd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_fspRBm1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_eLswbPGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_aB8VsE6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_14R4R5BN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_ZvP5OQmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DUjak1ss, 0, m, &cVar_DUjak1ss_sendMessage);
}

void Heavy_PhaseRing::cSend_nRQ9WRdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6CjJwVWX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_c3061VV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_V8dBMxMs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_0oGAgCmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8rAR96T3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_N3PNhdJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bbvv3O2p_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_7NhO12RM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_UI5O7rZN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_UI5O7rZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZPghyLhU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_QeUiHplc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_UI5O7rZN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_14R4R5BN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0FPsuEQs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_vzqZzDVi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oL8ldI27, 0, m, &cSlice_oL8ldI27_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZVW3RdFd, 0, m, &cRandom_ZVW3RdFd_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_IsDeYLLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9H3c9tPJ_sendMessage);
}

void Heavy_PhaseRing::cUnop_9H3c9tPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_TQKPT6Sx_sendMessage);
}

void Heavy_PhaseRing::cRandom_ZVW3RdFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 900.0f, 0, m, &cBinop_IsDeYLLx_sendMessage);
}

void Heavy_PhaseRing::cSlice_oL8ldI27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZVW3RdFd, 1, m, &cRandom_ZVW3RdFd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_b6ADm5cJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MCSQPpqm, 0, m, &cSlice_MCSQPpqm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Whe0zFdc, 0, m, &cRandom_Whe0zFdc_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_mGDtgu5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jKsZKUs7_sendMessage);
}

void Heavy_PhaseRing::cUnop_jKsZKUs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_MTzaFFN2_sendMessage);
}

void Heavy_PhaseRing::cRandom_Whe0zFdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_mGDtgu5l_sendMessage);
}

void Heavy_PhaseRing::cSlice_MCSQPpqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Whe0zFdc, 1, m, &cRandom_Whe0zFdc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_2JzW5q1d_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UZ8V0srQ, 0, m, &cSlice_UZ8V0srQ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_T6aNSyhw, 0, m, &cRandom_T6aNSyhw_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_eT9qzZnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RKwomlC3_sendMessage);
}

void Heavy_PhaseRing::cUnop_RKwomlC3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_5RBgjw1f_sendMessage);
}

void Heavy_PhaseRing::cRandom_T6aNSyhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_eT9qzZnE_sendMessage);
}

void Heavy_PhaseRing::cSlice_UZ8V0srQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_T6aNSyhw, 1, m, &cRandom_T6aNSyhw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_VZD3jq5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KmiEs60q, HV_BINOP_MULTIPLY, 0, m, &cBinop_KmiEs60q_sendMessage);
}

void Heavy_PhaseRing::cBinop_hrx3jwKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_P2lv92ib_sendMessage);
}

void Heavy_PhaseRing::cBinop_P2lv92ib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vwn1AXLn, HV_BINOP_POW, 1, m, &cBinop_Vwn1AXLn_sendMessage);
  cMsg_geAMaToK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Vwn1AXLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_VZD3jq5X_sendMessage);
}

void Heavy_PhaseRing::cMsg_geAMaToK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vwn1AXLn, HV_BINOP_POW, 0, m, &cBinop_Vwn1AXLn_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_bgoE6vAL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_joJ9ric1, 0, m, &cSlice_joJ9ric1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xII7mQfR, 0, m, &cRandom_xII7mQfR_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_2MK1qOKV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GyHOLnj0_sendMessage);
}

void Heavy_PhaseRing::cUnop_GyHOLnj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CoDU5a2y_sendMessage);
}

void Heavy_PhaseRing::cRandom_xII7mQfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_2MK1qOKV_sendMessage);
}

void Heavy_PhaseRing::cSlice_joJ9ric1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xII7mQfR, 1, m, &cRandom_xII7mQfR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_lhMufdE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ANAXPbTF, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_YbkcH7vs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_CFOzEXWj_sendMessage);
}

void Heavy_PhaseRing::cVar_HJ3kqbgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_OHvna8xd, 0, m);
}

void Heavy_PhaseRing::cVar_f6n2VHgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_sOanNndz, 0, m);
}

void Heavy_PhaseRing::cVar_WUAMruOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uuPyOIIw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9VBRoPzZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_65JIQisV_sendMessage);
}

void Heavy_PhaseRing::cCast_ar1kx4Pz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_XXHVOvgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_Qs1lsJhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_oZtNQz54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_386JdPB5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_sNAMIKxc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_sNAMIKxc_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_qHRI3QgK, 1, m, &cDelay_qHRI3QgK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mrNMl8oI_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_qHRI3QgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qHRI3QgK, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IfhE7iy3, 0, m, &cVar_IfhE7iy3_sendMessage);
}

void Heavy_PhaseRing::cMsg_sNAMIKxc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qHRI3QgK, 0, m, &cDelay_qHRI3QgK_sendMessage);
}

void Heavy_PhaseRing::cCast_mrNMl8oI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qHRI3QgK, 0, m, &cDelay_qHRI3QgK_sendMessage);
}

void Heavy_PhaseRing::cVar_IfhE7iy3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ExwJ5oTZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_66x9tacv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WUAMruOx, 0, m, &cVar_WUAMruOx_sendMessage);
}

void Heavy_PhaseRing::cMsg_PdZJu99C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_GksACBOf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_uL788rlD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_Q1laxKey_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ZWmAFsh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_mJgfuFoP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_PPKeOuB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1HJaDRvr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_h0FF6Fla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_IwdA02XF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kDFF6b8N_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_GksACBOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_Q1laxKey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1HJaDRvr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_mJgfuFoP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kDFF6b8N_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_QdY4jY56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_CQ6KitrP, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_ExwJ5oTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_CQ6KitrP, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_65JIQisV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_386JdPB5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_uuPyOIIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QdY4jY56_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_9VBRoPzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IfhE7iy3, 1, m, &cVar_IfhE7iy3_sendMessage);
}

void Heavy_PhaseRing::cCast_7rs8AbdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_529dzJWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_F5tPvQRz, 0, m, &cPack_F5tPvQRz_sendMessage);
}

void Heavy_PhaseRing::cUnop_0Ocfs6lz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AJHNDtyX, 0, m, &cPack_AJHNDtyX_sendMessage);
}

void Heavy_PhaseRing::cPack_AJHNDtyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8G7YlD6E, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_F5tPvQRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_joylSmui, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_Sb08Vpsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_529dzJWv_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_0Ocfs6lz_sendMessage);
}

void Heavy_PhaseRing::cMsg_EEeLBo8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_Sb08Vpsr_sendMessage);
}

void Heavy_PhaseRing::cSlice_6GOdge2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_nZfKcJqp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_2lqEEzGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I2KvdYCM_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_hrx3jwKY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_5RBgjw1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_t0QAnHQU_sendMessage);
}

void Heavy_PhaseRing::cBinop_t0QAnHQU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_Sb08Vpsr_sendMessage);
}

void Heavy_PhaseRing::cBinop_nZfKcJqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Dp3LLAH9_sendMessage(_c, 0, m);
  cSend_tkWyOqHJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_KmiEs60q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6PHS0xg0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PXUAcLP2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_f6n2VHgC, 0, m, &cVar_f6n2VHgC_sendMessage);
}

void Heavy_PhaseRing::cBinop_CoDU5a2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_wKtvO2eR_sendMessage);
}

void Heavy_PhaseRing::cBinop_wKtvO2eR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KmiEs60q, HV_BINOP_MULTIPLY, 1, m, &cBinop_KmiEs60q_sendMessage);
}

void Heavy_PhaseRing::cCast_I2KvdYCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bgoE6vAL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_Dp3LLAH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_coSdfKdS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_PXUAcLP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2JzW5q1d_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_6PHS0xg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_66x9tacv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7rs8AbdV_sendMessage);
}

void Heavy_PhaseRing::cBinop_CFOzEXWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lhMufdE7, 0, m, &cPack_lhMufdE7_sendMessage);
}

void Heavy_PhaseRing::cSend_tkWyOqHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JDAibMQp_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_NJwIgSoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_n7PYZmlr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_jSSLgpGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_NJwIgSoi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_9KbWwkEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qnYo7sop_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j9dgVNKI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bCp8yyCn_sendMessage);
}

void Heavy_PhaseRing::cIf_09s2cu00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_F6DYkSZM_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_n1WWzanb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_PeB22vO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_I1amgWX4, HV_BINOP_POW, 0, m, &cBinop_I1amgWX4_sendMessage);
}

void Heavy_PhaseRing::cBinop_I1amgWX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gKbAVDl8, 0, m, &cPack_gKbAVDl8_sendMessage);
}

void Heavy_PhaseRing::cBinop_MfEccXFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_KqCqgwD8_sendMessage);
}

void Heavy_PhaseRing::cCast_j9dgVNKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_diRUJyUI_sendMessage);
}

void Heavy_PhaseRing::cCast_bCp8yyCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_09s2cu00, 0, m, &cIf_09s2cu00_sendMessage);
}

void Heavy_PhaseRing::cBinop_diRUJyUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_09s2cu00, 1, m, &cIf_09s2cu00_sendMessage);
}

void Heavy_PhaseRing::cBinop_n1WWzanb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_MfEccXFb_sendMessage);
}

void Heavy_PhaseRing::cMsg_F6DYkSZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_gKbAVDl8, 0, m, &cPack_gKbAVDl8_sendMessage);
}

void Heavy_PhaseRing::cBinop_KqCqgwD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I1amgWX4, HV_BINOP_POW, 1, m, &cBinop_I1amgWX4_sendMessage);
  cMsg_PeB22vO0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_gKbAVDl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0i6WrGJS, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_DGYNmb7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_osMCNHe0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_qnYo7sop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_4yOljzYv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_4yOljzYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6GJtIX7G_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_osMCNHe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_U9KYS8R0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_zJBdbkb4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5v2mEr9D, 0, m, &cSlice_5v2mEr9D_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6pC19TVI, 0, m, &cRandom_6pC19TVI_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_iRjU6hqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3cfsxofr_sendMessage);
}

void Heavy_PhaseRing::cUnop_3cfsxofr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_8mAOGLM0_sendMessage);
}

void Heavy_PhaseRing::cRandom_6pC19TVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_iRjU6hqM_sendMessage);
}

void Heavy_PhaseRing::cSlice_5v2mEr9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6pC19TVI, 1, m, &cRandom_6pC19TVI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_TZcPMSlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3bosWtYg, HV_BINOP_MULTIPLY, 0, m, &cBinop_3bosWtYg_sendMessage);
}

void Heavy_PhaseRing::cBinop_Oodk9cI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_KiZHgG3F_sendMessage);
}

void Heavy_PhaseRing::cBinop_KiZHgG3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QjjS4yPR, HV_BINOP_POW, 1, m, &cBinop_QjjS4yPR_sendMessage);
  cMsg_EVKXa6M3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_QjjS4yPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_TZcPMSlB_sendMessage);
}

void Heavy_PhaseRing::cMsg_EVKXa6M3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QjjS4yPR, HV_BINOP_POW, 0, m, &cBinop_QjjS4yPR_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_35JRa42p_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Kt4IdsDL, 0, m, &cSlice_Kt4IdsDL_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DL3f9JCw, 0, m, &cRandom_DL3f9JCw_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_jMqEpmsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_g7hLmLwm_sendMessage);
}

void Heavy_PhaseRing::cUnop_g7hLmLwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_x5KvcbRC_sendMessage);
}

void Heavy_PhaseRing::cRandom_DL3f9JCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_jMqEpmsp_sendMessage);
}

void Heavy_PhaseRing::cSlice_Kt4IdsDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DL3f9JCw, 1, m, &cRandom_DL3f9JCw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_urDhOzsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2lHNZe7S, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_qVnsr15i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_YD5dD3tS_sendMessage);
}

void Heavy_PhaseRing::cVar_FumicZVE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_4XdVwZGx, 0, m);
}

void Heavy_PhaseRing::cVar_9zqIzjd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ZolYEEGx, 0, m);
}

void Heavy_PhaseRing::cVar_kX3NH6kf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hSK7fHsg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rC9zJhGr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9W4QlpZh_sendMessage);
}

void Heavy_PhaseRing::cCast_FlGJalNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_BUICChbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_AmIqoQeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_ZI1KbELp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_Po61J5Ad_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_xNhJoGkv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_xNhJoGkv_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_rrSTtoo2, 1, m, &cDelay_rrSTtoo2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iIyFkRX9_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_rrSTtoo2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rrSTtoo2, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FBsE2Zn0, 0, m, &cVar_FBsE2Zn0_sendMessage);
}

void Heavy_PhaseRing::cMsg_xNhJoGkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rrSTtoo2, 0, m, &cDelay_rrSTtoo2_sendMessage);
}

void Heavy_PhaseRing::cCast_iIyFkRX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rrSTtoo2, 0, m, &cDelay_rrSTtoo2_sendMessage);
}

void Heavy_PhaseRing::cVar_FBsE2Zn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8VDCWmco_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_UPwAU1hA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kX3NH6kf, 0, m, &cVar_kX3NH6kf_sendMessage);
}

void Heavy_PhaseRing::cMsg_zH3jWOwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_Ny3FpZyu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_6aSK7kdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_SJJ5jSgX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_jOB3LK9v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_9ZIpebl0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_eKOqDSW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oBan5v2r_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_NX1t7Tfx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_U5WrymWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NG604mFM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_Ny3FpZyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_SJJ5jSgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oBan5v2r_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_9ZIpebl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NG604mFM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_WeYLTwPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_atdJS5Fg, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_8VDCWmco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_atdJS5Fg, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_9W4QlpZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Po61J5Ad_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_rC9zJhGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FBsE2Zn0, 1, m, &cVar_FBsE2Zn0_sendMessage);
}

void Heavy_PhaseRing::cCast_hSK7fHsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WeYLTwPV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_LambUEoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_16qQXSTA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3RKZFYe6, 0, m, &cPack_3RKZFYe6_sendMessage);
}

void Heavy_PhaseRing::cUnop_QOxHf74W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5APBNPUX, 0, m, &cPack_5APBNPUX_sendMessage);
}

void Heavy_PhaseRing::cPack_5APBNPUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_XH4gVXQ1, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_3RKZFYe6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6m8TWZV9, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_tpJUbdBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_16qQXSTA_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_QOxHf74W_sendMessage);
}

void Heavy_PhaseRing::cMsg_TdUqRVWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_tpJUbdBc_sendMessage);
}

void Heavy_PhaseRing::cSlice_ulfDVX9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_qtKh5a0o_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_OQFhrboO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LrbZdTld_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Oodk9cI5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_8mAOGLM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_OU62ThHj_sendMessage);
}

void Heavy_PhaseRing::cBinop_OU62ThHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_tpJUbdBc_sendMessage);
}

void Heavy_PhaseRing::cBinop_qtKh5a0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AzxLaj1E_sendMessage(_c, 0, m);
  cSend_lWajcwrZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_3bosWtYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bzKracVM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kUrr8bbY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9zqIzjd8, 0, m, &cVar_9zqIzjd8_sendMessage);
}

void Heavy_PhaseRing::cBinop_x5KvcbRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_SMpgGk9P_sendMessage);
}

void Heavy_PhaseRing::cBinop_SMpgGk9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3bosWtYg, HV_BINOP_MULTIPLY, 1, m, &cBinop_3bosWtYg_sendMessage);
}

void Heavy_PhaseRing::cCast_LrbZdTld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_35JRa42p_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_AzxLaj1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Bhcwg8cr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_kUrr8bbY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zJBdbkb4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_bzKracVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UPwAU1hA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LambUEoG_sendMessage);
}

void Heavy_PhaseRing::cBinop_YD5dD3tS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_urDhOzsa, 0, m, &cPack_urDhOzsa_sendMessage);
}

void Heavy_PhaseRing::cSend_lWajcwrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4YrMBk81_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_XBQdvqxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qDQNTXVg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_K3fVInJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_XBQdvqxE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_jultlwmM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HKeY9tmf, 0, m, &cSlice_HKeY9tmf_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4wBiVbHq, 0, m, &cRandom_4wBiVbHq_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_d6d9fuPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3OZrZUwE_sendMessage);
}

void Heavy_PhaseRing::cUnop_3OZrZUwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_wSJKCrId_sendMessage);
}

void Heavy_PhaseRing::cRandom_4wBiVbHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_d6d9fuPq_sendMessage);
}

void Heavy_PhaseRing::cSlice_HKeY9tmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4wBiVbHq, 1, m, &cRandom_4wBiVbHq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Fcsj0XXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BrIJR0G5, HV_BINOP_MULTIPLY, 0, m, &cBinop_BrIJR0G5_sendMessage);
}

void Heavy_PhaseRing::cBinop_Pasopgfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ikQ38zXD_sendMessage);
}

void Heavy_PhaseRing::cBinop_ikQ38zXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fmzaWCDf, HV_BINOP_POW, 1, m, &cBinop_fmzaWCDf_sendMessage);
  cMsg_rYZZ4M8p_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_fmzaWCDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Fcsj0XXT_sendMessage);
}

void Heavy_PhaseRing::cMsg_rYZZ4M8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fmzaWCDf, HV_BINOP_POW, 0, m, &cBinop_fmzaWCDf_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_WrYLkZNH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yLDhKY2W, 0, m, &cSlice_yLDhKY2W_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SQzJ3ALU, 0, m, &cRandom_SQzJ3ALU_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_7JJlYcof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_fZN86NTs_sendMessage);
}

void Heavy_PhaseRing::cUnop_fZN86NTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Se3XWJWn_sendMessage);
}

void Heavy_PhaseRing::cRandom_SQzJ3ALU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_7JJlYcof_sendMessage);
}

void Heavy_PhaseRing::cSlice_yLDhKY2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SQzJ3ALU, 1, m, &cRandom_SQzJ3ALU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_9YGrzVqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PZxgQ4vv, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_4ytsUVfy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_BAgZBb4p_sendMessage);
}

void Heavy_PhaseRing::cVar_4nuv8CIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_QE5CoEJC, 0, m);
}

void Heavy_PhaseRing::cVar_GzBwM73L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Ws99x1Vb, 0, m);
}

void Heavy_PhaseRing::cVar_hshT62i2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0yknfjJa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2F5z5I0M_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oiTeeCwx_sendMessage);
}

void Heavy_PhaseRing::cCast_WcMSKTFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_7TesBYpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_7FDqAdTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_n4r7QlB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_Z57VqfBg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_P7Ev1Sia_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_P7Ev1Sia_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TGkQ4UaQ, 1, m, &cDelay_TGkQ4UaQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yWaQt2uB_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_TGkQ4UaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TGkQ4UaQ, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RsRVvDso, 0, m, &cVar_RsRVvDso_sendMessage);
}

void Heavy_PhaseRing::cMsg_P7Ev1Sia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TGkQ4UaQ, 0, m, &cDelay_TGkQ4UaQ_sendMessage);
}

void Heavy_PhaseRing::cCast_yWaQt2uB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TGkQ4UaQ, 0, m, &cDelay_TGkQ4UaQ_sendMessage);
}

void Heavy_PhaseRing::cVar_RsRVvDso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cvIB7OJo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_qdxMzmcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hshT62i2, 0, m, &cVar_hshT62i2_sendMessage);
}

void Heavy_PhaseRing::cMsg_VOAb2p02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_j7GcEGs5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_6Ejro9g7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_ylf9lMa6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_vOESJ1a0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_L2OeGCKB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_FLAgCuZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Iz7o3IDQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_wqz77hgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_hCt8bheW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LFG0ETsK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_j7GcEGs5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_ylf9lMa6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Iz7o3IDQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_L2OeGCKB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LFG0ETsK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_CUj85o21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3JzKuFzn, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_cvIB7OJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_3JzKuFzn, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_oiTeeCwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Z57VqfBg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_0yknfjJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CUj85o21_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_2F5z5I0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RsRVvDso, 1, m, &cVar_RsRVvDso_sendMessage);
}

void Heavy_PhaseRing::cCast_Qunqmyyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_KWxkur3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Qjbcz811, 0, m, &cPack_Qjbcz811_sendMessage);
}

void Heavy_PhaseRing::cUnop_3P2JvjqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Xjx4MR0z, 0, m, &cPack_Xjx4MR0z_sendMessage);
}

void Heavy_PhaseRing::cPack_Xjx4MR0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_iDc9BMa0, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_Qjbcz811_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_W9zwNLeY, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_c8Q8dfXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_KWxkur3m_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_3P2JvjqN_sendMessage);
}

void Heavy_PhaseRing::cMsg_MEzWCmhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_c8Q8dfXF_sendMessage);
}

void Heavy_PhaseRing::cSlice_jrRvuiG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_bmew9Qwv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_ycmGfEiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PDYfnInR_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Pasopgfq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_wSJKCrId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_Yfhioe9N_sendMessage);
}

void Heavy_PhaseRing::cBinop_Yfhioe9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_c8Q8dfXF_sendMessage);
}

void Heavy_PhaseRing::cBinop_bmew9Qwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tKA3mqYQ_sendMessage(_c, 0, m);
  cSend_9dIUZpLY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_BrIJR0G5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NOEo06wy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oowq11hV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GzBwM73L, 0, m, &cVar_GzBwM73L_sendMessage);
}

void Heavy_PhaseRing::cBinop_Se3XWJWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_oLfSibpX_sendMessage);
}

void Heavy_PhaseRing::cBinop_oLfSibpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BrIJR0G5, HV_BINOP_MULTIPLY, 1, m, &cBinop_BrIJR0G5_sendMessage);
}

void Heavy_PhaseRing::cCast_PDYfnInR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WrYLkZNH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_tKA3mqYQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OulqKMcS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_oowq11hV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jultlwmM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_NOEo06wy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qdxMzmcy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qunqmyyg_sendMessage);
}

void Heavy_PhaseRing::cBinop_BAgZBb4p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9YGrzVqQ, 0, m, &cPack_9YGrzVqQ_sendMessage);
}

void Heavy_PhaseRing::cSend_9dIUZpLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FW6QmXIL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_hql2Yp49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_t2ZV0rAN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_BZYUK2dX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_hql2Yp49_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Dx4WhREI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UPp5RqqQ, 0, m, &cSlice_UPp5RqqQ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_mUjLz6ri, 0, m, &cRandom_mUjLz6ri_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_SsnuYqV0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ksduq3fW_sendMessage);
}

void Heavy_PhaseRing::cUnop_ksduq3fW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_tBiZVY6k_sendMessage);
}

void Heavy_PhaseRing::cRandom_mUjLz6ri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_SsnuYqV0_sendMessage);
}

void Heavy_PhaseRing::cSlice_UPp5RqqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_mUjLz6ri, 1, m, &cRandom_mUjLz6ri_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_PDSaxzZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sKFclUIO, HV_BINOP_MULTIPLY, 0, m, &cBinop_sKFclUIO_sendMessage);
}

void Heavy_PhaseRing::cBinop_oG3NsJLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_1PxTetI0_sendMessage);
}

void Heavy_PhaseRing::cBinop_1PxTetI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bCn7425k, HV_BINOP_POW, 1, m, &cBinop_bCn7425k_sendMessage);
  cMsg_1k4DvobY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_bCn7425k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_PDSaxzZ0_sendMessage);
}

void Heavy_PhaseRing::cMsg_1k4DvobY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bCn7425k, HV_BINOP_POW, 0, m, &cBinop_bCn7425k_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_UhpRh7AR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IoR4twpE, 0, m, &cSlice_IoR4twpE_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_gSdLACQ0, 0, m, &cRandom_gSdLACQ0_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_1ynM3NtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_q6BU7CGL_sendMessage);
}

void Heavy_PhaseRing::cUnop_q6BU7CGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_s7JNJpI7_sendMessage);
}

void Heavy_PhaseRing::cRandom_gSdLACQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_1ynM3NtS_sendMessage);
}

void Heavy_PhaseRing::cSlice_IoR4twpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_gSdLACQ0, 1, m, &cRandom_gSdLACQ0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_LuSlkY39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AAlfaxyd, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_mX9qHu8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_dVCPTIXN_sendMessage);
}

void Heavy_PhaseRing::cVar_ihIMxsS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_kAUPrDFI, 0, m);
}

void Heavy_PhaseRing::cVar_JkJAE8Y7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_92im5H1J, 0, m);
}

void Heavy_PhaseRing::cVar_8LikXWEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y6ckd1QU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9Cwh4Wzr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pe5zqbxx_sendMessage);
}

void Heavy_PhaseRing::cCast_3ER4iJEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_1Kf2iKJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_bws95Xck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_4HXd6OpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_XAxTWqUA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_EUsrhbic_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_EUsrhbic_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_IgWx7hOq, 1, m, &cDelay_IgWx7hOq_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J6wmSCA6_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_IgWx7hOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IgWx7hOq, m);
  cVar_onMessage(_c, &Context(_c)->cVar_a0C5t57D, 0, m, &cVar_a0C5t57D_sendMessage);
}

void Heavy_PhaseRing::cMsg_EUsrhbic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IgWx7hOq, 0, m, &cDelay_IgWx7hOq_sendMessage);
}

void Heavy_PhaseRing::cCast_J6wmSCA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IgWx7hOq, 0, m, &cDelay_IgWx7hOq_sendMessage);
}

void Heavy_PhaseRing::cVar_a0C5t57D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5mxmLrxK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_DC1JMXL8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8LikXWEL, 0, m, &cVar_8LikXWEL_sendMessage);
}

void Heavy_PhaseRing::cMsg_mI4zrgCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_fUpBiPBC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_oWJVO1HZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_A2jIKISC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_lCtLUceO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_e5tRYC4x_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_4Z1bLRNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mmeYbl8N_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_kh31rGrG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_CYyxj55q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Cwgdtnjr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_fUpBiPBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_A2jIKISC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mmeYbl8N_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_e5tRYC4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Cwgdtnjr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_gZLZO3Xs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_jiu98xgY, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_5mxmLrxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_jiu98xgY, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_Pe5zqbxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XAxTWqUA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_Y6ckd1QU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gZLZO3Xs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_9Cwh4Wzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a0C5t57D, 1, m, &cVar_a0C5t57D_sendMessage);
}

void Heavy_PhaseRing::cCast_Fa2CfUkO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_ThWyUEg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vXO1Y0w5, 0, m, &cPack_vXO1Y0w5_sendMessage);
}

void Heavy_PhaseRing::cUnop_E34mj6V1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qo3rLzyF, 0, m, &cPack_qo3rLzyF_sendMessage);
}

void Heavy_PhaseRing::cPack_qo3rLzyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_jdBRTLys, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_vXO1Y0w5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tFaKUTQ1, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_Jj1lsaSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_ThWyUEg3_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_E34mj6V1_sendMessage);
}

void Heavy_PhaseRing::cMsg_HHzFZ4kp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_Jj1lsaSD_sendMessage);
}

void Heavy_PhaseRing::cSlice_qF8NwXkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_Fgiul60p_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_Yux3D6Rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VIV44jfs_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_oG3NsJLH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_tBiZVY6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_B6OHCbft_sendMessage);
}

void Heavy_PhaseRing::cBinop_B6OHCbft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_Jj1lsaSD_sendMessage);
}

void Heavy_PhaseRing::cBinop_Fgiul60p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_flUl5EHi_sendMessage(_c, 0, m);
  cSend_ymmN6uoX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_sKFclUIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GisuhC06_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mHzouDHw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JkJAE8Y7, 0, m, &cVar_JkJAE8Y7_sendMessage);
}

void Heavy_PhaseRing::cBinop_s7JNJpI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_YlgAjnVn_sendMessage);
}

void Heavy_PhaseRing::cBinop_YlgAjnVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sKFclUIO, HV_BINOP_MULTIPLY, 1, m, &cBinop_sKFclUIO_sendMessage);
}

void Heavy_PhaseRing::cCast_VIV44jfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UhpRh7AR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_flUl5EHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zWSW9c6q_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_GisuhC06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DC1JMXL8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Fa2CfUkO_sendMessage);
}

void Heavy_PhaseRing::cCast_mHzouDHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Dx4WhREI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_dVCPTIXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LuSlkY39, 0, m, &cPack_LuSlkY39_sendMessage);
}

void Heavy_PhaseRing::cSend_ymmN6uoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9C9lwhQe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_uVZwqJDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jQ4SCrIi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_loDSXbmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_uVZwqJDW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cTabhead_BYgux5Oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QTZ8M9xp, HV_BINOP_SUBTRACT, 0, m, &cBinop_QTZ8M9xp_sendMessage);
}

void Heavy_PhaseRing::cMsg_U34ef6fm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hrwZ6wZe_sendMessage);
}

void Heavy_PhaseRing::cSystem_hrwZ6wZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2cuEBPLH_sendMessage);
}

void Heavy_PhaseRing::cVar_GEdf6bpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JkdQEQ9K_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_hgT3NW6r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hgT3NW6r, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBidMiKv, 0, m, &cDelay_IBidMiKv_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZggRA7SG, 0, m, &sTabread_ZggRA7SG_sendMessage);
}

void Heavy_PhaseRing::cDelay_IBidMiKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IBidMiKv, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZggRA7SG, 0, m, &sTabread_ZggRA7SG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBidMiKv, 0, m, &cDelay_IBidMiKv_sendMessage);
}

void Heavy_PhaseRing::sTabread_ZggRA7SG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZkzYmhCP, HV_BINOP_SUBTRACT, 0, m, &cBinop_ZkzYmhCP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_O45KNWag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eKZnIbVg, HV_BINOP_MAX, 0, m, &cBinop_eKZnIbVg_sendMessage);
}

void Heavy_PhaseRing::cBinop_2cuEBPLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O45KNWag, HV_BINOP_MULTIPLY, 0, m, &cBinop_O45KNWag_sendMessage);
}

void Heavy_PhaseRing::cBinop_QTZ8M9xp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4Di29iyS_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZggRA7SG, 0, m, &sTabread_ZggRA7SG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Kbd2Hsp_sendMessage);
}

void Heavy_PhaseRing::cSystem_a0aCNmtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZkzYmhCP, HV_BINOP_SUBTRACT, 1, m, &cBinop_ZkzYmhCP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBidMiKv, 2, m, &cDelay_IBidMiKv_sendMessage);
}

void Heavy_PhaseRing::cMsg_JkdQEQ9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a0aCNmtb_sendMessage);
}

void Heavy_PhaseRing::cMsg_4Di29iyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hgT3NW6r, 0, m, &cDelay_hgT3NW6r_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBidMiKv, 0, m, &cDelay_IBidMiKv_sendMessage);
}

void Heavy_PhaseRing::cMsg_o5cDOztD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eKZnIbVg, HV_BINOP_MAX, 1, m, &cBinop_eKZnIbVg_sendMessage);
}

void Heavy_PhaseRing::cBinop_eKZnIbVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QTZ8M9xp, HV_BINOP_SUBTRACT, 1, m, &cBinop_QTZ8M9xp_sendMessage);
}

void Heavy_PhaseRing::cCast_1Kbd2Hsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hgT3NW6r, 0, m, &cDelay_hgT3NW6r_sendMessage);
}

void Heavy_PhaseRing::cBinop_G15evnO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hgT3NW6r, 2, m, &cDelay_hgT3NW6r_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZkzYmhCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_G15evnO1_sendMessage);
}

void Heavy_PhaseRing::cCast_QWhv3NGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GEdf6bpL, 0, m, &cVar_GEdf6bpL_sendMessage);
  cMsg_U34ef6fm_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BYgux5Oq, 0, m, &cTabhead_BYgux5Oq_sendMessage);
}

void Heavy_PhaseRing::cTabhead_6K2XfYQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nosz5xHw, HV_BINOP_SUBTRACT, 0, m, &cBinop_Nosz5xHw_sendMessage);
}

void Heavy_PhaseRing::cMsg_gEEbTRSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v7YdHIqJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_v7YdHIqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9vjPeFW8_sendMessage);
}

void Heavy_PhaseRing::cVar_kVzlv21K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EDKeyl4N_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_0eWO4dtB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0eWO4dtB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bodLRQnp, 0, m, &cDelay_bodLRQnp_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9OrIB1ve, 0, m, &sTabread_9OrIB1ve_sendMessage);
}

void Heavy_PhaseRing::cDelay_bodLRQnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bodLRQnp, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9OrIB1ve, 0, m, &sTabread_9OrIB1ve_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bodLRQnp, 0, m, &cDelay_bodLRQnp_sendMessage);
}

void Heavy_PhaseRing::sTabread_9OrIB1ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_s1zHoFGI, HV_BINOP_SUBTRACT, 0, m, &cBinop_s1zHoFGI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_f18bIhPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0Hlv3E3N, HV_BINOP_MAX, 0, m, &cBinop_0Hlv3E3N_sendMessage);
}

void Heavy_PhaseRing::cBinop_9vjPeFW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f18bIhPM, HV_BINOP_MULTIPLY, 0, m, &cBinop_f18bIhPM_sendMessage);
}

void Heavy_PhaseRing::cBinop_Nosz5xHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kTxhrO6J_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9OrIB1ve, 0, m, &sTabread_9OrIB1ve_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JR9G1HPJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_IJQq6bPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s1zHoFGI, HV_BINOP_SUBTRACT, 1, m, &cBinop_s1zHoFGI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bodLRQnp, 2, m, &cDelay_bodLRQnp_sendMessage);
}

void Heavy_PhaseRing::cMsg_EDKeyl4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IJQq6bPc_sendMessage);
}

void Heavy_PhaseRing::cMsg_kTxhrO6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0eWO4dtB, 0, m, &cDelay_0eWO4dtB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bodLRQnp, 0, m, &cDelay_bodLRQnp_sendMessage);
}

void Heavy_PhaseRing::cMsg_A4RHAf2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_0Hlv3E3N, HV_BINOP_MAX, 1, m, &cBinop_0Hlv3E3N_sendMessage);
}

void Heavy_PhaseRing::cBinop_0Hlv3E3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nosz5xHw, HV_BINOP_SUBTRACT, 1, m, &cBinop_Nosz5xHw_sendMessage);
}

void Heavy_PhaseRing::cCast_JR9G1HPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0eWO4dtB, 0, m, &cDelay_0eWO4dtB_sendMessage);
}

void Heavy_PhaseRing::cBinop_m4s4QbrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0eWO4dtB, 2, m, &cDelay_0eWO4dtB_sendMessage);
}

void Heavy_PhaseRing::cBinop_s1zHoFGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_m4s4QbrF_sendMessage);
}

void Heavy_PhaseRing::cCast_Zq4ve8Rz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kVzlv21K, 0, m, &cVar_kVzlv21K_sendMessage);
  cMsg_gEEbTRSc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6K2XfYQA, 0, m, &cTabhead_6K2XfYQA_sendMessage);
}

void Heavy_PhaseRing::cTabhead_WySMg7df_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fw85Oy8a, HV_BINOP_SUBTRACT, 0, m, &cBinop_Fw85Oy8a_sendMessage);
}

void Heavy_PhaseRing::cMsg_cArm9AuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oYBe04oS_sendMessage);
}

void Heavy_PhaseRing::cSystem_oYBe04oS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NcUSX7M9_sendMessage);
}

void Heavy_PhaseRing::cVar_2wGQoAAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m6P67bSF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_3gynYtVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3gynYtVx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4Jp2AHes, 0, m, &cDelay_4Jp2AHes_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oL3oXAzL, 0, m, &sTabread_oL3oXAzL_sendMessage);
}

void Heavy_PhaseRing::cDelay_4Jp2AHes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4Jp2AHes, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oL3oXAzL, 0, m, &sTabread_oL3oXAzL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4Jp2AHes, 0, m, &cDelay_4Jp2AHes_sendMessage);
}

void Heavy_PhaseRing::sTabread_oL3oXAzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bBwkbdfA, HV_BINOP_SUBTRACT, 0, m, &cBinop_bBwkbdfA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_DX4rPrzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z2d0c0oU, HV_BINOP_MAX, 0, m, &cBinop_Z2d0c0oU_sendMessage);
}

void Heavy_PhaseRing::cBinop_NcUSX7M9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DX4rPrzK, HV_BINOP_MULTIPLY, 0, m, &cBinop_DX4rPrzK_sendMessage);
}

void Heavy_PhaseRing::cBinop_Fw85Oy8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6DjMhNL3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oL3oXAzL, 0, m, &sTabread_oL3oXAzL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GHTMO5DN_sendMessage);
}

void Heavy_PhaseRing::cSystem_SCcDyZEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bBwkbdfA, HV_BINOP_SUBTRACT, 1, m, &cBinop_bBwkbdfA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4Jp2AHes, 2, m, &cDelay_4Jp2AHes_sendMessage);
}

void Heavy_PhaseRing::cMsg_m6P67bSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SCcDyZEd_sendMessage);
}

void Heavy_PhaseRing::cMsg_6DjMhNL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3gynYtVx, 0, m, &cDelay_3gynYtVx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4Jp2AHes, 0, m, &cDelay_4Jp2AHes_sendMessage);
}

void Heavy_PhaseRing::cMsg_KsjTkoMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z2d0c0oU, HV_BINOP_MAX, 1, m, &cBinop_Z2d0c0oU_sendMessage);
}

void Heavy_PhaseRing::cBinop_Z2d0c0oU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fw85Oy8a, HV_BINOP_SUBTRACT, 1, m, &cBinop_Fw85Oy8a_sendMessage);
}

void Heavy_PhaseRing::cCast_GHTMO5DN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3gynYtVx, 0, m, &cDelay_3gynYtVx_sendMessage);
}

void Heavy_PhaseRing::cBinop_VXac2tDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3gynYtVx, 2, m, &cDelay_3gynYtVx_sendMessage);
}

void Heavy_PhaseRing::cBinop_bBwkbdfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VXac2tDV_sendMessage);
}

void Heavy_PhaseRing::cCast_WEv1CLKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2wGQoAAH, 0, m, &cVar_2wGQoAAH_sendMessage);
  cMsg_cArm9AuE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WySMg7df, 0, m, &cTabhead_WySMg7df_sendMessage);
}

void Heavy_PhaseRing::cTabhead_FgFI6c4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2u6FhgjV, HV_BINOP_SUBTRACT, 0, m, &cBinop_2u6FhgjV_sendMessage);
}

void Heavy_PhaseRing::cMsg_XRycfCFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R4iA4rV4_sendMessage);
}

void Heavy_PhaseRing::cSystem_R4iA4rV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1w0nwepA_sendMessage);
}

void Heavy_PhaseRing::cVar_TtrsrRUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DjRJNV9J_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_izGum2nb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_izGum2nb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XQGrskAa, 0, m, &cDelay_XQGrskAa_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_QkcD7kLi, 0, m, &sTabread_QkcD7kLi_sendMessage);
}

void Heavy_PhaseRing::cDelay_XQGrskAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XQGrskAa, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_QkcD7kLi, 0, m, &sTabread_QkcD7kLi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XQGrskAa, 0, m, &cDelay_XQGrskAa_sendMessage);
}

void Heavy_PhaseRing::sTabread_QkcD7kLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aYyvgtUe, HV_BINOP_SUBTRACT, 0, m, &cBinop_aYyvgtUe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_NemRpaIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eZbJNWdR, HV_BINOP_MAX, 0, m, &cBinop_eZbJNWdR_sendMessage);
}

void Heavy_PhaseRing::cBinop_1w0nwepA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NemRpaIO, HV_BINOP_MULTIPLY, 0, m, &cBinop_NemRpaIO_sendMessage);
}

void Heavy_PhaseRing::cBinop_2u6FhgjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5GqcJ5oM_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_QkcD7kLi, 0, m, &sTabread_QkcD7kLi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l6kJeLVr_sendMessage);
}

void Heavy_PhaseRing::cSystem_xAUqhQvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aYyvgtUe, HV_BINOP_SUBTRACT, 1, m, &cBinop_aYyvgtUe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XQGrskAa, 2, m, &cDelay_XQGrskAa_sendMessage);
}

void Heavy_PhaseRing::cMsg_DjRJNV9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xAUqhQvX_sendMessage);
}

void Heavy_PhaseRing::cMsg_5GqcJ5oM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_izGum2nb, 0, m, &cDelay_izGum2nb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XQGrskAa, 0, m, &cDelay_XQGrskAa_sendMessage);
}

void Heavy_PhaseRing::cMsg_PLRwd1jq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eZbJNWdR, HV_BINOP_MAX, 1, m, &cBinop_eZbJNWdR_sendMessage);
}

void Heavy_PhaseRing::cBinop_eZbJNWdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2u6FhgjV, HV_BINOP_SUBTRACT, 1, m, &cBinop_2u6FhgjV_sendMessage);
}

void Heavy_PhaseRing::cCast_l6kJeLVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_izGum2nb, 0, m, &cDelay_izGum2nb_sendMessage);
}

void Heavy_PhaseRing::cBinop_EhJ9AuYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_izGum2nb, 2, m, &cDelay_izGum2nb_sendMessage);
}

void Heavy_PhaseRing::cBinop_aYyvgtUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EhJ9AuYS_sendMessage);
}

void Heavy_PhaseRing::cCast_gnYdhGv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TtrsrRUz, 0, m, &cVar_TtrsrRUz_sendMessage);
  cMsg_XRycfCFQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_FgFI6c4S, 0, m, &cTabhead_FgFI6c4S_sendMessage);
}

void Heavy_PhaseRing::cMsg_WsC8d8go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZX9aPIBU_sendMessage);
}

void Heavy_PhaseRing::cSystem_ZX9aPIBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Do3StrO7_sendMessage);
}

void Heavy_PhaseRing::cDelay_Sf9xbtun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Sf9xbtun, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rut3Wyf9, 0, m, &cDelay_rut3Wyf9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Sf9xbtun, 0, m, &cDelay_Sf9xbtun_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2LT0CmVD, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_rut3Wyf9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rut3Wyf9, m);
  cMsg_lmUVS3Rs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_DTyIng2L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_j0giA5gG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_jTQ9WaV8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WoSScBH6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_y1MeZAkG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oVzvygJf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Sf9xbtun, 2, m, &cDelay_Sf9xbtun_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_phJ7acee_sendMessage);
}

void Heavy_PhaseRing::cMsg_WoSScBH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_y1MeZAkG, 0, m, &hTable_y1MeZAkG_sendMessage);
}

void Heavy_PhaseRing::cBinop_Do3StrO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_jTQ9WaV8_sendMessage);
}

void Heavy_PhaseRing::cMsg_lmUVS3Rs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_y1MeZAkG, 0, m, &hTable_y1MeZAkG_sendMessage);
}

void Heavy_PhaseRing::cCast_phJ7acee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Sf9xbtun, 0, m, &cDelay_Sf9xbtun_sendMessage);
}

void Heavy_PhaseRing::cMsg_oVzvygJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rut3Wyf9, 2, m, &cDelay_rut3Wyf9_sendMessage);
}

void Heavy_PhaseRing::cMsg_j0giA5gG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2LT0CmVD, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_RaUK4heB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uwB1Uw7H_sendMessage);
}

void Heavy_PhaseRing::cSystem_uwB1Uw7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_q98Kg10R_sendMessage);
}

void Heavy_PhaseRing::cDelay_bXWugKGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bXWugKGV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kPlAJNHX, 0, m, &cDelay_kPlAJNHX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bXWugKGV, 0, m, &cDelay_bXWugKGV_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oOFBrGBM, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_kPlAJNHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kPlAJNHX, m);
  cMsg_p6bpVEn7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_gzpXhasf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_t8tiElYE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_bR3Mj3pg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vFhT7BAE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_yigFpQR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZO76cjAL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bXWugKGV, 2, m, &cDelay_bXWugKGV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gaYJFfx7_sendMessage);
}

void Heavy_PhaseRing::cMsg_vFhT7BAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_yigFpQR5, 0, m, &hTable_yigFpQR5_sendMessage);
}

void Heavy_PhaseRing::cBinop_q98Kg10R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_bR3Mj3pg_sendMessage);
}

void Heavy_PhaseRing::cMsg_p6bpVEn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_yigFpQR5, 0, m, &hTable_yigFpQR5_sendMessage);
}

void Heavy_PhaseRing::cCast_gaYJFfx7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bXWugKGV, 0, m, &cDelay_bXWugKGV_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZO76cjAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kPlAJNHX, 2, m, &cDelay_kPlAJNHX_sendMessage);
}

void Heavy_PhaseRing::cMsg_t8tiElYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oOFBrGBM, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_TfSThw4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sUyrGyV3_sendMessage);
}

void Heavy_PhaseRing::cSystem_sUyrGyV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gcVu9Erq_sendMessage);
}

void Heavy_PhaseRing::cDelay_ymEt5vAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ymEt5vAC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SaZyNKPa, 0, m, &cDelay_SaZyNKPa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymEt5vAC, 0, m, &cDelay_ymEt5vAC_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_UHLTxjB1, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_SaZyNKPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SaZyNKPa, m);
  cMsg_EMBCyJMu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_IEAhcDlK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_7hq4WavR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_n0NuJjXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HA8BTP5d_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_ZxLjdfs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lbjt8JZA_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymEt5vAC, 2, m, &cDelay_ymEt5vAC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zSeBHbAd_sendMessage);
}

void Heavy_PhaseRing::cMsg_HA8BTP5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ZxLjdfs4, 0, m, &hTable_ZxLjdfs4_sendMessage);
}

void Heavy_PhaseRing::cBinop_gcVu9Erq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_n0NuJjXx_sendMessage);
}

void Heavy_PhaseRing::cMsg_EMBCyJMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ZxLjdfs4, 0, m, &hTable_ZxLjdfs4_sendMessage);
}

void Heavy_PhaseRing::cCast_zSeBHbAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymEt5vAC, 0, m, &cDelay_ymEt5vAC_sendMessage);
}

void Heavy_PhaseRing::cMsg_lbjt8JZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_SaZyNKPa, 2, m, &cDelay_SaZyNKPa_sendMessage);
}

void Heavy_PhaseRing::cMsg_7hq4WavR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_UHLTxjB1, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_kj6sstMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mjegocZh_sendMessage);
}

void Heavy_PhaseRing::cSystem_mjegocZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AIoCvJdn_sendMessage);
}

void Heavy_PhaseRing::cDelay_OY4hgbW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OY4hgbW5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LwkCRlrs, 0, m, &cDelay_LwkCRlrs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OY4hgbW5, 0, m, &cDelay_OY4hgbW5_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rDLu65vc, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_LwkCRlrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LwkCRlrs, m);
  cMsg_28zTMxFj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_c3isXck4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_t0epJPOm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_hJBQkBDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3DM7tV6R_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_oqNTpXpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8XMH3csj_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OY4hgbW5, 2, m, &cDelay_OY4hgbW5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2CEUt6RE_sendMessage);
}

void Heavy_PhaseRing::cMsg_3DM7tV6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_oqNTpXpC, 0, m, &hTable_oqNTpXpC_sendMessage);
}

void Heavy_PhaseRing::cBinop_AIoCvJdn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_hJBQkBDB_sendMessage);
}

void Heavy_PhaseRing::cMsg_28zTMxFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_oqNTpXpC, 0, m, &hTable_oqNTpXpC_sendMessage);
}

void Heavy_PhaseRing::cCast_2CEUt6RE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OY4hgbW5, 0, m, &cDelay_OY4hgbW5_sendMessage);
}

void Heavy_PhaseRing::cMsg_8XMH3csj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_LwkCRlrs, 2, m, &cDelay_LwkCRlrs_sendMessage);
}

void Heavy_PhaseRing::cMsg_t0epJPOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rDLu65vc, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_nxG0vYAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ZAkDfo6M_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_3KYZgLGJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_9BFBFdqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_M8GTCZXo, HV_BINOP_POW, 0, m, &cBinop_M8GTCZXo_sendMessage);
}

void Heavy_PhaseRing::cBinop_M8GTCZXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_Wulf8gj1_sendMessage);
}

void Heavy_PhaseRing::cBinop_1P36TXSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_XYjUtyWx_sendMessage);
}

void Heavy_PhaseRing::cCast_LBtWH6o8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nxG0vYAO, 0, m, &cIf_nxG0vYAO_sendMessage);
}

void Heavy_PhaseRing::cCast_LGqxpKTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_jjSltIeY_sendMessage);
}

void Heavy_PhaseRing::cBinop_jjSltIeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nxG0vYAO, 1, m, &cIf_nxG0vYAO_sendMessage);
}

void Heavy_PhaseRing::cBinop_3KYZgLGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_1P36TXSk_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZAkDfo6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_Wulf8gj1_sendMessage);
}

void Heavy_PhaseRing::cBinop_XYjUtyWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M8GTCZXo, HV_BINOP_POW, 1, m, &cBinop_M8GTCZXo_sendMessage);
  cMsg_9BFBFdqx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_3AWggFEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uczCl8Bb, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_3r0DAcAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hqq5T9bD, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_XWZIl8pJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nleJHqJf_sendMessage);
}

void Heavy_PhaseRing::cBinop_nleJHqJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_OlE0cMrs_sendMessage);
}

void Heavy_PhaseRing::cVar_wDbWzIo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ii2zWj5D, HV_BINOP_MULTIPLY, 0, m, &cBinop_ii2zWj5D_sendMessage);
}

void Heavy_PhaseRing::cMsg_uqwfD6KP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kDiQT3Qm_sendMessage);
}

void Heavy_PhaseRing::cSystem_kDiQT3Qm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B5RQYscR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_ii2zWj5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_b2H3Tjzz_sendMessage);
}

void Heavy_PhaseRing::cBinop_boa1ocJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ii2zWj5D, HV_BINOP_MULTIPLY, 1, m, &cBinop_ii2zWj5D_sendMessage);
}

void Heavy_PhaseRing::cMsg_B5RQYscR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_boa1ocJg_sendMessage);
}

void Heavy_PhaseRing::cBinop_b2H3Tjzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tDlRJqVA_sendMessage);
}

void Heavy_PhaseRing::cBinop_tDlRJqVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_J4w9Oh2n_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_O2HDUS1L, m);
}

void Heavy_PhaseRing::cBinop_J4w9Oh2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Wi3Pu2Va, m);
}

void Heavy_PhaseRing::cVar_iptQFL2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LGqxpKTd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LBtWH6o8_sendMessage);
}

void Heavy_PhaseRing::cVar_b1EcaFfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_XWZIl8pJ_sendMessage);
}

void Heavy_PhaseRing::cVar_i23Hm69o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_ww9ne0gU_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_HBCc6rVn, 0, m, &cIf_HBCc6rVn_sendMessage);
}

void Heavy_PhaseRing::cVar_qDBY6K7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_BmrYyC0X_sendMessage);
}

void Heavy_PhaseRing::cIf_HBCc6rVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_73OZhWm4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_2OBOFhSR, 0, m, &cVar_2OBOFhSR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ww9ne0gU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HBCc6rVn, 1, m, &cIf_HBCc6rVn_sendMessage);
}

void Heavy_PhaseRing::cBinop_BmrYyC0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_SryQvzdj_sendMessage);
}

void Heavy_PhaseRing::cBinop_SryQvzdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aAxVeNc5, 0, m, &cVar_aAxVeNc5_sendMessage);
}

void Heavy_PhaseRing::cTabhead_LXChfygy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vv26S1sg, HV_BINOP_SUBTRACT, 0, m, &cBinop_vv26S1sg_sendMessage);
}

void Heavy_PhaseRing::cMsg_11VL7I23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2rzOAZgO_sendMessage);
}

void Heavy_PhaseRing::cSystem_2rzOAZgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_f5J6Wsg1_sendMessage);
}

void Heavy_PhaseRing::cVar_cEXPc9kM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Cb3MU8Di_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_zJATlGww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zJATlGww, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BZHBFkW6, 0, m, &cDelay_BZHBFkW6_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vcfVl5kT, 0, m, &sTabread_vcfVl5kT_sendMessage);
}

void Heavy_PhaseRing::cDelay_BZHBFkW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BZHBFkW6, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vcfVl5kT, 0, m, &sTabread_vcfVl5kT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BZHBFkW6, 0, m, &cDelay_BZHBFkW6_sendMessage);
}

void Heavy_PhaseRing::sTabread_vcfVl5kT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KyCYslyP, HV_BINOP_SUBTRACT, 0, m, &cBinop_KyCYslyP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_cRYIaxcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SVyw6Qgd, HV_BINOP_MAX, 0, m, &cBinop_SVyw6Qgd_sendMessage);
}

void Heavy_PhaseRing::cBinop_f5J6Wsg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cRYIaxcp, HV_BINOP_MULTIPLY, 0, m, &cBinop_cRYIaxcp_sendMessage);
}

void Heavy_PhaseRing::cBinop_vv26S1sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CEvPXpVR_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vcfVl5kT, 0, m, &sTabread_vcfVl5kT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8mMPck2m_sendMessage);
}

void Heavy_PhaseRing::cSystem_i5h0rLFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KyCYslyP, HV_BINOP_SUBTRACT, 1, m, &cBinop_KyCYslyP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BZHBFkW6, 2, m, &cDelay_BZHBFkW6_sendMessage);
}

void Heavy_PhaseRing::cMsg_Cb3MU8Di_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_i5h0rLFH_sendMessage);
}

void Heavy_PhaseRing::cMsg_CEvPXpVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zJATlGww, 0, m, &cDelay_zJATlGww_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BZHBFkW6, 0, m, &cDelay_BZHBFkW6_sendMessage);
}

void Heavy_PhaseRing::cMsg_6r5d4yRf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_SVyw6Qgd, HV_BINOP_MAX, 1, m, &cBinop_SVyw6Qgd_sendMessage);
}

void Heavy_PhaseRing::cBinop_SVyw6Qgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vv26S1sg, HV_BINOP_SUBTRACT, 1, m, &cBinop_vv26S1sg_sendMessage);
}

void Heavy_PhaseRing::cCast_8mMPck2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zJATlGww, 0, m, &cDelay_zJATlGww_sendMessage);
}

void Heavy_PhaseRing::cBinop_OPGmmxNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zJATlGww, 2, m, &cDelay_zJATlGww_sendMessage);
}

void Heavy_PhaseRing::cBinop_KyCYslyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OPGmmxNz_sendMessage);
}

void Heavy_PhaseRing::cCast_XCqEybaJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cEXPc9kM, 0, m, &cVar_cEXPc9kM_sendMessage);
  cMsg_11VL7I23_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LXChfygy, 0, m, &cTabhead_LXChfygy_sendMessage);
}

void Heavy_PhaseRing::cMsg_v7LF9BG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HVjHsOP8_sendMessage);
}

void Heavy_PhaseRing::cSystem_HVjHsOP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uMoVq96n_sendMessage);
}

void Heavy_PhaseRing::cDelay_rvsMNb54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rvsMNb54, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3V59cZIB, 0, m, &cDelay_3V59cZIB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rvsMNb54, 0, m, &cDelay_rvsMNb54_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fAgtdIR4, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_3V59cZIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3V59cZIB, m);
  cMsg_udwhKKKG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_7aWkhZh5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_9u6nuEFn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_Yx26KZpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_efE8jIb1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_zb1j4ZzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E7chOQkz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rvsMNb54, 2, m, &cDelay_rvsMNb54_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oL37ujGy_sendMessage);
}

void Heavy_PhaseRing::cMsg_efE8jIb1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_zb1j4ZzD, 0, m, &hTable_zb1j4ZzD_sendMessage);
}

void Heavy_PhaseRing::cBinop_uMoVq96n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_Yx26KZpP_sendMessage);
}

void Heavy_PhaseRing::cMsg_udwhKKKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_zb1j4ZzD, 0, m, &hTable_zb1j4ZzD_sendMessage);
}

void Heavy_PhaseRing::cCast_oL37ujGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rvsMNb54, 0, m, &cDelay_rvsMNb54_sendMessage);
}

void Heavy_PhaseRing::cMsg_E7chOQkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_3V59cZIB, 2, m, &cDelay_3V59cZIB_sendMessage);
}

void Heavy_PhaseRing::cMsg_9u6nuEFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fAgtdIR4, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_ggO7hi4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xEvw6OBE, HV_BINOP_SUBTRACT, 0, m, &cBinop_xEvw6OBE_sendMessage);
}

void Heavy_PhaseRing::cMsg_oKsoNFDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_US4rgV84_sendMessage);
}

void Heavy_PhaseRing::cSystem_US4rgV84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qRFf9f2A_sendMessage);
}

void Heavy_PhaseRing::cVar_mJ0OorsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KCNFTWHl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_Anzcazll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Anzcazll, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bqeEH4DY, 0, m, &cDelay_bqeEH4DY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jc6umH7j, 0, m, &sTabread_Jc6umH7j_sendMessage);
}

void Heavy_PhaseRing::cDelay_bqeEH4DY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bqeEH4DY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jc6umH7j, 0, m, &sTabread_Jc6umH7j_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bqeEH4DY, 0, m, &cDelay_bqeEH4DY_sendMessage);
}

void Heavy_PhaseRing::sTabread_Jc6umH7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JOK63hrr, HV_BINOP_SUBTRACT, 0, m, &cBinop_JOK63hrr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_n4WUtnTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RIuZIUXv, HV_BINOP_MAX, 0, m, &cBinop_RIuZIUXv_sendMessage);
}

void Heavy_PhaseRing::cBinop_qRFf9f2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n4WUtnTv, HV_BINOP_MULTIPLY, 0, m, &cBinop_n4WUtnTv_sendMessage);
}

void Heavy_PhaseRing::cBinop_xEvw6OBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zX5jjJWN_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jc6umH7j, 0, m, &sTabread_Jc6umH7j_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wHNHijWB_sendMessage);
}

void Heavy_PhaseRing::cSystem_CLjlSiBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JOK63hrr, HV_BINOP_SUBTRACT, 1, m, &cBinop_JOK63hrr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bqeEH4DY, 2, m, &cDelay_bqeEH4DY_sendMessage);
}

void Heavy_PhaseRing::cMsg_KCNFTWHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CLjlSiBU_sendMessage);
}

void Heavy_PhaseRing::cMsg_zX5jjJWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Anzcazll, 0, m, &cDelay_Anzcazll_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bqeEH4DY, 0, m, &cDelay_bqeEH4DY_sendMessage);
}

void Heavy_PhaseRing::cMsg_0IzHPtqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_RIuZIUXv, HV_BINOP_MAX, 1, m, &cBinop_RIuZIUXv_sendMessage);
}

void Heavy_PhaseRing::cBinop_RIuZIUXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xEvw6OBE, HV_BINOP_SUBTRACT, 1, m, &cBinop_xEvw6OBE_sendMessage);
}

void Heavy_PhaseRing::cCast_wHNHijWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Anzcazll, 0, m, &cDelay_Anzcazll_sendMessage);
}

void Heavy_PhaseRing::cBinop_uFGlsHOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Anzcazll, 2, m, &cDelay_Anzcazll_sendMessage);
}

void Heavy_PhaseRing::cBinop_JOK63hrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uFGlsHOC_sendMessage);
}

void Heavy_PhaseRing::cCast_TiuCbhaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mJ0OorsZ, 0, m, &cVar_mJ0OorsZ_sendMessage);
  cMsg_oKsoNFDw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ggO7hi4g, 0, m, &cTabhead_ggO7hi4g_sendMessage);
}

void Heavy_PhaseRing::cMsg_BvaxlHgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uqM1LXmq_sendMessage);
}

void Heavy_PhaseRing::cSystem_uqM1LXmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JPdk0mMJ_sendMessage);
}

void Heavy_PhaseRing::cDelay_pUkbWCoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pUkbWCoB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZuI8pMie, 0, m, &cDelay_ZuI8pMie_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pUkbWCoB, 0, m, &cDelay_pUkbWCoB_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2XqCi3im, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_ZuI8pMie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZuI8pMie, m);
  cMsg_KzMtKhXd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_c8RIh3PM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_X4kpzilL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_RYoDygvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bUPFgVww_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_SQbnfU0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eYV30wYG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pUkbWCoB, 2, m, &cDelay_pUkbWCoB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KcLxzCcg_sendMessage);
}

void Heavy_PhaseRing::cMsg_bUPFgVww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_SQbnfU0T, 0, m, &hTable_SQbnfU0T_sendMessage);
}

void Heavy_PhaseRing::cBinop_JPdk0mMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_RYoDygvw_sendMessage);
}

void Heavy_PhaseRing::cMsg_KzMtKhXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_SQbnfU0T, 0, m, &hTable_SQbnfU0T_sendMessage);
}

void Heavy_PhaseRing::cCast_KcLxzCcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pUkbWCoB, 0, m, &cDelay_pUkbWCoB_sendMessage);
}

void Heavy_PhaseRing::cMsg_eYV30wYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZuI8pMie, 2, m, &cDelay_ZuI8pMie_sendMessage);
}

void Heavy_PhaseRing::cMsg_X4kpzilL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2XqCi3im, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_udg83ApF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E6BfF2qa, HV_BINOP_SUBTRACT, 0, m, &cBinop_E6BfF2qa_sendMessage);
}

void Heavy_PhaseRing::cMsg_4xUyKQ9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ozIeuZM0_sendMessage);
}

void Heavy_PhaseRing::cSystem_ozIeuZM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hWu3pVLb_sendMessage);
}

void Heavy_PhaseRing::cVar_Gwt1SnHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UNDiRtIm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_FvDlChTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FvDlChTZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wcLoSYT4, 0, m, &cDelay_wcLoSYT4_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hfYqkB9J, 0, m, &sTabread_hfYqkB9J_sendMessage);
}

void Heavy_PhaseRing::cDelay_wcLoSYT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wcLoSYT4, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hfYqkB9J, 0, m, &sTabread_hfYqkB9J_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wcLoSYT4, 0, m, &cDelay_wcLoSYT4_sendMessage);
}

void Heavy_PhaseRing::sTabread_hfYqkB9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JsL97K5f, HV_BINOP_SUBTRACT, 0, m, &cBinop_JsL97K5f_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_QQf1nRhb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9RhtbeH4, HV_BINOP_MAX, 0, m, &cBinop_9RhtbeH4_sendMessage);
}

void Heavy_PhaseRing::cBinop_hWu3pVLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QQf1nRhb, HV_BINOP_MULTIPLY, 0, m, &cBinop_QQf1nRhb_sendMessage);
}

void Heavy_PhaseRing::cBinop_E6BfF2qa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3VXezZq9_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hfYqkB9J, 0, m, &sTabread_hfYqkB9J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Fq04iZmZ_sendMessage);
}

void Heavy_PhaseRing::cSystem_3xFBaHfy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JsL97K5f, HV_BINOP_SUBTRACT, 1, m, &cBinop_JsL97K5f_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wcLoSYT4, 2, m, &cDelay_wcLoSYT4_sendMessage);
}

void Heavy_PhaseRing::cMsg_UNDiRtIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3xFBaHfy_sendMessage);
}

void Heavy_PhaseRing::cMsg_3VXezZq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FvDlChTZ, 0, m, &cDelay_FvDlChTZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wcLoSYT4, 0, m, &cDelay_wcLoSYT4_sendMessage);
}

void Heavy_PhaseRing::cMsg_ap2bwsNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9RhtbeH4, HV_BINOP_MAX, 1, m, &cBinop_9RhtbeH4_sendMessage);
}

void Heavy_PhaseRing::cBinop_9RhtbeH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E6BfF2qa, HV_BINOP_SUBTRACT, 1, m, &cBinop_E6BfF2qa_sendMessage);
}

void Heavy_PhaseRing::cCast_Fq04iZmZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FvDlChTZ, 0, m, &cDelay_FvDlChTZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_61GDZlUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FvDlChTZ, 2, m, &cDelay_FvDlChTZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_JsL97K5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_61GDZlUs_sendMessage);
}

void Heavy_PhaseRing::cCast_7LCl0YNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Gwt1SnHS, 0, m, &cVar_Gwt1SnHS_sendMessage);
  cMsg_4xUyKQ9r_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_udg83ApF, 0, m, &cTabhead_udg83ApF_sendMessage);
}

void Heavy_PhaseRing::cMsg_1vuTp3PH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_T4DwdjfN_sendMessage);
}

void Heavy_PhaseRing::cSystem_T4DwdjfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_k93Bsvwb_sendMessage);
}

void Heavy_PhaseRing::cDelay_NZTHSGjx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NZTHSGjx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cuvfTpcL, 0, m, &cDelay_cuvfTpcL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NZTHSGjx, 0, m, &cDelay_NZTHSGjx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_G0xOtQci, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_cuvfTpcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cuvfTpcL, m);
  cMsg_Y0W3M8ro_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_meMaCdSs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_bvKPoc9g_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_Gge09UZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CU5EBosf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_EAyjGHbb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DHpBsfuy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NZTHSGjx, 2, m, &cDelay_NZTHSGjx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oZvgQLkc_sendMessage);
}

void Heavy_PhaseRing::cMsg_CU5EBosf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EAyjGHbb, 0, m, &hTable_EAyjGHbb_sendMessage);
}

void Heavy_PhaseRing::cBinop_k93Bsvwb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_Gge09UZD_sendMessage);
}

void Heavy_PhaseRing::cMsg_Y0W3M8ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EAyjGHbb, 0, m, &hTable_EAyjGHbb_sendMessage);
}

void Heavy_PhaseRing::cCast_oZvgQLkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NZTHSGjx, 0, m, &cDelay_NZTHSGjx_sendMessage);
}

void Heavy_PhaseRing::cMsg_DHpBsfuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cuvfTpcL, 2, m, &cDelay_cuvfTpcL_sendMessage);
}

void Heavy_PhaseRing::cMsg_bvKPoc9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_G0xOtQci, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_YKHEZJwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yzmlC2hh, HV_BINOP_SUBTRACT, 0, m, &cBinop_yzmlC2hh_sendMessage);
}

void Heavy_PhaseRing::cMsg_XjDxWQFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IwrYIP3y_sendMessage);
}

void Heavy_PhaseRing::cSystem_IwrYIP3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KuG9gVAk_sendMessage);
}

void Heavy_PhaseRing::cVar_RBftZ2Bb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BXQpZOJF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_JThtMW5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JThtMW5N, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lryKgDks, 0, m, &cDelay_lryKgDks_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_MjvOKsH4, 0, m, &sTabread_MjvOKsH4_sendMessage);
}

void Heavy_PhaseRing::cDelay_lryKgDks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lryKgDks, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_MjvOKsH4, 0, m, &sTabread_MjvOKsH4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lryKgDks, 0, m, &cDelay_lryKgDks_sendMessage);
}

void Heavy_PhaseRing::sTabread_MjvOKsH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_EnifgKdV, HV_BINOP_SUBTRACT, 0, m, &cBinop_EnifgKdV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_izXiUbcQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a7UdzStv, HV_BINOP_MAX, 0, m, &cBinop_a7UdzStv_sendMessage);
}

void Heavy_PhaseRing::cBinop_KuG9gVAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_izXiUbcQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_izXiUbcQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_yzmlC2hh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fdw7LG86_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_MjvOKsH4, 0, m, &sTabread_MjvOKsH4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qOOnhPdL_sendMessage);
}

void Heavy_PhaseRing::cSystem_znvlHblu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EnifgKdV, HV_BINOP_SUBTRACT, 1, m, &cBinop_EnifgKdV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lryKgDks, 2, m, &cDelay_lryKgDks_sendMessage);
}

void Heavy_PhaseRing::cMsg_BXQpZOJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_znvlHblu_sendMessage);
}

void Heavy_PhaseRing::cMsg_Fdw7LG86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JThtMW5N, 0, m, &cDelay_JThtMW5N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lryKgDks, 0, m, &cDelay_lryKgDks_sendMessage);
}

void Heavy_PhaseRing::cMsg_cdZQbr5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_a7UdzStv, HV_BINOP_MAX, 1, m, &cBinop_a7UdzStv_sendMessage);
}

void Heavy_PhaseRing::cBinop_a7UdzStv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yzmlC2hh, HV_BINOP_SUBTRACT, 1, m, &cBinop_yzmlC2hh_sendMessage);
}

void Heavy_PhaseRing::cCast_qOOnhPdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JThtMW5N, 0, m, &cDelay_JThtMW5N_sendMessage);
}

void Heavy_PhaseRing::cBinop_c3qcwxO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JThtMW5N, 2, m, &cDelay_JThtMW5N_sendMessage);
}

void Heavy_PhaseRing::cBinop_EnifgKdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_c3qcwxO0_sendMessage);
}

void Heavy_PhaseRing::cCast_uV1saxV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RBftZ2Bb, 0, m, &cVar_RBftZ2Bb_sendMessage);
  cMsg_XjDxWQFv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YKHEZJwr, 0, m, &cTabhead_YKHEZJwr_sendMessage);
}

void Heavy_PhaseRing::cMsg_d4LsMhDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OGHb4bCJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_OGHb4bCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SR8tpf3U_sendMessage);
}

void Heavy_PhaseRing::cDelay_vtmqkqXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vtmqkqXf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TmZZs2UG, 0, m, &cDelay_TmZZs2UG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vtmqkqXf, 0, m, &cDelay_vtmqkqXf_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AHXOGdjc, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_TmZZs2UG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TmZZs2UG, m);
  cMsg_GU42iwXb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_bewYbCG0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_YUEzgY8y_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_GMYSGIN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bAXJPCXQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_usOFQLK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JeaZa92v_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vtmqkqXf, 2, m, &cDelay_vtmqkqXf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J8337EiQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_bAXJPCXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_usOFQLK0, 0, m, &hTable_usOFQLK0_sendMessage);
}

void Heavy_PhaseRing::cBinop_SR8tpf3U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_GMYSGIN3_sendMessage);
}

void Heavy_PhaseRing::cMsg_GU42iwXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_usOFQLK0, 0, m, &hTable_usOFQLK0_sendMessage);
}

void Heavy_PhaseRing::cCast_J8337EiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vtmqkqXf, 0, m, &cDelay_vtmqkqXf_sendMessage);
}

void Heavy_PhaseRing::cMsg_JeaZa92v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_TmZZs2UG, 2, m, &cDelay_TmZZs2UG_sendMessage);
}

void Heavy_PhaseRing::cMsg_YUEzgY8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AHXOGdjc, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_TOKDBC1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YCvdQHEE, HV_BINOP_SUBTRACT, 0, m, &cBinop_YCvdQHEE_sendMessage);
}

void Heavy_PhaseRing::cMsg_ECkTKNzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Yb29pL2U_sendMessage);
}

void Heavy_PhaseRing::cSystem_Yb29pL2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fbUW38uw_sendMessage);
}

void Heavy_PhaseRing::cVar_KNKreDi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TMbGNUNM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_dEWsQpeX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dEWsQpeX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nv5UMYvg, 0, m, &cDelay_nv5UMYvg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vmArbZ7O, 0, m, &sTabread_vmArbZ7O_sendMessage);
}

void Heavy_PhaseRing::cDelay_nv5UMYvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nv5UMYvg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vmArbZ7O, 0, m, &sTabread_vmArbZ7O_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nv5UMYvg, 0, m, &cDelay_nv5UMYvg_sendMessage);
}

void Heavy_PhaseRing::sTabread_vmArbZ7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_AjE6Iafk, HV_BINOP_SUBTRACT, 0, m, &cBinop_AjE6Iafk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_f9icJ1ME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sY2qTzQ4, HV_BINOP_MAX, 0, m, &cBinop_sY2qTzQ4_sendMessage);
}

void Heavy_PhaseRing::cBinop_fbUW38uw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f9icJ1ME, HV_BINOP_MULTIPLY, 0, m, &cBinop_f9icJ1ME_sendMessage);
}

void Heavy_PhaseRing::cBinop_YCvdQHEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vU4VYkg5_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vmArbZ7O, 0, m, &sTabread_vmArbZ7O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SOMuE1kv_sendMessage);
}

void Heavy_PhaseRing::cSystem_iMNRyYBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AjE6Iafk, HV_BINOP_SUBTRACT, 1, m, &cBinop_AjE6Iafk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nv5UMYvg, 2, m, &cDelay_nv5UMYvg_sendMessage);
}

void Heavy_PhaseRing::cMsg_TMbGNUNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iMNRyYBO_sendMessage);
}

void Heavy_PhaseRing::cMsg_vU4VYkg5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_dEWsQpeX, 0, m, &cDelay_dEWsQpeX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nv5UMYvg, 0, m, &cDelay_nv5UMYvg_sendMessage);
}

void Heavy_PhaseRing::cMsg_FGlhPJJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_sY2qTzQ4, HV_BINOP_MAX, 1, m, &cBinop_sY2qTzQ4_sendMessage);
}

void Heavy_PhaseRing::cBinop_sY2qTzQ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YCvdQHEE, HV_BINOP_SUBTRACT, 1, m, &cBinop_YCvdQHEE_sendMessage);
}

void Heavy_PhaseRing::cCast_SOMuE1kv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dEWsQpeX, 0, m, &cDelay_dEWsQpeX_sendMessage);
}

void Heavy_PhaseRing::cBinop_SqqaSz3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dEWsQpeX, 2, m, &cDelay_dEWsQpeX_sendMessage);
}

void Heavy_PhaseRing::cBinop_AjE6Iafk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SqqaSz3d_sendMessage);
}

void Heavy_PhaseRing::cCast_Dbh1alVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KNKreDi4, 0, m, &cVar_KNKreDi4_sendMessage);
  cMsg_ECkTKNzS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TOKDBC1h, 0, m, &cTabhead_TOKDBC1h_sendMessage);
}

void Heavy_PhaseRing::cMsg_S5EKogOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5UfkW49r_sendMessage);
}

void Heavy_PhaseRing::cSystem_5UfkW49r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hVq70FBo_sendMessage);
}

void Heavy_PhaseRing::cDelay_OlSSbLWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OlSSbLWC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2joOFbZo, 0, m, &cDelay_2joOFbZo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OlSSbLWC, 0, m, &cDelay_OlSSbLWC_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_N6QpS2QX, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_2joOFbZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2joOFbZo, m);
  cMsg_LJmVE8wz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_AcKdIved_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_hNnbQQ8o_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_od3U0To1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FpuaftQI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_ESGkFV4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UrvVOeCN_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OlSSbLWC, 2, m, &cDelay_OlSSbLWC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IL7YexbU_sendMessage);
}

void Heavy_PhaseRing::cMsg_FpuaftQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ESGkFV4S, 0, m, &hTable_ESGkFV4S_sendMessage);
}

void Heavy_PhaseRing::cBinop_hVq70FBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_od3U0To1_sendMessage);
}

void Heavy_PhaseRing::cMsg_LJmVE8wz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ESGkFV4S, 0, m, &hTable_ESGkFV4S_sendMessage);
}

void Heavy_PhaseRing::cCast_IL7YexbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OlSSbLWC, 0, m, &cDelay_OlSSbLWC_sendMessage);
}

void Heavy_PhaseRing::cMsg_UrvVOeCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2joOFbZo, 2, m, &cDelay_2joOFbZo_sendMessage);
}

void Heavy_PhaseRing::cMsg_hNnbQQ8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_N6QpS2QX, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_gfjZHwzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lqDGvsWQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_lqDGvsWQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_mRap76vv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TlDaY0pG_sendMessage);
}

void Heavy_PhaseRing::cSystem_TlDaY0pG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7RNbZuJh_sendMessage);
}

void Heavy_PhaseRing::cVar_JjLZDyxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t2KBZifv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_vTOOvAEb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vTOOvAEb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nRRssa8x, 0, m, &cDelay_nRRssa8x_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aSfpeIZ0, 0, m, &sTabread_aSfpeIZ0_sendMessage);
}

void Heavy_PhaseRing::cDelay_nRRssa8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nRRssa8x, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aSfpeIZ0, 0, m, &sTabread_aSfpeIZ0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nRRssa8x, 0, m, &cDelay_nRRssa8x_sendMessage);
}

void Heavy_PhaseRing::sTabread_aSfpeIZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_iNAjqnLt, HV_BINOP_SUBTRACT, 0, m, &cBinop_iNAjqnLt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_J8fVevAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4OPIvG2F, HV_BINOP_MAX, 0, m, &cBinop_4OPIvG2F_sendMessage);
}

void Heavy_PhaseRing::cBinop_7RNbZuJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J8fVevAF, HV_BINOP_MULTIPLY, 0, m, &cBinop_J8fVevAF_sendMessage);
}

void Heavy_PhaseRing::cBinop_lqDGvsWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JpcRwNbN_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aSfpeIZ0, 0, m, &sTabread_aSfpeIZ0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ywxUszOx_sendMessage);
}

void Heavy_PhaseRing::cSystem_0s4v5SYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iNAjqnLt, HV_BINOP_SUBTRACT, 1, m, &cBinop_iNAjqnLt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nRRssa8x, 2, m, &cDelay_nRRssa8x_sendMessage);
}

void Heavy_PhaseRing::cMsg_t2KBZifv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0s4v5SYx_sendMessage);
}

void Heavy_PhaseRing::cMsg_JpcRwNbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_vTOOvAEb, 0, m, &cDelay_vTOOvAEb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nRRssa8x, 0, m, &cDelay_nRRssa8x_sendMessage);
}

void Heavy_PhaseRing::cMsg_JiThA3VA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_4OPIvG2F, HV_BINOP_MAX, 1, m, &cBinop_4OPIvG2F_sendMessage);
}

void Heavy_PhaseRing::cBinop_4OPIvG2F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lqDGvsWQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_lqDGvsWQ_sendMessage);
}

void Heavy_PhaseRing::cCast_ywxUszOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vTOOvAEb, 0, m, &cDelay_vTOOvAEb_sendMessage);
}

void Heavy_PhaseRing::cBinop_d0sDOYzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vTOOvAEb, 2, m, &cDelay_vTOOvAEb_sendMessage);
}

void Heavy_PhaseRing::cBinop_iNAjqnLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_d0sDOYzl_sendMessage);
}

void Heavy_PhaseRing::cCast_tFcOHFYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JjLZDyxy, 0, m, &cVar_JjLZDyxy_sendMessage);
  cMsg_mRap76vv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_gfjZHwzk, 0, m, &cTabhead_gfjZHwzk_sendMessage);
}

void Heavy_PhaseRing::cMsg_pOcmV89g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_C0ORxk1g_sendMessage);
}

void Heavy_PhaseRing::cSystem_C0ORxk1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2GE6lNC4_sendMessage);
}

void Heavy_PhaseRing::cDelay_T3krYsxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_T3krYsxd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XchXaKTx, 0, m, &cDelay_XchXaKTx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T3krYsxd, 0, m, &cDelay_T3krYsxd_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7m4vRAFI, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_XchXaKTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XchXaKTx, m);
  cMsg_StOCzmMz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_BMCFnDOZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6cJnkZao_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_PQhvvYFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2B2v81jS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_q9Y5tQmo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gfK1kA2k_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T3krYsxd, 2, m, &cDelay_T3krYsxd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CKsSlWml_sendMessage);
}

void Heavy_PhaseRing::cMsg_2B2v81jS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_q9Y5tQmo, 0, m, &hTable_q9Y5tQmo_sendMessage);
}

void Heavy_PhaseRing::cBinop_2GE6lNC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_PQhvvYFx_sendMessage);
}

void Heavy_PhaseRing::cMsg_StOCzmMz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_q9Y5tQmo, 0, m, &hTable_q9Y5tQmo_sendMessage);
}

void Heavy_PhaseRing::cCast_CKsSlWml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_T3krYsxd, 0, m, &cDelay_T3krYsxd_sendMessage);
}

void Heavy_PhaseRing::cMsg_gfK1kA2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XchXaKTx, 2, m, &cDelay_XchXaKTx_sendMessage);
}

void Heavy_PhaseRing::cMsg_6cJnkZao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7m4vRAFI, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_2OBOFhSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wDbWzIo5, 0, m, &cVar_wDbWzIo5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YLkeXdUk, 0, m, &cVar_YLkeXdUk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T04K6Uie, 0, m, &cVar_T04K6Uie_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_feJloJKb, 0, m, &cVar_feJloJKb_sendMessage);
}

void Heavy_PhaseRing::cVar_aAxVeNc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_1JqaJcgd_sendMessage);
}

void Heavy_PhaseRing::cPack_Is1pAcj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9PeTh1xu, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_YLkeXdUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QLbDGXFm, HV_BINOP_MULTIPLY, 0, m, &cBinop_QLbDGXFm_sendMessage);
}

void Heavy_PhaseRing::cMsg_xT5hHzma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zfgKfSgS_sendMessage);
}

void Heavy_PhaseRing::cSystem_zfgKfSgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mO4zcd9k_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_QLbDGXFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pbWoOTyu_sendMessage);
}

void Heavy_PhaseRing::cBinop_JhjGjViS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QLbDGXFm, HV_BINOP_MULTIPLY, 1, m, &cBinop_QLbDGXFm_sendMessage);
}

void Heavy_PhaseRing::cMsg_mO4zcd9k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JhjGjViS_sendMessage);
}

void Heavy_PhaseRing::cBinop_pbWoOTyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EiCe9tTr_sendMessage);
}

void Heavy_PhaseRing::cBinop_EiCe9tTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VVT1SyM0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_oUVcobdg, m);
}

void Heavy_PhaseRing::cBinop_VVT1SyM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FWoONJ3y, m);
}

void Heavy_PhaseRing::cVar_T04K6Uie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZCM1X2Vh, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZCM1X2Vh_sendMessage);
}

void Heavy_PhaseRing::cMsg_9XWgtcBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0g9qqXiN_sendMessage);
}

void Heavy_PhaseRing::cSystem_0g9qqXiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RhRBrOIV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_ZCM1X2Vh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WjeOtm2A_sendMessage);
}

void Heavy_PhaseRing::cBinop_gkAgtqAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZCM1X2Vh, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZCM1X2Vh_sendMessage);
}

void Heavy_PhaseRing::cMsg_RhRBrOIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gkAgtqAf_sendMessage);
}

void Heavy_PhaseRing::cBinop_WjeOtm2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kSAuLWMy_sendMessage);
}

void Heavy_PhaseRing::cBinop_kSAuLWMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MJDk5IJL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GPiYUsYW, m);
}

void Heavy_PhaseRing::cBinop_MJDk5IJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qZtS7PNG, m);
}

void Heavy_PhaseRing::cVar_feJloJKb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oezJlZH1, HV_BINOP_MULTIPLY, 0, m, &cBinop_oezJlZH1_sendMessage);
}

void Heavy_PhaseRing::cMsg_hOqUMfDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TTqyx1qL_sendMessage);
}

void Heavy_PhaseRing::cSystem_TTqyx1qL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H1Jqt8EF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_oezJlZH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_X1g35wID_sendMessage);
}

void Heavy_PhaseRing::cBinop_50JPQDJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oezJlZH1, HV_BINOP_MULTIPLY, 1, m, &cBinop_oezJlZH1_sendMessage);
}

void Heavy_PhaseRing::cMsg_H1Jqt8EF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_50JPQDJX_sendMessage);
}

void Heavy_PhaseRing::cBinop_X1g35wID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_SE4RX1Fq_sendMessage);
}

void Heavy_PhaseRing::cBinop_SE4RX1Fq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_43M6iDRA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tRl2p4MC, m);
}

void Heavy_PhaseRing::cBinop_43M6iDRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Px7mloIV, m);
}

void Heavy_PhaseRing::cBinop_OlE0cMrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3r0DAcAE, 0, m, &cPack_3r0DAcAE_sendMessage);
}

void Heavy_PhaseRing::cMsg_73OZhWm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_2OBOFhSR, 0, m, &cVar_2OBOFhSR_sendMessage);
}

void Heavy_PhaseRing::cBinop_1JqaJcgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Is1pAcj0, 0, m, &cPack_Is1pAcj0_sendMessage);
}

void Heavy_PhaseRing::cBinop_Wulf8gj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3AWggFEO, 0, m, &cPack_3AWggFEO_sendMessage);
}

void Heavy_PhaseRing::cIf_l2IUnkog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WXocDeoB_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_fk41sS7U_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_fk41sS7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_ZlV8O39U_sendMessage);
}

void Heavy_PhaseRing::cCast_H2sUX7PW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_BYcuJBH5_sendMessage);
}

void Heavy_PhaseRing::cCast_vcFU3ChA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_l2IUnkog, 0, m, &cIf_l2IUnkog_sendMessage);
}

void Heavy_PhaseRing::cMsg_WXocDeoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_iptQFL2n, 0, m, &cVar_iptQFL2n_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZlV8O39U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_WwSQQL9F_sendMessage);
}

void Heavy_PhaseRing::cBinop_WwSQQL9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lhoGI2Le_sendMessage);
}

void Heavy_PhaseRing::cBinop_lhoGI2Le_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iptQFL2n, 0, m, &cVar_iptQFL2n_sendMessage);
}

void Heavy_PhaseRing::cBinop_BYcuJBH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_l2IUnkog, 1, m, &cIf_l2IUnkog_sendMessage);
}

void Heavy_PhaseRing::cBinop_cE4cVlgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H2sUX7PW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vcFU3ChA_sendMessage);
}

void Heavy_PhaseRing::cBinop_d7fuRhuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cE4cVlgM_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_8MwSLWQX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_mMgqSG7V_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_mMgqSG7V_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_wMlynhaG, 1, m, &cDelay_wMlynhaG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SCBke3s2_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_wMlynhaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wMlynhaG, m);
  cMsg_GCa6fo9Z_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_mMgqSG7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wMlynhaG, 0, m, &cDelay_wMlynhaG_sendMessage);
}

void Heavy_PhaseRing::cCast_SCBke3s2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wMlynhaG, 0, m, &cDelay_wMlynhaG_sendMessage);
}

void Heavy_PhaseRing::cVar_aHWjUdmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FyA1UY0E, 0, m, &cPack_FyA1UY0E_sendMessage);
}

void Heavy_PhaseRing::cVar_5FMJR5Jq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_i1sNxkGM_sendMessage);
}

void Heavy_PhaseRing::cVar_FK7oAEXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_frItMVLi_sendMessage);
}

void Heavy_PhaseRing::cPack_JfnhsHEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_znxv5TKK, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_rg0NAiTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_gkBx4q4I_sendMessage);
}

void Heavy_PhaseRing::cBinop_GSbJ68ZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_rg0NAiTv_sendMessage);
}

void Heavy_PhaseRing::cPack_C9iKp8bl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_m7UoZwKy, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_THhh7Y18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_BXNmSPub_sendMessage);
}

void Heavy_PhaseRing::cMsg_GSxcX1gN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_c6t3Bj81_sendMessage);
}

void Heavy_PhaseRing::cSystem_c6t3Bj81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yrFxDItg_sendMessage);
}

void Heavy_PhaseRing::cDelay_Xca23ZRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Xca23ZRy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_K9B2wZ7E, 0, m, &cDelay_K9B2wZ7E_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xca23ZRy, 0, m, &cDelay_Xca23ZRy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NNNHp52Y, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_K9B2wZ7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_K9B2wZ7E, m);
  cMsg_tmqjeUdD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_YG06hHvW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_NgKm60MN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_SUgcO5FD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KYh4Sfmy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_3MB9R521_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_26PCEbwJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xca23ZRy, 2, m, &cDelay_Xca23ZRy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PWymvL6b_sendMessage);
}

void Heavy_PhaseRing::cMsg_KYh4Sfmy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3MB9R521, 0, m, &hTable_3MB9R521_sendMessage);
}

void Heavy_PhaseRing::cBinop_yrFxDItg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_SUgcO5FD_sendMessage);
}

void Heavy_PhaseRing::cMsg_tmqjeUdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3MB9R521, 0, m, &hTable_3MB9R521_sendMessage);
}

void Heavy_PhaseRing::cCast_PWymvL6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xca23ZRy, 0, m, &cDelay_Xca23ZRy_sendMessage);
}

void Heavy_PhaseRing::cMsg_26PCEbwJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_K9B2wZ7E, 2, m, &cDelay_K9B2wZ7E_sendMessage);
}

void Heavy_PhaseRing::cMsg_NgKm60MN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NNNHp52Y, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_SOMEtJHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qSGnxprF_sendMessage);
}

void Heavy_PhaseRing::cSystem_qSGnxprF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nRSryUF4_sendMessage);
}

void Heavy_PhaseRing::cVar_jgKpSud8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LwEtAXht_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_3fNRKp2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8j1O3IB1_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_l4sLowaT, m);
}

void Heavy_PhaseRing::cBinop_nRSryUF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZB32bdQj, m);
}

void Heavy_PhaseRing::cMsg_LwEtAXht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3fNRKp2z_sendMessage);
}

void Heavy_PhaseRing::cBinop_8j1O3IB1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cYA0F3X4, m);
}

void Heavy_PhaseRing::cMsg_V86Js269_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SuzfVsuw_sendMessage);
}

void Heavy_PhaseRing::cSystem_SuzfVsuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_x5USFXXm_sendMessage);
}

void Heavy_PhaseRing::cVar_CH6ToqHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7khZ4eUV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_9JdLliyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VmizrhhF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_X2sBVcX1, m);
}

void Heavy_PhaseRing::cBinop_x5USFXXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fP53xb6r, m);
}

void Heavy_PhaseRing::cMsg_7khZ4eUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9JdLliyJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_VmizrhhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_M4ZiY05L, m);
}

void Heavy_PhaseRing::cBinop_U2aT025m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ro856cO6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_dDkLNU9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8e8SaMsn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jtgL0Dki_sendMessage);
}

void Heavy_PhaseRing::cCast_8e8SaMsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U2aT025m, HV_BINOP_DIVIDE, 1, m, &cBinop_U2aT025m_sendMessage);
}

void Heavy_PhaseRing::cCast_jtgL0Dki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U2aT025m, HV_BINOP_DIVIDE, 0, m, &cBinop_U2aT025m_sendMessage);
}

void Heavy_PhaseRing::cBinop_gkBx4q4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5H46CZsN_sendMessage);
}

void Heavy_PhaseRing::cBinop_i1sNxkGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_GSbJ68ZW_sendMessage);
}

void Heavy_PhaseRing::cBinop_5H46CZsN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U2aT025m, HV_BINOP_DIVIDE, 0, m, &cBinop_U2aT025m_sendMessage);
}

void Heavy_PhaseRing::cBinop_BXNmSPub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_C9iKp8bl, 0, m, &cPack_C9iKp8bl_sendMessage);
}

void Heavy_PhaseRing::cBinop_frItMVLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_dDkLNU9R_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_JfnhsHEM, 0, m, &cPack_JfnhsHEM_sendMessage);
}

void Heavy_PhaseRing::cMsg_4YTkzy6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_FK7oAEXk, 0, m, &cVar_FK7oAEXk_sendMessage);
}

void Heavy_PhaseRing::cMsg_C4us6iyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_THhh7Y18, 0, m, &cVar_THhh7Y18_sendMessage);
}

void Heavy_PhaseRing::cMsg_ro856cO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ra2t3iLt, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_tBrgNhqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fCsXl3J0, HV_BINOP_MULTIPLY, 0, m, &cBinop_fCsXl3J0_sendMessage);
}

void Heavy_PhaseRing::cMsg_VuDrGmhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hmAxpmJQ_sendMessage);
}

void Heavy_PhaseRing::cSystem_hmAxpmJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UfueMkTJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_fCsXl3J0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xuUyHtq4_sendMessage);
}

void Heavy_PhaseRing::cBinop_vg6UIc77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fCsXl3J0, HV_BINOP_MULTIPLY, 1, m, &cBinop_fCsXl3J0_sendMessage);
}

void Heavy_PhaseRing::cMsg_UfueMkTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_vg6UIc77_sendMessage);
}

void Heavy_PhaseRing::cBinop_xuUyHtq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qscMlpGw_sendMessage);
}

void Heavy_PhaseRing::cBinop_qscMlpGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_kcPub2hT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vMGE5MHf, m);
}

void Heavy_PhaseRing::cBinop_kcPub2hT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_csx4kkkj, m);
}

void Heavy_PhaseRing::cVar_a8cm4Ru2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BmBRUCWQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_BmBRUCWQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_nupV6PUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yeBccHVK_sendMessage);
}

void Heavy_PhaseRing::cSystem_yeBccHVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EkJfKekP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_BmBRUCWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_O7xbiXwV_sendMessage);
}

void Heavy_PhaseRing::cBinop_DhQEnKZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BmBRUCWQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_BmBRUCWQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_EkJfKekP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DhQEnKZv_sendMessage);
}

void Heavy_PhaseRing::cBinop_O7xbiXwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_25nqfTrs_sendMessage);
}

void Heavy_PhaseRing::cBinop_25nqfTrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_gHn73kix_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uzb0pbpk, m);
}

void Heavy_PhaseRing::cBinop_gHn73kix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p5ETkzlj, m);
}

void Heavy_PhaseRing::cVar_XtibPGgI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iU7XPlfE, HV_BINOP_MULTIPLY, 0, m, &cBinop_iU7XPlfE_sendMessage);
}

void Heavy_PhaseRing::cMsg_2OEH06Hi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QZymyVUa_sendMessage);
}

void Heavy_PhaseRing::cSystem_QZymyVUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m15Qlfqj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_iU7XPlfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MdD8p5UK_sendMessage);
}

void Heavy_PhaseRing::cBinop_60TQEwiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iU7XPlfE, HV_BINOP_MULTIPLY, 1, m, &cBinop_iU7XPlfE_sendMessage);
}

void Heavy_PhaseRing::cMsg_m15Qlfqj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_60TQEwiH_sendMessage);
}

void Heavy_PhaseRing::cBinop_MdD8p5UK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QYLL7Xl1_sendMessage);
}

void Heavy_PhaseRing::cBinop_QYLL7Xl1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QAa9jEhX_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nnyHuAJH, m);
}

void Heavy_PhaseRing::cBinop_QAa9jEhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GZr2zu12, m);
}

void Heavy_PhaseRing::cMsg_a2nEiEng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Egsu62N8_sendMessage);
}

void Heavy_PhaseRing::cSystem_Egsu62N8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tS6TFCjl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_ths80PqV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_pxb0rL4S_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_3ko6GJxo, 0, m, &cIf_3ko6GJxo_sendMessage);
}

void Heavy_PhaseRing::cIf_3ko6GJxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5KCNldjk_sendMessage(_c, 0, m);
      cMsg_e0s7I90q_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_yntc9H2u_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_e84E46UG_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_E3fPsydy, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_pxb0rL4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3ko6GJxo, 1, m, &cIf_3ko6GJxo_sendMessage);
}

void Heavy_PhaseRing::cMsg_yntc9H2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_jjRinj8t_sendMessage);
}

void Heavy_PhaseRing::cBinop_jjRinj8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZdWfz8f6, m);
}

void Heavy_PhaseRing::cBinop_e84E46UG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TDnvdx9b_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_TDnvdx9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_M2BCwwWe_sendMessage);
}

void Heavy_PhaseRing::cBinop_M2BCwwWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y8h8L5in_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Y8h8L5in_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_tjW3tbkj_sendMessage);
}

void Heavy_PhaseRing::cBinop_tjW3tbkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FZirLyJW, m);
}

void Heavy_PhaseRing::cBinop_IJwRQovf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Zdg4sOPP, m);
}

void Heavy_PhaseRing::cMsg_tS6TFCjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IJwRQovf_sendMessage);
}

void Heavy_PhaseRing::cMsg_5KCNldjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_e84E46UG_sendMessage);
}

void Heavy_PhaseRing::cMsg_e0s7I90q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZdWfz8f6, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_E3fPsydy, m);
}

void Heavy_PhaseRing::cBinop_n4F7mBVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a8cm4Ru2, 0, m, &cVar_a8cm4Ru2_sendMessage);
}

void Heavy_PhaseRing::cBinop_vV3dbIxZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tBrgNhqW, 0, m, &cVar_tBrgNhqW_sendMessage);
}

void Heavy_PhaseRing::cBinop_XIrQSBYQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XtibPGgI, 0, m, &cVar_XtibPGgI_sendMessage);
}

void Heavy_PhaseRing::cCast_xSrotpmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_XIrQSBYQ_sendMessage);
}

void Heavy_PhaseRing::cCast_LZgpvNR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TdL6ZguY, m);
}

void Heavy_PhaseRing::cCast_nF7hft1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_vV3dbIxZ_sendMessage);
}

void Heavy_PhaseRing::cCast_FB4gtUVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_n4F7mBVc_sendMessage);
}

void Heavy_PhaseRing::cTabhead_EHXlnLo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_354Kspg7, HV_BINOP_SUBTRACT, 0, m, &cBinop_354Kspg7_sendMessage);
}

void Heavy_PhaseRing::cMsg_AOO0bccQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rcbMZ7R6_sendMessage);
}

void Heavy_PhaseRing::cSystem_rcbMZ7R6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wBiAgG5i_sendMessage);
}

void Heavy_PhaseRing::cVar_lEjLV3Ym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C1Z18hHr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_NQGZA977_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NQGZA977, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bR7FqG9C, 0, m, &cDelay_bR7FqG9C_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PXyDu9RO, 0, m, &sTabread_PXyDu9RO_sendMessage);
}

void Heavy_PhaseRing::cDelay_bR7FqG9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bR7FqG9C, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PXyDu9RO, 0, m, &sTabread_PXyDu9RO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bR7FqG9C, 0, m, &cDelay_bR7FqG9C_sendMessage);
}

void Heavy_PhaseRing::sTabread_PXyDu9RO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_WPHUBC8y, HV_BINOP_SUBTRACT, 0, m, &cBinop_WPHUBC8y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_HxzDBnxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6LcBPG5y, HV_BINOP_MAX, 0, m, &cBinop_6LcBPG5y_sendMessage);
}

void Heavy_PhaseRing::cBinop_wBiAgG5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HxzDBnxq, HV_BINOP_MULTIPLY, 0, m, &cBinop_HxzDBnxq_sendMessage);
}

void Heavy_PhaseRing::cBinop_354Kspg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rgD3QYYm_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PXyDu9RO, 0, m, &sTabread_PXyDu9RO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q1c5qGDX_sendMessage);
}

void Heavy_PhaseRing::cSystem_HRIRxpJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WPHUBC8y, HV_BINOP_SUBTRACT, 1, m, &cBinop_WPHUBC8y_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bR7FqG9C, 2, m, &cDelay_bR7FqG9C_sendMessage);
}

void Heavy_PhaseRing::cMsg_C1Z18hHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HRIRxpJp_sendMessage);
}

void Heavy_PhaseRing::cMsg_rgD3QYYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NQGZA977, 0, m, &cDelay_NQGZA977_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bR7FqG9C, 0, m, &cDelay_bR7FqG9C_sendMessage);
}

void Heavy_PhaseRing::cMsg_AjSAEACa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_6LcBPG5y, HV_BINOP_MAX, 1, m, &cBinop_6LcBPG5y_sendMessage);
}

void Heavy_PhaseRing::cBinop_6LcBPG5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_354Kspg7, HV_BINOP_SUBTRACT, 1, m, &cBinop_354Kspg7_sendMessage);
}

void Heavy_PhaseRing::cCast_Q1c5qGDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NQGZA977, 0, m, &cDelay_NQGZA977_sendMessage);
}

void Heavy_PhaseRing::cBinop_fhBqwFR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NQGZA977, 2, m, &cDelay_NQGZA977_sendMessage);
}

void Heavy_PhaseRing::cBinop_WPHUBC8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fhBqwFR9_sendMessage);
}

void Heavy_PhaseRing::cCast_GXoRbnCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lEjLV3Ym, 0, m, &cVar_lEjLV3Ym_sendMessage);
  cMsg_AOO0bccQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EHXlnLo5, 0, m, &cTabhead_EHXlnLo5_sendMessage);
}

void Heavy_PhaseRing::cTabhead_wJo875kz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xyAXwb4O, HV_BINOP_SUBTRACT, 0, m, &cBinop_xyAXwb4O_sendMessage);
}

void Heavy_PhaseRing::cMsg_Xf6tv8SY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cqVzrFhs_sendMessage);
}

void Heavy_PhaseRing::cSystem_cqVzrFhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qDeJDG6r_sendMessage);
}

void Heavy_PhaseRing::cVar_1t1QHggq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cpOHx2lr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_3AbXEH01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3AbXEH01, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V3hcXL8A, 0, m, &cDelay_V3hcXL8A_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_flr2zEpX, 0, m, &sTabread_flr2zEpX_sendMessage);
}

void Heavy_PhaseRing::cDelay_V3hcXL8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V3hcXL8A, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_flr2zEpX, 0, m, &sTabread_flr2zEpX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V3hcXL8A, 0, m, &cDelay_V3hcXL8A_sendMessage);
}

void Heavy_PhaseRing::sTabread_flr2zEpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NC6umlQj, HV_BINOP_SUBTRACT, 0, m, &cBinop_NC6umlQj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Xc3rAzSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0nUOCHZL, HV_BINOP_MAX, 0, m, &cBinop_0nUOCHZL_sendMessage);
}

void Heavy_PhaseRing::cBinop_qDeJDG6r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xc3rAzSr, HV_BINOP_MULTIPLY, 0, m, &cBinop_Xc3rAzSr_sendMessage);
}

void Heavy_PhaseRing::cBinop_xyAXwb4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XIcP6465_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_flr2zEpX, 0, m, &sTabread_flr2zEpX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dBECFE37_sendMessage);
}

void Heavy_PhaseRing::cSystem_sQlrM9A7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NC6umlQj, HV_BINOP_SUBTRACT, 1, m, &cBinop_NC6umlQj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V3hcXL8A, 2, m, &cDelay_V3hcXL8A_sendMessage);
}

void Heavy_PhaseRing::cMsg_cpOHx2lr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sQlrM9A7_sendMessage);
}

void Heavy_PhaseRing::cMsg_XIcP6465_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3AbXEH01, 0, m, &cDelay_3AbXEH01_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V3hcXL8A, 0, m, &cDelay_V3hcXL8A_sendMessage);
}

void Heavy_PhaseRing::cMsg_E302bBT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_0nUOCHZL, HV_BINOP_MAX, 1, m, &cBinop_0nUOCHZL_sendMessage);
}

void Heavy_PhaseRing::cBinop_0nUOCHZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xyAXwb4O, HV_BINOP_SUBTRACT, 1, m, &cBinop_xyAXwb4O_sendMessage);
}

void Heavy_PhaseRing::cCast_dBECFE37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3AbXEH01, 0, m, &cDelay_3AbXEH01_sendMessage);
}

void Heavy_PhaseRing::cBinop_FAJpVhiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3AbXEH01, 2, m, &cDelay_3AbXEH01_sendMessage);
}

void Heavy_PhaseRing::cBinop_NC6umlQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FAJpVhiP_sendMessage);
}

void Heavy_PhaseRing::cCast_emr853bj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1t1QHggq, 0, m, &cVar_1t1QHggq_sendMessage);
  cMsg_Xf6tv8SY_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wJo875kz, 0, m, &cTabhead_wJo875kz_sendMessage);
}

void Heavy_PhaseRing::cTabhead_uMseitWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lvs0MGei, HV_BINOP_SUBTRACT, 0, m, &cBinop_Lvs0MGei_sendMessage);
}

void Heavy_PhaseRing::cMsg_kgHp9AyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xhdNHIIJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_xhdNHIIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ApoOoaGl_sendMessage);
}

void Heavy_PhaseRing::cVar_Q876LdX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7WjR4geX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_htUJXMF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_htUJXMF6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zR3zevyN, 0, m, &cDelay_zR3zevyN_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XWgTHeQf, 0, m, &sTabread_XWgTHeQf_sendMessage);
}

void Heavy_PhaseRing::cDelay_zR3zevyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zR3zevyN, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XWgTHeQf, 0, m, &sTabread_XWgTHeQf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zR3zevyN, 0, m, &cDelay_zR3zevyN_sendMessage);
}

void Heavy_PhaseRing::sTabread_XWgTHeQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3S3Yk7W2, HV_BINOP_SUBTRACT, 0, m, &cBinop_3S3Yk7W2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_iQMcQev3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_clmYgYaa, HV_BINOP_MAX, 0, m, &cBinop_clmYgYaa_sendMessage);
}

void Heavy_PhaseRing::cBinop_ApoOoaGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iQMcQev3, HV_BINOP_MULTIPLY, 0, m, &cBinop_iQMcQev3_sendMessage);
}

void Heavy_PhaseRing::cBinop_Lvs0MGei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tnNaEmBH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XWgTHeQf, 0, m, &sTabread_XWgTHeQf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q5RimlK2_sendMessage);
}

void Heavy_PhaseRing::cSystem_UbXZqePn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3S3Yk7W2, HV_BINOP_SUBTRACT, 1, m, &cBinop_3S3Yk7W2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zR3zevyN, 2, m, &cDelay_zR3zevyN_sendMessage);
}

void Heavy_PhaseRing::cMsg_7WjR4geX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UbXZqePn_sendMessage);
}

void Heavy_PhaseRing::cMsg_tnNaEmBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_htUJXMF6, 0, m, &cDelay_htUJXMF6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zR3zevyN, 0, m, &cDelay_zR3zevyN_sendMessage);
}

void Heavy_PhaseRing::cMsg_OAPRoXvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_clmYgYaa, HV_BINOP_MAX, 1, m, &cBinop_clmYgYaa_sendMessage);
}

void Heavy_PhaseRing::cBinop_clmYgYaa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lvs0MGei, HV_BINOP_SUBTRACT, 1, m, &cBinop_Lvs0MGei_sendMessage);
}

void Heavy_PhaseRing::cCast_Q5RimlK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_htUJXMF6, 0, m, &cDelay_htUJXMF6_sendMessage);
}

void Heavy_PhaseRing::cBinop_qtR59nfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_htUJXMF6, 2, m, &cDelay_htUJXMF6_sendMessage);
}

void Heavy_PhaseRing::cBinop_3S3Yk7W2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qtR59nfY_sendMessage);
}

void Heavy_PhaseRing::cCast_eq9hp7S8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Q876LdX3, 0, m, &cVar_Q876LdX3_sendMessage);
  cMsg_kgHp9AyL_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uMseitWH, 0, m, &cTabhead_uMseitWH_sendMessage);
}

void Heavy_PhaseRing::cTabhead_G9yt3Hww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9RMod5mw, HV_BINOP_SUBTRACT, 0, m, &cBinop_9RMod5mw_sendMessage);
}

void Heavy_PhaseRing::cMsg_aDywl2EK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rB6DL3in_sendMessage);
}

void Heavy_PhaseRing::cSystem_rB6DL3in_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jqFnyYpj_sendMessage);
}

void Heavy_PhaseRing::cVar_MrcEnfDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vrrT0bJw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_Ly1VcRQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ly1VcRQj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qz6rf7IW, 0, m, &cDelay_Qz6rf7IW_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tkvhO79D, 0, m, &sTabread_tkvhO79D_sendMessage);
}

void Heavy_PhaseRing::cDelay_Qz6rf7IW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Qz6rf7IW, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tkvhO79D, 0, m, &sTabread_tkvhO79D_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qz6rf7IW, 0, m, &cDelay_Qz6rf7IW_sendMessage);
}

void Heavy_PhaseRing::sTabread_tkvhO79D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_poOmSGf6, HV_BINOP_SUBTRACT, 0, m, &cBinop_poOmSGf6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_VoMKxmdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UNkutTaK, HV_BINOP_MAX, 0, m, &cBinop_UNkutTaK_sendMessage);
}

void Heavy_PhaseRing::cBinop_jqFnyYpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VoMKxmdl, HV_BINOP_MULTIPLY, 0, m, &cBinop_VoMKxmdl_sendMessage);
}

void Heavy_PhaseRing::cBinop_9RMod5mw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HKzAR04B_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tkvhO79D, 0, m, &sTabread_tkvhO79D_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oVIbMv8S_sendMessage);
}

void Heavy_PhaseRing::cSystem_inV5zgXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_poOmSGf6, HV_BINOP_SUBTRACT, 1, m, &cBinop_poOmSGf6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qz6rf7IW, 2, m, &cDelay_Qz6rf7IW_sendMessage);
}

void Heavy_PhaseRing::cMsg_vrrT0bJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_inV5zgXR_sendMessage);
}

void Heavy_PhaseRing::cMsg_HKzAR04B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ly1VcRQj, 0, m, &cDelay_Ly1VcRQj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qz6rf7IW, 0, m, &cDelay_Qz6rf7IW_sendMessage);
}

void Heavy_PhaseRing::cMsg_s83m1N4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_UNkutTaK, HV_BINOP_MAX, 1, m, &cBinop_UNkutTaK_sendMessage);
}

void Heavy_PhaseRing::cBinop_UNkutTaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9RMod5mw, HV_BINOP_SUBTRACT, 1, m, &cBinop_9RMod5mw_sendMessage);
}

void Heavy_PhaseRing::cCast_oVIbMv8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ly1VcRQj, 0, m, &cDelay_Ly1VcRQj_sendMessage);
}

void Heavy_PhaseRing::cBinop_4sph3HQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ly1VcRQj, 2, m, &cDelay_Ly1VcRQj_sendMessage);
}

void Heavy_PhaseRing::cBinop_poOmSGf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4sph3HQB_sendMessage);
}

void Heavy_PhaseRing::cCast_m0GaynXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MrcEnfDs, 0, m, &cVar_MrcEnfDs_sendMessage);
  cMsg_aDywl2EK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_G9yt3Hww, 0, m, &cTabhead_G9yt3Hww_sendMessage);
}

void Heavy_PhaseRing::cMsg_FnIHVT05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mxwhNCmc_sendMessage);
}

void Heavy_PhaseRing::cSystem_mxwhNCmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mAy0DB66_sendMessage);
}

void Heavy_PhaseRing::cDelay_aa4Pno8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aa4Pno8v, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_b1Nt1EnY, 0, m, &cDelay_b1Nt1EnY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aa4Pno8v, 0, m, &cDelay_aa4Pno8v_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0DYm3TJV, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_b1Nt1EnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_b1Nt1EnY, m);
  cMsg_hNkHiekB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_BEO6fOIa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_xOULT4KR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_0JwIx7uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Sd8St6YG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_5ioMphG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DlRj1Q39_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aa4Pno8v, 2, m, &cDelay_aa4Pno8v_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KsW8wWek_sendMessage);
}

void Heavy_PhaseRing::cMsg_Sd8St6YG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_5ioMphG8, 0, m, &hTable_5ioMphG8_sendMessage);
}

void Heavy_PhaseRing::cBinop_mAy0DB66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_0JwIx7uy_sendMessage);
}

void Heavy_PhaseRing::cMsg_hNkHiekB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_5ioMphG8, 0, m, &hTable_5ioMphG8_sendMessage);
}

void Heavy_PhaseRing::cCast_KsW8wWek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aa4Pno8v, 0, m, &cDelay_aa4Pno8v_sendMessage);
}

void Heavy_PhaseRing::cMsg_DlRj1Q39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_b1Nt1EnY, 2, m, &cDelay_b1Nt1EnY_sendMessage);
}

void Heavy_PhaseRing::cMsg_xOULT4KR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0DYm3TJV, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_MfLohqMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H3cV61Y0_sendMessage);
}

void Heavy_PhaseRing::cSystem_H3cV61Y0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SBTJdNAb_sendMessage);
}

void Heavy_PhaseRing::cDelay_XqT4VSRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XqT4VSRt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQJrnsx8, 0, m, &cDelay_hQJrnsx8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XqT4VSRt, 0, m, &cDelay_XqT4VSRt_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hNA8U5MH, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_hQJrnsx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hQJrnsx8, m);
  cMsg_nawef7gb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_rNTLRPw5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_186kGL2O_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_f8ubvNmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CzZAef2d_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_RW3zd5nF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kSvl0gZ0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XqT4VSRt, 2, m, &cDelay_XqT4VSRt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1OdxKYOj_sendMessage);
}

void Heavy_PhaseRing::cMsg_CzZAef2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_RW3zd5nF, 0, m, &hTable_RW3zd5nF_sendMessage);
}

void Heavy_PhaseRing::cBinop_SBTJdNAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_f8ubvNmm_sendMessage);
}

void Heavy_PhaseRing::cMsg_nawef7gb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_RW3zd5nF, 0, m, &hTable_RW3zd5nF_sendMessage);
}

void Heavy_PhaseRing::cCast_1OdxKYOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XqT4VSRt, 0, m, &cDelay_XqT4VSRt_sendMessage);
}

void Heavy_PhaseRing::cMsg_kSvl0gZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQJrnsx8, 2, m, &cDelay_hQJrnsx8_sendMessage);
}

void Heavy_PhaseRing::cMsg_186kGL2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hNA8U5MH, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_YwiXiYwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kL94e2IF_sendMessage);
}

void Heavy_PhaseRing::cSystem_kL94e2IF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qtwAkrsc_sendMessage);
}

void Heavy_PhaseRing::cDelay_CjlsgyoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CjlsgyoY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_D0vGZPm7, 0, m, &cDelay_D0vGZPm7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CjlsgyoY, 0, m, &cDelay_CjlsgyoY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_CL1NrIq1, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_D0vGZPm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_D0vGZPm7, m);
  cMsg_QvS83V2J_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_rzs6NLeV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_8fso9TQl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_xCaAOxxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ImEMh6z8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_a8GDILoc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mkquRvCf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CjlsgyoY, 2, m, &cDelay_CjlsgyoY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ldOyPg1d_sendMessage);
}

void Heavy_PhaseRing::cMsg_ImEMh6z8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_a8GDILoc, 0, m, &hTable_a8GDILoc_sendMessage);
}

void Heavy_PhaseRing::cBinop_qtwAkrsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_xCaAOxxE_sendMessage);
}

void Heavy_PhaseRing::cMsg_QvS83V2J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_a8GDILoc, 0, m, &hTable_a8GDILoc_sendMessage);
}

void Heavy_PhaseRing::cCast_ldOyPg1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CjlsgyoY, 0, m, &cDelay_CjlsgyoY_sendMessage);
}

void Heavy_PhaseRing::cMsg_mkquRvCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_D0vGZPm7, 2, m, &cDelay_D0vGZPm7_sendMessage);
}

void Heavy_PhaseRing::cMsg_8fso9TQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_CL1NrIq1, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_bJTclTLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ow9viodp_sendMessage);
}

void Heavy_PhaseRing::cSystem_Ow9viodp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VyrClmwX_sendMessage);
}

void Heavy_PhaseRing::cDelay_G7K1QHJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_G7K1QHJe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NHxsGGxW, 0, m, &cDelay_NHxsGGxW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G7K1QHJe, 0, m, &cDelay_G7K1QHJe_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_nwjshKbH, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_NHxsGGxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NHxsGGxW, m);
  cMsg_TknWWtu6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_blrZen5j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_EfJ6caKD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_H7NchTvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9VJmIPpg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_M2AxBj05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n30CwLZ4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G7K1QHJe, 2, m, &cDelay_G7K1QHJe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A8uYMHLG_sendMessage);
}

void Heavy_PhaseRing::cMsg_9VJmIPpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_M2AxBj05, 0, m, &hTable_M2AxBj05_sendMessage);
}

void Heavy_PhaseRing::cBinop_VyrClmwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_H7NchTvH_sendMessage);
}

void Heavy_PhaseRing::cMsg_TknWWtu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_M2AxBj05, 0, m, &hTable_M2AxBj05_sendMessage);
}

void Heavy_PhaseRing::cCast_A8uYMHLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_G7K1QHJe, 0, m, &cDelay_G7K1QHJe_sendMessage);
}

void Heavy_PhaseRing::cMsg_n30CwLZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_NHxsGGxW, 2, m, &cDelay_NHxsGGxW_sendMessage);
}

void Heavy_PhaseRing::cMsg_EfJ6caKD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_nwjshKbH, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_MMZrngKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WWPT0zQm_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_JVuDB45u_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_ydlUhfzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_P0jJNQmP, HV_BINOP_POW, 0, m, &cBinop_P0jJNQmP_sendMessage);
}

void Heavy_PhaseRing::cBinop_P0jJNQmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_nDo1DKW5_sendMessage);
}

void Heavy_PhaseRing::cBinop_qvC6sWPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Fo7euc6H_sendMessage);
}

void Heavy_PhaseRing::cCast_KDb0XiBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Dlb70wu7_sendMessage);
}

void Heavy_PhaseRing::cCast_nR2Ub6mz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MMZrngKC, 0, m, &cIf_MMZrngKC_sendMessage);
}

void Heavy_PhaseRing::cBinop_Dlb70wu7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MMZrngKC, 1, m, &cIf_MMZrngKC_sendMessage);
}

void Heavy_PhaseRing::cBinop_JVuDB45u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_qvC6sWPd_sendMessage);
}

void Heavy_PhaseRing::cMsg_WWPT0zQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_nDo1DKW5_sendMessage);
}

void Heavy_PhaseRing::cBinop_Fo7euc6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P0jJNQmP, HV_BINOP_POW, 1, m, &cBinop_P0jJNQmP_sendMessage);
  cMsg_ydlUhfzh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_rEYD88aI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_BWCIt3KP, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_FIz5w5G4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_gsHEdUib, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_54Ed6tfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_hiFZyvz5_sendMessage);
}

void Heavy_PhaseRing::cBinop_hiFZyvz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_nslgGy3W_sendMessage);
}

void Heavy_PhaseRing::cVar_5LMTsEU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MusqmsQq, HV_BINOP_MULTIPLY, 0, m, &cBinop_MusqmsQq_sendMessage);
}

void Heavy_PhaseRing::cMsg_4i28eUCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6LhBDAPR_sendMessage);
}

void Heavy_PhaseRing::cSystem_6LhBDAPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lbRO7Y0P_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_MusqmsQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nu3tbTQJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_wPUcgaZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MusqmsQq, HV_BINOP_MULTIPLY, 1, m, &cBinop_MusqmsQq_sendMessage);
}

void Heavy_PhaseRing::cMsg_lbRO7Y0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_wPUcgaZv_sendMessage);
}

void Heavy_PhaseRing::cBinop_nu3tbTQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_HzDDcZlS_sendMessage);
}

void Heavy_PhaseRing::cBinop_HzDDcZlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JhEmVu2J_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mM61I41T, m);
}

void Heavy_PhaseRing::cBinop_JhEmVu2J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ANKhHPoX, m);
}

void Heavy_PhaseRing::cVar_rANLmejJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KDb0XiBf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nR2Ub6mz_sendMessage);
}

void Heavy_PhaseRing::cVar_Ywmnnyys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_54Ed6tfO_sendMessage);
}

void Heavy_PhaseRing::cVar_jR1PMCeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_e9sUFr9j_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Mex5YPg8, 0, m, &cIf_Mex5YPg8_sendMessage);
}

void Heavy_PhaseRing::cVar_N5qZjaMz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_W6gi3AjW_sendMessage);
}

void Heavy_PhaseRing::cIf_Mex5YPg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_MHzdKxZ1_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_VSjKuOI6, 0, m, &cVar_VSjKuOI6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_e9sUFr9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Mex5YPg8, 1, m, &cIf_Mex5YPg8_sendMessage);
}

void Heavy_PhaseRing::cBinop_W6gi3AjW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dVpjXYrt_sendMessage);
}

void Heavy_PhaseRing::cBinop_dVpjXYrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RLyMWiFF, 0, m, &cVar_RLyMWiFF_sendMessage);
}

void Heavy_PhaseRing::cTabhead_8l89wQDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aWyTqvEo, HV_BINOP_SUBTRACT, 0, m, &cBinop_aWyTqvEo_sendMessage);
}

void Heavy_PhaseRing::cMsg_seA9OYuC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ictj0hSv_sendMessage);
}

void Heavy_PhaseRing::cSystem_ictj0hSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iUVS0OSo_sendMessage);
}

void Heavy_PhaseRing::cVar_dnqkOPaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wFLZmmOm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_iQHl1VdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iQHl1VdU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ljnKCDim, 0, m, &cDelay_ljnKCDim_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JmFOVfVI, 0, m, &sTabread_JmFOVfVI_sendMessage);
}

void Heavy_PhaseRing::cDelay_ljnKCDim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ljnKCDim, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JmFOVfVI, 0, m, &sTabread_JmFOVfVI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ljnKCDim, 0, m, &cDelay_ljnKCDim_sendMessage);
}

void Heavy_PhaseRing::sTabread_JmFOVfVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jtCgEiHH, HV_BINOP_SUBTRACT, 0, m, &cBinop_jtCgEiHH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_8iKqQeVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MhLjqBPt, HV_BINOP_MAX, 0, m, &cBinop_MhLjqBPt_sendMessage);
}

void Heavy_PhaseRing::cBinop_iUVS0OSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8iKqQeVt, HV_BINOP_MULTIPLY, 0, m, &cBinop_8iKqQeVt_sendMessage);
}

void Heavy_PhaseRing::cBinop_aWyTqvEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hl5pgW20_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JmFOVfVI, 0, m, &sTabread_JmFOVfVI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DH9IxH9S_sendMessage);
}

void Heavy_PhaseRing::cSystem_6Y3EmoSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jtCgEiHH, HV_BINOP_SUBTRACT, 1, m, &cBinop_jtCgEiHH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ljnKCDim, 2, m, &cDelay_ljnKCDim_sendMessage);
}

void Heavy_PhaseRing::cMsg_wFLZmmOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6Y3EmoSb_sendMessage);
}

void Heavy_PhaseRing::cMsg_hl5pgW20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iQHl1VdU, 0, m, &cDelay_iQHl1VdU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ljnKCDim, 0, m, &cDelay_ljnKCDim_sendMessage);
}

void Heavy_PhaseRing::cMsg_w162vLdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_MhLjqBPt, HV_BINOP_MAX, 1, m, &cBinop_MhLjqBPt_sendMessage);
}

void Heavy_PhaseRing::cBinop_MhLjqBPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aWyTqvEo, HV_BINOP_SUBTRACT, 1, m, &cBinop_aWyTqvEo_sendMessage);
}

void Heavy_PhaseRing::cCast_DH9IxH9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iQHl1VdU, 0, m, &cDelay_iQHl1VdU_sendMessage);
}

void Heavy_PhaseRing::cBinop_ESX37TYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iQHl1VdU, 2, m, &cDelay_iQHl1VdU_sendMessage);
}

void Heavy_PhaseRing::cBinop_jtCgEiHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ESX37TYT_sendMessage);
}

void Heavy_PhaseRing::cCast_HVv2uUWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dnqkOPaL, 0, m, &cVar_dnqkOPaL_sendMessage);
  cMsg_seA9OYuC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8l89wQDU, 0, m, &cTabhead_8l89wQDU_sendMessage);
}

void Heavy_PhaseRing::cMsg_RxbMLTkW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MSU9VLmP_sendMessage);
}

void Heavy_PhaseRing::cSystem_MSU9VLmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bwluCRGV_sendMessage);
}

void Heavy_PhaseRing::cDelay_ubuhKJZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ubuhKJZJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WzECrtFb, 0, m, &cDelay_WzECrtFb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ubuhKJZJ, 0, m, &cDelay_ubuhKJZJ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GCCTafgW, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_WzECrtFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WzECrtFb, m);
  cMsg_OKDdsa7a_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_w4yQp2EM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ekY9TnaV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_mzhnT7MR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xcqTfRWs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_bbTFkl2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lj2fSx62_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ubuhKJZJ, 2, m, &cDelay_ubuhKJZJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V7zghW8w_sendMessage);
}

void Heavy_PhaseRing::cMsg_xcqTfRWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_bbTFkl2o, 0, m, &hTable_bbTFkl2o_sendMessage);
}

void Heavy_PhaseRing::cBinop_bwluCRGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_mzhnT7MR_sendMessage);
}

void Heavy_PhaseRing::cMsg_OKDdsa7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_bbTFkl2o, 0, m, &hTable_bbTFkl2o_sendMessage);
}

void Heavy_PhaseRing::cCast_V7zghW8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ubuhKJZJ, 0, m, &cDelay_ubuhKJZJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_Lj2fSx62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WzECrtFb, 2, m, &cDelay_WzECrtFb_sendMessage);
}

void Heavy_PhaseRing::cMsg_ekY9TnaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GCCTafgW, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_1WKT09kq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FJh9NdKz, HV_BINOP_SUBTRACT, 0, m, &cBinop_FJh9NdKz_sendMessage);
}

void Heavy_PhaseRing::cMsg_t29pJhUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xXZgbyQM_sendMessage);
}

void Heavy_PhaseRing::cSystem_xXZgbyQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Jrl4uDnS_sendMessage);
}

void Heavy_PhaseRing::cVar_0tS7ik3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K9ObHCt9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_3xD5TCeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3xD5TCeA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yLJ0kKUF, 0, m, &cDelay_yLJ0kKUF_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_DaGuuQMZ, 0, m, &sTabread_DaGuuQMZ_sendMessage);
}

void Heavy_PhaseRing::cDelay_yLJ0kKUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yLJ0kKUF, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_DaGuuQMZ, 0, m, &sTabread_DaGuuQMZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yLJ0kKUF, 0, m, &cDelay_yLJ0kKUF_sendMessage);
}

void Heavy_PhaseRing::sTabread_DaGuuQMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_czo0shkj, HV_BINOP_SUBTRACT, 0, m, &cBinop_czo0shkj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_OqKX8tU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sg5hXio5, HV_BINOP_MAX, 0, m, &cBinop_sg5hXio5_sendMessage);
}

void Heavy_PhaseRing::cBinop_Jrl4uDnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OqKX8tU1, HV_BINOP_MULTIPLY, 0, m, &cBinop_OqKX8tU1_sendMessage);
}

void Heavy_PhaseRing::cBinop_FJh9NdKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tbi0NtwO_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_DaGuuQMZ, 0, m, &sTabread_DaGuuQMZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lcawXIRR_sendMessage);
}

void Heavy_PhaseRing::cSystem_fyHsVPB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_czo0shkj, HV_BINOP_SUBTRACT, 1, m, &cBinop_czo0shkj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yLJ0kKUF, 2, m, &cDelay_yLJ0kKUF_sendMessage);
}

void Heavy_PhaseRing::cMsg_K9ObHCt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fyHsVPB6_sendMessage);
}

void Heavy_PhaseRing::cMsg_tbi0NtwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3xD5TCeA, 0, m, &cDelay_3xD5TCeA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yLJ0kKUF, 0, m, &cDelay_yLJ0kKUF_sendMessage);
}

void Heavy_PhaseRing::cMsg_Eki8TDFe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_sg5hXio5, HV_BINOP_MAX, 1, m, &cBinop_sg5hXio5_sendMessage);
}

void Heavy_PhaseRing::cBinop_sg5hXio5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FJh9NdKz, HV_BINOP_SUBTRACT, 1, m, &cBinop_FJh9NdKz_sendMessage);
}

void Heavy_PhaseRing::cCast_lcawXIRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3xD5TCeA, 0, m, &cDelay_3xD5TCeA_sendMessage);
}

void Heavy_PhaseRing::cBinop_7RCOG1Xt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3xD5TCeA, 2, m, &cDelay_3xD5TCeA_sendMessage);
}

void Heavy_PhaseRing::cBinop_czo0shkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7RCOG1Xt_sendMessage);
}

void Heavy_PhaseRing::cCast_Hpt3hAwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0tS7ik3A, 0, m, &cVar_0tS7ik3A_sendMessage);
  cMsg_t29pJhUf_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1WKT09kq, 0, m, &cTabhead_1WKT09kq_sendMessage);
}

void Heavy_PhaseRing::cMsg_saYiPYBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jS4TJKcZ_sendMessage);
}

void Heavy_PhaseRing::cSystem_jS4TJKcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ebyhVLqH_sendMessage);
}

void Heavy_PhaseRing::cDelay_ODlXItyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ODlXItyk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8aynC0x0, 0, m, &cDelay_8aynC0x0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ODlXItyk, 0, m, &cDelay_ODlXItyk_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sMxLbsQB, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_8aynC0x0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8aynC0x0, m);
  cMsg_yc4psE92_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_hqCW5qOk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_e9VOkiUL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_4SJ4zIvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_np7HJZiI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_6TQwTNEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DGU2tdIf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ODlXItyk, 2, m, &cDelay_ODlXItyk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E92E68RU_sendMessage);
}

void Heavy_PhaseRing::cMsg_np7HJZiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6TQwTNEC, 0, m, &hTable_6TQwTNEC_sendMessage);
}

void Heavy_PhaseRing::cBinop_ebyhVLqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_4SJ4zIvo_sendMessage);
}

void Heavy_PhaseRing::cMsg_yc4psE92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6TQwTNEC, 0, m, &hTable_6TQwTNEC_sendMessage);
}

void Heavy_PhaseRing::cCast_E92E68RU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ODlXItyk, 0, m, &cDelay_ODlXItyk_sendMessage);
}

void Heavy_PhaseRing::cMsg_DGU2tdIf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8aynC0x0, 2, m, &cDelay_8aynC0x0_sendMessage);
}

void Heavy_PhaseRing::cMsg_e9VOkiUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sMxLbsQB, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_f5cUl7Xf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_okVqhnt3, HV_BINOP_SUBTRACT, 0, m, &cBinop_okVqhnt3_sendMessage);
}

void Heavy_PhaseRing::cMsg_k96fpRp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1pwKqv57_sendMessage);
}

void Heavy_PhaseRing::cSystem_1pwKqv57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_a3oQaESy_sendMessage);
}

void Heavy_PhaseRing::cVar_2zIVBgYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xA82WbRa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_K3z66y12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_K3z66y12, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9vKHsOxt, 0, m, &cDelay_9vKHsOxt_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_f4mOLfF2, 0, m, &sTabread_f4mOLfF2_sendMessage);
}

void Heavy_PhaseRing::cDelay_9vKHsOxt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9vKHsOxt, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_f4mOLfF2, 0, m, &sTabread_f4mOLfF2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9vKHsOxt, 0, m, &cDelay_9vKHsOxt_sendMessage);
}

void Heavy_PhaseRing::sTabread_f4mOLfF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_56TYM670, HV_BINOP_SUBTRACT, 0, m, &cBinop_56TYM670_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_9o9vVh51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cNlr4xnw, HV_BINOP_MAX, 0, m, &cBinop_cNlr4xnw_sendMessage);
}

void Heavy_PhaseRing::cBinop_a3oQaESy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9o9vVh51, HV_BINOP_MULTIPLY, 0, m, &cBinop_9o9vVh51_sendMessage);
}

void Heavy_PhaseRing::cBinop_okVqhnt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k9QJJt4W_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_f4mOLfF2, 0, m, &sTabread_f4mOLfF2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RCSNATLJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_VlViNapU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_56TYM670, HV_BINOP_SUBTRACT, 1, m, &cBinop_56TYM670_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9vKHsOxt, 2, m, &cDelay_9vKHsOxt_sendMessage);
}

void Heavy_PhaseRing::cMsg_xA82WbRa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VlViNapU_sendMessage);
}

void Heavy_PhaseRing::cMsg_k9QJJt4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_K3z66y12, 0, m, &cDelay_K3z66y12_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9vKHsOxt, 0, m, &cDelay_9vKHsOxt_sendMessage);
}

void Heavy_PhaseRing::cMsg_OwXSGqRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cNlr4xnw, HV_BINOP_MAX, 1, m, &cBinop_cNlr4xnw_sendMessage);
}

void Heavy_PhaseRing::cBinop_cNlr4xnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_okVqhnt3, HV_BINOP_SUBTRACT, 1, m, &cBinop_okVqhnt3_sendMessage);
}

void Heavy_PhaseRing::cCast_RCSNATLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_K3z66y12, 0, m, &cDelay_K3z66y12_sendMessage);
}

void Heavy_PhaseRing::cBinop_p6QFdmeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_K3z66y12, 2, m, &cDelay_K3z66y12_sendMessage);
}

void Heavy_PhaseRing::cBinop_56TYM670_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_p6QFdmeQ_sendMessage);
}

void Heavy_PhaseRing::cCast_Nr000d5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2zIVBgYl, 0, m, &cVar_2zIVBgYl_sendMessage);
  cMsg_k96fpRp5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_f5cUl7Xf, 0, m, &cTabhead_f5cUl7Xf_sendMessage);
}

void Heavy_PhaseRing::cMsg_rGptPvZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H81xQPhO_sendMessage);
}

void Heavy_PhaseRing::cSystem_H81xQPhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fiz1KpS9_sendMessage);
}

void Heavy_PhaseRing::cDelay_sD1QqS0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sD1QqS0v, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DmmVHF9R, 0, m, &cDelay_DmmVHF9R_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sD1QqS0v, 0, m, &cDelay_sD1QqS0v_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RR0X2HCm, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_DmmVHF9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DmmVHF9R, m);
  cMsg_kMPzI8Ag_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_CingtF9P_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_BqcWSa7q_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_wjSfXUVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DeI6qKGx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_Kk9ndx4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0LRAkaNl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sD1QqS0v, 2, m, &cDelay_sD1QqS0v_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B1Exophs_sendMessage);
}

void Heavy_PhaseRing::cMsg_DeI6qKGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Kk9ndx4m, 0, m, &hTable_Kk9ndx4m_sendMessage);
}

void Heavy_PhaseRing::cBinop_fiz1KpS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_wjSfXUVy_sendMessage);
}

void Heavy_PhaseRing::cMsg_kMPzI8Ag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Kk9ndx4m, 0, m, &hTable_Kk9ndx4m_sendMessage);
}

void Heavy_PhaseRing::cCast_B1Exophs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sD1QqS0v, 0, m, &cDelay_sD1QqS0v_sendMessage);
}

void Heavy_PhaseRing::cMsg_0LRAkaNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_DmmVHF9R, 2, m, &cDelay_DmmVHF9R_sendMessage);
}

void Heavy_PhaseRing::cMsg_BqcWSa7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RR0X2HCm, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_mzetk4Vv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cx4OtOSE, HV_BINOP_SUBTRACT, 0, m, &cBinop_cx4OtOSE_sendMessage);
}

void Heavy_PhaseRing::cMsg_Bx5MMFoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kGylcWYa_sendMessage);
}

void Heavy_PhaseRing::cSystem_kGylcWYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2NmTPGn4_sendMessage);
}

void Heavy_PhaseRing::cVar_hHWxpwwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LZwDIQVG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_ngMrLHA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ngMrLHA1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aqm2r4JH, 0, m, &cDelay_aqm2r4JH_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XHsUMFug, 0, m, &sTabread_XHsUMFug_sendMessage);
}

void Heavy_PhaseRing::cDelay_aqm2r4JH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aqm2r4JH, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XHsUMFug, 0, m, &sTabread_XHsUMFug_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aqm2r4JH, 0, m, &cDelay_aqm2r4JH_sendMessage);
}

void Heavy_PhaseRing::sTabread_XHsUMFug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_R5U2N8wq, HV_BINOP_SUBTRACT, 0, m, &cBinop_R5U2N8wq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_FCT697CN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sbrQ4hCX, HV_BINOP_MAX, 0, m, &cBinop_sbrQ4hCX_sendMessage);
}

void Heavy_PhaseRing::cBinop_2NmTPGn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FCT697CN, HV_BINOP_MULTIPLY, 0, m, &cBinop_FCT697CN_sendMessage);
}

void Heavy_PhaseRing::cBinop_cx4OtOSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SueB7vi0_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XHsUMFug, 0, m, &sTabread_XHsUMFug_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3F1c1MJg_sendMessage);
}

void Heavy_PhaseRing::cSystem_m8G5VwZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R5U2N8wq, HV_BINOP_SUBTRACT, 1, m, &cBinop_R5U2N8wq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aqm2r4JH, 2, m, &cDelay_aqm2r4JH_sendMessage);
}

void Heavy_PhaseRing::cMsg_LZwDIQVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m8G5VwZQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_SueB7vi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ngMrLHA1, 0, m, &cDelay_ngMrLHA1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aqm2r4JH, 0, m, &cDelay_aqm2r4JH_sendMessage);
}

void Heavy_PhaseRing::cMsg_UUDj2liq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_sbrQ4hCX, HV_BINOP_MAX, 1, m, &cBinop_sbrQ4hCX_sendMessage);
}

void Heavy_PhaseRing::cBinop_sbrQ4hCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cx4OtOSE, HV_BINOP_SUBTRACT, 1, m, &cBinop_cx4OtOSE_sendMessage);
}

void Heavy_PhaseRing::cCast_3F1c1MJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ngMrLHA1, 0, m, &cDelay_ngMrLHA1_sendMessage);
}

void Heavy_PhaseRing::cBinop_EofWumXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ngMrLHA1, 2, m, &cDelay_ngMrLHA1_sendMessage);
}

void Heavy_PhaseRing::cBinop_R5U2N8wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EofWumXy_sendMessage);
}

void Heavy_PhaseRing::cCast_sxmQFeqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hHWxpwwe, 0, m, &cVar_hHWxpwwe_sendMessage);
  cMsg_Bx5MMFoi_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mzetk4Vv, 0, m, &cTabhead_mzetk4Vv_sendMessage);
}

void Heavy_PhaseRing::cMsg_DupI7FGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2ZhMYbCw_sendMessage);
}

void Heavy_PhaseRing::cSystem_2ZhMYbCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OlzmxuEu_sendMessage);
}

void Heavy_PhaseRing::cDelay_mokxzJXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mokxzJXS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qdlnubbr, 0, m, &cDelay_qdlnubbr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mokxzJXS, 0, m, &cDelay_mokxzJXS_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_t0iQBUbP, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_qdlnubbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qdlnubbr, m);
  cMsg_4VjpQObk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_7a9y8r33_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_dvbuvL2h_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_MOgK41go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rz5pxvnL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_vh7RD3Lg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8SbOv4ee_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mokxzJXS, 2, m, &cDelay_mokxzJXS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fL8N7IQW_sendMessage);
}

void Heavy_PhaseRing::cMsg_Rz5pxvnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vh7RD3Lg, 0, m, &hTable_vh7RD3Lg_sendMessage);
}

void Heavy_PhaseRing::cBinop_OlzmxuEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_MOgK41go_sendMessage);
}

void Heavy_PhaseRing::cMsg_4VjpQObk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vh7RD3Lg, 0, m, &hTable_vh7RD3Lg_sendMessage);
}

void Heavy_PhaseRing::cCast_fL8N7IQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mokxzJXS, 0, m, &cDelay_mokxzJXS_sendMessage);
}

void Heavy_PhaseRing::cMsg_8SbOv4ee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_qdlnubbr, 2, m, &cDelay_qdlnubbr_sendMessage);
}

void Heavy_PhaseRing::cMsg_dvbuvL2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_t0iQBUbP, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_rERg4Liv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DF9paIA4, HV_BINOP_SUBTRACT, 0, m, &cBinop_DF9paIA4_sendMessage);
}

void Heavy_PhaseRing::cMsg_bDVehLYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a0og9UZb_sendMessage);
}

void Heavy_PhaseRing::cSystem_a0og9UZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pKNxhFEe_sendMessage);
}

void Heavy_PhaseRing::cVar_dYNNhLpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QfqoInPM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_93wShjTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_93wShjTF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_okTg6dys, 0, m, &cDelay_okTg6dys_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1BtsQpNq, 0, m, &sTabread_1BtsQpNq_sendMessage);
}

void Heavy_PhaseRing::cDelay_okTg6dys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_okTg6dys, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1BtsQpNq, 0, m, &sTabread_1BtsQpNq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_okTg6dys, 0, m, &cDelay_okTg6dys_sendMessage);
}

void Heavy_PhaseRing::sTabread_1BtsQpNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xxXxNYUs, HV_BINOP_SUBTRACT, 0, m, &cBinop_xxXxNYUs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_6td1YrXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ODMXiAlH, HV_BINOP_MAX, 0, m, &cBinop_ODMXiAlH_sendMessage);
}

void Heavy_PhaseRing::cBinop_pKNxhFEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6td1YrXQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_6td1YrXQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_DF9paIA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rw5ldmkl_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1BtsQpNq, 0, m, &sTabread_1BtsQpNq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AHw3rg4K_sendMessage);
}

void Heavy_PhaseRing::cSystem_Ez83S6U2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xxXxNYUs, HV_BINOP_SUBTRACT, 1, m, &cBinop_xxXxNYUs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_okTg6dys, 2, m, &cDelay_okTg6dys_sendMessage);
}

void Heavy_PhaseRing::cMsg_QfqoInPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ez83S6U2_sendMessage);
}

void Heavy_PhaseRing::cMsg_rw5ldmkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_93wShjTF, 0, m, &cDelay_93wShjTF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_okTg6dys, 0, m, &cDelay_okTg6dys_sendMessage);
}

void Heavy_PhaseRing::cMsg_amk55EPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ODMXiAlH, HV_BINOP_MAX, 1, m, &cBinop_ODMXiAlH_sendMessage);
}

void Heavy_PhaseRing::cBinop_ODMXiAlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DF9paIA4, HV_BINOP_SUBTRACT, 1, m, &cBinop_DF9paIA4_sendMessage);
}

void Heavy_PhaseRing::cCast_AHw3rg4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_93wShjTF, 0, m, &cDelay_93wShjTF_sendMessage);
}

void Heavy_PhaseRing::cBinop_13k7ROqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_93wShjTF, 2, m, &cDelay_93wShjTF_sendMessage);
}

void Heavy_PhaseRing::cBinop_xxXxNYUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_13k7ROqF_sendMessage);
}

void Heavy_PhaseRing::cCast_UTDoOcNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dYNNhLpj, 0, m, &cVar_dYNNhLpj_sendMessage);
  cMsg_bDVehLYh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_rERg4Liv, 0, m, &cTabhead_rERg4Liv_sendMessage);
}

void Heavy_PhaseRing::cMsg_7gcAApb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EybB4ZhG_sendMessage);
}

void Heavy_PhaseRing::cSystem_EybB4ZhG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KqPQQWVB_sendMessage);
}

void Heavy_PhaseRing::cDelay_5BKOqaS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5BKOqaS2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3O5EV52U, 0, m, &cDelay_3O5EV52U_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5BKOqaS2, 0, m, &cDelay_5BKOqaS2_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tfNspXeb, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_3O5EV52U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3O5EV52U, m);
  cMsg_CoEIRgNb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Pd9hj2ks_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_WIEbEaGf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_tthsvs5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2zJthg9B_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_1wru8MHW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xGYcdFEl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5BKOqaS2, 2, m, &cDelay_5BKOqaS2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n3hDULbk_sendMessage);
}

void Heavy_PhaseRing::cMsg_2zJthg9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_1wru8MHW, 0, m, &hTable_1wru8MHW_sendMessage);
}

void Heavy_PhaseRing::cBinop_KqPQQWVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_tthsvs5o_sendMessage);
}

void Heavy_PhaseRing::cMsg_CoEIRgNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_1wru8MHW, 0, m, &hTable_1wru8MHW_sendMessage);
}

void Heavy_PhaseRing::cCast_n3hDULbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5BKOqaS2, 0, m, &cDelay_5BKOqaS2_sendMessage);
}

void Heavy_PhaseRing::cMsg_xGYcdFEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_3O5EV52U, 2, m, &cDelay_3O5EV52U_sendMessage);
}

void Heavy_PhaseRing::cMsg_WIEbEaGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tfNspXeb, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_lyMX9Vqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ld25pwKY, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ld25pwKY_sendMessage);
}

void Heavy_PhaseRing::cMsg_DTE2NcGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bs8snF3G_sendMessage);
}

void Heavy_PhaseRing::cSystem_bs8snF3G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_U7ykO59B_sendMessage);
}

void Heavy_PhaseRing::cVar_TQxYDTLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4XYK9gnf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_P7ubHVOe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_P7ubHVOe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bDG8bUgh, 0, m, &cDelay_bDG8bUgh_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JO88ZHSN, 0, m, &sTabread_JO88ZHSN_sendMessage);
}

void Heavy_PhaseRing::cDelay_bDG8bUgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bDG8bUgh, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JO88ZHSN, 0, m, &sTabread_JO88ZHSN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bDG8bUgh, 0, m, &cDelay_bDG8bUgh_sendMessage);
}

void Heavy_PhaseRing::sTabread_JO88ZHSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_tSvYVgmm, HV_BINOP_SUBTRACT, 0, m, &cBinop_tSvYVgmm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_8PdJ2dIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QbMDrJ5D, HV_BINOP_MAX, 0, m, &cBinop_QbMDrJ5D_sendMessage);
}

void Heavy_PhaseRing::cBinop_U7ykO59B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8PdJ2dIU, HV_BINOP_MULTIPLY, 0, m, &cBinop_8PdJ2dIU_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ld25pwKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zzsyFUdj_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JO88ZHSN, 0, m, &sTabread_JO88ZHSN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4Y6M13kR_sendMessage);
}

void Heavy_PhaseRing::cSystem_I7JSAPEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tSvYVgmm, HV_BINOP_SUBTRACT, 1, m, &cBinop_tSvYVgmm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bDG8bUgh, 2, m, &cDelay_bDG8bUgh_sendMessage);
}

void Heavy_PhaseRing::cMsg_4XYK9gnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I7JSAPEH_sendMessage);
}

void Heavy_PhaseRing::cMsg_zzsyFUdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_P7ubHVOe, 0, m, &cDelay_P7ubHVOe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bDG8bUgh, 0, m, &cDelay_bDG8bUgh_sendMessage);
}

void Heavy_PhaseRing::cMsg_YLN0xubX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_QbMDrJ5D, HV_BINOP_MAX, 1, m, &cBinop_QbMDrJ5D_sendMessage);
}

void Heavy_PhaseRing::cBinop_QbMDrJ5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ld25pwKY, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ld25pwKY_sendMessage);
}

void Heavy_PhaseRing::cCast_4Y6M13kR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P7ubHVOe, 0, m, &cDelay_P7ubHVOe_sendMessage);
}

void Heavy_PhaseRing::cBinop_ErK7AdJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P7ubHVOe, 2, m, &cDelay_P7ubHVOe_sendMessage);
}

void Heavy_PhaseRing::cBinop_tSvYVgmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ErK7AdJ8_sendMessage);
}

void Heavy_PhaseRing::cCast_qYjZ3dud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TQxYDTLG, 0, m, &cVar_TQxYDTLG_sendMessage);
  cMsg_DTE2NcGM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lyMX9Vqq, 0, m, &cTabhead_lyMX9Vqq_sendMessage);
}

void Heavy_PhaseRing::cMsg_7tqygLuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yu3a9Cwm_sendMessage);
}

void Heavy_PhaseRing::cSystem_yu3a9Cwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dqBKCtxY_sendMessage);
}

void Heavy_PhaseRing::cDelay_tB5NZr4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tB5NZr4E, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGsue7Jz, 0, m, &cDelay_hGsue7Jz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tB5NZr4E, 0, m, &cDelay_tB5NZr4E_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TNUGkcbb, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_hGsue7Jz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hGsue7Jz, m);
  cMsg_uFCbcH0r_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_QNC6S1Tt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_HyxSMhM3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_qQAuhH48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aAJN1YAO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_PavbqHbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TKjjzag1_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tB5NZr4E, 2, m, &cDelay_tB5NZr4E_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_msHVry0O_sendMessage);
}

void Heavy_PhaseRing::cMsg_aAJN1YAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_PavbqHbh, 0, m, &hTable_PavbqHbh_sendMessage);
}

void Heavy_PhaseRing::cBinop_dqBKCtxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_qQAuhH48_sendMessage);
}

void Heavy_PhaseRing::cMsg_uFCbcH0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_PavbqHbh, 0, m, &hTable_PavbqHbh_sendMessage);
}

void Heavy_PhaseRing::cCast_msHVry0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tB5NZr4E, 0, m, &cDelay_tB5NZr4E_sendMessage);
}

void Heavy_PhaseRing::cMsg_TKjjzag1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGsue7Jz, 2, m, &cDelay_hGsue7Jz_sendMessage);
}

void Heavy_PhaseRing::cMsg_HyxSMhM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TNUGkcbb, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_VSjKuOI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5LMTsEU1, 0, m, &cVar_5LMTsEU1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CDX6aypC, 0, m, &cVar_CDX6aypC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VrH9KxJW, 0, m, &cVar_VrH9KxJW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_v4TOZ2fz, 0, m, &cVar_v4TOZ2fz_sendMessage);
}

void Heavy_PhaseRing::cVar_RLyMWiFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_uFh0pMmi_sendMessage);
}

void Heavy_PhaseRing::cPack_VPR0Oyw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zo3ZvJuV, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_CDX6aypC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2aCi1Z79, HV_BINOP_MULTIPLY, 0, m, &cBinop_2aCi1Z79_sendMessage);
}

void Heavy_PhaseRing::cMsg_ta0kD9KA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UXwgzzu6_sendMessage);
}

void Heavy_PhaseRing::cSystem_UXwgzzu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yQ1ZFoub_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_2aCi1Z79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_mCZW1O4z_sendMessage);
}

void Heavy_PhaseRing::cBinop_vr7dxzW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2aCi1Z79, HV_BINOP_MULTIPLY, 1, m, &cBinop_2aCi1Z79_sendMessage);
}

void Heavy_PhaseRing::cMsg_yQ1ZFoub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_vr7dxzW2_sendMessage);
}

void Heavy_PhaseRing::cBinop_mCZW1O4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_1iDOcup3_sendMessage);
}

void Heavy_PhaseRing::cBinop_1iDOcup3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_V7rBzaeG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fwaft1NL, m);
}

void Heavy_PhaseRing::cBinop_V7rBzaeG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xcWUBgW7, m);
}

void Heavy_PhaseRing::cVar_VrH9KxJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NKEbzBYs, HV_BINOP_MULTIPLY, 0, m, &cBinop_NKEbzBYs_sendMessage);
}

void Heavy_PhaseRing::cMsg_Mx6fpj0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iVRQt9Sg_sendMessage);
}

void Heavy_PhaseRing::cSystem_iVRQt9Sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r1lS8pKF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_NKEbzBYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_PH1X22Tu_sendMessage);
}

void Heavy_PhaseRing::cBinop_iof3QOCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NKEbzBYs, HV_BINOP_MULTIPLY, 1, m, &cBinop_NKEbzBYs_sendMessage);
}

void Heavy_PhaseRing::cMsg_r1lS8pKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_iof3QOCL_sendMessage);
}

void Heavy_PhaseRing::cBinop_PH1X22Tu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7xlxMpk7_sendMessage);
}

void Heavy_PhaseRing::cBinop_7xlxMpk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZuYelAgu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WRIyWlnY, m);
}

void Heavy_PhaseRing::cBinop_ZuYelAgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tntaR9Sq, m);
}

void Heavy_PhaseRing::cVar_v4TOZ2fz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hgMJ4t71, HV_BINOP_MULTIPLY, 0, m, &cBinop_hgMJ4t71_sendMessage);
}

void Heavy_PhaseRing::cMsg_6JRUMWYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2hhpdjwx_sendMessage);
}

void Heavy_PhaseRing::cSystem_2hhpdjwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7By11fXO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_hgMJ4t71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_hcgkySbd_sendMessage);
}

void Heavy_PhaseRing::cBinop_iysDNuEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hgMJ4t71, HV_BINOP_MULTIPLY, 1, m, &cBinop_hgMJ4t71_sendMessage);
}

void Heavy_PhaseRing::cMsg_7By11fXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_iysDNuEy_sendMessage);
}

void Heavy_PhaseRing::cBinop_hcgkySbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_s6VIo3Q6_sendMessage);
}

void Heavy_PhaseRing::cBinop_s6VIo3Q6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yxlEoR2x_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GKaTfz83, m);
}

void Heavy_PhaseRing::cBinop_yxlEoR2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fxzFrkbz, m);
}

void Heavy_PhaseRing::cBinop_nslgGy3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FIz5w5G4, 0, m, &cPack_FIz5w5G4_sendMessage);
}

void Heavy_PhaseRing::cMsg_MHzdKxZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_VSjKuOI6, 0, m, &cVar_VSjKuOI6_sendMessage);
}

void Heavy_PhaseRing::cBinop_uFh0pMmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_VPR0Oyw5, 0, m, &cPack_VPR0Oyw5_sendMessage);
}

void Heavy_PhaseRing::cBinop_nDo1DKW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rEYD88aI, 0, m, &cPack_rEYD88aI_sendMessage);
}

void Heavy_PhaseRing::cMsg_6GsPBCgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_siYyoYHY_sendMessage);
}

void Heavy_PhaseRing::cSystem_siYyoYHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AUkfz837_sendMessage);
}

void Heavy_PhaseRing::cVar_B6eyIehi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tCmqcheM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_KUd74GVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qpLk54PQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FAim4t1n, m);
}

void Heavy_PhaseRing::cBinop_AUkfz837_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NxdC7Wh7, m);
}

void Heavy_PhaseRing::cMsg_tCmqcheM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KUd74GVH_sendMessage);
}

void Heavy_PhaseRing::cBinop_qpLk54PQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yCVKRnXZ, m);
}

void Heavy_PhaseRing::cVar_KVzdF0qM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IQFT6Jx2, HV_BINOP_MULTIPLY, 0, m, &cBinop_IQFT6Jx2_sendMessage);
}

void Heavy_PhaseRing::cMsg_BL2cskMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QLH3MbB4_sendMessage);
}

void Heavy_PhaseRing::cSystem_QLH3MbB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WAf5uBMH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_IQFT6Jx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5YEkP4Dj_sendMessage);
}

void Heavy_PhaseRing::cBinop_etAqBRUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IQFT6Jx2, HV_BINOP_MULTIPLY, 1, m, &cBinop_IQFT6Jx2_sendMessage);
}

void Heavy_PhaseRing::cMsg_WAf5uBMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_etAqBRUx_sendMessage);
}

void Heavy_PhaseRing::cBinop_5YEkP4Dj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZWjyVWw7_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZWjyVWw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_04igeagx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Bzq9t0uV, m);
}

void Heavy_PhaseRing::cBinop_04igeagx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PwVR65dU, m);
}

void Heavy_PhaseRing::cBinop_3HKJyrOl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_sn065Ei4_sendMessage);
}

void Heavy_PhaseRing::cBinop_sn065Ei4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZANEuPlt, m);
}

void Heavy_PhaseRing::cBinop_0HJjK3rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NS1i7cM0_sendMessage);
}

void Heavy_PhaseRing::cBinop_NS1i7cM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_NAAyemyy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OktBwiPb_sendMessage);
}

void Heavy_PhaseRing::cVar_lUgV589c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_x0tFbBzC_sendMessage);
}

void Heavy_PhaseRing::cMsg_JrYo1XlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pfT1QSqt_sendMessage);
}

void Heavy_PhaseRing::cSystem_pfT1QSqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A4U4v2mk, HV_BINOP_DIVIDE, 1, m, &cBinop_A4U4v2mk_sendMessage);
}

void Heavy_PhaseRing::cBinop_NAAyemyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_LUBOzvzk_sendMessage);
}

void Heavy_PhaseRing::cBinop_LUBOzvzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kcnAdkui, m);
}

void Heavy_PhaseRing::cMsg_6bcQ2ldK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_AW8nLzoQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_AW8nLzoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0HJjK3rt_sendMessage);
}

void Heavy_PhaseRing::cBinop_OktBwiPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bItwYSzW, m);
}

void Heavy_PhaseRing::cBinop_x0tFbBzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_JYAaCTPe_sendMessage);
}

void Heavy_PhaseRing::cBinop_JYAaCTPe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A4U4v2mk, HV_BINOP_DIVIDE, 0, m, &cBinop_A4U4v2mk_sendMessage);
}

void Heavy_PhaseRing::cBinop_A4U4v2mk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6bcQ2ldK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_kBPXvb21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GElnQWrm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_R57l1Dgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_N69KpMD6_sendMessage);
}

void Heavy_PhaseRing::cSystem_N69KpMD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EOFQJtFs_sendMessage);
}

void Heavy_PhaseRing::cDelay_WXHuVXot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WXHuVXot, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9R3DgsoH, 0, m, &cDelay_9R3DgsoH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WXHuVXot, 0, m, &cDelay_WXHuVXot_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tO3dLHQB, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_9R3DgsoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9R3DgsoH, m);
  cMsg_r6hOYU1s_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_KAfwoagZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_pbuzfFRl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_a3hy7jQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vuHpuwP8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_T9jAKNOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qaq3B8WQ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WXHuVXot, 2, m, &cDelay_WXHuVXot_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P6QzJFG8_sendMessage);
}

void Heavy_PhaseRing::cMsg_vuHpuwP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_T9jAKNOt, 0, m, &hTable_T9jAKNOt_sendMessage);
}

void Heavy_PhaseRing::cBinop_EOFQJtFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_a3hy7jQH_sendMessage);
}

void Heavy_PhaseRing::cMsg_r6hOYU1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_T9jAKNOt, 0, m, &hTable_T9jAKNOt_sendMessage);
}

void Heavy_PhaseRing::cCast_P6QzJFG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WXHuVXot, 0, m, &cDelay_WXHuVXot_sendMessage);
}

void Heavy_PhaseRing::cMsg_qaq3B8WQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_9R3DgsoH, 2, m, &cDelay_9R3DgsoH_sendMessage);
}

void Heavy_PhaseRing::cMsg_pbuzfFRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tO3dLHQB, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_fIKVeVPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_GElnQWrm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_GElnQWrm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_DinFcQxm, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_FyA1UY0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_11F9nC2y, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_pTr4KZKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FyA1UY0E, 0, m, &cPack_FyA1UY0E_sendMessage);
}

void Heavy_PhaseRing::cCast_r0zHblPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8MwSLWQX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_GCa6fo9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_11F9nC2y, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_bn1cS26N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Rq44zWcE, m);
}

void Heavy_PhaseRing::cMsg_k2e80oMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_3HKJyrOl_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_3RGEWBKX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pociiKCb, 0, m, &cSlice_pociiKCb_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8DFLrIJe, 0, m, &cRandom_8DFLrIJe_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_lfKIV1Nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_caB498m9_sendMessage);
}

void Heavy_PhaseRing::cUnop_caB498m9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_xtI7qqRM_sendMessage);
}

void Heavy_PhaseRing::cRandom_8DFLrIJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_lfKIV1Nq_sendMessage);
}

void Heavy_PhaseRing::cSlice_pociiKCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8DFLrIJe, 1, m, &cRandom_8DFLrIJe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_bOO0JPIt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_StVkbkdC, 0, m, &cSlice_StVkbkdC_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nSle3PgA, 0, m, &cRandom_nSle3PgA_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_cNTgx5N6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KOAWTjFt_sendMessage);
}

void Heavy_PhaseRing::cUnop_KOAWTjFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nbBuuQ5x, 0, m, &cPack_nbBuuQ5x_sendMessage);
}

void Heavy_PhaseRing::cRandom_nSle3PgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_cNTgx5N6_sendMessage);
}

void Heavy_PhaseRing::cSlice_StVkbkdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nSle3PgA, 1, m, &cRandom_nSle3PgA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_fYSkS6T0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_SkOa0hIA_sendMessage);
}

void Heavy_PhaseRing::cPack_ELiExiSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RxSDlkHs, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_751TakYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2KfzMPFi_sendMessage);
}

void Heavy_PhaseRing::cBinop_OxtPRet0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_751TakYM_sendMessage);
}

void Heavy_PhaseRing::cPack_zHbILivG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_dgmmG0t8, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_9yBeSKfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_ThCZoUoJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_zGvPydnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ih7jd8eU_sendMessage);
}

void Heavy_PhaseRing::cSystem_ih7jd8eU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_B4Gc8ccK_sendMessage);
}

void Heavy_PhaseRing::cDelay_8K7vf75r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8K7vf75r, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_F1wZrRjN, 0, m, &cDelay_F1wZrRjN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8K7vf75r, 0, m, &cDelay_8K7vf75r_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tnd0hLZl, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_F1wZrRjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_F1wZrRjN, m);
  cMsg_uo4LEXgq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_ee7gL2pb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_DilTSS8f_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_SBOMrrh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ro3HS03I_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_7GuvTMSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bV2tdXYG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8K7vf75r, 2, m, &cDelay_8K7vf75r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Irk6Ry01_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ro3HS03I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7GuvTMSA, 0, m, &hTable_7GuvTMSA_sendMessage);
}

void Heavy_PhaseRing::cBinop_B4Gc8ccK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_SBOMrrh8_sendMessage);
}

void Heavy_PhaseRing::cMsg_uo4LEXgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7GuvTMSA, 0, m, &hTable_7GuvTMSA_sendMessage);
}

void Heavy_PhaseRing::cCast_Irk6Ry01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8K7vf75r, 0, m, &cDelay_8K7vf75r_sendMessage);
}

void Heavy_PhaseRing::cMsg_bV2tdXYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_F1wZrRjN, 2, m, &cDelay_F1wZrRjN_sendMessage);
}

void Heavy_PhaseRing::cMsg_DilTSS8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tnd0hLZl, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_c2DuGGDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xdB8vqnP_sendMessage);
}

void Heavy_PhaseRing::cSystem_xdB8vqnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OXRc1XFp_sendMessage);
}

void Heavy_PhaseRing::cVar_m4vdGBeV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yUI37vAr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_r58kpoOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iCCtdd2y_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JA0AGxfo, m);
}

void Heavy_PhaseRing::cBinop_OXRc1XFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wxsmK5Ta, m);
}

void Heavy_PhaseRing::cMsg_yUI37vAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r58kpoOL_sendMessage);
}

void Heavy_PhaseRing::cBinop_iCCtdd2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RqhgoR3A, m);
}

void Heavy_PhaseRing::cMsg_cMMpwVHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4iGvzaCK_sendMessage);
}

void Heavy_PhaseRing::cSystem_4iGvzaCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wXedak46_sendMessage);
}

void Heavy_PhaseRing::cVar_3gJgXJtB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1BYQSPtA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_TaHD9Z70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QubTUmYL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dkOteZzn, m);
}

void Heavy_PhaseRing::cBinop_wXedak46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9NODZsot, m);
}

void Heavy_PhaseRing::cMsg_1BYQSPtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TaHD9Z70_sendMessage);
}

void Heavy_PhaseRing::cBinop_QubTUmYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JFW85uH9, m);
}

void Heavy_PhaseRing::cBinop_FLQJd8SI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qqPONaiW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_ldTVpab1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_527cAoRL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YBPWRsrD_sendMessage);
}

void Heavy_PhaseRing::cCast_527cAoRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FLQJd8SI, HV_BINOP_DIVIDE, 1, m, &cBinop_FLQJd8SI_sendMessage);
}

void Heavy_PhaseRing::cCast_YBPWRsrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FLQJd8SI, HV_BINOP_DIVIDE, 0, m, &cBinop_FLQJd8SI_sendMessage);
}

void Heavy_PhaseRing::cBinop_2KfzMPFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XFr0U3Fj_sendMessage);
}

void Heavy_PhaseRing::cBinop_edrJzUcX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_OxtPRet0_sendMessage);
}

void Heavy_PhaseRing::cBinop_XFr0U3Fj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FLQJd8SI, HV_BINOP_DIVIDE, 0, m, &cBinop_FLQJd8SI_sendMessage);
}

void Heavy_PhaseRing::cBinop_ThCZoUoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zHbILivG, 0, m, &cPack_zHbILivG_sendMessage);
}

void Heavy_PhaseRing::cBinop_SkOa0hIA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_ldTVpab1_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_ELiExiSB, 0, m, &cPack_ELiExiSB_sendMessage);
}

void Heavy_PhaseRing::cMsg_hZ3EUkFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_fYSkS6T0, 0, m, &cVar_fYSkS6T0_sendMessage);
}

void Heavy_PhaseRing::cMsg_sBVwloCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_9yBeSKfN, 0, m, &cVar_9yBeSKfN_sendMessage);
}

void Heavy_PhaseRing::cMsg_qqPONaiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_LOsz3tmd, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_cS1RU6Da_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GEBuly4c_sendMessage);
}

void Heavy_PhaseRing::cSystem_GEBuly4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7YZSLSeh_sendMessage);
}

void Heavy_PhaseRing::cVar_7MjhLhbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eX14g6uO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_QVe69BNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_W0gqEw36_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Vnlz4DVC, m);
}

void Heavy_PhaseRing::cBinop_7YZSLSeh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jSJqeU5r, m);
}

void Heavy_PhaseRing::cMsg_eX14g6uO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QVe69BNG_sendMessage);
}

void Heavy_PhaseRing::cBinop_W0gqEw36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IaLQBw4s, m);
}

void Heavy_PhaseRing::cVar_s3SXLxzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zkuPRZN6, HV_BINOP_MULTIPLY, 0, m, &cBinop_zkuPRZN6_sendMessage);
}

void Heavy_PhaseRing::cMsg_O1KLuuSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QIVJbKel_sendMessage);
}

void Heavy_PhaseRing::cSystem_QIVJbKel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ipwA6YRC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_zkuPRZN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_H8T0ZrnC_sendMessage);
}

void Heavy_PhaseRing::cBinop_78ZzXj7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zkuPRZN6, HV_BINOP_MULTIPLY, 1, m, &cBinop_zkuPRZN6_sendMessage);
}

void Heavy_PhaseRing::cMsg_ipwA6YRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_78ZzXj7t_sendMessage);
}

void Heavy_PhaseRing::cBinop_H8T0ZrnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8kmDE5HQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_8kmDE5HQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_l6a7sDHl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RQtlcfhh, m);
}

void Heavy_PhaseRing::cBinop_l6a7sDHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8sIvH1e6, m);
}

void Heavy_PhaseRing::cBinop_tWSHlVvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_sqAhEyLV_sendMessage);
}

void Heavy_PhaseRing::cBinop_sqAhEyLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xcxvsYac, m);
}

void Heavy_PhaseRing::cBinop_BLis0uAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BQJbuZzN_sendMessage);
}

void Heavy_PhaseRing::cBinop_BQJbuZzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6DzxqxnG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3LE2INKz_sendMessage);
}

void Heavy_PhaseRing::cVar_5fyFYwxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_5wXdDA4G_sendMessage);
}

void Heavy_PhaseRing::cMsg_CX2R373U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rSpjQmFt_sendMessage);
}

void Heavy_PhaseRing::cSystem_rSpjQmFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y7Ol9vyP, HV_BINOP_DIVIDE, 1, m, &cBinop_Y7Ol9vyP_sendMessage);
}

void Heavy_PhaseRing::cBinop_6DzxqxnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_3VdGqCCM_sendMessage);
}

void Heavy_PhaseRing::cBinop_3VdGqCCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rRPfTKuk, m);
}

void Heavy_PhaseRing::cMsg_wTaDspVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Sx7uMUMI_sendMessage);
}

void Heavy_PhaseRing::cBinop_Sx7uMUMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_BLis0uAk_sendMessage);
}

void Heavy_PhaseRing::cBinop_3LE2INKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XKpgWGaM, m);
}

void Heavy_PhaseRing::cBinop_5wXdDA4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_3OeE9iSD_sendMessage);
}

void Heavy_PhaseRing::cBinop_3OeE9iSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y7Ol9vyP, HV_BINOP_DIVIDE, 0, m, &cBinop_Y7Ol9vyP_sendMessage);
}

void Heavy_PhaseRing::cBinop_Y7Ol9vyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wTaDspVA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_KpNo94y7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nj6XU9z0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ZQRPlwDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mmk5yHZg_sendMessage);
}

void Heavy_PhaseRing::cSystem_mmk5yHZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WLYGCr9E_sendMessage);
}

void Heavy_PhaseRing::cDelay_b9MvT5AB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_b9MvT5AB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wd429Bd4, 0, m, &cDelay_Wd429Bd4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_b9MvT5AB, 0, m, &cDelay_b9MvT5AB_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dNzPEqGw, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_Wd429Bd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Wd429Bd4, m);
  cMsg_VtKQDySH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_TLRytXuT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_rrUolvij_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_crSCUWYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sRyxOmRj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_BRVG0Edd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Un01XBiy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_b9MvT5AB, 2, m, &cDelay_b9MvT5AB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1TADiWfC_sendMessage);
}

void Heavy_PhaseRing::cMsg_sRyxOmRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_BRVG0Edd, 0, m, &hTable_BRVG0Edd_sendMessage);
}

void Heavy_PhaseRing::cBinop_WLYGCr9E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_crSCUWYD_sendMessage);
}

void Heavy_PhaseRing::cMsg_VtKQDySH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_BRVG0Edd, 0, m, &hTable_BRVG0Edd_sendMessage);
}

void Heavy_PhaseRing::cCast_1TADiWfC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_b9MvT5AB, 0, m, &cDelay_b9MvT5AB_sendMessage);
}

void Heavy_PhaseRing::cMsg_Un01XBiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wd429Bd4, 2, m, &cDelay_Wd429Bd4_sendMessage);
}

void Heavy_PhaseRing::cMsg_rrUolvij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dNzPEqGw, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_vbdiQfBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_nj6XU9z0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_nj6XU9z0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dvxg473t, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_wjFrCnRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_xTcuGaSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ujMDTp8e_sendMessage);
}

void Heavy_PhaseRing::cSystem_ujMDTp8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y4nhF3kl, HV_BINOP_MULTIPLY, 1, m, &cBinop_y4nhF3kl_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dBAIq5zf, HV_BINOP_MULTIPLY, 1, m, &cBinop_dBAIq5zf_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_D4TunZXC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_yOt2AFin_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_yOt2AFin_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ul5XeSno_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_tGoOzEZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tGoOzEZE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGoOzEZE, 0, m, &cDelay_tGoOzEZE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jQ2PKway, 0, m, &cVar_jQ2PKway_sendMessage);
}

void Heavy_PhaseRing::cCast_ul5XeSno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yOt2AFin_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGoOzEZE, 0, m, &cDelay_tGoOzEZE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jQ2PKway, 0, m, &cVar_jQ2PKway_sendMessage);
}

void Heavy_PhaseRing::cMsg_QNWCVE54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vucmf0ZP_sendMessage);
}

void Heavy_PhaseRing::cSystem_vucmf0ZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hIPMKbp9_sendMessage);
}

void Heavy_PhaseRing::cVar_8CRKRHuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t1Vk3P8l, HV_BINOP_MULTIPLY, 0, m, &cBinop_t1Vk3P8l_sendMessage);
}

void Heavy_PhaseRing::cMsg_yOt2AFin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGoOzEZE, 0, m, &cDelay_tGoOzEZE_sendMessage);
}

void Heavy_PhaseRing::cBinop_i7q51Wtu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGoOzEZE, 2, m, &cDelay_tGoOzEZE_sendMessage);
}

void Heavy_PhaseRing::cBinop_hIPMKbp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t1Vk3P8l, HV_BINOP_MULTIPLY, 1, m, &cBinop_t1Vk3P8l_sendMessage);
}

void Heavy_PhaseRing::cBinop_t1Vk3P8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_i7q51Wtu_sendMessage);
}

void Heavy_PhaseRing::cVar_jQ2PKway_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eHU5LfkQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_eHU5LfkQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Wbj8vRpM_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_C3KLjq56_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RQfjNdwL_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WJyaJJit_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_RQfjNdwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ux5c8vAm, 0, m, &cVar_Ux5c8vAm_sendMessage);
}

void Heavy_PhaseRing::cCast_WJyaJJit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nAk6qC1k_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0ugKgSYY_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_KPOUvdJ8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nvRUROO6, 0, m, &cSlice_nvRUROO6_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BVblME9o, 0, m, &cSlice_BVblME9o_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DxMzLaNd_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dfP92UzD, 0, m, &cSlice_dfP92UzD_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_tgwEM8gv, 0, m, &cSlice_tgwEM8gv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zu6o1hN5_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N6vNA1gk_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_nvRUROO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_pCc2AXhw_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_pCc2AXhw_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_BVblME9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L6okVVHG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J6OY9zdo_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L6okVVHG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J6OY9zdo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_HiwtXj4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LdCKwVwa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M3DXJzAJ_sendMessage);
}

void Heavy_PhaseRing::cVar_kqxlJ3sZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RVkAPwpy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_RVkAPwpy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DDaJfR3c_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_y4nhF3kl, HV_BINOP_MULTIPLY, 0, m, &cBinop_y4nhF3kl_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_da9NdIzf, HV_BINOP_DIVIDE, 1, m, &cBinop_da9NdIzf_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_8CRKRHuo, 0, m, &cVar_8CRKRHuo_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_DDaJfR3c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FgclODnq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_3s9WM3nx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NtYfrCJv, HV_BINOP_SUBTRACT, 1, m, &cBinop_NtYfrCJv_sendMessage);
}

void Heavy_PhaseRing::cVar_RgeZUcOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ux5c8vAm, 0, m, &cVar_Ux5c8vAm_sendMessage);
}

void Heavy_PhaseRing::cVar_Ux5c8vAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OT5uZDkJ, HV_BINOP_ADD, 0, m, &cBinop_OT5uZDkJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FhuYEvja, HV_BINOP_ADD, 0, m, &cBinop_FhuYEvja_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_x6DpVOEB, 0, m, &cVar_x6DpVOEB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_edrJzUcX_sendMessage);
}

void Heavy_PhaseRing::cSlice_dfP92UzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LdCKwVwa_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M3DXJzAJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_tgwEM8gv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K5xcl824_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_h6zCuNtI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_YVLr4Ctj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jQ2PKway, 1, m, &cVar_jQ2PKway_sendMessage);
}

void Heavy_PhaseRing::cBinop_dBAIq5zf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YVLr4Ctj_sendMessage);
}

void Heavy_PhaseRing::cBinop_y4nhF3kl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YvDzKw21_sendMessage);
}

void Heavy_PhaseRing::cBinop_YvDzKw21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eHU5LfkQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_eHU5LfkQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_eHU5LfkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jQ2PKway, 1, m, &cVar_jQ2PKway_sendMessage);
}

void Heavy_PhaseRing::cMsg_oo6s9KMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_D4TunZXC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_cW9rfbrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_D4TunZXC_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FhuYEvja, HV_BINOP_ADD, 1, m, &cBinop_FhuYEvja_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OT5uZDkJ, HV_BINOP_ADD, 1, m, &cBinop_OT5uZDkJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_Wbj8vRpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_C3KLjq56_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_OT5uZDkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ux5c8vAm, 1, m, &cVar_Ux5c8vAm_sendMessage);
}

void Heavy_PhaseRing::cBinop_da9NdIzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lXVMcWzE, HV_BINOP_DIVIDE, 1, m, &cBinop_lXVMcWzE_sendMessage);
}

void Heavy_PhaseRing::cBinop_lXVMcWzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FhuYEvja, HV_BINOP_ADD, 1, m, &cBinop_FhuYEvja_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OT5uZDkJ, HV_BINOP_ADD, 1, m, &cBinop_OT5uZDkJ_sendMessage);
}

void Heavy_PhaseRing::cCast_M3DXJzAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_da9NdIzf, HV_BINOP_DIVIDE, 0, m, &cBinop_da9NdIzf_sendMessage);
}

void Heavy_PhaseRing::cCast_LdCKwVwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dBAIq5zf, HV_BINOP_MULTIPLY, 0, m, &cBinop_dBAIq5zf_sendMessage);
}

void Heavy_PhaseRing::cCast_K5xcl824_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RgeZUcOg, 1, m, &cVar_RgeZUcOg_sendMessage);
}

void Heavy_PhaseRing::cCast_h6zCuNtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NtYfrCJv, HV_BINOP_SUBTRACT, 0, m, &cBinop_NtYfrCJv_sendMessage);
}

void Heavy_PhaseRing::cCast_nAk6qC1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cW9rfbrS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_0ugKgSYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RgeZUcOg, 0, m, &cVar_RgeZUcOg_sendMessage);
}

void Heavy_PhaseRing::cBinop_FhuYEvja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3s9WM3nx, 0, m, &cVar_3s9WM3nx_sendMessage);
}

void Heavy_PhaseRing::cMsg_pCc2AXhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_D4TunZXC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_MtBAwHJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_HiwtXj4v, 1, m, &cVar_HiwtXj4v_sendMessage);
}

void Heavy_PhaseRing::cMsg_FgclODnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_y4nhF3kl, HV_BINOP_MULTIPLY, 0, m, &cBinop_y4nhF3kl_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_da9NdIzf, HV_BINOP_DIVIDE, 1, m, &cBinop_da9NdIzf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8CRKRHuo, 0, m, &cVar_8CRKRHuo_sendMessage);
}

void Heavy_PhaseRing::cCast_J6OY9zdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nCMRL7iL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FhuYEvja, HV_BINOP_ADD, 0, m, &cBinop_FhuYEvja_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ux5c8vAm, 1, m, &cVar_Ux5c8vAm_sendMessage);
}

void Heavy_PhaseRing::cCast_L6okVVHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pCc2AXhw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_NtYfrCJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lXVMcWzE, HV_BINOP_DIVIDE, 0, m, &cBinop_lXVMcWzE_sendMessage);
}

void Heavy_PhaseRing::cCast_nCMRL7iL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cW9rfbrS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_Zu6o1hN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oo6s9KMM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_DxMzLaNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HiwtXj4v, 0, m, &cVar_HiwtXj4v_sendMessage);
}

void Heavy_PhaseRing::cCast_N6vNA1gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MtBAwHJB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_x6DpVOEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_d4wbZFDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WFvnFpZx_sendMessage);
}

void Heavy_PhaseRing::cSystem_WFvnFpZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vlm7BGqs, HV_BINOP_MULTIPLY, 1, m, &cBinop_vlm7BGqs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_a76BC4DE, HV_BINOP_MULTIPLY, 1, m, &cBinop_a76BC4DE_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_lfMSIMdZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_ZDWYJXuj_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ZDWYJXuj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hH8TB5dz_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_csytpbCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_csytpbCe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_csytpbCe, 0, m, &cDelay_csytpbCe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qtVulrrs, 0, m, &cVar_qtVulrrs_sendMessage);
}

void Heavy_PhaseRing::cCast_hH8TB5dz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZDWYJXuj_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_csytpbCe, 0, m, &cDelay_csytpbCe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qtVulrrs, 0, m, &cVar_qtVulrrs_sendMessage);
}

void Heavy_PhaseRing::cMsg_wzQ06Fwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_d4dUEwo7_sendMessage);
}

void Heavy_PhaseRing::cSystem_d4dUEwo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_B4RD2op3_sendMessage);
}

void Heavy_PhaseRing::cVar_M969CT5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5KYiGRTu, HV_BINOP_MULTIPLY, 0, m, &cBinop_5KYiGRTu_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZDWYJXuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_csytpbCe, 0, m, &cDelay_csytpbCe_sendMessage);
}

void Heavy_PhaseRing::cBinop_ItIVvSVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_csytpbCe, 2, m, &cDelay_csytpbCe_sendMessage);
}

void Heavy_PhaseRing::cBinop_B4RD2op3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5KYiGRTu, HV_BINOP_MULTIPLY, 1, m, &cBinop_5KYiGRTu_sendMessage);
}

void Heavy_PhaseRing::cBinop_5KYiGRTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ItIVvSVV_sendMessage);
}

void Heavy_PhaseRing::cVar_qtVulrrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nAaeMzxo, HV_BINOP_SUBTRACT, 0, m, &cBinop_nAaeMzxo_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_0rSVPVI1_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_qMsskkxH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HiOQorw3_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mv4K05WN_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_HiOQorw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0J9Bc3Z6, 0, m, &cVar_0J9Bc3Z6_sendMessage);
}

void Heavy_PhaseRing::cCast_mv4K05WN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ryhkwDwu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OTk52TWW_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_G6CYxVbu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sSTjRaP3, 0, m, &cSlice_sSTjRaP3_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_59pei6Ik, 0, m, &cSlice_59pei6Ik_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4HebiE2E_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lZhF3YbG, 0, m, &cSlice_lZhF3YbG_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ss8VoQMF, 0, m, &cSlice_ss8VoQMF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FexOvQ4H_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qh9rUTps_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_sSTjRaP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_tpHtlqu2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_tpHtlqu2_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_59pei6Ik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eeD5GRpW_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Las6uSX4_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eeD5GRpW_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Las6uSX4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_yaJ5IQoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xS2wPGCB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JQjW1j9w_sendMessage);
}

void Heavy_PhaseRing::cVar_cXidXB74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_okvYUiYY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_okvYUiYY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4Jipp7vP_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vlm7BGqs, HV_BINOP_MULTIPLY, 0, m, &cBinop_vlm7BGqs_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_dPPORfjY, HV_BINOP_DIVIDE, 1, m, &cBinop_dPPORfjY_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_M969CT5o, 0, m, &cVar_M969CT5o_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_4Jipp7vP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aBorK9Wv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_k0UU3g9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oM7E0VMt, HV_BINOP_SUBTRACT, 1, m, &cBinop_oM7E0VMt_sendMessage);
}

void Heavy_PhaseRing::cVar_H7iuF1EU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0J9Bc3Z6, 0, m, &cVar_0J9Bc3Z6_sendMessage);
}

void Heavy_PhaseRing::cVar_0J9Bc3Z6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_whlr7eYj, HV_BINOP_ADD, 0, m, &cBinop_whlr7eYj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7Rzy6Wz, HV_BINOP_ADD, 0, m, &cBinop_l7Rzy6Wz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wjFrCnRx, 0, m, &cVar_wjFrCnRx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fng3KQbh, m);
}

void Heavy_PhaseRing::cSlice_lZhF3YbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xS2wPGCB_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JQjW1j9w_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_ss8VoQMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bCt2P1oI_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BaqVEqQo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_5RkLuXBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qtVulrrs, 1, m, &cVar_qtVulrrs_sendMessage);
}

void Heavy_PhaseRing::cBinop_a76BC4DE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5RkLuXBb_sendMessage);
}

void Heavy_PhaseRing::cBinop_vlm7BGqs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nrcT9yuS_sendMessage);
}

void Heavy_PhaseRing::cBinop_nrcT9yuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nAaeMzxo, HV_BINOP_SUBTRACT, 1, m, &cBinop_nAaeMzxo_sendMessage);
}

void Heavy_PhaseRing::cBinop_nAaeMzxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qtVulrrs, 1, m, &cVar_qtVulrrs_sendMessage);
}

void Heavy_PhaseRing::cMsg_J6YRU8cM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_lfMSIMdZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_VaNIvMt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_lfMSIMdZ_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7Rzy6Wz, HV_BINOP_ADD, 1, m, &cBinop_l7Rzy6Wz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_whlr7eYj, HV_BINOP_ADD, 1, m, &cBinop_whlr7eYj_sendMessage);
}

void Heavy_PhaseRing::cBinop_0rSVPVI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qMsskkxH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_whlr7eYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0J9Bc3Z6, 1, m, &cVar_0J9Bc3Z6_sendMessage);
}

void Heavy_PhaseRing::cBinop_dPPORfjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4iVbTpYQ, HV_BINOP_DIVIDE, 1, m, &cBinop_4iVbTpYQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_4iVbTpYQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7Rzy6Wz, HV_BINOP_ADD, 1, m, &cBinop_l7Rzy6Wz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_whlr7eYj, HV_BINOP_ADD, 1, m, &cBinop_whlr7eYj_sendMessage);
}

void Heavy_PhaseRing::cCast_xS2wPGCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a76BC4DE, HV_BINOP_MULTIPLY, 0, m, &cBinop_a76BC4DE_sendMessage);
}

void Heavy_PhaseRing::cCast_JQjW1j9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dPPORfjY, HV_BINOP_DIVIDE, 0, m, &cBinop_dPPORfjY_sendMessage);
}

void Heavy_PhaseRing::cCast_BaqVEqQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oM7E0VMt, HV_BINOP_SUBTRACT, 0, m, &cBinop_oM7E0VMt_sendMessage);
}

void Heavy_PhaseRing::cCast_bCt2P1oI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H7iuF1EU, 1, m, &cVar_H7iuF1EU_sendMessage);
}

void Heavy_PhaseRing::cCast_OTk52TWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H7iuF1EU, 0, m, &cVar_H7iuF1EU_sendMessage);
}

void Heavy_PhaseRing::cCast_ryhkwDwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VaNIvMt9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_l7Rzy6Wz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k0UU3g9m, 0, m, &cVar_k0UU3g9m_sendMessage);
}

void Heavy_PhaseRing::cMsg_tpHtlqu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_lfMSIMdZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_YeNGeBwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_yaJ5IQoG, 1, m, &cVar_yaJ5IQoG_sendMessage);
}

void Heavy_PhaseRing::cMsg_aBorK9Wv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vlm7BGqs, HV_BINOP_MULTIPLY, 0, m, &cBinop_vlm7BGqs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dPPORfjY, HV_BINOP_DIVIDE, 1, m, &cBinop_dPPORfjY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_M969CT5o, 0, m, &cVar_M969CT5o_sendMessage);
}

void Heavy_PhaseRing::cCast_Las6uSX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U9d4T82Y_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7Rzy6Wz, HV_BINOP_ADD, 0, m, &cBinop_l7Rzy6Wz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0J9Bc3Z6, 1, m, &cVar_0J9Bc3Z6_sendMessage);
}

void Heavy_PhaseRing::cCast_eeD5GRpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tpHtlqu2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_oM7E0VMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4iVbTpYQ, HV_BINOP_DIVIDE, 0, m, &cBinop_4iVbTpYQ_sendMessage);
}

void Heavy_PhaseRing::cCast_U9d4T82Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VaNIvMt9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_FexOvQ4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J6YRU8cM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_4HebiE2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yaJ5IQoG, 0, m, &cVar_yaJ5IQoG_sendMessage);
}

void Heavy_PhaseRing::cCast_qh9rUTps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YeNGeBwN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_lj3CVp5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_t3Uzaxmb, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_nBhvg53r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KPOUvdJ8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_nbBuuQ5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_G6CYxVbu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_Bd6dwvLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_vxGKmvlB_sendMessage);
}

void Heavy_PhaseRing::cBinop_vxGKmvlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nBhvg53r, 0, m, &cPack_nBhvg53r_sendMessage);
}

void Heavy_PhaseRing::cBinop_xtI7qqRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Bd6dwvLf_sendMessage);
}

void Heavy_PhaseRing::cCast_RaKqBflO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3RGEWBKX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_BmO3zgC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bOO0JPIt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_0Ts8SxMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_tWSHlVvU_sendMessage);
}

void Heavy_PhaseRing::cVar_yy7u2DPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m9Bv0tLn_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_obhAC7yJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SgFtEin2_sendMessage);
}

void Heavy_PhaseRing::cIf_ktDIzt8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5AcyBliN_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Vsul0Sj4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_vEqO5JSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nEN4eHhT, HV_BINOP_POW, 0, m, &cBinop_nEN4eHhT_sendMessage);
}

void Heavy_PhaseRing::cBinop_nEN4eHhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8xMASgQt, 0, m, &cPack_8xMASgQt_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZrXArOQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Mjsy3pEo_sendMessage);
}

void Heavy_PhaseRing::cCast_obhAC7yJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_zrXqULgK_sendMessage);
}

void Heavy_PhaseRing::cCast_SgFtEin2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ktDIzt8g, 0, m, &cIf_ktDIzt8g_sendMessage);
}

void Heavy_PhaseRing::cBinop_zrXqULgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ktDIzt8g, 1, m, &cIf_ktDIzt8g_sendMessage);
}

void Heavy_PhaseRing::cBinop_Vsul0Sj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_ZrXArOQe_sendMessage);
}

void Heavy_PhaseRing::cMsg_5AcyBliN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_8xMASgQt, 0, m, &cPack_8xMASgQt_sendMessage);
}

void Heavy_PhaseRing::cBinop_Mjsy3pEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nEN4eHhT, HV_BINOP_POW, 1, m, &cBinop_nEN4eHhT_sendMessage);
  cMsg_vEqO5JSl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_8xMASgQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_a3969af3, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_kGp7c0Ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_K2KWPted_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_m9Bv0tLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_zj3jHInd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_zj3jHInd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_F5dEd7ti_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_K2KWPted_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_i9hE7C9l_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_wm0wVmwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oy7Lwao6_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zSmuOUl9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xZUlIDsg_sendMessage);
}

void Heavy_PhaseRing::cIf_zxf3sfnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WhpD0gxV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_vco2kEs6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_6zvpYtlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VbRuF6q3, HV_BINOP_POW, 0, m, &cBinop_VbRuF6q3_sendMessage);
}

void Heavy_PhaseRing::cBinop_VbRuF6q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hPYcf5jS, 0, m, &cPack_hPYcf5jS_sendMessage);
}

void Heavy_PhaseRing::cBinop_4i0eLNP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Tiuih0Bt_sendMessage);
}

void Heavy_PhaseRing::cCast_xZUlIDsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zxf3sfnV, 0, m, &cIf_zxf3sfnV_sendMessage);
}

void Heavy_PhaseRing::cCast_zSmuOUl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_FqFaSKrE_sendMessage);
}

void Heavy_PhaseRing::cBinop_FqFaSKrE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zxf3sfnV, 1, m, &cIf_zxf3sfnV_sendMessage);
}

void Heavy_PhaseRing::cBinop_vco2kEs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_4i0eLNP5_sendMessage);
}

void Heavy_PhaseRing::cMsg_WhpD0gxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_hPYcf5jS, 0, m, &cPack_hPYcf5jS_sendMessage);
}

void Heavy_PhaseRing::cBinop_Tiuih0Bt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VbRuF6q3, HV_BINOP_POW, 1, m, &cBinop_VbRuF6q3_sendMessage);
  cMsg_6zvpYtlS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_hPYcf5jS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Y7iZe6LJ, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_836UydQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TOysgRA2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_oy7Lwao6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_LrsDuRzm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_LrsDuRzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UgACIFTM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_TOysgRA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EHYKwga2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_efq16Bf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gjeVkiUx_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_bhwEw3Mn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_bhwEw3Mn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_LbjjtjBG_sendMessage);
}

void Heavy_PhaseRing::cCast_V2qDSgC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_efq16Bf3, 0, m, &cIf_efq16Bf3_sendMessage);
}

void Heavy_PhaseRing::cCast_ZVbEesVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yJtlP9lq_sendMessage);
}

void Heavy_PhaseRing::cMsg_gjeVkiUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_m9Bv0tLn_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_obhAC7yJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SgFtEin2_sendMessage);
}

void Heavy_PhaseRing::cBinop_LbjjtjBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_c9FZGkBo_sendMessage);
}

void Heavy_PhaseRing::cBinop_c9FZGkBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_HnarJ7k9_sendMessage);
}

void Heavy_PhaseRing::cBinop_HnarJ7k9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m9Bv0tLn_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_obhAC7yJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SgFtEin2_sendMessage);
}

void Heavy_PhaseRing::cBinop_yJtlP9lq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_efq16Bf3, 1, m, &cIf_efq16Bf3_sendMessage);
}

void Heavy_PhaseRing::cBinop_9nM1n8d1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZVbEesVa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_V2qDSgC0_sendMessage);
}

void Heavy_PhaseRing::cBinop_320ZTwnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9nM1n8d1_sendMessage);
}

void Heavy_PhaseRing::cIf_ZehOVtjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_LLNFdEhA_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_UugijJTv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_UugijJTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_8umuanSM_sendMessage);
}

void Heavy_PhaseRing::cCast_cLZofvwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_bj6FbzoS_sendMessage);
}

void Heavy_PhaseRing::cCast_Rlhk05Vz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZehOVtjS, 0, m, &cIf_ZehOVtjS_sendMessage);
}

void Heavy_PhaseRing::cMsg_LLNFdEhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_oy7Lwao6_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zSmuOUl9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xZUlIDsg_sendMessage);
}

void Heavy_PhaseRing::cBinop_8umuanSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_SEXrGqVg_sendMessage);
}

void Heavy_PhaseRing::cBinop_SEXrGqVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_u2LTcWNO_sendMessage);
}

void Heavy_PhaseRing::cBinop_u2LTcWNO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oy7Lwao6_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zSmuOUl9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xZUlIDsg_sendMessage);
}

void Heavy_PhaseRing::cBinop_bj6FbzoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZehOVtjS, 1, m, &cIf_ZehOVtjS_sendMessage);
}

void Heavy_PhaseRing::cBinop_HHDEAouM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cLZofvwO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rlhk05Vz_sendMessage);
}

void Heavy_PhaseRing::cBinop_cWtHhJeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_HHDEAouM_sendMessage);
}

void Heavy_PhaseRing::cVar_vgNw3AV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VULPii8v_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KaNqAECU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BZB3wO00_sendMessage);
}

void Heavy_PhaseRing::cIf_6TUkv7BL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_AbDMD3D6_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_QCtkfv41_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_kF0JihRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rrvflGKn, HV_BINOP_POW, 0, m, &cBinop_rrvflGKn_sendMessage);
}

void Heavy_PhaseRing::cBinop_rrvflGKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mawjhgeE, 0, m, &cPack_mawjhgeE_sendMessage);
}

void Heavy_PhaseRing::cBinop_k891nFcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_kCdoDK6Z_sendMessage);
}

void Heavy_PhaseRing::cCast_BZB3wO00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6TUkv7BL, 0, m, &cIf_6TUkv7BL_sendMessage);
}

void Heavy_PhaseRing::cCast_KaNqAECU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_0NE1XZhy_sendMessage);
}

void Heavy_PhaseRing::cBinop_0NE1XZhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6TUkv7BL, 1, m, &cIf_6TUkv7BL_sendMessage);
}

void Heavy_PhaseRing::cBinop_QCtkfv41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_k891nFcY_sendMessage);
}

void Heavy_PhaseRing::cMsg_AbDMD3D6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_mawjhgeE, 0, m, &cPack_mawjhgeE_sendMessage);
}

void Heavy_PhaseRing::cBinop_kCdoDK6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rrvflGKn, HV_BINOP_POW, 1, m, &cBinop_rrvflGKn_sendMessage);
  cMsg_kF0JihRv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_mawjhgeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_pkRaBx80, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_zmUQx012_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JEkHK0oR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_VULPii8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_gfGH08QW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_gfGH08QW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1yQIaM5Y_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_JEkHK0oR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sz1syj4D_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_CoQ2QmcJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YFJUysXG_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H4qEuC5q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_T86H1T8Q_sendMessage);
}

void Heavy_PhaseRing::cIf_GY6gzMjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rCoOWH82_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_gNifx7uW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_o7Jh5fPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UXZqsQOt, HV_BINOP_POW, 0, m, &cBinop_UXZqsQOt_sendMessage);
}

void Heavy_PhaseRing::cBinop_UXZqsQOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_q53Zlbry, 0, m, &cPack_q53Zlbry_sendMessage);
}

void Heavy_PhaseRing::cBinop_b1jTYYyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_PZgM8hw4_sendMessage);
}

void Heavy_PhaseRing::cCast_T86H1T8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GY6gzMjG, 0, m, &cIf_GY6gzMjG_sendMessage);
}

void Heavy_PhaseRing::cCast_H4qEuC5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Sd31yuNy_sendMessage);
}

void Heavy_PhaseRing::cBinop_Sd31yuNy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GY6gzMjG, 1, m, &cIf_GY6gzMjG_sendMessage);
}

void Heavy_PhaseRing::cBinop_gNifx7uW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_b1jTYYyp_sendMessage);
}

void Heavy_PhaseRing::cMsg_rCoOWH82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_q53Zlbry, 0, m, &cPack_q53Zlbry_sendMessage);
}

void Heavy_PhaseRing::cBinop_PZgM8hw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UXZqsQOt, HV_BINOP_POW, 1, m, &cBinop_UXZqsQOt_sendMessage);
  cMsg_o7Jh5fPJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_q53Zlbry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lZ7zgSzw, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_26iW6huZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SpGllSj0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_YFJUysXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_lOYgCd45_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_lOYgCd45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_I0Gfc08Y_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_SpGllSj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4UjoCW5G_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_XYNJNEsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bFLti6QY_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4nimggjv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HTjKXPqW_sendMessage);
}

void Heavy_PhaseRing::cIf_L3FuPtI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_PqPx01IH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_AUwGB7vq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_oAms7VSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mp6KMkpD, HV_BINOP_POW, 0, m, &cBinop_mp6KMkpD_sendMessage);
}

void Heavy_PhaseRing::cBinop_mp6KMkpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3NlgJCQH, 0, m, &cPack_3NlgJCQH_sendMessage);
}

void Heavy_PhaseRing::cBinop_vHYxmAdF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_zjd9E06e_sendMessage);
}

void Heavy_PhaseRing::cCast_4nimggjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_GakZA5ab_sendMessage);
}

void Heavy_PhaseRing::cCast_HTjKXPqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_L3FuPtI6, 0, m, &cIf_L3FuPtI6_sendMessage);
}

void Heavy_PhaseRing::cBinop_GakZA5ab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_L3FuPtI6, 1, m, &cIf_L3FuPtI6_sendMessage);
}

void Heavy_PhaseRing::cBinop_AUwGB7vq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_vHYxmAdF_sendMessage);
}

void Heavy_PhaseRing::cMsg_PqPx01IH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_3NlgJCQH, 0, m, &cPack_3NlgJCQH_sendMessage);
}

void Heavy_PhaseRing::cBinop_zjd9E06e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mp6KMkpD, HV_BINOP_POW, 1, m, &cBinop_mp6KMkpD_sendMessage);
  cMsg_oAms7VSJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_3NlgJCQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_rMs0vHVo, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_mL16X60G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_hb33dgPc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_bFLti6QY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_ApyuwBaq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ApyuwBaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YT4AJVHt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_hb33dgPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BR1JSnsx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_TOzuRusS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gbhQn5d6, 0, m, &cIf_gbhQn5d6_sendMessage);
}

void Heavy_PhaseRing::cSlice_rP2DqFDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lhlYouzN_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Z0yIbBe2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_dFOkW6fv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_uhJfd3ds, 0, m, &cIf_uhJfd3ds_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_uhJfd3ds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dAswxLGI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3YKp6x8A_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_49YgxZV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_K8jbMucM, 2, m, &cPack_K8jbMucM_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_wCas8DYj, 1, m, &cPack_wCas8DYj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_Kf0nzgJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_rP2DqFDa, 0, m, &cSlice_rP2DqFDa_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dFOkW6fv, 0, m, &cSlice_dFOkW6fv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_11knuROK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_a086Wh94_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_iOVw4Kwd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YSgot8ne_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N8wSQHt0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eVnBmSt7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_nXjuoZsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_e4IK4MES, 1, m, &cIf_e4IK4MES_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_f69Tmabh_sendMessage);
}

void Heavy_PhaseRing::cIf_e4IK4MES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_rP2DqFDa, 0, m, &cSlice_rP2DqFDa_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dFOkW6fv, 0, m, &cSlice_dFOkW6fv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_wCas8DYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Kf0nzgJ7, 0, m, &cIf_Kf0nzgJ7_sendMessage);
}

void Heavy_PhaseRing::cBinop_jcMxyraj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uhJfd3ds, 1, m, &cIf_uhJfd3ds_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_49YgxZV7, 1, m, &cIf_49YgxZV7_sendMessage);
}

void Heavy_PhaseRing::cCast_Z0yIbBe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_49YgxZV7, 0, m, &cIf_49YgxZV7_sendMessage);
}

void Heavy_PhaseRing::cCast_lhlYouzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_jcMxyraj_sendMessage);
}

void Heavy_PhaseRing::cMsg_eqMlKFpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_nXjuoZsi, 1, m, &cVar_nXjuoZsi_sendMessage);
}

void Heavy_PhaseRing::cMsg_a086Wh94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_nXjuoZsi, 1, m, &cVar_nXjuoZsi_sendMessage);
}

void Heavy_PhaseRing::cCast_eVnBmSt7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eqMlKFpL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_N8wSQHt0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wCas8DYj, 0, m, &cPack_wCas8DYj_sendMessage);
}

void Heavy_PhaseRing::cCast_YSgot8ne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nXjuoZsi, 0, m, &cVar_nXjuoZsi_sendMessage);
}

void Heavy_PhaseRing::cBinop_f69Tmabh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Kf0nzgJ7, 1, m, &cIf_Kf0nzgJ7_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_h0uznoma_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UgR7IaJY, 0, m, &cSlice_UgR7IaJY_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UhU3P1Xu, 0, m, &cSlice_UhU3P1Xu_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TYaivwTL, 0, m, &cSlice_TYaivwTL_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_K2ZUL236, 0, m, &cSlice_K2ZUL236_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_UgR7IaJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_6GOdge2Y, 0, m, &cSlice_6GOdge2Y_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2lqEEzGp, 0, m, &cSlice_2lqEEzGp_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_6GOdge2Y, 0, m, &cSlice_6GOdge2Y_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2lqEEzGp, 0, m, &cSlice_2lqEEzGp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_UhU3P1Xu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jrRvuiG1, 0, m, &cSlice_jrRvuiG1_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ycmGfEiE, 0, m, &cSlice_ycmGfEiE_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jrRvuiG1, 0, m, &cSlice_jrRvuiG1_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ycmGfEiE, 0, m, &cSlice_ycmGfEiE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_TYaivwTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qF8NwXkf, 0, m, &cSlice_qF8NwXkf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Yux3D6Rp, 0, m, &cSlice_Yux3D6Rp_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qF8NwXkf, 0, m, &cSlice_qF8NwXkf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Yux3D6Rp, 0, m, &cSlice_Yux3D6Rp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_K2ZUL236_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ulfDVX9H, 0, m, &cSlice_ulfDVX9H_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_OQFhrboO, 0, m, &cSlice_OQFhrboO_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ulfDVX9H, 0, m, &cSlice_ulfDVX9H_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_OQFhrboO, 0, m, &cSlice_OQFhrboO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_R22Nd31B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wa4Q8QMd_sendMessage);
      break;
    }
    default: {
      cMsg_ZV8yxKjn_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_Wa4Q8QMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_atFL740Q_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_gbhQn5d6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_11knuROK, 0, m, &cSlice_11knuROK_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_iOVw4Kwd, 0, m, &cSlice_iOVw4Kwd_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_e4IK4MES, 0, m, &cIf_e4IK4MES_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_7GT4fARz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_6OYJ8EhE_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_gbhQn5d6, 1, m, &cIf_gbhQn5d6_sendMessage);
}

void Heavy_PhaseRing::cBinop_6OYJ8EhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7GT4fARz, 1, m, &cVar_7GT4fARz_sendMessage);
}

void Heavy_PhaseRing::cMsg_atFL740Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_7GT4fARz, 0, m, &cVar_7GT4fARz_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZV8yxKjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_7GT4fARz, 0, m, &cVar_7GT4fARz_sendMessage);
}

void Heavy_PhaseRing::cPack_K8jbMucM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_h0uznoma_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_90bllaDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_K8jbMucM, 0, m, &cPack_K8jbMucM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_sTY0UeVU_sendMessage);
}

void Heavy_PhaseRing::cBinop_sTY0UeVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_KmAoCbsi_sendMessage);
}

void Heavy_PhaseRing::cBinop_KmAoCbsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_90bllaDa, 1, m, &cVar_90bllaDa_sendMessage);
}

void Heavy_PhaseRing::cMsg_hHShGQd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_R22Nd31B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_3YKp6x8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_90bllaDa, 0, m, &cVar_90bllaDa_sendMessage);
}

void Heavy_PhaseRing::cCast_dAswxLGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_K8jbMucM, 1, m, &cPack_K8jbMucM_sendMessage);
}

void Heavy_PhaseRing::cSend_8eceagcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_V8dBMxMs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_eFQAQBx3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8rAR96T3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_eLdaU0ik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_MTzaFFN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ycchKSnU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_TQKPT6Sx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VGehhxzn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ycchKSnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UdySrlo1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_VGehhxzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_frcTHsEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vzqZzDVi_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_b6ADm5cJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cReceive_tyFrrbKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v7LF9BG4_sendMessage(_c, 0, m);
  cMsg_BvaxlHgD_sendMessage(_c, 0, m);
  cMsg_1vuTp3PH_sendMessage(_c, 0, m);
  cMsg_d4LsMhDV_sendMessage(_c, 0, m);
  cMsg_S5EKogOO_sendMessage(_c, 0, m);
  cMsg_pOcmV89g_sendMessage(_c, 0, m);
  cMsg_RxbMLTkW_sendMessage(_c, 0, m);
  cMsg_saYiPYBT_sendMessage(_c, 0, m);
  cMsg_rGptPvZ7_sendMessage(_c, 0, m);
  cMsg_DupI7FGd_sendMessage(_c, 0, m);
  cMsg_7gcAApb6_sendMessage(_c, 0, m);
  cMsg_7tqygLuQ_sendMessage(_c, 0, m);
  cMsg_WsC8d8go_sendMessage(_c, 0, m);
  cMsg_RaUK4heB_sendMessage(_c, 0, m);
  cMsg_TfSThw4l_sendMessage(_c, 0, m);
  cMsg_kj6sstMu_sendMessage(_c, 0, m);
  cMsg_uqwfD6KP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wDbWzIo5, 0, m, &cVar_wDbWzIo5_sendMessage);
  cMsg_xT5hHzma_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YLkeXdUk, 0, m, &cVar_YLkeXdUk_sendMessage);
  cMsg_9XWgtcBu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_T04K6Uie, 0, m, &cVar_T04K6Uie_sendMessage);
  cMsg_hOqUMfDO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_feJloJKb, 0, m, &cVar_feJloJKb_sendMessage);
  cMsg_GSxcX1gN_sendMessage(_c, 0, m);
  cMsg_VuDrGmhP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tBrgNhqW, 0, m, &cVar_tBrgNhqW_sendMessage);
  cMsg_nupV6PUr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_a8cm4Ru2, 0, m, &cVar_a8cm4Ru2_sendMessage);
  cMsg_2OEH06Hi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XtibPGgI, 0, m, &cVar_XtibPGgI_sendMessage);
  cMsg_a2nEiEng_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ths80PqV, 0, m, &cVar_ths80PqV_sendMessage);
  cMsg_FnIHVT05_sendMessage(_c, 0, m);
  cMsg_MfLohqMV_sendMessage(_c, 0, m);
  cMsg_YwiXiYwv_sendMessage(_c, 0, m);
  cMsg_bJTclTLc_sendMessage(_c, 0, m);
  cMsg_4i28eUCZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5LMTsEU1, 0, m, &cVar_5LMTsEU1_sendMessage);
  cMsg_ta0kD9KA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CDX6aypC, 0, m, &cVar_CDX6aypC_sendMessage);
  cMsg_Mx6fpj0p_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VrH9KxJW, 0, m, &cVar_VrH9KxJW_sendMessage);
  cMsg_6JRUMWYX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_v4TOZ2fz, 0, m, &cVar_v4TOZ2fz_sendMessage);
  cMsg_BL2cskMh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KVzdF0qM, 0, m, &cVar_KVzdF0qM_sendMessage);
  cMsg_JrYo1XlM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lUgV589c, 0, m, &cVar_lUgV589c_sendMessage);
  cMsg_R57l1Dgi_sendMessage(_c, 0, m);
  cMsg_zGvPydnK_sendMessage(_c, 0, m);
  cMsg_O1KLuuSA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_s3SXLxzX, 0, m, &cVar_s3SXLxzX_sendMessage);
  cMsg_CX2R373U_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5fyFYwxj, 0, m, &cVar_5fyFYwxj_sendMessage);
  cMsg_ZQRPlwDl_sendMessage(_c, 0, m);
  cMsg_QNWCVE54_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8CRKRHuo, 0, m, &cVar_8CRKRHuo_sendMessage);
  cMsg_wzQ06Fwl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_M969CT5o, 0, m, &cVar_M969CT5o_sendMessage);
  cMsg_b59zLMmU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fZPigCv4, 0, m, &cVar_fZPigCv4_sendMessage);
  cMsg_PdZJu99C_sendMessage(_c, 0, m);
  cMsg_uL788rlD_sendMessage(_c, 0, m);
  cMsg_ZWmAFsh1_sendMessage(_c, 0, m);
  cMsg_EEeLBo8u_sendMessage(_c, 0, m);
  cMsg_zH3jWOwA_sendMessage(_c, 0, m);
  cMsg_6aSK7kdQ_sendMessage(_c, 0, m);
  cMsg_jOB3LK9v_sendMessage(_c, 0, m);
  cMsg_TdUqRVWH_sendMessage(_c, 0, m);
  cMsg_VOAb2p02_sendMessage(_c, 0, m);
  cMsg_6Ejro9g7_sendMessage(_c, 0, m);
  cMsg_vOESJ1a0_sendMessage(_c, 0, m);
  cMsg_MEzWCmhw_sendMessage(_c, 0, m);
  cMsg_mI4zrgCY_sendMessage(_c, 0, m);
  cMsg_oWJVO1HZ_sendMessage(_c, 0, m);
  cMsg_lCtLUceO_sendMessage(_c, 0, m);
  cMsg_HHzFZ4kp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iptQFL2n, 0, m, &cVar_iptQFL2n_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_b1EcaFfL, 0, m, &cVar_b1EcaFfL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_i23Hm69o, 0, m, &cVar_i23Hm69o_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qDBY6K7j, 0, m, &cVar_qDBY6K7j_sendMessage);
  cMsg_4YTkzy6j_sendMessage(_c, 0, m);
  cMsg_C4us6iyo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rANLmejJ, 0, m, &cVar_rANLmejJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ywmnnyys, 0, m, &cVar_Ywmnnyys_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jR1PMCeb, 0, m, &cVar_jR1PMCeb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_N5qZjaMz, 0, m, &cVar_N5qZjaMz_sendMessage);
  cMsg_fIKVeVPp_sendMessage(_c, 0, m);
  cMsg_hZ3EUkFC_sendMessage(_c, 0, m);
  cMsg_sBVwloCU_sendMessage(_c, 0, m);
  cMsg_vbdiQfBm_sendMessage(_c, 0, m);
  cMsg_xTcuGaSc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3s9WM3nx, 0, m, &cVar_3s9WM3nx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kqxlJ3sZ, 0, m, &cVar_kqxlJ3sZ_sendMessage);
  cMsg_d4wbZFDL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_k0UU3g9m, 0, m, &cVar_k0UU3g9m_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cXidXB74, 0, m, &cVar_cXidXB74_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tfkrxusq, 0, m, &cVar_tfkrxusq_sendMessage);
  cMsg_jSSLgpGp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9KbWwkEh, 0, m, &cVar_9KbWwkEh_sendMessage);
  cMsg_K3fVInJ6_sendMessage(_c, 0, m);
  cMsg_BZYUK2dX_sendMessage(_c, 0, m);
  cMsg_loDSXbmF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5FMJR5Jq, 0, m, &cVar_5FMJR5Jq_sendMessage);
  cMsg_bn1cS26N_sendMessage(_c, 0, m);
  cMsg_k2e80oMh_sendMessage(_c, 0, m);
  cMsg_0Ts8SxMO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yy7u2DPM, 0, m, &cVar_yy7u2DPM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wm0wVmwR, 0, m, &cVar_wm0wVmwR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vgNw3AV9, 0, m, &cVar_vgNw3AV9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CoQ2QmcJ, 0, m, &cVar_CoQ2QmcJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XYNJNEsX, 0, m, &cVar_XYNJNEsX_sendMessage);
  cMsg_hHShGQd1_sendMessage(_c, 0, m);
  cSwitchcase_vzqZzDVi_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_b6ADm5cJ_onMessage(_c, NULL, 0, m, NULL);
  cMsg_o5cDOztD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GEdf6bpL, 0, m, &cVar_GEdf6bpL_sendMessage);
  cMsg_U34ef6fm_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BYgux5Oq, 0, m, &cTabhead_BYgux5Oq_sendMessage);
  cMsg_A4RHAf2T_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kVzlv21K, 0, m, &cVar_kVzlv21K_sendMessage);
  cMsg_gEEbTRSc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6K2XfYQA, 0, m, &cTabhead_6K2XfYQA_sendMessage);
  cMsg_KsjTkoMn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2wGQoAAH, 0, m, &cVar_2wGQoAAH_sendMessage);
  cMsg_cArm9AuE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WySMg7df, 0, m, &cTabhead_WySMg7df_sendMessage);
  cMsg_PLRwd1jq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TtrsrRUz, 0, m, &cVar_TtrsrRUz_sendMessage);
  cMsg_XRycfCFQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_FgFI6c4S, 0, m, &cTabhead_FgFI6c4S_sendMessage);
  cMsg_6r5d4yRf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cEXPc9kM, 0, m, &cVar_cEXPc9kM_sendMessage);
  cMsg_11VL7I23_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LXChfygy, 0, m, &cTabhead_LXChfygy_sendMessage);
  cMsg_0IzHPtqD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mJ0OorsZ, 0, m, &cVar_mJ0OorsZ_sendMessage);
  cMsg_oKsoNFDw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ggO7hi4g, 0, m, &cTabhead_ggO7hi4g_sendMessage);
  cMsg_ap2bwsNw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Gwt1SnHS, 0, m, &cVar_Gwt1SnHS_sendMessage);
  cMsg_4xUyKQ9r_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_udg83ApF, 0, m, &cTabhead_udg83ApF_sendMessage);
  cMsg_cdZQbr5d_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RBftZ2Bb, 0, m, &cVar_RBftZ2Bb_sendMessage);
  cMsg_XjDxWQFv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YKHEZJwr, 0, m, &cTabhead_YKHEZJwr_sendMessage);
  cMsg_FGlhPJJS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KNKreDi4, 0, m, &cVar_KNKreDi4_sendMessage);
  cMsg_ECkTKNzS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TOKDBC1h, 0, m, &cTabhead_TOKDBC1h_sendMessage);
  cMsg_JiThA3VA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JjLZDyxy, 0, m, &cVar_JjLZDyxy_sendMessage);
  cMsg_mRap76vv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_gfjZHwzk, 0, m, &cTabhead_gfjZHwzk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jgKpSud8, 0, m, &cVar_jgKpSud8_sendMessage);
  cMsg_SOMEtJHN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CH6ToqHl, 0, m, &cVar_CH6ToqHl_sendMessage);
  cMsg_V86Js269_sendMessage(_c, 0, m);
  cMsg_AjSAEACa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lEjLV3Ym, 0, m, &cVar_lEjLV3Ym_sendMessage);
  cMsg_AOO0bccQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EHXlnLo5, 0, m, &cTabhead_EHXlnLo5_sendMessage);
  cMsg_E302bBT9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1t1QHggq, 0, m, &cVar_1t1QHggq_sendMessage);
  cMsg_Xf6tv8SY_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wJo875kz, 0, m, &cTabhead_wJo875kz_sendMessage);
  cMsg_OAPRoXvh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Q876LdX3, 0, m, &cVar_Q876LdX3_sendMessage);
  cMsg_kgHp9AyL_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uMseitWH, 0, m, &cTabhead_uMseitWH_sendMessage);
  cMsg_s83m1N4o_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MrcEnfDs, 0, m, &cVar_MrcEnfDs_sendMessage);
  cMsg_aDywl2EK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_G9yt3Hww, 0, m, &cTabhead_G9yt3Hww_sendMessage);
  cMsg_w162vLdY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dnqkOPaL, 0, m, &cVar_dnqkOPaL_sendMessage);
  cMsg_seA9OYuC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8l89wQDU, 0, m, &cTabhead_8l89wQDU_sendMessage);
  cMsg_Eki8TDFe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0tS7ik3A, 0, m, &cVar_0tS7ik3A_sendMessage);
  cMsg_t29pJhUf_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1WKT09kq, 0, m, &cTabhead_1WKT09kq_sendMessage);
  cMsg_OwXSGqRD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2zIVBgYl, 0, m, &cVar_2zIVBgYl_sendMessage);
  cMsg_k96fpRp5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_f5cUl7Xf, 0, m, &cTabhead_f5cUl7Xf_sendMessage);
  cMsg_UUDj2liq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hHWxpwwe, 0, m, &cVar_hHWxpwwe_sendMessage);
  cMsg_Bx5MMFoi_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mzetk4Vv, 0, m, &cTabhead_mzetk4Vv_sendMessage);
  cMsg_amk55EPV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dYNNhLpj, 0, m, &cVar_dYNNhLpj_sendMessage);
  cMsg_bDVehLYh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_rERg4Liv, 0, m, &cTabhead_rERg4Liv_sendMessage);
  cMsg_YLN0xubX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TQxYDTLG, 0, m, &cVar_TQxYDTLG_sendMessage);
  cMsg_DTE2NcGM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lyMX9Vqq, 0, m, &cTabhead_lyMX9Vqq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_B6eyIehi, 0, m, &cVar_B6eyIehi_sendMessage);
  cMsg_6GsPBCgr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_m4vdGBeV, 0, m, &cVar_m4vdGBeV_sendMessage);
  cMsg_c2DuGGDZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3gJgXJtB, 0, m, &cVar_3gJgXJtB_sendMessage);
  cMsg_cMMpwVHl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7MjhLhbF, 0, m, &cVar_7MjhLhbF_sendMessage);
  cMsg_cS1RU6Da_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_O2r0FHQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_2oyQdFcN, 0, m, &cSlice_2oyQdFcN_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_tX1hGAss, 0, m, &cSlice_tX1hGAss_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_xuJ9oz5l, 0, m, &cSlice_xuJ9oz5l_sendMessage);
}

void Heavy_PhaseRing::cReceive_V8dBMxMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TOzuRusS, 0, m, &cPack_TOzuRusS_sendMessage);
}

void Heavy_PhaseRing::cReceive_8rAR96T3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TOzuRusS, 1, m, &cPack_TOzuRusS_sendMessage);
}

void Heavy_PhaseRing::cReceive_6CjJwVWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_fA0ISshA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CNr6rz7z, 0, m, &cIf_CNr6rz7z_sendMessage);
}

void Heavy_PhaseRing::cReceive_bbvv3O2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_TI0lVUsY_sendMessage);
}

void Heavy_PhaseRing::cReceive_DQRtVvLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_l0NchqdR, 0, m, &cPack_l0NchqdR_sendMessage);
}

void Heavy_PhaseRing::cReceive_qjnKTty8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_qOAE8hKp_sendMessage);
}

void Heavy_PhaseRing::cReceive_xfuITMBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cReceive_0NjDKsU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0QFNIltJ_sendMessage);
}

void Heavy_PhaseRing::cReceive_ZPghyLhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pTr4KZKU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r0zHblPi_sendMessage);
}

void Heavy_PhaseRing::cReceive_0FPsuEQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_frcTHsEK_sendMessage);
}

void Heavy_PhaseRing::cReceive_UdySrlo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HJ3kqbgo, 0, m, &cVar_HJ3kqbgo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FumicZVE, 0, m, &cVar_FumicZVE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4nuv8CIp, 0, m, &cVar_4nuv8CIp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ihIMxsS6, 0, m, &cVar_ihIMxsS6_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_3W1w5ygR, 0, m, &cPack_3W1w5ygR_sendMessage);
}

void Heavy_PhaseRing::cReceive_coSdfKdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IwdA02XF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XXHVOvgh, 0, m, &cVar_XXHVOvgh_sendMessage);
}

void Heavy_PhaseRing::cReceive_JDAibMQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lhMufdE7, 0, m, &cPack_lhMufdE7_sendMessage);
}

void Heavy_PhaseRing::cReceive_1HJaDRvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WUAMruOx, 1, m, &cVar_WUAMruOx_sendMessage);
}

void Heavy_PhaseRing::cReceive_kDFF6b8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mjhR6lcz, m);
}

void Heavy_PhaseRing::cReceive_cOSoz3ld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_h0FF6Fla_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Qs1lsJhA, 0, m, &cVar_Qs1lsJhA_sendMessage);
}

void Heavy_PhaseRing::cReceive_n7PYZmlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PPKeOuB9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oZtNQz54, 0, m, &cVar_oZtNQz54_sendMessage);
}

void Heavy_PhaseRing::cReceive_6GJtIX7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DGYNmb7R, 0, m, &cVar_DGYNmb7R_sendMessage);
}

void Heavy_PhaseRing::cReceive_U9KYS8R0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j9dgVNKI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bCp8yyCn_sendMessage);
}

void Heavy_PhaseRing::cReceive_Bhcwg8cr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_U5WrymWv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BUICChbe, 0, m, &cVar_BUICChbe_sendMessage);
}

void Heavy_PhaseRing::cReceive_4YrMBk81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_urDhOzsa, 0, m, &cPack_urDhOzsa_sendMessage);
}

void Heavy_PhaseRing::cReceive_oBan5v2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kX3NH6kf, 1, m, &cVar_kX3NH6kf_sendMessage);
}

void Heavy_PhaseRing::cReceive_NG604mFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zNXHzklq, m);
}

void Heavy_PhaseRing::cReceive_ovloK2rB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NX1t7Tfx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AmIqoQeM, 0, m, &cVar_AmIqoQeM_sendMessage);
}

void Heavy_PhaseRing::cReceive_qDQNTXVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_eKOqDSW2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZI1KbELp, 0, m, &cVar_ZI1KbELp_sendMessage);
}

void Heavy_PhaseRing::cReceive_OulqKMcS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_hCt8bheW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7TesBYpa, 0, m, &cVar_7TesBYpa_sendMessage);
}

void Heavy_PhaseRing::cReceive_FW6QmXIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9YGrzVqQ, 0, m, &cPack_9YGrzVqQ_sendMessage);
}

void Heavy_PhaseRing::cReceive_Iz7o3IDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hshT62i2, 1, m, &cVar_hshT62i2_sendMessage);
}

void Heavy_PhaseRing::cReceive_LFG0ETsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rtoHHS8W, m);
}

void Heavy_PhaseRing::cReceive_RBP0MJ3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wqz77hgd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7FDqAdTM, 0, m, &cVar_7FDqAdTM_sendMessage);
}

void Heavy_PhaseRing::cReceive_t2ZV0rAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FLAgCuZ5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_n4r7QlB4, 0, m, &cVar_n4r7QlB4_sendMessage);
}

void Heavy_PhaseRing::cReceive_zWSW9c6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_CYyxj55q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1Kf2iKJO, 0, m, &cVar_1Kf2iKJO_sendMessage);
}

void Heavy_PhaseRing::cReceive_9C9lwhQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LuSlkY39, 0, m, &cPack_LuSlkY39_sendMessage);
}

void Heavy_PhaseRing::cReceive_mmeYbl8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8LikXWEL, 1, m, &cVar_8LikXWEL_sendMessage);
}

void Heavy_PhaseRing::cReceive_Cwgdtnjr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4IEbLrSU, m);
}

void Heavy_PhaseRing::cReceive_BCpPJ7NN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kh31rGrG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bws95Xck, 0, m, &cVar_bws95Xck_sendMessage);
}

void Heavy_PhaseRing::cReceive_jQ4SCrIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4Z1bLRNw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4HXd6OpD, 0, m, &cVar_4HXd6OpD_sendMessage);
}

void Heavy_PhaseRing::cReceive_UMGUVQmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_d7fuRhuR_sendMessage);
}

void Heavy_PhaseRing::cReceive_0izWBkMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BmO3zgC4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RaKqBflO_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_lj3CVp5m, 0, m, &cPack_lj3CVp5m_sendMessage);
}

void Heavy_PhaseRing::cReceive_F5dEd7ti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kGp7c0Ky, 0, m, &cVar_kGp7c0Ky_sendMessage);
}

void Heavy_PhaseRing::cReceive_i9hE7C9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_obhAC7yJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SgFtEin2_sendMessage);
}

void Heavy_PhaseRing::cReceive_O3UozzMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_320ZTwnp_sendMessage);
}

void Heavy_PhaseRing::cReceive_UgACIFTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_836UydQs, 0, m, &cVar_836UydQs_sendMessage);
}

void Heavy_PhaseRing::cReceive_EHYKwga2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zSmuOUl9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xZUlIDsg_sendMessage);
}

void Heavy_PhaseRing::cReceive_PvIc2szs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_cWtHhJeP_sendMessage);
}

void Heavy_PhaseRing::cReceive_1yQIaM5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zmUQx012, 0, m, &cVar_zmUQx012_sendMessage);
}

void Heavy_PhaseRing::cReceive_sz1syj4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KaNqAECU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BZB3wO00_sendMessage);
}

void Heavy_PhaseRing::cReceive_I0Gfc08Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_26iW6huZ, 0, m, &cVar_26iW6huZ_sendMessage);
}

void Heavy_PhaseRing::cReceive_4UjoCW5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H4qEuC5q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_T86H1T8Q_sendMessage);
}

void Heavy_PhaseRing::cReceive_YT4AJVHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mL16X60G, 0, m, &cVar_mL16X60G_sendMessage);
}

void Heavy_PhaseRing::cReceive_BR1JSnsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4nimggjv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HTjKXPqW_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_OHvna8xd, VOf(Bf0));
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
    __hv_line_f(&sLine_ANAXPbTF, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_sOanNndz, VOf(Bf0));
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
    __hv_line_f(&sLine_CQ6KitrP, VOf(Bf5));
    __hv_varread_f(&sVarf_mjhR6lcz, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_joylSmui, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_8G7YlD6E, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_4XdVwZGx, VOf(Bf3));
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
    __hv_line_f(&sLine_2lHNZe7S, VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_ZolYEEGx, VOf(Bf3));
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
    __hv_line_f(&sLine_atdJS5Fg, VOf(Bf1));
    __hv_varread_f(&sVarf_zNXHzklq, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_6m8TWZV9, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_XH4gVXQ1, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_QE5CoEJC, VOf(Bf6));
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
    __hv_line_f(&sLine_PZxgQ4vv, VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_Ws99x1Vb, VOf(Bf6));
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
    __hv_line_f(&sLine_3JzKuFzn, VOf(Bf3));
    __hv_varread_f(&sVarf_rtoHHS8W, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_W9zwNLeY, VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_iDc9BMa0, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_kAUPrDFI, VOf(Bf8));
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
    __hv_line_f(&sLine_AAlfaxyd, VOf(Bf9));
    __hv_phasor_k_f(&sPhasor_92im5H1J, VOf(Bf8));
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
    __hv_line_f(&sLine_jiu98xgY, VOf(Bf6));
    __hv_varread_f(&sVarf_4IEbLrSU, VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_tFaKUTQ1, VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_jdBRTLys, VOf(Bf6));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_0i6WrGJS, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_9EgVUUQA, VOf(Bf6));
    __hv_phasor_f(&sPhasor_kOSMOFiw, VIf(Bf6), VOf(Bf6));
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
    __hv_line_f(&sLine_AdIVMSVN, VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_QiBGcMM7, VOf(Bf6));
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
    __hv_line_f(&sLine_CkCYmdco, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_X2lphywz, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_mCTN3Dzg, VOf(Bf11));
    __hv_rpole_f(&sRPole_tO99yYz4, VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_AGOAwoLv, VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_aY444rQY, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_lZ7zgSzw, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf7));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_add_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_pkRaBx80, VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_a3969af3, VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_tabread_f(&sTabread_ZggRA7SG, VOf(Bf7));
    __hv_varread_f(&sVarf_O2HDUS1L, VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_Wi3Pu2Va, VOf(Bf0));
    __hv_rpole_f(&sRPole_KRYOr11w, VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf0));
    __hv_line_f(&sLine_9PeTh1xu, VOf(Bf10));
    __hv_fma_f(VIf(Bf0), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_hqq5T9bD, VOf(Bf0));
    __hv_tabread_f(&sTabread_aSfpeIZ0, VOf(Bf5));
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf9));
    __hv_tabread_f(&sTabread_vmArbZ7O, VOf(Bf6));
    __hv_add_f(VIf(Bf9), VIf(Bf6), VOf(Bf1));
    __hv_tabread_f(&sTabread_MjvOKsH4, VOf(Bf8));
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf2));
    __hv_tabread_f(&sTabread_hfYqkB9J, VOf(Bf12));
    __hv_add_f(VIf(Bf2), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_Jc6umH7j, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_fAgtdIR4, VIf(Bf15));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_2XqCi3im, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_G0xOtQci, VIf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_AHXOGdjc, VIf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_N6QpS2QX, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_7m4vRAFI, VIf(Bf3));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_vcfVl5kT, VOf(Bf13));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_9OrIB1ve, VOf(Bf7));
    __hv_varread_f(&sVarf_oUVcobdg, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_FWoONJ3y, VOf(Bf6));
    __hv_rpole_f(&sRPole_th6oNTP6, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf7));
    __hv_tabread_f(&sTabread_oL3oXAzL, VOf(Bf6));
    __hv_varread_f(&sVarf_GPiYUsYW, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_qZtS7PNG, VOf(Bf9));
    __hv_rpole_f(&sRPole_5pvLm6CJ, VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_tabread_f(&sTabread_QkcD7kLi, VOf(Bf9));
    __hv_varread_f(&sVarf_tRl2p4MC, VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Px7mloIV, VOf(Bf8));
    __hv_rpole_f(&sRPole_4cw6x8fy, VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf9));
    __hv_add_f(VIf(Bf7), VIf(Bf9), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_2LT0CmVD, VIf(Bf10));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf10));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf8));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_oOFBrGBM, VIf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_UHLTxjB1, VIf(Bf9));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_rDLu65vc, VIf(Bf8));
    __hv_line_f(&sLine_uczCl8Bb, VOf(Bf8));
    __hv_mul_f(VIf(Bf14), VIf(Bf8), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf13));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_11F9nC2y, VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_NNNHp52Y, VIf(Bf6));
    __hv_line_f(&sLine_ra2t3iLt, VOf(Bf8));
    __hv_phasor_f(&sPhasor_VjQFrNUs, VIf(Bf8), VOf(Bf8));
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
    __hv_line_f(&sLine_znxv5TKK, VOf(Bf1));
    __hv_line_f(&sLine_m7UoZwKy, VOf(Bf0));
    __hv_fma_f(VIf(Bf8), VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabhead_f(&sTabhead_Ir3fgzsS, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_ZB32bdQj, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_cYA0F3X4, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf7));
    __hv_varread_f(&sVarf_l4sLowaT, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_qo88IZXw, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_sbTiUdTK, VIi(Bi0), VOf(Bf2));
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
    __hv_tabhead_f(&sTabhead_rZ9FNpNx, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_fP53xb6r, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_M4ZiY05L, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf8));
    __hv_varread_f(&sVarf_X2sBVcX1, VOf(Bf0));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_MIydgMei, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_7lCwCbsB, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf16), VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_Rq44zWcE, VOf(Bf2));
    __hv_tabhead_f(&sTabhead_GPC5HALu, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_NxdC7Wh7, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_yCVKRnXZ, VOf(Bf2));
    __hv_min_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_FAim4t1n, VOf(Bf2));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_jlLWdWEq, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_mFehtGPf, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf8), VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_bItwYSzW, VOf(Bf17));
    __hv_rpole_f(&sRPole_ZbaGCCYH, VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_uFpPVIsl, VIf(Bf17), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_kcnAdkui, VOf(Bf17));
    __hv_mul_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_ZANEuPlt, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf17));
    __hv_line_f(&sLine_DinFcQxm, VOf(Bf8));
    __hv_varread_f(&sVarf_Bzq9t0uV, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_PwVR65dU, VOf(Bf2));
    __hv_rpole_f(&sRPole_18Kud4jJ, VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_tO3dLHQB, VIf(Bf2));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_TdL6ZguY, VOf(Bf17));
    __hv_varread_f(&sVarf_Zdg4sOPP, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_E3fPsydy, VOf(Bf2));
    __hv_min_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_ZdWfz8f6, VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_varread_f(&sVarf_FZirLyJW, VOf(Bf2));
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
    __hv_cpole_f(&sCPole_b45m8lnX, VIf(Bf2), VIf(ZERO), VIf(Bf0), VIf(Bf17), VOf(Bf17), VOf(Bf0));
    __hv_varread_f(&sVarf_vMGE5MHf, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_csx4kkkj, VOf(Bf17));
    __hv_rpole_f(&sRPole_CSJ1RoMW, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_uzb0pbpk, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_p5ETkzlj, VOf(Bf17));
    __hv_rpole_f(&sRPole_94lHuSv4, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_nnyHuAJH, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_GZr2zu12, VOf(Bf17));
    __hv_rpole_f(&sRPole_tO5wkHAm, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_PXyDu9RO, VOf(Bf0));
    __hv_varread_f(&sVarf_mM61I41T, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_ANKhHPoX, VOf(Bf8));
    __hv_rpole_f(&sRPole_XOU7T7r0, VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf8));
    __hv_line_f(&sLine_zo3ZvJuV, VOf(Bf2));
    __hv_fma_f(VIf(Bf8), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_gsHEdUib, VOf(Bf8));
    __hv_tabread_f(&sTabread_JO88ZHSN, VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf12));
    __hv_tabread_f(&sTabread_1BtsQpNq, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_XHsUMFug, VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf18));
    __hv_tabread_f(&sTabread_f4mOLfF2, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf9));
    __hv_tabread_f(&sTabread_DaGuuQMZ, VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_GCCTafgW, VIf(Bf5));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_sMxLbsQB, VIf(Bf15));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_RR0X2HCm, VIf(Bf7));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_t0iQBUbP, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_tfNspXeb, VIf(Bf6));
    __hv_tabwrite_f(&sTabwrite_TNUGkcbb, VIf(Bf17));
    __hv_add_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_JmFOVfVI, VOf(Bf9));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_flr2zEpX, VOf(Bf0));
    __hv_varread_f(&sVarf_fwaft1NL, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_xcWUBgW7, VOf(Bf16));
    __hv_rpole_f(&sRPole_LZPkfJj5, VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf0));
    __hv_tabread_f(&sTabread_XWgTHeQf, VOf(Bf16));
    __hv_varread_f(&sVarf_WRIyWlnY, VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_tntaR9Sq, VOf(Bf12));
    __hv_rpole_f(&sRPole_RzfG4IYL, VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf16));
    __hv_tabread_f(&sTabread_tkvhO79D, VOf(Bf12));
    __hv_varread_f(&sVarf_GKaTfz83, VOf(Bf6));
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_fxzFrkbz, VOf(Bf7));
    __hv_rpole_f(&sRPole_xSpAzXc7, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf12), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf16), VIf(Bf8), VOf(Bf12));
    __hv_add_f(VIf(Bf0), VIf(Bf12), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_0DYm3TJV, VIf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf2));
    __hv_sub_f(VIf(Bf16), VIf(Bf8), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf7), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_hNA8U5MH, VIf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_CL1NrIq1, VIf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_nwjshKbH, VIf(Bf7));
    __hv_line_f(&sLine_BWCIt3KP, VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf16), VIf(Bf7), VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_t3Uzaxmb, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_tnd0hLZl, VIf(Bf10));
    __hv_line_f(&sLine_LOsz3tmd, VOf(Bf10));
    __hv_phasor_f(&sPhasor_K4gw19Pv, VIf(Bf10), VOf(Bf10));
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
    __hv_line_f(&sLine_RxSDlkHs, VOf(Bf2));
    __hv_line_f(&sLine_dgmmG0t8, VOf(Bf3));
    __hv_fma_f(VIf(Bf10), VIf(Bf2), VIf(Bf3), VOf(Bf0));
    __hv_tabhead_f(&sTabhead_SmYrbpBM, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_wxsmK5Ta, VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_RqhgoR3A, VOf(Bf0));
    __hv_min_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf9));
    __hv_varread_f(&sVarf_JA0AGxfo, VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_0K71SMO4, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_EbVmp8J3, VIi(Bi0), VOf(Bf0));
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
    __hv_tabhead_f(&sTabhead_yG1WKB2f, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf10), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_9NODZsot, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_JFW85uH9, VOf(Bf3));
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf10));
    __hv_varread_f(&sVarf_dkOteZzn, VOf(Bf3));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_xYP1PdmQ, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_eK4hUs6O, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf1), VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_fng3KQbh, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_ZkYou3SO, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_jSJqeU5r, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_IaLQBw4s, VOf(Bf0));
    __hv_min_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_Vnlz4DVC, VOf(Bf0));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_5Qza54DK, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_ov3xDB6f, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf10));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf10), VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_XKpgWGaM, VOf(Bf15));
    __hv_rpole_f(&sRPole_dFKIJdij, VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_lELfXtI3, VIf(Bf15), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_rRPfTKuk, VOf(Bf15));
    __hv_mul_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_xcxvsYac, VOf(Bf0));
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf15));
    __hv_line_f(&sLine_dvxg473t, VOf(Bf10));
    __hv_varread_f(&sVarf_RQtlcfhh, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_8sIvH1e6, VOf(Bf0));
    __hv_rpole_f(&sRPole_F7mx2iYS, VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_dNzPEqGw, VIf(Bf0));
    __hv_var_k_f(VOf(Bf0), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf14), VIf(Bf0), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_rMs0vHVo, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_Y7iZe6LJ, VOf(Bf11));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf14));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf14), VIf(O0), VOf(O0));

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

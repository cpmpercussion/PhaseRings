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
  numBytes += sPhasor_k_init(&sPhasor_k73cXnPz, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_PKTYloo8);
  numBytes += sPhasor_k_init(&sPhasor_AUHfrJ6v, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_vkU8qyFt);
  numBytes += sLine_init(&sLine_XSHc0Ia9);
  numBytes += sLine_init(&sLine_QvZeBKlp);
  numBytes += sPhasor_k_init(&sPhasor_gPUxC6HI, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_2wGmCP6f);
  numBytes += sPhasor_k_init(&sPhasor_b77Uip5l, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_fkpNNbeY);
  numBytes += sLine_init(&sLine_uZlc43yW);
  numBytes += sLine_init(&sLine_VM7U9S3k);
  numBytes += sPhasor_k_init(&sPhasor_TwPMNSqD, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_lfjulrbb);
  numBytes += sPhasor_k_init(&sPhasor_UQlC35Bg, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_UJQ3qvrt);
  numBytes += sLine_init(&sLine_y0iwHJXT);
  numBytes += sLine_init(&sLine_qcs4NT4o);
  numBytes += sPhasor_k_init(&sPhasor_Enk7pASw, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_ofjH5gHt);
  numBytes += sPhasor_k_init(&sPhasor_klqndxqF, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_3Q9siue6);
  numBytes += sLine_init(&sLine_AjhEoLRe);
  numBytes += sLine_init(&sLine_SUo3sPnP);
  numBytes += sLine_init(&sLine_8qxqPQ0y);
  numBytes += sLine_init(&sLine_iwX6FNnm);
  numBytes += sPhasor_init(&sPhasor_1YWSwqqQ, sampleRate);
  numBytes += sLine_init(&sLine_b7aAIByH);
  numBytes += sPhasor_k_init(&sPhasor_eX1XmOPT, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_67FSWtId);
  numBytes += sLine_init(&sLine_glIoRjzW);
  numBytes += sRPole_init(&sRPole_40SLN4AE);
  numBytes += sDel1_init(&sDel1_Aqr3M9Zy);
  numBytes += sLine_init(&sLine_MUsAcsjq);
  numBytes += sLine_init(&sLine_cEfkkKfs);
  numBytes += sLine_init(&sLine_neCt0u0x);
  numBytes += sTabread_init(&sTabread_Ys5s11Pg, &hTable_zghthmB7, true);
  numBytes += sRPole_init(&sRPole_F9p1qg0O);
  numBytes += sLine_init(&sLine_PLHq1d1h);
  numBytes += sLine_init(&sLine_5hAnulJB);
  numBytes += sTabread_init(&sTabread_67EzIRIe, &hTable_bqM7kUv1, true);
  numBytes += sTabread_init(&sTabread_zgD4o1zF, &hTable_FY7LcnD6, true);
  numBytes += sTabread_init(&sTabread_u0oJipNF, &hTable_jzBRok7l, true);
  numBytes += sTabread_init(&sTabread_QLTQYVNM, &hTable_LbWYVZB4, true);
  numBytes += sTabread_init(&sTabread_qbwrOpHv, &hTable_IJIcP0va, true);
  numBytes += sTabwrite_init(&sTabwrite_j3FCvULD, &hTable_ua2isCjv);
  numBytes += sTabwrite_init(&sTabwrite_A06E13j1, &hTable_IJIcP0va);
  numBytes += sTabwrite_init(&sTabwrite_mfFAEgqr, &hTable_LbWYVZB4);
  numBytes += sTabwrite_init(&sTabwrite_rk0cq70c, &hTable_jzBRok7l);
  numBytes += sTabwrite_init(&sTabwrite_yLQQoOMv, &hTable_FY7LcnD6);
  numBytes += sTabwrite_init(&sTabwrite_OAIcRncr, &hTable_bqM7kUv1);
  numBytes += sTabread_init(&sTabread_qj0gKYka, &hTable_ua2isCjv, true);
  numBytes += sTabread_init(&sTabread_cUvUR4dE, &hTable_nalEOYMq, true);
  numBytes += sRPole_init(&sRPole_NtBVvwQp);
  numBytes += sTabread_init(&sTabread_RR5kdm1K, &hTable_OcmXYXCS, true);
  numBytes += sRPole_init(&sRPole_g2J69m1A);
  numBytes += sTabread_init(&sTabread_K67nHFvW, &hTable_SjPHX9Gv, true);
  numBytes += sRPole_init(&sRPole_nECRggN7);
  numBytes += sTabwrite_init(&sTabwrite_O0xU8mRH, &hTable_zghthmB7);
  numBytes += sTabwrite_init(&sTabwrite_mJYYDbnn, &hTable_nalEOYMq);
  numBytes += sTabwrite_init(&sTabwrite_dCTeVU8K, &hTable_OcmXYXCS);
  numBytes += sTabwrite_init(&sTabwrite_HyokTsKa, &hTable_SjPHX9Gv);
  numBytes += sLine_init(&sLine_v5yKaspP);
  numBytes += sLine_init(&sLine_dcyduFWh);
  numBytes += sTabwrite_init(&sTabwrite_bJAtj8sL, &hTable_1N2pKnrk);
  numBytes += sLine_init(&sLine_PapVVXG2);
  numBytes += sPhasor_init(&sPhasor_XiSahmyi, sampleRate);
  numBytes += sLine_init(&sLine_7dmqaXz6);
  numBytes += sLine_init(&sLine_dF5MkyD8);
  numBytes += sTabhead_init(&sTabhead_fyNHHege, &hTable_1N2pKnrk);
  numBytes += sTabread_init(&sTabread_7VeimvbA, &hTable_1N2pKnrk, false);
  numBytes += sTabread_init(&sTabread_BhpISfFr, &hTable_1N2pKnrk, false);
  numBytes += sTabhead_init(&sTabhead_Ncw6jqHQ, &hTable_1N2pKnrk);
  numBytes += sTabread_init(&sTabread_txtDhCeY, &hTable_1N2pKnrk, false);
  numBytes += sTabread_init(&sTabread_RyAS8U0e, &hTable_1N2pKnrk, false);
  numBytes += sTabhead_init(&sTabhead_xKfNJ6dI, &hTable_HKcO3eEe);
  numBytes += sTabread_init(&sTabread_EjwIG1T0, &hTable_HKcO3eEe, false);
  numBytes += sTabread_init(&sTabread_0GvHqizF, &hTable_HKcO3eEe, false);
  numBytes += sRPole_init(&sRPole_Jn4gbNsO);
  numBytes += sDel1_init(&sDel1_wP1N300m);
  numBytes += sLine_init(&sLine_uLhRvkj8);
  numBytes += sRPole_init(&sRPole_EvFl9jfu);
  numBytes += sTabwrite_init(&sTabwrite_XjpyiVUt, &hTable_HKcO3eEe);
  numBytes += sCPole_init(&sCPole_LeNGF1Lp);
  numBytes += sRPole_init(&sRPole_g2STlTqp);
  numBytes += sRPole_init(&sRPole_OpnQXJ1B);
  numBytes += sRPole_init(&sRPole_WPBrTeM0);
  numBytes += sTabread_init(&sTabread_X8n8jThG, &hTable_AA8FCmwT, true);
  numBytes += sRPole_init(&sRPole_jSZqQ0lL);
  numBytes += sLine_init(&sLine_Jg3s4D1U);
  numBytes += sLine_init(&sLine_aEsnGRZY);
  numBytes += sTabread_init(&sTabread_AwhXa1Ng, &hTable_gngThHUw, true);
  numBytes += sTabread_init(&sTabread_KSlFr7mp, &hTable_w0g3xqJH, true);
  numBytes += sTabread_init(&sTabread_qRhYlQLm, &hTable_jDvbKOz0, true);
  numBytes += sTabread_init(&sTabread_X0LsXJ8p, &hTable_p0Gq1zlL, true);
  numBytes += sTabread_init(&sTabread_fHleRiW7, &hTable_0xMUdkpu, true);
  numBytes += sTabwrite_init(&sTabwrite_pwvPJ18S, &hTable_uHbLv3ZI);
  numBytes += sTabwrite_init(&sTabwrite_vwhKMr0I, &hTable_0xMUdkpu);
  numBytes += sTabwrite_init(&sTabwrite_qtj81PRF, &hTable_p0Gq1zlL);
  numBytes += sTabwrite_init(&sTabwrite_JMfmRKr6, &hTable_jDvbKOz0);
  numBytes += sTabwrite_init(&sTabwrite_eoRIXOU8, &hTable_w0g3xqJH);
  numBytes += sTabwrite_init(&sTabwrite_9oAWvycu, &hTable_gngThHUw);
  numBytes += sTabread_init(&sTabread_i0nUPV0N, &hTable_uHbLv3ZI, true);
  numBytes += sTabread_init(&sTabread_U8yFvSeH, &hTable_Wr6uU0Bu, true);
  numBytes += sRPole_init(&sRPole_SG2qPBr0);
  numBytes += sTabread_init(&sTabread_1QZ9j9kB, &hTable_7yScw3nJ, true);
  numBytes += sRPole_init(&sRPole_gdSJK9Ls);
  numBytes += sTabread_init(&sTabread_81UfMuMh, &hTable_oyaHkUVb, true);
  numBytes += sRPole_init(&sRPole_78JjUjzn);
  numBytes += sTabwrite_init(&sTabwrite_oQkEofYY, &hTable_AA8FCmwT);
  numBytes += sTabwrite_init(&sTabwrite_abHPcO78, &hTable_Wr6uU0Bu);
  numBytes += sTabwrite_init(&sTabwrite_lVqJ67wj, &hTable_7yScw3nJ);
  numBytes += sTabwrite_init(&sTabwrite_axHp8D1Y, &hTable_oyaHkUVb);
  numBytes += sLine_init(&sLine_9JANBMrb);
  numBytes += sLine_init(&sLine_2ulNQBW7);
  numBytes += sTabwrite_init(&sTabwrite_zZeUuENe, &hTable_8vLYIp60);
  numBytes += sLine_init(&sLine_kQZ4WyTN);
  numBytes += sPhasor_init(&sPhasor_U7wgqZ4E, sampleRate);
  numBytes += sLine_init(&sLine_FWHXK7UL);
  numBytes += sLine_init(&sLine_NYkFsGOG);
  numBytes += sTabhead_init(&sTabhead_TS7P7xQr, &hTable_8vLYIp60);
  numBytes += sTabread_init(&sTabread_OgKEU2x4, &hTable_8vLYIp60, false);
  numBytes += sTabread_init(&sTabread_fllwqEiV, &hTable_8vLYIp60, false);
  numBytes += sTabhead_init(&sTabhead_lcGu26cY, &hTable_8vLYIp60);
  numBytes += sTabread_init(&sTabread_QrAwO8Fn, &hTable_8vLYIp60, false);
  numBytes += sTabread_init(&sTabread_BGbK8XdQ, &hTable_8vLYIp60, false);
  numBytes += sTabhead_init(&sTabhead_7BRePxTP, &hTable_lLISmVYz);
  numBytes += sTabread_init(&sTabread_SpBVxlSp, &hTable_lLISmVYz, false);
  numBytes += sTabread_init(&sTabread_CiU8dxtr, &hTable_lLISmVYz, false);
  numBytes += sRPole_init(&sRPole_VEnQJT2g);
  numBytes += sDel1_init(&sDel1_KHoqDlOB);
  numBytes += sLine_init(&sLine_zJD1I8kT);
  numBytes += sRPole_init(&sRPole_mLACGxL9);
  numBytes += sTabwrite_init(&sTabwrite_gLnBb38i, &hTable_lLISmVYz);
  numBytes += sLine_init(&sLine_Wz7rkSKw);
  numBytes += sLine_init(&sLine_MwVyL2cc);
  numBytes += cSlice_init(&cSlice_zO41hOit, 2, 1);
  numBytes += cSlice_init(&cSlice_MfO1apwe, 1, 1);
  numBytes += cSlice_init(&cSlice_Melq9WiR, 0, 1);
  numBytes += cVar_init_f(&cVar_J732KMWy, 0.0f);
  numBytes += cIf_init(&cIf_j2cSIZ8g, false);
  numBytes += cIf_init(&cIf_YvKDNjoL, false);
  numBytes += cIf_init(&cIf_haIq85Ct, false);
  numBytes += cIf_init(&cIf_iwh5AQfU, false);
  numBytes += cIf_init(&cIf_P020EIVz, false);
  numBytes += cBinop_init(&cBinop_Op4FiIsx, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_xJrWuDN1, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_GCUpExZI, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1Rc5fTsG, 5.0f);
  numBytes += cBinop_init(&cBinop_saxV5h1c, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_8CuO9lEx, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_PIdtxMH6, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_MetXbSLF, "floatatom");
  numBytes += cVar_init_s(&cVar_xq0RaZ6A, "floatatom");
  numBytes += cIf_init(&cIf_VNPUgcNO, false);
  numBytes += cIf_init(&cIf_qm3EhjKE, false);
  numBytes += cIf_init(&cIf_RIcgfi22, false);
  numBytes += cIf_init(&cIf_1UUaB3bG, false);
  numBytes += cPack_init(&cPack_YjP80vSV, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_LDCqQ8mk, 2, 0.0f, 80.0f);
  numBytes += cPack_init(&cPack_SH1NswbM, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_X3FIS4ue, 1147626488);
  numBytes += cSlice_init(&cSlice_ScRtj1Yh, 1, 1);
  numBytes += cVar_init_s(&cVar_dSdsjEgs, "floatatom");
  numBytes += cRandom_init(&cRandom_9dUCoAus, 881453873);
  numBytes += cSlice_init(&cSlice_meMtDNmS, 1, 1);
  numBytes += cVar_init_s(&cVar_vot9Ww7M, "floatatom");
  numBytes += cVar_init_f(&cVar_e8a1ocVD, 1.0f);
  numBytes += cVar_init_f(&cVar_3jE9LqiR, 0.0f);
  numBytes += cVar_init_f(&cVar_XYrmuz0y, 0.0f);
  numBytes += cRandom_init(&cRandom_LNdOnIeR, 2053084576);
  numBytes += cSlice_init(&cSlice_zMOKKkV7, 1, 1);
  numBytes += cRandom_init(&cRandom_ZJxuQMTx, 589615543);
  numBytes += cSlice_init(&cSlice_4XiOkRXS, 1, 1);
  numBytes += cRandom_init(&cRandom_fSSHAapF, 1588661739);
  numBytes += cSlice_init(&cSlice_xi8yIGLI, 1, 1);
  numBytes += cBinop_init(&cBinop_QdHgHCU3, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_hs6N4n4X, -1476326788);
  numBytes += cSlice_init(&cSlice_9ifCiDdA, 1, 1);
  numBytes += cPack_init(&cPack_qga02r6d, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_VkEvoHpW, "floatatom");
  numBytes += cVar_init_s(&cVar_IpN5uEAM, "floatatom");
  numBytes += cVar_init_s(&cVar_5uY5FSX6, "floatatom");
  numBytes += cVar_init_f(&cVar_mIvK51LZ, 0.0f);
  numBytes += cVar_init_s(&cVar_ucpRQZTB, "floatatom");
  numBytes += cVar_init_s(&cVar_AETZlJBZ, "floatatom");
  numBytes += cVar_init_s(&cVar_Rv02aqAA, "floatatom");
  numBytes += cDelay_init(this, &cDelay_NPDSNxZk, 25.0f);
  numBytes += cVar_init_f(&cVar_Dxq0jnWh, 0.0f);
  numBytes += sVarf_init(&sVarf_4MiWnT4r, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_ZqZ2Lw0N, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_WwOpPCE2, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_I5P8dIPt, 1, 1);
  numBytes += cSlice_init(&cSlice_ZmKwHMw4, 0, 1);
  numBytes += cBinop_init(&cBinop_1FYsqLy2, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_44gqBxJv, 98.0f);
  numBytes += cIf_init(&cIf_W9v35q3y, false);
  numBytes += cBinop_init(&cBinop_V8L0xr24, 0.0f); // __pow
  numBytes += cPack_init(&cPack_TUxtaI2o, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_tZXmWoPK, 0.0f);
  numBytes += cRandom_init(&cRandom_vdqMrm3q, 1079137484);
  numBytes += cSlice_init(&cSlice_A0FIe4Nv, 1, 1);
  numBytes += cBinop_init(&cBinop_rPqpEclf, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_VC60tZ0H, -263085838);
  numBytes += cSlice_init(&cSlice_mtQbmmIc, 1, 1);
  numBytes += cPack_init(&cPack_o64KUlOS, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_oTfLKwWG, "floatatom");
  numBytes += cVar_init_s(&cVar_ZjHRbsem, "floatatom");
  numBytes += cVar_init_s(&cVar_GhQKxHJo, "floatatom");
  numBytes += cVar_init_f(&cVar_DcFOFDEl, 0.0f);
  numBytes += cVar_init_s(&cVar_iwLT7mxs, "floatatom");
  numBytes += cVar_init_s(&cVar_ZQ6dr5Pe, "floatatom");
  numBytes += cVar_init_s(&cVar_iXAR9BNO, "floatatom");
  numBytes += cDelay_init(this, &cDelay_cMdrE4ih, 25.0f);
  numBytes += cVar_init_f(&cVar_CSNn3Xl7, 0.0f);
  numBytes += sVarf_init(&sVarf_33bOjuDc, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_yiGwZXJ5, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_y4NyJHqF, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_yKMnqAgU, 1, 1);
  numBytes += cSlice_init(&cSlice_oxGDBhLH, 0, 1);
  numBytes += cBinop_init(&cBinop_2xlbbWOj, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_9uFDVHe7, -695734068);
  numBytes += cSlice_init(&cSlice_ZVzkeZZ1, 1, 1);
  numBytes += cBinop_init(&cBinop_oxLnReda, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_yK52COJp, 982338874);
  numBytes += cSlice_init(&cSlice_7KXzri4A, 1, 1);
  numBytes += cPack_init(&cPack_YHMo2vNL, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_J24FyqzL, "floatatom");
  numBytes += cVar_init_s(&cVar_bwhleghx, "floatatom");
  numBytes += cVar_init_s(&cVar_NRGE7V5B, "floatatom");
  numBytes += cVar_init_f(&cVar_szQbx5JT, 0.0f);
  numBytes += cVar_init_s(&cVar_BRWseyD5, "floatatom");
  numBytes += cVar_init_s(&cVar_bJ4Jtvxg, "floatatom");
  numBytes += cVar_init_s(&cVar_DaU8lEEx, "floatatom");
  numBytes += cDelay_init(this, &cDelay_s1AElv26, 25.0f);
  numBytes += cVar_init_f(&cVar_ZyQ0oJpa, 0.0f);
  numBytes += sVarf_init(&sVarf_TlFuKxJy, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_z3tNdwTJ, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_wwNwO158, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_7q6wjVzX, 1, 1);
  numBytes += cSlice_init(&cSlice_J5uIL2zn, 0, 1);
  numBytes += cBinop_init(&cBinop_fvzN3ueB, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_YHaUr0xV, 117462316);
  numBytes += cSlice_init(&cSlice_cQtVbUT4, 1, 1);
  numBytes += cBinop_init(&cBinop_6Qm2h2hS, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_8kZph7XC, 721754944);
  numBytes += cSlice_init(&cSlice_jZuuLUwE, 1, 1);
  numBytes += cPack_init(&cPack_dv0wyXYD, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_vVuNcon5, "floatatom");
  numBytes += cVar_init_s(&cVar_CAQFoj2g, "floatatom");
  numBytes += cVar_init_s(&cVar_pzyCJlEJ, "floatatom");
  numBytes += cVar_init_f(&cVar_OQTQGfX3, 0.0f);
  numBytes += cVar_init_s(&cVar_rfyPG4fb, "floatatom");
  numBytes += cVar_init_s(&cVar_vbXZkDDr, "floatatom");
  numBytes += cVar_init_s(&cVar_LaQxPMqx, "floatatom");
  numBytes += cDelay_init(this, &cDelay_JfS2bsSp, 25.0f);
  numBytes += cVar_init_f(&cVar_uYPjLKCn, 0.0f);
  numBytes += sVarf_init(&sVarf_R4HrtQFB, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_N7sEgEmo, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_MHJpUkeH, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_bhVmhJzT, 1, 1);
  numBytes += cSlice_init(&cSlice_dV5FdnHL, 0, 1);
  numBytes += cBinop_init(&cBinop_j5AAeXIe, 1.0f); // __mul
  numBytes += cTabhead_init(&cTabhead_0Fke5nX6, &hTable_zghthmB7);
  numBytes += cVar_init_s(&cVar_WvCPrYVT, "del-1210-del1");
  numBytes += cDelay_init(this, &cDelay_IgnxSrFw, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_QPiEuzTS, 0.0f);
  numBytes += cBinop_init(&cBinop_Od8Gb5uI, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_XeZ1B0j3, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cBFrpQZd, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_J1dAtqij, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_ZYDBgI6J, &hTable_nalEOYMq);
  numBytes += cVar_init_s(&cVar_dOnx3kV9, "del-1210-del2");
  numBytes += cDelay_init(this, &cDelay_geou72Zr, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_pbEXgWCS, 0.0f);
  numBytes += cBinop_init(&cBinop_G7EaGEEP, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_kdbLKXPB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_p435uMVj, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_CKjh4tHs, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_jLPJ7Rox, &hTable_OcmXYXCS);
  numBytes += cVar_init_s(&cVar_jc3BiXZR, "del-1210-del3");
  numBytes += cDelay_init(this, &cDelay_4NETi1iS, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_cnM0Het2, 0.0f);
  numBytes += cBinop_init(&cBinop_V5Ns1Rao, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_QBUhAdl0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_hleNuWc1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NJQHJi2W, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_3HAxw8TX, &hTable_SjPHX9Gv);
  numBytes += cVar_init_s(&cVar_9WpELT9g, "del-1210-del4");
  numBytes += cDelay_init(this, &cDelay_38U5jP1j, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_iADLw9Wa, 0.0f);
  numBytes += cBinop_init(&cBinop_mmU8fmuD, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_QFvEQ7uF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_TZyMXI3T, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_j5g9oZRg, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Qg28wfPc, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8ZiwyqQC, 0.0f);
  numBytes += hTable_init(&hTable_zghthmB7, 256);
  numBytes += cDelay_init(this, &cDelay_7G5xGPKl, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2sDqRWxl, 0.0f);
  numBytes += hTable_init(&hTable_nalEOYMq, 256);
  numBytes += cDelay_init(this, &cDelay_7ezXWCla, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ej3O4ieo, 0.0f);
  numBytes += hTable_init(&hTable_OcmXYXCS, 256);
  numBytes += cDelay_init(this, &cDelay_Ok992P7Z, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UGGdVog3, 0.0f);
  numBytes += hTable_init(&hTable_SjPHX9Gv, 256);
  numBytes += cIf_init(&cIf_b9uOHWLM, false);
  numBytes += cBinop_init(&cBinop_UNBjwgJA, 0.0f); // __pow
  numBytes += cPack_init(&cPack_JaZ3eDOy, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_4Jz7rgcG, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_NMEJtwwS, 22050.0f);
  numBytes += cBinop_init(&cBinop_UTAO3DIz, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_SW07rReW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_80zhOBzS, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_zIBaPinP, 95.0f);
  numBytes += cVar_init_f(&cVar_tdEnmbEy, 90.0f);
  numBytes += cVar_init_f(&cVar_vHcevg4J, 6000.0f);
  numBytes += cVar_init_f(&cVar_1E0CcgIK, 60.0f);
  numBytes += cIf_init(&cIf_PcBwtAKv, false);
  numBytes += cTabhead_init(&cTabhead_FHyNMIDU, &hTable_ua2isCjv);
  numBytes += cVar_init_s(&cVar_YrZxt1rh, "del-1210-ref6");
  numBytes += cDelay_init(this, &cDelay_rs0ZI53N, 13.645f);
  numBytes += cDelay_init(this, &cDelay_sg0nENxn, 0.0f);
  numBytes += cBinop_init(&cBinop_fojkmdtD, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_YI7jofVs, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_DpzjsUUJ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_gwfFXcxv, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_WED2CAam, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2LsYZIZ1, 0.0f);
  numBytes += hTable_init(&hTable_ua2isCjv, 256);
  numBytes += cTabhead_init(&cTabhead_FOJj7uQb, &hTable_IJIcP0va);
  numBytes += cVar_init_s(&cVar_ha1m79M0, "del-1210-ref5");
  numBytes += cDelay_init(this, &cDelay_w7TRfqmS, 16.364f);
  numBytes += cDelay_init(this, &cDelay_k02NmOhH, 0.0f);
  numBytes += cBinop_init(&cBinop_1fYu0Cxb, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_dJY8djhW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9hxgt79H, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ocW9cRuy, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_VE8lOCJz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kTPQJB8T, 0.0f);
  numBytes += hTable_init(&hTable_IJIcP0va, 256);
  numBytes += cTabhead_init(&cTabhead_nytT6jlV, &hTable_LbWYVZB4);
  numBytes += cVar_init_s(&cVar_gRq60mBs, "del-1210-ref4");
  numBytes += cDelay_init(this, &cDelay_pqpvpTwe, 19.392f);
  numBytes += cDelay_init(this, &cDelay_7BhEE3ah, 0.0f);
  numBytes += cBinop_init(&cBinop_SXxYBNIe, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_ghNnoeZh, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3B1bZibQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_mGrvInav, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_nxc8hsgb, 0.0f);
  numBytes += cDelay_init(this, &cDelay_i7rKHIQo, 0.0f);
  numBytes += hTable_init(&hTable_LbWYVZB4, 256);
  numBytes += cTabhead_init(&cTabhead_psfVSoyH, &hTable_jzBRok7l);
  numBytes += cVar_init_s(&cVar_2xQG8E27, "del-1210-ref3");
  numBytes += cDelay_init(this, &cDelay_KR4SJEvk, 25.796f);
  numBytes += cDelay_init(this, &cDelay_9xNRa14F, 0.0f);
  numBytes += cBinop_init(&cBinop_4XhwcMR0, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_ou54OYx1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_rAd7lEnx, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_VCWpGUhD, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_8Q2h1lLF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_5p93yCNt, 0.0f);
  numBytes += hTable_init(&hTable_jzBRok7l, 256);
  numBytes += cTabhead_init(&cTabhead_RH4MTcMd, &hTable_FY7LcnD6);
  numBytes += cVar_init_s(&cVar_62yBMUkD, "del-1210-ref2");
  numBytes += cDelay_init(this, &cDelay_AyVIx8ik, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_RHKAkzNv, 0.0f);
  numBytes += cBinop_init(&cBinop_9GJp52R7, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_ecfimlrR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_PQtHySxj, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_oHvSPIZo, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_1A2OUMB6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_seEmRnEi, 0.0f);
  numBytes += hTable_init(&hTable_FY7LcnD6, 256);
  numBytes += cTabhead_init(&cTabhead_RZ7cANBB, &hTable_bqM7kUv1);
  numBytes += cVar_init_s(&cVar_4llXTxP6, "del-1210-ref1");
  numBytes += cDelay_init(this, &cDelay_4UEVqa75, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_18c0dvqT, 0.0f);
  numBytes += cBinop_init(&cBinop_eUNUDpjX, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_n7xdHyON, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_DED03ilD, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_PeOZESoo, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_MyXinqIS, 0.0f);
  numBytes += cDelay_init(this, &cDelay_owLUDsgK, 0.0f);
  numBytes += hTable_init(&hTable_bqM7kUv1, 256);
  numBytes += cVar_init_f(&cVar_Cdv4cOqi, 0.0f);
  numBytes += cVar_init_f(&cVar_bMD4OnpX, 0.0f);
  numBytes += cPack_init(&cPack_2Tht7zvb, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_aCK74uYh, 22050.0f);
  numBytes += cBinop_init(&cBinop_CL2JF3zD, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Np2LMZiG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7r1Y4ooD, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_E5bOsQS9, 22050.0f);
  numBytes += cBinop_init(&cBinop_HNTWv9WT, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_7LrvpiZq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_j47QkNgi, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xj5p7vRM, 22050.0f);
  numBytes += cBinop_init(&cBinop_jQQoksIO, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_KYRZv9FD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sdbMylJD, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_2WklvkdS, false);
  numBytes += cDelay_init(this, &cDelay_Zq3Wk8q4, 50.0f);
  numBytes += cVar_init_f(&cVar_t3mDz5EI, 0.0f);
  numBytes += cVar_init_f(&cVar_mQXfbYRn, 12.0f);
  numBytes += cVar_init_s(&cVar_4uvfQEXX, "floatatom");
  numBytes += cPack_init(&cPack_cveYnAOw, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_V2cbpbHT, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_8jYEnF13, "floatatom");
  numBytes += cDelay_init(this, &cDelay_24sW0uyh, 0.0f);
  numBytes += cDelay_init(this, &cDelay_KQbseKwF, 0.0f);
  numBytes += hTable_init(&hTable_1N2pKnrk, 256);
  numBytes += cVar_init_s(&cVar_91hhEDAv, "del-1317-del");
  numBytes += sVarf_init(&sVarf_r3SBiOvf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hYULEoNG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_B3puZuTF, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_FW92KCMh, "del-1317-del");
  numBytes += sVarf_init(&sVarf_ECOtSiwK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_AjCEyYil, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xo0PuH6q, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_k5nMeJvX, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_DbNwVwe2, 4720.0f);
  numBytes += cBinop_init(&cBinop_XUZf3upv, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_GSGz0Jj4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7ExfHys2, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_0aUqG0n5, 4720.0f);
  numBytes += cBinop_init(&cBinop_QnvoyYgK, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_uUXnc56J, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wR3iwfXo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5EGrzIwn, 4720.0f);
  numBytes += cBinop_init(&cBinop_rboUgxUy, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_l7DmsHrf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BRv2Tpjt, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_SQ4unrAw, 1.0f);
  numBytes += cIf_init(&cIf_Ah847ggI, false);
  numBytes += sVarf_init(&sVarf_Thu1yC1L, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_G488OcuY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MqrhPoRK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6K6LZ0P0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HTtj5Eyq, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_Fliazw6k, &hTable_AA8FCmwT);
  numBytes += cVar_init_s(&cVar_PIfzD63H, "del-1380-del1");
  numBytes += cDelay_init(this, &cDelay_AbWJAN9B, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_F7piPUKt, 0.0f);
  numBytes += cBinop_init(&cBinop_eljwDx9x, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_BBmBfMBp, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eDQztlJJ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_mR9A5E2f, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_fDGNzDFl, &hTable_Wr6uU0Bu);
  numBytes += cVar_init_s(&cVar_N6PqgSfb, "del-1380-del2");
  numBytes += cDelay_init(this, &cDelay_RyffeVBl, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_l8ZEhDCH, 0.0f);
  numBytes += cBinop_init(&cBinop_6vs3c1LD, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_roj9xzjo, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_usv63aL5, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_KGd0N7nO, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_34KDiFsG, &hTable_7yScw3nJ);
  numBytes += cVar_init_s(&cVar_rwGbOOyz, "del-1380-del3");
  numBytes += cDelay_init(this, &cDelay_xb4vGCmZ, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_3tEjPjMU, 0.0f);
  numBytes += cBinop_init(&cBinop_OCnwVvGp, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_HTEiG5u7, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ErjRs9Ex, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_2lBagygC, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_TMVweQpP, &hTable_oyaHkUVb);
  numBytes += cVar_init_s(&cVar_GPED2EGP, "del-1380-del4");
  numBytes += cDelay_init(this, &cDelay_EiB80pph, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_YhwnxGxK, 0.0f);
  numBytes += cBinop_init(&cBinop_Dv78FfOp, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_eSIoRcEG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_GU1SgWOu, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_4008yVIF, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_QXeZNJ13, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gEpsM1oD, 0.0f);
  numBytes += hTable_init(&hTable_AA8FCmwT, 256);
  numBytes += cDelay_init(this, &cDelay_NUTujX28, 0.0f);
  numBytes += cDelay_init(this, &cDelay_p195Jv95, 0.0f);
  numBytes += hTable_init(&hTable_Wr6uU0Bu, 256);
  numBytes += cDelay_init(this, &cDelay_pOfyuVuK, 0.0f);
  numBytes += cDelay_init(this, &cDelay_hIZ9T1Ej, 0.0f);
  numBytes += hTable_init(&hTable_7yScw3nJ, 256);
  numBytes += cDelay_init(this, &cDelay_i5kZ2tbM, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Nz2xsUDS, 0.0f);
  numBytes += hTable_init(&hTable_oyaHkUVb, 256);
  numBytes += cIf_init(&cIf_fq44mSQR, false);
  numBytes += cBinop_init(&cBinop_opFDE68L, 0.0f); // __pow
  numBytes += cPack_init(&cPack_f44vPekf, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_y7gfsDlF, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_wvqBiHyg, 22050.0f);
  numBytes += cBinop_init(&cBinop_jdT1xnfo, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_MDg5XWZi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VMCrHD8y, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_gAX6mmnJ, 100.0f);
  numBytes += cVar_init_f(&cVar_1JpSKrMU, 95.0f);
  numBytes += cVar_init_f(&cVar_q0VZLCDb, 14400.0f);
  numBytes += cVar_init_f(&cVar_uJUXRS0d, 60.0f);
  numBytes += cIf_init(&cIf_eW9BShOm, false);
  numBytes += cTabhead_init(&cTabhead_CJVfSWQs, &hTable_uHbLv3ZI);
  numBytes += cVar_init_s(&cVar_T5ZaXecQ, "del-1380-ref6");
  numBytes += cDelay_init(this, &cDelay_NzDPZ5ro, 13.645f);
  numBytes += cDelay_init(this, &cDelay_Kki6Rj5Z, 0.0f);
  numBytes += cBinop_init(&cBinop_xwR2qYe7, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_fjBWJfkQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_yaJmEFHR, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_W5lGQtOq, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_BlpMBaE6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_F4mHZQL3, 0.0f);
  numBytes += hTable_init(&hTable_uHbLv3ZI, 256);
  numBytes += cTabhead_init(&cTabhead_Npn5Gs7X, &hTable_0xMUdkpu);
  numBytes += cVar_init_s(&cVar_xlR6cb7z, "del-1380-ref5");
  numBytes += cDelay_init(this, &cDelay_8j1gQ198, 16.364f);
  numBytes += cDelay_init(this, &cDelay_8wJgRt2M, 0.0f);
  numBytes += cBinop_init(&cBinop_RLmGRtXy, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_R51UWAQr, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_WWPq2cFi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_9oRiTY2W, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ZVKdIE8i, 0.0f);
  numBytes += cDelay_init(this, &cDelay_IaTgcD0g, 0.0f);
  numBytes += hTable_init(&hTable_0xMUdkpu, 256);
  numBytes += cTabhead_init(&cTabhead_ZV8Ypr3I, &hTable_p0Gq1zlL);
  numBytes += cVar_init_s(&cVar_UDrWTyAM, "del-1380-ref4");
  numBytes += cDelay_init(this, &cDelay_gYE5VDdm, 19.392f);
  numBytes += cDelay_init(this, &cDelay_dmr82Y3U, 0.0f);
  numBytes += cBinop_init(&cBinop_yYwQhoDp, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_X6H0L9tN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_kfAt7Rp7, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_EQUJcgeY, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_dICYFjpK, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TBrJIwhT, 0.0f);
  numBytes += hTable_init(&hTable_p0Gq1zlL, 256);
  numBytes += cTabhead_init(&cTabhead_oNNWyJxi, &hTable_jDvbKOz0);
  numBytes += cVar_init_s(&cVar_BxllU1k2, "del-1380-ref3");
  numBytes += cDelay_init(this, &cDelay_CIQ1Cu1m, 25.796f);
  numBytes += cDelay_init(this, &cDelay_NO6QXvFX, 0.0f);
  numBytes += cBinop_init(&cBinop_c0Ol9jr8, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_zKYsUZiI, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_LX1YMRf0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Yo5dYA0S, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_2Pra6bHw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ufiWnvyN, 0.0f);
  numBytes += hTable_init(&hTable_jDvbKOz0, 256);
  numBytes += cTabhead_init(&cTabhead_MKr9R2kL, &hTable_w0g3xqJH);
  numBytes += cVar_init_s(&cVar_dUCQXc61, "del-1380-ref2");
  numBytes += cDelay_init(this, &cDelay_AARbjPMx, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_BaoNAWoO, 0.0f);
  numBytes += cBinop_init(&cBinop_WldOVrMD, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_8LtSulAM, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_kxqIhQSJ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_LZJLYdJB, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_mCyHROzX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_av2fMsqf, 0.0f);
  numBytes += hTable_init(&hTable_w0g3xqJH, 256);
  numBytes += cTabhead_init(&cTabhead_z8c866Q4, &hTable_gngThHUw);
  numBytes += cVar_init_s(&cVar_rV8IiApr, "del-1380-ref1");
  numBytes += cDelay_init(this, &cDelay_YWixhY0I, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_iinlJNcQ, 0.0f);
  numBytes += cBinop_init(&cBinop_z7mLb2yA, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_LmCQzUYh, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_evTzH5f2, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_3sDkMlx1, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_c7eD1oCg, 0.0f);
  numBytes += cDelay_init(this, &cDelay_HhxsQCX4, 0.0f);
  numBytes += hTable_init(&hTable_gngThHUw, 256);
  numBytes += cVar_init_f(&cVar_0B5UB2A9, 0.0f);
  numBytes += cVar_init_f(&cVar_aKeeEg34, 0.0f);
  numBytes += cPack_init(&cPack_iF6cES8k, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_tBuxNZDA, 22050.0f);
  numBytes += cBinop_init(&cBinop_Fun07543, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_grFrKiK8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WxuCPDrV, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_zzIlLKFl, 22050.0f);
  numBytes += cBinop_init(&cBinop_eWbVX0cP, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_3TRoGytN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xV2AZBCF, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_GziR87yH, 22050.0f);
  numBytes += cBinop_init(&cBinop_joHR4093, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_3WwDXyzG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oAzfR1Fg, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_BIO8G4ji, "del-1479-del1");
  numBytes += sVarf_init(&sVarf_JOZkTfsK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9R8cTYmr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wt7Hf6Y5, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_zVoFtlE2, 10000.0f);
  numBytes += cBinop_init(&cBinop_sly4pc9z, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ysHOOdUa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ImIXwPOC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xpuR5GTl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3CuIpagK, 10.0f);
  numBytes += cBinop_init(&cBinop_qNnsMkXV, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_PaWux6rN, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_JI1HgfyK, "floatatom");
  numBytes += sVarf_init(&sVarf_X5MvNE68, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_UsDyoL0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BQTxa2Co, 0.0f);
  numBytes += hTable_init(&hTable_HKcO3eEe, 256);
  numBytes += sVarf_init(&sVarf_1ADVNZeK, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_sfplaFgE, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_IAVFoM2H, 713606508);
  numBytes += cSlice_init(&cSlice_lM13Svxg, 1, 1);
  numBytes += cRandom_init(&cRandom_Ld5vbcrm, -2120343116);
  numBytes += cSlice_init(&cSlice_VVCvEaDV, 1, 1);
  numBytes += cVar_init_s(&cVar_qcKmFLAu, "floatatom");
  numBytes += cPack_init(&cPack_TDllDUMv, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_YornEpoA, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_Aoz0Ylud, "floatatom");
  numBytes += cDelay_init(this, &cDelay_7eDCLKg7, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iHx9K2Xl, 0.0f);
  numBytes += hTable_init(&hTable_8vLYIp60, 256);
  numBytes += cVar_init_s(&cVar_SNN4ljMF, "del-1510-del");
  numBytes += sVarf_init(&sVarf_VVRMQJZm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LeT5vdn3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bWhtdLBz, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_5sULwvJK, "del-1510-del");
  numBytes += sVarf_init(&sVarf_qiUpTbwx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_c8UOcUI6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GKpB4cI1, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_UVnEHB5Y, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_DE55hnrI, "del-1539-del1");
  numBytes += sVarf_init(&sVarf_Llk9n9su, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zaKt4Hps, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_00zQrgip, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_p2amF8mZ, 10000.0f);
  numBytes += cBinop_init(&cBinop_sJiN9tn3, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_RB5vETCB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_boDQkf3r, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JsFdbytZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_IlGYwPwu, 10.0f);
  numBytes += cBinop_init(&cBinop_HXcnvIkw, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_GW74Pjns, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_FLupumKs, "floatatom");
  numBytes += sVarf_init(&sVarf_WJZu03VI, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_DZa1FVMj, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iiPJHDNo, 0.0f);
  numBytes += hTable_init(&hTable_lLISmVYz, 256);
  numBytes += sVarf_init(&sVarf_Fstt3lug, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_fxBTFh90, "floatatom");
  numBytes += cDelay_init(this, &cDelay_R9eMiN6y, 0.0f);
  numBytes += cVar_init_f(&cVar_9eqcpuUT, 20.0f);
  numBytes += cBinop_init(&cBinop_vU0POHY3, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_8dNTxIif, 0.0f);
  numBytes += cSlice_init(&cSlice_4T14f291, 1, -1);
  numBytes += cSlice_init(&cSlice_HzXEDruP, 1, -1);
  numBytes += cVar_init_f(&cVar_KgK9C7hY, 0.0f);
  numBytes += cVar_init_f(&cVar_isgjVizP, 20.0f);
  numBytes += cVar_init_f(&cVar_zdoYTd0O, 0.0f);
  numBytes += cVar_init_f(&cVar_EdryHjUY, 0.0f);
  numBytes += cVar_init_f(&cVar_vCAL56qD, 0.0f);
  numBytes += cSlice_init(&cSlice_zsttKeH6, 1, 1);
  numBytes += cSlice_init(&cSlice_XLgsQqlr, 0, 1);
  numBytes += cBinop_init(&cBinop_GQi2OUzv, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_jKxVdelU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_T75fuRPH, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fYGK290I, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_45LfvXrd, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_Hre7USsQ, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_pJUAe0B5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_8iyfo9lO, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_NZislZMT, "floatatom");
  numBytes += cDelay_init(this, &cDelay_nduJtpT8, 0.0f);
  numBytes += cVar_init_f(&cVar_0eGhL6Ra, 20.0f);
  numBytes += cBinop_init(&cBinop_gEhZubWJ, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_bYSYmOPD, 0.0f);
  numBytes += cSlice_init(&cSlice_ymgelnvv, 1, -1);
  numBytes += cSlice_init(&cSlice_i9epzjp5, 1, -1);
  numBytes += cVar_init_f(&cVar_pv9Bnd7W, 0.0f);
  numBytes += cVar_init_f(&cVar_w6B1Jcnl, 20.0f);
  numBytes += cVar_init_f(&cVar_dxbFSLUZ, 0.0f);
  numBytes += cVar_init_f(&cVar_X4k0EvSf, 0.0f);
  numBytes += cVar_init_f(&cVar_IwK6Yyho, 0.0f);
  numBytes += cSlice_init(&cSlice_YAIaLWub, 1, 1);
  numBytes += cSlice_init(&cSlice_596bXd7m, 0, 1);
  numBytes += cBinop_init(&cBinop_jYCnQCnD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ohNTrYB6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KS2Ob2Ee, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_wtRV29LK, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_JKEVvJ6Y, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_g3Lognc2, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_1pCsfHOM, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_E9AXFdvV, 0.0f); // __sub
  numBytes += cPack_init(&cPack_zdemUwI4, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_qsoRmaEh, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_bUnTBK9z, 2, 0.0f, 1000.0f);
  numBytes += cVar_init_f(&cVar_Wa3ZuHrX, 100.0f);
  numBytes += cIf_init(&cIf_TWcIrZiz, false);
  numBytes += cBinop_init(&cBinop_LxAerO3A, 0.0f); // __pow
  numBytes += cPack_init(&cPack_0la9f8kZ, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_1grn6RFg, 0.0f);
  numBytes += cVar_init_f(&cVar_ZDRtiCOj, 100.0f);
  numBytes += cIf_init(&cIf_WMevGynS, false);
  numBytes += cBinop_init(&cBinop_EjviZu4l, 0.0f); // __pow
  numBytes += cPack_init(&cPack_uT1kzjv9, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_4EI6xETs, 0.0f);
  numBytes += cIf_init(&cIf_M4xmTw4z, false);
  numBytes += cIf_init(&cIf_TpAvcDbp, false);
  numBytes += cVar_init_f(&cVar_vU6kApsy, 97.0f);
  numBytes += cIf_init(&cIf_OsJcpA78, false);
  numBytes += cBinop_init(&cBinop_3kQOOAwh, 0.0f); // __pow
  numBytes += cPack_init(&cPack_RwiAAHjl, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_C0CgSJO1, 0.0f);
  numBytes += cVar_init_f(&cVar_sp6qHUTy, 89.0f);
  numBytes += cIf_init(&cIf_EBtKSKzO, false);
  numBytes += cBinop_init(&cBinop_WvTwfFVe, 0.0f); // __pow
  numBytes += cPack_init(&cPack_AmMg9ayQ, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_oYymC1Q0, 0.0f);
  numBytes += cVar_init_f(&cVar_FEiShUFa, 97.0f);
  numBytes += cIf_init(&cIf_JkV95C07, false);
  numBytes += cBinop_init(&cBinop_t57fy7gY, 0.0f); // __pow
  numBytes += cPack_init(&cPack_gvXiuAOf, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_bv1eKTqn, 0.0f);
  numBytes += cPack_init(&cPack_SyqN42LB, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_7qt4Xpyk, 1, 1);
  numBytes += cSlice_init(&cSlice_ylQXCBlm, 0, 1);
  numBytes += cIf_init(&cIf_TQD6cYgl, false);
  numBytes += cIf_init(&cIf_mndE9qbC, false);
  numBytes += cIf_init(&cIf_yVsKWkzp, false);
  numBytes += cSlice_init(&cSlice_bgnoNinY, 1, 1);
  numBytes += cSlice_init(&cSlice_fv72dWQ9, 0, 1);
  numBytes += cVar_init_f(&cVar_3YlMDn5k, 0.0f);
  numBytes += cIf_init(&cIf_EcSKl7VR, false);
  numBytes += cPack_init(&cPack_3Z7TkOOR, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_lfnkktQz, 1, -1);
  numBytes += cSlice_init(&cSlice_PsFEi1mg, 1, -1);
  numBytes += cSlice_init(&cSlice_zaKByEg2, 1, -1);
  numBytes += cSlice_init(&cSlice_Za2Z892y, 1, -1);
  numBytes += cIf_init(&cIf_tpgqEebY, false);
  numBytes += cVar_init_f(&cVar_zIwtTIlE, 1.0f);
  numBytes += cPack_init(&cPack_kQqnYKg0, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_s14KR1LY, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_PhaseRing::~Heavy_PhaseRing() {
  cPack_free(&cPack_PIdtxMH6);
  cPack_free(&cPack_YjP80vSV);
  cPack_free(&cPack_LDCqQ8mk);
  cPack_free(&cPack_SH1NswbM);
  cPack_free(&cPack_qga02r6d);
  cPack_free(&cPack_ZqZ2Lw0N);
  cPack_free(&cPack_WwOpPCE2);
  cPack_free(&cPack_TUxtaI2o);
  cPack_free(&cPack_o64KUlOS);
  cPack_free(&cPack_yiGwZXJ5);
  cPack_free(&cPack_y4NyJHqF);
  cPack_free(&cPack_YHMo2vNL);
  cPack_free(&cPack_z3tNdwTJ);
  cPack_free(&cPack_wwNwO158);
  cPack_free(&cPack_dv0wyXYD);
  cPack_free(&cPack_N7sEgEmo);
  cPack_free(&cPack_MHJpUkeH);
  hTable_free(&hTable_zghthmB7);
  hTable_free(&hTable_nalEOYMq);
  hTable_free(&hTable_OcmXYXCS);
  hTable_free(&hTable_SjPHX9Gv);
  cPack_free(&cPack_JaZ3eDOy);
  cPack_free(&cPack_4Jz7rgcG);
  hTable_free(&hTable_ua2isCjv);
  hTable_free(&hTable_IJIcP0va);
  hTable_free(&hTable_LbWYVZB4);
  hTable_free(&hTable_jzBRok7l);
  hTable_free(&hTable_FY7LcnD6);
  hTable_free(&hTable_bqM7kUv1);
  cPack_free(&cPack_2Tht7zvb);
  cPack_free(&cPack_cveYnAOw);
  cPack_free(&cPack_V2cbpbHT);
  hTable_free(&hTable_1N2pKnrk);
  hTable_free(&hTable_AA8FCmwT);
  hTable_free(&hTable_Wr6uU0Bu);
  hTable_free(&hTable_7yScw3nJ);
  hTable_free(&hTable_oyaHkUVb);
  cPack_free(&cPack_f44vPekf);
  cPack_free(&cPack_y7gfsDlF);
  hTable_free(&hTable_uHbLv3ZI);
  hTable_free(&hTable_0xMUdkpu);
  hTable_free(&hTable_p0Gq1zlL);
  hTable_free(&hTable_jDvbKOz0);
  hTable_free(&hTable_w0g3xqJH);
  hTable_free(&hTable_gngThHUw);
  cPack_free(&cPack_iF6cES8k);
  hTable_free(&hTable_HKcO3eEe);
  cPack_free(&cPack_sfplaFgE);
  cPack_free(&cPack_TDllDUMv);
  cPack_free(&cPack_YornEpoA);
  hTable_free(&hTable_8vLYIp60);
  hTable_free(&hTable_lLISmVYz);
  cPack_free(&cPack_zdemUwI4);
  cPack_free(&cPack_qsoRmaEh);
  cPack_free(&cPack_bUnTBK9z);
  cPack_free(&cPack_0la9f8kZ);
  cPack_free(&cPack_uT1kzjv9);
  cPack_free(&cPack_RwiAAHjl);
  cPack_free(&cPack_AmMg9ayQ);
  cPack_free(&cPack_gvXiuAOf);
  cPack_free(&cPack_SyqN42LB);
  cPack_free(&cPack_3Z7TkOOR);
  cPack_free(&cPack_kQqnYKg0);
}

HvTable *Heavy_PhaseRing::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xB0671461: return &hTable_zghthmB7; // del-1210-del1
    case 0xD3F5721F: return &hTable_nalEOYMq; // del-1210-del2
    case 0xC10D6C35: return &hTable_OcmXYXCS; // del-1210-del3
    case 0xB5FEED7B: return &hTable_SjPHX9Gv; // del-1210-del4
    case 0x2A9662CE: return &hTable_ua2isCjv; // del-1210-ref6
    case 0x3096656F: return &hTable_IJIcP0va; // del-1210-ref5
    case 0x70243206: return &hTable_LbWYVZB4; // del-1210-ref4
    case 0xEEED6608: return &hTable_jzBRok7l; // del-1210-ref3
    case 0xDBBB6EB0: return &hTable_FY7LcnD6; // del-1210-ref2
    case 0xB68B4BD4: return &hTable_bqM7kUv1; // del-1210-ref1
    case 0x405083F: return &hTable_1N2pKnrk; // del-1317-del
    case 0xF19F8B56: return &hTable_AA8FCmwT; // del-1380-del1
    case 0x308C8562: return &hTable_Wr6uU0Bu; // del-1380-del2
    case 0x21526483: return &hTable_7yScw3nJ; // del-1380-del3
    case 0xBE3EFFE1: return &hTable_oyaHkUVb; // del-1380-del4
    case 0xEB7F6762: return &hTable_uHbLv3ZI; // del-1380-ref6
    case 0x198895E2: return &hTable_0xMUdkpu; // del-1380-ref5
    case 0x28608A96: return &hTable_p0Gq1zlL; // del-1380-ref4
    case 0xAC336734: return &hTable_jDvbKOz0; // del-1380-ref3
    case 0xB3E48849: return &hTable_w0g3xqJH; // del-1380-ref2
    case 0x78A7871A: return &hTable_gngThHUw; // del-1380-ref1
    case 0xB4A4BA2: return &hTable_HKcO3eEe; // del-1479-del1
    case 0x74129230: return &hTable_8vLYIp60; // del-1510-del
    case 0x3CFB0B3: return &hTable_lLISmVYz; // del-1539-del1
    default: return nullptr;
  }
}

void Heavy_PhaseRing::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x9DBB052E: { // 1057-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PgUb6ep7_sendMessage);
      break;
    }
    case 0xF1DE93DD: { // 1057-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YU11Kgar_sendMessage);
      break;
    }
    case 0x6CD381D4: { // 1057-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cdF1MFb0_sendMessage);
      break;
    }
    case 0xCF6D3C3F: { // 1057-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IFfLEHOl_sendMessage);
      break;
    }
    case 0xEDDFD30D: { // 1057-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ONgsZ2Ya_sendMessage);
      break;
    }
    case 0xF2BA3B2A: { // 1057-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_D9HFBQZB_sendMessage);
      break;
    }
    case 0x4C999BDD: { // 1094-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IzMdH9vB_sendMessage);
      break;
    }
    case 0xB7ADD52E: { // 1094-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hCWsdjJc_sendMessage);
      break;
    }
    case 0x3A67A583: { // 1102-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZFwFO0dE_sendMessage);
      break;
    }
    case 0x106C8009: { // 1102-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oHdcddXE_sendMessage);
      break;
    }
    case 0x42BC8229: { // 1102-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8atSetXe_sendMessage);
      break;
    }
    case 0xC1FC464: { // 1102-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_i6PWbdPz_sendMessage);
      break;
    }
    case 0x2189FF6C: { // 1102-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BX5195QS_sendMessage);
      break;
    }
    case 0xEC7D062A: { // 1102-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ghxOfvx4_sendMessage);
      break;
    }
    case 0xA936B970: { // 1138-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cc0Hdcfi_sendMessage);
      break;
    }
    case 0x2A8844A1: { // 1138-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VozYFjql_sendMessage);
      break;
    }
    case 0xB529824: { // 1138-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gWGIIkJO_sendMessage);
      break;
    }
    case 0x9097A2AD: { // 1138-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Kcx1vUDc_sendMessage);
      break;
    }
    case 0x7F7D0117: { // 1138-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PwabnvwU_sendMessage);
      break;
    }
    case 0x574B730F: { // 1138-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uHKTDtox_sendMessage);
      break;
    }
    case 0x585707AB: { // 1174-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZKiahiLS_sendMessage);
      break;
    }
    case 0x7B3A6787: { // 1174-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qqZkRvqp_sendMessage);
      break;
    }
    case 0xF29D7AC3: { // 1174-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RViHAS67_sendMessage);
      break;
    }
    case 0x75F9193E: { // 1174-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3Ttddo5N_sendMessage);
      break;
    }
    case 0xB840EC84: { // 1174-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tCBXysrW_sendMessage);
      break;
    }
    case 0x2F34E032: { // 1174-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_51U0050o_sendMessage);
      break;
    }
    case 0xEA1C03D1: { // 1600-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sBtu3ipe_sendMessage);
      break;
    }
    case 0x6CD92272: { // 1600-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CLeWNtPI_sendMessage);
      break;
    }
    case 0x95ACE67F: { // 1608-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jhJX6wl0_sendMessage);
      break;
    }
    case 0x3FE1AFF3: { // 1608-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6GAwzpGg_sendMessage);
      break;
    }
    case 0x17DE41C5: { // 1620-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dDj1gONn_sendMessage);
      break;
    }
    case 0x8C4E88AD: { // 1620-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UxKsKFFs_sendMessage);
      break;
    }
    case 0x864A3907: { // 1628-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5QcGMf5m_sendMessage);
      break;
    }
    case 0x7E3F5388: { // 1628-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_J2kbkFVt_sendMessage);
      break;
    }
    case 0xF2EB190A: { // 1636-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gsPJEUFg_sendMessage);
      break;
    }
    case 0x4DD3A5BD: { // 1636-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9hk6hPlD_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zrgvIk4U_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dvK4NdTB_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_re6mUNLq_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CEhZt9in_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iSeAYiiZ_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PEVlcOCo_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VFDd3yRq_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bZX432e7_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NaNZwWtP_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_U2EvzGwG_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qawHGVJM_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zMi2GUWu_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fqrjLzG9_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4MOGS1E2_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WBgraKGP_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Q1oS9UTc_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yYoq6e31_sendMessage);
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


void Heavy_PhaseRing::cSlice_zO41hOit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_9SOh7DzP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_MfO1apwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_iwh5AQfU, 0, m, &cIf_iwh5AQfU_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_YvKDNjoL, 0, m, &cIf_YvKDNjoL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_Melq9WiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_P020EIVz, 0, m, &cIf_P020EIVz_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_haIq85Ct, 0, m, &cIf_haIq85Ct_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_J732KMWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Zw5W3zeQ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_j2cSIZ8g, 0, m, &cIf_j2cSIZ8g_sendMessage);
}

void Heavy_PhaseRing::cUnop_H1frellT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_70cRixsz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Op4FiIsx, HV_BINOP_EQ, 1, m, &cBinop_Op4FiIsx_sendMessage);
}

void Heavy_PhaseRing::cUnop_rerEIR0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_70cRixsz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Op4FiIsx, HV_BINOP_EQ, 1, m, &cBinop_Op4FiIsx_sendMessage);
}

void Heavy_PhaseRing::cIf_j2cSIZ8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_rerEIR0K_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_H1frellT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Zw5W3zeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_j2cSIZ8g, 1, m, &cIf_j2cSIZ8g_sendMessage);
}

void Heavy_PhaseRing::cIf_YvKDNjoL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_sk0mjCCI_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_haIq85Ct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_7thgdSyc_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_iwh5AQfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_sk0mjCCI_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_P020EIVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_7thgdSyc_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_9SOh7DzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Op4FiIsx, HV_BINOP_EQ, 0, m, &cBinop_Op4FiIsx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Dt21lpxn_sendMessage);
}

void Heavy_PhaseRing::cBinop_70cRixsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1ATlqTvP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fQEd0z3Q_sendMessage);
}

void Heavy_PhaseRing::cBinop_Op4FiIsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_r6bvAsCW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aPKtyRFL_sendMessage);
}

void Heavy_PhaseRing::cCast_r6bvAsCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YvKDNjoL, 1, m, &cIf_YvKDNjoL_sendMessage);
}

void Heavy_PhaseRing::cCast_aPKtyRFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_P020EIVz, 1, m, &cIf_P020EIVz_sendMessage);
}

void Heavy_PhaseRing::cCast_1ATlqTvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iwh5AQfU, 1, m, &cIf_iwh5AQfU_sendMessage);
}

void Heavy_PhaseRing::cCast_fQEd0z3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_haIq85Ct, 1, m, &cIf_haIq85Ct_sendMessage);
}

void Heavy_PhaseRing::cBinop_Dt21lpxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_94zgp24O_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_MUgBISEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xq0RaZ6A, 0, m, &cVar_xq0RaZ6A_sendMessage);
}

void Heavy_PhaseRing::cBinop_dxxE8wo2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ayUhTy63_sendMessage);
}

void Heavy_PhaseRing::cBinop_ayUhTy63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xJrWuDN1, HV_BINOP_POW, 1, m, &cBinop_xJrWuDN1_sendMessage);
  cMsg_ryygtFsk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_xJrWuDN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_MUgBISEN_sendMessage);
}

void Heavy_PhaseRing::cMsg_ryygtFsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xJrWuDN1, HV_BINOP_POW, 0, m, &cBinop_xJrWuDN1_sendMessage);
}

void Heavy_PhaseRing::cBinop_f4vcSEzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OBnM61Wp_sendMessage);
}

void Heavy_PhaseRing::cBinop_OBnM61Wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_smCrLydM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QcgqMvER_sendMessage);
}

void Heavy_PhaseRing::cVar_1Rc5fTsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_C2i5Go06_sendMessage);
}

void Heavy_PhaseRing::cMsg_2HUJUN4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YGczftff_sendMessage);
}

void Heavy_PhaseRing::cSystem_YGczftff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_saxV5h1c, HV_BINOP_DIVIDE, 1, m, &cBinop_saxV5h1c_sendMessage);
}

void Heavy_PhaseRing::cBinop_smCrLydM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Mj6MoCZa_sendMessage);
}

void Heavy_PhaseRing::cBinop_Mj6MoCZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8CuO9lEx, m);
}

void Heavy_PhaseRing::cMsg_hDNvCcYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_u8BfvmSt_sendMessage);
}

void Heavy_PhaseRing::cBinop_u8BfvmSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_f4vcSEzu_sendMessage);
}

void Heavy_PhaseRing::cBinop_QcgqMvER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GCUpExZI, m);
}

void Heavy_PhaseRing::cBinop_C2i5Go06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_BlZ2QShw_sendMessage);
}

void Heavy_PhaseRing::cBinop_BlZ2QShw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_saxV5h1c, HV_BINOP_DIVIDE, 0, m, &cBinop_saxV5h1c_sendMessage);
}

void Heavy_PhaseRing::cBinop_saxV5h1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hDNvCcYG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_PIdtxMH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_b7aAIByH, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_MetXbSLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_AZDpHJKg_sendMessage);
}

void Heavy_PhaseRing::cVar_xq0RaZ6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_eX1XmOPT, 0, m);
}

void Heavy_PhaseRing::cIf_VNPUgcNO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_zIezfTBu_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_qm3EhjKE, 0, m, &cIf_qm3EhjKE_sendMessage);
      break;
    }
    case 1: {
      cMsg_5kjckQnE_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_16DZkcyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VNPUgcNO, 1, m, &cIf_VNPUgcNO_sendMessage);
}

void Heavy_PhaseRing::cIf_qm3EhjKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_kAz5onaB_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_YS2m7VKs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_zIezfTBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qm3EhjKE, 1, m, &cIf_qm3EhjKE_sendMessage);
}

void Heavy_PhaseRing::cMsg_5kjckQnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_YS2m7VKs_sendMessage);
}

void Heavy_PhaseRing::cMsg_kAz5onaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_YS2m7VKs_sendMessage);
}

void Heavy_PhaseRing::cIf_RIcgfi22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_fydH4ycR_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_1UUaB3bG, 0, m, &cIf_1UUaB3bG_sendMessage);
      break;
    }
    case 1: {
      cMsg_7dPzDVl9_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_rDb1lntl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RIcgfi22, 1, m, &cIf_RIcgfi22_sendMessage);
}

void Heavy_PhaseRing::cIf_1UUaB3bG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Fs9M4ko4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_LDCqQ8mk, 0, m, &cPack_LDCqQ8mk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_fydH4ycR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1UUaB3bG, 1, m, &cIf_1UUaB3bG_sendMessage);
}

void Heavy_PhaseRing::cMsg_7dPzDVl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_LDCqQ8mk, 0, m, &cPack_LDCqQ8mk_sendMessage);
}

void Heavy_PhaseRing::cMsg_Fs9M4ko4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_LDCqQ8mk, 0, m, &cPack_LDCqQ8mk_sendMessage);
}

void Heavy_PhaseRing::cPack_YjP80vSV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_iwX6FNnm, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_LDCqQ8mk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_67FSWtId, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_SH1NswbM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_glIoRjzW, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_AZDpHJKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.1f, 0, m, &cBinop_UX7pBGfF_sendMessage);
}

void Heavy_PhaseRing::cBinop_E7MhDO4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MetXbSLF, 0, m, &cVar_MetXbSLF_sendMessage);
}

void Heavy_PhaseRing::cBinop_UX7pBGfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PIdtxMH6, 0, m, &cPack_PIdtxMH6_sendMessage);
}

void Heavy_PhaseRing::cBinop_YS2m7VKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_qDPUCMYT_sendMessage);
}

void Heavy_PhaseRing::cBinop_qDPUCMYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_rDb1lntl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_RIcgfi22, 0, m, &cIf_RIcgfi22_sendMessage);
}

void Heavy_PhaseRing::cCast_aoaVbtsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VDKJGDUT_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_sGMk8bWU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_VDKJGDUT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ScRtj1Yh, 0, m, &cSlice_ScRtj1Yh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_X3FIS4ue, 0, m, &cRandom_X3FIS4ue_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_NQNnSYlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qNut2hCi_sendMessage);
}

void Heavy_PhaseRing::cUnop_qNut2hCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dSdsjEgs, 0, m, &cVar_dSdsjEgs_sendMessage);
}

void Heavy_PhaseRing::cRandom_X3FIS4ue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_NQNnSYlI_sendMessage);
}

void Heavy_PhaseRing::cSlice_ScRtj1Yh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_X3FIS4ue, 1, m, &cRandom_X3FIS4ue_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_dSdsjEgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IpiA7SIw_sendMessage(_c, 0, m);
  cSend_9LlikF1N_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_sGMk8bWU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_meMtDNmS, 0, m, &cSlice_meMtDNmS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9dUCoAus, 0, m, &cRandom_9dUCoAus_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_cE9eVUgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tk309aBn_sendMessage);
}

void Heavy_PhaseRing::cUnop_tk309aBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_tORgHaH4_sendMessage);
  cSend_cX67e01E_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cRandom_9dUCoAus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_cE9eVUgw_sendMessage);
}

void Heavy_PhaseRing::cSlice_meMtDNmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9dUCoAus, 1, m, &cRandom_9dUCoAus_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_vot9Ww7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_hSE5Dx3M_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_e8a1ocVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_iVa2XXFN_sendMessage);
}

void Heavy_PhaseRing::cBinop_iVa2XXFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e8a1ocVD, 1, m, &cVar_e8a1ocVD_sendMessage);
}

void Heavy_PhaseRing::cCast_5oxQb5lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_3jE9LqiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_XYrmuz0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_zXCjBBTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_u2VAPVZ1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_tORgHaH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vot9Ww7M, 0, m, &cVar_vot9Ww7M_sendMessage);
}

void Heavy_PhaseRing::cSend_hSE5Dx3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4MOGS1E2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_IpiA7SIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bZX432e7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_cX67e01E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yYoq6e31_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_9LlikF1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WBgraKGP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_uk2yaXjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_jue277sV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_jue277sV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PEVlcOCo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_R4bJWbpA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_jue277sV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_u2VAPVZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_re6mUNLq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_NdDIyUTM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zMOKKkV7, 0, m, &cSlice_zMOKKkV7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LNdOnIeR, 0, m, &cRandom_LNdOnIeR_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_z9lOvA3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tKBNlys2_sendMessage);
}

void Heavy_PhaseRing::cUnop_tKBNlys2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_M2qsroXp_sendMessage);
}

void Heavy_PhaseRing::cRandom_LNdOnIeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 900.0f, 0, m, &cBinop_z9lOvA3C_sendMessage);
}

void Heavy_PhaseRing::cSlice_zMOKKkV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LNdOnIeR, 1, m, &cRandom_LNdOnIeR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_eaHDBZcj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4XiOkRXS, 0, m, &cSlice_4XiOkRXS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZJxuQMTx, 0, m, &cRandom_ZJxuQMTx_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_esXwC8SJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2TrY82Vg_sendMessage);
}

void Heavy_PhaseRing::cUnop_2TrY82Vg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_1bu0N9II_sendMessage);
}

void Heavy_PhaseRing::cRandom_ZJxuQMTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_esXwC8SJ_sendMessage);
}

void Heavy_PhaseRing::cSlice_4XiOkRXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZJxuQMTx, 1, m, &cRandom_ZJxuQMTx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_Q5brILsM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xi8yIGLI, 0, m, &cSlice_xi8yIGLI_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fSSHAapF, 0, m, &cRandom_fSSHAapF_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_KmCm3yHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_dC6otFNY_sendMessage);
}

void Heavy_PhaseRing::cUnop_dC6otFNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_895yfdDK_sendMessage);
}

void Heavy_PhaseRing::cRandom_fSSHAapF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_KmCm3yHb_sendMessage);
}

void Heavy_PhaseRing::cSlice_xi8yIGLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fSSHAapF, 1, m, &cRandom_fSSHAapF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_FVspPN63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1FYsqLy2, HV_BINOP_MULTIPLY, 0, m, &cBinop_1FYsqLy2_sendMessage);
}

void Heavy_PhaseRing::cBinop_83B3S87X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_2AbM6yWu_sendMessage);
}

void Heavy_PhaseRing::cBinop_2AbM6yWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QdHgHCU3, HV_BINOP_POW, 1, m, &cBinop_QdHgHCU3_sendMessage);
  cMsg_9vNOgRbt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_QdHgHCU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_FVspPN63_sendMessage);
}

void Heavy_PhaseRing::cMsg_9vNOgRbt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QdHgHCU3, HV_BINOP_POW, 0, m, &cBinop_QdHgHCU3_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_lAR2oBOU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9ifCiDdA, 0, m, &cSlice_9ifCiDdA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hs6N4n4X, 0, m, &cRandom_hs6N4n4X_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_SYCx6KSy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_izuA7ODF_sendMessage);
}

void Heavy_PhaseRing::cUnop_izuA7ODF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IaFJqgd1_sendMessage);
}

void Heavy_PhaseRing::cRandom_hs6N4n4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_SYCx6KSy_sendMessage);
}

void Heavy_PhaseRing::cSlice_9ifCiDdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hs6N4n4X, 1, m, &cRandom_hs6N4n4X_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_qga02r6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PKTYloo8, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_VkEvoHpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_caEIpcD4_sendMessage);
}

void Heavy_PhaseRing::cVar_IpN5uEAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_k73cXnPz, 0, m);
}

void Heavy_PhaseRing::cVar_5uY5FSX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_AUHfrJ6v, 0, m);
}

void Heavy_PhaseRing::cVar_mIvK51LZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wZ87OUa8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hx5mLmat_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gENLtRpi_sendMessage);
}

void Heavy_PhaseRing::cCast_idmzrX1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_ucpRQZTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_AETZlJBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_Rv02aqAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_H3ec3zXG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_zBBtJLVB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_zBBtJLVB_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_NPDSNxZk, 1, m, &cDelay_NPDSNxZk_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AAzRGs4H_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_NPDSNxZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NPDSNxZk, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Dxq0jnWh, 0, m, &cVar_Dxq0jnWh_sendMessage);
}

void Heavy_PhaseRing::cMsg_zBBtJLVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NPDSNxZk, 0, m, &cDelay_NPDSNxZk_sendMessage);
}

void Heavy_PhaseRing::cCast_AAzRGs4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NPDSNxZk, 0, m, &cDelay_NPDSNxZk_sendMessage);
}

void Heavy_PhaseRing::cVar_Dxq0jnWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nVHTEFCD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_kfV9dtgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mIvK51LZ, 0, m, &cVar_mIvK51LZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_sAdVk3Pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_ZGwoN9nW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_RuaIcvMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_kgrsRlqm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Hhj8OATG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_MNGUIPYC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_bU66K3gH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YU11Kgar_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_FHmlnRR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_73vHDODT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cdF1MFb0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ZGwoN9nW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_kgrsRlqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YU11Kgar_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_MNGUIPYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cdF1MFb0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_tLAUv91L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_vkU8qyFt, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_nVHTEFCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_vkU8qyFt, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_gENLtRpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_H3ec3zXG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_wZ87OUa8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tLAUv91L_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_hx5mLmat_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Dxq0jnWh, 1, m, &cVar_Dxq0jnWh_sendMessage);
}

void Heavy_PhaseRing::cCast_NUGCJSPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_p66pyCwc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WwOpPCE2, 0, m, &cPack_WwOpPCE2_sendMessage);
}

void Heavy_PhaseRing::cUnop_hn4ji2Qs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ZqZ2Lw0N, 0, m, &cPack_ZqZ2Lw0N_sendMessage);
}

void Heavy_PhaseRing::cPack_ZqZ2Lw0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QvZeBKlp, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_WwOpPCE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_XSHc0Ia9, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_akwLxymb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_p66pyCwc_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_hn4ji2Qs_sendMessage);
}

void Heavy_PhaseRing::cMsg_7hsCOIfC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_akwLxymb_sendMessage);
}

void Heavy_PhaseRing::cSlice_I5P8dIPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_D7koaC4L_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_ZmKwHMw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ds5yVetT_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_83B3S87X_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_895yfdDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_55ervAIv_sendMessage);
}

void Heavy_PhaseRing::cBinop_55ervAIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_akwLxymb_sendMessage);
}

void Heavy_PhaseRing::cBinop_D7koaC4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TWV1KvuN_sendMessage(_c, 0, m);
  cSend_hoJkL0yt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_1FYsqLy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dIyqa1xy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s1lN25yT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5uY5FSX6, 0, m, &cVar_5uY5FSX6_sendMessage);
}

void Heavy_PhaseRing::cBinop_IaFJqgd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_JtxkJ2Mq_sendMessage);
}

void Heavy_PhaseRing::cBinop_JtxkJ2Mq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1FYsqLy2, HV_BINOP_MULTIPLY, 1, m, &cBinop_1FYsqLy2_sendMessage);
}

void Heavy_PhaseRing::cCast_Ds5yVetT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lAR2oBOU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_TWV1KvuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_D9HFBQZB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_s1lN25yT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Q5brILsM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_dIyqa1xy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kfV9dtgw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NUGCJSPd_sendMessage);
}

void Heavy_PhaseRing::cBinop_caEIpcD4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qga02r6d, 0, m, &cPack_qga02r6d_sendMessage);
}

void Heavy_PhaseRing::cSend_hoJkL0yt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IFfLEHOl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_TnFP4B6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ONgsZ2Ya_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_XWwfgsJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_TnFP4B6z_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_44gqBxJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pt7EcWYK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LuJdJzmu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4s6UAlqA_sendMessage);
}

void Heavy_PhaseRing::cIf_W9v35q3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_JRqc2cSd_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_c3GBEk9k_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_hqE5sPad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_V8L0xr24, HV_BINOP_POW, 0, m, &cBinop_V8L0xr24_sendMessage);
}

void Heavy_PhaseRing::cBinop_V8L0xr24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TUxtaI2o, 0, m, &cPack_TUxtaI2o_sendMessage);
}

void Heavy_PhaseRing::cBinop_4LOrV5Pd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_DgwtH2iY_sendMessage);
}

void Heavy_PhaseRing::cCast_4s6UAlqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_W9v35q3y, 0, m, &cIf_W9v35q3y_sendMessage);
}

void Heavy_PhaseRing::cCast_LuJdJzmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_iZ2BPYlw_sendMessage);
}

void Heavy_PhaseRing::cBinop_iZ2BPYlw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_W9v35q3y, 1, m, &cIf_W9v35q3y_sendMessage);
}

void Heavy_PhaseRing::cBinop_c3GBEk9k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_4LOrV5Pd_sendMessage);
}

void Heavy_PhaseRing::cMsg_JRqc2cSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_TUxtaI2o, 0, m, &cPack_TUxtaI2o_sendMessage);
}

void Heavy_PhaseRing::cBinop_DgwtH2iY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V8L0xr24, HV_BINOP_POW, 1, m, &cBinop_V8L0xr24_sendMessage);
  cMsg_hqE5sPad_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_TUxtaI2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8qxqPQ0y, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_tZXmWoPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_L8hGt09e_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_pt7EcWYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_tO2YSipM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_tO2YSipM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IzMdH9vB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_L8hGt09e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hCWsdjJc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Ua8QPmGP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_A0FIe4Nv, 0, m, &cSlice_A0FIe4Nv_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vdqMrm3q, 0, m, &cRandom_vdqMrm3q_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_Mcl9oSN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vteUlfaz_sendMessage);
}

void Heavy_PhaseRing::cUnop_vteUlfaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_Qg6a09Un_sendMessage);
}

void Heavy_PhaseRing::cRandom_vdqMrm3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_Mcl9oSN3_sendMessage);
}

void Heavy_PhaseRing::cSlice_A0FIe4Nv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vdqMrm3q, 1, m, &cRandom_vdqMrm3q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_DGJuwWSK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2xlbbWOj, HV_BINOP_MULTIPLY, 0, m, &cBinop_2xlbbWOj_sendMessage);
}

void Heavy_PhaseRing::cBinop_1uHJrK7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_g02VE8P1_sendMessage);
}

void Heavy_PhaseRing::cBinop_g02VE8P1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rPqpEclf, HV_BINOP_POW, 1, m, &cBinop_rPqpEclf_sendMessage);
  cMsg_Yf53l8iH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_rPqpEclf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_DGJuwWSK_sendMessage);
}

void Heavy_PhaseRing::cMsg_Yf53l8iH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rPqpEclf, HV_BINOP_POW, 0, m, &cBinop_rPqpEclf_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_yWeUer5A_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mtQbmmIc, 0, m, &cSlice_mtQbmmIc_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VC60tZ0H, 0, m, &cRandom_VC60tZ0H_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_paLDleZI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_8VZxA0U4_sendMessage);
}

void Heavy_PhaseRing::cUnop_8VZxA0U4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YB5XgtJx_sendMessage);
}

void Heavy_PhaseRing::cRandom_VC60tZ0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_paLDleZI_sendMessage);
}

void Heavy_PhaseRing::cSlice_mtQbmmIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VC60tZ0H, 1, m, &cRandom_VC60tZ0H_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_o64KUlOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2wGmCP6f, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_oTfLKwWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_KGjLkXtn_sendMessage);
}

void Heavy_PhaseRing::cVar_ZjHRbsem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_gPUxC6HI, 0, m);
}

void Heavy_PhaseRing::cVar_GhQKxHJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_b77Uip5l, 0, m);
}

void Heavy_PhaseRing::cVar_DcFOFDEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oLrEjCQf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JoVavqNb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OAgDvgZe_sendMessage);
}

void Heavy_PhaseRing::cCast_fbABPWNN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_iwLT7mxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_ZQ6dr5Pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_iXAR9BNO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_F46xUUYl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_wmfGhn19_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_wmfGhn19_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_cMdrE4ih, 1, m, &cDelay_cMdrE4ih_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ebeF66WL_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_cMdrE4ih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cMdrE4ih, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CSNn3Xl7, 0, m, &cVar_CSNn3Xl7_sendMessage);
}

void Heavy_PhaseRing::cMsg_wmfGhn19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cMdrE4ih, 0, m, &cDelay_cMdrE4ih_sendMessage);
}

void Heavy_PhaseRing::cCast_ebeF66WL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cMdrE4ih, 0, m, &cDelay_cMdrE4ih_sendMessage);
}

void Heavy_PhaseRing::cVar_CSNn3Xl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m3KGe8in_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_QLqynGr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DcFOFDEl, 0, m, &cVar_DcFOFDEl_sendMessage);
}

void Heavy_PhaseRing::cMsg_D8FM2aAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_8f5Hp662_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_fBefhZry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_E2zPHTjX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_lM9rxF42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_uCq4NaRT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_TO8mRI0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oHdcddXE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_5epepYRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_SnWDloHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8atSetXe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_8f5Hp662_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_E2zPHTjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oHdcddXE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_uCq4NaRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8atSetXe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_HUDia0UA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fkpNNbeY, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_m3KGe8in_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_fkpNNbeY, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_JoVavqNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CSNn3Xl7, 1, m, &cVar_CSNn3Xl7_sendMessage);
}

void Heavy_PhaseRing::cCast_oLrEjCQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HUDia0UA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_OAgDvgZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_F46xUUYl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_UBhr8ZCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_eBR5Lqcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_y4NyJHqF, 0, m, &cPack_y4NyJHqF_sendMessage);
}

void Heavy_PhaseRing::cUnop_Wn1ITcYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_yiGwZXJ5, 0, m, &cPack_yiGwZXJ5_sendMessage);
}

void Heavy_PhaseRing::cPack_yiGwZXJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VM7U9S3k, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_y4NyJHqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uZlc43yW, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_lO68a10t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_eBR5Lqcg_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_Wn1ITcYY_sendMessage);
}

void Heavy_PhaseRing::cMsg_Aqw6ALcV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_lO68a10t_sendMessage);
}

void Heavy_PhaseRing::cSlice_yKMnqAgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_LvzlxP4d_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_oxGDBhLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HhOvnxmc_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1uHJrK7f_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Qg6a09Un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_x6dGYKxu_sendMessage);
}

void Heavy_PhaseRing::cBinop_x6dGYKxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_lO68a10t_sendMessage);
}

void Heavy_PhaseRing::cBinop_LvzlxP4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nNdf6Qwu_sendMessage(_c, 0, m);
  cSend_kUdwllAQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_2xlbbWOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xcl5EkmM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SlEkAsPV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GhQKxHJo, 0, m, &cVar_GhQKxHJo_sendMessage);
}

void Heavy_PhaseRing::cBinop_YB5XgtJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_yrJ5L0od_sendMessage);
}

void Heavy_PhaseRing::cBinop_yrJ5L0od_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2xlbbWOj, HV_BINOP_MULTIPLY, 1, m, &cBinop_2xlbbWOj_sendMessage);
}

void Heavy_PhaseRing::cCast_HhOvnxmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yWeUer5A_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_nNdf6Qwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ghxOfvx4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_Xcl5EkmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QLqynGr1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UBhr8ZCV_sendMessage);
}

void Heavy_PhaseRing::cCast_SlEkAsPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ua8QPmGP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_KGjLkXtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_o64KUlOS, 0, m, &cPack_o64KUlOS_sendMessage);
}

void Heavy_PhaseRing::cSend_kUdwllAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_i6PWbdPz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_GrsJuMnv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BX5195QS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_OGSHByfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_GrsJuMnv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_0ZeTaJtL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZVzkeZZ1, 0, m, &cSlice_ZVzkeZZ1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9uFDVHe7, 0, m, &cRandom_9uFDVHe7_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_QiYby3eS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ycRmSjII_sendMessage);
}

void Heavy_PhaseRing::cUnop_ycRmSjII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_Y4a2yXNU_sendMessage);
}

void Heavy_PhaseRing::cRandom_9uFDVHe7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_QiYby3eS_sendMessage);
}

void Heavy_PhaseRing::cSlice_ZVzkeZZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9uFDVHe7, 1, m, &cRandom_9uFDVHe7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_0BBoGpxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvzN3ueB, HV_BINOP_MULTIPLY, 0, m, &cBinop_fvzN3ueB_sendMessage);
}

void Heavy_PhaseRing::cBinop_oxNrA0xW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_iq3vfrTi_sendMessage);
}

void Heavy_PhaseRing::cBinop_iq3vfrTi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oxLnReda, HV_BINOP_POW, 1, m, &cBinop_oxLnReda_sendMessage);
  cMsg_K2wg4h4H_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_oxLnReda_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_0BBoGpxp_sendMessage);
}

void Heavy_PhaseRing::cMsg_K2wg4h4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oxLnReda, HV_BINOP_POW, 0, m, &cBinop_oxLnReda_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_S3xfVUwf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7KXzri4A, 0, m, &cSlice_7KXzri4A_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yK52COJp, 0, m, &cRandom_yK52COJp_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_XZEoD6GX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ygeOi4Eq_sendMessage);
}

void Heavy_PhaseRing::cUnop_ygeOi4Eq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_p5Whw2Jc_sendMessage);
}

void Heavy_PhaseRing::cRandom_yK52COJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_XZEoD6GX_sendMessage);
}

void Heavy_PhaseRing::cSlice_7KXzri4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yK52COJp, 1, m, &cRandom_yK52COJp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_YHMo2vNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lfjulrbb, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_J24FyqzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_GJ9C6GBq_sendMessage);
}

void Heavy_PhaseRing::cVar_bwhleghx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_TwPMNSqD, 0, m);
}

void Heavy_PhaseRing::cVar_NRGE7V5B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_UQlC35Bg, 0, m);
}

void Heavy_PhaseRing::cVar_szQbx5JT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_emL6MVKO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7xynz09i_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iev43YRF_sendMessage);
}

void Heavy_PhaseRing::cCast_rf0GTmHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_BRWseyD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_bJ4Jtvxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_DaU8lEEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_uaynUU9f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_hPHy1r3X_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_hPHy1r3X_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_s1AElv26, 1, m, &cDelay_s1AElv26_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tonoQnv1_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_s1AElv26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_s1AElv26, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZyQ0oJpa, 0, m, &cVar_ZyQ0oJpa_sendMessage);
}

void Heavy_PhaseRing::cMsg_hPHy1r3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_s1AElv26, 0, m, &cDelay_s1AElv26_sendMessage);
}

void Heavy_PhaseRing::cCast_tonoQnv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_s1AElv26, 0, m, &cDelay_s1AElv26_sendMessage);
}

void Heavy_PhaseRing::cVar_ZyQ0oJpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QFQgzg0A_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_pasPJBUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_szQbx5JT, 0, m, &cVar_szQbx5JT_sendMessage);
}

void Heavy_PhaseRing::cMsg_j3e2wCnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_jpu2hyRz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_S94LtOSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_of6LVtxS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_iRWGK0ZI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_uJrvycr6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_DtkGLhP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VozYFjql_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_gx21glYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_gAOvJfnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gWGIIkJO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_jpu2hyRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_of6LVtxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VozYFjql_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_uJrvycr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gWGIIkJO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_HnHvkNLZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_UJQ3qvrt, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_QFQgzg0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_UJQ3qvrt, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_7xynz09i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZyQ0oJpa, 1, m, &cVar_ZyQ0oJpa_sendMessage);
}

void Heavy_PhaseRing::cCast_emL6MVKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HnHvkNLZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_iev43YRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uaynUU9f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_BChErnnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_l2usCjNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wwNwO158, 0, m, &cPack_wwNwO158_sendMessage);
}

void Heavy_PhaseRing::cUnop_R9bQM2bi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_z3tNdwTJ, 0, m, &cPack_z3tNdwTJ_sendMessage);
}

void Heavy_PhaseRing::cPack_z3tNdwTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qcs4NT4o, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_wwNwO158_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_y0iwHJXT, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_WWibXMtB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_l2usCjNZ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_R9bQM2bi_sendMessage);
}

void Heavy_PhaseRing::cMsg_4p9QFS0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_WWibXMtB_sendMessage);
}

void Heavy_PhaseRing::cSlice_7q6wjVzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_4zf8bKo1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_J5uIL2zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7bzayvDA_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_oxNrA0xW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Y4a2yXNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_yngktCjG_sendMessage);
}

void Heavy_PhaseRing::cBinop_yngktCjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_WWibXMtB_sendMessage);
}

void Heavy_PhaseRing::cBinop_4zf8bKo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ps8a5hJk_sendMessage(_c, 0, m);
  cSend_CCtmR16v_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_fvzN3ueB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c2atkUhc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aVsixz8b_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NRGE7V5B, 0, m, &cVar_NRGE7V5B_sendMessage);
}

void Heavy_PhaseRing::cBinop_p5Whw2Jc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_YM7dK5nW_sendMessage);
}

void Heavy_PhaseRing::cBinop_YM7dK5nW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvzN3ueB, HV_BINOP_MULTIPLY, 1, m, &cBinop_fvzN3ueB_sendMessage);
}

void Heavy_PhaseRing::cCast_7bzayvDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_S3xfVUwf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_ps8a5hJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uHKTDtox_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_c2atkUhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pasPJBUx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BChErnnK_sendMessage);
}

void Heavy_PhaseRing::cCast_aVsixz8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0ZeTaJtL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_GJ9C6GBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YHMo2vNL, 0, m, &cPack_YHMo2vNL_sendMessage);
}

void Heavy_PhaseRing::cSend_CCtmR16v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Kcx1vUDc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_p6vlTPqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PwabnvwU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_UYDbhr5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_p6vlTPqJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_54rATUpl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_cQtVbUT4, 0, m, &cSlice_cQtVbUT4_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YHaUr0xV, 0, m, &cRandom_YHaUr0xV_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_WtkQpLlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AwZp4klv_sendMessage);
}

void Heavy_PhaseRing::cUnop_AwZp4klv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_C8gEDFZm_sendMessage);
}

void Heavy_PhaseRing::cRandom_YHaUr0xV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_WtkQpLlH_sendMessage);
}

void Heavy_PhaseRing::cSlice_cQtVbUT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YHaUr0xV, 1, m, &cRandom_YHaUr0xV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_unGbpIre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j5AAeXIe, HV_BINOP_MULTIPLY, 0, m, &cBinop_j5AAeXIe_sendMessage);
}

void Heavy_PhaseRing::cBinop_ehOR1TbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_PVPa3RR3_sendMessage);
}

void Heavy_PhaseRing::cBinop_PVPa3RR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Qm2h2hS, HV_BINOP_POW, 1, m, &cBinop_6Qm2h2hS_sendMessage);
  cMsg_DNcou3yr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_6Qm2h2hS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_unGbpIre_sendMessage);
}

void Heavy_PhaseRing::cMsg_DNcou3yr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Qm2h2hS, HV_BINOP_POW, 0, m, &cBinop_6Qm2h2hS_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_cndbSp0G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jZuuLUwE, 0, m, &cSlice_jZuuLUwE_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8kZph7XC, 0, m, &cRandom_8kZph7XC_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_OcFa4Nib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_u4PfQCNp_sendMessage);
}

void Heavy_PhaseRing::cUnop_u4PfQCNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bI76n6rY_sendMessage);
}

void Heavy_PhaseRing::cRandom_8kZph7XC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_OcFa4Nib_sendMessage);
}

void Heavy_PhaseRing::cSlice_jZuuLUwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8kZph7XC, 1, m, &cRandom_8kZph7XC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_dv0wyXYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ofjH5gHt, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_vVuNcon5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_8yXvZjTW_sendMessage);
}

void Heavy_PhaseRing::cVar_CAQFoj2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Enk7pASw, 0, m);
}

void Heavy_PhaseRing::cVar_pzyCJlEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_klqndxqF, 0, m);
}

void Heavy_PhaseRing::cVar_OQTQGfX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uQ13ojiU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_twzfU9Le_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sD0RTUG8_sendMessage);
}

void Heavy_PhaseRing::cCast_pXrncYYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_rfyPG4fb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_vbXZkDDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_LaQxPMqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_3MF66Xum_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_a1gz0lTW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_a1gz0lTW_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_JfS2bsSp, 1, m, &cDelay_JfS2bsSp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MkQ7NzT2_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_JfS2bsSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JfS2bsSp, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uYPjLKCn, 0, m, &cVar_uYPjLKCn_sendMessage);
}

void Heavy_PhaseRing::cMsg_a1gz0lTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JfS2bsSp, 0, m, &cDelay_JfS2bsSp_sendMessage);
}

void Heavy_PhaseRing::cCast_MkQ7NzT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JfS2bsSp, 0, m, &cDelay_JfS2bsSp_sendMessage);
}

void Heavy_PhaseRing::cVar_uYPjLKCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1Ne8cL6b_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_YLSAaS57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OQTQGfX3, 0, m, &cVar_OQTQGfX3_sendMessage);
}

void Heavy_PhaseRing::cMsg_d9punK7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_5pe8WBen_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_EXqv4cMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_UOR589Ws_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_L2p0G28a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_gxnvqVz1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_RSdCdLAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qqZkRvqp_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_i4NAprGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_9oxNDIBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RViHAS67_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_5pe8WBen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_UOR589Ws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qqZkRvqp_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_gxnvqVz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RViHAS67_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_t0K78W2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3Q9siue6, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_1Ne8cL6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_3Q9siue6, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_twzfU9Le_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uYPjLKCn, 1, m, &cVar_uYPjLKCn_sendMessage);
}

void Heavy_PhaseRing::cCast_uQ13ojiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t0K78W2H_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_sD0RTUG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3MF66Xum_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_EPnljPKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_Ea25WriS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_MHJpUkeH, 0, m, &cPack_MHJpUkeH_sendMessage);
}

void Heavy_PhaseRing::cUnop_L7euAOIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_N7sEgEmo, 0, m, &cPack_N7sEgEmo_sendMessage);
}

void Heavy_PhaseRing::cPack_N7sEgEmo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_SUo3sPnP, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_MHJpUkeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AjhEoLRe, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_b6hHgvLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Ea25WriS_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_L7euAOIp_sendMessage);
}

void Heavy_PhaseRing::cMsg_oOkFnAPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_b6hHgvLA_sendMessage);
}

void Heavy_PhaseRing::cSlice_bhVmhJzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_hjmVC42Y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_dV5FdnHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lYSTEROD_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ehOR1TbI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_C8gEDFZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_D05IiAcI_sendMessage);
}

void Heavy_PhaseRing::cBinop_D05IiAcI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_b6hHgvLA_sendMessage);
}

void Heavy_PhaseRing::cBinop_hjmVC42Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yH4l91Ir_sendMessage(_c, 0, m);
  cSend_OjW07jUa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_j5AAeXIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_acwGljsS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pADdPZcH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pzyCJlEJ, 0, m, &cVar_pzyCJlEJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_bI76n6rY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_u3o2xGzq_sendMessage);
}

void Heavy_PhaseRing::cBinop_u3o2xGzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j5AAeXIe, HV_BINOP_MULTIPLY, 1, m, &cBinop_j5AAeXIe_sendMessage);
}

void Heavy_PhaseRing::cCast_lYSTEROD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cndbSp0G_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_yH4l91Ir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_51U0050o_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_pADdPZcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_54rATUpl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_acwGljsS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YLSAaS57_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EPnljPKd_sendMessage);
}

void Heavy_PhaseRing::cBinop_8yXvZjTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dv0wyXYD, 0, m, &cPack_dv0wyXYD_sendMessage);
}

void Heavy_PhaseRing::cSend_OjW07jUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3Ttddo5N_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_cUniYWly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tCBXysrW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_JYbPUuMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_cUniYWly_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cTabhead_0Fke5nX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XeZ1B0j3, HV_BINOP_SUBTRACT, 0, m, &cBinop_XeZ1B0j3_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ld0BUJ9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JBxtgE5X_sendMessage);
}

void Heavy_PhaseRing::cSystem_JBxtgE5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PLyhwUQ3_sendMessage);
}

void Heavy_PhaseRing::cVar_WvCPrYVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nnwhIpHn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_IgnxSrFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IgnxSrFw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QPiEuzTS, 0, m, &cDelay_QPiEuzTS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ys5s11Pg, 0, m, &sTabread_Ys5s11Pg_sendMessage);
}

void Heavy_PhaseRing::cDelay_QPiEuzTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QPiEuzTS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ys5s11Pg, 0, m, &sTabread_Ys5s11Pg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QPiEuzTS, 0, m, &cDelay_QPiEuzTS_sendMessage);
}

void Heavy_PhaseRing::sTabread_Ys5s11Pg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_J1dAtqij, HV_BINOP_SUBTRACT, 0, m, &cBinop_J1dAtqij_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Od8Gb5uI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cBFrpQZd, HV_BINOP_MAX, 0, m, &cBinop_cBFrpQZd_sendMessage);
}

void Heavy_PhaseRing::cBinop_PLyhwUQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Od8Gb5uI, HV_BINOP_MULTIPLY, 0, m, &cBinop_Od8Gb5uI_sendMessage);
}

void Heavy_PhaseRing::cBinop_XeZ1B0j3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n9wOl64J_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ys5s11Pg, 0, m, &sTabread_Ys5s11Pg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RswlFY8I_sendMessage);
}

void Heavy_PhaseRing::cSystem_QGdQWykw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J1dAtqij, HV_BINOP_SUBTRACT, 1, m, &cBinop_J1dAtqij_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QPiEuzTS, 2, m, &cDelay_QPiEuzTS_sendMessage);
}

void Heavy_PhaseRing::cMsg_nnwhIpHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QGdQWykw_sendMessage);
}

void Heavy_PhaseRing::cMsg_n9wOl64J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IgnxSrFw, 0, m, &cDelay_IgnxSrFw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QPiEuzTS, 0, m, &cDelay_QPiEuzTS_sendMessage);
}

void Heavy_PhaseRing::cMsg_BVB4vcBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cBFrpQZd, HV_BINOP_MAX, 1, m, &cBinop_cBFrpQZd_sendMessage);
}

void Heavy_PhaseRing::cBinop_cBFrpQZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XeZ1B0j3, HV_BINOP_SUBTRACT, 1, m, &cBinop_XeZ1B0j3_sendMessage);
}

void Heavy_PhaseRing::cCast_RswlFY8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IgnxSrFw, 0, m, &cDelay_IgnxSrFw_sendMessage);
}

void Heavy_PhaseRing::cBinop_EQqOJSpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IgnxSrFw, 2, m, &cDelay_IgnxSrFw_sendMessage);
}

void Heavy_PhaseRing::cBinop_J1dAtqij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EQqOJSpQ_sendMessage);
}

void Heavy_PhaseRing::cCast_1opSwSgR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WvCPrYVT, 0, m, &cVar_WvCPrYVT_sendMessage);
  cMsg_Ld0BUJ9J_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_0Fke5nX6, 0, m, &cTabhead_0Fke5nX6_sendMessage);
}

void Heavy_PhaseRing::cTabhead_ZYDBgI6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kdbLKXPB, HV_BINOP_SUBTRACT, 0, m, &cBinop_kdbLKXPB_sendMessage);
}

void Heavy_PhaseRing::cMsg_PeemXUce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v2gukGw3_sendMessage);
}

void Heavy_PhaseRing::cSystem_v2gukGw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_N2UREQXV_sendMessage);
}

void Heavy_PhaseRing::cVar_dOnx3kV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RFoguxmh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_geou72Zr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_geou72Zr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pbEXgWCS, 0, m, &cDelay_pbEXgWCS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cUvUR4dE, 0, m, &sTabread_cUvUR4dE_sendMessage);
}

void Heavy_PhaseRing::cDelay_pbEXgWCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pbEXgWCS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cUvUR4dE, 0, m, &sTabread_cUvUR4dE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pbEXgWCS, 0, m, &cDelay_pbEXgWCS_sendMessage);
}

void Heavy_PhaseRing::sTabread_cUvUR4dE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_CKjh4tHs, HV_BINOP_SUBTRACT, 0, m, &cBinop_CKjh4tHs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_G7EaGEEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p435uMVj, HV_BINOP_MAX, 0, m, &cBinop_p435uMVj_sendMessage);
}

void Heavy_PhaseRing::cBinop_N2UREQXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G7EaGEEP, HV_BINOP_MULTIPLY, 0, m, &cBinop_G7EaGEEP_sendMessage);
}

void Heavy_PhaseRing::cBinop_kdbLKXPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0fhGzdHH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cUvUR4dE, 0, m, &sTabread_cUvUR4dE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tzSLSy42_sendMessage);
}

void Heavy_PhaseRing::cSystem_m4vGnoGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CKjh4tHs, HV_BINOP_SUBTRACT, 1, m, &cBinop_CKjh4tHs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pbEXgWCS, 2, m, &cDelay_pbEXgWCS_sendMessage);
}

void Heavy_PhaseRing::cMsg_RFoguxmh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m4vGnoGs_sendMessage);
}

void Heavy_PhaseRing::cMsg_0fhGzdHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_geou72Zr, 0, m, &cDelay_geou72Zr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pbEXgWCS, 0, m, &cDelay_pbEXgWCS_sendMessage);
}

void Heavy_PhaseRing::cMsg_R3RO4Wty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_p435uMVj, HV_BINOP_MAX, 1, m, &cBinop_p435uMVj_sendMessage);
}

void Heavy_PhaseRing::cBinop_p435uMVj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kdbLKXPB, HV_BINOP_SUBTRACT, 1, m, &cBinop_kdbLKXPB_sendMessage);
}

void Heavy_PhaseRing::cCast_tzSLSy42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_geou72Zr, 0, m, &cDelay_geou72Zr_sendMessage);
}

void Heavy_PhaseRing::cBinop_Spp0wYzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_geou72Zr, 2, m, &cDelay_geou72Zr_sendMessage);
}

void Heavy_PhaseRing::cBinop_CKjh4tHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Spp0wYzD_sendMessage);
}

void Heavy_PhaseRing::cCast_NfYf96Zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dOnx3kV9, 0, m, &cVar_dOnx3kV9_sendMessage);
  cMsg_PeemXUce_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZYDBgI6J, 0, m, &cTabhead_ZYDBgI6J_sendMessage);
}

void Heavy_PhaseRing::cTabhead_jLPJ7Rox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QBUhAdl0, HV_BINOP_SUBTRACT, 0, m, &cBinop_QBUhAdl0_sendMessage);
}

void Heavy_PhaseRing::cMsg_hAwFeOm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BM0X2rfF_sendMessage);
}

void Heavy_PhaseRing::cSystem_BM0X2rfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LzqsgOgP_sendMessage);
}

void Heavy_PhaseRing::cVar_jc3BiXZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ab9cGnLw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_4NETi1iS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4NETi1iS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cnM0Het2, 0, m, &cDelay_cnM0Het2_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RR5kdm1K, 0, m, &sTabread_RR5kdm1K_sendMessage);
}

void Heavy_PhaseRing::cDelay_cnM0Het2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cnM0Het2, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RR5kdm1K, 0, m, &sTabread_RR5kdm1K_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cnM0Het2, 0, m, &cDelay_cnM0Het2_sendMessage);
}

void Heavy_PhaseRing::sTabread_RR5kdm1K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NJQHJi2W, HV_BINOP_SUBTRACT, 0, m, &cBinop_NJQHJi2W_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_V5Ns1Rao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hleNuWc1, HV_BINOP_MAX, 0, m, &cBinop_hleNuWc1_sendMessage);
}

void Heavy_PhaseRing::cBinop_LzqsgOgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V5Ns1Rao, HV_BINOP_MULTIPLY, 0, m, &cBinop_V5Ns1Rao_sendMessage);
}

void Heavy_PhaseRing::cBinop_QBUhAdl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5N7koRks_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RR5kdm1K, 0, m, &sTabread_RR5kdm1K_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GcAcoi6f_sendMessage);
}

void Heavy_PhaseRing::cSystem_3WI1YleX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NJQHJi2W, HV_BINOP_SUBTRACT, 1, m, &cBinop_NJQHJi2W_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cnM0Het2, 2, m, &cDelay_cnM0Het2_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ab9cGnLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3WI1YleX_sendMessage);
}

void Heavy_PhaseRing::cMsg_5N7koRks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_4NETi1iS, 0, m, &cDelay_4NETi1iS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cnM0Het2, 0, m, &cDelay_cnM0Het2_sendMessage);
}

void Heavy_PhaseRing::cMsg_y15tfJze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_hleNuWc1, HV_BINOP_MAX, 1, m, &cBinop_hleNuWc1_sendMessage);
}

void Heavy_PhaseRing::cBinop_hleNuWc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QBUhAdl0, HV_BINOP_SUBTRACT, 1, m, &cBinop_QBUhAdl0_sendMessage);
}

void Heavy_PhaseRing::cCast_GcAcoi6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4NETi1iS, 0, m, &cDelay_4NETi1iS_sendMessage);
}

void Heavy_PhaseRing::cBinop_kCAcvST2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4NETi1iS, 2, m, &cDelay_4NETi1iS_sendMessage);
}

void Heavy_PhaseRing::cBinop_NJQHJi2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kCAcvST2_sendMessage);
}

void Heavy_PhaseRing::cCast_wnpScVa9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jc3BiXZR, 0, m, &cVar_jc3BiXZR_sendMessage);
  cMsg_hAwFeOm3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jLPJ7Rox, 0, m, &cTabhead_jLPJ7Rox_sendMessage);
}

void Heavy_PhaseRing::cTabhead_3HAxw8TX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QFvEQ7uF, HV_BINOP_SUBTRACT, 0, m, &cBinop_QFvEQ7uF_sendMessage);
}

void Heavy_PhaseRing::cMsg_lGfvx6Wn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8ARFmwiv_sendMessage);
}

void Heavy_PhaseRing::cSystem_8ARFmwiv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_D2ytNelj_sendMessage);
}

void Heavy_PhaseRing::cVar_9WpELT9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fakUYzs6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_38U5jP1j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_38U5jP1j, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iADLw9Wa, 0, m, &cDelay_iADLw9Wa_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_K67nHFvW, 0, m, &sTabread_K67nHFvW_sendMessage);
}

void Heavy_PhaseRing::cDelay_iADLw9Wa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iADLw9Wa, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_K67nHFvW, 0, m, &sTabread_K67nHFvW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iADLw9Wa, 0, m, &cDelay_iADLw9Wa_sendMessage);
}

void Heavy_PhaseRing::sTabread_K67nHFvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_j5g9oZRg, HV_BINOP_SUBTRACT, 0, m, &cBinop_j5g9oZRg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_mmU8fmuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TZyMXI3T, HV_BINOP_MAX, 0, m, &cBinop_TZyMXI3T_sendMessage);
}

void Heavy_PhaseRing::cBinop_D2ytNelj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mmU8fmuD, HV_BINOP_MULTIPLY, 0, m, &cBinop_mmU8fmuD_sendMessage);
}

void Heavy_PhaseRing::cBinop_QFvEQ7uF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iWPFNE7E_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_K67nHFvW, 0, m, &sTabread_K67nHFvW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bOPjxGHA_sendMessage);
}

void Heavy_PhaseRing::cSystem_esZGjRGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j5g9oZRg, HV_BINOP_SUBTRACT, 1, m, &cBinop_j5g9oZRg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iADLw9Wa, 2, m, &cDelay_iADLw9Wa_sendMessage);
}

void Heavy_PhaseRing::cMsg_fakUYzs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_esZGjRGY_sendMessage);
}

void Heavy_PhaseRing::cMsg_iWPFNE7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_38U5jP1j, 0, m, &cDelay_38U5jP1j_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iADLw9Wa, 0, m, &cDelay_iADLw9Wa_sendMessage);
}

void Heavy_PhaseRing::cMsg_FniwRk4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_TZyMXI3T, HV_BINOP_MAX, 1, m, &cBinop_TZyMXI3T_sendMessage);
}

void Heavy_PhaseRing::cBinop_TZyMXI3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QFvEQ7uF, HV_BINOP_SUBTRACT, 1, m, &cBinop_QFvEQ7uF_sendMessage);
}

void Heavy_PhaseRing::cCast_bOPjxGHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_38U5jP1j, 0, m, &cDelay_38U5jP1j_sendMessage);
}

void Heavy_PhaseRing::cBinop_1rO6s9fM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_38U5jP1j, 2, m, &cDelay_38U5jP1j_sendMessage);
}

void Heavy_PhaseRing::cBinop_j5g9oZRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1rO6s9fM_sendMessage);
}

void Heavy_PhaseRing::cCast_e7fTzjRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9WpELT9g, 0, m, &cVar_9WpELT9g_sendMessage);
  cMsg_lGfvx6Wn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3HAxw8TX, 0, m, &cTabhead_3HAxw8TX_sendMessage);
}

void Heavy_PhaseRing::cMsg_DfeiofMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WnjO7Z2L_sendMessage);
}

void Heavy_PhaseRing::cSystem_WnjO7Z2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_D5pm3Lof_sendMessage);
}

void Heavy_PhaseRing::cDelay_Qg28wfPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Qg28wfPc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ZiwyqQC, 0, m, &cDelay_8ZiwyqQC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qg28wfPc, 0, m, &cDelay_Qg28wfPc_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_O0xU8mRH, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_8ZiwyqQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8ZiwyqQC, m);
  cMsg_rc9BX7l6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_sGn3nzbF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_QPDzzSCw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_6dnsmyBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gAPgTmU3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_zghthmB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YkxRDnoY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qg28wfPc, 2, m, &cDelay_Qg28wfPc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NVJ6kYAF_sendMessage);
}

void Heavy_PhaseRing::cMsg_gAPgTmU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_zghthmB7, 0, m, &hTable_zghthmB7_sendMessage);
}

void Heavy_PhaseRing::cBinop_D5pm3Lof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_6dnsmyBP_sendMessage);
}

void Heavy_PhaseRing::cMsg_rc9BX7l6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_zghthmB7, 0, m, &hTable_zghthmB7_sendMessage);
}

void Heavy_PhaseRing::cCast_NVJ6kYAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qg28wfPc, 0, m, &cDelay_Qg28wfPc_sendMessage);
}

void Heavy_PhaseRing::cMsg_YkxRDnoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ZiwyqQC, 2, m, &cDelay_8ZiwyqQC_sendMessage);
}

void Heavy_PhaseRing::cMsg_QPDzzSCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_O0xU8mRH, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_aSRhFih8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BfYpCwqZ_sendMessage);
}

void Heavy_PhaseRing::cSystem_BfYpCwqZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_l7AilmyA_sendMessage);
}

void Heavy_PhaseRing::cDelay_7G5xGPKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7G5xGPKl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2sDqRWxl, 0, m, &cDelay_2sDqRWxl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7G5xGPKl, 0, m, &cDelay_7G5xGPKl_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mJYYDbnn, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_2sDqRWxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2sDqRWxl, m);
  cMsg_9xymckRX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_vyGZqAV6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_AyBylTuT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_eSP1nUMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EqQdOqGk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_nalEOYMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6aJQGgeo_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7G5xGPKl, 2, m, &cDelay_7G5xGPKl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EwlOx2V7_sendMessage);
}

void Heavy_PhaseRing::cMsg_EqQdOqGk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_nalEOYMq, 0, m, &hTable_nalEOYMq_sendMessage);
}

void Heavy_PhaseRing::cBinop_l7AilmyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_eSP1nUMC_sendMessage);
}

void Heavy_PhaseRing::cMsg_9xymckRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_nalEOYMq, 0, m, &hTable_nalEOYMq_sendMessage);
}

void Heavy_PhaseRing::cCast_EwlOx2V7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7G5xGPKl, 0, m, &cDelay_7G5xGPKl_sendMessage);
}

void Heavy_PhaseRing::cMsg_6aJQGgeo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2sDqRWxl, 2, m, &cDelay_2sDqRWxl_sendMessage);
}

void Heavy_PhaseRing::cMsg_AyBylTuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mJYYDbnn, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_KNb6jO5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_o7DLUt4C_sendMessage);
}

void Heavy_PhaseRing::cSystem_o7DLUt4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TKG5l0V0_sendMessage);
}

void Heavy_PhaseRing::cDelay_7ezXWCla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7ezXWCla, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ej3O4ieo, 0, m, &cDelay_ej3O4ieo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7ezXWCla, 0, m, &cDelay_7ezXWCla_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dCTeVU8K, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_ej3O4ieo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ej3O4ieo, m);
  cMsg_mkksK2B6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_DMjjMoGv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_QmtSiaHX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_QbJL0gMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yZrISCoR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_OcmXYXCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HtQdyVz8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7ezXWCla, 2, m, &cDelay_7ezXWCla_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GsteeU4q_sendMessage);
}

void Heavy_PhaseRing::cMsg_yZrISCoR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_OcmXYXCS, 0, m, &hTable_OcmXYXCS_sendMessage);
}

void Heavy_PhaseRing::cBinop_TKG5l0V0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_QbJL0gMr_sendMessage);
}

void Heavy_PhaseRing::cMsg_mkksK2B6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_OcmXYXCS, 0, m, &hTable_OcmXYXCS_sendMessage);
}

void Heavy_PhaseRing::cCast_GsteeU4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7ezXWCla, 0, m, &cDelay_7ezXWCla_sendMessage);
}

void Heavy_PhaseRing::cMsg_HtQdyVz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ej3O4ieo, 2, m, &cDelay_ej3O4ieo_sendMessage);
}

void Heavy_PhaseRing::cMsg_QmtSiaHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dCTeVU8K, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_IIgSmFxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Gix5EQBI_sendMessage);
}

void Heavy_PhaseRing::cSystem_Gix5EQBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VG7zaaf1_sendMessage);
}

void Heavy_PhaseRing::cDelay_Ok992P7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ok992P7Z, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UGGdVog3, 0, m, &cDelay_UGGdVog3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ok992P7Z, 0, m, &cDelay_Ok992P7Z_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HyokTsKa, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_UGGdVog3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UGGdVog3, m);
  cMsg_8D3Af1T7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_xqenj2XW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Ol4Qs79M_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_Pi0yhNAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iff4MJps_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_SjPHX9Gv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PNlhBdcE_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ok992P7Z, 2, m, &cDelay_Ok992P7Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZkMDeiVU_sendMessage);
}

void Heavy_PhaseRing::cMsg_iff4MJps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_SjPHX9Gv, 0, m, &hTable_SjPHX9Gv_sendMessage);
}

void Heavy_PhaseRing::cBinop_VG7zaaf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_Pi0yhNAB_sendMessage);
}

void Heavy_PhaseRing::cMsg_8D3Af1T7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_SjPHX9Gv, 0, m, &hTable_SjPHX9Gv_sendMessage);
}

void Heavy_PhaseRing::cCast_ZkMDeiVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ok992P7Z, 0, m, &cDelay_Ok992P7Z_sendMessage);
}

void Heavy_PhaseRing::cMsg_PNlhBdcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_UGGdVog3, 2, m, &cDelay_UGGdVog3_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ol4Qs79M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HyokTsKa, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_b9uOHWLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_PukIu6VZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_BmLm9Tyu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_AFqr29Uj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UNBjwgJA, HV_BINOP_POW, 0, m, &cBinop_UNBjwgJA_sendMessage);
}

void Heavy_PhaseRing::cBinop_UNBjwgJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_UPyVhisQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_N6kKKOHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_c50jx3vi_sendMessage);
}

void Heavy_PhaseRing::cCast_XAsUDycb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_XnFFcnTs_sendMessage);
}

void Heavy_PhaseRing::cCast_fDkXp21l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b9uOHWLM, 0, m, &cIf_b9uOHWLM_sendMessage);
}

void Heavy_PhaseRing::cBinop_XnFFcnTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b9uOHWLM, 1, m, &cIf_b9uOHWLM_sendMessage);
}

void Heavy_PhaseRing::cBinop_BmLm9Tyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_N6kKKOHd_sendMessage);
}

void Heavy_PhaseRing::cMsg_PukIu6VZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_UPyVhisQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_c50jx3vi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UNBjwgJA, HV_BINOP_POW, 1, m, &cBinop_UNBjwgJA_sendMessage);
  cMsg_AFqr29Uj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_JaZ3eDOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_v5yKaspP, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_4Jz7rgcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5hAnulJB, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_hA9H42NJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QsevMRD6_sendMessage);
}

void Heavy_PhaseRing::cBinop_QsevMRD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_TGGcpe1T_sendMessage);
}

void Heavy_PhaseRing::cVar_NMEJtwwS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UTAO3DIz, HV_BINOP_MULTIPLY, 0, m, &cBinop_UTAO3DIz_sendMessage);
}

void Heavy_PhaseRing::cMsg_5Dbq1qTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uZo8UH20_sendMessage);
}

void Heavy_PhaseRing::cSystem_uZo8UH20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XhEuRjFB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_UTAO3DIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_tdPPfqH6_sendMessage);
}

void Heavy_PhaseRing::cBinop_7O5XlSaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UTAO3DIz, HV_BINOP_MULTIPLY, 1, m, &cBinop_UTAO3DIz_sendMessage);
}

void Heavy_PhaseRing::cMsg_XhEuRjFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7O5XlSaG_sendMessage);
}

void Heavy_PhaseRing::cBinop_tdPPfqH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zFH3k8an_sendMessage);
}

void Heavy_PhaseRing::cBinop_zFH3k8an_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_B1CbJfdd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_80zhOBzS, m);
}

void Heavy_PhaseRing::cBinop_B1CbJfdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SW07rReW, m);
}

void Heavy_PhaseRing::cVar_zIBaPinP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XAsUDycb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fDkXp21l_sendMessage);
}

void Heavy_PhaseRing::cVar_tdEnmbEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_hA9H42NJ_sendMessage);
}

void Heavy_PhaseRing::cVar_vHcevg4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_2YlHv0Ro_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_PcBwtAKv, 0, m, &cIf_PcBwtAKv_sendMessage);
}

void Heavy_PhaseRing::cVar_1E0CcgIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_p1ymImqf_sendMessage);
}

void Heavy_PhaseRing::cIf_PcBwtAKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_23rmWSzO_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Cdv4cOqi, 0, m, &cVar_Cdv4cOqi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_2YlHv0Ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PcBwtAKv, 1, m, &cIf_PcBwtAKv_sendMessage);
}

void Heavy_PhaseRing::cBinop_p1ymImqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6N4rWCPJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_6N4rWCPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bMD4OnpX, 0, m, &cVar_bMD4OnpX_sendMessage);
}

void Heavy_PhaseRing::cTabhead_FHyNMIDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YI7jofVs, HV_BINOP_SUBTRACT, 0, m, &cBinop_YI7jofVs_sendMessage);
}

void Heavy_PhaseRing::cMsg_FUvSKUwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zzzizZuq_sendMessage);
}

void Heavy_PhaseRing::cSystem_zzzizZuq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AErpLfgh_sendMessage);
}

void Heavy_PhaseRing::cVar_YrZxt1rh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_enaKkCfV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_rs0ZI53N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rs0ZI53N, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sg0nENxn, 0, m, &cDelay_sg0nENxn_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qj0gKYka, 0, m, &sTabread_qj0gKYka_sendMessage);
}

void Heavy_PhaseRing::cDelay_sg0nENxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sg0nENxn, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qj0gKYka, 0, m, &sTabread_qj0gKYka_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sg0nENxn, 0, m, &cDelay_sg0nENxn_sendMessage);
}

void Heavy_PhaseRing::sTabread_qj0gKYka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gwfFXcxv, HV_BINOP_SUBTRACT, 0, m, &cBinop_gwfFXcxv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_fojkmdtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DpzjsUUJ, HV_BINOP_MAX, 0, m, &cBinop_DpzjsUUJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_AErpLfgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fojkmdtD, HV_BINOP_MULTIPLY, 0, m, &cBinop_fojkmdtD_sendMessage);
}

void Heavy_PhaseRing::cBinop_YI7jofVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gcoJiC2Q_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qj0gKYka, 0, m, &sTabread_qj0gKYka_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BPsBaNix_sendMessage);
}

void Heavy_PhaseRing::cSystem_iwTrOgw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gwfFXcxv, HV_BINOP_SUBTRACT, 1, m, &cBinop_gwfFXcxv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sg0nENxn, 2, m, &cDelay_sg0nENxn_sendMessage);
}

void Heavy_PhaseRing::cMsg_enaKkCfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iwTrOgw3_sendMessage);
}

void Heavy_PhaseRing::cMsg_gcoJiC2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rs0ZI53N, 0, m, &cDelay_rs0ZI53N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sg0nENxn, 0, m, &cDelay_sg0nENxn_sendMessage);
}

void Heavy_PhaseRing::cMsg_zuJrmDae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_DpzjsUUJ, HV_BINOP_MAX, 1, m, &cBinop_DpzjsUUJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_DpzjsUUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YI7jofVs, HV_BINOP_SUBTRACT, 1, m, &cBinop_YI7jofVs_sendMessage);
}

void Heavy_PhaseRing::cCast_BPsBaNix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rs0ZI53N, 0, m, &cDelay_rs0ZI53N_sendMessage);
}

void Heavy_PhaseRing::cBinop_HuUK1Nul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rs0ZI53N, 2, m, &cDelay_rs0ZI53N_sendMessage);
}

void Heavy_PhaseRing::cBinop_gwfFXcxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HuUK1Nul_sendMessage);
}

void Heavy_PhaseRing::cCast_FMbjTt8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YrZxt1rh, 0, m, &cVar_YrZxt1rh_sendMessage);
  cMsg_FUvSKUwO_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_FHyNMIDU, 0, m, &cTabhead_FHyNMIDU_sendMessage);
}

void Heavy_PhaseRing::cMsg_HdcXoiK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SNeqcFbh_sendMessage);
}

void Heavy_PhaseRing::cSystem_SNeqcFbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QsutHN50_sendMessage);
}

void Heavy_PhaseRing::cDelay_WED2CAam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WED2CAam, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2LsYZIZ1, 0, m, &cDelay_2LsYZIZ1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WED2CAam, 0, m, &cDelay_WED2CAam_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_j3FCvULD, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_2LsYZIZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2LsYZIZ1, m);
  cMsg_8TqJanvS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_SCehsxO4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_dpmI42JT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_VT7vSRZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7J7Nd8PO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_ua2isCjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fAbpgBDU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WED2CAam, 2, m, &cDelay_WED2CAam_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l8XDjSy9_sendMessage);
}

void Heavy_PhaseRing::cMsg_7J7Nd8PO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ua2isCjv, 0, m, &hTable_ua2isCjv_sendMessage);
}

void Heavy_PhaseRing::cBinop_QsutHN50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_VT7vSRZT_sendMessage);
}

void Heavy_PhaseRing::cMsg_8TqJanvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ua2isCjv, 0, m, &hTable_ua2isCjv_sendMessage);
}

void Heavy_PhaseRing::cCast_l8XDjSy9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WED2CAam, 0, m, &cDelay_WED2CAam_sendMessage);
}

void Heavy_PhaseRing::cMsg_fAbpgBDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2LsYZIZ1, 2, m, &cDelay_2LsYZIZ1_sendMessage);
}

void Heavy_PhaseRing::cMsg_dpmI42JT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_j3FCvULD, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_FOJj7uQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dJY8djhW, HV_BINOP_SUBTRACT, 0, m, &cBinop_dJY8djhW_sendMessage);
}

void Heavy_PhaseRing::cMsg_BBlr8m3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_q4BRBC62_sendMessage);
}

void Heavy_PhaseRing::cSystem_q4BRBC62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XR4LxDEG_sendMessage);
}

void Heavy_PhaseRing::cVar_ha1m79M0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iMAr6QHQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_w7TRfqmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_w7TRfqmS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k02NmOhH, 0, m, &cDelay_k02NmOhH_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qbwrOpHv, 0, m, &sTabread_qbwrOpHv_sendMessage);
}

void Heavy_PhaseRing::cDelay_k02NmOhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_k02NmOhH, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qbwrOpHv, 0, m, &sTabread_qbwrOpHv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k02NmOhH, 0, m, &cDelay_k02NmOhH_sendMessage);
}

void Heavy_PhaseRing::sTabread_qbwrOpHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ocW9cRuy, HV_BINOP_SUBTRACT, 0, m, &cBinop_ocW9cRuy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_1fYu0Cxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9hxgt79H, HV_BINOP_MAX, 0, m, &cBinop_9hxgt79H_sendMessage);
}

void Heavy_PhaseRing::cBinop_XR4LxDEG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1fYu0Cxb, HV_BINOP_MULTIPLY, 0, m, &cBinop_1fYu0Cxb_sendMessage);
}

void Heavy_PhaseRing::cBinop_dJY8djhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TR4OABlO_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qbwrOpHv, 0, m, &sTabread_qbwrOpHv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uhRYwL2T_sendMessage);
}

void Heavy_PhaseRing::cSystem_qBkSDnwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ocW9cRuy, HV_BINOP_SUBTRACT, 1, m, &cBinop_ocW9cRuy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k02NmOhH, 2, m, &cDelay_k02NmOhH_sendMessage);
}

void Heavy_PhaseRing::cMsg_iMAr6QHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qBkSDnwL_sendMessage);
}

void Heavy_PhaseRing::cMsg_TR4OABlO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_w7TRfqmS, 0, m, &cDelay_w7TRfqmS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k02NmOhH, 0, m, &cDelay_k02NmOhH_sendMessage);
}

void Heavy_PhaseRing::cMsg_LdyWds04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9hxgt79H, HV_BINOP_MAX, 1, m, &cBinop_9hxgt79H_sendMessage);
}

void Heavy_PhaseRing::cBinop_9hxgt79H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dJY8djhW, HV_BINOP_SUBTRACT, 1, m, &cBinop_dJY8djhW_sendMessage);
}

void Heavy_PhaseRing::cCast_uhRYwL2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_w7TRfqmS, 0, m, &cDelay_w7TRfqmS_sendMessage);
}

void Heavy_PhaseRing::cBinop_r1KaPFSK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_w7TRfqmS, 2, m, &cDelay_w7TRfqmS_sendMessage);
}

void Heavy_PhaseRing::cBinop_ocW9cRuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_r1KaPFSK_sendMessage);
}

void Heavy_PhaseRing::cCast_CtRqg10a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ha1m79M0, 0, m, &cVar_ha1m79M0_sendMessage);
  cMsg_BBlr8m3V_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_FOJj7uQb, 0, m, &cTabhead_FOJj7uQb_sendMessage);
}

void Heavy_PhaseRing::cMsg_RyrY1Ry7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TiD9dCuR_sendMessage);
}

void Heavy_PhaseRing::cSystem_TiD9dCuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_w0WnnLsf_sendMessage);
}

void Heavy_PhaseRing::cDelay_VE8lOCJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VE8lOCJz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kTPQJB8T, 0, m, &cDelay_kTPQJB8T_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VE8lOCJz, 0, m, &cDelay_VE8lOCJz_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_A06E13j1, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_kTPQJB8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kTPQJB8T, m);
  cMsg_FGqJTM42_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Cy9Xdjnv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_CBWmUgwy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ArMPB4re_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mPJDQ8rt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_IJIcP0va_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BpSsHtDP_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VE8lOCJz, 2, m, &cDelay_VE8lOCJz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Vn1y7tOa_sendMessage);
}

void Heavy_PhaseRing::cMsg_mPJDQ8rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_IJIcP0va, 0, m, &hTable_IJIcP0va_sendMessage);
}

void Heavy_PhaseRing::cBinop_w0WnnLsf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_ArMPB4re_sendMessage);
}

void Heavy_PhaseRing::cMsg_FGqJTM42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_IJIcP0va, 0, m, &hTable_IJIcP0va_sendMessage);
}

void Heavy_PhaseRing::cCast_Vn1y7tOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VE8lOCJz, 0, m, &cDelay_VE8lOCJz_sendMessage);
}

void Heavy_PhaseRing::cMsg_BpSsHtDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kTPQJB8T, 2, m, &cDelay_kTPQJB8T_sendMessage);
}

void Heavy_PhaseRing::cMsg_CBWmUgwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_A06E13j1, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_nytT6jlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ghNnoeZh, HV_BINOP_SUBTRACT, 0, m, &cBinop_ghNnoeZh_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ww83srei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RnQWXGGf_sendMessage);
}

void Heavy_PhaseRing::cSystem_RnQWXGGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Zq04uym7_sendMessage);
}

void Heavy_PhaseRing::cVar_gRq60mBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BHGf6UDy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_pqpvpTwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pqpvpTwe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7BhEE3ah, 0, m, &cDelay_7BhEE3ah_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_QLTQYVNM, 0, m, &sTabread_QLTQYVNM_sendMessage);
}

void Heavy_PhaseRing::cDelay_7BhEE3ah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7BhEE3ah, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_QLTQYVNM, 0, m, &sTabread_QLTQYVNM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7BhEE3ah, 0, m, &cDelay_7BhEE3ah_sendMessage);
}

void Heavy_PhaseRing::sTabread_QLTQYVNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mGrvInav, HV_BINOP_SUBTRACT, 0, m, &cBinop_mGrvInav_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_SXxYBNIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3B1bZibQ, HV_BINOP_MAX, 0, m, &cBinop_3B1bZibQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_Zq04uym7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SXxYBNIe, HV_BINOP_MULTIPLY, 0, m, &cBinop_SXxYBNIe_sendMessage);
}

void Heavy_PhaseRing::cBinop_ghNnoeZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u0J7L4JH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_QLTQYVNM, 0, m, &sTabread_QLTQYVNM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fmzqc5Fv_sendMessage);
}

void Heavy_PhaseRing::cSystem_EvYZjjhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mGrvInav, HV_BINOP_SUBTRACT, 1, m, &cBinop_mGrvInav_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7BhEE3ah, 2, m, &cDelay_7BhEE3ah_sendMessage);
}

void Heavy_PhaseRing::cMsg_BHGf6UDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EvYZjjhq_sendMessage);
}

void Heavy_PhaseRing::cMsg_u0J7L4JH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pqpvpTwe, 0, m, &cDelay_pqpvpTwe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7BhEE3ah, 0, m, &cDelay_7BhEE3ah_sendMessage);
}

void Heavy_PhaseRing::cMsg_FRAwHzK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_3B1bZibQ, HV_BINOP_MAX, 1, m, &cBinop_3B1bZibQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_3B1bZibQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ghNnoeZh, HV_BINOP_SUBTRACT, 1, m, &cBinop_ghNnoeZh_sendMessage);
}

void Heavy_PhaseRing::cCast_fmzqc5Fv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pqpvpTwe, 0, m, &cDelay_pqpvpTwe_sendMessage);
}

void Heavy_PhaseRing::cBinop_OPW6lWsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pqpvpTwe, 2, m, &cDelay_pqpvpTwe_sendMessage);
}

void Heavy_PhaseRing::cBinop_mGrvInav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OPW6lWsX_sendMessage);
}

void Heavy_PhaseRing::cCast_8tG4xXqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gRq60mBs, 0, m, &cVar_gRq60mBs_sendMessage);
  cMsg_Ww83srei_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nytT6jlV, 0, m, &cTabhead_nytT6jlV_sendMessage);
}

void Heavy_PhaseRing::cMsg_d0CdqYvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MAtFB8OH_sendMessage);
}

void Heavy_PhaseRing::cSystem_MAtFB8OH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1aM84s8l_sendMessage);
}

void Heavy_PhaseRing::cDelay_nxc8hsgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nxc8hsgb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_i7rKHIQo, 0, m, &cDelay_i7rKHIQo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nxc8hsgb, 0, m, &cDelay_nxc8hsgb_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mfFAEgqr, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_i7rKHIQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_i7rKHIQo, m);
  cMsg_hWNIFg0B_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_FVm94phX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_gQ2ghVSA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_KzpU4NZV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V5oq3Qfq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_LbWYVZB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1H19VLAj_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nxc8hsgb, 2, m, &cDelay_nxc8hsgb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yrui3WmZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_V5oq3Qfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_LbWYVZB4, 0, m, &hTable_LbWYVZB4_sendMessage);
}

void Heavy_PhaseRing::cBinop_1aM84s8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_KzpU4NZV_sendMessage);
}

void Heavy_PhaseRing::cMsg_hWNIFg0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_LbWYVZB4, 0, m, &hTable_LbWYVZB4_sendMessage);
}

void Heavy_PhaseRing::cCast_yrui3WmZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nxc8hsgb, 0, m, &cDelay_nxc8hsgb_sendMessage);
}

void Heavy_PhaseRing::cMsg_1H19VLAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_i7rKHIQo, 2, m, &cDelay_i7rKHIQo_sendMessage);
}

void Heavy_PhaseRing::cMsg_gQ2ghVSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mfFAEgqr, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_psfVSoyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ou54OYx1, HV_BINOP_SUBTRACT, 0, m, &cBinop_ou54OYx1_sendMessage);
}

void Heavy_PhaseRing::cMsg_cHHfHK6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PBBzocsX_sendMessage);
}

void Heavy_PhaseRing::cSystem_PBBzocsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VJC1aKs8_sendMessage);
}

void Heavy_PhaseRing::cVar_2xQG8E27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6IhsKVGJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_KR4SJEvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KR4SJEvk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9xNRa14F, 0, m, &cDelay_9xNRa14F_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u0oJipNF, 0, m, &sTabread_u0oJipNF_sendMessage);
}

void Heavy_PhaseRing::cDelay_9xNRa14F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9xNRa14F, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u0oJipNF, 0, m, &sTabread_u0oJipNF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9xNRa14F, 0, m, &cDelay_9xNRa14F_sendMessage);
}

void Heavy_PhaseRing::sTabread_u0oJipNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_VCWpGUhD, HV_BINOP_SUBTRACT, 0, m, &cBinop_VCWpGUhD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_4XhwcMR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rAd7lEnx, HV_BINOP_MAX, 0, m, &cBinop_rAd7lEnx_sendMessage);
}

void Heavy_PhaseRing::cBinop_VJC1aKs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4XhwcMR0, HV_BINOP_MULTIPLY, 0, m, &cBinop_4XhwcMR0_sendMessage);
}

void Heavy_PhaseRing::cBinop_ou54OYx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Xq9FibJG_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u0oJipNF, 0, m, &sTabread_u0oJipNF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YsV5hjeM_sendMessage);
}

void Heavy_PhaseRing::cSystem_1P1CHV5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VCWpGUhD, HV_BINOP_SUBTRACT, 1, m, &cBinop_VCWpGUhD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9xNRa14F, 2, m, &cDelay_9xNRa14F_sendMessage);
}

void Heavy_PhaseRing::cMsg_6IhsKVGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1P1CHV5s_sendMessage);
}

void Heavy_PhaseRing::cMsg_Xq9FibJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KR4SJEvk, 0, m, &cDelay_KR4SJEvk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9xNRa14F, 0, m, &cDelay_9xNRa14F_sendMessage);
}

void Heavy_PhaseRing::cMsg_GyXZ7rMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_rAd7lEnx, HV_BINOP_MAX, 1, m, &cBinop_rAd7lEnx_sendMessage);
}

void Heavy_PhaseRing::cBinop_rAd7lEnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ou54OYx1, HV_BINOP_SUBTRACT, 1, m, &cBinop_ou54OYx1_sendMessage);
}

void Heavy_PhaseRing::cCast_YsV5hjeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KR4SJEvk, 0, m, &cDelay_KR4SJEvk_sendMessage);
}

void Heavy_PhaseRing::cBinop_g9a8eqIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KR4SJEvk, 2, m, &cDelay_KR4SJEvk_sendMessage);
}

void Heavy_PhaseRing::cBinop_VCWpGUhD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_g9a8eqIK_sendMessage);
}

void Heavy_PhaseRing::cCast_0fxhXra0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2xQG8E27, 0, m, &cVar_2xQG8E27_sendMessage);
  cMsg_cHHfHK6t_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_psfVSoyH, 0, m, &cTabhead_psfVSoyH_sendMessage);
}

void Heavy_PhaseRing::cMsg_70DUGP0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kDmy1nlb_sendMessage);
}

void Heavy_PhaseRing::cSystem_kDmy1nlb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IUXUUvLw_sendMessage);
}

void Heavy_PhaseRing::cDelay_8Q2h1lLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8Q2h1lLF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5p93yCNt, 0, m, &cDelay_5p93yCNt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Q2h1lLF, 0, m, &cDelay_8Q2h1lLF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rk0cq70c, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_5p93yCNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5p93yCNt, m);
  cMsg_byKu6ZhT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_1hlPIk8x_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_OdqFagzV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_acbMv4oX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SdxTwamF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_jzBRok7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PGYqMlNv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Q2h1lLF, 2, m, &cDelay_8Q2h1lLF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l6Ir8S7C_sendMessage);
}

void Heavy_PhaseRing::cMsg_SdxTwamF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jzBRok7l, 0, m, &hTable_jzBRok7l_sendMessage);
}

void Heavy_PhaseRing::cBinop_IUXUUvLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_acbMv4oX_sendMessage);
}

void Heavy_PhaseRing::cMsg_byKu6ZhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jzBRok7l, 0, m, &hTable_jzBRok7l_sendMessage);
}

void Heavy_PhaseRing::cCast_l6Ir8S7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Q2h1lLF, 0, m, &cDelay_8Q2h1lLF_sendMessage);
}

void Heavy_PhaseRing::cMsg_PGYqMlNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_5p93yCNt, 2, m, &cDelay_5p93yCNt_sendMessage);
}

void Heavy_PhaseRing::cMsg_OdqFagzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rk0cq70c, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_RH4MTcMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ecfimlrR, HV_BINOP_SUBTRACT, 0, m, &cBinop_ecfimlrR_sendMessage);
}

void Heavy_PhaseRing::cMsg_Lf1mFsru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4wxPIssj_sendMessage);
}

void Heavy_PhaseRing::cSystem_4wxPIssj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Y4p9XVWx_sendMessage);
}

void Heavy_PhaseRing::cVar_62yBMUkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oyXnRMeL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_AyVIx8ik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AyVIx8ik, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RHKAkzNv, 0, m, &cDelay_RHKAkzNv_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zgD4o1zF, 0, m, &sTabread_zgD4o1zF_sendMessage);
}

void Heavy_PhaseRing::cDelay_RHKAkzNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RHKAkzNv, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zgD4o1zF, 0, m, &sTabread_zgD4o1zF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RHKAkzNv, 0, m, &cDelay_RHKAkzNv_sendMessage);
}

void Heavy_PhaseRing::sTabread_zgD4o1zF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oHvSPIZo, HV_BINOP_SUBTRACT, 0, m, &cBinop_oHvSPIZo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_9GJp52R7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PQtHySxj, HV_BINOP_MAX, 0, m, &cBinop_PQtHySxj_sendMessage);
}

void Heavy_PhaseRing::cBinop_Y4p9XVWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9GJp52R7, HV_BINOP_MULTIPLY, 0, m, &cBinop_9GJp52R7_sendMessage);
}

void Heavy_PhaseRing::cBinop_ecfimlrR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4q7lkFBE_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zgD4o1zF, 0, m, &sTabread_zgD4o1zF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xgnSQIvZ_sendMessage);
}

void Heavy_PhaseRing::cSystem_jDx6k5Gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oHvSPIZo, HV_BINOP_SUBTRACT, 1, m, &cBinop_oHvSPIZo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RHKAkzNv, 2, m, &cDelay_RHKAkzNv_sendMessage);
}

void Heavy_PhaseRing::cMsg_oyXnRMeL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jDx6k5Gy_sendMessage);
}

void Heavy_PhaseRing::cMsg_4q7lkFBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_AyVIx8ik, 0, m, &cDelay_AyVIx8ik_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RHKAkzNv, 0, m, &cDelay_RHKAkzNv_sendMessage);
}

void Heavy_PhaseRing::cMsg_M2KvHH0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_PQtHySxj, HV_BINOP_MAX, 1, m, &cBinop_PQtHySxj_sendMessage);
}

void Heavy_PhaseRing::cBinop_PQtHySxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ecfimlrR, HV_BINOP_SUBTRACT, 1, m, &cBinop_ecfimlrR_sendMessage);
}

void Heavy_PhaseRing::cCast_xgnSQIvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AyVIx8ik, 0, m, &cDelay_AyVIx8ik_sendMessage);
}

void Heavy_PhaseRing::cBinop_mq1tO03b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AyVIx8ik, 2, m, &cDelay_AyVIx8ik_sendMessage);
}

void Heavy_PhaseRing::cBinop_oHvSPIZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mq1tO03b_sendMessage);
}

void Heavy_PhaseRing::cCast_iUMPjq5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_62yBMUkD, 0, m, &cVar_62yBMUkD_sendMessage);
  cMsg_Lf1mFsru_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RH4MTcMd, 0, m, &cTabhead_RH4MTcMd_sendMessage);
}

void Heavy_PhaseRing::cMsg_2crterX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PSGy1RBQ_sendMessage);
}

void Heavy_PhaseRing::cSystem_PSGy1RBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_27Z4kEFa_sendMessage);
}

void Heavy_PhaseRing::cDelay_1A2OUMB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1A2OUMB6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_seEmRnEi, 0, m, &cDelay_seEmRnEi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1A2OUMB6, 0, m, &cDelay_1A2OUMB6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yLQQoOMv, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_seEmRnEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_seEmRnEi, m);
  cMsg_yGmjrTNf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_f9zB9ZQ5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Yb2nnWlS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ycIDxcng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZWMS3v5i_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_FY7LcnD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8ZL18EST_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1A2OUMB6, 2, m, &cDelay_1A2OUMB6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ydPE3jtV_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZWMS3v5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_FY7LcnD6, 0, m, &hTable_FY7LcnD6_sendMessage);
}

void Heavy_PhaseRing::cBinop_27Z4kEFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_ycIDxcng_sendMessage);
}

void Heavy_PhaseRing::cMsg_yGmjrTNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_FY7LcnD6, 0, m, &hTable_FY7LcnD6_sendMessage);
}

void Heavy_PhaseRing::cCast_ydPE3jtV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1A2OUMB6, 0, m, &cDelay_1A2OUMB6_sendMessage);
}

void Heavy_PhaseRing::cMsg_8ZL18EST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_seEmRnEi, 2, m, &cDelay_seEmRnEi_sendMessage);
}

void Heavy_PhaseRing::cMsg_Yb2nnWlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yLQQoOMv, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_RZ7cANBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n7xdHyON, HV_BINOP_SUBTRACT, 0, m, &cBinop_n7xdHyON_sendMessage);
}

void Heavy_PhaseRing::cMsg_aX6ETK77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QWh1ctZM_sendMessage);
}

void Heavy_PhaseRing::cSystem_QWh1ctZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LIxbFQBb_sendMessage);
}

void Heavy_PhaseRing::cVar_4llXTxP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R8xRBrov_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_4UEVqa75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4UEVqa75, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_18c0dvqT, 0, m, &cDelay_18c0dvqT_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_67EzIRIe, 0, m, &sTabread_67EzIRIe_sendMessage);
}

void Heavy_PhaseRing::cDelay_18c0dvqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_18c0dvqT, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_67EzIRIe, 0, m, &sTabread_67EzIRIe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_18c0dvqT, 0, m, &cDelay_18c0dvqT_sendMessage);
}

void Heavy_PhaseRing::sTabread_67EzIRIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_PeOZESoo, HV_BINOP_SUBTRACT, 0, m, &cBinop_PeOZESoo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_eUNUDpjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DED03ilD, HV_BINOP_MAX, 0, m, &cBinop_DED03ilD_sendMessage);
}

void Heavy_PhaseRing::cBinop_LIxbFQBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eUNUDpjX, HV_BINOP_MULTIPLY, 0, m, &cBinop_eUNUDpjX_sendMessage);
}

void Heavy_PhaseRing::cBinop_n7xdHyON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ntbPeNPH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_67EzIRIe, 0, m, &sTabread_67EzIRIe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SZcRGZJX_sendMessage);
}

void Heavy_PhaseRing::cSystem_l0UIeFMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PeOZESoo, HV_BINOP_SUBTRACT, 1, m, &cBinop_PeOZESoo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_18c0dvqT, 2, m, &cDelay_18c0dvqT_sendMessage);
}

void Heavy_PhaseRing::cMsg_R8xRBrov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l0UIeFMY_sendMessage);
}

void Heavy_PhaseRing::cMsg_ntbPeNPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_4UEVqa75, 0, m, &cDelay_4UEVqa75_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_18c0dvqT, 0, m, &cDelay_18c0dvqT_sendMessage);
}

void Heavy_PhaseRing::cMsg_He8Bok0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_DED03ilD, HV_BINOP_MAX, 1, m, &cBinop_DED03ilD_sendMessage);
}

void Heavy_PhaseRing::cBinop_DED03ilD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n7xdHyON, HV_BINOP_SUBTRACT, 1, m, &cBinop_n7xdHyON_sendMessage);
}

void Heavy_PhaseRing::cCast_SZcRGZJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4UEVqa75, 0, m, &cDelay_4UEVqa75_sendMessage);
}

void Heavy_PhaseRing::cBinop_LrxgFvkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4UEVqa75, 2, m, &cDelay_4UEVqa75_sendMessage);
}

void Heavy_PhaseRing::cBinop_PeOZESoo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LrxgFvkn_sendMessage);
}

void Heavy_PhaseRing::cCast_jxH0GIJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4llXTxP6, 0, m, &cVar_4llXTxP6_sendMessage);
  cMsg_aX6ETK77_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RZ7cANBB, 0, m, &cTabhead_RZ7cANBB_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZVkWlCqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I5Vy0AR9_sendMessage);
}

void Heavy_PhaseRing::cSystem_I5Vy0AR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6FLof8i1_sendMessage);
}

void Heavy_PhaseRing::cDelay_MyXinqIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MyXinqIS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_owLUDsgK, 0, m, &cDelay_owLUDsgK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MyXinqIS, 0, m, &cDelay_MyXinqIS_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OAIcRncr, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_owLUDsgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_owLUDsgK, m);
  cMsg_IpUqpFWJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_IWhvKSq1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_HOf8hw2t_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_zFtTyh1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s3qUYSUa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_bqM7kUv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AuxCjzme_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MyXinqIS, 2, m, &cDelay_MyXinqIS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dgPoVQF7_sendMessage);
}

void Heavy_PhaseRing::cMsg_s3qUYSUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_bqM7kUv1, 0, m, &hTable_bqM7kUv1_sendMessage);
}

void Heavy_PhaseRing::cBinop_6FLof8i1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_zFtTyh1T_sendMessage);
}

void Heavy_PhaseRing::cMsg_IpUqpFWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_bqM7kUv1, 0, m, &hTable_bqM7kUv1_sendMessage);
}

void Heavy_PhaseRing::cCast_dgPoVQF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MyXinqIS, 0, m, &cDelay_MyXinqIS_sendMessage);
}

void Heavy_PhaseRing::cMsg_AuxCjzme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_owLUDsgK, 2, m, &cDelay_owLUDsgK_sendMessage);
}

void Heavy_PhaseRing::cMsg_HOf8hw2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OAIcRncr, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_Cdv4cOqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NMEJtwwS, 0, m, &cVar_NMEJtwwS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aCK74uYh, 0, m, &cVar_aCK74uYh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_E5bOsQS9, 0, m, &cVar_E5bOsQS9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xj5p7vRM, 0, m, &cVar_xj5p7vRM_sendMessage);
}

void Heavy_PhaseRing::cVar_bMD4OnpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_nFNSpqhr_sendMessage);
}

void Heavy_PhaseRing::cPack_2Tht7zvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PLHq1d1h, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_aCK74uYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CL2JF3zD, HV_BINOP_MULTIPLY, 0, m, &cBinop_CL2JF3zD_sendMessage);
}

void Heavy_PhaseRing::cMsg_is4RjVUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_h8AZB2s2_sendMessage);
}

void Heavy_PhaseRing::cSystem_h8AZB2s2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3Jgzs7rR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_CL2JF3zD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_8qzxDIkL_sendMessage);
}

void Heavy_PhaseRing::cBinop_wLwBSCxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CL2JF3zD, HV_BINOP_MULTIPLY, 1, m, &cBinop_CL2JF3zD_sendMessage);
}

void Heavy_PhaseRing::cMsg_3Jgzs7rR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_wLwBSCxz_sendMessage);
}

void Heavy_PhaseRing::cBinop_8qzxDIkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EmEVeqOn_sendMessage);
}

void Heavy_PhaseRing::cBinop_EmEVeqOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_PJnPdVAV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7r1Y4ooD, m);
}

void Heavy_PhaseRing::cBinop_PJnPdVAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Np2LMZiG, m);
}

void Heavy_PhaseRing::cVar_E5bOsQS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HNTWv9WT, HV_BINOP_MULTIPLY, 0, m, &cBinop_HNTWv9WT_sendMessage);
}

void Heavy_PhaseRing::cMsg_8oidOGDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0lsXHUD0_sendMessage);
}

void Heavy_PhaseRing::cSystem_0lsXHUD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SlTogUir_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_HNTWv9WT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7FC5DQU3_sendMessage);
}

void Heavy_PhaseRing::cBinop_AsUb2ztj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HNTWv9WT, HV_BINOP_MULTIPLY, 1, m, &cBinop_HNTWv9WT_sendMessage);
}

void Heavy_PhaseRing::cMsg_SlTogUir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_AsUb2ztj_sendMessage);
}

void Heavy_PhaseRing::cBinop_7FC5DQU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_l3PglCYa_sendMessage);
}

void Heavy_PhaseRing::cBinop_l3PglCYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XxVzglKc_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_j47QkNgi, m);
}

void Heavy_PhaseRing::cBinop_XxVzglKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7LrvpiZq, m);
}

void Heavy_PhaseRing::cVar_xj5p7vRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jQQoksIO, HV_BINOP_MULTIPLY, 0, m, &cBinop_jQQoksIO_sendMessage);
}

void Heavy_PhaseRing::cMsg_hNJv2cgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QjllGsMr_sendMessage);
}

void Heavy_PhaseRing::cSystem_QjllGsMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5VsvkYvL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_jQQoksIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Fr93o0u6_sendMessage);
}

void Heavy_PhaseRing::cBinop_h0RryCgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jQQoksIO, HV_BINOP_MULTIPLY, 1, m, &cBinop_jQQoksIO_sendMessage);
}

void Heavy_PhaseRing::cMsg_5VsvkYvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_h0RryCgi_sendMessage);
}

void Heavy_PhaseRing::cBinop_Fr93o0u6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_vGzL3mJa_sendMessage);
}

void Heavy_PhaseRing::cBinop_vGzL3mJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qQ1Vltk1_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sdbMylJD, m);
}

void Heavy_PhaseRing::cBinop_qQ1Vltk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KYRZv9FD, m);
}

void Heavy_PhaseRing::cBinop_TGGcpe1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4Jz7rgcG, 0, m, &cPack_4Jz7rgcG_sendMessage);
}

void Heavy_PhaseRing::cMsg_23rmWSzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Cdv4cOqi, 0, m, &cVar_Cdv4cOqi_sendMessage);
}

void Heavy_PhaseRing::cBinop_nFNSpqhr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2Tht7zvb, 0, m, &cPack_2Tht7zvb_sendMessage);
}

void Heavy_PhaseRing::cBinop_UPyVhisQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JaZ3eDOy, 0, m, &cPack_JaZ3eDOy_sendMessage);
}

void Heavy_PhaseRing::cIf_2WklvkdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Nlj3BCyf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_Np1AurJ9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_Np1AurJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_Hk6f2eJe_sendMessage);
}

void Heavy_PhaseRing::cCast_VaGhe5kJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Uyam3TiF_sendMessage);
}

void Heavy_PhaseRing::cCast_sTeIuXh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2WklvkdS, 0, m, &cIf_2WklvkdS_sendMessage);
}

void Heavy_PhaseRing::cMsg_Nlj3BCyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_zIBaPinP, 0, m, &cVar_zIBaPinP_sendMessage);
}

void Heavy_PhaseRing::cBinop_Hk6f2eJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_jY2WBKly_sendMessage);
}

void Heavy_PhaseRing::cBinop_jY2WBKly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lJTC8OAv_sendMessage);
}

void Heavy_PhaseRing::cBinop_lJTC8OAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zIBaPinP, 0, m, &cVar_zIBaPinP_sendMessage);
}

void Heavy_PhaseRing::cBinop_Uyam3TiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2WklvkdS, 1, m, &cIf_2WklvkdS_sendMessage);
}

void Heavy_PhaseRing::cBinop_tk178jh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VaGhe5kJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sTeIuXh8_sendMessage);
}

void Heavy_PhaseRing::cBinop_whcAJBQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tk178jh8_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_SMgQxlua_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_hUakihqp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_hUakihqp_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Zq3Wk8q4, 1, m, &cDelay_Zq3Wk8q4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PLYVCol7_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_Zq3Wk8q4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Zq3Wk8q4, m);
  cMsg_L9mKBslp_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_hUakihqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zq3Wk8q4, 0, m, &cDelay_Zq3Wk8q4_sendMessage);
}

void Heavy_PhaseRing::cCast_PLYVCol7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zq3Wk8q4, 0, m, &cDelay_Zq3Wk8q4_sendMessage);
}

void Heavy_PhaseRing::cVar_t3mDz5EI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sfplaFgE, 0, m, &cPack_sfplaFgE_sendMessage);
}

void Heavy_PhaseRing::cVar_mQXfbYRn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_OHG7Re1Z_sendMessage);
}

void Heavy_PhaseRing::cVar_4uvfQEXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_AssbmtAN_sendMessage);
}

void Heavy_PhaseRing::cPack_cveYnAOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_7dmqaXz6, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_K5MoDY6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JxvBZSz8_sendMessage);
}

void Heavy_PhaseRing::cBinop_eZC0W6AF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_K5MoDY6D_sendMessage);
}

void Heavy_PhaseRing::cPack_V2cbpbHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_dF5MkyD8, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_8jYEnF13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_5KlWQMGS_sendMessage);
}

void Heavy_PhaseRing::cMsg_5J2iMQ9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XlZVzy0D_sendMessage);
}

void Heavy_PhaseRing::cSystem_XlZVzy0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mL7h0Lqh_sendMessage);
}

void Heavy_PhaseRing::cDelay_24sW0uyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_24sW0uyh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KQbseKwF, 0, m, &cDelay_KQbseKwF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_24sW0uyh, 0, m, &cDelay_24sW0uyh_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bJAtj8sL, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_KQbseKwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KQbseKwF, m);
  cMsg_FvrIZOEj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Y6ENY1iU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6BaOnDXt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_5A648Uow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H4CCnODX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_1N2pKnrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sYUPOhQe_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_24sW0uyh, 2, m, &cDelay_24sW0uyh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k8UWjjiP_sendMessage);
}

void Heavy_PhaseRing::cMsg_H4CCnODX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_1N2pKnrk, 0, m, &hTable_1N2pKnrk_sendMessage);
}

void Heavy_PhaseRing::cBinop_mL7h0Lqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_5A648Uow_sendMessage);
}

void Heavy_PhaseRing::cMsg_FvrIZOEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_1N2pKnrk, 0, m, &hTable_1N2pKnrk_sendMessage);
}

void Heavy_PhaseRing::cCast_k8UWjjiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_24sW0uyh, 0, m, &cDelay_24sW0uyh_sendMessage);
}

void Heavy_PhaseRing::cMsg_sYUPOhQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_KQbseKwF, 2, m, &cDelay_KQbseKwF_sendMessage);
}

void Heavy_PhaseRing::cMsg_6BaOnDXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bJAtj8sL, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_B7BEIPem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qyJG0MNX_sendMessage);
}

void Heavy_PhaseRing::cSystem_qyJG0MNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SrPDN0Xn_sendMessage);
}

void Heavy_PhaseRing::cVar_91hhEDAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W9N03F1g_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_dwoxdKsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GzUVQ3TM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_r3SBiOvf, m);
}

void Heavy_PhaseRing::cBinop_SrPDN0Xn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hYULEoNG, m);
}

void Heavy_PhaseRing::cMsg_W9N03F1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dwoxdKsH_sendMessage);
}

void Heavy_PhaseRing::cBinop_GzUVQ3TM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_B3puZuTF, m);
}

void Heavy_PhaseRing::cMsg_Nbh0kq0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xaT0rN0P_sendMessage);
}

void Heavy_PhaseRing::cSystem_xaT0rN0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_52CQ1f4h_sendMessage);
}

void Heavy_PhaseRing::cVar_FW92KCMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WcjuloBD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_6zAXgx8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_NdTFReqy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ECOtSiwK, m);
}

void Heavy_PhaseRing::cBinop_52CQ1f4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AjCEyYil, m);
}

void Heavy_PhaseRing::cMsg_WcjuloBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6zAXgx8R_sendMessage);
}

void Heavy_PhaseRing::cBinop_NdTFReqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xo0PuH6q, m);
}

void Heavy_PhaseRing::cBinop_k5nMeJvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ROCuNJiG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_U3w5BfKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UnoE2L5i_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z6hm7lCg_sendMessage);
}

void Heavy_PhaseRing::cCast_UnoE2L5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k5nMeJvX, HV_BINOP_DIVIDE, 1, m, &cBinop_k5nMeJvX_sendMessage);
}

void Heavy_PhaseRing::cCast_z6hm7lCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k5nMeJvX, HV_BINOP_DIVIDE, 0, m, &cBinop_k5nMeJvX_sendMessage);
}

void Heavy_PhaseRing::cBinop_JxvBZSz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JDPEuPtT_sendMessage);
}

void Heavy_PhaseRing::cBinop_OHG7Re1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_eZC0W6AF_sendMessage);
}

void Heavy_PhaseRing::cBinop_JDPEuPtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k5nMeJvX, HV_BINOP_DIVIDE, 0, m, &cBinop_k5nMeJvX_sendMessage);
}

void Heavy_PhaseRing::cBinop_5KlWQMGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_V2cbpbHT, 0, m, &cPack_V2cbpbHT_sendMessage);
}

void Heavy_PhaseRing::cBinop_AssbmtAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_U3w5BfKP_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_cveYnAOw, 0, m, &cPack_cveYnAOw_sendMessage);
}

void Heavy_PhaseRing::cMsg_Q0SfGP8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_4uvfQEXX, 0, m, &cVar_4uvfQEXX_sendMessage);
}

void Heavy_PhaseRing::cMsg_7wAk8YJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_8jYEnF13, 0, m, &cVar_8jYEnF13_sendMessage);
}

void Heavy_PhaseRing::cMsg_ROCuNJiG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_PapVVXG2, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_DbNwVwe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XUZf3upv, HV_BINOP_MULTIPLY, 0, m, &cBinop_XUZf3upv_sendMessage);
}

void Heavy_PhaseRing::cMsg_tIdIOL3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pApaRCBb_sendMessage);
}

void Heavy_PhaseRing::cSystem_pApaRCBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BE0TIUZC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_XUZf3upv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_mB8iiZlM_sendMessage);
}

void Heavy_PhaseRing::cBinop_qNt9MVsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XUZf3upv, HV_BINOP_MULTIPLY, 1, m, &cBinop_XUZf3upv_sendMessage);
}

void Heavy_PhaseRing::cMsg_BE0TIUZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qNt9MVsa_sendMessage);
}

void Heavy_PhaseRing::cBinop_mB8iiZlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oHxBPNUE_sendMessage);
}

void Heavy_PhaseRing::cBinop_oHxBPNUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Vwxdk7oz_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7ExfHys2, m);
}

void Heavy_PhaseRing::cBinop_Vwxdk7oz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GSGz0Jj4, m);
}

void Heavy_PhaseRing::cVar_0aUqG0n5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QnvoyYgK, HV_BINOP_MULTIPLY, 0, m, &cBinop_QnvoyYgK_sendMessage);
}

void Heavy_PhaseRing::cMsg_elMB56Kn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QUarB9FY_sendMessage);
}

void Heavy_PhaseRing::cSystem_QUarB9FY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FXDpKGLV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_QnvoyYgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jIgLDZut_sendMessage);
}

void Heavy_PhaseRing::cBinop_xLlXpmhi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QnvoyYgK, HV_BINOP_MULTIPLY, 1, m, &cBinop_QnvoyYgK_sendMessage);
}

void Heavy_PhaseRing::cMsg_FXDpKGLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xLlXpmhi_sendMessage);
}

void Heavy_PhaseRing::cBinop_jIgLDZut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LIIHUfte_sendMessage);
}

void Heavy_PhaseRing::cBinop_LIIHUfte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Epbgsbx5_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wR3iwfXo, m);
}

void Heavy_PhaseRing::cBinop_Epbgsbx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uUXnc56J, m);
}

void Heavy_PhaseRing::cVar_5EGrzIwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rboUgxUy, HV_BINOP_MULTIPLY, 0, m, &cBinop_rboUgxUy_sendMessage);
}

void Heavy_PhaseRing::cMsg_9tADVRw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JYAJjkxU_sendMessage);
}

void Heavy_PhaseRing::cSystem_JYAJjkxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Zx5QXE9l_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_rboUgxUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xTDnWJPl_sendMessage);
}

void Heavy_PhaseRing::cBinop_CETZ7AMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rboUgxUy, HV_BINOP_MULTIPLY, 1, m, &cBinop_rboUgxUy_sendMessage);
}

void Heavy_PhaseRing::cMsg_Zx5QXE9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CETZ7AMo_sendMessage);
}

void Heavy_PhaseRing::cBinop_xTDnWJPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZtLIv6fH_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZtLIv6fH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_kYatqot6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BRv2Tpjt, m);
}

void Heavy_PhaseRing::cBinop_kYatqot6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_l7DmsHrf, m);
}

void Heavy_PhaseRing::cMsg_sRxoC5X9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Edo7zl7y_sendMessage);
}

void Heavy_PhaseRing::cSystem_Edo7zl7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A46KbxCb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_SQ4unrAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_JxaRSv1U_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Ah847ggI, 0, m, &cIf_Ah847ggI_sendMessage);
}

void Heavy_PhaseRing::cIf_Ah847ggI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KPe2LtLs_sendMessage(_c, 0, m);
      cMsg_04OwaFcA_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_DD0y3J54_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_CiiIU13n_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_6K6LZ0P0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_JxaRSv1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ah847ggI, 1, m, &cIf_Ah847ggI_sendMessage);
}

void Heavy_PhaseRing::cMsg_DD0y3J54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_a3BsF6T5_sendMessage);
}

void Heavy_PhaseRing::cBinop_a3BsF6T5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_G488OcuY, m);
}

void Heavy_PhaseRing::cBinop_CiiIU13n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8KDBu1Ry_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_8KDBu1Ry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IFVFPjeF_sendMessage);
}

void Heavy_PhaseRing::cBinop_IFVFPjeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KYOB3kxI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_KYOB3kxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_URkhnbSp_sendMessage);
}

void Heavy_PhaseRing::cBinop_URkhnbSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MqrhPoRK, m);
}

void Heavy_PhaseRing::cBinop_RYlQ1RG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Thu1yC1L, m);
}

void Heavy_PhaseRing::cMsg_A46KbxCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_RYlQ1RG2_sendMessage);
}

void Heavy_PhaseRing::cMsg_KPe2LtLs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_CiiIU13n_sendMessage);
}

void Heavy_PhaseRing::cMsg_04OwaFcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_G488OcuY, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6K6LZ0P0, m);
}

void Heavy_PhaseRing::cBinop_JpIwOJ6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0aUqG0n5, 0, m, &cVar_0aUqG0n5_sendMessage);
}

void Heavy_PhaseRing::cBinop_vfdlMrNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DbNwVwe2, 0, m, &cVar_DbNwVwe2_sendMessage);
}

void Heavy_PhaseRing::cBinop_XaMdjOvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5EGrzIwn, 0, m, &cVar_5EGrzIwn_sendMessage);
}

void Heavy_PhaseRing::cCast_YuaAHUVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_vfdlMrNZ_sendMessage);
}

void Heavy_PhaseRing::cCast_lsNI7eP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_XaMdjOvj_sendMessage);
}

void Heavy_PhaseRing::cCast_zkT9rmcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HTtj5Eyq, m);
}

void Heavy_PhaseRing::cCast_6cEW9aTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_JpIwOJ6u_sendMessage);
}

void Heavy_PhaseRing::cTabhead_Fliazw6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BBmBfMBp, HV_BINOP_SUBTRACT, 0, m, &cBinop_BBmBfMBp_sendMessage);
}

void Heavy_PhaseRing::cMsg_tpH0J9oe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0s75MRP6_sendMessage);
}

void Heavy_PhaseRing::cSystem_0s75MRP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rzJ1oh0Z_sendMessage);
}

void Heavy_PhaseRing::cVar_PIfzD63H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pYMuPFcF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_AbWJAN9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AbWJAN9B, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_F7piPUKt, 0, m, &cDelay_F7piPUKt_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X8n8jThG, 0, m, &sTabread_X8n8jThG_sendMessage);
}

void Heavy_PhaseRing::cDelay_F7piPUKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_F7piPUKt, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X8n8jThG, 0, m, &sTabread_X8n8jThG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_F7piPUKt, 0, m, &cDelay_F7piPUKt_sendMessage);
}

void Heavy_PhaseRing::sTabread_X8n8jThG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mR9A5E2f, HV_BINOP_SUBTRACT, 0, m, &cBinop_mR9A5E2f_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_eljwDx9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eDQztlJJ, HV_BINOP_MAX, 0, m, &cBinop_eDQztlJJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_rzJ1oh0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eljwDx9x, HV_BINOP_MULTIPLY, 0, m, &cBinop_eljwDx9x_sendMessage);
}

void Heavy_PhaseRing::cBinop_BBmBfMBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aOg5NTcv_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X8n8jThG, 0, m, &sTabread_X8n8jThG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DBMuZv0w_sendMessage);
}

void Heavy_PhaseRing::cSystem_ENCLbIQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mR9A5E2f, HV_BINOP_SUBTRACT, 1, m, &cBinop_mR9A5E2f_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_F7piPUKt, 2, m, &cDelay_F7piPUKt_sendMessage);
}

void Heavy_PhaseRing::cMsg_pYMuPFcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ENCLbIQA_sendMessage);
}

void Heavy_PhaseRing::cMsg_aOg5NTcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_AbWJAN9B, 0, m, &cDelay_AbWJAN9B_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_F7piPUKt, 0, m, &cDelay_F7piPUKt_sendMessage);
}

void Heavy_PhaseRing::cMsg_2HBvWquF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eDQztlJJ, HV_BINOP_MAX, 1, m, &cBinop_eDQztlJJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_eDQztlJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BBmBfMBp, HV_BINOP_SUBTRACT, 1, m, &cBinop_BBmBfMBp_sendMessage);
}

void Heavy_PhaseRing::cCast_DBMuZv0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AbWJAN9B, 0, m, &cDelay_AbWJAN9B_sendMessage);
}

void Heavy_PhaseRing::cBinop_yMFHHbtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AbWJAN9B, 2, m, &cDelay_AbWJAN9B_sendMessage);
}

void Heavy_PhaseRing::cBinop_mR9A5E2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yMFHHbtk_sendMessage);
}

void Heavy_PhaseRing::cCast_2n4E0W01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PIfzD63H, 0, m, &cVar_PIfzD63H_sendMessage);
  cMsg_tpH0J9oe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Fliazw6k, 0, m, &cTabhead_Fliazw6k_sendMessage);
}

void Heavy_PhaseRing::cTabhead_fDGNzDFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_roj9xzjo, HV_BINOP_SUBTRACT, 0, m, &cBinop_roj9xzjo_sendMessage);
}

void Heavy_PhaseRing::cMsg_1SkEqFCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5hJerXGa_sendMessage);
}

void Heavy_PhaseRing::cSystem_5hJerXGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1o3iqHms_sendMessage);
}

void Heavy_PhaseRing::cVar_N6PqgSfb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OKrNqaeZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_RyffeVBl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RyffeVBl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l8ZEhDCH, 0, m, &cDelay_l8ZEhDCH_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_U8yFvSeH, 0, m, &sTabread_U8yFvSeH_sendMessage);
}

void Heavy_PhaseRing::cDelay_l8ZEhDCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_l8ZEhDCH, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_U8yFvSeH, 0, m, &sTabread_U8yFvSeH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l8ZEhDCH, 0, m, &cDelay_l8ZEhDCH_sendMessage);
}

void Heavy_PhaseRing::sTabread_U8yFvSeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KGd0N7nO, HV_BINOP_SUBTRACT, 0, m, &cBinop_KGd0N7nO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_6vs3c1LD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_usv63aL5, HV_BINOP_MAX, 0, m, &cBinop_usv63aL5_sendMessage);
}

void Heavy_PhaseRing::cBinop_1o3iqHms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vs3c1LD, HV_BINOP_MULTIPLY, 0, m, &cBinop_6vs3c1LD_sendMessage);
}

void Heavy_PhaseRing::cBinop_roj9xzjo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PhsrijVZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_U8yFvSeH, 0, m, &sTabread_U8yFvSeH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uTZat26r_sendMessage);
}

void Heavy_PhaseRing::cSystem_kZzsUqpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KGd0N7nO, HV_BINOP_SUBTRACT, 1, m, &cBinop_KGd0N7nO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l8ZEhDCH, 2, m, &cDelay_l8ZEhDCH_sendMessage);
}

void Heavy_PhaseRing::cMsg_OKrNqaeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kZzsUqpR_sendMessage);
}

void Heavy_PhaseRing::cMsg_PhsrijVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_RyffeVBl, 0, m, &cDelay_RyffeVBl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l8ZEhDCH, 0, m, &cDelay_l8ZEhDCH_sendMessage);
}

void Heavy_PhaseRing::cMsg_M87oPYEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_usv63aL5, HV_BINOP_MAX, 1, m, &cBinop_usv63aL5_sendMessage);
}

void Heavy_PhaseRing::cBinop_usv63aL5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_roj9xzjo, HV_BINOP_SUBTRACT, 1, m, &cBinop_roj9xzjo_sendMessage);
}

void Heavy_PhaseRing::cCast_uTZat26r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RyffeVBl, 0, m, &cDelay_RyffeVBl_sendMessage);
}

void Heavy_PhaseRing::cBinop_MqBeeP8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RyffeVBl, 2, m, &cDelay_RyffeVBl_sendMessage);
}

void Heavy_PhaseRing::cBinop_KGd0N7nO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MqBeeP8p_sendMessage);
}

void Heavy_PhaseRing::cCast_IXjDmDdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N6PqgSfb, 0, m, &cVar_N6PqgSfb_sendMessage);
  cMsg_1SkEqFCn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_fDGNzDFl, 0, m, &cTabhead_fDGNzDFl_sendMessage);
}

void Heavy_PhaseRing::cTabhead_34KDiFsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HTEiG5u7, HV_BINOP_SUBTRACT, 0, m, &cBinop_HTEiG5u7_sendMessage);
}

void Heavy_PhaseRing::cMsg_6cfDvXJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UKmzBrKX_sendMessage);
}

void Heavy_PhaseRing::cSystem_UKmzBrKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0YfShemA_sendMessage);
}

void Heavy_PhaseRing::cVar_rwGbOOyz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9wLXyq9e_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_xb4vGCmZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xb4vGCmZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3tEjPjMU, 0, m, &cDelay_3tEjPjMU_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1QZ9j9kB, 0, m, &sTabread_1QZ9j9kB_sendMessage);
}

void Heavy_PhaseRing::cDelay_3tEjPjMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3tEjPjMU, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1QZ9j9kB, 0, m, &sTabread_1QZ9j9kB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3tEjPjMU, 0, m, &cDelay_3tEjPjMU_sendMessage);
}

void Heavy_PhaseRing::sTabread_1QZ9j9kB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2lBagygC, HV_BINOP_SUBTRACT, 0, m, &cBinop_2lBagygC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_OCnwVvGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ErjRs9Ex, HV_BINOP_MAX, 0, m, &cBinop_ErjRs9Ex_sendMessage);
}

void Heavy_PhaseRing::cBinop_0YfShemA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OCnwVvGp, HV_BINOP_MULTIPLY, 0, m, &cBinop_OCnwVvGp_sendMessage);
}

void Heavy_PhaseRing::cBinop_HTEiG5u7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4N5cZeKq_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1QZ9j9kB, 0, m, &sTabread_1QZ9j9kB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5HqUIGbi_sendMessage);
}

void Heavy_PhaseRing::cSystem_Ie4Sa3ce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2lBagygC, HV_BINOP_SUBTRACT, 1, m, &cBinop_2lBagygC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3tEjPjMU, 2, m, &cDelay_3tEjPjMU_sendMessage);
}

void Heavy_PhaseRing::cMsg_9wLXyq9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ie4Sa3ce_sendMessage);
}

void Heavy_PhaseRing::cMsg_4N5cZeKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xb4vGCmZ, 0, m, &cDelay_xb4vGCmZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3tEjPjMU, 0, m, &cDelay_3tEjPjMU_sendMessage);
}

void Heavy_PhaseRing::cMsg_59VCik6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ErjRs9Ex, HV_BINOP_MAX, 1, m, &cBinop_ErjRs9Ex_sendMessage);
}

void Heavy_PhaseRing::cBinop_ErjRs9Ex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HTEiG5u7, HV_BINOP_SUBTRACT, 1, m, &cBinop_HTEiG5u7_sendMessage);
}

void Heavy_PhaseRing::cCast_5HqUIGbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xb4vGCmZ, 0, m, &cDelay_xb4vGCmZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_aE0OUSvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xb4vGCmZ, 2, m, &cDelay_xb4vGCmZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_2lBagygC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aE0OUSvv_sendMessage);
}

void Heavy_PhaseRing::cCast_Y7uNZNmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rwGbOOyz, 0, m, &cVar_rwGbOOyz_sendMessage);
  cMsg_6cfDvXJv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_34KDiFsG, 0, m, &cTabhead_34KDiFsG_sendMessage);
}

void Heavy_PhaseRing::cTabhead_TMVweQpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eSIoRcEG, HV_BINOP_SUBTRACT, 0, m, &cBinop_eSIoRcEG_sendMessage);
}

void Heavy_PhaseRing::cMsg_YFD241Oe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_d9wzUlFY_sendMessage);
}

void Heavy_PhaseRing::cSystem_d9wzUlFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bYjCsDY0_sendMessage);
}

void Heavy_PhaseRing::cVar_GPED2EGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wGvcgS04_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_EiB80pph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EiB80pph, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YhwnxGxK, 0, m, &cDelay_YhwnxGxK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_81UfMuMh, 0, m, &sTabread_81UfMuMh_sendMessage);
}

void Heavy_PhaseRing::cDelay_YhwnxGxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YhwnxGxK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_81UfMuMh, 0, m, &sTabread_81UfMuMh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YhwnxGxK, 0, m, &cDelay_YhwnxGxK_sendMessage);
}

void Heavy_PhaseRing::sTabread_81UfMuMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4008yVIF, HV_BINOP_SUBTRACT, 0, m, &cBinop_4008yVIF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Dv78FfOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GU1SgWOu, HV_BINOP_MAX, 0, m, &cBinop_GU1SgWOu_sendMessage);
}

void Heavy_PhaseRing::cBinop_bYjCsDY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dv78FfOp, HV_BINOP_MULTIPLY, 0, m, &cBinop_Dv78FfOp_sendMessage);
}

void Heavy_PhaseRing::cBinop_eSIoRcEG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ruPwtgGK_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_81UfMuMh, 0, m, &sTabread_81UfMuMh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_raQTl6WH_sendMessage);
}

void Heavy_PhaseRing::cSystem_qIND6fV0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4008yVIF, HV_BINOP_SUBTRACT, 1, m, &cBinop_4008yVIF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YhwnxGxK, 2, m, &cDelay_YhwnxGxK_sendMessage);
}

void Heavy_PhaseRing::cMsg_wGvcgS04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qIND6fV0_sendMessage);
}

void Heavy_PhaseRing::cMsg_ruPwtgGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EiB80pph, 0, m, &cDelay_EiB80pph_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YhwnxGxK, 0, m, &cDelay_YhwnxGxK_sendMessage);
}

void Heavy_PhaseRing::cMsg_bkB9NWR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_GU1SgWOu, HV_BINOP_MAX, 1, m, &cBinop_GU1SgWOu_sendMessage);
}

void Heavy_PhaseRing::cBinop_GU1SgWOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eSIoRcEG, HV_BINOP_SUBTRACT, 1, m, &cBinop_eSIoRcEG_sendMessage);
}

void Heavy_PhaseRing::cCast_raQTl6WH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EiB80pph, 0, m, &cDelay_EiB80pph_sendMessage);
}

void Heavy_PhaseRing::cBinop_OTImQI8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EiB80pph, 2, m, &cDelay_EiB80pph_sendMessage);
}

void Heavy_PhaseRing::cBinop_4008yVIF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OTImQI8P_sendMessage);
}

void Heavy_PhaseRing::cCast_EsFxNDo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GPED2EGP, 0, m, &cVar_GPED2EGP_sendMessage);
  cMsg_YFD241Oe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TMVweQpP, 0, m, &cTabhead_TMVweQpP_sendMessage);
}

void Heavy_PhaseRing::cMsg_EehKra25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vEacGJKw_sendMessage);
}

void Heavy_PhaseRing::cSystem_vEacGJKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hSHz8hll_sendMessage);
}

void Heavy_PhaseRing::cDelay_QXeZNJ13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QXeZNJ13, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gEpsM1oD, 0, m, &cDelay_gEpsM1oD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QXeZNJ13, 0, m, &cDelay_QXeZNJ13_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oQkEofYY, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_gEpsM1oD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gEpsM1oD, m);
  cMsg_1Cnduwgo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_sTATddn8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_E7ErcUqh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_nTbV7Mzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OgVZbd1T_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_AA8FCmwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nKSNuh17_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QXeZNJ13, 2, m, &cDelay_QXeZNJ13_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Drttmf20_sendMessage);
}

void Heavy_PhaseRing::cMsg_OgVZbd1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_AA8FCmwT, 0, m, &hTable_AA8FCmwT_sendMessage);
}

void Heavy_PhaseRing::cBinop_hSHz8hll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_nTbV7Mzn_sendMessage);
}

void Heavy_PhaseRing::cMsg_1Cnduwgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_AA8FCmwT, 0, m, &hTable_AA8FCmwT_sendMessage);
}

void Heavy_PhaseRing::cCast_Drttmf20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QXeZNJ13, 0, m, &cDelay_QXeZNJ13_sendMessage);
}

void Heavy_PhaseRing::cMsg_nKSNuh17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_gEpsM1oD, 2, m, &cDelay_gEpsM1oD_sendMessage);
}

void Heavy_PhaseRing::cMsg_E7ErcUqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oQkEofYY, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_6H3z7TBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CsBrUmHS_sendMessage);
}

void Heavy_PhaseRing::cSystem_CsBrUmHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VDjRaIig_sendMessage);
}

void Heavy_PhaseRing::cDelay_NUTujX28_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NUTujX28, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p195Jv95, 0, m, &cDelay_p195Jv95_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NUTujX28, 0, m, &cDelay_NUTujX28_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_abHPcO78, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_p195Jv95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_p195Jv95, m);
  cMsg_wkH3pfAG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_ErbhqBZR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_kBuT0IaZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_wxbglaTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BhqchuPU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_Wr6uU0Bu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_00QC8poH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NUTujX28, 2, m, &cDelay_NUTujX28_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9pt3JYZR_sendMessage);
}

void Heavy_PhaseRing::cMsg_BhqchuPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Wr6uU0Bu, 0, m, &hTable_Wr6uU0Bu_sendMessage);
}

void Heavy_PhaseRing::cBinop_VDjRaIig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_wxbglaTt_sendMessage);
}

void Heavy_PhaseRing::cMsg_wkH3pfAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Wr6uU0Bu, 0, m, &hTable_Wr6uU0Bu_sendMessage);
}

void Heavy_PhaseRing::cCast_9pt3JYZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NUTujX28, 0, m, &cDelay_NUTujX28_sendMessage);
}

void Heavy_PhaseRing::cMsg_00QC8poH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_p195Jv95, 2, m, &cDelay_p195Jv95_sendMessage);
}

void Heavy_PhaseRing::cMsg_kBuT0IaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_abHPcO78, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_bAt70oa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bveThsgx_sendMessage);
}

void Heavy_PhaseRing::cSystem_bveThsgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_njvTWb54_sendMessage);
}

void Heavy_PhaseRing::cDelay_pOfyuVuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pOfyuVuK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hIZ9T1Ej, 0, m, &cDelay_hIZ9T1Ej_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOfyuVuK, 0, m, &cDelay_pOfyuVuK_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lVqJ67wj, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_hIZ9T1Ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hIZ9T1Ej, m);
  cMsg_kc9kfodN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_5uCMYduv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_c8UM68rF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_jRy8MIDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nYti5ZdD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_7yScw3nJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l2lpQxCf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOfyuVuK, 2, m, &cDelay_pOfyuVuK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mKVHLpGX_sendMessage);
}

void Heavy_PhaseRing::cMsg_nYti5ZdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7yScw3nJ, 0, m, &hTable_7yScw3nJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_njvTWb54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_jRy8MIDj_sendMessage);
}

void Heavy_PhaseRing::cMsg_kc9kfodN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7yScw3nJ, 0, m, &hTable_7yScw3nJ_sendMessage);
}

void Heavy_PhaseRing::cCast_mKVHLpGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOfyuVuK, 0, m, &cDelay_pOfyuVuK_sendMessage);
}

void Heavy_PhaseRing::cMsg_l2lpQxCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_hIZ9T1Ej, 2, m, &cDelay_hIZ9T1Ej_sendMessage);
}

void Heavy_PhaseRing::cMsg_c8UM68rF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lVqJ67wj, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_tQiEntrw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zdVk7aXG_sendMessage);
}

void Heavy_PhaseRing::cSystem_zdVk7aXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bCtCMW0D_sendMessage);
}

void Heavy_PhaseRing::cDelay_i5kZ2tbM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_i5kZ2tbM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nz2xsUDS, 0, m, &cDelay_Nz2xsUDS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_i5kZ2tbM, 0, m, &cDelay_i5kZ2tbM_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_axHp8D1Y, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_Nz2xsUDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Nz2xsUDS, m);
  cMsg_2aPjH8xP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Qzvo1jOF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_RSQnDg60_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_wzgVSH7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mUN5EerD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_oyaHkUVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EupTDQVZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_i5kZ2tbM, 2, m, &cDelay_i5kZ2tbM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HHeMYIx8_sendMessage);
}

void Heavy_PhaseRing::cMsg_mUN5EerD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_oyaHkUVb, 0, m, &hTable_oyaHkUVb_sendMessage);
}

void Heavy_PhaseRing::cBinop_bCtCMW0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_wzgVSH7B_sendMessage);
}

void Heavy_PhaseRing::cMsg_2aPjH8xP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_oyaHkUVb, 0, m, &hTable_oyaHkUVb_sendMessage);
}

void Heavy_PhaseRing::cCast_HHeMYIx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_i5kZ2tbM, 0, m, &cDelay_i5kZ2tbM_sendMessage);
}

void Heavy_PhaseRing::cMsg_EupTDQVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nz2xsUDS, 2, m, &cDelay_Nz2xsUDS_sendMessage);
}

void Heavy_PhaseRing::cMsg_RSQnDg60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_axHp8D1Y, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_fq44mSQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_6ABeIoIy_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_5yYgl8tZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_zWAVoQ2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_opFDE68L, HV_BINOP_POW, 0, m, &cBinop_opFDE68L_sendMessage);
}

void Heavy_PhaseRing::cBinop_opFDE68L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_NkHVzP6j_sendMessage);
}

void Heavy_PhaseRing::cBinop_So4QURJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Jkr6MrT5_sendMessage);
}

void Heavy_PhaseRing::cCast_6kt8AWHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fq44mSQR, 0, m, &cIf_fq44mSQR_sendMessage);
}

void Heavy_PhaseRing::cCast_z4NZzSxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ggKumG3v_sendMessage);
}

void Heavy_PhaseRing::cBinop_ggKumG3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fq44mSQR, 1, m, &cIf_fq44mSQR_sendMessage);
}

void Heavy_PhaseRing::cBinop_5yYgl8tZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_So4QURJH_sendMessage);
}

void Heavy_PhaseRing::cMsg_6ABeIoIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_NkHVzP6j_sendMessage);
}

void Heavy_PhaseRing::cBinop_Jkr6MrT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_opFDE68L, HV_BINOP_POW, 1, m, &cBinop_opFDE68L_sendMessage);
  cMsg_zWAVoQ2G_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_f44vPekf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9JANBMrb, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_y7gfsDlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_aEsnGRZY, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_F5uhsLHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ou5wQiAE_sendMessage);
}

void Heavy_PhaseRing::cBinop_ou5wQiAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_CObgDnAS_sendMessage);
}

void Heavy_PhaseRing::cVar_wvqBiHyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jdT1xnfo, HV_BINOP_MULTIPLY, 0, m, &cBinop_jdT1xnfo_sendMessage);
}

void Heavy_PhaseRing::cMsg_AKe2l9eW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HBv0IKdL_sendMessage);
}

void Heavy_PhaseRing::cSystem_HBv0IKdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gk6t9ll5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_jdT1xnfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_OU14WqaE_sendMessage);
}

void Heavy_PhaseRing::cBinop_JZl0aDf9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jdT1xnfo, HV_BINOP_MULTIPLY, 1, m, &cBinop_jdT1xnfo_sendMessage);
}

void Heavy_PhaseRing::cMsg_Gk6t9ll5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JZl0aDf9_sendMessage);
}

void Heavy_PhaseRing::cBinop_OU14WqaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Ce8s66ky_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ce8s66ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3RYY8nVX_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VMCrHD8y, m);
}

void Heavy_PhaseRing::cBinop_3RYY8nVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MDg5XWZi, m);
}

void Heavy_PhaseRing::cVar_gAX6mmnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z4NZzSxa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6kt8AWHU_sendMessage);
}

void Heavy_PhaseRing::cVar_1JpSKrMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_F5uhsLHl_sendMessage);
}

void Heavy_PhaseRing::cVar_q0VZLCDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_u3rratos_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_eW9BShOm, 0, m, &cIf_eW9BShOm_sendMessage);
}

void Heavy_PhaseRing::cVar_uJUXRS0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_eAkuXLVR_sendMessage);
}

void Heavy_PhaseRing::cIf_eW9BShOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_CcCGGduI_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_0B5UB2A9, 0, m, &cVar_0B5UB2A9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_u3rratos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eW9BShOm, 1, m, &cIf_eW9BShOm_sendMessage);
}

void Heavy_PhaseRing::cBinop_eAkuXLVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ApROMOZc_sendMessage);
}

void Heavy_PhaseRing::cBinop_ApROMOZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aKeeEg34, 0, m, &cVar_aKeeEg34_sendMessage);
}

void Heavy_PhaseRing::cTabhead_CJVfSWQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fjBWJfkQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_fjBWJfkQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_Po22Mk8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_d6hJlx2p_sendMessage);
}

void Heavy_PhaseRing::cSystem_d6hJlx2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zuqq7Ozv_sendMessage);
}

void Heavy_PhaseRing::cVar_T5ZaXecQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_746e8O0u_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_NzDPZ5ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NzDPZ5ro, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kki6Rj5Z, 0, m, &cDelay_Kki6Rj5Z_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_i0nUPV0N, 0, m, &sTabread_i0nUPV0N_sendMessage);
}

void Heavy_PhaseRing::cDelay_Kki6Rj5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Kki6Rj5Z, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_i0nUPV0N, 0, m, &sTabread_i0nUPV0N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kki6Rj5Z, 0, m, &cDelay_Kki6Rj5Z_sendMessage);
}

void Heavy_PhaseRing::sTabread_i0nUPV0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_W5lGQtOq, HV_BINOP_SUBTRACT, 0, m, &cBinop_W5lGQtOq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_xwR2qYe7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yaJmEFHR, HV_BINOP_MAX, 0, m, &cBinop_yaJmEFHR_sendMessage);
}

void Heavy_PhaseRing::cBinop_zuqq7Ozv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xwR2qYe7, HV_BINOP_MULTIPLY, 0, m, &cBinop_xwR2qYe7_sendMessage);
}

void Heavy_PhaseRing::cBinop_fjBWJfkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NlrRl0xQ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_i0nUPV0N, 0, m, &sTabread_i0nUPV0N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QIV2ZSMN_sendMessage);
}

void Heavy_PhaseRing::cSystem_ibQdsnTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W5lGQtOq, HV_BINOP_SUBTRACT, 1, m, &cBinop_W5lGQtOq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kki6Rj5Z, 2, m, &cDelay_Kki6Rj5Z_sendMessage);
}

void Heavy_PhaseRing::cMsg_746e8O0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ibQdsnTq_sendMessage);
}

void Heavy_PhaseRing::cMsg_NlrRl0xQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NzDPZ5ro, 0, m, &cDelay_NzDPZ5ro_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kki6Rj5Z, 0, m, &cDelay_Kki6Rj5Z_sendMessage);
}

void Heavy_PhaseRing::cMsg_8CN40sr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_yaJmEFHR, HV_BINOP_MAX, 1, m, &cBinop_yaJmEFHR_sendMessage);
}

void Heavy_PhaseRing::cBinop_yaJmEFHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fjBWJfkQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_fjBWJfkQ_sendMessage);
}

void Heavy_PhaseRing::cCast_QIV2ZSMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NzDPZ5ro, 0, m, &cDelay_NzDPZ5ro_sendMessage);
}

void Heavy_PhaseRing::cBinop_taguqksV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NzDPZ5ro, 2, m, &cDelay_NzDPZ5ro_sendMessage);
}

void Heavy_PhaseRing::cBinop_W5lGQtOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_taguqksV_sendMessage);
}

void Heavy_PhaseRing::cCast_ooskNTWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T5ZaXecQ, 0, m, &cVar_T5ZaXecQ_sendMessage);
  cMsg_Po22Mk8l_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_CJVfSWQs, 0, m, &cTabhead_CJVfSWQs_sendMessage);
}

void Heavy_PhaseRing::cMsg_EAgyP3Ut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k9MQv7i0_sendMessage);
}

void Heavy_PhaseRing::cSystem_k9MQv7i0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GFO1KioR_sendMessage);
}

void Heavy_PhaseRing::cDelay_BlpMBaE6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BlpMBaE6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_F4mHZQL3, 0, m, &cDelay_F4mHZQL3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlpMBaE6, 0, m, &cDelay_BlpMBaE6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pwvPJ18S, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_F4mHZQL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_F4mHZQL3, m);
  cMsg_u7vP3PT1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_e5DBhl2c_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_msEIWo7n_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_uuVxRCUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tLhf2wUz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_uHbLv3ZI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_28EHEo54_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlpMBaE6, 2, m, &cDelay_BlpMBaE6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wKKvzhLd_sendMessage);
}

void Heavy_PhaseRing::cMsg_tLhf2wUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_uHbLv3ZI, 0, m, &hTable_uHbLv3ZI_sendMessage);
}

void Heavy_PhaseRing::cBinop_GFO1KioR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_uuVxRCUW_sendMessage);
}

void Heavy_PhaseRing::cMsg_u7vP3PT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_uHbLv3ZI, 0, m, &hTable_uHbLv3ZI_sendMessage);
}

void Heavy_PhaseRing::cCast_wKKvzhLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlpMBaE6, 0, m, &cDelay_BlpMBaE6_sendMessage);
}

void Heavy_PhaseRing::cMsg_28EHEo54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_F4mHZQL3, 2, m, &cDelay_F4mHZQL3_sendMessage);
}

void Heavy_PhaseRing::cMsg_msEIWo7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pwvPJ18S, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_Npn5Gs7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R51UWAQr, HV_BINOP_SUBTRACT, 0, m, &cBinop_R51UWAQr_sendMessage);
}

void Heavy_PhaseRing::cMsg_gb66HVi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6Z6470Tn_sendMessage);
}

void Heavy_PhaseRing::cSystem_6Z6470Tn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_F2SfeFaV_sendMessage);
}

void Heavy_PhaseRing::cVar_xlR6cb7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RamTy9t7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_8j1gQ198_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8j1gQ198, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8wJgRt2M, 0, m, &cDelay_8wJgRt2M_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fHleRiW7, 0, m, &sTabread_fHleRiW7_sendMessage);
}

void Heavy_PhaseRing::cDelay_8wJgRt2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8wJgRt2M, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fHleRiW7, 0, m, &sTabread_fHleRiW7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8wJgRt2M, 0, m, &cDelay_8wJgRt2M_sendMessage);
}

void Heavy_PhaseRing::sTabread_fHleRiW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9oRiTY2W, HV_BINOP_SUBTRACT, 0, m, &cBinop_9oRiTY2W_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_RLmGRtXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WWPq2cFi, HV_BINOP_MAX, 0, m, &cBinop_WWPq2cFi_sendMessage);
}

void Heavy_PhaseRing::cBinop_F2SfeFaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RLmGRtXy, HV_BINOP_MULTIPLY, 0, m, &cBinop_RLmGRtXy_sendMessage);
}

void Heavy_PhaseRing::cBinop_R51UWAQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qdFIS1LV_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fHleRiW7, 0, m, &sTabread_fHleRiW7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ninSlHDC_sendMessage);
}

void Heavy_PhaseRing::cSystem_r0UNVcs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9oRiTY2W, HV_BINOP_SUBTRACT, 1, m, &cBinop_9oRiTY2W_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8wJgRt2M, 2, m, &cDelay_8wJgRt2M_sendMessage);
}

void Heavy_PhaseRing::cMsg_RamTy9t7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r0UNVcs4_sendMessage);
}

void Heavy_PhaseRing::cMsg_qdFIS1LV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8j1gQ198, 0, m, &cDelay_8j1gQ198_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8wJgRt2M, 0, m, &cDelay_8wJgRt2M_sendMessage);
}

void Heavy_PhaseRing::cMsg_3uTgDFtf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_WWPq2cFi, HV_BINOP_MAX, 1, m, &cBinop_WWPq2cFi_sendMessage);
}

void Heavy_PhaseRing::cBinop_WWPq2cFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R51UWAQr, HV_BINOP_SUBTRACT, 1, m, &cBinop_R51UWAQr_sendMessage);
}

void Heavy_PhaseRing::cCast_ninSlHDC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8j1gQ198, 0, m, &cDelay_8j1gQ198_sendMessage);
}

void Heavy_PhaseRing::cBinop_gZrvhRju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8j1gQ198, 2, m, &cDelay_8j1gQ198_sendMessage);
}

void Heavy_PhaseRing::cBinop_9oRiTY2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gZrvhRju_sendMessage);
}

void Heavy_PhaseRing::cCast_dsHAkieK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xlR6cb7z, 0, m, &cVar_xlR6cb7z_sendMessage);
  cMsg_gb66HVi5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Npn5Gs7X, 0, m, &cTabhead_Npn5Gs7X_sendMessage);
}

void Heavy_PhaseRing::cMsg_MZ9nrwDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_o0iYRvlM_sendMessage);
}

void Heavy_PhaseRing::cSystem_o0iYRvlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_A9RYv0UN_sendMessage);
}

void Heavy_PhaseRing::cDelay_ZVKdIE8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZVKdIE8i, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IaTgcD0g, 0, m, &cDelay_IaTgcD0g_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZVKdIE8i, 0, m, &cDelay_ZVKdIE8i_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vwhKMr0I, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_IaTgcD0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IaTgcD0g, m);
  cMsg_tceHnzig_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_ZwX9hY0l_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Orghejos_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_hr4XoW6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u9ZXALqi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_0xMUdkpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f243guK9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZVKdIE8i, 2, m, &cDelay_ZVKdIE8i_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ev6phSPO_sendMessage);
}

void Heavy_PhaseRing::cMsg_u9ZXALqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_0xMUdkpu, 0, m, &hTable_0xMUdkpu_sendMessage);
}

void Heavy_PhaseRing::cBinop_A9RYv0UN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_hr4XoW6K_sendMessage);
}

void Heavy_PhaseRing::cMsg_tceHnzig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_0xMUdkpu, 0, m, &hTable_0xMUdkpu_sendMessage);
}

void Heavy_PhaseRing::cCast_ev6phSPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZVKdIE8i, 0, m, &cDelay_ZVKdIE8i_sendMessage);
}

void Heavy_PhaseRing::cMsg_f243guK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_IaTgcD0g, 2, m, &cDelay_IaTgcD0g_sendMessage);
}

void Heavy_PhaseRing::cMsg_Orghejos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vwhKMr0I, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_ZV8Ypr3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X6H0L9tN, HV_BINOP_SUBTRACT, 0, m, &cBinop_X6H0L9tN_sendMessage);
}

void Heavy_PhaseRing::cMsg_SrZxoiMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DjwG3vMG_sendMessage);
}

void Heavy_PhaseRing::cSystem_DjwG3vMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WN96z4hn_sendMessage);
}

void Heavy_PhaseRing::cVar_UDrWTyAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_koFV8hEu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_gYE5VDdm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gYE5VDdm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dmr82Y3U, 0, m, &cDelay_dmr82Y3U_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X0LsXJ8p, 0, m, &sTabread_X0LsXJ8p_sendMessage);
}

void Heavy_PhaseRing::cDelay_dmr82Y3U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dmr82Y3U, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X0LsXJ8p, 0, m, &sTabread_X0LsXJ8p_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dmr82Y3U, 0, m, &cDelay_dmr82Y3U_sendMessage);
}

void Heavy_PhaseRing::sTabread_X0LsXJ8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_EQUJcgeY, HV_BINOP_SUBTRACT, 0, m, &cBinop_EQUJcgeY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_yYwQhoDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kfAt7Rp7, HV_BINOP_MAX, 0, m, &cBinop_kfAt7Rp7_sendMessage);
}

void Heavy_PhaseRing::cBinop_WN96z4hn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yYwQhoDp, HV_BINOP_MULTIPLY, 0, m, &cBinop_yYwQhoDp_sendMessage);
}

void Heavy_PhaseRing::cBinop_X6H0L9tN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KoQU1tay_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X0LsXJ8p, 0, m, &sTabread_X0LsXJ8p_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zFwri0B7_sendMessage);
}

void Heavy_PhaseRing::cSystem_IvEj6v4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EQUJcgeY, HV_BINOP_SUBTRACT, 1, m, &cBinop_EQUJcgeY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dmr82Y3U, 2, m, &cDelay_dmr82Y3U_sendMessage);
}

void Heavy_PhaseRing::cMsg_koFV8hEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IvEj6v4C_sendMessage);
}

void Heavy_PhaseRing::cMsg_KoQU1tay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gYE5VDdm, 0, m, &cDelay_gYE5VDdm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dmr82Y3U, 0, m, &cDelay_dmr82Y3U_sendMessage);
}

void Heavy_PhaseRing::cMsg_Vp4LHSIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_kfAt7Rp7, HV_BINOP_MAX, 1, m, &cBinop_kfAt7Rp7_sendMessage);
}

void Heavy_PhaseRing::cBinop_kfAt7Rp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X6H0L9tN, HV_BINOP_SUBTRACT, 1, m, &cBinop_X6H0L9tN_sendMessage);
}

void Heavy_PhaseRing::cCast_zFwri0B7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gYE5VDdm, 0, m, &cDelay_gYE5VDdm_sendMessage);
}

void Heavy_PhaseRing::cBinop_sadbuZuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gYE5VDdm, 2, m, &cDelay_gYE5VDdm_sendMessage);
}

void Heavy_PhaseRing::cBinop_EQUJcgeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sadbuZuz_sendMessage);
}

void Heavy_PhaseRing::cCast_zZUjXveV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UDrWTyAM, 0, m, &cVar_UDrWTyAM_sendMessage);
  cMsg_SrZxoiMq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZV8Ypr3I, 0, m, &cTabhead_ZV8Ypr3I_sendMessage);
}

void Heavy_PhaseRing::cMsg_QPmIw1sa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qg8R9z5t_sendMessage);
}

void Heavy_PhaseRing::cSystem_Qg8R9z5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_djnjqTR1_sendMessage);
}

void Heavy_PhaseRing::cDelay_dICYFjpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dICYFjpK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TBrJIwhT, 0, m, &cDelay_TBrJIwhT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dICYFjpK, 0, m, &cDelay_dICYFjpK_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qtj81PRF, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_TBrJIwhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TBrJIwhT, m);
  cMsg_zmVFwpVz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_1pNicOwL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_RbIRUOtx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_zhinpLIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xjLhQAeG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_p0Gq1zlL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RAWkbZlb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dICYFjpK, 2, m, &cDelay_dICYFjpK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dfvSxMeL_sendMessage);
}

void Heavy_PhaseRing::cMsg_xjLhQAeG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_p0Gq1zlL, 0, m, &hTable_p0Gq1zlL_sendMessage);
}

void Heavy_PhaseRing::cBinop_djnjqTR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_zhinpLIY_sendMessage);
}

void Heavy_PhaseRing::cMsg_zmVFwpVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_p0Gq1zlL, 0, m, &hTable_p0Gq1zlL_sendMessage);
}

void Heavy_PhaseRing::cCast_dfvSxMeL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dICYFjpK, 0, m, &cDelay_dICYFjpK_sendMessage);
}

void Heavy_PhaseRing::cMsg_RAWkbZlb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_TBrJIwhT, 2, m, &cDelay_TBrJIwhT_sendMessage);
}

void Heavy_PhaseRing::cMsg_RbIRUOtx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qtj81PRF, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_oNNWyJxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zKYsUZiI, HV_BINOP_SUBTRACT, 0, m, &cBinop_zKYsUZiI_sendMessage);
}

void Heavy_PhaseRing::cMsg_tgHH6F6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WFGCEAxw_sendMessage);
}

void Heavy_PhaseRing::cSystem_WFGCEAxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VmaiJBxT_sendMessage);
}

void Heavy_PhaseRing::cVar_BxllU1k2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x8DU0qdu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_CIQ1Cu1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CIQ1Cu1m, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NO6QXvFX, 0, m, &cDelay_NO6QXvFX_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qRhYlQLm, 0, m, &sTabread_qRhYlQLm_sendMessage);
}

void Heavy_PhaseRing::cDelay_NO6QXvFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NO6QXvFX, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qRhYlQLm, 0, m, &sTabread_qRhYlQLm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NO6QXvFX, 0, m, &cDelay_NO6QXvFX_sendMessage);
}

void Heavy_PhaseRing::sTabread_qRhYlQLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Yo5dYA0S, HV_BINOP_SUBTRACT, 0, m, &cBinop_Yo5dYA0S_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_c0Ol9jr8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LX1YMRf0, HV_BINOP_MAX, 0, m, &cBinop_LX1YMRf0_sendMessage);
}

void Heavy_PhaseRing::cBinop_VmaiJBxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c0Ol9jr8, HV_BINOP_MULTIPLY, 0, m, &cBinop_c0Ol9jr8_sendMessage);
}

void Heavy_PhaseRing::cBinop_zKYsUZiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pH6F4bin_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qRhYlQLm, 0, m, &sTabread_qRhYlQLm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OjNqyj1S_sendMessage);
}

void Heavy_PhaseRing::cSystem_BoUL2S4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yo5dYA0S, HV_BINOP_SUBTRACT, 1, m, &cBinop_Yo5dYA0S_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NO6QXvFX, 2, m, &cDelay_NO6QXvFX_sendMessage);
}

void Heavy_PhaseRing::cMsg_x8DU0qdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BoUL2S4n_sendMessage);
}

void Heavy_PhaseRing::cMsg_pH6F4bin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CIQ1Cu1m, 0, m, &cDelay_CIQ1Cu1m_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NO6QXvFX, 0, m, &cDelay_NO6QXvFX_sendMessage);
}

void Heavy_PhaseRing::cMsg_bfEedAqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_LX1YMRf0, HV_BINOP_MAX, 1, m, &cBinop_LX1YMRf0_sendMessage);
}

void Heavy_PhaseRing::cBinop_LX1YMRf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zKYsUZiI, HV_BINOP_SUBTRACT, 1, m, &cBinop_zKYsUZiI_sendMessage);
}

void Heavy_PhaseRing::cCast_OjNqyj1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CIQ1Cu1m, 0, m, &cDelay_CIQ1Cu1m_sendMessage);
}

void Heavy_PhaseRing::cBinop_UKe48WzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CIQ1Cu1m, 2, m, &cDelay_CIQ1Cu1m_sendMessage);
}

void Heavy_PhaseRing::cBinop_Yo5dYA0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UKe48WzK_sendMessage);
}

void Heavy_PhaseRing::cCast_0T2iEjJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BxllU1k2, 0, m, &cVar_BxllU1k2_sendMessage);
  cMsg_tgHH6F6t_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_oNNWyJxi, 0, m, &cTabhead_oNNWyJxi_sendMessage);
}

void Heavy_PhaseRing::cMsg_r1rHZCvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bcDqYJJp_sendMessage);
}

void Heavy_PhaseRing::cSystem_bcDqYJJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Tl36nlvB_sendMessage);
}

void Heavy_PhaseRing::cDelay_2Pra6bHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2Pra6bHw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ufiWnvyN, 0, m, &cDelay_ufiWnvyN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2Pra6bHw, 0, m, &cDelay_2Pra6bHw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JMfmRKr6, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_ufiWnvyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ufiWnvyN, m);
  cMsg_8sRK3bPE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_MpELinhT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_YtYZOWxT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_EicyKivQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qx4os6gG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_jDvbKOz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DZcgwL4f_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2Pra6bHw, 2, m, &cDelay_2Pra6bHw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iha1cMqR_sendMessage);
}

void Heavy_PhaseRing::cMsg_Qx4os6gG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jDvbKOz0, 0, m, &hTable_jDvbKOz0_sendMessage);
}

void Heavy_PhaseRing::cBinop_Tl36nlvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_EicyKivQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_8sRK3bPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jDvbKOz0, 0, m, &hTable_jDvbKOz0_sendMessage);
}

void Heavy_PhaseRing::cCast_iha1cMqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2Pra6bHw, 0, m, &cDelay_2Pra6bHw_sendMessage);
}

void Heavy_PhaseRing::cMsg_DZcgwL4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ufiWnvyN, 2, m, &cDelay_ufiWnvyN_sendMessage);
}

void Heavy_PhaseRing::cMsg_YtYZOWxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JMfmRKr6, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_MKr9R2kL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8LtSulAM, HV_BINOP_SUBTRACT, 0, m, &cBinop_8LtSulAM_sendMessage);
}

void Heavy_PhaseRing::cMsg_MoPMO3pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OLf7X0jF_sendMessage);
}

void Heavy_PhaseRing::cSystem_OLf7X0jF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NEtii4Ex_sendMessage);
}

void Heavy_PhaseRing::cVar_dUCQXc61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_38m0xwaz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_AARbjPMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AARbjPMx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BaoNAWoO, 0, m, &cDelay_BaoNAWoO_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KSlFr7mp, 0, m, &sTabread_KSlFr7mp_sendMessage);
}

void Heavy_PhaseRing::cDelay_BaoNAWoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BaoNAWoO, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KSlFr7mp, 0, m, &sTabread_KSlFr7mp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BaoNAWoO, 0, m, &cDelay_BaoNAWoO_sendMessage);
}

void Heavy_PhaseRing::sTabread_KSlFr7mp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LZJLYdJB, HV_BINOP_SUBTRACT, 0, m, &cBinop_LZJLYdJB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_WldOVrMD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kxqIhQSJ, HV_BINOP_MAX, 0, m, &cBinop_kxqIhQSJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_NEtii4Ex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WldOVrMD, HV_BINOP_MULTIPLY, 0, m, &cBinop_WldOVrMD_sendMessage);
}

void Heavy_PhaseRing::cBinop_8LtSulAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wx6haSEa_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KSlFr7mp, 0, m, &sTabread_KSlFr7mp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yD9z3vKa_sendMessage);
}

void Heavy_PhaseRing::cSystem_RK2V9lsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LZJLYdJB, HV_BINOP_SUBTRACT, 1, m, &cBinop_LZJLYdJB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BaoNAWoO, 2, m, &cDelay_BaoNAWoO_sendMessage);
}

void Heavy_PhaseRing::cMsg_38m0xwaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RK2V9lsX_sendMessage);
}

void Heavy_PhaseRing::cMsg_wx6haSEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_AARbjPMx, 0, m, &cDelay_AARbjPMx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BaoNAWoO, 0, m, &cDelay_BaoNAWoO_sendMessage);
}

void Heavy_PhaseRing::cMsg_Dxc6tkH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_kxqIhQSJ, HV_BINOP_MAX, 1, m, &cBinop_kxqIhQSJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_kxqIhQSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8LtSulAM, HV_BINOP_SUBTRACT, 1, m, &cBinop_8LtSulAM_sendMessage);
}

void Heavy_PhaseRing::cCast_yD9z3vKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AARbjPMx, 0, m, &cDelay_AARbjPMx_sendMessage);
}

void Heavy_PhaseRing::cBinop_u28lCFlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AARbjPMx, 2, m, &cDelay_AARbjPMx_sendMessage);
}

void Heavy_PhaseRing::cBinop_LZJLYdJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_u28lCFlF_sendMessage);
}

void Heavy_PhaseRing::cCast_BT9YuOqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dUCQXc61, 0, m, &cVar_dUCQXc61_sendMessage);
  cMsg_MoPMO3pc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MKr9R2kL, 0, m, &cTabhead_MKr9R2kL_sendMessage);
}

void Heavy_PhaseRing::cMsg_QGi0HWr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yr4KZDQL_sendMessage);
}

void Heavy_PhaseRing::cSystem_yr4KZDQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_znvTWbhw_sendMessage);
}

void Heavy_PhaseRing::cDelay_mCyHROzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mCyHROzX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_av2fMsqf, 0, m, &cDelay_av2fMsqf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCyHROzX, 0, m, &cDelay_mCyHROzX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_eoRIXOU8, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_av2fMsqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_av2fMsqf, m);
  cMsg_74qAMEpa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_1FoPq6e6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_5HXlBAMY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_MRXUKDhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JDeUNXsa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_w0g3xqJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KkskU2g0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCyHROzX, 2, m, &cDelay_mCyHROzX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9qrzCp0R_sendMessage);
}

void Heavy_PhaseRing::cMsg_JDeUNXsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_w0g3xqJH, 0, m, &hTable_w0g3xqJH_sendMessage);
}

void Heavy_PhaseRing::cBinop_znvTWbhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_MRXUKDhF_sendMessage);
}

void Heavy_PhaseRing::cMsg_74qAMEpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_w0g3xqJH, 0, m, &hTable_w0g3xqJH_sendMessage);
}

void Heavy_PhaseRing::cCast_9qrzCp0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mCyHROzX, 0, m, &cDelay_mCyHROzX_sendMessage);
}

void Heavy_PhaseRing::cMsg_KkskU2g0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_av2fMsqf, 2, m, &cDelay_av2fMsqf_sendMessage);
}

void Heavy_PhaseRing::cMsg_5HXlBAMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_eoRIXOU8, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_z8c866Q4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LmCQzUYh, HV_BINOP_SUBTRACT, 0, m, &cBinop_LmCQzUYh_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZkWEDH76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_J6AkBXRA_sendMessage);
}

void Heavy_PhaseRing::cSystem_J6AkBXRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vqMNjx1s_sendMessage);
}

void Heavy_PhaseRing::cVar_rV8IiApr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kTwgfWYT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_YWixhY0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YWixhY0I, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iinlJNcQ, 0, m, &cDelay_iinlJNcQ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AwhXa1Ng, 0, m, &sTabread_AwhXa1Ng_sendMessage);
}

void Heavy_PhaseRing::cDelay_iinlJNcQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iinlJNcQ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AwhXa1Ng, 0, m, &sTabread_AwhXa1Ng_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iinlJNcQ, 0, m, &cDelay_iinlJNcQ_sendMessage);
}

void Heavy_PhaseRing::sTabread_AwhXa1Ng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3sDkMlx1, HV_BINOP_SUBTRACT, 0, m, &cBinop_3sDkMlx1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_z7mLb2yA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_evTzH5f2, HV_BINOP_MAX, 0, m, &cBinop_evTzH5f2_sendMessage);
}

void Heavy_PhaseRing::cBinop_vqMNjx1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z7mLb2yA, HV_BINOP_MULTIPLY, 0, m, &cBinop_z7mLb2yA_sendMessage);
}

void Heavy_PhaseRing::cBinop_LmCQzUYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_56JidRjL_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AwhXa1Ng, 0, m, &sTabread_AwhXa1Ng_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bWy9J3Uo_sendMessage);
}

void Heavy_PhaseRing::cSystem_JSeAO2CV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3sDkMlx1, HV_BINOP_SUBTRACT, 1, m, &cBinop_3sDkMlx1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iinlJNcQ, 2, m, &cDelay_iinlJNcQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_kTwgfWYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JSeAO2CV_sendMessage);
}

void Heavy_PhaseRing::cMsg_56JidRjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YWixhY0I, 0, m, &cDelay_YWixhY0I_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iinlJNcQ, 0, m, &cDelay_iinlJNcQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_skKsyVJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_evTzH5f2, HV_BINOP_MAX, 1, m, &cBinop_evTzH5f2_sendMessage);
}

void Heavy_PhaseRing::cBinop_evTzH5f2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LmCQzUYh, HV_BINOP_SUBTRACT, 1, m, &cBinop_LmCQzUYh_sendMessage);
}

void Heavy_PhaseRing::cCast_bWy9J3Uo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YWixhY0I, 0, m, &cDelay_YWixhY0I_sendMessage);
}

void Heavy_PhaseRing::cBinop_Z59GUEhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YWixhY0I, 2, m, &cDelay_YWixhY0I_sendMessage);
}

void Heavy_PhaseRing::cBinop_3sDkMlx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Z59GUEhT_sendMessage);
}

void Heavy_PhaseRing::cCast_XrtfArSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rV8IiApr, 0, m, &cVar_rV8IiApr_sendMessage);
  cMsg_ZkWEDH76_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_z8c866Q4, 0, m, &cTabhead_z8c866Q4_sendMessage);
}

void Heavy_PhaseRing::cMsg_3NC0qn0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0dV2lR1Z_sendMessage);
}

void Heavy_PhaseRing::cSystem_0dV2lR1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_twoUjBIZ_sendMessage);
}

void Heavy_PhaseRing::cDelay_c7eD1oCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c7eD1oCg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HhxsQCX4, 0, m, &cDelay_HhxsQCX4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c7eD1oCg, 0, m, &cDelay_c7eD1oCg_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9oAWvycu, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_HhxsQCX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HhxsQCX4, m);
  cMsg_m7lFJIXf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_1cHDphSy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_B8VSRJU2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_RRZuOYDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z4MVFL3c_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_gngThHUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tN50sc65_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c7eD1oCg, 2, m, &cDelay_c7eD1oCg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CwYQQSgx_sendMessage);
}

void Heavy_PhaseRing::cMsg_Z4MVFL3c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gngThHUw, 0, m, &hTable_gngThHUw_sendMessage);
}

void Heavy_PhaseRing::cBinop_twoUjBIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_RRZuOYDa_sendMessage);
}

void Heavy_PhaseRing::cMsg_m7lFJIXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gngThHUw, 0, m, &hTable_gngThHUw_sendMessage);
}

void Heavy_PhaseRing::cCast_CwYQQSgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_c7eD1oCg, 0, m, &cDelay_c7eD1oCg_sendMessage);
}

void Heavy_PhaseRing::cMsg_tN50sc65_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_HhxsQCX4, 2, m, &cDelay_HhxsQCX4_sendMessage);
}

void Heavy_PhaseRing::cMsg_B8VSRJU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9oAWvycu, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_0B5UB2A9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wvqBiHyg, 0, m, &cVar_wvqBiHyg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tBuxNZDA, 0, m, &cVar_tBuxNZDA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zzIlLKFl, 0, m, &cVar_zzIlLKFl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GziR87yH, 0, m, &cVar_GziR87yH_sendMessage);
}

void Heavy_PhaseRing::cVar_aKeeEg34_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_4a65SLco_sendMessage);
}

void Heavy_PhaseRing::cPack_iF6cES8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Jg3s4D1U, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_tBuxNZDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fun07543, HV_BINOP_MULTIPLY, 0, m, &cBinop_Fun07543_sendMessage);
}

void Heavy_PhaseRing::cMsg_cUla9zMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RNF47l3z_sendMessage);
}

void Heavy_PhaseRing::cSystem_RNF47l3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZpnobyWN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Fun07543_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_3uaecrLy_sendMessage);
}

void Heavy_PhaseRing::cBinop_O2fMfVXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fun07543, HV_BINOP_MULTIPLY, 1, m, &cBinop_Fun07543_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZpnobyWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_O2fMfVXb_sendMessage);
}

void Heavy_PhaseRing::cBinop_3uaecrLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ncU3JVrk_sendMessage);
}

void Heavy_PhaseRing::cBinop_ncU3JVrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Q2Tteml0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WxuCPDrV, m);
}

void Heavy_PhaseRing::cBinop_Q2Tteml0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_grFrKiK8, m);
}

void Heavy_PhaseRing::cVar_zzIlLKFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eWbVX0cP, HV_BINOP_MULTIPLY, 0, m, &cBinop_eWbVX0cP_sendMessage);
}

void Heavy_PhaseRing::cMsg_CDudzBJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WLbMDbxQ_sendMessage);
}

void Heavy_PhaseRing::cSystem_WLbMDbxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9sveGUBR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_eWbVX0cP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KyIxcsWW_sendMessage);
}

void Heavy_PhaseRing::cBinop_5IVDVhRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eWbVX0cP, HV_BINOP_MULTIPLY, 1, m, &cBinop_eWbVX0cP_sendMessage);
}

void Heavy_PhaseRing::cMsg_9sveGUBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5IVDVhRp_sendMessage);
}

void Heavy_PhaseRing::cBinop_KyIxcsWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cuB1QULe_sendMessage);
}

void Heavy_PhaseRing::cBinop_cuB1QULe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_v7qFsS8o_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xV2AZBCF, m);
}

void Heavy_PhaseRing::cBinop_v7qFsS8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3TRoGytN, m);
}

void Heavy_PhaseRing::cVar_GziR87yH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_joHR4093, HV_BINOP_MULTIPLY, 0, m, &cBinop_joHR4093_sendMessage);
}

void Heavy_PhaseRing::cMsg_sx3ZL2lQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NuHr5IdD_sendMessage);
}

void Heavy_PhaseRing::cSystem_NuHr5IdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sMC1AOpT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_joHR4093_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_TJGDNVbw_sendMessage);
}

void Heavy_PhaseRing::cBinop_oEblPzBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_joHR4093, HV_BINOP_MULTIPLY, 1, m, &cBinop_joHR4093_sendMessage);
}

void Heavy_PhaseRing::cMsg_sMC1AOpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_oEblPzBF_sendMessage);
}

void Heavy_PhaseRing::cBinop_TJGDNVbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZGG3vwEJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZGG3vwEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FcYGyucF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_oAzfR1Fg, m);
}

void Heavy_PhaseRing::cBinop_FcYGyucF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3WwDXyzG, m);
}

void Heavy_PhaseRing::cBinop_CObgDnAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_y7gfsDlF, 0, m, &cPack_y7gfsDlF_sendMessage);
}

void Heavy_PhaseRing::cMsg_CcCGGduI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_0B5UB2A9, 0, m, &cVar_0B5UB2A9_sendMessage);
}

void Heavy_PhaseRing::cBinop_4a65SLco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_iF6cES8k, 0, m, &cPack_iF6cES8k_sendMessage);
}

void Heavy_PhaseRing::cBinop_NkHVzP6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f44vPekf, 0, m, &cPack_f44vPekf_sendMessage);
}

void Heavy_PhaseRing::cMsg_4wKnBs3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WJfs6vy6_sendMessage);
}

void Heavy_PhaseRing::cSystem_WJfs6vy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cdJIXzFw_sendMessage);
}

void Heavy_PhaseRing::cVar_BIO8G4ji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3UxV7klq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_O67dNutX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2vGI0w5g_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JOZkTfsK, m);
}

void Heavy_PhaseRing::cBinop_cdJIXzFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9R8cTYmr, m);
}

void Heavy_PhaseRing::cMsg_3UxV7klq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_O67dNutX_sendMessage);
}

void Heavy_PhaseRing::cBinop_2vGI0w5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wt7Hf6Y5, m);
}

void Heavy_PhaseRing::cVar_zVoFtlE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sly4pc9z, HV_BINOP_MULTIPLY, 0, m, &cBinop_sly4pc9z_sendMessage);
}

void Heavy_PhaseRing::cMsg_LJUok0ys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DFl2wJLP_sendMessage);
}

void Heavy_PhaseRing::cSystem_DFl2wJLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wWcoTUb4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_sly4pc9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jXdSXXTU_sendMessage);
}

void Heavy_PhaseRing::cBinop_2VJyk1R5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sly4pc9z, HV_BINOP_MULTIPLY, 1, m, &cBinop_sly4pc9z_sendMessage);
}

void Heavy_PhaseRing::cMsg_wWcoTUb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_2VJyk1R5_sendMessage);
}

void Heavy_PhaseRing::cBinop_jXdSXXTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LsBADStk_sendMessage);
}

void Heavy_PhaseRing::cBinop_LsBADStk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_UXeeU2zV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ImIXwPOC, m);
}

void Heavy_PhaseRing::cBinop_UXeeU2zV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ysHOOdUa, m);
}

void Heavy_PhaseRing::cBinop_5NNBnLSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_o3wXqEd2_sendMessage);
}

void Heavy_PhaseRing::cBinop_o3wXqEd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1ADVNZeK, m);
}

void Heavy_PhaseRing::cBinop_ZkkoTQGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wyNrXt2V_sendMessage);
}

void Heavy_PhaseRing::cBinop_wyNrXt2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_LPMiEGf1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OJ7nKVfO_sendMessage);
}

void Heavy_PhaseRing::cVar_3CuIpagK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_9O7prKmS_sendMessage);
}

void Heavy_PhaseRing::cMsg_BDRtcNdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2HDjU5e7_sendMessage);
}

void Heavy_PhaseRing::cSystem_2HDjU5e7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qNnsMkXV, HV_BINOP_DIVIDE, 1, m, &cBinop_qNnsMkXV_sendMessage);
}

void Heavy_PhaseRing::cBinop_LPMiEGf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_AS9Egl69_sendMessage);
}

void Heavy_PhaseRing::cBinop_AS9Egl69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PaWux6rN, m);
}

void Heavy_PhaseRing::cMsg_9a1LI9Z0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_EWkNCtu8_sendMessage);
}

void Heavy_PhaseRing::cBinop_EWkNCtu8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ZkkoTQGa_sendMessage);
}

void Heavy_PhaseRing::cBinop_OJ7nKVfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xpuR5GTl, m);
}

void Heavy_PhaseRing::cBinop_9O7prKmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_GikYo5QJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_GikYo5QJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qNnsMkXV, HV_BINOP_DIVIDE, 0, m, &cBinop_qNnsMkXV_sendMessage);
}

void Heavy_PhaseRing::cBinop_qNnsMkXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9a1LI9Z0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_JI1HgfyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KAXfElqm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_F6qPddP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L1s0dmZK_sendMessage);
}

void Heavy_PhaseRing::cSystem_L1s0dmZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vIKChtCq_sendMessage);
}

void Heavy_PhaseRing::cDelay_UsDyoL0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UsDyoL0f, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BQTxa2Co, 0, m, &cDelay_BQTxa2Co_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UsDyoL0f, 0, m, &cDelay_UsDyoL0f_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_XjpyiVUt, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_BQTxa2Co_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BQTxa2Co, m);
  cMsg_QEjJhoPq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_ggG7Sn5v_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_09feKrM6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_eqb939iQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5trN6vBt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_HKcO3eEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HsBd43I2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UsDyoL0f, 2, m, &cDelay_UsDyoL0f_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k702n8wq_sendMessage);
}

void Heavy_PhaseRing::cMsg_5trN6vBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_HKcO3eEe, 0, m, &hTable_HKcO3eEe_sendMessage);
}

void Heavy_PhaseRing::cBinop_vIKChtCq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_eqb939iQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_QEjJhoPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_HKcO3eEe, 0, m, &hTable_HKcO3eEe_sendMessage);
}

void Heavy_PhaseRing::cCast_k702n8wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UsDyoL0f, 0, m, &cDelay_UsDyoL0f_sendMessage);
}

void Heavy_PhaseRing::cMsg_HsBd43I2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BQTxa2Co, 2, m, &cDelay_BQTxa2Co_sendMessage);
}

void Heavy_PhaseRing::cMsg_09feKrM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_XjpyiVUt, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_gkNuj3dL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_KAXfElqm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_KAXfElqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_uLhRvkj8, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_sfplaFgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_dcyduFWh, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_6kmZl4Oo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sfplaFgE, 0, m, &cPack_sfplaFgE_sendMessage);
}

void Heavy_PhaseRing::cCast_MmHO53KN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SMgQxlua_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_L9mKBslp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dcyduFWh, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_8U4pKmJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_X5MvNE68, m);
}

void Heavy_PhaseRing::cMsg_Oa3pS19K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5NNBnLSB_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_j1PwZyrl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lM13Svxg, 0, m, &cSlice_lM13Svxg_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_IAVFoM2H, 0, m, &cRandom_IAVFoM2H_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_WS40tlYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_EWdc69BV_sendMessage);
}

void Heavy_PhaseRing::cUnop_EWdc69BV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_pvVwwT0n_sendMessage);
}

void Heavy_PhaseRing::cRandom_IAVFoM2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_WS40tlYL_sendMessage);
}

void Heavy_PhaseRing::cSlice_lM13Svxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_IAVFoM2H, 1, m, &cRandom_IAVFoM2H_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_80B2cjdr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VVCvEaDV, 0, m, &cSlice_VVCvEaDV_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ld5vbcrm, 0, m, &cRandom_Ld5vbcrm_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ju0VvbOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QItpe9a5_sendMessage);
}

void Heavy_PhaseRing::cUnop_QItpe9a5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bUnTBK9z, 0, m, &cPack_bUnTBK9z_sendMessage);
}

void Heavy_PhaseRing::cRandom_Ld5vbcrm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_ju0VvbOS_sendMessage);
}

void Heavy_PhaseRing::cSlice_VVCvEaDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ld5vbcrm, 1, m, &cRandom_Ld5vbcrm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_qcKmFLAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_b2k9Ux1n_sendMessage);
}

void Heavy_PhaseRing::cPack_TDllDUMv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_FWHXK7UL, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_oqpHB2LL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nyYlX345_sendMessage);
}

void Heavy_PhaseRing::cBinop_rqQzxEB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_oqpHB2LL_sendMessage);
}

void Heavy_PhaseRing::cPack_YornEpoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_NYkFsGOG, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_Aoz0Ylud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_rE1s6iiO_sendMessage);
}

void Heavy_PhaseRing::cMsg_NyMMVlDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_g9NMcp7o_sendMessage);
}

void Heavy_PhaseRing::cSystem_g9NMcp7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Aza9Ob0i_sendMessage);
}

void Heavy_PhaseRing::cDelay_7eDCLKg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7eDCLKg7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iHx9K2Xl, 0, m, &cDelay_iHx9K2Xl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7eDCLKg7, 0, m, &cDelay_7eDCLKg7_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zZeUuENe, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_iHx9K2Xl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iHx9K2Xl, m);
  cMsg_lBKPJKtS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_q70G1Ccq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_x3uMLo8t_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_Ti5DQCkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wICxhwSb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_8vLYIp60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_62p0649t_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7eDCLKg7, 2, m, &cDelay_7eDCLKg7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SbCdeCut_sendMessage);
}

void Heavy_PhaseRing::cMsg_wICxhwSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_8vLYIp60, 0, m, &hTable_8vLYIp60_sendMessage);
}

void Heavy_PhaseRing::cBinop_Aza9Ob0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_Ti5DQCkw_sendMessage);
}

void Heavy_PhaseRing::cMsg_lBKPJKtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_8vLYIp60, 0, m, &hTable_8vLYIp60_sendMessage);
}

void Heavy_PhaseRing::cCast_SbCdeCut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7eDCLKg7, 0, m, &cDelay_7eDCLKg7_sendMessage);
}

void Heavy_PhaseRing::cMsg_62p0649t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_iHx9K2Xl, 2, m, &cDelay_iHx9K2Xl_sendMessage);
}

void Heavy_PhaseRing::cMsg_x3uMLo8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zZeUuENe, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_ATVacbbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OWPcvjGm_sendMessage);
}

void Heavy_PhaseRing::cSystem_OWPcvjGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rWk0WrWw_sendMessage);
}

void Heavy_PhaseRing::cVar_SNN4ljMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2Itue36m_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_38oMgaPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6PcqS1bD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VVRMQJZm, m);
}

void Heavy_PhaseRing::cBinop_rWk0WrWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LeT5vdn3, m);
}

void Heavy_PhaseRing::cMsg_2Itue36m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_38oMgaPC_sendMessage);
}

void Heavy_PhaseRing::cBinop_6PcqS1bD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bWhtdLBz, m);
}

void Heavy_PhaseRing::cMsg_hzaZefnQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9zlVsT5L_sendMessage);
}

void Heavy_PhaseRing::cSystem_9zlVsT5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_g8dG7MvP_sendMessage);
}

void Heavy_PhaseRing::cVar_5sULwvJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SWkGhH9O_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_3ucnHP0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fYvhQrXN_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qiUpTbwx, m);
}

void Heavy_PhaseRing::cBinop_g8dG7MvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_c8UOcUI6, m);
}

void Heavy_PhaseRing::cMsg_SWkGhH9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3ucnHP0S_sendMessage);
}

void Heavy_PhaseRing::cBinop_fYvhQrXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GKpB4cI1, m);
}

void Heavy_PhaseRing::cBinop_UVnEHB5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VCO0I85j_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_9P1kPPY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mFFf8Yed_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DxmxwoP9_sendMessage);
}

void Heavy_PhaseRing::cCast_DxmxwoP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UVnEHB5Y, HV_BINOP_DIVIDE, 0, m, &cBinop_UVnEHB5Y_sendMessage);
}

void Heavy_PhaseRing::cCast_mFFf8Yed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UVnEHB5Y, HV_BINOP_DIVIDE, 1, m, &cBinop_UVnEHB5Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_nyYlX345_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FLiLsdnA_sendMessage);
}

void Heavy_PhaseRing::cBinop_6UDwFnct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_rqQzxEB0_sendMessage);
}

void Heavy_PhaseRing::cBinop_FLiLsdnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UVnEHB5Y, HV_BINOP_DIVIDE, 0, m, &cBinop_UVnEHB5Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_rE1s6iiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YornEpoA, 0, m, &cPack_YornEpoA_sendMessage);
}

void Heavy_PhaseRing::cBinop_b2k9Ux1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_9P1kPPY8_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_TDllDUMv, 0, m, &cPack_TDllDUMv_sendMessage);
}

void Heavy_PhaseRing::cMsg_SyuQyLGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_qcKmFLAu, 0, m, &cVar_qcKmFLAu_sendMessage);
}

void Heavy_PhaseRing::cMsg_17rWQso0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_Aoz0Ylud, 0, m, &cVar_Aoz0Ylud_sendMessage);
}

void Heavy_PhaseRing::cMsg_VCO0I85j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_kQZ4WyTN, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_Nhy1G4I9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VUPHnekU_sendMessage);
}

void Heavy_PhaseRing::cSystem_VUPHnekU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XfN3h339_sendMessage);
}

void Heavy_PhaseRing::cVar_DE55hnrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8Ao7VFzw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_wyrLuIxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_7P7YM8NG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Llk9n9su, m);
}

void Heavy_PhaseRing::cBinop_XfN3h339_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zaKt4Hps, m);
}

void Heavy_PhaseRing::cMsg_8Ao7VFzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wyrLuIxh_sendMessage);
}

void Heavy_PhaseRing::cBinop_7P7YM8NG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_00zQrgip, m);
}

void Heavy_PhaseRing::cVar_p2amF8mZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sJiN9tn3, HV_BINOP_MULTIPLY, 0, m, &cBinop_sJiN9tn3_sendMessage);
}

void Heavy_PhaseRing::cMsg_Po9tEiEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_USBryAXD_sendMessage);
}

void Heavy_PhaseRing::cSystem_USBryAXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1GVCOKhn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_sJiN9tn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_HAxzgn5N_sendMessage);
}

void Heavy_PhaseRing::cBinop_rvZgWHCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sJiN9tn3, HV_BINOP_MULTIPLY, 1, m, &cBinop_sJiN9tn3_sendMessage);
}

void Heavy_PhaseRing::cMsg_1GVCOKhn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rvZgWHCo_sendMessage);
}

void Heavy_PhaseRing::cBinop_HAxzgn5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_JpNvrHew_sendMessage);
}

void Heavy_PhaseRing::cBinop_JpNvrHew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tWLnU45Z_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_boDQkf3r, m);
}

void Heavy_PhaseRing::cBinop_tWLnU45Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RB5vETCB, m);
}

void Heavy_PhaseRing::cBinop_p1YMhKm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_quSgqIoG_sendMessage);
}

void Heavy_PhaseRing::cBinop_quSgqIoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Fstt3lug, m);
}

void Heavy_PhaseRing::cBinop_JIwgz8Rj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GgjSRFm7_sendMessage);
}

void Heavy_PhaseRing::cBinop_GgjSRFm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_1KnDavBe_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JU8tKZF4_sendMessage);
}

void Heavy_PhaseRing::cVar_IlGYwPwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4Mhk4HF5_sendMessage);
}

void Heavy_PhaseRing::cMsg_qKiZx5a6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gyDO3Q7m_sendMessage);
}

void Heavy_PhaseRing::cSystem_gyDO3Q7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HXcnvIkw, HV_BINOP_DIVIDE, 1, m, &cBinop_HXcnvIkw_sendMessage);
}

void Heavy_PhaseRing::cBinop_1KnDavBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Qy0eotXI_sendMessage);
}

void Heavy_PhaseRing::cBinop_Qy0eotXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GW74Pjns, m);
}

void Heavy_PhaseRing::cMsg_SZuH3XgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Xk1DHuWm_sendMessage);
}

void Heavy_PhaseRing::cBinop_Xk1DHuWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_JIwgz8Rj_sendMessage);
}

void Heavy_PhaseRing::cBinop_JU8tKZF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JsFdbytZ, m);
}

void Heavy_PhaseRing::cBinop_4Mhk4HF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_qBRM3q4r_sendMessage);
}

void Heavy_PhaseRing::cBinop_qBRM3q4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HXcnvIkw, HV_BINOP_DIVIDE, 0, m, &cBinop_HXcnvIkw_sendMessage);
}

void Heavy_PhaseRing::cBinop_HXcnvIkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SZuH3XgM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_FLupumKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v8GVDYk1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_juVjzCey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pMeezuCu_sendMessage);
}

void Heavy_PhaseRing::cSystem_pMeezuCu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EcYQjEzF_sendMessage);
}

void Heavy_PhaseRing::cDelay_DZa1FVMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DZa1FVMj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iiPJHDNo, 0, m, &cDelay_iiPJHDNo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DZa1FVMj, 0, m, &cDelay_DZa1FVMj_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gLnBb38i, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_iiPJHDNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iiPJHDNo, m);
  cMsg_eGmW4QKc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_t0AonGx1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_9rc5u8mB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_DdH4dwjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lkq3vbNW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_lLISmVYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qNgvGaoZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DZa1FVMj, 2, m, &cDelay_DZa1FVMj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XskGf5Fi_sendMessage);
}

void Heavy_PhaseRing::cMsg_Lkq3vbNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_lLISmVYz, 0, m, &hTable_lLISmVYz_sendMessage);
}

void Heavy_PhaseRing::cBinop_EcYQjEzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_DdH4dwjv_sendMessage);
}

void Heavy_PhaseRing::cMsg_eGmW4QKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_lLISmVYz, 0, m, &hTable_lLISmVYz_sendMessage);
}

void Heavy_PhaseRing::cCast_XskGf5Fi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DZa1FVMj, 0, m, &cDelay_DZa1FVMj_sendMessage);
}

void Heavy_PhaseRing::cMsg_qNgvGaoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_iiPJHDNo, 2, m, &cDelay_iiPJHDNo_sendMessage);
}

void Heavy_PhaseRing::cMsg_9rc5u8mB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gLnBb38i, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_AvpiLTVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_v8GVDYk1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_v8GVDYk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_zJD1I8kT, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_fxBTFh90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_Zmi38Qsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kiZ7QQwV_sendMessage);
}

void Heavy_PhaseRing::cSystem_kiZ7QQwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jKxVdelU, HV_BINOP_MULTIPLY, 1, m, &cBinop_jKxVdelU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GQi2OUzv, HV_BINOP_MULTIPLY, 1, m, &cBinop_GQi2OUzv_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_ukAbrRSU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_B3xhFaoK_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_B3xhFaoK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nx4QuXv1_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_R9eMiN6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_R9eMiN6y, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_R9eMiN6y, 0, m, &cDelay_R9eMiN6y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8dNTxIif, 0, m, &cVar_8dNTxIif_sendMessage);
}

void Heavy_PhaseRing::cCast_nx4QuXv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B3xhFaoK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_R9eMiN6y, 0, m, &cDelay_R9eMiN6y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8dNTxIif, 0, m, &cVar_8dNTxIif_sendMessage);
}

void Heavy_PhaseRing::cMsg_a5Af2hQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9Q9coDMP_sendMessage);
}

void Heavy_PhaseRing::cSystem_9Q9coDMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2gjAiS3o_sendMessage);
}

void Heavy_PhaseRing::cVar_9eqcpuUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vU0POHY3, HV_BINOP_MULTIPLY, 0, m, &cBinop_vU0POHY3_sendMessage);
}

void Heavy_PhaseRing::cMsg_B3xhFaoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_R9eMiN6y, 0, m, &cDelay_R9eMiN6y_sendMessage);
}

void Heavy_PhaseRing::cBinop_kHTSmZVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_R9eMiN6y, 2, m, &cDelay_R9eMiN6y_sendMessage);
}

void Heavy_PhaseRing::cBinop_2gjAiS3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vU0POHY3, HV_BINOP_MULTIPLY, 1, m, &cBinop_vU0POHY3_sendMessage);
}

void Heavy_PhaseRing::cBinop_vU0POHY3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kHTSmZVH_sendMessage);
}

void Heavy_PhaseRing::cVar_8dNTxIif_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T75fuRPH, HV_BINOP_SUBTRACT, 0, m, &cBinop_T75fuRPH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_cdVYwNGd_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_paI1dnVy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4MLbfRhQ_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JJuxle6Q_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_4MLbfRhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vCAL56qD, 0, m, &cVar_vCAL56qD_sendMessage);
}

void Heavy_PhaseRing::cCast_JJuxle6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DaaaAOqb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7UQUV1Lh_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_HHTTv2KK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4T14f291, 0, m, &cSlice_4T14f291_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HzXEDruP, 0, m, &cSlice_HzXEDruP_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_peC88Qxs_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zsttKeH6, 0, m, &cSlice_zsttKeH6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_XLgsQqlr, 0, m, &cSlice_XLgsQqlr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fIwk2WKO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2bgv0O8J_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_4T14f291_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_29X8K2yf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_29X8K2yf_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_HzXEDruP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JLZrzvdK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fn9vuRFT_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JLZrzvdK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fn9vuRFT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_KgK9C7hY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GPDWarf9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bkLzPpyi_sendMessage);
}

void Heavy_PhaseRing::cVar_isgjVizP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7qiNqYzv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_7qiNqYzv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cyr41BYf_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jKxVdelU, HV_BINOP_MULTIPLY, 0, m, &cBinop_jKxVdelU_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_45LfvXrd, HV_BINOP_DIVIDE, 1, m, &cBinop_45LfvXrd_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_9eqcpuUT, 0, m, &cVar_9eqcpuUT_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_Cyr41BYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lrcf4ytd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_zdoYTd0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8iyfo9lO, HV_BINOP_SUBTRACT, 1, m, &cBinop_8iyfo9lO_sendMessage);
}

void Heavy_PhaseRing::cVar_EdryHjUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vCAL56qD, 0, m, &cVar_vCAL56qD_sendMessage);
}

void Heavy_PhaseRing::cVar_vCAL56qD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fYGK290I, HV_BINOP_ADD, 0, m, &cBinop_fYGK290I_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pJUAe0B5, HV_BINOP_ADD, 0, m, &cBinop_pJUAe0B5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NZislZMT, 0, m, &cVar_NZislZMT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_6UDwFnct_sendMessage);
}

void Heavy_PhaseRing::cSlice_zsttKeH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GPDWarf9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bkLzPpyi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_XLgsQqlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IcU1CU5f_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kmn3dYpT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Xeg3xDDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8dNTxIif, 1, m, &cVar_8dNTxIif_sendMessage);
}

void Heavy_PhaseRing::cBinop_GQi2OUzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Xeg3xDDB_sendMessage);
}

void Heavy_PhaseRing::cBinop_jKxVdelU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wAMzBmjZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_wAMzBmjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T75fuRPH, HV_BINOP_SUBTRACT, 1, m, &cBinop_T75fuRPH_sendMessage);
}

void Heavy_PhaseRing::cBinop_T75fuRPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8dNTxIif, 1, m, &cVar_8dNTxIif_sendMessage);
}

void Heavy_PhaseRing::cMsg_ubWOubIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_ukAbrRSU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_lB3sAiEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_ukAbrRSU_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pJUAe0B5, HV_BINOP_ADD, 1, m, &cBinop_pJUAe0B5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fYGK290I, HV_BINOP_ADD, 1, m, &cBinop_fYGK290I_sendMessage);
}

void Heavy_PhaseRing::cBinop_cdVYwNGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_paI1dnVy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_fYGK290I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vCAL56qD, 1, m, &cVar_vCAL56qD_sendMessage);
}

void Heavy_PhaseRing::cBinop_45LfvXrd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hre7USsQ, HV_BINOP_DIVIDE, 1, m, &cBinop_Hre7USsQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_Hre7USsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pJUAe0B5, HV_BINOP_ADD, 1, m, &cBinop_pJUAe0B5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fYGK290I, HV_BINOP_ADD, 1, m, &cBinop_fYGK290I_sendMessage);
}

void Heavy_PhaseRing::cCast_GPDWarf9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GQi2OUzv, HV_BINOP_MULTIPLY, 0, m, &cBinop_GQi2OUzv_sendMessage);
}

void Heavy_PhaseRing::cCast_bkLzPpyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_45LfvXrd, HV_BINOP_DIVIDE, 0, m, &cBinop_45LfvXrd_sendMessage);
}

void Heavy_PhaseRing::cCast_Kmn3dYpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8iyfo9lO, HV_BINOP_SUBTRACT, 0, m, &cBinop_8iyfo9lO_sendMessage);
}

void Heavy_PhaseRing::cCast_IcU1CU5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EdryHjUY, 1, m, &cVar_EdryHjUY_sendMessage);
}

void Heavy_PhaseRing::cCast_DaaaAOqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lB3sAiEK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_7UQUV1Lh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EdryHjUY, 0, m, &cVar_EdryHjUY_sendMessage);
}

void Heavy_PhaseRing::cBinop_pJUAe0B5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zdoYTd0O, 0, m, &cVar_zdoYTd0O_sendMessage);
}

void Heavy_PhaseRing::cMsg_29X8K2yf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_ukAbrRSU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_30mUhUoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KgK9C7hY, 1, m, &cVar_KgK9C7hY_sendMessage);
}

void Heavy_PhaseRing::cMsg_lrcf4ytd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jKxVdelU, HV_BINOP_MULTIPLY, 0, m, &cBinop_jKxVdelU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_45LfvXrd, HV_BINOP_DIVIDE, 1, m, &cBinop_45LfvXrd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9eqcpuUT, 0, m, &cVar_9eqcpuUT_sendMessage);
}

void Heavy_PhaseRing::cCast_JLZrzvdK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_29X8K2yf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_Fn9vuRFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hUHsnXY1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pJUAe0B5, HV_BINOP_ADD, 0, m, &cBinop_pJUAe0B5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vCAL56qD, 1, m, &cVar_vCAL56qD_sendMessage);
}

void Heavy_PhaseRing::cBinop_8iyfo9lO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hre7USsQ, HV_BINOP_DIVIDE, 0, m, &cBinop_Hre7USsQ_sendMessage);
}

void Heavy_PhaseRing::cCast_hUHsnXY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lB3sAiEK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_2bgv0O8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_30mUhUoO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_fIwk2WKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ubWOubIJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_peC88Qxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KgK9C7hY, 0, m, &cVar_KgK9C7hY_sendMessage);
}

void Heavy_PhaseRing::cVar_NZislZMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_yfUOkQmb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_J7mWIJkg_sendMessage);
}

void Heavy_PhaseRing::cSystem_J7mWIJkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ohNTrYB6, HV_BINOP_MULTIPLY, 1, m, &cBinop_ohNTrYB6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jYCnQCnD, HV_BINOP_MULTIPLY, 1, m, &cBinop_jYCnQCnD_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_p8rcYAvr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_IX7RVDwD_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_IX7RVDwD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TYtXAUVS_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_nduJtpT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nduJtpT8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nduJtpT8, 0, m, &cDelay_nduJtpT8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bYSYmOPD, 0, m, &cVar_bYSYmOPD_sendMessage);
}

void Heavy_PhaseRing::cCast_TYtXAUVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IX7RVDwD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nduJtpT8, 0, m, &cDelay_nduJtpT8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bYSYmOPD, 0, m, &cVar_bYSYmOPD_sendMessage);
}

void Heavy_PhaseRing::cMsg_VVsACMS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Bwq6fHmy_sendMessage);
}

void Heavy_PhaseRing::cSystem_Bwq6fHmy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d6zrIpvb_sendMessage);
}

void Heavy_PhaseRing::cVar_0eGhL6Ra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gEhZubWJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_gEhZubWJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_IX7RVDwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nduJtpT8, 0, m, &cDelay_nduJtpT8_sendMessage);
}

void Heavy_PhaseRing::cBinop_ewpp5ow9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nduJtpT8, 2, m, &cDelay_nduJtpT8_sendMessage);
}

void Heavy_PhaseRing::cBinop_d6zrIpvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gEhZubWJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_gEhZubWJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_gEhZubWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ewpp5ow9_sendMessage);
}

void Heavy_PhaseRing::cVar_bYSYmOPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KS2Ob2Ee, HV_BINOP_SUBTRACT, 0, m, &cBinop_KS2Ob2Ee_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Q4IDYOsL_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_kfkqkoaO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eFDJr9es_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T5H4nwZE_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_eFDJr9es_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IwK6Yyho, 0, m, &cVar_IwK6Yyho_sendMessage);
}

void Heavy_PhaseRing::cCast_T5H4nwZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7CEjJzwQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YGw56fiS_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_1SW9DYD5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ymgelnvv, 0, m, &cSlice_ymgelnvv_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_i9epzjp5, 0, m, &cSlice_i9epzjp5_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K1xA0qKm_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_YAIaLWub, 0, m, &cSlice_YAIaLWub_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_596bXd7m, 0, m, &cSlice_596bXd7m_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M1gMY6fG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jDqFvPAD_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_ymgelnvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_FElsnaxV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_FElsnaxV_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_i9epzjp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Os8tbgzT_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H4KATioz_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Os8tbgzT_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H4KATioz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_pv9Bnd7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aMTJegg3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z4htyWBn_sendMessage);
}

void Heavy_PhaseRing::cVar_w6B1Jcnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OpUkbbbx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_OpUkbbbx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Og9yxBlp_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ohNTrYB6, HV_BINOP_MULTIPLY, 0, m, &cBinop_ohNTrYB6_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_JKEVvJ6Y, HV_BINOP_DIVIDE, 1, m, &cBinop_JKEVvJ6Y_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_0eGhL6Ra, 0, m, &cVar_0eGhL6Ra_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_Og9yxBlp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6JtlKcgh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_dxbFSLUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E9AXFdvV, HV_BINOP_SUBTRACT, 1, m, &cBinop_E9AXFdvV_sendMessage);
}

void Heavy_PhaseRing::cVar_X4k0EvSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IwK6Yyho, 0, m, &cVar_IwK6Yyho_sendMessage);
}

void Heavy_PhaseRing::cVar_IwK6Yyho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wtRV29LK, HV_BINOP_ADD, 0, m, &cBinop_wtRV29LK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1pCsfHOM, HV_BINOP_ADD, 0, m, &cBinop_1pCsfHOM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fxBTFh90, 0, m, &cVar_fxBTFh90_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WJZu03VI, m);
}

void Heavy_PhaseRing::cSlice_YAIaLWub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aMTJegg3_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z4htyWBn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_596bXd7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ysGaH8Pg_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_srTYPePA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_9ePJz9qx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bYSYmOPD, 1, m, &cVar_bYSYmOPD_sendMessage);
}

void Heavy_PhaseRing::cBinop_jYCnQCnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9ePJz9qx_sendMessage);
}

void Heavy_PhaseRing::cBinop_ohNTrYB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BZ5fESaz_sendMessage);
}

void Heavy_PhaseRing::cBinop_BZ5fESaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KS2Ob2Ee, HV_BINOP_SUBTRACT, 1, m, &cBinop_KS2Ob2Ee_sendMessage);
}

void Heavy_PhaseRing::cBinop_KS2Ob2Ee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bYSYmOPD, 1, m, &cVar_bYSYmOPD_sendMessage);
}

void Heavy_PhaseRing::cMsg_7fCjsCoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_p8rcYAvr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_T0XsL1RD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_p8rcYAvr_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1pCsfHOM, HV_BINOP_ADD, 1, m, &cBinop_1pCsfHOM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wtRV29LK, HV_BINOP_ADD, 1, m, &cBinop_wtRV29LK_sendMessage);
}

void Heavy_PhaseRing::cBinop_Q4IDYOsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kfkqkoaO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_wtRV29LK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IwK6Yyho, 1, m, &cVar_IwK6Yyho_sendMessage);
}

void Heavy_PhaseRing::cBinop_JKEVvJ6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g3Lognc2, HV_BINOP_DIVIDE, 1, m, &cBinop_g3Lognc2_sendMessage);
}

void Heavy_PhaseRing::cBinop_g3Lognc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1pCsfHOM, HV_BINOP_ADD, 1, m, &cBinop_1pCsfHOM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wtRV29LK, HV_BINOP_ADD, 1, m, &cBinop_wtRV29LK_sendMessage);
}

void Heavy_PhaseRing::cCast_aMTJegg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jYCnQCnD, HV_BINOP_MULTIPLY, 0, m, &cBinop_jYCnQCnD_sendMessage);
}

void Heavy_PhaseRing::cCast_z4htyWBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JKEVvJ6Y, HV_BINOP_DIVIDE, 0, m, &cBinop_JKEVvJ6Y_sendMessage);
}

void Heavy_PhaseRing::cCast_srTYPePA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E9AXFdvV, HV_BINOP_SUBTRACT, 0, m, &cBinop_E9AXFdvV_sendMessage);
}

void Heavy_PhaseRing::cCast_ysGaH8Pg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X4k0EvSf, 1, m, &cVar_X4k0EvSf_sendMessage);
}

void Heavy_PhaseRing::cCast_YGw56fiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X4k0EvSf, 0, m, &cVar_X4k0EvSf_sendMessage);
}

void Heavy_PhaseRing::cCast_7CEjJzwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T0XsL1RD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_1pCsfHOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dxbFSLUZ, 0, m, &cVar_dxbFSLUZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_FElsnaxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_p8rcYAvr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_RiqHHzjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_pv9Bnd7W, 1, m, &cVar_pv9Bnd7W_sendMessage);
}

void Heavy_PhaseRing::cMsg_6JtlKcgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ohNTrYB6, HV_BINOP_MULTIPLY, 0, m, &cBinop_ohNTrYB6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JKEVvJ6Y, HV_BINOP_DIVIDE, 1, m, &cBinop_JKEVvJ6Y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0eGhL6Ra, 0, m, &cVar_0eGhL6Ra_sendMessage);
}

void Heavy_PhaseRing::cCast_H4KATioz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_baay5UwD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1pCsfHOM, HV_BINOP_ADD, 0, m, &cBinop_1pCsfHOM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IwK6Yyho, 1, m, &cVar_IwK6Yyho_sendMessage);
}

void Heavy_PhaseRing::cCast_Os8tbgzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FElsnaxV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_E9AXFdvV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g3Lognc2, HV_BINOP_DIVIDE, 0, m, &cBinop_g3Lognc2_sendMessage);
}

void Heavy_PhaseRing::cCast_baay5UwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T0XsL1RD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_jDqFvPAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RiqHHzjM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_K1xA0qKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pv9Bnd7W, 0, m, &cVar_pv9Bnd7W_sendMessage);
}

void Heavy_PhaseRing::cCast_M1gMY6fG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7fCjsCoi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_zdemUwI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2ulNQBW7, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_qsoRmaEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HHTTv2KK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_bUnTBK9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1SW9DYD5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_GAA0eCRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_zp4UbKqW_sendMessage);
}

void Heavy_PhaseRing::cBinop_zp4UbKqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qsoRmaEh, 0, m, &cPack_qsoRmaEh_sendMessage);
}

void Heavy_PhaseRing::cBinop_pvVwwT0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GAA0eCRu_sendMessage);
}

void Heavy_PhaseRing::cCast_pCzn3UOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_j1PwZyrl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_FWgJQ8Jo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_80B2cjdr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_N3xkgdKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_p1YMhKm3_sendMessage);
}

void Heavy_PhaseRing::cVar_Wa3ZuHrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UeaSU9V3_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_45xUuoaN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Qlx0rukB_sendMessage);
}

void Heavy_PhaseRing::cIf_TWcIrZiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_NOSzqo0v_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_EggfDYqR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_d1STnNqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LxAerO3A, HV_BINOP_POW, 0, m, &cBinop_LxAerO3A_sendMessage);
}

void Heavy_PhaseRing::cBinop_LxAerO3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0la9f8kZ, 0, m, &cPack_0la9f8kZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_P1Hy916q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_DHBQWGfS_sendMessage);
}

void Heavy_PhaseRing::cCast_Qlx0rukB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TWcIrZiz, 0, m, &cIf_TWcIrZiz_sendMessage);
}

void Heavy_PhaseRing::cCast_45xUuoaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_bKzH1x16_sendMessage);
}

void Heavy_PhaseRing::cBinop_bKzH1x16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TWcIrZiz, 1, m, &cIf_TWcIrZiz_sendMessage);
}

void Heavy_PhaseRing::cBinop_EggfDYqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_P1Hy916q_sendMessage);
}

void Heavy_PhaseRing::cMsg_NOSzqo0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_0la9f8kZ, 0, m, &cPack_0la9f8kZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_DHBQWGfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LxAerO3A, HV_BINOP_POW, 1, m, &cBinop_LxAerO3A_sendMessage);
  cMsg_d1STnNqw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_0la9f8kZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_neCt0u0x, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_1grn6RFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_QTPwzBWE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_UeaSU9V3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_I6HkaMsV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_I6HkaMsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sBtu3ipe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_QTPwzBWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CLeWNtPI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_ZDRtiCOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FW6UImhQ_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rgyRkCHQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Unn8xiIy_sendMessage);
}

void Heavy_PhaseRing::cIf_WMevGynS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_B9h8Zt9k_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_MRhAnuYY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_pZ7KyNOl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EjviZu4l, HV_BINOP_POW, 0, m, &cBinop_EjviZu4l_sendMessage);
}

void Heavy_PhaseRing::cBinop_EjviZu4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uT1kzjv9, 0, m, &cPack_uT1kzjv9_sendMessage);
}

void Heavy_PhaseRing::cBinop_1y7UgfiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_WrzuJYG0_sendMessage);
}

void Heavy_PhaseRing::cCast_Unn8xiIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WMevGynS, 0, m, &cIf_WMevGynS_sendMessage);
}

void Heavy_PhaseRing::cCast_rgyRkCHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_DrKPv0w2_sendMessage);
}

void Heavy_PhaseRing::cBinop_DrKPv0w2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WMevGynS, 1, m, &cIf_WMevGynS_sendMessage);
}

void Heavy_PhaseRing::cBinop_MRhAnuYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_1y7UgfiH_sendMessage);
}

void Heavy_PhaseRing::cMsg_B9h8Zt9k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_uT1kzjv9, 0, m, &cPack_uT1kzjv9_sendMessage);
}

void Heavy_PhaseRing::cBinop_WrzuJYG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EjviZu4l, HV_BINOP_POW, 1, m, &cBinop_EjviZu4l_sendMessage);
  cMsg_pZ7KyNOl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_uT1kzjv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MwVyL2cc, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_4EI6xETs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RFu0TihE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_FW6UImhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_lkHfwgec_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_lkHfwgec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jhJX6wl0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_RFu0TihE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6GAwzpGg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_M4xmTw4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_kPOAdBwA_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_c4jKAYAR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_c4jKAYAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_LYUXSWWH_sendMessage);
}

void Heavy_PhaseRing::cCast_7g3iPO6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_qkcFhsBb_sendMessage);
}

void Heavy_PhaseRing::cCast_ejuPDaaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_M4xmTw4z, 0, m, &cIf_M4xmTw4z_sendMessage);
}

void Heavy_PhaseRing::cMsg_kPOAdBwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_UeaSU9V3_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_45xUuoaN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Qlx0rukB_sendMessage);
}

void Heavy_PhaseRing::cBinop_LYUXSWWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_qYZIuoba_sendMessage);
}

void Heavy_PhaseRing::cBinop_qYZIuoba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_TxAhanDP_sendMessage);
}

void Heavy_PhaseRing::cBinop_TxAhanDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UeaSU9V3_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_45xUuoaN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Qlx0rukB_sendMessage);
}

void Heavy_PhaseRing::cBinop_qkcFhsBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_M4xmTw4z, 1, m, &cIf_M4xmTw4z_sendMessage);
}

void Heavy_PhaseRing::cBinop_uPU39uM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7g3iPO6y_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ejuPDaaf_sendMessage);
}

void Heavy_PhaseRing::cBinop_3Vu8nR7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_uPU39uM4_sendMessage);
}

void Heavy_PhaseRing::cIf_TpAvcDbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_4sFqRnRg_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_IpViamG9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_IpViamG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_dk88bDkb_sendMessage);
}

void Heavy_PhaseRing::cCast_YM6ulB4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TpAvcDbp, 0, m, &cIf_TpAvcDbp_sendMessage);
}

void Heavy_PhaseRing::cCast_ngFSUqth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_EdZ2v9e8_sendMessage);
}

void Heavy_PhaseRing::cMsg_4sFqRnRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_FW6UImhQ_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rgyRkCHQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Unn8xiIy_sendMessage);
}

void Heavy_PhaseRing::cBinop_dk88bDkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_xVpWJPMR_sendMessage);
}

void Heavy_PhaseRing::cBinop_xVpWJPMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RQydt0Ji_sendMessage);
}

void Heavy_PhaseRing::cBinop_RQydt0Ji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FW6UImhQ_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rgyRkCHQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Unn8xiIy_sendMessage);
}

void Heavy_PhaseRing::cBinop_EdZ2v9e8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TpAvcDbp, 1, m, &cIf_TpAvcDbp_sendMessage);
}

void Heavy_PhaseRing::cBinop_tKatKN6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ngFSUqth_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YM6ulB4f_sendMessage);
}

void Heavy_PhaseRing::cBinop_qKW1vATt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tKatKN6O_sendMessage);
}

void Heavy_PhaseRing::cVar_vU6kApsy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F2z6PUE2_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JNV7xkTI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0WSKcOsb_sendMessage);
}

void Heavy_PhaseRing::cIf_OsJcpA78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DzKFCauI_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_fTWkc3Al_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_Ddx3icuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3kQOOAwh, HV_BINOP_POW, 0, m, &cBinop_3kQOOAwh_sendMessage);
}

void Heavy_PhaseRing::cBinop_3kQOOAwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RwiAAHjl, 0, m, &cPack_RwiAAHjl_sendMessage);
}

void Heavy_PhaseRing::cBinop_dtsogmSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_tpeiN3Mu_sendMessage);
}

void Heavy_PhaseRing::cCast_JNV7xkTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_EBKLJsDe_sendMessage);
}

void Heavy_PhaseRing::cCast_0WSKcOsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OsJcpA78, 0, m, &cIf_OsJcpA78_sendMessage);
}

void Heavy_PhaseRing::cBinop_EBKLJsDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OsJcpA78, 1, m, &cIf_OsJcpA78_sendMessage);
}

void Heavy_PhaseRing::cBinop_fTWkc3Al_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_dtsogmSl_sendMessage);
}

void Heavy_PhaseRing::cMsg_DzKFCauI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_RwiAAHjl, 0, m, &cPack_RwiAAHjl_sendMessage);
}

void Heavy_PhaseRing::cBinop_tpeiN3Mu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3kQOOAwh, HV_BINOP_POW, 1, m, &cBinop_3kQOOAwh_sendMessage);
  cMsg_Ddx3icuy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_RwiAAHjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cEfkkKfs, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_C0CgSJO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_OkaLo85j_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_F2z6PUE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_03u9WS8C_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_03u9WS8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dDj1gONn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_OkaLo85j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UxKsKFFs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_sp6qHUTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G5mnxUEu_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fq3fwF2G_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QEd0klL2_sendMessage);
}

void Heavy_PhaseRing::cIf_EBtKSKzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5gmzwJXS_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_eP9Dsqy1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_01MXPcyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WvTwfFVe, HV_BINOP_POW, 0, m, &cBinop_WvTwfFVe_sendMessage);
}

void Heavy_PhaseRing::cBinop_WvTwfFVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AmMg9ayQ, 0, m, &cPack_AmMg9ayQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_QV2HOpkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_2mAbyVF3_sendMessage);
}

void Heavy_PhaseRing::cCast_QEd0klL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EBtKSKzO, 0, m, &cIf_EBtKSKzO_sendMessage);
}

void Heavy_PhaseRing::cCast_fq3fwF2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_1ShZj27x_sendMessage);
}

void Heavy_PhaseRing::cBinop_1ShZj27x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EBtKSKzO, 1, m, &cIf_EBtKSKzO_sendMessage);
}

void Heavy_PhaseRing::cBinop_eP9Dsqy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_QV2HOpkE_sendMessage);
}

void Heavy_PhaseRing::cMsg_5gmzwJXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_AmMg9ayQ, 0, m, &cPack_AmMg9ayQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_2mAbyVF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WvTwfFVe, HV_BINOP_POW, 1, m, &cBinop_WvTwfFVe_sendMessage);
  cMsg_01MXPcyh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_AmMg9ayQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MUsAcsjq, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_oYymC1Q0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3Hjn0O7H_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_G5mnxUEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_165j2rRy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_165j2rRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5QcGMf5m_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_3Hjn0O7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_J2kbkFVt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_FEiShUFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4myYhg99_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vUTU0rOG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6Wd2eICn_sendMessage);
}

void Heavy_PhaseRing::cIf_JkV95C07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Vk5x4YuL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_EgHs9urr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_rV5As9kV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_t57fy7gY, HV_BINOP_POW, 0, m, &cBinop_t57fy7gY_sendMessage);
}

void Heavy_PhaseRing::cBinop_t57fy7gY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gvXiuAOf, 0, m, &cPack_gvXiuAOf_sendMessage);
}

void Heavy_PhaseRing::cBinop_M52b9XTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_zVEYAx4k_sendMessage);
}

void Heavy_PhaseRing::cCast_6Wd2eICn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JkV95C07, 0, m, &cIf_JkV95C07_sendMessage);
}

void Heavy_PhaseRing::cCast_vUTU0rOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_3wvSKC40_sendMessage);
}

void Heavy_PhaseRing::cBinop_3wvSKC40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JkV95C07, 1, m, &cIf_JkV95C07_sendMessage);
}

void Heavy_PhaseRing::cBinop_EgHs9urr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_M52b9XTN_sendMessage);
}

void Heavy_PhaseRing::cMsg_Vk5x4YuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_gvXiuAOf, 0, m, &cPack_gvXiuAOf_sendMessage);
}

void Heavy_PhaseRing::cBinop_zVEYAx4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t57fy7gY, HV_BINOP_POW, 1, m, &cBinop_t57fy7gY_sendMessage);
  cMsg_rV5As9kV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_gvXiuAOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Wz7rkSKw, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_bv1eKTqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0ee3M4rf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_4myYhg99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_tv1vluJZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_tv1vluJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gsPJEUFg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_0ee3M4rf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9hk6hPlD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_SyqN42LB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tpgqEebY, 0, m, &cIf_tpgqEebY_sendMessage);
}

void Heavy_PhaseRing::cSlice_7qt4Xpyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C6pHu4AP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bddv1Ex8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_ylQXCBlm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_TQD6cYgl, 0, m, &cIf_TQD6cYgl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_TQD6cYgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SuJBLeee_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_77nti01A_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_mndE9qbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_kQqnYKg0, 2, m, &cPack_kQqnYKg0_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_3Z7TkOOR, 1, m, &cPack_3Z7TkOOR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_yVsKWkzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7qt4Xpyk, 0, m, &cSlice_7qt4Xpyk_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ylQXCBlm, 0, m, &cSlice_ylQXCBlm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_bgnoNinY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_uePDerkl_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_fv72dWQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DRHbSa4w_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a228heMH_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_abRGMz7k_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_3YlMDn5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EcSKl7VR, 1, m, &cIf_EcSKl7VR_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_O1Ku2C5N_sendMessage);
}

void Heavy_PhaseRing::cIf_EcSKl7VR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7qt4Xpyk, 0, m, &cSlice_7qt4Xpyk_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ylQXCBlm, 0, m, &cSlice_ylQXCBlm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_3Z7TkOOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yVsKWkzp, 0, m, &cIf_yVsKWkzp_sendMessage);
}

void Heavy_PhaseRing::cBinop_7KdXoLol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TQD6cYgl, 1, m, &cIf_TQD6cYgl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_mndE9qbC, 1, m, &cIf_mndE9qbC_sendMessage);
}

void Heavy_PhaseRing::cCast_bddv1Ex8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mndE9qbC, 0, m, &cIf_mndE9qbC_sendMessage);
}

void Heavy_PhaseRing::cCast_C6pHu4AP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_7KdXoLol_sendMessage);
}

void Heavy_PhaseRing::cMsg_bQyZvZNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_3YlMDn5k, 1, m, &cVar_3YlMDn5k_sendMessage);
}

void Heavy_PhaseRing::cMsg_uePDerkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_3YlMDn5k, 1, m, &cVar_3YlMDn5k_sendMessage);
}

void Heavy_PhaseRing::cCast_abRGMz7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bQyZvZNj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_DRHbSa4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3YlMDn5k, 0, m, &cVar_3YlMDn5k_sendMessage);
}

void Heavy_PhaseRing::cCast_a228heMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3Z7TkOOR, 0, m, &cPack_3Z7TkOOR_sendMessage);
}

void Heavy_PhaseRing::cBinop_O1Ku2C5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yVsKWkzp, 1, m, &cIf_yVsKWkzp_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_DCy0XJD2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lfnkktQz, 0, m, &cSlice_lfnkktQz_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PsFEi1mg, 0, m, &cSlice_PsFEi1mg_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zaKByEg2, 0, m, &cSlice_zaKByEg2_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Za2Z892y, 0, m, &cSlice_Za2Z892y_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_lfnkktQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_I5P8dIPt, 0, m, &cSlice_I5P8dIPt_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZmKwHMw4, 0, m, &cSlice_ZmKwHMw4_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_I5P8dIPt, 0, m, &cSlice_I5P8dIPt_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZmKwHMw4, 0, m, &cSlice_ZmKwHMw4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_PsFEi1mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7q6wjVzX, 0, m, &cSlice_7q6wjVzX_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_J5uIL2zn, 0, m, &cSlice_J5uIL2zn_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7q6wjVzX, 0, m, &cSlice_7q6wjVzX_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_J5uIL2zn, 0, m, &cSlice_J5uIL2zn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_zaKByEg2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bhVmhJzT, 0, m, &cSlice_bhVmhJzT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dV5FdnHL, 0, m, &cSlice_dV5FdnHL_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bhVmhJzT, 0, m, &cSlice_bhVmhJzT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dV5FdnHL, 0, m, &cSlice_dV5FdnHL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_Za2Z892y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_yKMnqAgU, 0, m, &cSlice_yKMnqAgU_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_oxGDBhLH, 0, m, &cSlice_oxGDBhLH_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_yKMnqAgU, 0, m, &cSlice_yKMnqAgU_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_oxGDBhLH, 0, m, &cSlice_oxGDBhLH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_1stsBVe7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eO0SaMR8_sendMessage);
      break;
    }
    default: {
      cMsg_4JYI4dsw_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_eO0SaMR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_loN3CNNH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_tpgqEebY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bgnoNinY, 0, m, &cSlice_bgnoNinY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fv72dWQ9, 0, m, &cSlice_fv72dWQ9_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_EcSKl7VR, 0, m, &cIf_EcSKl7VR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_zIwtTIlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Kj5lIxNZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_tpgqEebY, 1, m, &cIf_tpgqEebY_sendMessage);
}

void Heavy_PhaseRing::cBinop_Kj5lIxNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zIwtTIlE, 1, m, &cVar_zIwtTIlE_sendMessage);
}

void Heavy_PhaseRing::cMsg_loN3CNNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_zIwtTIlE, 0, m, &cVar_zIwtTIlE_sendMessage);
}

void Heavy_PhaseRing::cMsg_4JYI4dsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_zIwtTIlE, 0, m, &cVar_zIwtTIlE_sendMessage);
}

void Heavy_PhaseRing::cPack_kQqnYKg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DCy0XJD2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_s14KR1LY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kQqnYKg0, 0, m, &cPack_kQqnYKg0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_2dffPb3w_sendMessage);
}

void Heavy_PhaseRing::cBinop_2dffPb3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_1RsZkhd3_sendMessage);
}

void Heavy_PhaseRing::cBinop_1RsZkhd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s14KR1LY, 1, m, &cVar_s14KR1LY_sendMessage);
}

void Heavy_PhaseRing::cMsg_ce9KMJBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_1stsBVe7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_SuJBLeee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kQqnYKg0, 1, m, &cPack_kQqnYKg0_sendMessage);
}

void Heavy_PhaseRing::cCast_77nti01A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s14KR1LY, 0, m, &cVar_s14KR1LY_sendMessage);
}

void Heavy_PhaseRing::cSend_7thgdSyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bZX432e7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_sk0mjCCI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yYoq6e31_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_94zgp24O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_1bu0N9II_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HGXkU4wd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_M2qsroXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tADOx9Wk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_HGXkU4wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VFDd3yRq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_tADOx9Wk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_l7HmOpVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NdDIyUTM_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_eaHDBZcj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cReceive_zrgvIk4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HdcXoiK0_sendMessage(_c, 0, m);
  cMsg_RyrY1Ry7_sendMessage(_c, 0, m);
  cMsg_d0CdqYvn_sendMessage(_c, 0, m);
  cMsg_70DUGP0N_sendMessage(_c, 0, m);
  cMsg_2crterX7_sendMessage(_c, 0, m);
  cMsg_ZVkWlCqX_sendMessage(_c, 0, m);
  cMsg_EAgyP3Ut_sendMessage(_c, 0, m);
  cMsg_MZ9nrwDB_sendMessage(_c, 0, m);
  cMsg_QPmIw1sa_sendMessage(_c, 0, m);
  cMsg_r1rHZCvv_sendMessage(_c, 0, m);
  cMsg_QGi0HWr1_sendMessage(_c, 0, m);
  cMsg_3NC0qn0K_sendMessage(_c, 0, m);
  cMsg_DfeiofMa_sendMessage(_c, 0, m);
  cMsg_aSRhFih8_sendMessage(_c, 0, m);
  cMsg_KNb6jO5z_sendMessage(_c, 0, m);
  cMsg_IIgSmFxb_sendMessage(_c, 0, m);
  cMsg_5Dbq1qTE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NMEJtwwS, 0, m, &cVar_NMEJtwwS_sendMessage);
  cMsg_is4RjVUy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aCK74uYh, 0, m, &cVar_aCK74uYh_sendMessage);
  cMsg_8oidOGDZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_E5bOsQS9, 0, m, &cVar_E5bOsQS9_sendMessage);
  cMsg_hNJv2cgp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xj5p7vRM, 0, m, &cVar_xj5p7vRM_sendMessage);
  cMsg_5J2iMQ9b_sendMessage(_c, 0, m);
  cMsg_tIdIOL3P_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DbNwVwe2, 0, m, &cVar_DbNwVwe2_sendMessage);
  cMsg_elMB56Kn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0aUqG0n5, 0, m, &cVar_0aUqG0n5_sendMessage);
  cMsg_9tADVRw3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5EGrzIwn, 0, m, &cVar_5EGrzIwn_sendMessage);
  cMsg_sRxoC5X9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SQ4unrAw, 0, m, &cVar_SQ4unrAw_sendMessage);
  cMsg_EehKra25_sendMessage(_c, 0, m);
  cMsg_6H3z7TBo_sendMessage(_c, 0, m);
  cMsg_bAt70oa1_sendMessage(_c, 0, m);
  cMsg_tQiEntrw_sendMessage(_c, 0, m);
  cMsg_AKe2l9eW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wvqBiHyg, 0, m, &cVar_wvqBiHyg_sendMessage);
  cMsg_cUla9zMy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tBuxNZDA, 0, m, &cVar_tBuxNZDA_sendMessage);
  cMsg_CDudzBJJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zzIlLKFl, 0, m, &cVar_zzIlLKFl_sendMessage);
  cMsg_sx3ZL2lQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GziR87yH, 0, m, &cVar_GziR87yH_sendMessage);
  cMsg_LJUok0ys_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zVoFtlE2, 0, m, &cVar_zVoFtlE2_sendMessage);
  cMsg_BDRtcNdR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3CuIpagK, 0, m, &cVar_3CuIpagK_sendMessage);
  cMsg_F6qPddP2_sendMessage(_c, 0, m);
  cMsg_NyMMVlDG_sendMessage(_c, 0, m);
  cMsg_Po9tEiEP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_p2amF8mZ, 0, m, &cVar_p2amF8mZ_sendMessage);
  cMsg_qKiZx5a6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IlGYwPwu, 0, m, &cVar_IlGYwPwu_sendMessage);
  cMsg_juVjzCey_sendMessage(_c, 0, m);
  cMsg_a5Af2hQo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9eqcpuUT, 0, m, &cVar_9eqcpuUT_sendMessage);
  cMsg_VVsACMS1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0eGhL6Ra, 0, m, &cVar_0eGhL6Ra_sendMessage);
  cMsg_2HUJUN4T_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1Rc5fTsG, 0, m, &cVar_1Rc5fTsG_sendMessage);
  cMsg_sAdVk3Pw_sendMessage(_c, 0, m);
  cMsg_RuaIcvMf_sendMessage(_c, 0, m);
  cMsg_Hhj8OATG_sendMessage(_c, 0, m);
  cMsg_7hsCOIfC_sendMessage(_c, 0, m);
  cMsg_D8FM2aAl_sendMessage(_c, 0, m);
  cMsg_fBefhZry_sendMessage(_c, 0, m);
  cMsg_lM9rxF42_sendMessage(_c, 0, m);
  cMsg_Aqw6ALcV_sendMessage(_c, 0, m);
  cMsg_j3e2wCnU_sendMessage(_c, 0, m);
  cMsg_S94LtOSa_sendMessage(_c, 0, m);
  cMsg_iRWGK0ZI_sendMessage(_c, 0, m);
  cMsg_4p9QFS0c_sendMessage(_c, 0, m);
  cMsg_d9punK7k_sendMessage(_c, 0, m);
  cMsg_EXqv4cMo_sendMessage(_c, 0, m);
  cMsg_L2p0G28a_sendMessage(_c, 0, m);
  cMsg_oOkFnAPF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zIBaPinP, 0, m, &cVar_zIBaPinP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tdEnmbEy, 0, m, &cVar_tdEnmbEy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vHcevg4J, 0, m, &cVar_vHcevg4J_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1E0CcgIK, 0, m, &cVar_1E0CcgIK_sendMessage);
  cMsg_Q0SfGP8s_sendMessage(_c, 0, m);
  cMsg_7wAk8YJl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gAX6mmnJ, 0, m, &cVar_gAX6mmnJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1JpSKrMU, 0, m, &cVar_1JpSKrMU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_q0VZLCDb, 0, m, &cVar_q0VZLCDb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uJUXRS0d, 0, m, &cVar_uJUXRS0d_sendMessage);
  cMsg_gkNuj3dL_sendMessage(_c, 0, m);
  cMsg_SyuQyLGp_sendMessage(_c, 0, m);
  cMsg_17rWQso0_sendMessage(_c, 0, m);
  cMsg_AvpiLTVV_sendMessage(_c, 0, m);
  cMsg_Zmi38Qsv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zdoYTd0O, 0, m, &cVar_zdoYTd0O_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_isgjVizP, 0, m, &cVar_isgjVizP_sendMessage);
  cMsg_yfUOkQmb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dxbFSLUZ, 0, m, &cVar_dxbFSLUZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_w6B1Jcnl, 0, m, &cVar_w6B1Jcnl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_J732KMWy, 0, m, &cVar_J732KMWy_sendMessage);
  cMsg_XWwfgsJA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_44gqBxJv, 0, m, &cVar_44gqBxJv_sendMessage);
  cMsg_OGSHByfg_sendMessage(_c, 0, m);
  cMsg_UYDbhr5e_sendMessage(_c, 0, m);
  cMsg_JYbPUuMQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mQXfbYRn, 0, m, &cVar_mQXfbYRn_sendMessage);
  cMsg_8U4pKmJ8_sendMessage(_c, 0, m);
  cMsg_Oa3pS19K_sendMessage(_c, 0, m);
  cMsg_N3xkgdKY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Wa3ZuHrX, 0, m, &cVar_Wa3ZuHrX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZDRtiCOj, 0, m, &cVar_ZDRtiCOj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vU6kApsy, 0, m, &cVar_vU6kApsy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sp6qHUTy, 0, m, &cVar_sp6qHUTy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FEiShUFa, 0, m, &cVar_FEiShUFa_sendMessage);
  cMsg_ce9KMJBJ_sendMessage(_c, 0, m);
  cSwitchcase_NdDIyUTM_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_eaHDBZcj_onMessage(_c, NULL, 0, m, NULL);
  cMsg_BVB4vcBj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WvCPrYVT, 0, m, &cVar_WvCPrYVT_sendMessage);
  cMsg_Ld0BUJ9J_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_0Fke5nX6, 0, m, &cTabhead_0Fke5nX6_sendMessage);
  cMsg_R3RO4Wty_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dOnx3kV9, 0, m, &cVar_dOnx3kV9_sendMessage);
  cMsg_PeemXUce_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZYDBgI6J, 0, m, &cTabhead_ZYDBgI6J_sendMessage);
  cMsg_y15tfJze_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jc3BiXZR, 0, m, &cVar_jc3BiXZR_sendMessage);
  cMsg_hAwFeOm3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jLPJ7Rox, 0, m, &cTabhead_jLPJ7Rox_sendMessage);
  cMsg_FniwRk4q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9WpELT9g, 0, m, &cVar_9WpELT9g_sendMessage);
  cMsg_lGfvx6Wn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3HAxw8TX, 0, m, &cTabhead_3HAxw8TX_sendMessage);
  cMsg_zuJrmDae_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YrZxt1rh, 0, m, &cVar_YrZxt1rh_sendMessage);
  cMsg_FUvSKUwO_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_FHyNMIDU, 0, m, &cTabhead_FHyNMIDU_sendMessage);
  cMsg_LdyWds04_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ha1m79M0, 0, m, &cVar_ha1m79M0_sendMessage);
  cMsg_BBlr8m3V_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_FOJj7uQb, 0, m, &cTabhead_FOJj7uQb_sendMessage);
  cMsg_FRAwHzK1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gRq60mBs, 0, m, &cVar_gRq60mBs_sendMessage);
  cMsg_Ww83srei_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nytT6jlV, 0, m, &cTabhead_nytT6jlV_sendMessage);
  cMsg_GyXZ7rMi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2xQG8E27, 0, m, &cVar_2xQG8E27_sendMessage);
  cMsg_cHHfHK6t_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_psfVSoyH, 0, m, &cTabhead_psfVSoyH_sendMessage);
  cMsg_M2KvHH0L_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_62yBMUkD, 0, m, &cVar_62yBMUkD_sendMessage);
  cMsg_Lf1mFsru_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RH4MTcMd, 0, m, &cTabhead_RH4MTcMd_sendMessage);
  cMsg_He8Bok0M_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4llXTxP6, 0, m, &cVar_4llXTxP6_sendMessage);
  cMsg_aX6ETK77_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RZ7cANBB, 0, m, &cTabhead_RZ7cANBB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_91hhEDAv, 0, m, &cVar_91hhEDAv_sendMessage);
  cMsg_B7BEIPem_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FW92KCMh, 0, m, &cVar_FW92KCMh_sendMessage);
  cMsg_Nbh0kq0i_sendMessage(_c, 0, m);
  cMsg_2HBvWquF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PIfzD63H, 0, m, &cVar_PIfzD63H_sendMessage);
  cMsg_tpH0J9oe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Fliazw6k, 0, m, &cTabhead_Fliazw6k_sendMessage);
  cMsg_M87oPYEK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_N6PqgSfb, 0, m, &cVar_N6PqgSfb_sendMessage);
  cMsg_1SkEqFCn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_fDGNzDFl, 0, m, &cTabhead_fDGNzDFl_sendMessage);
  cMsg_59VCik6n_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rwGbOOyz, 0, m, &cVar_rwGbOOyz_sendMessage);
  cMsg_6cfDvXJv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_34KDiFsG, 0, m, &cTabhead_34KDiFsG_sendMessage);
  cMsg_bkB9NWR9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GPED2EGP, 0, m, &cVar_GPED2EGP_sendMessage);
  cMsg_YFD241Oe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TMVweQpP, 0, m, &cTabhead_TMVweQpP_sendMessage);
  cMsg_8CN40sr4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_T5ZaXecQ, 0, m, &cVar_T5ZaXecQ_sendMessage);
  cMsg_Po22Mk8l_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_CJVfSWQs, 0, m, &cTabhead_CJVfSWQs_sendMessage);
  cMsg_3uTgDFtf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xlR6cb7z, 0, m, &cVar_xlR6cb7z_sendMessage);
  cMsg_gb66HVi5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Npn5Gs7X, 0, m, &cTabhead_Npn5Gs7X_sendMessage);
  cMsg_Vp4LHSIg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UDrWTyAM, 0, m, &cVar_UDrWTyAM_sendMessage);
  cMsg_SrZxoiMq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZV8Ypr3I, 0, m, &cTabhead_ZV8Ypr3I_sendMessage);
  cMsg_bfEedAqX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BxllU1k2, 0, m, &cVar_BxllU1k2_sendMessage);
  cMsg_tgHH6F6t_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_oNNWyJxi, 0, m, &cTabhead_oNNWyJxi_sendMessage);
  cMsg_Dxc6tkH7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dUCQXc61, 0, m, &cVar_dUCQXc61_sendMessage);
  cMsg_MoPMO3pc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MKr9R2kL, 0, m, &cTabhead_MKr9R2kL_sendMessage);
  cMsg_skKsyVJz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rV8IiApr, 0, m, &cVar_rV8IiApr_sendMessage);
  cMsg_ZkWEDH76_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_z8c866Q4, 0, m, &cTabhead_z8c866Q4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BIO8G4ji, 0, m, &cVar_BIO8G4ji_sendMessage);
  cMsg_4wKnBs3x_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SNN4ljMF, 0, m, &cVar_SNN4ljMF_sendMessage);
  cMsg_ATVacbbr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5sULwvJK, 0, m, &cVar_5sULwvJK_sendMessage);
  cMsg_hzaZefnQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DE55hnrI, 0, m, &cVar_DE55hnrI_sendMessage);
  cMsg_Nhy1G4I9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_dvK4NdTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_zO41hOit, 0, m, &cSlice_zO41hOit_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_MfO1apwe, 0, m, &cSlice_MfO1apwe_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Melq9WiR, 0, m, &cSlice_Melq9WiR_sendMessage);
}

void Heavy_PhaseRing::cReceive_bZX432e7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SyqN42LB, 0, m, &cPack_SyqN42LB_sendMessage);
}

void Heavy_PhaseRing::cReceive_yYoq6e31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SyqN42LB, 1, m, &cPack_SyqN42LB_sendMessage);
}

void Heavy_PhaseRing::cReceive_4MOGS1E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_16DZkcyT_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_VNPUgcNO, 0, m, &cIf_VNPUgcNO_sendMessage);
}

void Heavy_PhaseRing::cReceive_WBgraKGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_dxxE8wo2_sendMessage);
}

void Heavy_PhaseRing::cReceive_fqrjLzG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SH1NswbM, 0, m, &cPack_SH1NswbM_sendMessage);
}

void Heavy_PhaseRing::cReceive_zMi2GUWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_E7MhDO4m_sendMessage);
}

void Heavy_PhaseRing::cReceive_U2EvzGwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cReceive_Q1oS9UTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aoaVbtsU_sendMessage);
}

void Heavy_PhaseRing::cReceive_PEVlcOCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6kmZl4Oo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MmHO53KN_sendMessage);
}

void Heavy_PhaseRing::cReceive_re6mUNLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l7HmOpVO_sendMessage);
}

void Heavy_PhaseRing::cReceive_VFDd3yRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IpN5uEAM, 0, m, &cVar_IpN5uEAM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZjHRbsem, 0, m, &cVar_ZjHRbsem_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bwhleghx, 0, m, &cVar_bwhleghx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CAQFoj2g, 0, m, &cVar_CAQFoj2g_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_YjP80vSV, 0, m, &cPack_YjP80vSV_sendMessage);
}

void Heavy_PhaseRing::cReceive_D9HFBQZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_73vHDODT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ucpRQZTB, 0, m, &cVar_ucpRQZTB_sendMessage);
}

void Heavy_PhaseRing::cReceive_IFfLEHOl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qga02r6d, 0, m, &cPack_qga02r6d_sendMessage);
}

void Heavy_PhaseRing::cReceive_YU11Kgar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mIvK51LZ, 1, m, &cVar_mIvK51LZ_sendMessage);
}

void Heavy_PhaseRing::cReceive_cdF1MFb0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4MiWnT4r, m);
}

void Heavy_PhaseRing::cReceive_PgUb6ep7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FHmlnRR4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AETZlJBZ, 0, m, &cVar_AETZlJBZ_sendMessage);
}

void Heavy_PhaseRing::cReceive_ONgsZ2Ya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_bU66K3gH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Rv02aqAA, 0, m, &cVar_Rv02aqAA_sendMessage);
}

void Heavy_PhaseRing::cReceive_IzMdH9vB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tZXmWoPK, 0, m, &cVar_tZXmWoPK_sendMessage);
}

void Heavy_PhaseRing::cReceive_hCWsdjJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LuJdJzmu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4s6UAlqA_sendMessage);
}

void Heavy_PhaseRing::cReceive_ghxOfvx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SnWDloHN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iwLT7mxs, 0, m, &cVar_iwLT7mxs_sendMessage);
}

void Heavy_PhaseRing::cReceive_i6PWbdPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_o64KUlOS, 0, m, &cPack_o64KUlOS_sendMessage);
}

void Heavy_PhaseRing::cReceive_oHdcddXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DcFOFDEl, 1, m, &cVar_DcFOFDEl_sendMessage);
}

void Heavy_PhaseRing::cReceive_8atSetXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_33bOjuDc, m);
}

void Heavy_PhaseRing::cReceive_ZFwFO0dE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5epepYRA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZQ6dr5Pe, 0, m, &cVar_ZQ6dr5Pe_sendMessage);
}

void Heavy_PhaseRing::cReceive_BX5195QS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TO8mRI0f_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iXAR9BNO, 0, m, &cVar_iXAR9BNO_sendMessage);
}

void Heavy_PhaseRing::cReceive_uHKTDtox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gAOvJfnV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BRWseyD5, 0, m, &cVar_BRWseyD5_sendMessage);
}

void Heavy_PhaseRing::cReceive_Kcx1vUDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YHMo2vNL, 0, m, &cPack_YHMo2vNL_sendMessage);
}

void Heavy_PhaseRing::cReceive_VozYFjql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_szQbx5JT, 1, m, &cVar_szQbx5JT_sendMessage);
}

void Heavy_PhaseRing::cReceive_gWGIIkJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TlFuKxJy, m);
}

void Heavy_PhaseRing::cReceive_cc0Hdcfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gx21glYF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bJ4Jtvxg, 0, m, &cVar_bJ4Jtvxg_sendMessage);
}

void Heavy_PhaseRing::cReceive_PwabnvwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DtkGLhP1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DaU8lEEx, 0, m, &cVar_DaU8lEEx_sendMessage);
}

void Heavy_PhaseRing::cReceive_51U0050o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9oxNDIBO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rfyPG4fb, 0, m, &cVar_rfyPG4fb_sendMessage);
}

void Heavy_PhaseRing::cReceive_3Ttddo5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dv0wyXYD, 0, m, &cPack_dv0wyXYD_sendMessage);
}

void Heavy_PhaseRing::cReceive_qqZkRvqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OQTQGfX3, 1, m, &cVar_OQTQGfX3_sendMessage);
}

void Heavy_PhaseRing::cReceive_RViHAS67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_R4HrtQFB, m);
}

void Heavy_PhaseRing::cReceive_ZKiahiLS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_i4NAprGD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vbXZkDDr, 0, m, &cVar_vbXZkDDr_sendMessage);
}

void Heavy_PhaseRing::cReceive_tCBXysrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RSdCdLAl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LaQxPMqx, 0, m, &cVar_LaQxPMqx_sendMessage);
}

void Heavy_PhaseRing::cReceive_qawHGVJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_whcAJBQe_sendMessage);
}

void Heavy_PhaseRing::cReceive_CEhZt9in_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FWgJQ8Jo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pCzn3UOM_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_zdemUwI4, 0, m, &cPack_zdemUwI4_sendMessage);
}

void Heavy_PhaseRing::cReceive_sBtu3ipe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1grn6RFg, 0, m, &cVar_1grn6RFg_sendMessage);
}

void Heavy_PhaseRing::cReceive_CLeWNtPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_45xUuoaN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Qlx0rukB_sendMessage);
}

void Heavy_PhaseRing::cReceive_NaNZwWtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_3Vu8nR7y_sendMessage);
}

void Heavy_PhaseRing::cReceive_jhJX6wl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4EI6xETs, 0, m, &cVar_4EI6xETs_sendMessage);
}

void Heavy_PhaseRing::cReceive_6GAwzpGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rgyRkCHQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Unn8xiIy_sendMessage);
}

void Heavy_PhaseRing::cReceive_iSeAYiiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_qKW1vATt_sendMessage);
}

void Heavy_PhaseRing::cReceive_dDj1gONn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C0CgSJO1, 0, m, &cVar_C0CgSJO1_sendMessage);
}

void Heavy_PhaseRing::cReceive_UxKsKFFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JNV7xkTI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0WSKcOsb_sendMessage);
}

void Heavy_PhaseRing::cReceive_5QcGMf5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oYymC1Q0, 0, m, &cVar_oYymC1Q0_sendMessage);
}

void Heavy_PhaseRing::cReceive_J2kbkFVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fq3fwF2G_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QEd0klL2_sendMessage);
}

void Heavy_PhaseRing::cReceive_gsPJEUFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bv1eKTqn, 0, m, &cVar_bv1eKTqn_sendMessage);
}

void Heavy_PhaseRing::cReceive_9hk6hPlD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vUTU0rOG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6Wd2eICn_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_k73cXnPz, VOf(Bf0));
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
    __hv_line_f(&sLine_PKTYloo8, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_AUHfrJ6v, VOf(Bf0));
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
    __hv_line_f(&sLine_vkU8qyFt, VOf(Bf5));
    __hv_varread_f(&sVarf_4MiWnT4r, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_XSHc0Ia9, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_QvZeBKlp, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_gPUxC6HI, VOf(Bf3));
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
    __hv_line_f(&sLine_2wGmCP6f, VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_b77Uip5l, VOf(Bf3));
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
    __hv_line_f(&sLine_fkpNNbeY, VOf(Bf1));
    __hv_varread_f(&sVarf_33bOjuDc, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_uZlc43yW, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_VM7U9S3k, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_TwPMNSqD, VOf(Bf6));
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
    __hv_line_f(&sLine_lfjulrbb, VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_UQlC35Bg, VOf(Bf6));
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
    __hv_line_f(&sLine_UJQ3qvrt, VOf(Bf3));
    __hv_varread_f(&sVarf_TlFuKxJy, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_y0iwHJXT, VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_qcs4NT4o, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_Enk7pASw, VOf(Bf8));
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
    __hv_line_f(&sLine_ofjH5gHt, VOf(Bf9));
    __hv_phasor_k_f(&sPhasor_klqndxqF, VOf(Bf8));
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
    __hv_line_f(&sLine_3Q9siue6, VOf(Bf6));
    __hv_varread_f(&sVarf_R4HrtQFB, VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_AjhEoLRe, VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_SUo3sPnP, VOf(Bf6));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_8qxqPQ0y, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_iwX6FNnm, VOf(Bf6));
    __hv_phasor_f(&sPhasor_1YWSwqqQ, VIf(Bf6), VOf(Bf6));
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
    __hv_line_f(&sLine_b7aAIByH, VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_eX1XmOPT, VOf(Bf6));
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
    __hv_line_f(&sLine_67FSWtId, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_glIoRjzW, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_GCUpExZI, VOf(Bf11));
    __hv_rpole_f(&sRPole_40SLN4AE, VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Aqr3M9Zy, VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_8CuO9lEx, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_MUsAcsjq, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf7));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_add_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_cEfkkKfs, VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_neCt0u0x, VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_tabread_f(&sTabread_Ys5s11Pg, VOf(Bf7));
    __hv_varread_f(&sVarf_80zhOBzS, VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_SW07rReW, VOf(Bf0));
    __hv_rpole_f(&sRPole_F9p1qg0O, VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf0));
    __hv_line_f(&sLine_PLHq1d1h, VOf(Bf10));
    __hv_fma_f(VIf(Bf0), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_5hAnulJB, VOf(Bf0));
    __hv_tabread_f(&sTabread_67EzIRIe, VOf(Bf5));
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf9));
    __hv_tabread_f(&sTabread_zgD4o1zF, VOf(Bf6));
    __hv_add_f(VIf(Bf9), VIf(Bf6), VOf(Bf1));
    __hv_tabread_f(&sTabread_u0oJipNF, VOf(Bf8));
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf2));
    __hv_tabread_f(&sTabread_QLTQYVNM, VOf(Bf12));
    __hv_add_f(VIf(Bf2), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_qbwrOpHv, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_j3FCvULD, VIf(Bf15));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_A06E13j1, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_mfFAEgqr, VIf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_rk0cq70c, VIf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_yLQQoOMv, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_OAIcRncr, VIf(Bf3));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_qj0gKYka, VOf(Bf13));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_cUvUR4dE, VOf(Bf7));
    __hv_varread_f(&sVarf_7r1Y4ooD, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Np2LMZiG, VOf(Bf6));
    __hv_rpole_f(&sRPole_NtBVvwQp, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf7));
    __hv_tabread_f(&sTabread_RR5kdm1K, VOf(Bf6));
    __hv_varread_f(&sVarf_j47QkNgi, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_7LrvpiZq, VOf(Bf9));
    __hv_rpole_f(&sRPole_g2J69m1A, VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_tabread_f(&sTabread_K67nHFvW, VOf(Bf9));
    __hv_varread_f(&sVarf_sdbMylJD, VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_KYRZv9FD, VOf(Bf8));
    __hv_rpole_f(&sRPole_nECRggN7, VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf9));
    __hv_add_f(VIf(Bf7), VIf(Bf9), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_O0xU8mRH, VIf(Bf10));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf10));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf8));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_mJYYDbnn, VIf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_dCTeVU8K, VIf(Bf9));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_HyokTsKa, VIf(Bf8));
    __hv_line_f(&sLine_v5yKaspP, VOf(Bf8));
    __hv_mul_f(VIf(Bf14), VIf(Bf8), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf13));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_dcyduFWh, VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_bJAtj8sL, VIf(Bf6));
    __hv_line_f(&sLine_PapVVXG2, VOf(Bf8));
    __hv_phasor_f(&sPhasor_XiSahmyi, VIf(Bf8), VOf(Bf8));
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
    __hv_line_f(&sLine_7dmqaXz6, VOf(Bf1));
    __hv_line_f(&sLine_dF5MkyD8, VOf(Bf0));
    __hv_fma_f(VIf(Bf8), VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabhead_f(&sTabhead_fyNHHege, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_hYULEoNG, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_B3puZuTF, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf7));
    __hv_varread_f(&sVarf_r3SBiOvf, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_7VeimvbA, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_BhpISfFr, VIi(Bi0), VOf(Bf2));
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
    __hv_tabhead_f(&sTabhead_Ncw6jqHQ, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_AjCEyYil, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_xo0PuH6q, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf8));
    __hv_varread_f(&sVarf_ECOtSiwK, VOf(Bf0));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_txtDhCeY, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_RyAS8U0e, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf16), VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_X5MvNE68, VOf(Bf2));
    __hv_tabhead_f(&sTabhead_xKfNJ6dI, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_9R8cTYmr, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_wt7Hf6Y5, VOf(Bf2));
    __hv_min_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_JOZkTfsK, VOf(Bf2));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_EjwIG1T0, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_0GvHqizF, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf8), VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_xpuR5GTl, VOf(Bf17));
    __hv_rpole_f(&sRPole_Jn4gbNsO, VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_wP1N300m, VIf(Bf17), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_PaWux6rN, VOf(Bf17));
    __hv_mul_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_1ADVNZeK, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf17));
    __hv_line_f(&sLine_uLhRvkj8, VOf(Bf8));
    __hv_varread_f(&sVarf_ImIXwPOC, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_ysHOOdUa, VOf(Bf2));
    __hv_rpole_f(&sRPole_EvFl9jfu, VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_XjpyiVUt, VIf(Bf2));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_HTtj5Eyq, VOf(Bf17));
    __hv_varread_f(&sVarf_Thu1yC1L, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_6K6LZ0P0, VOf(Bf2));
    __hv_min_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_G488OcuY, VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_varread_f(&sVarf_MqrhPoRK, VOf(Bf2));
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
    __hv_cpole_f(&sCPole_LeNGF1Lp, VIf(Bf2), VIf(ZERO), VIf(Bf0), VIf(Bf17), VOf(Bf17), VOf(Bf0));
    __hv_varread_f(&sVarf_7ExfHys2, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_GSGz0Jj4, VOf(Bf17));
    __hv_rpole_f(&sRPole_g2STlTqp, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_wR3iwfXo, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_uUXnc56J, VOf(Bf17));
    __hv_rpole_f(&sRPole_OpnQXJ1B, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_BRv2Tpjt, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_l7DmsHrf, VOf(Bf17));
    __hv_rpole_f(&sRPole_WPBrTeM0, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_X8n8jThG, VOf(Bf0));
    __hv_varread_f(&sVarf_VMCrHD8y, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_MDg5XWZi, VOf(Bf8));
    __hv_rpole_f(&sRPole_jSZqQ0lL, VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf8));
    __hv_line_f(&sLine_Jg3s4D1U, VOf(Bf2));
    __hv_fma_f(VIf(Bf8), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_aEsnGRZY, VOf(Bf8));
    __hv_tabread_f(&sTabread_AwhXa1Ng, VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf12));
    __hv_tabread_f(&sTabread_KSlFr7mp, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_qRhYlQLm, VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf18));
    __hv_tabread_f(&sTabread_X0LsXJ8p, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf9));
    __hv_tabread_f(&sTabread_fHleRiW7, VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_pwvPJ18S, VIf(Bf5));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_vwhKMr0I, VIf(Bf15));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_qtj81PRF, VIf(Bf7));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_JMfmRKr6, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_eoRIXOU8, VIf(Bf6));
    __hv_tabwrite_f(&sTabwrite_9oAWvycu, VIf(Bf17));
    __hv_add_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_i0nUPV0N, VOf(Bf9));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_U8yFvSeH, VOf(Bf0));
    __hv_varread_f(&sVarf_WxuCPDrV, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_grFrKiK8, VOf(Bf16));
    __hv_rpole_f(&sRPole_SG2qPBr0, VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf0));
    __hv_tabread_f(&sTabread_1QZ9j9kB, VOf(Bf16));
    __hv_varread_f(&sVarf_xV2AZBCF, VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_3TRoGytN, VOf(Bf12));
    __hv_rpole_f(&sRPole_gdSJK9Ls, VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf16));
    __hv_tabread_f(&sTabread_81UfMuMh, VOf(Bf12));
    __hv_varread_f(&sVarf_oAzfR1Fg, VOf(Bf6));
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_3WwDXyzG, VOf(Bf7));
    __hv_rpole_f(&sRPole_78JjUjzn, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf12), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf16), VIf(Bf8), VOf(Bf12));
    __hv_add_f(VIf(Bf0), VIf(Bf12), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_oQkEofYY, VIf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf2));
    __hv_sub_f(VIf(Bf16), VIf(Bf8), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf7), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_abHPcO78, VIf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_lVqJ67wj, VIf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_axHp8D1Y, VIf(Bf7));
    __hv_line_f(&sLine_9JANBMrb, VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf16), VIf(Bf7), VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_2ulNQBW7, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_zZeUuENe, VIf(Bf10));
    __hv_line_f(&sLine_kQZ4WyTN, VOf(Bf10));
    __hv_phasor_f(&sPhasor_U7wgqZ4E, VIf(Bf10), VOf(Bf10));
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
    __hv_line_f(&sLine_FWHXK7UL, VOf(Bf2));
    __hv_line_f(&sLine_NYkFsGOG, VOf(Bf3));
    __hv_fma_f(VIf(Bf10), VIf(Bf2), VIf(Bf3), VOf(Bf0));
    __hv_tabhead_f(&sTabhead_TS7P7xQr, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_LeT5vdn3, VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_bWhtdLBz, VOf(Bf0));
    __hv_min_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf9));
    __hv_varread_f(&sVarf_VVRMQJZm, VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_OgKEU2x4, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_fllwqEiV, VIi(Bi0), VOf(Bf0));
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
    __hv_tabhead_f(&sTabhead_lcGu26cY, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf10), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_c8UOcUI6, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_GKpB4cI1, VOf(Bf3));
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf10));
    __hv_varread_f(&sVarf_qiUpTbwx, VOf(Bf3));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_QrAwO8Fn, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_BGbK8XdQ, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf1), VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_WJZu03VI, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_7BRePxTP, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_zaKt4Hps, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_00zQrgip, VOf(Bf0));
    __hv_min_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_Llk9n9su, VOf(Bf0));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_SpBVxlSp, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_CiU8dxtr, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf10));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf10), VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_JsFdbytZ, VOf(Bf15));
    __hv_rpole_f(&sRPole_VEnQJT2g, VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_KHoqDlOB, VIf(Bf15), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_GW74Pjns, VOf(Bf15));
    __hv_mul_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_Fstt3lug, VOf(Bf0));
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf15));
    __hv_line_f(&sLine_zJD1I8kT, VOf(Bf10));
    __hv_varread_f(&sVarf_boDQkf3r, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_RB5vETCB, VOf(Bf0));
    __hv_rpole_f(&sRPole_mLACGxL9, VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_gLnBb38i, VIf(Bf0));
    __hv_var_k_f(VOf(Bf0), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf14), VIf(Bf0), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_Wz7rkSKw, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_MwVyL2cc, VOf(Bf11));
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

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
  numBytes += sPhasor_k_init(&sPhasor_KupL8rk4, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_yCZ5UF5E);
  numBytes += sPhasor_k_init(&sPhasor_jQoJc3jA, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_LCNx6j0h);
  numBytes += sLine_init(&sLine_KU8NrRpw);
  numBytes += sLine_init(&sLine_Wiminwiw);
  numBytes += sPhasor_k_init(&sPhasor_EKX5j2AH, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_M8zZGzLr);
  numBytes += sPhasor_k_init(&sPhasor_2W9lcyq0, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_P93JhlOV);
  numBytes += sLine_init(&sLine_y81cXvBh);
  numBytes += sLine_init(&sLine_AwubTsXz);
  numBytes += sPhasor_k_init(&sPhasor_LB2ew2iH, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_1379S3bt);
  numBytes += sPhasor_k_init(&sPhasor_nf2jQAJ2, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_oUK3aHfG);
  numBytes += sLine_init(&sLine_Zx1Khw9H);
  numBytes += sLine_init(&sLine_2B3idU3w);
  numBytes += sPhasor_k_init(&sPhasor_FEpaSRFq, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_ISm6S5dl);
  numBytes += sPhasor_k_init(&sPhasor_wgZ6wBNY, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_DHtymZqR);
  numBytes += sLine_init(&sLine_kTXW25HV);
  numBytes += sLine_init(&sLine_0HqE5T6z);
  numBytes += sLine_init(&sLine_I23XyPSZ);
  numBytes += sLine_init(&sLine_nLRqvWAz);
  numBytes += sPhasor_init(&sPhasor_GPVMkv4M, sampleRate);
  numBytes += sLine_init(&sLine_5zxIH7av);
  numBytes += sPhasor_k_init(&sPhasor_ZBbMdwex, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_OWfRZIbw);
  numBytes += sLine_init(&sLine_odE54cL6);
  numBytes += sRPole_init(&sRPole_eJkYAeDp);
  numBytes += sDel1_init(&sDel1_atLVhQqU);
  numBytes += sLine_init(&sLine_fDOQsrwE);
  numBytes += sLine_init(&sLine_pO1nUgkE);
  numBytes += sLine_init(&sLine_8Db04CFa);
  numBytes += sTabread_init(&sTabread_SCiAZ5ej, &hTable_pgPZf0IE, true);
  numBytes += sRPole_init(&sRPole_ukpk8D0G);
  numBytes += sLine_init(&sLine_YNdmCaIO);
  numBytes += sLine_init(&sLine_OCEdvZRu);
  numBytes += sTabread_init(&sTabread_AkqyJDpE, &hTable_HXWSxKDU, true);
  numBytes += sTabread_init(&sTabread_0Af6xxwK, &hTable_UI28wuy7, true);
  numBytes += sTabread_init(&sTabread_cdVPKRuV, &hTable_lbIc8ogL, true);
  numBytes += sTabread_init(&sTabread_aUfhIf8I, &hTable_IKDHvxMN, true);
  numBytes += sTabread_init(&sTabread_YJ4wweYe, &hTable_grQHM5HS, true);
  numBytes += sTabwrite_init(&sTabwrite_YMuJVHKs, &hTable_OnYdYUyR);
  numBytes += sTabwrite_init(&sTabwrite_sgXiCgJ0, &hTable_grQHM5HS);
  numBytes += sTabwrite_init(&sTabwrite_4ygwkJN6, &hTable_IKDHvxMN);
  numBytes += sTabwrite_init(&sTabwrite_W1KqlR5W, &hTable_lbIc8ogL);
  numBytes += sTabwrite_init(&sTabwrite_6X3zPgzv, &hTable_UI28wuy7);
  numBytes += sTabwrite_init(&sTabwrite_Wf3JLY5U, &hTable_HXWSxKDU);
  numBytes += sTabread_init(&sTabread_dJZHmhaK, &hTable_OnYdYUyR, true);
  numBytes += sTabread_init(&sTabread_kbnk23zl, &hTable_gcHyd7im, true);
  numBytes += sRPole_init(&sRPole_hqZLxa8z);
  numBytes += sTabread_init(&sTabread_nX943Mky, &hTable_hwX01sys, true);
  numBytes += sRPole_init(&sRPole_8zMTva9T);
  numBytes += sTabread_init(&sTabread_9gZBr7Nn, &hTable_WFbfQ60g, true);
  numBytes += sRPole_init(&sRPole_CAijZ5ok);
  numBytes += sTabwrite_init(&sTabwrite_IpWOMN7X, &hTable_pgPZf0IE);
  numBytes += sTabwrite_init(&sTabwrite_8PaB8R5s, &hTable_gcHyd7im);
  numBytes += sTabwrite_init(&sTabwrite_sX1AxrfI, &hTable_hwX01sys);
  numBytes += sTabwrite_init(&sTabwrite_uLATWRDs, &hTable_WFbfQ60g);
  numBytes += sLine_init(&sLine_0HprnEfv);
  numBytes += sLine_init(&sLine_KJf5FkvN);
  numBytes += sTabwrite_init(&sTabwrite_fUUiNl5n, &hTable_vyXqPpGz);
  numBytes += sLine_init(&sLine_mzxCLgbx);
  numBytes += sPhasor_init(&sPhasor_bz8atC2r, sampleRate);
  numBytes += sLine_init(&sLine_fBjfcEse);
  numBytes += sLine_init(&sLine_HroFg6Ql);
  numBytes += sTabhead_init(&sTabhead_jXXzowPB, &hTable_vyXqPpGz);
  numBytes += sTabread_init(&sTabread_9S29kSto, &hTable_vyXqPpGz, false);
  numBytes += sTabread_init(&sTabread_xhNyUEru, &hTable_vyXqPpGz, false);
  numBytes += sTabhead_init(&sTabhead_SO9xpg3p, &hTable_vyXqPpGz);
  numBytes += sTabread_init(&sTabread_WIEDHSU3, &hTable_vyXqPpGz, false);
  numBytes += sTabread_init(&sTabread_n7nuVJbz, &hTable_vyXqPpGz, false);
  numBytes += sTabhead_init(&sTabhead_2R4kKfLl, &hTable_3s6AKaH3);
  numBytes += sTabread_init(&sTabread_WFbcDkNg, &hTable_3s6AKaH3, false);
  numBytes += sTabread_init(&sTabread_0IrnFXgc, &hTable_3s6AKaH3, false);
  numBytes += sRPole_init(&sRPole_LAWhM57q);
  numBytes += sDel1_init(&sDel1_CFUSDDew);
  numBytes += sLine_init(&sLine_sEA64x1r);
  numBytes += sRPole_init(&sRPole_c407WftA);
  numBytes += sTabwrite_init(&sTabwrite_pe0F4E1o, &hTable_3s6AKaH3);
  numBytes += sCPole_init(&sCPole_gIMPSaxl);
  numBytes += sRPole_init(&sRPole_FXWV1jky);
  numBytes += sRPole_init(&sRPole_r7pemxc4);
  numBytes += sRPole_init(&sRPole_G1QLrmt1);
  numBytes += sTabread_init(&sTabread_N1KtBq9B, &hTable_K1aScmmi, true);
  numBytes += sRPole_init(&sRPole_tHuTnwvX);
  numBytes += sLine_init(&sLine_X9VNqmng);
  numBytes += sLine_init(&sLine_9XhIlXlt);
  numBytes += sTabread_init(&sTabread_tGeCXlmx, &hTable_0uBwf0XD, true);
  numBytes += sTabread_init(&sTabread_901JJraY, &hTable_GUL21Yeq, true);
  numBytes += sTabread_init(&sTabread_TNEawRUc, &hTable_EYemnlv2, true);
  numBytes += sTabread_init(&sTabread_fCmcOsqk, &hTable_70Qa0lXY, true);
  numBytes += sTabread_init(&sTabread_7ExfUmls, &hTable_fgSHe5Ec, true);
  numBytes += sTabwrite_init(&sTabwrite_tw7hAKLU, &hTable_klSDzc9D);
  numBytes += sTabwrite_init(&sTabwrite_DPtLct7K, &hTable_fgSHe5Ec);
  numBytes += sTabwrite_init(&sTabwrite_zNHpzpPC, &hTable_70Qa0lXY);
  numBytes += sTabwrite_init(&sTabwrite_N9lXNEBn, &hTable_EYemnlv2);
  numBytes += sTabwrite_init(&sTabwrite_zYAn3Pa6, &hTable_GUL21Yeq);
  numBytes += sTabwrite_init(&sTabwrite_JDYYESne, &hTable_0uBwf0XD);
  numBytes += sTabread_init(&sTabread_cbnmZkC3, &hTable_klSDzc9D, true);
  numBytes += sTabread_init(&sTabread_TizZqi4E, &hTable_3LkNluZU, true);
  numBytes += sRPole_init(&sRPole_JjCc25kf);
  numBytes += sTabread_init(&sTabread_hHyAglfJ, &hTable_DTDd40da, true);
  numBytes += sRPole_init(&sRPole_D0Y7KClU);
  numBytes += sTabread_init(&sTabread_ChyqmDJ7, &hTable_6XR14HlF, true);
  numBytes += sRPole_init(&sRPole_J6xHci59);
  numBytes += sTabwrite_init(&sTabwrite_j0ichkzQ, &hTable_K1aScmmi);
  numBytes += sTabwrite_init(&sTabwrite_g8tuq0tx, &hTable_3LkNluZU);
  numBytes += sTabwrite_init(&sTabwrite_zK6oCu99, &hTable_DTDd40da);
  numBytes += sTabwrite_init(&sTabwrite_y26wtbcY, &hTable_6XR14HlF);
  numBytes += sLine_init(&sLine_fcBaLfBX);
  numBytes += sLine_init(&sLine_XMNwGU4a);
  numBytes += sTabwrite_init(&sTabwrite_soY6jzND, &hTable_guhiLadY);
  numBytes += sLine_init(&sLine_MbeYeuMO);
  numBytes += sPhasor_init(&sPhasor_TgISGE7R, sampleRate);
  numBytes += sLine_init(&sLine_mzMT2qN8);
  numBytes += sLine_init(&sLine_gLJMVqkf);
  numBytes += sTabhead_init(&sTabhead_W1H5osb5, &hTable_guhiLadY);
  numBytes += sTabread_init(&sTabread_sLHRrj5Y, &hTable_guhiLadY, false);
  numBytes += sTabread_init(&sTabread_N3mTSvnR, &hTable_guhiLadY, false);
  numBytes += sTabhead_init(&sTabhead_MBqnYgup, &hTable_guhiLadY);
  numBytes += sTabread_init(&sTabread_OqKPN3Uy, &hTable_guhiLadY, false);
  numBytes += sTabread_init(&sTabread_8EVL16eC, &hTable_guhiLadY, false);
  numBytes += sTabhead_init(&sTabhead_CjTR0srb, &hTable_di1iubhs);
  numBytes += sTabread_init(&sTabread_9bagjJ0g, &hTable_di1iubhs, false);
  numBytes += sTabread_init(&sTabread_MAi0f6JL, &hTable_di1iubhs, false);
  numBytes += sRPole_init(&sRPole_cRmWxyf0);
  numBytes += sDel1_init(&sDel1_rLW9lDlP);
  numBytes += sLine_init(&sLine_cYQl9xOB);
  numBytes += sRPole_init(&sRPole_2xySuOO2);
  numBytes += sTabwrite_init(&sTabwrite_9qsXjxfx, &hTable_di1iubhs);
  numBytes += sLine_init(&sLine_p2v7lRUr);
  numBytes += sLine_init(&sLine_QZjWrUld);
  numBytes += cSlice_init(&cSlice_pJYnbGAE, 2, 1);
  numBytes += cSlice_init(&cSlice_urQKbdvJ, 1, 1);
  numBytes += cSlice_init(&cSlice_2d1FImcy, 0, 1);
  numBytes += cVar_init_f(&cVar_DZoGRvWO, 0.0f);
  numBytes += cIf_init(&cIf_6VFNLK73, false);
  numBytes += cIf_init(&cIf_YT6OzAOI, false);
  numBytes += cIf_init(&cIf_zeZBKZp2, false);
  numBytes += cIf_init(&cIf_l6Op3Eiy, false);
  numBytes += cIf_init(&cIf_twkiVEg1, false);
  numBytes += cBinop_init(&cBinop_hGcbRE0v, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_rYYQyHY9, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_eANBshng, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9n1LtUF0, 5.0f);
  numBytes += cBinop_init(&cBinop_3RmydNXy, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_ldBCSB6D, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_xnLJfynF, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_kxA2BqJY, "floatatom");
  numBytes += cVar_init_s(&cVar_EsFn7rPq, "floatatom");
  numBytes += cIf_init(&cIf_Ch9kt21n, false);
  numBytes += cIf_init(&cIf_UuzKOOUy, false);
  numBytes += cIf_init(&cIf_6zKxGMpB, false);
  numBytes += cIf_init(&cIf_cy6Tw3xc, false);
  numBytes += cPack_init(&cPack_77hFqgJt, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_MwiWrvJV, 2, 0.0f, 80.0f);
  numBytes += cPack_init(&cPack_xQjFqcxK, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_7OdCMXoC, -1839858323);
  numBytes += cSlice_init(&cSlice_atjqamt9, 1, 1);
  numBytes += cVar_init_s(&cVar_9BJqEEmU, "floatatom");
  numBytes += cRandom_init(&cRandom_31zt7s6R, 871676115);
  numBytes += cSlice_init(&cSlice_ASpW116q, 1, 1);
  numBytes += cVar_init_s(&cVar_19rMM5BP, "floatatom");
  numBytes += cVar_init_f(&cVar_1kFk0586, 1.0f);
  numBytes += cVar_init_f(&cVar_1RjHGpbJ, 0.0f);
  numBytes += cVar_init_f(&cVar_H9szrrGF, 0.0f);
  numBytes += cRandom_init(&cRandom_xnYfS2wp, 163070327);
  numBytes += cSlice_init(&cSlice_UKh7BPEf, 1, 1);
  numBytes += cRandom_init(&cRandom_TCIoyOu3, 372300943);
  numBytes += cSlice_init(&cSlice_sWvZ52N8, 1, 1);
  numBytes += cRandom_init(&cRandom_O9XXc8aH, -1107545110);
  numBytes += cSlice_init(&cSlice_pRWijCeY, 1, 1);
  numBytes += cBinop_init(&cBinop_Ha0nI3Aj, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_Yx1E86vL, 1939440277);
  numBytes += cSlice_init(&cSlice_DQSlsmXW, 1, 1);
  numBytes += cPack_init(&cPack_9Ct5EGJa, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_5vAOqlSd, "floatatom");
  numBytes += cVar_init_s(&cVar_4SgIdkam, "floatatom");
  numBytes += cVar_init_s(&cVar_VjGtFmIE, "floatatom");
  numBytes += cVar_init_f(&cVar_bL299idK, 0.0f);
  numBytes += cVar_init_s(&cVar_8zEbK0a5, "floatatom");
  numBytes += cVar_init_s(&cVar_mX4DVZwZ, "floatatom");
  numBytes += cVar_init_s(&cVar_gXLyN6yV, "floatatom");
  numBytes += cDelay_init(this, &cDelay_h9a7Uq10, 25.0f);
  numBytes += cVar_init_f(&cVar_d7xbKJSs, 0.0f);
  numBytes += sVarf_init(&sVarf_jyfWku8B, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_PvJ4HMrl, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_tMVLFKpD, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_IwWHqRHS, 1, 1);
  numBytes += cSlice_init(&cSlice_fQrcROrY, 0, 1);
  numBytes += cBinop_init(&cBinop_oJs6fuNZ, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_5fCMrO4S, 98.0f);
  numBytes += cIf_init(&cIf_YdFZe4ns, false);
  numBytes += cBinop_init(&cBinop_qL1SZxrX, 0.0f); // __pow
  numBytes += cPack_init(&cPack_JQPDIOJH, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_wqvqiksN, 0.0f);
  numBytes += cRandom_init(&cRandom_cQLNL3zY, -1418496128);
  numBytes += cSlice_init(&cSlice_4taF2ET3, 1, 1);
  numBytes += cBinop_init(&cBinop_yuM7rWlo, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_pPgusswa, -1987981692);
  numBytes += cSlice_init(&cSlice_MA7czWVA, 1, 1);
  numBytes += cPack_init(&cPack_JzHBc5xA, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_bzxhWGhw, "floatatom");
  numBytes += cVar_init_s(&cVar_DNHWcE5U, "floatatom");
  numBytes += cVar_init_s(&cVar_3GEwdbHA, "floatatom");
  numBytes += cVar_init_f(&cVar_KzYhEUqd, 0.0f);
  numBytes += cVar_init_s(&cVar_WlDCW7Hd, "floatatom");
  numBytes += cVar_init_s(&cVar_6wIw5zOx, "floatatom");
  numBytes += cVar_init_s(&cVar_ay6Axlvk, "floatatom");
  numBytes += cDelay_init(this, &cDelay_Mo3r272g, 25.0f);
  numBytes += cVar_init_f(&cVar_eiBMlk1o, 0.0f);
  numBytes += sVarf_init(&sVarf_vpD4GvgD, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_Q29jOqWk, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_IkT7oU0M, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_L5yRvuNe, 1, 1);
  numBytes += cSlice_init(&cSlice_jUBi9E0n, 0, 1);
  numBytes += cBinop_init(&cBinop_zKLgK6RO, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_kqSw7Q9W, 1831321585);
  numBytes += cSlice_init(&cSlice_emBRX8R6, 1, 1);
  numBytes += cBinop_init(&cBinop_43xjdRJu, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_DN6i49pY, -1934031120);
  numBytes += cSlice_init(&cSlice_si9GhHfF, 1, 1);
  numBytes += cPack_init(&cPack_tIeJMhc3, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_kGQqzVpB, "floatatom");
  numBytes += cVar_init_s(&cVar_IkMvwwrm, "floatatom");
  numBytes += cVar_init_s(&cVar_St0WSmTm, "floatatom");
  numBytes += cVar_init_f(&cVar_gdz77FuD, 0.0f);
  numBytes += cVar_init_s(&cVar_ADFKvGqw, "floatatom");
  numBytes += cVar_init_s(&cVar_35ClfaMM, "floatatom");
  numBytes += cVar_init_s(&cVar_3Mfmya7W, "floatatom");
  numBytes += cDelay_init(this, &cDelay_EEVFXi6s, 25.0f);
  numBytes += cVar_init_f(&cVar_fuu1l6TP, 0.0f);
  numBytes += sVarf_init(&sVarf_o6uIPriL, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_A1gdQFHg, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_XKnoZ4C7, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_87noxniN, 1, 1);
  numBytes += cSlice_init(&cSlice_VcKrQMbH, 0, 1);
  numBytes += cBinop_init(&cBinop_gQDmWdV7, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_2tCzZa8y, 246663750);
  numBytes += cSlice_init(&cSlice_Rg0YYvmI, 1, 1);
  numBytes += cBinop_init(&cBinop_eZSjtQVT, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_K5tPsM9l, 953754747);
  numBytes += cSlice_init(&cSlice_zeiMsRQT, 1, 1);
  numBytes += cPack_init(&cPack_0Orw5xlf, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_ia9skgs2, "floatatom");
  numBytes += cVar_init_s(&cVar_vVGy03qd, "floatatom");
  numBytes += cVar_init_s(&cVar_Nl85qvXx, "floatatom");
  numBytes += cVar_init_f(&cVar_tLoaVAEH, 0.0f);
  numBytes += cVar_init_s(&cVar_vNYLbCbD, "floatatom");
  numBytes += cVar_init_s(&cVar_HKC6CFrx, "floatatom");
  numBytes += cVar_init_s(&cVar_1AnGgcMA, "floatatom");
  numBytes += cDelay_init(this, &cDelay_HvZs9rW8, 25.0f);
  numBytes += cVar_init_f(&cVar_HLArS4Bg, 0.0f);
  numBytes += sVarf_init(&sVarf_L5VlFBwx, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_FAy19rGU, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_7BlV7H0w, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_aGFuVIpq, 1, 1);
  numBytes += cSlice_init(&cSlice_BN7cx0Gf, 0, 1);
  numBytes += cBinop_init(&cBinop_T4wyosMe, 1.0f); // __mul
  numBytes += cTabhead_init(&cTabhead_IMwe3nPg, &hTable_pgPZf0IE);
  numBytes += cVar_init_s(&cVar_D0FpZg8t, "del-1209-del1");
  numBytes += cDelay_init(this, &cDelay_jY3Ty1EC, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_GIP4xKs4, 0.0f);
  numBytes += cBinop_init(&cBinop_KZ65lBkA, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_el4mRY3o, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fOBcn907, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_IeLiIdDR, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_Hg1oudlu, &hTable_gcHyd7im);
  numBytes += cVar_init_s(&cVar_edpZMBKO, "del-1209-del2");
  numBytes += cDelay_init(this, &cDelay_VsFzuik0, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_TYnX2QFK, 0.0f);
  numBytes += cBinop_init(&cBinop_D98s8usE, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_tp8Xo4VR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_CP65G6oK, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_bDGHZjcc, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_dpicMwrf, &hTable_hwX01sys);
  numBytes += cVar_init_s(&cVar_uxMuFUYk, "del-1209-del3");
  numBytes += cDelay_init(this, &cDelay_nAxvVKDs, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_em4V3bfI, 0.0f);
  numBytes += cBinop_init(&cBinop_IUkjt1TS, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_GLjyDCHi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_uRtrO9sw, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_3Z7pqHFH, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_7SacHoqo, &hTable_WFbfQ60g);
  numBytes += cVar_init_s(&cVar_JOarUAdq, "del-1209-del4");
  numBytes += cDelay_init(this, &cDelay_QSyaPP8Z, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_pJFoxiT3, 0.0f);
  numBytes += cBinop_init(&cBinop_K7rMxLkT, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_kEPxrPbk, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_shr2ES1b, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_YIYpUPPS, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_VFE34itR, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ciXARioa, 0.0f);
  numBytes += hTable_init(&hTable_pgPZf0IE, 256);
  numBytes += cDelay_init(this, &cDelay_E6NhkF3o, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zRepZjUw, 0.0f);
  numBytes += hTable_init(&hTable_gcHyd7im, 256);
  numBytes += cDelay_init(this, &cDelay_3OQy15n8, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ZUhYwtMt, 0.0f);
  numBytes += hTable_init(&hTable_hwX01sys, 256);
  numBytes += cDelay_init(this, &cDelay_yxr76SAm, 0.0f);
  numBytes += cDelay_init(this, &cDelay_shNGIKSY, 0.0f);
  numBytes += hTable_init(&hTable_WFbfQ60g, 256);
  numBytes += cIf_init(&cIf_tffwZN4M, false);
  numBytes += cBinop_init(&cBinop_2hPczHq2, 0.0f); // __pow
  numBytes += cPack_init(&cPack_5cGHpwXI, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_wvfA3FwO, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_Qs45NgZZ, 22050.0f);
  numBytes += cBinop_init(&cBinop_T8fz72kT, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_u8HOxMwx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9QUtcGKm, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_yVIvHqaq, 95.0f);
  numBytes += cVar_init_f(&cVar_fggGamqk, 90.0f);
  numBytes += cVar_init_f(&cVar_PphZneDn, 6000.0f);
  numBytes += cVar_init_f(&cVar_q8CjSUa9, 60.0f);
  numBytes += cIf_init(&cIf_NNPgEX51, false);
  numBytes += cTabhead_init(&cTabhead_VlBMV2gL, &hTable_OnYdYUyR);
  numBytes += cVar_init_s(&cVar_DnT4jY1y, "del-1209-ref6");
  numBytes += cDelay_init(this, &cDelay_YQwUiXj2, 13.645f);
  numBytes += cDelay_init(this, &cDelay_RsziTqO3, 0.0f);
  numBytes += cBinop_init(&cBinop_L9JMQJij, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_srimtoJc, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jtekiNK0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_fKW36ceb, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_6sa91CDy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_9nAHaqD3, 0.0f);
  numBytes += hTable_init(&hTable_OnYdYUyR, 256);
  numBytes += cTabhead_init(&cTabhead_YMntfmcA, &hTable_grQHM5HS);
  numBytes += cVar_init_s(&cVar_UOaRLbba, "del-1209-ref5");
  numBytes += cDelay_init(this, &cDelay_hQJUvCnk, 16.364f);
  numBytes += cDelay_init(this, &cDelay_yamN075Q, 0.0f);
  numBytes += cBinop_init(&cBinop_JjQ7ioeH, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_feGCcxyn, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_1YoBDDX8, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_aaavNkPr, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ONwFLmuw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_pf2EBUvy, 0.0f);
  numBytes += hTable_init(&hTable_grQHM5HS, 256);
  numBytes += cTabhead_init(&cTabhead_HFG71gw9, &hTable_IKDHvxMN);
  numBytes += cVar_init_s(&cVar_CmYwz2BP, "del-1209-ref4");
  numBytes += cDelay_init(this, &cDelay_kt0uOeEr, 19.392f);
  numBytes += cDelay_init(this, &cDelay_Xxp2hxM8, 0.0f);
  numBytes += cBinop_init(&cBinop_A3uS268K, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_XJC2Lnas, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_y0VVIrYP, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_6WnJt3pK, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_WQk8zHce, 0.0f);
  numBytes += cDelay_init(this, &cDelay_6eY6tb2m, 0.0f);
  numBytes += hTable_init(&hTable_IKDHvxMN, 256);
  numBytes += cTabhead_init(&cTabhead_YcdN9ZMp, &hTable_lbIc8ogL);
  numBytes += cVar_init_s(&cVar_dBpOBpDz, "del-1209-ref3");
  numBytes += cDelay_init(this, &cDelay_mimp5Jwf, 25.796f);
  numBytes += cDelay_init(this, &cDelay_8rHSrGun, 0.0f);
  numBytes += cBinop_init(&cBinop_cXmg0ciX, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_0EIR5ggF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_AggYFerR, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_nN3AvzZF, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_BCIpgQY7, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2xcEdaQ9, 0.0f);
  numBytes += hTable_init(&hTable_lbIc8ogL, 256);
  numBytes += cTabhead_init(&cTabhead_iA56AgyJ, &hTable_UI28wuy7);
  numBytes += cVar_init_s(&cVar_pMisGsDW, "del-1209-ref2");
  numBytes += cDelay_init(this, &cDelay_C3gJ3QA1, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_zsPNEZbS, 0.0f);
  numBytes += cBinop_init(&cBinop_w48yXRKm, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_R0lBc1EU, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_o8sjXksm, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_eHma0e2z, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_hQSh3Vip, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zrn9HoHn, 0.0f);
  numBytes += hTable_init(&hTable_UI28wuy7, 256);
  numBytes += cTabhead_init(&cTabhead_rCqdHZP6, &hTable_HXWSxKDU);
  numBytes += cVar_init_s(&cVar_a5pMPZMC, "del-1209-ref1");
  numBytes += cDelay_init(this, &cDelay_3GacL0nI, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_5sIwgL3E, 0.0f);
  numBytes += cBinop_init(&cBinop_GQZfs91s, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_vGrqpFbn, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eXQ9yv6D, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_C6ZLwXkw, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ylMzCEGz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2e9tv64E, 0.0f);
  numBytes += hTable_init(&hTable_HXWSxKDU, 256);
  numBytes += cVar_init_f(&cVar_UE2NlU6a, 0.0f);
  numBytes += cVar_init_f(&cVar_MQAzBCR1, 0.0f);
  numBytes += cPack_init(&cPack_rHjiJj5d, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_NirfK3pc, 22050.0f);
  numBytes += cBinop_init(&cBinop_IX3YMtwx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_lcZ10pFH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XB0GKQXA, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_rYtsEwgf, 22050.0f);
  numBytes += cBinop_init(&cBinop_NlA40NGJ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ZmSFKFZ5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gqGJq891, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_zzeqD4ps, 22050.0f);
  numBytes += cBinop_init(&cBinop_uwNV2JLB, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_P0qK0Zi0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5nWro7Fk, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_gmYGXyom, false);
  numBytes += cDelay_init(this, &cDelay_UlTUgu0H, 50.0f);
  numBytes += cVar_init_f(&cVar_ZDnAPNmg, 0.0f);
  numBytes += cVar_init_f(&cVar_kE6ziXzN, 12.0f);
  numBytes += cVar_init_s(&cVar_ejzsZLNQ, "floatatom");
  numBytes += cPack_init(&cPack_KOAuQBbt, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_v6eDtMGb, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_gKxIEzVQ, "floatatom");
  numBytes += cDelay_init(this, &cDelay_XvSJZbCX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_AljaQDRL, 0.0f);
  numBytes += hTable_init(&hTable_vyXqPpGz, 256);
  numBytes += cVar_init_s(&cVar_ow42iGtw, "del-1316-del");
  numBytes += sVarf_init(&sVarf_cboCLk4T, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zu0z7tLz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4Sm3YqjO, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_rYglaobA, "del-1316-del");
  numBytes += sVarf_init(&sVarf_2sb2Pj7Z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mj8lvNqY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yIEpzLjm, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_7Q7Ku0ck, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_vNB7vmoA, 4720.0f);
  numBytes += cBinop_init(&cBinop_wUdEchLk, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wezXNcbi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rv5Wyvjj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mh8knXVY, 4720.0f);
  numBytes += cBinop_init(&cBinop_gYuJGpxM, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_6qSZ1emO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_K7ZJidyG, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_DOdxgB2j, 4720.0f);
  numBytes += cBinop_init(&cBinop_nBj79MUE, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_64AiehE0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aKn3TGo8, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_rHdiT0C4, 1.0f);
  numBytes += cIf_init(&cIf_f88IriLp, false);
  numBytes += sVarf_init(&sVarf_gjVVJfE2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_H69Y9moT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_k8WWzsdp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BLcMibJp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_A7QOGCN7, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_w0qwgau0, &hTable_K1aScmmi);
  numBytes += cVar_init_s(&cVar_WKqWlziK, "del-1379-del1");
  numBytes += cDelay_init(this, &cDelay_u4iJSCNy, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_gzgXR07b, 0.0f);
  numBytes += cBinop_init(&cBinop_HLgsX0Xo, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_V83Cm21H, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_0AyTeWOz, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_yQvCdi0Y, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_v2DPnjXn, &hTable_3LkNluZU);
  numBytes += cVar_init_s(&cVar_BxVdRu3f, "del-1379-del2");
  numBytes += cDelay_init(this, &cDelay_UayTqgsP, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_1l94TooO, 0.0f);
  numBytes += cBinop_init(&cBinop_yxpv0vF6, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_KOyryfGV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cvGtM9oa, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_DC0GiVjm, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_psRGDwv1, &hTable_DTDd40da);
  numBytes += cVar_init_s(&cVar_ech2kDFp, "del-1379-del3");
  numBytes += cDelay_init(this, &cDelay_rvGNcrzs, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_kXQoQaRk, 0.0f);
  numBytes += cBinop_init(&cBinop_ig7BVmNT, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_YTnZ0jcR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_M3ISVrmj, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_FUw5O85B, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_hE32Qk0j, &hTable_6XR14HlF);
  numBytes += cVar_init_s(&cVar_8h7MhJNv, "del-1379-del4");
  numBytes += cDelay_init(this, &cDelay_Op72lj8X, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_LTwnqIST, 0.0f);
  numBytes += cBinop_init(&cBinop_DT3KbUSJ, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_5nZZ5lub, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eDviFlSn, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NyQgrCrw, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_RCf3k0Po, 0.0f);
  numBytes += cDelay_init(this, &cDelay_t6lKluSY, 0.0f);
  numBytes += hTable_init(&hTable_K1aScmmi, 256);
  numBytes += cDelay_init(this, &cDelay_fhzaUiLT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OhqVnn5g, 0.0f);
  numBytes += hTable_init(&hTable_3LkNluZU, 256);
  numBytes += cDelay_init(this, &cDelay_QGILnq4B, 0.0f);
  numBytes += cDelay_init(this, &cDelay_PTyN58bV, 0.0f);
  numBytes += hTable_init(&hTable_DTDd40da, 256);
  numBytes += cDelay_init(this, &cDelay_W4U4xDgs, 0.0f);
  numBytes += cDelay_init(this, &cDelay_18yDL5im, 0.0f);
  numBytes += hTable_init(&hTable_6XR14HlF, 256);
  numBytes += cIf_init(&cIf_G1CeFONS, false);
  numBytes += cBinop_init(&cBinop_5Jk5i6dF, 0.0f); // __pow
  numBytes += cPack_init(&cPack_j2C6DQNi, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_ItvaU0MJ, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_2IOmky7M, 22050.0f);
  numBytes += cBinop_init(&cBinop_Gm6Z3atX, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_osWlHqQY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_G2FE53kK, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_f6wVQhqn, 100.0f);
  numBytes += cVar_init_f(&cVar_kmaGgIi3, 95.0f);
  numBytes += cVar_init_f(&cVar_zgLCLkVt, 14400.0f);
  numBytes += cVar_init_f(&cVar_G8tdBE38, 60.0f);
  numBytes += cIf_init(&cIf_Mxbq6Eiz, false);
  numBytes += cTabhead_init(&cTabhead_Xh5tBNgx, &hTable_klSDzc9D);
  numBytes += cVar_init_s(&cVar_H4uxYUhj, "del-1379-ref6");
  numBytes += cDelay_init(this, &cDelay_thXEEZID, 13.645f);
  numBytes += cDelay_init(this, &cDelay_PH8jTY0Z, 0.0f);
  numBytes += cBinop_init(&cBinop_AjLemRyB, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_GdB0D9c8, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jmtkwoT4, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_tXLDmG4R, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_87NqYNFg, 0.0f);
  numBytes += cDelay_init(this, &cDelay_IVopa0N9, 0.0f);
  numBytes += hTable_init(&hTable_klSDzc9D, 256);
  numBytes += cTabhead_init(&cTabhead_sfL9vFkw, &hTable_fgSHe5Ec);
  numBytes += cVar_init_s(&cVar_3LSC7hO6, "del-1379-ref5");
  numBytes += cDelay_init(this, &cDelay_y35ZqJai, 16.364f);
  numBytes += cDelay_init(this, &cDelay_NfSWMc84, 0.0f);
  numBytes += cBinop_init(&cBinop_RcAEGTNx, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_rzu3kMLd, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_gGAonqT1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_eus52awF, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_u3iw5wbo, 0.0f);
  numBytes += cDelay_init(this, &cDelay_66bhsayA, 0.0f);
  numBytes += hTable_init(&hTable_fgSHe5Ec, 256);
  numBytes += cTabhead_init(&cTabhead_3J7fSdyK, &hTable_70Qa0lXY);
  numBytes += cVar_init_s(&cVar_VXcee2tK, "del-1379-ref4");
  numBytes += cDelay_init(this, &cDelay_oIN4i6l3, 19.392f);
  numBytes += cDelay_init(this, &cDelay_9z4EDDEF, 0.0f);
  numBytes += cBinop_init(&cBinop_BDvNFGMD, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_cOMfaASe, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_5axgK1d9, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_QyRQbdJ0, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_6nUpZnEy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_6mOlyxlu, 0.0f);
  numBytes += hTable_init(&hTable_70Qa0lXY, 256);
  numBytes += cTabhead_init(&cTabhead_0BdrXPb4, &hTable_EYemnlv2);
  numBytes += cVar_init_s(&cVar_iTJJYn8o, "del-1379-ref3");
  numBytes += cDelay_init(this, &cDelay_X7SjfnyQ, 25.796f);
  numBytes += cDelay_init(this, &cDelay_UR2ke14T, 0.0f);
  numBytes += cBinop_init(&cBinop_pYahqfRs, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_fvBnPj0u, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_rDCXVDSi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_DCBn4zEm, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Tf9piw99, 0.0f);
  numBytes += cDelay_init(this, &cDelay_d2m96mPR, 0.0f);
  numBytes += hTable_init(&hTable_EYemnlv2, 256);
  numBytes += cTabhead_init(&cTabhead_9wfR3ZpS, &hTable_GUL21Yeq);
  numBytes += cVar_init_s(&cVar_M7VObPq1, "del-1379-ref2");
  numBytes += cDelay_init(this, &cDelay_KrGkRZcV, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_HZ8GsjMJ, 0.0f);
  numBytes += cBinop_init(&cBinop_uJjXBSH8, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_U13QPYuu, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_sLJ7kzcW, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_57P96EX9, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_KlfTWINn, 0.0f);
  numBytes += cDelay_init(this, &cDelay_AezK23YR, 0.0f);
  numBytes += hTable_init(&hTable_GUL21Yeq, 256);
  numBytes += cTabhead_init(&cTabhead_OCcUsNGd, &hTable_0uBwf0XD);
  numBytes += cVar_init_s(&cVar_5lTUZVRn, "del-1379-ref1");
  numBytes += cDelay_init(this, &cDelay_kCHyH9Yd, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_ZVnQ5ynQ, 0.0f);
  numBytes += cBinop_init(&cBinop_AjJpAuO5, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_Pm0CuOR4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_lBoS58YP, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NqiPgS6o, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_WFlC9FGx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_GVDRMqVP, 0.0f);
  numBytes += hTable_init(&hTable_0uBwf0XD, 256);
  numBytes += cVar_init_f(&cVar_2e0ExTPo, 0.0f);
  numBytes += cVar_init_f(&cVar_IvPhtg5Q, 0.0f);
  numBytes += cPack_init(&cPack_fccQMY3b, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_IiH18POU, 22050.0f);
  numBytes += cBinop_init(&cBinop_lVzd5m3p, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_s6KrrzVj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9NEyGJZO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_BWaZGSbM, 22050.0f);
  numBytes += cBinop_init(&cBinop_4LYHKg6t, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_xCdjK98a, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_B8EERp6p, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lBsll9s6, 22050.0f);
  numBytes += cBinop_init(&cBinop_957F88mg, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_YiOdYKWE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FGlaqMDl, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_CarJsOLT, "del-1478-del1");
  numBytes += sVarf_init(&sVarf_eVSawrjG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KPwIzAB8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_J5FGDDlY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4c1I3vMe, 10000.0f);
  numBytes += cBinop_init(&cBinop_wMeb7gz3, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_4SKkcWr8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KOcUABO6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RMbLEeSj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_HtGsEAiN, 10.0f);
  numBytes += cBinop_init(&cBinop_XHu79TOS, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_dd8sB44J, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_LrQr7SC6, "floatatom");
  numBytes += sVarf_init(&sVarf_zDeJ1jQz, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_dmcibqUl, 0.0f);
  numBytes += cDelay_init(this, &cDelay_riyPeKSB, 0.0f);
  numBytes += hTable_init(&hTable_3s6AKaH3, 256);
  numBytes += sVarf_init(&sVarf_WJEdGXE5, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_CXdjhTqE, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_A6GNcW9s, -1347073446);
  numBytes += cSlice_init(&cSlice_xZobGNRs, 1, 1);
  numBytes += cRandom_init(&cRandom_L22ejGHH, -1523929753);
  numBytes += cSlice_init(&cSlice_tjXq1TPI, 1, 1);
  numBytes += cVar_init_s(&cVar_EBmJ0ZAq, "floatatom");
  numBytes += cPack_init(&cPack_hj4FDpy3, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_fkscfO8s, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_oZMzsfZc, "floatatom");
  numBytes += cDelay_init(this, &cDelay_M6K0kTY6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zFO2C5md, 0.0f);
  numBytes += hTable_init(&hTable_guhiLadY, 256);
  numBytes += cVar_init_s(&cVar_tD1VKwcs, "del-1509-del");
  numBytes += sVarf_init(&sVarf_6TBiKZ6y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BWFUYOzV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Rq8Q8I6Y, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_r1cbd4S9, "del-1509-del");
  numBytes += sVarf_init(&sVarf_19bbDObM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nJdQMaL3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hD1kZknj, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_vxWN4o5V, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_1J4Szb00, "del-1538-del1");
  numBytes += sVarf_init(&sVarf_XflmxsNB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kTEDW4i5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fEcRipuq, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_FyTt1grn, 10000.0f);
  numBytes += cBinop_init(&cBinop_LbnkeYBg, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_5xBcNy7o, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6kNQPpiu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wuy4GXHc, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_LDx5LZqT, 10.0f);
  numBytes += cBinop_init(&cBinop_sKo7NDsQ, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_V0zuyRmQ, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_oVzTuQ1s, "floatatom");
  numBytes += sVarf_init(&sVarf_MzPhG95i, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_rSHYHpVJ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ZL2maAgx, 0.0f);
  numBytes += hTable_init(&hTable_di1iubhs, 256);
  numBytes += sVarf_init(&sVarf_jlyzQH5O, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_k04ha051, "floatatom");
  numBytes += cDelay_init(this, &cDelay_VTifhy1S, 0.0f);
  numBytes += cVar_init_f(&cVar_e43tLdfK, 20.0f);
  numBytes += cBinop_init(&cBinop_VC7c5Y4Y, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_3oxqrZi3, 0.0f);
  numBytes += cSlice_init(&cSlice_r7DOwSFY, 1, -1);
  numBytes += cSlice_init(&cSlice_HXR8svDD, 1, -1);
  numBytes += cVar_init_f(&cVar_5Te1m1Sk, 0.0f);
  numBytes += cVar_init_f(&cVar_bMG4eNhl, 20.0f);
  numBytes += cVar_init_f(&cVar_quOUMNUk, 0.0f);
  numBytes += cVar_init_f(&cVar_73eX4RoG, 0.0f);
  numBytes += cVar_init_f(&cVar_s0MJW3Zb, 0.0f);
  numBytes += cSlice_init(&cSlice_aU5EkKCJ, 1, 1);
  numBytes += cSlice_init(&cSlice_IPfLRWqC, 0, 1);
  numBytes += cBinop_init(&cBinop_CRQYU3Cx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_pcmXgbw9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_EsR9cAq5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fjKbUf1H, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_R9cHW10T, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_NUHGA7By, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_R8ZdBOfA, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_XIakjTfO, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_duR93HYG, "floatatom");
  numBytes += cDelay_init(this, &cDelay_c54sncFZ, 0.0f);
  numBytes += cVar_init_f(&cVar_uGI9p5ir, 20.0f);
  numBytes += cBinop_init(&cBinop_1kdUdRTE, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Do1XLr0V, 0.0f);
  numBytes += cSlice_init(&cSlice_nPUUwWxR, 1, -1);
  numBytes += cSlice_init(&cSlice_rzOv715X, 1, -1);
  numBytes += cVar_init_f(&cVar_wmsUdVnr, 0.0f);
  numBytes += cVar_init_f(&cVar_9UPSbwlV, 20.0f);
  numBytes += cVar_init_f(&cVar_NQY3hqWK, 0.0f);
  numBytes += cVar_init_f(&cVar_GE7SRatX, 0.0f);
  numBytes += cVar_init_f(&cVar_JXzN7553, 0.0f);
  numBytes += cSlice_init(&cSlice_bAbGZS3R, 1, 1);
  numBytes += cSlice_init(&cSlice_WDiOlHnO, 0, 1);
  numBytes += cBinop_init(&cBinop_9woa3Tq8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zMnMbRtN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Gh8zovmI, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pPKsJL1Z, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_RfIXx4zA, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_NShloVBR, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_NHnxaV1F, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Hlv6veiz, 0.0f); // __sub
  numBytes += cPack_init(&cPack_Kwi9mtNC, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_n78Luc83, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_17eiHbby, 2, 0.0f, 1000.0f);
  numBytes += cVar_init_f(&cVar_VX0498Jm, 100.0f);
  numBytes += cIf_init(&cIf_GGUMi9uf, false);
  numBytes += cBinop_init(&cBinop_fGDEDlZK, 0.0f); // __pow
  numBytes += cPack_init(&cPack_Rmm3ULDU, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_qTm622iC, 0.0f);
  numBytes += cVar_init_f(&cVar_KRMYtzmF, 100.0f);
  numBytes += cIf_init(&cIf_KbcMiqHM, false);
  numBytes += cBinop_init(&cBinop_U5LltJPu, 0.0f); // __pow
  numBytes += cPack_init(&cPack_i625RJtJ, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_l9sRo4of, 0.0f);
  numBytes += cIf_init(&cIf_DbcGz94T, false);
  numBytes += cIf_init(&cIf_yP2K3iLI, false);
  numBytes += cVar_init_f(&cVar_fshe9hD2, 97.0f);
  numBytes += cIf_init(&cIf_IdYY3Gov, false);
  numBytes += cBinop_init(&cBinop_C3xaycOH, 0.0f); // __pow
  numBytes += cPack_init(&cPack_6UqoDElm, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_hQI7e8aX, 0.0f);
  numBytes += cVar_init_f(&cVar_RU26ydeH, 89.0f);
  numBytes += cIf_init(&cIf_f0j9rXFM, false);
  numBytes += cBinop_init(&cBinop_eGcZEuEM, 0.0f); // __pow
  numBytes += cPack_init(&cPack_OBycxFAf, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_kDTAXYYI, 0.0f);
  numBytes += cVar_init_f(&cVar_e6jh305m, 97.0f);
  numBytes += cIf_init(&cIf_eoHNc2Rw, false);
  numBytes += cBinop_init(&cBinop_gu1MassY, 0.0f); // __pow
  numBytes += cPack_init(&cPack_Uf2zj94R, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_PUc6sID5, 0.0f);
  numBytes += cPack_init(&cPack_4IETPmub, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_eyw5qIip, 1, 1);
  numBytes += cSlice_init(&cSlice_dgJ9ywQw, 0, 1);
  numBytes += cIf_init(&cIf_Mwxd9GGa, false);
  numBytes += cIf_init(&cIf_EvQCPFN7, false);
  numBytes += cIf_init(&cIf_ktCINcPw, false);
  numBytes += cSlice_init(&cSlice_Re1vePEX, 1, 1);
  numBytes += cSlice_init(&cSlice_6xb3LVQz, 0, 1);
  numBytes += cVar_init_f(&cVar_7eZMtrAG, 0.0f);
  numBytes += cIf_init(&cIf_DwdssIAR, false);
  numBytes += cPack_init(&cPack_FIqA3x0K, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_bp5j8D2I, 1, -1);
  numBytes += cSlice_init(&cSlice_DAjzTfio, 1, -1);
  numBytes += cSlice_init(&cSlice_k2mzw6mS, 1, -1);
  numBytes += cSlice_init(&cSlice_LQkUTVGP, 1, -1);
  numBytes += cIf_init(&cIf_rre5YOQK, false);
  numBytes += cVar_init_f(&cVar_mw74KFSk, 1.0f);
  numBytes += cPack_init(&cPack_B4Z9fwPn, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_QTz2d6xK, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_PhaseRing::~Heavy_PhaseRing() {
  cPack_free(&cPack_xnLJfynF);
  cPack_free(&cPack_77hFqgJt);
  cPack_free(&cPack_MwiWrvJV);
  cPack_free(&cPack_xQjFqcxK);
  cPack_free(&cPack_9Ct5EGJa);
  cPack_free(&cPack_PvJ4HMrl);
  cPack_free(&cPack_tMVLFKpD);
  cPack_free(&cPack_JQPDIOJH);
  cPack_free(&cPack_JzHBc5xA);
  cPack_free(&cPack_Q29jOqWk);
  cPack_free(&cPack_IkT7oU0M);
  cPack_free(&cPack_tIeJMhc3);
  cPack_free(&cPack_A1gdQFHg);
  cPack_free(&cPack_XKnoZ4C7);
  cPack_free(&cPack_0Orw5xlf);
  cPack_free(&cPack_FAy19rGU);
  cPack_free(&cPack_7BlV7H0w);
  hTable_free(&hTable_pgPZf0IE);
  hTable_free(&hTable_gcHyd7im);
  hTable_free(&hTable_hwX01sys);
  hTable_free(&hTable_WFbfQ60g);
  cPack_free(&cPack_5cGHpwXI);
  cPack_free(&cPack_wvfA3FwO);
  hTable_free(&hTable_OnYdYUyR);
  hTable_free(&hTable_grQHM5HS);
  hTable_free(&hTable_IKDHvxMN);
  hTable_free(&hTable_lbIc8ogL);
  hTable_free(&hTable_UI28wuy7);
  hTable_free(&hTable_HXWSxKDU);
  cPack_free(&cPack_rHjiJj5d);
  cPack_free(&cPack_KOAuQBbt);
  cPack_free(&cPack_v6eDtMGb);
  hTable_free(&hTable_vyXqPpGz);
  hTable_free(&hTable_K1aScmmi);
  hTable_free(&hTable_3LkNluZU);
  hTable_free(&hTable_DTDd40da);
  hTable_free(&hTable_6XR14HlF);
  cPack_free(&cPack_j2C6DQNi);
  cPack_free(&cPack_ItvaU0MJ);
  hTable_free(&hTable_klSDzc9D);
  hTable_free(&hTable_fgSHe5Ec);
  hTable_free(&hTable_70Qa0lXY);
  hTable_free(&hTable_EYemnlv2);
  hTable_free(&hTable_GUL21Yeq);
  hTable_free(&hTable_0uBwf0XD);
  cPack_free(&cPack_fccQMY3b);
  hTable_free(&hTable_3s6AKaH3);
  cPack_free(&cPack_CXdjhTqE);
  cPack_free(&cPack_hj4FDpy3);
  cPack_free(&cPack_fkscfO8s);
  hTable_free(&hTable_guhiLadY);
  hTable_free(&hTable_di1iubhs);
  cPack_free(&cPack_Kwi9mtNC);
  cPack_free(&cPack_n78Luc83);
  cPack_free(&cPack_17eiHbby);
  cPack_free(&cPack_Rmm3ULDU);
  cPack_free(&cPack_i625RJtJ);
  cPack_free(&cPack_6UqoDElm);
  cPack_free(&cPack_OBycxFAf);
  cPack_free(&cPack_Uf2zj94R);
  cPack_free(&cPack_4IETPmub);
  cPack_free(&cPack_FIqA3x0K);
  cPack_free(&cPack_B4Z9fwPn);
}

HvTable *Heavy_PhaseRing::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xF96F9CBC: return &hTable_pgPZf0IE; // del-1209-del1
    case 0xEAD79ADF: return &hTable_gcHyd7im; // del-1209-del2
    case 0xB1129AA0: return &hTable_hwX01sys; // del-1209-del3
    case 0x4F62B33F: return &hTable_WFbfQ60g; // del-1209-del4
    case 0x36047BDC: return &hTable_OnYdYUyR; // del-1209-ref6
    case 0x66BE8A1D: return &hTable_grQHM5HS; // del-1209-ref5
    case 0xD4C64222: return &hTable_IKDHvxMN; // del-1209-ref4
    case 0xC5A2B81B: return &hTable_lbIc8ogL; // del-1209-ref3
    case 0xE629D5: return &hTable_UI28wuy7; // del-1209-ref2
    case 0x912EE503: return &hTable_HXWSxKDU; // del-1209-ref1
    case 0xFBB0E240: return &hTable_vyXqPpGz; // del-1316-del
    case 0xDB23006E: return &hTable_K1aScmmi; // del-1379-del1
    case 0x71D4109E: return &hTable_3LkNluZU; // del-1379-del2
    case 0x3209AF80: return &hTable_DTDd40da; // del-1379-del3
    case 0x243F6DE3: return &hTable_6XR14HlF; // del-1379-del4
    case 0x57CE1FFD: return &hTable_klSDzc9D; // del-1379-ref6
    case 0xE6EB4810: return &hTable_fgSHe5Ec; // del-1379-ref5
    case 0x1A778356: return &hTable_70Qa0lXY; // del-1379-ref4
    case 0xEAC5B9C7: return &hTable_EYemnlv2; // del-1379-ref3
    case 0x59B93D98: return &hTable_GUL21Yeq; // del-1379-ref2
    case 0x29741CDA: return &hTable_0uBwf0XD; // del-1379-ref1
    case 0xE6E7333E: return &hTable_3s6AKaH3; // del-1478-del1
    case 0x37C7A3A7: return &hTable_guhiLadY; // del-1509-del
    case 0x55F6486C: return &hTable_di1iubhs; // del-1538-del1
    default: return nullptr;
  }
}

void Heavy_PhaseRing::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x9DBB052E: { // 1057-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6rUhGEzV_sendMessage);
      break;
    }
    case 0xF1DE93DD: { // 1057-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_d1x49Idi_sendMessage);
      break;
    }
    case 0x6CD381D4: { // 1057-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_s5MV5ZBA_sendMessage);
      break;
    }
    case 0xCF6D3C3F: { // 1057-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sdfc8c18_sendMessage);
      break;
    }
    case 0xEDDFD30D: { // 1057-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zSwVT03B_sendMessage);
      break;
    }
    case 0xF2BA3B2A: { // 1057-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OjDM7nnb_sendMessage);
      break;
    }
    case 0x4408E690: { // 1093-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AxaZx0Zs_sendMessage);
      break;
    }
    case 0x8AB98019: { // 1093-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vpjkkcPW_sendMessage);
      break;
    }
    case 0x27A42126: { // 1101-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fmTJHBa1_sendMessage);
      break;
    }
    case 0xB5E9A65D: { // 1101-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wvYElEpD_sendMessage);
      break;
    }
    case 0x56934ECA: { // 1101-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_olsP70nX_sendMessage);
      break;
    }
    case 0x7514C9B6: { // 1101-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hOB01E8J_sendMessage);
      break;
    }
    case 0xCB831B98: { // 1101-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mUrop4YA_sendMessage);
      break;
    }
    case 0x3A687221: { // 1101-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kOAYJe8d_sendMessage);
      break;
    }
    case 0x68EAABD0: { // 1137-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_O9jFyZBj_sendMessage);
      break;
    }
    case 0x20D6E4AD: { // 1137-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AQ7bNWxe_sendMessage);
      break;
    }
    case 0x4BE05FC6: { // 1137-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4OYr2W2Y_sendMessage);
      break;
    }
    case 0xD8FD070D: { // 1137-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IEvVTTCx_sendMessage);
      break;
    }
    case 0xC65E45B8: { // 1137-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lKrLhBWy_sendMessage);
      break;
    }
    case 0x9349BDCA: { // 1137-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uBquHsQs_sendMessage);
      break;
    }
    case 0x8A2C77AE: { // 1173-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JO2kPIbC_sendMessage);
      break;
    }
    case 0xD6F86CC3: { // 1173-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PjEBdfYT_sendMessage);
      break;
    }
    case 0x2A29490B: { // 1173-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vrykT3kU_sendMessage);
      break;
    }
    case 0xFAE8AB: { // 1173-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gKWyKNrd_sendMessage);
      break;
    }
    case 0xBFDBA4A2: { // 1173-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qkOsjaH2_sendMessage);
      break;
    }
    case 0x7638E91B: { // 1173-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SeedFGST_sendMessage);
      break;
    }
    case 0x83D209A2: { // 1599-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CGeTYhkq_sendMessage);
      break;
    }
    case 0x62CA542E: { // 1599-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Q6trVHsB_sendMessage);
      break;
    }
    case 0xF8E41A5F: { // 1607-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5P3ATf5q_sendMessage);
      break;
    }
    case 0x9164CD41: { // 1607-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Mus39q4C_sendMessage);
      break;
    }
    case 0x78060116: { // 1619-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7PYA8VCW_sendMessage);
      break;
    }
    case 0xDDEDC45: { // 1619-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3Blo6BH1_sendMessage);
      break;
    }
    case 0x3FF54ADC: { // 1627-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FKotlQA8_sendMessage);
      break;
    }
    case 0x613389B1: { // 1627-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VPJ6n72T_sendMessage);
      break;
    }
    case 0xCA661AA: { // 1635-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9UPzyFio_sendMessage);
      break;
    }
    case 0x33695BEA: { // 1635-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_am1PGiv0_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QgdJnhnA_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NCKJrbAY_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tDey43Le_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rU6RmXiI_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Fq2RGNPk_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zHaJyGhq_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1J2so8lt_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Hjzg4uYz_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_l296PDwh_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5Svr7oZf_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_znVjwaSa_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_m0M6e0dU_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qhshrG6x_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fUAu3lOo_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tooSZXgA_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4JlpZx3C_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YdK90uaw_sendMessage);
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


void Heavy_PhaseRing::cSlice_pJYnbGAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_mdlfewXj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_urQKbdvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_l6Op3Eiy, 0, m, &cIf_l6Op3Eiy_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_YT6OzAOI, 0, m, &cIf_YT6OzAOI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_2d1FImcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_twkiVEg1, 0, m, &cIf_twkiVEg1_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_zeZBKZp2, 0, m, &cIf_zeZBKZp2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_DZoGRvWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ykdwQH2h_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_6VFNLK73, 0, m, &cIf_6VFNLK73_sendMessage);
}

void Heavy_PhaseRing::cUnop_gPNAXZyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_7ptWCNS7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hGcbRE0v, HV_BINOP_EQ, 1, m, &cBinop_hGcbRE0v_sendMessage);
}

void Heavy_PhaseRing::cUnop_Xpxj1DqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_7ptWCNS7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hGcbRE0v, HV_BINOP_EQ, 1, m, &cBinop_hGcbRE0v_sendMessage);
}

void Heavy_PhaseRing::cIf_6VFNLK73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Xpxj1DqE_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_gPNAXZyT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ykdwQH2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6VFNLK73, 1, m, &cIf_6VFNLK73_sendMessage);
}

void Heavy_PhaseRing::cIf_YT6OzAOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Ak3pwYdN_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_zeZBKZp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_aHU2tshS_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_l6Op3Eiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Ak3pwYdN_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_twkiVEg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_aHU2tshS_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_mdlfewXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hGcbRE0v, HV_BINOP_EQ, 0, m, &cBinop_hGcbRE0v_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_c7FL5ZzV_sendMessage);
}

void Heavy_PhaseRing::cBinop_7ptWCNS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RVUjeK2y_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3kLOAGLp_sendMessage);
}

void Heavy_PhaseRing::cBinop_hGcbRE0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_G0lQS7yp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9zZ36uP1_sendMessage);
}

void Heavy_PhaseRing::cCast_9zZ36uP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_twkiVEg1, 1, m, &cIf_twkiVEg1_sendMessage);
}

void Heavy_PhaseRing::cCast_G0lQS7yp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YT6OzAOI, 1, m, &cIf_YT6OzAOI_sendMessage);
}

void Heavy_PhaseRing::cCast_3kLOAGLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zeZBKZp2, 1, m, &cIf_zeZBKZp2_sendMessage);
}

void Heavy_PhaseRing::cCast_RVUjeK2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_l6Op3Eiy, 1, m, &cIf_l6Op3Eiy_sendMessage);
}

void Heavy_PhaseRing::cBinop_c7FL5ZzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_b774Isw3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_mn0cncqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EsFn7rPq, 0, m, &cVar_EsFn7rPq_sendMessage);
}

void Heavy_PhaseRing::cBinop_KnfJ54YT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_XeVaCU8W_sendMessage);
}

void Heavy_PhaseRing::cBinop_XeVaCU8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rYYQyHY9, HV_BINOP_POW, 1, m, &cBinop_rYYQyHY9_sendMessage);
  cMsg_ykaZq6jX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_rYYQyHY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_mn0cncqR_sendMessage);
}

void Heavy_PhaseRing::cMsg_ykaZq6jX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rYYQyHY9, HV_BINOP_POW, 0, m, &cBinop_rYYQyHY9_sendMessage);
}

void Heavy_PhaseRing::cBinop_KS9myr53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_acLOqQmF_sendMessage);
}

void Heavy_PhaseRing::cBinop_acLOqQmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_i50v2F8I_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GSl9ows9_sendMessage);
}

void Heavy_PhaseRing::cVar_9n1LtUF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_WXVf16VJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_tBLixq99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yZgylGGF_sendMessage);
}

void Heavy_PhaseRing::cSystem_yZgylGGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3RmydNXy, HV_BINOP_DIVIDE, 1, m, &cBinop_3RmydNXy_sendMessage);
}

void Heavy_PhaseRing::cBinop_i50v2F8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_DxmnMXmt_sendMessage);
}

void Heavy_PhaseRing::cBinop_DxmnMXmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ldBCSB6D, m);
}

void Heavy_PhaseRing::cMsg_ygA3Nbt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_VzXD51KM_sendMessage);
}

void Heavy_PhaseRing::cBinop_VzXD51KM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KS9myr53_sendMessage);
}

void Heavy_PhaseRing::cBinop_GSl9ows9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eANBshng, m);
}

void Heavy_PhaseRing::cBinop_WXVf16VJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Ygj6DdQz_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ygj6DdQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3RmydNXy, HV_BINOP_DIVIDE, 0, m, &cBinop_3RmydNXy_sendMessage);
}

void Heavy_PhaseRing::cBinop_3RmydNXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ygA3Nbt5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_xnLJfynF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5zxIH7av, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_kxA2BqJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_ogzqCWim_sendMessage);
}

void Heavy_PhaseRing::cVar_EsFn7rPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ZBbMdwex, 0, m);
}

void Heavy_PhaseRing::cIf_Ch9kt21n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_tdYXEgd1_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_UuzKOOUy, 0, m, &cIf_UuzKOOUy_sendMessage);
      break;
    }
    case 1: {
      cMsg_rX2S2BEQ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_y6jt1Vsu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ch9kt21n, 1, m, &cIf_Ch9kt21n_sendMessage);
}

void Heavy_PhaseRing::cIf_UuzKOOUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_RE4VkZUG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_cDaeYNE2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_tdYXEgd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UuzKOOUy, 1, m, &cIf_UuzKOOUy_sendMessage);
}

void Heavy_PhaseRing::cMsg_rX2S2BEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_cDaeYNE2_sendMessage);
}

void Heavy_PhaseRing::cMsg_RE4VkZUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_cDaeYNE2_sendMessage);
}

void Heavy_PhaseRing::cIf_6zKxGMpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_AmbbNMx6_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_cy6Tw3xc, 0, m, &cIf_cy6Tw3xc_sendMessage);
      break;
    }
    case 1: {
      cMsg_EJOXWbOd_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_6cJjY6TO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6zKxGMpB, 1, m, &cIf_6zKxGMpB_sendMessage);
}

void Heavy_PhaseRing::cIf_cy6Tw3xc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_1m8IActQ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_MwiWrvJV, 0, m, &cPack_MwiWrvJV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_AmbbNMx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cy6Tw3xc, 1, m, &cIf_cy6Tw3xc_sendMessage);
}

void Heavy_PhaseRing::cMsg_EJOXWbOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_MwiWrvJV, 0, m, &cPack_MwiWrvJV_sendMessage);
}

void Heavy_PhaseRing::cMsg_1m8IActQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_MwiWrvJV, 0, m, &cPack_MwiWrvJV_sendMessage);
}

void Heavy_PhaseRing::cPack_77hFqgJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nLRqvWAz, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_MwiWrvJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OWfRZIbw, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_xQjFqcxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_odE54cL6, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_ogzqCWim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.1f, 0, m, &cBinop_Ta0T6MU6_sendMessage);
}

void Heavy_PhaseRing::cBinop_LawhudfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kxA2BqJY, 0, m, &cVar_kxA2BqJY_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ta0T6MU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_xnLJfynF, 0, m, &cPack_xnLJfynF_sendMessage);
}

void Heavy_PhaseRing::cBinop_cDaeYNE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_FHnTnqnj_sendMessage);
}

void Heavy_PhaseRing::cBinop_FHnTnqnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_6cJjY6TO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_6zKxGMpB, 0, m, &cIf_6zKxGMpB_sendMessage);
}

void Heavy_PhaseRing::cCast_YIe1JmA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0xIOtYN7_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Ncx4mef1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_0xIOtYN7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_atjqamt9, 0, m, &cSlice_atjqamt9_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7OdCMXoC, 0, m, &cRandom_7OdCMXoC_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_maUUz4S6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HxcCik5k_sendMessage);
}

void Heavy_PhaseRing::cUnop_HxcCik5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9BJqEEmU, 0, m, &cVar_9BJqEEmU_sendMessage);
}

void Heavy_PhaseRing::cRandom_7OdCMXoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_maUUz4S6_sendMessage);
}

void Heavy_PhaseRing::cSlice_atjqamt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7OdCMXoC, 1, m, &cRandom_7OdCMXoC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_9BJqEEmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_eSEgRjhM_sendMessage(_c, 0, m);
  cSend_j12sB2Kz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Ncx4mef1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ASpW116q, 0, m, &cSlice_ASpW116q_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_31zt7s6R, 0, m, &cRandom_31zt7s6R_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_qdtQJrF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_lj4ZTN1M_sendMessage);
}

void Heavy_PhaseRing::cUnop_lj4ZTN1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_xKrc1BLV_sendMessage);
  cSend_R5Edkcgv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cRandom_31zt7s6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_qdtQJrF3_sendMessage);
}

void Heavy_PhaseRing::cSlice_ASpW116q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_31zt7s6R, 1, m, &cRandom_31zt7s6R_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_19rMM5BP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xYnEGyNH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_1kFk0586_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_IzqAOCUC_sendMessage);
}

void Heavy_PhaseRing::cBinop_IzqAOCUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1kFk0586, 1, m, &cVar_1kFk0586_sendMessage);
}

void Heavy_PhaseRing::cCast_kVJGFWG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_1RjHGpbJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_H9szrrGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_INsUs3xk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JkF1Ui7R_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_xKrc1BLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_19rMM5BP, 0, m, &cVar_19rMM5BP_sendMessage);
}

void Heavy_PhaseRing::cSend_xYnEGyNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fUAu3lOo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_eSEgRjhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Hjzg4uYz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_R5Edkcgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YdK90uaw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_j12sB2Kz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tooSZXgA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_4BNiuc8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_02CLjBNj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_02CLjBNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zHaJyGhq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_WMnIl65Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_02CLjBNj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_JkF1Ui7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tDey43Le_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_KmVIUYK1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UKh7BPEf, 0, m, &cSlice_UKh7BPEf_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xnYfS2wp, 0, m, &cRandom_xnYfS2wp_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_yy5iXlzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rfASI9go_sendMessage);
}

void Heavy_PhaseRing::cUnop_rfASI9go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_eNwnKfeR_sendMessage);
}

void Heavy_PhaseRing::cRandom_xnYfS2wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 900.0f, 0, m, &cBinop_yy5iXlzK_sendMessage);
}

void Heavy_PhaseRing::cSlice_UKh7BPEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xnYfS2wp, 1, m, &cRandom_xnYfS2wp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_qWw8JXuw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sWvZ52N8, 0, m, &cSlice_sWvZ52N8_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TCIoyOu3, 0, m, &cRandom_TCIoyOu3_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_jChDK7la_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_1uWZVL0Z_sendMessage);
}

void Heavy_PhaseRing::cUnop_1uWZVL0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_BYdHNLQQ_sendMessage);
}

void Heavy_PhaseRing::cRandom_TCIoyOu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_jChDK7la_sendMessage);
}

void Heavy_PhaseRing::cSlice_sWvZ52N8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TCIoyOu3, 1, m, &cRandom_TCIoyOu3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_GyogUSBW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pRWijCeY, 0, m, &cSlice_pRWijCeY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_O9XXc8aH, 0, m, &cRandom_O9XXc8aH_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_KW5GgUtt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_j12KQcVG_sendMessage);
}

void Heavy_PhaseRing::cUnop_j12KQcVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_SLdeIawn_sendMessage);
}

void Heavy_PhaseRing::cRandom_O9XXc8aH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_KW5GgUtt_sendMessage);
}

void Heavy_PhaseRing::cSlice_pRWijCeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_O9XXc8aH, 1, m, &cRandom_O9XXc8aH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_0QASZWcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oJs6fuNZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_oJs6fuNZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ff5YdQOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_1AArUCSR_sendMessage);
}

void Heavy_PhaseRing::cBinop_1AArUCSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ha0nI3Aj, HV_BINOP_POW, 1, m, &cBinop_Ha0nI3Aj_sendMessage);
  cMsg_JwGPsjbV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Ha0nI3Aj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_0QASZWcH_sendMessage);
}

void Heavy_PhaseRing::cMsg_JwGPsjbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ha0nI3Aj, HV_BINOP_POW, 0, m, &cBinop_Ha0nI3Aj_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_c5YRcIIm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DQSlsmXW, 0, m, &cSlice_DQSlsmXW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Yx1E86vL, 0, m, &cRandom_Yx1E86vL_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_HTPWFlgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jhQ8dKoQ_sendMessage);
}

void Heavy_PhaseRing::cUnop_jhQ8dKoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dEctTGi9_sendMessage);
}

void Heavy_PhaseRing::cRandom_Yx1E86vL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_HTPWFlgS_sendMessage);
}

void Heavy_PhaseRing::cSlice_DQSlsmXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Yx1E86vL, 1, m, &cRandom_Yx1E86vL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_9Ct5EGJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yCZ5UF5E, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_5vAOqlSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_ksXtnFJK_sendMessage);
}

void Heavy_PhaseRing::cVar_4SgIdkam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_KupL8rk4, 0, m);
}

void Heavy_PhaseRing::cVar_VjGtFmIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_jQoJc3jA, 0, m);
}

void Heavy_PhaseRing::cVar_bL299idK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rFegqJ4Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PGNnEfRQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eIjsm2fW_sendMessage);
}

void Heavy_PhaseRing::cCast_x2xyyPgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_8zEbK0a5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_mX4DVZwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_gXLyN6yV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_ilanBTw6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ic72jvSc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ic72jvSc_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_h9a7Uq10, 1, m, &cDelay_h9a7Uq10_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N5o5rS4B_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_h9a7Uq10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_h9a7Uq10, m);
  cVar_onMessage(_c, &Context(_c)->cVar_d7xbKJSs, 0, m, &cVar_d7xbKJSs_sendMessage);
}

void Heavy_PhaseRing::cMsg_ic72jvSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_h9a7Uq10, 0, m, &cDelay_h9a7Uq10_sendMessage);
}

void Heavy_PhaseRing::cCast_N5o5rS4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_h9a7Uq10, 0, m, &cDelay_h9a7Uq10_sendMessage);
}

void Heavy_PhaseRing::cVar_d7xbKJSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K9r9tn55_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_uTkxDOZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bL299idK, 0, m, &cVar_bL299idK_sendMessage);
}

void Heavy_PhaseRing::cMsg_4UvcmyZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_o5AzMvsD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ahuPdt0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_bFUDoLos_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_9xYDajdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_VIzgOPuV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_5x3afAPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_d1x49Idi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_fthTOmvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_07fTRTi6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_s5MV5ZBA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_o5AzMvsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_bFUDoLos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_d1x49Idi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_VIzgOPuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_s5MV5ZBA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_js0dhUIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_LCNx6j0h, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_K9r9tn55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_LCNx6j0h, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_PGNnEfRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d7xbKJSs, 1, m, &cVar_d7xbKJSs_sendMessage);
}

void Heavy_PhaseRing::cCast_eIjsm2fW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ilanBTw6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_rFegqJ4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_js0dhUIj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_jgr241b6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_HreaJF6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tMVLFKpD, 0, m, &cPack_tMVLFKpD_sendMessage);
}

void Heavy_PhaseRing::cUnop_7WmPilVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PvJ4HMrl, 0, m, &cPack_PvJ4HMrl_sendMessage);
}

void Heavy_PhaseRing::cPack_PvJ4HMrl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Wiminwiw, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_tMVLFKpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KU8NrRpw, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_124YyhsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_HreaJF6N_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_7WmPilVF_sendMessage);
}

void Heavy_PhaseRing::cMsg_IHY8FmlZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_124YyhsV_sendMessage);
}

void Heavy_PhaseRing::cSlice_IwWHqRHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_GdLfIsFo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_fQrcROrY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4ojMoyrz_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Ff5YdQOV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_SLdeIawn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_1rj4sMzf_sendMessage);
}

void Heavy_PhaseRing::cBinop_1rj4sMzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_124YyhsV_sendMessage);
}

void Heavy_PhaseRing::cBinop_GdLfIsFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_UQH56m3m_sendMessage(_c, 0, m);
  cSend_ppfBmBee_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_oJs6fuNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HRqn5OQ9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H3kMtOsW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VjGtFmIE, 0, m, &cVar_VjGtFmIE_sendMessage);
}

void Heavy_PhaseRing::cBinop_dEctTGi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_B97QA3kH_sendMessage);
}

void Heavy_PhaseRing::cBinop_B97QA3kH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oJs6fuNZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_oJs6fuNZ_sendMessage);
}

void Heavy_PhaseRing::cCast_4ojMoyrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_c5YRcIIm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_UQH56m3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OjDM7nnb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_H3kMtOsW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GyogUSBW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_HRqn5OQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uTkxDOZB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jgr241b6_sendMessage);
}

void Heavy_PhaseRing::cBinop_ksXtnFJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9Ct5EGJa, 0, m, &cPack_9Ct5EGJa_sendMessage);
}

void Heavy_PhaseRing::cSend_ppfBmBee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sdfc8c18_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_7pt0ezmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zSwVT03B_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_aQ2TmW7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_7pt0ezmR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_5fCMrO4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ezSltzay_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WnDBNe53_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Z08RAmzy_sendMessage);
}

void Heavy_PhaseRing::cIf_YdFZe4ns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_f3NItFge_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_kj9w1ZbM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_dWrtOGGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qL1SZxrX, HV_BINOP_POW, 0, m, &cBinop_qL1SZxrX_sendMessage);
}

void Heavy_PhaseRing::cBinop_qL1SZxrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JQPDIOJH, 0, m, &cPack_JQPDIOJH_sendMessage);
}

void Heavy_PhaseRing::cBinop_KWTBx3zJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ovDMhWvj_sendMessage);
}

void Heavy_PhaseRing::cCast_WnDBNe53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MLnWLHk5_sendMessage);
}

void Heavy_PhaseRing::cCast_Z08RAmzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YdFZe4ns, 0, m, &cIf_YdFZe4ns_sendMessage);
}

void Heavy_PhaseRing::cBinop_MLnWLHk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YdFZe4ns, 1, m, &cIf_YdFZe4ns_sendMessage);
}

void Heavy_PhaseRing::cBinop_kj9w1ZbM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_KWTBx3zJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_f3NItFge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_JQPDIOJH, 0, m, &cPack_JQPDIOJH_sendMessage);
}

void Heavy_PhaseRing::cBinop_ovDMhWvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qL1SZxrX, HV_BINOP_POW, 1, m, &cBinop_qL1SZxrX_sendMessage);
  cMsg_dWrtOGGw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_JQPDIOJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_I23XyPSZ, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_wqvqiksN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_e3kmc9lY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ezSltzay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_Tgfwm77W_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_Tgfwm77W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AxaZx0Zs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_e3kmc9lY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vpjkkcPW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_uyg6GiwS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4taF2ET3, 0, m, &cSlice_4taF2ET3_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cQLNL3zY, 0, m, &cRandom_cQLNL3zY_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_fRO7Xggx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ncYj4nqx_sendMessage);
}

void Heavy_PhaseRing::cUnop_ncYj4nqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_oTDS2Op9_sendMessage);
}

void Heavy_PhaseRing::cRandom_cQLNL3zY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_fRO7Xggx_sendMessage);
}

void Heavy_PhaseRing::cSlice_4taF2ET3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cQLNL3zY, 1, m, &cRandom_cQLNL3zY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_qGU5w5CR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zKLgK6RO, HV_BINOP_MULTIPLY, 0, m, &cBinop_zKLgK6RO_sendMessage);
}

void Heavy_PhaseRing::cBinop_fgoC646C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_LyxUEAv4_sendMessage);
}

void Heavy_PhaseRing::cBinop_LyxUEAv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yuM7rWlo, HV_BINOP_POW, 1, m, &cBinop_yuM7rWlo_sendMessage);
  cMsg_Rcersd7K_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_yuM7rWlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_qGU5w5CR_sendMessage);
}

void Heavy_PhaseRing::cMsg_Rcersd7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yuM7rWlo, HV_BINOP_POW, 0, m, &cBinop_yuM7rWlo_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_kx7WYgZF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MA7czWVA, 0, m, &cSlice_MA7czWVA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pPgusswa, 0, m, &cRandom_pPgusswa_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_fbyb2OFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3B1Fh4Y8_sendMessage);
}

void Heavy_PhaseRing::cUnop_3B1Fh4Y8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9XOC5PqS_sendMessage);
}

void Heavy_PhaseRing::cRandom_pPgusswa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_fbyb2OFF_sendMessage);
}

void Heavy_PhaseRing::cSlice_MA7czWVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pPgusswa, 1, m, &cRandom_pPgusswa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_JzHBc5xA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_M8zZGzLr, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_bzxhWGhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_zOpwhopS_sendMessage);
}

void Heavy_PhaseRing::cVar_DNHWcE5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_EKX5j2AH, 0, m);
}

void Heavy_PhaseRing::cVar_3GEwdbHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_2W9lcyq0, 0, m);
}

void Heavy_PhaseRing::cVar_KzYhEUqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MdCp59gE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yDItFAoq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GgveKoLu_sendMessage);
}

void Heavy_PhaseRing::cCast_fa8rlo6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_WlDCW7Hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_6wIw5zOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_ay6Axlvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_SRkslpsg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_IudV7Tje_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_IudV7Tje_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Mo3r272g, 1, m, &cDelay_Mo3r272g_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vOiaZ7p2_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_Mo3r272g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Mo3r272g, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eiBMlk1o, 0, m, &cVar_eiBMlk1o_sendMessage);
}

void Heavy_PhaseRing::cMsg_IudV7Tje_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mo3r272g, 0, m, &cDelay_Mo3r272g_sendMessage);
}

void Heavy_PhaseRing::cCast_vOiaZ7p2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mo3r272g, 0, m, &cDelay_Mo3r272g_sendMessage);
}

void Heavy_PhaseRing::cVar_eiBMlk1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6gcULbrt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_7y0akvI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KzYhEUqd, 0, m, &cVar_KzYhEUqd_sendMessage);
}

void Heavy_PhaseRing::cMsg_8L30hmBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_4aDK9MrJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_q0PFxAgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_3bRM93Ux_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_tl3GrKB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_NVQfZ1wS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_DZtqRyxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wvYElEpD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_xWpkOo3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_2KtwQCdW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_olsP70nX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_4aDK9MrJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_3bRM93Ux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wvYElEpD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_NVQfZ1wS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_olsP70nX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_30PMe1O9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_P93JhlOV, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_6gcULbrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_P93JhlOV, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_MdCp59gE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_30PMe1O9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_GgveKoLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SRkslpsg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_yDItFAoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eiBMlk1o, 1, m, &cVar_eiBMlk1o_sendMessage);
}

void Heavy_PhaseRing::cCast_tfcoUf9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_QJYcFyS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IkT7oU0M, 0, m, &cPack_IkT7oU0M_sendMessage);
}

void Heavy_PhaseRing::cUnop_JiGgiAlJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Q29jOqWk, 0, m, &cPack_Q29jOqWk_sendMessage);
}

void Heavy_PhaseRing::cPack_Q29jOqWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AwubTsXz, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_IkT7oU0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_y81cXvBh, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_ggUYx6Kr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_QJYcFyS2_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_JiGgiAlJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_A3hKbXbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_ggUYx6Kr_sendMessage);
}

void Heavy_PhaseRing::cSlice_L5yRvuNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_23BsY7P5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_jUBi9E0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lR6DqVy2_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_fgoC646C_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_oTDS2Op9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_fBpDCkO3_sendMessage);
}

void Heavy_PhaseRing::cBinop_fBpDCkO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_ggUYx6Kr_sendMessage);
}

void Heavy_PhaseRing::cBinop_23BsY7P5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7kEcwbbN_sendMessage(_c, 0, m);
  cSend_Do0bKBSX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_zKLgK6RO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N9EtvCV8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P6jCW3I2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3GEwdbHA, 0, m, &cVar_3GEwdbHA_sendMessage);
}

void Heavy_PhaseRing::cBinop_9XOC5PqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_pGlmna1e_sendMessage);
}

void Heavy_PhaseRing::cBinop_pGlmna1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zKLgK6RO, HV_BINOP_MULTIPLY, 1, m, &cBinop_zKLgK6RO_sendMessage);
}

void Heavy_PhaseRing::cCast_lR6DqVy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kx7WYgZF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_7kEcwbbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kOAYJe8d_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_P6jCW3I2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uyg6GiwS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_N9EtvCV8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7y0akvI8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tfcoUf9l_sendMessage);
}

void Heavy_PhaseRing::cBinop_zOpwhopS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JzHBc5xA, 0, m, &cPack_JzHBc5xA_sendMessage);
}

void Heavy_PhaseRing::cSend_Do0bKBSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hOB01E8J_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_IRfyl3DD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mUrop4YA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_4OzIN58z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_IRfyl3DD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_4y1WG0Xc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_emBRX8R6, 0, m, &cSlice_emBRX8R6_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kqSw7Q9W, 0, m, &cRandom_kqSw7Q9W_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ZRbwFfuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_XlhGGLrr_sendMessage);
}

void Heavy_PhaseRing::cUnop_XlhGGLrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_qCxLjEiu_sendMessage);
}

void Heavy_PhaseRing::cRandom_kqSw7Q9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_ZRbwFfuR_sendMessage);
}

void Heavy_PhaseRing::cSlice_emBRX8R6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kqSw7Q9W, 1, m, &cRandom_kqSw7Q9W_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_HivxMowo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gQDmWdV7, HV_BINOP_MULTIPLY, 0, m, &cBinop_gQDmWdV7_sendMessage);
}

void Heavy_PhaseRing::cBinop_yuX7ZSrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_BA0Hn8Xy_sendMessage);
}

void Heavy_PhaseRing::cBinop_BA0Hn8Xy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_43xjdRJu, HV_BINOP_POW, 1, m, &cBinop_43xjdRJu_sendMessage);
  cMsg_q2peZjzy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_43xjdRJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_HivxMowo_sendMessage);
}

void Heavy_PhaseRing::cMsg_q2peZjzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_43xjdRJu, HV_BINOP_POW, 0, m, &cBinop_43xjdRJu_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_LacPXIXg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_si9GhHfF, 0, m, &cSlice_si9GhHfF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DN6i49pY, 0, m, &cRandom_DN6i49pY_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_T17OUJOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9Dr4FV8N_sendMessage);
}

void Heavy_PhaseRing::cUnop_9Dr4FV8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JDXtV4Z7_sendMessage);
}

void Heavy_PhaseRing::cRandom_DN6i49pY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_T17OUJOb_sendMessage);
}

void Heavy_PhaseRing::cSlice_si9GhHfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DN6i49pY, 1, m, &cRandom_DN6i49pY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_tIeJMhc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_1379S3bt, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_kGQqzVpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_FShvyTXI_sendMessage);
}

void Heavy_PhaseRing::cVar_IkMvwwrm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_LB2ew2iH, 0, m);
}

void Heavy_PhaseRing::cVar_St0WSmTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_nf2jQAJ2, 0, m);
}

void Heavy_PhaseRing::cVar_gdz77FuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x51H52iu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5fNiW1bd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cA39uumb_sendMessage);
}

void Heavy_PhaseRing::cCast_0gcvn0gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_ADFKvGqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_35ClfaMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_3Mfmya7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_zDiT2eCf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_X5ycRFFH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_X5ycRFFH_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_EEVFXi6s, 1, m, &cDelay_EEVFXi6s_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FCri5q9A_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_EEVFXi6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EEVFXi6s, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fuu1l6TP, 0, m, &cVar_fuu1l6TP_sendMessage);
}

void Heavy_PhaseRing::cMsg_X5ycRFFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EEVFXi6s, 0, m, &cDelay_EEVFXi6s_sendMessage);
}

void Heavy_PhaseRing::cCast_FCri5q9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EEVFXi6s, 0, m, &cDelay_EEVFXi6s_sendMessage);
}

void Heavy_PhaseRing::cVar_fuu1l6TP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZaNnFg50_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_SCTLtfFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gdz77FuD, 0, m, &cVar_gdz77FuD_sendMessage);
}

void Heavy_PhaseRing::cMsg_MZu8ZgXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_gT5uhfY9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_6JmVIw6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_CNiv34fc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_k4EGrYUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_PsNJQaTh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_lQaljssR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AQ7bNWxe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_nHLaVdAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_FejasjHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4OYr2W2Y_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_gT5uhfY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_CNiv34fc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AQ7bNWxe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_PsNJQaTh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4OYr2W2Y_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_k6PPVksL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_oUK3aHfG, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_ZaNnFg50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_oUK3aHfG, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_cA39uumb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zDiT2eCf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_x51H52iu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k6PPVksL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_5fNiW1bd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fuu1l6TP, 1, m, &cVar_fuu1l6TP_sendMessage);
}

void Heavy_PhaseRing::cCast_C83FYaXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_FoUbygz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XKnoZ4C7, 0, m, &cPack_XKnoZ4C7_sendMessage);
}

void Heavy_PhaseRing::cUnop_kVuaE7sZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_A1gdQFHg, 0, m, &cPack_A1gdQFHg_sendMessage);
}

void Heavy_PhaseRing::cPack_A1gdQFHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2B3idU3w, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_XKnoZ4C7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Zx1Khw9H, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_WbtWfjka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_FoUbygz5_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_kVuaE7sZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_Xy1r0SKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_WbtWfjka_sendMessage);
}

void Heavy_PhaseRing::cSlice_87noxniN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_CFzAPUlG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_VcKrQMbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Q79Hrun_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_yuX7ZSrD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_qCxLjEiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_rMXkT6N0_sendMessage);
}

void Heavy_PhaseRing::cBinop_rMXkT6N0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_WbtWfjka_sendMessage);
}

void Heavy_PhaseRing::cBinop_CFzAPUlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NYps0mAj_sendMessage(_c, 0, m);
  cSend_8VwwJDyQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_gQDmWdV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uBLh8oAy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ETM7Fcnp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_St0WSmTm, 0, m, &cVar_St0WSmTm_sendMessage);
}

void Heavy_PhaseRing::cBinop_JDXtV4Z7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_0dAZB12b_sendMessage);
}

void Heavy_PhaseRing::cBinop_0dAZB12b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gQDmWdV7, HV_BINOP_MULTIPLY, 1, m, &cBinop_gQDmWdV7_sendMessage);
}

void Heavy_PhaseRing::cCast_1Q79Hrun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LacPXIXg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_NYps0mAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uBquHsQs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_uBLh8oAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SCTLtfFO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C83FYaXY_sendMessage);
}

void Heavy_PhaseRing::cCast_ETM7Fcnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4y1WG0Xc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_FShvyTXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tIeJMhc3, 0, m, &cPack_tIeJMhc3_sendMessage);
}

void Heavy_PhaseRing::cSend_8VwwJDyQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IEvVTTCx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_1zTwy1g0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lKrLhBWy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Z6QeNl6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_1zTwy1g0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_RqgSE5xK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Rg0YYvmI, 0, m, &cSlice_Rg0YYvmI_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2tCzZa8y, 0, m, &cRandom_2tCzZa8y_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_kuzrhQZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_iWTboqJY_sendMessage);
}

void Heavy_PhaseRing::cUnop_iWTboqJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_IxDm6mln_sendMessage);
}

void Heavy_PhaseRing::cRandom_2tCzZa8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_kuzrhQZB_sendMessage);
}

void Heavy_PhaseRing::cSlice_Rg0YYvmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2tCzZa8y, 1, m, &cRandom_2tCzZa8y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_pOb9xhpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T4wyosMe, HV_BINOP_MULTIPLY, 0, m, &cBinop_T4wyosMe_sendMessage);
}

void Heavy_PhaseRing::cBinop_AEyiErvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_9lECnURy_sendMessage);
}

void Heavy_PhaseRing::cBinop_9lECnURy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eZSjtQVT, HV_BINOP_POW, 1, m, &cBinop_eZSjtQVT_sendMessage);
  cMsg_C4NvJYJT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_eZSjtQVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_pOb9xhpc_sendMessage);
}

void Heavy_PhaseRing::cMsg_C4NvJYJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_eZSjtQVT, HV_BINOP_POW, 0, m, &cBinop_eZSjtQVT_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_swdTad1W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zeiMsRQT, 0, m, &cSlice_zeiMsRQT_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_K5tPsM9l, 0, m, &cRandom_K5tPsM9l_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_Rb7DcPfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Fm5X87N9_sendMessage);
}

void Heavy_PhaseRing::cUnop_Fm5X87N9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d0tEHeYB_sendMessage);
}

void Heavy_PhaseRing::cRandom_K5tPsM9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_Rb7DcPfE_sendMessage);
}

void Heavy_PhaseRing::cSlice_zeiMsRQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_K5tPsM9l, 1, m, &cRandom_K5tPsM9l_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_0Orw5xlf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ISm6S5dl, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_ia9skgs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_gC64rJGM_sendMessage);
}

void Heavy_PhaseRing::cVar_vVGy03qd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_FEpaSRFq, 0, m);
}

void Heavy_PhaseRing::cVar_Nl85qvXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_wgZ6wBNY, 0, m);
}

void Heavy_PhaseRing::cVar_tLoaVAEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w0JBibD8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PI0mzCko_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wUfORJ1P_sendMessage);
}

void Heavy_PhaseRing::cCast_iRUB3keg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_vNYLbCbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_HKC6CFrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_1AnGgcMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_dznTkbx5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_MVzlqFKi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_MVzlqFKi_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_HvZs9rW8, 1, m, &cDelay_HvZs9rW8_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PUiVtbyZ_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_HvZs9rW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HvZs9rW8, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HLArS4Bg, 0, m, &cVar_HLArS4Bg_sendMessage);
}

void Heavy_PhaseRing::cMsg_MVzlqFKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvZs9rW8, 0, m, &cDelay_HvZs9rW8_sendMessage);
}

void Heavy_PhaseRing::cCast_PUiVtbyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvZs9rW8, 0, m, &cDelay_HvZs9rW8_sendMessage);
}

void Heavy_PhaseRing::cVar_HLArS4Bg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KQtuzHjQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_7nU7aROx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tLoaVAEH, 0, m, &cVar_tLoaVAEH_sendMessage);
}

void Heavy_PhaseRing::cMsg_U4oE9BVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_E9xuTOAk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_zOARik7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_UB0Fh49x_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_1i8u0G25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_9dINgmIX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_IJpOOscd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PjEBdfYT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_B1M0Xcml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_R1UABskU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vrykT3kU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_E9xuTOAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_UB0Fh49x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PjEBdfYT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_9dINgmIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vrykT3kU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_1ZK5kgiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_DHtymZqR, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_KQtuzHjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_DHtymZqR, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_wUfORJ1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dznTkbx5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_w0JBibD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1ZK5kgiK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_PI0mzCko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HLArS4Bg, 1, m, &cVar_HLArS4Bg_sendMessage);
}

void Heavy_PhaseRing::cCast_ocWgKNb0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_eG9QnR3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7BlV7H0w, 0, m, &cPack_7BlV7H0w_sendMessage);
}

void Heavy_PhaseRing::cUnop_iN95r5dj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FAy19rGU, 0, m, &cPack_FAy19rGU_sendMessage);
}

void Heavy_PhaseRing::cPack_FAy19rGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0HqE5T6z, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_7BlV7H0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_kTXW25HV, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_YFWMG6xL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_eG9QnR3R_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_iN95r5dj_sendMessage);
}

void Heavy_PhaseRing::cMsg_mhh3Tp4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_YFWMG6xL_sendMessage);
}

void Heavy_PhaseRing::cSlice_aGFuVIpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_p8CUblFc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_BN7cx0Gf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AJ964qna_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_AEyiErvL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_IxDm6mln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_AZS4QqSZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_AZS4QqSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_YFWMG6xL_sendMessage);
}

void Heavy_PhaseRing::cBinop_p8CUblFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_n8mhDZ7C_sendMessage(_c, 0, m);
  cSend_A9Nfr5TP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_T4wyosMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wyKduql5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ROBvO7ZL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Nl85qvXx, 0, m, &cVar_Nl85qvXx_sendMessage);
}

void Heavy_PhaseRing::cBinop_d0tEHeYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_k0arBXbD_sendMessage);
}

void Heavy_PhaseRing::cBinop_k0arBXbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T4wyosMe, HV_BINOP_MULTIPLY, 1, m, &cBinop_T4wyosMe_sendMessage);
}

void Heavy_PhaseRing::cCast_AJ964qna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_swdTad1W_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_n8mhDZ7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SeedFGST_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_wyKduql5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7nU7aROx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ocWgKNb0_sendMessage);
}

void Heavy_PhaseRing::cCast_ROBvO7ZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RqgSE5xK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_gC64rJGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0Orw5xlf, 0, m, &cPack_0Orw5xlf_sendMessage);
}

void Heavy_PhaseRing::cSend_A9Nfr5TP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gKWyKNrd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_mmFoR07w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qkOsjaH2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_1qOHquZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_mmFoR07w_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cTabhead_IMwe3nPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_el4mRY3o, HV_BINOP_SUBTRACT, 0, m, &cBinop_el4mRY3o_sendMessage);
}

void Heavy_PhaseRing::cMsg_25jR9CGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2gg7gWJO_sendMessage);
}

void Heavy_PhaseRing::cSystem_2gg7gWJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CB9bmvEJ_sendMessage);
}

void Heavy_PhaseRing::cVar_D0FpZg8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_52bDaFt1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_jY3Ty1EC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jY3Ty1EC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GIP4xKs4, 0, m, &cDelay_GIP4xKs4_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SCiAZ5ej, 0, m, &sTabread_SCiAZ5ej_sendMessage);
}

void Heavy_PhaseRing::cDelay_GIP4xKs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GIP4xKs4, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SCiAZ5ej, 0, m, &sTabread_SCiAZ5ej_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GIP4xKs4, 0, m, &cDelay_GIP4xKs4_sendMessage);
}

void Heavy_PhaseRing::sTabread_SCiAZ5ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IeLiIdDR, HV_BINOP_SUBTRACT, 0, m, &cBinop_IeLiIdDR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_KZ65lBkA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fOBcn907, HV_BINOP_MAX, 0, m, &cBinop_fOBcn907_sendMessage);
}

void Heavy_PhaseRing::cBinop_CB9bmvEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KZ65lBkA, HV_BINOP_MULTIPLY, 0, m, &cBinop_KZ65lBkA_sendMessage);
}

void Heavy_PhaseRing::cBinop_el4mRY3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IV8mhHg9_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SCiAZ5ej, 0, m, &sTabread_SCiAZ5ej_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HZUSzFQU_sendMessage);
}

void Heavy_PhaseRing::cSystem_27O6cy4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IeLiIdDR, HV_BINOP_SUBTRACT, 1, m, &cBinop_IeLiIdDR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GIP4xKs4, 2, m, &cDelay_GIP4xKs4_sendMessage);
}

void Heavy_PhaseRing::cMsg_52bDaFt1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_27O6cy4v_sendMessage);
}

void Heavy_PhaseRing::cMsg_IV8mhHg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jY3Ty1EC, 0, m, &cDelay_jY3Ty1EC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GIP4xKs4, 0, m, &cDelay_GIP4xKs4_sendMessage);
}

void Heavy_PhaseRing::cMsg_hh3t2McM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_fOBcn907, HV_BINOP_MAX, 1, m, &cBinop_fOBcn907_sendMessage);
}

void Heavy_PhaseRing::cBinop_fOBcn907_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_el4mRY3o, HV_BINOP_SUBTRACT, 1, m, &cBinop_el4mRY3o_sendMessage);
}

void Heavy_PhaseRing::cCast_HZUSzFQU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jY3Ty1EC, 0, m, &cDelay_jY3Ty1EC_sendMessage);
}

void Heavy_PhaseRing::cBinop_Tzqln6em_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jY3Ty1EC, 2, m, &cDelay_jY3Ty1EC_sendMessage);
}

void Heavy_PhaseRing::cBinop_IeLiIdDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Tzqln6em_sendMessage);
}

void Heavy_PhaseRing::cCast_pNQEpW9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D0FpZg8t, 0, m, &cVar_D0FpZg8t_sendMessage);
  cMsg_25jR9CGy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IMwe3nPg, 0, m, &cTabhead_IMwe3nPg_sendMessage);
}

void Heavy_PhaseRing::cTabhead_Hg1oudlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tp8Xo4VR, HV_BINOP_SUBTRACT, 0, m, &cBinop_tp8Xo4VR_sendMessage);
}

void Heavy_PhaseRing::cMsg_NqoKhHwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_trvumPpH_sendMessage);
}

void Heavy_PhaseRing::cSystem_trvumPpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JHCJufdJ_sendMessage);
}

void Heavy_PhaseRing::cVar_edpZMBKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gUAhWHU8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_VsFzuik0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VsFzuik0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TYnX2QFK, 0, m, &cDelay_TYnX2QFK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kbnk23zl, 0, m, &sTabread_kbnk23zl_sendMessage);
}

void Heavy_PhaseRing::cDelay_TYnX2QFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TYnX2QFK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kbnk23zl, 0, m, &sTabread_kbnk23zl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TYnX2QFK, 0, m, &cDelay_TYnX2QFK_sendMessage);
}

void Heavy_PhaseRing::sTabread_kbnk23zl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bDGHZjcc, HV_BINOP_SUBTRACT, 0, m, &cBinop_bDGHZjcc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_D98s8usE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CP65G6oK, HV_BINOP_MAX, 0, m, &cBinop_CP65G6oK_sendMessage);
}

void Heavy_PhaseRing::cBinop_JHCJufdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D98s8usE, HV_BINOP_MULTIPLY, 0, m, &cBinop_D98s8usE_sendMessage);
}

void Heavy_PhaseRing::cBinop_tp8Xo4VR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_77CnE9XK_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kbnk23zl, 0, m, &sTabread_kbnk23zl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HUVRs5ze_sendMessage);
}

void Heavy_PhaseRing::cSystem_QlxPxCJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bDGHZjcc, HV_BINOP_SUBTRACT, 1, m, &cBinop_bDGHZjcc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TYnX2QFK, 2, m, &cDelay_TYnX2QFK_sendMessage);
}

void Heavy_PhaseRing::cMsg_gUAhWHU8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QlxPxCJH_sendMessage);
}

void Heavy_PhaseRing::cMsg_77CnE9XK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_VsFzuik0, 0, m, &cDelay_VsFzuik0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TYnX2QFK, 0, m, &cDelay_TYnX2QFK_sendMessage);
}

void Heavy_PhaseRing::cMsg_Rz2lPwaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_CP65G6oK, HV_BINOP_MAX, 1, m, &cBinop_CP65G6oK_sendMessage);
}

void Heavy_PhaseRing::cBinop_CP65G6oK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tp8Xo4VR, HV_BINOP_SUBTRACT, 1, m, &cBinop_tp8Xo4VR_sendMessage);
}

void Heavy_PhaseRing::cCast_HUVRs5ze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VsFzuik0, 0, m, &cDelay_VsFzuik0_sendMessage);
}

void Heavy_PhaseRing::cBinop_7xMJcgXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VsFzuik0, 2, m, &cDelay_VsFzuik0_sendMessage);
}

void Heavy_PhaseRing::cBinop_bDGHZjcc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7xMJcgXg_sendMessage);
}

void Heavy_PhaseRing::cCast_6klDYcjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_edpZMBKO, 0, m, &cVar_edpZMBKO_sendMessage);
  cMsg_NqoKhHwA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Hg1oudlu, 0, m, &cTabhead_Hg1oudlu_sendMessage);
}

void Heavy_PhaseRing::cTabhead_dpicMwrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GLjyDCHi, HV_BINOP_SUBTRACT, 0, m, &cBinop_GLjyDCHi_sendMessage);
}

void Heavy_PhaseRing::cMsg_f9Tuaazq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EdRuCDKw_sendMessage);
}

void Heavy_PhaseRing::cSystem_EdRuCDKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_x3j0pKs7_sendMessage);
}

void Heavy_PhaseRing::cVar_uxMuFUYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GzXQ6UkS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_nAxvVKDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nAxvVKDs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_em4V3bfI, 0, m, &cDelay_em4V3bfI_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nX943Mky, 0, m, &sTabread_nX943Mky_sendMessage);
}

void Heavy_PhaseRing::cDelay_em4V3bfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_em4V3bfI, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nX943Mky, 0, m, &sTabread_nX943Mky_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_em4V3bfI, 0, m, &cDelay_em4V3bfI_sendMessage);
}

void Heavy_PhaseRing::sTabread_nX943Mky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3Z7pqHFH, HV_BINOP_SUBTRACT, 0, m, &cBinop_3Z7pqHFH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_IUkjt1TS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uRtrO9sw, HV_BINOP_MAX, 0, m, &cBinop_uRtrO9sw_sendMessage);
}

void Heavy_PhaseRing::cBinop_x3j0pKs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IUkjt1TS, HV_BINOP_MULTIPLY, 0, m, &cBinop_IUkjt1TS_sendMessage);
}

void Heavy_PhaseRing::cBinop_GLjyDCHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BhmPbDC2_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nX943Mky, 0, m, &sTabread_nX943Mky_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0XaXVymR_sendMessage);
}

void Heavy_PhaseRing::cSystem_ZKFF0k5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Z7pqHFH, HV_BINOP_SUBTRACT, 1, m, &cBinop_3Z7pqHFH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_em4V3bfI, 2, m, &cDelay_em4V3bfI_sendMessage);
}

void Heavy_PhaseRing::cMsg_GzXQ6UkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZKFF0k5h_sendMessage);
}

void Heavy_PhaseRing::cMsg_BhmPbDC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nAxvVKDs, 0, m, &cDelay_nAxvVKDs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_em4V3bfI, 0, m, &cDelay_em4V3bfI_sendMessage);
}

void Heavy_PhaseRing::cMsg_UFZlFL0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_uRtrO9sw, HV_BINOP_MAX, 1, m, &cBinop_uRtrO9sw_sendMessage);
}

void Heavy_PhaseRing::cBinop_uRtrO9sw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GLjyDCHi, HV_BINOP_SUBTRACT, 1, m, &cBinop_GLjyDCHi_sendMessage);
}

void Heavy_PhaseRing::cCast_0XaXVymR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nAxvVKDs, 0, m, &cDelay_nAxvVKDs_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZVGKSbxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nAxvVKDs, 2, m, &cDelay_nAxvVKDs_sendMessage);
}

void Heavy_PhaseRing::cBinop_3Z7pqHFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZVGKSbxk_sendMessage);
}

void Heavy_PhaseRing::cCast_iBMMV4Zs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uxMuFUYk, 0, m, &cVar_uxMuFUYk_sendMessage);
  cMsg_f9Tuaazq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_dpicMwrf, 0, m, &cTabhead_dpicMwrf_sendMessage);
}

void Heavy_PhaseRing::cTabhead_7SacHoqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kEPxrPbk, HV_BINOP_SUBTRACT, 0, m, &cBinop_kEPxrPbk_sendMessage);
}

void Heavy_PhaseRing::cMsg_Npz1LOpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_536r8u07_sendMessage);
}

void Heavy_PhaseRing::cSystem_536r8u07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kznTp8C6_sendMessage);
}

void Heavy_PhaseRing::cVar_JOarUAdq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ft4Ne1eJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_QSyaPP8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QSyaPP8Z, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pJFoxiT3, 0, m, &cDelay_pJFoxiT3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9gZBr7Nn, 0, m, &sTabread_9gZBr7Nn_sendMessage);
}

void Heavy_PhaseRing::cDelay_pJFoxiT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pJFoxiT3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9gZBr7Nn, 0, m, &sTabread_9gZBr7Nn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pJFoxiT3, 0, m, &cDelay_pJFoxiT3_sendMessage);
}

void Heavy_PhaseRing::sTabread_9gZBr7Nn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_YIYpUPPS, HV_BINOP_SUBTRACT, 0, m, &cBinop_YIYpUPPS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_K7rMxLkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_shr2ES1b, HV_BINOP_MAX, 0, m, &cBinop_shr2ES1b_sendMessage);
}

void Heavy_PhaseRing::cBinop_kznTp8C6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K7rMxLkT, HV_BINOP_MULTIPLY, 0, m, &cBinop_K7rMxLkT_sendMessage);
}

void Heavy_PhaseRing::cBinop_kEPxrPbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TCaLVRDx_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9gZBr7Nn, 0, m, &sTabread_9gZBr7Nn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0izfHAqv_sendMessage);
}

void Heavy_PhaseRing::cSystem_ZtoKnu5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YIYpUPPS, HV_BINOP_SUBTRACT, 1, m, &cBinop_YIYpUPPS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pJFoxiT3, 2, m, &cDelay_pJFoxiT3_sendMessage);
}

void Heavy_PhaseRing::cMsg_ft4Ne1eJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZtoKnu5r_sendMessage);
}

void Heavy_PhaseRing::cMsg_TCaLVRDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QSyaPP8Z, 0, m, &cDelay_QSyaPP8Z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pJFoxiT3, 0, m, &cDelay_pJFoxiT3_sendMessage);
}

void Heavy_PhaseRing::cMsg_fmWM30K8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_shr2ES1b, HV_BINOP_MAX, 1, m, &cBinop_shr2ES1b_sendMessage);
}

void Heavy_PhaseRing::cBinop_shr2ES1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kEPxrPbk, HV_BINOP_SUBTRACT, 1, m, &cBinop_kEPxrPbk_sendMessage);
}

void Heavy_PhaseRing::cCast_0izfHAqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QSyaPP8Z, 0, m, &cDelay_QSyaPP8Z_sendMessage);
}

void Heavy_PhaseRing::cBinop_F15jixla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QSyaPP8Z, 2, m, &cDelay_QSyaPP8Z_sendMessage);
}

void Heavy_PhaseRing::cBinop_YIYpUPPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_F15jixla_sendMessage);
}

void Heavy_PhaseRing::cCast_WhV2gxOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JOarUAdq, 0, m, &cVar_JOarUAdq_sendMessage);
  cMsg_Npz1LOpj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7SacHoqo, 0, m, &cTabhead_7SacHoqo_sendMessage);
}

void Heavy_PhaseRing::cMsg_PoLBZZyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5DB0o3IC_sendMessage);
}

void Heavy_PhaseRing::cSystem_5DB0o3IC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_H8njy5v3_sendMessage);
}

void Heavy_PhaseRing::cDelay_VFE34itR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VFE34itR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ciXARioa, 0, m, &cDelay_ciXARioa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VFE34itR, 0, m, &cDelay_VFE34itR_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IpWOMN7X, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_ciXARioa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ciXARioa, m);
  cMsg_Ovo9loqO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_FzlhKpod_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_hJJ2aGdt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_o2ZRorpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gKhbYEwm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_pgPZf0IE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S8iUYrN2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VFE34itR, 2, m, &cDelay_VFE34itR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8tsKlpel_sendMessage);
}

void Heavy_PhaseRing::cMsg_gKhbYEwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_pgPZf0IE, 0, m, &hTable_pgPZf0IE_sendMessage);
}

void Heavy_PhaseRing::cBinop_H8njy5v3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_o2ZRorpm_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ovo9loqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_pgPZf0IE, 0, m, &hTable_pgPZf0IE_sendMessage);
}

void Heavy_PhaseRing::cCast_8tsKlpel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VFE34itR, 0, m, &cDelay_VFE34itR_sendMessage);
}

void Heavy_PhaseRing::cMsg_S8iUYrN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ciXARioa, 2, m, &cDelay_ciXARioa_sendMessage);
}

void Heavy_PhaseRing::cMsg_hJJ2aGdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IpWOMN7X, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_GE3arVYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I0U8y8Dc_sendMessage);
}

void Heavy_PhaseRing::cSystem_I0U8y8Dc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WFM6kvHY_sendMessage);
}

void Heavy_PhaseRing::cDelay_E6NhkF3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_E6NhkF3o, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zRepZjUw, 0, m, &cDelay_zRepZjUw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E6NhkF3o, 0, m, &cDelay_E6NhkF3o_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8PaB8R5s, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_zRepZjUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zRepZjUw, m);
  cMsg_6NoUq5Of_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Di75K7UB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_NxVPQooY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_IUu5u6BM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VmbNhjhV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_gcHyd7im_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5nnJ4ZxT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E6NhkF3o, 2, m, &cDelay_E6NhkF3o_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5Wv8YvkA_sendMessage);
}

void Heavy_PhaseRing::cMsg_VmbNhjhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gcHyd7im, 0, m, &hTable_gcHyd7im_sendMessage);
}

void Heavy_PhaseRing::cBinop_WFM6kvHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_IUu5u6BM_sendMessage);
}

void Heavy_PhaseRing::cMsg_6NoUq5Of_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gcHyd7im, 0, m, &hTable_gcHyd7im_sendMessage);
}

void Heavy_PhaseRing::cCast_5Wv8YvkA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_E6NhkF3o, 0, m, &cDelay_E6NhkF3o_sendMessage);
}

void Heavy_PhaseRing::cMsg_5nnJ4ZxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_zRepZjUw, 2, m, &cDelay_zRepZjUw_sendMessage);
}

void Heavy_PhaseRing::cMsg_NxVPQooY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8PaB8R5s, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_tOclDmI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZG2ZDj88_sendMessage);
}

void Heavy_PhaseRing::cSystem_ZG2ZDj88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lJsR9WwC_sendMessage);
}

void Heavy_PhaseRing::cDelay_3OQy15n8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3OQy15n8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZUhYwtMt, 0, m, &cDelay_ZUhYwtMt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3OQy15n8, 0, m, &cDelay_3OQy15n8_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sX1AxrfI, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_ZUhYwtMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZUhYwtMt, m);
  cMsg_fSb7W54m_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_GIYUSwiv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6b1I8S53_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ybOxOapW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jvEo5qzg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_hwX01sys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iGBa2y45_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3OQy15n8, 2, m, &cDelay_3OQy15n8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bNoeetvN_sendMessage);
}

void Heavy_PhaseRing::cMsg_jvEo5qzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_hwX01sys, 0, m, &hTable_hwX01sys_sendMessage);
}

void Heavy_PhaseRing::cBinop_lJsR9WwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_ybOxOapW_sendMessage);
}

void Heavy_PhaseRing::cMsg_fSb7W54m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_hwX01sys, 0, m, &hTable_hwX01sys_sendMessage);
}

void Heavy_PhaseRing::cCast_bNoeetvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3OQy15n8, 0, m, &cDelay_3OQy15n8_sendMessage);
}

void Heavy_PhaseRing::cMsg_iGBa2y45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZUhYwtMt, 2, m, &cDelay_ZUhYwtMt_sendMessage);
}

void Heavy_PhaseRing::cMsg_6b1I8S53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sX1AxrfI, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_Hwej5COh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WJ0OK5Z7_sendMessage);
}

void Heavy_PhaseRing::cSystem_WJ0OK5Z7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GGaXljuz_sendMessage);
}

void Heavy_PhaseRing::cDelay_yxr76SAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yxr76SAm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_shNGIKSY, 0, m, &cDelay_shNGIKSY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yxr76SAm, 0, m, &cDelay_yxr76SAm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uLATWRDs, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_shNGIKSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_shNGIKSY, m);
  cMsg_dctbAmud_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_MyKFKPN4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_pl6znenE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ZxOLWb5w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QTEgxVbN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_WFbfQ60g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cptqzFVc_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yxr76SAm, 2, m, &cDelay_yxr76SAm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pwoC0lix_sendMessage);
}

void Heavy_PhaseRing::cMsg_QTEgxVbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_WFbfQ60g, 0, m, &hTable_WFbfQ60g_sendMessage);
}

void Heavy_PhaseRing::cBinop_GGaXljuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_ZxOLWb5w_sendMessage);
}

void Heavy_PhaseRing::cMsg_dctbAmud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_WFbfQ60g, 0, m, &hTable_WFbfQ60g_sendMessage);
}

void Heavy_PhaseRing::cCast_pwoC0lix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yxr76SAm, 0, m, &cDelay_yxr76SAm_sendMessage);
}

void Heavy_PhaseRing::cMsg_cptqzFVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_shNGIKSY, 2, m, &cDelay_shNGIKSY_sendMessage);
}

void Heavy_PhaseRing::cMsg_pl6znenE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uLATWRDs, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_tffwZN4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Xw8xualb_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_SQ2Lnral_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_hR8xCE9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2hPczHq2, HV_BINOP_POW, 0, m, &cBinop_2hPczHq2_sendMessage);
}

void Heavy_PhaseRing::cBinop_2hPczHq2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_Qou9eTIb_sendMessage);
}

void Heavy_PhaseRing::cBinop_MvroLvKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_mWjBxvUn_sendMessage);
}

void Heavy_PhaseRing::cCast_iYNZqP3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_CTDlGwT5_sendMessage);
}

void Heavy_PhaseRing::cCast_oo3cGf52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tffwZN4M, 0, m, &cIf_tffwZN4M_sendMessage);
}

void Heavy_PhaseRing::cBinop_CTDlGwT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tffwZN4M, 1, m, &cIf_tffwZN4M_sendMessage);
}

void Heavy_PhaseRing::cBinop_SQ2Lnral_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_MvroLvKm_sendMessage);
}

void Heavy_PhaseRing::cMsg_Xw8xualb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_Qou9eTIb_sendMessage);
}

void Heavy_PhaseRing::cBinop_mWjBxvUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2hPczHq2, HV_BINOP_POW, 1, m, &cBinop_2hPczHq2_sendMessage);
  cMsg_hR8xCE9t_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_5cGHpwXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0HprnEfv, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_wvfA3FwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OCEdvZRu, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_PLjrnzeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_uWgDmdNP_sendMessage);
}

void Heavy_PhaseRing::cBinop_uWgDmdNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_6PwnkgLC_sendMessage);
}

void Heavy_PhaseRing::cVar_Qs45NgZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T8fz72kT, HV_BINOP_MULTIPLY, 0, m, &cBinop_T8fz72kT_sendMessage);
}

void Heavy_PhaseRing::cMsg_Pq5XmrtK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4Pj95dWf_sendMessage);
}

void Heavy_PhaseRing::cSystem_4Pj95dWf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JPeYQGga_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_T8fz72kT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_FJ7v4N0v_sendMessage);
}

void Heavy_PhaseRing::cBinop_CaACCztg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T8fz72kT, HV_BINOP_MULTIPLY, 1, m, &cBinop_T8fz72kT_sendMessage);
}

void Heavy_PhaseRing::cMsg_JPeYQGga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CaACCztg_sendMessage);
}

void Heavy_PhaseRing::cBinop_FJ7v4N0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gbYtpG8k_sendMessage);
}

void Heavy_PhaseRing::cBinop_gbYtpG8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8EVaq3LF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9QUtcGKm, m);
}

void Heavy_PhaseRing::cBinop_8EVaq3LF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_u8HOxMwx, m);
}

void Heavy_PhaseRing::cVar_yVIvHqaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iYNZqP3s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oo3cGf52_sendMessage);
}

void Heavy_PhaseRing::cVar_fggGamqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_PLjrnzeI_sendMessage);
}

void Heavy_PhaseRing::cVar_PphZneDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_NoudE79E_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NNPgEX51, 0, m, &cIf_NNPgEX51_sendMessage);
}

void Heavy_PhaseRing::cVar_q8CjSUa9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_c0QarDI2_sendMessage);
}

void Heavy_PhaseRing::cIf_NNPgEX51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_QmlllzNU_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_UE2NlU6a, 0, m, &cVar_UE2NlU6a_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_NoudE79E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NNPgEX51, 1, m, &cIf_NNPgEX51_sendMessage);
}

void Heavy_PhaseRing::cBinop_c0QarDI2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wri1D4JR_sendMessage);
}

void Heavy_PhaseRing::cBinop_wri1D4JR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MQAzBCR1, 0, m, &cVar_MQAzBCR1_sendMessage);
}

void Heavy_PhaseRing::cTabhead_VlBMV2gL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_srimtoJc, HV_BINOP_SUBTRACT, 0, m, &cBinop_srimtoJc_sendMessage);
}

void Heavy_PhaseRing::cMsg_GRdNAW46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Xi8vd0z0_sendMessage);
}

void Heavy_PhaseRing::cSystem_Xi8vd0z0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HYItm7wf_sendMessage);
}

void Heavy_PhaseRing::cVar_DnT4jY1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EJN58XUh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_YQwUiXj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YQwUiXj2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RsziTqO3, 0, m, &cDelay_RsziTqO3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dJZHmhaK, 0, m, &sTabread_dJZHmhaK_sendMessage);
}

void Heavy_PhaseRing::cDelay_RsziTqO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RsziTqO3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dJZHmhaK, 0, m, &sTabread_dJZHmhaK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RsziTqO3, 0, m, &cDelay_RsziTqO3_sendMessage);
}

void Heavy_PhaseRing::sTabread_dJZHmhaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fKW36ceb, HV_BINOP_SUBTRACT, 0, m, &cBinop_fKW36ceb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_L9JMQJij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jtekiNK0, HV_BINOP_MAX, 0, m, &cBinop_jtekiNK0_sendMessage);
}

void Heavy_PhaseRing::cBinop_HYItm7wf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L9JMQJij, HV_BINOP_MULTIPLY, 0, m, &cBinop_L9JMQJij_sendMessage);
}

void Heavy_PhaseRing::cBinop_srimtoJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sFjhyvaX_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dJZHmhaK, 0, m, &sTabread_dJZHmhaK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pfuu4fJ2_sendMessage);
}

void Heavy_PhaseRing::cSystem_1x9EOLRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fKW36ceb, HV_BINOP_SUBTRACT, 1, m, &cBinop_fKW36ceb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RsziTqO3, 2, m, &cDelay_RsziTqO3_sendMessage);
}

void Heavy_PhaseRing::cMsg_EJN58XUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1x9EOLRU_sendMessage);
}

void Heavy_PhaseRing::cMsg_sFjhyvaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YQwUiXj2, 0, m, &cDelay_YQwUiXj2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RsziTqO3, 0, m, &cDelay_RsziTqO3_sendMessage);
}

void Heavy_PhaseRing::cMsg_mDCqoyc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_jtekiNK0, HV_BINOP_MAX, 1, m, &cBinop_jtekiNK0_sendMessage);
}

void Heavy_PhaseRing::cBinop_jtekiNK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_srimtoJc, HV_BINOP_SUBTRACT, 1, m, &cBinop_srimtoJc_sendMessage);
}

void Heavy_PhaseRing::cCast_Pfuu4fJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YQwUiXj2, 0, m, &cDelay_YQwUiXj2_sendMessage);
}

void Heavy_PhaseRing::cBinop_Mn6Xael3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YQwUiXj2, 2, m, &cDelay_YQwUiXj2_sendMessage);
}

void Heavy_PhaseRing::cBinop_fKW36ceb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Mn6Xael3_sendMessage);
}

void Heavy_PhaseRing::cCast_wVimVK5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DnT4jY1y, 0, m, &cVar_DnT4jY1y_sendMessage);
  cMsg_GRdNAW46_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VlBMV2gL, 0, m, &cTabhead_VlBMV2gL_sendMessage);
}

void Heavy_PhaseRing::cMsg_UDa8P0Bc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R5BiRBlA_sendMessage);
}

void Heavy_PhaseRing::cSystem_R5BiRBlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QHicXE67_sendMessage);
}

void Heavy_PhaseRing::cDelay_6sa91CDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6sa91CDy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9nAHaqD3, 0, m, &cDelay_9nAHaqD3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6sa91CDy, 0, m, &cDelay_6sa91CDy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YMuJVHKs, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_9nAHaqD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9nAHaqD3, m);
  cMsg_cZNTGwaV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_ynPyO0Rb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_1Kweq1w0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_yrZ5XqhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rm8xtM6N_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_OnYdYUyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JaUtakac_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6sa91CDy, 2, m, &cDelay_6sa91CDy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hbXxR1Uo_sendMessage);
}

void Heavy_PhaseRing::cMsg_Rm8xtM6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_OnYdYUyR, 0, m, &hTable_OnYdYUyR_sendMessage);
}

void Heavy_PhaseRing::cBinop_QHicXE67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_yrZ5XqhQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_cZNTGwaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_OnYdYUyR, 0, m, &hTable_OnYdYUyR_sendMessage);
}

void Heavy_PhaseRing::cCast_hbXxR1Uo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6sa91CDy, 0, m, &cDelay_6sa91CDy_sendMessage);
}

void Heavy_PhaseRing::cMsg_JaUtakac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_9nAHaqD3, 2, m, &cDelay_9nAHaqD3_sendMessage);
}

void Heavy_PhaseRing::cMsg_1Kweq1w0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YMuJVHKs, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_YMntfmcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_feGCcxyn, HV_BINOP_SUBTRACT, 0, m, &cBinop_feGCcxyn_sendMessage);
}

void Heavy_PhaseRing::cMsg_Uup5pJ5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_22No62ec_sendMessage);
}

void Heavy_PhaseRing::cSystem_22No62ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Hju7q1ef_sendMessage);
}

void Heavy_PhaseRing::cVar_UOaRLbba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6HbGjg3T_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_hQJUvCnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hQJUvCnk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yamN075Q, 0, m, &cDelay_yamN075Q_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_YJ4wweYe, 0, m, &sTabread_YJ4wweYe_sendMessage);
}

void Heavy_PhaseRing::cDelay_yamN075Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yamN075Q, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_YJ4wweYe, 0, m, &sTabread_YJ4wweYe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yamN075Q, 0, m, &cDelay_yamN075Q_sendMessage);
}

void Heavy_PhaseRing::sTabread_YJ4wweYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aaavNkPr, HV_BINOP_SUBTRACT, 0, m, &cBinop_aaavNkPr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_JjQ7ioeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1YoBDDX8, HV_BINOP_MAX, 0, m, &cBinop_1YoBDDX8_sendMessage);
}

void Heavy_PhaseRing::cBinop_Hju7q1ef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JjQ7ioeH, HV_BINOP_MULTIPLY, 0, m, &cBinop_JjQ7ioeH_sendMessage);
}

void Heavy_PhaseRing::cBinop_feGCcxyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ttedehTE_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_YJ4wweYe, 0, m, &sTabread_YJ4wweYe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Eul43oz6_sendMessage);
}

void Heavy_PhaseRing::cSystem_61ar2AqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aaavNkPr, HV_BINOP_SUBTRACT, 1, m, &cBinop_aaavNkPr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yamN075Q, 2, m, &cDelay_yamN075Q_sendMessage);
}

void Heavy_PhaseRing::cMsg_6HbGjg3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_61ar2AqX_sendMessage);
}

void Heavy_PhaseRing::cMsg_ttedehTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQJUvCnk, 0, m, &cDelay_hQJUvCnk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yamN075Q, 0, m, &cDelay_yamN075Q_sendMessage);
}

void Heavy_PhaseRing::cMsg_6A5Qknck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_1YoBDDX8, HV_BINOP_MAX, 1, m, &cBinop_1YoBDDX8_sendMessage);
}

void Heavy_PhaseRing::cBinop_1YoBDDX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_feGCcxyn, HV_BINOP_SUBTRACT, 1, m, &cBinop_feGCcxyn_sendMessage);
}

void Heavy_PhaseRing::cCast_Eul43oz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQJUvCnk, 0, m, &cDelay_hQJUvCnk_sendMessage);
}

void Heavy_PhaseRing::cBinop_ppdmlXE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQJUvCnk, 2, m, &cDelay_hQJUvCnk_sendMessage);
}

void Heavy_PhaseRing::cBinop_aaavNkPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ppdmlXE7_sendMessage);
}

void Heavy_PhaseRing::cCast_nd686DB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UOaRLbba, 0, m, &cVar_UOaRLbba_sendMessage);
  cMsg_Uup5pJ5p_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YMntfmcA, 0, m, &cTabhead_YMntfmcA_sendMessage);
}

void Heavy_PhaseRing::cMsg_gIIyvXUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_85vOkNK9_sendMessage);
}

void Heavy_PhaseRing::cSystem_85vOkNK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_s246qvul_sendMessage);
}

void Heavy_PhaseRing::cDelay_ONwFLmuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ONwFLmuw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pf2EBUvy, 0, m, &cDelay_pf2EBUvy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ONwFLmuw, 0, m, &cDelay_ONwFLmuw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sgXiCgJ0, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_pf2EBUvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pf2EBUvy, m);
  cMsg_9EsOLYPV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_nTO1PQAw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_MlisEu1Q_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_yDOrQ6NO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IzE9jKDh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_grQHM5HS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZArrdQyK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ONwFLmuw, 2, m, &cDelay_ONwFLmuw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qfvXZrYy_sendMessage);
}

void Heavy_PhaseRing::cMsg_IzE9jKDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_grQHM5HS, 0, m, &hTable_grQHM5HS_sendMessage);
}

void Heavy_PhaseRing::cBinop_s246qvul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_yDOrQ6NO_sendMessage);
}

void Heavy_PhaseRing::cMsg_9EsOLYPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_grQHM5HS, 0, m, &hTable_grQHM5HS_sendMessage);
}

void Heavy_PhaseRing::cCast_qfvXZrYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ONwFLmuw, 0, m, &cDelay_ONwFLmuw_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZArrdQyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_pf2EBUvy, 2, m, &cDelay_pf2EBUvy_sendMessage);
}

void Heavy_PhaseRing::cMsg_MlisEu1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sgXiCgJ0, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_HFG71gw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XJC2Lnas, HV_BINOP_SUBTRACT, 0, m, &cBinop_XJC2Lnas_sendMessage);
}

void Heavy_PhaseRing::cMsg_k1tZpdkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ePdJmCKp_sendMessage);
}

void Heavy_PhaseRing::cSystem_ePdJmCKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RqHPfGRi_sendMessage);
}

void Heavy_PhaseRing::cVar_CmYwz2BP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qnWwin29_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_kt0uOeEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kt0uOeEr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xxp2hxM8, 0, m, &cDelay_Xxp2hxM8_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aUfhIf8I, 0, m, &sTabread_aUfhIf8I_sendMessage);
}

void Heavy_PhaseRing::cDelay_Xxp2hxM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Xxp2hxM8, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aUfhIf8I, 0, m, &sTabread_aUfhIf8I_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xxp2hxM8, 0, m, &cDelay_Xxp2hxM8_sendMessage);
}

void Heavy_PhaseRing::sTabread_aUfhIf8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6WnJt3pK, HV_BINOP_SUBTRACT, 0, m, &cBinop_6WnJt3pK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_A3uS268K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y0VVIrYP, HV_BINOP_MAX, 0, m, &cBinop_y0VVIrYP_sendMessage);
}

void Heavy_PhaseRing::cBinop_RqHPfGRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A3uS268K, HV_BINOP_MULTIPLY, 0, m, &cBinop_A3uS268K_sendMessage);
}

void Heavy_PhaseRing::cBinop_XJC2Lnas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MyG28YZM_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aUfhIf8I, 0, m, &sTabread_aUfhIf8I_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q8gvSG8l_sendMessage);
}

void Heavy_PhaseRing::cSystem_azJPQKoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6WnJt3pK, HV_BINOP_SUBTRACT, 1, m, &cBinop_6WnJt3pK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xxp2hxM8, 2, m, &cDelay_Xxp2hxM8_sendMessage);
}

void Heavy_PhaseRing::cMsg_qnWwin29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_azJPQKoZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_MyG28YZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kt0uOeEr, 0, m, &cDelay_kt0uOeEr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xxp2hxM8, 0, m, &cDelay_Xxp2hxM8_sendMessage);
}

void Heavy_PhaseRing::cMsg_zv0jKid7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_y0VVIrYP, HV_BINOP_MAX, 1, m, &cBinop_y0VVIrYP_sendMessage);
}

void Heavy_PhaseRing::cBinop_y0VVIrYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XJC2Lnas, HV_BINOP_SUBTRACT, 1, m, &cBinop_XJC2Lnas_sendMessage);
}

void Heavy_PhaseRing::cCast_q8gvSG8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kt0uOeEr, 0, m, &cDelay_kt0uOeEr_sendMessage);
}

void Heavy_PhaseRing::cBinop_zsdH3Tpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kt0uOeEr, 2, m, &cDelay_kt0uOeEr_sendMessage);
}

void Heavy_PhaseRing::cBinop_6WnJt3pK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zsdH3Tpc_sendMessage);
}

void Heavy_PhaseRing::cCast_HmKdlv5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CmYwz2BP, 0, m, &cVar_CmYwz2BP_sendMessage);
  cMsg_k1tZpdkr_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HFG71gw9, 0, m, &cTabhead_HFG71gw9_sendMessage);
}

void Heavy_PhaseRing::cMsg_n87Udfuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DDPlKMLq_sendMessage);
}

void Heavy_PhaseRing::cSystem_DDPlKMLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7Bm2k380_sendMessage);
}

void Heavy_PhaseRing::cDelay_WQk8zHce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WQk8zHce, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6eY6tb2m, 0, m, &cDelay_6eY6tb2m_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WQk8zHce, 0, m, &cDelay_WQk8zHce_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4ygwkJN6, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_6eY6tb2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6eY6tb2m, m);
  cMsg_tumnrikj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_CG12JPER_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_c4KQhmye_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_BA4i3mE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lokSCnbn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_IKDHvxMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zEgjuPSG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WQk8zHce, 2, m, &cDelay_WQk8zHce_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4bMqfauH_sendMessage);
}

void Heavy_PhaseRing::cMsg_lokSCnbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_IKDHvxMN, 0, m, &hTable_IKDHvxMN_sendMessage);
}

void Heavy_PhaseRing::cBinop_7Bm2k380_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_BA4i3mE1_sendMessage);
}

void Heavy_PhaseRing::cMsg_tumnrikj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_IKDHvxMN, 0, m, &hTable_IKDHvxMN_sendMessage);
}

void Heavy_PhaseRing::cCast_4bMqfauH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WQk8zHce, 0, m, &cDelay_WQk8zHce_sendMessage);
}

void Heavy_PhaseRing::cMsg_zEgjuPSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_6eY6tb2m, 2, m, &cDelay_6eY6tb2m_sendMessage);
}

void Heavy_PhaseRing::cMsg_c4KQhmye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4ygwkJN6, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_YcdN9ZMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0EIR5ggF, HV_BINOP_SUBTRACT, 0, m, &cBinop_0EIR5ggF_sendMessage);
}

void Heavy_PhaseRing::cMsg_FgaE7LJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zTnUmNmB_sendMessage);
}

void Heavy_PhaseRing::cSystem_zTnUmNmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DE64WSEb_sendMessage);
}

void Heavy_PhaseRing::cVar_dBpOBpDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BR6twhwp_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_mimp5Jwf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mimp5Jwf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8rHSrGun, 0, m, &cDelay_8rHSrGun_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cdVPKRuV, 0, m, &sTabread_cdVPKRuV_sendMessage);
}

void Heavy_PhaseRing::cDelay_8rHSrGun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8rHSrGun, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cdVPKRuV, 0, m, &sTabread_cdVPKRuV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8rHSrGun, 0, m, &cDelay_8rHSrGun_sendMessage);
}

void Heavy_PhaseRing::sTabread_cdVPKRuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nN3AvzZF, HV_BINOP_SUBTRACT, 0, m, &cBinop_nN3AvzZF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_cXmg0ciX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AggYFerR, HV_BINOP_MAX, 0, m, &cBinop_AggYFerR_sendMessage);
}

void Heavy_PhaseRing::cBinop_DE64WSEb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cXmg0ciX, HV_BINOP_MULTIPLY, 0, m, &cBinop_cXmg0ciX_sendMessage);
}

void Heavy_PhaseRing::cBinop_0EIR5ggF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rLKScvC0_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cdVPKRuV, 0, m, &sTabread_cdVPKRuV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DrZszygJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_qA2vqVO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nN3AvzZF, HV_BINOP_SUBTRACT, 1, m, &cBinop_nN3AvzZF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8rHSrGun, 2, m, &cDelay_8rHSrGun_sendMessage);
}

void Heavy_PhaseRing::cMsg_BR6twhwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qA2vqVO0_sendMessage);
}

void Heavy_PhaseRing::cMsg_rLKScvC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mimp5Jwf, 0, m, &cDelay_mimp5Jwf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8rHSrGun, 0, m, &cDelay_8rHSrGun_sendMessage);
}

void Heavy_PhaseRing::cMsg_lUIEYJKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_AggYFerR, HV_BINOP_MAX, 1, m, &cBinop_AggYFerR_sendMessage);
}

void Heavy_PhaseRing::cBinop_AggYFerR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0EIR5ggF, HV_BINOP_SUBTRACT, 1, m, &cBinop_0EIR5ggF_sendMessage);
}

void Heavy_PhaseRing::cCast_DrZszygJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mimp5Jwf, 0, m, &cDelay_mimp5Jwf_sendMessage);
}

void Heavy_PhaseRing::cBinop_NgXFyntA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mimp5Jwf, 2, m, &cDelay_mimp5Jwf_sendMessage);
}

void Heavy_PhaseRing::cBinop_nN3AvzZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NgXFyntA_sendMessage);
}

void Heavy_PhaseRing::cCast_AKRUcq08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dBpOBpDz, 0, m, &cVar_dBpOBpDz_sendMessage);
  cMsg_FgaE7LJ4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YcdN9ZMp, 0, m, &cTabhead_YcdN9ZMp_sendMessage);
}

void Heavy_PhaseRing::cMsg_1aS3CeKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0yYfrsVU_sendMessage);
}

void Heavy_PhaseRing::cSystem_0yYfrsVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_D3eJgfd5_sendMessage);
}

void Heavy_PhaseRing::cDelay_BCIpgQY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BCIpgQY7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2xcEdaQ9, 0, m, &cDelay_2xcEdaQ9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BCIpgQY7, 0, m, &cDelay_BCIpgQY7_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_W1KqlR5W, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_2xcEdaQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2xcEdaQ9, m);
  cMsg_Cgu8AoUJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_CxT39C2o_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_CYNWSrWK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_pjd3SIul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_syo8imqi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_lbIc8ogL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a9jojggn_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BCIpgQY7, 2, m, &cDelay_BCIpgQY7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5HDl6WYn_sendMessage);
}

void Heavy_PhaseRing::cMsg_syo8imqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_lbIc8ogL, 0, m, &hTable_lbIc8ogL_sendMessage);
}

void Heavy_PhaseRing::cBinop_D3eJgfd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_pjd3SIul_sendMessage);
}

void Heavy_PhaseRing::cMsg_Cgu8AoUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_lbIc8ogL, 0, m, &hTable_lbIc8ogL_sendMessage);
}

void Heavy_PhaseRing::cCast_5HDl6WYn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BCIpgQY7, 0, m, &cDelay_BCIpgQY7_sendMessage);
}

void Heavy_PhaseRing::cMsg_a9jojggn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2xcEdaQ9, 2, m, &cDelay_2xcEdaQ9_sendMessage);
}

void Heavy_PhaseRing::cMsg_CYNWSrWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_W1KqlR5W, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_iA56AgyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0lBc1EU, HV_BINOP_SUBTRACT, 0, m, &cBinop_R0lBc1EU_sendMessage);
}

void Heavy_PhaseRing::cMsg_KQMyeOHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KbMXJrkY_sendMessage);
}

void Heavy_PhaseRing::cSystem_KbMXJrkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_H6MIStca_sendMessage);
}

void Heavy_PhaseRing::cVar_pMisGsDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mBwkhwEr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_C3gJ3QA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_C3gJ3QA1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zsPNEZbS, 0, m, &cDelay_zsPNEZbS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0Af6xxwK, 0, m, &sTabread_0Af6xxwK_sendMessage);
}

void Heavy_PhaseRing::cDelay_zsPNEZbS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zsPNEZbS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0Af6xxwK, 0, m, &sTabread_0Af6xxwK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zsPNEZbS, 0, m, &cDelay_zsPNEZbS_sendMessage);
}

void Heavy_PhaseRing::sTabread_0Af6xxwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eHma0e2z, HV_BINOP_SUBTRACT, 0, m, &cBinop_eHma0e2z_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_w48yXRKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o8sjXksm, HV_BINOP_MAX, 0, m, &cBinop_o8sjXksm_sendMessage);
}

void Heavy_PhaseRing::cBinop_H6MIStca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w48yXRKm, HV_BINOP_MULTIPLY, 0, m, &cBinop_w48yXRKm_sendMessage);
}

void Heavy_PhaseRing::cBinop_R0lBc1EU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3jKx0dhp_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0Af6xxwK, 0, m, &sTabread_0Af6xxwK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kjWrOudu_sendMessage);
}

void Heavy_PhaseRing::cSystem_m4KQQb2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eHma0e2z, HV_BINOP_SUBTRACT, 1, m, &cBinop_eHma0e2z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zsPNEZbS, 2, m, &cDelay_zsPNEZbS_sendMessage);
}

void Heavy_PhaseRing::cMsg_mBwkhwEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m4KQQb2s_sendMessage);
}

void Heavy_PhaseRing::cMsg_3jKx0dhp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_C3gJ3QA1, 0, m, &cDelay_C3gJ3QA1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zsPNEZbS, 0, m, &cDelay_zsPNEZbS_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZxitS22J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_o8sjXksm, HV_BINOP_MAX, 1, m, &cBinop_o8sjXksm_sendMessage);
}

void Heavy_PhaseRing::cBinop_o8sjXksm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0lBc1EU, HV_BINOP_SUBTRACT, 1, m, &cBinop_R0lBc1EU_sendMessage);
}

void Heavy_PhaseRing::cCast_kjWrOudu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_C3gJ3QA1, 0, m, &cDelay_C3gJ3QA1_sendMessage);
}

void Heavy_PhaseRing::cBinop_XgTGE7EX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_C3gJ3QA1, 2, m, &cDelay_C3gJ3QA1_sendMessage);
}

void Heavy_PhaseRing::cBinop_eHma0e2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XgTGE7EX_sendMessage);
}

void Heavy_PhaseRing::cCast_Jw3mLzJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pMisGsDW, 0, m, &cVar_pMisGsDW_sendMessage);
  cMsg_KQMyeOHq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_iA56AgyJ, 0, m, &cTabhead_iA56AgyJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_lfJtzrSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GGmOu0RY_sendMessage);
}

void Heavy_PhaseRing::cSystem_GGmOu0RY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SLXglp8Y_sendMessage);
}

void Heavy_PhaseRing::cDelay_hQSh3Vip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hQSh3Vip, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zrn9HoHn, 0, m, &cDelay_zrn9HoHn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQSh3Vip, 0, m, &cDelay_hQSh3Vip_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6X3zPgzv, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_zrn9HoHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zrn9HoHn, m);
  cMsg_tDgnqS8m_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_AZ8Vd5aJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ix6yrX32_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_KWZeXOa4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7FDjhprR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_UI28wuy7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7zvPlMX3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQSh3Vip, 2, m, &cDelay_hQSh3Vip_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gidStLpp_sendMessage);
}

void Heavy_PhaseRing::cMsg_7FDjhprR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_UI28wuy7, 0, m, &hTable_UI28wuy7_sendMessage);
}

void Heavy_PhaseRing::cBinop_SLXglp8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_KWZeXOa4_sendMessage);
}

void Heavy_PhaseRing::cMsg_tDgnqS8m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_UI28wuy7, 0, m, &hTable_UI28wuy7_sendMessage);
}

void Heavy_PhaseRing::cCast_gidStLpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQSh3Vip, 0, m, &cDelay_hQSh3Vip_sendMessage);
}

void Heavy_PhaseRing::cMsg_7zvPlMX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_zrn9HoHn, 2, m, &cDelay_zrn9HoHn_sendMessage);
}

void Heavy_PhaseRing::cMsg_ix6yrX32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6X3zPgzv, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_rCqdHZP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vGrqpFbn, HV_BINOP_SUBTRACT, 0, m, &cBinop_vGrqpFbn_sendMessage);
}

void Heavy_PhaseRing::cMsg_5evGwmOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PN0RlJ1d_sendMessage);
}

void Heavy_PhaseRing::cSystem_PN0RlJ1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KINo0bcO_sendMessage);
}

void Heavy_PhaseRing::cVar_a5pMPZMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y91xp27Z_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_3GacL0nI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3GacL0nI, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5sIwgL3E, 0, m, &cDelay_5sIwgL3E_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AkqyJDpE, 0, m, &sTabread_AkqyJDpE_sendMessage);
}

void Heavy_PhaseRing::cDelay_5sIwgL3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5sIwgL3E, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AkqyJDpE, 0, m, &sTabread_AkqyJDpE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5sIwgL3E, 0, m, &cDelay_5sIwgL3E_sendMessage);
}

void Heavy_PhaseRing::sTabread_AkqyJDpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_C6ZLwXkw, HV_BINOP_SUBTRACT, 0, m, &cBinop_C6ZLwXkw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_GQZfs91s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eXQ9yv6D, HV_BINOP_MAX, 0, m, &cBinop_eXQ9yv6D_sendMessage);
}

void Heavy_PhaseRing::cBinop_KINo0bcO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GQZfs91s, HV_BINOP_MULTIPLY, 0, m, &cBinop_GQZfs91s_sendMessage);
}

void Heavy_PhaseRing::cBinop_vGrqpFbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4nzj4tbH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AkqyJDpE, 0, m, &sTabread_AkqyJDpE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2c9gAmEe_sendMessage);
}

void Heavy_PhaseRing::cSystem_fwDXR6Nm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C6ZLwXkw, HV_BINOP_SUBTRACT, 1, m, &cBinop_C6ZLwXkw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5sIwgL3E, 2, m, &cDelay_5sIwgL3E_sendMessage);
}

void Heavy_PhaseRing::cMsg_y91xp27Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fwDXR6Nm_sendMessage);
}

void Heavy_PhaseRing::cMsg_4nzj4tbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3GacL0nI, 0, m, &cDelay_3GacL0nI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5sIwgL3E, 0, m, &cDelay_5sIwgL3E_sendMessage);
}

void Heavy_PhaseRing::cMsg_fI0Vg8O0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eXQ9yv6D, HV_BINOP_MAX, 1, m, &cBinop_eXQ9yv6D_sendMessage);
}

void Heavy_PhaseRing::cBinop_eXQ9yv6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vGrqpFbn, HV_BINOP_SUBTRACT, 1, m, &cBinop_vGrqpFbn_sendMessage);
}

void Heavy_PhaseRing::cCast_2c9gAmEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3GacL0nI, 0, m, &cDelay_3GacL0nI_sendMessage);
}

void Heavy_PhaseRing::cBinop_b7xpEMIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3GacL0nI, 2, m, &cDelay_3GacL0nI_sendMessage);
}

void Heavy_PhaseRing::cBinop_C6ZLwXkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_b7xpEMIH_sendMessage);
}

void Heavy_PhaseRing::cCast_gnR3cIHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a5pMPZMC, 0, m, &cVar_a5pMPZMC_sendMessage);
  cMsg_5evGwmOa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_rCqdHZP6, 0, m, &cTabhead_rCqdHZP6_sendMessage);
}

void Heavy_PhaseRing::cMsg_6mQ1y0a0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2BrP1HBV_sendMessage);
}

void Heavy_PhaseRing::cSystem_2BrP1HBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4Gsq0ros_sendMessage);
}

void Heavy_PhaseRing::cDelay_ylMzCEGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ylMzCEGz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2e9tv64E, 0, m, &cDelay_2e9tv64E_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ylMzCEGz, 0, m, &cDelay_ylMzCEGz_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Wf3JLY5U, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_2e9tv64E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2e9tv64E, m);
  cMsg_yhmpB9iH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_gxC0rvbO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_UpDIRszh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_2DDbRjLs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5P3JXl99_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_HXWSxKDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iVZO8UIY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ylMzCEGz, 2, m, &cDelay_ylMzCEGz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KFKhlsBS_sendMessage);
}

void Heavy_PhaseRing::cMsg_5P3JXl99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_HXWSxKDU, 0, m, &hTable_HXWSxKDU_sendMessage);
}

void Heavy_PhaseRing::cBinop_4Gsq0ros_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_2DDbRjLs_sendMessage);
}

void Heavy_PhaseRing::cMsg_yhmpB9iH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_HXWSxKDU, 0, m, &hTable_HXWSxKDU_sendMessage);
}

void Heavy_PhaseRing::cCast_KFKhlsBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ylMzCEGz, 0, m, &cDelay_ylMzCEGz_sendMessage);
}

void Heavy_PhaseRing::cMsg_iVZO8UIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2e9tv64E, 2, m, &cDelay_2e9tv64E_sendMessage);
}

void Heavy_PhaseRing::cMsg_UpDIRszh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Wf3JLY5U, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_UE2NlU6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qs45NgZZ, 0, m, &cVar_Qs45NgZZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NirfK3pc, 0, m, &cVar_NirfK3pc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rYtsEwgf, 0, m, &cVar_rYtsEwgf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zzeqD4ps, 0, m, &cVar_zzeqD4ps_sendMessage);
}

void Heavy_PhaseRing::cVar_MQAzBCR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_zs9oiuvm_sendMessage);
}

void Heavy_PhaseRing::cPack_rHjiJj5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_YNdmCaIO, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_NirfK3pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IX3YMtwx, HV_BINOP_MULTIPLY, 0, m, &cBinop_IX3YMtwx_sendMessage);
}

void Heavy_PhaseRing::cMsg_NhKPh8YY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xvE6ts0u_sendMessage);
}

void Heavy_PhaseRing::cSystem_xvE6ts0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2XA1Ycjo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_IX3YMtwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_kjRRQCk3_sendMessage);
}

void Heavy_PhaseRing::cBinop_0pcjCi32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IX3YMtwx, HV_BINOP_MULTIPLY, 1, m, &cBinop_IX3YMtwx_sendMessage);
}

void Heavy_PhaseRing::cMsg_2XA1Ycjo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_0pcjCi32_sendMessage);
}

void Heavy_PhaseRing::cBinop_kjRRQCk3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_hYWqOYJi_sendMessage);
}

void Heavy_PhaseRing::cBinop_hYWqOYJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iVANNd1z_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_XB0GKQXA, m);
}

void Heavy_PhaseRing::cBinop_iVANNd1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lcZ10pFH, m);
}

void Heavy_PhaseRing::cVar_rYtsEwgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NlA40NGJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_NlA40NGJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_4ouI2Z5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bBCcD3nV_sendMessage);
}

void Heavy_PhaseRing::cSystem_bBCcD3nV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CFfAkV7q_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_NlA40NGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_hrDMTUiZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_B1MgR2ZS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NlA40NGJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_NlA40NGJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_CFfAkV7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_B1MgR2ZS_sendMessage);
}

void Heavy_PhaseRing::cBinop_hrDMTUiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_YWlwFh1e_sendMessage);
}

void Heavy_PhaseRing::cBinop_YWlwFh1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_D6fYS4bx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gqGJq891, m);
}

void Heavy_PhaseRing::cBinop_D6fYS4bx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZmSFKFZ5, m);
}

void Heavy_PhaseRing::cVar_zzeqD4ps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uwNV2JLB, HV_BINOP_MULTIPLY, 0, m, &cBinop_uwNV2JLB_sendMessage);
}

void Heavy_PhaseRing::cMsg_dukjTsqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TRV9401F_sendMessage);
}

void Heavy_PhaseRing::cSystem_TRV9401F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nlIEnusA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_uwNV2JLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_A1NnpfKh_sendMessage);
}

void Heavy_PhaseRing::cBinop_Iuw3JCph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uwNV2JLB, HV_BINOP_MULTIPLY, 1, m, &cBinop_uwNV2JLB_sendMessage);
}

void Heavy_PhaseRing::cMsg_nlIEnusA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Iuw3JCph_sendMessage);
}

void Heavy_PhaseRing::cBinop_A1NnpfKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_w6rN5x9l_sendMessage);
}

void Heavy_PhaseRing::cBinop_w6rN5x9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tHwCPQ6Q_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5nWro7Fk, m);
}

void Heavy_PhaseRing::cBinop_tHwCPQ6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_P0qK0Zi0, m);
}

void Heavy_PhaseRing::cBinop_6PwnkgLC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wvfA3FwO, 0, m, &cPack_wvfA3FwO_sendMessage);
}

void Heavy_PhaseRing::cMsg_QmlllzNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_UE2NlU6a, 0, m, &cVar_UE2NlU6a_sendMessage);
}

void Heavy_PhaseRing::cBinop_zs9oiuvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rHjiJj5d, 0, m, &cPack_rHjiJj5d_sendMessage);
}

void Heavy_PhaseRing::cBinop_Qou9eTIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5cGHpwXI, 0, m, &cPack_5cGHpwXI_sendMessage);
}

void Heavy_PhaseRing::cIf_gmYGXyom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_t4a9x6WF_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_iJBmUReD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_iJBmUReD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_50R2YxMB_sendMessage);
}

void Heavy_PhaseRing::cCast_2BvmCnb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gmYGXyom, 0, m, &cIf_gmYGXyom_sendMessage);
}

void Heavy_PhaseRing::cCast_cahO5BIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_1pUnfKiJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_t4a9x6WF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_yVIvHqaq, 0, m, &cVar_yVIvHqaq_sendMessage);
}

void Heavy_PhaseRing::cBinop_50R2YxMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_QQAhucWI_sendMessage);
}

void Heavy_PhaseRing::cBinop_QQAhucWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UDwcQl3V_sendMessage);
}

void Heavy_PhaseRing::cBinop_UDwcQl3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yVIvHqaq, 0, m, &cVar_yVIvHqaq_sendMessage);
}

void Heavy_PhaseRing::cBinop_1pUnfKiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gmYGXyom, 1, m, &cIf_gmYGXyom_sendMessage);
}

void Heavy_PhaseRing::cBinop_zRyOPbJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cahO5BIb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2BvmCnb4_sendMessage);
}

void Heavy_PhaseRing::cBinop_MI77bjF1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zRyOPbJq_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_u6Eyb6Fe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ZyjfgBNE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ZyjfgBNE_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_UlTUgu0H, 1, m, &cDelay_UlTUgu0H_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VfpkBrOC_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_UlTUgu0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UlTUgu0H, m);
  cMsg_NLMmAgyv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ZyjfgBNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_UlTUgu0H, 0, m, &cDelay_UlTUgu0H_sendMessage);
}

void Heavy_PhaseRing::cCast_VfpkBrOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UlTUgu0H, 0, m, &cDelay_UlTUgu0H_sendMessage);
}

void Heavy_PhaseRing::cVar_ZDnAPNmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CXdjhTqE, 0, m, &cPack_CXdjhTqE_sendMessage);
}

void Heavy_PhaseRing::cVar_kE6ziXzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_eln6py60_sendMessage);
}

void Heavy_PhaseRing::cVar_ejzsZLNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_0YpTt0lg_sendMessage);
}

void Heavy_PhaseRing::cPack_KOAuQBbt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_fBjfcEse, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_jaEWTUot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_R7Ou5sdB_sendMessage);
}

void Heavy_PhaseRing::cBinop_YpsEwMYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_jaEWTUot_sendMessage);
}

void Heavy_PhaseRing::cPack_v6eDtMGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HroFg6Ql, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_gKxIEzVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_EjlXvk1O_sendMessage);
}

void Heavy_PhaseRing::cMsg_NQtYoQQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DkrMthVQ_sendMessage);
}

void Heavy_PhaseRing::cSystem_DkrMthVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_n0hq8QRM_sendMessage);
}

void Heavy_PhaseRing::cDelay_XvSJZbCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XvSJZbCX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AljaQDRL, 0, m, &cDelay_AljaQDRL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XvSJZbCX, 0, m, &cDelay_XvSJZbCX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fUUiNl5n, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_AljaQDRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AljaQDRL, m);
  cMsg_viIJseIg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_760jXBO3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_qyZlzeEI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_F73txgUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h6fknkWP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_vyXqPpGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BQVXskGC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XvSJZbCX, 2, m, &cDelay_XvSJZbCX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tixQwhMR_sendMessage);
}

void Heavy_PhaseRing::cMsg_h6fknkWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vyXqPpGz, 0, m, &hTable_vyXqPpGz_sendMessage);
}

void Heavy_PhaseRing::cBinop_n0hq8QRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_F73txgUy_sendMessage);
}

void Heavy_PhaseRing::cMsg_viIJseIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vyXqPpGz, 0, m, &hTable_vyXqPpGz_sendMessage);
}

void Heavy_PhaseRing::cCast_tixQwhMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XvSJZbCX, 0, m, &cDelay_XvSJZbCX_sendMessage);
}

void Heavy_PhaseRing::cMsg_BQVXskGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_AljaQDRL, 2, m, &cDelay_AljaQDRL_sendMessage);
}

void Heavy_PhaseRing::cMsg_qyZlzeEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fUUiNl5n, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_lMPaacJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ua2NxW10_sendMessage);
}

void Heavy_PhaseRing::cSystem_Ua2NxW10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_f0LvgUkN_sendMessage);
}

void Heavy_PhaseRing::cVar_ow42iGtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KAbXdQ5L_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_l1fsoyfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SV0LWSNA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cboCLk4T, m);
}

void Heavy_PhaseRing::cBinop_f0LvgUkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zu0z7tLz, m);
}

void Heavy_PhaseRing::cMsg_KAbXdQ5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l1fsoyfE_sendMessage);
}

void Heavy_PhaseRing::cBinop_SV0LWSNA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4Sm3YqjO, m);
}

void Heavy_PhaseRing::cMsg_5SJF4OYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rZR77Cxu_sendMessage);
}

void Heavy_PhaseRing::cSystem_rZR77Cxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rucRwiCK_sendMessage);
}

void Heavy_PhaseRing::cVar_rYglaobA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DQu0lveg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_0YUPpRE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_jPjEz1nu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2sb2Pj7Z, m);
}

void Heavy_PhaseRing::cBinop_rucRwiCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mj8lvNqY, m);
}

void Heavy_PhaseRing::cMsg_DQu0lveg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0YUPpRE7_sendMessage);
}

void Heavy_PhaseRing::cBinop_jPjEz1nu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yIEpzLjm, m);
}

void Heavy_PhaseRing::cBinop_7Q7Ku0ck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aXkOKRZM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_mRgm9vrm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x6cM1soE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_edojlfXo_sendMessage);
}

void Heavy_PhaseRing::cCast_edojlfXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Q7Ku0ck, HV_BINOP_DIVIDE, 0, m, &cBinop_7Q7Ku0ck_sendMessage);
}

void Heavy_PhaseRing::cCast_x6cM1soE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Q7Ku0ck, HV_BINOP_DIVIDE, 1, m, &cBinop_7Q7Ku0ck_sendMessage);
}

void Heavy_PhaseRing::cBinop_R7Ou5sdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hmhzuYjD_sendMessage);
}

void Heavy_PhaseRing::cBinop_eln6py60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_YpsEwMYG_sendMessage);
}

void Heavy_PhaseRing::cBinop_hmhzuYjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Q7Ku0ck, HV_BINOP_DIVIDE, 0, m, &cBinop_7Q7Ku0ck_sendMessage);
}

void Heavy_PhaseRing::cBinop_EjlXvk1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_v6eDtMGb, 0, m, &cPack_v6eDtMGb_sendMessage);
}

void Heavy_PhaseRing::cBinop_0YpTt0lg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_mRgm9vrm_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_KOAuQBbt, 0, m, &cPack_KOAuQBbt_sendMessage);
}

void Heavy_PhaseRing::cMsg_46pHvWUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ejzsZLNQ, 0, m, &cVar_ejzsZLNQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_Pp0t5zJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_gKxIEzVQ, 0, m, &cVar_gKxIEzVQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_aXkOKRZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mzxCLgbx, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_vNB7vmoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wUdEchLk, HV_BINOP_MULTIPLY, 0, m, &cBinop_wUdEchLk_sendMessage);
}

void Heavy_PhaseRing::cMsg_bfFhZbUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tttkfWss_sendMessage);
}

void Heavy_PhaseRing::cSystem_tttkfWss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EqAhyjVu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_wUdEchLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_SKQQIvwa_sendMessage);
}

void Heavy_PhaseRing::cBinop_XjmMCOfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wUdEchLk, HV_BINOP_MULTIPLY, 1, m, &cBinop_wUdEchLk_sendMessage);
}

void Heavy_PhaseRing::cMsg_EqAhyjVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XjmMCOfp_sendMessage);
}

void Heavy_PhaseRing::cBinop_SKQQIvwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xQXjkmT7_sendMessage);
}

void Heavy_PhaseRing::cBinop_xQXjkmT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5uewpFrL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rv5Wyvjj, m);
}

void Heavy_PhaseRing::cBinop_5uewpFrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wezXNcbi, m);
}

void Heavy_PhaseRing::cVar_mh8knXVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gYuJGpxM, HV_BINOP_MULTIPLY, 0, m, &cBinop_gYuJGpxM_sendMessage);
}

void Heavy_PhaseRing::cMsg_th8tuY18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pQZEvZiu_sendMessage);
}

void Heavy_PhaseRing::cSystem_pQZEvZiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8kKbpmy3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_gYuJGpxM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_69d4tnfH_sendMessage);
}

void Heavy_PhaseRing::cBinop_VPXyAya7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gYuJGpxM, HV_BINOP_MULTIPLY, 1, m, &cBinop_gYuJGpxM_sendMessage);
}

void Heavy_PhaseRing::cMsg_8kKbpmy3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VPXyAya7_sendMessage);
}

void Heavy_PhaseRing::cBinop_69d4tnfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CJ5QIlCD_sendMessage);
}

void Heavy_PhaseRing::cBinop_CJ5QIlCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Vo7QAQvv_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_K7ZJidyG, m);
}

void Heavy_PhaseRing::cBinop_Vo7QAQvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6qSZ1emO, m);
}

void Heavy_PhaseRing::cVar_DOdxgB2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nBj79MUE, HV_BINOP_MULTIPLY, 0, m, &cBinop_nBj79MUE_sendMessage);
}

void Heavy_PhaseRing::cMsg_wGubX8K4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_o0yiXxmX_sendMessage);
}

void Heavy_PhaseRing::cSystem_o0yiXxmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L6Cr1Tez_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_nBj79MUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_p13mriec_sendMessage);
}

void Heavy_PhaseRing::cBinop_G6hPIL3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nBj79MUE, HV_BINOP_MULTIPLY, 1, m, &cBinop_nBj79MUE_sendMessage);
}

void Heavy_PhaseRing::cMsg_L6Cr1Tez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_G6hPIL3y_sendMessage);
}

void Heavy_PhaseRing::cBinop_p13mriec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_c62MuWUo_sendMessage);
}

void Heavy_PhaseRing::cBinop_c62MuWUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_1oMhluBP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_aKn3TGo8, m);
}

void Heavy_PhaseRing::cBinop_1oMhluBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_64AiehE0, m);
}

void Heavy_PhaseRing::cMsg_NxEUb1oB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BLJ8xx64_sendMessage);
}

void Heavy_PhaseRing::cSystem_BLJ8xx64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eBfdRzXs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_rHdiT0C4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_Xsg3VmMx_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_f88IriLp, 0, m, &cIf_f88IriLp_sendMessage);
}

void Heavy_PhaseRing::cIf_f88IriLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_pciP60KT_sendMessage(_c, 0, m);
      cMsg_CfTOkOKU_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_J7N26H92_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_gvdygPzR_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_BLcMibJp, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Xsg3VmMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f88IriLp, 1, m, &cIf_f88IriLp_sendMessage);
}

void Heavy_PhaseRing::cMsg_J7N26H92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Y1YvHWPS_sendMessage);
}

void Heavy_PhaseRing::cBinop_Y1YvHWPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_H69Y9moT, m);
}

void Heavy_PhaseRing::cBinop_gvdygPzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ejiXCZZx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ejiXCZZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DnZwv9YS_sendMessage);
}

void Heavy_PhaseRing::cBinop_DnZwv9YS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NfGzJFA2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_NfGzJFA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_pXyS5z9B_sendMessage);
}

void Heavy_PhaseRing::cBinop_pXyS5z9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_k8WWzsdp, m);
}

void Heavy_PhaseRing::cBinop_v7GiubIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gjVVJfE2, m);
}

void Heavy_PhaseRing::cMsg_eBfdRzXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_v7GiubIy_sendMessage);
}

void Heavy_PhaseRing::cMsg_pciP60KT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_gvdygPzR_sendMessage);
}

void Heavy_PhaseRing::cMsg_CfTOkOKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_H69Y9moT, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BLcMibJp, m);
}

void Heavy_PhaseRing::cBinop_nnwDsQfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mh8knXVY, 0, m, &cVar_mh8knXVY_sendMessage);
}

void Heavy_PhaseRing::cBinop_3v22MwaP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vNB7vmoA, 0, m, &cVar_vNB7vmoA_sendMessage);
}

void Heavy_PhaseRing::cBinop_NORxZ3gQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DOdxgB2j, 0, m, &cVar_DOdxgB2j_sendMessage);
}

void Heavy_PhaseRing::cCast_dFNKNzxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_3v22MwaP_sendMessage);
}

void Heavy_PhaseRing::cCast_aj7aBI83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_A7QOGCN7, m);
}

void Heavy_PhaseRing::cCast_b63VgeDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_NORxZ3gQ_sendMessage);
}

void Heavy_PhaseRing::cCast_dNLXYx0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_nnwDsQfP_sendMessage);
}

void Heavy_PhaseRing::cTabhead_w0qwgau0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V83Cm21H, HV_BINOP_SUBTRACT, 0, m, &cBinop_V83Cm21H_sendMessage);
}

void Heavy_PhaseRing::cMsg_IPYyDhov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_crSl6dVb_sendMessage);
}

void Heavy_PhaseRing::cSystem_crSl6dVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mVqnH88V_sendMessage);
}

void Heavy_PhaseRing::cVar_WKqWlziK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G9zqwwLs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_u4iJSCNy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_u4iJSCNy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gzgXR07b, 0, m, &cDelay_gzgXR07b_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_N1KtBq9B, 0, m, &sTabread_N1KtBq9B_sendMessage);
}

void Heavy_PhaseRing::cDelay_gzgXR07b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gzgXR07b, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_N1KtBq9B, 0, m, &sTabread_N1KtBq9B_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gzgXR07b, 0, m, &cDelay_gzgXR07b_sendMessage);
}

void Heavy_PhaseRing::sTabread_N1KtBq9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yQvCdi0Y, HV_BINOP_SUBTRACT, 0, m, &cBinop_yQvCdi0Y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_HLgsX0Xo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0AyTeWOz, HV_BINOP_MAX, 0, m, &cBinop_0AyTeWOz_sendMessage);
}

void Heavy_PhaseRing::cBinop_mVqnH88V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HLgsX0Xo, HV_BINOP_MULTIPLY, 0, m, &cBinop_HLgsX0Xo_sendMessage);
}

void Heavy_PhaseRing::cBinop_V83Cm21H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZfsGuSel_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_N1KtBq9B, 0, m, &sTabread_N1KtBq9B_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RqAoHjsy_sendMessage);
}

void Heavy_PhaseRing::cSystem_Bv3FWLGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQvCdi0Y, HV_BINOP_SUBTRACT, 1, m, &cBinop_yQvCdi0Y_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gzgXR07b, 2, m, &cDelay_gzgXR07b_sendMessage);
}

void Heavy_PhaseRing::cMsg_G9zqwwLs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Bv3FWLGN_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZfsGuSel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_u4iJSCNy, 0, m, &cDelay_u4iJSCNy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gzgXR07b, 0, m, &cDelay_gzgXR07b_sendMessage);
}

void Heavy_PhaseRing::cMsg_EurgfTWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_0AyTeWOz, HV_BINOP_MAX, 1, m, &cBinop_0AyTeWOz_sendMessage);
}

void Heavy_PhaseRing::cBinop_0AyTeWOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V83Cm21H, HV_BINOP_SUBTRACT, 1, m, &cBinop_V83Cm21H_sendMessage);
}

void Heavy_PhaseRing::cCast_RqAoHjsy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_u4iJSCNy, 0, m, &cDelay_u4iJSCNy_sendMessage);
}

void Heavy_PhaseRing::cBinop_Nq4x9EvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_u4iJSCNy, 2, m, &cDelay_u4iJSCNy_sendMessage);
}

void Heavy_PhaseRing::cBinop_yQvCdi0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Nq4x9EvT_sendMessage);
}

void Heavy_PhaseRing::cCast_hZ5LIkbP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WKqWlziK, 0, m, &cVar_WKqWlziK_sendMessage);
  cMsg_IPYyDhov_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_w0qwgau0, 0, m, &cTabhead_w0qwgau0_sendMessage);
}

void Heavy_PhaseRing::cTabhead_v2DPnjXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KOyryfGV, HV_BINOP_SUBTRACT, 0, m, &cBinop_KOyryfGV_sendMessage);
}

void Heavy_PhaseRing::cMsg_6uN0vTuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9WzbCcjL_sendMessage);
}

void Heavy_PhaseRing::cSystem_9WzbCcjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tC8xwfSJ_sendMessage);
}

void Heavy_PhaseRing::cVar_BxVdRu3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xjErizMO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_UayTqgsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UayTqgsP, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1l94TooO, 0, m, &cDelay_1l94TooO_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TizZqi4E, 0, m, &sTabread_TizZqi4E_sendMessage);
}

void Heavy_PhaseRing::cDelay_1l94TooO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1l94TooO, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TizZqi4E, 0, m, &sTabread_TizZqi4E_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1l94TooO, 0, m, &cDelay_1l94TooO_sendMessage);
}

void Heavy_PhaseRing::sTabread_TizZqi4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DC0GiVjm, HV_BINOP_SUBTRACT, 0, m, &cBinop_DC0GiVjm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_yxpv0vF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cvGtM9oa, HV_BINOP_MAX, 0, m, &cBinop_cvGtM9oa_sendMessage);
}

void Heavy_PhaseRing::cBinop_tC8xwfSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yxpv0vF6, HV_BINOP_MULTIPLY, 0, m, &cBinop_yxpv0vF6_sendMessage);
}

void Heavy_PhaseRing::cBinop_KOyryfGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pw9F9ol2_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TizZqi4E, 0, m, &sTabread_TizZqi4E_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u9VSn8J3_sendMessage);
}

void Heavy_PhaseRing::cSystem_tYSR6Tby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DC0GiVjm, HV_BINOP_SUBTRACT, 1, m, &cBinop_DC0GiVjm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1l94TooO, 2, m, &cDelay_1l94TooO_sendMessage);
}

void Heavy_PhaseRing::cMsg_xjErizMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tYSR6Tby_sendMessage);
}

void Heavy_PhaseRing::cMsg_pw9F9ol2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_UayTqgsP, 0, m, &cDelay_UayTqgsP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1l94TooO, 0, m, &cDelay_1l94TooO_sendMessage);
}

void Heavy_PhaseRing::cMsg_5hj9ow23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cvGtM9oa, HV_BINOP_MAX, 1, m, &cBinop_cvGtM9oa_sendMessage);
}

void Heavy_PhaseRing::cBinop_cvGtM9oa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KOyryfGV, HV_BINOP_SUBTRACT, 1, m, &cBinop_KOyryfGV_sendMessage);
}

void Heavy_PhaseRing::cCast_u9VSn8J3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UayTqgsP, 0, m, &cDelay_UayTqgsP_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZXfcfz7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UayTqgsP, 2, m, &cDelay_UayTqgsP_sendMessage);
}

void Heavy_PhaseRing::cBinop_DC0GiVjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZXfcfz7H_sendMessage);
}

void Heavy_PhaseRing::cCast_xpl7zpHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BxVdRu3f, 0, m, &cVar_BxVdRu3f_sendMessage);
  cMsg_6uN0vTuE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_v2DPnjXn, 0, m, &cTabhead_v2DPnjXn_sendMessage);
}

void Heavy_PhaseRing::cTabhead_psRGDwv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YTnZ0jcR, HV_BINOP_SUBTRACT, 0, m, &cBinop_YTnZ0jcR_sendMessage);
}

void Heavy_PhaseRing::cMsg_5lshIHzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KsC1frQL_sendMessage);
}

void Heavy_PhaseRing::cSystem_KsC1frQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yGNOVzIy_sendMessage);
}

void Heavy_PhaseRing::cVar_ech2kDFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yru6h7Kn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_rvGNcrzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rvGNcrzs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kXQoQaRk, 0, m, &cDelay_kXQoQaRk_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hHyAglfJ, 0, m, &sTabread_hHyAglfJ_sendMessage);
}

void Heavy_PhaseRing::cDelay_kXQoQaRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kXQoQaRk, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hHyAglfJ, 0, m, &sTabread_hHyAglfJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kXQoQaRk, 0, m, &cDelay_kXQoQaRk_sendMessage);
}

void Heavy_PhaseRing::sTabread_hHyAglfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_FUw5O85B, HV_BINOP_SUBTRACT, 0, m, &cBinop_FUw5O85B_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ig7BVmNT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M3ISVrmj, HV_BINOP_MAX, 0, m, &cBinop_M3ISVrmj_sendMessage);
}

void Heavy_PhaseRing::cBinop_yGNOVzIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ig7BVmNT, HV_BINOP_MULTIPLY, 0, m, &cBinop_ig7BVmNT_sendMessage);
}

void Heavy_PhaseRing::cBinop_YTnZ0jcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hxZ4L9tg_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hHyAglfJ, 0, m, &sTabread_hHyAglfJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V3hrqwle_sendMessage);
}

void Heavy_PhaseRing::cSystem_nLOZupSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FUw5O85B, HV_BINOP_SUBTRACT, 1, m, &cBinop_FUw5O85B_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kXQoQaRk, 2, m, &cDelay_kXQoQaRk_sendMessage);
}

void Heavy_PhaseRing::cMsg_yru6h7Kn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nLOZupSX_sendMessage);
}

void Heavy_PhaseRing::cMsg_hxZ4L9tg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rvGNcrzs, 0, m, &cDelay_rvGNcrzs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kXQoQaRk, 0, m, &cDelay_kXQoQaRk_sendMessage);
}

void Heavy_PhaseRing::cMsg_ctgUHMP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_M3ISVrmj, HV_BINOP_MAX, 1, m, &cBinop_M3ISVrmj_sendMessage);
}

void Heavy_PhaseRing::cBinop_M3ISVrmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YTnZ0jcR, HV_BINOP_SUBTRACT, 1, m, &cBinop_YTnZ0jcR_sendMessage);
}

void Heavy_PhaseRing::cCast_V3hrqwle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rvGNcrzs, 0, m, &cDelay_rvGNcrzs_sendMessage);
}

void Heavy_PhaseRing::cBinop_pqGRp9Ce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rvGNcrzs, 2, m, &cDelay_rvGNcrzs_sendMessage);
}

void Heavy_PhaseRing::cBinop_FUw5O85B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pqGRp9Ce_sendMessage);
}

void Heavy_PhaseRing::cCast_hHBNGLcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ech2kDFp, 0, m, &cVar_ech2kDFp_sendMessage);
  cMsg_5lshIHzG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_psRGDwv1, 0, m, &cTabhead_psRGDwv1_sendMessage);
}

void Heavy_PhaseRing::cTabhead_hE32Qk0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5nZZ5lub, HV_BINOP_SUBTRACT, 0, m, &cBinop_5nZZ5lub_sendMessage);
}

void Heavy_PhaseRing::cMsg_PHpljHvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sn8ho6Y4_sendMessage);
}

void Heavy_PhaseRing::cSystem_sn8ho6Y4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SxHawflw_sendMessage);
}

void Heavy_PhaseRing::cVar_8h7MhJNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9O3fpv46_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_Op72lj8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Op72lj8X, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LTwnqIST, 0, m, &cDelay_LTwnqIST_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ChyqmDJ7, 0, m, &sTabread_ChyqmDJ7_sendMessage);
}

void Heavy_PhaseRing::cDelay_LTwnqIST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LTwnqIST, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ChyqmDJ7, 0, m, &sTabread_ChyqmDJ7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LTwnqIST, 0, m, &cDelay_LTwnqIST_sendMessage);
}

void Heavy_PhaseRing::sTabread_ChyqmDJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NyQgrCrw, HV_BINOP_SUBTRACT, 0, m, &cBinop_NyQgrCrw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_DT3KbUSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eDviFlSn, HV_BINOP_MAX, 0, m, &cBinop_eDviFlSn_sendMessage);
}

void Heavy_PhaseRing::cBinop_SxHawflw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DT3KbUSJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_DT3KbUSJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_5nZZ5lub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RwU1iHsr_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ChyqmDJ7, 0, m, &sTabread_ChyqmDJ7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fkOFtIqG_sendMessage);
}

void Heavy_PhaseRing::cSystem_DGEFO6ni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NyQgrCrw, HV_BINOP_SUBTRACT, 1, m, &cBinop_NyQgrCrw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LTwnqIST, 2, m, &cDelay_LTwnqIST_sendMessage);
}

void Heavy_PhaseRing::cMsg_9O3fpv46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DGEFO6ni_sendMessage);
}

void Heavy_PhaseRing::cMsg_RwU1iHsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Op72lj8X, 0, m, &cDelay_Op72lj8X_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LTwnqIST, 0, m, &cDelay_LTwnqIST_sendMessage);
}

void Heavy_PhaseRing::cMsg_TKrqyhqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eDviFlSn, HV_BINOP_MAX, 1, m, &cBinop_eDviFlSn_sendMessage);
}

void Heavy_PhaseRing::cBinop_eDviFlSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5nZZ5lub, HV_BINOP_SUBTRACT, 1, m, &cBinop_5nZZ5lub_sendMessage);
}

void Heavy_PhaseRing::cCast_fkOFtIqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Op72lj8X, 0, m, &cDelay_Op72lj8X_sendMessage);
}

void Heavy_PhaseRing::cBinop_aNGIL58D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Op72lj8X, 2, m, &cDelay_Op72lj8X_sendMessage);
}

void Heavy_PhaseRing::cBinop_NyQgrCrw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aNGIL58D_sendMessage);
}

void Heavy_PhaseRing::cCast_9JHegaPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8h7MhJNv, 0, m, &cVar_8h7MhJNv_sendMessage);
  cMsg_PHpljHvd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_hE32Qk0j, 0, m, &cTabhead_hE32Qk0j_sendMessage);
}

void Heavy_PhaseRing::cMsg_8vbWoyUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uLjDBLLG_sendMessage);
}

void Heavy_PhaseRing::cSystem_uLjDBLLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gayaPwBE_sendMessage);
}

void Heavy_PhaseRing::cDelay_RCf3k0Po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RCf3k0Po, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_t6lKluSY, 0, m, &cDelay_t6lKluSY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RCf3k0Po, 0, m, &cDelay_RCf3k0Po_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_j0ichkzQ, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_t6lKluSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_t6lKluSY, m);
  cMsg_2wkaQGy8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_GmMgqgLN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_XzghOBpL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_APXnsXg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HvcSsmT4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_K1aScmmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_noWxYRwe_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RCf3k0Po, 2, m, &cDelay_RCf3k0Po_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wo1oZtaw_sendMessage);
}

void Heavy_PhaseRing::cMsg_HvcSsmT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_K1aScmmi, 0, m, &hTable_K1aScmmi_sendMessage);
}

void Heavy_PhaseRing::cBinop_gayaPwBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_APXnsXg1_sendMessage);
}

void Heavy_PhaseRing::cMsg_2wkaQGy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_K1aScmmi, 0, m, &hTable_K1aScmmi_sendMessage);
}

void Heavy_PhaseRing::cCast_wo1oZtaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RCf3k0Po, 0, m, &cDelay_RCf3k0Po_sendMessage);
}

void Heavy_PhaseRing::cMsg_noWxYRwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_t6lKluSY, 2, m, &cDelay_t6lKluSY_sendMessage);
}

void Heavy_PhaseRing::cMsg_XzghOBpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_j0ichkzQ, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_5hJVKyFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GJNovxx3_sendMessage);
}

void Heavy_PhaseRing::cSystem_GJNovxx3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Emy9JCRO_sendMessage);
}

void Heavy_PhaseRing::cDelay_fhzaUiLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fhzaUiLT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OhqVnn5g, 0, m, &cDelay_OhqVnn5g_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fhzaUiLT, 0, m, &cDelay_fhzaUiLT_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_g8tuq0tx, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_OhqVnn5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OhqVnn5g, m);
  cMsg_gBJCrJ9x_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Gvh4qQBe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3QbbY0nc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_p9DjDJGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9WZJemvt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_3LkNluZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HPK6HQAK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fhzaUiLT, 2, m, &cDelay_fhzaUiLT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_52WP04nj_sendMessage);
}

void Heavy_PhaseRing::cMsg_9WZJemvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3LkNluZU, 0, m, &hTable_3LkNluZU_sendMessage);
}

void Heavy_PhaseRing::cBinop_Emy9JCRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_p9DjDJGm_sendMessage);
}

void Heavy_PhaseRing::cMsg_gBJCrJ9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3LkNluZU, 0, m, &hTable_3LkNluZU_sendMessage);
}

void Heavy_PhaseRing::cCast_52WP04nj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fhzaUiLT, 0, m, &cDelay_fhzaUiLT_sendMessage);
}

void Heavy_PhaseRing::cMsg_HPK6HQAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OhqVnn5g, 2, m, &cDelay_OhqVnn5g_sendMessage);
}

void Heavy_PhaseRing::cMsg_3QbbY0nc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_g8tuq0tx, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_jt0q6uDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BgR3wwCq_sendMessage);
}

void Heavy_PhaseRing::cSystem_BgR3wwCq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_s1uqs1vx_sendMessage);
}

void Heavy_PhaseRing::cDelay_QGILnq4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QGILnq4B, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PTyN58bV, 0, m, &cDelay_PTyN58bV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QGILnq4B, 0, m, &cDelay_QGILnq4B_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zK6oCu99, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_PTyN58bV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PTyN58bV, m);
  cMsg_k5GHPR6F_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Pbu1jrc7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_lJpVOQ0d_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_GY8JwXAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H6HC7kqm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_DTDd40da_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fgZ7WL1S_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QGILnq4B, 2, m, &cDelay_QGILnq4B_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hVWu0G5I_sendMessage);
}

void Heavy_PhaseRing::cMsg_H6HC7kqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_DTDd40da, 0, m, &hTable_DTDd40da_sendMessage);
}

void Heavy_PhaseRing::cBinop_s1uqs1vx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_GY8JwXAw_sendMessage);
}

void Heavy_PhaseRing::cMsg_k5GHPR6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_DTDd40da, 0, m, &hTable_DTDd40da_sendMessage);
}

void Heavy_PhaseRing::cCast_hVWu0G5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QGILnq4B, 0, m, &cDelay_QGILnq4B_sendMessage);
}

void Heavy_PhaseRing::cMsg_fgZ7WL1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_PTyN58bV, 2, m, &cDelay_PTyN58bV_sendMessage);
}

void Heavy_PhaseRing::cMsg_lJpVOQ0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zK6oCu99, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_Y8aveTze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_j0LAsYGK_sendMessage);
}

void Heavy_PhaseRing::cSystem_j0LAsYGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_snqiRVKu_sendMessage);
}

void Heavy_PhaseRing::cDelay_W4U4xDgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_W4U4xDgs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_18yDL5im, 0, m, &cDelay_18yDL5im_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_W4U4xDgs, 0, m, &cDelay_W4U4xDgs_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_y26wtbcY, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_18yDL5im_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_18yDL5im, m);
  cMsg_s8IcoIN5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_dgNJEapI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_c8LU9ogz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_72osRPPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VUoDOp4w_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_6XR14HlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O6TuDiNs_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_W4U4xDgs, 2, m, &cDelay_W4U4xDgs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D7mGxJgS_sendMessage);
}

void Heavy_PhaseRing::cMsg_VUoDOp4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6XR14HlF, 0, m, &hTable_6XR14HlF_sendMessage);
}

void Heavy_PhaseRing::cBinop_snqiRVKu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_72osRPPy_sendMessage);
}

void Heavy_PhaseRing::cMsg_s8IcoIN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6XR14HlF, 0, m, &hTable_6XR14HlF_sendMessage);
}

void Heavy_PhaseRing::cCast_D7mGxJgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_W4U4xDgs, 0, m, &cDelay_W4U4xDgs_sendMessage);
}

void Heavy_PhaseRing::cMsg_O6TuDiNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_18yDL5im, 2, m, &cDelay_18yDL5im_sendMessage);
}

void Heavy_PhaseRing::cMsg_c8LU9ogz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_y26wtbcY, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_G1CeFONS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_73qwTnAd_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_pagispRY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_KzPe2rDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5Jk5i6dF, HV_BINOP_POW, 0, m, &cBinop_5Jk5i6dF_sendMessage);
}

void Heavy_PhaseRing::cBinop_5Jk5i6dF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_mKyNCi3o_sendMessage);
}

void Heavy_PhaseRing::cBinop_YqruI7PW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_7zjInsBf_sendMessage);
}

void Heavy_PhaseRing::cCast_QVl2VRf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Vi12NBuZ_sendMessage);
}

void Heavy_PhaseRing::cCast_NvtZKlD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_G1CeFONS, 0, m, &cIf_G1CeFONS_sendMessage);
}

void Heavy_PhaseRing::cBinop_Vi12NBuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_G1CeFONS, 1, m, &cIf_G1CeFONS_sendMessage);
}

void Heavy_PhaseRing::cBinop_pagispRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_YqruI7PW_sendMessage);
}

void Heavy_PhaseRing::cMsg_73qwTnAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_mKyNCi3o_sendMessage);
}

void Heavy_PhaseRing::cBinop_7zjInsBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5Jk5i6dF, HV_BINOP_POW, 1, m, &cBinop_5Jk5i6dF_sendMessage);
  cMsg_KzPe2rDK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_j2C6DQNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_fcBaLfBX, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_ItvaU0MJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9XhIlXlt, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_mvjIscEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7aV4DbQe_sendMessage);
}

void Heavy_PhaseRing::cBinop_7aV4DbQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_HmGZf6Iy_sendMessage);
}

void Heavy_PhaseRing::cVar_2IOmky7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gm6Z3atX, HV_BINOP_MULTIPLY, 0, m, &cBinop_Gm6Z3atX_sendMessage);
}

void Heavy_PhaseRing::cMsg_Kt1UMbal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1g3a5r07_sendMessage);
}

void Heavy_PhaseRing::cSystem_1g3a5r07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k2dW1rCQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Gm6Z3atX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jSOvroKj_sendMessage);
}

void Heavy_PhaseRing::cBinop_UTiTMx4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gm6Z3atX, HV_BINOP_MULTIPLY, 1, m, &cBinop_Gm6Z3atX_sendMessage);
}

void Heavy_PhaseRing::cMsg_k2dW1rCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_UTiTMx4s_sendMessage);
}

void Heavy_PhaseRing::cBinop_jSOvroKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_hbeF3LMk_sendMessage);
}

void Heavy_PhaseRing::cBinop_hbeF3LMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SGdv1KJv_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_G2FE53kK, m);
}

void Heavy_PhaseRing::cBinop_SGdv1KJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_osWlHqQY, m);
}

void Heavy_PhaseRing::cVar_f6wVQhqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QVl2VRf3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NvtZKlD5_sendMessage);
}

void Heavy_PhaseRing::cVar_kmaGgIi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_mvjIscEA_sendMessage);
}

void Heavy_PhaseRing::cVar_zgLCLkVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_3A2GLN4E_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Mxbq6Eiz, 0, m, &cIf_Mxbq6Eiz_sendMessage);
}

void Heavy_PhaseRing::cVar_G8tdBE38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_r7CriXpp_sendMessage);
}

void Heavy_PhaseRing::cIf_Mxbq6Eiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gsaiFCRh_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_2e0ExTPo, 0, m, &cVar_2e0ExTPo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_3A2GLN4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Mxbq6Eiz, 1, m, &cIf_Mxbq6Eiz_sendMessage);
}

void Heavy_PhaseRing::cBinop_r7CriXpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_eqUnWesz_sendMessage);
}

void Heavy_PhaseRing::cBinop_eqUnWesz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IvPhtg5Q, 0, m, &cVar_IvPhtg5Q_sendMessage);
}

void Heavy_PhaseRing::cTabhead_Xh5tBNgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GdB0D9c8, HV_BINOP_SUBTRACT, 0, m, &cBinop_GdB0D9c8_sendMessage);
}

void Heavy_PhaseRing::cMsg_9AJlevEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_piMtbgWS_sendMessage);
}

void Heavy_PhaseRing::cSystem_piMtbgWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WvhkbCtI_sendMessage);
}

void Heavy_PhaseRing::cVar_H4uxYUhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NXoxFT5o_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_thXEEZID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_thXEEZID, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PH8jTY0Z, 0, m, &cDelay_PH8jTY0Z_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cbnmZkC3, 0, m, &sTabread_cbnmZkC3_sendMessage);
}

void Heavy_PhaseRing::cDelay_PH8jTY0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PH8jTY0Z, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cbnmZkC3, 0, m, &sTabread_cbnmZkC3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PH8jTY0Z, 0, m, &cDelay_PH8jTY0Z_sendMessage);
}

void Heavy_PhaseRing::sTabread_cbnmZkC3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_tXLDmG4R, HV_BINOP_SUBTRACT, 0, m, &cBinop_tXLDmG4R_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_AjLemRyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jmtkwoT4, HV_BINOP_MAX, 0, m, &cBinop_jmtkwoT4_sendMessage);
}

void Heavy_PhaseRing::cBinop_WvhkbCtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AjLemRyB, HV_BINOP_MULTIPLY, 0, m, &cBinop_AjLemRyB_sendMessage);
}

void Heavy_PhaseRing::cBinop_GdB0D9c8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p3wcIUOt_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cbnmZkC3, 0, m, &sTabread_cbnmZkC3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U1JtZm7M_sendMessage);
}

void Heavy_PhaseRing::cSystem_5G7XYq3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tXLDmG4R, HV_BINOP_SUBTRACT, 1, m, &cBinop_tXLDmG4R_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PH8jTY0Z, 2, m, &cDelay_PH8jTY0Z_sendMessage);
}

void Heavy_PhaseRing::cMsg_NXoxFT5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5G7XYq3M_sendMessage);
}

void Heavy_PhaseRing::cMsg_p3wcIUOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_thXEEZID, 0, m, &cDelay_thXEEZID_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PH8jTY0Z, 0, m, &cDelay_PH8jTY0Z_sendMessage);
}

void Heavy_PhaseRing::cMsg_VBrtPaNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_jmtkwoT4, HV_BINOP_MAX, 1, m, &cBinop_jmtkwoT4_sendMessage);
}

void Heavy_PhaseRing::cBinop_jmtkwoT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GdB0D9c8, HV_BINOP_SUBTRACT, 1, m, &cBinop_GdB0D9c8_sendMessage);
}

void Heavy_PhaseRing::cCast_U1JtZm7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_thXEEZID, 0, m, &cDelay_thXEEZID_sendMessage);
}

void Heavy_PhaseRing::cBinop_dPknknSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_thXEEZID, 2, m, &cDelay_thXEEZID_sendMessage);
}

void Heavy_PhaseRing::cBinop_tXLDmG4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dPknknSw_sendMessage);
}

void Heavy_PhaseRing::cCast_t3Zdes4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H4uxYUhj, 0, m, &cVar_H4uxYUhj_sendMessage);
  cMsg_9AJlevEt_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Xh5tBNgx, 0, m, &cTabhead_Xh5tBNgx_sendMessage);
}

void Heavy_PhaseRing::cMsg_rR4UAxSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RFt88haz_sendMessage);
}

void Heavy_PhaseRing::cSystem_RFt88haz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Aj9z24fp_sendMessage);
}

void Heavy_PhaseRing::cDelay_87NqYNFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_87NqYNFg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IVopa0N9, 0, m, &cDelay_IVopa0N9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_87NqYNFg, 0, m, &cDelay_87NqYNFg_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tw7hAKLU, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_IVopa0N9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IVopa0N9, m);
  cMsg_daF1ZdlM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_c2K9Hs8f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_9b10N2WK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_pz9cJYbz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3gLG4Nca_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_klSDzc9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FPnfANZb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_87NqYNFg, 2, m, &cDelay_87NqYNFg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TsY0G80n_sendMessage);
}

void Heavy_PhaseRing::cMsg_3gLG4Nca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_klSDzc9D, 0, m, &hTable_klSDzc9D_sendMessage);
}

void Heavy_PhaseRing::cBinop_Aj9z24fp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_pz9cJYbz_sendMessage);
}

void Heavy_PhaseRing::cMsg_daF1ZdlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_klSDzc9D, 0, m, &hTable_klSDzc9D_sendMessage);
}

void Heavy_PhaseRing::cCast_TsY0G80n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_87NqYNFg, 0, m, &cDelay_87NqYNFg_sendMessage);
}

void Heavy_PhaseRing::cMsg_FPnfANZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_IVopa0N9, 2, m, &cDelay_IVopa0N9_sendMessage);
}

void Heavy_PhaseRing::cMsg_9b10N2WK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tw7hAKLU, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_sfL9vFkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rzu3kMLd, HV_BINOP_SUBTRACT, 0, m, &cBinop_rzu3kMLd_sendMessage);
}

void Heavy_PhaseRing::cMsg_aplmmHLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4L6kBWdq_sendMessage);
}

void Heavy_PhaseRing::cSystem_4L6kBWdq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kiW7xOAu_sendMessage);
}

void Heavy_PhaseRing::cVar_3LSC7hO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9stvR6IS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_y35ZqJai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_y35ZqJai, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NfSWMc84, 0, m, &cDelay_NfSWMc84_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7ExfUmls, 0, m, &sTabread_7ExfUmls_sendMessage);
}

void Heavy_PhaseRing::cDelay_NfSWMc84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NfSWMc84, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7ExfUmls, 0, m, &sTabread_7ExfUmls_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NfSWMc84, 0, m, &cDelay_NfSWMc84_sendMessage);
}

void Heavy_PhaseRing::sTabread_7ExfUmls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eus52awF, HV_BINOP_SUBTRACT, 0, m, &cBinop_eus52awF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_RcAEGTNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gGAonqT1, HV_BINOP_MAX, 0, m, &cBinop_gGAonqT1_sendMessage);
}

void Heavy_PhaseRing::cBinop_kiW7xOAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RcAEGTNx, HV_BINOP_MULTIPLY, 0, m, &cBinop_RcAEGTNx_sendMessage);
}

void Heavy_PhaseRing::cBinop_rzu3kMLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eCrm8yjg_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7ExfUmls, 0, m, &sTabread_7ExfUmls_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wtkd2bQ8_sendMessage);
}

void Heavy_PhaseRing::cSystem_YYdwMrSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eus52awF, HV_BINOP_SUBTRACT, 1, m, &cBinop_eus52awF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NfSWMc84, 2, m, &cDelay_NfSWMc84_sendMessage);
}

void Heavy_PhaseRing::cMsg_9stvR6IS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YYdwMrSf_sendMessage);
}

void Heavy_PhaseRing::cMsg_eCrm8yjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_y35ZqJai, 0, m, &cDelay_y35ZqJai_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NfSWMc84, 0, m, &cDelay_NfSWMc84_sendMessage);
}

void Heavy_PhaseRing::cMsg_E4kYa4BX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_gGAonqT1, HV_BINOP_MAX, 1, m, &cBinop_gGAonqT1_sendMessage);
}

void Heavy_PhaseRing::cBinop_gGAonqT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rzu3kMLd, HV_BINOP_SUBTRACT, 1, m, &cBinop_rzu3kMLd_sendMessage);
}

void Heavy_PhaseRing::cCast_Wtkd2bQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_y35ZqJai, 0, m, &cDelay_y35ZqJai_sendMessage);
}

void Heavy_PhaseRing::cBinop_MAlZxeRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_y35ZqJai, 2, m, &cDelay_y35ZqJai_sendMessage);
}

void Heavy_PhaseRing::cBinop_eus52awF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MAlZxeRA_sendMessage);
}

void Heavy_PhaseRing::cCast_P7ipJZL8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3LSC7hO6, 0, m, &cVar_3LSC7hO6_sendMessage);
  cMsg_aplmmHLU_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sfL9vFkw, 0, m, &cTabhead_sfL9vFkw_sendMessage);
}

void Heavy_PhaseRing::cMsg_1AA81F2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eipeXxRR_sendMessage);
}

void Heavy_PhaseRing::cSystem_eipeXxRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gCxY7l6e_sendMessage);
}

void Heavy_PhaseRing::cDelay_u3iw5wbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_u3iw5wbo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_66bhsayA, 0, m, &cDelay_66bhsayA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u3iw5wbo, 0, m, &cDelay_u3iw5wbo_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_DPtLct7K, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_66bhsayA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_66bhsayA, m);
  cMsg_H0Fsqz7k_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_fXIDlEgG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_lg042Bp9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_yVBf9vD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mqinqy6Q_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_fgSHe5Ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wmZVlqZU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u3iw5wbo, 2, m, &cDelay_u3iw5wbo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3c2hit0S_sendMessage);
}

void Heavy_PhaseRing::cMsg_mqinqy6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_fgSHe5Ec, 0, m, &hTable_fgSHe5Ec_sendMessage);
}

void Heavy_PhaseRing::cBinop_gCxY7l6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_yVBf9vD3_sendMessage);
}

void Heavy_PhaseRing::cMsg_H0Fsqz7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_fgSHe5Ec, 0, m, &hTable_fgSHe5Ec_sendMessage);
}

void Heavy_PhaseRing::cCast_3c2hit0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_u3iw5wbo, 0, m, &cDelay_u3iw5wbo_sendMessage);
}

void Heavy_PhaseRing::cMsg_wmZVlqZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_66bhsayA, 2, m, &cDelay_66bhsayA_sendMessage);
}

void Heavy_PhaseRing::cMsg_lg042Bp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_DPtLct7K, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_3J7fSdyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOMfaASe, HV_BINOP_SUBTRACT, 0, m, &cBinop_cOMfaASe_sendMessage);
}

void Heavy_PhaseRing::cMsg_5MO4cvcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aumr7J3c_sendMessage);
}

void Heavy_PhaseRing::cSystem_aumr7J3c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nDpWD4Id_sendMessage);
}

void Heavy_PhaseRing::cVar_VXcee2tK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8TZlWhh4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_oIN4i6l3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oIN4i6l3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9z4EDDEF, 0, m, &cDelay_9z4EDDEF_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fCmcOsqk, 0, m, &sTabread_fCmcOsqk_sendMessage);
}

void Heavy_PhaseRing::cDelay_9z4EDDEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9z4EDDEF, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fCmcOsqk, 0, m, &sTabread_fCmcOsqk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9z4EDDEF, 0, m, &cDelay_9z4EDDEF_sendMessage);
}

void Heavy_PhaseRing::sTabread_fCmcOsqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QyRQbdJ0, HV_BINOP_SUBTRACT, 0, m, &cBinop_QyRQbdJ0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_BDvNFGMD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5axgK1d9, HV_BINOP_MAX, 0, m, &cBinop_5axgK1d9_sendMessage);
}

void Heavy_PhaseRing::cBinop_nDpWD4Id_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BDvNFGMD, HV_BINOP_MULTIPLY, 0, m, &cBinop_BDvNFGMD_sendMessage);
}

void Heavy_PhaseRing::cBinop_cOMfaASe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U6tsvohc_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fCmcOsqk, 0, m, &sTabread_fCmcOsqk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ka9NPBwJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_gc5HtV5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QyRQbdJ0, HV_BINOP_SUBTRACT, 1, m, &cBinop_QyRQbdJ0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9z4EDDEF, 2, m, &cDelay_9z4EDDEF_sendMessage);
}

void Heavy_PhaseRing::cMsg_8TZlWhh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gc5HtV5z_sendMessage);
}

void Heavy_PhaseRing::cMsg_U6tsvohc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_oIN4i6l3, 0, m, &cDelay_oIN4i6l3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9z4EDDEF, 0, m, &cDelay_9z4EDDEF_sendMessage);
}

void Heavy_PhaseRing::cMsg_7h0ocG12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_5axgK1d9, HV_BINOP_MAX, 1, m, &cBinop_5axgK1d9_sendMessage);
}

void Heavy_PhaseRing::cBinop_5axgK1d9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOMfaASe, HV_BINOP_SUBTRACT, 1, m, &cBinop_cOMfaASe_sendMessage);
}

void Heavy_PhaseRing::cCast_ka9NPBwJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oIN4i6l3, 0, m, &cDelay_oIN4i6l3_sendMessage);
}

void Heavy_PhaseRing::cBinop_2FRPEhFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oIN4i6l3, 2, m, &cDelay_oIN4i6l3_sendMessage);
}

void Heavy_PhaseRing::cBinop_QyRQbdJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2FRPEhFE_sendMessage);
}

void Heavy_PhaseRing::cCast_9VXIqasC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VXcee2tK, 0, m, &cVar_VXcee2tK_sendMessage);
  cMsg_5MO4cvcD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3J7fSdyK, 0, m, &cTabhead_3J7fSdyK_sendMessage);
}

void Heavy_PhaseRing::cMsg_Kq52xoUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tXULZXIY_sendMessage);
}

void Heavy_PhaseRing::cSystem_tXULZXIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9r3Y3Cf5_sendMessage);
}

void Heavy_PhaseRing::cDelay_6nUpZnEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6nUpZnEy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6mOlyxlu, 0, m, &cDelay_6mOlyxlu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6nUpZnEy, 0, m, &cDelay_6nUpZnEy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zNHpzpPC, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_6mOlyxlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6mOlyxlu, m);
  cMsg_LKQmdfWe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_gkvr6hH7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_b8rmfGE7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_zlNBQoeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VMhGgEKr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_70Qa0lXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_56gGpztg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6nUpZnEy, 2, m, &cDelay_6nUpZnEy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UrQTl02E_sendMessage);
}

void Heavy_PhaseRing::cMsg_VMhGgEKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_70Qa0lXY, 0, m, &hTable_70Qa0lXY_sendMessage);
}

void Heavy_PhaseRing::cBinop_9r3Y3Cf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_zlNBQoeR_sendMessage);
}

void Heavy_PhaseRing::cMsg_LKQmdfWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_70Qa0lXY, 0, m, &hTable_70Qa0lXY_sendMessage);
}

void Heavy_PhaseRing::cCast_UrQTl02E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6nUpZnEy, 0, m, &cDelay_6nUpZnEy_sendMessage);
}

void Heavy_PhaseRing::cMsg_56gGpztg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_6mOlyxlu, 2, m, &cDelay_6mOlyxlu_sendMessage);
}

void Heavy_PhaseRing::cMsg_b8rmfGE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zNHpzpPC, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_0BdrXPb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvBnPj0u, HV_BINOP_SUBTRACT, 0, m, &cBinop_fvBnPj0u_sendMessage);
}

void Heavy_PhaseRing::cMsg_dATDyHWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8jNmtp0U_sendMessage);
}

void Heavy_PhaseRing::cSystem_8jNmtp0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9Lp0DJWz_sendMessage);
}

void Heavy_PhaseRing::cVar_iTJJYn8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_onVZi0vh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_X7SjfnyQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_X7SjfnyQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UR2ke14T, 0, m, &cDelay_UR2ke14T_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TNEawRUc, 0, m, &sTabread_TNEawRUc_sendMessage);
}

void Heavy_PhaseRing::cDelay_UR2ke14T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UR2ke14T, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TNEawRUc, 0, m, &sTabread_TNEawRUc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UR2ke14T, 0, m, &cDelay_UR2ke14T_sendMessage);
}

void Heavy_PhaseRing::sTabread_TNEawRUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DCBn4zEm, HV_BINOP_SUBTRACT, 0, m, &cBinop_DCBn4zEm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_pYahqfRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rDCXVDSi, HV_BINOP_MAX, 0, m, &cBinop_rDCXVDSi_sendMessage);
}

void Heavy_PhaseRing::cBinop_9Lp0DJWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pYahqfRs, HV_BINOP_MULTIPLY, 0, m, &cBinop_pYahqfRs_sendMessage);
}

void Heavy_PhaseRing::cBinop_fvBnPj0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5eFu3gFK_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TNEawRUc, 0, m, &sTabread_TNEawRUc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OBPG2tja_sendMessage);
}

void Heavy_PhaseRing::cSystem_lF9Op7U3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DCBn4zEm, HV_BINOP_SUBTRACT, 1, m, &cBinop_DCBn4zEm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UR2ke14T, 2, m, &cDelay_UR2ke14T_sendMessage);
}

void Heavy_PhaseRing::cMsg_onVZi0vh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lF9Op7U3_sendMessage);
}

void Heavy_PhaseRing::cMsg_5eFu3gFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_X7SjfnyQ, 0, m, &cDelay_X7SjfnyQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UR2ke14T, 0, m, &cDelay_UR2ke14T_sendMessage);
}

void Heavy_PhaseRing::cMsg_XNub820P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_rDCXVDSi, HV_BINOP_MAX, 1, m, &cBinop_rDCXVDSi_sendMessage);
}

void Heavy_PhaseRing::cBinop_rDCXVDSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvBnPj0u, HV_BINOP_SUBTRACT, 1, m, &cBinop_fvBnPj0u_sendMessage);
}

void Heavy_PhaseRing::cCast_OBPG2tja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_X7SjfnyQ, 0, m, &cDelay_X7SjfnyQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_a0fASriO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_X7SjfnyQ, 2, m, &cDelay_X7SjfnyQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_DCBn4zEm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_a0fASriO_sendMessage);
}

void Heavy_PhaseRing::cCast_TBLh13Mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iTJJYn8o, 0, m, &cVar_iTJJYn8o_sendMessage);
  cMsg_dATDyHWl_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_0BdrXPb4, 0, m, &cTabhead_0BdrXPb4_sendMessage);
}

void Heavy_PhaseRing::cMsg_y42S63zF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ajTNHO2s_sendMessage);
}

void Heavy_PhaseRing::cSystem_ajTNHO2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_w7J4x4Ez_sendMessage);
}

void Heavy_PhaseRing::cDelay_Tf9piw99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Tf9piw99, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_d2m96mPR, 0, m, &cDelay_d2m96mPR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tf9piw99, 0, m, &cDelay_Tf9piw99_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_N9lXNEBn, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_d2m96mPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_d2m96mPR, m);
  cMsg_e3IdQjpn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_dPmSQPvE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_FrCx8D6T_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_McwxCziN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V04Y55eZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_EYemnlv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rjViTl2x_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tf9piw99, 2, m, &cDelay_Tf9piw99_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D7jawWKX_sendMessage);
}

void Heavy_PhaseRing::cMsg_V04Y55eZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EYemnlv2, 0, m, &hTable_EYemnlv2_sendMessage);
}

void Heavy_PhaseRing::cBinop_w7J4x4Ez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_McwxCziN_sendMessage);
}

void Heavy_PhaseRing::cMsg_e3IdQjpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EYemnlv2, 0, m, &hTable_EYemnlv2_sendMessage);
}

void Heavy_PhaseRing::cCast_D7jawWKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tf9piw99, 0, m, &cDelay_Tf9piw99_sendMessage);
}

void Heavy_PhaseRing::cMsg_rjViTl2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_d2m96mPR, 2, m, &cDelay_d2m96mPR_sendMessage);
}

void Heavy_PhaseRing::cMsg_FrCx8D6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_N9lXNEBn, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_9wfR3ZpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U13QPYuu, HV_BINOP_SUBTRACT, 0, m, &cBinop_U13QPYuu_sendMessage);
}

void Heavy_PhaseRing::cMsg_wSFy3KuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lMRRIOVN_sendMessage);
}

void Heavy_PhaseRing::cSystem_lMRRIOVN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_z7Ry0u5T_sendMessage);
}

void Heavy_PhaseRing::cVar_M7VObPq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OZmBLAxz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_KrGkRZcV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KrGkRZcV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HZ8GsjMJ, 0, m, &cDelay_HZ8GsjMJ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_901JJraY, 0, m, &sTabread_901JJraY_sendMessage);
}

void Heavy_PhaseRing::cDelay_HZ8GsjMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HZ8GsjMJ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_901JJraY, 0, m, &sTabread_901JJraY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HZ8GsjMJ, 0, m, &cDelay_HZ8GsjMJ_sendMessage);
}

void Heavy_PhaseRing::sTabread_901JJraY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_57P96EX9, HV_BINOP_SUBTRACT, 0, m, &cBinop_57P96EX9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_uJjXBSH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sLJ7kzcW, HV_BINOP_MAX, 0, m, &cBinop_sLJ7kzcW_sendMessage);
}

void Heavy_PhaseRing::cBinop_z7Ry0u5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uJjXBSH8, HV_BINOP_MULTIPLY, 0, m, &cBinop_uJjXBSH8_sendMessage);
}

void Heavy_PhaseRing::cBinop_U13QPYuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XFcAL7dn_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_901JJraY, 0, m, &sTabread_901JJraY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V60M38GU_sendMessage);
}

void Heavy_PhaseRing::cSystem_fkOLAnYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_57P96EX9, HV_BINOP_SUBTRACT, 1, m, &cBinop_57P96EX9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HZ8GsjMJ, 2, m, &cDelay_HZ8GsjMJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_OZmBLAxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fkOLAnYi_sendMessage);
}

void Heavy_PhaseRing::cMsg_XFcAL7dn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KrGkRZcV, 0, m, &cDelay_KrGkRZcV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HZ8GsjMJ, 0, m, &cDelay_HZ8GsjMJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_krLQEoVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_sLJ7kzcW, HV_BINOP_MAX, 1, m, &cBinop_sLJ7kzcW_sendMessage);
}

void Heavy_PhaseRing::cBinop_sLJ7kzcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U13QPYuu, HV_BINOP_SUBTRACT, 1, m, &cBinop_U13QPYuu_sendMessage);
}

void Heavy_PhaseRing::cCast_V60M38GU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KrGkRZcV, 0, m, &cDelay_KrGkRZcV_sendMessage);
}

void Heavy_PhaseRing::cBinop_7PF3FFIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KrGkRZcV, 2, m, &cDelay_KrGkRZcV_sendMessage);
}

void Heavy_PhaseRing::cBinop_57P96EX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7PF3FFIT_sendMessage);
}

void Heavy_PhaseRing::cCast_bUVN7hUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M7VObPq1, 0, m, &cVar_M7VObPq1_sendMessage);
  cMsg_wSFy3KuE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9wfR3ZpS, 0, m, &cTabhead_9wfR3ZpS_sendMessage);
}

void Heavy_PhaseRing::cMsg_c5ToNjYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_J6BmElon_sendMessage);
}

void Heavy_PhaseRing::cSystem_J6BmElon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QrsZYquI_sendMessage);
}

void Heavy_PhaseRing::cDelay_KlfTWINn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KlfTWINn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AezK23YR, 0, m, &cDelay_AezK23YR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KlfTWINn, 0, m, &cDelay_KlfTWINn_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zYAn3Pa6, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_AezK23YR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AezK23YR, m);
  cMsg_QRwZZoXc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_xwk0juZV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mRmTm3GA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_WcX7mfOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1FVY3viS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_GUL21Yeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FoYHkcj3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KlfTWINn, 2, m, &cDelay_KlfTWINn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gcoOzBbh_sendMessage);
}

void Heavy_PhaseRing::cMsg_1FVY3viS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GUL21Yeq, 0, m, &hTable_GUL21Yeq_sendMessage);
}

void Heavy_PhaseRing::cBinop_QrsZYquI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_WcX7mfOn_sendMessage);
}

void Heavy_PhaseRing::cMsg_QRwZZoXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GUL21Yeq, 0, m, &hTable_GUL21Yeq_sendMessage);
}

void Heavy_PhaseRing::cCast_gcoOzBbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KlfTWINn, 0, m, &cDelay_KlfTWINn_sendMessage);
}

void Heavy_PhaseRing::cMsg_FoYHkcj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_AezK23YR, 2, m, &cDelay_AezK23YR_sendMessage);
}

void Heavy_PhaseRing::cMsg_mRmTm3GA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zYAn3Pa6, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_OCcUsNGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pm0CuOR4, HV_BINOP_SUBTRACT, 0, m, &cBinop_Pm0CuOR4_sendMessage);
}

void Heavy_PhaseRing::cMsg_zE96OYzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W5LGLFuu_sendMessage);
}

void Heavy_PhaseRing::cSystem_W5LGLFuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oG32Sy5z_sendMessage);
}

void Heavy_PhaseRing::cVar_5lTUZVRn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xcZF0JTf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_kCHyH9Yd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kCHyH9Yd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZVnQ5ynQ, 0, m, &cDelay_ZVnQ5ynQ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tGeCXlmx, 0, m, &sTabread_tGeCXlmx_sendMessage);
}

void Heavy_PhaseRing::cDelay_ZVnQ5ynQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZVnQ5ynQ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tGeCXlmx, 0, m, &sTabread_tGeCXlmx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZVnQ5ynQ, 0, m, &cDelay_ZVnQ5ynQ_sendMessage);
}

void Heavy_PhaseRing::sTabread_tGeCXlmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NqiPgS6o, HV_BINOP_SUBTRACT, 0, m, &cBinop_NqiPgS6o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_AjJpAuO5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lBoS58YP, HV_BINOP_MAX, 0, m, &cBinop_lBoS58YP_sendMessage);
}

void Heavy_PhaseRing::cBinop_oG32Sy5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AjJpAuO5, HV_BINOP_MULTIPLY, 0, m, &cBinop_AjJpAuO5_sendMessage);
}

void Heavy_PhaseRing::cBinop_Pm0CuOR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_anh2BYPu_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tGeCXlmx, 0, m, &sTabread_tGeCXlmx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_681EpMRX_sendMessage);
}

void Heavy_PhaseRing::cSystem_D2Y4Xnwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NqiPgS6o, HV_BINOP_SUBTRACT, 1, m, &cBinop_NqiPgS6o_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZVnQ5ynQ, 2, m, &cDelay_ZVnQ5ynQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_xcZF0JTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D2Y4Xnwz_sendMessage);
}

void Heavy_PhaseRing::cMsg_anh2BYPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kCHyH9Yd, 0, m, &cDelay_kCHyH9Yd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZVnQ5ynQ, 0, m, &cDelay_ZVnQ5ynQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_OkdJDUWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_lBoS58YP, HV_BINOP_MAX, 1, m, &cBinop_lBoS58YP_sendMessage);
}

void Heavy_PhaseRing::cBinop_lBoS58YP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pm0CuOR4, HV_BINOP_SUBTRACT, 1, m, &cBinop_Pm0CuOR4_sendMessage);
}

void Heavy_PhaseRing::cCast_681EpMRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kCHyH9Yd, 0, m, &cDelay_kCHyH9Yd_sendMessage);
}

void Heavy_PhaseRing::cBinop_TAS94ZX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kCHyH9Yd, 2, m, &cDelay_kCHyH9Yd_sendMessage);
}

void Heavy_PhaseRing::cBinop_NqiPgS6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TAS94ZX8_sendMessage);
}

void Heavy_PhaseRing::cCast_we2FQXer_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5lTUZVRn, 0, m, &cVar_5lTUZVRn_sendMessage);
  cMsg_zE96OYzg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OCcUsNGd, 0, m, &cTabhead_OCcUsNGd_sendMessage);
}

void Heavy_PhaseRing::cMsg_NJNqgqKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_12iXLZQE_sendMessage);
}

void Heavy_PhaseRing::cSystem_12iXLZQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QOw9SzW8_sendMessage);
}

void Heavy_PhaseRing::cDelay_WFlC9FGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WFlC9FGx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GVDRMqVP, 0, m, &cDelay_GVDRMqVP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WFlC9FGx, 0, m, &cDelay_WFlC9FGx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JDYYESne, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_GVDRMqVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GVDRMqVP, m);
  cMsg_vLgAg5qN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_kyifIpkC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_VNLyYmTK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_BC1FclSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QUuX6aoe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_0uBwf0XD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6vqzTZXe_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WFlC9FGx, 2, m, &cDelay_WFlC9FGx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hwVDuKeL_sendMessage);
}

void Heavy_PhaseRing::cMsg_QUuX6aoe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_0uBwf0XD, 0, m, &hTable_0uBwf0XD_sendMessage);
}

void Heavy_PhaseRing::cBinop_QOw9SzW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_BC1FclSn_sendMessage);
}

void Heavy_PhaseRing::cMsg_vLgAg5qN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_0uBwf0XD, 0, m, &hTable_0uBwf0XD_sendMessage);
}

void Heavy_PhaseRing::cCast_hwVDuKeL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WFlC9FGx, 0, m, &cDelay_WFlC9FGx_sendMessage);
}

void Heavy_PhaseRing::cMsg_6vqzTZXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_GVDRMqVP, 2, m, &cDelay_GVDRMqVP_sendMessage);
}

void Heavy_PhaseRing::cMsg_VNLyYmTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JDYYESne, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_2e0ExTPo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2IOmky7M, 0, m, &cVar_2IOmky7M_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IiH18POU, 0, m, &cVar_IiH18POU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BWaZGSbM, 0, m, &cVar_BWaZGSbM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lBsll9s6, 0, m, &cVar_lBsll9s6_sendMessage);
}

void Heavy_PhaseRing::cVar_IvPhtg5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_EH0FRlIV_sendMessage);
}

void Heavy_PhaseRing::cPack_fccQMY3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_X9VNqmng, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_IiH18POU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lVzd5m3p, HV_BINOP_MULTIPLY, 0, m, &cBinop_lVzd5m3p_sendMessage);
}

void Heavy_PhaseRing::cMsg_QaxVgdGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DioMj1p9_sendMessage);
}

void Heavy_PhaseRing::cSystem_DioMj1p9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uZycKlB7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_lVzd5m3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pzJSJBHr_sendMessage);
}

void Heavy_PhaseRing::cBinop_8sojoxFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lVzd5m3p, HV_BINOP_MULTIPLY, 1, m, &cBinop_lVzd5m3p_sendMessage);
}

void Heavy_PhaseRing::cMsg_uZycKlB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8sojoxFM_sendMessage);
}

void Heavy_PhaseRing::cBinop_pzJSJBHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yYq3Ovzq_sendMessage);
}

void Heavy_PhaseRing::cBinop_yYq3Ovzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yuk4JnBi_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9NEyGJZO, m);
}

void Heavy_PhaseRing::cBinop_yuk4JnBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_s6KrrzVj, m);
}

void Heavy_PhaseRing::cVar_BWaZGSbM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4LYHKg6t, HV_BINOP_MULTIPLY, 0, m, &cBinop_4LYHKg6t_sendMessage);
}

void Heavy_PhaseRing::cMsg_0rBuFJr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xgvxp8zS_sendMessage);
}

void Heavy_PhaseRing::cSystem_xgvxp8zS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IXHbyXjs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_4LYHKg6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6y3AleAO_sendMessage);
}

void Heavy_PhaseRing::cBinop_CzHJSGO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4LYHKg6t, HV_BINOP_MULTIPLY, 1, m, &cBinop_4LYHKg6t_sendMessage);
}

void Heavy_PhaseRing::cMsg_IXHbyXjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CzHJSGO6_sendMessage);
}

void Heavy_PhaseRing::cBinop_6y3AleAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_E4KhoKU7_sendMessage);
}

void Heavy_PhaseRing::cBinop_E4KhoKU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CAntBPfp_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_B8EERp6p, m);
}

void Heavy_PhaseRing::cBinop_CAntBPfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xCdjK98a, m);
}

void Heavy_PhaseRing::cVar_lBsll9s6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_957F88mg, HV_BINOP_MULTIPLY, 0, m, &cBinop_957F88mg_sendMessage);
}

void Heavy_PhaseRing::cMsg_TebJg4eG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bIkMyngc_sendMessage);
}

void Heavy_PhaseRing::cSystem_bIkMyngc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tqobie8F_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_957F88mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_15gviwgF_sendMessage);
}

void Heavy_PhaseRing::cBinop_kinU56NK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_957F88mg, HV_BINOP_MULTIPLY, 1, m, &cBinop_957F88mg_sendMessage);
}

void Heavy_PhaseRing::cMsg_tqobie8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kinU56NK_sendMessage);
}

void Heavy_PhaseRing::cBinop_15gviwgF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Nu9iehqS_sendMessage);
}

void Heavy_PhaseRing::cBinop_Nu9iehqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_B4y4Hspr_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FGlaqMDl, m);
}

void Heavy_PhaseRing::cBinop_B4y4Hspr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YiOdYKWE, m);
}

void Heavy_PhaseRing::cBinop_HmGZf6Iy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ItvaU0MJ, 0, m, &cPack_ItvaU0MJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_gsaiFCRh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_2e0ExTPo, 0, m, &cVar_2e0ExTPo_sendMessage);
}

void Heavy_PhaseRing::cBinop_EH0FRlIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fccQMY3b, 0, m, &cPack_fccQMY3b_sendMessage);
}

void Heavy_PhaseRing::cBinop_mKyNCi3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_j2C6DQNi, 0, m, &cPack_j2C6DQNi_sendMessage);
}

void Heavy_PhaseRing::cMsg_s0YTwiwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NB5EbBL5_sendMessage);
}

void Heavy_PhaseRing::cSystem_NB5EbBL5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_woRcIRlj_sendMessage);
}

void Heavy_PhaseRing::cVar_CarJsOLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IYM03EVS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_6zVCzQmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yKVM5GZU_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eVSawrjG, m);
}

void Heavy_PhaseRing::cBinop_woRcIRlj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KPwIzAB8, m);
}

void Heavy_PhaseRing::cMsg_IYM03EVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6zVCzQmB_sendMessage);
}

void Heavy_PhaseRing::cBinop_yKVM5GZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_J5FGDDlY, m);
}

void Heavy_PhaseRing::cVar_4c1I3vMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wMeb7gz3, HV_BINOP_MULTIPLY, 0, m, &cBinop_wMeb7gz3_sendMessage);
}

void Heavy_PhaseRing::cMsg_3kraV9na_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JAnnGbIH_sendMessage);
}

void Heavy_PhaseRing::cSystem_JAnnGbIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z5iuNubx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_wMeb7gz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_qt5vYQOm_sendMessage);
}

void Heavy_PhaseRing::cBinop_npmzF8sG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wMeb7gz3, HV_BINOP_MULTIPLY, 1, m, &cBinop_wMeb7gz3_sendMessage);
}

void Heavy_PhaseRing::cMsg_Z5iuNubx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_npmzF8sG_sendMessage);
}

void Heavy_PhaseRing::cBinop_qt5vYQOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Tv4Wszxq_sendMessage);
}

void Heavy_PhaseRing::cBinop_Tv4Wszxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JgCJS3xn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KOcUABO6, m);
}

void Heavy_PhaseRing::cBinop_JgCJS3xn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4SKkcWr8, m);
}

void Heavy_PhaseRing::cBinop_CbEAARDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_vXvOmYzb_sendMessage);
}

void Heavy_PhaseRing::cBinop_vXvOmYzb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WJEdGXE5, m);
}

void Heavy_PhaseRing::cBinop_eQHfhVMX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LmTO91WY_sendMessage);
}

void Heavy_PhaseRing::cBinop_LmTO91WY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jUPv5QTG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_lpBUFw1h_sendMessage);
}

void Heavy_PhaseRing::cVar_HtGsEAiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_wtJIGUQq_sendMessage);
}

void Heavy_PhaseRing::cMsg_yCCgodlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W4rmiKPv_sendMessage);
}

void Heavy_PhaseRing::cSystem_W4rmiKPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XHu79TOS, HV_BINOP_DIVIDE, 1, m, &cBinop_XHu79TOS_sendMessage);
}

void Heavy_PhaseRing::cBinop_jUPv5QTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_o1FGbUwi_sendMessage);
}

void Heavy_PhaseRing::cBinop_o1FGbUwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dd8sB44J, m);
}

void Heavy_PhaseRing::cMsg_naoikBDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_PU1cV8FJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_PU1cV8FJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_eQHfhVMX_sendMessage);
}

void Heavy_PhaseRing::cBinop_lpBUFw1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RMbLEeSj, m);
}

void Heavy_PhaseRing::cBinop_wtJIGUQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_F7u60odU_sendMessage);
}

void Heavy_PhaseRing::cBinop_F7u60odU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XHu79TOS, HV_BINOP_DIVIDE, 0, m, &cBinop_XHu79TOS_sendMessage);
}

void Heavy_PhaseRing::cBinop_XHu79TOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_naoikBDh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_LrQr7SC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tm5J8UC3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_qjTIAcAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X5xM5RAF_sendMessage);
}

void Heavy_PhaseRing::cSystem_X5xM5RAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kBMytybp_sendMessage);
}

void Heavy_PhaseRing::cDelay_dmcibqUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dmcibqUl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_riyPeKSB, 0, m, &cDelay_riyPeKSB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dmcibqUl, 0, m, &cDelay_dmcibqUl_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pe0F4E1o, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_riyPeKSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_riyPeKSB, m);
  cMsg_doo2IXmM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_gWRqI8p3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_PaSxHBbG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_vtWuiPgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j4SwS958_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_3s6AKaH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4NgOf50D_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dmcibqUl, 2, m, &cDelay_dmcibqUl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fy0WFPda_sendMessage);
}

void Heavy_PhaseRing::cMsg_j4SwS958_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3s6AKaH3, 0, m, &hTable_3s6AKaH3_sendMessage);
}

void Heavy_PhaseRing::cBinop_kBMytybp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_vtWuiPgJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_doo2IXmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3s6AKaH3, 0, m, &hTable_3s6AKaH3_sendMessage);
}

void Heavy_PhaseRing::cCast_fy0WFPda_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dmcibqUl, 0, m, &cDelay_dmcibqUl_sendMessage);
}

void Heavy_PhaseRing::cMsg_4NgOf50D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_riyPeKSB, 2, m, &cDelay_riyPeKSB_sendMessage);
}

void Heavy_PhaseRing::cMsg_PaSxHBbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pe0F4E1o, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_qFMfbyiD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_Tm5J8UC3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Tm5J8UC3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_sEA64x1r, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_CXdjhTqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KJf5FkvN, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_uzFF2kWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CXdjhTqE, 0, m, &cPack_CXdjhTqE_sendMessage);
}

void Heavy_PhaseRing::cCast_0bY1Ngxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_u6Eyb6Fe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_NLMmAgyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_KJf5FkvN, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_Cqia6yHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_zDeJ1jQz, m);
}

void Heavy_PhaseRing::cMsg_K586Nq2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_CbEAARDN_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_00QTswrE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xZobGNRs, 0, m, &cSlice_xZobGNRs_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_A6GNcW9s, 0, m, &cRandom_A6GNcW9s_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_1tuDAUlU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tu3c8Z7U_sendMessage);
}

void Heavy_PhaseRing::cUnop_tu3c8Z7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_Z9woiKoW_sendMessage);
}

void Heavy_PhaseRing::cRandom_A6GNcW9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_1tuDAUlU_sendMessage);
}

void Heavy_PhaseRing::cSlice_xZobGNRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_A6GNcW9s, 1, m, &cRandom_A6GNcW9s_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_GQWNcRwf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tjXq1TPI, 0, m, &cSlice_tjXq1TPI_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_L22ejGHH, 0, m, &cRandom_L22ejGHH_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_4pgmdJot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uIx92Lhl_sendMessage);
}

void Heavy_PhaseRing::cUnop_uIx92Lhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_17eiHbby, 0, m, &cPack_17eiHbby_sendMessage);
}

void Heavy_PhaseRing::cRandom_L22ejGHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_4pgmdJot_sendMessage);
}

void Heavy_PhaseRing::cSlice_tjXq1TPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_L22ejGHH, 1, m, &cRandom_L22ejGHH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_EBmJ0ZAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_sH2BDQlp_sendMessage);
}

void Heavy_PhaseRing::cPack_hj4FDpy3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mzMT2qN8, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_H7pDa0mG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ncHkoyIc_sendMessage);
}

void Heavy_PhaseRing::cBinop_KAkC5ltu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_H7pDa0mG_sendMessage);
}

void Heavy_PhaseRing::cPack_fkscfO8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_gLJMVqkf, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_oZMzsfZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_G7SLP1Su_sendMessage);
}

void Heavy_PhaseRing::cMsg_fJbomtA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_p49t80Ls_sendMessage);
}

void Heavy_PhaseRing::cSystem_p49t80Ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DIAF9BLI_sendMessage);
}

void Heavy_PhaseRing::cDelay_M6K0kTY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M6K0kTY6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zFO2C5md, 0, m, &cDelay_zFO2C5md_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M6K0kTY6, 0, m, &cDelay_M6K0kTY6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_soY6jzND, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_zFO2C5md_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zFO2C5md, m);
  cMsg_vunxMScU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_I85Dq7sC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LCzfMkZp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_2GS9AubV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CODv1XZz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_guhiLadY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FYX5VgT0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M6K0kTY6, 2, m, &cDelay_M6K0kTY6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_t4PlUmQo_sendMessage);
}

void Heavy_PhaseRing::cMsg_CODv1XZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_guhiLadY, 0, m, &hTable_guhiLadY_sendMessage);
}

void Heavy_PhaseRing::cBinop_DIAF9BLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_2GS9AubV_sendMessage);
}

void Heavy_PhaseRing::cMsg_vunxMScU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_guhiLadY, 0, m, &hTable_guhiLadY_sendMessage);
}

void Heavy_PhaseRing::cCast_t4PlUmQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_M6K0kTY6, 0, m, &cDelay_M6K0kTY6_sendMessage);
}

void Heavy_PhaseRing::cMsg_FYX5VgT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_zFO2C5md, 2, m, &cDelay_zFO2C5md_sendMessage);
}

void Heavy_PhaseRing::cMsg_LCzfMkZp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_soY6jzND, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_w5quhA0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SMsLsFEI_sendMessage);
}

void Heavy_PhaseRing::cSystem_SMsLsFEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YuoybGML_sendMessage);
}

void Heavy_PhaseRing::cVar_tD1VKwcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WvUP4eZR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_yNX3GAg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9R0UR8US_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6TBiKZ6y, m);
}

void Heavy_PhaseRing::cBinop_YuoybGML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BWFUYOzV, m);
}

void Heavy_PhaseRing::cMsg_WvUP4eZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yNX3GAg4_sendMessage);
}

void Heavy_PhaseRing::cBinop_9R0UR8US_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Rq8Q8I6Y, m);
}

void Heavy_PhaseRing::cMsg_EkcktGkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_649cELmr_sendMessage);
}

void Heavy_PhaseRing::cSystem_649cELmr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JF1g3OQf_sendMessage);
}

void Heavy_PhaseRing::cVar_r1cbd4S9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1IVVL5xv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_UiqeuVCR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tE1Vjy6h_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_19bbDObM, m);
}

void Heavy_PhaseRing::cBinop_JF1g3OQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nJdQMaL3, m);
}

void Heavy_PhaseRing::cMsg_1IVVL5xv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UiqeuVCR_sendMessage);
}

void Heavy_PhaseRing::cBinop_tE1Vjy6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hD1kZknj, m);
}

void Heavy_PhaseRing::cBinop_vxWN4o5V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dLoB8SSq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_J1Oktfk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GHUbtC07_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Uwc2pIUu_sendMessage);
}

void Heavy_PhaseRing::cCast_Uwc2pIUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vxWN4o5V, HV_BINOP_DIVIDE, 0, m, &cBinop_vxWN4o5V_sendMessage);
}

void Heavy_PhaseRing::cCast_GHUbtC07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vxWN4o5V, HV_BINOP_DIVIDE, 1, m, &cBinop_vxWN4o5V_sendMessage);
}

void Heavy_PhaseRing::cBinop_ncHkoyIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Ipj5NudO_sendMessage);
}

void Heavy_PhaseRing::cBinop_CXpGODwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_KAkC5ltu_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ipj5NudO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vxWN4o5V, HV_BINOP_DIVIDE, 0, m, &cBinop_vxWN4o5V_sendMessage);
}

void Heavy_PhaseRing::cBinop_G7SLP1Su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fkscfO8s, 0, m, &cPack_fkscfO8s_sendMessage);
}

void Heavy_PhaseRing::cBinop_sH2BDQlp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_J1Oktfk1_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_hj4FDpy3, 0, m, &cPack_hj4FDpy3_sendMessage);
}

void Heavy_PhaseRing::cMsg_T4msOt3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_EBmJ0ZAq, 0, m, &cVar_EBmJ0ZAq_sendMessage);
}

void Heavy_PhaseRing::cMsg_P3bNOFcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_oZMzsfZc, 0, m, &cVar_oZMzsfZc_sendMessage);
}

void Heavy_PhaseRing::cMsg_dLoB8SSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_MbeYeuMO, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_h4LYyq5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wEHupBf1_sendMessage);
}

void Heavy_PhaseRing::cSystem_wEHupBf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ch5P0lM7_sendMessage);
}

void Heavy_PhaseRing::cVar_1J4Szb00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E7XZGKhN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_EQI3hvi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_aw3Auv0y_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_XflmxsNB, m);
}

void Heavy_PhaseRing::cBinop_ch5P0lM7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kTEDW4i5, m);
}

void Heavy_PhaseRing::cMsg_E7XZGKhN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EQI3hvi1_sendMessage);
}

void Heavy_PhaseRing::cBinop_aw3Auv0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fEcRipuq, m);
}

void Heavy_PhaseRing::cVar_FyTt1grn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LbnkeYBg, HV_BINOP_MULTIPLY, 0, m, &cBinop_LbnkeYBg_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ary7YCaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UzY6APst_sendMessage);
}

void Heavy_PhaseRing::cSystem_UzY6APst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rTJ7fin6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_LbnkeYBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_HzqCh9Cg_sendMessage);
}

void Heavy_PhaseRing::cBinop_YAvhqUhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LbnkeYBg, HV_BINOP_MULTIPLY, 1, m, &cBinop_LbnkeYBg_sendMessage);
}

void Heavy_PhaseRing::cMsg_rTJ7fin6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YAvhqUhM_sendMessage);
}

void Heavy_PhaseRing::cBinop_HzqCh9Cg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_shbxIgLQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_shbxIgLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JZTzvTDe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6kNQPpiu, m);
}

void Heavy_PhaseRing::cBinop_JZTzvTDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5xBcNy7o, m);
}

void Heavy_PhaseRing::cBinop_tSqhUSse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_GH8fXfJq_sendMessage);
}

void Heavy_PhaseRing::cBinop_GH8fXfJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jlyzQH5O, m);
}

void Heavy_PhaseRing::cBinop_3DFDSZfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iW01TXaK_sendMessage);
}

void Heavy_PhaseRing::cBinop_iW01TXaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_9XFmsGUb_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TUyeRr88_sendMessage);
}

void Heavy_PhaseRing::cVar_LDx5LZqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_AV7BY80T_sendMessage);
}

void Heavy_PhaseRing::cMsg_fQw92vxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y8cII8bA_sendMessage);
}

void Heavy_PhaseRing::cSystem_y8cII8bA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sKo7NDsQ, HV_BINOP_DIVIDE, 1, m, &cBinop_sKo7NDsQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_9XFmsGUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_xWuNhnEh_sendMessage);
}

void Heavy_PhaseRing::cBinop_xWuNhnEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_V0zuyRmQ, m);
}

void Heavy_PhaseRing::cMsg_AW26ueK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_lAYJdFZJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_lAYJdFZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_3DFDSZfH_sendMessage);
}

void Heavy_PhaseRing::cBinop_TUyeRr88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wuy4GXHc, m);
}

void Heavy_PhaseRing::cBinop_AV7BY80T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_tvmjTVUc_sendMessage);
}

void Heavy_PhaseRing::cBinop_tvmjTVUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sKo7NDsQ, HV_BINOP_DIVIDE, 0, m, &cBinop_sKo7NDsQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_sKo7NDsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AW26ueK6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_oVzTuQ1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_glJUS4FK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_lHjsGWg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R1w4oE7F_sendMessage);
}

void Heavy_PhaseRing::cSystem_R1w4oE7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YGZvalh6_sendMessage);
}

void Heavy_PhaseRing::cDelay_rSHYHpVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rSHYHpVJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZL2maAgx, 0, m, &cDelay_ZL2maAgx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rSHYHpVJ, 0, m, &cDelay_rSHYHpVJ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9qsXjxfx, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_ZL2maAgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZL2maAgx, m);
  cMsg_81IuYFAt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_rkckmXPG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_2Jwrc9rp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_3qnSN8Br_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_udJSmJ2C_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_di1iubhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4aplXd63_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rSHYHpVJ, 2, m, &cDelay_rSHYHpVJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2ZOKeXPM_sendMessage);
}

void Heavy_PhaseRing::cMsg_udJSmJ2C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_di1iubhs, 0, m, &hTable_di1iubhs_sendMessage);
}

void Heavy_PhaseRing::cBinop_YGZvalh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_3qnSN8Br_sendMessage);
}

void Heavy_PhaseRing::cMsg_81IuYFAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_di1iubhs, 0, m, &hTable_di1iubhs_sendMessage);
}

void Heavy_PhaseRing::cCast_2ZOKeXPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rSHYHpVJ, 0, m, &cDelay_rSHYHpVJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_4aplXd63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZL2maAgx, 2, m, &cDelay_ZL2maAgx_sendMessage);
}

void Heavy_PhaseRing::cMsg_2Jwrc9rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9qsXjxfx, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_kpVJHdEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_glJUS4FK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_glJUS4FK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cYQl9xOB, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_k04ha051_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_qdibYfzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oky8ia4i_sendMessage);
}

void Heavy_PhaseRing::cSystem_oky8ia4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pcmXgbw9, HV_BINOP_MULTIPLY, 1, m, &cBinop_pcmXgbw9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CRQYU3Cx, HV_BINOP_MULTIPLY, 1, m, &cBinop_CRQYU3Cx_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_CtvUXtM3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_3GeT87dC_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_3GeT87dC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JC2EMWev_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_VTifhy1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VTifhy1S, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VTifhy1S, 0, m, &cDelay_VTifhy1S_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3oxqrZi3, 0, m, &cVar_3oxqrZi3_sendMessage);
}

void Heavy_PhaseRing::cCast_JC2EMWev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3GeT87dC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VTifhy1S, 0, m, &cDelay_VTifhy1S_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3oxqrZi3, 0, m, &cVar_3oxqrZi3_sendMessage);
}

void Heavy_PhaseRing::cMsg_4CZR7eYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TJNZgJLy_sendMessage);
}

void Heavy_PhaseRing::cSystem_TJNZgJLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vBEM8RyM_sendMessage);
}

void Heavy_PhaseRing::cVar_e43tLdfK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VC7c5Y4Y, HV_BINOP_MULTIPLY, 0, m, &cBinop_VC7c5Y4Y_sendMessage);
}

void Heavy_PhaseRing::cMsg_3GeT87dC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_VTifhy1S, 0, m, &cDelay_VTifhy1S_sendMessage);
}

void Heavy_PhaseRing::cBinop_PiTCD2bI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VTifhy1S, 2, m, &cDelay_VTifhy1S_sendMessage);
}

void Heavy_PhaseRing::cBinop_vBEM8RyM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VC7c5Y4Y, HV_BINOP_MULTIPLY, 1, m, &cBinop_VC7c5Y4Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_VC7c5Y4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_PiTCD2bI_sendMessage);
}

void Heavy_PhaseRing::cVar_3oxqrZi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EsR9cAq5, HV_BINOP_SUBTRACT, 0, m, &cBinop_EsR9cAq5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_9z2aG7et_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_ouKw7BqP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8su4c9gj_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_92xaFQfd_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_8su4c9gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s0MJW3Zb, 0, m, &cVar_s0MJW3Zb_sendMessage);
}

void Heavy_PhaseRing::cCast_92xaFQfd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Jj5JhF7C_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dlUg5s5E_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_psbeYbRV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_r7DOwSFY, 0, m, &cSlice_r7DOwSFY_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HXR8svDD, 0, m, &cSlice_HXR8svDD_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TNVjz9us_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_aU5EkKCJ, 0, m, &cSlice_aU5EkKCJ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_IPfLRWqC, 0, m, &cSlice_IPfLRWqC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C0uRgcpw_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LJc6MsZs_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_r7DOwSFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_XmQc6Ky2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_XmQc6Ky2_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_HXR8svDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XFADctHf_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Nfd0wOVE_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XFADctHf_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Nfd0wOVE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_5Te1m1Sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QU7OI1UL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zAYKASm0_sendMessage);
}

void Heavy_PhaseRing::cVar_bMG4eNhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VO3PfWkd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_VO3PfWkd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jxWVrREb_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pcmXgbw9, HV_BINOP_MULTIPLY, 0, m, &cBinop_pcmXgbw9_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_R9cHW10T, HV_BINOP_DIVIDE, 1, m, &cBinop_R9cHW10T_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_e43tLdfK, 0, m, &cVar_e43tLdfK_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_jxWVrREb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LjIFOYeS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_quOUMNUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XIakjTfO, HV_BINOP_SUBTRACT, 1, m, &cBinop_XIakjTfO_sendMessage);
}

void Heavy_PhaseRing::cVar_73eX4RoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s0MJW3Zb, 0, m, &cVar_s0MJW3Zb_sendMessage);
}

void Heavy_PhaseRing::cVar_s0MJW3Zb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fjKbUf1H, HV_BINOP_ADD, 0, m, &cBinop_fjKbUf1H_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8ZdBOfA, HV_BINOP_ADD, 0, m, &cBinop_R8ZdBOfA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_duR93HYG, 0, m, &cVar_duR93HYG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_CXpGODwI_sendMessage);
}

void Heavy_PhaseRing::cSlice_aU5EkKCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QU7OI1UL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zAYKASm0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_IPfLRWqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z9bj4d3G_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3ey8IAUp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_s0r73XRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3oxqrZi3, 1, m, &cVar_3oxqrZi3_sendMessage);
}

void Heavy_PhaseRing::cBinop_CRQYU3Cx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_s0r73XRA_sendMessage);
}

void Heavy_PhaseRing::cBinop_pcmXgbw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dggPbXzd_sendMessage);
}

void Heavy_PhaseRing::cBinop_dggPbXzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EsR9cAq5, HV_BINOP_SUBTRACT, 1, m, &cBinop_EsR9cAq5_sendMessage);
}

void Heavy_PhaseRing::cBinop_EsR9cAq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3oxqrZi3, 1, m, &cVar_3oxqrZi3_sendMessage);
}

void Heavy_PhaseRing::cMsg_VrJMkHAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_CtvUXtM3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_RBpGk8bP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_CtvUXtM3_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8ZdBOfA, HV_BINOP_ADD, 1, m, &cBinop_R8ZdBOfA_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fjKbUf1H, HV_BINOP_ADD, 1, m, &cBinop_fjKbUf1H_sendMessage);
}

void Heavy_PhaseRing::cBinop_9z2aG7et_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ouKw7BqP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_fjKbUf1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s0MJW3Zb, 1, m, &cVar_s0MJW3Zb_sendMessage);
}

void Heavy_PhaseRing::cBinop_R9cHW10T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NUHGA7By, HV_BINOP_DIVIDE, 1, m, &cBinop_NUHGA7By_sendMessage);
}

void Heavy_PhaseRing::cBinop_NUHGA7By_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8ZdBOfA, HV_BINOP_ADD, 1, m, &cBinop_R8ZdBOfA_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fjKbUf1H, HV_BINOP_ADD, 1, m, &cBinop_fjKbUf1H_sendMessage);
}

void Heavy_PhaseRing::cCast_zAYKASm0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R9cHW10T, HV_BINOP_DIVIDE, 0, m, &cBinop_R9cHW10T_sendMessage);
}

void Heavy_PhaseRing::cCast_QU7OI1UL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CRQYU3Cx, HV_BINOP_MULTIPLY, 0, m, &cBinop_CRQYU3Cx_sendMessage);
}

void Heavy_PhaseRing::cCast_z9bj4d3G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_73eX4RoG, 1, m, &cVar_73eX4RoG_sendMessage);
}

void Heavy_PhaseRing::cCast_3ey8IAUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XIakjTfO, HV_BINOP_SUBTRACT, 0, m, &cBinop_XIakjTfO_sendMessage);
}

void Heavy_PhaseRing::cCast_dlUg5s5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_73eX4RoG, 0, m, &cVar_73eX4RoG_sendMessage);
}

void Heavy_PhaseRing::cCast_Jj5JhF7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RBpGk8bP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_R8ZdBOfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_quOUMNUk, 0, m, &cVar_quOUMNUk_sendMessage);
}

void Heavy_PhaseRing::cMsg_XmQc6Ky2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_CtvUXtM3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_vL8chvWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_5Te1m1Sk, 1, m, &cVar_5Te1m1Sk_sendMessage);
}

void Heavy_PhaseRing::cMsg_LjIFOYeS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pcmXgbw9, HV_BINOP_MULTIPLY, 0, m, &cBinop_pcmXgbw9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R9cHW10T, HV_BINOP_DIVIDE, 1, m, &cBinop_R9cHW10T_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_e43tLdfK, 0, m, &cVar_e43tLdfK_sendMessage);
}

void Heavy_PhaseRing::cCast_XFADctHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XmQc6Ky2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_Nfd0wOVE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VxhSSN1f_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8ZdBOfA, HV_BINOP_ADD, 0, m, &cBinop_R8ZdBOfA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_s0MJW3Zb, 1, m, &cVar_s0MJW3Zb_sendMessage);
}

void Heavy_PhaseRing::cBinop_XIakjTfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NUHGA7By, HV_BINOP_DIVIDE, 0, m, &cBinop_NUHGA7By_sendMessage);
}

void Heavy_PhaseRing::cCast_VxhSSN1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RBpGk8bP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_LJc6MsZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vL8chvWh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_TNVjz9us_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5Te1m1Sk, 0, m, &cVar_5Te1m1Sk_sendMessage);
}

void Heavy_PhaseRing::cCast_C0uRgcpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VrJMkHAB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_duR93HYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_qJSAVXg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vLCot405_sendMessage);
}

void Heavy_PhaseRing::cSystem_vLCot405_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zMnMbRtN, HV_BINOP_MULTIPLY, 1, m, &cBinop_zMnMbRtN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9woa3Tq8, HV_BINOP_MULTIPLY, 1, m, &cBinop_9woa3Tq8_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_tBxAaezP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_ZFypAPWS_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ZFypAPWS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XY2YE4pf_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_c54sncFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c54sncFZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c54sncFZ, 0, m, &cDelay_c54sncFZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Do1XLr0V, 0, m, &cVar_Do1XLr0V_sendMessage);
}

void Heavy_PhaseRing::cCast_XY2YE4pf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZFypAPWS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c54sncFZ, 0, m, &cDelay_c54sncFZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Do1XLr0V, 0, m, &cVar_Do1XLr0V_sendMessage);
}

void Heavy_PhaseRing::cMsg_t200Yi70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yg2cmCQe_sendMessage);
}

void Heavy_PhaseRing::cSystem_yg2cmCQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BKysgBCP_sendMessage);
}

void Heavy_PhaseRing::cVar_uGI9p5ir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1kdUdRTE, HV_BINOP_MULTIPLY, 0, m, &cBinop_1kdUdRTE_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZFypAPWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_c54sncFZ, 0, m, &cDelay_c54sncFZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_qSjfPtTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_c54sncFZ, 2, m, &cDelay_c54sncFZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_BKysgBCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1kdUdRTE, HV_BINOP_MULTIPLY, 1, m, &cBinop_1kdUdRTE_sendMessage);
}

void Heavy_PhaseRing::cBinop_1kdUdRTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_qSjfPtTj_sendMessage);
}

void Heavy_PhaseRing::cVar_Do1XLr0V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gh8zovmI, HV_BINOP_SUBTRACT, 0, m, &cBinop_Gh8zovmI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Pwj8mRxd_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_QLvAZOKA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rnDnU6fk_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FkOVt9yX_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_rnDnU6fk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JXzN7553, 0, m, &cVar_JXzN7553_sendMessage);
}

void Heavy_PhaseRing::cCast_FkOVt9yX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YParIBel_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0NsLFLxS_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_iqBgXd26_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nPUUwWxR, 0, m, &cSlice_nPUUwWxR_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rzOv715X, 0, m, &cSlice_rzOv715X_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1te0Vkid_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_bAbGZS3R, 0, m, &cSlice_bAbGZS3R_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_WDiOlHnO, 0, m, &cSlice_WDiOlHnO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MLURk08d_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bWB9TqAp_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_nPUUwWxR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VWTdCOhy_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_VWTdCOhy_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_rzOv715X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KqxePtA2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DupptDap_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KqxePtA2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DupptDap_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_wmsUdVnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DCVwlEL0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EWsjT9WZ_sendMessage);
}

void Heavy_PhaseRing::cVar_9UPSbwlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uGKhqtjH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_uGKhqtjH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_006zerev_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zMnMbRtN, HV_BINOP_MULTIPLY, 0, m, &cBinop_zMnMbRtN_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_RfIXx4zA, HV_BINOP_DIVIDE, 1, m, &cBinop_RfIXx4zA_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_uGI9p5ir, 0, m, &cVar_uGI9p5ir_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_006zerev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Got9oPtO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_NQY3hqWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hlv6veiz, HV_BINOP_SUBTRACT, 1, m, &cBinop_Hlv6veiz_sendMessage);
}

void Heavy_PhaseRing::cVar_GE7SRatX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JXzN7553, 0, m, &cVar_JXzN7553_sendMessage);
}

void Heavy_PhaseRing::cVar_JXzN7553_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pPKsJL1Z, HV_BINOP_ADD, 0, m, &cBinop_pPKsJL1Z_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NHnxaV1F, HV_BINOP_ADD, 0, m, &cBinop_NHnxaV1F_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k04ha051, 0, m, &cVar_k04ha051_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_MzPhG95i, m);
}

void Heavy_PhaseRing::cSlice_bAbGZS3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DCVwlEL0_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EWsjT9WZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_WDiOlHnO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wkU9EiGO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1jRXP3Dn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_IcazvRmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Do1XLr0V, 1, m, &cVar_Do1XLr0V_sendMessage);
}

void Heavy_PhaseRing::cBinop_9woa3Tq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IcazvRmS_sendMessage);
}

void Heavy_PhaseRing::cBinop_zMnMbRtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HDrXVs9i_sendMessage);
}

void Heavy_PhaseRing::cBinop_HDrXVs9i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gh8zovmI, HV_BINOP_SUBTRACT, 1, m, &cBinop_Gh8zovmI_sendMessage);
}

void Heavy_PhaseRing::cBinop_Gh8zovmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Do1XLr0V, 1, m, &cVar_Do1XLr0V_sendMessage);
}

void Heavy_PhaseRing::cMsg_Prbgdd4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_tBxAaezP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_CalD45JR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_tBxAaezP_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NHnxaV1F, HV_BINOP_ADD, 1, m, &cBinop_NHnxaV1F_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pPKsJL1Z, HV_BINOP_ADD, 1, m, &cBinop_pPKsJL1Z_sendMessage);
}

void Heavy_PhaseRing::cBinop_Pwj8mRxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QLvAZOKA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_pPKsJL1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JXzN7553, 1, m, &cVar_JXzN7553_sendMessage);
}

void Heavy_PhaseRing::cBinop_RfIXx4zA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NShloVBR, HV_BINOP_DIVIDE, 1, m, &cBinop_NShloVBR_sendMessage);
}

void Heavy_PhaseRing::cBinop_NShloVBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NHnxaV1F, HV_BINOP_ADD, 1, m, &cBinop_NHnxaV1F_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pPKsJL1Z, HV_BINOP_ADD, 1, m, &cBinop_pPKsJL1Z_sendMessage);
}

void Heavy_PhaseRing::cCast_DCVwlEL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9woa3Tq8, HV_BINOP_MULTIPLY, 0, m, &cBinop_9woa3Tq8_sendMessage);
}

void Heavy_PhaseRing::cCast_EWsjT9WZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RfIXx4zA, HV_BINOP_DIVIDE, 0, m, &cBinop_RfIXx4zA_sendMessage);
}

void Heavy_PhaseRing::cCast_1jRXP3Dn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hlv6veiz, HV_BINOP_SUBTRACT, 0, m, &cBinop_Hlv6veiz_sendMessage);
}

void Heavy_PhaseRing::cCast_wkU9EiGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GE7SRatX, 1, m, &cVar_GE7SRatX_sendMessage);
}

void Heavy_PhaseRing::cCast_0NsLFLxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GE7SRatX, 0, m, &cVar_GE7SRatX_sendMessage);
}

void Heavy_PhaseRing::cCast_YParIBel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CalD45JR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_NHnxaV1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NQY3hqWK, 0, m, &cVar_NQY3hqWK_sendMessage);
}

void Heavy_PhaseRing::cMsg_VWTdCOhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_tBxAaezP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_I14m2n7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_wmsUdVnr, 1, m, &cVar_wmsUdVnr_sendMessage);
}

void Heavy_PhaseRing::cMsg_Got9oPtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zMnMbRtN, HV_BINOP_MULTIPLY, 0, m, &cBinop_zMnMbRtN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RfIXx4zA, HV_BINOP_DIVIDE, 1, m, &cBinop_RfIXx4zA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uGI9p5ir, 0, m, &cVar_uGI9p5ir_sendMessage);
}

void Heavy_PhaseRing::cCast_DupptDap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wiwjPlAL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NHnxaV1F, HV_BINOP_ADD, 0, m, &cBinop_NHnxaV1F_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JXzN7553, 1, m, &cVar_JXzN7553_sendMessage);
}

void Heavy_PhaseRing::cCast_KqxePtA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VWTdCOhy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Hlv6veiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NShloVBR, HV_BINOP_DIVIDE, 0, m, &cBinop_NShloVBR_sendMessage);
}

void Heavy_PhaseRing::cCast_wiwjPlAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CalD45JR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_1te0Vkid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wmsUdVnr, 0, m, &cVar_wmsUdVnr_sendMessage);
}

void Heavy_PhaseRing::cCast_bWB9TqAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I14m2n7S_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_MLURk08d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Prbgdd4Q_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_Kwi9mtNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_XMNwGU4a, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_n78Luc83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_psbeYbRV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_17eiHbby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_iqBgXd26_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_Ngri1h8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_YdvvNVpk_sendMessage);
}

void Heavy_PhaseRing::cBinop_YdvvNVpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_n78Luc83, 0, m, &cPack_n78Luc83_sendMessage);
}

void Heavy_PhaseRing::cBinop_Z9woiKoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Ngri1h8d_sendMessage);
}

void Heavy_PhaseRing::cCast_s87WRIMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GQWNcRwf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_YiV8OEKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_00QTswrE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_ir5nzFqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_tSqhUSse_sendMessage);
}

void Heavy_PhaseRing::cVar_VX0498Jm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G3o8n0CP_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0MKr4EfR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SQycWATE_sendMessage);
}

void Heavy_PhaseRing::cIf_GGUMi9uf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_zHNStTPa_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_13n3qDp6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_p0yjAMRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fGDEDlZK, HV_BINOP_POW, 0, m, &cBinop_fGDEDlZK_sendMessage);
}

void Heavy_PhaseRing::cBinop_fGDEDlZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Rmm3ULDU, 0, m, &cPack_Rmm3ULDU_sendMessage);
}

void Heavy_PhaseRing::cBinop_2XfcRNRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_n8oTI4lN_sendMessage);
}

void Heavy_PhaseRing::cCast_0MKr4EfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_m7RZOHRs_sendMessage);
}

void Heavy_PhaseRing::cCast_SQycWATE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GGUMi9uf, 0, m, &cIf_GGUMi9uf_sendMessage);
}

void Heavy_PhaseRing::cBinop_m7RZOHRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GGUMi9uf, 1, m, &cIf_GGUMi9uf_sendMessage);
}

void Heavy_PhaseRing::cBinop_13n3qDp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_2XfcRNRK_sendMessage);
}

void Heavy_PhaseRing::cMsg_zHNStTPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_Rmm3ULDU, 0, m, &cPack_Rmm3ULDU_sendMessage);
}

void Heavy_PhaseRing::cBinop_n8oTI4lN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fGDEDlZK, HV_BINOP_POW, 1, m, &cBinop_fGDEDlZK_sendMessage);
  cMsg_p0yjAMRb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_Rmm3ULDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8Db04CFa, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_qTm622iC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3IQoPfiC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_G3o8n0CP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_JoqebE54_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_JoqebE54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CGeTYhkq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_3IQoPfiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Q6trVHsB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_KRMYtzmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p0Xak0kX_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6mydv8Qx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d82Igqg7_sendMessage);
}

void Heavy_PhaseRing::cIf_KbcMiqHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_MeAweJW0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_pkwIFRn6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_P5oD9PSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_U5LltJPu, HV_BINOP_POW, 0, m, &cBinop_U5LltJPu_sendMessage);
}

void Heavy_PhaseRing::cBinop_U5LltJPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_i625RJtJ, 0, m, &cPack_i625RJtJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_uKIS8WPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_qde5GaJV_sendMessage);
}

void Heavy_PhaseRing::cCast_d82Igqg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KbcMiqHM, 0, m, &cIf_KbcMiqHM_sendMessage);
}

void Heavy_PhaseRing::cCast_6mydv8Qx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_PvJ6UtKl_sendMessage);
}

void Heavy_PhaseRing::cBinop_PvJ6UtKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KbcMiqHM, 1, m, &cIf_KbcMiqHM_sendMessage);
}

void Heavy_PhaseRing::cBinop_pkwIFRn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_uKIS8WPn_sendMessage);
}

void Heavy_PhaseRing::cMsg_MeAweJW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_i625RJtJ, 0, m, &cPack_i625RJtJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_qde5GaJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U5LltJPu, HV_BINOP_POW, 1, m, &cBinop_U5LltJPu_sendMessage);
  cMsg_P5oD9PSb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_i625RJtJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QZjWrUld, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_l9sRo4of_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XthpRLCl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_p0Xak0kX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_fvnWW4NZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_fvnWW4NZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5P3ATf5q_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_XthpRLCl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Mus39q4C_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_DbcGz94T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_1e61TXcr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_0uO1tYJj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_0uO1tYJj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_lkrnn5KA_sendMessage);
}

void Heavy_PhaseRing::cCast_4G938n54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_juqRvZoS_sendMessage);
}

void Heavy_PhaseRing::cCast_5fSRnqAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DbcGz94T, 0, m, &cIf_DbcGz94T_sendMessage);
}

void Heavy_PhaseRing::cMsg_1e61TXcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_G3o8n0CP_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0MKr4EfR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SQycWATE_sendMessage);
}

void Heavy_PhaseRing::cBinop_lkrnn5KA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_Aq0jolg9_sendMessage);
}

void Heavy_PhaseRing::cBinop_Aq0jolg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EcpzLE4X_sendMessage);
}

void Heavy_PhaseRing::cBinop_EcpzLE4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G3o8n0CP_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0MKr4EfR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SQycWATE_sendMessage);
}

void Heavy_PhaseRing::cBinop_juqRvZoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DbcGz94T, 1, m, &cIf_DbcGz94T_sendMessage);
}

void Heavy_PhaseRing::cBinop_FKqWKnBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4G938n54_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5fSRnqAU_sendMessage);
}

void Heavy_PhaseRing::cBinop_sWStK7ey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FKqWKnBQ_sendMessage);
}

void Heavy_PhaseRing::cIf_yP2K3iLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_nPl43Ax8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_tADRvrtx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_tADRvrtx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_XlUiIHxh_sendMessage);
}

void Heavy_PhaseRing::cCast_BBLetL9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yP2K3iLI, 0, m, &cIf_yP2K3iLI_sendMessage);
}

void Heavy_PhaseRing::cCast_6lhbtuXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_KEg3atVH_sendMessage);
}

void Heavy_PhaseRing::cMsg_nPl43Ax8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_p0Xak0kX_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6mydv8Qx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d82Igqg7_sendMessage);
}

void Heavy_PhaseRing::cBinop_XlUiIHxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_NoTYvmM5_sendMessage);
}

void Heavy_PhaseRing::cBinop_NoTYvmM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8zLlRkym_sendMessage);
}

void Heavy_PhaseRing::cBinop_8zLlRkym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p0Xak0kX_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6mydv8Qx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d82Igqg7_sendMessage);
}

void Heavy_PhaseRing::cBinop_KEg3atVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yP2K3iLI, 1, m, &cIf_yP2K3iLI_sendMessage);
}

void Heavy_PhaseRing::cBinop_aumQflv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6lhbtuXz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BBLetL9H_sendMessage);
}

void Heavy_PhaseRing::cBinop_Oup6qcLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_aumQflv7_sendMessage);
}

void Heavy_PhaseRing::cVar_fshe9hD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mKasGUv1_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DjbPgT6s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q4DSMf9c_sendMessage);
}

void Heavy_PhaseRing::cIf_IdYY3Gov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WDYYstxb_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_yFPqFGXd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_bFXF02yo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_C3xaycOH, HV_BINOP_POW, 0, m, &cBinop_C3xaycOH_sendMessage);
}

void Heavy_PhaseRing::cBinop_C3xaycOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6UqoDElm, 0, m, &cPack_6UqoDElm_sendMessage);
}

void Heavy_PhaseRing::cBinop_C41yA6dJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_O6xrVV2H_sendMessage);
}

void Heavy_PhaseRing::cCast_DjbPgT6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_6TKdwtYA_sendMessage);
}

void Heavy_PhaseRing::cCast_Q4DSMf9c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IdYY3Gov, 0, m, &cIf_IdYY3Gov_sendMessage);
}

void Heavy_PhaseRing::cBinop_6TKdwtYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IdYY3Gov, 1, m, &cIf_IdYY3Gov_sendMessage);
}

void Heavy_PhaseRing::cBinop_yFPqFGXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_C41yA6dJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_WDYYstxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_6UqoDElm, 0, m, &cPack_6UqoDElm_sendMessage);
}

void Heavy_PhaseRing::cBinop_O6xrVV2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C3xaycOH, HV_BINOP_POW, 1, m, &cBinop_C3xaycOH_sendMessage);
  cMsg_bFXF02yo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_6UqoDElm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_pO1nUgkE, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_hQI7e8aX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZruYMVCo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_mKasGUv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_zjcYKzIz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_zjcYKzIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7PYA8VCW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ZruYMVCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3Blo6BH1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_RU26ydeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YYa2rlhO_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rt7pZ8Ia_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QxTMMv1o_sendMessage);
}

void Heavy_PhaseRing::cIf_f0j9rXFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WpQtI922_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_oBHr1et7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_LBgupFdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_eGcZEuEM, HV_BINOP_POW, 0, m, &cBinop_eGcZEuEM_sendMessage);
}

void Heavy_PhaseRing::cBinop_eGcZEuEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_OBycxFAf, 0, m, &cPack_OBycxFAf_sendMessage);
}

void Heavy_PhaseRing::cBinop_3OJnv4GI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_b7gBlzbY_sendMessage);
}

void Heavy_PhaseRing::cCast_QxTMMv1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f0j9rXFM, 0, m, &cIf_f0j9rXFM_sendMessage);
}

void Heavy_PhaseRing::cCast_Rt7pZ8Ia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_j4BlEb4J_sendMessage);
}

void Heavy_PhaseRing::cBinop_j4BlEb4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f0j9rXFM, 1, m, &cIf_f0j9rXFM_sendMessage);
}

void Heavy_PhaseRing::cBinop_oBHr1et7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_3OJnv4GI_sendMessage);
}

void Heavy_PhaseRing::cMsg_WpQtI922_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_OBycxFAf, 0, m, &cPack_OBycxFAf_sendMessage);
}

void Heavy_PhaseRing::cBinop_b7gBlzbY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eGcZEuEM, HV_BINOP_POW, 1, m, &cBinop_eGcZEuEM_sendMessage);
  cMsg_LBgupFdl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_OBycxFAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_fDOQsrwE, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_kDTAXYYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fcJd8URn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_YYa2rlhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_wqUolYQC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_wqUolYQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FKotlQA8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_fcJd8URn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VPJ6n72T_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_e6jh305m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CnDYVYqo_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WJpf5hes_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qcpyix3y_sendMessage);
}

void Heavy_PhaseRing::cIf_eoHNc2Rw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DPU6WUWC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_R0DtnBHK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_fTctimbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gu1MassY, HV_BINOP_POW, 0, m, &cBinop_gu1MassY_sendMessage);
}

void Heavy_PhaseRing::cBinop_gu1MassY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Uf2zj94R, 0, m, &cPack_Uf2zj94R_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ess0lPEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_GUOXR5oP_sendMessage);
}

void Heavy_PhaseRing::cCast_WJpf5hes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_LcH1cqLs_sendMessage);
}

void Heavy_PhaseRing::cCast_qcpyix3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eoHNc2Rw, 0, m, &cIf_eoHNc2Rw_sendMessage);
}

void Heavy_PhaseRing::cBinop_LcH1cqLs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eoHNc2Rw, 1, m, &cIf_eoHNc2Rw_sendMessage);
}

void Heavy_PhaseRing::cBinop_R0DtnBHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_Ess0lPEr_sendMessage);
}

void Heavy_PhaseRing::cMsg_DPU6WUWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_Uf2zj94R, 0, m, &cPack_Uf2zj94R_sendMessage);
}

void Heavy_PhaseRing::cBinop_GUOXR5oP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gu1MassY, HV_BINOP_POW, 1, m, &cBinop_gu1MassY_sendMessage);
  cMsg_fTctimbn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_Uf2zj94R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_p2v7lRUr, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_PUc6sID5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vwn66V5u_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_CnDYVYqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_yJe85tEt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_yJe85tEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9UPzyFio_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_vwn66V5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_am1PGiv0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_4IETPmub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rre5YOQK, 0, m, &cIf_rre5YOQK_sendMessage);
}

void Heavy_PhaseRing::cSlice_eyw5qIip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_03bXEZs2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0ObPssp6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_dgJ9ywQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_Mwxd9GGa, 0, m, &cIf_Mwxd9GGa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_Mwxd9GGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bVX0FQh3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Li02A3oB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_EvQCPFN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_B4Z9fwPn, 2, m, &cPack_B4Z9fwPn_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_FIqA3x0K, 1, m, &cPack_FIqA3x0K_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_ktCINcPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_eyw5qIip, 0, m, &cSlice_eyw5qIip_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dgJ9ywQw, 0, m, &cSlice_dgJ9ywQw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_Re1vePEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_FClWtqqN_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_6xb3LVQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bV0F4pNq_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4VrgBa8y_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4wEntCgA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_7eZMtrAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DwdssIAR, 1, m, &cIf_DwdssIAR_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_NUDMyrvA_sendMessage);
}

void Heavy_PhaseRing::cIf_DwdssIAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_eyw5qIip, 0, m, &cSlice_eyw5qIip_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dgJ9ywQw, 0, m, &cSlice_dgJ9ywQw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_FIqA3x0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ktCINcPw, 0, m, &cIf_ktCINcPw_sendMessage);
}

void Heavy_PhaseRing::cBinop_NZXeOXLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Mwxd9GGa, 1, m, &cIf_Mwxd9GGa_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_EvQCPFN7, 1, m, &cIf_EvQCPFN7_sendMessage);
}

void Heavy_PhaseRing::cCast_03bXEZs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_NZXeOXLc_sendMessage);
}

void Heavy_PhaseRing::cCast_0ObPssp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EvQCPFN7, 0, m, &cIf_EvQCPFN7_sendMessage);
}

void Heavy_PhaseRing::cMsg_BgyRIeRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_7eZMtrAG, 1, m, &cVar_7eZMtrAG_sendMessage);
}

void Heavy_PhaseRing::cMsg_FClWtqqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_7eZMtrAG, 1, m, &cVar_7eZMtrAG_sendMessage);
}

void Heavy_PhaseRing::cCast_4VrgBa8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FIqA3x0K, 0, m, &cPack_FIqA3x0K_sendMessage);
}

void Heavy_PhaseRing::cCast_4wEntCgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BgyRIeRN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_bV0F4pNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7eZMtrAG, 0, m, &cVar_7eZMtrAG_sendMessage);
}

void Heavy_PhaseRing::cBinop_NUDMyrvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ktCINcPw, 1, m, &cIf_ktCINcPw_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_dmpvjxDM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bp5j8D2I, 0, m, &cSlice_bp5j8D2I_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DAjzTfio, 0, m, &cSlice_DAjzTfio_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_k2mzw6mS, 0, m, &cSlice_k2mzw6mS_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LQkUTVGP, 0, m, &cSlice_LQkUTVGP_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_bp5j8D2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_IwWHqRHS, 0, m, &cSlice_IwWHqRHS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fQrcROrY, 0, m, &cSlice_fQrcROrY_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_IwWHqRHS, 0, m, &cSlice_IwWHqRHS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fQrcROrY, 0, m, &cSlice_fQrcROrY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_DAjzTfio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_87noxniN, 0, m, &cSlice_87noxniN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_VcKrQMbH, 0, m, &cSlice_VcKrQMbH_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_87noxniN, 0, m, &cSlice_87noxniN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_VcKrQMbH, 0, m, &cSlice_VcKrQMbH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_k2mzw6mS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_aGFuVIpq, 0, m, &cSlice_aGFuVIpq_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_BN7cx0Gf, 0, m, &cSlice_BN7cx0Gf_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_aGFuVIpq, 0, m, &cSlice_aGFuVIpq_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_BN7cx0Gf, 0, m, &cSlice_BN7cx0Gf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_LQkUTVGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_L5yRvuNe, 0, m, &cSlice_L5yRvuNe_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_jUBi9E0n, 0, m, &cSlice_jUBi9E0n_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_L5yRvuNe, 0, m, &cSlice_L5yRvuNe_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_jUBi9E0n, 0, m, &cSlice_jUBi9E0n_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_W5w03tOs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DP7SbwiB_sendMessage);
      break;
    }
    default: {
      cMsg_0v2r2voC_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_DP7SbwiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5v1xtNLV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_rre5YOQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Re1vePEX, 0, m, &cSlice_Re1vePEX_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_6xb3LVQz, 0, m, &cSlice_6xb3LVQz_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_DwdssIAR, 0, m, &cIf_DwdssIAR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_mw74KFSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_EGWSuJ9F_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rre5YOQK, 1, m, &cIf_rre5YOQK_sendMessage);
}

void Heavy_PhaseRing::cBinop_EGWSuJ9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mw74KFSk, 1, m, &cVar_mw74KFSk_sendMessage);
}

void Heavy_PhaseRing::cMsg_5v1xtNLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_mw74KFSk, 0, m, &cVar_mw74KFSk_sendMessage);
}

void Heavy_PhaseRing::cMsg_0v2r2voC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_mw74KFSk, 0, m, &cVar_mw74KFSk_sendMessage);
}

void Heavy_PhaseRing::cPack_B4Z9fwPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dmpvjxDM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_QTz2d6xK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_B4Z9fwPn, 0, m, &cPack_B4Z9fwPn_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_RXlo5WmS_sendMessage);
}

void Heavy_PhaseRing::cBinop_RXlo5WmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_vv1eMmtS_sendMessage);
}

void Heavy_PhaseRing::cBinop_vv1eMmtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QTz2d6xK, 1, m, &cVar_QTz2d6xK_sendMessage);
}

void Heavy_PhaseRing::cMsg_Nhjgptrd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_W5w03tOs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_bVX0FQh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_B4Z9fwPn, 1, m, &cPack_B4Z9fwPn_sendMessage);
}

void Heavy_PhaseRing::cCast_Li02A3oB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QTz2d6xK, 0, m, &cVar_QTz2d6xK_sendMessage);
}

void Heavy_PhaseRing::cSend_aHU2tshS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Hjzg4uYz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_Ak3pwYdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YdK90uaw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_b774Isw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_BYdHNLQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_CniJpYWo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_eNwnKfeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Rc9785ac_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_CniJpYWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1J2so8lt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_Rc9785ac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_oErwn0ch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KmVIUYK1_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_qWw8JXuw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cReceive_QgdJnhnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UDa8P0Bc_sendMessage(_c, 0, m);
  cMsg_gIIyvXUg_sendMessage(_c, 0, m);
  cMsg_n87Udfuu_sendMessage(_c, 0, m);
  cMsg_1aS3CeKr_sendMessage(_c, 0, m);
  cMsg_lfJtzrSC_sendMessage(_c, 0, m);
  cMsg_6mQ1y0a0_sendMessage(_c, 0, m);
  cMsg_rR4UAxSk_sendMessage(_c, 0, m);
  cMsg_1AA81F2p_sendMessage(_c, 0, m);
  cMsg_Kq52xoUH_sendMessage(_c, 0, m);
  cMsg_y42S63zF_sendMessage(_c, 0, m);
  cMsg_c5ToNjYa_sendMessage(_c, 0, m);
  cMsg_NJNqgqKU_sendMessage(_c, 0, m);
  cMsg_PoLBZZyH_sendMessage(_c, 0, m);
  cMsg_GE3arVYV_sendMessage(_c, 0, m);
  cMsg_tOclDmI8_sendMessage(_c, 0, m);
  cMsg_Hwej5COh_sendMessage(_c, 0, m);
  cMsg_Pq5XmrtK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Qs45NgZZ, 0, m, &cVar_Qs45NgZZ_sendMessage);
  cMsg_NhKPh8YY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NirfK3pc, 0, m, &cVar_NirfK3pc_sendMessage);
  cMsg_4ouI2Z5g_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rYtsEwgf, 0, m, &cVar_rYtsEwgf_sendMessage);
  cMsg_dukjTsqn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zzeqD4ps, 0, m, &cVar_zzeqD4ps_sendMessage);
  cMsg_NQtYoQQd_sendMessage(_c, 0, m);
  cMsg_bfFhZbUj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vNB7vmoA, 0, m, &cVar_vNB7vmoA_sendMessage);
  cMsg_th8tuY18_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mh8knXVY, 0, m, &cVar_mh8knXVY_sendMessage);
  cMsg_wGubX8K4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DOdxgB2j, 0, m, &cVar_DOdxgB2j_sendMessage);
  cMsg_NxEUb1oB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rHdiT0C4, 0, m, &cVar_rHdiT0C4_sendMessage);
  cMsg_8vbWoyUZ_sendMessage(_c, 0, m);
  cMsg_5hJVKyFu_sendMessage(_c, 0, m);
  cMsg_jt0q6uDk_sendMessage(_c, 0, m);
  cMsg_Y8aveTze_sendMessage(_c, 0, m);
  cMsg_Kt1UMbal_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2IOmky7M, 0, m, &cVar_2IOmky7M_sendMessage);
  cMsg_QaxVgdGB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IiH18POU, 0, m, &cVar_IiH18POU_sendMessage);
  cMsg_0rBuFJr5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BWaZGSbM, 0, m, &cVar_BWaZGSbM_sendMessage);
  cMsg_TebJg4eG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lBsll9s6, 0, m, &cVar_lBsll9s6_sendMessage);
  cMsg_3kraV9na_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4c1I3vMe, 0, m, &cVar_4c1I3vMe_sendMessage);
  cMsg_yCCgodlz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HtGsEAiN, 0, m, &cVar_HtGsEAiN_sendMessage);
  cMsg_qjTIAcAv_sendMessage(_c, 0, m);
  cMsg_fJbomtA2_sendMessage(_c, 0, m);
  cMsg_Ary7YCaR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FyTt1grn, 0, m, &cVar_FyTt1grn_sendMessage);
  cMsg_fQw92vxC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LDx5LZqT, 0, m, &cVar_LDx5LZqT_sendMessage);
  cMsg_lHjsGWg8_sendMessage(_c, 0, m);
  cMsg_4CZR7eYp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_e43tLdfK, 0, m, &cVar_e43tLdfK_sendMessage);
  cMsg_t200Yi70_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uGI9p5ir, 0, m, &cVar_uGI9p5ir_sendMessage);
  cMsg_tBLixq99_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9n1LtUF0, 0, m, &cVar_9n1LtUF0_sendMessage);
  cMsg_4UvcmyZJ_sendMessage(_c, 0, m);
  cMsg_ahuPdt0F_sendMessage(_c, 0, m);
  cMsg_9xYDajdf_sendMessage(_c, 0, m);
  cMsg_IHY8FmlZ_sendMessage(_c, 0, m);
  cMsg_8L30hmBN_sendMessage(_c, 0, m);
  cMsg_q0PFxAgq_sendMessage(_c, 0, m);
  cMsg_tl3GrKB9_sendMessage(_c, 0, m);
  cMsg_A3hKbXbG_sendMessage(_c, 0, m);
  cMsg_MZu8ZgXi_sendMessage(_c, 0, m);
  cMsg_6JmVIw6B_sendMessage(_c, 0, m);
  cMsg_k4EGrYUD_sendMessage(_c, 0, m);
  cMsg_Xy1r0SKW_sendMessage(_c, 0, m);
  cMsg_U4oE9BVq_sendMessage(_c, 0, m);
  cMsg_zOARik7x_sendMessage(_c, 0, m);
  cMsg_1i8u0G25_sendMessage(_c, 0, m);
  cMsg_mhh3Tp4J_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yVIvHqaq, 0, m, &cVar_yVIvHqaq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fggGamqk, 0, m, &cVar_fggGamqk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PphZneDn, 0, m, &cVar_PphZneDn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_q8CjSUa9, 0, m, &cVar_q8CjSUa9_sendMessage);
  cMsg_46pHvWUC_sendMessage(_c, 0, m);
  cMsg_Pp0t5zJc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_f6wVQhqn, 0, m, &cVar_f6wVQhqn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kmaGgIi3, 0, m, &cVar_kmaGgIi3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zgLCLkVt, 0, m, &cVar_zgLCLkVt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_G8tdBE38, 0, m, &cVar_G8tdBE38_sendMessage);
  cMsg_qFMfbyiD_sendMessage(_c, 0, m);
  cMsg_T4msOt3l_sendMessage(_c, 0, m);
  cMsg_P3bNOFcm_sendMessage(_c, 0, m);
  cMsg_kpVJHdEE_sendMessage(_c, 0, m);
  cMsg_qdibYfzg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_quOUMNUk, 0, m, &cVar_quOUMNUk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bMG4eNhl, 0, m, &cVar_bMG4eNhl_sendMessage);
  cMsg_qJSAVXg9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NQY3hqWK, 0, m, &cVar_NQY3hqWK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9UPSbwlV, 0, m, &cVar_9UPSbwlV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DZoGRvWO, 0, m, &cVar_DZoGRvWO_sendMessage);
  cMsg_aQ2TmW7D_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5fCMrO4S, 0, m, &cVar_5fCMrO4S_sendMessage);
  cMsg_4OzIN58z_sendMessage(_c, 0, m);
  cMsg_Z6QeNl6l_sendMessage(_c, 0, m);
  cMsg_1qOHquZg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kE6ziXzN, 0, m, &cVar_kE6ziXzN_sendMessage);
  cMsg_Cqia6yHw_sendMessage(_c, 0, m);
  cMsg_K586Nq2c_sendMessage(_c, 0, m);
  cMsg_ir5nzFqC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VX0498Jm, 0, m, &cVar_VX0498Jm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KRMYtzmF, 0, m, &cVar_KRMYtzmF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fshe9hD2, 0, m, &cVar_fshe9hD2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RU26ydeH, 0, m, &cVar_RU26ydeH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_e6jh305m, 0, m, &cVar_e6jh305m_sendMessage);
  cMsg_Nhjgptrd_sendMessage(_c, 0, m);
  cSwitchcase_KmVIUYK1_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_qWw8JXuw_onMessage(_c, NULL, 0, m, NULL);
  cMsg_hh3t2McM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_D0FpZg8t, 0, m, &cVar_D0FpZg8t_sendMessage);
  cMsg_25jR9CGy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IMwe3nPg, 0, m, &cTabhead_IMwe3nPg_sendMessage);
  cMsg_Rz2lPwaL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_edpZMBKO, 0, m, &cVar_edpZMBKO_sendMessage);
  cMsg_NqoKhHwA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Hg1oudlu, 0, m, &cTabhead_Hg1oudlu_sendMessage);
  cMsg_UFZlFL0Z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uxMuFUYk, 0, m, &cVar_uxMuFUYk_sendMessage);
  cMsg_f9Tuaazq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_dpicMwrf, 0, m, &cTabhead_dpicMwrf_sendMessage);
  cMsg_fmWM30K8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JOarUAdq, 0, m, &cVar_JOarUAdq_sendMessage);
  cMsg_Npz1LOpj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7SacHoqo, 0, m, &cTabhead_7SacHoqo_sendMessage);
  cMsg_mDCqoyc5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DnT4jY1y, 0, m, &cVar_DnT4jY1y_sendMessage);
  cMsg_GRdNAW46_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VlBMV2gL, 0, m, &cTabhead_VlBMV2gL_sendMessage);
  cMsg_6A5Qknck_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UOaRLbba, 0, m, &cVar_UOaRLbba_sendMessage);
  cMsg_Uup5pJ5p_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YMntfmcA, 0, m, &cTabhead_YMntfmcA_sendMessage);
  cMsg_zv0jKid7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CmYwz2BP, 0, m, &cVar_CmYwz2BP_sendMessage);
  cMsg_k1tZpdkr_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HFG71gw9, 0, m, &cTabhead_HFG71gw9_sendMessage);
  cMsg_lUIEYJKO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dBpOBpDz, 0, m, &cVar_dBpOBpDz_sendMessage);
  cMsg_FgaE7LJ4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YcdN9ZMp, 0, m, &cTabhead_YcdN9ZMp_sendMessage);
  cMsg_ZxitS22J_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pMisGsDW, 0, m, &cVar_pMisGsDW_sendMessage);
  cMsg_KQMyeOHq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_iA56AgyJ, 0, m, &cTabhead_iA56AgyJ_sendMessage);
  cMsg_fI0Vg8O0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_a5pMPZMC, 0, m, &cVar_a5pMPZMC_sendMessage);
  cMsg_5evGwmOa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_rCqdHZP6, 0, m, &cTabhead_rCqdHZP6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ow42iGtw, 0, m, &cVar_ow42iGtw_sendMessage);
  cMsg_lMPaacJM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rYglaobA, 0, m, &cVar_rYglaobA_sendMessage);
  cMsg_5SJF4OYC_sendMessage(_c, 0, m);
  cMsg_EurgfTWT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WKqWlziK, 0, m, &cVar_WKqWlziK_sendMessage);
  cMsg_IPYyDhov_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_w0qwgau0, 0, m, &cTabhead_w0qwgau0_sendMessage);
  cMsg_5hj9ow23_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BxVdRu3f, 0, m, &cVar_BxVdRu3f_sendMessage);
  cMsg_6uN0vTuE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_v2DPnjXn, 0, m, &cTabhead_v2DPnjXn_sendMessage);
  cMsg_ctgUHMP3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ech2kDFp, 0, m, &cVar_ech2kDFp_sendMessage);
  cMsg_5lshIHzG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_psRGDwv1, 0, m, &cTabhead_psRGDwv1_sendMessage);
  cMsg_TKrqyhqr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8h7MhJNv, 0, m, &cVar_8h7MhJNv_sendMessage);
  cMsg_PHpljHvd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_hE32Qk0j, 0, m, &cTabhead_hE32Qk0j_sendMessage);
  cMsg_VBrtPaNd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_H4uxYUhj, 0, m, &cVar_H4uxYUhj_sendMessage);
  cMsg_9AJlevEt_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Xh5tBNgx, 0, m, &cTabhead_Xh5tBNgx_sendMessage);
  cMsg_E4kYa4BX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3LSC7hO6, 0, m, &cVar_3LSC7hO6_sendMessage);
  cMsg_aplmmHLU_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sfL9vFkw, 0, m, &cTabhead_sfL9vFkw_sendMessage);
  cMsg_7h0ocG12_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VXcee2tK, 0, m, &cVar_VXcee2tK_sendMessage);
  cMsg_5MO4cvcD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3J7fSdyK, 0, m, &cTabhead_3J7fSdyK_sendMessage);
  cMsg_XNub820P_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iTJJYn8o, 0, m, &cVar_iTJJYn8o_sendMessage);
  cMsg_dATDyHWl_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_0BdrXPb4, 0, m, &cTabhead_0BdrXPb4_sendMessage);
  cMsg_krLQEoVV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_M7VObPq1, 0, m, &cVar_M7VObPq1_sendMessage);
  cMsg_wSFy3KuE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9wfR3ZpS, 0, m, &cTabhead_9wfR3ZpS_sendMessage);
  cMsg_OkdJDUWE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5lTUZVRn, 0, m, &cVar_5lTUZVRn_sendMessage);
  cMsg_zE96OYzg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OCcUsNGd, 0, m, &cTabhead_OCcUsNGd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CarJsOLT, 0, m, &cVar_CarJsOLT_sendMessage);
  cMsg_s0YTwiwl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tD1VKwcs, 0, m, &cVar_tD1VKwcs_sendMessage);
  cMsg_w5quhA0f_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_r1cbd4S9, 0, m, &cVar_r1cbd4S9_sendMessage);
  cMsg_EkcktGkg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1J4Szb00, 0, m, &cVar_1J4Szb00_sendMessage);
  cMsg_h4LYyq5L_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_NCKJrbAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_pJYnbGAE, 0, m, &cSlice_pJYnbGAE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_urQKbdvJ, 0, m, &cSlice_urQKbdvJ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_2d1FImcy, 0, m, &cSlice_2d1FImcy_sendMessage);
}

void Heavy_PhaseRing::cReceive_Hjzg4uYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4IETPmub, 0, m, &cPack_4IETPmub_sendMessage);
}

void Heavy_PhaseRing::cReceive_YdK90uaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4IETPmub, 1, m, &cPack_4IETPmub_sendMessage);
}

void Heavy_PhaseRing::cReceive_fUAu3lOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_y6jt1Vsu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Ch9kt21n, 0, m, &cIf_Ch9kt21n_sendMessage);
}

void Heavy_PhaseRing::cReceive_tooSZXgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_KnfJ54YT_sendMessage);
}

void Heavy_PhaseRing::cReceive_qhshrG6x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_xQjFqcxK, 0, m, &cPack_xQjFqcxK_sendMessage);
}

void Heavy_PhaseRing::cReceive_m0M6e0dU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_LawhudfT_sendMessage);
}

void Heavy_PhaseRing::cReceive_5Svr7oZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cReceive_4JlpZx3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YIe1JmA9_sendMessage);
}

void Heavy_PhaseRing::cReceive_zHaJyGhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uzFF2kWh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0bY1Ngxm_sendMessage);
}

void Heavy_PhaseRing::cReceive_tDey43Le_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oErwn0ch_sendMessage);
}

void Heavy_PhaseRing::cReceive_1J2so8lt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4SgIdkam, 0, m, &cVar_4SgIdkam_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DNHWcE5U, 0, m, &cVar_DNHWcE5U_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IkMvwwrm, 0, m, &cVar_IkMvwwrm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vVGy03qd, 0, m, &cVar_vVGy03qd_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_77hFqgJt, 0, m, &cPack_77hFqgJt_sendMessage);
}

void Heavy_PhaseRing::cReceive_OjDM7nnb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_07fTRTi6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8zEbK0a5, 0, m, &cVar_8zEbK0a5_sendMessage);
}

void Heavy_PhaseRing::cReceive_sdfc8c18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9Ct5EGJa, 0, m, &cPack_9Ct5EGJa_sendMessage);
}

void Heavy_PhaseRing::cReceive_d1x49Idi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bL299idK, 1, m, &cVar_bL299idK_sendMessage);
}

void Heavy_PhaseRing::cReceive_s5MV5ZBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jyfWku8B, m);
}

void Heavy_PhaseRing::cReceive_6rUhGEzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fthTOmvL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mX4DVZwZ, 0, m, &cVar_mX4DVZwZ_sendMessage);
}

void Heavy_PhaseRing::cReceive_zSwVT03B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5x3afAPE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gXLyN6yV, 0, m, &cVar_gXLyN6yV_sendMessage);
}

void Heavy_PhaseRing::cReceive_AxaZx0Zs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wqvqiksN, 0, m, &cVar_wqvqiksN_sendMessage);
}

void Heavy_PhaseRing::cReceive_vpjkkcPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WnDBNe53_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Z08RAmzy_sendMessage);
}

void Heavy_PhaseRing::cReceive_kOAYJe8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2KtwQCdW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WlDCW7Hd, 0, m, &cVar_WlDCW7Hd_sendMessage);
}

void Heavy_PhaseRing::cReceive_hOB01E8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JzHBc5xA, 0, m, &cPack_JzHBc5xA_sendMessage);
}

void Heavy_PhaseRing::cReceive_wvYElEpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KzYhEUqd, 1, m, &cVar_KzYhEUqd_sendMessage);
}

void Heavy_PhaseRing::cReceive_olsP70nX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vpD4GvgD, m);
}

void Heavy_PhaseRing::cReceive_fmTJHBa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xWpkOo3m_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6wIw5zOx, 0, m, &cVar_6wIw5zOx_sendMessage);
}

void Heavy_PhaseRing::cReceive_mUrop4YA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DZtqRyxi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ay6Axlvk, 0, m, &cVar_ay6Axlvk_sendMessage);
}

void Heavy_PhaseRing::cReceive_uBquHsQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FejasjHf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ADFKvGqw, 0, m, &cVar_ADFKvGqw_sendMessage);
}

void Heavy_PhaseRing::cReceive_IEvVTTCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tIeJMhc3, 0, m, &cPack_tIeJMhc3_sendMessage);
}

void Heavy_PhaseRing::cReceive_AQ7bNWxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gdz77FuD, 1, m, &cVar_gdz77FuD_sendMessage);
}

void Heavy_PhaseRing::cReceive_4OYr2W2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_o6uIPriL, m);
}

void Heavy_PhaseRing::cReceive_O9jFyZBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nHLaVdAD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_35ClfaMM, 0, m, &cVar_35ClfaMM_sendMessage);
}

void Heavy_PhaseRing::cReceive_lKrLhBWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lQaljssR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3Mfmya7W, 0, m, &cVar_3Mfmya7W_sendMessage);
}

void Heavy_PhaseRing::cReceive_SeedFGST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_R1UABskU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vNYLbCbD, 0, m, &cVar_vNYLbCbD_sendMessage);
}

void Heavy_PhaseRing::cReceive_gKWyKNrd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0Orw5xlf, 0, m, &cPack_0Orw5xlf_sendMessage);
}

void Heavy_PhaseRing::cReceive_PjEBdfYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tLoaVAEH, 1, m, &cVar_tLoaVAEH_sendMessage);
}

void Heavy_PhaseRing::cReceive_vrykT3kU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_L5VlFBwx, m);
}

void Heavy_PhaseRing::cReceive_JO2kPIbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_B1M0Xcml_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HKC6CFrx, 0, m, &cVar_HKC6CFrx_sendMessage);
}

void Heavy_PhaseRing::cReceive_qkOsjaH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IJpOOscd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1AnGgcMA, 0, m, &cVar_1AnGgcMA_sendMessage);
}

void Heavy_PhaseRing::cReceive_znVjwaSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_MI77bjF1_sendMessage);
}

void Heavy_PhaseRing::cReceive_rU6RmXiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s87WRIMR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YiV8OEKt_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_Kwi9mtNC, 0, m, &cPack_Kwi9mtNC_sendMessage);
}

void Heavy_PhaseRing::cReceive_CGeTYhkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qTm622iC, 0, m, &cVar_qTm622iC_sendMessage);
}

void Heavy_PhaseRing::cReceive_Q6trVHsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0MKr4EfR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SQycWATE_sendMessage);
}

void Heavy_PhaseRing::cReceive_l296PDwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_sWStK7ey_sendMessage);
}

void Heavy_PhaseRing::cReceive_5P3ATf5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_l9sRo4of, 0, m, &cVar_l9sRo4of_sendMessage);
}

void Heavy_PhaseRing::cReceive_Mus39q4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6mydv8Qx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d82Igqg7_sendMessage);
}

void Heavy_PhaseRing::cReceive_Fq2RGNPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_Oup6qcLL_sendMessage);
}

void Heavy_PhaseRing::cReceive_7PYA8VCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hQI7e8aX, 0, m, &cVar_hQI7e8aX_sendMessage);
}

void Heavy_PhaseRing::cReceive_3Blo6BH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DjbPgT6s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q4DSMf9c_sendMessage);
}

void Heavy_PhaseRing::cReceive_FKotlQA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kDTAXYYI, 0, m, &cVar_kDTAXYYI_sendMessage);
}

void Heavy_PhaseRing::cReceive_VPJ6n72T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rt7pZ8Ia_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QxTMMv1o_sendMessage);
}

void Heavy_PhaseRing::cReceive_9UPzyFio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PUc6sID5, 0, m, &cVar_PUc6sID5_sendMessage);
}

void Heavy_PhaseRing::cReceive_am1PGiv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WJpf5hes_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qcpyix3y_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_KupL8rk4, VOf(Bf0));
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
    __hv_line_f(&sLine_yCZ5UF5E, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_jQoJc3jA, VOf(Bf0));
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
    __hv_line_f(&sLine_LCNx6j0h, VOf(Bf5));
    __hv_varread_f(&sVarf_jyfWku8B, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_KU8NrRpw, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_Wiminwiw, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_EKX5j2AH, VOf(Bf3));
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
    __hv_line_f(&sLine_M8zZGzLr, VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_2W9lcyq0, VOf(Bf3));
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
    __hv_line_f(&sLine_P93JhlOV, VOf(Bf1));
    __hv_varread_f(&sVarf_vpD4GvgD, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_y81cXvBh, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_AwubTsXz, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_LB2ew2iH, VOf(Bf6));
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
    __hv_line_f(&sLine_1379S3bt, VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_nf2jQAJ2, VOf(Bf6));
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
    __hv_line_f(&sLine_oUK3aHfG, VOf(Bf3));
    __hv_varread_f(&sVarf_o6uIPriL, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_Zx1Khw9H, VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_2B3idU3w, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_FEpaSRFq, VOf(Bf8));
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
    __hv_line_f(&sLine_ISm6S5dl, VOf(Bf9));
    __hv_phasor_k_f(&sPhasor_wgZ6wBNY, VOf(Bf8));
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
    __hv_line_f(&sLine_DHtymZqR, VOf(Bf6));
    __hv_varread_f(&sVarf_L5VlFBwx, VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_kTXW25HV, VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_0HqE5T6z, VOf(Bf6));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_I23XyPSZ, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_nLRqvWAz, VOf(Bf6));
    __hv_phasor_f(&sPhasor_GPVMkv4M, VIf(Bf6), VOf(Bf6));
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
    __hv_line_f(&sLine_5zxIH7av, VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_ZBbMdwex, VOf(Bf6));
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
    __hv_line_f(&sLine_OWfRZIbw, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_odE54cL6, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_eANBshng, VOf(Bf11));
    __hv_rpole_f(&sRPole_eJkYAeDp, VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_atLVhQqU, VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_ldBCSB6D, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_fDOQsrwE, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf7));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_add_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_pO1nUgkE, VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_8Db04CFa, VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_tabread_f(&sTabread_SCiAZ5ej, VOf(Bf7));
    __hv_varread_f(&sVarf_9QUtcGKm, VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_u8HOxMwx, VOf(Bf0));
    __hv_rpole_f(&sRPole_ukpk8D0G, VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf0));
    __hv_line_f(&sLine_YNdmCaIO, VOf(Bf10));
    __hv_fma_f(VIf(Bf0), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_OCEdvZRu, VOf(Bf0));
    __hv_tabread_f(&sTabread_AkqyJDpE, VOf(Bf5));
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf9));
    __hv_tabread_f(&sTabread_0Af6xxwK, VOf(Bf6));
    __hv_add_f(VIf(Bf9), VIf(Bf6), VOf(Bf1));
    __hv_tabread_f(&sTabread_cdVPKRuV, VOf(Bf8));
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf2));
    __hv_tabread_f(&sTabread_aUfhIf8I, VOf(Bf12));
    __hv_add_f(VIf(Bf2), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_YJ4wweYe, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_YMuJVHKs, VIf(Bf15));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_sgXiCgJ0, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_4ygwkJN6, VIf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_W1KqlR5W, VIf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_6X3zPgzv, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_Wf3JLY5U, VIf(Bf3));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_dJZHmhaK, VOf(Bf13));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_kbnk23zl, VOf(Bf7));
    __hv_varread_f(&sVarf_XB0GKQXA, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_lcZ10pFH, VOf(Bf6));
    __hv_rpole_f(&sRPole_hqZLxa8z, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf7));
    __hv_tabread_f(&sTabread_nX943Mky, VOf(Bf6));
    __hv_varread_f(&sVarf_gqGJq891, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_ZmSFKFZ5, VOf(Bf9));
    __hv_rpole_f(&sRPole_8zMTva9T, VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_tabread_f(&sTabread_9gZBr7Nn, VOf(Bf9));
    __hv_varread_f(&sVarf_5nWro7Fk, VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_P0qK0Zi0, VOf(Bf8));
    __hv_rpole_f(&sRPole_CAijZ5ok, VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf9));
    __hv_add_f(VIf(Bf7), VIf(Bf9), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_IpWOMN7X, VIf(Bf10));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf10));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf8));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_8PaB8R5s, VIf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_sX1AxrfI, VIf(Bf9));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_uLATWRDs, VIf(Bf8));
    __hv_line_f(&sLine_0HprnEfv, VOf(Bf8));
    __hv_mul_f(VIf(Bf14), VIf(Bf8), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf13));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_KJf5FkvN, VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_fUUiNl5n, VIf(Bf6));
    __hv_line_f(&sLine_mzxCLgbx, VOf(Bf8));
    __hv_phasor_f(&sPhasor_bz8atC2r, VIf(Bf8), VOf(Bf8));
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
    __hv_line_f(&sLine_fBjfcEse, VOf(Bf1));
    __hv_line_f(&sLine_HroFg6Ql, VOf(Bf0));
    __hv_fma_f(VIf(Bf8), VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabhead_f(&sTabhead_jXXzowPB, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_zu0z7tLz, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_4Sm3YqjO, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf7));
    __hv_varread_f(&sVarf_cboCLk4T, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_9S29kSto, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_xhNyUEru, VIi(Bi0), VOf(Bf2));
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
    __hv_tabhead_f(&sTabhead_SO9xpg3p, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_mj8lvNqY, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_yIEpzLjm, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf8));
    __hv_varread_f(&sVarf_2sb2Pj7Z, VOf(Bf0));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_WIEDHSU3, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_n7nuVJbz, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf16), VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_zDeJ1jQz, VOf(Bf2));
    __hv_tabhead_f(&sTabhead_2R4kKfLl, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_KPwIzAB8, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_J5FGDDlY, VOf(Bf2));
    __hv_min_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_eVSawrjG, VOf(Bf2));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_WFbcDkNg, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_0IrnFXgc, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf8), VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_RMbLEeSj, VOf(Bf17));
    __hv_rpole_f(&sRPole_LAWhM57q, VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_CFUSDDew, VIf(Bf17), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_dd8sB44J, VOf(Bf17));
    __hv_mul_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_WJEdGXE5, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf17));
    __hv_line_f(&sLine_sEA64x1r, VOf(Bf8));
    __hv_varread_f(&sVarf_KOcUABO6, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_4SKkcWr8, VOf(Bf2));
    __hv_rpole_f(&sRPole_c407WftA, VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_pe0F4E1o, VIf(Bf2));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_A7QOGCN7, VOf(Bf17));
    __hv_varread_f(&sVarf_gjVVJfE2, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_BLcMibJp, VOf(Bf2));
    __hv_min_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_H69Y9moT, VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_varread_f(&sVarf_k8WWzsdp, VOf(Bf2));
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
    __hv_cpole_f(&sCPole_gIMPSaxl, VIf(Bf2), VIf(ZERO), VIf(Bf0), VIf(Bf17), VOf(Bf17), VOf(Bf0));
    __hv_varread_f(&sVarf_rv5Wyvjj, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_wezXNcbi, VOf(Bf17));
    __hv_rpole_f(&sRPole_FXWV1jky, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_K7ZJidyG, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_6qSZ1emO, VOf(Bf17));
    __hv_rpole_f(&sRPole_r7pemxc4, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_aKn3TGo8, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_64AiehE0, VOf(Bf17));
    __hv_rpole_f(&sRPole_G1QLrmt1, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_N1KtBq9B, VOf(Bf0));
    __hv_varread_f(&sVarf_G2FE53kK, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_osWlHqQY, VOf(Bf8));
    __hv_rpole_f(&sRPole_tHuTnwvX, VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf8));
    __hv_line_f(&sLine_X9VNqmng, VOf(Bf2));
    __hv_fma_f(VIf(Bf8), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_9XhIlXlt, VOf(Bf8));
    __hv_tabread_f(&sTabread_tGeCXlmx, VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf12));
    __hv_tabread_f(&sTabread_901JJraY, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_TNEawRUc, VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf18));
    __hv_tabread_f(&sTabread_fCmcOsqk, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf9));
    __hv_tabread_f(&sTabread_7ExfUmls, VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_tw7hAKLU, VIf(Bf5));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_DPtLct7K, VIf(Bf15));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_zNHpzpPC, VIf(Bf7));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_N9lXNEBn, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_zYAn3Pa6, VIf(Bf6));
    __hv_tabwrite_f(&sTabwrite_JDYYESne, VIf(Bf17));
    __hv_add_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_cbnmZkC3, VOf(Bf9));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_TizZqi4E, VOf(Bf0));
    __hv_varread_f(&sVarf_9NEyGJZO, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_s6KrrzVj, VOf(Bf16));
    __hv_rpole_f(&sRPole_JjCc25kf, VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf0));
    __hv_tabread_f(&sTabread_hHyAglfJ, VOf(Bf16));
    __hv_varread_f(&sVarf_B8EERp6p, VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_xCdjK98a, VOf(Bf12));
    __hv_rpole_f(&sRPole_D0Y7KClU, VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf16));
    __hv_tabread_f(&sTabread_ChyqmDJ7, VOf(Bf12));
    __hv_varread_f(&sVarf_FGlaqMDl, VOf(Bf6));
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_YiOdYKWE, VOf(Bf7));
    __hv_rpole_f(&sRPole_J6xHci59, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf12), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf16), VIf(Bf8), VOf(Bf12));
    __hv_add_f(VIf(Bf0), VIf(Bf12), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_j0ichkzQ, VIf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf2));
    __hv_sub_f(VIf(Bf16), VIf(Bf8), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf7), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_g8tuq0tx, VIf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_zK6oCu99, VIf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_y26wtbcY, VIf(Bf7));
    __hv_line_f(&sLine_fcBaLfBX, VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf16), VIf(Bf7), VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_XMNwGU4a, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_soY6jzND, VIf(Bf10));
    __hv_line_f(&sLine_MbeYeuMO, VOf(Bf10));
    __hv_phasor_f(&sPhasor_TgISGE7R, VIf(Bf10), VOf(Bf10));
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
    __hv_line_f(&sLine_mzMT2qN8, VOf(Bf2));
    __hv_line_f(&sLine_gLJMVqkf, VOf(Bf3));
    __hv_fma_f(VIf(Bf10), VIf(Bf2), VIf(Bf3), VOf(Bf0));
    __hv_tabhead_f(&sTabhead_W1H5osb5, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_BWFUYOzV, VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_Rq8Q8I6Y, VOf(Bf0));
    __hv_min_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf9));
    __hv_varread_f(&sVarf_6TBiKZ6y, VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_sLHRrj5Y, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_N3mTSvnR, VIi(Bi0), VOf(Bf0));
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
    __hv_tabhead_f(&sTabhead_MBqnYgup, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf10), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_nJdQMaL3, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_hD1kZknj, VOf(Bf3));
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf10));
    __hv_varread_f(&sVarf_19bbDObM, VOf(Bf3));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_OqKPN3Uy, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_8EVL16eC, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf1), VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_MzPhG95i, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_CjTR0srb, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_kTEDW4i5, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_fEcRipuq, VOf(Bf0));
    __hv_min_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_XflmxsNB, VOf(Bf0));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_9bagjJ0g, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_MAi0f6JL, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf10));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf10), VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_wuy4GXHc, VOf(Bf15));
    __hv_rpole_f(&sRPole_cRmWxyf0, VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_rLW9lDlP, VIf(Bf15), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_V0zuyRmQ, VOf(Bf15));
    __hv_mul_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_jlyzQH5O, VOf(Bf0));
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf15));
    __hv_line_f(&sLine_cYQl9xOB, VOf(Bf10));
    __hv_varread_f(&sVarf_6kNQPpiu, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_5xBcNy7o, VOf(Bf0));
    __hv_rpole_f(&sRPole_2xySuOO2, VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_9qsXjxfx, VIf(Bf0));
    __hv_var_k_f(VOf(Bf0), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf14), VIf(Bf0), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_p2v7lRUr, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_QZjWrUld, VOf(Bf11));
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

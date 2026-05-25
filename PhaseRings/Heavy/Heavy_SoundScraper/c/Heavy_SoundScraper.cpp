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
  numBytes += sRPole_init(&sRPole_wIDQ6C6Z);
  numBytes += sLine_init(&sLine_tK764FaY);
  numBytes += sPhasor_k_init(&sPhasor_inmxr9Es, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_hIJtDmsi);
  numBytes += sSamphold_init(&sSamphold_amKviKQx);
  numBytes += sDel1_init(&sDel1_ATjOjaDZ);
  numBytes += sSamphold_init(&sSamphold_FkliRt2O);
  numBytes += sTabread_init(&sTabread_MBtSkfgm, &hTable_HHfueTlC, false);
  numBytes += sTabread_init(&sTabread_m5nbA8ZB, &hTable_HHfueTlC, false);
  numBytes += sDel1_init(&sDel1_2AGiVuMi);
  numBytes += sSamphold_init(&sSamphold_Qi9pzIqD);
  numBytes += sDel1_init(&sDel1_WdVty1oU);
  numBytes += sSamphold_init(&sSamphold_izQfT84g);
  numBytes += sTabread_init(&sTabread_gdL4Gw2I, &hTable_HHfueTlC, false);
  numBytes += sTabread_init(&sTabread_fFaWN2KY, &hTable_HHfueTlC, false);
  numBytes += sRPole_init(&sRPole_NpOYHH4D);
  numBytes += sDel1_init(&sDel1_2cauPm0C);
  numBytes += sLine_init(&sLine_tXvT6cHz);
  numBytes += sLine_init(&sLine_f5d8zUwC);
  numBytes += sTabread_init(&sTabread_5XEyxLUF, &hTable_HHfueTlC, false);
  numBytes += sTabread_init(&sTabread_fwyz1fM4, &hTable_HHfueTlC, false);
  numBytes += sLine_init(&sLine_IZFTWrFD);
  numBytes += sLine_init(&sLine_EQgeWPIP);
  numBytes += sLine_init(&sLine_HtLLvVBA);
  numBytes += sLine_init(&sLine_f52ztb7P);
  numBytes += sLine_init(&sLine_ocH3PVC3);
  numBytes += sTabread_init(&sTabread_Q8eCgjLK, &hTable_HHfueTlC, false);
  numBytes += sTabread_init(&sTabread_RtoSlKmF, &hTable_HHfueTlC, false);
  numBytes += sLine_init(&sLine_6345v7Wq);
  numBytes += sLine_init(&sLine_kj4HFN8n);
  numBytes += sLine_init(&sLine_82VLZeYw);
  numBytes += sLine_init(&sLine_b6lztIzY);
  numBytes += sLine_init(&sLine_EUbnU3Vo);
  numBytes += sTabread_init(&sTabread_Yuwr9mH4, &hTable_HHfueTlC, false);
  numBytes += sTabread_init(&sTabread_ar4OAyRU, &hTable_HHfueTlC, false);
  numBytes += sLine_init(&sLine_DUoEC9ee);
  numBytes += sLine_init(&sLine_YE8VdnqH);
  numBytes += sLine_init(&sLine_JnO3n7dX);
  numBytes += sLine_init(&sLine_jQdRQLfi);
  numBytes += sLine_init(&sLine_U6KocVLC);
  numBytes += sTabread_init(&sTabread_8ZhUxK3H, &hTable_HHfueTlC, false);
  numBytes += sTabread_init(&sTabread_JpeD1zqd, &hTable_HHfueTlC, false);
  numBytes += sLine_init(&sLine_2iPDAcPG);
  numBytes += sLine_init(&sLine_2bVg3iUv);
  numBytes += sLine_init(&sLine_3PNAFvQS);
  numBytes += sLine_init(&sLine_UOTAVrEi);
  numBytes += sLine_init(&sLine_bFszP7fh);
  numBytes += sLine_init(&sLine_mQrqDsTx);
  numBytes += sLine_init(&sLine_4zhPJk2l);
  numBytes += sLine_init(&sLine_JASCXvgB);
  numBytes += sLine_init(&sLine_OohGk3Ir);
  numBytes += sTabwrite_init(&sTabwrite_MCWLDrhL, &hTable_Uit9aCmF);
  numBytes += sLine_init(&sLine_PY90kPB2);
  numBytes += sPhasor_init(&sPhasor_Jqg70Oi2, sampleRate);
  numBytes += sLine_init(&sLine_TLP1ZLXH);
  numBytes += sLine_init(&sLine_Sl3jLFYS);
  numBytes += sTabhead_init(&sTabhead_wS5HdcrQ, &hTable_Uit9aCmF);
  numBytes += sTabread_init(&sTabread_c0d74f60, &hTable_Uit9aCmF, false);
  numBytes += sTabread_init(&sTabread_xCBhyFkM, &hTable_Uit9aCmF, false);
  numBytes += sTabhead_init(&sTabhead_dvOKoNRm, &hTable_Uit9aCmF);
  numBytes += sTabread_init(&sTabread_JwDQeq3l, &hTable_Uit9aCmF, false);
  numBytes += sTabread_init(&sTabread_i6eBd8Qe, &hTable_Uit9aCmF, false);
  numBytes += sTabhead_init(&sTabhead_UwpCsv8D, &hTable_VjaqfHY6);
  numBytes += sTabread_init(&sTabread_C5sDjHkg, &hTable_VjaqfHY6, false);
  numBytes += sTabread_init(&sTabread_z70eyCVD, &hTable_VjaqfHY6, false);
  numBytes += sRPole_init(&sRPole_LzynpEQc);
  numBytes += sDel1_init(&sDel1_IIH3c9lw);
  numBytes += sLine_init(&sLine_htrZRFu9);
  numBytes += sRPole_init(&sRPole_vS9ig7qD);
  numBytes += sTabwrite_init(&sTabwrite_nG1E8QsX, &hTable_VjaqfHY6);
  numBytes += sTabread_init(&sTabread_nFsiV9AO, &hTable_jVtpceAv, true);
  numBytes += sRPole_init(&sRPole_oeOv1VAI);
  numBytes += sLine_init(&sLine_NwAX0XzW);
  numBytes += sLine_init(&sLine_9Nru90GF);
  numBytes += sTabread_init(&sTabread_SoEfIq3Q, &hTable_G8HwV53M, true);
  numBytes += sTabread_init(&sTabread_ByuHBIhT, &hTable_ex1q5Loa, true);
  numBytes += sTabread_init(&sTabread_lGiNSqRS, &hTable_JhfOlUP4, true);
  numBytes += sTabread_init(&sTabread_vUJLchAb, &hTable_9zLfnrf6, true);
  numBytes += sTabread_init(&sTabread_G8BLlR3M, &hTable_OeabZUPW, true);
  numBytes += sTabwrite_init(&sTabwrite_SZxDX6FQ, &hTable_S8GYBCus);
  numBytes += sTabwrite_init(&sTabwrite_wHZ96ogv, &hTable_OeabZUPW);
  numBytes += sTabwrite_init(&sTabwrite_bDVtTEPH, &hTable_9zLfnrf6);
  numBytes += sTabwrite_init(&sTabwrite_wX3f1zdF, &hTable_JhfOlUP4);
  numBytes += sTabwrite_init(&sTabwrite_qZiwZj50, &hTable_ex1q5Loa);
  numBytes += sTabwrite_init(&sTabwrite_YUCcfRYV, &hTable_G8HwV53M);
  numBytes += sTabread_init(&sTabread_8TiO2QqT, &hTable_S8GYBCus, true);
  numBytes += sTabread_init(&sTabread_6MpUprMM, &hTable_gQm9T15j, true);
  numBytes += sRPole_init(&sRPole_12Slqcep);
  numBytes += sTabread_init(&sTabread_WDZcyJFx, &hTable_Mv6L78uO, true);
  numBytes += sRPole_init(&sRPole_cez6Yleu);
  numBytes += sTabread_init(&sTabread_zQySRaOQ, &hTable_HTdiw5Pz, true);
  numBytes += sRPole_init(&sRPole_JcBxRs6z);
  numBytes += sTabwrite_init(&sTabwrite_2ikyDYvr, &hTable_jVtpceAv);
  numBytes += sTabwrite_init(&sTabwrite_0O7eryX8, &hTable_gQm9T15j);
  numBytes += sTabwrite_init(&sTabwrite_66PkRnAr, &hTable_Mv6L78uO);
  numBytes += sTabwrite_init(&sTabwrite_m04BFh4L, &hTable_HTdiw5Pz);
  numBytes += sLine_init(&sLine_M44fhw6G);
  numBytes += sLine_init(&sLine_F8AciC1G);
  numBytes += sTabwrite_init(&sTabwrite_Y9SpFGiB, &hTable_q07YJFQv);
  numBytes += sLine_init(&sLine_2I9ucnEo);
  numBytes += sPhasor_init(&sPhasor_wvK9R4px, sampleRate);
  numBytes += sLine_init(&sLine_P6XQRzFt);
  numBytes += sLine_init(&sLine_e7rlnpyz);
  numBytes += sTabhead_init(&sTabhead_1fHAF4hG, &hTable_q07YJFQv);
  numBytes += sTabread_init(&sTabread_QdqR7BMc, &hTable_q07YJFQv, false);
  numBytes += sTabread_init(&sTabread_t6kL1d2b, &hTable_q07YJFQv, false);
  numBytes += sTabhead_init(&sTabhead_TTcAz6zL, &hTable_q07YJFQv);
  numBytes += sTabread_init(&sTabread_j789nZrI, &hTable_q07YJFQv, false);
  numBytes += sTabread_init(&sTabread_TqYniTcz, &hTable_q07YJFQv, false);
  numBytes += sTabhead_init(&sTabhead_5PrH694i, &hTable_vbDgCxW0);
  numBytes += sTabread_init(&sTabread_YfE4TQFG, &hTable_vbDgCxW0, false);
  numBytes += sTabread_init(&sTabread_jt8ydAGk, &hTable_vbDgCxW0, false);
  numBytes += sRPole_init(&sRPole_A5azKhnC);
  numBytes += sDel1_init(&sDel1_O1LEs9mp);
  numBytes += sLine_init(&sLine_wk7ewaKj);
  numBytes += sRPole_init(&sRPole_gyJlU0GT);
  numBytes += sTabwrite_init(&sTabwrite_tnwfmDNO, &hTable_vbDgCxW0);
  numBytes += sCPole_init(&sCPole_aDdSLmuG);
  numBytes += sRPole_init(&sRPole_1jvIb09Y);
  numBytes += sRPole_init(&sRPole_MKmAq8VK);
  numBytes += sRPole_init(&sRPole_JsaATWUv);
  numBytes += sTabread_init(&sTabread_AgVlguab, &hTable_z6CszX9t, true);
  numBytes += sRPole_init(&sRPole_xBVLRNeQ);
  numBytes += sLine_init(&sLine_ZD8R3tt7);
  numBytes += sLine_init(&sLine_eYnFYIuf);
  numBytes += sTabread_init(&sTabread_0IZ8nORU, &hTable_bmegWqSo, true);
  numBytes += sTabread_init(&sTabread_mgIVHQem, &hTable_rWE9zngZ, true);
  numBytes += sTabread_init(&sTabread_4suNHM9o, &hTable_msxcGeza, true);
  numBytes += sTabread_init(&sTabread_aoPyPNhj, &hTable_VpWyHd8s, true);
  numBytes += sTabread_init(&sTabread_dZv9KKUM, &hTable_VNnMcNUN, true);
  numBytes += sTabwrite_init(&sTabwrite_OS5yf72n, &hTable_n2E9gz35);
  numBytes += sTabwrite_init(&sTabwrite_NdM6mKe9, &hTable_VNnMcNUN);
  numBytes += sTabwrite_init(&sTabwrite_w0GnQ7af, &hTable_VpWyHd8s);
  numBytes += sTabwrite_init(&sTabwrite_1YrWt7oa, &hTable_msxcGeza);
  numBytes += sTabwrite_init(&sTabwrite_hMzDiWdn, &hTable_rWE9zngZ);
  numBytes += sTabwrite_init(&sTabwrite_HuOBa9aL, &hTable_bmegWqSo);
  numBytes += sTabread_init(&sTabread_5wnKoKew, &hTable_n2E9gz35, true);
  numBytes += sTabread_init(&sTabread_OxZuBhjs, &hTable_56JzGsTx, true);
  numBytes += sRPole_init(&sRPole_5av99rbs);
  numBytes += sTabread_init(&sTabread_7M44m0bj, &hTable_vfuj0syF, true);
  numBytes += sRPole_init(&sRPole_BQv3FcO4);
  numBytes += sTabread_init(&sTabread_eh90VO1r, &hTable_VVkTmdpB, true);
  numBytes += sRPole_init(&sRPole_MywAw9kY);
  numBytes += sTabwrite_init(&sTabwrite_uZX5lcGt, &hTable_z6CszX9t);
  numBytes += sTabwrite_init(&sTabwrite_jSjQlYAw, &hTable_56JzGsTx);
  numBytes += sTabwrite_init(&sTabwrite_JimkW3VP, &hTable_vfuj0syF);
  numBytes += sTabwrite_init(&sTabwrite_75MO2qRU, &hTable_VVkTmdpB);
  numBytes += sLine_init(&sLine_6tzZEzTm);
  numBytes += sLine_init(&sLine_UwfEmNoc);
  numBytes += sLine_init(&sLine_Oa55Ct8W);
  numBytes += cSlice_init(&cSlice_gF56NqnA, 2, 1);
  numBytes += cSlice_init(&cSlice_3Bx5Ot5o, 1, 1);
  numBytes += cSlice_init(&cSlice_Kock4fG4, 0, 1);
  numBytes += cVar_init_f(&cVar_7N875SnD, 0.0f);
  numBytes += cIf_init(&cIf_ZvTiOJ4O, false);
  numBytes += cIf_init(&cIf_XLwhqs0c, false);
  numBytes += cIf_init(&cIf_y2cA8LPd, false);
  numBytes += cIf_init(&cIf_yeo6MZB3, false);
  numBytes += cIf_init(&cIf_eZZV4EIB, false);
  numBytes += cBinop_init(&cBinop_9cWutWzx, 0.0f); // __eq
  numBytes += cVar_init_s(&cVar_HucbY6X7, "floatatom");
  numBytes += cVar_init_s(&cVar_Tg8Au3QT, "floatatom");
  numBytes += cVar_init_f(&cVar_Xg9WxPwm, 1.0f);
  numBytes += cVar_init_f(&cVar_Zk6PBzoj, 0.0f);
  numBytes += cVar_init_f(&cVar_8uc0FXbI, 0.0f);
  numBytes += cVar_init_f(&cVar_z7EP3Xmj, 127.0f);
  numBytes += cRandom_init(&cRandom_tHqbwidA, 277379459);
  numBytes += cSlice_init(&cSlice_Q3zZiFEX, 1, 1);
  numBytes += cVar_init_s(&cVar_CDjeilGe, "floatatom");
  numBytes += cVar_init_f(&cVar_GDs39y5O, 98.0f);
  numBytes += cIf_init(&cIf_DcUQPLEO, false);
  numBytes += cBinop_init(&cBinop_GJ2kjPIJ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_nHSSkW9R, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_J8TVZyOD, 0.0f);
  numBytes += cRandom_init(&cRandom_3QzWnPi7, -1715779385);
  numBytes += cSlice_init(&cSlice_P9ZCm75R, 1, 1);
  numBytes += cRandom_init(&cRandom_p6dCP7h0, 591443104);
  numBytes += cSlice_init(&cSlice_D54xwlyF, 1, 1);
  numBytes += cVar_init_s(&cVar_eIzA0tC9, "floatatom");
  numBytes += cPack_init(&cPack_tCyLDNoF, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_6raKcuXb, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_bI5hokle, "floatatom");
  numBytes += cDelay_init(this, &cDelay_i5BwdoVw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FLua5l0E, 0.0f);
  numBytes += hTable_init(&hTable_Uit9aCmF, 256);
  numBytes += cVar_init_s(&cVar_PN001S4G, "del-1040-del");
  numBytes += sVarf_init(&sVarf_835RoTyx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yYrneiOh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_K0vHWCYf, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_uzhe3rDr, "del-1040-del");
  numBytes += sVarf_init(&sVarf_1Rbyu1Lv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LxAAAM9K, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9KYbO0mX, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_Q8HfAfjy, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_N1bIU3am, "del-1069-del1");
  numBytes += sVarf_init(&sVarf_dlr9Ba7U, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Q8Ak7iaw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_s4Q9Jbe6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3nW7GnM9, 10000.0f);
  numBytes += cBinop_init(&cBinop_ce4BzkMc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_IoBKSN30, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_AMaSOcaw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LV0rKBrz, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9qBCLUOw, 10.0f);
  numBytes += cBinop_init(&cBinop_TrKAhKro, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_lXuvEeCN, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_9VennEtx, "floatatom");
  numBytes += sVarf_init(&sVarf_pB9AS2GX, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_cRPiguM3, 0.0f);
  numBytes += cDelay_init(this, &cDelay_jnVq5i5C, 0.0f);
  numBytes += hTable_init(&hTable_VjaqfHY6, 256);
  numBytes += sVarf_init(&sVarf_8MKDWaXg, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_aC5Lb8WF, "floatatom");
  numBytes += cDelay_init(this, &cDelay_WLI5CSPo, 0.0f);
  numBytes += cVar_init_f(&cVar_Q91BSv1o, 20.0f);
  numBytes += cBinop_init(&cBinop_YpcVFBqW, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_5KJPGZyt, 0.0f);
  numBytes += cSlice_init(&cSlice_WjvfUKvL, 1, -1);
  numBytes += cSlice_init(&cSlice_aVP9NMtl, 1, -1);
  numBytes += cVar_init_f(&cVar_f3G9Xswv, 0.0f);
  numBytes += cVar_init_f(&cVar_bZuQslVf, 20.0f);
  numBytes += cVar_init_f(&cVar_ik3F8Xlw, 0.0f);
  numBytes += cVar_init_f(&cVar_7z1ccC1S, 0.0f);
  numBytes += cVar_init_f(&cVar_zBdwzDkG, 0.0f);
  numBytes += cSlice_init(&cSlice_GWsfrkn3, 1, 1);
  numBytes += cSlice_init(&cSlice_Lf7MwPbN, 0, 1);
  numBytes += cBinop_init(&cBinop_m30CkHPG, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_vyCB5Vbh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BpDJExe3, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_GorsA9Zs, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_izGr7zaA, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_jfnS550B, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_nOdN8OEK, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Loff5IxV, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_TxffXSoW, "floatatom");
  numBytes += cPack_init(&cPack_oqMjOJOt, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_adVBMXBT, 0.0f);
  numBytes += cVar_init_f(&cVar_RCkRsSmF, 20.0f);
  numBytes += cBinop_init(&cBinop_tyKV4AeD, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Au2VEMBJ, 0.0f);
  numBytes += cSlice_init(&cSlice_y903FRi5, 1, -1);
  numBytes += cSlice_init(&cSlice_XDafsAN3, 1, -1);
  numBytes += cVar_init_f(&cVar_L8UlPwqZ, 0.0f);
  numBytes += cVar_init_f(&cVar_N1f2HKgs, 20.0f);
  numBytes += cVar_init_f(&cVar_onsg4u3h, 0.0f);
  numBytes += cVar_init_f(&cVar_6SJNRTTi, 0.0f);
  numBytes += cVar_init_f(&cVar_OknhBpGK, 0.0f);
  numBytes += cSlice_init(&cSlice_wXsWnoml, 1, 1);
  numBytes += cSlice_init(&cSlice_SX2gz6TU, 0, 1);
  numBytes += cBinop_init(&cBinop_6DEUeD3x, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Rnlv7z23, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_MiWsi1e2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3jT15HkF, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_lQEEZx9u, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_8EUMUr8T, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Tp8kAiT3, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_9InVqm0D, 0.0f); // __sub
  numBytes += cPack_init(&cPack_QAKFCTX9, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_c2NkkjaU, 2, 0.0f, 1000.0f);
  numBytes += cTabhead_init(&cTabhead_Qh2iF1Sj, &hTable_jVtpceAv);
  numBytes += cVar_init_s(&cVar_N2NHHKUW, "del-1130-del1");
  numBytes += cDelay_init(this, &cDelay_hN4BhCmi, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_vb6xx54b, 0.0f);
  numBytes += cBinop_init(&cBinop_CP91iWNe, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_rdYxvAIJ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Bxaf95Up, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_570DlWZp, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_cEOFa9Kl, &hTable_gQm9T15j);
  numBytes += cVar_init_s(&cVar_91mfJLLA, "del-1130-del2");
  numBytes += cDelay_init(this, &cDelay_Z60FoEOn, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_HHr1cBoN, 0.0f);
  numBytes += cBinop_init(&cBinop_4LPlUMtz, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_8kyHTbko, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_aFMyJUD1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NTP0h5fK, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_bp9JVud4, &hTable_Mv6L78uO);
  numBytes += cVar_init_s(&cVar_Pmrs8wcP, "del-1130-del3");
  numBytes += cDelay_init(this, &cDelay_fwHCxVfp, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_kr4buJMe, 0.0f);
  numBytes += cBinop_init(&cBinop_npoaxeV9, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_yAXkaPhF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_XDTdvHly, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NCLG9BG8, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_lPUxqSYh, &hTable_HTdiw5Pz);
  numBytes += cVar_init_s(&cVar_SsZVtlwB, "del-1130-del4");
  numBytes += cDelay_init(this, &cDelay_UY4jLKN2, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_L0eXs9ie, 0.0f);
  numBytes += cBinop_init(&cBinop_pD1O0wXw, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_ahGZoAVL, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_flOP5uoC, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_rJPaCtBg, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_NXBsLqcV, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vHoaYqN0, 0.0f);
  numBytes += hTable_init(&hTable_jVtpceAv, 256);
  numBytes += cDelay_init(this, &cDelay_QSKIifgy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8ob8fF4w, 0.0f);
  numBytes += hTable_init(&hTable_gQm9T15j, 256);
  numBytes += cDelay_init(this, &cDelay_12fD6C6i, 0.0f);
  numBytes += cDelay_init(this, &cDelay_c02UmLkQ, 0.0f);
  numBytes += hTable_init(&hTable_Mv6L78uO, 256);
  numBytes += cDelay_init(this, &cDelay_o4K1kFX8, 0.0f);
  numBytes += cDelay_init(this, &cDelay_eOTbDkMZ, 0.0f);
  numBytes += hTable_init(&hTable_HTdiw5Pz, 256);
  numBytes += cIf_init(&cIf_1BvcWK6l, false);
  numBytes += cBinop_init(&cBinop_FTz7s88m, 0.0f); // __pow
  numBytes += cPack_init(&cPack_I78PYX3u, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_SaMhCDYJ, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_oLcsMzos, 22050.0f);
  numBytes += cBinop_init(&cBinop_GnzueuSa, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dgefkAVN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qUR4c4DW, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mK8fl5jB, 95.0f);
  numBytes += cVar_init_f(&cVar_3ImaLLeR, 90.0f);
  numBytes += cVar_init_f(&cVar_Fdnkb8K0, 6000.0f);
  numBytes += cVar_init_f(&cVar_92ThOhVl, 60.0f);
  numBytes += cIf_init(&cIf_xYurcsoE, false);
  numBytes += cTabhead_init(&cTabhead_F4qsxLkm, &hTable_S8GYBCus);
  numBytes += cVar_init_s(&cVar_3uYo4STR, "del-1130-ref6");
  numBytes += cDelay_init(this, &cDelay_YPO78Xqa, 13.645f);
  numBytes += cDelay_init(this, &cDelay_7KlBi9AA, 0.0f);
  numBytes += cBinop_init(&cBinop_LgjrOjXo, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_FiIjB6wP, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_OwlpPLn1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_9KlqjE4q, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_lt64u1ue, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kM72QB8P, 0.0f);
  numBytes += hTable_init(&hTable_S8GYBCus, 256);
  numBytes += cTabhead_init(&cTabhead_khqdUWnu, &hTable_OeabZUPW);
  numBytes += cVar_init_s(&cVar_g3v5JQlq, "del-1130-ref5");
  numBytes += cDelay_init(this, &cDelay_nzvWKIOF, 16.364f);
  numBytes += cDelay_init(this, &cDelay_0qtHhzwn, 0.0f);
  numBytes += cBinop_init(&cBinop_pVruW4r2, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_551qRvkT, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ABoRvidT, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_sWiCjcSa, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_RR0g8MO7, 0.0f);
  numBytes += cDelay_init(this, &cDelay_N16IhPqm, 0.0f);
  numBytes += hTable_init(&hTable_OeabZUPW, 256);
  numBytes += cTabhead_init(&cTabhead_uIOqhkAA, &hTable_9zLfnrf6);
  numBytes += cVar_init_s(&cVar_7aLtqAgc, "del-1130-ref4");
  numBytes += cDelay_init(this, &cDelay_MttZITON, 19.392f);
  numBytes += cDelay_init(this, &cDelay_IUNIzeOY, 0.0f);
  numBytes += cBinop_init(&cBinop_djFyWzPi, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_xPhWy2S4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_RluzQyTv, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_B7d41DHI, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_tixNIH3R, 0.0f);
  numBytes += cDelay_init(this, &cDelay_37Ik0mJY, 0.0f);
  numBytes += hTable_init(&hTable_9zLfnrf6, 256);
  numBytes += cTabhead_init(&cTabhead_Mf40FuaB, &hTable_JhfOlUP4);
  numBytes += cVar_init_s(&cVar_Eu2qxh1r, "del-1130-ref3");
  numBytes += cDelay_init(this, &cDelay_7zWmDk4N, 25.796f);
  numBytes += cDelay_init(this, &cDelay_kl4hROAf, 0.0f);
  numBytes += cBinop_init(&cBinop_W7nHuMcP, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_peLwAYbD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_22JWdPle, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_8QQA95NS, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_f2bnD3Rw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VSq7OoZ6, 0.0f);
  numBytes += hTable_init(&hTable_JhfOlUP4, 256);
  numBytes += cTabhead_init(&cTabhead_5PQzVi2C, &hTable_ex1q5Loa);
  numBytes += cVar_init_s(&cVar_zKXoFiBq, "del-1130-ref2");
  numBytes += cDelay_init(this, &cDelay_gt4bOFtZ, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_2Wsi620N, 0.0f);
  numBytes += cBinop_init(&cBinop_0G6bBUjD, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_kZbyKKHs, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_JmgQOkrF, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_gbmsr61v, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_7MPgiWsr, 0.0f);
  numBytes += cDelay_init(this, &cDelay_QWktwaYX, 0.0f);
  numBytes += hTable_init(&hTable_ex1q5Loa, 256);
  numBytes += cTabhead_init(&cTabhead_QDoPWXEB, &hTable_G8HwV53M);
  numBytes += cVar_init_s(&cVar_6PvHlScG, "del-1130-ref1");
  numBytes += cDelay_init(this, &cDelay_Y0qY4tis, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_OPUnkNXi, 0.0f);
  numBytes += cBinop_init(&cBinop_qGNwSQcC, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_Wd65SF7B, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fpV1hQpF, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_mw08Kos8, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_NgKb0Gou, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8ksdeNbu, 0.0f);
  numBytes += hTable_init(&hTable_G8HwV53M, 256);
  numBytes += cVar_init_f(&cVar_JBNceENl, 0.0f);
  numBytes += cVar_init_f(&cVar_93W03rJ0, 0.0f);
  numBytes += cPack_init(&cPack_lY7yv2xT, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_Vk3I88T4, 22050.0f);
  numBytes += cBinop_init(&cBinop_6G0axKst, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_xFCmmsvM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gaDNZJK1, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_oQTQwdD6, 22050.0f);
  numBytes += cBinop_init(&cBinop_T1gBYGRp, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_zb4IPxIn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LYPSGsZ0, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4nmbuxG1, 22050.0f);
  numBytes += cBinop_init(&cBinop_7SetHZZS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_pFnUkHHr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WTZM1YbA, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_X4CXhr7p, 50.0f);
  numBytes += cVar_init_f(&cVar_13uN1nuK, 0.0f);
  numBytes += cVar_init_f(&cVar_6G6VgaM3, 12.0f);
  numBytes += cVar_init_s(&cVar_7YrODSHZ, "floatatom");
  numBytes += cPack_init(&cPack_hT8gPoHS, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_E5r2XsbJ, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_boI0Qc6O, "floatatom");
  numBytes += cDelay_init(this, &cDelay_caYwPPqG, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CWqNmb2N, 0.0f);
  numBytes += hTable_init(&hTable_q07YJFQv, 256);
  numBytes += cVar_init_s(&cVar_h96QIkIW, "del-1235-del");
  numBytes += sVarf_init(&sVarf_CdR4pfST, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Vl5g8onr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MDzAQhe7, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_0fGqAmpX, "del-1235-del");
  numBytes += sVarf_init(&sVarf_R0GB4r9H, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0ymJCToo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BS17oump, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_51TXXPJW, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_IzyJ7Xer, 4720.0f);
  numBytes += cBinop_init(&cBinop_i0pGFQrO, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_UHuarA3L, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8OiixBdl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_aLua7DGo, 4720.0f);
  numBytes += cBinop_init(&cBinop_17CVhu4X, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_egttFfRK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gwqVDu5D, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_PgiNjOQl, 4720.0f);
  numBytes += cBinop_init(&cBinop_ODvWHyWf, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_kx9XffAD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BNLzf529, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_MllDaIjH, 1.0f);
  numBytes += cIf_init(&cIf_fy4Aj4nK, false);
  numBytes += sVarf_init(&sVarf_qPpBiMoQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vKKOe1zg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Dqqr9xmO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kTovkMDl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bTDMG5Tn, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_c6Jwn46d, &hTable_z6CszX9t);
  numBytes += cVar_init_s(&cVar_pzN1VgPd, "del-1298-del1");
  numBytes += cDelay_init(this, &cDelay_MJ3g6R6g, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_Ds8tpMnf, 0.0f);
  numBytes += cBinop_init(&cBinop_lV8rDliF, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_tTqgNBin, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jhGs6TXo, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_2lnm0cEO, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_49cxCtzA, &hTable_56JzGsTx);
  numBytes += cVar_init_s(&cVar_MjHcADru, "del-1298-del2");
  numBytes += cDelay_init(this, &cDelay_egmB63Qp, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_HCGq3OHs, 0.0f);
  numBytes += cBinop_init(&cBinop_XULG9doF, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_fMYvaVbr, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FbQUXct7, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_7rHWuhhv, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_aauTwDH1, &hTable_vfuj0syF);
  numBytes += cVar_init_s(&cVar_yqo9LDLw, "del-1298-del3");
  numBytes += cDelay_init(this, &cDelay_kK5RkVX5, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_nURErQYp, 0.0f);
  numBytes += cBinop_init(&cBinop_gQbjdssZ, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_1nPvFGCM, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_zmoVsNs6, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_J6UVukCW, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_QeTufyKk, &hTable_VVkTmdpB);
  numBytes += cVar_init_s(&cVar_v72dRMLm, "del-1298-del4");
  numBytes += cDelay_init(this, &cDelay_VqHVIFBL, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_VfNAoGpm, 0.0f);
  numBytes += cBinop_init(&cBinop_3Okxe3om, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_tEQtTQmV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NjcuYoVv, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_AXtuokJV, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_xjXtDEcr, 0.0f);
  numBytes += cDelay_init(this, &cDelay_AbxUgxI4, 0.0f);
  numBytes += hTable_init(&hTable_z6CszX9t, 256);
  numBytes += cDelay_init(this, &cDelay_eXNOUEXW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_xgCG0c4t, 0.0f);
  numBytes += hTable_init(&hTable_56JzGsTx, 256);
  numBytes += cDelay_init(this, &cDelay_ZdSPeiWo, 0.0f);
  numBytes += cDelay_init(this, &cDelay_w4aHoJga, 0.0f);
  numBytes += hTable_init(&hTable_vfuj0syF, 256);
  numBytes += cDelay_init(this, &cDelay_1Cd8dnLG, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VfGPG8rr, 0.0f);
  numBytes += hTable_init(&hTable_VVkTmdpB, 256);
  numBytes += cIf_init(&cIf_2Ri9MznF, false);
  numBytes += cBinop_init(&cBinop_4OuNVA6F, 0.0f); // __pow
  numBytes += cPack_init(&cPack_5Q1id9Vr, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_O1nLvPsc, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_K3XIB8AC, 22050.0f);
  numBytes += cBinop_init(&cBinop_C3j3lzPc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hLwUGtIf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bp4zwb2g, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_NyeoSkPJ, 100.0f);
  numBytes += cVar_init_f(&cVar_HpUQFnyS, 95.0f);
  numBytes += cVar_init_f(&cVar_LyPTYrzF, 14400.0f);
  numBytes += cVar_init_f(&cVar_9xcwDih4, 60.0f);
  numBytes += cIf_init(&cIf_0c3pcpPB, false);
  numBytes += cTabhead_init(&cTabhead_GNqInCF0, &hTable_n2E9gz35);
  numBytes += cVar_init_s(&cVar_FoxtFCsc, "del-1298-ref6");
  numBytes += cDelay_init(this, &cDelay_t9lGsV4d, 13.645f);
  numBytes += cDelay_init(this, &cDelay_0uhJjrqG, 0.0f);
  numBytes += cBinop_init(&cBinop_lQKpZP1z, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_2OkEwzpX, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_OTujQdol, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_VQdALCJp, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_FHMMpkD8, 0.0f);
  numBytes += cDelay_init(this, &cDelay_44fTBqee, 0.0f);
  numBytes += hTable_init(&hTable_n2E9gz35, 256);
  numBytes += cTabhead_init(&cTabhead_ARHN8UiJ, &hTable_VNnMcNUN);
  numBytes += cVar_init_s(&cVar_nUy2aM88, "del-1298-ref5");
  numBytes += cDelay_init(this, &cDelay_z8A5aUak, 16.364f);
  numBytes += cDelay_init(this, &cDelay_bNpyiWnL, 0.0f);
  numBytes += cBinop_init(&cBinop_q9oZeqxO, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_DJPsuX26, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ZCHcmrH0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_M9ORZjjU, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_KeIhE631, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WEX59K8t, 0.0f);
  numBytes += hTable_init(&hTable_VNnMcNUN, 256);
  numBytes += cTabhead_init(&cTabhead_XL8xQ3x9, &hTable_VpWyHd8s);
  numBytes += cVar_init_s(&cVar_d3apkzzx, "del-1298-ref4");
  numBytes += cDelay_init(this, &cDelay_epndJlR8, 19.392f);
  numBytes += cDelay_init(this, &cDelay_c7x5E6Cp, 0.0f);
  numBytes += cBinop_init(&cBinop_UE1CFFNZ, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_cyz73g6E, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ySDwYsfi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_W01xczcH, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_GO1hcw1V, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vPx41Lhj, 0.0f);
  numBytes += hTable_init(&hTable_VpWyHd8s, 256);
  numBytes += cTabhead_init(&cTabhead_8WCi2ini, &hTable_msxcGeza);
  numBytes += cVar_init_s(&cVar_Adh4yrss, "del-1298-ref3");
  numBytes += cDelay_init(this, &cDelay_PVC8NRiS, 25.796f);
  numBytes += cDelay_init(this, &cDelay_IOAfBjxT, 0.0f);
  numBytes += cBinop_init(&cBinop_ahRzvJYV, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_bNjNlr8S, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BCGir0PO, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_I9oTSubY, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_tqhqMmxe, 0.0f);
  numBytes += cDelay_init(this, &cDelay_SalQnEhU, 0.0f);
  numBytes += hTable_init(&hTable_msxcGeza, 256);
  numBytes += cTabhead_init(&cTabhead_ZNB2PqhN, &hTable_rWE9zngZ);
  numBytes += cVar_init_s(&cVar_reMorDrL, "del-1298-ref2");
  numBytes += cDelay_init(this, &cDelay_PwB0XfqW, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_fGpOZigy, 0.0f);
  numBytes += cBinop_init(&cBinop_SUQ2IIKw, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_LGSqCNIU, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_j2Kjs8wj, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_znMwlMDA, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_gHAF8bsU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XNUmkQMJ, 0.0f);
  numBytes += hTable_init(&hTable_rWE9zngZ, 256);
  numBytes += cTabhead_init(&cTabhead_qxjHhATg, &hTable_bmegWqSo);
  numBytes += cVar_init_s(&cVar_hiEceA0Z, "del-1298-ref1");
  numBytes += cDelay_init(this, &cDelay_cMgMCzg7, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_kYqLm6bp, 0.0f);
  numBytes += cBinop_init(&cBinop_6vAF2TJz, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_3oLW5EAj, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3Ea0sk8w, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_asJnBBVV, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_2IvXBfig, 0.0f);
  numBytes += cDelay_init(this, &cDelay_qU036ze2, 0.0f);
  numBytes += hTable_init(&hTable_bmegWqSo, 256);
  numBytes += cVar_init_f(&cVar_pGHuwTZr, 0.0f);
  numBytes += cVar_init_f(&cVar_gN2kQ6ob, 0.0f);
  numBytes += cPack_init(&cPack_R23eCpiE, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_mw7R4dMK, 22050.0f);
  numBytes += cBinop_init(&cBinop_jr1N0F7Z, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_D2WCxO88, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3OqHSE28, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_0mLgCZJk, 22050.0f);
  numBytes += cBinop_init(&cBinop_qiN3syTL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_LDbuDX4h, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ruIKdTMI, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_aTuR5bEy, 22050.0f);
  numBytes += cBinop_init(&cBinop_ZHU1mV9G, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_DPsj2MhN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lvFQNp7z, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_iP0oz6Bp, "del-1397-del1");
  numBytes += sVarf_init(&sVarf_w7z1IsXG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oxI8WbKp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_y3iBRhGC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_dfnvLIfx, 10000.0f);
  numBytes += cBinop_init(&cBinop_fcti31QZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_JfD2jMx3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tHZuoQoY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pm1EeHbj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lYayMnfr, 10.0f);
  numBytes += cBinop_init(&cBinop_fm4UK0v2, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_fJE5MDGA, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_zqhT0mdi, "floatatom");
  numBytes += sVarf_init(&sVarf_j9AJL8rr, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_AwiReYX3, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XTZY2Mn9, 0.0f);
  numBytes += hTable_init(&hTable_vbDgCxW0, 256);
  numBytes += sVarf_init(&sVarf_CpksG3Zx, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_i8nrhttR, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_oKCi4klI, 1074953051);
  numBytes += cSlice_init(&cSlice_qjPLyANN, 1, 1);
  numBytes += cBinop_init(&cBinop_vxeDosYv, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_88fNTrLE, -1645942339);
  numBytes += cSlice_init(&cSlice_inqc4rGW, 1, 1);
  numBytes += cSlice_init(&cSlice_pvmdHmBX, 1, 1);
  numBytes += cSlice_init(&cSlice_smuPsA0X, 0, 1);
  numBytes += cPack_init(&cPack_HnogbGix, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_lofNDizK, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_w6BsjLj9, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OQSpZkfB, 25.0f);
  numBytes += cVar_init_f(&cVar_HxvIWPAn, 0.0f);
  numBytes += sVarf_init(&sVarf_jZq37lLx, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_0wY2A44e, "crotale");
  numBytes += cSlice_init(&cSlice_VLLhSsxY, 1, 1);
  numBytes += sVarf_init(&sVarf_flsPbRxt, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_SUHIrc79, 0.0f);
  numBytes += cVar_init_f(&cVar_mCq2PK4m, 1.0f);
  numBytes += cIf_init(&cIf_kJPyjbdS, false);
  numBytes += cVar_init_f(&cVar_KVEjC6gS, 1.0f);
  numBytes += cVar_init_f(&cVar_gMapRCOF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CAY5z2w0, 2.0f);
  numBytes += cPack_init(&cPack_vcbIbpkX, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_pc7JRg3W, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vFYZHQ0s, 2.0f);
  numBytes += cPack_init(&cPack_qBdj0tIq, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_0UigZHUC, 2, 0.0f, -220500000.0f);
  numBytes += cPack_init(&cPack_8t46lUwo, 2, 0.0f, 220500000.0f);
  numBytes += cPack_init(&cPack_AVOT1xr3, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_OP1LMVvU, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_uw5D8EFu, 0.0f);
  numBytes += cVar_init_f(&cVar_iOoQ1WXW, 1.0f);
  numBytes += cPack_init(&cPack_u9EIWQp1, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_63aEC5AQ, 1, 1);
  numBytes += cSlice_init(&cSlice_fDSIzqye, 0, 1);
  numBytes += cSlice_init(&cSlice_kZOJUuDQ, 1, 1);
  numBytes += cSlice_init(&cSlice_j0H2wCF5, 0, 1);
  numBytes += cBinop_init(&cBinop_hvYfRcPW, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_2maS7GZu, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_NuDloqz1, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_1EzEYA9d, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_IM1LdDB6, 22.05f); // __mul
  numBytes += cSlice_init(&cSlice_ZUPNcyvo, 5, 1);
  numBytes += cSlice_init(&cSlice_mx6vvLZY, 4, 1);
  numBytes += cSlice_init(&cSlice_259eC9P0, 3, 1);
  numBytes += cSlice_init(&cSlice_n1sWIZ4r, 2, 1);
  numBytes += cSlice_init(&cSlice_3EdMFpQh, 1, 1);
  numBytes += cSlice_init(&cSlice_CcXTQqxY, 0, 1);
  numBytes += cSlice_init(&cSlice_xfQvE7YN, 1, 1);
  numBytes += cSlice_init(&cSlice_7NN34YMr, 0, 1);
  numBytes += cPack_init(&cPack_ki1RNn6v, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_j7SEZUjg, "floatatom");
  numBytes += cSlice_init(&cSlice_KSfWutt3, 1, 1);
  numBytes += cSlice_init(&cSlice_H1CE7nja, 0, 1);
  numBytes += cBinop_init(&cBinop_7PI8cSGj, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_mdBvfqoo, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_z1rwnIze, 1, 1);
  numBytes += cSlice_init(&cSlice_lKuI6xBU, 0, 1);
  numBytes += cVar_init_f(&cVar_0KP4RwC6, 0.0f);
  numBytes += cVar_init_f(&cVar_qoPjf6Vl, 1.0f);
  numBytes += cPack_init(&cPack_f0nvypbF, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_6fLTFqKj, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_h329csiO, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_C9I21fWP, 1039952017);
  numBytes += cSlice_init(&cSlice_iCsyDQk0, 1, 1);
  numBytes += cBinop_init(&cBinop_6Wm0R5ag, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_qrnx9jID, 312921851);
  numBytes += cSlice_init(&cSlice_SowuFVbv, 1, 1);
  numBytes += cSlice_init(&cSlice_A935J5Rc, 1, 1);
  numBytes += cSlice_init(&cSlice_DFZ2omn1, 0, 1);
  numBytes += cPack_init(&cPack_QV6fLvnQ, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_eXSw1xZJ, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_sYUxIteA, 0.0f);
  numBytes += cDelay_init(this, &cDelay_k5LLuZTK, 25.0f);
  numBytes += cVar_init_f(&cVar_gW0DiIiN, 0.0f);
  numBytes += sVarf_init(&sVarf_cZfkr1FI, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_fetpSVOz, "crotale");
  numBytes += cSlice_init(&cSlice_3BzYHIwr, 1, 1);
  numBytes += sVarf_init(&sVarf_nJvIRFux, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_51F8CCMp, 0.0f);
  numBytes += cVar_init_f(&cVar_N2cL1cyc, 1.0f);
  numBytes += cIf_init(&cIf_u3Y3WltG, false);
  numBytes += cVar_init_f(&cVar_m3zVLUQI, 1.0f);
  numBytes += cVar_init_f(&cVar_zf38RJxH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ypaDMQ1H, 2.0f);
  numBytes += cPack_init(&cPack_HaX2qrjp, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4NhJyJT5, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Ke83EeFw, 2.0f);
  numBytes += cPack_init(&cPack_pmsi2oOu, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_HM6itJPZ, 2, 0.0f, -220500000.0f);
  numBytes += cPack_init(&cPack_JOg7byX1, 2, 0.0f, 220500000.0f);
  numBytes += cPack_init(&cPack_N5YNLr3I, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_2vPS6pBV, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_9vAscWTN, 0.0f);
  numBytes += cVar_init_f(&cVar_mg5Jwkt3, 1.0f);
  numBytes += cPack_init(&cPack_anvmogl2, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_I1jse7IU, 1, 1);
  numBytes += cSlice_init(&cSlice_vUl7fa6d, 0, 1);
  numBytes += cSlice_init(&cSlice_JWqffbOg, 1, 1);
  numBytes += cSlice_init(&cSlice_EJK3LFuZ, 0, 1);
  numBytes += cBinop_init(&cBinop_dRS76zmL, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_PJMRjxHC, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_QgNR2RtR, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_hdYWlAaQ, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_lbLfWD8R, 22.05f); // __mul
  numBytes += cSlice_init(&cSlice_iNFdV1oj, 5, 1);
  numBytes += cSlice_init(&cSlice_FSC4k5ZY, 4, 1);
  numBytes += cSlice_init(&cSlice_EP5dU5rA, 3, 1);
  numBytes += cSlice_init(&cSlice_dJ7NFNP5, 2, 1);
  numBytes += cSlice_init(&cSlice_Sgu9Wr9l, 1, 1);
  numBytes += cSlice_init(&cSlice_8nB2xTv7, 0, 1);
  numBytes += cSlice_init(&cSlice_GHoKaGRQ, 1, 1);
  numBytes += cSlice_init(&cSlice_ETZCKcdN, 0, 1);
  numBytes += cPack_init(&cPack_lZNb4zyO, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_OKLfMCLg, "floatatom");
  numBytes += cSlice_init(&cSlice_YuWMInkC, 1, 1);
  numBytes += cSlice_init(&cSlice_ONkzmAAJ, 0, 1);
  numBytes += cBinop_init(&cBinop_BXbPuDrT, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_YA3uyjgc, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_u9Xqg0ml, 1, 1);
  numBytes += cSlice_init(&cSlice_ptaasdVk, 0, 1);
  numBytes += cVar_init_f(&cVar_eNLHIUzg, 0.0f);
  numBytes += cVar_init_f(&cVar_GZyHjxNg, 1.0f);
  numBytes += cPack_init(&cPack_tydvqhFl, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_1B7IsYbl, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_iajd5keQ, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_x7N0aC7f, -675701144);
  numBytes += cSlice_init(&cSlice_LznwPt31, 1, 1);
  numBytes += cBinop_init(&cBinop_jOGiiawe, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_KiTMUJUU, 1721830652);
  numBytes += cSlice_init(&cSlice_LuuhJxwZ, 1, 1);
  numBytes += cSlice_init(&cSlice_BgzNrejB, 1, 1);
  numBytes += cSlice_init(&cSlice_QwMwSmiR, 0, 1);
  numBytes += cPack_init(&cPack_iy72yUJv, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_glIN05IF, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_8g046wQ1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DAi0Y0fg, 25.0f);
  numBytes += cVar_init_f(&cVar_ugvTKVQq, 0.0f);
  numBytes += sVarf_init(&sVarf_RQBB2CYq, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_LUiodfWo, "crotale");
  numBytes += cSlice_init(&cSlice_wEXN2JNZ, 1, 1);
  numBytes += sVarf_init(&sVarf_aJR2wyXX, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_AMQ8fYV4, 0.0f);
  numBytes += cVar_init_f(&cVar_ZJ34sTpS, 1.0f);
  numBytes += cIf_init(&cIf_tNfMBmWk, false);
  numBytes += cVar_init_f(&cVar_s9knBuP0, 1.0f);
  numBytes += cVar_init_f(&cVar_1ZhHLgy1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_qhLn4TaM, 2.0f);
  numBytes += cPack_init(&cPack_awlfwhed, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_oB2KhVYW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_nsI1qWCf, 2.0f);
  numBytes += cPack_init(&cPack_JKEYuDVq, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_qHfcMM9G, 2, 0.0f, -220500000.0f);
  numBytes += cPack_init(&cPack_aHVzeG9D, 2, 0.0f, 220500000.0f);
  numBytes += cPack_init(&cPack_Lox4tWPQ, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_7oDnoUMn, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_I6j0Rc8z, 0.0f);
  numBytes += cVar_init_f(&cVar_CIoyXwKa, 1.0f);
  numBytes += cPack_init(&cPack_QmIC7Vfy, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_lJc6QFav, 1, 1);
  numBytes += cSlice_init(&cSlice_W7JntOxG, 0, 1);
  numBytes += cSlice_init(&cSlice_opHDTDiN, 1, 1);
  numBytes += cSlice_init(&cSlice_wHtW5rfB, 0, 1);
  numBytes += cBinop_init(&cBinop_yQV2SttF, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_VGcsXMV2, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_1JtQsEiD, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_OR2edB1h, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_M8x0WpkY, 22.05f); // __mul
  numBytes += cSlice_init(&cSlice_Z3FYfdgM, 5, 1);
  numBytes += cSlice_init(&cSlice_4RnslAh7, 4, 1);
  numBytes += cSlice_init(&cSlice_OPhpzvEw, 3, 1);
  numBytes += cSlice_init(&cSlice_BTAX4nMC, 2, 1);
  numBytes += cSlice_init(&cSlice_KmdnYnAD, 1, 1);
  numBytes += cSlice_init(&cSlice_GT5Vs5FI, 0, 1);
  numBytes += cSlice_init(&cSlice_bxGTatNZ, 1, 1);
  numBytes += cSlice_init(&cSlice_hxiFlJl4, 0, 1);
  numBytes += cPack_init(&cPack_aHyvdpw8, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_JBxl2BNP, "floatatom");
  numBytes += cSlice_init(&cSlice_1bu7BR1H, 1, 1);
  numBytes += cSlice_init(&cSlice_eF1NBNQq, 0, 1);
  numBytes += cBinop_init(&cBinop_rXyxOcvg, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_uY7uA4os, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_FXSkZnby, 1, 1);
  numBytes += cSlice_init(&cSlice_cnJogt9T, 0, 1);
  numBytes += cVar_init_f(&cVar_tr8TAC6a, 0.0f);
  numBytes += cVar_init_f(&cVar_NahEyvbZ, 1.0f);
  numBytes += cPack_init(&cPack_0aRWDeRk, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_l7s0i59l, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_yaY5cQwn, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_lXsyFYfQ, 1302123569);
  numBytes += cSlice_init(&cSlice_pdTfZVna, 1, 1);
  numBytes += cBinop_init(&cBinop_Z5k7Kah6, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_70lYcY3E, -1769586244);
  numBytes += cSlice_init(&cSlice_COYqVIfG, 1, 1);
  numBytes += cSlice_init(&cSlice_jHtbTf4Z, 1, 1);
  numBytes += cSlice_init(&cSlice_S1nYIyAR, 0, 1);
  numBytes += cPack_init(&cPack_tubQWDR5, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_csA8u2m9, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_knmFkY2y, 0.0f);
  numBytes += cDelay_init(this, &cDelay_SE3YwM4M, 25.0f);
  numBytes += cVar_init_f(&cVar_NXtwZNhD, 0.0f);
  numBytes += sVarf_init(&sVarf_06t8gV9x, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_KmmEqxwI, "crotale");
  numBytes += cSlice_init(&cSlice_w2DvFUDs, 1, 1);
  numBytes += sVarf_init(&sVarf_3sId2lea, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_uvPwAJzY, 0.0f);
  numBytes += cVar_init_f(&cVar_hFKRS3jB, 1.0f);
  numBytes += cIf_init(&cIf_zUqUz5bM, false);
  numBytes += cVar_init_f(&cVar_gpYKDewF, 1.0f);
  numBytes += cVar_init_f(&cVar_9dVEpMmC, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ua8w0ARd, 2.0f);
  numBytes += cPack_init(&cPack_7VQm0qO6, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_dSROOccP, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iwbf23Wv, 2.0f);
  numBytes += cPack_init(&cPack_idxERVC4, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_c8BAvy5O, 2, 0.0f, -220500000.0f);
  numBytes += cPack_init(&cPack_hHbKpNUo, 2, 0.0f, 220500000.0f);
  numBytes += cPack_init(&cPack_SAfKwfvJ, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_kQBalaVk, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_o6ABbOM9, 0.0f);
  numBytes += cVar_init_f(&cVar_mJntBFfM, 1.0f);
  numBytes += cPack_init(&cPack_NPw7VWWX, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_QDByNRL7, 1, 1);
  numBytes += cSlice_init(&cSlice_TaUZydIz, 0, 1);
  numBytes += cSlice_init(&cSlice_ApoGF0w8, 1, 1);
  numBytes += cSlice_init(&cSlice_7BPixTs2, 0, 1);
  numBytes += cBinop_init(&cBinop_U8gASISt, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_p3LS4zf3, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_yfrKWl4k, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_oWMPlqpB, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_LROWzPm5, 22.05f); // __mul
  numBytes += cSlice_init(&cSlice_NZucynTd, 5, 1);
  numBytes += cSlice_init(&cSlice_vJlifqfT, 4, 1);
  numBytes += cSlice_init(&cSlice_kbs8Zyfo, 3, 1);
  numBytes += cSlice_init(&cSlice_DgWtMBvI, 2, 1);
  numBytes += cSlice_init(&cSlice_uInGRj87, 1, 1);
  numBytes += cSlice_init(&cSlice_Cmiw4wzt, 0, 1);
  numBytes += cSlice_init(&cSlice_1c2ZTtdP, 1, 1);
  numBytes += cSlice_init(&cSlice_uJHKVOPx, 0, 1);
  numBytes += cPack_init(&cPack_We5uBtup, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_sFjD6IYN, "floatatom");
  numBytes += cSlice_init(&cSlice_i76AwZLQ, 1, 1);
  numBytes += cSlice_init(&cSlice_fyfZpF8I, 0, 1);
  numBytes += cBinop_init(&cBinop_YSP4nBv8, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_IQItaRVb, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_Q7qJrA9w, 1, 1);
  numBytes += cSlice_init(&cSlice_DIdVSaWM, 0, 1);
  numBytes += cVar_init_f(&cVar_VvR1dAGz, 0.0f);
  numBytes += cVar_init_f(&cVar_GgknyzQi, 1.0f);
  numBytes += cPack_init(&cPack_DSklzqgD, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_1rmmKHih, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_y9TKo4Ur, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_PO73u0tm, 1786941131);
  numBytes += cSlice_init(&cSlice_OLQ1PQCx, 1, 1);
  numBytes += cVar_init_f(&cVar_RvvO72sl, 98.0f);
  numBytes += cIf_init(&cIf_IAEXlpVJ, false);
  numBytes += cBinop_init(&cBinop_zeW739bn, 0.0f); // __pow
  numBytes += cPack_init(&cPack_1IkF2cyc, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_0YI7NiCN, 0.0f);
  numBytes += cVar_init_f(&cVar_1Uizhf61, 100.0f);
  numBytes += cIf_init(&cIf_zvLD43kE, false);
  numBytes += cBinop_init(&cBinop_sfX5s909, 0.0f); // __pow
  numBytes += cPack_init(&cPack_zUwRhVRU, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_d8ZnlbDl, 0.0f);
  numBytes += cVar_init_f(&cVar_cARKryah, 100.0f);
  numBytes += cIf_init(&cIf_b7rAU3M0, false);
  numBytes += cBinop_init(&cBinop_PoUIlUOA, 0.0f); // __pow
  numBytes += cPack_init(&cPack_LVj4fcxd, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_fUAHW5ir, 0.0f);
  numBytes += cIf_init(&cIf_ZXfIpuAP, false);
  numBytes += cIf_init(&cIf_5BdWiroS, false);
  numBytes += cIf_init(&cIf_eOfDjukW, false);
  numBytes += cVar_init_f(&cVar_HoDE51UV, 97.0f);
  numBytes += cIf_init(&cIf_sfb8FdfV, false);
  numBytes += cBinop_init(&cBinop_XH5xj6jQ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_6gj7DwNl, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_9wZmOk49, 0.0f);
  numBytes += cVar_init_f(&cVar_j1yecy4h, 97.0f);
  numBytes += cIf_init(&cIf_5WrZzYbh, false);
  numBytes += cBinop_init(&cBinop_iCmP4QLR, 0.0f); // __pow
  numBytes += cPack_init(&cPack_Rox7fAq4, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_sLu2O4yb, 0.0f);
  numBytes += cPack_init(&cPack_rrZ8MHv4, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_aJsCdIKj, 1, 1);
  numBytes += cSlice_init(&cSlice_vmlqrmoT, 0, 1);
  numBytes += cIf_init(&cIf_hWB84Ihb, false);
  numBytes += cIf_init(&cIf_avBQq2ts, false);
  numBytes += cIf_init(&cIf_BuRP5uci, false);
  numBytes += cSlice_init(&cSlice_OmSjkJxy, 1, 1);
  numBytes += cSlice_init(&cSlice_pJpaRFRv, 0, 1);
  numBytes += cVar_init_f(&cVar_lJklLelE, 0.0f);
  numBytes += cIf_init(&cIf_nu0aKjh6, false);
  numBytes += cPack_init(&cPack_tOsJYqaY, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_fiMxjs57, 1, -1);
  numBytes += cSlice_init(&cSlice_kmbrukko, 1, -1);
  numBytes += cSlice_init(&cSlice_03DmEe5R, 1, -1);
  numBytes += cSlice_init(&cSlice_e2tCE7i7, 1, -1);
  numBytes += cIf_init(&cIf_f2l9qggW, false);
  numBytes += cVar_init_f(&cVar_qR62oSe3, 1.0f);
  numBytes += cPack_init(&cPack_vPYbmP5A, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_Ef46yxKZ, 0.0f);
  numBytes += cVar_init_f(&cVar_VR9B4aGA, 1.0f);
  numBytes += cPack_init(&cPack_1qFmMXPY, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_gyBM6ebi, -1423288722);
  numBytes += cSlice_init(&cSlice_akHRQzX4, 1, 1);
  numBytes += cRandom_init(&cRandom_dVT8QAlf, -964784027);
  numBytes += cSlice_init(&cSlice_Ed7rsCsY, 1, 1);
  numBytes += cRandom_init(&cRandom_cWTNAlVK, -1108725314);
  numBytes += cSlice_init(&cSlice_EriH71xy, 1, 1);
  numBytes += cVar_init_s(&cVar_XiCwkoYX, "floatatom");
  numBytes += cVar_init_s(&cVar_NQBM3Stm, "floatatom");
  numBytes += cIf_init(&cIf_zgftVSZD, false);
  numBytes += cVar_init_s(&cVar_TimsKYLv, "floatatom");
  numBytes += cBinop_init(&cBinop_mGEd0VaN, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Ul3XBQST, 72.07f); // __sub
  numBytes += cSlice_init(&cSlice_RVevB0cJ, 1, -1);
  numBytes += cSlice_init(&cSlice_1VY1pW7P, 1, -1);
  numBytes += cBinop_init(&cBinop_tDax3soW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_beeIGorf, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_CTxXPBj5, 1, 1);
  numBytes += cSlice_init(&cSlice_VRSRcpQZ, 0, 1);
  numBytes += cPack_init(&cPack_JQZEEQiT, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_29O6GnF2, 0.0f);
  numBytes += cVar_init_f(&cVar_FRxeL5KK, 10.0f);
  numBytes += cPack_init(&cPack_fq06Iz3C, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_L6nYYdte, 1, 1);
  numBytes += cSlice_init(&cSlice_F6XnlqA1, 0, 1);
  numBytes += cBinop_init(&cBinop_wzEEZdfo, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_UImHnzDQ, 22.05f); // __mul
  numBytes += cVar_init_f(&cVar_giCNzmUp, 5.0f);
  numBytes += cBinop_init(&cBinop_GgI1AXfE, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Rhu2jWWN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Aadb4l2X, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_Q532gYa7, 0.0f);
  numBytes += cIf_init(&cIf_kceOqLfC, false);
  numBytes += cSlice_init(&cSlice_0iFaIPlS, 1, 1);
  numBytes += cSlice_init(&cSlice_ZMx4KMfI, 0, 1);
  numBytes += cVar_init_s(&cVar_FVq8r9Ju, "crotale");
  numBytes += cSlice_init(&cSlice_GtvdlRvP, 1, 1);
  numBytes += sVarf_init(&sVarf_cs71lYng, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_XiZnQO8V, "crotale");
  numBytes += cSlice_init(&cSlice_61svUy2C, 1, 1);
  numBytes += sVarf_init(&sVarf_D9yO6SqW, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_9ndE94Oq, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_IQPif8Or, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_sfkqaYZr, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_nN9tPd0Q, 5.0f);
  numBytes += cBinop_init(&cBinop_IB4pmMdm, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_d0vENQWV, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_mJmhlyIE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_XdtmvEEt, 220.5f); // __mul
  numBytes += sVarf_init(&sVarf_PCZzQFIN, 0.0f, 0.0f, false);
  numBytes += hTable_init(&hTable_yQvyZ5yW, 200000);
  numBytes += hTable_init(&hTable_HHfueTlC, 200000);
  numBytes += hTable_init(&hTable_uqWqV2XU, 200000);
  numBytes += hTable_init(&hTable_nF3TUztb, 200000);
  numBytes += hTable_init(&hTable_ywMVMBCB, 200000);
  numBytes += hTable_init(&hTable_pydTeLcN, 200000);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_SoundScraper::~Heavy_SoundScraper() {
  cPack_free(&cPack_nHSSkW9R);
  cPack_free(&cPack_tCyLDNoF);
  cPack_free(&cPack_6raKcuXb);
  hTable_free(&hTable_Uit9aCmF);
  hTable_free(&hTable_VjaqfHY6);
  cPack_free(&cPack_oqMjOJOt);
  cPack_free(&cPack_QAKFCTX9);
  cPack_free(&cPack_c2NkkjaU);
  hTable_free(&hTable_jVtpceAv);
  hTable_free(&hTable_gQm9T15j);
  hTable_free(&hTable_Mv6L78uO);
  hTable_free(&hTable_HTdiw5Pz);
  cPack_free(&cPack_I78PYX3u);
  cPack_free(&cPack_SaMhCDYJ);
  hTable_free(&hTable_S8GYBCus);
  hTable_free(&hTable_OeabZUPW);
  hTable_free(&hTable_9zLfnrf6);
  hTable_free(&hTable_JhfOlUP4);
  hTable_free(&hTable_ex1q5Loa);
  hTable_free(&hTable_G8HwV53M);
  cPack_free(&cPack_lY7yv2xT);
  cPack_free(&cPack_hT8gPoHS);
  cPack_free(&cPack_E5r2XsbJ);
  hTable_free(&hTable_q07YJFQv);
  hTable_free(&hTable_z6CszX9t);
  hTable_free(&hTable_56JzGsTx);
  hTable_free(&hTable_vfuj0syF);
  hTable_free(&hTable_VVkTmdpB);
  cPack_free(&cPack_5Q1id9Vr);
  cPack_free(&cPack_O1nLvPsc);
  hTable_free(&hTable_n2E9gz35);
  hTable_free(&hTable_VNnMcNUN);
  hTable_free(&hTable_VpWyHd8s);
  hTable_free(&hTable_msxcGeza);
  hTable_free(&hTable_rWE9zngZ);
  hTable_free(&hTable_bmegWqSo);
  cPack_free(&cPack_R23eCpiE);
  hTable_free(&hTable_vbDgCxW0);
  cPack_free(&cPack_i8nrhttR);
  cPack_free(&cPack_HnogbGix);
  cPack_free(&cPack_lofNDizK);
  cPack_free(&cPack_vcbIbpkX);
  cPack_free(&cPack_qBdj0tIq);
  cPack_free(&cPack_0UigZHUC);
  cPack_free(&cPack_8t46lUwo);
  cPack_free(&cPack_AVOT1xr3);
  cPack_free(&cPack_OP1LMVvU);
  cPack_free(&cPack_u9EIWQp1);
  cPack_free(&cPack_ki1RNn6v);
  cPack_free(&cPack_f0nvypbF);
  cPack_free(&cPack_QV6fLvnQ);
  cPack_free(&cPack_eXSw1xZJ);
  cPack_free(&cPack_HaX2qrjp);
  cPack_free(&cPack_pmsi2oOu);
  cPack_free(&cPack_HM6itJPZ);
  cPack_free(&cPack_JOg7byX1);
  cPack_free(&cPack_N5YNLr3I);
  cPack_free(&cPack_2vPS6pBV);
  cPack_free(&cPack_anvmogl2);
  cPack_free(&cPack_lZNb4zyO);
  cPack_free(&cPack_tydvqhFl);
  cPack_free(&cPack_iy72yUJv);
  cPack_free(&cPack_glIN05IF);
  cPack_free(&cPack_awlfwhed);
  cPack_free(&cPack_JKEYuDVq);
  cPack_free(&cPack_qHfcMM9G);
  cPack_free(&cPack_aHVzeG9D);
  cPack_free(&cPack_Lox4tWPQ);
  cPack_free(&cPack_7oDnoUMn);
  cPack_free(&cPack_QmIC7Vfy);
  cPack_free(&cPack_aHyvdpw8);
  cPack_free(&cPack_0aRWDeRk);
  cPack_free(&cPack_tubQWDR5);
  cPack_free(&cPack_csA8u2m9);
  cPack_free(&cPack_7VQm0qO6);
  cPack_free(&cPack_idxERVC4);
  cPack_free(&cPack_c8BAvy5O);
  cPack_free(&cPack_hHbKpNUo);
  cPack_free(&cPack_SAfKwfvJ);
  cPack_free(&cPack_kQBalaVk);
  cPack_free(&cPack_NPw7VWWX);
  cPack_free(&cPack_We5uBtup);
  cPack_free(&cPack_DSklzqgD);
  cPack_free(&cPack_1IkF2cyc);
  cPack_free(&cPack_zUwRhVRU);
  cPack_free(&cPack_LVj4fcxd);
  cPack_free(&cPack_6gj7DwNl);
  cPack_free(&cPack_Rox7fAq4);
  cPack_free(&cPack_rrZ8MHv4);
  cPack_free(&cPack_tOsJYqaY);
  cPack_free(&cPack_vPYbmP5A);
  cPack_free(&cPack_1qFmMXPY);
  cPack_free(&cPack_JQZEEQiT);
  cPack_free(&cPack_fq06Iz3C);
  hTable_free(&hTable_yQvyZ5yW);
  hTable_free(&hTable_HHfueTlC);
  hTable_free(&hTable_uqWqV2XU);
  hTable_free(&hTable_nF3TUztb);
  hTable_free(&hTable_ywMVMBCB);
  hTable_free(&hTable_pydTeLcN);
}

HvTable *Heavy_SoundScraper::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x436A0550: return &hTable_Uit9aCmF; // del-1040-del
    case 0x7F066481: return &hTable_VjaqfHY6; // del-1069-del1
    case 0x2FD71841: return &hTable_jVtpceAv; // del-1130-del1
    case 0x4F984AEF: return &hTable_gQm9T15j; // del-1130-del2
    case 0xF31DED20: return &hTable_Mv6L78uO; // del-1130-del3
    case 0x43D20BD9: return &hTable_HTdiw5Pz; // del-1130-del4
    case 0x1792E9A6: return &hTable_S8GYBCus; // del-1130-ref6
    case 0xB84BF7D2: return &hTable_OeabZUPW; // del-1130-ref5
    case 0x695825B7: return &hTable_9zLfnrf6; // del-1130-ref4
    case 0x460C1764: return &hTable_JhfOlUP4; // del-1130-ref3
    case 0x46A969C7: return &hTable_ex1q5Loa; // del-1130-ref2
    case 0xC03F1F97: return &hTable_G8HwV53M; // del-1130-ref1
    case 0xBB7C9AAB: return &hTable_q07YJFQv; // del-1235-del
    case 0xB8603A7: return &hTable_z6CszX9t; // del-1298-del1
    case 0xFB383A6C: return &hTable_56JzGsTx; // del-1298-del2
    case 0x4DD59F74: return &hTable_vfuj0syF; // del-1298-del3
    case 0xEED55635: return &hTable_VVkTmdpB; // del-1298-del4
    case 0x480E74AD: return &hTable_n2E9gz35; // del-1298-ref6
    case 0x19B4711D: return &hTable_VNnMcNUN; // del-1298-ref5
    case 0xC655A199: return &hTable_VpWyHd8s; // del-1298-ref4
    case 0xB6FE6212: return &hTable_msxcGeza; // del-1298-ref3
    case 0x6E3EF8B1: return &hTable_rWE9zngZ; // del-1298-ref2
    case 0x5D7D44A3: return &hTable_bmegWqSo; // del-1298-ref1
    case 0xF89A3E8D: return &hTable_vbDgCxW0; // del-1397-del1
    case 0x9BCAD111: return &hTable_yQvyZ5yW; // bowl
    case 0x782CD90: return &hTable_HHfueTlC; // crotale
    case 0x53C964B5: return &hTable_uqWqV2XU; // gong
    case 0xAC13AE99: return &hTable_nF3TUztb; // marimba
    case 0x1FD931DF: return &hTable_ywMVMBCB; // xylo
    case 0x6F52CA74: return &hTable_pydTeLcN; // almglocken
    default: return nullptr;
  }
}

void Heavy_SoundScraper::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE0749F2A: { // 1029-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TLd92gz8_sendMessage);
      break;
    }
    case 0x560204A8: { // 1029-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AaWmRax8_sendMessage);
      break;
    }
    case 0xD247D84C: { // 1425-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vCZ4Geg0_sendMessage);
      break;
    }
    case 0xBDA51D66: { // 1425-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pvFnIqYn_sendMessage);
      break;
    }
    case 0x30040A5: { // 1425-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jl6EDOZu_sendMessage);
      break;
    }
    case 0xD148B541: { // 1425-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_puIdtWvG_sendMessage);
      break;
    }
    case 0xADA48AA6: { // 1425-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jFb8uooI_sendMessage);
      break;
    }
    case 0xE3A9780D: { // 1425-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3wfboKgf_sendMessage);
      break;
    }
    case 0xD0D5CEF9: { // 1425-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2JZ1aDEt_sendMessage);
      break;
    }
    case 0x5C820E51: { // 1425-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RMOmIDKX_sendMessage);
      break;
    }
    case 0xF25D44B5: { // 1425-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_prsoxjPI_sendMessage);
      break;
    }
    case 0x7285011E: { // 1425-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_D2UulC8D_sendMessage);
      break;
    }
    case 0xFE26C634: { // 1425-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eo1PcGuu_sendMessage);
      break;
    }
    case 0x50C83E0E: { // 1425-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Sf3UlUDJ_sendMessage);
      break;
    }
    case 0x8E3370CC: { // 1425-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9u2Q2WoU_sendMessage);
      break;
    }
    case 0xA0EFE537: { // 1462-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kxA6XgNM_sendMessage);
      break;
    }
    case 0xEC20A028: { // 1462-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YoCPr1f9_sendMessage);
      break;
    }
    case 0xBBD44683: { // 1462-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ENJVwLWz_sendMessage);
      break;
    }
    case 0x7BC1F9DF: { // 1462-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_s5Tb0AVP_sendMessage);
      break;
    }
    case 0x4B5BA74: { // 1462-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KU8E2G8X_sendMessage);
      break;
    }
    case 0x9C518D6A: { // 1462-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_smFubyv1_sendMessage);
      break;
    }
    case 0xCBB7AAE6: { // 1462-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kIvgwZr2_sendMessage);
      break;
    }
    case 0xB8B4037B: { // 1462-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IeJzihJX_sendMessage);
      break;
    }
    case 0xFD5A1B8B: { // 1462-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4LuN6Fly_sendMessage);
      break;
    }
    case 0xC0CD7EA7: { // 1462-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Toge1gW4_sendMessage);
      break;
    }
    case 0xFF74E5E7: { // 1462-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PtvZ02v0_sendMessage);
      break;
    }
    case 0x94F6ADD2: { // 1462-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_evSV9zzK_sendMessage);
      break;
    }
    case 0xACF89C8: { // 1462-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hvGRZo4D_sendMessage);
      break;
    }
    case 0xC9EF10C4: { // 1499-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UM41rwTS_sendMessage);
      break;
    }
    case 0x650A218A: { // 1499-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mXi5eudv_sendMessage);
      break;
    }
    case 0x1AEC0FEB: { // 1499-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_x8W8go9Z_sendMessage);
      break;
    }
    case 0x90D3CB6A: { // 1499-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rUJpbPwI_sendMessage);
      break;
    }
    case 0xFB007407: { // 1499-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jEcdTOnK_sendMessage);
      break;
    }
    case 0xD741C2E1: { // 1499-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cB2KfVBp_sendMessage);
      break;
    }
    case 0xB713905B: { // 1499-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BxedxBrb_sendMessage);
      break;
    }
    case 0xBCB09D65: { // 1499-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_T0GteK6q_sendMessage);
      break;
    }
    case 0x3462CF26: { // 1499-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_heD1FoTH_sendMessage);
      break;
    }
    case 0x7EB71D60: { // 1499-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RkUj55iW_sendMessage);
      break;
    }
    case 0xF143DE5C: { // 1499-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NauRnm0H_sendMessage);
      break;
    }
    case 0x69B62A6F: { // 1499-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gVT2TZRx_sendMessage);
      break;
    }
    case 0xDE45E1E5: { // 1499-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1OPcUT1Z_sendMessage);
      break;
    }
    case 0xCA7D42C6: { // 1536-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qbBmrEAZ_sendMessage);
      break;
    }
    case 0x806FD96F: { // 1536-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Srs2QlbM_sendMessage);
      break;
    }
    case 0xDCB98A92: { // 1536-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WpYvY7yr_sendMessage);
      break;
    }
    case 0x4CE2FD57: { // 1536-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mGmxsbCG_sendMessage);
      break;
    }
    case 0x6B909FB9: { // 1536-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uAn9zqw4_sendMessage);
      break;
    }
    case 0xF07FBCA: { // 1536-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yAdlsYH8_sendMessage);
      break;
    }
    case 0x849A5730: { // 1536-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6wgfSv1j_sendMessage);
      break;
    }
    case 0x36907641: { // 1536-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PLCfMZBe_sendMessage);
      break;
    }
    case 0xB52D4339: { // 1536-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nLU2i3AG_sendMessage);
      break;
    }
    case 0x12964E75: { // 1536-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_b6DfmkFG_sendMessage);
      break;
    }
    case 0x6AA538B: { // 1536-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hS1w2Z8q_sendMessage);
      break;
    }
    case 0x3E65138: { // 1536-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_L6C72N63_sendMessage);
      break;
    }
    case 0x6681B9BB: { // 1536-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UPeteCQP_sendMessage);
      break;
    }
    case 0x9A67848D: { // 1576-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IunLi465_sendMessage);
      break;
    }
    case 0x28756C44: { // 1576-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8UbtHlxV_sendMessage);
      break;
    }
    case 0xDA3F765E: { // 1584-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kWMIetWs_sendMessage);
      break;
    }
    case 0x63BB35B3: { // 1584-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HTiBNaQl_sendMessage);
      break;
    }
    case 0xBCF12351: { // 1592-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wF78PJdw_sendMessage);
      break;
    }
    case 0x2C88EFF0: { // 1592-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5i5AI5KQ_sendMessage);
      break;
    }
    case 0x24E085E9: { // 1606-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3PkN71bX_sendMessage);
      break;
    }
    case 0x379A99BA: { // 1606-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vgqqosdi_sendMessage);
      break;
    }
    case 0xE15D0C40: { // 1614-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zWW595pW_sendMessage);
      break;
    }
    case 0xFAB26528: { // 1614-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OraqQrGC_sendMessage);
      break;
    }
    case 0x67469CDB: { // 1638-bend
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ucMXPHax_sendMessage);
      break;
    }
    case 0xD2E9EE87: { // 1638-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gGZK9Zx3_sendMessage);
      break;
    }
    case 0x590B79E7: { // 1638-chunk-size-samples
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UUHXKUVu_sendMessage);
      break;
    }
    case 0x1BD17C37: { // 1638-chunk-size-sec
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_I3z2BxtX_sendMessage);
      break;
    }
    case 0x40D20EFE: { // 1638-dur
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pqaxcsox_sendMessage);
      break;
    }
    case 0x8F1874CE: { // 1638-level
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CiThLe76_sendMessage);
      break;
    }
    case 0x3B8EF450: { // 1638-loopstart
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6gdkdXmT_sendMessage);
      break;
    }
    case 0x52A7D435: { // 1638-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TblnXtqh_sendMessage);
      break;
    }
    case 0xDD183CF: { // 1638-reset
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3jTQCeXz_sendMessage);
      break;
    }
    case 0x9D1E092: { // 1638-sample
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Yc1K0Vrg_sendMessage);
      break;
    }
    case 0x7ABA477F: { // 1638-sample-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eFYzkyhx_sendMessage);
      break;
    }
    case 0x10C055C1: { // 1638-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_15wD6EWi_sendMessage);
      break;
    }
    case 0x93FD56E6: { // 1638-start
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YBitqehK_sendMessage);
      break;
    }
    case 0x8D24D2B6: { // 1638-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2r7xUzy0_sendMessage);
      break;
    }
    case 0xB316C51D: { // 1638-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zJX3xpTq_sendMessage);
      break;
    }
    case 0x34F5B966: { // 1638-transposition
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SOshemBf_sendMessage);
      break;
    }
    case 0xAEF9A5F0: { // 1638-vline
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IqB45mIO_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_f0YE5p9u_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7n5YxE2D_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lKveBJ2s_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gZ47smmV_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BP0cYOC4_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_niF7XuyO_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PVrbPH0R_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_puLT41M8_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_m0442LZU_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4leEx4mq_sendMessage);
      break;
    }
    case 0x7FFAC478: { // sampleNameFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QxRcqbot_sendMessage);
      break;
    }
    case 0x62D6FDDE: { // selectsound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HCy3hhFA_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5BHtA12B_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_A9k3CmNJ_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DrOgteuj_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_X3udhRta_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zJzFHEKg_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wMkUngD4_sendMessage);
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


void Heavy_SoundScraper::cSlice_gF56NqnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_9RHlmlku_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_3Bx5Ot5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_yeo6MZB3, 0, m, &cIf_yeo6MZB3_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_XLwhqs0c, 0, m, &cIf_XLwhqs0c_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Kock4fG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_eZZV4EIB, 0, m, &cIf_eZZV4EIB_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_y2cA8LPd, 0, m, &cIf_y2cA8LPd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_7N875SnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_dAkStA76_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ZvTiOJ4O, 0, m, &cIf_ZvTiOJ4O_sendMessage);
}

void Heavy_SoundScraper::cUnop_pfLXWBl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_OW3J85sZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9cWutWzx, HV_BINOP_EQ, 1, m, &cBinop_9cWutWzx_sendMessage);
}

void Heavy_SoundScraper::cUnop_pPzMC17n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_OW3J85sZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9cWutWzx, HV_BINOP_EQ, 1, m, &cBinop_9cWutWzx_sendMessage);
}

void Heavy_SoundScraper::cIf_ZvTiOJ4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_pPzMC17n_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pfLXWBl4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_dAkStA76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZvTiOJ4O, 1, m, &cIf_ZvTiOJ4O_sendMessage);
}

void Heavy_SoundScraper::cIf_XLwhqs0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_r4jsSSPY_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_y2cA8LPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_YeG6wFB6_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_yeo6MZB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_r4jsSSPY_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_eZZV4EIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_YeG6wFB6_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_9RHlmlku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9cWutWzx, HV_BINOP_EQ, 0, m, &cBinop_9cWutWzx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_VPzILekh_sendMessage);
}

void Heavy_SoundScraper::cBinop_OW3J85sZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bSEfAngu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C2gd6MFE_sendMessage);
}

void Heavy_SoundScraper::cBinop_9cWutWzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1cwlh5gI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vx6RNtef_sendMessage);
}

void Heavy_SoundScraper::cCast_vx6RNtef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eZZV4EIB, 1, m, &cIf_eZZV4EIB_sendMessage);
}

void Heavy_SoundScraper::cCast_1cwlh5gI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XLwhqs0c, 1, m, &cIf_XLwhqs0c_sendMessage);
}

void Heavy_SoundScraper::cCast_bSEfAngu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yeo6MZB3, 1, m, &cIf_yeo6MZB3_sendMessage);
}

void Heavy_SoundScraper::cCast_C2gd6MFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_y2cA8LPd, 1, m, &cIf_y2cA8LPd_sendMessage);
}

void Heavy_SoundScraper::cBinop_VPzILekh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9qX1pDTL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_lEBaoPDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_z7EP3Xmj, 0, m, &cVar_z7EP3Xmj_sendMessage);
  cSwitchcase_dlmHjL2T_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_HucbY6X7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uoMfevcH_sendMessage(_c, 0, m);
  cSend_PtT0nRf7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Tg8Au3QT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Sc9TvLaP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Xg9WxPwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_gb2kVcou_sendMessage);
}

void Heavy_SoundScraper::cBinop_gb2kVcou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xg9WxPwm, 1, m, &cVar_Xg9WxPwm_sendMessage);
}

void Heavy_SoundScraper::cCast_liu5RDYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_Zk6PBzoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_8uc0FXbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_z7EP3Xmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Tg8Au3QT, 0, m, &cVar_Tg8Au3QT_sendMessage);
  cSend_yRThZNyI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_dlmHjL2T_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Q3zZiFEX, 0, m, &cSlice_Q3zZiFEX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tHqbwidA, 0, m, &cRandom_tHqbwidA_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_1a4Jg04M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wkhUaHY4_sendMessage);
}

void Heavy_SoundScraper::cUnop_wkhUaHY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 32.0f, 0, m, &cBinop_ABFbyFrP_sendMessage);
}

void Heavy_SoundScraper::cRandom_tHqbwidA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 64.0f, 0, m, &cBinop_1a4Jg04M_sendMessage);
}

void Heavy_SoundScraper::cSlice_Q3zZiFEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tHqbwidA, 1, m, &cRandom_tHqbwidA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSend_Sc9TvLaP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DrOgteuj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_uoMfevcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PVrbPH0R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_yRThZNyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wMkUngD4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_PtT0nRf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_X3udhRta_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_A8NWt7bQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_M9OG4RO1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_M9OG4RO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_niF7XuyO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_F66Em09O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_M9OG4RO1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ABFbyFrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HucbY6X7, 0, m, &cVar_HucbY6X7_sendMessage);
}

void Heavy_SoundScraper::cMsg_pZXm9qyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 64.0f);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EIF8aufA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RWq2eWdr_sendMessage);
}

void Heavy_SoundScraper::cCast_EIF8aufA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_z7EP3Xmj, 0, m, &cVar_z7EP3Xmj_sendMessage);
}

void Heavy_SoundScraper::cCast_RWq2eWdr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HucbY6X7, 0, m, &cVar_HucbY6X7_sendMessage);
}

void Heavy_SoundScraper::cVar_CDjeilGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_GDs39y5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g1Jvs9rK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UKO34jxE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_74uyxlTn_sendMessage);
}

void Heavy_SoundScraper::cIf_DcUQPLEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Zf0BAQoF_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_iKm8hWsI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_fS902wDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GJ2kjPIJ, HV_BINOP_POW, 0, m, &cBinop_GJ2kjPIJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_GJ2kjPIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nHSSkW9R, 0, m, &cPack_nHSSkW9R_sendMessage);
}

void Heavy_SoundScraper::cBinop_E19O6w0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_W75MAl5U_sendMessage);
}

void Heavy_SoundScraper::cCast_UKO34jxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_iuSoZGVi_sendMessage);
}

void Heavy_SoundScraper::cCast_74uyxlTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DcUQPLEO, 0, m, &cIf_DcUQPLEO_sendMessage);
}

void Heavy_SoundScraper::cBinop_iuSoZGVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DcUQPLEO, 1, m, &cIf_DcUQPLEO_sendMessage);
}

void Heavy_SoundScraper::cBinop_iKm8hWsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_E19O6w0G_sendMessage);
}

void Heavy_SoundScraper::cMsg_Zf0BAQoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_nHSSkW9R, 0, m, &cPack_nHSSkW9R_sendMessage);
}

void Heavy_SoundScraper::cBinop_W75MAl5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GJ2kjPIJ, HV_BINOP_POW, 1, m, &cBinop_GJ2kjPIJ_sendMessage);
  cMsg_fS902wDJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_nHSSkW9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_4zhPJk2l, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_J8TVZyOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pMK8Pgq5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_g1Jvs9rK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_ARzN9HOr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ARzN9HOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TLd92gz8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_pMK8Pgq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AaWmRax8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_i1eHe6mL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_P9ZCm75R, 0, m, &cSlice_P9ZCm75R_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3QzWnPi7, 0, m, &cRandom_3QzWnPi7_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_PTmIuiIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2oBbr5Z4_sendMessage);
}

void Heavy_SoundScraper::cUnop_2oBbr5Z4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_jWbuQhBA_sendMessage);
}

void Heavy_SoundScraper::cRandom_3QzWnPi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_PTmIuiIu_sendMessage);
}

void Heavy_SoundScraper::cSlice_P9ZCm75R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3QzWnPi7, 1, m, &cRandom_3QzWnPi7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_aAa17gKu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_D54xwlyF, 0, m, &cSlice_D54xwlyF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_p6dCP7h0, 0, m, &cRandom_p6dCP7h0_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_NYqwgVns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LiKMwNqd_sendMessage);
}

void Heavy_SoundScraper::cUnop_LiKMwNqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QAKFCTX9, 0, m, &cPack_QAKFCTX9_sendMessage);
}

void Heavy_SoundScraper::cRandom_p6dCP7h0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_NYqwgVns_sendMessage);
}

void Heavy_SoundScraper::cSlice_D54xwlyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_p6dCP7h0, 1, m, &cRandom_p6dCP7h0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_eIzA0tC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_yvEbdTnb_sendMessage);
}

void Heavy_SoundScraper::cPack_tCyLDNoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TLP1ZLXH, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_dVe3Q2M7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_J2ovtRYi_sendMessage);
}

void Heavy_SoundScraper::cBinop_dSxbmfR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_dVe3Q2M7_sendMessage);
}

void Heavy_SoundScraper::cPack_6raKcuXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Sl3jLFYS, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_bI5hokle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_ZJ88DFxh_sendMessage);
}

void Heavy_SoundScraper::cMsg_IpI5NVPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KsGcLEkU_sendMessage);
}

void Heavy_SoundScraper::cSystem_KsGcLEkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_veX0fH9D_sendMessage);
}

void Heavy_SoundScraper::cDelay_i5BwdoVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_i5BwdoVw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FLua5l0E, 0, m, &cDelay_FLua5l0E_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_i5BwdoVw, 0, m, &cDelay_i5BwdoVw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_MCWLDrhL, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_FLua5l0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FLua5l0E, m);
  cMsg_cBBq3Gtb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_pyw6zbAu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ZbkB6zVm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_KjMB6Abh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3sRGgYQ0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_Uit9aCmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MENWANRe_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_i5BwdoVw, 2, m, &cDelay_i5BwdoVw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XCjJQME7_sendMessage);
}

void Heavy_SoundScraper::cMsg_3sRGgYQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Uit9aCmF, 0, m, &hTable_Uit9aCmF_sendMessage);
}

void Heavy_SoundScraper::cBinop_veX0fH9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_KjMB6Abh_sendMessage);
}

void Heavy_SoundScraper::cMsg_cBBq3Gtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Uit9aCmF, 0, m, &hTable_Uit9aCmF_sendMessage);
}

void Heavy_SoundScraper::cCast_XCjJQME7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_i5BwdoVw, 0, m, &cDelay_i5BwdoVw_sendMessage);
}

void Heavy_SoundScraper::cMsg_MENWANRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_FLua5l0E, 2, m, &cDelay_FLua5l0E_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZbkB6zVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_MCWLDrhL, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_SiNFlWS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UWOulK8x_sendMessage);
}

void Heavy_SoundScraper::cSystem_UWOulK8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZXaLhujx_sendMessage);
}

void Heavy_SoundScraper::cVar_PN001S4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pTVjzeZm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_pZsncFpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MXRQfvvi_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_835RoTyx, m);
}

void Heavy_SoundScraper::cBinop_ZXaLhujx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yYrneiOh, m);
}

void Heavy_SoundScraper::cMsg_pTVjzeZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pZsncFpO_sendMessage);
}

void Heavy_SoundScraper::cBinop_MXRQfvvi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_K0vHWCYf, m);
}

void Heavy_SoundScraper::cMsg_Edquf7OW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VJfI3Xsv_sendMessage);
}

void Heavy_SoundScraper::cSystem_VJfI3Xsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rezn6Uqf_sendMessage);
}

void Heavy_SoundScraper::cVar_uzhe3rDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pdMLQ1Nw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_iRroJUqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_90gJ2m2H_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1Rbyu1Lv, m);
}

void Heavy_SoundScraper::cBinop_rezn6Uqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LxAAAM9K, m);
}

void Heavy_SoundScraper::cMsg_pdMLQ1Nw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iRroJUqR_sendMessage);
}

void Heavy_SoundScraper::cBinop_90gJ2m2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9KYbO0mX, m);
}

void Heavy_SoundScraper::cBinop_Q8HfAfjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oXDFrtLG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_WwdfqMZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o9leSDaN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DlhKKIIO_sendMessage);
}

void Heavy_SoundScraper::cCast_DlhKKIIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q8HfAfjy, HV_BINOP_DIVIDE, 0, m, &cBinop_Q8HfAfjy_sendMessage);
}

void Heavy_SoundScraper::cCast_o9leSDaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q8HfAfjy, HV_BINOP_DIVIDE, 1, m, &cBinop_Q8HfAfjy_sendMessage);
}

void Heavy_SoundScraper::cBinop_J2ovtRYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gyOoa7I6_sendMessage);
}

void Heavy_SoundScraper::cBinop_UyxrYjLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_dSxbmfR5_sendMessage);
}

void Heavy_SoundScraper::cBinop_gyOoa7I6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q8HfAfjy, HV_BINOP_DIVIDE, 0, m, &cBinop_Q8HfAfjy_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZJ88DFxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6raKcuXb, 0, m, &cPack_6raKcuXb_sendMessage);
}

void Heavy_SoundScraper::cBinop_yvEbdTnb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_WwdfqMZA_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_tCyLDNoF, 0, m, &cPack_tCyLDNoF_sendMessage);
}

void Heavy_SoundScraper::cMsg_TxrINUoV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_eIzA0tC9, 0, m, &cVar_eIzA0tC9_sendMessage);
}

void Heavy_SoundScraper::cMsg_AtohvImR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_bI5hokle, 0, m, &cVar_bI5hokle_sendMessage);
}

void Heavy_SoundScraper::cMsg_oXDFrtLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_PY90kPB2, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_cFTATF4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MAcOpIaT_sendMessage);
}

void Heavy_SoundScraper::cSystem_MAcOpIaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GrbSU3qc_sendMessage);
}

void Heavy_SoundScraper::cVar_N1bIU3am_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IgPEmSBA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_nG7f5diC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_91vbkeHJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dlr9Ba7U, m);
}

void Heavy_SoundScraper::cBinop_GrbSU3qc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q8Ak7iaw, m);
}

void Heavy_SoundScraper::cMsg_IgPEmSBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nG7f5diC_sendMessage);
}

void Heavy_SoundScraper::cBinop_91vbkeHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_s4Q9Jbe6, m);
}

void Heavy_SoundScraper::cVar_3nW7GnM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ce4BzkMc, HV_BINOP_MULTIPLY, 0, m, &cBinop_ce4BzkMc_sendMessage);
}

void Heavy_SoundScraper::cMsg_4LH76Q3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4qgCwlOU_sendMessage);
}

void Heavy_SoundScraper::cSystem_4qgCwlOU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_St7RKOxY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ce4BzkMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_oWUx6CFw_sendMessage);
}

void Heavy_SoundScraper::cBinop_t3gRUWrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ce4BzkMc, HV_BINOP_MULTIPLY, 1, m, &cBinop_ce4BzkMc_sendMessage);
}

void Heavy_SoundScraper::cMsg_St7RKOxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_t3gRUWrg_sendMessage);
}

void Heavy_SoundScraper::cBinop_oWUx6CFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5KZDtF2V_sendMessage);
}

void Heavy_SoundScraper::cBinop_5KZDtF2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_djbdZA6b_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_AMaSOcaw, m);
}

void Heavy_SoundScraper::cBinop_djbdZA6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IoBKSN30, m);
}

void Heavy_SoundScraper::cBinop_5IXN9hyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_4Ei7gsxN_sendMessage);
}

void Heavy_SoundScraper::cBinop_4Ei7gsxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8MKDWaXg, m);
}

void Heavy_SoundScraper::cBinop_VxXTVh9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jFvcrJTy_sendMessage);
}

void Heavy_SoundScraper::cBinop_jFvcrJTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_DKzutU9q_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vhBvXuyI_sendMessage);
}

void Heavy_SoundScraper::cVar_9qBCLUOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_mzXuyRBO_sendMessage);
}

void Heavy_SoundScraper::cMsg_iM5IhmZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rwG1nlcY_sendMessage);
}

void Heavy_SoundScraper::cSystem_rwG1nlcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TrKAhKro, HV_BINOP_DIVIDE, 1, m, &cBinop_TrKAhKro_sendMessage);
}

void Heavy_SoundScraper::cBinop_DKzutU9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_vbAaSg7p_sendMessage);
}

void Heavy_SoundScraper::cBinop_vbAaSg7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lXuvEeCN, m);
}

void Heavy_SoundScraper::cMsg_LIyTs8ul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_thwWBwUn_sendMessage);
}

void Heavy_SoundScraper::cBinop_thwWBwUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_VxXTVh9d_sendMessage);
}

void Heavy_SoundScraper::cBinop_vhBvXuyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LV0rKBrz, m);
}

void Heavy_SoundScraper::cBinop_mzXuyRBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_ZGDWiXWV_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZGDWiXWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TrKAhKro, HV_BINOP_DIVIDE, 0, m, &cBinop_TrKAhKro_sendMessage);
}

void Heavy_SoundScraper::cBinop_TrKAhKro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LIyTs8ul_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_9VennEtx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IqMoSLu2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6Vfgj3vc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uuz5fORR_sendMessage);
}

void Heavy_SoundScraper::cSystem_uuz5fORR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wFWaGrGy_sendMessage);
}

void Heavy_SoundScraper::cDelay_cRPiguM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cRPiguM3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jnVq5i5C, 0, m, &cDelay_jnVq5i5C_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cRPiguM3, 0, m, &cDelay_cRPiguM3_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_nG1E8QsX, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_jnVq5i5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jnVq5i5C, m);
  cMsg_lEyXpUtc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Xm5k0bRk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_rdS6LPbQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_empcoI4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RGwjPr29_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_VjaqfHY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4VeOPpEg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cRPiguM3, 2, m, &cDelay_cRPiguM3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kR9kIHiw_sendMessage);
}

void Heavy_SoundScraper::cMsg_RGwjPr29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VjaqfHY6, 0, m, &hTable_VjaqfHY6_sendMessage);
}

void Heavy_SoundScraper::cBinop_wFWaGrGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_empcoI4x_sendMessage);
}

void Heavy_SoundScraper::cMsg_lEyXpUtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VjaqfHY6, 0, m, &hTable_VjaqfHY6_sendMessage);
}

void Heavy_SoundScraper::cCast_kR9kIHiw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cRPiguM3, 0, m, &cDelay_cRPiguM3_sendMessage);
}

void Heavy_SoundScraper::cMsg_4VeOPpEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_jnVq5i5C, 2, m, &cDelay_jnVq5i5C_sendMessage);
}

void Heavy_SoundScraper::cMsg_rdS6LPbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_nG1E8QsX, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_qCnAnZ4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_IqMoSLu2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_IqMoSLu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_htrZRFu9, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_aC5Lb8WF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_ZjRK45n5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2s9b5add_sendMessage);
}

void Heavy_SoundScraper::cSystem_2s9b5add_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vyCB5Vbh, HV_BINOP_MULTIPLY, 1, m, &cBinop_vyCB5Vbh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_m30CkHPG, HV_BINOP_MULTIPLY, 1, m, &cBinop_m30CkHPG_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_pFcKHUyW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_qdKIRHH0_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_qdKIRHH0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4VPuMozT_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_WLI5CSPo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WLI5CSPo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WLI5CSPo, 0, m, &cDelay_WLI5CSPo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5KJPGZyt, 0, m, &cVar_5KJPGZyt_sendMessage);
}

void Heavy_SoundScraper::cCast_4VPuMozT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qdKIRHH0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WLI5CSPo, 0, m, &cDelay_WLI5CSPo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5KJPGZyt, 0, m, &cVar_5KJPGZyt_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZRpryZYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mcscYLtv_sendMessage);
}

void Heavy_SoundScraper::cSystem_mcscYLtv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gpBCkBaB_sendMessage);
}

void Heavy_SoundScraper::cVar_Q91BSv1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YpcVFBqW, HV_BINOP_MULTIPLY, 0, m, &cBinop_YpcVFBqW_sendMessage);
}

void Heavy_SoundScraper::cMsg_qdKIRHH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WLI5CSPo, 0, m, &cDelay_WLI5CSPo_sendMessage);
}

void Heavy_SoundScraper::cBinop_Yxxz9AQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WLI5CSPo, 2, m, &cDelay_WLI5CSPo_sendMessage);
}

void Heavy_SoundScraper::cBinop_gpBCkBaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YpcVFBqW, HV_BINOP_MULTIPLY, 1, m, &cBinop_YpcVFBqW_sendMessage);
}

void Heavy_SoundScraper::cBinop_YpcVFBqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Yxxz9AQS_sendMessage);
}

void Heavy_SoundScraper::cVar_5KJPGZyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BpDJExe3, HV_BINOP_SUBTRACT, 0, m, &cBinop_BpDJExe3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_6204dSxG_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_GkQfA3Es_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QIH1HCjE_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wkp7afrt_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_QIH1HCjE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zBdwzDkG, 0, m, &cVar_zBdwzDkG_sendMessage);
}

void Heavy_SoundScraper::cCast_Wkp7afrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bc42RpD8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GWE0mIsM_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Sa7NjFTk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WjvfUKvL, 0, m, &cSlice_WjvfUKvL_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_aVP9NMtl, 0, m, &cSlice_aVP9NMtl_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v2p8yTcM_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_GWsfrkn3, 0, m, &cSlice_GWsfrkn3_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Lf7MwPbN, 0, m, &cSlice_Lf7MwPbN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tj7hOV1O_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GLEvDCkM_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_WjvfUKvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_HComAT9Y_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_HComAT9Y_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_aVP9NMtl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZUloDqho_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O6T7xjxF_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZUloDqho_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O6T7xjxF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_f3G9Xswv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0KuQPBlS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bCeSLCGe_sendMessage);
}

void Heavy_SoundScraper::cVar_bZuQslVf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cxZ21Xy8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_cxZ21Xy8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rvvZBIfU_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vyCB5Vbh, HV_BINOP_MULTIPLY, 0, m, &cBinop_vyCB5Vbh_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_izGr7zaA, HV_BINOP_DIVIDE, 1, m, &cBinop_izGr7zaA_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Q91BSv1o, 0, m, &cVar_Q91BSv1o_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_rvvZBIfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6paTNYrb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_ik3F8Xlw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Loff5IxV, HV_BINOP_SUBTRACT, 1, m, &cBinop_Loff5IxV_sendMessage);
}

void Heavy_SoundScraper::cVar_7z1ccC1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zBdwzDkG, 0, m, &cVar_zBdwzDkG_sendMessage);
}

void Heavy_SoundScraper::cVar_zBdwzDkG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GorsA9Zs, HV_BINOP_ADD, 0, m, &cBinop_GorsA9Zs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nOdN8OEK, HV_BINOP_ADD, 0, m, &cBinop_nOdN8OEK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TxffXSoW, 0, m, &cVar_TxffXSoW_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_UyxrYjLY_sendMessage);
}

void Heavy_SoundScraper::cSlice_GWsfrkn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0KuQPBlS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bCeSLCGe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Lf7MwPbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_15kqdee7_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_852lhxMT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_mVLUWrNT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5KJPGZyt, 1, m, &cVar_5KJPGZyt_sendMessage);
}

void Heavy_SoundScraper::cBinop_m30CkHPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mVLUWrNT_sendMessage);
}

void Heavy_SoundScraper::cBinop_vyCB5Vbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GGEwDsjV_sendMessage);
}

void Heavy_SoundScraper::cBinop_GGEwDsjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BpDJExe3, HV_BINOP_SUBTRACT, 1, m, &cBinop_BpDJExe3_sendMessage);
}

void Heavy_SoundScraper::cBinop_BpDJExe3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5KJPGZyt, 1, m, &cVar_5KJPGZyt_sendMessage);
}

void Heavy_SoundScraper::cMsg_9JVUGsTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_pFcKHUyW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_iUlzdlwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_pFcKHUyW_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nOdN8OEK, HV_BINOP_ADD, 1, m, &cBinop_nOdN8OEK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GorsA9Zs, HV_BINOP_ADD, 1, m, &cBinop_GorsA9Zs_sendMessage);
}

void Heavy_SoundScraper::cBinop_6204dSxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GkQfA3Es_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_GorsA9Zs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zBdwzDkG, 1, m, &cVar_zBdwzDkG_sendMessage);
}

void Heavy_SoundScraper::cBinop_izGr7zaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jfnS550B, HV_BINOP_DIVIDE, 1, m, &cBinop_jfnS550B_sendMessage);
}

void Heavy_SoundScraper::cBinop_jfnS550B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nOdN8OEK, HV_BINOP_ADD, 1, m, &cBinop_nOdN8OEK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GorsA9Zs, HV_BINOP_ADD, 1, m, &cBinop_GorsA9Zs_sendMessage);
}

void Heavy_SoundScraper::cCast_bCeSLCGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_izGr7zaA, HV_BINOP_DIVIDE, 0, m, &cBinop_izGr7zaA_sendMessage);
}

void Heavy_SoundScraper::cCast_0KuQPBlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m30CkHPG, HV_BINOP_MULTIPLY, 0, m, &cBinop_m30CkHPG_sendMessage);
}

void Heavy_SoundScraper::cCast_852lhxMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Loff5IxV, HV_BINOP_SUBTRACT, 0, m, &cBinop_Loff5IxV_sendMessage);
}

void Heavy_SoundScraper::cCast_15kqdee7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7z1ccC1S, 1, m, &cVar_7z1ccC1S_sendMessage);
}

void Heavy_SoundScraper::cCast_GWE0mIsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7z1ccC1S, 0, m, &cVar_7z1ccC1S_sendMessage);
}

void Heavy_SoundScraper::cCast_bc42RpD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iUlzdlwR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_nOdN8OEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ik3F8Xlw, 0, m, &cVar_ik3F8Xlw_sendMessage);
}

void Heavy_SoundScraper::cMsg_HComAT9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_pFcKHUyW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_wicw56O9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_f3G9Xswv, 1, m, &cVar_f3G9Xswv_sendMessage);
}

void Heavy_SoundScraper::cMsg_6paTNYrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vyCB5Vbh, HV_BINOP_MULTIPLY, 0, m, &cBinop_vyCB5Vbh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_izGr7zaA, HV_BINOP_DIVIDE, 1, m, &cBinop_izGr7zaA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Q91BSv1o, 0, m, &cVar_Q91BSv1o_sendMessage);
}

void Heavy_SoundScraper::cCast_ZUloDqho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HComAT9Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_O6T7xjxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2vWYeSHq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nOdN8OEK, HV_BINOP_ADD, 0, m, &cBinop_nOdN8OEK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zBdwzDkG, 1, m, &cVar_zBdwzDkG_sendMessage);
}

void Heavy_SoundScraper::cBinop_Loff5IxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jfnS550B, HV_BINOP_DIVIDE, 0, m, &cBinop_jfnS550B_sendMessage);
}

void Heavy_SoundScraper::cCast_2vWYeSHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iUlzdlwR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Tj7hOV1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9JVUGsTZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_GLEvDCkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wicw56O9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_v2p8yTcM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f3G9Xswv, 0, m, &cVar_f3G9Xswv_sendMessage);
}

void Heavy_SoundScraper::cVar_TxffXSoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cPack_oqMjOJOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Sa7NjFTk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_JCc8Zrdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qKYSndnx_sendMessage);
}

void Heavy_SoundScraper::cSystem_qKYSndnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rnlv7z23, HV_BINOP_MULTIPLY, 1, m, &cBinop_Rnlv7z23_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6DEUeD3x, HV_BINOP_MULTIPLY, 1, m, &cBinop_6DEUeD3x_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_LgN3oPVZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_Q0XmiGl9_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Q0XmiGl9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NnUOzpgg_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_adVBMXBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_adVBMXBT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_adVBMXBT, 0, m, &cDelay_adVBMXBT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Au2VEMBJ, 0, m, &cVar_Au2VEMBJ_sendMessage);
}

void Heavy_SoundScraper::cCast_NnUOzpgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q0XmiGl9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_adVBMXBT, 0, m, &cDelay_adVBMXBT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Au2VEMBJ, 0, m, &cVar_Au2VEMBJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_woSD1C87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K7NXBG82_sendMessage);
}

void Heavy_SoundScraper::cSystem_K7NXBG82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_z8PZBJVK_sendMessage);
}

void Heavy_SoundScraper::cVar_RCkRsSmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tyKV4AeD, HV_BINOP_MULTIPLY, 0, m, &cBinop_tyKV4AeD_sendMessage);
}

void Heavy_SoundScraper::cMsg_Q0XmiGl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_adVBMXBT, 0, m, &cDelay_adVBMXBT_sendMessage);
}

void Heavy_SoundScraper::cBinop_DERmHQ36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_adVBMXBT, 2, m, &cDelay_adVBMXBT_sendMessage);
}

void Heavy_SoundScraper::cBinop_z8PZBJVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tyKV4AeD, HV_BINOP_MULTIPLY, 1, m, &cBinop_tyKV4AeD_sendMessage);
}

void Heavy_SoundScraper::cBinop_tyKV4AeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_DERmHQ36_sendMessage);
}

void Heavy_SoundScraper::cVar_Au2VEMBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MiWsi1e2, HV_BINOP_SUBTRACT, 0, m, &cBinop_MiWsi1e2_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_f8IVYekx_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_sIYpXjTB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5c1t18Mc_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_91NYpzW8_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_5c1t18Mc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OknhBpGK, 0, m, &cVar_OknhBpGK_sendMessage);
}

void Heavy_SoundScraper::cCast_91NYpzW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KLE6EXmv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dQjeGvt8_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ZzPJ9P4g_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_y903FRi5, 0, m, &cSlice_y903FRi5_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XDafsAN3, 0, m, &cSlice_XDafsAN3_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_graKOG2N_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wXsWnoml, 0, m, &cSlice_wXsWnoml_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_SX2gz6TU, 0, m, &cSlice_SX2gz6TU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2xycyoii_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LRX6yvlz_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_y903FRi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_pjJqtcdc_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_pjJqtcdc_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_XDafsAN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ybidsNS2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NQoC2nfD_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ybidsNS2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NQoC2nfD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_L8UlPwqZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vzJjE3Bv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JAIg9mE7_sendMessage);
}

void Heavy_SoundScraper::cVar_N1f2HKgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Sm8pkSS5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_Sm8pkSS5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2AoJIYBt_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Rnlv7z23, HV_BINOP_MULTIPLY, 0, m, &cBinop_Rnlv7z23_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_lQEEZx9u, HV_BINOP_DIVIDE, 1, m, &cBinop_lQEEZx9u_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_RCkRsSmF, 0, m, &cVar_RCkRsSmF_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_2AoJIYBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7ey7jchd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_onsg4u3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9InVqm0D, HV_BINOP_SUBTRACT, 1, m, &cBinop_9InVqm0D_sendMessage);
}

void Heavy_SoundScraper::cVar_6SJNRTTi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OknhBpGK, 0, m, &cVar_OknhBpGK_sendMessage);
}

void Heavy_SoundScraper::cVar_OknhBpGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3jT15HkF, HV_BINOP_ADD, 0, m, &cBinop_3jT15HkF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tp8kAiT3, HV_BINOP_ADD, 0, m, &cBinop_Tp8kAiT3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aC5Lb8WF, 0, m, &cVar_aC5Lb8WF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pB9AS2GX, m);
}

void Heavy_SoundScraper::cSlice_wXsWnoml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vzJjE3Bv_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JAIg9mE7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_SX2gz6TU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_g8BTCkIX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Z8Dr2Uva_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_SH7GoYh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Au2VEMBJ, 1, m, &cVar_Au2VEMBJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_6DEUeD3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SH7GoYh6_sendMessage);
}

void Heavy_SoundScraper::cBinop_Rnlv7z23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_030xORkV_sendMessage);
}

void Heavy_SoundScraper::cBinop_030xORkV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MiWsi1e2, HV_BINOP_SUBTRACT, 1, m, &cBinop_MiWsi1e2_sendMessage);
}

void Heavy_SoundScraper::cBinop_MiWsi1e2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Au2VEMBJ, 1, m, &cVar_Au2VEMBJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_C5Flcxce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_LgN3oPVZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_OyNsrPP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_LgN3oPVZ_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tp8kAiT3, HV_BINOP_ADD, 1, m, &cBinop_Tp8kAiT3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3jT15HkF, HV_BINOP_ADD, 1, m, &cBinop_3jT15HkF_sendMessage);
}

void Heavy_SoundScraper::cBinop_f8IVYekx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sIYpXjTB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_3jT15HkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OknhBpGK, 1, m, &cVar_OknhBpGK_sendMessage);
}

void Heavy_SoundScraper::cBinop_lQEEZx9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8EUMUr8T, HV_BINOP_DIVIDE, 1, m, &cBinop_8EUMUr8T_sendMessage);
}

void Heavy_SoundScraper::cBinop_8EUMUr8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tp8kAiT3, HV_BINOP_ADD, 1, m, &cBinop_Tp8kAiT3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3jT15HkF, HV_BINOP_ADD, 1, m, &cBinop_3jT15HkF_sendMessage);
}

void Heavy_SoundScraper::cCast_vzJjE3Bv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6DEUeD3x, HV_BINOP_MULTIPLY, 0, m, &cBinop_6DEUeD3x_sendMessage);
}

void Heavy_SoundScraper::cCast_JAIg9mE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lQEEZx9u, HV_BINOP_DIVIDE, 0, m, &cBinop_lQEEZx9u_sendMessage);
}

void Heavy_SoundScraper::cCast_g8BTCkIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6SJNRTTi, 1, m, &cVar_6SJNRTTi_sendMessage);
}

void Heavy_SoundScraper::cCast_Z8Dr2Uva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9InVqm0D, HV_BINOP_SUBTRACT, 0, m, &cBinop_9InVqm0D_sendMessage);
}

void Heavy_SoundScraper::cCast_dQjeGvt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6SJNRTTi, 0, m, &cVar_6SJNRTTi_sendMessage);
}

void Heavy_SoundScraper::cCast_KLE6EXmv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OyNsrPP3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Tp8kAiT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_onsg4u3h, 0, m, &cVar_onsg4u3h_sendMessage);
}

void Heavy_SoundScraper::cMsg_pjJqtcdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_LgN3oPVZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_PlfRhfDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_L8UlPwqZ, 1, m, &cVar_L8UlPwqZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_7ey7jchd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rnlv7z23, HV_BINOP_MULTIPLY, 0, m, &cBinop_Rnlv7z23_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lQEEZx9u, HV_BINOP_DIVIDE, 1, m, &cBinop_lQEEZx9u_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RCkRsSmF, 0, m, &cVar_RCkRsSmF_sendMessage);
}

void Heavy_SoundScraper::cCast_NQoC2nfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K6Wf4te9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tp8kAiT3, HV_BINOP_ADD, 0, m, &cBinop_Tp8kAiT3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OknhBpGK, 1, m, &cVar_OknhBpGK_sendMessage);
}

void Heavy_SoundScraper::cCast_ybidsNS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pjJqtcdc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_9InVqm0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8EUMUr8T, HV_BINOP_DIVIDE, 0, m, &cBinop_8EUMUr8T_sendMessage);
}

void Heavy_SoundScraper::cCast_K6Wf4te9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OyNsrPP3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_2xycyoii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C5Flcxce_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_graKOG2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L8UlPwqZ, 0, m, &cVar_L8UlPwqZ_sendMessage);
}

void Heavy_SoundScraper::cCast_LRX6yvlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PlfRhfDi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_QAKFCTX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZzPJ9P4g_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_c2NkkjaU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OohGk3Ir, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_4WjQ1L9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_6g5pe8CU_sendMessage);
}

void Heavy_SoundScraper::cBinop_6g5pe8CU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oqMjOJOt, 0, m, &cPack_oqMjOJOt_sendMessage);
}

void Heavy_SoundScraper::cBinop_jWbuQhBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4WjQ1L9R_sendMessage);
}

void Heavy_SoundScraper::cCast_5b34eS4P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_i1eHe6mL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_jCxTCrsf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_aAa17gKu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_qrAHQ1Ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5IXN9hyr_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Qh2iF1Sj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rdYxvAIJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_rdYxvAIJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_mWX9MKIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YbmujmYn_sendMessage);
}

void Heavy_SoundScraper::cSystem_YbmujmYn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mB2fHQHG_sendMessage);
}

void Heavy_SoundScraper::cVar_N2NHHKUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MXt1AfXC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_hN4BhCmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hN4BhCmi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vb6xx54b, 0, m, &cDelay_vb6xx54b_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nFsiV9AO, 0, m, &sTabread_nFsiV9AO_sendMessage);
}

void Heavy_SoundScraper::cDelay_vb6xx54b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vb6xx54b, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nFsiV9AO, 0, m, &sTabread_nFsiV9AO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vb6xx54b, 0, m, &cDelay_vb6xx54b_sendMessage);
}

void Heavy_SoundScraper::sTabread_nFsiV9AO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_570DlWZp, HV_BINOP_SUBTRACT, 0, m, &cBinop_570DlWZp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_CP91iWNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bxaf95Up, HV_BINOP_MAX, 0, m, &cBinop_Bxaf95Up_sendMessage);
}

void Heavy_SoundScraper::cBinop_mB2fHQHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CP91iWNe, HV_BINOP_MULTIPLY, 0, m, &cBinop_CP91iWNe_sendMessage);
}

void Heavy_SoundScraper::cBinop_rdYxvAIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I9AMaWqv_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nFsiV9AO, 0, m, &sTabread_nFsiV9AO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6FpZjTay_sendMessage);
}

void Heavy_SoundScraper::cSystem_kFavKO7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_570DlWZp, HV_BINOP_SUBTRACT, 1, m, &cBinop_570DlWZp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vb6xx54b, 2, m, &cDelay_vb6xx54b_sendMessage);
}

void Heavy_SoundScraper::cMsg_MXt1AfXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kFavKO7X_sendMessage);
}

void Heavy_SoundScraper::cMsg_I9AMaWqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hN4BhCmi, 0, m, &cDelay_hN4BhCmi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vb6xx54b, 0, m, &cDelay_vb6xx54b_sendMessage);
}

void Heavy_SoundScraper::cMsg_gAwgj97C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bxaf95Up, HV_BINOP_MAX, 1, m, &cBinop_Bxaf95Up_sendMessage);
}

void Heavy_SoundScraper::cBinop_Bxaf95Up_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rdYxvAIJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_rdYxvAIJ_sendMessage);
}

void Heavy_SoundScraper::cCast_6FpZjTay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hN4BhCmi, 0, m, &cDelay_hN4BhCmi_sendMessage);
}

void Heavy_SoundScraper::cBinop_8edeyWOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hN4BhCmi, 2, m, &cDelay_hN4BhCmi_sendMessage);
}

void Heavy_SoundScraper::cBinop_570DlWZp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8edeyWOc_sendMessage);
}

void Heavy_SoundScraper::cCast_7MQZ0FY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N2NHHKUW, 0, m, &cVar_N2NHHKUW_sendMessage);
  cMsg_mWX9MKIs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Qh2iF1Sj, 0, m, &cTabhead_Qh2iF1Sj_sendMessage);
}

void Heavy_SoundScraper::cTabhead_cEOFa9Kl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8kyHTbko, HV_BINOP_SUBTRACT, 0, m, &cBinop_8kyHTbko_sendMessage);
}

void Heavy_SoundScraper::cMsg_ejGWhZxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lREnMTtQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_lREnMTtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8Zge7mRj_sendMessage);
}

void Heavy_SoundScraper::cVar_91mfJLLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uqzGqSLl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_Z60FoEOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Z60FoEOn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HHr1cBoN, 0, m, &cDelay_HHr1cBoN_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6MpUprMM, 0, m, &sTabread_6MpUprMM_sendMessage);
}

void Heavy_SoundScraper::cDelay_HHr1cBoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HHr1cBoN, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6MpUprMM, 0, m, &sTabread_6MpUprMM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HHr1cBoN, 0, m, &cDelay_HHr1cBoN_sendMessage);
}

void Heavy_SoundScraper::sTabread_6MpUprMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NTP0h5fK, HV_BINOP_SUBTRACT, 0, m, &cBinop_NTP0h5fK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_4LPlUMtz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aFMyJUD1, HV_BINOP_MAX, 0, m, &cBinop_aFMyJUD1_sendMessage);
}

void Heavy_SoundScraper::cBinop_8Zge7mRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4LPlUMtz, HV_BINOP_MULTIPLY, 0, m, &cBinop_4LPlUMtz_sendMessage);
}

void Heavy_SoundScraper::cBinop_8kyHTbko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2S2sPia0_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6MpUprMM, 0, m, &sTabread_6MpUprMM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dRNQn5DT_sendMessage);
}

void Heavy_SoundScraper::cSystem_b6mVDJJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NTP0h5fK, HV_BINOP_SUBTRACT, 1, m, &cBinop_NTP0h5fK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HHr1cBoN, 2, m, &cDelay_HHr1cBoN_sendMessage);
}

void Heavy_SoundScraper::cMsg_uqzGqSLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_b6mVDJJz_sendMessage);
}

void Heavy_SoundScraper::cMsg_2S2sPia0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z60FoEOn, 0, m, &cDelay_Z60FoEOn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HHr1cBoN, 0, m, &cDelay_HHr1cBoN_sendMessage);
}

void Heavy_SoundScraper::cMsg_mtiO4wsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_aFMyJUD1, HV_BINOP_MAX, 1, m, &cBinop_aFMyJUD1_sendMessage);
}

void Heavy_SoundScraper::cBinop_aFMyJUD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8kyHTbko, HV_BINOP_SUBTRACT, 1, m, &cBinop_8kyHTbko_sendMessage);
}

void Heavy_SoundScraper::cCast_dRNQn5DT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z60FoEOn, 0, m, &cDelay_Z60FoEOn_sendMessage);
}

void Heavy_SoundScraper::cBinop_9Y6P0Ze4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z60FoEOn, 2, m, &cDelay_Z60FoEOn_sendMessage);
}

void Heavy_SoundScraper::cBinop_NTP0h5fK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9Y6P0Ze4_sendMessage);
}

void Heavy_SoundScraper::cCast_WCeHgGMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_91mfJLLA, 0, m, &cVar_91mfJLLA_sendMessage);
  cMsg_ejGWhZxr_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_cEOFa9Kl, 0, m, &cTabhead_cEOFa9Kl_sendMessage);
}

void Heavy_SoundScraper::cTabhead_bp9JVud4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yAXkaPhF, HV_BINOP_SUBTRACT, 0, m, &cBinop_yAXkaPhF_sendMessage);
}

void Heavy_SoundScraper::cMsg_r2sWfSAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_muOSvPJv_sendMessage);
}

void Heavy_SoundScraper::cSystem_muOSvPJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DCAuKvpx_sendMessage);
}

void Heavy_SoundScraper::cVar_Pmrs8wcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IUEu1KLi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_fwHCxVfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fwHCxVfp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kr4buJMe, 0, m, &cDelay_kr4buJMe_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WDZcyJFx, 0, m, &sTabread_WDZcyJFx_sendMessage);
}

void Heavy_SoundScraper::cDelay_kr4buJMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kr4buJMe, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WDZcyJFx, 0, m, &sTabread_WDZcyJFx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kr4buJMe, 0, m, &cDelay_kr4buJMe_sendMessage);
}

void Heavy_SoundScraper::sTabread_WDZcyJFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NCLG9BG8, HV_BINOP_SUBTRACT, 0, m, &cBinop_NCLG9BG8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_npoaxeV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XDTdvHly, HV_BINOP_MAX, 0, m, &cBinop_XDTdvHly_sendMessage);
}

void Heavy_SoundScraper::cBinop_DCAuKvpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_npoaxeV9, HV_BINOP_MULTIPLY, 0, m, &cBinop_npoaxeV9_sendMessage);
}

void Heavy_SoundScraper::cBinop_yAXkaPhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ddg6QTLZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WDZcyJFx, 0, m, &sTabread_WDZcyJFx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HbASFvAc_sendMessage);
}

void Heavy_SoundScraper::cSystem_MBjhDPd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NCLG9BG8, HV_BINOP_SUBTRACT, 1, m, &cBinop_NCLG9BG8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kr4buJMe, 2, m, &cDelay_kr4buJMe_sendMessage);
}

void Heavy_SoundScraper::cMsg_IUEu1KLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MBjhDPd3_sendMessage);
}

void Heavy_SoundScraper::cMsg_ddg6QTLZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fwHCxVfp, 0, m, &cDelay_fwHCxVfp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kr4buJMe, 0, m, &cDelay_kr4buJMe_sendMessage);
}

void Heavy_SoundScraper::cMsg_SzwfSrhe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_XDTdvHly, HV_BINOP_MAX, 1, m, &cBinop_XDTdvHly_sendMessage);
}

void Heavy_SoundScraper::cBinop_XDTdvHly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yAXkaPhF, HV_BINOP_SUBTRACT, 1, m, &cBinop_yAXkaPhF_sendMessage);
}

void Heavy_SoundScraper::cCast_HbASFvAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fwHCxVfp, 0, m, &cDelay_fwHCxVfp_sendMessage);
}

void Heavy_SoundScraper::cBinop_Lda46NaH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fwHCxVfp, 2, m, &cDelay_fwHCxVfp_sendMessage);
}

void Heavy_SoundScraper::cBinop_NCLG9BG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Lda46NaH_sendMessage);
}

void Heavy_SoundScraper::cCast_oUZCMnkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Pmrs8wcP, 0, m, &cVar_Pmrs8wcP_sendMessage);
  cMsg_r2sWfSAD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bp9JVud4, 0, m, &cTabhead_bp9JVud4_sendMessage);
}

void Heavy_SoundScraper::cTabhead_lPUxqSYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ahGZoAVL, HV_BINOP_SUBTRACT, 0, m, &cBinop_ahGZoAVL_sendMessage);
}

void Heavy_SoundScraper::cMsg_Y8Mf70P7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TDyVNArQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_TDyVNArQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_voPbkKje_sendMessage);
}

void Heavy_SoundScraper::cVar_SsZVtlwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jW0Et18t_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_UY4jLKN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UY4jLKN2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0eXs9ie, 0, m, &cDelay_L0eXs9ie_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zQySRaOQ, 0, m, &sTabread_zQySRaOQ_sendMessage);
}

void Heavy_SoundScraper::cDelay_L0eXs9ie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_L0eXs9ie, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zQySRaOQ, 0, m, &sTabread_zQySRaOQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0eXs9ie, 0, m, &cDelay_L0eXs9ie_sendMessage);
}

void Heavy_SoundScraper::sTabread_zQySRaOQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rJPaCtBg, HV_BINOP_SUBTRACT, 0, m, &cBinop_rJPaCtBg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_pD1O0wXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_flOP5uoC, HV_BINOP_MAX, 0, m, &cBinop_flOP5uoC_sendMessage);
}

void Heavy_SoundScraper::cBinop_voPbkKje_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pD1O0wXw, HV_BINOP_MULTIPLY, 0, m, &cBinop_pD1O0wXw_sendMessage);
}

void Heavy_SoundScraper::cBinop_ahGZoAVL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Pv1R0hXS_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zQySRaOQ, 0, m, &sTabread_zQySRaOQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GYwlaRL8_sendMessage);
}

void Heavy_SoundScraper::cSystem_0R5Nt0Fi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rJPaCtBg, HV_BINOP_SUBTRACT, 1, m, &cBinop_rJPaCtBg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0eXs9ie, 2, m, &cDelay_L0eXs9ie_sendMessage);
}

void Heavy_SoundScraper::cMsg_jW0Et18t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0R5Nt0Fi_sendMessage);
}

void Heavy_SoundScraper::cMsg_Pv1R0hXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_UY4jLKN2, 0, m, &cDelay_UY4jLKN2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0eXs9ie, 0, m, &cDelay_L0eXs9ie_sendMessage);
}

void Heavy_SoundScraper::cMsg_qCRjN7Jg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_flOP5uoC, HV_BINOP_MAX, 1, m, &cBinop_flOP5uoC_sendMessage);
}

void Heavy_SoundScraper::cBinop_flOP5uoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ahGZoAVL, HV_BINOP_SUBTRACT, 1, m, &cBinop_ahGZoAVL_sendMessage);
}

void Heavy_SoundScraper::cCast_GYwlaRL8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UY4jLKN2, 0, m, &cDelay_UY4jLKN2_sendMessage);
}

void Heavy_SoundScraper::cBinop_nm7LQBEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UY4jLKN2, 2, m, &cDelay_UY4jLKN2_sendMessage);
}

void Heavy_SoundScraper::cBinop_rJPaCtBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nm7LQBEu_sendMessage);
}

void Heavy_SoundScraper::cCast_RA3JAi6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SsZVtlwB, 0, m, &cVar_SsZVtlwB_sendMessage);
  cMsg_Y8Mf70P7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lPUxqSYh, 0, m, &cTabhead_lPUxqSYh_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ud8LnDuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rVYWMUSX_sendMessage);
}

void Heavy_SoundScraper::cSystem_rVYWMUSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HPPxYi5F_sendMessage);
}

void Heavy_SoundScraper::cDelay_NXBsLqcV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NXBsLqcV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vHoaYqN0, 0, m, &cDelay_vHoaYqN0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NXBsLqcV, 0, m, &cDelay_NXBsLqcV_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2ikyDYvr, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_vHoaYqN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vHoaYqN0, m);
  cMsg_6iWb8QRW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_0pX7Ne7u_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_wYo5597c_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_joGil1Cg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LayJEh9B_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_jVtpceAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CvLlCzV2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NXBsLqcV, 2, m, &cDelay_NXBsLqcV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hBQFXivg_sendMessage);
}

void Heavy_SoundScraper::cMsg_LayJEh9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jVtpceAv, 0, m, &hTable_jVtpceAv_sendMessage);
}

void Heavy_SoundScraper::cBinop_HPPxYi5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_joGil1Cg_sendMessage);
}

void Heavy_SoundScraper::cMsg_6iWb8QRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jVtpceAv, 0, m, &hTable_jVtpceAv_sendMessage);
}

void Heavy_SoundScraper::cCast_hBQFXivg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NXBsLqcV, 0, m, &cDelay_NXBsLqcV_sendMessage);
}

void Heavy_SoundScraper::cMsg_CvLlCzV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vHoaYqN0, 2, m, &cDelay_vHoaYqN0_sendMessage);
}

void Heavy_SoundScraper::cMsg_wYo5597c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2ikyDYvr, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Pk6yXC5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ii8UXpFM_sendMessage);
}

void Heavy_SoundScraper::cSystem_Ii8UXpFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pApp4mqM_sendMessage);
}

void Heavy_SoundScraper::cDelay_QSKIifgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QSKIifgy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ob8fF4w, 0, m, &cDelay_8ob8fF4w_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QSKIifgy, 0, m, &cDelay_QSKIifgy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0O7eryX8, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_8ob8fF4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8ob8fF4w, m);
  cMsg_e1M5IEMs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_94kEK4aC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_tfINctG8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_6CVm4jpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hC7Ks5l9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_gQm9T15j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pbsAEydC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QSKIifgy, 2, m, &cDelay_QSKIifgy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q54FVDrN_sendMessage);
}

void Heavy_SoundScraper::cMsg_hC7Ks5l9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gQm9T15j, 0, m, &hTable_gQm9T15j_sendMessage);
}

void Heavy_SoundScraper::cBinop_pApp4mqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_6CVm4jpl_sendMessage);
}

void Heavy_SoundScraper::cMsg_e1M5IEMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gQm9T15j, 0, m, &hTable_gQm9T15j_sendMessage);
}

void Heavy_SoundScraper::cCast_q54FVDrN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QSKIifgy, 0, m, &cDelay_QSKIifgy_sendMessage);
}

void Heavy_SoundScraper::cMsg_pbsAEydC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ob8fF4w, 2, m, &cDelay_8ob8fF4w_sendMessage);
}

void Heavy_SoundScraper::cMsg_tfINctG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0O7eryX8, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_9Nl4GLXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Mkgpr4Gl_sendMessage);
}

void Heavy_SoundScraper::cSystem_Mkgpr4Gl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eePHH6oa_sendMessage);
}

void Heavy_SoundScraper::cDelay_12fD6C6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_12fD6C6i, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c02UmLkQ, 0, m, &cDelay_c02UmLkQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_12fD6C6i, 0, m, &cDelay_12fD6C6i_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_66PkRnAr, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_c02UmLkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c02UmLkQ, m);
  cMsg_rZJS5GPH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_xogRpRkx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_xkGaxPMp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_dd9rIN79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OEfxKl0F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_Mv6L78uO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NaG5wRph_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_12fD6C6i, 2, m, &cDelay_12fD6C6i_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vQg4wtX1_sendMessage);
}

void Heavy_SoundScraper::cMsg_OEfxKl0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Mv6L78uO, 0, m, &hTable_Mv6L78uO_sendMessage);
}

void Heavy_SoundScraper::cBinop_eePHH6oa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_dd9rIN79_sendMessage);
}

void Heavy_SoundScraper::cMsg_rZJS5GPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Mv6L78uO, 0, m, &hTable_Mv6L78uO_sendMessage);
}

void Heavy_SoundScraper::cCast_vQg4wtX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_12fD6C6i, 0, m, &cDelay_12fD6C6i_sendMessage);
}

void Heavy_SoundScraper::cMsg_NaG5wRph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_c02UmLkQ, 2, m, &cDelay_c02UmLkQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_xkGaxPMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_66PkRnAr, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_COXID2By_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WwF5UhmD_sendMessage);
}

void Heavy_SoundScraper::cSystem_WwF5UhmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TQhq78KG_sendMessage);
}

void Heavy_SoundScraper::cDelay_o4K1kFX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_o4K1kFX8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eOTbDkMZ, 0, m, &cDelay_eOTbDkMZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_o4K1kFX8, 0, m, &cDelay_o4K1kFX8_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_m04BFh4L, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_eOTbDkMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eOTbDkMZ, m);
  cMsg_KlXjYkI5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_gnuHefL2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_x3Jnx7Ld_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_iTMihzNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vZcKPYaw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_HTdiw5Pz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VVNQuaO6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_o4K1kFX8, 2, m, &cDelay_o4K1kFX8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ap0Cyjc2_sendMessage);
}

void Heavy_SoundScraper::cMsg_vZcKPYaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_HTdiw5Pz, 0, m, &hTable_HTdiw5Pz_sendMessage);
}

void Heavy_SoundScraper::cBinop_TQhq78KG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_iTMihzNM_sendMessage);
}

void Heavy_SoundScraper::cMsg_KlXjYkI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_HTdiw5Pz, 0, m, &hTable_HTdiw5Pz_sendMessage);
}

void Heavy_SoundScraper::cCast_ap0Cyjc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_o4K1kFX8, 0, m, &cDelay_o4K1kFX8_sendMessage);
}

void Heavy_SoundScraper::cMsg_VVNQuaO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_eOTbDkMZ, 2, m, &cDelay_eOTbDkMZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_x3Jnx7Ld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_m04BFh4L, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_1BvcWK6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_wbb55CnT_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_cmLU9Q0o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_aiPfvwAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FTz7s88m, HV_BINOP_POW, 0, m, &cBinop_FTz7s88m_sendMessage);
}

void Heavy_SoundScraper::cBinop_FTz7s88m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_wjSSUaTY_sendMessage);
}

void Heavy_SoundScraper::cBinop_TY3yo3Rd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_OpM41i1S_sendMessage);
}

void Heavy_SoundScraper::cCast_3FRNccOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1BvcWK6l, 0, m, &cIf_1BvcWK6l_sendMessage);
}

void Heavy_SoundScraper::cCast_rNZInl1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_UzZJ8ZZB_sendMessage);
}

void Heavy_SoundScraper::cBinop_UzZJ8ZZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1BvcWK6l, 1, m, &cIf_1BvcWK6l_sendMessage);
}

void Heavy_SoundScraper::cBinop_cmLU9Q0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_TY3yo3Rd_sendMessage);
}

void Heavy_SoundScraper::cMsg_wbb55CnT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_wjSSUaTY_sendMessage);
}

void Heavy_SoundScraper::cBinop_OpM41i1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FTz7s88m, HV_BINOP_POW, 1, m, &cBinop_FTz7s88m_sendMessage);
  cMsg_aiPfvwAk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_I78PYX3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_M44fhw6G, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_SaMhCDYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9Nru90GF, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_CUbqqRMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Av8mQhfH_sendMessage);
}

void Heavy_SoundScraper::cBinop_Av8mQhfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_BuXT4ZcE_sendMessage);
}

void Heavy_SoundScraper::cVar_oLcsMzos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GnzueuSa, HV_BINOP_MULTIPLY, 0, m, &cBinop_GnzueuSa_sendMessage);
}

void Heavy_SoundScraper::cMsg_n5v1lewP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hqeijQ6u_sendMessage);
}

void Heavy_SoundScraper::cSystem_hqeijQ6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hWIVGlRW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_GnzueuSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_qVMeXT53_sendMessage);
}

void Heavy_SoundScraper::cBinop_EjzNTPx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GnzueuSa, HV_BINOP_MULTIPLY, 1, m, &cBinop_GnzueuSa_sendMessage);
}

void Heavy_SoundScraper::cMsg_hWIVGlRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_EjzNTPx2_sendMessage);
}

void Heavy_SoundScraper::cBinop_qVMeXT53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_s6qaZbsp_sendMessage);
}

void Heavy_SoundScraper::cBinop_s6qaZbsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_D0GrMs4d_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qUR4c4DW, m);
}

void Heavy_SoundScraper::cBinop_D0GrMs4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dgefkAVN, m);
}

void Heavy_SoundScraper::cVar_mK8fl5jB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rNZInl1J_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3FRNccOx_sendMessage);
}

void Heavy_SoundScraper::cVar_3ImaLLeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_CUbqqRMs_sendMessage);
}

void Heavy_SoundScraper::cVar_Fdnkb8K0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_YSMnGjsi_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xYurcsoE, 0, m, &cIf_xYurcsoE_sendMessage);
}

void Heavy_SoundScraper::cVar_92ThOhVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_xswL0nUX_sendMessage);
}

void Heavy_SoundScraper::cIf_xYurcsoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_JD1RzHHK_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_JBNceENl, 0, m, &cVar_JBNceENl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_YSMnGjsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xYurcsoE, 1, m, &cIf_xYurcsoE_sendMessage);
}

void Heavy_SoundScraper::cBinop_xswL0nUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_huxadaTN_sendMessage);
}

void Heavy_SoundScraper::cBinop_huxadaTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_93W03rJ0, 0, m, &cVar_93W03rJ0_sendMessage);
}

void Heavy_SoundScraper::cTabhead_F4qsxLkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FiIjB6wP, HV_BINOP_SUBTRACT, 0, m, &cBinop_FiIjB6wP_sendMessage);
}

void Heavy_SoundScraper::cMsg_St1eStOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GLtnBPvt_sendMessage);
}

void Heavy_SoundScraper::cSystem_GLtnBPvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3vs84PcD_sendMessage);
}

void Heavy_SoundScraper::cVar_3uYo4STR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mGRFu60E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_YPO78Xqa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YPO78Xqa, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7KlBi9AA, 0, m, &cDelay_7KlBi9AA_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8TiO2QqT, 0, m, &sTabread_8TiO2QqT_sendMessage);
}

void Heavy_SoundScraper::cDelay_7KlBi9AA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7KlBi9AA, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8TiO2QqT, 0, m, &sTabread_8TiO2QqT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7KlBi9AA, 0, m, &cDelay_7KlBi9AA_sendMessage);
}

void Heavy_SoundScraper::sTabread_8TiO2QqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9KlqjE4q, HV_BINOP_SUBTRACT, 0, m, &cBinop_9KlqjE4q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_LgjrOjXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OwlpPLn1, HV_BINOP_MAX, 0, m, &cBinop_OwlpPLn1_sendMessage);
}

void Heavy_SoundScraper::cBinop_3vs84PcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LgjrOjXo, HV_BINOP_MULTIPLY, 0, m, &cBinop_LgjrOjXo_sendMessage);
}

void Heavy_SoundScraper::cBinop_FiIjB6wP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dKBIwzRq_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8TiO2QqT, 0, m, &sTabread_8TiO2QqT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kOhyeCBT_sendMessage);
}

void Heavy_SoundScraper::cSystem_ij0ktwtz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9KlqjE4q, HV_BINOP_SUBTRACT, 1, m, &cBinop_9KlqjE4q_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7KlBi9AA, 2, m, &cDelay_7KlBi9AA_sendMessage);
}

void Heavy_SoundScraper::cMsg_mGRFu60E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ij0ktwtz_sendMessage);
}

void Heavy_SoundScraper::cMsg_dKBIwzRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YPO78Xqa, 0, m, &cDelay_YPO78Xqa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7KlBi9AA, 0, m, &cDelay_7KlBi9AA_sendMessage);
}

void Heavy_SoundScraper::cMsg_7q6G626q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_OwlpPLn1, HV_BINOP_MAX, 1, m, &cBinop_OwlpPLn1_sendMessage);
}

void Heavy_SoundScraper::cBinop_OwlpPLn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FiIjB6wP, HV_BINOP_SUBTRACT, 1, m, &cBinop_FiIjB6wP_sendMessage);
}

void Heavy_SoundScraper::cCast_kOhyeCBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YPO78Xqa, 0, m, &cDelay_YPO78Xqa_sendMessage);
}

void Heavy_SoundScraper::cBinop_K7I4AzG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YPO78Xqa, 2, m, &cDelay_YPO78Xqa_sendMessage);
}

void Heavy_SoundScraper::cBinop_9KlqjE4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_K7I4AzG3_sendMessage);
}

void Heavy_SoundScraper::cCast_Qx3QCVOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3uYo4STR, 0, m, &cVar_3uYo4STR_sendMessage);
  cMsg_St1eStOz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_F4qsxLkm, 0, m, &cTabhead_F4qsxLkm_sendMessage);
}

void Heavy_SoundScraper::cMsg_NZgTeq96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Wlz9JPvn_sendMessage);
}

void Heavy_SoundScraper::cSystem_Wlz9JPvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jQWpKWfr_sendMessage);
}

void Heavy_SoundScraper::cDelay_lt64u1ue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lt64u1ue, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kM72QB8P, 0, m, &cDelay_kM72QB8P_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lt64u1ue, 0, m, &cDelay_lt64u1ue_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SZxDX6FQ, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_kM72QB8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kM72QB8P, m);
  cMsg_sxty706G_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_fODa40vf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_wXuXhDVA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_zyteP1XV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K3mzxTac_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_S8GYBCus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I4boNEV3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lt64u1ue, 2, m, &cDelay_lt64u1ue_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nEQNXOc0_sendMessage);
}

void Heavy_SoundScraper::cMsg_K3mzxTac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_S8GYBCus, 0, m, &hTable_S8GYBCus_sendMessage);
}

void Heavy_SoundScraper::cBinop_jQWpKWfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_zyteP1XV_sendMessage);
}

void Heavy_SoundScraper::cMsg_sxty706G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_S8GYBCus, 0, m, &hTable_S8GYBCus_sendMessage);
}

void Heavy_SoundScraper::cCast_nEQNXOc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lt64u1ue, 0, m, &cDelay_lt64u1ue_sendMessage);
}

void Heavy_SoundScraper::cMsg_I4boNEV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kM72QB8P, 2, m, &cDelay_kM72QB8P_sendMessage);
}

void Heavy_SoundScraper::cMsg_wXuXhDVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SZxDX6FQ, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_khqdUWnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_551qRvkT, HV_BINOP_SUBTRACT, 0, m, &cBinop_551qRvkT_sendMessage);
}

void Heavy_SoundScraper::cMsg_sQWS6Teh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_678GsgdY_sendMessage);
}

void Heavy_SoundScraper::cSystem_678GsgdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RKfuGHlq_sendMessage);
}

void Heavy_SoundScraper::cVar_g3v5JQlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GC6MGMiF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_nzvWKIOF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nzvWKIOF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0qtHhzwn, 0, m, &cDelay_0qtHhzwn_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_G8BLlR3M, 0, m, &sTabread_G8BLlR3M_sendMessage);
}

void Heavy_SoundScraper::cDelay_0qtHhzwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0qtHhzwn, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_G8BLlR3M, 0, m, &sTabread_G8BLlR3M_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0qtHhzwn, 0, m, &cDelay_0qtHhzwn_sendMessage);
}

void Heavy_SoundScraper::sTabread_G8BLlR3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_sWiCjcSa, HV_BINOP_SUBTRACT, 0, m, &cBinop_sWiCjcSa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_pVruW4r2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ABoRvidT, HV_BINOP_MAX, 0, m, &cBinop_ABoRvidT_sendMessage);
}

void Heavy_SoundScraper::cBinop_RKfuGHlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pVruW4r2, HV_BINOP_MULTIPLY, 0, m, &cBinop_pVruW4r2_sendMessage);
}

void Heavy_SoundScraper::cBinop_551qRvkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rRDfUKKF_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_G8BLlR3M, 0, m, &sTabread_G8BLlR3M_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gzffT6JO_sendMessage);
}

void Heavy_SoundScraper::cSystem_1dHN6q32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sWiCjcSa, HV_BINOP_SUBTRACT, 1, m, &cBinop_sWiCjcSa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0qtHhzwn, 2, m, &cDelay_0qtHhzwn_sendMessage);
}

void Heavy_SoundScraper::cMsg_GC6MGMiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1dHN6q32_sendMessage);
}

void Heavy_SoundScraper::cMsg_rRDfUKKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nzvWKIOF, 0, m, &cDelay_nzvWKIOF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0qtHhzwn, 0, m, &cDelay_0qtHhzwn_sendMessage);
}

void Heavy_SoundScraper::cMsg_ctAi9Ryc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ABoRvidT, HV_BINOP_MAX, 1, m, &cBinop_ABoRvidT_sendMessage);
}

void Heavy_SoundScraper::cBinop_ABoRvidT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_551qRvkT, HV_BINOP_SUBTRACT, 1, m, &cBinop_551qRvkT_sendMessage);
}

void Heavy_SoundScraper::cCast_gzffT6JO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nzvWKIOF, 0, m, &cDelay_nzvWKIOF_sendMessage);
}

void Heavy_SoundScraper::cBinop_PP3Dsukz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nzvWKIOF, 2, m, &cDelay_nzvWKIOF_sendMessage);
}

void Heavy_SoundScraper::cBinop_sWiCjcSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PP3Dsukz_sendMessage);
}

void Heavy_SoundScraper::cCast_KTEaAt1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g3v5JQlq, 0, m, &cVar_g3v5JQlq_sendMessage);
  cMsg_sQWS6Teh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_khqdUWnu, 0, m, &cTabhead_khqdUWnu_sendMessage);
}

void Heavy_SoundScraper::cMsg_DQzEeojE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2lj1eCK5_sendMessage);
}

void Heavy_SoundScraper::cSystem_2lj1eCK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_slXvQoxw_sendMessage);
}

void Heavy_SoundScraper::cDelay_RR0g8MO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RR0g8MO7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_N16IhPqm, 0, m, &cDelay_N16IhPqm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RR0g8MO7, 0, m, &cDelay_RR0g8MO7_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wHZ96ogv, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_N16IhPqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_N16IhPqm, m);
  cMsg_ujGceBHB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_EvehvdDh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_22mUvSQR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_NHXGu0Jz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Hs05eP8G_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_OeabZUPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fw4m5LDT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RR0g8MO7, 2, m, &cDelay_RR0g8MO7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HFLthZuE_sendMessage);
}

void Heavy_SoundScraper::cMsg_Hs05eP8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_OeabZUPW, 0, m, &hTable_OeabZUPW_sendMessage);
}

void Heavy_SoundScraper::cBinop_slXvQoxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_NHXGu0Jz_sendMessage);
}

void Heavy_SoundScraper::cMsg_ujGceBHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_OeabZUPW, 0, m, &hTable_OeabZUPW_sendMessage);
}

void Heavy_SoundScraper::cCast_HFLthZuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RR0g8MO7, 0, m, &cDelay_RR0g8MO7_sendMessage);
}

void Heavy_SoundScraper::cMsg_Fw4m5LDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_N16IhPqm, 2, m, &cDelay_N16IhPqm_sendMessage);
}

void Heavy_SoundScraper::cMsg_22mUvSQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wHZ96ogv, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_uIOqhkAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xPhWy2S4, HV_BINOP_SUBTRACT, 0, m, &cBinop_xPhWy2S4_sendMessage);
}

void Heavy_SoundScraper::cMsg_XYNQrn0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ILXOmqUX_sendMessage);
}

void Heavy_SoundScraper::cSystem_ILXOmqUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_keR67IUF_sendMessage);
}

void Heavy_SoundScraper::cVar_7aLtqAgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g9OXBCjG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_MttZITON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MttZITON, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IUNIzeOY, 0, m, &cDelay_IUNIzeOY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vUJLchAb, 0, m, &sTabread_vUJLchAb_sendMessage);
}

void Heavy_SoundScraper::cDelay_IUNIzeOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IUNIzeOY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vUJLchAb, 0, m, &sTabread_vUJLchAb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IUNIzeOY, 0, m, &cDelay_IUNIzeOY_sendMessage);
}

void Heavy_SoundScraper::sTabread_vUJLchAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_B7d41DHI, HV_BINOP_SUBTRACT, 0, m, &cBinop_B7d41DHI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_djFyWzPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RluzQyTv, HV_BINOP_MAX, 0, m, &cBinop_RluzQyTv_sendMessage);
}

void Heavy_SoundScraper::cBinop_keR67IUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_djFyWzPi, HV_BINOP_MULTIPLY, 0, m, &cBinop_djFyWzPi_sendMessage);
}

void Heavy_SoundScraper::cBinop_xPhWy2S4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SZGHHpLh_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vUJLchAb, 0, m, &sTabread_vUJLchAb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NFUk9lAy_sendMessage);
}

void Heavy_SoundScraper::cSystem_zUJRtQxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B7d41DHI, HV_BINOP_SUBTRACT, 1, m, &cBinop_B7d41DHI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IUNIzeOY, 2, m, &cDelay_IUNIzeOY_sendMessage);
}

void Heavy_SoundScraper::cMsg_g9OXBCjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zUJRtQxj_sendMessage);
}

void Heavy_SoundScraper::cMsg_SZGHHpLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_MttZITON, 0, m, &cDelay_MttZITON_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IUNIzeOY, 0, m, &cDelay_IUNIzeOY_sendMessage);
}

void Heavy_SoundScraper::cMsg_EHEc4dyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_RluzQyTv, HV_BINOP_MAX, 1, m, &cBinop_RluzQyTv_sendMessage);
}

void Heavy_SoundScraper::cBinop_RluzQyTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xPhWy2S4, HV_BINOP_SUBTRACT, 1, m, &cBinop_xPhWy2S4_sendMessage);
}

void Heavy_SoundScraper::cCast_NFUk9lAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MttZITON, 0, m, &cDelay_MttZITON_sendMessage);
}

void Heavy_SoundScraper::cBinop_DMxTvuTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MttZITON, 2, m, &cDelay_MttZITON_sendMessage);
}

void Heavy_SoundScraper::cBinop_B7d41DHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DMxTvuTw_sendMessage);
}

void Heavy_SoundScraper::cCast_GKDwsnan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7aLtqAgc, 0, m, &cVar_7aLtqAgc_sendMessage);
  cMsg_XYNQrn0o_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uIOqhkAA, 0, m, &cTabhead_uIOqhkAA_sendMessage);
}

void Heavy_SoundScraper::cMsg_9mL9boCE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XPk27MJT_sendMessage);
}

void Heavy_SoundScraper::cSystem_XPk27MJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_a3dVj6GV_sendMessage);
}

void Heavy_SoundScraper::cDelay_tixNIH3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tixNIH3R, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_37Ik0mJY, 0, m, &cDelay_37Ik0mJY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tixNIH3R, 0, m, &cDelay_tixNIH3R_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bDVtTEPH, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_37Ik0mJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_37Ik0mJY, m);
  cMsg_VmsJ3U4P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_oV8kabC5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_WXbonHcc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_WMsAbo4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eZYf7PYr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_9zLfnrf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NpICslYU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tixNIH3R, 2, m, &cDelay_tixNIH3R_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GsldJFzQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_eZYf7PYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_9zLfnrf6, 0, m, &hTable_9zLfnrf6_sendMessage);
}

void Heavy_SoundScraper::cBinop_a3dVj6GV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_WMsAbo4n_sendMessage);
}

void Heavy_SoundScraper::cMsg_VmsJ3U4P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_9zLfnrf6, 0, m, &hTable_9zLfnrf6_sendMessage);
}

void Heavy_SoundScraper::cCast_GsldJFzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tixNIH3R, 0, m, &cDelay_tixNIH3R_sendMessage);
}

void Heavy_SoundScraper::cMsg_NpICslYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_37Ik0mJY, 2, m, &cDelay_37Ik0mJY_sendMessage);
}

void Heavy_SoundScraper::cMsg_WXbonHcc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bDVtTEPH, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_Mf40FuaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_peLwAYbD, HV_BINOP_SUBTRACT, 0, m, &cBinop_peLwAYbD_sendMessage);
}

void Heavy_SoundScraper::cMsg_IV70i7g4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WgDMaIP3_sendMessage);
}

void Heavy_SoundScraper::cSystem_WgDMaIP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0XW58Uwz_sendMessage);
}

void Heavy_SoundScraper::cVar_Eu2qxh1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I1AoMBkf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_7zWmDk4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7zWmDk4N, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kl4hROAf, 0, m, &cDelay_kl4hROAf_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_lGiNSqRS, 0, m, &sTabread_lGiNSqRS_sendMessage);
}

void Heavy_SoundScraper::cDelay_kl4hROAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kl4hROAf, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_lGiNSqRS, 0, m, &sTabread_lGiNSqRS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kl4hROAf, 0, m, &cDelay_kl4hROAf_sendMessage);
}

void Heavy_SoundScraper::sTabread_lGiNSqRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_8QQA95NS, HV_BINOP_SUBTRACT, 0, m, &cBinop_8QQA95NS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_W7nHuMcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_22JWdPle, HV_BINOP_MAX, 0, m, &cBinop_22JWdPle_sendMessage);
}

void Heavy_SoundScraper::cBinop_0XW58Uwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W7nHuMcP, HV_BINOP_MULTIPLY, 0, m, &cBinop_W7nHuMcP_sendMessage);
}

void Heavy_SoundScraper::cBinop_peLwAYbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nCLAbNRu_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_lGiNSqRS, 0, m, &sTabread_lGiNSqRS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4fprg0pr_sendMessage);
}

void Heavy_SoundScraper::cSystem_0PPp9aTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8QQA95NS, HV_BINOP_SUBTRACT, 1, m, &cBinop_8QQA95NS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kl4hROAf, 2, m, &cDelay_kl4hROAf_sendMessage);
}

void Heavy_SoundScraper::cMsg_I1AoMBkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0PPp9aTr_sendMessage);
}

void Heavy_SoundScraper::cMsg_nCLAbNRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7zWmDk4N, 0, m, &cDelay_7zWmDk4N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kl4hROAf, 0, m, &cDelay_kl4hROAf_sendMessage);
}

void Heavy_SoundScraper::cMsg_E0bDPZ2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_22JWdPle, HV_BINOP_MAX, 1, m, &cBinop_22JWdPle_sendMessage);
}

void Heavy_SoundScraper::cBinop_22JWdPle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_peLwAYbD, HV_BINOP_SUBTRACT, 1, m, &cBinop_peLwAYbD_sendMessage);
}

void Heavy_SoundScraper::cCast_4fprg0pr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7zWmDk4N, 0, m, &cDelay_7zWmDk4N_sendMessage);
}

void Heavy_SoundScraper::cBinop_FC61mczo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7zWmDk4N, 2, m, &cDelay_7zWmDk4N_sendMessage);
}

void Heavy_SoundScraper::cBinop_8QQA95NS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FC61mczo_sendMessage);
}

void Heavy_SoundScraper::cCast_52BKoXJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Eu2qxh1r, 0, m, &cVar_Eu2qxh1r_sendMessage);
  cMsg_IV70i7g4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Mf40FuaB, 0, m, &cTabhead_Mf40FuaB_sendMessage);
}

void Heavy_SoundScraper::cMsg_mkHwuo7g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FDvzRvd9_sendMessage);
}

void Heavy_SoundScraper::cSystem_FDvzRvd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9erSRGL3_sendMessage);
}

void Heavy_SoundScraper::cDelay_f2bnD3Rw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_f2bnD3Rw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VSq7OoZ6, 0, m, &cDelay_VSq7OoZ6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f2bnD3Rw, 0, m, &cDelay_f2bnD3Rw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wX3f1zdF, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_VSq7OoZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VSq7OoZ6, m);
  cMsg_hiLTn0tK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_3svCExrD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6c1i1e7A_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_kodc3Vlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2ty0bO8i_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_JhfOlUP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vhz8KBiP_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f2bnD3Rw, 2, m, &cDelay_f2bnD3Rw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_owcIpRiv_sendMessage);
}

void Heavy_SoundScraper::cMsg_2ty0bO8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_JhfOlUP4, 0, m, &hTable_JhfOlUP4_sendMessage);
}

void Heavy_SoundScraper::cBinop_9erSRGL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_kodc3Vlx_sendMessage);
}

void Heavy_SoundScraper::cMsg_hiLTn0tK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_JhfOlUP4, 0, m, &hTable_JhfOlUP4_sendMessage);
}

void Heavy_SoundScraper::cCast_owcIpRiv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_f2bnD3Rw, 0, m, &cDelay_f2bnD3Rw_sendMessage);
}

void Heavy_SoundScraper::cMsg_vhz8KBiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_VSq7OoZ6, 2, m, &cDelay_VSq7OoZ6_sendMessage);
}

void Heavy_SoundScraper::cMsg_6c1i1e7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wX3f1zdF, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_5PQzVi2C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kZbyKKHs, HV_BINOP_SUBTRACT, 0, m, &cBinop_kZbyKKHs_sendMessage);
}

void Heavy_SoundScraper::cMsg_o7AoDe42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LJ03OE1H_sendMessage);
}

void Heavy_SoundScraper::cSystem_LJ03OE1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Q7NLN3qF_sendMessage);
}

void Heavy_SoundScraper::cVar_zKXoFiBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Yczit0HK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_gt4bOFtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gt4bOFtZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2Wsi620N, 0, m, &cDelay_2Wsi620N_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ByuHBIhT, 0, m, &sTabread_ByuHBIhT_sendMessage);
}

void Heavy_SoundScraper::cDelay_2Wsi620N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2Wsi620N, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ByuHBIhT, 0, m, &sTabread_ByuHBIhT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2Wsi620N, 0, m, &cDelay_2Wsi620N_sendMessage);
}

void Heavy_SoundScraper::sTabread_ByuHBIhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gbmsr61v, HV_BINOP_SUBTRACT, 0, m, &cBinop_gbmsr61v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_0G6bBUjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JmgQOkrF, HV_BINOP_MAX, 0, m, &cBinop_JmgQOkrF_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q7NLN3qF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0G6bBUjD, HV_BINOP_MULTIPLY, 0, m, &cBinop_0G6bBUjD_sendMessage);
}

void Heavy_SoundScraper::cBinop_kZbyKKHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LgdC07Kt_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ByuHBIhT, 0, m, &sTabread_ByuHBIhT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ou8o0KKC_sendMessage);
}

void Heavy_SoundScraper::cSystem_gHjyLD1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gbmsr61v, HV_BINOP_SUBTRACT, 1, m, &cBinop_gbmsr61v_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2Wsi620N, 2, m, &cDelay_2Wsi620N_sendMessage);
}

void Heavy_SoundScraper::cMsg_Yczit0HK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gHjyLD1M_sendMessage);
}

void Heavy_SoundScraper::cMsg_LgdC07Kt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gt4bOFtZ, 0, m, &cDelay_gt4bOFtZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2Wsi620N, 0, m, &cDelay_2Wsi620N_sendMessage);
}

void Heavy_SoundScraper::cMsg_oPpCtap5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_JmgQOkrF, HV_BINOP_MAX, 1, m, &cBinop_JmgQOkrF_sendMessage);
}

void Heavy_SoundScraper::cBinop_JmgQOkrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kZbyKKHs, HV_BINOP_SUBTRACT, 1, m, &cBinop_kZbyKKHs_sendMessage);
}

void Heavy_SoundScraper::cCast_Ou8o0KKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gt4bOFtZ, 0, m, &cDelay_gt4bOFtZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_qVc79JNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gt4bOFtZ, 2, m, &cDelay_gt4bOFtZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_gbmsr61v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qVc79JNI_sendMessage);
}

void Heavy_SoundScraper::cCast_y0RpPREE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zKXoFiBq, 0, m, &cVar_zKXoFiBq_sendMessage);
  cMsg_o7AoDe42_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5PQzVi2C, 0, m, &cTabhead_5PQzVi2C_sendMessage);
}

void Heavy_SoundScraper::cMsg_Kx62RuA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_azveMcn6_sendMessage);
}

void Heavy_SoundScraper::cSystem_azveMcn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_28BOHULZ_sendMessage);
}

void Heavy_SoundScraper::cDelay_7MPgiWsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7MPgiWsr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QWktwaYX, 0, m, &cDelay_QWktwaYX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7MPgiWsr, 0, m, &cDelay_7MPgiWsr_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qZiwZj50, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_QWktwaYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QWktwaYX, m);
  cMsg_19DJDqEY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_lNRC2zsS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_s48sqHfq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_oxVWL8cj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZUzTpwNF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_ex1q5Loa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lB1EglC4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7MPgiWsr, 2, m, &cDelay_7MPgiWsr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZU5PXtMs_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZUzTpwNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ex1q5Loa, 0, m, &hTable_ex1q5Loa_sendMessage);
}

void Heavy_SoundScraper::cBinop_28BOHULZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_oxVWL8cj_sendMessage);
}

void Heavy_SoundScraper::cMsg_19DJDqEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ex1q5Loa, 0, m, &hTable_ex1q5Loa_sendMessage);
}

void Heavy_SoundScraper::cCast_ZU5PXtMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7MPgiWsr, 0, m, &cDelay_7MPgiWsr_sendMessage);
}

void Heavy_SoundScraper::cMsg_lB1EglC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_QWktwaYX, 2, m, &cDelay_QWktwaYX_sendMessage);
}

void Heavy_SoundScraper::cMsg_s48sqHfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qZiwZj50, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_QDoPWXEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wd65SF7B, HV_BINOP_SUBTRACT, 0, m, &cBinop_Wd65SF7B_sendMessage);
}

void Heavy_SoundScraper::cMsg_bl35mNsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RRojLZcQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_RRojLZcQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_t0J3YCJn_sendMessage);
}

void Heavy_SoundScraper::cVar_6PvHlScG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_demBIYva_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_Y0qY4tis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Y0qY4tis, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OPUnkNXi, 0, m, &cDelay_OPUnkNXi_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SoEfIq3Q, 0, m, &sTabread_SoEfIq3Q_sendMessage);
}

void Heavy_SoundScraper::cDelay_OPUnkNXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OPUnkNXi, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SoEfIq3Q, 0, m, &sTabread_SoEfIq3Q_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OPUnkNXi, 0, m, &cDelay_OPUnkNXi_sendMessage);
}

void Heavy_SoundScraper::sTabread_SoEfIq3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mw08Kos8, HV_BINOP_SUBTRACT, 0, m, &cBinop_mw08Kos8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_qGNwSQcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fpV1hQpF, HV_BINOP_MAX, 0, m, &cBinop_fpV1hQpF_sendMessage);
}

void Heavy_SoundScraper::cBinop_t0J3YCJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qGNwSQcC, HV_BINOP_MULTIPLY, 0, m, &cBinop_qGNwSQcC_sendMessage);
}

void Heavy_SoundScraper::cBinop_Wd65SF7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sUi1NPev_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SoEfIq3Q, 0, m, &sTabread_SoEfIq3Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yF27mAlx_sendMessage);
}

void Heavy_SoundScraper::cSystem_fM5mZuZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mw08Kos8, HV_BINOP_SUBTRACT, 1, m, &cBinop_mw08Kos8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OPUnkNXi, 2, m, &cDelay_OPUnkNXi_sendMessage);
}

void Heavy_SoundScraper::cMsg_demBIYva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fM5mZuZb_sendMessage);
}

void Heavy_SoundScraper::cMsg_sUi1NPev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y0qY4tis, 0, m, &cDelay_Y0qY4tis_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OPUnkNXi, 0, m, &cDelay_OPUnkNXi_sendMessage);
}

void Heavy_SoundScraper::cMsg_1RqJzBCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_fpV1hQpF, HV_BINOP_MAX, 1, m, &cBinop_fpV1hQpF_sendMessage);
}

void Heavy_SoundScraper::cBinop_fpV1hQpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wd65SF7B, HV_BINOP_SUBTRACT, 1, m, &cBinop_Wd65SF7B_sendMessage);
}

void Heavy_SoundScraper::cCast_yF27mAlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y0qY4tis, 0, m, &cDelay_Y0qY4tis_sendMessage);
}

void Heavy_SoundScraper::cBinop_5AxOLuyM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y0qY4tis, 2, m, &cDelay_Y0qY4tis_sendMessage);
}

void Heavy_SoundScraper::cBinop_mw08Kos8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5AxOLuyM_sendMessage);
}

void Heavy_SoundScraper::cCast_WLDcZP1W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6PvHlScG, 0, m, &cVar_6PvHlScG_sendMessage);
  cMsg_bl35mNsD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QDoPWXEB, 0, m, &cTabhead_QDoPWXEB_sendMessage);
}

void Heavy_SoundScraper::cMsg_dJelF5Zp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_97AzyO1c_sendMessage);
}

void Heavy_SoundScraper::cSystem_97AzyO1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nt6zrYQr_sendMessage);
}

void Heavy_SoundScraper::cDelay_NgKb0Gou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NgKb0Gou, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ksdeNbu, 0, m, &cDelay_8ksdeNbu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NgKb0Gou, 0, m, &cDelay_NgKb0Gou_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YUCcfRYV, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_8ksdeNbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8ksdeNbu, m);
  cMsg_hXOFHwdd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_qYuezTU2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_rI2xuW8O_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_5xlsrJtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W1cg4g6F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_G8HwV53M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4c9CMMx8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NgKb0Gou, 2, m, &cDelay_NgKb0Gou_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l8rlV8vQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_W1cg4g6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_G8HwV53M, 0, m, &hTable_G8HwV53M_sendMessage);
}

void Heavy_SoundScraper::cBinop_nt6zrYQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_5xlsrJtw_sendMessage);
}

void Heavy_SoundScraper::cMsg_hXOFHwdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_G8HwV53M, 0, m, &hTable_G8HwV53M_sendMessage);
}

void Heavy_SoundScraper::cCast_l8rlV8vQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NgKb0Gou, 0, m, &cDelay_NgKb0Gou_sendMessage);
}

void Heavy_SoundScraper::cMsg_4c9CMMx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ksdeNbu, 2, m, &cDelay_8ksdeNbu_sendMessage);
}

void Heavy_SoundScraper::cMsg_rI2xuW8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YUCcfRYV, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_JBNceENl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oLcsMzos, 0, m, &cVar_oLcsMzos_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Vk3I88T4, 0, m, &cVar_Vk3I88T4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oQTQwdD6, 0, m, &cVar_oQTQwdD6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4nmbuxG1, 0, m, &cVar_4nmbuxG1_sendMessage);
}

void Heavy_SoundScraper::cVar_93W03rJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_DIwhLUYH_sendMessage);
}

void Heavy_SoundScraper::cPack_lY7yv2xT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_NwAX0XzW, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_Vk3I88T4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6G0axKst, HV_BINOP_MULTIPLY, 0, m, &cBinop_6G0axKst_sendMessage);
}

void Heavy_SoundScraper::cMsg_gFj5VcGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1YyPcybw_sendMessage);
}

void Heavy_SoundScraper::cSystem_1YyPcybw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9o4TJwNl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_6G0axKst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_t6vukSqK_sendMessage);
}

void Heavy_SoundScraper::cBinop_9DYBwovu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6G0axKst, HV_BINOP_MULTIPLY, 1, m, &cBinop_6G0axKst_sendMessage);
}

void Heavy_SoundScraper::cMsg_9o4TJwNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_9DYBwovu_sendMessage);
}

void Heavy_SoundScraper::cBinop_t6vukSqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QuxRn3I9_sendMessage);
}

void Heavy_SoundScraper::cBinop_QuxRn3I9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qOZ3yMlu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gaDNZJK1, m);
}

void Heavy_SoundScraper::cBinop_qOZ3yMlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xFCmmsvM, m);
}

void Heavy_SoundScraper::cVar_oQTQwdD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T1gBYGRp, HV_BINOP_MULTIPLY, 0, m, &cBinop_T1gBYGRp_sendMessage);
}

void Heavy_SoundScraper::cMsg_VOQy1s5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8n72VANZ_sendMessage);
}

void Heavy_SoundScraper::cSystem_8n72VANZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gx1PMHyV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_T1gBYGRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_SIltQZDv_sendMessage);
}

void Heavy_SoundScraper::cBinop_TEvkDpJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T1gBYGRp, HV_BINOP_MULTIPLY, 1, m, &cBinop_T1gBYGRp_sendMessage);
}

void Heavy_SoundScraper::cMsg_gx1PMHyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_TEvkDpJS_sendMessage);
}

void Heavy_SoundScraper::cBinop_SIltQZDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QVZJUHy5_sendMessage);
}

void Heavy_SoundScraper::cBinop_QVZJUHy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9BNzjabA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LYPSGsZ0, m);
}

void Heavy_SoundScraper::cBinop_9BNzjabA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zb4IPxIn, m);
}

void Heavy_SoundScraper::cVar_4nmbuxG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7SetHZZS, HV_BINOP_MULTIPLY, 0, m, &cBinop_7SetHZZS_sendMessage);
}

void Heavy_SoundScraper::cMsg_hfZLjphy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9BfWE04f_sendMessage);
}

void Heavy_SoundScraper::cSystem_9BfWE04f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vsRjzcL2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_7SetHZZS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_onyuGUdM_sendMessage);
}

void Heavy_SoundScraper::cBinop_tAjReTJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7SetHZZS, HV_BINOP_MULTIPLY, 1, m, &cBinop_7SetHZZS_sendMessage);
}

void Heavy_SoundScraper::cMsg_vsRjzcL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tAjReTJG_sendMessage);
}

void Heavy_SoundScraper::cBinop_onyuGUdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_G7l75P7Q_sendMessage);
}

void Heavy_SoundScraper::cBinop_G7l75P7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3P08PNGu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WTZM1YbA, m);
}

void Heavy_SoundScraper::cBinop_3P08PNGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pFnUkHHr, m);
}

void Heavy_SoundScraper::cBinop_BuXT4ZcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SaMhCDYJ, 0, m, &cPack_SaMhCDYJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_JD1RzHHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_JBNceENl, 0, m, &cVar_JBNceENl_sendMessage);
}

void Heavy_SoundScraper::cBinop_DIwhLUYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lY7yv2xT, 0, m, &cPack_lY7yv2xT_sendMessage);
}

void Heavy_SoundScraper::cBinop_wjSSUaTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_I78PYX3u, 0, m, &cPack_I78PYX3u_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_s8elvp5Z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_rjs8L9ba_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_rjs8L9ba_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_X4CXhr7p, 1, m, &cDelay_X4CXhr7p_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5SPk4I9g_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_X4CXhr7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_X4CXhr7p, m);
  cMsg_gFCytAjG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_rjs8L9ba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_X4CXhr7p, 0, m, &cDelay_X4CXhr7p_sendMessage);
}

void Heavy_SoundScraper::cCast_5SPk4I9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_X4CXhr7p, 0, m, &cDelay_X4CXhr7p_sendMessage);
}

void Heavy_SoundScraper::cVar_13uN1nuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_i8nrhttR, 0, m, &cPack_i8nrhttR_sendMessage);
}

void Heavy_SoundScraper::cVar_6G6VgaM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_AZ2eUlUY_sendMessage);
}

void Heavy_SoundScraper::cVar_7YrODSHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_hCa7JPcL_sendMessage);
}

void Heavy_SoundScraper::cPack_hT8gPoHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_P6XQRzFt, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_TbkIt99k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VPtCtV62_sendMessage);
}

void Heavy_SoundScraper::cBinop_t6bwxOke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_TbkIt99k_sendMessage);
}

void Heavy_SoundScraper::cPack_E5r2XsbJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_e7rlnpyz, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_boI0Qc6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_9tu1VzWo_sendMessage);
}

void Heavy_SoundScraper::cMsg_ftsx0l4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_o60GELmn_sendMessage);
}

void Heavy_SoundScraper::cSystem_o60GELmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Af4OkUyi_sendMessage);
}

void Heavy_SoundScraper::cDelay_caYwPPqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_caYwPPqG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CWqNmb2N, 0, m, &cDelay_CWqNmb2N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_caYwPPqG, 0, m, &cDelay_caYwPPqG_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y9SpFGiB, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_CWqNmb2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CWqNmb2N, m);
  cMsg_p7SOsLlL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ZRoYdGtO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mfv8BSFE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_6SkXOL89_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NRhxCkg2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_q07YJFQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1LpKoqYp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_caYwPPqG, 2, m, &cDelay_caYwPPqG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KLAXgS0S_sendMessage);
}

void Heavy_SoundScraper::cMsg_NRhxCkg2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_q07YJFQv, 0, m, &hTable_q07YJFQv_sendMessage);
}

void Heavy_SoundScraper::cBinop_Af4OkUyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_6SkXOL89_sendMessage);
}

void Heavy_SoundScraper::cMsg_p7SOsLlL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_q07YJFQv, 0, m, &hTable_q07YJFQv_sendMessage);
}

void Heavy_SoundScraper::cCast_KLAXgS0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_caYwPPqG, 0, m, &cDelay_caYwPPqG_sendMessage);
}

void Heavy_SoundScraper::cMsg_1LpKoqYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_CWqNmb2N, 2, m, &cDelay_CWqNmb2N_sendMessage);
}

void Heavy_SoundScraper::cMsg_mfv8BSFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y9SpFGiB, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_zE21Z3zY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l3OasbBo_sendMessage);
}

void Heavy_SoundScraper::cSystem_l3OasbBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_X1zJ5NsT_sendMessage);
}

void Heavy_SoundScraper::cVar_h96QIkIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_peFvoLx5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_VDiQb7Ke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BXPgqJ21_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_CdR4pfST, m);
}

void Heavy_SoundScraper::cBinop_X1zJ5NsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Vl5g8onr, m);
}

void Heavy_SoundScraper::cMsg_peFvoLx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VDiQb7Ke_sendMessage);
}

void Heavy_SoundScraper::cBinop_BXPgqJ21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MDzAQhe7, m);
}

void Heavy_SoundScraper::cMsg_OET0V7Rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BVpvhMLa_sendMessage);
}

void Heavy_SoundScraper::cSystem_BVpvhMLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sF0K0VSh_sendMessage);
}

void Heavy_SoundScraper::cVar_0fGqAmpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dnzzv3n2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_M8pqoKzM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GPy6sfsl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_R0GB4r9H, m);
}

void Heavy_SoundScraper::cBinop_sF0K0VSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0ymJCToo, m);
}

void Heavy_SoundScraper::cMsg_dnzzv3n2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M8pqoKzM_sendMessage);
}

void Heavy_SoundScraper::cBinop_GPy6sfsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BS17oump, m);
}

void Heavy_SoundScraper::cBinop_51TXXPJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ImjQCTj1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_JczXiQNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QqYqeizO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2XZDavJM_sendMessage);
}

void Heavy_SoundScraper::cCast_QqYqeizO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_51TXXPJW, HV_BINOP_DIVIDE, 1, m, &cBinop_51TXXPJW_sendMessage);
}

void Heavy_SoundScraper::cCast_2XZDavJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_51TXXPJW, HV_BINOP_DIVIDE, 0, m, &cBinop_51TXXPJW_sendMessage);
}

void Heavy_SoundScraper::cBinop_VPtCtV62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jzL0OgY7_sendMessage);
}

void Heavy_SoundScraper::cBinop_AZ2eUlUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_t6bwxOke_sendMessage);
}

void Heavy_SoundScraper::cBinop_jzL0OgY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_51TXXPJW, HV_BINOP_DIVIDE, 0, m, &cBinop_51TXXPJW_sendMessage);
}

void Heavy_SoundScraper::cBinop_9tu1VzWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_E5r2XsbJ, 0, m, &cPack_E5r2XsbJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_hCa7JPcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_JczXiQNr_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_hT8gPoHS, 0, m, &cPack_hT8gPoHS_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZQqc6tSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_7YrODSHZ, 0, m, &cVar_7YrODSHZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_9Xq8ds0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_boI0Qc6O, 0, m, &cVar_boI0Qc6O_sendMessage);
}

void Heavy_SoundScraper::cMsg_ImjQCTj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2I9ucnEo, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_IzyJ7Xer_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i0pGFQrO, HV_BINOP_MULTIPLY, 0, m, &cBinop_i0pGFQrO_sendMessage);
}

void Heavy_SoundScraper::cMsg_LJu9jxo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eTPGMvbA_sendMessage);
}

void Heavy_SoundScraper::cSystem_eTPGMvbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NmxY7XaY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_i0pGFQrO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iYSVgv4c_sendMessage);
}

void Heavy_SoundScraper::cBinop_2L1zixae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i0pGFQrO, HV_BINOP_MULTIPLY, 1, m, &cBinop_i0pGFQrO_sendMessage);
}

void Heavy_SoundScraper::cMsg_NmxY7XaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_2L1zixae_sendMessage);
}

void Heavy_SoundScraper::cBinop_iYSVgv4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ezmjFwFt_sendMessage);
}

void Heavy_SoundScraper::cBinop_ezmjFwFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_z5hN22jC_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8OiixBdl, m);
}

void Heavy_SoundScraper::cBinop_z5hN22jC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UHuarA3L, m);
}

void Heavy_SoundScraper::cVar_aLua7DGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_17CVhu4X, HV_BINOP_MULTIPLY, 0, m, &cBinop_17CVhu4X_sendMessage);
}

void Heavy_SoundScraper::cMsg_6CEqGZ93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3DCBuiKJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_3DCBuiKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wTZZMb5r_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_17CVhu4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_kcnLt7eg_sendMessage);
}

void Heavy_SoundScraper::cBinop_IuvktnS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_17CVhu4X, HV_BINOP_MULTIPLY, 1, m, &cBinop_17CVhu4X_sendMessage);
}

void Heavy_SoundScraper::cMsg_wTZZMb5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IuvktnS6_sendMessage);
}

void Heavy_SoundScraper::cBinop_kcnLt7eg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_45LEezXn_sendMessage);
}

void Heavy_SoundScraper::cBinop_45LEezXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_abFYBe3P_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gwqVDu5D, m);
}

void Heavy_SoundScraper::cBinop_abFYBe3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_egttFfRK, m);
}

void Heavy_SoundScraper::cVar_PgiNjOQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ODvWHyWf, HV_BINOP_MULTIPLY, 0, m, &cBinop_ODvWHyWf_sendMessage);
}

void Heavy_SoundScraper::cMsg_krmBsZyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kBC9t2Oe_sendMessage);
}

void Heavy_SoundScraper::cSystem_kBC9t2Oe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QDj31S60_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ODvWHyWf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_bQLvEWfI_sendMessage);
}

void Heavy_SoundScraper::cBinop_F6qCmqvi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ODvWHyWf, HV_BINOP_MULTIPLY, 1, m, &cBinop_ODvWHyWf_sendMessage);
}

void Heavy_SoundScraper::cMsg_QDj31S60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_F6qCmqvi_sendMessage);
}

void Heavy_SoundScraper::cBinop_bQLvEWfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gy1UAsrb_sendMessage);
}

void Heavy_SoundScraper::cBinop_gy1UAsrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ddsoA2dn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BNLzf529, m);
}

void Heavy_SoundScraper::cBinop_ddsoA2dn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kx9XffAD, m);
}

void Heavy_SoundScraper::cMsg_gvyFe5zz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tOVOEMYQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_tOVOEMYQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_45V8Z6xf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_MllDaIjH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_FBmoAFpE_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fy4Aj4nK, 0, m, &cIf_fy4Aj4nK_sendMessage);
}

void Heavy_SoundScraper::cIf_fy4Aj4nK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_oahNZhC8_sendMessage(_c, 0, m);
      cMsg_cbj3TPJn_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_AyUiTzSN_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_oKYAd1J7_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_kTovkMDl, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_FBmoAFpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fy4Aj4nK, 1, m, &cIf_fy4Aj4nK_sendMessage);
}

void Heavy_SoundScraper::cMsg_AyUiTzSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_WRSq15Bp_sendMessage);
}

void Heavy_SoundScraper::cBinop_WRSq15Bp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vKKOe1zg, m);
}

void Heavy_SoundScraper::cBinop_oKYAd1J7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DrfTZqgx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_DrfTZqgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_g6hhtoVW_sendMessage);
}

void Heavy_SoundScraper::cBinop_g6hhtoVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_34j3ygS7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_34j3ygS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_MHOLhxfs_sendMessage);
}

void Heavy_SoundScraper::cBinop_MHOLhxfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Dqqr9xmO, m);
}

void Heavy_SoundScraper::cBinop_ymtPnGrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qPpBiMoQ, m);
}

void Heavy_SoundScraper::cMsg_45V8Z6xf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ymtPnGrx_sendMessage);
}

void Heavy_SoundScraper::cMsg_oahNZhC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_oKYAd1J7_sendMessage);
}

void Heavy_SoundScraper::cMsg_cbj3TPJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vKKOe1zg, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kTovkMDl, m);
}

void Heavy_SoundScraper::cBinop_tFkoZVCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aLua7DGo, 0, m, &cVar_aLua7DGo_sendMessage);
}

void Heavy_SoundScraper::cBinop_zMJ1iaai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IzyJ7Xer, 0, m, &cVar_IzyJ7Xer_sendMessage);
}

void Heavy_SoundScraper::cBinop_W1gvWZfu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PgiNjOQl, 0, m, &cVar_PgiNjOQl_sendMessage);
}

void Heavy_SoundScraper::cCast_GEEzVmfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bTDMG5Tn, m);
}

void Heavy_SoundScraper::cCast_3GhqtSDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_zMJ1iaai_sendMessage);
}

void Heavy_SoundScraper::cCast_X8SaglSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_tFkoZVCs_sendMessage);
}

void Heavy_SoundScraper::cCast_eVt9zm3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_W1gvWZfu_sendMessage);
}

void Heavy_SoundScraper::cTabhead_c6Jwn46d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tTqgNBin, HV_BINOP_SUBTRACT, 0, m, &cBinop_tTqgNBin_sendMessage);
}

void Heavy_SoundScraper::cMsg_0Psu2AJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CphbCLmK_sendMessage);
}

void Heavy_SoundScraper::cSystem_CphbCLmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YFPHCx0J_sendMessage);
}

void Heavy_SoundScraper::cVar_pzN1VgPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gTKAAtdW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_MJ3g6R6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MJ3g6R6g, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ds8tpMnf, 0, m, &cDelay_Ds8tpMnf_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AgVlguab, 0, m, &sTabread_AgVlguab_sendMessage);
}

void Heavy_SoundScraper::cDelay_Ds8tpMnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ds8tpMnf, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AgVlguab, 0, m, &sTabread_AgVlguab_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ds8tpMnf, 0, m, &cDelay_Ds8tpMnf_sendMessage);
}

void Heavy_SoundScraper::sTabread_AgVlguab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2lnm0cEO, HV_BINOP_SUBTRACT, 0, m, &cBinop_2lnm0cEO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_lV8rDliF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jhGs6TXo, HV_BINOP_MAX, 0, m, &cBinop_jhGs6TXo_sendMessage);
}

void Heavy_SoundScraper::cBinop_YFPHCx0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lV8rDliF, HV_BINOP_MULTIPLY, 0, m, &cBinop_lV8rDliF_sendMessage);
}

void Heavy_SoundScraper::cBinop_tTqgNBin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QVkyjGwt_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AgVlguab, 0, m, &sTabread_AgVlguab_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XqDnbkm5_sendMessage);
}

void Heavy_SoundScraper::cSystem_buw55Hx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2lnm0cEO, HV_BINOP_SUBTRACT, 1, m, &cBinop_2lnm0cEO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ds8tpMnf, 2, m, &cDelay_Ds8tpMnf_sendMessage);
}

void Heavy_SoundScraper::cMsg_gTKAAtdW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_buw55Hx4_sendMessage);
}

void Heavy_SoundScraper::cMsg_QVkyjGwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_MJ3g6R6g, 0, m, &cDelay_MJ3g6R6g_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ds8tpMnf, 0, m, &cDelay_Ds8tpMnf_sendMessage);
}

void Heavy_SoundScraper::cMsg_Cen8fV9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_jhGs6TXo, HV_BINOP_MAX, 1, m, &cBinop_jhGs6TXo_sendMessage);
}

void Heavy_SoundScraper::cBinop_jhGs6TXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tTqgNBin, HV_BINOP_SUBTRACT, 1, m, &cBinop_tTqgNBin_sendMessage);
}

void Heavy_SoundScraper::cCast_XqDnbkm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MJ3g6R6g, 0, m, &cDelay_MJ3g6R6g_sendMessage);
}

void Heavy_SoundScraper::cBinop_TIUBg4f5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MJ3g6R6g, 2, m, &cDelay_MJ3g6R6g_sendMessage);
}

void Heavy_SoundScraper::cBinop_2lnm0cEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TIUBg4f5_sendMessage);
}

void Heavy_SoundScraper::cCast_REFD9s95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pzN1VgPd, 0, m, &cVar_pzN1VgPd_sendMessage);
  cMsg_0Psu2AJ9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_c6Jwn46d, 0, m, &cTabhead_c6Jwn46d_sendMessage);
}

void Heavy_SoundScraper::cTabhead_49cxCtzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fMYvaVbr, HV_BINOP_SUBTRACT, 0, m, &cBinop_fMYvaVbr_sendMessage);
}

void Heavy_SoundScraper::cMsg_U9Lo1R0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WEEmduPl_sendMessage);
}

void Heavy_SoundScraper::cSystem_WEEmduPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ScSzB1JN_sendMessage);
}

void Heavy_SoundScraper::cVar_MjHcADru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F6RZGxkS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_egmB63Qp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_egmB63Qp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HCGq3OHs, 0, m, &cDelay_HCGq3OHs_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OxZuBhjs, 0, m, &sTabread_OxZuBhjs_sendMessage);
}

void Heavy_SoundScraper::cDelay_HCGq3OHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HCGq3OHs, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OxZuBhjs, 0, m, &sTabread_OxZuBhjs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HCGq3OHs, 0, m, &cDelay_HCGq3OHs_sendMessage);
}

void Heavy_SoundScraper::sTabread_OxZuBhjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_7rHWuhhv, HV_BINOP_SUBTRACT, 0, m, &cBinop_7rHWuhhv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_XULG9doF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FbQUXct7, HV_BINOP_MAX, 0, m, &cBinop_FbQUXct7_sendMessage);
}

void Heavy_SoundScraper::cBinop_ScSzB1JN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XULG9doF, HV_BINOP_MULTIPLY, 0, m, &cBinop_XULG9doF_sendMessage);
}

void Heavy_SoundScraper::cBinop_fMYvaVbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_91NhOewo_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OxZuBhjs, 0, m, &sTabread_OxZuBhjs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C9d6pFz5_sendMessage);
}

void Heavy_SoundScraper::cSystem_Npk6pZw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7rHWuhhv, HV_BINOP_SUBTRACT, 1, m, &cBinop_7rHWuhhv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HCGq3OHs, 2, m, &cDelay_HCGq3OHs_sendMessage);
}

void Heavy_SoundScraper::cMsg_F6RZGxkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Npk6pZw0_sendMessage);
}

void Heavy_SoundScraper::cMsg_91NhOewo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_egmB63Qp, 0, m, &cDelay_egmB63Qp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HCGq3OHs, 0, m, &cDelay_HCGq3OHs_sendMessage);
}

void Heavy_SoundScraper::cMsg_eFoEbJCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_FbQUXct7, HV_BINOP_MAX, 1, m, &cBinop_FbQUXct7_sendMessage);
}

void Heavy_SoundScraper::cBinop_FbQUXct7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fMYvaVbr, HV_BINOP_SUBTRACT, 1, m, &cBinop_fMYvaVbr_sendMessage);
}

void Heavy_SoundScraper::cCast_C9d6pFz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_egmB63Qp, 0, m, &cDelay_egmB63Qp_sendMessage);
}

void Heavy_SoundScraper::cBinop_XU0oj91o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_egmB63Qp, 2, m, &cDelay_egmB63Qp_sendMessage);
}

void Heavy_SoundScraper::cBinop_7rHWuhhv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XU0oj91o_sendMessage);
}

void Heavy_SoundScraper::cCast_6wuWsNZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MjHcADru, 0, m, &cVar_MjHcADru_sendMessage);
  cMsg_U9Lo1R0U_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_49cxCtzA, 0, m, &cTabhead_49cxCtzA_sendMessage);
}

void Heavy_SoundScraper::cTabhead_aauTwDH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1nPvFGCM, HV_BINOP_SUBTRACT, 0, m, &cBinop_1nPvFGCM_sendMessage);
}

void Heavy_SoundScraper::cMsg_2at2Fisj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_S1HwrpEg_sendMessage);
}

void Heavy_SoundScraper::cSystem_S1HwrpEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zJdTI29N_sendMessage);
}

void Heavy_SoundScraper::cVar_yqo9LDLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KNZuFntE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_kK5RkVX5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kK5RkVX5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nURErQYp, 0, m, &cDelay_nURErQYp_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7M44m0bj, 0, m, &sTabread_7M44m0bj_sendMessage);
}

void Heavy_SoundScraper::cDelay_nURErQYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nURErQYp, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7M44m0bj, 0, m, &sTabread_7M44m0bj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nURErQYp, 0, m, &cDelay_nURErQYp_sendMessage);
}

void Heavy_SoundScraper::sTabread_7M44m0bj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_J6UVukCW, HV_BINOP_SUBTRACT, 0, m, &cBinop_J6UVukCW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_gQbjdssZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zmoVsNs6, HV_BINOP_MAX, 0, m, &cBinop_zmoVsNs6_sendMessage);
}

void Heavy_SoundScraper::cBinop_zJdTI29N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gQbjdssZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_gQbjdssZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_1nPvFGCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_psUHLfZH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7M44m0bj, 0, m, &sTabread_7M44m0bj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m3TOa5lT_sendMessage);
}

void Heavy_SoundScraper::cSystem_AhHKwzZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J6UVukCW, HV_BINOP_SUBTRACT, 1, m, &cBinop_J6UVukCW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nURErQYp, 2, m, &cDelay_nURErQYp_sendMessage);
}

void Heavy_SoundScraper::cMsg_KNZuFntE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AhHKwzZo_sendMessage);
}

void Heavy_SoundScraper::cMsg_psUHLfZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kK5RkVX5, 0, m, &cDelay_kK5RkVX5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nURErQYp, 0, m, &cDelay_nURErQYp_sendMessage);
}

void Heavy_SoundScraper::cMsg_9WDWwcAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_zmoVsNs6, HV_BINOP_MAX, 1, m, &cBinop_zmoVsNs6_sendMessage);
}

void Heavy_SoundScraper::cBinop_zmoVsNs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1nPvFGCM, HV_BINOP_SUBTRACT, 1, m, &cBinop_1nPvFGCM_sendMessage);
}

void Heavy_SoundScraper::cCast_m3TOa5lT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kK5RkVX5, 0, m, &cDelay_kK5RkVX5_sendMessage);
}

void Heavy_SoundScraper::cBinop_mk9Gphle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kK5RkVX5, 2, m, &cDelay_kK5RkVX5_sendMessage);
}

void Heavy_SoundScraper::cBinop_J6UVukCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mk9Gphle_sendMessage);
}

void Heavy_SoundScraper::cCast_JOJZQmsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yqo9LDLw, 0, m, &cVar_yqo9LDLw_sendMessage);
  cMsg_2at2Fisj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_aauTwDH1, 0, m, &cTabhead_aauTwDH1_sendMessage);
}

void Heavy_SoundScraper::cTabhead_QeTufyKk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tEQtTQmV, HV_BINOP_SUBTRACT, 0, m, &cBinop_tEQtTQmV_sendMessage);
}

void Heavy_SoundScraper::cMsg_klszmtM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hhkIx0le_sendMessage);
}

void Heavy_SoundScraper::cSystem_hhkIx0le_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_trLEHmOe_sendMessage);
}

void Heavy_SoundScraper::cVar_v72dRMLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5zcTTLPp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_VqHVIFBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VqHVIFBL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VfNAoGpm, 0, m, &cDelay_VfNAoGpm_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eh90VO1r, 0, m, &sTabread_eh90VO1r_sendMessage);
}

void Heavy_SoundScraper::cDelay_VfNAoGpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VfNAoGpm, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eh90VO1r, 0, m, &sTabread_eh90VO1r_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VfNAoGpm, 0, m, &cDelay_VfNAoGpm_sendMessage);
}

void Heavy_SoundScraper::sTabread_eh90VO1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_AXtuokJV, HV_BINOP_SUBTRACT, 0, m, &cBinop_AXtuokJV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_3Okxe3om_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NjcuYoVv, HV_BINOP_MAX, 0, m, &cBinop_NjcuYoVv_sendMessage);
}

void Heavy_SoundScraper::cBinop_trLEHmOe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Okxe3om, HV_BINOP_MULTIPLY, 0, m, &cBinop_3Okxe3om_sendMessage);
}

void Heavy_SoundScraper::cBinop_tEQtTQmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_trMZLq1j_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eh90VO1r, 0, m, &sTabread_eh90VO1r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xzEnFxxs_sendMessage);
}

void Heavy_SoundScraper::cSystem_xk2hviqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AXtuokJV, HV_BINOP_SUBTRACT, 1, m, &cBinop_AXtuokJV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VfNAoGpm, 2, m, &cDelay_VfNAoGpm_sendMessage);
}

void Heavy_SoundScraper::cMsg_5zcTTLPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xk2hviqx_sendMessage);
}

void Heavy_SoundScraper::cMsg_trMZLq1j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_VqHVIFBL, 0, m, &cDelay_VqHVIFBL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VfNAoGpm, 0, m, &cDelay_VfNAoGpm_sendMessage);
}

void Heavy_SoundScraper::cMsg_h1BSVTaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_NjcuYoVv, HV_BINOP_MAX, 1, m, &cBinop_NjcuYoVv_sendMessage);
}

void Heavy_SoundScraper::cBinop_NjcuYoVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tEQtTQmV, HV_BINOP_SUBTRACT, 1, m, &cBinop_tEQtTQmV_sendMessage);
}

void Heavy_SoundScraper::cCast_xzEnFxxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VqHVIFBL, 0, m, &cDelay_VqHVIFBL_sendMessage);
}

void Heavy_SoundScraper::cBinop_t5qwEfnQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VqHVIFBL, 2, m, &cDelay_VqHVIFBL_sendMessage);
}

void Heavy_SoundScraper::cBinop_AXtuokJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_t5qwEfnQ_sendMessage);
}

void Heavy_SoundScraper::cCast_VQjT1C2K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v72dRMLm, 0, m, &cVar_v72dRMLm_sendMessage);
  cMsg_klszmtM9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QeTufyKk, 0, m, &cTabhead_QeTufyKk_sendMessage);
}

void Heavy_SoundScraper::cMsg_9OR8acZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BUcnZXpx_sendMessage);
}

void Heavy_SoundScraper::cSystem_BUcnZXpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mZNCJWyJ_sendMessage);
}

void Heavy_SoundScraper::cDelay_xjXtDEcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xjXtDEcr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AbxUgxI4, 0, m, &cDelay_AbxUgxI4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjXtDEcr, 0, m, &cDelay_xjXtDEcr_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uZX5lcGt, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_AbxUgxI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AbxUgxI4, m);
  cMsg_9x39UpNa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_k9Xm7PWZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_o8bTdOks_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_gUyq0cQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qIUzY33Q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_z6CszX9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dn311aVG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjXtDEcr, 2, m, &cDelay_xjXtDEcr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QyvH8K27_sendMessage);
}

void Heavy_SoundScraper::cMsg_qIUzY33Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_z6CszX9t, 0, m, &hTable_z6CszX9t_sendMessage);
}

void Heavy_SoundScraper::cBinop_mZNCJWyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_gUyq0cQp_sendMessage);
}

void Heavy_SoundScraper::cMsg_9x39UpNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_z6CszX9t, 0, m, &hTable_z6CszX9t_sendMessage);
}

void Heavy_SoundScraper::cCast_QyvH8K27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjXtDEcr, 0, m, &cDelay_xjXtDEcr_sendMessage);
}

void Heavy_SoundScraper::cMsg_Dn311aVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_AbxUgxI4, 2, m, &cDelay_AbxUgxI4_sendMessage);
}

void Heavy_SoundScraper::cMsg_o8bTdOks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uZX5lcGt, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_OVuar3mC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ShWngURU_sendMessage);
}

void Heavy_SoundScraper::cSystem_ShWngURU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5uCn7evG_sendMessage);
}

void Heavy_SoundScraper::cDelay_eXNOUEXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eXNOUEXW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xgCG0c4t, 0, m, &cDelay_xgCG0c4t_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eXNOUEXW, 0, m, &cDelay_eXNOUEXW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jSjQlYAw, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_xgCG0c4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xgCG0c4t, m);
  cMsg_BMrLAZhs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_LiiXHtKC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Pyri6waC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_62V7uhOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_upqLo2tw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_56JzGsTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uUxqAbel_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eXNOUEXW, 2, m, &cDelay_eXNOUEXW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y8JlJNvS_sendMessage);
}

void Heavy_SoundScraper::cMsg_upqLo2tw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_56JzGsTx, 0, m, &hTable_56JzGsTx_sendMessage);
}

void Heavy_SoundScraper::cBinop_5uCn7evG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_62V7uhOd_sendMessage);
}

void Heavy_SoundScraper::cMsg_BMrLAZhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_56JzGsTx, 0, m, &hTable_56JzGsTx_sendMessage);
}

void Heavy_SoundScraper::cCast_Y8JlJNvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eXNOUEXW, 0, m, &cDelay_eXNOUEXW_sendMessage);
}

void Heavy_SoundScraper::cMsg_uUxqAbel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_xgCG0c4t, 2, m, &cDelay_xgCG0c4t_sendMessage);
}

void Heavy_SoundScraper::cMsg_Pyri6waC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jSjQlYAw, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_EoiDpUAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rffcdyfO_sendMessage);
}

void Heavy_SoundScraper::cSystem_rffcdyfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wllDieVK_sendMessage);
}

void Heavy_SoundScraper::cDelay_ZdSPeiWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZdSPeiWo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_w4aHoJga, 0, m, &cDelay_w4aHoJga_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZdSPeiWo, 0, m, &cDelay_ZdSPeiWo_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JimkW3VP, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_w4aHoJga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_w4aHoJga, m);
  cMsg_DIYeY6Oc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_wTRQFWCy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ULpLDiEH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_5XpBF2TP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oNwjlEse_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_vfuj0syF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D71xmyPM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZdSPeiWo, 2, m, &cDelay_ZdSPeiWo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qnNMi376_sendMessage);
}

void Heavy_SoundScraper::cMsg_oNwjlEse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vfuj0syF, 0, m, &hTable_vfuj0syF_sendMessage);
}

void Heavy_SoundScraper::cBinop_wllDieVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_5XpBF2TP_sendMessage);
}

void Heavy_SoundScraper::cMsg_DIYeY6Oc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vfuj0syF, 0, m, &hTable_vfuj0syF_sendMessage);
}

void Heavy_SoundScraper::cCast_qnNMi376_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZdSPeiWo, 0, m, &cDelay_ZdSPeiWo_sendMessage);
}

void Heavy_SoundScraper::cMsg_D71xmyPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_w4aHoJga, 2, m, &cDelay_w4aHoJga_sendMessage);
}

void Heavy_SoundScraper::cMsg_ULpLDiEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JimkW3VP, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_UmbK0JI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wZiDGNEa_sendMessage);
}

void Heavy_SoundScraper::cSystem_wZiDGNEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mZPPgteu_sendMessage);
}

void Heavy_SoundScraper::cDelay_1Cd8dnLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1Cd8dnLG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VfGPG8rr, 0, m, &cDelay_VfGPG8rr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Cd8dnLG, 0, m, &cDelay_1Cd8dnLG_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_75MO2qRU, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_VfGPG8rr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VfGPG8rr, m);
  cMsg_SzUHvDeY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_DCMt3naw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_DWdk8emn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_fPf0NaPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aopDR3mF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_VVkTmdpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x8V2rvt6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Cd8dnLG, 2, m, &cDelay_1Cd8dnLG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z2agvnu5_sendMessage);
}

void Heavy_SoundScraper::cMsg_aopDR3mF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VVkTmdpB, 0, m, &hTable_VVkTmdpB_sendMessage);
}

void Heavy_SoundScraper::cBinop_mZPPgteu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_fPf0NaPh_sendMessage);
}

void Heavy_SoundScraper::cMsg_SzUHvDeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VVkTmdpB, 0, m, &hTable_VVkTmdpB_sendMessage);
}

void Heavy_SoundScraper::cCast_z2agvnu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Cd8dnLG, 0, m, &cDelay_1Cd8dnLG_sendMessage);
}

void Heavy_SoundScraper::cMsg_x8V2rvt6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_VfGPG8rr, 2, m, &cDelay_VfGPG8rr_sendMessage);
}

void Heavy_SoundScraper::cMsg_DWdk8emn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_75MO2qRU, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_2Ri9MznF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_7C0l1bZc_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Ue26PYAF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_fgQZGqL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4OuNVA6F, HV_BINOP_POW, 0, m, &cBinop_4OuNVA6F_sendMessage);
}

void Heavy_SoundScraper::cBinop_4OuNVA6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_Zpm7Dfkz_sendMessage);
}

void Heavy_SoundScraper::cBinop_nW3dQdcc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ssOhWfkf_sendMessage);
}

void Heavy_SoundScraper::cCast_7PWzveGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2Ri9MznF, 0, m, &cIf_2Ri9MznF_sendMessage);
}

void Heavy_SoundScraper::cCast_kAnkFbPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_i9nFabXj_sendMessage);
}

void Heavy_SoundScraper::cBinop_i9nFabXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2Ri9MznF, 1, m, &cIf_2Ri9MznF_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ue26PYAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_nW3dQdcc_sendMessage);
}

void Heavy_SoundScraper::cMsg_7C0l1bZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_Zpm7Dfkz_sendMessage);
}

void Heavy_SoundScraper::cBinop_ssOhWfkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4OuNVA6F, HV_BINOP_POW, 1, m, &cBinop_4OuNVA6F_sendMessage);
  cMsg_fgQZGqL2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_5Q1id9Vr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6tzZEzTm, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_O1nLvPsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_eYnFYIuf, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_HpkLfF90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_TulKwe7p_sendMessage);
}

void Heavy_SoundScraper::cBinop_TulKwe7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_YYC3mTYZ_sendMessage);
}

void Heavy_SoundScraper::cVar_K3XIB8AC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C3j3lzPc, HV_BINOP_MULTIPLY, 0, m, &cBinop_C3j3lzPc_sendMessage);
}

void Heavy_SoundScraper::cMsg_skRUoGjq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_c8xZQAuQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_c8xZQAuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FFYOZvdf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_C3j3lzPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_soOEtgIW_sendMessage);
}

void Heavy_SoundScraper::cBinop_fHhDxGwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C3j3lzPc, HV_BINOP_MULTIPLY, 1, m, &cBinop_C3j3lzPc_sendMessage);
}

void Heavy_SoundScraper::cMsg_FFYOZvdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_fHhDxGwx_sendMessage);
}

void Heavy_SoundScraper::cBinop_soOEtgIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Yl6iBi6w_sendMessage);
}

void Heavy_SoundScraper::cBinop_Yl6iBi6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_jsmnZ9Qn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bp4zwb2g, m);
}

void Heavy_SoundScraper::cBinop_jsmnZ9Qn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hLwUGtIf, m);
}

void Heavy_SoundScraper::cVar_NyeoSkPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kAnkFbPK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7PWzveGq_sendMessage);
}

void Heavy_SoundScraper::cVar_HpUQFnyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_HpkLfF90_sendMessage);
}

void Heavy_SoundScraper::cVar_LyPTYrzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_5gTtDo6q_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_0c3pcpPB, 0, m, &cIf_0c3pcpPB_sendMessage);
}

void Heavy_SoundScraper::cVar_9xcwDih4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_QLz4GdbO_sendMessage);
}

void Heavy_SoundScraper::cIf_0c3pcpPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KvwrLvFL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_pGHuwTZr, 0, m, &cVar_pGHuwTZr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_5gTtDo6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0c3pcpPB, 1, m, &cIf_0c3pcpPB_sendMessage);
}

void Heavy_SoundScraper::cBinop_QLz4GdbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CIMybWM5_sendMessage);
}

void Heavy_SoundScraper::cBinop_CIMybWM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gN2kQ6ob, 0, m, &cVar_gN2kQ6ob_sendMessage);
}

void Heavy_SoundScraper::cTabhead_GNqInCF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2OkEwzpX, HV_BINOP_SUBTRACT, 0, m, &cBinop_2OkEwzpX_sendMessage);
}

void Heavy_SoundScraper::cMsg_FXjyMeem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zgpA2D1j_sendMessage);
}

void Heavy_SoundScraper::cSystem_zgpA2D1j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Potr9mkq_sendMessage);
}

void Heavy_SoundScraper::cVar_FoxtFCsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2CR3KDIz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_t9lGsV4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_t9lGsV4d, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0uhJjrqG, 0, m, &cDelay_0uhJjrqG_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5wnKoKew, 0, m, &sTabread_5wnKoKew_sendMessage);
}

void Heavy_SoundScraper::cDelay_0uhJjrqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0uhJjrqG, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5wnKoKew, 0, m, &sTabread_5wnKoKew_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0uhJjrqG, 0, m, &cDelay_0uhJjrqG_sendMessage);
}

void Heavy_SoundScraper::sTabread_5wnKoKew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_VQdALCJp, HV_BINOP_SUBTRACT, 0, m, &cBinop_VQdALCJp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_lQKpZP1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OTujQdol, HV_BINOP_MAX, 0, m, &cBinop_OTujQdol_sendMessage);
}

void Heavy_SoundScraper::cBinop_Potr9mkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lQKpZP1z, HV_BINOP_MULTIPLY, 0, m, &cBinop_lQKpZP1z_sendMessage);
}

void Heavy_SoundScraper::cBinop_2OkEwzpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4xpmZUz9_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5wnKoKew, 0, m, &sTabread_5wnKoKew_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VWdkNQOF_sendMessage);
}

void Heavy_SoundScraper::cSystem_cgWXdxMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VQdALCJp, HV_BINOP_SUBTRACT, 1, m, &cBinop_VQdALCJp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0uhJjrqG, 2, m, &cDelay_0uhJjrqG_sendMessage);
}

void Heavy_SoundScraper::cMsg_2CR3KDIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cgWXdxMa_sendMessage);
}

void Heavy_SoundScraper::cMsg_4xpmZUz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_t9lGsV4d, 0, m, &cDelay_t9lGsV4d_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0uhJjrqG, 0, m, &cDelay_0uhJjrqG_sendMessage);
}

void Heavy_SoundScraper::cMsg_0EsukddP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_OTujQdol, HV_BINOP_MAX, 1, m, &cBinop_OTujQdol_sendMessage);
}

void Heavy_SoundScraper::cBinop_OTujQdol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2OkEwzpX, HV_BINOP_SUBTRACT, 1, m, &cBinop_2OkEwzpX_sendMessage);
}

void Heavy_SoundScraper::cCast_VWdkNQOF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_t9lGsV4d, 0, m, &cDelay_t9lGsV4d_sendMessage);
}

void Heavy_SoundScraper::cBinop_nGfwoYgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_t9lGsV4d, 2, m, &cDelay_t9lGsV4d_sendMessage);
}

void Heavy_SoundScraper::cBinop_VQdALCJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nGfwoYgn_sendMessage);
}

void Heavy_SoundScraper::cCast_SbTZFvs5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FoxtFCsc, 0, m, &cVar_FoxtFCsc_sendMessage);
  cMsg_FXjyMeem_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GNqInCF0, 0, m, &cTabhead_GNqInCF0_sendMessage);
}

void Heavy_SoundScraper::cMsg_UsBXIOXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_idVupPtA_sendMessage);
}

void Heavy_SoundScraper::cSystem_idVupPtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SLkqDj8i_sendMessage);
}

void Heavy_SoundScraper::cDelay_FHMMpkD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FHMMpkD8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_44fTBqee, 0, m, &cDelay_44fTBqee_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FHMMpkD8, 0, m, &cDelay_FHMMpkD8_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OS5yf72n, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_44fTBqee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_44fTBqee, m);
  cMsg_EBIS0uXU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_4y9c8nn5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_GBGpdTpZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_L7qiYLXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YrgKUq8q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_n2E9gz35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FeANFOfo_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FHMMpkD8, 2, m, &cDelay_FHMMpkD8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3IGu7I8l_sendMessage);
}

void Heavy_SoundScraper::cMsg_YrgKUq8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_n2E9gz35, 0, m, &hTable_n2E9gz35_sendMessage);
}

void Heavy_SoundScraper::cBinop_SLkqDj8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_L7qiYLXr_sendMessage);
}

void Heavy_SoundScraper::cMsg_EBIS0uXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_n2E9gz35, 0, m, &hTable_n2E9gz35_sendMessage);
}

void Heavy_SoundScraper::cCast_3IGu7I8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FHMMpkD8, 0, m, &cDelay_FHMMpkD8_sendMessage);
}

void Heavy_SoundScraper::cMsg_FeANFOfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_44fTBqee, 2, m, &cDelay_44fTBqee_sendMessage);
}

void Heavy_SoundScraper::cMsg_GBGpdTpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OS5yf72n, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_ARHN8UiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DJPsuX26, HV_BINOP_SUBTRACT, 0, m, &cBinop_DJPsuX26_sendMessage);
}

void Heavy_SoundScraper::cMsg_MUJ21bs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6vKSAPu1_sendMessage);
}

void Heavy_SoundScraper::cSystem_6vKSAPu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GqEdsLSe_sendMessage);
}

void Heavy_SoundScraper::cVar_nUy2aM88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sjuGqIIb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_z8A5aUak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z8A5aUak, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bNpyiWnL, 0, m, &cDelay_bNpyiWnL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dZv9KKUM, 0, m, &sTabread_dZv9KKUM_sendMessage);
}

void Heavy_SoundScraper::cDelay_bNpyiWnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bNpyiWnL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dZv9KKUM, 0, m, &sTabread_dZv9KKUM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bNpyiWnL, 0, m, &cDelay_bNpyiWnL_sendMessage);
}

void Heavy_SoundScraper::sTabread_dZv9KKUM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_M9ORZjjU, HV_BINOP_SUBTRACT, 0, m, &cBinop_M9ORZjjU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_q9oZeqxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZCHcmrH0, HV_BINOP_MAX, 0, m, &cBinop_ZCHcmrH0_sendMessage);
}

void Heavy_SoundScraper::cBinop_GqEdsLSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q9oZeqxO, HV_BINOP_MULTIPLY, 0, m, &cBinop_q9oZeqxO_sendMessage);
}

void Heavy_SoundScraper::cBinop_DJPsuX26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IKFRAOIV_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dZv9KKUM, 0, m, &sTabread_dZv9KKUM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YSg4Wbnm_sendMessage);
}

void Heavy_SoundScraper::cSystem_pVQrDOhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M9ORZjjU, HV_BINOP_SUBTRACT, 1, m, &cBinop_M9ORZjjU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bNpyiWnL, 2, m, &cDelay_bNpyiWnL_sendMessage);
}

void Heavy_SoundScraper::cMsg_sjuGqIIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pVQrDOhX_sendMessage);
}

void Heavy_SoundScraper::cMsg_IKFRAOIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_z8A5aUak, 0, m, &cDelay_z8A5aUak_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bNpyiWnL, 0, m, &cDelay_bNpyiWnL_sendMessage);
}

void Heavy_SoundScraper::cMsg_jhUWyleh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZCHcmrH0, HV_BINOP_MAX, 1, m, &cBinop_ZCHcmrH0_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZCHcmrH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DJPsuX26, HV_BINOP_SUBTRACT, 1, m, &cBinop_DJPsuX26_sendMessage);
}

void Heavy_SoundScraper::cCast_YSg4Wbnm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z8A5aUak, 0, m, &cDelay_z8A5aUak_sendMessage);
}

void Heavy_SoundScraper::cBinop_wMcZp7ps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z8A5aUak, 2, m, &cDelay_z8A5aUak_sendMessage);
}

void Heavy_SoundScraper::cBinop_M9ORZjjU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wMcZp7ps_sendMessage);
}

void Heavy_SoundScraper::cCast_52l5PXMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nUy2aM88, 0, m, &cVar_nUy2aM88_sendMessage);
  cMsg_MUJ21bs4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ARHN8UiJ, 0, m, &cTabhead_ARHN8UiJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_jikoL51z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nUZapfuf_sendMessage);
}

void Heavy_SoundScraper::cSystem_nUZapfuf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fJxg7usO_sendMessage);
}

void Heavy_SoundScraper::cDelay_KeIhE631_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KeIhE631, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WEX59K8t, 0, m, &cDelay_WEX59K8t_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KeIhE631, 0, m, &cDelay_KeIhE631_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NdM6mKe9, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_WEX59K8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WEX59K8t, m);
  cMsg_umlqZr9f_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_UKAiwWpk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mCMB5RBc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_PC9q8E4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dJXWPdNS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_VNnMcNUN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QmF5BVty_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KeIhE631, 2, m, &cDelay_KeIhE631_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7yav0qsB_sendMessage);
}

void Heavy_SoundScraper::cMsg_dJXWPdNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VNnMcNUN, 0, m, &hTable_VNnMcNUN_sendMessage);
}

void Heavy_SoundScraper::cBinop_fJxg7usO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_PC9q8E4f_sendMessage);
}

void Heavy_SoundScraper::cMsg_umlqZr9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VNnMcNUN, 0, m, &hTable_VNnMcNUN_sendMessage);
}

void Heavy_SoundScraper::cCast_7yav0qsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KeIhE631, 0, m, &cDelay_KeIhE631_sendMessage);
}

void Heavy_SoundScraper::cMsg_QmF5BVty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WEX59K8t, 2, m, &cDelay_WEX59K8t_sendMessage);
}

void Heavy_SoundScraper::cMsg_mCMB5RBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NdM6mKe9, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_XL8xQ3x9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cyz73g6E, HV_BINOP_SUBTRACT, 0, m, &cBinop_cyz73g6E_sendMessage);
}

void Heavy_SoundScraper::cMsg_5C8feYRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Pa8xRrPT_sendMessage);
}

void Heavy_SoundScraper::cSystem_Pa8xRrPT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nHYJpT7T_sendMessage);
}

void Heavy_SoundScraper::cVar_d3apkzzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1Q7meM6M_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_epndJlR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_epndJlR8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c7x5E6Cp, 0, m, &cDelay_c7x5E6Cp_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aoPyPNhj, 0, m, &sTabread_aoPyPNhj_sendMessage);
}

void Heavy_SoundScraper::cDelay_c7x5E6Cp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c7x5E6Cp, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aoPyPNhj, 0, m, &sTabread_aoPyPNhj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c7x5E6Cp, 0, m, &cDelay_c7x5E6Cp_sendMessage);
}

void Heavy_SoundScraper::sTabread_aoPyPNhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_W01xczcH, HV_BINOP_SUBTRACT, 0, m, &cBinop_W01xczcH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_UE1CFFNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ySDwYsfi, HV_BINOP_MAX, 0, m, &cBinop_ySDwYsfi_sendMessage);
}

void Heavy_SoundScraper::cBinop_nHYJpT7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UE1CFFNZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_UE1CFFNZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_cyz73g6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_591bXHPR_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aoPyPNhj, 0, m, &sTabread_aoPyPNhj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JQWOCc4V_sendMessage);
}

void Heavy_SoundScraper::cSystem_plRMeqwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W01xczcH, HV_BINOP_SUBTRACT, 1, m, &cBinop_W01xczcH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c7x5E6Cp, 2, m, &cDelay_c7x5E6Cp_sendMessage);
}

void Heavy_SoundScraper::cMsg_1Q7meM6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_plRMeqwP_sendMessage);
}

void Heavy_SoundScraper::cMsg_591bXHPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_epndJlR8, 0, m, &cDelay_epndJlR8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c7x5E6Cp, 0, m, &cDelay_c7x5E6Cp_sendMessage);
}

void Heavy_SoundScraper::cMsg_vpbI0UTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ySDwYsfi, HV_BINOP_MAX, 1, m, &cBinop_ySDwYsfi_sendMessage);
}

void Heavy_SoundScraper::cBinop_ySDwYsfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cyz73g6E, HV_BINOP_SUBTRACT, 1, m, &cBinop_cyz73g6E_sendMessage);
}

void Heavy_SoundScraper::cCast_JQWOCc4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_epndJlR8, 0, m, &cDelay_epndJlR8_sendMessage);
}

void Heavy_SoundScraper::cBinop_muwdblRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_epndJlR8, 2, m, &cDelay_epndJlR8_sendMessage);
}

void Heavy_SoundScraper::cBinop_W01xczcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_muwdblRE_sendMessage);
}

void Heavy_SoundScraper::cCast_5lnYjJ2S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d3apkzzx, 0, m, &cVar_d3apkzzx_sendMessage);
  cMsg_5C8feYRC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_XL8xQ3x9, 0, m, &cTabhead_XL8xQ3x9_sendMessage);
}

void Heavy_SoundScraper::cMsg_js8R4W8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HshJpsfr_sendMessage);
}

void Heavy_SoundScraper::cSystem_HshJpsfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZRyo3k2d_sendMessage);
}

void Heavy_SoundScraper::cDelay_GO1hcw1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GO1hcw1V, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vPx41Lhj, 0, m, &cDelay_vPx41Lhj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GO1hcw1V, 0, m, &cDelay_GO1hcw1V_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_w0GnQ7af, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_vPx41Lhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vPx41Lhj, m);
  cMsg_OxnIxwlx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_vJeLgpfE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_iWrqjzAU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_HT7iaT2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S97yra29_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_VpWyHd8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8ZvKixEv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GO1hcw1V, 2, m, &cDelay_GO1hcw1V_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FQPbRVJy_sendMessage);
}

void Heavy_SoundScraper::cMsg_S97yra29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VpWyHd8s, 0, m, &hTable_VpWyHd8s_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZRyo3k2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_HT7iaT2b_sendMessage);
}

void Heavy_SoundScraper::cMsg_OxnIxwlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VpWyHd8s, 0, m, &hTable_VpWyHd8s_sendMessage);
}

void Heavy_SoundScraper::cCast_FQPbRVJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GO1hcw1V, 0, m, &cDelay_GO1hcw1V_sendMessage);
}

void Heavy_SoundScraper::cMsg_8ZvKixEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vPx41Lhj, 2, m, &cDelay_vPx41Lhj_sendMessage);
}

void Heavy_SoundScraper::cMsg_iWrqjzAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_w0GnQ7af, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_8WCi2ini_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bNjNlr8S, HV_BINOP_SUBTRACT, 0, m, &cBinop_bNjNlr8S_sendMessage);
}

void Heavy_SoundScraper::cMsg_h444TC4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_P1pW0urD_sendMessage);
}

void Heavy_SoundScraper::cSystem_P1pW0urD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_f0TzSPip_sendMessage);
}

void Heavy_SoundScraper::cVar_Adh4yrss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DJ1xV5x5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_PVC8NRiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PVC8NRiS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IOAfBjxT, 0, m, &cDelay_IOAfBjxT_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4suNHM9o, 0, m, &sTabread_4suNHM9o_sendMessage);
}

void Heavy_SoundScraper::cDelay_IOAfBjxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IOAfBjxT, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4suNHM9o, 0, m, &sTabread_4suNHM9o_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IOAfBjxT, 0, m, &cDelay_IOAfBjxT_sendMessage);
}

void Heavy_SoundScraper::sTabread_4suNHM9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_I9oTSubY, HV_BINOP_SUBTRACT, 0, m, &cBinop_I9oTSubY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ahRzvJYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BCGir0PO, HV_BINOP_MAX, 0, m, &cBinop_BCGir0PO_sendMessage);
}

void Heavy_SoundScraper::cBinop_f0TzSPip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ahRzvJYV, HV_BINOP_MULTIPLY, 0, m, &cBinop_ahRzvJYV_sendMessage);
}

void Heavy_SoundScraper::cBinop_bNjNlr8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ntje5qUp_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4suNHM9o, 0, m, &sTabread_4suNHM9o_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jLeWY46N_sendMessage);
}

void Heavy_SoundScraper::cSystem_dgaqHNc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I9oTSubY, HV_BINOP_SUBTRACT, 1, m, &cBinop_I9oTSubY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IOAfBjxT, 2, m, &cDelay_IOAfBjxT_sendMessage);
}

void Heavy_SoundScraper::cMsg_DJ1xV5x5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dgaqHNc6_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ntje5qUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PVC8NRiS, 0, m, &cDelay_PVC8NRiS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IOAfBjxT, 0, m, &cDelay_IOAfBjxT_sendMessage);
}

void Heavy_SoundScraper::cMsg_xKODkgIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_BCGir0PO, HV_BINOP_MAX, 1, m, &cBinop_BCGir0PO_sendMessage);
}

void Heavy_SoundScraper::cBinop_BCGir0PO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bNjNlr8S, HV_BINOP_SUBTRACT, 1, m, &cBinop_bNjNlr8S_sendMessage);
}

void Heavy_SoundScraper::cCast_jLeWY46N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PVC8NRiS, 0, m, &cDelay_PVC8NRiS_sendMessage);
}

void Heavy_SoundScraper::cBinop_4JU1GNVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PVC8NRiS, 2, m, &cDelay_PVC8NRiS_sendMessage);
}

void Heavy_SoundScraper::cBinop_I9oTSubY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4JU1GNVr_sendMessage);
}

void Heavy_SoundScraper::cCast_V1mvO4qe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Adh4yrss, 0, m, &cVar_Adh4yrss_sendMessage);
  cMsg_h444TC4a_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8WCi2ini, 0, m, &cTabhead_8WCi2ini_sendMessage);
}

void Heavy_SoundScraper::cMsg_0Ln1WGLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_69SKyKTQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_69SKyKTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rns51qrN_sendMessage);
}

void Heavy_SoundScraper::cDelay_tqhqMmxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tqhqMmxe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SalQnEhU, 0, m, &cDelay_SalQnEhU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tqhqMmxe, 0, m, &cDelay_tqhqMmxe_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1YrWt7oa, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_SalQnEhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SalQnEhU, m);
  cMsg_yTr0h6gV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_MOdiCOWs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_pEEu6aS5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_yAiYmqyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b6wb44JD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_msxcGeza_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PgoarTtU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tqhqMmxe, 2, m, &cDelay_tqhqMmxe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cuMwAbMG_sendMessage);
}

void Heavy_SoundScraper::cMsg_b6wb44JD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_msxcGeza, 0, m, &hTable_msxcGeza_sendMessage);
}

void Heavy_SoundScraper::cBinop_rns51qrN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_yAiYmqyA_sendMessage);
}

void Heavy_SoundScraper::cMsg_yTr0h6gV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_msxcGeza, 0, m, &hTable_msxcGeza_sendMessage);
}

void Heavy_SoundScraper::cCast_cuMwAbMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tqhqMmxe, 0, m, &cDelay_tqhqMmxe_sendMessage);
}

void Heavy_SoundScraper::cMsg_PgoarTtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_SalQnEhU, 2, m, &cDelay_SalQnEhU_sendMessage);
}

void Heavy_SoundScraper::cMsg_pEEu6aS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1YrWt7oa, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_ZNB2PqhN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LGSqCNIU, HV_BINOP_SUBTRACT, 0, m, &cBinop_LGSqCNIU_sendMessage);
}

void Heavy_SoundScraper::cMsg_XA3xsssM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_V03LXoga_sendMessage);
}

void Heavy_SoundScraper::cSystem_V03LXoga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_T6JvrdrU_sendMessage);
}

void Heavy_SoundScraper::cVar_reMorDrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4JuvyVqu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_PwB0XfqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PwB0XfqW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fGpOZigy, 0, m, &cDelay_fGpOZigy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mgIVHQem, 0, m, &sTabread_mgIVHQem_sendMessage);
}

void Heavy_SoundScraper::cDelay_fGpOZigy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fGpOZigy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mgIVHQem, 0, m, &sTabread_mgIVHQem_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fGpOZigy, 0, m, &cDelay_fGpOZigy_sendMessage);
}

void Heavy_SoundScraper::sTabread_mgIVHQem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_znMwlMDA, HV_BINOP_SUBTRACT, 0, m, &cBinop_znMwlMDA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_SUQ2IIKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j2Kjs8wj, HV_BINOP_MAX, 0, m, &cBinop_j2Kjs8wj_sendMessage);
}

void Heavy_SoundScraper::cBinop_T6JvrdrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SUQ2IIKw, HV_BINOP_MULTIPLY, 0, m, &cBinop_SUQ2IIKw_sendMessage);
}

void Heavy_SoundScraper::cBinop_LGSqCNIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Yl98cmX9_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mgIVHQem, 0, m, &sTabread_mgIVHQem_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uz7hG1MG_sendMessage);
}

void Heavy_SoundScraper::cSystem_jcL3HF47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_znMwlMDA, HV_BINOP_SUBTRACT, 1, m, &cBinop_znMwlMDA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fGpOZigy, 2, m, &cDelay_fGpOZigy_sendMessage);
}

void Heavy_SoundScraper::cMsg_4JuvyVqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jcL3HF47_sendMessage);
}

void Heavy_SoundScraper::cMsg_Yl98cmX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PwB0XfqW, 0, m, &cDelay_PwB0XfqW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fGpOZigy, 0, m, &cDelay_fGpOZigy_sendMessage);
}

void Heavy_SoundScraper::cMsg_exxuU9kf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_j2Kjs8wj, HV_BINOP_MAX, 1, m, &cBinop_j2Kjs8wj_sendMessage);
}

void Heavy_SoundScraper::cBinop_j2Kjs8wj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LGSqCNIU, HV_BINOP_SUBTRACT, 1, m, &cBinop_LGSqCNIU_sendMessage);
}

void Heavy_SoundScraper::cCast_uz7hG1MG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PwB0XfqW, 0, m, &cDelay_PwB0XfqW_sendMessage);
}

void Heavy_SoundScraper::cBinop_GK9BAMA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PwB0XfqW, 2, m, &cDelay_PwB0XfqW_sendMessage);
}

void Heavy_SoundScraper::cBinop_znMwlMDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GK9BAMA0_sendMessage);
}

void Heavy_SoundScraper::cCast_dpaLbzGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_reMorDrL, 0, m, &cVar_reMorDrL_sendMessage);
  cMsg_XA3xsssM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZNB2PqhN, 0, m, &cTabhead_ZNB2PqhN_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ko7ndIwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qMp0Jcfz_sendMessage);
}

void Heavy_SoundScraper::cSystem_qMp0Jcfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pcL4twC7_sendMessage);
}

void Heavy_SoundScraper::cDelay_gHAF8bsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gHAF8bsU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XNUmkQMJ, 0, m, &cDelay_XNUmkQMJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gHAF8bsU, 0, m, &cDelay_gHAF8bsU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hMzDiWdn, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_XNUmkQMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XNUmkQMJ, m);
  cMsg_YXE2wPbn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_5r4NtfSV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_xbRoTb8I_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_ORjBukmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_deAHxs8e_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_rWE9zngZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mXB6vWpf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gHAF8bsU, 2, m, &cDelay_gHAF8bsU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WmSQ2QzR_sendMessage);
}

void Heavy_SoundScraper::cMsg_deAHxs8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rWE9zngZ, 0, m, &hTable_rWE9zngZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_pcL4twC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_ORjBukmS_sendMessage);
}

void Heavy_SoundScraper::cMsg_YXE2wPbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rWE9zngZ, 0, m, &hTable_rWE9zngZ_sendMessage);
}

void Heavy_SoundScraper::cCast_WmSQ2QzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gHAF8bsU, 0, m, &cDelay_gHAF8bsU_sendMessage);
}

void Heavy_SoundScraper::cMsg_mXB6vWpf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XNUmkQMJ, 2, m, &cDelay_XNUmkQMJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_xbRoTb8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hMzDiWdn, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_qxjHhATg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3oLW5EAj, HV_BINOP_SUBTRACT, 0, m, &cBinop_3oLW5EAj_sendMessage);
}

void Heavy_SoundScraper::cMsg_Y7VE1YvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FwR1Vn7O_sendMessage);
}

void Heavy_SoundScraper::cSystem_FwR1Vn7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bGj0sViM_sendMessage);
}

void Heavy_SoundScraper::cVar_hiEceA0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HiaBLnTO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_cMgMCzg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cMgMCzg7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kYqLm6bp, 0, m, &cDelay_kYqLm6bp_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0IZ8nORU, 0, m, &sTabread_0IZ8nORU_sendMessage);
}

void Heavy_SoundScraper::cDelay_kYqLm6bp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kYqLm6bp, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0IZ8nORU, 0, m, &sTabread_0IZ8nORU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kYqLm6bp, 0, m, &cDelay_kYqLm6bp_sendMessage);
}

void Heavy_SoundScraper::sTabread_0IZ8nORU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_asJnBBVV, HV_BINOP_SUBTRACT, 0, m, &cBinop_asJnBBVV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_6vAF2TJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Ea0sk8w, HV_BINOP_MAX, 0, m, &cBinop_3Ea0sk8w_sendMessage);
}

void Heavy_SoundScraper::cBinop_bGj0sViM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vAF2TJz, HV_BINOP_MULTIPLY, 0, m, &cBinop_6vAF2TJz_sendMessage);
}

void Heavy_SoundScraper::cBinop_3oLW5EAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_54xk1bmq_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0IZ8nORU, 0, m, &sTabread_0IZ8nORU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gbHJA7y5_sendMessage);
}

void Heavy_SoundScraper::cSystem_kUUXQn19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_asJnBBVV, HV_BINOP_SUBTRACT, 1, m, &cBinop_asJnBBVV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kYqLm6bp, 2, m, &cDelay_kYqLm6bp_sendMessage);
}

void Heavy_SoundScraper::cMsg_HiaBLnTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kUUXQn19_sendMessage);
}

void Heavy_SoundScraper::cMsg_54xk1bmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cMgMCzg7, 0, m, &cDelay_cMgMCzg7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kYqLm6bp, 0, m, &cDelay_kYqLm6bp_sendMessage);
}

void Heavy_SoundScraper::cMsg_uHzoidow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Ea0sk8w, HV_BINOP_MAX, 1, m, &cBinop_3Ea0sk8w_sendMessage);
}

void Heavy_SoundScraper::cBinop_3Ea0sk8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3oLW5EAj, HV_BINOP_SUBTRACT, 1, m, &cBinop_3oLW5EAj_sendMessage);
}

void Heavy_SoundScraper::cCast_gbHJA7y5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cMgMCzg7, 0, m, &cDelay_cMgMCzg7_sendMessage);
}

void Heavy_SoundScraper::cBinop_3vnsKXZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cMgMCzg7, 2, m, &cDelay_cMgMCzg7_sendMessage);
}

void Heavy_SoundScraper::cBinop_asJnBBVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3vnsKXZG_sendMessage);
}

void Heavy_SoundScraper::cCast_LppxsgWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hiEceA0Z, 0, m, &cVar_hiEceA0Z_sendMessage);
  cMsg_Y7VE1YvP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qxjHhATg, 0, m, &cTabhead_qxjHhATg_sendMessage);
}

void Heavy_SoundScraper::cMsg_9vhBhgTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yomeC9ku_sendMessage);
}

void Heavy_SoundScraper::cSystem_yomeC9ku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YmtZaxvc_sendMessage);
}

void Heavy_SoundScraper::cDelay_2IvXBfig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2IvXBfig, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qU036ze2, 0, m, &cDelay_qU036ze2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2IvXBfig, 0, m, &cDelay_2IvXBfig_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HuOBa9aL, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_qU036ze2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qU036ze2, m);
  cMsg_7OYpARR1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_qHUaYj9U_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_B2Z3e5it_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_DVKfApyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p2ChYDN7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_bmegWqSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3OwYks8W_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2IvXBfig, 2, m, &cDelay_2IvXBfig_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m4IiyiCK_sendMessage);
}

void Heavy_SoundScraper::cMsg_p2ChYDN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_bmegWqSo, 0, m, &hTable_bmegWqSo_sendMessage);
}

void Heavy_SoundScraper::cBinop_YmtZaxvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_DVKfApyn_sendMessage);
}

void Heavy_SoundScraper::cMsg_7OYpARR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_bmegWqSo, 0, m, &hTable_bmegWqSo_sendMessage);
}

void Heavy_SoundScraper::cCast_m4IiyiCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2IvXBfig, 0, m, &cDelay_2IvXBfig_sendMessage);
}

void Heavy_SoundScraper::cMsg_3OwYks8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_qU036ze2, 2, m, &cDelay_qU036ze2_sendMessage);
}

void Heavy_SoundScraper::cMsg_B2Z3e5it_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HuOBa9aL, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_pGHuwTZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K3XIB8AC, 0, m, &cVar_K3XIB8AC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mw7R4dMK, 0, m, &cVar_mw7R4dMK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0mLgCZJk, 0, m, &cVar_0mLgCZJk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aTuR5bEy, 0, m, &cVar_aTuR5bEy_sendMessage);
}

void Heavy_SoundScraper::cVar_gN2kQ6ob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_kaOVObSS_sendMessage);
}

void Heavy_SoundScraper::cPack_R23eCpiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ZD8R3tt7, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_mw7R4dMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jr1N0F7Z, HV_BINOP_MULTIPLY, 0, m, &cBinop_jr1N0F7Z_sendMessage);
}

void Heavy_SoundScraper::cMsg_jQU1h1jE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rExSrzNG_sendMessage);
}

void Heavy_SoundScraper::cSystem_rExSrzNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_woPbnOPS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_jr1N0F7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7EyLrQvE_sendMessage);
}

void Heavy_SoundScraper::cBinop_bTdQ6YDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jr1N0F7Z, HV_BINOP_MULTIPLY, 1, m, &cBinop_jr1N0F7Z_sendMessage);
}

void Heavy_SoundScraper::cMsg_woPbnOPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_bTdQ6YDc_sendMessage);
}

void Heavy_SoundScraper::cBinop_7EyLrQvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZeMl6DEg_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZeMl6DEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wRKDXeCr_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3OqHSE28, m);
}

void Heavy_SoundScraper::cBinop_wRKDXeCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_D2WCxO88, m);
}

void Heavy_SoundScraper::cVar_0mLgCZJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qiN3syTL, HV_BINOP_MULTIPLY, 0, m, &cBinop_qiN3syTL_sendMessage);
}

void Heavy_SoundScraper::cMsg_cgDTZ2jN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_d336W6Q3_sendMessage);
}

void Heavy_SoundScraper::cSystem_d336W6Q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uRpj2iyH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_qiN3syTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_TL1k051R_sendMessage);
}

void Heavy_SoundScraper::cBinop_DAijqOVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qiN3syTL, HV_BINOP_MULTIPLY, 1, m, &cBinop_qiN3syTL_sendMessage);
}

void Heavy_SoundScraper::cMsg_uRpj2iyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DAijqOVY_sendMessage);
}

void Heavy_SoundScraper::cBinop_TL1k051R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_vp9cbiF7_sendMessage);
}

void Heavy_SoundScraper::cBinop_vp9cbiF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_F0vGjczG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ruIKdTMI, m);
}

void Heavy_SoundScraper::cBinop_F0vGjczG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LDbuDX4h, m);
}

void Heavy_SoundScraper::cVar_aTuR5bEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZHU1mV9G, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZHU1mV9G_sendMessage);
}

void Heavy_SoundScraper::cMsg_AvDUY6oh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fa2ZP0vZ_sendMessage);
}

void Heavy_SoundScraper::cSystem_fa2ZP0vZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CIa9Giwl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ZHU1mV9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6UtCyHbO_sendMessage);
}

void Heavy_SoundScraper::cBinop_Qf2VjSxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZHU1mV9G, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZHU1mV9G_sendMessage);
}

void Heavy_SoundScraper::cMsg_CIa9Giwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Qf2VjSxb_sendMessage);
}

void Heavy_SoundScraper::cBinop_6UtCyHbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_59JqVbzO_sendMessage);
}

void Heavy_SoundScraper::cBinop_59JqVbzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_I17SLSaf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lvFQNp7z, m);
}

void Heavy_SoundScraper::cBinop_I17SLSaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DPsj2MhN, m);
}

void Heavy_SoundScraper::cBinop_YYC3mTYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_O1nLvPsc, 0, m, &cPack_O1nLvPsc_sendMessage);
}

void Heavy_SoundScraper::cMsg_KvwrLvFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_pGHuwTZr, 0, m, &cVar_pGHuwTZr_sendMessage);
}

void Heavy_SoundScraper::cBinop_kaOVObSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R23eCpiE, 0, m, &cPack_R23eCpiE_sendMessage);
}

void Heavy_SoundScraper::cBinop_Zpm7Dfkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5Q1id9Vr, 0, m, &cPack_5Q1id9Vr_sendMessage);
}

void Heavy_SoundScraper::cMsg_75ogWp0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OZy9YucO_sendMessage);
}

void Heavy_SoundScraper::cSystem_OZy9YucO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yHP3JnFY_sendMessage);
}

void Heavy_SoundScraper::cVar_iP0oz6Bp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BmjCboRp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_GvXq7IeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Ix7taxYq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_w7z1IsXG, m);
}

void Heavy_SoundScraper::cBinop_yHP3JnFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_oxI8WbKp, m);
}

void Heavy_SoundScraper::cMsg_BmjCboRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GvXq7IeU_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ix7taxYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_y3iBRhGC, m);
}

void Heavy_SoundScraper::cVar_dfnvLIfx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fcti31QZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_fcti31QZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_i2bN2laE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_z7Y06HIx_sendMessage);
}

void Heavy_SoundScraper::cSystem_z7Y06HIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RApYjGo8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_fcti31QZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_D4dSiPWD_sendMessage);
}

void Heavy_SoundScraper::cBinop_xByRjbYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fcti31QZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_fcti31QZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_RApYjGo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xByRjbYz_sendMessage);
}

void Heavy_SoundScraper::cBinop_D4dSiPWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yCY136Le_sendMessage);
}

void Heavy_SoundScraper::cBinop_yCY136Le_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_UkDa2y1L_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tHZuoQoY, m);
}

void Heavy_SoundScraper::cBinop_UkDa2y1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JfD2jMx3, m);
}

void Heavy_SoundScraper::cBinop_s6U4w1vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_O5z9Z7Qq_sendMessage);
}

void Heavy_SoundScraper::cBinop_O5z9Z7Qq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CpksG3Zx, m);
}

void Heavy_SoundScraper::cBinop_D4KBxktq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rTo5Qb80_sendMessage);
}

void Heavy_SoundScraper::cBinop_rTo5Qb80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_AjESnUI2_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nn3ZzSvr_sendMessage);
}

void Heavy_SoundScraper::cVar_lYayMnfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_5NyrX6Ai_sendMessage);
}

void Heavy_SoundScraper::cMsg_hEzx02Y3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ViCGxvCg_sendMessage);
}

void Heavy_SoundScraper::cSystem_ViCGxvCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fm4UK0v2, HV_BINOP_DIVIDE, 1, m, &cBinop_fm4UK0v2_sendMessage);
}

void Heavy_SoundScraper::cBinop_AjESnUI2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_F64nE7kH_sendMessage);
}

void Heavy_SoundScraper::cBinop_F64nE7kH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fJE5MDGA, m);
}

void Heavy_SoundScraper::cMsg_P1CsOIc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Fe0TQZV8_sendMessage);
}

void Heavy_SoundScraper::cBinop_Fe0TQZV8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_D4KBxktq_sendMessage);
}

void Heavy_SoundScraper::cBinop_nn3ZzSvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pm1EeHbj, m);
}

void Heavy_SoundScraper::cBinop_5NyrX6Ai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_UQ8LbzgL_sendMessage);
}

void Heavy_SoundScraper::cBinop_UQ8LbzgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fm4UK0v2, HV_BINOP_DIVIDE, 0, m, &cBinop_fm4UK0v2_sendMessage);
}

void Heavy_SoundScraper::cBinop_fm4UK0v2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P1CsOIc3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_zqhT0mdi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QdhHju67_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_bvr5zjb0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1bEBIIXw_sendMessage);
}

void Heavy_SoundScraper::cSystem_1bEBIIXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qjWveVYh_sendMessage);
}

void Heavy_SoundScraper::cDelay_AwiReYX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AwiReYX3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XTZY2Mn9, 0, m, &cDelay_XTZY2Mn9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AwiReYX3, 0, m, &cDelay_AwiReYX3_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tnwfmDNO, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_XTZY2Mn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XTZY2Mn9, m);
  cMsg_jl6kKFGs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_kX3kCrCO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Fi1eJ599_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_3AwQ4teo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2SO1jpZv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_vbDgCxW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SFp2Nina_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AwiReYX3, 2, m, &cDelay_AwiReYX3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dYjZWdI8_sendMessage);
}

void Heavy_SoundScraper::cMsg_2SO1jpZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vbDgCxW0, 0, m, &hTable_vbDgCxW0_sendMessage);
}

void Heavy_SoundScraper::cBinop_qjWveVYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_3AwQ4teo_sendMessage);
}

void Heavy_SoundScraper::cMsg_jl6kKFGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vbDgCxW0, 0, m, &hTable_vbDgCxW0_sendMessage);
}

void Heavy_SoundScraper::cCast_dYjZWdI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AwiReYX3, 0, m, &cDelay_AwiReYX3_sendMessage);
}

void Heavy_SoundScraper::cMsg_SFp2Nina_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XTZY2Mn9, 2, m, &cDelay_XTZY2Mn9_sendMessage);
}

void Heavy_SoundScraper::cMsg_Fi1eJ599_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tnwfmDNO, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_ajd3G86K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_QdhHju67_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_QdhHju67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wk7ewaKj, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_i8nrhttR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_F8AciC1G, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_RsHiST2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_i8nrhttR, 0, m, &cPack_i8nrhttR_sendMessage);
}

void Heavy_SoundScraper::cCast_wpyH6AmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_s8elvp5Z_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_gFCytAjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_F8AciC1G, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_1DBhwmy4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_j9AJL8rr, m);
}

void Heavy_SoundScraper::cMsg_2F7LPkwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_s6U4w1vn_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_h0cOJIbe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qjPLyANN, 0, m, &cSlice_qjPLyANN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_oKCi4klI, 0, m, &cRandom_oKCi4klI_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_9Eja24I7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_X9srQArp_sendMessage);
}

void Heavy_SoundScraper::cUnop_X9srQArp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_CB8Bn3D4_sendMessage);
}

void Heavy_SoundScraper::cRandom_oKCi4klI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_9Eja24I7_sendMessage);
}

void Heavy_SoundScraper::cSlice_qjPLyANN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_oKCi4klI, 1, m, &cRandom_oKCi4klI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_bA3jeVcX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h329csiO, HV_BINOP_DIVIDE, 0, m, &cBinop_h329csiO_sendMessage);
}

void Heavy_SoundScraper::cBinop_UKnODyTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_LWmXwwNP_sendMessage);
}

void Heavy_SoundScraper::cBinop_LWmXwwNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vxeDosYv, HV_BINOP_POW, 1, m, &cBinop_vxeDosYv_sendMessage);
  cMsg_Hwg3SUIn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_vxeDosYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_bA3jeVcX_sendMessage);
}

void Heavy_SoundScraper::cMsg_Hwg3SUIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vxeDosYv, HV_BINOP_POW, 0, m, &cBinop_vxeDosYv_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_7lj2jciH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_inqc4rGW, 0, m, &cSlice_inqc4rGW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_88fNTrLE, 0, m, &cRandom_88fNTrLE_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_273lSvCk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GkytMdkE_sendMessage);
}

void Heavy_SoundScraper::cUnop_GkytMdkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GYChsioZ_sendMessage);
}

void Heavy_SoundScraper::cRandom_88fNTrLE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_273lSvCk_sendMessage);
}

void Heavy_SoundScraper::cSlice_inqc4rGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_88fNTrLE, 1, m, &cRandom_88fNTrLE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_pvmdHmBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_OXn7gtF0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_smuPsA0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_VQtC3MXJ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_5Mx7QXEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lofNDizK, 0, m, &cPack_lofNDizK_sendMessage);
}

void Heavy_SoundScraper::cUnop_BpoEnhsm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HnogbGix, 0, m, &cPack_HnogbGix_sendMessage);
}

void Heavy_SoundScraper::cPack_HnogbGix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_f52ztb7P, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_lofNDizK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HtLLvVBA, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_YM7vOxDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_5Mx7QXEf_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_BpoEnhsm_sendMessage);
}

void Heavy_SoundScraper::cMsg_LyCTxcSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_YM7vOxDp_sendMessage);
}

void Heavy_SoundScraper::cCast_W7nr451h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_w6BsjLj9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DIOcOJoN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QFaw5WOV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XQXqNuw3_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_GxPYWX2a_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_EdeG4mvK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_EdeG4mvK_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_OQSpZkfB, 1, m, &cDelay_OQSpZkfB_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FFipT48s_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_OQSpZkfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OQSpZkfB, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HxvIWPAn, 0, m, &cVar_HxvIWPAn_sendMessage);
}

void Heavy_SoundScraper::cMsg_EdeG4mvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_OQSpZkfB, 0, m, &cDelay_OQSpZkfB_sendMessage);
}

void Heavy_SoundScraper::cCast_FFipT48s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OQSpZkfB, 0, m, &cDelay_OQSpZkfB_sendMessage);
}

void Heavy_SoundScraper::cVar_HxvIWPAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l3BVQSSJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_GZ0Vux5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_w6BsjLj9, 0, m, &cVar_w6BsjLj9_sendMessage);
}

void Heavy_SoundScraper::cSend_lfQbgKFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_uX1xYixJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3wfboKgf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Q0ApGg4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_lfQbgKFv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_OEVjTKqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_uX1xYixJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_jkd7mwnM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9u2Q2WoU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_DmWp4NYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_jkd7mwnM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_egh9POsS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_YVBzKLSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3wfboKgf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_U55ybgJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9u2Q2WoU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_qPqzIf03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_EQgeWPIP, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_l3BVQSSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_EQgeWPIP, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_XQXqNuw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GxPYWX2a_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_QFaw5WOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HxvIWPAn, 1, m, &cVar_HxvIWPAn_sendMessage);
}

void Heavy_SoundScraper::cCast_DIOcOJoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qPqzIf03_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_06bjOylm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VLLhSsxY, 0, m, &cSlice_VLLhSsxY_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_0wY2A44e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cQgZLIfG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_H7qakpnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_UjLoQEQA_sendMessage);
}

void Heavy_SoundScraper::cBinop_UjLoQEQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_flsPbRxt, m);
}

void Heavy_SoundScraper::cMsg_cQgZLIfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H7qakpnR_sendMessage);
}

void Heavy_SoundScraper::cSlice_VLLhSsxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_5XEyxLUF, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_fwyz1fM4, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_0wY2A44e, 0, m, &cVar_0wY2A44e_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_SUHIrc79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_u9EIWQp1, 0, m, &cPack_u9EIWQp1_sendMessage);
}

void Heavy_SoundScraper::cVar_mCq2PK4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_IXZQA2xc_sendMessage);
}

void Heavy_SoundScraper::cIf_kJPyjbdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_VSxrUtMM_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_mCq2PK4m, 1, m, &cVar_mCq2PK4m_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_1qPlMxob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kJPyjbdS, 1, m, &cIf_kJPyjbdS_sendMessage);
}

void Heavy_SoundScraper::cVar_KVEjC6gS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_AdiOsB4u_sendMessage);
}

void Heavy_SoundScraper::cUnop_VSxrUtMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KVEjC6gS, 1, m, &cVar_KVEjC6gS_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_0R7VtR2Z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DVQuOPjs_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_al0AJU6s_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_DVQuOPjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mCq2PK4m, 0, m, &cVar_mCq2PK4m_sendMessage);
}

void Heavy_SoundScraper::cCast_al0AJU6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KVEjC6gS, 0, m, &cVar_KVEjC6gS_sendMessage);
}

void Heavy_SoundScraper::cVar_gMapRCOF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_HmR3jKvY_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_1y5PZwkm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_C3cR9fxa_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_C3cR9fxa_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_CAY5z2w0, 1, m, &cDelay_CAY5z2w0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lMGSChOT_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_CAY5z2w0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CAY5z2w0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cczx10fb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7qKz0NyC_sendMessage);
}

void Heavy_SoundScraper::cMsg_C3cR9fxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CAY5z2w0, 0, m, &cDelay_CAY5z2w0_sendMessage);
}

void Heavy_SoundScraper::cCast_lMGSChOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CAY5z2w0, 0, m, &cDelay_CAY5z2w0_sendMessage);
}

void Heavy_SoundScraper::cPack_vcbIbpkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_R8lE2LJY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_4VBw9LeJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kde6vjIJ_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2maS7GZu, HV_BINOP_SUBTRACT, 0, m, &cBinop_2maS7GZu_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Kde6vjIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RhdKEYx3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_RE0JUiCi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_zS44mhiT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_zS44mhiT_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_pc7JRg3W, 1, m, &cDelay_pc7JRg3W_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BpEQnY4O_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_pc7JRg3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pc7JRg3W, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lBBCbQBz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P4hh9nQ9_sendMessage);
}

void Heavy_SoundScraper::cMsg_zS44mhiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pc7JRg3W, 0, m, &cDelay_pc7JRg3W_sendMessage);
}

void Heavy_SoundScraper::cCast_BpEQnY4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pc7JRg3W, 0, m, &cDelay_pc7JRg3W_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_A2rBJ6EY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_69YRgEdZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_69YRgEdZ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_vFYZHQ0s, 1, m, &cDelay_vFYZHQ0s_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KNsrUy0U_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_vFYZHQ0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vFYZHQ0s, m);
}

void Heavy_SoundScraper::cMsg_69YRgEdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_vFYZHQ0s, 0, m, &cDelay_vFYZHQ0s_sendMessage);
}

void Heavy_SoundScraper::cCast_KNsrUy0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vFYZHQ0s, 0, m, &cDelay_vFYZHQ0s_sendMessage);
}

void Heavy_SoundScraper::cPack_qBdj0tIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RXEtKWwT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_0UigZHUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_paU8R2VW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_8t46lUwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3uoZEflC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_AVOT1xr3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JiYo7jGp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_OP1LMVvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vsQGDTmw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_uw5D8EFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1EzEYA9d, HV_BINOP_DIVIDE, 1, m, &cBinop_1EzEYA9d_sendMessage);
}

void Heavy_SoundScraper::cVar_iOoQ1WXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1EzEYA9d, HV_BINOP_DIVIDE, 0, m, &cBinop_1EzEYA9d_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_PDooMdLW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_baxRzURc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CrRpqJHW_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lfoNhC0H_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3Omqny92_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_CrRpqJHW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iOoQ1WXW, 0, m, &cVar_iOoQ1WXW_sendMessage);
}

void Heavy_SoundScraper::cCast_baxRzURc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uw5D8EFu, 0, m, &cVar_uw5D8EFu_sendMessage);
}

void Heavy_SoundScraper::cCast_lfoNhC0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uw5D8EFu, 0, m, &cVar_uw5D8EFu_sendMessage);
}

void Heavy_SoundScraper::cCast_3Omqny92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iOoQ1WXW, 0, m, &cVar_iOoQ1WXW_sendMessage);
}

void Heavy_SoundScraper::cPack_u9EIWQp1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VKfEhleB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_63aEC5AQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_vcbIbpkX, 1, m, &cPack_vcbIbpkX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_fDSIzqye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hvYfRcPW, HV_BINOP_ADD, 0, m, &cBinop_hvYfRcPW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_kZOJUuDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_qBdj0tIq, 1, m, &cPack_qBdj0tIq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_j0H2wCF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NuDloqz1, HV_BINOP_ADD, 0, m, &cBinop_NuDloqz1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_7qKz0NyC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SUHIrc79, 0, m, &cVar_SUHIrc79_sendMessage);
}

void Heavy_SoundScraper::cCast_Cczx10fb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gMapRCOF, 0, m, &cVar_gMapRCOF_sendMessage);
}

void Heavy_SoundScraper::cSend_R8lE2LJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jFb8uooI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_VKfEhleB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pvFnIqYn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_JiYo7jGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pvFnIqYn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_8RzFf40W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AVOT1xr3, 0, m, &cPack_AVOT1xr3_sendMessage);
}

void Heavy_SoundScraper::cCast_xqShDmfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1y5PZwkm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_IXZQA2xc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8t46lUwo, 0, m, &cPack_8t46lUwo_sendMessage);
}

void Heavy_SoundScraper::cSend_RXEtKWwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jFb8uooI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_AdiOsB4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0UigZHUC, 0, m, &cPack_0UigZHUC_sendMessage);
}

void Heavy_SoundScraper::cBinop_HmR3jKvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0R7VtR2Z_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_hvYfRcPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vcbIbpkX, 0, m, &cPack_vcbIbpkX_sendMessage);
}

void Heavy_SoundScraper::cBinop_2maS7GZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RE0JUiCi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_NuDloqz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qBdj0tIq, 0, m, &cPack_qBdj0tIq_sendMessage);
}

void Heavy_SoundScraper::cMsg_RhdKEYx3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_RE0JUiCi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_7Iizq8sj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IM1LdDB6, HV_BINOP_MULTIPLY, 1, m, &cBinop_IM1LdDB6_sendMessage);
}

void Heavy_SoundScraper::cMsg_paU8R2VW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kZOJUuDQ, 0, m, &cSlice_kZOJUuDQ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_j0H2wCF5, 0, m, &cSlice_j0H2wCF5_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kZOJUuDQ, 0, m, &cSlice_kZOJUuDQ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_j0H2wCF5, 0, m, &cSlice_j0H2wCF5_sendMessage);
}

void Heavy_SoundScraper::cBinop_Nk1J8C1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0UigZHUC, 1, m, &cPack_0UigZHUC_sendMessage);
}

void Heavy_SoundScraper::cBinop_PpNxvSHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8t46lUwo, 1, m, &cPack_8t46lUwo_sendMessage);
}

void Heavy_SoundScraper::cMsg_3uoZEflC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_63aEC5AQ, 0, m, &cSlice_63aEC5AQ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_fDSIzqye, 0, m, &cSlice_fDSIzqye_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_63aEC5AQ, 0, m, &cSlice_63aEC5AQ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_fDSIzqye, 0, m, &cSlice_fDSIzqye_sendMessage);
}

void Heavy_SoundScraper::cSend_vsQGDTmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pvFnIqYn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1EzEYA9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_1qPlMxob_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_kJPyjbdS, 0, m, &cIf_kJPyjbdS_sendMessage);
}

void Heavy_SoundScraper::cCast_520XZmHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AVOT1xr3, 1, m, &cPack_AVOT1xr3_sendMessage);
}

void Heavy_SoundScraper::cCast_cmXaLuWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CAY5z2w0, 1, m, &cDelay_CAY5z2w0_sendMessage);
}

void Heavy_SoundScraper::cCast_UlNqEjh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hvYfRcPW, HV_BINOP_ADD, 1, m, &cBinop_hvYfRcPW_sendMessage);
}

void Heavy_SoundScraper::cCast_fMbc7n0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NuDloqz1, HV_BINOP_ADD, 1, m, &cBinop_NuDloqz1_sendMessage);
}

void Heavy_SoundScraper::cCast_dzYW7SJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2maS7GZu, HV_BINOP_SUBTRACT, 1, m, &cBinop_2maS7GZu_sendMessage);
}

void Heavy_SoundScraper::cCast_KqLkayvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vFYZHQ0s, 1, m, &cDelay_vFYZHQ0s_sendMessage);
}

void Heavy_SoundScraper::cCast_lBBCbQBz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_A2rBJ6EY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_P4hh9nQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_OP1LMVvU, 0, m, &cPack_OP1LMVvU_sendMessage);
}

void Heavy_SoundScraper::cCast_rws0a6nl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RE0JUiCi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_K5pElOWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_A2rBJ6EY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_IM1LdDB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fMbc7n0m_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UlNqEjh8_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_uMSuRuoq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zdda5kbX_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_SUHIrc79, 1, m, &cVar_SUHIrc79_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_zdda5kbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ylYGA4PD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_d4VrZb3b_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tsB10FPl_sendMessage);
      break;
    }
    default: {
      cSwitchcase_PDooMdLW_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_gMapRCOF, 1, m, &cVar_gMapRCOF_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_tsB10FPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dq8spxqZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_ZUPNcyvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_mx6vvLZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_4VBw9LeJ_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_259eC9P0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IM1LdDB6, HV_BINOP_MULTIPLY, 0, m, &cBinop_IM1LdDB6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_n1sWIZ4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_d4VrZb3b_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_3EdMFpQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_CcXTQqxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_uMSuRuoq_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_ylYGA4PD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_SUHIrc79, 1, m, &cVar_SUHIrc79_sendMessage);
}

void Heavy_SoundScraper::cCast_mFFSsN3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zDcNkFVV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Dq8spxqZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_PDooMdLW_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_gMapRCOF, 1, m, &cVar_gMapRCOF_sendMessage);
}

void Heavy_SoundScraper::cMsg_zDcNkFVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ZUPNcyvo, 0, m, &cSlice_ZUPNcyvo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mx6vvLZY, 0, m, &cSlice_mx6vvLZY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_259eC9P0, 0, m, &cSlice_259eC9P0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_n1sWIZ4r, 0, m, &cSlice_n1sWIZ4r_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_3EdMFpQh, 0, m, &cSlice_3EdMFpQh_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_CcXTQqxY, 0, m, &cSlice_CcXTQqxY_sendMessage);
}

void Heavy_SoundScraper::cSlice_xfQvE7YN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tzaAq0oZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_7NN34YMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mM9CZBkH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_mM9CZBkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IHphEDBQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_IHphEDBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jl6EDOZu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_tzaAq0oZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_LrXfsnYY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_LrXfsnYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_puIdtWvG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_ki1RNn6v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_04p3LUQ2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_j7SEZUjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7PI8cSGj, HV_BINOP_MULTIPLY, 1, m, &cBinop_7PI8cSGj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mdBvfqoo, HV_BINOP_MULTIPLY, 1, m, &cBinop_mdBvfqoo_sendMessage);
}

void Heavy_SoundScraper::cSlice_KSfWutt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_7PI8cSGj, HV_BINOP_MULTIPLY, 0, m, &cBinop_7PI8cSGj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_H1CE7nja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mdBvfqoo, HV_BINOP_MULTIPLY, 0, m, &cBinop_mdBvfqoo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_04p3LUQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_Gp7mluQz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Gp7mluQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 220500000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cMsg_ZKpeYNgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_KSfWutt3, 0, m, &cSlice_KSfWutt3_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_H1CE7nja, 0, m, &cSlice_H1CE7nja_sendMessage);
}

void Heavy_SoundScraper::cBinop_7PI8cSGj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ki1RNn6v, 1, m, &cPack_ki1RNn6v_sendMessage);
}

void Heavy_SoundScraper::cBinop_mdBvfqoo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ki1RNn6v, 0, m, &cPack_ki1RNn6v_sendMessage);
}

void Heavy_SoundScraper::cSend_T5joV0UV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RMOmIDKX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_LoTkgSEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_06bjOylm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_z1rwnIze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_psXoMlxs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_lKuI6xBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aGSVWM0a_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_UKnODyTT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_0KP4RwC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f0nvypbF, 1, m, &cPack_f0nvypbF_sendMessage);
}

void Heavy_SoundScraper::cVar_qoPjf6Vl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f0nvypbF, 0, m, &cPack_f0nvypbF_sendMessage);
}

void Heavy_SoundScraper::cPack_f0nvypbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qTGd6CjC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gTXLuiQc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mFFSsN3h_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ZUPNcyvo, 0, m, &cSlice_ZUPNcyvo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mx6vvLZY, 0, m, &cSlice_mx6vvLZY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_259eC9P0, 0, m, &cSlice_259eC9P0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_n1sWIZ4r, 0, m, &cSlice_n1sWIZ4r_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_3EdMFpQh, 0, m, &cSlice_3EdMFpQh_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_CcXTQqxY, 0, m, &cSlice_CcXTQqxY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8RzFf40W_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xqShDmfW_sendMessage);
  cMsg_LoTkgSEv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_H3SG1pYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qoPjf6Vl, 0, m, &cVar_qoPjf6Vl_sendMessage);
}

void Heavy_SoundScraper::cCast_K0OeSN0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f0nvypbF, 2, m, &cPack_f0nvypbF_sendMessage);
}

void Heavy_SoundScraper::cCast_zsI32TQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0KP4RwC6, 0, m, &cVar_0KP4RwC6_sendMessage);
}

void Heavy_SoundScraper::cBinop_CB8Bn3D4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_8OehOeol_sendMessage);
}

void Heavy_SoundScraper::cBinop_8OehOeol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_YM7vOxDp_sendMessage);
}

void Heavy_SoundScraper::cBinop_psXoMlxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Kpul7nFf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_6fLTFqKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K0OeSN0F_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zsI32TQG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H3SG1pYr_sendMessage);
}

void Heavy_SoundScraper::cBinop_GYChsioZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_w6AIbznP_sendMessage);
}

void Heavy_SoundScraper::cBinop_w6AIbznP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6fLTFqKj, HV_BINOP_MULTIPLY, 1, m, &cBinop_6fLTFqKj_sendMessage);
}

void Heavy_SoundScraper::cCast_aGSVWM0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7lj2jciH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_gTXLuiQc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GZ0Vux5L_sendMessage);
}

void Heavy_SoundScraper::cCast_qTGd6CjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_h0cOJIbe_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W7nr451h_sendMessage);
}

void Heavy_SoundScraper::cSend_VQtC3MXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eo1PcGuu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_OXn7gtF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_D2UulC8D_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_h329csiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6fLTFqKj, HV_BINOP_MULTIPLY, 0, m, &cBinop_6fLTFqKj_sendMessage);
}

void Heavy_SoundScraper::cSend_Kpul7nFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Sf3UlUDJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6aDLlMsS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_T5joV0UV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_0L9FNkgL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iCsyDQk0, 0, m, &cSlice_iCsyDQk0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_C9I21fWP, 0, m, &cRandom_C9I21fWP_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_KFHIFyeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_TMD2CUlA_sendMessage);
}

void Heavy_SoundScraper::cUnop_TMD2CUlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_dvsW8oge_sendMessage);
}

void Heavy_SoundScraper::cRandom_C9I21fWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_KFHIFyeZ_sendMessage);
}

void Heavy_SoundScraper::cSlice_iCsyDQk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_C9I21fWP, 1, m, &cRandom_C9I21fWP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_E4mRpyUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iajd5keQ, HV_BINOP_DIVIDE, 0, m, &cBinop_iajd5keQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_n0QFC1pd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_4KvegDEH_sendMessage);
}

void Heavy_SoundScraper::cBinop_4KvegDEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Wm0R5ag, HV_BINOP_POW, 1, m, &cBinop_6Wm0R5ag_sendMessage);
  cMsg_rHsYt7ap_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_6Wm0R5ag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_E4mRpyUe_sendMessage);
}

void Heavy_SoundScraper::cMsg_rHsYt7ap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Wm0R5ag, HV_BINOP_POW, 0, m, &cBinop_6Wm0R5ag_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ejI1xTrX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SowuFVbv, 0, m, &cSlice_SowuFVbv_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qrnx9jID, 0, m, &cRandom_qrnx9jID_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_gUSMfdVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LVEAw93P_sendMessage);
}

void Heavy_SoundScraper::cUnop_LVEAw93P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mp2b3Ao7_sendMessage);
}

void Heavy_SoundScraper::cRandom_qrnx9jID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_gUSMfdVs_sendMessage);
}

void Heavy_SoundScraper::cSlice_SowuFVbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qrnx9jID, 1, m, &cRandom_qrnx9jID_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_A935J5Rc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_lTEJvtQ2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_DFZ2omn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_tR0nejNZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_j9Z6aWmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_eXSw1xZJ, 0, m, &cPack_eXSw1xZJ_sendMessage);
}

void Heavy_SoundScraper::cUnop_6rzg4xiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QV6fLvnQ, 0, m, &cPack_QV6fLvnQ_sendMessage);
}

void Heavy_SoundScraper::cPack_QV6fLvnQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_b6lztIzY, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_eXSw1xZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_82VLZeYw, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_UkziVc8m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_j9Z6aWmx_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_6rzg4xiA_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZvWRWlMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_UkziVc8m_sendMessage);
}

void Heavy_SoundScraper::cCast_bhZaVHpb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_sYUxIteA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HsYR2cfc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XS7oixEQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pOfSGWfh_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ztMpBUYi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_BeAHsEY3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_BeAHsEY3_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_k5LLuZTK, 1, m, &cDelay_k5LLuZTK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dYwoUXfD_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_k5LLuZTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_k5LLuZTK, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gW0DiIiN, 0, m, &cVar_gW0DiIiN_sendMessage);
}

void Heavy_SoundScraper::cMsg_BeAHsEY3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_k5LLuZTK, 0, m, &cDelay_k5LLuZTK_sendMessage);
}

void Heavy_SoundScraper::cCast_dYwoUXfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_k5LLuZTK, 0, m, &cDelay_k5LLuZTK_sendMessage);
}

void Heavy_SoundScraper::cVar_gW0DiIiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RwjWElcZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ftnumeOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sYUxIteA, 0, m, &cVar_sYUxIteA_sendMessage);
}

void Heavy_SoundScraper::cSend_y1bFeuh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_zxM7NdxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_smFubyv1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_udv19Yta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_y1bFeuh7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_eoXpKdxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_zxM7NdxK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_qDUgEFqZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hvGRZo4D_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_1XcmSlqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_qDUgEFqZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_r4ePNcT6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_GKbAc5LL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_smFubyv1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_b768iTNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hvGRZo4D_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_yQxAeEJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_kj4HFN8n, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_RwjWElcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_kj4HFN8n, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_HsYR2cfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yQxAeEJ8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_XS7oixEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gW0DiIiN, 1, m, &cVar_gW0DiIiN_sendMessage);
}

void Heavy_SoundScraper::cCast_pOfSGWfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ztMpBUYi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_yRXyAvXG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3BzYHIwr, 0, m, &cSlice_3BzYHIwr_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_fetpSVOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_skXYGwZv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Ogx0coo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_OXRJ4v0V_sendMessage);
}

void Heavy_SoundScraper::cBinop_OXRJ4v0V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nJvIRFux, m);
}

void Heavy_SoundScraper::cMsg_skXYGwZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ogx0coo3_sendMessage);
}

void Heavy_SoundScraper::cSlice_3BzYHIwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_Q8eCgjLK, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_RtoSlKmF, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_fetpSVOz, 0, m, &cVar_fetpSVOz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_51F8CCMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_anvmogl2, 0, m, &cPack_anvmogl2_sendMessage);
}

void Heavy_SoundScraper::cVar_N2cL1cyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_WhJq8enP_sendMessage);
}

void Heavy_SoundScraper::cIf_u3Y3WltG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_NOpoSp16_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_N2cL1cyc, 1, m, &cVar_N2cL1cyc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_uOu0L1qH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_u3Y3WltG, 1, m, &cIf_u3Y3WltG_sendMessage);
}

void Heavy_SoundScraper::cVar_m3zVLUQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_DaARrhEx_sendMessage);
}

void Heavy_SoundScraper::cUnop_NOpoSp16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m3zVLUQI, 1, m, &cVar_m3zVLUQI_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_DLXpA1Jj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dc8MSuiR_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3x3UVHvH_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Dc8MSuiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N2cL1cyc, 0, m, &cVar_N2cL1cyc_sendMessage);
}

void Heavy_SoundScraper::cCast_3x3UVHvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m3zVLUQI, 0, m, &cVar_m3zVLUQI_sendMessage);
}

void Heavy_SoundScraper::cVar_zf38RJxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_fYSnIlhi_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_oku0i7lF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_9gWV6hJN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_9gWV6hJN_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ypaDMQ1H, 1, m, &cDelay_ypaDMQ1H_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tE6xtjD4_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ypaDMQ1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ypaDMQ1H, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c9BDl7ZG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HwpdcD1d_sendMessage);
}

void Heavy_SoundScraper::cMsg_9gWV6hJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ypaDMQ1H, 0, m, &cDelay_ypaDMQ1H_sendMessage);
}

void Heavy_SoundScraper::cCast_tE6xtjD4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ypaDMQ1H, 0, m, &cDelay_ypaDMQ1H_sendMessage);
}

void Heavy_SoundScraper::cPack_HaX2qrjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_B47DsTTY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_yyYqNsKv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DzdER1s2_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_PJMRjxHC, HV_BINOP_SUBTRACT, 0, m, &cBinop_PJMRjxHC_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_DzdER1s2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vZwxUtpb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_OsHk8OFc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_FaXuFcHP_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_FaXuFcHP_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_4NhJyJT5, 1, m, &cDelay_4NhJyJT5_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EJs3hq83_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_4NhJyJT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4NhJyJT5, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P0s7ks50_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0F4ipEjI_sendMessage);
}

void Heavy_SoundScraper::cMsg_FaXuFcHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_4NhJyJT5, 0, m, &cDelay_4NhJyJT5_sendMessage);
}

void Heavy_SoundScraper::cCast_EJs3hq83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4NhJyJT5, 0, m, &cDelay_4NhJyJT5_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_mDq0fhuw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_dR5wOw4x_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_dR5wOw4x_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Ke83EeFw, 1, m, &cDelay_Ke83EeFw_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tMCNb73k_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_Ke83EeFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ke83EeFw, m);
}

void Heavy_SoundScraper::cMsg_dR5wOw4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ke83EeFw, 0, m, &cDelay_Ke83EeFw_sendMessage);
}

void Heavy_SoundScraper::cCast_tMCNb73k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ke83EeFw, 0, m, &cDelay_Ke83EeFw_sendMessage);
}

void Heavy_SoundScraper::cPack_pmsi2oOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6me83YCR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_HM6itJPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zsC8p9ni_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_JOg7byX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CNxL7WXB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_N5YNLr3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_iDsSVg0x_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_2vPS6pBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JlzhQpqK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_9vAscWTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hdYWlAaQ, HV_BINOP_DIVIDE, 1, m, &cBinop_hdYWlAaQ_sendMessage);
}

void Heavy_SoundScraper::cVar_mg5Jwkt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hdYWlAaQ, HV_BINOP_DIVIDE, 0, m, &cBinop_hdYWlAaQ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_JUKUmPFQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CzjtJfzd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F3xhmT51_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kARd4mYo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nBZVULVd_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_F3xhmT51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mg5Jwkt3, 0, m, &cVar_mg5Jwkt3_sendMessage);
}

void Heavy_SoundScraper::cCast_CzjtJfzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9vAscWTN, 0, m, &cVar_9vAscWTN_sendMessage);
}

void Heavy_SoundScraper::cCast_nBZVULVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mg5Jwkt3, 0, m, &cVar_mg5Jwkt3_sendMessage);
}

void Heavy_SoundScraper::cCast_kARd4mYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9vAscWTN, 0, m, &cVar_9vAscWTN_sendMessage);
}

void Heavy_SoundScraper::cPack_anvmogl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Hi1TRUoK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_I1jse7IU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_HaX2qrjp, 1, m, &cPack_HaX2qrjp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_vUl7fa6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_dRS76zmL, HV_BINOP_ADD, 0, m, &cBinop_dRS76zmL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_JWqffbOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_pmsi2oOu, 1, m, &cPack_pmsi2oOu_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_EJK3LFuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QgNR2RtR, HV_BINOP_ADD, 0, m, &cBinop_QgNR2RtR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_HwpdcD1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_51F8CCMp, 0, m, &cVar_51F8CCMp_sendMessage);
}

void Heavy_SoundScraper::cCast_c9BDl7ZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zf38RJxH, 0, m, &cVar_zf38RJxH_sendMessage);
}

void Heavy_SoundScraper::cSend_B47DsTTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KU8E2G8X_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Hi1TRUoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YoCPr1f9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_iDsSVg0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YoCPr1f9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_GSQTTq3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_N5YNLr3I, 0, m, &cPack_N5YNLr3I_sendMessage);
}

void Heavy_SoundScraper::cCast_Koe1ZzEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oku0i7lF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_WhJq8enP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JOg7byX1, 0, m, &cPack_JOg7byX1_sendMessage);
}

void Heavy_SoundScraper::cSend_6me83YCR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KU8E2G8X_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_DaARrhEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HM6itJPZ, 0, m, &cPack_HM6itJPZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_fYSnIlhi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DLXpA1Jj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_dRS76zmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HaX2qrjp, 0, m, &cPack_HaX2qrjp_sendMessage);
}

void Heavy_SoundScraper::cBinop_PJMRjxHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OsHk8OFc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_QgNR2RtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pmsi2oOu, 0, m, &cPack_pmsi2oOu_sendMessage);
}

void Heavy_SoundScraper::cMsg_vZwxUtpb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_OsHk8OFc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_28Pf50gP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lbLfWD8R, HV_BINOP_MULTIPLY, 1, m, &cBinop_lbLfWD8R_sendMessage);
}

void Heavy_SoundScraper::cMsg_zsC8p9ni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JWqffbOg, 0, m, &cSlice_JWqffbOg_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_EJK3LFuZ, 0, m, &cSlice_EJK3LFuZ_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JWqffbOg, 0, m, &cSlice_JWqffbOg_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_EJK3LFuZ, 0, m, &cSlice_EJK3LFuZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_YTqHVszK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HM6itJPZ, 1, m, &cPack_HM6itJPZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_RTjNKR0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JOg7byX1, 1, m, &cPack_JOg7byX1_sendMessage);
}

void Heavy_SoundScraper::cMsg_CNxL7WXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_I1jse7IU, 0, m, &cSlice_I1jse7IU_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vUl7fa6d, 0, m, &cSlice_vUl7fa6d_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_I1jse7IU, 0, m, &cSlice_I1jse7IU_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vUl7fa6d, 0, m, &cSlice_vUl7fa6d_sendMessage);
}

void Heavy_SoundScraper::cSend_JlzhQpqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YoCPr1f9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_hdYWlAaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_uOu0L1qH_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_u3Y3WltG, 0, m, &cIf_u3Y3WltG_sendMessage);
}

void Heavy_SoundScraper::cCast_MBqAmoAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_N5YNLr3I, 1, m, &cPack_N5YNLr3I_sendMessage);
}

void Heavy_SoundScraper::cCast_cbdPZlRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ypaDMQ1H, 1, m, &cDelay_ypaDMQ1H_sendMessage);
}

void Heavy_SoundScraper::cCast_UrjBwNou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QgNR2RtR, HV_BINOP_ADD, 1, m, &cBinop_QgNR2RtR_sendMessage);
}

void Heavy_SoundScraper::cCast_RjMdpWHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dRS76zmL, HV_BINOP_ADD, 1, m, &cBinop_dRS76zmL_sendMessage);
}

void Heavy_SoundScraper::cCast_KdjOWqlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ke83EeFw, 1, m, &cDelay_Ke83EeFw_sendMessage);
}

void Heavy_SoundScraper::cCast_RFTK4Nbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PJMRjxHC, HV_BINOP_SUBTRACT, 1, m, &cBinop_PJMRjxHC_sendMessage);
}

void Heavy_SoundScraper::cCast_0F4ipEjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2vPS6pBV, 0, m, &cPack_2vPS6pBV_sendMessage);
}

void Heavy_SoundScraper::cCast_P0s7ks50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mDq0fhuw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_RV51UVgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mDq0fhuw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_LwSnvQl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OsHk8OFc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_lbLfWD8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UrjBwNou_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RjMdpWHF_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_0ZrBHHa9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oXQbK3fE_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_51F8CCMp, 1, m, &cVar_51F8CCMp_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_oXQbK3fE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BI0tfjUf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_qSD6vMTE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gIFZKjpy_sendMessage);
      break;
    }
    default: {
      cSwitchcase_JUKUmPFQ_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_zf38RJxH, 1, m, &cVar_zf38RJxH_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_gIFZKjpy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OG0si4NX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_iNFdV1oj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_FSC4k5ZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_yyYqNsKv_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_EP5dU5rA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_lbLfWD8R, HV_BINOP_MULTIPLY, 0, m, &cBinop_lbLfWD8R_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_dJ7NFNP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_qSD6vMTE_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Sgu9Wr9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_8nB2xTv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_0ZrBHHa9_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_BI0tfjUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_51F8CCMp, 1, m, &cVar_51F8CCMp_sendMessage);
}

void Heavy_SoundScraper::cCast_oqR2fUcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LKmHcQOp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_OG0si4NX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_JUKUmPFQ_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_zf38RJxH, 1, m, &cVar_zf38RJxH_sendMessage);
}

void Heavy_SoundScraper::cMsg_LKmHcQOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_iNFdV1oj, 0, m, &cSlice_iNFdV1oj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FSC4k5ZY, 0, m, &cSlice_FSC4k5ZY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_EP5dU5rA, 0, m, &cSlice_EP5dU5rA_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dJ7NFNP5, 0, m, &cSlice_dJ7NFNP5_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Sgu9Wr9l, 0, m, &cSlice_Sgu9Wr9l_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_8nB2xTv7, 0, m, &cSlice_8nB2xTv7_sendMessage);
}

void Heavy_SoundScraper::cSlice_GHoKaGRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lrtwQXkX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ETZCKcdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Wz1mGfIN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Wz1mGfIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wEsGatnt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_wEsGatnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ENJVwLWz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_lrtwQXkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nH6Hu2Ci_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_nH6Hu2Ci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_s5Tb0AVP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_lZNb4zyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pdT0xnwg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_OKLfMCLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BXbPuDrT, HV_BINOP_MULTIPLY, 1, m, &cBinop_BXbPuDrT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YA3uyjgc, HV_BINOP_MULTIPLY, 1, m, &cBinop_YA3uyjgc_sendMessage);
}

void Heavy_SoundScraper::cSlice_YuWMInkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_BXbPuDrT, HV_BINOP_MULTIPLY, 0, m, &cBinop_BXbPuDrT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ONkzmAAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_YA3uyjgc, HV_BINOP_MULTIPLY, 0, m, &cBinop_YA3uyjgc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_pdT0xnwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_ZL9EUHaI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ZL9EUHaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 220500000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cMsg_sao1lBED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YuWMInkC, 0, m, &cSlice_YuWMInkC_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ONkzmAAJ, 0, m, &cSlice_ONkzmAAJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_BXbPuDrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lZNb4zyO, 1, m, &cPack_lZNb4zyO_sendMessage);
}

void Heavy_SoundScraper::cBinop_YA3uyjgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lZNb4zyO, 0, m, &cPack_lZNb4zyO_sendMessage);
}

void Heavy_SoundScraper::cSend_Fi980AHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IeJzihJX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_WhhcWpi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_yRXyAvXG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_u9Xqg0ml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_vi839rNM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ptaasdVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U82FLAjc_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_n0QFC1pd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_eNLHIUzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tydvqhFl, 1, m, &cPack_tydvqhFl_sendMessage);
}

void Heavy_SoundScraper::cVar_GZyHjxNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tydvqhFl, 0, m, &cPack_tydvqhFl_sendMessage);
}

void Heavy_SoundScraper::cPack_tydvqhFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tLcIPd5v_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uzWX9KCt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oqR2fUcm_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_iNFdV1oj, 0, m, &cSlice_iNFdV1oj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FSC4k5ZY, 0, m, &cSlice_FSC4k5ZY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_EP5dU5rA, 0, m, &cSlice_EP5dU5rA_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dJ7NFNP5, 0, m, &cSlice_dJ7NFNP5_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Sgu9Wr9l, 0, m, &cSlice_Sgu9Wr9l_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_8nB2xTv7, 0, m, &cSlice_8nB2xTv7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GSQTTq3h_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Koe1ZzEU_sendMessage);
  cMsg_WhhcWpi1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Ukq0OzDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tydvqhFl, 2, m, &cPack_tydvqhFl_sendMessage);
}

void Heavy_SoundScraper::cCast_hWLdSBOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eNLHIUzg, 0, m, &cVar_eNLHIUzg_sendMessage);
}

void Heavy_SoundScraper::cCast_QMMHjQxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GZyHjxNg, 0, m, &cVar_GZyHjxNg_sendMessage);
}

void Heavy_SoundScraper::cBinop_dvsW8oge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_JlUoTRoR_sendMessage);
}

void Heavy_SoundScraper::cBinop_JlUoTRoR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_UkziVc8m_sendMessage);
}

void Heavy_SoundScraper::cBinop_vi839rNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xJPxtwkR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1B7IsYbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ukq0OzDi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hWLdSBOu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QMMHjQxk_sendMessage);
}

void Heavy_SoundScraper::cBinop_mp2b3Ao7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_rshRBgSz_sendMessage);
}

void Heavy_SoundScraper::cBinop_rshRBgSz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1B7IsYbl, HV_BINOP_MULTIPLY, 1, m, &cBinop_1B7IsYbl_sendMessage);
}

void Heavy_SoundScraper::cCast_U82FLAjc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ejI1xTrX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_uzWX9KCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ftnumeOf_sendMessage);
}

void Heavy_SoundScraper::cCast_tLcIPd5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0L9FNkgL_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bhZaVHpb_sendMessage);
}

void Heavy_SoundScraper::cSend_tR0nejNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PtvZ02v0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_lTEJvtQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Toge1gW4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_iajd5keQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1B7IsYbl, HV_BINOP_MULTIPLY, 0, m, &cBinop_1B7IsYbl_sendMessage);
}

void Heavy_SoundScraper::cSend_xJPxtwkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_evSV9zzK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_yWBHVUKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_Fi980AHg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ZCmDJ8Ex_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LznwPt31, 0, m, &cSlice_LznwPt31_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_x7N0aC7f, 0, m, &cRandom_x7N0aC7f_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_E78u76RO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_5w13OZQM_sendMessage);
}

void Heavy_SoundScraper::cUnop_5w13OZQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_4D5fVyMu_sendMessage);
}

void Heavy_SoundScraper::cRandom_x7N0aC7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_E78u76RO_sendMessage);
}

void Heavy_SoundScraper::cSlice_LznwPt31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_x7N0aC7f, 1, m, &cRandom_x7N0aC7f_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_rkCxKREj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yaY5cQwn, HV_BINOP_DIVIDE, 0, m, &cBinop_yaY5cQwn_sendMessage);
}

void Heavy_SoundScraper::cBinop_b2XQjDlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_NU1wioKT_sendMessage);
}

void Heavy_SoundScraper::cBinop_NU1wioKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jOGiiawe, HV_BINOP_POW, 1, m, &cBinop_jOGiiawe_sendMessage);
  cMsg_hDh6vzjV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_jOGiiawe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_rkCxKREj_sendMessage);
}

void Heavy_SoundScraper::cMsg_hDh6vzjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jOGiiawe, HV_BINOP_POW, 0, m, &cBinop_jOGiiawe_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_GfctOgnO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LuuhJxwZ, 0, m, &cSlice_LuuhJxwZ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KiTMUJUU, 0, m, &cRandom_KiTMUJUU_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Qij7sBC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qZ3YVCRp_sendMessage);
}

void Heavy_SoundScraper::cUnop_qZ3YVCRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uEpJ0xmx_sendMessage);
}

void Heavy_SoundScraper::cRandom_KiTMUJUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_Qij7sBC2_sendMessage);
}

void Heavy_SoundScraper::cSlice_LuuhJxwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KiTMUJUU, 1, m, &cRandom_KiTMUJUU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_BgzNrejB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_CLRffXxb_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_QwMwSmiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_j1uts22i_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_FrCd1HF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_glIN05IF, 0, m, &cPack_glIN05IF_sendMessage);
}

void Heavy_SoundScraper::cUnop_zwAjlnDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_iy72yUJv, 0, m, &cPack_iy72yUJv_sendMessage);
}

void Heavy_SoundScraper::cPack_iy72yUJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_jQdRQLfi, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_glIN05IF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_JnO3n7dX, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_q3NOnipa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_FrCd1HF0_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_zwAjlnDl_sendMessage);
}

void Heavy_SoundScraper::cMsg_0aehdU4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_q3NOnipa_sendMessage);
}

void Heavy_SoundScraper::cCast_ZYmkl56m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_8g046wQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZsuP9HWR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ot30z1Bc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k2D287v9_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_hvIQ2pRd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_lJoAcwbB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_lJoAcwbB_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_DAi0Y0fg, 1, m, &cDelay_DAi0Y0fg_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZJWStvMc_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_DAi0Y0fg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DAi0Y0fg, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ugvTKVQq, 0, m, &cVar_ugvTKVQq_sendMessage);
}

void Heavy_SoundScraper::cMsg_lJoAcwbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DAi0Y0fg, 0, m, &cDelay_DAi0Y0fg_sendMessage);
}

void Heavy_SoundScraper::cCast_ZJWStvMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DAi0Y0fg, 0, m, &cDelay_DAi0Y0fg_sendMessage);
}

void Heavy_SoundScraper::cVar_ugvTKVQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sAQQ6qt6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_FdTIVmBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8g046wQ1, 0, m, &cVar_8g046wQ1_sendMessage);
}

void Heavy_SoundScraper::cSend_gtLYTdxR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_V7b0oJ6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cB2KfVBp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_8REVD2pG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_gtLYTdxR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_DkxA2uqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_V7b0oJ6e_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_EIapSj4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1OPcUT1Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_9Ps5o61y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_EIapSj4A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cYsIGyUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_Tmetfqpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cB2KfVBp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_4DeatsjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1OPcUT1Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_vFvKky84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_YE8VdnqH, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_sAQQ6qt6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_YE8VdnqH, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ot30z1Bc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ugvTKVQq, 1, m, &cVar_ugvTKVQq_sendMessage);
}

void Heavy_SoundScraper::cCast_k2D287v9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_hvIQ2pRd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ZsuP9HWR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vFvKky84_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_mKMKVUXb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_wEXN2JNZ, 0, m, &cSlice_wEXN2JNZ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_LUiodfWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SSMitcxE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Lb0aDExu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_EiPJNMkZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_EiPJNMkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aJR2wyXX, m);
}

void Heavy_SoundScraper::cMsg_SSMitcxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Lb0aDExu_sendMessage);
}

void Heavy_SoundScraper::cSlice_wEXN2JNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_Yuwr9mH4, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_ar4OAyRU, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_LUiodfWo, 0, m, &cVar_LUiodfWo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_AMQ8fYV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QmIC7Vfy, 0, m, &cPack_QmIC7Vfy_sendMessage);
}

void Heavy_SoundScraper::cVar_ZJ34sTpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_6LzfVdvi_sendMessage);
}

void Heavy_SoundScraper::cIf_tNfMBmWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_8s9WqU7w_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_ZJ34sTpS, 1, m, &cVar_ZJ34sTpS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_DmDhVBQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tNfMBmWk, 1, m, &cIf_tNfMBmWk_sendMessage);
}

void Heavy_SoundScraper::cVar_s9knBuP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_KHqJVEOJ_sendMessage);
}

void Heavy_SoundScraper::cUnop_8s9WqU7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s9knBuP0, 1, m, &cVar_s9knBuP0_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_QLY2AnBC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rx2O9NGJ_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c7MyXEPE_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Rx2O9NGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZJ34sTpS, 0, m, &cVar_ZJ34sTpS_sendMessage);
}

void Heavy_SoundScraper::cCast_c7MyXEPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s9knBuP0, 0, m, &cVar_s9knBuP0_sendMessage);
}

void Heavy_SoundScraper::cVar_1ZhHLgy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_1pyxrwza_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_FYsituht_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_YAJdvIqQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_YAJdvIqQ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_qhLn4TaM, 1, m, &cDelay_qhLn4TaM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OQqxBm2s_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_qhLn4TaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qhLn4TaM, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GdeD0ZOR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yapqfVd7_sendMessage);
}

void Heavy_SoundScraper::cMsg_YAJdvIqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qhLn4TaM, 0, m, &cDelay_qhLn4TaM_sendMessage);
}

void Heavy_SoundScraper::cCast_OQqxBm2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qhLn4TaM, 0, m, &cDelay_qhLn4TaM_sendMessage);
}

void Heavy_SoundScraper::cPack_awlfwhed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TaIEsGAo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_9qjvEhxY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cfsscvFk_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_VGcsXMV2, HV_BINOP_SUBTRACT, 0, m, &cBinop_VGcsXMV2_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_cfsscvFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z2dlRsJC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_sjcW5mxs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_7ELDur2f_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_7ELDur2f_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_oB2KhVYW, 1, m, &cDelay_oB2KhVYW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7HW1mdA7_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_oB2KhVYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oB2KhVYW, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_liJi3GRz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dSfeWMAD_sendMessage);
}

void Heavy_SoundScraper::cMsg_7ELDur2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_oB2KhVYW, 0, m, &cDelay_oB2KhVYW_sendMessage);
}

void Heavy_SoundScraper::cCast_7HW1mdA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oB2KhVYW, 0, m, &cDelay_oB2KhVYW_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_pjJV8yZ7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_6YhXHIj3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_6YhXHIj3_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_nsI1qWCf, 1, m, &cDelay_nsI1qWCf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tFc2NGGA_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_nsI1qWCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nsI1qWCf, m);
}

void Heavy_SoundScraper::cMsg_6YhXHIj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nsI1qWCf, 0, m, &cDelay_nsI1qWCf_sendMessage);
}

void Heavy_SoundScraper::cCast_tFc2NGGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nsI1qWCf, 0, m, &cDelay_nsI1qWCf_sendMessage);
}

void Heavy_SoundScraper::cPack_JKEYuDVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SynE2Kv4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_qHfcMM9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KNQvY5ji_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_aHVzeG9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IdjdoeLw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_Lox4tWPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MAXzuWeF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_7oDnoUMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8lyTGZOw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_I6j0Rc8z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OR2edB1h, HV_BINOP_DIVIDE, 1, m, &cBinop_OR2edB1h_sendMessage);
}

void Heavy_SoundScraper::cVar_CIoyXwKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OR2edB1h, HV_BINOP_DIVIDE, 0, m, &cBinop_OR2edB1h_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_3mUPtn9H_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I3ug2qHH_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jQmbcG5i_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VnAdZfM1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jPlb9a5o_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_I3ug2qHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I6j0Rc8z, 0, m, &cVar_I6j0Rc8z_sendMessage);
}

void Heavy_SoundScraper::cCast_jQmbcG5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CIoyXwKa, 0, m, &cVar_CIoyXwKa_sendMessage);
}

void Heavy_SoundScraper::cCast_jPlb9a5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CIoyXwKa, 0, m, &cVar_CIoyXwKa_sendMessage);
}

void Heavy_SoundScraper::cCast_VnAdZfM1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I6j0Rc8z, 0, m, &cVar_I6j0Rc8z_sendMessage);
}

void Heavy_SoundScraper::cPack_QmIC7Vfy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3NbvYjnZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_lJc6QFav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_awlfwhed, 1, m, &cPack_awlfwhed_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_W7JntOxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yQV2SttF, HV_BINOP_ADD, 0, m, &cBinop_yQV2SttF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_opHDTDiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_JKEYuDVq, 1, m, &cPack_JKEYuDVq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_wHtW5rfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1JtQsEiD, HV_BINOP_ADD, 0, m, &cBinop_1JtQsEiD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_GdeD0ZOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1ZhHLgy1, 0, m, &cVar_1ZhHLgy1_sendMessage);
}

void Heavy_SoundScraper::cCast_yapqfVd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AMQ8fYV4, 0, m, &cVar_AMQ8fYV4_sendMessage);
}

void Heavy_SoundScraper::cSend_TaIEsGAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jEcdTOnK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_3NbvYjnZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mXi5eudv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_MAXzuWeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mXi5eudv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_oln8UWcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_FYsituht_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_TWkawlYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Lox4tWPQ, 0, m, &cPack_Lox4tWPQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_6LzfVdvi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_aHVzeG9D, 0, m, &cPack_aHVzeG9D_sendMessage);
}

void Heavy_SoundScraper::cSend_SynE2Kv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jEcdTOnK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_KHqJVEOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qHfcMM9G, 0, m, &cPack_qHfcMM9G_sendMessage);
}

void Heavy_SoundScraper::cBinop_1pyxrwza_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QLY2AnBC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_yQV2SttF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_awlfwhed, 0, m, &cPack_awlfwhed_sendMessage);
}

void Heavy_SoundScraper::cBinop_VGcsXMV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sjcW5mxs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_1JtQsEiD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JKEYuDVq, 0, m, &cPack_JKEYuDVq_sendMessage);
}

void Heavy_SoundScraper::cMsg_z2dlRsJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_sjcW5mxs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_eQZWzkir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M8x0WpkY, HV_BINOP_MULTIPLY, 1, m, &cBinop_M8x0WpkY_sendMessage);
}

void Heavy_SoundScraper::cMsg_KNQvY5ji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_opHDTDiN, 0, m, &cSlice_opHDTDiN_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_wHtW5rfB, 0, m, &cSlice_wHtW5rfB_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_opHDTDiN, 0, m, &cSlice_opHDTDiN_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_wHtW5rfB, 0, m, &cSlice_wHtW5rfB_sendMessage);
}

void Heavy_SoundScraper::cBinop_c03ATzVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qHfcMM9G, 1, m, &cPack_qHfcMM9G_sendMessage);
}

void Heavy_SoundScraper::cBinop_hW3yQZBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_aHVzeG9D, 1, m, &cPack_aHVzeG9D_sendMessage);
}

void Heavy_SoundScraper::cMsg_IdjdoeLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_lJc6QFav, 0, m, &cSlice_lJc6QFav_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_W7JntOxG, 0, m, &cSlice_W7JntOxG_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_lJc6QFav, 0, m, &cSlice_lJc6QFav_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_W7JntOxG, 0, m, &cSlice_W7JntOxG_sendMessage);
}

void Heavy_SoundScraper::cSend_8lyTGZOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mXi5eudv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_OR2edB1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_DmDhVBQG_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_tNfMBmWk, 0, m, &cIf_tNfMBmWk_sendMessage);
}

void Heavy_SoundScraper::cCast_iYbm2woG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Lox4tWPQ, 1, m, &cPack_Lox4tWPQ_sendMessage);
}

void Heavy_SoundScraper::cCast_94IHGqqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qhLn4TaM, 1, m, &cDelay_qhLn4TaM_sendMessage);
}

void Heavy_SoundScraper::cCast_r32avDma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1JtQsEiD, HV_BINOP_ADD, 1, m, &cBinop_1JtQsEiD_sendMessage);
}

void Heavy_SoundScraper::cCast_Oq5RZZqs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQV2SttF, HV_BINOP_ADD, 1, m, &cBinop_yQV2SttF_sendMessage);
}

void Heavy_SoundScraper::cCast_Itu06abr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nsI1qWCf, 1, m, &cDelay_nsI1qWCf_sendMessage);
}

void Heavy_SoundScraper::cCast_beH50Voc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VGcsXMV2, HV_BINOP_SUBTRACT, 1, m, &cBinop_VGcsXMV2_sendMessage);
}

void Heavy_SoundScraper::cCast_liJi3GRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pjJV8yZ7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_dSfeWMAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7oDnoUMn, 0, m, &cPack_7oDnoUMn_sendMessage);
}

void Heavy_SoundScraper::cCast_je5oR4Ah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sjcW5mxs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_H53Ld2Rj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pjJV8yZ7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_M8x0WpkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_r32avDma_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Oq5RZZqs_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Eiiua512_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZcFAOPIw_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_AMQ8fYV4, 1, m, &cVar_AMQ8fYV4_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_ZcFAOPIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vbEfBCrL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_1qvQuYC6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A9YPtVXk_sendMessage);
      break;
    }
    default: {
      cSwitchcase_3mUPtn9H_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_1ZhHLgy1, 1, m, &cVar_1ZhHLgy1_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_A9YPtVXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NSr76y1T_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_Z3FYfdgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_4RnslAh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_9qjvEhxY_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_OPhpzvEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_M8x0WpkY, HV_BINOP_MULTIPLY, 0, m, &cBinop_M8x0WpkY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_BTAX4nMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_1qvQuYC6_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_KmdnYnAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_GT5Vs5FI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_Eiiua512_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_vbEfBCrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_AMQ8fYV4, 1, m, &cVar_AMQ8fYV4_sendMessage);
}

void Heavy_SoundScraper::cCast_ZuAWtO8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HTiePzEW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_NSr76y1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_3mUPtn9H_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_1ZhHLgy1, 1, m, &cVar_1ZhHLgy1_sendMessage);
}

void Heavy_SoundScraper::cMsg_HTiePzEW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Z3FYfdgM, 0, m, &cSlice_Z3FYfdgM_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_4RnslAh7, 0, m, &cSlice_4RnslAh7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OPhpzvEw, 0, m, &cSlice_OPhpzvEw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BTAX4nMC, 0, m, &cSlice_BTAX4nMC_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_KmdnYnAD, 0, m, &cSlice_KmdnYnAD_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GT5Vs5FI, 0, m, &cSlice_GT5Vs5FI_sendMessage);
}

void Heavy_SoundScraper::cSlice_bxGTatNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3N2TIHhH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_hxiFlJl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nnrsvsDu_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_nnrsvsDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BrQ4otC8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_BrQ4otC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_x8W8go9Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_3N2TIHhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yXkKEt3i_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_yXkKEt3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rUJpbPwI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_aHyvdpw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_baM2cima_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_JBxl2BNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rXyxOcvg, HV_BINOP_MULTIPLY, 1, m, &cBinop_rXyxOcvg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uY7uA4os, HV_BINOP_MULTIPLY, 1, m, &cBinop_uY7uA4os_sendMessage);
}

void Heavy_SoundScraper::cSlice_1bu7BR1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rXyxOcvg, HV_BINOP_MULTIPLY, 0, m, &cBinop_rXyxOcvg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_eF1NBNQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_uY7uA4os, HV_BINOP_MULTIPLY, 0, m, &cBinop_uY7uA4os_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_baM2cima_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_m9wWSj4e_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_m9wWSj4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 220500000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cMsg_tQtEkIvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1bu7BR1H, 0, m, &cSlice_1bu7BR1H_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_eF1NBNQq, 0, m, &cSlice_eF1NBNQq_sendMessage);
}

void Heavy_SoundScraper::cBinop_rXyxOcvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_aHyvdpw8, 1, m, &cPack_aHyvdpw8_sendMessage);
}

void Heavy_SoundScraper::cBinop_uY7uA4os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_aHyvdpw8, 0, m, &cPack_aHyvdpw8_sendMessage);
}

void Heavy_SoundScraper::cSend_yrXZR99L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_T0GteK6q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_OlWzacdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_mKMKVUXb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_FXSkZnby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_hZqLQ3mg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_cnJogt9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nL0OQ4De_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_b2XQjDlT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_tr8TAC6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0aRWDeRk, 1, m, &cPack_0aRWDeRk_sendMessage);
}

void Heavy_SoundScraper::cVar_NahEyvbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0aRWDeRk, 0, m, &cPack_0aRWDeRk_sendMessage);
}

void Heavy_SoundScraper::cPack_0aRWDeRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RfaUCXct_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IcJRXeAC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZuAWtO8E_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Z3FYfdgM, 0, m, &cSlice_Z3FYfdgM_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_4RnslAh7, 0, m, &cSlice_4RnslAh7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OPhpzvEw, 0, m, &cSlice_OPhpzvEw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BTAX4nMC, 0, m, &cSlice_BTAX4nMC_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_KmdnYnAD, 0, m, &cSlice_KmdnYnAD_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GT5Vs5FI, 0, m, &cSlice_GT5Vs5FI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TWkawlYw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oln8UWcx_sendMessage);
  cMsg_OlWzacdj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_34JmNnDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NahEyvbZ, 0, m, &cVar_NahEyvbZ_sendMessage);
}

void Heavy_SoundScraper::cCast_OX9M8HWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0aRWDeRk, 2, m, &cPack_0aRWDeRk_sendMessage);
}

void Heavy_SoundScraper::cCast_2bbqQCxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tr8TAC6a, 0, m, &cVar_tr8TAC6a_sendMessage);
}

void Heavy_SoundScraper::cBinop_4D5fVyMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_PxFz3Yhj_sendMessage);
}

void Heavy_SoundScraper::cBinop_PxFz3Yhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_q3NOnipa_sendMessage);
}

void Heavy_SoundScraper::cBinop_hZqLQ3mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Vvg3Pxc2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_l7s0i59l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OX9M8HWj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2bbqQCxd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_34JmNnDp_sendMessage);
}

void Heavy_SoundScraper::cBinop_uEpJ0xmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_Por28N1q_sendMessage);
}

void Heavy_SoundScraper::cBinop_Por28N1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7s0i59l, HV_BINOP_MULTIPLY, 1, m, &cBinop_l7s0i59l_sendMessage);
}

void Heavy_SoundScraper::cCast_nL0OQ4De_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GfctOgnO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_IcJRXeAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FdTIVmBk_sendMessage);
}

void Heavy_SoundScraper::cCast_RfaUCXct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZCmDJ8Ex_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZYmkl56m_sendMessage);
}

void Heavy_SoundScraper::cSend_j1uts22i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NauRnm0H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_CLRffXxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RkUj55iW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_yaY5cQwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7s0i59l, HV_BINOP_MULTIPLY, 0, m, &cBinop_l7s0i59l_sendMessage);
}

void Heavy_SoundScraper::cSend_Vvg3Pxc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gVT2TZRx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_IcCrIP5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_yrXZR99L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_MZ7sA6ys_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pdTfZVna, 0, m, &cSlice_pdTfZVna_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lXsyFYfQ, 0, m, &cRandom_lXsyFYfQ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_4Bi3CMkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_TEJucVXE_sendMessage);
}

void Heavy_SoundScraper::cUnop_TEJucVXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_LfrXiNYh_sendMessage);
}

void Heavy_SoundScraper::cRandom_lXsyFYfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_4Bi3CMkQ_sendMessage);
}

void Heavy_SoundScraper::cSlice_pdTfZVna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lXsyFYfQ, 1, m, &cRandom_lXsyFYfQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_TgMrm1b6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9TKo4Ur, HV_BINOP_DIVIDE, 0, m, &cBinop_y9TKo4Ur_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ka8tyBfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_H3IMWuEO_sendMessage);
}

void Heavy_SoundScraper::cBinop_H3IMWuEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z5k7Kah6, HV_BINOP_POW, 1, m, &cBinop_Z5k7Kah6_sendMessage);
  cMsg_hgj3ZJqO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Z5k7Kah6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_TgMrm1b6_sendMessage);
}

void Heavy_SoundScraper::cMsg_hgj3ZJqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z5k7Kah6, HV_BINOP_POW, 0, m, &cBinop_Z5k7Kah6_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_S91l5WJL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_COYqVIfG, 0, m, &cSlice_COYqVIfG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_70lYcY3E, 0, m, &cRandom_70lYcY3E_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_jRFNklkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_P5kMNoQB_sendMessage);
}

void Heavy_SoundScraper::cUnop_P5kMNoQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yB5LXsvA_sendMessage);
}

void Heavy_SoundScraper::cRandom_70lYcY3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_jRFNklkr_sendMessage);
}

void Heavy_SoundScraper::cSlice_COYqVIfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_70lYcY3E, 1, m, &cRandom_70lYcY3E_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_jHtbTf4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_IrfOLMAc_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_S1nYIyAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_EhfwqAxa_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_TN3HctkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_csA8u2m9, 0, m, &cPack_csA8u2m9_sendMessage);
}

void Heavy_SoundScraper::cUnop_SBpuGrYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tubQWDR5, 0, m, &cPack_tubQWDR5_sendMessage);
}

void Heavy_SoundScraper::cPack_tubQWDR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_UOTAVrEi, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_csA8u2m9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_3PNAFvQS, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_9kBQevsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_TN3HctkE_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_SBpuGrYz_sendMessage);
}

void Heavy_SoundScraper::cMsg_PHN8opTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_9kBQevsP_sendMessage);
}

void Heavy_SoundScraper::cCast_rgLPzao8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_knmFkY2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QT79yKTu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p6irhe6T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QDRHj35a_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_rG3Wu9Aa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_WakYR4AF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_WakYR4AF_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_SE3YwM4M, 1, m, &cDelay_SE3YwM4M_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2n9HPYPW_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_SE3YwM4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SE3YwM4M, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NXtwZNhD, 0, m, &cVar_NXtwZNhD_sendMessage);
}

void Heavy_SoundScraper::cMsg_WakYR4AF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SE3YwM4M, 0, m, &cDelay_SE3YwM4M_sendMessage);
}

void Heavy_SoundScraper::cCast_2n9HPYPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SE3YwM4M, 0, m, &cDelay_SE3YwM4M_sendMessage);
}

void Heavy_SoundScraper::cVar_NXtwZNhD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a3VoF8qL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_rJUtsKAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_knmFkY2y, 0, m, &cVar_knmFkY2y_sendMessage);
}

void Heavy_SoundScraper::cSend_I5kazipM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_wlwpPaMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yAdlsYH8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_I3IoP9d1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_I5kazipM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_UPUylRRh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_wlwpPaMy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_EIALWyz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UPeteCQP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KAV7ePwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_EIALWyz9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_iIGWw2XZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_6iZWzfCj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yAdlsYH8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_fXr5d8Bb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UPeteCQP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_b81LfuFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2bVg3iUv, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_a3VoF8qL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_2bVg3iUv, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_QT79yKTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b81LfuFj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_p6irhe6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NXtwZNhD, 1, m, &cVar_NXtwZNhD_sendMessage);
}

void Heavy_SoundScraper::cCast_QDRHj35a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rG3Wu9Aa_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_1ddJ58w5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_w2DvFUDs, 0, m, &cSlice_w2DvFUDs_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_KmmEqxwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vFdu7fvu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_OPSXuMTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_9yHzjMNe_sendMessage);
}

void Heavy_SoundScraper::cBinop_9yHzjMNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3sId2lea, m);
}

void Heavy_SoundScraper::cMsg_vFdu7fvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OPSXuMTW_sendMessage);
}

void Heavy_SoundScraper::cSlice_w2DvFUDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_8ZhUxK3H, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_JpeD1zqd, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_KmmEqxwI, 0, m, &cVar_KmmEqxwI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_uvPwAJzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_NPw7VWWX, 0, m, &cPack_NPw7VWWX_sendMessage);
}

void Heavy_SoundScraper::cVar_hFKRS3jB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_Zh0dxbye_sendMessage);
}

void Heavy_SoundScraper::cIf_zUqUz5bM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_ueDwsEGD_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_hFKRS3jB, 1, m, &cVar_hFKRS3jB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_1Ek27faV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zUqUz5bM, 1, m, &cIf_zUqUz5bM_sendMessage);
}

void Heavy_SoundScraper::cVar_gpYKDewF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_FGMDYDUC_sendMessage);
}

void Heavy_SoundScraper::cUnop_ueDwsEGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gpYKDewF, 1, m, &cVar_gpYKDewF_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_LwayEhzj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v2rlyrBF_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QYnAe9YJ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_v2rlyrBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hFKRS3jB, 0, m, &cVar_hFKRS3jB_sendMessage);
}

void Heavy_SoundScraper::cCast_QYnAe9YJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gpYKDewF, 0, m, &cVar_gpYKDewF_sendMessage);
}

void Heavy_SoundScraper::cVar_9dVEpMmC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_oPMlnPkE_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_TguK2ko2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_rzJARxiy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_rzJARxiy_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ua8w0ARd, 1, m, &cDelay_ua8w0ARd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6XyPik9n_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ua8w0ARd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ua8w0ARd, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UWdhXKSj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wTBNCLgK_sendMessage);
}

void Heavy_SoundScraper::cMsg_rzJARxiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ua8w0ARd, 0, m, &cDelay_ua8w0ARd_sendMessage);
}

void Heavy_SoundScraper::cCast_6XyPik9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ua8w0ARd, 0, m, &cDelay_ua8w0ARd_sendMessage);
}

void Heavy_SoundScraper::cPack_7VQm0qO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HPAfgktJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_DImXIEFw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3PJSTUJT_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_p3LS4zf3, HV_BINOP_SUBTRACT, 0, m, &cBinop_p3LS4zf3_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_3PJSTUJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JtA6BTvI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_87wAXYaW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_aGpNrsAr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_aGpNrsAr_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_dSROOccP, 1, m, &cDelay_dSROOccP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dlb5d86t_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_dSROOccP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dSROOccP, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YnMjCCCz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6Wx8ubms_sendMessage);
}

void Heavy_SoundScraper::cMsg_aGpNrsAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_dSROOccP, 0, m, &cDelay_dSROOccP_sendMessage);
}

void Heavy_SoundScraper::cCast_Dlb5d86t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dSROOccP, 0, m, &cDelay_dSROOccP_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_cYVO97mE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Y2P5lT8I_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Y2P5lT8I_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_iwbf23Wv, 1, m, &cDelay_iwbf23Wv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8Wm1gtVB_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_iwbf23Wv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iwbf23Wv, m);
}

void Heavy_SoundScraper::cMsg_Y2P5lT8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iwbf23Wv, 0, m, &cDelay_iwbf23Wv_sendMessage);
}

void Heavy_SoundScraper::cCast_8Wm1gtVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iwbf23Wv, 0, m, &cDelay_iwbf23Wv_sendMessage);
}

void Heavy_SoundScraper::cPack_idxERVC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_EiQlUc1P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_c8BAvy5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nTynFeCb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_hHbKpNUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8zEgIVJ0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_SAfKwfvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_llQKu2qz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_kQBalaVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uuc1iilN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_o6ABbOM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oWMPlqpB, HV_BINOP_DIVIDE, 1, m, &cBinop_oWMPlqpB_sendMessage);
}

void Heavy_SoundScraper::cVar_mJntBFfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oWMPlqpB, HV_BINOP_DIVIDE, 0, m, &cBinop_oWMPlqpB_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_KDdP5At3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WDfSUqNs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NF6fXV4x_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wa7A8Zr2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9l6cfe9K_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_NF6fXV4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mJntBFfM, 0, m, &cVar_mJntBFfM_sendMessage);
}

void Heavy_SoundScraper::cCast_WDfSUqNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o6ABbOM9, 0, m, &cVar_o6ABbOM9_sendMessage);
}

void Heavy_SoundScraper::cCast_9l6cfe9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mJntBFfM, 0, m, &cVar_mJntBFfM_sendMessage);
}

void Heavy_SoundScraper::cCast_wa7A8Zr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o6ABbOM9, 0, m, &cVar_o6ABbOM9_sendMessage);
}

void Heavy_SoundScraper::cPack_NPw7VWWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6cpvj7qa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_QDByNRL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_7VQm0qO6, 1, m, &cPack_7VQm0qO6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_TaUZydIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_U8gASISt, HV_BINOP_ADD, 0, m, &cBinop_U8gASISt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ApoGF0w8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_idxERVC4, 1, m, &cPack_idxERVC4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_7BPixTs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yfrKWl4k, HV_BINOP_ADD, 0, m, &cBinop_yfrKWl4k_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_UWdhXKSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9dVEpMmC, 0, m, &cVar_9dVEpMmC_sendMessage);
}

void Heavy_SoundScraper::cCast_wTBNCLgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uvPwAJzY, 0, m, &cVar_uvPwAJzY_sendMessage);
}

void Heavy_SoundScraper::cSend_HPAfgktJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uAn9zqw4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_6cpvj7qa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Srs2QlbM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_llQKu2qz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Srs2QlbM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_HrefQiUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SAfKwfvJ, 0, m, &cPack_SAfKwfvJ_sendMessage);
}

void Heavy_SoundScraper::cCast_F2e9SGKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TguK2ko2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_Zh0dxbye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hHbKpNUo, 0, m, &cPack_hHbKpNUo_sendMessage);
}

void Heavy_SoundScraper::cSend_EiQlUc1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uAn9zqw4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_FGMDYDUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_c8BAvy5O, 0, m, &cPack_c8BAvy5O_sendMessage);
}

void Heavy_SoundScraper::cBinop_oPMlnPkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LwayEhzj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_U8gASISt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7VQm0qO6, 0, m, &cPack_7VQm0qO6_sendMessage);
}

void Heavy_SoundScraper::cBinop_p3LS4zf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_87wAXYaW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_yfrKWl4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_idxERVC4, 0, m, &cPack_idxERVC4_sendMessage);
}

void Heavy_SoundScraper::cMsg_JtA6BTvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_87wAXYaW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_kbJMmWBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LROWzPm5, HV_BINOP_MULTIPLY, 1, m, &cBinop_LROWzPm5_sendMessage);
}

void Heavy_SoundScraper::cMsg_nTynFeCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ApoGF0w8, 0, m, &cSlice_ApoGF0w8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_7BPixTs2, 0, m, &cSlice_7BPixTs2_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ApoGF0w8, 0, m, &cSlice_ApoGF0w8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_7BPixTs2, 0, m, &cSlice_7BPixTs2_sendMessage);
}

void Heavy_SoundScraper::cBinop_JzXgoPit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_c8BAvy5O, 1, m, &cPack_c8BAvy5O_sendMessage);
}

void Heavy_SoundScraper::cBinop_JVRqjkE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hHbKpNUo, 1, m, &cPack_hHbKpNUo_sendMessage);
}

void Heavy_SoundScraper::cMsg_8zEgIVJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QDByNRL7, 0, m, &cSlice_QDByNRL7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TaUZydIz, 0, m, &cSlice_TaUZydIz_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QDByNRL7, 0, m, &cSlice_QDByNRL7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TaUZydIz, 0, m, &cSlice_TaUZydIz_sendMessage);
}

void Heavy_SoundScraper::cSend_uuc1iilN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Srs2QlbM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_oWMPlqpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_1Ek27faV_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zUqUz5bM, 0, m, &cIf_zUqUz5bM_sendMessage);
}

void Heavy_SoundScraper::cCast_KleTJijS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SAfKwfvJ, 1, m, &cPack_SAfKwfvJ_sendMessage);
}

void Heavy_SoundScraper::cCast_fG0YqvAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ua8w0ARd, 1, m, &cDelay_ua8w0ARd_sendMessage);
}

void Heavy_SoundScraper::cCast_MW06Zc5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8gASISt, HV_BINOP_ADD, 1, m, &cBinop_U8gASISt_sendMessage);
}

void Heavy_SoundScraper::cCast_dVjhrmwd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yfrKWl4k, HV_BINOP_ADD, 1, m, &cBinop_yfrKWl4k_sendMessage);
}

void Heavy_SoundScraper::cCast_ulgOQNH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p3LS4zf3, HV_BINOP_SUBTRACT, 1, m, &cBinop_p3LS4zf3_sendMessage);
}

void Heavy_SoundScraper::cCast_KbAas3mW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iwbf23Wv, 1, m, &cDelay_iwbf23Wv_sendMessage);
}

void Heavy_SoundScraper::cCast_YnMjCCCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cYVO97mE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_6Wx8ubms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kQBalaVk, 0, m, &cPack_kQBalaVk_sendMessage);
}

void Heavy_SoundScraper::cCast_QiO6oqmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cYVO97mE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ktEkFV4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_87wAXYaW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_LROWzPm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dVjhrmwd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MW06Zc5m_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_5cLXo6Py_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HYazb6DN_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_uvPwAJzY, 1, m, &cVar_uvPwAJzY_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_HYazb6DN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O6jkHssn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_acEYQF9T_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qmZzG1IE_sendMessage);
      break;
    }
    default: {
      cSwitchcase_KDdP5At3_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_9dVEpMmC, 1, m, &cVar_9dVEpMmC_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_qmZzG1IE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hRMLNp7K_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_NZucynTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_vJlifqfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_DImXIEFw_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_kbs8Zyfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LROWzPm5, HV_BINOP_MULTIPLY, 0, m, &cBinop_LROWzPm5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_DgWtMBvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_acEYQF9T_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_uInGRj87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_Cmiw4wzt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_5cLXo6Py_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_O6jkHssn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_uvPwAJzY, 1, m, &cVar_uvPwAJzY_sendMessage);
}

void Heavy_SoundScraper::cCast_swKJssGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2mVINF62_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_hRMLNp7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_KDdP5At3_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_9dVEpMmC, 1, m, &cVar_9dVEpMmC_sendMessage);
}

void Heavy_SoundScraper::cMsg_2mVINF62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NZucynTd, 0, m, &cSlice_NZucynTd_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vJlifqfT, 0, m, &cSlice_vJlifqfT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kbs8Zyfo, 0, m, &cSlice_kbs8Zyfo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DgWtMBvI, 0, m, &cSlice_DgWtMBvI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uInGRj87, 0, m, &cSlice_uInGRj87_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Cmiw4wzt, 0, m, &cSlice_Cmiw4wzt_sendMessage);
}

void Heavy_SoundScraper::cSlice_1c2ZTtdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EtW8bE9D_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_uJHKVOPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yz2BrATB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_yz2BrATB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HpGnMdb6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_HpGnMdb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WpYvY7yr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_EtW8bE9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rqhMLoEi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_rqhMLoEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mGmxsbCG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_We5uBtup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eUWksDO4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_sFjD6IYN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YSP4nBv8, HV_BINOP_MULTIPLY, 1, m, &cBinop_YSP4nBv8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IQItaRVb, HV_BINOP_MULTIPLY, 1, m, &cBinop_IQItaRVb_sendMessage);
}

void Heavy_SoundScraper::cSlice_i76AwZLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_YSP4nBv8, HV_BINOP_MULTIPLY, 0, m, &cBinop_YSP4nBv8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_fyfZpF8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IQItaRVb, HV_BINOP_MULTIPLY, 0, m, &cBinop_IQItaRVb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_eUWksDO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_p3XFrZKU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_p3XFrZKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 220500000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cMsg_afSQfykh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_i76AwZLQ, 0, m, &cSlice_i76AwZLQ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_fyfZpF8I, 0, m, &cSlice_fyfZpF8I_sendMessage);
}

void Heavy_SoundScraper::cBinop_YSP4nBv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_We5uBtup, 1, m, &cPack_We5uBtup_sendMessage);
}

void Heavy_SoundScraper::cBinop_IQItaRVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_We5uBtup, 0, m, &cPack_We5uBtup_sendMessage);
}

void Heavy_SoundScraper::cSend_YlxQE1x9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PLCfMZBe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_s80snXyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_1ddJ58w5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_Q7qJrA9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_d7WjO3BP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_DIdVSaWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X9Gsmzwb_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Ka8tyBfM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_VvR1dAGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DSklzqgD, 1, m, &cPack_DSklzqgD_sendMessage);
}

void Heavy_SoundScraper::cVar_GgknyzQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DSklzqgD, 0, m, &cPack_DSklzqgD_sendMessage);
}

void Heavy_SoundScraper::cPack_DSklzqgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nRIGaN8w_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_72uupIN1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_swKJssGo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NZucynTd, 0, m, &cSlice_NZucynTd_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vJlifqfT, 0, m, &cSlice_vJlifqfT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kbs8Zyfo, 0, m, &cSlice_kbs8Zyfo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DgWtMBvI, 0, m, &cSlice_DgWtMBvI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uInGRj87, 0, m, &cSlice_uInGRj87_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Cmiw4wzt, 0, m, &cSlice_Cmiw4wzt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HrefQiUp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F2e9SGKY_sendMessage);
  cMsg_s80snXyK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_jKAUt8mn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GgknyzQi, 0, m, &cVar_GgknyzQi_sendMessage);
}

void Heavy_SoundScraper::cCast_2RXt4PyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DSklzqgD, 2, m, &cPack_DSklzqgD_sendMessage);
}

void Heavy_SoundScraper::cCast_1Eq13Mld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VvR1dAGz, 0, m, &cVar_VvR1dAGz_sendMessage);
}

void Heavy_SoundScraper::cBinop_LfrXiNYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_PwKgsdwn_sendMessage);
}

void Heavy_SoundScraper::cBinop_PwKgsdwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_9kBQevsP_sendMessage);
}

void Heavy_SoundScraper::cBinop_d7WjO3BP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Jy8QNooW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1rmmKHih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2RXt4PyP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Eq13Mld_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jKAUt8mn_sendMessage);
}

void Heavy_SoundScraper::cBinop_yB5LXsvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_boEfwqNf_sendMessage);
}

void Heavy_SoundScraper::cBinop_boEfwqNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1rmmKHih, HV_BINOP_MULTIPLY, 1, m, &cBinop_1rmmKHih_sendMessage);
}

void Heavy_SoundScraper::cCast_X9Gsmzwb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_S91l5WJL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_72uupIN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rJUtsKAM_sendMessage);
}

void Heavy_SoundScraper::cCast_nRIGaN8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MZ7sA6ys_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rgLPzao8_sendMessage);
}

void Heavy_SoundScraper::cSend_EhfwqAxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hS1w2Z8q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_IrfOLMAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_b6DfmkFG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_y9TKo4Ur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1rmmKHih, HV_BINOP_MULTIPLY, 0, m, &cBinop_1rmmKHih_sendMessage);
}

void Heavy_SoundScraper::cSend_Jy8QNooW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_L6C72N63_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_5N6aX30V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_YlxQE1x9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_hVYy6fcl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OLQ1PQCx, 0, m, &cSlice_OLQ1PQCx_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PO73u0tm, 0, m, &cRandom_PO73u0tm_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_MWVKNvAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PWE0JFKs_sendMessage);
}

void Heavy_SoundScraper::cUnop_PWE0JFKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_n6dvrW5k_sendMessage);
}

void Heavy_SoundScraper::cRandom_PO73u0tm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_MWVKNvAN_sendMessage);
}

void Heavy_SoundScraper::cSlice_OLQ1PQCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PO73u0tm, 1, m, &cRandom_PO73u0tm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_XfqfhTEv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W4x5SL9u_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vAafbkiV_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XG1pdyuL_sendMessage);
      break;
    }
    case 0x40A00000: { // "5.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E8p3Wig0_sendMessage);
      break;
    }
    case 0x40C00000: { // "6.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SGeHMKYp_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_W4x5SL9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k5xbTlT1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_vAafbkiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w8uDsb0E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_XG1pdyuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9pPf9ahL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_E8p3Wig0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c01s3Jxt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_SGeHMKYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TpMsYyLq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_RvvO72sl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RhpfNdtA_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_An2zERQQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KeNsvscq_sendMessage);
}

void Heavy_SoundScraper::cIf_IAEXlpVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_k22MxCcb_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_57Tlu8Bf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_bO9JRGZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zeW739bn, HV_BINOP_POW, 0, m, &cBinop_zeW739bn_sendMessage);
}

void Heavy_SoundScraper::cBinop_zeW739bn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1IkF2cyc, 0, m, &cPack_1IkF2cyc_sendMessage);
}

void Heavy_SoundScraper::cBinop_XfECdkys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_qeJwfRbk_sendMessage);
}

void Heavy_SoundScraper::cCast_KeNsvscq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IAEXlpVJ, 0, m, &cIf_IAEXlpVJ_sendMessage);
}

void Heavy_SoundScraper::cCast_An2zERQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_GFew0xVW_sendMessage);
}

void Heavy_SoundScraper::cBinop_GFew0xVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IAEXlpVJ, 1, m, &cIf_IAEXlpVJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_57Tlu8Bf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_XfECdkys_sendMessage);
}

void Heavy_SoundScraper::cMsg_k22MxCcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_1IkF2cyc, 0, m, &cPack_1IkF2cyc_sendMessage);
}

void Heavy_SoundScraper::cBinop_qeJwfRbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zeW739bn, HV_BINOP_POW, 1, m, &cBinop_zeW739bn_sendMessage);
  cMsg_bO9JRGZl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_1IkF2cyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_UwfEmNoc, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_0YI7NiCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yGJIGkRS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_RhpfNdtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_c1CG78uy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_c1CG78uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IunLi465_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_yGJIGkRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8UbtHlxV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_1Uizhf61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hTH7wtii_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P1utA5BO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bVWGltde_sendMessage);
}

void Heavy_SoundScraper::cIf_zvLD43kE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_QHLfgya2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_axKcF1tE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_1Daqhtgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sfX5s909, HV_BINOP_POW, 0, m, &cBinop_sfX5s909_sendMessage);
}

void Heavy_SoundScraper::cBinop_sfX5s909_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zUwRhVRU, 0, m, &cPack_zUwRhVRU_sendMessage);
}

void Heavy_SoundScraper::cBinop_J9JWsv7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_P7IYi2P6_sendMessage);
}

void Heavy_SoundScraper::cCast_bVWGltde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zvLD43kE, 0, m, &cIf_zvLD43kE_sendMessage);
}

void Heavy_SoundScraper::cCast_P1utA5BO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_8ErNoD5M_sendMessage);
}

void Heavy_SoundScraper::cBinop_8ErNoD5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zvLD43kE, 1, m, &cIf_zvLD43kE_sendMessage);
}

void Heavy_SoundScraper::cBinop_axKcF1tE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_J9JWsv7Y_sendMessage);
}

void Heavy_SoundScraper::cMsg_QHLfgya2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_zUwRhVRU, 0, m, &cPack_zUwRhVRU_sendMessage);
}

void Heavy_SoundScraper::cBinop_P7IYi2P6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sfX5s909, HV_BINOP_POW, 1, m, &cBinop_sfX5s909_sendMessage);
  cMsg_1Daqhtgp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_zUwRhVRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_JASCXvgB, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_d8ZnlbDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pNA2LEJ6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_hTH7wtii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_kjShzGPv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_kjShzGPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kWMIetWs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_pNA2LEJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HTiBNaQl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_cARKryah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cHs4TIgb_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvFGyLGP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jlybmkbc_sendMessage);
}

void Heavy_SoundScraper::cIf_b7rAU3M0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VfpnXzpJ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_tFU5E6BK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_JBVdUC5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PoUIlUOA, HV_BINOP_POW, 0, m, &cBinop_PoUIlUOA_sendMessage);
}

void Heavy_SoundScraper::cBinop_PoUIlUOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LVj4fcxd, 0, m, &cPack_LVj4fcxd_sendMessage);
}

void Heavy_SoundScraper::cBinop_076jLahT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_7uPUR8Bd_sendMessage);
}

void Heavy_SoundScraper::cCast_GvFGyLGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_g8YwL602_sendMessage);
}

void Heavy_SoundScraper::cCast_Jlybmkbc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b7rAU3M0, 0, m, &cIf_b7rAU3M0_sendMessage);
}

void Heavy_SoundScraper::cBinop_g8YwL602_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b7rAU3M0, 1, m, &cIf_b7rAU3M0_sendMessage);
}

void Heavy_SoundScraper::cBinop_tFU5E6BK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_076jLahT_sendMessage);
}

void Heavy_SoundScraper::cMsg_VfpnXzpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_LVj4fcxd, 0, m, &cPack_LVj4fcxd_sendMessage);
}

void Heavy_SoundScraper::cBinop_7uPUR8Bd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PoUIlUOA, HV_BINOP_POW, 1, m, &cBinop_PoUIlUOA_sendMessage);
  cMsg_JBVdUC5A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_LVj4fcxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Oa55Ct8W, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_fUAHW5ir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xXLpVjxo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_cHs4TIgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_rwnO5Lx1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_rwnO5Lx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wF78PJdw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_xXLpVjxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5i5AI5KQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_ZXfIpuAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_RzL87w6g_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_bFg4pkwn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_bFg4pkwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_I660pWLQ_sendMessage);
}

void Heavy_SoundScraper::cCast_2yGwa1Y5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZXfIpuAP, 0, m, &cIf_ZXfIpuAP_sendMessage);
}

void Heavy_SoundScraper::cCast_LTGdkSmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_242DXZvO_sendMessage);
}

void Heavy_SoundScraper::cMsg_RzL87w6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_cHs4TIgb_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvFGyLGP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jlybmkbc_sendMessage);
}

void Heavy_SoundScraper::cBinop_I660pWLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_kj9G12KT_sendMessage);
}

void Heavy_SoundScraper::cBinop_kj9G12KT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DjHXikQV_sendMessage);
}

void Heavy_SoundScraper::cBinop_DjHXikQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cHs4TIgb_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvFGyLGP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jlybmkbc_sendMessage);
}

void Heavy_SoundScraper::cBinop_242DXZvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZXfIpuAP, 1, m, &cIf_ZXfIpuAP_sendMessage);
}

void Heavy_SoundScraper::cBinop_GbyAEhNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LTGdkSmf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2yGwa1Y5_sendMessage);
}

void Heavy_SoundScraper::cBinop_LMrkgcEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GbyAEhNJ_sendMessage);
}

void Heavy_SoundScraper::cIf_5BdWiroS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_aSDrsoRl_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_GZ2mHglz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_GZ2mHglz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_veBJUyh8_sendMessage);
}

void Heavy_SoundScraper::cCast_IxijpbQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5BdWiroS, 0, m, &cIf_5BdWiroS_sendMessage);
}

void Heavy_SoundScraper::cCast_XCaYJLsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ovaQMuTr_sendMessage);
}

void Heavy_SoundScraper::cMsg_aSDrsoRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_mK8fl5jB, 0, m, &cVar_mK8fl5jB_sendMessage);
}

void Heavy_SoundScraper::cBinop_veBJUyh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_tPaX7Ugd_sendMessage);
}

void Heavy_SoundScraper::cBinop_tPaX7Ugd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_radRj58m_sendMessage);
}

void Heavy_SoundScraper::cBinop_radRj58m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mK8fl5jB, 0, m, &cVar_mK8fl5jB_sendMessage);
}

void Heavy_SoundScraper::cBinop_ovaQMuTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5BdWiroS, 1, m, &cIf_5BdWiroS_sendMessage);
}

void Heavy_SoundScraper::cBinop_90IG5txj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XCaYJLsa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IxijpbQj_sendMessage);
}

void Heavy_SoundScraper::cBinop_U6cfhE15_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_90IG5txj_sendMessage);
}

void Heavy_SoundScraper::cIf_eOfDjukW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_uONqSZRY_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_UeIqRopv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_UeIqRopv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_6V3cEjI7_sendMessage);
}

void Heavy_SoundScraper::cCast_tLYmXLQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eOfDjukW, 0, m, &cIf_eOfDjukW_sendMessage);
}

void Heavy_SoundScraper::cCast_89qSY9jD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_urxrKX2x_sendMessage);
}

void Heavy_SoundScraper::cMsg_uONqSZRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_hTH7wtii_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P1utA5BO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bVWGltde_sendMessage);
}

void Heavy_SoundScraper::cBinop_6V3cEjI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_eylekkZ7_sendMessage);
}

void Heavy_SoundScraper::cBinop_eylekkZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cb5jCk2W_sendMessage);
}

void Heavy_SoundScraper::cBinop_cb5jCk2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hTH7wtii_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P1utA5BO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bVWGltde_sendMessage);
}

void Heavy_SoundScraper::cBinop_urxrKX2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eOfDjukW, 1, m, &cIf_eOfDjukW_sendMessage);
}

void Heavy_SoundScraper::cBinop_RojOcIUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_89qSY9jD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tLYmXLQ5_sendMessage);
}

void Heavy_SoundScraper::cBinop_Oyd1FXPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RojOcIUJ_sendMessage);
}

void Heavy_SoundScraper::cVar_HoDE51UV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SK8YdoMs_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZRNc4WeH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eep6e3Qa_sendMessage);
}

void Heavy_SoundScraper::cIf_sfb8FdfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_3xJw9m2D_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_NOgZAK4m_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_m3G7Gamm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XH5xj6jQ, HV_BINOP_POW, 0, m, &cBinop_XH5xj6jQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_XH5xj6jQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6gj7DwNl, 0, m, &cPack_6gj7DwNl_sendMessage);
}

void Heavy_SoundScraper::cBinop_3n0142kX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_k5qgB3na_sendMessage);
}

void Heavy_SoundScraper::cCast_ZRNc4WeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_2iSUrQ17_sendMessage);
}

void Heavy_SoundScraper::cCast_Eep6e3Qa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sfb8FdfV, 0, m, &cIf_sfb8FdfV_sendMessage);
}

void Heavy_SoundScraper::cBinop_2iSUrQ17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sfb8FdfV, 1, m, &cIf_sfb8FdfV_sendMessage);
}

void Heavy_SoundScraper::cBinop_NOgZAK4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_3n0142kX_sendMessage);
}

void Heavy_SoundScraper::cMsg_3xJw9m2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_6gj7DwNl, 0, m, &cPack_6gj7DwNl_sendMessage);
}

void Heavy_SoundScraper::cBinop_k5qgB3na_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XH5xj6jQ, HV_BINOP_POW, 1, m, &cBinop_XH5xj6jQ_sendMessage);
  cMsg_m3G7Gamm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_6gj7DwNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_bFszP7fh, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_9wZmOk49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_CUH2Xmv4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_SK8YdoMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_SESCnXK4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_SESCnXK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3PkN71bX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_CUH2Xmv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vgqqosdi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_j1yecy4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GG2z1naq_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_T2P3x86I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kdv6B4DE_sendMessage);
}

void Heavy_SoundScraper::cIf_5WrZzYbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_2GeDcQRj_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_gbTRlrnn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_Z5qpgODW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_iCmP4QLR, HV_BINOP_POW, 0, m, &cBinop_iCmP4QLR_sendMessage);
}

void Heavy_SoundScraper::cBinop_iCmP4QLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Rox7fAq4, 0, m, &cPack_Rox7fAq4_sendMessage);
}

void Heavy_SoundScraper::cBinop_im4Dq3Ci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_8tCSV3tg_sendMessage);
}

void Heavy_SoundScraper::cCast_T2P3x86I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_iR06demQ_sendMessage);
}

void Heavy_SoundScraper::cCast_Kdv6B4DE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5WrZzYbh, 0, m, &cIf_5WrZzYbh_sendMessage);
}

void Heavy_SoundScraper::cBinop_iR06demQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5WrZzYbh, 1, m, &cIf_5WrZzYbh_sendMessage);
}

void Heavy_SoundScraper::cBinop_gbTRlrnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_im4Dq3Ci_sendMessage);
}

void Heavy_SoundScraper::cMsg_2GeDcQRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_Rox7fAq4, 0, m, &cPack_Rox7fAq4_sendMessage);
}

void Heavy_SoundScraper::cBinop_8tCSV3tg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iCmP4QLR, HV_BINOP_POW, 1, m, &cBinop_iCmP4QLR_sendMessage);
  cMsg_Z5qpgODW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_Rox7fAq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mQrqDsTx, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_sLu2O4yb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0weEGW7b_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_GG2z1naq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_To6z4TUz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_To6z4TUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zWW595pW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_0weEGW7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OraqQrGC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_rrZ8MHv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f2l9qggW, 0, m, &cIf_f2l9qggW_sendMessage);
}

void Heavy_SoundScraper::cSlice_aJsCdIKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wJiMZrOG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_74rDp3Gt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_vmlqrmoT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_hWB84Ihb, 0, m, &cIf_hWB84Ihb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_hWB84Ihb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BsprpFg3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hEIWqpti_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_avBQq2ts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_vPYbmP5A, 2, m, &cPack_vPYbmP5A_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_tOsJYqaY, 1, m, &cPack_tOsJYqaY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_BuRP5uci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_aJsCdIKj, 0, m, &cSlice_aJsCdIKj_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vmlqrmoT, 0, m, &cSlice_vmlqrmoT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_OmSjkJxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ImgdvTVv_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_pJpaRFRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zo96Q29P_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SLJKaOnu_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yfd4oyxl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_lJklLelE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nu0aKjh6, 1, m, &cIf_nu0aKjh6_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_t3Qi5CfO_sendMessage);
}

void Heavy_SoundScraper::cIf_nu0aKjh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_aJsCdIKj, 0, m, &cSlice_aJsCdIKj_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vmlqrmoT, 0, m, &cSlice_vmlqrmoT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_tOsJYqaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BuRP5uci, 0, m, &cIf_BuRP5uci_sendMessage);
}

void Heavy_SoundScraper::cBinop_O32H9y2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hWB84Ihb, 1, m, &cIf_hWB84Ihb_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_avBQq2ts, 1, m, &cIf_avBQq2ts_sendMessage);
}

void Heavy_SoundScraper::cCast_wJiMZrOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_O32H9y2N_sendMessage);
}

void Heavy_SoundScraper::cCast_74rDp3Gt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_avBQq2ts, 0, m, &cIf_avBQq2ts_sendMessage);
}

void Heavy_SoundScraper::cMsg_G8ayus27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_lJklLelE, 1, m, &cVar_lJklLelE_sendMessage);
}

void Heavy_SoundScraper::cMsg_ImgdvTVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_lJklLelE, 1, m, &cVar_lJklLelE_sendMessage);
}

void Heavy_SoundScraper::cCast_Zo96Q29P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lJklLelE, 0, m, &cVar_lJklLelE_sendMessage);
}

void Heavy_SoundScraper::cCast_SLJKaOnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tOsJYqaY, 0, m, &cPack_tOsJYqaY_sendMessage);
}

void Heavy_SoundScraper::cCast_yfd4oyxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G8ayus27_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_t3Qi5CfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BuRP5uci, 1, m, &cIf_BuRP5uci_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_cvyMS33C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fiMxjs57, 0, m, &cSlice_fiMxjs57_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kmbrukko, 0, m, &cSlice_kmbrukko_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_03DmEe5R, 0, m, &cSlice_03DmEe5R_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_e2tCE7i7, 0, m, &cSlice_e2tCE7i7_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_fiMxjs57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_z1rwnIze, 0, m, &cSlice_z1rwnIze_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lKuI6xBU, 0, m, &cSlice_lKuI6xBU_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_z1rwnIze, 0, m, &cSlice_z1rwnIze_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lKuI6xBU, 0, m, &cSlice_lKuI6xBU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_kmbrukko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_u9Xqg0ml, 0, m, &cSlice_u9Xqg0ml_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ptaasdVk, 0, m, &cSlice_ptaasdVk_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_u9Xqg0ml, 0, m, &cSlice_u9Xqg0ml_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ptaasdVk, 0, m, &cSlice_ptaasdVk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_03DmEe5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_FXSkZnby, 0, m, &cSlice_FXSkZnby_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_cnJogt9T, 0, m, &cSlice_cnJogt9T_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_FXSkZnby, 0, m, &cSlice_FXSkZnby_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_cnJogt9T, 0, m, &cSlice_cnJogt9T_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_e2tCE7i7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Q7qJrA9w, 0, m, &cSlice_Q7qJrA9w_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_DIdVSaWM, 0, m, &cSlice_DIdVSaWM_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Q7qJrA9w, 0, m, &cSlice_Q7qJrA9w_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_DIdVSaWM, 0, m, &cSlice_DIdVSaWM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_fkijfhUU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1iwUUKaN_sendMessage);
      break;
    }
    default: {
      cMsg_gKzCKLwP_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_1iwUUKaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RQm9xVTB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_f2l9qggW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_OmSjkJxy, 0, m, &cSlice_OmSjkJxy_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_pJpaRFRv, 0, m, &cSlice_pJpaRFRv_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_nu0aKjh6, 0, m, &cIf_nu0aKjh6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_qR62oSe3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_IqMvf9K2_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_f2l9qggW, 1, m, &cIf_f2l9qggW_sendMessage);
}

void Heavy_SoundScraper::cBinop_IqMvf9K2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qR62oSe3, 1, m, &cVar_qR62oSe3_sendMessage);
}

void Heavy_SoundScraper::cMsg_RQm9xVTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_qR62oSe3, 0, m, &cVar_qR62oSe3_sendMessage);
}

void Heavy_SoundScraper::cMsg_gKzCKLwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_qR62oSe3, 0, m, &cVar_qR62oSe3_sendMessage);
}

void Heavy_SoundScraper::cPack_vPYbmP5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cvyMS33C_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_Ef46yxKZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vPYbmP5A, 0, m, &cPack_vPYbmP5A_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YtjMuoFe_sendMessage);
}

void Heavy_SoundScraper::cBinop_YtjMuoFe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_dvnmb8Os_sendMessage);
}

void Heavy_SoundScraper::cBinop_dvnmb8Os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ef46yxKZ, 1, m, &cVar_Ef46yxKZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_c0WwBOzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_fkijfhUU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_hEIWqpti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ef46yxKZ, 0, m, &cVar_Ef46yxKZ_sendMessage);
}

void Heavy_SoundScraper::cCast_BsprpFg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vPYbmP5A, 1, m, &cPack_vPYbmP5A_sendMessage);
}

void Heavy_SoundScraper::cVar_VR9B4aGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_gppboioT_sendMessage);
  cSend_N1R6vtn2_sendMessage(_c, 0, m);
  cSwitchcase_1VVgBE17_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_gppboioT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VR9B4aGA, 1, m, &cVar_VR9B4aGA_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_tOpTw103_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3lYKS7dh_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_3lYKS7dh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aedLRuXK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_1qFmMXPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tXvT6cHz, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_QS2UsFm3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_akHRQzX4, 0, m, &cSlice_akHRQzX4_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_gyBM6ebi, 0, m, &cRandom_gyBM6ebi_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_ozC2iEvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_oOwGv4QP_sendMessage);
}

void Heavy_SoundScraper::cUnop_oOwGv4QP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 25.0f, 0, m, &cBinop_WAfWxD2Y_sendMessage);
}

void Heavy_SoundScraper::cRandom_gyBM6ebi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 30.0f, 0, m, &cBinop_ozC2iEvw_sendMessage);
}

void Heavy_SoundScraper::cSlice_akHRQzX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_gyBM6ebi, 1, m, &cRandom_gyBM6ebi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_BCXxR3de_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ed7rsCsY, 0, m, &cSlice_Ed7rsCsY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dVT8QAlf, 0, m, &cRandom_dVT8QAlf_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_wMCR590d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_8DbbfMLV_sendMessage);
}

void Heavy_SoundScraper::cUnop_8DbbfMLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_vorGFxRW_sendMessage);
}

void Heavy_SoundScraper::cRandom_dVT8QAlf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_wMCR590d_sendMessage);
}

void Heavy_SoundScraper::cSlice_Ed7rsCsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dVT8QAlf, 1, m, &cRandom_dVT8QAlf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_87EVufwR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_EriH71xy, 0, m, &cSlice_EriH71xy_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cWTNAlVK, 0, m, &cRandom_cWTNAlVK_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_oJLqw30d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sWmjFI2K_sendMessage);
}

void Heavy_SoundScraper::cUnop_sWmjFI2K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_e7SVF7hq_sendMessage);
}

void Heavy_SoundScraper::cRandom_cWTNAlVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_oJLqw30d_sendMessage);
}

void Heavy_SoundScraper::cSlice_EriH71xy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cWTNAlVK, 1, m, &cRandom_cWTNAlVK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_WAfWxD2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TrfjDPTv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_vorGFxRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2Ko34Yot_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_e7SVF7hq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4AlJ7dRy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_elBKNIys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gileWk3u_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_A6UYcbH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QS2UsFm3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_OVA4AoXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_87EVufwR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_S1Od6ekR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BCXxR3de_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_gileWk3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_lAKLKWU0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_lAKLKWU0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ucMXPHax_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_4AlJ7dRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gGZK9Zx3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_2Ko34Yot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pqaxcsox_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_TrfjDPTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6gdkdXmT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_XiCwkoYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_39cpSX0E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_NQBM3Stm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w7Gkdxiw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wWR8ZDyV_sendMessage);
}

void Heavy_SoundScraper::cIf_zgftVSZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_30GP82vX_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_QNApGtJx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_qMhRetE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_LvHjudKK_sendMessage);
}

void Heavy_SoundScraper::cBinop_QNApGtJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_qMhRetE3_sendMessage);
}

void Heavy_SoundScraper::cBinop_LvHjudKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_9EeRnuMH_sendMessage);
}

void Heavy_SoundScraper::cBinop_9EeRnuMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TimsKYLv, 0, m, &cVar_TimsKYLv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ul3XBQST, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ul3XBQST_sendMessage);
}

void Heavy_SoundScraper::cCast_w7Gkdxiw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_1Jo3QnvR_sendMessage);
}

void Heavy_SoundScraper::cCast_wWR8ZDyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zgftVSZD, 0, m, &cIf_zgftVSZD_sendMessage);
}

void Heavy_SoundScraper::cBinop_1Jo3QnvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zgftVSZD, 1, m, &cIf_zgftVSZD_sendMessage);
}

void Heavy_SoundScraper::cMsg_30GP82vX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_TimsKYLv, 0, m, &cVar_TimsKYLv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ul3XBQST, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ul3XBQST_sendMessage);
}

void Heavy_SoundScraper::cVar_TimsKYLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_6Si4Js7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ul3XBQST, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ul3XBQST_sendMessage);
}

void Heavy_SoundScraper::cBinop_mGEd0VaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XiCwkoYX, 0, m, &cVar_XiCwkoYX_sendMessage);
}

void Heavy_SoundScraper::cBinop_gPbkUK46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mGEd0VaN, HV_BINOP_ADD, 1, m, &cBinop_mGEd0VaN_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ul3XBQST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mGEd0VaN, HV_BINOP_ADD, 0, m, &cBinop_mGEd0VaN_sendMessage);
}

void Heavy_SoundScraper::cSend_39cpSX0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SOshemBf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_1VVgBE17_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RVevB0cJ, 0, m, &cSlice_RVevB0cJ_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1VY1pW7P, 0, m, &cSlice_1VY1pW7P_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_RVevB0cJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u5N5l84z_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u5N5l84z_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_1VY1pW7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hox3lov1_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hox3lov1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_uyogWhQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tDax3soW, HV_BINOP_SUBTRACT, 1, m, &cBinop_tDax3soW_sendMessage);
}

void Heavy_SoundScraper::cMsg_d4eL8oSg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uyogWhQR_sendMessage);
}

void Heavy_SoundScraper::cBinop_tDax3soW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_beeIGorf, HV_BINOP_DIVIDE, 0, m, &cBinop_beeIGorf_sendMessage);
}

void Heavy_SoundScraper::cSystem_iaynbq3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tDax3soW, HV_BINOP_SUBTRACT, 0, m, &cBinop_tDax3soW_sendMessage);
}

void Heavy_SoundScraper::cMsg_Wg1ewRLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iaynbq3u_sendMessage);
}

void Heavy_SoundScraper::cBinop_beeIGorf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mJmhlyIE, HV_BINOP_SUBTRACT, 1, m, &cBinop_mJmhlyIE_sendMessage);
}

void Heavy_SoundScraper::cSystem_gspzETKb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6fn4OxgY_sendMessage);
}

void Heavy_SoundScraper::cMsg_bjtEBgeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gspzETKb_sendMessage);
}

void Heavy_SoundScraper::cBinop_6fn4OxgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_beeIGorf, HV_BINOP_DIVIDE, 1, m, &cBinop_beeIGorf_sendMessage);
}

void Heavy_SoundScraper::cSlice_CTxXPBj5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_E6GNgdTe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_VRSRcpQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_e5DBPx3j_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_JQZEEQiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_L6nYYdte, 0, m, &cSlice_L6nYYdte_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_F6XnlqA1, 0, m, &cSlice_F6XnlqA1_sendMessage);
}

void Heavy_SoundScraper::cVar_29O6GnF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FlRID4nF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_jJydvFt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_29O6GnF2, 0, m, &cVar_29O6GnF2_sendMessage);
}

void Heavy_SoundScraper::cMsg_FlRID4nF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_CTxXPBj5, 0, m, &cSlice_CTxXPBj5_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VRSRcpQZ, 0, m, &cSlice_VRSRcpQZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_e5DBPx3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JQZEEQiT, 0, m, &cPack_JQZEEQiT_sendMessage);
}

void Heavy_SoundScraper::cBinop_E6GNgdTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JQZEEQiT, 1, m, &cPack_JQZEEQiT_sendMessage);
}

void Heavy_SoundScraper::cMsg_W3o2D9oF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 22050.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_29O6GnF2, 1, m, &cVar_29O6GnF2_sendMessage);
}

void Heavy_SoundScraper::cVar_FRxeL5KK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kceOqLfC, 0, m, &cIf_kceOqLfC_sendMessage);
}

void Heavy_SoundScraper::cPack_fq06Iz3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_D7XPJonl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_L6nYYdte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_fq06Iz3C, 1, m, &cPack_fq06Iz3C_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_F6XnlqA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_wzEEZdfo, HV_BINOP_ADD, 0, m, &cBinop_wzEEZdfo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_wzEEZdfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fq06Iz3C, 0, m, &cPack_fq06Iz3C_sendMessage);
}

void Heavy_SoundScraper::cBinop_XEv9kq9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UImHnzDQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_UImHnzDQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_UImHnzDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wzEEZdfo, HV_BINOP_ADD, 1, m, &cBinop_wzEEZdfo_sendMessage);
}

void Heavy_SoundScraper::cVar_giCNzmUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GgI1AXfE, HV_BINOP_MULTIPLY, 0, m, &cBinop_GgI1AXfE_sendMessage);
}

void Heavy_SoundScraper::cMsg_5HudBzbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FGAXQAau_sendMessage);
}

void Heavy_SoundScraper::cSystem_FGAXQAau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Korap014_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_GgI1AXfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zNPyU0Sh_sendMessage);
}

void Heavy_SoundScraper::cBinop_hS6vG9bg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GgI1AXfE, HV_BINOP_MULTIPLY, 1, m, &cBinop_GgI1AXfE_sendMessage);
}

void Heavy_SoundScraper::cMsg_Korap014_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_hS6vG9bg_sendMessage);
}

void Heavy_SoundScraper::cBinop_zNPyU0Sh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mct9uWIJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_mct9uWIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KzPRjHrS_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Aadb4l2X, m);
}

void Heavy_SoundScraper::cBinop_KzPRjHrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Rhu2jWWN, m);
}

void Heavy_SoundScraper::cSwitchcase_bm3RV5LI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ZoFM2Ndy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ZoFM2Ndy_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Q532gYa7, 1, m, &cDelay_Q532gYa7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9HrFyjJr_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_Q532gYa7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Q532gYa7, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CEacn8V2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mlLxR9rU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z6TH2U8l_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YeNyorn4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cHQUOTPY_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZoFM2Ndy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q532gYa7, 0, m, &cDelay_Q532gYa7_sendMessage);
}

void Heavy_SoundScraper::cCast_9HrFyjJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q532gYa7, 0, m, &cDelay_Q532gYa7_sendMessage);
}

void Heavy_SoundScraper::cIf_kceOqLfC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_bm3RV5LI_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_CebpklYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_bm3RV5LI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_kWrTBhtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_kceOqLfC, 1, m, &cIf_kceOqLfC_sendMessage);
}

void Heavy_SoundScraper::cMsg_GobVcmI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_kceOqLfC, 1, m, &cIf_kceOqLfC_sendMessage);
}

void Heavy_SoundScraper::cCast_5YxDJmK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CEacn8V2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mlLxR9rU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z6TH2U8l_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YeNyorn4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cHQUOTPY_sendMessage);
}

void Heavy_SoundScraper::cCast_hRRITxoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kWrTBhtA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_eX17bbZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GobVcmI5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ApcIDI19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CebpklYx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_0iFaIPlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_Kdk3VNaS_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ZMx4KMfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_UzYeri3n_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_a3gc7GXl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GtvdlRvP, 0, m, &cSlice_GtvdlRvP_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_FVq8r9Ju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gJUhFmHt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_MeK80wNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_NPcR76cH_sendMessage);
}

void Heavy_SoundScraper::cBinop_NPcR76cH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cs71lYng, m);
}

void Heavy_SoundScraper::cMsg_gJUhFmHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MeK80wNW_sendMessage);
}

void Heavy_SoundScraper::cSlice_GtvdlRvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_MBtSkfgm, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_m5nbA8ZB, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_FVq8r9Ju, 0, m, &cVar_FVq8r9Ju_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_IVOfUJuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_a3gc7GXl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_7BBPR5k7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_61svUy2C, 0, m, &cSlice_61svUy2C_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_XiZnQO8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OvnJulvQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_vYknkhct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_TSJlPSSF_sendMessage);
}

void Heavy_SoundScraper::cBinop_TSJlPSSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_D9yO6SqW, m);
}

void Heavy_SoundScraper::cMsg_OvnJulvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vYknkhct_sendMessage);
}

void Heavy_SoundScraper::cSlice_61svUy2C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_gdL4Gw2I, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_fFaWN2KY, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_XiZnQO8V, 0, m, &cVar_XiZnQO8V_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_U3xeTycp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_7BBPR5k7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_9ndE94Oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IQPif8Or, HV_BINOP_DIVIDE, 0, m, &cBinop_IQPif8Or_sendMessage);
}

void Heavy_SoundScraper::cCast_OhFFbjh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qlF52Tsp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_nBLPemwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ndE94Oq, HV_BINOP_POW, 1, m, &cBinop_9ndE94Oq_sendMessage);
}

void Heavy_SoundScraper::cMsg_qlF52Tsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ndE94Oq, HV_BINOP_POW, 0, m, &cBinop_9ndE94Oq_sendMessage);
}

void Heavy_SoundScraper::cCast_w7OnEWhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IQPif8Or, HV_BINOP_DIVIDE, 1, m, &cBinop_IQPif8Or_sendMessage);
}

void Heavy_SoundScraper::cCast_VKuEhVJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IQPif8Or, HV_BINOP_DIVIDE, 0, m, &cBinop_IQPif8Or_sendMessage);
}

void Heavy_SoundScraper::cBinop_IQPif8Or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_inmxr9Es, 0, m);
}

void Heavy_SoundScraper::cBinop_3jbB4Ww9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nBLPemwR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OhFFbjh7_sendMessage);
}

void Heavy_SoundScraper::cMsg_HEIFfkux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_U5aoUlWc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_U5aoUlWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SOshemBf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_jFINYQso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gGZK9Zx3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_YSDWuT4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5.0f);
  cSend_jFINYQso_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_VSPuSxqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_3XDL4Nwz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_3XDL4Nwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_15wD6EWi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Xn9yGdNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ycejFgDK_sendMessage);
}

void Heavy_SoundScraper::cBinop_ycejFgDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_WcIUsbjX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_lmGYuRGq_sendMessage);
}

void Heavy_SoundScraper::cVar_nN9tPd0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ckjNzghO_sendMessage);
}

void Heavy_SoundScraper::cMsg_mU7w4yjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yn36cIbE_sendMessage);
}

void Heavy_SoundScraper::cSystem_yn36cIbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IB4pmMdm, HV_BINOP_DIVIDE, 1, m, &cBinop_IB4pmMdm_sendMessage);
}

void Heavy_SoundScraper::cBinop_WcIUsbjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Uq4KMSjV_sendMessage);
}

void Heavy_SoundScraper::cBinop_Uq4KMSjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_d0vENQWV, m);
}

void Heavy_SoundScraper::cMsg_PB8fwQgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_9fbfE8gm_sendMessage);
}

void Heavy_SoundScraper::cBinop_9fbfE8gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Xn9yGdNX_sendMessage);
}

void Heavy_SoundScraper::cBinop_lmGYuRGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sfkqaYZr, m);
}

void Heavy_SoundScraper::cBinop_ckjNzghO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_L9DPHDav_sendMessage);
}

void Heavy_SoundScraper::cBinop_L9DPHDav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IB4pmMdm, HV_BINOP_DIVIDE, 0, m, &cBinop_IB4pmMdm_sendMessage);
}

void Heavy_SoundScraper::cBinop_IB4pmMdm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PB8fwQgT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_nbQrlOZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TblnXtqh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_SBOWG3Fr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CiThLe76_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_vr8VHjMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Yc1K0Vrg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Qih3PPtv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3jTQCeXz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_vCWVgLfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ucMXPHax_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_xlYZVVlk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_slmKlCCr_sendMessage);
}

void Heavy_SoundScraper::cBinop_slmKlCCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1qFmMXPY, 0, m, &cPack_1qFmMXPY_sendMessage);
}

void Heavy_SoundScraper::cSend_aedLRuXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3jTQCeXz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_N1R6vtn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_QgqJxhma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YBitqehK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_MfHcLtxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2r7xUzy0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_u5N5l84z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_QgqJxhma_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Hox3lov1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MfHcLtxE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_mJmhlyIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gdDpk8qV_sendMessage);
}

void Heavy_SoundScraper::cCast_PUxwwfhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bjtEBgeb_sendMessage(_c, 0, m);
  cMsg_Wg1ewRLd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_rOZ1v2Zr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mJmhlyIE, HV_BINOP_SUBTRACT, 0, m, &cBinop_mJmhlyIE_sendMessage);
}

void Heavy_SoundScraper::cBinop_gdDpk8qV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kceOqLfC, 0, m, &cIf_kceOqLfC_sendMessage);
}

void Heavy_SoundScraper::cMsg_O83SH34N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_L6nYYdte, 0, m, &cSlice_L6nYYdte_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_F6XnlqA1, 0, m, &cSlice_F6XnlqA1_sendMessage);
}

void Heavy_SoundScraper::cBinop_bNw5WAVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PUxwwfhL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rOZ1v2Zr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FRxeL5KK, 1, m, &cVar_FRxeL5KK_sendMessage);
}

void Heavy_SoundScraper::cMsg_T0EWtrbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_PCZzQFIN, m);
}

void Heavy_SoundScraper::cMsg_HODFBNJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_PCZzQFIN, m);
}

void Heavy_SoundScraper::cSend_D7XPJonl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IqB45mIO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ZaLyKOgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_tK764FaY, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_cHQUOTPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_29O6GnF2, 0, m, &cVar_29O6GnF2_sendMessage);
}

void Heavy_SoundScraper::cCast_CEacn8V2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d4eL8oSg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_z6TH2U8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_YeNyorn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O83SH34N_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_mlLxR9rU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FRxeL5KK, 0, m, &cVar_FRxeL5KK_sendMessage);
}

void Heavy_SoundScraper::cSend_UzYeri3n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zJX3xpTq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Kdk3VNaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eFYzkyhx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_CKclqPlp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vW8Kk8Ax_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_vW8Kk8Ax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_I3z2BxtX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_SjLFk3Hz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6UjiG4f1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b2tR9Wvr_sendMessage);
}

void Heavy_SoundScraper::cCast_6UjiG4f1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XdtmvEEt, HV_BINOP_MULTIPLY, 1, m, &cBinop_XdtmvEEt_sendMessage);
}

void Heavy_SoundScraper::cCast_b2tR9Wvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XdtmvEEt, HV_BINOP_MULTIPLY, 0, m, &cBinop_XdtmvEEt_sendMessage);
}

void Heavy_SoundScraper::cBinop_XdtmvEEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GRbI5jFh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_GRbI5jFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UUHXKUVu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_yQvyZ5yW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_HHfueTlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_uqWqV2XU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_nF3TUztb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_ywMVMBCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_pydTeLcN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_YeG6wFB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PVrbPH0R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_r4jsSSPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wMkUngD4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_9qX1pDTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_TpMsYyLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "marimba");
  msg_setFloat(m, 1, 264.0f);
  cSend_NT7wPWVt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Zu9cBYaU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "xylo");
  msg_setFloat(m, 1, 2116.9f);
  cSend_NT7wPWVt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_k5xbTlT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "almglocken");
  msg_setFloat(m, 1, 525.57f);
  cSend_NT7wPWVt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_c01s3Jxt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "bowl");
  msg_setFloat(m, 1, 705.52f);
  cSend_NT7wPWVt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_w8uDsb0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "gong");
  msg_setFloat(m, 1, 179.88f);
  cSend_NT7wPWVt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_NT7wPWVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QxRcqbot_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_9pPf9ahL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "crotale");
  msg_setFloat(m, 1, 1058.39f);
  cSend_NT7wPWVt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_n6dvrW5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XfqfhTEv_onMessage(_c, NULL, 0, m, NULL);
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
}

void Heavy_SoundScraper::cReceive_f0YE5p9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UsBXIOXN_sendMessage(_c, 0, m);
  cMsg_jikoL51z_sendMessage(_c, 0, m);
  cMsg_js8R4W8c_sendMessage(_c, 0, m);
  cMsg_0Ln1WGLY_sendMessage(_c, 0, m);
  cMsg_Ko7ndIwg_sendMessage(_c, 0, m);
  cMsg_9vhBhgTe_sendMessage(_c, 0, m);
  cMsg_IpI5NVPt_sendMessage(_c, 0, m);
  cMsg_4LH76Q3J_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3nW7GnM9, 0, m, &cVar_3nW7GnM9_sendMessage);
  cMsg_iM5IhmZA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9qBCLUOw, 0, m, &cVar_9qBCLUOw_sendMessage);
  cMsg_6Vfgj3vc_sendMessage(_c, 0, m);
  cMsg_ZRpryZYY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Q91BSv1o, 0, m, &cVar_Q91BSv1o_sendMessage);
  cMsg_woSD1C87_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RCkRsSmF, 0, m, &cVar_RCkRsSmF_sendMessage);
  cMsg_NZgTeq96_sendMessage(_c, 0, m);
  cMsg_DQzEeojE_sendMessage(_c, 0, m);
  cMsg_9mL9boCE_sendMessage(_c, 0, m);
  cMsg_mkHwuo7g_sendMessage(_c, 0, m);
  cMsg_Kx62RuA7_sendMessage(_c, 0, m);
  cMsg_dJelF5Zp_sendMessage(_c, 0, m);
  cMsg_ftsx0l4d_sendMessage(_c, 0, m);
  cMsg_LJu9jxo0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IzyJ7Xer, 0, m, &cVar_IzyJ7Xer_sendMessage);
  cMsg_6CEqGZ93_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aLua7DGo, 0, m, &cVar_aLua7DGo_sendMessage);
  cMsg_krmBsZyO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PgiNjOQl, 0, m, &cVar_PgiNjOQl_sendMessage);
  cMsg_gvyFe5zz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MllDaIjH, 0, m, &cVar_MllDaIjH_sendMessage);
  cMsg_9OR8acZE_sendMessage(_c, 0, m);
  cMsg_OVuar3mC_sendMessage(_c, 0, m);
  cMsg_EoiDpUAy_sendMessage(_c, 0, m);
  cMsg_UmbK0JI4_sendMessage(_c, 0, m);
  cMsg_skRUoGjq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_K3XIB8AC, 0, m, &cVar_K3XIB8AC_sendMessage);
  cMsg_jQU1h1jE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mw7R4dMK, 0, m, &cVar_mw7R4dMK_sendMessage);
  cMsg_cgDTZ2jN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0mLgCZJk, 0, m, &cVar_0mLgCZJk_sendMessage);
  cMsg_AvDUY6oh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aTuR5bEy, 0, m, &cVar_aTuR5bEy_sendMessage);
  cMsg_i2bN2laE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dfnvLIfx, 0, m, &cVar_dfnvLIfx_sendMessage);
  cMsg_hEzx02Y3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lYayMnfr, 0, m, &cVar_lYayMnfr_sendMessage);
  cMsg_bvr5zjb0_sendMessage(_c, 0, m);
  cMsg_TxrINUoV_sendMessage(_c, 0, m);
  cMsg_AtohvImR_sendMessage(_c, 0, m);
  cMsg_qCnAnZ4R_sendMessage(_c, 0, m);
  cMsg_ZjRK45n5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ik3F8Xlw, 0, m, &cVar_ik3F8Xlw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bZuQslVf, 0, m, &cVar_bZuQslVf_sendMessage);
  cMsg_JCc8Zrdk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_onsg4u3h, 0, m, &cVar_onsg4u3h_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_N1f2HKgs, 0, m, &cVar_N1f2HKgs_sendMessage);
  cMsg_Ud8LnDuX_sendMessage(_c, 0, m);
  cMsg_Pk6yXC5M_sendMessage(_c, 0, m);
  cMsg_9Nl4GLXy_sendMessage(_c, 0, m);
  cMsg_COXID2By_sendMessage(_c, 0, m);
  cMsg_n5v1lewP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oLcsMzos, 0, m, &cVar_oLcsMzos_sendMessage);
  cMsg_gFj5VcGR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Vk3I88T4, 0, m, &cVar_Vk3I88T4_sendMessage);
  cMsg_VOQy1s5I_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oQTQwdD6, 0, m, &cVar_oQTQwdD6_sendMessage);
  cMsg_hfZLjphy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4nmbuxG1, 0, m, &cVar_4nmbuxG1_sendMessage);
  cMsg_ZQqc6tSC_sendMessage(_c, 0, m);
  cMsg_9Xq8ds0m_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NyeoSkPJ, 0, m, &cVar_NyeoSkPJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HpUQFnyS, 0, m, &cVar_HpUQFnyS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LyPTYrzF, 0, m, &cVar_LyPTYrzF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9xcwDih4, 0, m, &cVar_9xcwDih4_sendMessage);
  cMsg_ajd3G86K_sendMessage(_c, 0, m);
  cMsg_LyCTxcSt_sendMessage(_c, 0, m);
  cMsg_Q0ApGg4Y_sendMessage(_c, 0, m);
  cMsg_OEVjTKqf_sendMessage(_c, 0, m);
  cMsg_DmWp4NYA_sendMessage(_c, 0, m);
  cMsg_ZvWRWlMS_sendMessage(_c, 0, m);
  cMsg_udv19Yta_sendMessage(_c, 0, m);
  cMsg_eoXpKdxp_sendMessage(_c, 0, m);
  cMsg_1XcmSlqN_sendMessage(_c, 0, m);
  cMsg_0aehdU4i_sendMessage(_c, 0, m);
  cMsg_8REVD2pG_sendMessage(_c, 0, m);
  cMsg_DkxA2uqW_sendMessage(_c, 0, m);
  cMsg_9Ps5o61y_sendMessage(_c, 0, m);
  cMsg_PHN8opTO_sendMessage(_c, 0, m);
  cMsg_I3IoP9d1_sendMessage(_c, 0, m);
  cMsg_UPUylRRh_sendMessage(_c, 0, m);
  cMsg_KAV7ePwZ_sendMessage(_c, 0, m);
  cMsg_5HudBzbs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_giCNzmUp, 0, m, &cVar_giCNzmUp_sendMessage);
  cMsg_HEIFfkux_sendMessage(_c, 0, m);
  cMsg_YSDWuT4s_sendMessage(_c, 0, m);
  cMsg_VSPuSxqX_sendMessage(_c, 0, m);
  cMsg_mU7w4yjM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nN9tPd0Q, 0, m, &cVar_nN9tPd0Q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7N875SnD, 0, m, &cVar_7N875SnD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GDs39y5O, 0, m, &cVar_GDs39y5O_sendMessage);
  cMsg_qrAHQ1Ec_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mK8fl5jB, 0, m, &cVar_mK8fl5jB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3ImaLLeR, 0, m, &cVar_3ImaLLeR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Fdnkb8K0, 0, m, &cVar_Fdnkb8K0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_92ThOhVl, 0, m, &cVar_92ThOhVl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6G6VgaM3, 0, m, &cVar_6G6VgaM3_sendMessage);
  cMsg_1DBhwmy4_sendMessage(_c, 0, m);
  cMsg_2F7LPkwR_sendMessage(_c, 0, m);
  cMsg_6aDLlMsS_sendMessage(_c, 0, m);
  cMsg_yWBHVUKU_sendMessage(_c, 0, m);
  cMsg_IcCrIP5v_sendMessage(_c, 0, m);
  cMsg_5N6aX30V_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RvvO72sl, 0, m, &cVar_RvvO72sl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1Uizhf61, 0, m, &cVar_1Uizhf61_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cARKryah, 0, m, &cVar_cARKryah_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HoDE51UV, 0, m, &cVar_HoDE51UV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_j1yecy4h, 0, m, &cVar_j1yecy4h_sendMessage);
  cMsg_c0WwBOzx_sendMessage(_c, 0, m);
  cSend_Qih3PPtv_sendMessage(_c, 0, m);
  cMsg_Zu9cBYaU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PN001S4G, 0, m, &cVar_PN001S4G_sendMessage);
  cMsg_SiNFlWS2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uzhe3rDr, 0, m, &cVar_uzhe3rDr_sendMessage);
  cMsg_Edquf7OW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_N1bIU3am, 0, m, &cVar_N1bIU3am_sendMessage);
  cMsg_cFTATF4T_sendMessage(_c, 0, m);
  cMsg_gAwgj97C_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_N2NHHKUW, 0, m, &cVar_N2NHHKUW_sendMessage);
  cMsg_mWX9MKIs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Qh2iF1Sj, 0, m, &cTabhead_Qh2iF1Sj_sendMessage);
  cMsg_mtiO4wsn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_91mfJLLA, 0, m, &cVar_91mfJLLA_sendMessage);
  cMsg_ejGWhZxr_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_cEOFa9Kl, 0, m, &cTabhead_cEOFa9Kl_sendMessage);
  cMsg_SzwfSrhe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Pmrs8wcP, 0, m, &cVar_Pmrs8wcP_sendMessage);
  cMsg_r2sWfSAD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bp9JVud4, 0, m, &cTabhead_bp9JVud4_sendMessage);
  cMsg_qCRjN7Jg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SsZVtlwB, 0, m, &cVar_SsZVtlwB_sendMessage);
  cMsg_Y8Mf70P7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lPUxqSYh, 0, m, &cTabhead_lPUxqSYh_sendMessage);
  cMsg_7q6G626q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3uYo4STR, 0, m, &cVar_3uYo4STR_sendMessage);
  cMsg_St1eStOz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_F4qsxLkm, 0, m, &cTabhead_F4qsxLkm_sendMessage);
  cMsg_ctAi9Ryc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_g3v5JQlq, 0, m, &cVar_g3v5JQlq_sendMessage);
  cMsg_sQWS6Teh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_khqdUWnu, 0, m, &cTabhead_khqdUWnu_sendMessage);
  cMsg_EHEc4dyb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7aLtqAgc, 0, m, &cVar_7aLtqAgc_sendMessage);
  cMsg_XYNQrn0o_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uIOqhkAA, 0, m, &cTabhead_uIOqhkAA_sendMessage);
  cMsg_E0bDPZ2g_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Eu2qxh1r, 0, m, &cVar_Eu2qxh1r_sendMessage);
  cMsg_IV70i7g4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Mf40FuaB, 0, m, &cTabhead_Mf40FuaB_sendMessage);
  cMsg_oPpCtap5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zKXoFiBq, 0, m, &cVar_zKXoFiBq_sendMessage);
  cMsg_o7AoDe42_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5PQzVi2C, 0, m, &cTabhead_5PQzVi2C_sendMessage);
  cMsg_1RqJzBCX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6PvHlScG, 0, m, &cVar_6PvHlScG_sendMessage);
  cMsg_bl35mNsD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QDoPWXEB, 0, m, &cTabhead_QDoPWXEB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_h96QIkIW, 0, m, &cVar_h96QIkIW_sendMessage);
  cMsg_zE21Z3zY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0fGqAmpX, 0, m, &cVar_0fGqAmpX_sendMessage);
  cMsg_OET0V7Rp_sendMessage(_c, 0, m);
  cMsg_Cen8fV9g_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pzN1VgPd, 0, m, &cVar_pzN1VgPd_sendMessage);
  cMsg_0Psu2AJ9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_c6Jwn46d, 0, m, &cTabhead_c6Jwn46d_sendMessage);
  cMsg_eFoEbJCa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MjHcADru, 0, m, &cVar_MjHcADru_sendMessage);
  cMsg_U9Lo1R0U_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_49cxCtzA, 0, m, &cTabhead_49cxCtzA_sendMessage);
  cMsg_9WDWwcAO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yqo9LDLw, 0, m, &cVar_yqo9LDLw_sendMessage);
  cMsg_2at2Fisj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_aauTwDH1, 0, m, &cTabhead_aauTwDH1_sendMessage);
  cMsg_h1BSVTaq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_v72dRMLm, 0, m, &cVar_v72dRMLm_sendMessage);
  cMsg_klszmtM9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QeTufyKk, 0, m, &cTabhead_QeTufyKk_sendMessage);
  cMsg_0EsukddP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FoxtFCsc, 0, m, &cVar_FoxtFCsc_sendMessage);
  cMsg_FXjyMeem_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GNqInCF0, 0, m, &cTabhead_GNqInCF0_sendMessage);
  cMsg_jhUWyleh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nUy2aM88, 0, m, &cVar_nUy2aM88_sendMessage);
  cMsg_MUJ21bs4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ARHN8UiJ, 0, m, &cTabhead_ARHN8UiJ_sendMessage);
  cMsg_vpbI0UTK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_d3apkzzx, 0, m, &cVar_d3apkzzx_sendMessage);
  cMsg_5C8feYRC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_XL8xQ3x9, 0, m, &cTabhead_XL8xQ3x9_sendMessage);
  cMsg_xKODkgIT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Adh4yrss, 0, m, &cVar_Adh4yrss_sendMessage);
  cMsg_h444TC4a_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8WCi2ini, 0, m, &cTabhead_8WCi2ini_sendMessage);
  cMsg_exxuU9kf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_reMorDrL, 0, m, &cVar_reMorDrL_sendMessage);
  cMsg_XA3xsssM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZNB2PqhN, 0, m, &cTabhead_ZNB2PqhN_sendMessage);
  cMsg_uHzoidow_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hiEceA0Z, 0, m, &cVar_hiEceA0Z_sendMessage);
  cMsg_Y7VE1YvP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qxjHhATg, 0, m, &cTabhead_qxjHhATg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iP0oz6Bp, 0, m, &cVar_iP0oz6Bp_sendMessage);
  cMsg_75ogWp0e_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0wY2A44e, 0, m, &cVar_0wY2A44e_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fetpSVOz, 0, m, &cVar_fetpSVOz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LUiodfWo, 0, m, &cVar_LUiodfWo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KmmEqxwI, 0, m, &cVar_KmmEqxwI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FVq8r9Ju, 0, m, &cVar_FVq8r9Ju_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XiZnQO8V, 0, m, &cVar_XiZnQO8V_sendMessage);
}

void Heavy_SoundScraper::cReceive_7n5YxE2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_gF56NqnA, 0, m, &cSlice_gF56NqnA_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_3Bx5Ot5o, 0, m, &cSlice_3Bx5Ot5o_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Kock4fG4, 0, m, &cSlice_Kock4fG4_sendMessage);
}

void Heavy_SoundScraper::cReceive_PVrbPH0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rrZ8MHv4, 0, m, &cPack_rrZ8MHv4_sendMessage);
}

void Heavy_SoundScraper::cReceive_wMkUngD4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rrZ8MHv4, 1, m, &cPack_rrZ8MHv4_sendMessage);
}

void Heavy_SoundScraper::cReceive_DrOgteuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SBOWG3Fr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_zJzFHEKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lEBaoPDW_sendMessage);
}

void Heavy_SoundScraper::cReceive_X3udhRta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nbQrlOZa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_niF7XuyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RsHiST2H_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wpyH6AmL_sendMessage);
}

void Heavy_SoundScraper::cReceive_QxRcqbot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_jHtbTf4Z, 0, m, &cSlice_jHtbTf4Z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_S1nYIyAR, 0, m, &cSlice_S1nYIyAR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_pvmdHmBX, 0, m, &cSlice_pvmdHmBX_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_smuPsA0X, 0, m, &cSlice_smuPsA0X_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_A935J5Rc, 0, m, &cSlice_A935J5Rc_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DFZ2omn1, 0, m, &cSlice_DFZ2omn1_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BgzNrejB, 0, m, &cSlice_BgzNrejB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QwMwSmiR, 0, m, &cSlice_QwMwSmiR_sendMessage);
  cSend_vr8VHjMO_sendMessage(_c, 0, m);
  cPrint_onMessage(_c, m, "SCRAPE_SAMPLE");
}

void Heavy_SoundScraper::cReceive_A9k3CmNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tOpTw103_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_VR9B4aGA, 0, m, &cVar_VR9B4aGA_sendMessage);
}

void Heavy_SoundScraper::cReceive_5BHtA12B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vCWVgLfg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_m0442LZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Qih3PPtv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_lKveBJ2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_hVYy6fcl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_TLd92gz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J8TVZyOD, 0, m, &cVar_J8TVZyOD_sendMessage);
}

void Heavy_SoundScraper::cReceive_AaWmRax8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UKO34jxE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_74uyxlTn_sendMessage);
}

void Heavy_SoundScraper::cReceive_gZ47smmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jCxTCrsf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5b34eS4P_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_c2NkkjaU, 0, m, &cPack_c2NkkjaU_sendMessage);
}

void Heavy_SoundScraper::cReceive_eo1PcGuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0KP4RwC6, 1, m, &cVar_0KP4RwC6_sendMessage);
}

void Heavy_SoundScraper::cReceive_D2UulC8D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h329csiO, HV_BINOP_DIVIDE, 1, m, &cBinop_h329csiO_sendMessage);
}

void Heavy_SoundScraper::cReceive_Sf3UlUDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_U55ybgJi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_2JZ1aDEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YVBzKLSE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_vCZ4Geg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_egh9POsS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_3wfboKgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_w6BsjLj9, 1, m, &cVar_w6BsjLj9_sendMessage);
}

void Heavy_SoundScraper::cReceive_9u2Q2WoU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jZq37lLx, m);
}

void Heavy_SoundScraper::cReceive_jFb8uooI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_f5d8zUwC, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_pvFnIqYn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_IZFTWrFD, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_RMOmIDKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7Iizq8sj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_Nk1J8C1t_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_PpNxvSHO_sendMessage);
}

void Heavy_SoundScraper::cReceive_prsoxjPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K5pElOWy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rws0a6nl_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_f5d8zUwC, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_puIdtWvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_520XZmHp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cmXaLuWV_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_OP1LMVvU, 1, m, &cPack_OP1LMVvU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KqLkayvZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dzYW7SJQ_sendMessage);
}

void Heavy_SoundScraper::cReceive_jl6EDOZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_u9EIWQp1, 1, m, &cPack_u9EIWQp1_sendMessage);
}

void Heavy_SoundScraper::cReceive_PtvZ02v0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eNLHIUzg, 1, m, &cVar_eNLHIUzg_sendMessage);
}

void Heavy_SoundScraper::cReceive_Toge1gW4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iajd5keQ, HV_BINOP_DIVIDE, 1, m, &cBinop_iajd5keQ_sendMessage);
}

void Heavy_SoundScraper::cReceive_evSV9zzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_b768iTNJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_kIvgwZr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GKbAc5LL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_kxA6XgNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_r4ePNcT6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_smFubyv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sYUxIteA, 1, m, &cVar_sYUxIteA_sendMessage);
}

void Heavy_SoundScraper::cReceive_hvGRZo4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cZfkr1FI, m);
}

void Heavy_SoundScraper::cReceive_KU8E2G8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ocH3PVC3, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_YoCPr1f9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6345v7Wq, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_IeJzihJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_28Pf50gP_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_YTqHVszK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_RTjNKR0P_sendMessage);
}

void Heavy_SoundScraper::cReceive_4LuN6Fly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RV51UVgP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LwSnvQl4_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_ocH3PVC3, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_s5Tb0AVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MBqAmoAO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cbdPZlRb_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_2vPS6pBV, 1, m, &cPack_2vPS6pBV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KdjOWqlG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RFTK4Nbo_sendMessage);
}

void Heavy_SoundScraper::cReceive_ENJVwLWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_anvmogl2, 1, m, &cPack_anvmogl2_sendMessage);
}

void Heavy_SoundScraper::cReceive_NauRnm0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tr8TAC6a, 1, m, &cVar_tr8TAC6a_sendMessage);
}

void Heavy_SoundScraper::cReceive_RkUj55iW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yaY5cQwn, HV_BINOP_DIVIDE, 1, m, &cBinop_yaY5cQwn_sendMessage);
}

void Heavy_SoundScraper::cReceive_gVT2TZRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4DeatsjZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_BxedxBrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Tmetfqpq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_UM41rwTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cYsIGyUU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_cB2KfVBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8g046wQ1, 1, m, &cVar_8g046wQ1_sendMessage);
}

void Heavy_SoundScraper::cReceive_1OPcUT1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RQBB2CYq, m);
}

void Heavy_SoundScraper::cReceive_jEcdTOnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_EUbnU3Vo, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_mXi5eudv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_DUoEC9ee, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_T0GteK6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eQZWzkir_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_c03ATzVi_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_hW3yQZBc_sendMessage);
}

void Heavy_SoundScraper::cReceive_heD1FoTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H53Ld2Rj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_je5oR4Ah_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_EUbnU3Vo, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_rUJpbPwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iYbm2woG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_94IHGqqX_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_7oDnoUMn, 1, m, &cPack_7oDnoUMn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Itu06abr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_beH50Voc_sendMessage);
}

void Heavy_SoundScraper::cReceive_x8W8go9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QmIC7Vfy, 1, m, &cPack_QmIC7Vfy_sendMessage);
}

void Heavy_SoundScraper::cReceive_hS1w2Z8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VvR1dAGz, 1, m, &cVar_VvR1dAGz_sendMessage);
}

void Heavy_SoundScraper::cReceive_b6DfmkFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9TKo4Ur, HV_BINOP_DIVIDE, 1, m, &cBinop_y9TKo4Ur_sendMessage);
}

void Heavy_SoundScraper::cReceive_L6C72N63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fXr5d8Bb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_6wgfSv1j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6iZWzfCj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_qbBmrEAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_iIGWw2XZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_yAdlsYH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_knmFkY2y, 1, m, &cVar_knmFkY2y_sendMessage);
}

void Heavy_SoundScraper::cReceive_UPeteCQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_06t8gV9x, m);
}

void Heavy_SoundScraper::cReceive_uAn9zqw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_U6KocVLC, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_Srs2QlbM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2iPDAcPG, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_PLCfMZBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kbJMmWBG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_JzXgoPit_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_JVRqjkE7_sendMessage);
}

void Heavy_SoundScraper::cReceive_nLU2i3AG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QiO6oqmm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ktEkFV4x_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_U6KocVLC, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_mGmxsbCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KleTJijS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fG0YqvAw_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_kQBalaVk, 1, m, &cPack_kQBalaVk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KbAas3mW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ulgOQNH3_sendMessage);
}

void Heavy_SoundScraper::cReceive_WpYvY7yr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_NPw7VWWX, 1, m, &cPack_NPw7VWWX_sendMessage);
}

void Heavy_SoundScraper::cReceive_HCy3hhFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XfqfhTEv_onMessage(_c, NULL, 0, m, NULL);
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
}

void Heavy_SoundScraper::cReceive_4leEx4mq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_U6cfhE15_sendMessage);
}

void Heavy_SoundScraper::cReceive_IunLi465_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0YI7NiCN, 0, m, &cVar_0YI7NiCN_sendMessage);
}

void Heavy_SoundScraper::cReceive_8UbtHlxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_An2zERQQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KeNsvscq_sendMessage);
}

void Heavy_SoundScraper::cReceive_kWMIetWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d8ZnlbDl, 0, m, &cVar_d8ZnlbDl_sendMessage);
}

void Heavy_SoundScraper::cReceive_HTiBNaQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P1utA5BO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bVWGltde_sendMessage);
}

void Heavy_SoundScraper::cReceive_puLT41M8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_Oyd1FXPW_sendMessage);
}

void Heavy_SoundScraper::cReceive_wF78PJdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fUAHW5ir, 0, m, &cVar_fUAHW5ir_sendMessage);
}

void Heavy_SoundScraper::cReceive_5i5AI5KQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvFGyLGP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jlybmkbc_sendMessage);
}

void Heavy_SoundScraper::cReceive_BP0cYOC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_LMrkgcEj_sendMessage);
}

void Heavy_SoundScraper::cReceive_3PkN71bX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9wZmOk49, 0, m, &cVar_9wZmOk49_sendMessage);
}

void Heavy_SoundScraper::cReceive_vgqqosdi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZRNc4WeH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eep6e3Qa_sendMessage);
}

void Heavy_SoundScraper::cReceive_zWW595pW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sLu2O4yb, 0, m, &cVar_sLu2O4yb_sendMessage);
}

void Heavy_SoundScraper::cReceive_OraqQrGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_T2P3x86I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kdv6B4DE_sendMessage);
}

void Heavy_SoundScraper::cReceive_TblnXtqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ul3XBQST, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ul3XBQST_sendMessage);
}

void Heavy_SoundScraper::cReceive_CiThLe76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xlYZVVlk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CDjeilGe, 0, m, &cVar_CDjeilGe_sendMessage);
}

void Heavy_SoundScraper::cReceive_Yc1K0Vrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_0iFaIPlS, 0, m, &cSlice_0iFaIPlS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ZMx4KMfI, 0, m, &cSlice_ZMx4KMfI_sendMessage);
}

void Heavy_SoundScraper::cReceive_3jTQCeXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_elBKNIys_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OVA4AoXw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A6UYcbH5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S1Od6ekR_sendMessage);
}

void Heavy_SoundScraper::cReceive_ucMXPHax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_gPbkUK46_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6Si4Js7P_sendMessage);
}

void Heavy_SoundScraper::cReceive_gGZK9Zx3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_CKclqPlp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XdtmvEEt, HV_BINOP_MULTIPLY, 0, m, &cBinop_XdtmvEEt_sendMessage);
}

void Heavy_SoundScraper::cReceive_pqaxcsox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 10.0f, 0, m, &cBinop_bNw5WAVP_sendMessage);
}

void Heavy_SoundScraper::cReceive_6gdkdXmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UImHnzDQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_UImHnzDQ_sendMessage);
}

void Heavy_SoundScraper::cReceive_SOshemBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_3jbB4Ww9_sendMessage);
}

void Heavy_SoundScraper::cReceive_eFYzkyhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NQBM3Stm, 0, m, &cVar_NQBM3Stm_sendMessage);
}

void Heavy_SoundScraper::cReceive_YBitqehK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hRRITxoC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5YxDJmK8_sendMessage);
  cMsg_T0EWtrbh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_2r7xUzy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eX17bbZ2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ApcIDI19_sendMessage);
  cMsg_HODFBNJv_sendMessage(_c, 0, m);
  cMsg_ZaLyKOgc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_15wD6EWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_29O6GnF2, 1, m, &cVar_29O6GnF2_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_XEv9kq9B_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_SjLFk3Hz_sendMessage);
}

void Heavy_SoundScraper::cReceive_IqB45mIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tK764FaY, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_zJX3xpTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IVOfUJuN_sendMessage(_c, 0, m);
  cMsg_U3xeTycp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_UUHXKUVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cReceive_I3z2BxtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w7OnEWhO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VKuEhVJx_sendMessage);
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
    __hv_varread_f(&sVarf_PCZzQFIN, VOf(Bf0));
    __hv_varread_f(&sVarf_Aadb4l2X, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Rhu2jWWN, VOf(Bf0));
    __hv_rpole_f(&sRPole_wIDQ6C6Z, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_tK764FaY, VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_inmxr9Es, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_del1_f(&sDel1_hIJtDmsi, VIf(Bf2), VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_amKviKQx, VIf(ZERO), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_del1_f(&sDel1_ATjOjaDZ, VIf(Bf2), VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_FkliRt2O, VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_cs71lYng, VOf(Bf5));
    __hv_min_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_MBtSkfgm, VIi(Bi1), VOf(Bf6));
    __hv_tabread_if(&sTabread_m5nbA8ZB, VIi(Bi0), VOf(Bf7));
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
    __hv_del1_f(&sDel1_2AGiVuMi, VIf(Bf4), VOf(Bf7));
    __hv_lt_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_samphold_f(&sSamphold_Qi9pzIqD, VIf(ZERO), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_del1_f(&sDel1_WdVty1oU, VIf(Bf4), VOf(Bf7));
    __hv_lt_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_samphold_f(&sSamphold_izQfT84g, VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_D9yO6SqW, VOf(Bf9));
    __hv_min_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_gdL4Gw2I, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_fFaWN2KY, VIi(Bi0), VOf(Bf5));
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
    __hv_varread_f(&sVarf_sfkqaYZr, VOf(Bf10));
    __hv_rpole_f(&sRPole_NpOYHH4D, VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_2cauPm0C, VIf(Bf10), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_d0vENQWV, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_tXvT6cHz, VOf(Bf0));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_f5d8zUwC, VOf(Bf10));
    __hv_varread_f(&sVarf_flsPbRxt, VOf(Bf3));
    __hv_min_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_5XEyxLUF, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_fwyz1fM4, VIi(Bi0), VOf(Bf8));
    __hv_sub_f(VIf(Bf5), VIf(Bf8), VOf(Bf5));
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_IZFTWrFD, VOf(Bf3));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_EQgeWPIP, VOf(Bf8));
    __hv_varread_f(&sVarf_jZq37lLx, VOf(Bf5));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_HtLLvVBA, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_f52ztb7P, VOf(Bf8));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_ocH3PVC3, VOf(Bf5));
    __hv_varread_f(&sVarf_nJvIRFux, VOf(Bf10));
    __hv_min_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Q8eCgjLK, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_RtoSlKmF, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf9));
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_6345v7Wq, VOf(Bf10));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_kj4HFN8n, VOf(Bf2));
    __hv_varread_f(&sVarf_cZfkr1FI, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_82VLZeYw, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_b6lztIzY, VOf(Bf2));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_EUbnU3Vo, VOf(Bf3));
    __hv_varread_f(&sVarf_aJR2wyXX, VOf(Bf9));
    __hv_min_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Yuwr9mH4, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_ar4OAyRU, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_DUoEC9ee, VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_YE8VdnqH, VOf(Bf11));
    __hv_varread_f(&sVarf_RQBB2CYq, VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_JnO3n7dX, VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_jQdRQLfi, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_U6KocVLC, VOf(Bf10));
    __hv_varread_f(&sVarf_3sId2lea, VOf(Bf5));
    __hv_min_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_8ZhUxK3H, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_JpeD1zqd, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf3), VIf(Bf7), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_2iPDAcPG, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_2bVg3iUv, VOf(Bf7));
    __hv_varread_f(&sVarf_06t8gV9x, VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_3PNAFvQS, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_UOTAVrEi, VOf(Bf7));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_bFszP7fh, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_mQrqDsTx, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf0));
    __hv_add_f(VIf(Bf11), VIf(Bf7), VOf(Bf11));
    __hv_line_f(&sLine_4zhPJk2l, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_JASCXvgB, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_OohGk3Ir, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_MCWLDrhL, VIf(Bf7));
    __hv_line_f(&sLine_PY90kPB2, VOf(Bf7));
    __hv_phasor_f(&sPhasor_Jqg70Oi2, VIf(Bf7), VOf(Bf7));
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
    __hv_line_f(&sLine_TLP1ZLXH, VOf(Bf4));
    __hv_line_f(&sLine_Sl3jLFYS, VOf(Bf11));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf11), VOf(Bf6));
    __hv_tabhead_f(&sTabhead_wS5HdcrQ, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf3), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_yYrneiOh, VOf(Bf10));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_K0vHWCYf, VOf(Bf6));
    __hv_min_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf3));
    __hv_varread_f(&sVarf_835RoTyx, VOf(Bf6));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_c0d74f60, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_xCBhyFkM, VIi(Bi0), VOf(Bf6));
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
    __hv_tabhead_f(&sTabhead_dvOKoNRm, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_LxAAAM9K, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_9KYbO0mX, VOf(Bf11));
    __hv_min_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf7));
    __hv_varread_f(&sVarf_1Rbyu1Lv, VOf(Bf11));
    __hv_zero_f(VOf(Bf13));
    __hv_lt_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_and_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_cast_fi(VIf(Bf13), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_JwDQeq3l, VIi(Bi1), VOf(Bf13));
    __hv_tabread_if(&sTabread_i6eBd8Qe, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf13));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf13), VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_pB9AS2GX, VOf(Bf6));
    __hv_tabhead_f(&sTabhead_UwpCsv8D, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf14), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_Q8Ak7iaw, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_s4Q9Jbe6, VOf(Bf6));
    __hv_min_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf14));
    __hv_varread_f(&sVarf_dlr9Ba7U, VOf(Bf6));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_C5sDjHkg, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_z70eyCVD, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf7), VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_LV0rKBrz, VOf(Bf14));
    __hv_rpole_f(&sRPole_LzynpEQc, VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_IIH3c9lw, VIf(Bf14), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_lXuvEeCN, VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_8MKDWaXg, VOf(Bf6));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf14));
    __hv_line_f(&sLine_htrZRFu9, VOf(Bf7));
    __hv_varread_f(&sVarf_AMaSOcaw, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_IoBKSN30, VOf(Bf6));
    __hv_rpole_f(&sRPole_vS9ig7qD, VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_nG1E8QsX, VIf(Bf6));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_tabread_f(&sTabread_nFsiV9AO, VOf(Bf14));
    __hv_varread_f(&sVarf_qUR4c4DW, VOf(Bf7));
    __hv_mul_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_dgefkAVN, VOf(Bf11));
    __hv_rpole_f(&sRPole_oeOv1VAI, VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf11), VIf(Bf14), VOf(Bf11));
    __hv_line_f(&sLine_NwAX0XzW, VOf(Bf7));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_9Nru90GF, VOf(Bf11));
    __hv_tabread_f(&sTabread_SoEfIq3Q, VOf(Bf1));
    __hv_add_f(VIf(Bf5), VIf(Bf1), VOf(Bf13));
    __hv_tabread_f(&sTabread_ByuHBIhT, VOf(Bf4));
    __hv_add_f(VIf(Bf13), VIf(Bf4), VOf(Bf3));
    __hv_tabread_f(&sTabread_lGiNSqRS, VOf(Bf15));
    __hv_add_f(VIf(Bf3), VIf(Bf15), VOf(Bf12));
    __hv_tabread_f(&sTabread_vUJLchAb, VOf(Bf9));
    __hv_add_f(VIf(Bf12), VIf(Bf9), VOf(Bf8));
    __hv_tabread_f(&sTabread_G8BLlR3M, VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_SZxDX6FQ, VIf(Bf16));
    __hv_sub_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_wHZ96ogv, VIf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_bDVtTEPH, VIf(Bf15));
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_wX3f1zdF, VIf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_qZiwZj50, VIf(Bf1));
    __hv_tabwrite_f(&sTabwrite_YUCcfRYV, VIf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_8TiO2QqT, VOf(Bf8));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_6MpUprMM, VOf(Bf14));
    __hv_varread_f(&sVarf_gaDNZJK1, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_xFCmmsvM, VOf(Bf4));
    __hv_rpole_f(&sRPole_12Slqcep, VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf4), VIf(Bf14), VOf(Bf4));
    __hv_fma_f(VIf(Bf4), VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf14));
    __hv_tabread_f(&sTabread_WDZcyJFx, VOf(Bf4));
    __hv_varread_f(&sVarf_LYPSGsZ0, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_zb4IPxIn, VOf(Bf13));
    __hv_rpole_f(&sRPole_cez6Yleu, VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_tabread_f(&sTabread_zQySRaOQ, VOf(Bf13));
    __hv_varread_f(&sVarf_WTZM1YbA, VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_pFnUkHHr, VOf(Bf15));
    __hv_rpole_f(&sRPole_JcBxRs6z, VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf13), VOf(Bf15));
    __hv_fma_f(VIf(Bf15), VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf4), VIf(Bf11), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_2ikyDYvr, VIf(Bf7));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf15));
    __hv_add_f(VIf(Bf7), VIf(Bf15), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_0O7eryX8, VIf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_66PkRnAr, VIf(Bf13));
    __hv_sub_f(VIf(Bf7), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_m04BFh4L, VIf(Bf15));
    __hv_line_f(&sLine_M44fhw6G, VOf(Bf15));
    __hv_mul_f(VIf(Bf10), VIf(Bf15), VOf(Bf10));
    __hv_mul_f(VIf(Bf8), VIf(Bf15), VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf15), VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_F8AciC1G, VOf(Bf15));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_Y9SpFGiB, VIf(Bf5));
    __hv_line_f(&sLine_2I9ucnEo, VOf(Bf15));
    __hv_phasor_f(&sPhasor_wvK9R4px, VIf(Bf15), VOf(Bf15));
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
    __hv_line_f(&sLine_P6XQRzFt, VOf(Bf1));
    __hv_line_f(&sLine_e7rlnpyz, VOf(Bf4));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf4), VOf(Bf9));
    __hv_tabhead_f(&sTabhead_1fHAF4hG, VOf(Bf14));
    __hv_var_k_f_r(VOf(Bf13), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_Vl5g8onr, VOf(Bf14));
    __hv_mul_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_MDzAQhe7, VOf(Bf9));
    __hv_min_f(VIf(Bf14), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf13));
    __hv_varread_f(&sVarf_CdR4pfST, VOf(Bf9));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_QdqR7BMc, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_t6kL1d2b, VIi(Bi0), VOf(Bf9));
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
    __hv_tabhead_f(&sTabhead_TTcAz6zL, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_0ymJCToo, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_BS17oump, VOf(Bf4));
    __hv_min_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf15));
    __hv_varread_f(&sVarf_R0GB4r9H, VOf(Bf4));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_j789nZrI, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_TqYniTcz, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf16), VIf(Bf4), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf16), VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_j9AJL8rr, VOf(Bf9));
    __hv_tabhead_f(&sTabhead_5PrH694i, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_oxI8WbKp, VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_y3iBRhGC, VOf(Bf9));
    __hv_min_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf17));
    __hv_varread_f(&sVarf_w7z1IsXG, VOf(Bf9));
    __hv_zero_f(VOf(Bf15));
    __hv_lt_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_cast_fi(VIf(Bf15), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_YfE4TQFG, VIi(Bi1), VOf(Bf15));
    __hv_tabread_if(&sTabread_jt8ydAGk, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf15), VIf(Bf9), VOf(Bf15));
    __hv_sub_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf15), VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_pm1EeHbj, VOf(Bf17));
    __hv_rpole_f(&sRPole_A5azKhnC, VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_O1LEs9mp, VIf(Bf17), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_fJE5MDGA, VOf(Bf17));
    __hv_mul_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_CpksG3Zx, VOf(Bf9));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf4), VIf(Bf9), VOf(Bf17));
    __hv_line_f(&sLine_wk7ewaKj, VOf(Bf15));
    __hv_varread_f(&sVarf_tHZuoQoY, VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_JfD2jMx3, VOf(Bf9));
    __hv_rpole_f(&sRPole_gyJlU0GT, VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf4), VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_tnwfmDNO, VIf(Bf9));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_bTDMG5Tn, VOf(Bf17));
    __hv_varread_f(&sVarf_qPpBiMoQ, VOf(Bf9));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_kTovkMDl, VOf(Bf9));
    __hv_min_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_vKKOe1zg, VOf(Bf15));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf5));
    __hv_varread_f(&sVarf_Dqqr9xmO, VOf(Bf9));
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
    __hv_cpole_f(&sCPole_aDdSLmuG, VIf(Bf9), VIf(ZERO), VIf(Bf4), VIf(Bf17), VOf(Bf17), VOf(Bf4));
    __hv_varread_f(&sVarf_8OiixBdl, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_UHuarA3L, VOf(Bf17));
    __hv_rpole_f(&sRPole_1jvIb09Y, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_gwqVDu5D, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_egttFfRK, VOf(Bf17));
    __hv_rpole_f(&sRPole_MKmAq8VK, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_BNLzf529, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_kx9XffAD, VOf(Bf17));
    __hv_rpole_f(&sRPole_JsaATWUv, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_AgVlguab, VOf(Bf4));
    __hv_varread_f(&sVarf_bp4zwb2g, VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_hLwUGtIf, VOf(Bf15));
    __hv_rpole_f(&sRPole_xBVLRNeQ, VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf15));
    __hv_line_f(&sLine_ZD8R3tt7, VOf(Bf9));
    __hv_fma_f(VIf(Bf15), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_eYnFYIuf, VOf(Bf15));
    __hv_tabread_f(&sTabread_0IZ8nORU, VOf(Bf5));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf3));
    __hv_tabread_f(&sTabread_mgIVHQem, VOf(Bf16));
    __hv_add_f(VIf(Bf3), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_4suNHM9o, VOf(Bf13));
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf18));
    __hv_tabread_f(&sTabread_aoPyPNhj, VOf(Bf12));
    __hv_add_f(VIf(Bf18), VIf(Bf12), VOf(Bf7));
    __hv_tabread_f(&sTabread_dZv9KKUM, VOf(Bf11));
    __hv_sub_f(VIf(Bf7), VIf(Bf11), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_OS5yf72n, VIf(Bf14));
    __hv_sub_f(VIf(Bf18), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_NdM6mKe9, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_w0GnQ7af, VIf(Bf13));
    __hv_sub_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_1YrWt7oa, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_hMzDiWdn, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_HuOBa9aL, VIf(Bf17));
    __hv_add_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_5wnKoKew, VOf(Bf7));
    __hv_fma_f(VIf(Bf4), VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_OxZuBhjs, VOf(Bf4));
    __hv_varread_f(&sVarf_3OqHSE28, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_D2WCxO88, VOf(Bf16));
    __hv_rpole_f(&sRPole_5av99rbs, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf4), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf4), VIf(Bf15), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf11), VIf(Bf7), VOf(Bf4));
    __hv_tabread_f(&sTabread_7M44m0bj, VOf(Bf16));
    __hv_varread_f(&sVarf_ruIKdTMI, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_LDbuDX4h, VOf(Bf3));
    __hv_rpole_f(&sRPole_BQv3FcO4, VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf16), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf16));
    __hv_tabread_f(&sTabread_eh90VO1r, VOf(Bf3));
    __hv_varread_f(&sVarf_lvFQNp7z, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_DPsj2MhN, VOf(Bf13));
    __hv_rpole_f(&sRPole_MywAw9kY, VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf3), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf16), VIf(Bf15), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_uZX5lcGt, VIf(Bf9));
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf9));
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf13));
    __hv_add_f(VIf(Bf9), VIf(Bf13), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_jSjQlYAw, VIf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_JimkW3VP, VIf(Bf3));
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_75MO2qRU, VIf(Bf13));
    __hv_line_f(&sLine_6tzZEzTm, VOf(Bf13));
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
    __hv_line_f(&sLine_UwfEmNoc, VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf10));
    __hv_mul_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_Oa55Ct8W, VOf(Bf2));
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

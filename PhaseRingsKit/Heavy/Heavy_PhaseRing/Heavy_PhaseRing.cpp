/** Copyright (c) 2026 Charles Martin. Generated from Pure Data by hvcc (https://github.com/Wasted-Audio/hvcc). */

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
  numBytes += sPhasor_k_init(&sPhasor_EgPFXmsd, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_lMuc2LpX);
  numBytes += sPhasor_k_init(&sPhasor_JsbSoQr0, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_5dohWZaN);
  numBytes += sLine_init(&sLine_7MY9FA4f);
  numBytes += sLine_init(&sLine_AZr3Sohn);
  numBytes += sPhasor_k_init(&sPhasor_tZkOHd5D, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_9TgWPYcF);
  numBytes += sPhasor_k_init(&sPhasor_d6rQIE5W, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_E4GJw2Mv);
  numBytes += sLine_init(&sLine_p6RLl9ed);
  numBytes += sLine_init(&sLine_row2Xprb);
  numBytes += sPhasor_k_init(&sPhasor_UGOv6nYl, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_vWrAVoai);
  numBytes += sPhasor_k_init(&sPhasor_AtdoyN25, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_bQ4nxFJs);
  numBytes += sLine_init(&sLine_3nVSm8o5);
  numBytes += sLine_init(&sLine_4FWNfVUv);
  numBytes += sPhasor_k_init(&sPhasor_wuO8mb2C, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_VEngK9mt);
  numBytes += sPhasor_k_init(&sPhasor_C8Rogm34, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_Ef22l1vd);
  numBytes += sLine_init(&sLine_TFJwJV7E);
  numBytes += sLine_init(&sLine_WtRayAnr);
  numBytes += sLine_init(&sLine_wpWPBc00);
  numBytes += sLine_init(&sLine_GxvvmjH4);
  numBytes += sPhasor_init(&sPhasor_24pqy2K1, sampleRate);
  numBytes += sLine_init(&sLine_AKfwDSmu);
  numBytes += sPhasor_k_init(&sPhasor_iZaLmucb, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_EtFH8KRx);
  numBytes += sLine_init(&sLine_Pw1OFfpO);
  numBytes += sRPole_init(&sRPole_CEgZamZ0);
  numBytes += sDel1_init(&sDel1_Rc4poccF);
  numBytes += sLine_init(&sLine_CkNXZgdu);
  numBytes += sLine_init(&sLine_AA5gy14d);
  numBytes += sLine_init(&sLine_mOJWbroJ);
  numBytes += sTabread_init(&sTabread_ss8XATiQ, &hTable_whMXIRQ3, true);
  numBytes += sRPole_init(&sRPole_JrlWd5RU);
  numBytes += sLine_init(&sLine_KTHIp4Sv);
  numBytes += sLine_init(&sLine_5aM0vGxX);
  numBytes += sTabread_init(&sTabread_cu3cZnNI, &hTable_qL0S8TQo, true);
  numBytes += sTabread_init(&sTabread_dghLZh9A, &hTable_3fLm6Dbi, true);
  numBytes += sTabread_init(&sTabread_X8V50qQF, &hTable_PUvS8ivH, true);
  numBytes += sTabread_init(&sTabread_wffloDbf, &hTable_gyyb06xd, true);
  numBytes += sTabread_init(&sTabread_ym0mC4Og, &hTable_QRKZRUyO, true);
  numBytes += sTabwrite_init(&sTabwrite_uwOlxGrC, &hTable_aZ7gPpdB);
  numBytes += sTabwrite_init(&sTabwrite_BPVNU90c, &hTable_QRKZRUyO);
  numBytes += sTabwrite_init(&sTabwrite_ZN6mPLk9, &hTable_gyyb06xd);
  numBytes += sTabwrite_init(&sTabwrite_JHFXe0ee, &hTable_PUvS8ivH);
  numBytes += sTabwrite_init(&sTabwrite_RFf1elrf, &hTable_3fLm6Dbi);
  numBytes += sTabwrite_init(&sTabwrite_3wiViRVW, &hTable_qL0S8TQo);
  numBytes += sTabread_init(&sTabread_Gcpr8fEh, &hTable_aZ7gPpdB, true);
  numBytes += sTabread_init(&sTabread_EcCksb3G, &hTable_lsVeKNp4, true);
  numBytes += sRPole_init(&sRPole_hjYVkrhe);
  numBytes += sTabread_init(&sTabread_Vy8XwgvI, &hTable_uydvynKR, true);
  numBytes += sRPole_init(&sRPole_hS5bKfed);
  numBytes += sTabread_init(&sTabread_pEThncXJ, &hTable_GjyYVBVq, true);
  numBytes += sRPole_init(&sRPole_WcBUSARq);
  numBytes += sTabwrite_init(&sTabwrite_Zr3OBmyJ, &hTable_whMXIRQ3);
  numBytes += sTabwrite_init(&sTabwrite_v4qRoaUZ, &hTable_lsVeKNp4);
  numBytes += sTabwrite_init(&sTabwrite_h0WP7Mzj, &hTable_uydvynKR);
  numBytes += sTabwrite_init(&sTabwrite_VPcgzzYi, &hTable_GjyYVBVq);
  numBytes += sLine_init(&sLine_ckD8PFEi);
  numBytes += sLine_init(&sLine_Uybn0hAd);
  numBytes += sTabwrite_init(&sTabwrite_x6EaIm60, &hTable_rLMfo5BU);
  numBytes += sLine_init(&sLine_L6Uz2u3Y);
  numBytes += sPhasor_init(&sPhasor_e73hdcqQ, sampleRate);
  numBytes += sLine_init(&sLine_6eE1G0oF);
  numBytes += sLine_init(&sLine_zT0U5Nd2);
  numBytes += sTabhead_init(&sTabhead_Nb0uyUxq, &hTable_rLMfo5BU);
  numBytes += sTabread_init(&sTabread_NGpoj74r, &hTable_rLMfo5BU, false);
  numBytes += sTabread_init(&sTabread_v8aZLEL2, &hTable_rLMfo5BU, false);
  numBytes += sTabhead_init(&sTabhead_F4ljiYZF, &hTable_rLMfo5BU);
  numBytes += sTabread_init(&sTabread_4DfAhkcn, &hTable_rLMfo5BU, false);
  numBytes += sTabread_init(&sTabread_csNIpZav, &hTable_rLMfo5BU, false);
  numBytes += sTabhead_init(&sTabhead_rlkXvl73, &hTable_hD8vCwux);
  numBytes += sTabread_init(&sTabread_A1osutGy, &hTable_hD8vCwux, false);
  numBytes += sTabread_init(&sTabread_BifwfxeL, &hTable_hD8vCwux, false);
  numBytes += sRPole_init(&sRPole_G1Q7NZ0y);
  numBytes += sDel1_init(&sDel1_lQDjeGyL);
  numBytes += sLine_init(&sLine_HdZ8RftR);
  numBytes += sRPole_init(&sRPole_Wr9tEVsW);
  numBytes += sTabwrite_init(&sTabwrite_38MffpdR, &hTable_hD8vCwux);
  numBytes += sCPole_init(&sCPole_DpBexXci);
  numBytes += sRPole_init(&sRPole_SPayu0oI);
  numBytes += sRPole_init(&sRPole_n3ZRQQPj);
  numBytes += sRPole_init(&sRPole_8DgRBtoo);
  numBytes += sTabread_init(&sTabread_kZbSpnoU, &hTable_M1rYVYAE, true);
  numBytes += sRPole_init(&sRPole_PhiaDtVP);
  numBytes += sLine_init(&sLine_jGXZkfC6);
  numBytes += sLine_init(&sLine_PAnsX5zg);
  numBytes += sTabread_init(&sTabread_pYPAozmb, &hTable_nrttz5pW, true);
  numBytes += sTabread_init(&sTabread_hDmyyXGr, &hTable_eDc8KrsZ, true);
  numBytes += sTabread_init(&sTabread_ZTn4TLVK, &hTable_ltOQcVTD, true);
  numBytes += sTabread_init(&sTabread_FkP35a8D, &hTable_0ArOQmiF, true);
  numBytes += sTabread_init(&sTabread_nUbLFRYq, &hTable_VVfLeoyT, true);
  numBytes += sTabwrite_init(&sTabwrite_fXzbIy6j, &hTable_6MNDkIzt);
  numBytes += sTabwrite_init(&sTabwrite_SewxLwmm, &hTable_VVfLeoyT);
  numBytes += sTabwrite_init(&sTabwrite_8IOOxRRR, &hTable_0ArOQmiF);
  numBytes += sTabwrite_init(&sTabwrite_OHMVbHSM, &hTable_ltOQcVTD);
  numBytes += sTabwrite_init(&sTabwrite_7HZmQdfN, &hTable_eDc8KrsZ);
  numBytes += sTabwrite_init(&sTabwrite_vCtUo5b0, &hTable_nrttz5pW);
  numBytes += sTabread_init(&sTabread_0wySjqiB, &hTable_6MNDkIzt, true);
  numBytes += sTabread_init(&sTabread_VDlUKKBc, &hTable_5XeJExYj, true);
  numBytes += sRPole_init(&sRPole_GFly23yw);
  numBytes += sTabread_init(&sTabread_uBeiRDrW, &hTable_B33IOwXy, true);
  numBytes += sRPole_init(&sRPole_ztwtSFrv);
  numBytes += sTabread_init(&sTabread_3VpwcPro, &hTable_ydIMUu9i, true);
  numBytes += sRPole_init(&sRPole_MeomZkml);
  numBytes += sTabwrite_init(&sTabwrite_43udeLsA, &hTable_M1rYVYAE);
  numBytes += sTabwrite_init(&sTabwrite_mGVewA1Y, &hTable_5XeJExYj);
  numBytes += sTabwrite_init(&sTabwrite_zN0I33gf, &hTable_B33IOwXy);
  numBytes += sTabwrite_init(&sTabwrite_rT7B78Ix, &hTable_ydIMUu9i);
  numBytes += sLine_init(&sLine_xjTgnxKo);
  numBytes += sLine_init(&sLine_VTWbQbgJ);
  numBytes += sTabwrite_init(&sTabwrite_bO6asmit, &hTable_AfeJHjAC);
  numBytes += sLine_init(&sLine_p05MInlQ);
  numBytes += sPhasor_init(&sPhasor_Zd5eAN7U, sampleRate);
  numBytes += sLine_init(&sLine_lPV7LxmL);
  numBytes += sLine_init(&sLine_7sgXNfJA);
  numBytes += sTabhead_init(&sTabhead_ueE0lkxZ, &hTable_AfeJHjAC);
  numBytes += sTabread_init(&sTabread_oJ2OntoU, &hTable_AfeJHjAC, false);
  numBytes += sTabread_init(&sTabread_fiDUreYE, &hTable_AfeJHjAC, false);
  numBytes += sTabhead_init(&sTabhead_ySl3IAMs, &hTable_AfeJHjAC);
  numBytes += sTabread_init(&sTabread_g9i34wPG, &hTable_AfeJHjAC, false);
  numBytes += sTabread_init(&sTabread_yVxAWfh3, &hTable_AfeJHjAC, false);
  numBytes += sTabhead_init(&sTabhead_Ozvdazik, &hTable_7NDdVPeG);
  numBytes += sTabread_init(&sTabread_HIdKTKZO, &hTable_7NDdVPeG, false);
  numBytes += sTabread_init(&sTabread_LZGtpteI, &hTable_7NDdVPeG, false);
  numBytes += sRPole_init(&sRPole_QoMjxTEE);
  numBytes += sDel1_init(&sDel1_0dKfSLUi);
  numBytes += sLine_init(&sLine_3juLZgyV);
  numBytes += sRPole_init(&sRPole_NQ0jUhW8);
  numBytes += sTabwrite_init(&sTabwrite_6Pfb0x1G, &hTable_7NDdVPeG);
  numBytes += sLine_init(&sLine_BMCnp3ik);
  numBytes += sLine_init(&sLine_7SwZS8xB);
  numBytes += cSlice_init(&cSlice_fESLPaAW, 2, 1);
  numBytes += cSlice_init(&cSlice_b9hIovkd, 1, 1);
  numBytes += cSlice_init(&cSlice_HJdEfHnu, 0, 1);
  numBytes += cVar_init_f(&cVar_oLk3LvF4, 0.0f);
  numBytes += cIf_init(&cIf_ZxOtHAVv, false);
  numBytes += cIf_init(&cIf_6rc9zzZP, false);
  numBytes += cIf_init(&cIf_ke39xWar, false);
  numBytes += cIf_init(&cIf_HaTLJpF3, false);
  numBytes += cIf_init(&cIf_dKxidmK3, false);
  numBytes += cBinop_init(&cBinop_8AbvkA84, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_Veb96ISV, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_el8eT63s, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_AVwH8FVU, 5.0f);
  numBytes += cBinop_init(&cBinop_apyNKt9B, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_G2Jqvbkg, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_uOv749Gl, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_T39QJ6xn, "floatatom");
  numBytes += cVar_init_s(&cVar_IpRWJlnH, "floatatom");
  numBytes += cIf_init(&cIf_jZo0co7K, false);
  numBytes += cIf_init(&cIf_N5uNJpM3, false);
  numBytes += cIf_init(&cIf_rHpt0Dj7, false);
  numBytes += cIf_init(&cIf_s7Dy8Bcr, false);
  numBytes += cPack_init(&cPack_0GAkseD5, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_X11oeTM0, 2, 0.0f, 80.0f);
  numBytes += cPack_init(&cPack_uky0mP76, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_yOTsxdOn, -1834437591);
  numBytes += cSlice_init(&cSlice_1cshByV6, 1, 1);
  numBytes += cVar_init_s(&cVar_NMuyNgh0, "floatatom");
  numBytes += cRandom_init(&cRandom_mGKrtgaB, -1758724672);
  numBytes += cSlice_init(&cSlice_rj1k1nVG, 1, 1);
  numBytes += cVar_init_s(&cVar_p6PYCvI5, "floatatom");
  numBytes += cVar_init_f(&cVar_RLOKvk1q, 1.0f);
  numBytes += cVar_init_f(&cVar_9blA9CGg, 0.0f);
  numBytes += cVar_init_f(&cVar_HM0rezZh, 0.0f);
  numBytes += cRandom_init(&cRandom_z0tgS2FV, 2041621002);
  numBytes += cSlice_init(&cSlice_MpYXfcsw, 1, 1);
  numBytes += cRandom_init(&cRandom_6jFB5OWM, -1312784452);
  numBytes += cSlice_init(&cSlice_daYKdEmm, 1, 1);
  numBytes += cRandom_init(&cRandom_D06nSaR9, 1164927509);
  numBytes += cSlice_init(&cSlice_pr0aaVBY, 1, 1);
  numBytes += cBinop_init(&cBinop_b4X6z80n, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_EfFWHMEY, -1261350184);
  numBytes += cSlice_init(&cSlice_uwGwPmYh, 1, 1);
  numBytes += cPack_init(&cPack_eXVzX7zl, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_ki90msOt, "floatatom");
  numBytes += cVar_init_s(&cVar_B0CciSoD, "floatatom");
  numBytes += cVar_init_s(&cVar_aeh3jmMB, "floatatom");
  numBytes += cVar_init_f(&cVar_tCGKna7s, 0.0f);
  numBytes += cVar_init_s(&cVar_yhtWorUn, "floatatom");
  numBytes += cVar_init_s(&cVar_iCYW18fo, "floatatom");
  numBytes += cVar_init_s(&cVar_GA0byKO3, "floatatom");
  numBytes += cDelay_init(this, &cDelay_slmogFXM, 25.0f);
  numBytes += cVar_init_f(&cVar_oiffz1xJ, 0.0f);
  numBytes += sVarf_init(&sVarf_A0kDY4YY, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_G6M7DAyn, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_mNtkfsfH, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_TB0B6sDp, 1, 1);
  numBytes += cSlice_init(&cSlice_1oOtrvBh, 0, 1);
  numBytes += cBinop_init(&cBinop_HuLypX8p, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_Fr8DHrvr, 98.0f);
  numBytes += cIf_init(&cIf_L9E5HDnV, false);
  numBytes += cBinop_init(&cBinop_DLvH69KX, 0.0f); // __pow
  numBytes += cPack_init(&cPack_mP4042xs, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_SxmeRZcZ, 0.0f);
  numBytes += cRandom_init(&cRandom_0s8J6h5N, 1275685436);
  numBytes += cSlice_init(&cSlice_DAZ7WZ5L, 1, 1);
  numBytes += cBinop_init(&cBinop_m0DKXse3, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_jyJXKuPh, -1043939219);
  numBytes += cSlice_init(&cSlice_GHKKrCoP, 1, 1);
  numBytes += cPack_init(&cPack_gwsNKHJW, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_ufiHiFwN, "floatatom");
  numBytes += cVar_init_s(&cVar_lpwvnreK, "floatatom");
  numBytes += cVar_init_s(&cVar_CH0iC2F4, "floatatom");
  numBytes += cVar_init_f(&cVar_O90gOwiw, 0.0f);
  numBytes += cVar_init_s(&cVar_zm14CA7m, "floatatom");
  numBytes += cVar_init_s(&cVar_Nk37ur1Y, "floatatom");
  numBytes += cVar_init_s(&cVar_JoKps3gy, "floatatom");
  numBytes += cDelay_init(this, &cDelay_G0djwFKA, 25.0f);
  numBytes += cVar_init_f(&cVar_B3HgcL3Z, 0.0f);
  numBytes += sVarf_init(&sVarf_ULDdb0X6, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_kK7BQrkZ, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_sTT0onN4, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_7K9E3PAI, 1, 1);
  numBytes += cSlice_init(&cSlice_nXPk7n3I, 0, 1);
  numBytes += cBinop_init(&cBinop_hh9Lg0ob, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_LyND3D5l, -1128876972);
  numBytes += cSlice_init(&cSlice_3HWQJil1, 1, 1);
  numBytes += cBinop_init(&cBinop_SARqOKXv, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_krw64aD6, 1517588401);
  numBytes += cSlice_init(&cSlice_cp7Eti07, 1, 1);
  numBytes += cPack_init(&cPack_cCvAVVBM, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_zkjD0wpu, "floatatom");
  numBytes += cVar_init_s(&cVar_6ImolnSq, "floatatom");
  numBytes += cVar_init_s(&cVar_kBSqCQh0, "floatatom");
  numBytes += cVar_init_f(&cVar_OTKaE5wW, 0.0f);
  numBytes += cVar_init_s(&cVar_Jh0tlPo6, "floatatom");
  numBytes += cVar_init_s(&cVar_hUmtzh86, "floatatom");
  numBytes += cVar_init_s(&cVar_QvV1vCLR, "floatatom");
  numBytes += cDelay_init(this, &cDelay_dHfwNaFZ, 25.0f);
  numBytes += cVar_init_f(&cVar_HE80rZF0, 0.0f);
  numBytes += sVarf_init(&sVarf_j9jpSXYK, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_4413kkSB, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_ndNS47ij, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_1REj9Ufc, 1, 1);
  numBytes += cSlice_init(&cSlice_JxMOWpkk, 0, 1);
  numBytes += cBinop_init(&cBinop_uhsGmRCa, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_TagL0VcW, 1328205662);
  numBytes += cSlice_init(&cSlice_FUvhFPRh, 1, 1);
  numBytes += cBinop_init(&cBinop_hWrYNI9j, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_tTn8LC2z, 532720171);
  numBytes += cSlice_init(&cSlice_tCirdl9S, 1, 1);
  numBytes += cPack_init(&cPack_9bkU2OkU, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_JJw23vMR, "floatatom");
  numBytes += cVar_init_s(&cVar_AXliokcF, "floatatom");
  numBytes += cVar_init_s(&cVar_nOfN1rxA, "floatatom");
  numBytes += cVar_init_f(&cVar_C0FrBgZs, 0.0f);
  numBytes += cVar_init_s(&cVar_uLsZ590T, "floatatom");
  numBytes += cVar_init_s(&cVar_PK4N2nxj, "floatatom");
  numBytes += cVar_init_s(&cVar_60z9JOad, "floatatom");
  numBytes += cDelay_init(this, &cDelay_LcpMfb2k, 25.0f);
  numBytes += cVar_init_f(&cVar_TlZSlvaI, 0.0f);
  numBytes += sVarf_init(&sVarf_tIJ7HHY1, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_ANGMXssE, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_DpcKOTfm, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_LdSRsq9A, 1, 1);
  numBytes += cSlice_init(&cSlice_g0j3JeDk, 0, 1);
  numBytes += cBinop_init(&cBinop_VEvUdUVk, 1.0f); // __mul
  numBytes += cTabhead_init(&cTabhead_DJsKyvZW, &hTable_whMXIRQ3);
  numBytes += cVar_init_s(&cVar_Yjke4BbL, "del-1209-del1");
  numBytes += cDelay_init(this, &cDelay_c45GUcCy, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_4mzlX5Fx, 0.0f);
  numBytes += cBinop_init(&cBinop_eSLhp8Nh, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_6V3WfN98, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6XDlta6G, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_qKkAbzEu, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_9Tb2rOGi, &hTable_lsVeKNp4);
  numBytes += cVar_init_s(&cVar_Hj03nxtc, "del-1209-del2");
  numBytes += cDelay_init(this, &cDelay_T17osNCo, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_Egp4MSTy, 0.0f);
  numBytes += cBinop_init(&cBinop_v8Ncjv1c, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_A0RCIHcC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xKZhgHuJ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zN1f21Z2, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_zniqSSRx, &hTable_uydvynKR);
  numBytes += cVar_init_s(&cVar_ogPat2Qz, "del-1209-del3");
  numBytes += cDelay_init(this, &cDelay_eVOYlF6w, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_uVYPyhOm, 0.0f);
  numBytes += cBinop_init(&cBinop_RnWkkfJl, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_XyTrasPt, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pbNImcnC, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_n2PXWp1e, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_BMwEKgwi, &hTable_GjyYVBVq);
  numBytes += cVar_init_s(&cVar_5VImFzOw, "del-1209-del4");
  numBytes += cDelay_init(this, &cDelay_lt8BFQko, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_lYAeeO0V, 0.0f);
  numBytes += cBinop_init(&cBinop_4XNhEbkI, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_kJHN8eD5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Mb7NjzHS, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_FdWMcc6H, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_7sqWRCHh, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zxrno3az, 0.0f);
  numBytes += hTable_init(&hTable_whMXIRQ3, 256);
  numBytes += cDelay_init(this, &cDelay_RtQ0NIXs, 0.0f);
  numBytes += cDelay_init(this, &cDelay_oEmR4ike, 0.0f);
  numBytes += hTable_init(&hTable_lsVeKNp4, 256);
  numBytes += cDelay_init(this, &cDelay_hfmEo0gk, 0.0f);
  numBytes += cDelay_init(this, &cDelay_PmVxB3Cs, 0.0f);
  numBytes += hTable_init(&hTable_uydvynKR, 256);
  numBytes += cDelay_init(this, &cDelay_RD5AnM2Z, 0.0f);
  numBytes += cDelay_init(this, &cDelay_u8SnnwIM, 0.0f);
  numBytes += hTable_init(&hTable_GjyYVBVq, 256);
  numBytes += cIf_init(&cIf_Wn3XsaBx, false);
  numBytes += cBinop_init(&cBinop_VUJ8XKuK, 0.0f); // __pow
  numBytes += cPack_init(&cPack_dQU0SMhl, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_1GWe9r8A, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_XPj00sGH, 22050.0f);
  numBytes += cBinop_init(&cBinop_zSOGzYuw, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_b3CKtgZY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_F4cXwsnx, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_QXOBBPyn, 95.0f);
  numBytes += cVar_init_f(&cVar_aiF97HwO, 90.0f);
  numBytes += cVar_init_f(&cVar_neMgIJRF, 6000.0f);
  numBytes += cVar_init_f(&cVar_Ex8ouweF, 60.0f);
  numBytes += cIf_init(&cIf_iDXxBfpu, false);
  numBytes += cTabhead_init(&cTabhead_q0Jb4lNK, &hTable_aZ7gPpdB);
  numBytes += cVar_init_s(&cVar_5TZdf7Ge, "del-1209-ref6");
  numBytes += cDelay_init(this, &cDelay_rDhEBaX8, 13.645f);
  numBytes += cDelay_init(this, &cDelay_fEcUM8Uh, 0.0f);
  numBytes += cBinop_init(&cBinop_L4WwHbJg, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_QxDlefW1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fL5iDBSf, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_nyzMJMNB, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_KrGni5Vg, 0.0f);
  numBytes += cDelay_init(this, &cDelay_W0bwZCG3, 0.0f);
  numBytes += hTable_init(&hTable_aZ7gPpdB, 256);
  numBytes += cTabhead_init(&cTabhead_zlO6azOc, &hTable_QRKZRUyO);
  numBytes += cVar_init_s(&cVar_XZh7uSpw, "del-1209-ref5");
  numBytes += cDelay_init(this, &cDelay_vuKmSmq0, 16.364f);
  numBytes += cDelay_init(this, &cDelay_N9WARvCi, 0.0f);
  numBytes += cBinop_init(&cBinop_W8EcRhtg, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_jgvDOlP0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_u9Lpo23R, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_6U6ziOK0, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_pVuksFL0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_SktDr2XY, 0.0f);
  numBytes += hTable_init(&hTable_QRKZRUyO, 256);
  numBytes += cTabhead_init(&cTabhead_J01iXiyW, &hTable_gyyb06xd);
  numBytes += cVar_init_s(&cVar_boVHaGib, "del-1209-ref4");
  numBytes += cDelay_init(this, &cDelay_LD8J2YFe, 19.392f);
  numBytes += cDelay_init(this, &cDelay_7DFT6Lzp, 0.0f);
  numBytes += cBinop_init(&cBinop_Lx4zoyvJ, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_4qI6MRiv, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_lc5nvkVq, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_GsrQ7Hko, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_VQ1GiHuO, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TgTgg8ud, 0.0f);
  numBytes += hTable_init(&hTable_gyyb06xd, 256);
  numBytes += cTabhead_init(&cTabhead_U85d9Y5U, &hTable_PUvS8ivH);
  numBytes += cVar_init_s(&cVar_F7J7F0R3, "del-1209-ref3");
  numBytes += cDelay_init(this, &cDelay_iKTpOozt, 25.796f);
  numBytes += cDelay_init(this, &cDelay_oIvGjAdZ, 0.0f);
  numBytes += cBinop_init(&cBinop_yQX2pdQG, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_AcgeRjWQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Axop58DN, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_oI1yMeLD, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_DIxhgo7m, 0.0f);
  numBytes += cDelay_init(this, &cDelay_dlz2MkiL, 0.0f);
  numBytes += hTable_init(&hTable_PUvS8ivH, 256);
  numBytes += cTabhead_init(&cTabhead_Z2O1qOoy, &hTable_3fLm6Dbi);
  numBytes += cVar_init_s(&cVar_j24waaS7, "del-1209-ref2");
  numBytes += cDelay_init(this, &cDelay_hw7smwev, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_KBZ4jugh, 0.0f);
  numBytes += cBinop_init(&cBinop_VSa6jbkK, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_hT9yNgqG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_joaVrnsv, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_kHjWJFAD, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_resvxUqm, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Qx4ZOnQF, 0.0f);
  numBytes += hTable_init(&hTable_3fLm6Dbi, 256);
  numBytes += cTabhead_init(&cTabhead_FepUjPkp, &hTable_qL0S8TQo);
  numBytes += cVar_init_s(&cVar_fCzNbENK, "del-1209-ref1");
  numBytes += cDelay_init(this, &cDelay_nvFbreoW, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_ces9BUQY, 0.0f);
  numBytes += cBinop_init(&cBinop_Ym4BrJJo, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_fmPY3BC2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jaLI1T6Y, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_SkisodUC, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_HJ3zVYIV, 0.0f);
  numBytes += cDelay_init(this, &cDelay_KNDSJSLf, 0.0f);
  numBytes += hTable_init(&hTable_qL0S8TQo, 256);
  numBytes += cVar_init_f(&cVar_CdZSZ8c9, 0.0f);
  numBytes += cVar_init_f(&cVar_eW6f03YJ, 0.0f);
  numBytes += cPack_init(&cPack_t7KaHNbo, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_KH4afGDD, 22050.0f);
  numBytes += cBinop_init(&cBinop_e9u3ntw9, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_nrehWPSJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VF6nDds8, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8Q8fIgxJ, 22050.0f);
  numBytes += cBinop_init(&cBinop_SFDvUQJo, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_1weslR2s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Qm967ZSJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_MxPYDdnH, 22050.0f);
  numBytes += cBinop_init(&cBinop_kosU7XqC, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_7N6sgdaj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Jqg8EUnA, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_v9Xga2Z8, false);
  numBytes += cDelay_init(this, &cDelay_ss2qV98Z, 50.0f);
  numBytes += cVar_init_f(&cVar_86P2DOps, 0.0f);
  numBytes += cVar_init_f(&cVar_celc4kgG, 12.0f);
  numBytes += cVar_init_s(&cVar_KIVpJPJ7, "floatatom");
  numBytes += cPack_init(&cPack_Zljc5kMo, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_3IaAYn5p, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_0yZsJ2JY, "floatatom");
  numBytes += cDelay_init(this, &cDelay_zUiEEujJ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_EyO9wt9S, 0.0f);
  numBytes += hTable_init(&hTable_rLMfo5BU, 256);
  numBytes += cVar_init_s(&cVar_RlIm1VPq, "del-1316-del");
  numBytes += sVarf_init(&sVarf_dqMc9oLE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xsBzyZiz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qtVatXXt, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_hkZ0L2Kq, "del-1316-del");
  numBytes += sVarf_init(&sVarf_otoAoWKG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pGEdpUhu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xv2fJy9z, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_cMklvmWL, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_DoS6YuLp, 4720.0f);
  numBytes += cBinop_init(&cBinop_zcl1hGOM, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_xIoTsUED, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fRkdFzLs, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_pLrzwnd1, 4720.0f);
  numBytes += cBinop_init(&cBinop_TzjFmHtQ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_LmjaFRr7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oRWDO7FO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_D7DzEICZ, 4720.0f);
  numBytes += cBinop_init(&cBinop_pkRzYqMY, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_g12I6sjG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0htvQe1P, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_tVuBjZrW, 1.0f);
  numBytes += cIf_init(&cIf_vhZQguXv, false);
  numBytes += sVarf_init(&sVarf_wwvIsUpJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qV50ElgG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rCF2O5HX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_B8JPcRgV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_opCZfXDh, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_EIuMrBwv, &hTable_M1rYVYAE);
  numBytes += cVar_init_s(&cVar_4k5qqSle, "del-1379-del1");
  numBytes += cDelay_init(this, &cDelay_YitKmdmR, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_NMpeHMNa, 0.0f);
  numBytes += cBinop_init(&cBinop_lkOYe2De, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_EYOgrxt9, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_zuVeZA7Z, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_FTMLvNaW, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_kladtYAp, &hTable_5XeJExYj);
  numBytes += cVar_init_s(&cVar_Nz53AEGq, "del-1379-del2");
  numBytes += cDelay_init(this, &cDelay_eLPt0H1G, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_sALvnZzS, 0.0f);
  numBytes += cBinop_init(&cBinop_jKY1dZT1, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_9nOPe9c9, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3AyFN7mm, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ysT1vAxa, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_ZitnlkJz, &hTable_B33IOwXy);
  numBytes += cVar_init_s(&cVar_yHyoXIx9, "del-1379-del3");
  numBytes += cDelay_init(this, &cDelay_bzzC5jIa, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_Kv2o9GOb, 0.0f);
  numBytes += cBinop_init(&cBinop_PDAtOdw7, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_c8d7sW2W, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_1oDbsHy7, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_fBlVodfn, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_xvYgYoT8, &hTable_ydIMUu9i);
  numBytes += cVar_init_s(&cVar_s8QlkCHL, "del-1379-del4");
  numBytes += cDelay_init(this, &cDelay_naNBRtFl, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_oJZNBWtV, 0.0f);
  numBytes += cBinop_init(&cBinop_UPqgy9nN, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_Ogld3fPD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_GkrnHhPi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_jAJDaAGO, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_mkN7zfYi, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kHyoTOQG, 0.0f);
  numBytes += hTable_init(&hTable_M1rYVYAE, 256);
  numBytes += cDelay_init(this, &cDelay_0rYfKjAs, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XkeusFgD, 0.0f);
  numBytes += hTable_init(&hTable_5XeJExYj, 256);
  numBytes += cDelay_init(this, &cDelay_i6z5I7dm, 0.0f);
  numBytes += cDelay_init(this, &cDelay_e2W1oOj5, 0.0f);
  numBytes += hTable_init(&hTable_B33IOwXy, 256);
  numBytes += cDelay_init(this, &cDelay_6cppwRCN, 0.0f);
  numBytes += cDelay_init(this, &cDelay_JKg3cTs8, 0.0f);
  numBytes += hTable_init(&hTable_ydIMUu9i, 256);
  numBytes += cIf_init(&cIf_7SAxiJf5, false);
  numBytes += cBinop_init(&cBinop_ovFgPnIy, 0.0f); // __pow
  numBytes += cPack_init(&cPack_oYibzZju, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_ROrUWDcm, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_pFdDqbIX, 22050.0f);
  numBytes += cBinop_init(&cBinop_iNkPXPDv, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_kDTd7ARj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_M5ttx0Hr, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_JdvEXeF3, 100.0f);
  numBytes += cVar_init_f(&cVar_8Sv7xkSj, 95.0f);
  numBytes += cVar_init_f(&cVar_W9892EYu, 14400.0f);
  numBytes += cVar_init_f(&cVar_PY43sc3t, 60.0f);
  numBytes += cIf_init(&cIf_l17kefhp, false);
  numBytes += cTabhead_init(&cTabhead_sPzwrraR, &hTable_6MNDkIzt);
  numBytes += cVar_init_s(&cVar_Fu3LHd7f, "del-1379-ref6");
  numBytes += cDelay_init(this, &cDelay_8mYj7hrW, 13.645f);
  numBytes += cDelay_init(this, &cDelay_vCETmHlC, 0.0f);
  numBytes += cBinop_init(&cBinop_8eGsjW2u, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_Xtcx3IQ0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9tKEt1so, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_PWiZC8Lq, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_833OB0xe, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CvItOc9j, 0.0f);
  numBytes += hTable_init(&hTable_6MNDkIzt, 256);
  numBytes += cTabhead_init(&cTabhead_9J3vn407, &hTable_VVfLeoyT);
  numBytes += cVar_init_s(&cVar_NyEn7IN9, "del-1379-ref5");
  numBytes += cDelay_init(this, &cDelay_Bl0oubVU, 16.364f);
  numBytes += cDelay_init(this, &cDelay_iS7gmIZb, 0.0f);
  numBytes += cBinop_init(&cBinop_gXtGfBW9, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_gYGyawHy, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NNf4yaZy, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_qKrSRncX, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_yRc6Umav, 0.0f);
  numBytes += cDelay_init(this, &cDelay_S1vMFU2c, 0.0f);
  numBytes += hTable_init(&hTable_VVfLeoyT, 256);
  numBytes += cTabhead_init(&cTabhead_QhIIM1Wp, &hTable_0ArOQmiF);
  numBytes += cVar_init_s(&cVar_gdktfi2h, "del-1379-ref4");
  numBytes += cDelay_init(this, &cDelay_uoTQW5FF, 19.392f);
  numBytes += cDelay_init(this, &cDelay_IudEQopu, 0.0f);
  numBytes += cBinop_init(&cBinop_QvB1XFtG, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_8Wz2uWIB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FpeK57c6, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_7UMrAnKg, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Z7XkxSaZ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_AYrgqUmr, 0.0f);
  numBytes += hTable_init(&hTable_0ArOQmiF, 256);
  numBytes += cTabhead_init(&cTabhead_7igCf9ZW, &hTable_ltOQcVTD);
  numBytes += cVar_init_s(&cVar_rgmbpMPk, "del-1379-ref3");
  numBytes += cDelay_init(this, &cDelay_sBvRVht6, 25.796f);
  numBytes += cDelay_init(this, &cDelay_dIBMKLNm, 0.0f);
  numBytes += cBinop_init(&cBinop_CZqidWcr, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_4M5y7FJh, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cj78Oo2B, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_8TkYuhTJ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_0qLR1EdC, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0d36govI, 0.0f);
  numBytes += hTable_init(&hTable_ltOQcVTD, 256);
  numBytes += cTabhead_init(&cTabhead_vSVFcE5z, &hTable_eDc8KrsZ);
  numBytes += cVar_init_s(&cVar_UIQzP1YQ, "del-1379-ref2");
  numBytes += cDelay_init(this, &cDelay_Gt7R3eD5, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_Dm2fO2A8, 0.0f);
  numBytes += cBinop_init(&cBinop_JXPgZxpz, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_n7iVOLm7, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ztGo0js0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Ctacuj9q, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_uHloocTA, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1sSo9hxv, 0.0f);
  numBytes += hTable_init(&hTable_eDc8KrsZ, 256);
  numBytes += cTabhead_init(&cTabhead_U08NLIoz, &hTable_nrttz5pW);
  numBytes += cVar_init_s(&cVar_9LEXC4CG, "del-1379-ref1");
  numBytes += cDelay_init(this, &cDelay_CvX6UvW5, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_mAekHjvH, 0.0f);
  numBytes += cBinop_init(&cBinop_UT9FC3gi, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_75tWTASF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_O5M7cENq, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_cWeFwL9x, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_UjOnGLS1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vA08MII0, 0.0f);
  numBytes += hTable_init(&hTable_nrttz5pW, 256);
  numBytes += cVar_init_f(&cVar_cTQu7TXa, 0.0f);
  numBytes += cVar_init_f(&cVar_cIMUacQS, 0.0f);
  numBytes += cPack_init(&cPack_ZGM0XTa2, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_LfSsfqKi, 22050.0f);
  numBytes += cBinop_init(&cBinop_m9eKUUjV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_jWQfRG73, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NKe9y2xE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_myw2Dnre, 22050.0f);
  numBytes += cBinop_init(&cBinop_i6JZ0omC, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ipZ7hH4B, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Rs3LFxpv, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_6H6YvLhW, 22050.0f);
  numBytes += cBinop_init(&cBinop_WyCMgGDM, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_JsdKSllh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JOAX3PId, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_luFtk7S7, "del-1478-del1");
  numBytes += sVarf_init(&sVarf_96PjJZmS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pF2wFGwx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GJVSvaYt, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mJFYSDIG, 10000.0f);
  numBytes += cBinop_init(&cBinop_SjmJnjGD, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8iBRt9CU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DiER5g1K, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_blGeibxy, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VOeYVCJp, 10.0f);
  numBytes += cBinop_init(&cBinop_h1Eivxwc, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_SJ9BFOT1, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_WAvBIGqG, "floatatom");
  numBytes += sVarf_init(&sVarf_LEghi2TG, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_VxielVub, 0.0f);
  numBytes += cDelay_init(this, &cDelay_pTfJAkaO, 0.0f);
  numBytes += hTable_init(&hTable_hD8vCwux, 256);
  numBytes += sVarf_init(&sVarf_H4vyfMuo, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_6eySD7Ik, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_pBFB6yRj, -621361848);
  numBytes += cSlice_init(&cSlice_5z8Nlcy1, 1, 1);
  numBytes += cRandom_init(&cRandom_qfLY97rt, -560504653);
  numBytes += cSlice_init(&cSlice_jmZ8Ebhm, 1, 1);
  numBytes += cVar_init_s(&cVar_bEwczvOg, "floatatom");
  numBytes += cPack_init(&cPack_f2C6RCcF, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_y8UlqmNX, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_NATijDg4, "floatatom");
  numBytes += cDelay_init(this, &cDelay_1upx28Gm, 0.0f);
  numBytes += cDelay_init(this, &cDelay_NWQX60N7, 0.0f);
  numBytes += hTable_init(&hTable_AfeJHjAC, 256);
  numBytes += cVar_init_s(&cVar_fFLErozG, "del-1509-del");
  numBytes += sVarf_init(&sVarf_LQt8CfLM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_by1vll3K, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RtOlYvmY, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_No3ef98I, "del-1509-del");
  numBytes += sVarf_init(&sVarf_7AraMLj0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PzrJFW3F, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eqaZ4nfi, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_yGJd6fdu, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_Q06SCMde, "del-1538-del1");
  numBytes += sVarf_init(&sVarf_27qYBP8n, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_AGSmbZFU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5b1lNuYl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_bUGY8CSu, 10000.0f);
  numBytes += cBinop_init(&cBinop_MFQLXG4W, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XLsvwfIe, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uR73kTj8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_O3irMjca, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_fTot3fFS, 10.0f);
  numBytes += cBinop_init(&cBinop_f4VdivFj, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_dfZLNOUp, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_mLzLidEV, "floatatom");
  numBytes += sVarf_init(&sVarf_cTNm0UNL, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_M1Ej8jys, 0.0f);
  numBytes += cDelay_init(this, &cDelay_eCgU0hFE, 0.0f);
  numBytes += hTable_init(&hTable_7NDdVPeG, 256);
  numBytes += sVarf_init(&sVarf_ZaU6HlVU, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Dk9ac1eE, "floatatom");
  numBytes += cDelay_init(this, &cDelay_htVbaWgg, 0.0f);
  numBytes += cVar_init_f(&cVar_NLRDvdDt, 20.0f);
  numBytes += cBinop_init(&cBinop_rrEaphQj, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_w4ZZ3CoS, 0.0f);
  numBytes += cSlice_init(&cSlice_jId1gJHL, 1, -1);
  numBytes += cSlice_init(&cSlice_1Q7wlTbK, 1, -1);
  numBytes += cVar_init_f(&cVar_kjC99cs3, 0.0f);
  numBytes += cVar_init_f(&cVar_Lrw3Ayun, 20.0f);
  numBytes += cVar_init_f(&cVar_URxMdMVG, 0.0f);
  numBytes += cVar_init_f(&cVar_sZ68RCdu, 0.0f);
  numBytes += cVar_init_f(&cVar_rFITZeXO, 0.0f);
  numBytes += cSlice_init(&cSlice_sPxB0mKC, 1, 1);
  numBytes += cSlice_init(&cSlice_C8yJpD2a, 0, 1);
  numBytes += cBinop_init(&cBinop_v0mWRMwg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_t84jhfg6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_eCtL9KgD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_qTonpsYO, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_tOyMqrjw, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_gbzC9vKI, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_PjliQphW, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_wXCszMHG, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_haBknosn, "floatatom");
  numBytes += cDelay_init(this, &cDelay_rygFSngc, 0.0f);
  numBytes += cVar_init_f(&cVar_xVjvCi5o, 20.0f);
  numBytes += cBinop_init(&cBinop_EFe6WgBx, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_eWvy9Q1s, 0.0f);
  numBytes += cSlice_init(&cSlice_iuuLXMGP, 1, -1);
  numBytes += cSlice_init(&cSlice_5LWBeD5J, 1, -1);
  numBytes += cVar_init_f(&cVar_oCsnNbis, 0.0f);
  numBytes += cVar_init_f(&cVar_1OURFzj7, 20.0f);
  numBytes += cVar_init_f(&cVar_SRH2aXPr, 0.0f);
  numBytes += cVar_init_f(&cVar_Aj5dyiA4, 0.0f);
  numBytes += cVar_init_f(&cVar_lsMnydcQ, 0.0f);
  numBytes += cSlice_init(&cSlice_t802OmXg, 1, 1);
  numBytes += cSlice_init(&cSlice_LBExNF64, 0, 1);
  numBytes += cBinop_init(&cBinop_WcZ6MSww, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_pz5YD5wS, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_UNfvuQDt, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_8YejB9WL, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_1Emj0Os4, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_JKbBa80r, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_oaxbi6B6, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ANHRDZ4N, 0.0f); // __sub
  numBytes += cPack_init(&cPack_ZhvVIc8S, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_VDhFOKH2, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_XpkEdFcK, 2, 0.0f, 1000.0f);
  numBytes += cVar_init_f(&cVar_RPybZG23, 100.0f);
  numBytes += cIf_init(&cIf_1CqJK5oW, false);
  numBytes += cBinop_init(&cBinop_yBj5eBiZ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_RYZ5ufup, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_S4yUNy6C, 0.0f);
  numBytes += cVar_init_f(&cVar_uZgsw1TH, 100.0f);
  numBytes += cIf_init(&cIf_64oDgDLw, false);
  numBytes += cBinop_init(&cBinop_yrDPxQe7, 0.0f); // __pow
  numBytes += cPack_init(&cPack_hv7dTLCt, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_8oGAA6Ou, 0.0f);
  numBytes += cIf_init(&cIf_wPAy1Io4, false);
  numBytes += cIf_init(&cIf_tUm53yHS, false);
  numBytes += cVar_init_f(&cVar_r2EEnIRC, 97.0f);
  numBytes += cIf_init(&cIf_ztAeB2HP, false);
  numBytes += cBinop_init(&cBinop_f2AWJBR8, 0.0f); // __pow
  numBytes += cPack_init(&cPack_rpGo6UUj, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_5Ki1cTP4, 0.0f);
  numBytes += cVar_init_f(&cVar_kfaNmKKg, 89.0f);
  numBytes += cIf_init(&cIf_vuVtdIZA, false);
  numBytes += cBinop_init(&cBinop_AVTWcZRQ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_M56f88bG, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_RjdZLC7k, 0.0f);
  numBytes += cVar_init_f(&cVar_sUTqnFYU, 97.0f);
  numBytes += cIf_init(&cIf_80nWHzBT, false);
  numBytes += cBinop_init(&cBinop_vbeCAGtU, 0.0f); // __pow
  numBytes += cPack_init(&cPack_FIxhQEG6, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_2XHS8FIa, 0.0f);
  numBytes += cPack_init(&cPack_g3hW58dk, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_HWN7DiDW, 1, 1);
  numBytes += cSlice_init(&cSlice_QkTGDsYw, 0, 1);
  numBytes += cIf_init(&cIf_Lsm9iEtX, false);
  numBytes += cIf_init(&cIf_gM29ndnV, false);
  numBytes += cIf_init(&cIf_1xBytj6g, false);
  numBytes += cSlice_init(&cSlice_ccNR9G8S, 1, 1);
  numBytes += cSlice_init(&cSlice_F8v0TK6O, 0, 1);
  numBytes += cVar_init_f(&cVar_71z5UQ7n, 0.0f);
  numBytes += cIf_init(&cIf_3c5SCZIG, false);
  numBytes += cPack_init(&cPack_IrNYKeed, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_Ur8AgDTI, 1, -1);
  numBytes += cSlice_init(&cSlice_jIOWyo9q, 1, -1);
  numBytes += cSlice_init(&cSlice_qKivOSKT, 1, -1);
  numBytes += cSlice_init(&cSlice_VMcOjzdS, 1, -1);
  numBytes += cIf_init(&cIf_phjlgO4k, false);
  numBytes += cVar_init_f(&cVar_WHwpMS5J, 1.0f);
  numBytes += cPack_init(&cPack_YncaOnmr, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_KV5AF9iJ, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_PhaseRing::~Heavy_PhaseRing() {
  cPack_free(&cPack_uOv749Gl);
  cPack_free(&cPack_0GAkseD5);
  cPack_free(&cPack_X11oeTM0);
  cPack_free(&cPack_uky0mP76);
  cPack_free(&cPack_eXVzX7zl);
  cPack_free(&cPack_G6M7DAyn);
  cPack_free(&cPack_mNtkfsfH);
  cPack_free(&cPack_mP4042xs);
  cPack_free(&cPack_gwsNKHJW);
  cPack_free(&cPack_kK7BQrkZ);
  cPack_free(&cPack_sTT0onN4);
  cPack_free(&cPack_cCvAVVBM);
  cPack_free(&cPack_4413kkSB);
  cPack_free(&cPack_ndNS47ij);
  cPack_free(&cPack_9bkU2OkU);
  cPack_free(&cPack_ANGMXssE);
  cPack_free(&cPack_DpcKOTfm);
  hTable_free(&hTable_whMXIRQ3);
  hTable_free(&hTable_lsVeKNp4);
  hTable_free(&hTable_uydvynKR);
  hTable_free(&hTable_GjyYVBVq);
  cPack_free(&cPack_dQU0SMhl);
  cPack_free(&cPack_1GWe9r8A);
  hTable_free(&hTable_aZ7gPpdB);
  hTable_free(&hTable_QRKZRUyO);
  hTable_free(&hTable_gyyb06xd);
  hTable_free(&hTable_PUvS8ivH);
  hTable_free(&hTable_3fLm6Dbi);
  hTable_free(&hTable_qL0S8TQo);
  cPack_free(&cPack_t7KaHNbo);
  cPack_free(&cPack_Zljc5kMo);
  cPack_free(&cPack_3IaAYn5p);
  hTable_free(&hTable_rLMfo5BU);
  hTable_free(&hTable_M1rYVYAE);
  hTable_free(&hTable_5XeJExYj);
  hTable_free(&hTable_B33IOwXy);
  hTable_free(&hTable_ydIMUu9i);
  cPack_free(&cPack_oYibzZju);
  cPack_free(&cPack_ROrUWDcm);
  hTable_free(&hTable_6MNDkIzt);
  hTable_free(&hTable_VVfLeoyT);
  hTable_free(&hTable_0ArOQmiF);
  hTable_free(&hTable_ltOQcVTD);
  hTable_free(&hTable_eDc8KrsZ);
  hTable_free(&hTable_nrttz5pW);
  cPack_free(&cPack_ZGM0XTa2);
  hTable_free(&hTable_hD8vCwux);
  cPack_free(&cPack_6eySD7Ik);
  cPack_free(&cPack_f2C6RCcF);
  cPack_free(&cPack_y8UlqmNX);
  hTable_free(&hTable_AfeJHjAC);
  hTable_free(&hTable_7NDdVPeG);
  cPack_free(&cPack_ZhvVIc8S);
  cPack_free(&cPack_VDhFOKH2);
  cPack_free(&cPack_XpkEdFcK);
  cPack_free(&cPack_RYZ5ufup);
  cPack_free(&cPack_hv7dTLCt);
  cPack_free(&cPack_rpGo6UUj);
  cPack_free(&cPack_M56f88bG);
  cPack_free(&cPack_FIxhQEG6);
  cPack_free(&cPack_g3hW58dk);
  cPack_free(&cPack_IrNYKeed);
  cPack_free(&cPack_YncaOnmr);
}

HvTable *Heavy_PhaseRing::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xF96F9CBC: return &hTable_whMXIRQ3; // del-1209-del1
    case 0xEAD79ADF: return &hTable_lsVeKNp4; // del-1209-del2
    case 0xB1129AA0: return &hTable_uydvynKR; // del-1209-del3
    case 0x4F62B33F: return &hTable_GjyYVBVq; // del-1209-del4
    case 0x36047BDC: return &hTable_aZ7gPpdB; // del-1209-ref6
    case 0x66BE8A1D: return &hTable_QRKZRUyO; // del-1209-ref5
    case 0xD4C64222: return &hTable_gyyb06xd; // del-1209-ref4
    case 0xC5A2B81B: return &hTable_PUvS8ivH; // del-1209-ref3
    case 0xE629D5: return &hTable_3fLm6Dbi; // del-1209-ref2
    case 0x912EE503: return &hTable_qL0S8TQo; // del-1209-ref1
    case 0xFBB0E240: return &hTable_rLMfo5BU; // del-1316-del
    case 0xDB23006E: return &hTable_M1rYVYAE; // del-1379-del1
    case 0x71D4109E: return &hTable_5XeJExYj; // del-1379-del2
    case 0x3209AF80: return &hTable_B33IOwXy; // del-1379-del3
    case 0x243F6DE3: return &hTable_ydIMUu9i; // del-1379-del4
    case 0x57CE1FFD: return &hTable_6MNDkIzt; // del-1379-ref6
    case 0xE6EB4810: return &hTable_VVfLeoyT; // del-1379-ref5
    case 0x1A778356: return &hTable_0ArOQmiF; // del-1379-ref4
    case 0xEAC5B9C7: return &hTable_ltOQcVTD; // del-1379-ref3
    case 0x59B93D98: return &hTable_eDc8KrsZ; // del-1379-ref2
    case 0x29741CDA: return &hTable_nrttz5pW; // del-1379-ref1
    case 0xE6E7333E: return &hTable_hD8vCwux; // del-1478-del1
    case 0x37C7A3A7: return &hTable_AfeJHjAC; // del-1509-del
    case 0x55F6486C: return &hTable_7NDdVPeG; // del-1538-del1
    default: return nullptr;
  }
}

void Heavy_PhaseRing::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x9DBB052E: { // 1057-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3BDo215S_sendMessage);
      break;
    }
    case 0xF1DE93DD: { // 1057-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Z0OzQNyf_sendMessage);
      break;
    }
    case 0x6CD381D4: { // 1057-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_X8EaeImA_sendMessage);
      break;
    }
    case 0xCF6D3C3F: { // 1057-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YkqcS6vr_sendMessage);
      break;
    }
    case 0xEDDFD30D: { // 1057-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sKEnmiHC_sendMessage);
      break;
    }
    case 0xF2BA3B2A: { // 1057-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YvGfEJ1c_sendMessage);
      break;
    }
    case 0x4408E690: { // 1093-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DEga6JdK_sendMessage);
      break;
    }
    case 0x8AB98019: { // 1093-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BHa2ZALi_sendMessage);
      break;
    }
    case 0x27A42126: { // 1101-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_c88i3DWw_sendMessage);
      break;
    }
    case 0xB5E9A65D: { // 1101-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wkRWCbd8_sendMessage);
      break;
    }
    case 0x56934ECA: { // 1101-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9yXHCQi1_sendMessage);
      break;
    }
    case 0x7514C9B6: { // 1101-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZCJv7p8u_sendMessage);
      break;
    }
    case 0xCB831B98: { // 1101-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9CHaZ2S3_sendMessage);
      break;
    }
    case 0x3A687221: { // 1101-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jgRFFnY1_sendMessage);
      break;
    }
    case 0x68EAABD0: { // 1137-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QkjQVfJG_sendMessage);
      break;
    }
    case 0x20D6E4AD: { // 1137-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5e7VaWpo_sendMessage);
      break;
    }
    case 0x4BE05FC6: { // 1137-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YcH6dYxF_sendMessage);
      break;
    }
    case 0xD8FD070D: { // 1137-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aMvG38NC_sendMessage);
      break;
    }
    case 0xC65E45B8: { // 1137-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZAYhlkdg_sendMessage);
      break;
    }
    case 0x9349BDCA: { // 1137-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hy5Ok4HN_sendMessage);
      break;
    }
    case 0x8A2C77AE: { // 1173-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_X6s6Chi8_sendMessage);
      break;
    }
    case 0xD6F86CC3: { // 1173-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5irM8S1r_sendMessage);
      break;
    }
    case 0x2A29490B: { // 1173-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gMNUY4Fc_sendMessage);
      break;
    }
    case 0xFAE8AB: { // 1173-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rr1jbxmF_sendMessage);
      break;
    }
    case 0xBFDBA4A2: { // 1173-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8hJLCNQe_sendMessage);
      break;
    }
    case 0x7638E91B: { // 1173-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Pa6oZDgY_sendMessage);
      break;
    }
    case 0x83D209A2: { // 1599-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FpAOw40q_sendMessage);
      break;
    }
    case 0x62CA542E: { // 1599-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PhvXooBG_sendMessage);
      break;
    }
    case 0xF8E41A5F: { // 1607-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XZmywEum_sendMessage);
      break;
    }
    case 0x9164CD41: { // 1607-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OSLmL3lX_sendMessage);
      break;
    }
    case 0x78060116: { // 1619-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BbkJgtRY_sendMessage);
      break;
    }
    case 0xDDEDC45: { // 1619-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yngnY8qR_sendMessage);
      break;
    }
    case 0x3FF54ADC: { // 1627-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TUCV2Tj3_sendMessage);
      break;
    }
    case 0x613389B1: { // 1627-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ptcoxQAM_sendMessage);
      break;
    }
    case 0xCA661AA: { // 1635-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sCqytfQh_sendMessage);
      break;
    }
    case 0x33695BEA: { // 1635-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6DrEvHhw_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HENPNznC_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yq4lbNbe_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fGMqgrZz_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rTu1CCrb_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dJiywmSv_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M3BAfxSp_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Gifx0eEn_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TuqPBqrR_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YK5iZytf_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_61ZJX2wL_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2dq0lZZi_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Z2WhtVyA_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IcCfKqei_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_efxuoxRF_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kAkOWUc9_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_71nqDOQo_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tWZbFbp0_sendMessage);
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


void Heavy_PhaseRing::cSlice_fESLPaAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_eDHTwBpq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_b9hIovkd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_HaTLJpF3, 0, m, &cIf_HaTLJpF3_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_6rc9zzZP, 0, m, &cIf_6rc9zzZP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_HJdEfHnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_dKxidmK3, 0, m, &cIf_dKxidmK3_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_ke39xWar, 0, m, &cIf_ke39xWar_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_oLk3LvF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_WcRPSJCO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ZxOtHAVv, 0, m, &cIf_ZxOtHAVv_sendMessage);
}

void Heavy_PhaseRing::cUnop_773DpkLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_nXCbkeLX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8AbvkA84, HV_BINOP_EQ, 1, m, &cBinop_8AbvkA84_sendMessage);
}

void Heavy_PhaseRing::cUnop_fRX1lIsy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_nXCbkeLX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8AbvkA84, HV_BINOP_EQ, 1, m, &cBinop_8AbvkA84_sendMessage);
}

void Heavy_PhaseRing::cIf_ZxOtHAVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_fRX1lIsy_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_773DpkLD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_WcRPSJCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZxOtHAVv, 1, m, &cIf_ZxOtHAVv_sendMessage);
}

void Heavy_PhaseRing::cIf_6rc9zzZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_0PxQBoCp_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_ke39xWar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_5n8Hn23c_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_HaTLJpF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_0PxQBoCp_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_dKxidmK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_5n8Hn23c_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_eDHTwBpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8AbvkA84, HV_BINOP_EQ, 0, m, &cBinop_8AbvkA84_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_UFALu4ND_sendMessage);
}

void Heavy_PhaseRing::cBinop_nXCbkeLX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UOaY1tpC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QosrKS6j_sendMessage);
}

void Heavy_PhaseRing::cBinop_8AbvkA84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dQ7QTHuV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J3ELUnys_sendMessage);
}

void Heavy_PhaseRing::cCast_dQ7QTHuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6rc9zzZP, 1, m, &cIf_6rc9zzZP_sendMessage);
}

void Heavy_PhaseRing::cCast_J3ELUnys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dKxidmK3, 1, m, &cIf_dKxidmK3_sendMessage);
}

void Heavy_PhaseRing::cCast_QosrKS6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ke39xWar, 1, m, &cIf_ke39xWar_sendMessage);
}

void Heavy_PhaseRing::cCast_UOaY1tpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HaTLJpF3, 1, m, &cIf_HaTLJpF3_sendMessage);
}

void Heavy_PhaseRing::cBinop_UFALu4ND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AcxLzwHZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_WuDYEVdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IpRWJlnH, 0, m, &cVar_IpRWJlnH_sendMessage);
}

void Heavy_PhaseRing::cBinop_s9rxYej0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_N1DR8Isv_sendMessage);
}

void Heavy_PhaseRing::cBinop_N1DR8Isv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Veb96ISV, HV_BINOP_POW, 1, m, &cBinop_Veb96ISV_sendMessage);
  cMsg_uZyn8F6Y_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Veb96ISV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_WuDYEVdQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_uZyn8F6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Veb96ISV, HV_BINOP_POW, 0, m, &cBinop_Veb96ISV_sendMessage);
}

void Heavy_PhaseRing::cBinop_uZoutv77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iKv44wZt_sendMessage);
}

void Heavy_PhaseRing::cBinop_iKv44wZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_fQhSMOnI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZjHAM8aL_sendMessage);
}

void Heavy_PhaseRing::cVar_AVwH8FVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_OgaHRgmF_sendMessage);
}

void Heavy_PhaseRing::cMsg_OnnCgHDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lYjRpes9_sendMessage);
}

void Heavy_PhaseRing::cSystem_lYjRpes9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_apyNKt9B, HV_BINOP_DIVIDE, 1, m, &cBinop_apyNKt9B_sendMessage);
}

void Heavy_PhaseRing::cBinop_fQhSMOnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_5B3Q5o5y_sendMessage);
}

void Heavy_PhaseRing::cBinop_5B3Q5o5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_G2Jqvbkg, m);
}

void Heavy_PhaseRing::cMsg_pAHaDUWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_R6GhBemc_sendMessage);
}

void Heavy_PhaseRing::cBinop_R6GhBemc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_uZoutv77_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZjHAM8aL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_el8eT63s, m);
}

void Heavy_PhaseRing::cBinop_OgaHRgmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_wMCRZFfj_sendMessage);
}

void Heavy_PhaseRing::cBinop_wMCRZFfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_apyNKt9B, HV_BINOP_DIVIDE, 0, m, &cBinop_apyNKt9B_sendMessage);
}

void Heavy_PhaseRing::cBinop_apyNKt9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pAHaDUWD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_uOv749Gl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AKfwDSmu, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_T39QJ6xn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_gVPzmwPg_sendMessage);
}

void Heavy_PhaseRing::cVar_IpRWJlnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_iZaLmucb, 0, m);
}

void Heavy_PhaseRing::cIf_jZo0co7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_yS82IvXS_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_N5uNJpM3, 0, m, &cIf_N5uNJpM3_sendMessage);
      break;
    }
    case 1: {
      cMsg_gbSts12h_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_VglWAXiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jZo0co7K, 1, m, &cIf_jZo0co7K_sendMessage);
}

void Heavy_PhaseRing::cIf_N5uNJpM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_HLSJQNKW_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_bKQFE26e_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_yS82IvXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_N5uNJpM3, 1, m, &cIf_N5uNJpM3_sendMessage);
}

void Heavy_PhaseRing::cMsg_gbSts12h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_bKQFE26e_sendMessage);
}

void Heavy_PhaseRing::cMsg_HLSJQNKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_bKQFE26e_sendMessage);
}

void Heavy_PhaseRing::cIf_rHpt0Dj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_5mWF5k0H_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_s7Dy8Bcr, 0, m, &cIf_s7Dy8Bcr_sendMessage);
      break;
    }
    case 1: {
      cMsg_7ABpJdWS_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_k5RYZylQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rHpt0Dj7, 1, m, &cIf_rHpt0Dj7_sendMessage);
}

void Heavy_PhaseRing::cIf_s7Dy8Bcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ixiontvK_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_X11oeTM0, 0, m, &cPack_X11oeTM0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_5mWF5k0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_s7Dy8Bcr, 1, m, &cIf_s7Dy8Bcr_sendMessage);
}

void Heavy_PhaseRing::cMsg_7ABpJdWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_X11oeTM0, 0, m, &cPack_X11oeTM0_sendMessage);
}

void Heavy_PhaseRing::cMsg_ixiontvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_X11oeTM0, 0, m, &cPack_X11oeTM0_sendMessage);
}

void Heavy_PhaseRing::cPack_0GAkseD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_GxvvmjH4, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_X11oeTM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_EtFH8KRx, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_uky0mP76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Pw1OFfpO, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_gVPzmwPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.1f, 0, m, &cBinop_SKhzXf4S_sendMessage);
}

void Heavy_PhaseRing::cBinop_I7chejO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T39QJ6xn, 0, m, &cVar_T39QJ6xn_sendMessage);
}

void Heavy_PhaseRing::cBinop_SKhzXf4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uOv749Gl, 0, m, &cPack_uOv749Gl_sendMessage);
}

void Heavy_PhaseRing::cBinop_bKQFE26e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_5TQaczFx_sendMessage);
}

void Heavy_PhaseRing::cBinop_5TQaczFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_k5RYZylQ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rHpt0Dj7, 0, m, &cIf_rHpt0Dj7_sendMessage);
}

void Heavy_PhaseRing::cCast_wb8RjuuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3pt1Cibe_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_8qcK4ot0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_3pt1Cibe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1cshByV6, 0, m, &cSlice_1cshByV6_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yOTsxdOn, 0, m, &cRandom_yOTsxdOn_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_yFYC68KP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_CQ4oIGNs_sendMessage);
}

void Heavy_PhaseRing::cUnop_CQ4oIGNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NMuyNgh0, 0, m, &cVar_NMuyNgh0_sendMessage);
}

void Heavy_PhaseRing::cRandom_yOTsxdOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_yFYC68KP_sendMessage);
}

void Heavy_PhaseRing::cSlice_1cshByV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yOTsxdOn, 1, m, &cRandom_yOTsxdOn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_NMuyNgh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_oasw25xH_sendMessage(_c, 0, m);
  cSend_l7P0UZgu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_8qcK4ot0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rj1k1nVG, 0, m, &cSlice_rj1k1nVG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_mGKrtgaB, 0, m, &cRandom_mGKrtgaB_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_lfo48DGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_zwNmeJjh_sendMessage);
}

void Heavy_PhaseRing::cUnop_zwNmeJjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_1di0mKU2_sendMessage);
  cSend_BS8iPDcv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cRandom_mGKrtgaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_lfo48DGu_sendMessage);
}

void Heavy_PhaseRing::cSlice_rj1k1nVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_mGKrtgaB, 1, m, &cRandom_mGKrtgaB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_p6PYCvI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vXcYdK5H_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_RLOKvk1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_nwHgQB9o_sendMessage);
}

void Heavy_PhaseRing::cBinop_nwHgQB9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RLOKvk1q, 1, m, &cVar_RLOKvk1q_sendMessage);
}

void Heavy_PhaseRing::cCast_KJdLN72A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_9blA9CGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_HM0rezZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_xx3UEuid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_P0YKaLGU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_1di0mKU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p6PYCvI5, 0, m, &cVar_p6PYCvI5_sendMessage);
}

void Heavy_PhaseRing::cSend_vXcYdK5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_efxuoxRF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_oasw25xH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TuqPBqrR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_BS8iPDcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tWZbFbp0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_l7P0UZgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kAkOWUc9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_6yqf8J1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_Z8xRwJpO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_Z8xRwJpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_M3BAfxSp_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_375wwvqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_Z8xRwJpO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_P0YKaLGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fGMqgrZz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_y1sMA4oa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MpYXfcsw, 0, m, &cSlice_MpYXfcsw_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_z0tgS2FV, 0, m, &cRandom_z0tgS2FV_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_H2xDQ4Bs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_V6196LPj_sendMessage);
}

void Heavy_PhaseRing::cUnop_V6196LPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_SanAMiCL_sendMessage);
}

void Heavy_PhaseRing::cRandom_z0tgS2FV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 900.0f, 0, m, &cBinop_H2xDQ4Bs_sendMessage);
}

void Heavy_PhaseRing::cSlice_MpYXfcsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_z0tgS2FV, 1, m, &cRandom_z0tgS2FV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_KnedFyXo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_daYKdEmm, 0, m, &cSlice_daYKdEmm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6jFB5OWM, 0, m, &cRandom_6jFB5OWM_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_IAoGI6p2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Lo1lc25X_sendMessage);
}

void Heavy_PhaseRing::cUnop_Lo1lc25X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_hmDN3oQN_sendMessage);
}

void Heavy_PhaseRing::cRandom_6jFB5OWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_IAoGI6p2_sendMessage);
}

void Heavy_PhaseRing::cSlice_daYKdEmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6jFB5OWM, 1, m, &cRandom_6jFB5OWM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_UkVz4IlR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pr0aaVBY, 0, m, &cSlice_pr0aaVBY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_D06nSaR9, 0, m, &cRandom_D06nSaR9_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_cqsDbBiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_mMi0vaE3_sendMessage);
}

void Heavy_PhaseRing::cUnop_mMi0vaE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_3Dl08eWQ_sendMessage);
}

void Heavy_PhaseRing::cRandom_D06nSaR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_cqsDbBiA_sendMessage);
}

void Heavy_PhaseRing::cSlice_pr0aaVBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_D06nSaR9, 1, m, &cRandom_D06nSaR9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ZB3SZ92J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HuLypX8p, HV_BINOP_MULTIPLY, 0, m, &cBinop_HuLypX8p_sendMessage);
}

void Heavy_PhaseRing::cBinop_Nf99722y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_HlD9pFvw_sendMessage);
}

void Heavy_PhaseRing::cBinop_HlD9pFvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b4X6z80n, HV_BINOP_POW, 1, m, &cBinop_b4X6z80n_sendMessage);
  cMsg_DCbVMHQs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_b4X6z80n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ZB3SZ92J_sendMessage);
}

void Heavy_PhaseRing::cMsg_DCbVMHQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_b4X6z80n, HV_BINOP_POW, 0, m, &cBinop_b4X6z80n_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_iw9Wl1tA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uwGwPmYh, 0, m, &cSlice_uwGwPmYh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_EfFWHMEY, 0, m, &cRandom_EfFWHMEY_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_RwZrxSXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_W06kitD1_sendMessage);
}

void Heavy_PhaseRing::cUnop_W06kitD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bvt1s0tr_sendMessage);
}

void Heavy_PhaseRing::cRandom_EfFWHMEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_RwZrxSXq_sendMessage);
}

void Heavy_PhaseRing::cSlice_uwGwPmYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_EfFWHMEY, 1, m, &cRandom_EfFWHMEY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_eXVzX7zl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lMuc2LpX, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_ki90msOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_6xhIacYm_sendMessage);
}

void Heavy_PhaseRing::cVar_B0CciSoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_EgPFXmsd, 0, m);
}

void Heavy_PhaseRing::cVar_aeh3jmMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_JsbSoQr0, 0, m);
}

void Heavy_PhaseRing::cVar_tCGKna7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ye5g0Lk5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FopyuNfg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q0SR5JZH_sendMessage);
}

void Heavy_PhaseRing::cCast_jni7BjxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_yhtWorUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_iCYW18fo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_GA0byKO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_c1fp5S7t_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_br2ubrqi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_br2ubrqi_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_slmogFXM, 1, m, &cDelay_slmogFXM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Jvuq0ZbC_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_slmogFXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_slmogFXM, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oiffz1xJ, 0, m, &cVar_oiffz1xJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_br2ubrqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_slmogFXM, 0, m, &cDelay_slmogFXM_sendMessage);
}

void Heavy_PhaseRing::cCast_Jvuq0ZbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_slmogFXM, 0, m, &cDelay_slmogFXM_sendMessage);
}

void Heavy_PhaseRing::cVar_oiffz1xJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f0odHgxm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_KHs8NlLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tCGKna7s, 0, m, &cVar_tCGKna7s_sendMessage);
}

void Heavy_PhaseRing::cMsg_nWxOcH9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_TUJl20Od_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_yZk548xJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_U7zWh1LZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_RLNzaHAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_0DrKjYGa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_tHKPUkqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Z0OzQNyf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ewU5JghP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_FeSq78Cc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_X8EaeImA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_TUJl20Od_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_U7zWh1LZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Z0OzQNyf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_0DrKjYGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_X8EaeImA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_1TISHYhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5dohWZaN, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_f0odHgxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_5dohWZaN, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_FopyuNfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oiffz1xJ, 1, m, &cVar_oiffz1xJ_sendMessage);
}

void Heavy_PhaseRing::cCast_Ye5g0Lk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1TISHYhg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_Q0SR5JZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_c1fp5S7t_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_B2xjeRE6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_5l1izt8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mNtkfsfH, 0, m, &cPack_mNtkfsfH_sendMessage);
}

void Heavy_PhaseRing::cUnop_Q8j3Tvpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_G6M7DAyn, 0, m, &cPack_G6M7DAyn_sendMessage);
}

void Heavy_PhaseRing::cPack_G6M7DAyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AZr3Sohn, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_mNtkfsfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_7MY9FA4f, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_1mC8WVZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_5l1izt8R_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_Q8j3Tvpo_sendMessage);
}

void Heavy_PhaseRing::cMsg_dE9kM7Ct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_1mC8WVZ0_sendMessage);
}

void Heavy_PhaseRing::cSlice_TB0B6sDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_e2c2sMz0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_1oOtrvBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r1GYKIfY_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Nf99722y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_3Dl08eWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_KoB0Jxv5_sendMessage);
}

void Heavy_PhaseRing::cBinop_KoB0Jxv5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_1mC8WVZ0_sendMessage);
}

void Heavy_PhaseRing::cBinop_e2c2sMz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IgzGAmQE_sendMessage(_c, 0, m);
  cSend_LOlBLG0R_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_HuLypX8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QKBCiaCN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xgiwKNDL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aeh3jmMB, 0, m, &cVar_aeh3jmMB_sendMessage);
}

void Heavy_PhaseRing::cBinop_bvt1s0tr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_0oW3zxvz_sendMessage);
}

void Heavy_PhaseRing::cBinop_0oW3zxvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HuLypX8p, HV_BINOP_MULTIPLY, 1, m, &cBinop_HuLypX8p_sendMessage);
}

void Heavy_PhaseRing::cCast_r1GYKIfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_iw9Wl1tA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_IgzGAmQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YvGfEJ1c_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_xgiwKNDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UkVz4IlR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_QKBCiaCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KHs8NlLk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B2xjeRE6_sendMessage);
}

void Heavy_PhaseRing::cBinop_6xhIacYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_eXVzX7zl, 0, m, &cPack_eXVzX7zl_sendMessage);
}

void Heavy_PhaseRing::cSend_LOlBLG0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YkqcS6vr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_GjgHcMeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sKEnmiHC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_rKg4gXdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_GjgHcMeJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_Fr8DHrvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oOQZ7QfF_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WaMDSsYk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TKwvTsTZ_sendMessage);
}

void Heavy_PhaseRing::cIf_L9E5HDnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_QwqvuqPE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_cqBlTdJ2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_o5Ubb2yf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DLvH69KX, HV_BINOP_POW, 0, m, &cBinop_DLvH69KX_sendMessage);
}

void Heavy_PhaseRing::cBinop_DLvH69KX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mP4042xs, 0, m, &cPack_mP4042xs_sendMessage);
}

void Heavy_PhaseRing::cBinop_QT5Y5hzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_0ffT7gOf_sendMessage);
}

void Heavy_PhaseRing::cCast_WaMDSsYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_1O6lfxgz_sendMessage);
}

void Heavy_PhaseRing::cCast_TKwvTsTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_L9E5HDnV, 0, m, &cIf_L9E5HDnV_sendMessage);
}

void Heavy_PhaseRing::cBinop_1O6lfxgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_L9E5HDnV, 1, m, &cIf_L9E5HDnV_sendMessage);
}

void Heavy_PhaseRing::cBinop_cqBlTdJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_QT5Y5hzZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_QwqvuqPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_mP4042xs, 0, m, &cPack_mP4042xs_sendMessage);
}

void Heavy_PhaseRing::cBinop_0ffT7gOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DLvH69KX, HV_BINOP_POW, 1, m, &cBinop_DLvH69KX_sendMessage);
  cMsg_o5Ubb2yf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_mP4042xs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wpWPBc00, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_SxmeRZcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AgxKYfDD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_oOQZ7QfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_EnSCmUHy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_EnSCmUHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DEga6JdK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_AgxKYfDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BHa2ZALi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_cWtHVegW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DAZ7WZ5L, 0, m, &cSlice_DAZ7WZ5L_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0s8J6h5N, 0, m, &cRandom_0s8J6h5N_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_bAd2jkZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Z8MMrJ1J_sendMessage);
}

void Heavy_PhaseRing::cUnop_Z8MMrJ1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_Jo02v8oF_sendMessage);
}

void Heavy_PhaseRing::cRandom_0s8J6h5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_bAd2jkZl_sendMessage);
}

void Heavy_PhaseRing::cSlice_DAZ7WZ5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0s8J6h5N, 1, m, &cRandom_0s8J6h5N_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_p6SOlxuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hh9Lg0ob, HV_BINOP_MULTIPLY, 0, m, &cBinop_hh9Lg0ob_sendMessage);
}

void Heavy_PhaseRing::cBinop_s6YI8hLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_wfN8KllO_sendMessage);
}

void Heavy_PhaseRing::cBinop_wfN8KllO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m0DKXse3, HV_BINOP_POW, 1, m, &cBinop_m0DKXse3_sendMessage);
  cMsg_VssciE9d_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_m0DKXse3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_p6SOlxuh_sendMessage);
}

void Heavy_PhaseRing::cMsg_VssciE9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_m0DKXse3, HV_BINOP_POW, 0, m, &cBinop_m0DKXse3_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_OUCvYFCJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GHKKrCoP, 0, m, &cSlice_GHKKrCoP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jyJXKuPh, 0, m, &cRandom_jyJXKuPh_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_MjDFid1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WVUFZ8Mg_sendMessage);
}

void Heavy_PhaseRing::cUnop_WVUFZ8Mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_96cKXfvP_sendMessage);
}

void Heavy_PhaseRing::cRandom_jyJXKuPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_MjDFid1D_sendMessage);
}

void Heavy_PhaseRing::cSlice_GHKKrCoP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jyJXKuPh, 1, m, &cRandom_jyJXKuPh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_gwsNKHJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9TgWPYcF, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_ufiHiFwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_RbWegi0B_sendMessage);
}

void Heavy_PhaseRing::cVar_lpwvnreK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_tZkOHd5D, 0, m);
}

void Heavy_PhaseRing::cVar_CH0iC2F4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_d6rQIE5W, 0, m);
}

void Heavy_PhaseRing::cVar_O90gOwiw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZYOeMepi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nAR7YLSM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fFBLcNsI_sendMessage);
}

void Heavy_PhaseRing::cCast_KZadLGEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_zm14CA7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_Nk37ur1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_JoKps3gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_d4kM0cP4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_mmEgKhP1_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_mmEgKhP1_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_G0djwFKA, 1, m, &cDelay_G0djwFKA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AldCySp1_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_G0djwFKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_G0djwFKA, m);
  cVar_onMessage(_c, &Context(_c)->cVar_B3HgcL3Z, 0, m, &cVar_B3HgcL3Z_sendMessage);
}

void Heavy_PhaseRing::cMsg_mmEgKhP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_G0djwFKA, 0, m, &cDelay_G0djwFKA_sendMessage);
}

void Heavy_PhaseRing::cCast_AldCySp1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_G0djwFKA, 0, m, &cDelay_G0djwFKA_sendMessage);
}

void Heavy_PhaseRing::cVar_B3HgcL3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_la7NwVKq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_ZuYaEEGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O90gOwiw, 0, m, &cVar_O90gOwiw_sendMessage);
}

void Heavy_PhaseRing::cMsg_3IltbDzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_HMkVMFen_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_LI6ItjUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_PQXeZXnU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_xCZ6fCAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_K0KfGSCy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_dnzqWiEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wkRWCbd8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_5G9vXvBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_1GjbBA4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9yXHCQi1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_HMkVMFen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_PQXeZXnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wkRWCbd8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_K0KfGSCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9yXHCQi1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ouhOMCF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_E4GJw2Mv, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_la7NwVKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_E4GJw2Mv, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_ZYOeMepi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ouhOMCF5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_fFBLcNsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_d4kM0cP4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_nAR7YLSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_B3HgcL3Z, 1, m, &cVar_B3HgcL3Z_sendMessage);
}

void Heavy_PhaseRing::cCast_eiog93lu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_rKHcjUWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sTT0onN4, 0, m, &cPack_sTT0onN4_sendMessage);
}

void Heavy_PhaseRing::cUnop_zMrP9Jpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kK7BQrkZ, 0, m, &cPack_kK7BQrkZ_sendMessage);
}

void Heavy_PhaseRing::cPack_kK7BQrkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_row2Xprb, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_sTT0onN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_p6RLl9ed, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_x0NtBP1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_rKHcjUWG_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_zMrP9Jpp_sendMessage);
}

void Heavy_PhaseRing::cMsg_hPtYbyiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_x0NtBP1Q_sendMessage);
}

void Heavy_PhaseRing::cSlice_7K9E3PAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_UvN8nmFZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_nXPk7n3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7kAM8hFi_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_s6YI8hLG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Jo02v8oF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_Kdef5bJ5_sendMessage);
}

void Heavy_PhaseRing::cBinop_Kdef5bJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_x0NtBP1Q_sendMessage);
}

void Heavy_PhaseRing::cBinop_UvN8nmFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kVUcs9TS_sendMessage(_c, 0, m);
  cSend_HsiMjYqg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_hh9Lg0ob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gtbTMgWk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tvnndVBI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CH0iC2F4, 0, m, &cVar_CH0iC2F4_sendMessage);
}

void Heavy_PhaseRing::cBinop_96cKXfvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_t6pbFIJT_sendMessage);
}

void Heavy_PhaseRing::cBinop_t6pbFIJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hh9Lg0ob, HV_BINOP_MULTIPLY, 1, m, &cBinop_hh9Lg0ob_sendMessage);
}

void Heavy_PhaseRing::cCast_7kAM8hFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OUCvYFCJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_kVUcs9TS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jgRFFnY1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_gtbTMgWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZuYaEEGw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eiog93lu_sendMessage);
}

void Heavy_PhaseRing::cCast_tvnndVBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cWtHVegW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_RbWegi0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gwsNKHJW, 0, m, &cPack_gwsNKHJW_sendMessage);
}

void Heavy_PhaseRing::cSend_HsiMjYqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZCJv7p8u_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_U1I26uHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9CHaZ2S3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_xBba5blE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_U1I26uHj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_jkZqnBME_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3HWQJil1, 0, m, &cSlice_3HWQJil1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LyND3D5l, 0, m, &cRandom_LyND3D5l_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_F68iLOWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_DzxYoOOi_sendMessage);
}

void Heavy_PhaseRing::cUnop_DzxYoOOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_ZQMdO5lc_sendMessage);
}

void Heavy_PhaseRing::cRandom_LyND3D5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_F68iLOWO_sendMessage);
}

void Heavy_PhaseRing::cSlice_3HWQJil1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LyND3D5l, 1, m, &cRandom_LyND3D5l_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_iSqg8pKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uhsGmRCa, HV_BINOP_MULTIPLY, 0, m, &cBinop_uhsGmRCa_sendMessage);
}

void Heavy_PhaseRing::cBinop_w6Fc7EqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_84YTHvAw_sendMessage);
}

void Heavy_PhaseRing::cBinop_84YTHvAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SARqOKXv, HV_BINOP_POW, 1, m, &cBinop_SARqOKXv_sendMessage);
  cMsg_rHXWbf22_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_SARqOKXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_iSqg8pKr_sendMessage);
}

void Heavy_PhaseRing::cMsg_rHXWbf22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SARqOKXv, HV_BINOP_POW, 0, m, &cBinop_SARqOKXv_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_64LwvzNW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_cp7Eti07, 0, m, &cSlice_cp7Eti07_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_krw64aD6, 0, m, &cRandom_krw64aD6_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_soMgBvse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uvRIxrYs_sendMessage);
}

void Heavy_PhaseRing::cUnop_uvRIxrYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7mHpiAKM_sendMessage);
}

void Heavy_PhaseRing::cRandom_krw64aD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_soMgBvse_sendMessage);
}

void Heavy_PhaseRing::cSlice_cp7Eti07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_krw64aD6, 1, m, &cRandom_krw64aD6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_cCvAVVBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_vWrAVoai, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_zkjD0wpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_YmVxXi9l_sendMessage);
}

void Heavy_PhaseRing::cVar_6ImolnSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_UGOv6nYl, 0, m);
}

void Heavy_PhaseRing::cVar_kBSqCQh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_AtdoyN25, 0, m);
}

void Heavy_PhaseRing::cVar_OTKaE5wW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FMrEpqpY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XLGF1cow_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PXq3C4CW_sendMessage);
}

void Heavy_PhaseRing::cCast_7897oTc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_Jh0tlPo6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_hUmtzh86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_QvV1vCLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_PeGT7DQr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_CrvkIKSE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_CrvkIKSE_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_dHfwNaFZ, 1, m, &cDelay_dHfwNaFZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_trfZiNBp_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_dHfwNaFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dHfwNaFZ, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HE80rZF0, 0, m, &cVar_HE80rZF0_sendMessage);
}

void Heavy_PhaseRing::cMsg_CrvkIKSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_dHfwNaFZ, 0, m, &cDelay_dHfwNaFZ_sendMessage);
}

void Heavy_PhaseRing::cCast_trfZiNBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dHfwNaFZ, 0, m, &cDelay_dHfwNaFZ_sendMessage);
}

void Heavy_PhaseRing::cVar_HE80rZF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9kGR2ZRk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_ujNhjm3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OTKaE5wW, 0, m, &cVar_OTKaE5wW_sendMessage);
}

void Heavy_PhaseRing::cMsg_klBygAGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_cpIXgNXB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_iyaogXMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_kmyMKlGI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_A2uOzC7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_nmU2AMep_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_EbzD5B1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5e7VaWpo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_pPCzKJWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_ku4kcs9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YcH6dYxF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_cpIXgNXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_kmyMKlGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5e7VaWpo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_nmU2AMep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YcH6dYxF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_MQLUCWV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_bQ4nxFJs, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_9kGR2ZRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_bQ4nxFJs, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_PXq3C4CW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PeGT7DQr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_XLGF1cow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HE80rZF0, 1, m, &cVar_HE80rZF0_sendMessage);
}

void Heavy_PhaseRing::cCast_FMrEpqpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MQLUCWV1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_obuANYTA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_vhP5Blbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ndNS47ij, 0, m, &cPack_ndNS47ij_sendMessage);
}

void Heavy_PhaseRing::cUnop_Mcv3If4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4413kkSB, 0, m, &cPack_4413kkSB_sendMessage);
}

void Heavy_PhaseRing::cPack_4413kkSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_4FWNfVUv, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_ndNS47ij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_3nVSm8o5, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_ayRjR42N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_vhP5Blbo_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_Mcv3If4T_sendMessage);
}

void Heavy_PhaseRing::cMsg_7SK4q6xt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_ayRjR42N_sendMessage);
}

void Heavy_PhaseRing::cSlice_1REj9Ufc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_FhgBzBFN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_JxMOWpkk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wBX6MyLz_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_w6Fc7EqG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ZQMdO5lc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_kkVHovd6_sendMessage);
}

void Heavy_PhaseRing::cBinop_kkVHovd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_ayRjR42N_sendMessage);
}

void Heavy_PhaseRing::cBinop_FhgBzBFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3xE5Af4l_sendMessage(_c, 0, m);
  cSend_MRlTw5Or_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_uhsGmRCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SrcFvhsA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q9vW36kQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kBSqCQh0, 0, m, &cVar_kBSqCQh0_sendMessage);
}

void Heavy_PhaseRing::cBinop_7mHpiAKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_HqsqhIxL_sendMessage);
}

void Heavy_PhaseRing::cBinop_HqsqhIxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uhsGmRCa, HV_BINOP_MULTIPLY, 1, m, &cBinop_uhsGmRCa_sendMessage);
}

void Heavy_PhaseRing::cCast_wBX6MyLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_64LwvzNW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_3xE5Af4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hy5Ok4HN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_SrcFvhsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ujNhjm3d_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_obuANYTA_sendMessage);
}

void Heavy_PhaseRing::cCast_Q9vW36kQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jkZqnBME_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_YmVxXi9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cCvAVVBM, 0, m, &cPack_cCvAVVBM_sendMessage);
}

void Heavy_PhaseRing::cSend_MRlTw5Or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aMvG38NC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_3vvry3sB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZAYhlkdg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_4qXQKdIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_3vvry3sB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_yGR595p2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FUvhFPRh, 0, m, &cSlice_FUvhFPRh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TagL0VcW, 0, m, &cRandom_TagL0VcW_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ta6pnGe6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BJX7Crde_sendMessage);
}

void Heavy_PhaseRing::cUnop_BJX7Crde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_SFwDzmAA_sendMessage);
}

void Heavy_PhaseRing::cRandom_TagL0VcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_ta6pnGe6_sendMessage);
}

void Heavy_PhaseRing::cSlice_FUvhFPRh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TagL0VcW, 1, m, &cRandom_TagL0VcW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_PEwfwy93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VEvUdUVk, HV_BINOP_MULTIPLY, 0, m, &cBinop_VEvUdUVk_sendMessage);
}

void Heavy_PhaseRing::cBinop_i9OIvEgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_lmZ9oGVo_sendMessage);
}

void Heavy_PhaseRing::cBinop_lmZ9oGVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hWrYNI9j, HV_BINOP_POW, 1, m, &cBinop_hWrYNI9j_sendMessage);
  cMsg_bCvOD1d4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_hWrYNI9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_PEwfwy93_sendMessage);
}

void Heavy_PhaseRing::cMsg_bCvOD1d4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hWrYNI9j, HV_BINOP_POW, 0, m, &cBinop_hWrYNI9j_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_vzwN8v0e_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tCirdl9S, 0, m, &cSlice_tCirdl9S_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tTn8LC2z, 0, m, &cRandom_tTn8LC2z_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_w6HNu51b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_IyQoeEfN_sendMessage);
}

void Heavy_PhaseRing::cUnop_IyQoeEfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cnTuipHR_sendMessage);
}

void Heavy_PhaseRing::cRandom_tTn8LC2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_w6HNu51b_sendMessage);
}

void Heavy_PhaseRing::cSlice_tCirdl9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tTn8LC2z, 1, m, &cRandom_tTn8LC2z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_9bkU2OkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VEngK9mt, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_JJw23vMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_EAEsqShM_sendMessage);
}

void Heavy_PhaseRing::cVar_AXliokcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_wuO8mb2C, 0, m);
}

void Heavy_PhaseRing::cVar_nOfN1rxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_C8Rogm34, 0, m);
}

void Heavy_PhaseRing::cVar_C0FrBgZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jYLB8PMN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Yw4nctFa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OyWt2efE_sendMessage);
}

void Heavy_PhaseRing::cCast_0zpP2rym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_uLsZ590T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_PK4N2nxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_60z9JOad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_NXkSSDrR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Nwk2yjaW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Nwk2yjaW_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_LcpMfb2k, 1, m, &cDelay_LcpMfb2k_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7T3ajofG_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_LcpMfb2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LcpMfb2k, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TlZSlvaI, 0, m, &cVar_TlZSlvaI_sendMessage);
}

void Heavy_PhaseRing::cMsg_Nwk2yjaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LcpMfb2k, 0, m, &cDelay_LcpMfb2k_sendMessage);
}

void Heavy_PhaseRing::cCast_7T3ajofG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LcpMfb2k, 0, m, &cDelay_LcpMfb2k_sendMessage);
}

void Heavy_PhaseRing::cVar_TlZSlvaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pb0MJOFj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_1HBVHhOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C0FrBgZs, 0, m, &cVar_C0FrBgZs_sendMessage);
}

void Heavy_PhaseRing::cMsg_W5p6L1Zp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_KveFEvYU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ip2GIbYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_cAVS0XFc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_CEqTWvNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_o5j2mtos_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_X5WJTuDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5irM8S1r_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_WiHSg4RG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_gznHaRdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gMNUY4Fc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_KveFEvYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_cAVS0XFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5irM8S1r_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_o5j2mtos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gMNUY4Fc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_KJFN7SiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Ef22l1vd, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_pb0MJOFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_Ef22l1vd, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_OyWt2efE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NXkSSDrR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_Yw4nctFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TlZSlvaI, 1, m, &cVar_TlZSlvaI_sendMessage);
}

void Heavy_PhaseRing::cCast_jYLB8PMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KJFN7SiB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_JjQA7IJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_UrwavxY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DpcKOTfm, 0, m, &cPack_DpcKOTfm_sendMessage);
}

void Heavy_PhaseRing::cUnop_W2Cb8M33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ANGMXssE, 0, m, &cPack_ANGMXssE_sendMessage);
}

void Heavy_PhaseRing::cPack_ANGMXssE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_WtRayAnr, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_DpcKOTfm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TFJwJV7E, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_ZiE8HsiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_UrwavxY6_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_W2Cb8M33_sendMessage);
}

void Heavy_PhaseRing::cMsg_9LGFCW2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_ZiE8HsiF_sendMessage);
}

void Heavy_PhaseRing::cSlice_LdSRsq9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_T2MpJdIZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_g0j3JeDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xg5NB1DT_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_i9OIvEgZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_SFwDzmAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_dE8Xmq4g_sendMessage);
}

void Heavy_PhaseRing::cBinop_dE8Xmq4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_ZiE8HsiF_sendMessage);
}

void Heavy_PhaseRing::cBinop_T2MpJdIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MGSoFWKC_sendMessage(_c, 0, m);
  cSend_MLdiP4xx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_VEvUdUVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TeXDJGU3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UgvhjVNP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nOfN1rxA, 0, m, &cVar_nOfN1rxA_sendMessage);
}

void Heavy_PhaseRing::cBinop_cnTuipHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_f0b6qyEX_sendMessage);
}

void Heavy_PhaseRing::cBinop_f0b6qyEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VEvUdUVk, HV_BINOP_MULTIPLY, 1, m, &cBinop_VEvUdUVk_sendMessage);
}

void Heavy_PhaseRing::cCast_xg5NB1DT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vzwN8v0e_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_MGSoFWKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Pa6oZDgY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_TeXDJGU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1HBVHhOY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JjQA7IJJ_sendMessage);
}

void Heavy_PhaseRing::cCast_UgvhjVNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yGR595p2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_EAEsqShM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9bkU2OkU, 0, m, &cPack_9bkU2OkU_sendMessage);
}

void Heavy_PhaseRing::cSend_MLdiP4xx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rr1jbxmF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_IGwzy6jR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8hJLCNQe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_cTlD1QQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_IGwzy6jR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cTabhead_DJsKyvZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6V3WfN98, HV_BINOP_SUBTRACT, 0, m, &cBinop_6V3WfN98_sendMessage);
}

void Heavy_PhaseRing::cMsg_1cVh67FZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eB6zIXdC_sendMessage);
}

void Heavy_PhaseRing::cSystem_eB6zIXdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_l6MwGdbF_sendMessage);
}

void Heavy_PhaseRing::cVar_Yjke4BbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HoQxfn4K_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_c45GUcCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c45GUcCy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4mzlX5Fx, 0, m, &cDelay_4mzlX5Fx_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ss8XATiQ, 0, m, &sTabread_ss8XATiQ_sendMessage);
}

void Heavy_PhaseRing::cDelay_4mzlX5Fx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4mzlX5Fx, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ss8XATiQ, 0, m, &sTabread_ss8XATiQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4mzlX5Fx, 0, m, &cDelay_4mzlX5Fx_sendMessage);
}

void Heavy_PhaseRing::sTabread_ss8XATiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qKkAbzEu, HV_BINOP_SUBTRACT, 0, m, &cBinop_qKkAbzEu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_eSLhp8Nh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6XDlta6G, HV_BINOP_MAX, 0, m, &cBinop_6XDlta6G_sendMessage);
}

void Heavy_PhaseRing::cBinop_l6MwGdbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eSLhp8Nh, HV_BINOP_MULTIPLY, 0, m, &cBinop_eSLhp8Nh_sendMessage);
}

void Heavy_PhaseRing::cBinop_6V3WfN98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nKmjv8Zw_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ss8XATiQ, 0, m, &sTabread_ss8XATiQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZGsQXkyr_sendMessage);
}

void Heavy_PhaseRing::cSystem_rl0eCrNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qKkAbzEu, HV_BINOP_SUBTRACT, 1, m, &cBinop_qKkAbzEu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4mzlX5Fx, 2, m, &cDelay_4mzlX5Fx_sendMessage);
}

void Heavy_PhaseRing::cMsg_HoQxfn4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rl0eCrNf_sendMessage);
}

void Heavy_PhaseRing::cMsg_nKmjv8Zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_c45GUcCy, 0, m, &cDelay_c45GUcCy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4mzlX5Fx, 0, m, &cDelay_4mzlX5Fx_sendMessage);
}

void Heavy_PhaseRing::cMsg_uX0QHHzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_6XDlta6G, HV_BINOP_MAX, 1, m, &cBinop_6XDlta6G_sendMessage);
}

void Heavy_PhaseRing::cBinop_6XDlta6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6V3WfN98, HV_BINOP_SUBTRACT, 1, m, &cBinop_6V3WfN98_sendMessage);
}

void Heavy_PhaseRing::cCast_ZGsQXkyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_c45GUcCy, 0, m, &cDelay_c45GUcCy_sendMessage);
}

void Heavy_PhaseRing::cBinop_bPClrQxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_c45GUcCy, 2, m, &cDelay_c45GUcCy_sendMessage);
}

void Heavy_PhaseRing::cBinop_qKkAbzEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bPClrQxQ_sendMessage);
}

void Heavy_PhaseRing::cCast_g7uexQHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yjke4BbL, 0, m, &cVar_Yjke4BbL_sendMessage);
  cMsg_1cVh67FZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DJsKyvZW, 0, m, &cTabhead_DJsKyvZW_sendMessage);
}

void Heavy_PhaseRing::cTabhead_9Tb2rOGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A0RCIHcC, HV_BINOP_SUBTRACT, 0, m, &cBinop_A0RCIHcC_sendMessage);
}

void Heavy_PhaseRing::cMsg_Az6vd0lE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dciuanJJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_dciuanJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BUo6ktWT_sendMessage);
}

void Heavy_PhaseRing::cVar_Hj03nxtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DzcZ17Lu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_T17osNCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_T17osNCo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Egp4MSTy, 0, m, &cDelay_Egp4MSTy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EcCksb3G, 0, m, &sTabread_EcCksb3G_sendMessage);
}

void Heavy_PhaseRing::cDelay_Egp4MSTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Egp4MSTy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EcCksb3G, 0, m, &sTabread_EcCksb3G_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Egp4MSTy, 0, m, &cDelay_Egp4MSTy_sendMessage);
}

void Heavy_PhaseRing::sTabread_EcCksb3G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zN1f21Z2, HV_BINOP_SUBTRACT, 0, m, &cBinop_zN1f21Z2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_v8Ncjv1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xKZhgHuJ, HV_BINOP_MAX, 0, m, &cBinop_xKZhgHuJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_BUo6ktWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v8Ncjv1c, HV_BINOP_MULTIPLY, 0, m, &cBinop_v8Ncjv1c_sendMessage);
}

void Heavy_PhaseRing::cBinop_A0RCIHcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a5SUxL1d_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EcCksb3G, 0, m, &sTabread_EcCksb3G_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CPQ7klrc_sendMessage);
}

void Heavy_PhaseRing::cSystem_1d8G2y2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zN1f21Z2, HV_BINOP_SUBTRACT, 1, m, &cBinop_zN1f21Z2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Egp4MSTy, 2, m, &cDelay_Egp4MSTy_sendMessage);
}

void Heavy_PhaseRing::cMsg_DzcZ17Lu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1d8G2y2E_sendMessage);
}

void Heavy_PhaseRing::cMsg_a5SUxL1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_T17osNCo, 0, m, &cDelay_T17osNCo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Egp4MSTy, 0, m, &cDelay_Egp4MSTy_sendMessage);
}

void Heavy_PhaseRing::cMsg_9CK2VThX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_xKZhgHuJ, HV_BINOP_MAX, 1, m, &cBinop_xKZhgHuJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_xKZhgHuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A0RCIHcC, HV_BINOP_SUBTRACT, 1, m, &cBinop_A0RCIHcC_sendMessage);
}

void Heavy_PhaseRing::cCast_CPQ7klrc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_T17osNCo, 0, m, &cDelay_T17osNCo_sendMessage);
}

void Heavy_PhaseRing::cBinop_Hs37v6Y7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_T17osNCo, 2, m, &cDelay_T17osNCo_sendMessage);
}

void Heavy_PhaseRing::cBinop_zN1f21Z2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Hs37v6Y7_sendMessage);
}

void Heavy_PhaseRing::cCast_lqmi0qxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hj03nxtc, 0, m, &cVar_Hj03nxtc_sendMessage);
  cMsg_Az6vd0lE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9Tb2rOGi, 0, m, &cTabhead_9Tb2rOGi_sendMessage);
}

void Heavy_PhaseRing::cTabhead_zniqSSRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XyTrasPt, HV_BINOP_SUBTRACT, 0, m, &cBinop_XyTrasPt_sendMessage);
}

void Heavy_PhaseRing::cMsg_oP1U5t7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mUHPSxVM_sendMessage);
}

void Heavy_PhaseRing::cSystem_mUHPSxVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RNEiG9yg_sendMessage);
}

void Heavy_PhaseRing::cVar_ogPat2Qz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_18lm9Squ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_eVOYlF6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eVOYlF6w, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uVYPyhOm, 0, m, &cDelay_uVYPyhOm_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Vy8XwgvI, 0, m, &sTabread_Vy8XwgvI_sendMessage);
}

void Heavy_PhaseRing::cDelay_uVYPyhOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uVYPyhOm, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Vy8XwgvI, 0, m, &sTabread_Vy8XwgvI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uVYPyhOm, 0, m, &cDelay_uVYPyhOm_sendMessage);
}

void Heavy_PhaseRing::sTabread_Vy8XwgvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_n2PXWp1e, HV_BINOP_SUBTRACT, 0, m, &cBinop_n2PXWp1e_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_RnWkkfJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pbNImcnC, HV_BINOP_MAX, 0, m, &cBinop_pbNImcnC_sendMessage);
}

void Heavy_PhaseRing::cBinop_RNEiG9yg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RnWkkfJl, HV_BINOP_MULTIPLY, 0, m, &cBinop_RnWkkfJl_sendMessage);
}

void Heavy_PhaseRing::cBinop_XyTrasPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_523r6K3N_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Vy8XwgvI, 0, m, &sTabread_Vy8XwgvI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oVUvRALg_sendMessage);
}

void Heavy_PhaseRing::cSystem_6RMnzUqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n2PXWp1e, HV_BINOP_SUBTRACT, 1, m, &cBinop_n2PXWp1e_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uVYPyhOm, 2, m, &cDelay_uVYPyhOm_sendMessage);
}

void Heavy_PhaseRing::cMsg_18lm9Squ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6RMnzUqH_sendMessage);
}

void Heavy_PhaseRing::cMsg_523r6K3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_eVOYlF6w, 0, m, &cDelay_eVOYlF6w_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uVYPyhOm, 0, m, &cDelay_uVYPyhOm_sendMessage);
}

void Heavy_PhaseRing::cMsg_Xphg4P4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_pbNImcnC, HV_BINOP_MAX, 1, m, &cBinop_pbNImcnC_sendMessage);
}

void Heavy_PhaseRing::cBinop_pbNImcnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XyTrasPt, HV_BINOP_SUBTRACT, 1, m, &cBinop_XyTrasPt_sendMessage);
}

void Heavy_PhaseRing::cCast_oVUvRALg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eVOYlF6w, 0, m, &cDelay_eVOYlF6w_sendMessage);
}

void Heavy_PhaseRing::cBinop_MPLCKwNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eVOYlF6w, 2, m, &cDelay_eVOYlF6w_sendMessage);
}

void Heavy_PhaseRing::cBinop_n2PXWp1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MPLCKwNv_sendMessage);
}

void Heavy_PhaseRing::cCast_tLGPVeJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ogPat2Qz, 0, m, &cVar_ogPat2Qz_sendMessage);
  cMsg_oP1U5t7E_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zniqSSRx, 0, m, &cTabhead_zniqSSRx_sendMessage);
}

void Heavy_PhaseRing::cTabhead_BMwEKgwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kJHN8eD5, HV_BINOP_SUBTRACT, 0, m, &cBinop_kJHN8eD5_sendMessage);
}

void Heavy_PhaseRing::cMsg_pZxnaOU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_i6fP1hWP_sendMessage);
}

void Heavy_PhaseRing::cSystem_i6fP1hWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rjVwLD4p_sendMessage);
}

void Heavy_PhaseRing::cVar_5VImFzOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LHpsMEzN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_lt8BFQko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lt8BFQko, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lYAeeO0V, 0, m, &cDelay_lYAeeO0V_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_pEThncXJ, 0, m, &sTabread_pEThncXJ_sendMessage);
}

void Heavy_PhaseRing::cDelay_lYAeeO0V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lYAeeO0V, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_pEThncXJ, 0, m, &sTabread_pEThncXJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lYAeeO0V, 0, m, &cDelay_lYAeeO0V_sendMessage);
}

void Heavy_PhaseRing::sTabread_pEThncXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_FdWMcc6H, HV_BINOP_SUBTRACT, 0, m, &cBinop_FdWMcc6H_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_4XNhEbkI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mb7NjzHS, HV_BINOP_MAX, 0, m, &cBinop_Mb7NjzHS_sendMessage);
}

void Heavy_PhaseRing::cBinop_rjVwLD4p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4XNhEbkI, HV_BINOP_MULTIPLY, 0, m, &cBinop_4XNhEbkI_sendMessage);
}

void Heavy_PhaseRing::cBinop_kJHN8eD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v75m3q1U_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_pEThncXJ, 0, m, &sTabread_pEThncXJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IIozbyTf_sendMessage);
}

void Heavy_PhaseRing::cSystem_ibrhMOUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FdWMcc6H, HV_BINOP_SUBTRACT, 1, m, &cBinop_FdWMcc6H_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lYAeeO0V, 2, m, &cDelay_lYAeeO0V_sendMessage);
}

void Heavy_PhaseRing::cMsg_LHpsMEzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ibrhMOUm_sendMessage);
}

void Heavy_PhaseRing::cMsg_v75m3q1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_lt8BFQko, 0, m, &cDelay_lt8BFQko_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lYAeeO0V, 0, m, &cDelay_lYAeeO0V_sendMessage);
}

void Heavy_PhaseRing::cMsg_PoKXTLjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mb7NjzHS, HV_BINOP_MAX, 1, m, &cBinop_Mb7NjzHS_sendMessage);
}

void Heavy_PhaseRing::cBinop_Mb7NjzHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kJHN8eD5, HV_BINOP_SUBTRACT, 1, m, &cBinop_kJHN8eD5_sendMessage);
}

void Heavy_PhaseRing::cCast_IIozbyTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lt8BFQko, 0, m, &cDelay_lt8BFQko_sendMessage);
}

void Heavy_PhaseRing::cBinop_qaFksjSK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lt8BFQko, 2, m, &cDelay_lt8BFQko_sendMessage);
}

void Heavy_PhaseRing::cBinop_FdWMcc6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qaFksjSK_sendMessage);
}

void Heavy_PhaseRing::cCast_4B5MsIpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5VImFzOw, 0, m, &cVar_5VImFzOw_sendMessage);
  cMsg_pZxnaOU2_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BMwEKgwi, 0, m, &cTabhead_BMwEKgwi_sendMessage);
}

void Heavy_PhaseRing::cMsg_TPAwYdYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ctKkI1RX_sendMessage);
}

void Heavy_PhaseRing::cSystem_ctKkI1RX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ehUUxKDn_sendMessage);
}

void Heavy_PhaseRing::cDelay_7sqWRCHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7sqWRCHh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zxrno3az, 0, m, &cDelay_zxrno3az_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7sqWRCHh, 0, m, &cDelay_7sqWRCHh_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Zr3OBmyJ, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_zxrno3az_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zxrno3az, m);
  cMsg_hd8gDJKl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_sdv8EtjY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_KG9yFf7l_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_haRj9dSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mP76YHgo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_whMXIRQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gUMn2zgH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7sqWRCHh, 2, m, &cDelay_7sqWRCHh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EFpqHwyn_sendMessage);
}

void Heavy_PhaseRing::cMsg_mP76YHgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_whMXIRQ3, 0, m, &hTable_whMXIRQ3_sendMessage);
}

void Heavy_PhaseRing::cBinop_ehUUxKDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_haRj9dSb_sendMessage);
}

void Heavy_PhaseRing::cMsg_hd8gDJKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_whMXIRQ3, 0, m, &hTable_whMXIRQ3_sendMessage);
}

void Heavy_PhaseRing::cCast_EFpqHwyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7sqWRCHh, 0, m, &cDelay_7sqWRCHh_sendMessage);
}

void Heavy_PhaseRing::cMsg_gUMn2zgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_zxrno3az, 2, m, &cDelay_zxrno3az_sendMessage);
}

void Heavy_PhaseRing::cMsg_KG9yFf7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Zr3OBmyJ, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_mLEPgkdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yb5LLerL_sendMessage);
}

void Heavy_PhaseRing::cSystem_yb5LLerL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fqbmlruQ_sendMessage);
}

void Heavy_PhaseRing::cDelay_RtQ0NIXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RtQ0NIXs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oEmR4ike, 0, m, &cDelay_oEmR4ike_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RtQ0NIXs, 0, m, &cDelay_RtQ0NIXs_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_v4qRoaUZ, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_oEmR4ike_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oEmR4ike, m);
  cMsg_tlfqEzyU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_mpHWDNyE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4U6UnmME_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_HeIZPyG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g5FmajGp_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_lsVeKNp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pGrIaSwY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RtQ0NIXs, 2, m, &cDelay_RtQ0NIXs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aYb7u3Ea_sendMessage);
}

void Heavy_PhaseRing::cMsg_g5FmajGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_lsVeKNp4, 0, m, &hTable_lsVeKNp4_sendMessage);
}

void Heavy_PhaseRing::cBinop_fqbmlruQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_HeIZPyG3_sendMessage);
}

void Heavy_PhaseRing::cMsg_tlfqEzyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_lsVeKNp4, 0, m, &hTable_lsVeKNp4_sendMessage);
}

void Heavy_PhaseRing::cCast_aYb7u3Ea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RtQ0NIXs, 0, m, &cDelay_RtQ0NIXs_sendMessage);
}

void Heavy_PhaseRing::cMsg_pGrIaSwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_oEmR4ike, 2, m, &cDelay_oEmR4ike_sendMessage);
}

void Heavy_PhaseRing::cMsg_4U6UnmME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_v4qRoaUZ, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_m5H1PTtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xyfTGZFb_sendMessage);
}

void Heavy_PhaseRing::cSystem_xyfTGZFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MLRq24AL_sendMessage);
}

void Heavy_PhaseRing::cDelay_hfmEo0gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hfmEo0gk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PmVxB3Cs, 0, m, &cDelay_PmVxB3Cs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hfmEo0gk, 0, m, &cDelay_hfmEo0gk_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_h0WP7Mzj, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_PmVxB3Cs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PmVxB3Cs, m);
  cMsg_tRvOtgHr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_iJlDJ8O9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_2RZMgGrF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_1mRngp8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mN4jC1A8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_uydvynKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XKJ8R9XV_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hfmEo0gk, 2, m, &cDelay_hfmEo0gk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5Dwvkgr8_sendMessage);
}

void Heavy_PhaseRing::cMsg_mN4jC1A8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_uydvynKR, 0, m, &hTable_uydvynKR_sendMessage);
}

void Heavy_PhaseRing::cBinop_MLRq24AL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_1mRngp8Q_sendMessage);
}

void Heavy_PhaseRing::cMsg_tRvOtgHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_uydvynKR, 0, m, &hTable_uydvynKR_sendMessage);
}

void Heavy_PhaseRing::cCast_5Dwvkgr8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hfmEo0gk, 0, m, &cDelay_hfmEo0gk_sendMessage);
}

void Heavy_PhaseRing::cMsg_XKJ8R9XV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_PmVxB3Cs, 2, m, &cDelay_PmVxB3Cs_sendMessage);
}

void Heavy_PhaseRing::cMsg_2RZMgGrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_h0WP7Mzj, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_htXq5Wqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AsGV9DOj_sendMessage);
}

void Heavy_PhaseRing::cSystem_AsGV9DOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jOj3gWUR_sendMessage);
}

void Heavy_PhaseRing::cDelay_RD5AnM2Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RD5AnM2Z, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u8SnnwIM, 0, m, &cDelay_u8SnnwIM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RD5AnM2Z, 0, m, &cDelay_RD5AnM2Z_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VPcgzzYi, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_u8SnnwIM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_u8SnnwIM, m);
  cMsg_MCO3dg6e_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_HfNwmcga_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Kmvxm4B1_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_PztSgOMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QIipn46s_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_GjyYVBVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XGRPoZLH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RD5AnM2Z, 2, m, &cDelay_RD5AnM2Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oQhElgI2_sendMessage);
}

void Heavy_PhaseRing::cMsg_QIipn46s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GjyYVBVq, 0, m, &hTable_GjyYVBVq_sendMessage);
}

void Heavy_PhaseRing::cBinop_jOj3gWUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_PztSgOMN_sendMessage);
}

void Heavy_PhaseRing::cMsg_MCO3dg6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GjyYVBVq, 0, m, &hTable_GjyYVBVq_sendMessage);
}

void Heavy_PhaseRing::cCast_oQhElgI2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RD5AnM2Z, 0, m, &cDelay_RD5AnM2Z_sendMessage);
}

void Heavy_PhaseRing::cMsg_XGRPoZLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_u8SnnwIM, 2, m, &cDelay_u8SnnwIM_sendMessage);
}

void Heavy_PhaseRing::cMsg_Kmvxm4B1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VPcgzzYi, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_Wn3XsaBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_4USVHX3e_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_rPGpvuWF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_NGTy1RaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VUJ8XKuK, HV_BINOP_POW, 0, m, &cBinop_VUJ8XKuK_sendMessage);
}

void Heavy_PhaseRing::cBinop_VUJ8XKuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_CLXTa6OV_sendMessage);
}

void Heavy_PhaseRing::cBinop_jIu5gjEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_TygFgUC1_sendMessage);
}

void Heavy_PhaseRing::cCast_5FzARgeV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Wn3XsaBx, 0, m, &cIf_Wn3XsaBx_sendMessage);
}

void Heavy_PhaseRing::cCast_QVf5lzaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_E68QmBgW_sendMessage);
}

void Heavy_PhaseRing::cBinop_E68QmBgW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Wn3XsaBx, 1, m, &cIf_Wn3XsaBx_sendMessage);
}

void Heavy_PhaseRing::cBinop_rPGpvuWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_jIu5gjEN_sendMessage);
}

void Heavy_PhaseRing::cMsg_4USVHX3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_CLXTa6OV_sendMessage);
}

void Heavy_PhaseRing::cBinop_TygFgUC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VUJ8XKuK, HV_BINOP_POW, 1, m, &cBinop_VUJ8XKuK_sendMessage);
  cMsg_NGTy1RaB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_dQU0SMhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ckD8PFEi, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_1GWe9r8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5aM0vGxX, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_ydwAYQkO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lIKk5qEE_sendMessage);
}

void Heavy_PhaseRing::cBinop_lIKk5qEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_2sMaXTVf_sendMessage);
}

void Heavy_PhaseRing::cVar_XPj00sGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zSOGzYuw, HV_BINOP_MULTIPLY, 0, m, &cBinop_zSOGzYuw_sendMessage);
}

void Heavy_PhaseRing::cMsg_tkoitAWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZktSn2NY_sendMessage);
}

void Heavy_PhaseRing::cSystem_ZktSn2NY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PxB5M5gd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_zSOGzYuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_JAmuzgOb_sendMessage);
}

void Heavy_PhaseRing::cBinop_BF8FDLPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zSOGzYuw, HV_BINOP_MULTIPLY, 1, m, &cBinop_zSOGzYuw_sendMessage);
}

void Heavy_PhaseRing::cMsg_PxB5M5gd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BF8FDLPR_sendMessage);
}

void Heavy_PhaseRing::cBinop_JAmuzgOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_YXmzDbkH_sendMessage);
}

void Heavy_PhaseRing::cBinop_YXmzDbkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_xJQOY8og_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_F4cXwsnx, m);
}

void Heavy_PhaseRing::cBinop_xJQOY8og_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_b3CKtgZY, m);
}

void Heavy_PhaseRing::cVar_QXOBBPyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QVf5lzaM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5FzARgeV_sendMessage);
}

void Heavy_PhaseRing::cVar_aiF97HwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_ydwAYQkO_sendMessage);
}

void Heavy_PhaseRing::cVar_neMgIJRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_BRns4TVc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_iDXxBfpu, 0, m, &cIf_iDXxBfpu_sendMessage);
}

void Heavy_PhaseRing::cVar_Ex8ouweF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_c8UxejS4_sendMessage);
}

void Heavy_PhaseRing::cIf_iDXxBfpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_TQN7nCwX_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_CdZSZ8c9, 0, m, &cVar_CdZSZ8c9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_BRns4TVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iDXxBfpu, 1, m, &cIf_iDXxBfpu_sendMessage);
}

void Heavy_PhaseRing::cBinop_c8UxejS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IraH924C_sendMessage);
}

void Heavy_PhaseRing::cBinop_IraH924C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eW6f03YJ, 0, m, &cVar_eW6f03YJ_sendMessage);
}

void Heavy_PhaseRing::cTabhead_q0Jb4lNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QxDlefW1, HV_BINOP_SUBTRACT, 0, m, &cBinop_QxDlefW1_sendMessage);
}

void Heavy_PhaseRing::cMsg_txoj0mEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yVcpCzT1_sendMessage);
}

void Heavy_PhaseRing::cSystem_yVcpCzT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_B0nkolJf_sendMessage);
}

void Heavy_PhaseRing::cVar_5TZdf7Ge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gvGHQrmP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_rDhEBaX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rDhEBaX8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fEcUM8Uh, 0, m, &cDelay_fEcUM8Uh_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Gcpr8fEh, 0, m, &sTabread_Gcpr8fEh_sendMessage);
}

void Heavy_PhaseRing::cDelay_fEcUM8Uh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fEcUM8Uh, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Gcpr8fEh, 0, m, &sTabread_Gcpr8fEh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fEcUM8Uh, 0, m, &cDelay_fEcUM8Uh_sendMessage);
}

void Heavy_PhaseRing::sTabread_Gcpr8fEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nyzMJMNB, HV_BINOP_SUBTRACT, 0, m, &cBinop_nyzMJMNB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_L4WwHbJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fL5iDBSf, HV_BINOP_MAX, 0, m, &cBinop_fL5iDBSf_sendMessage);
}

void Heavy_PhaseRing::cBinop_B0nkolJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L4WwHbJg, HV_BINOP_MULTIPLY, 0, m, &cBinop_L4WwHbJg_sendMessage);
}

void Heavy_PhaseRing::cBinop_QxDlefW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IT5WDDNr_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Gcpr8fEh, 0, m, &sTabread_Gcpr8fEh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_URZt7fdd_sendMessage);
}

void Heavy_PhaseRing::cSystem_Iwi8bchH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nyzMJMNB, HV_BINOP_SUBTRACT, 1, m, &cBinop_nyzMJMNB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fEcUM8Uh, 2, m, &cDelay_fEcUM8Uh_sendMessage);
}

void Heavy_PhaseRing::cMsg_gvGHQrmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Iwi8bchH_sendMessage);
}

void Heavy_PhaseRing::cMsg_IT5WDDNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rDhEBaX8, 0, m, &cDelay_rDhEBaX8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fEcUM8Uh, 0, m, &cDelay_fEcUM8Uh_sendMessage);
}

void Heavy_PhaseRing::cMsg_i7vqvBVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_fL5iDBSf, HV_BINOP_MAX, 1, m, &cBinop_fL5iDBSf_sendMessage);
}

void Heavy_PhaseRing::cBinop_fL5iDBSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QxDlefW1, HV_BINOP_SUBTRACT, 1, m, &cBinop_QxDlefW1_sendMessage);
}

void Heavy_PhaseRing::cCast_URZt7fdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rDhEBaX8, 0, m, &cDelay_rDhEBaX8_sendMessage);
}

void Heavy_PhaseRing::cBinop_A9nMz2hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rDhEBaX8, 2, m, &cDelay_rDhEBaX8_sendMessage);
}

void Heavy_PhaseRing::cBinop_nyzMJMNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_A9nMz2hg_sendMessage);
}

void Heavy_PhaseRing::cCast_z1kmmXnB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5TZdf7Ge, 0, m, &cVar_5TZdf7Ge_sendMessage);
  cMsg_txoj0mEo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_q0Jb4lNK, 0, m, &cTabhead_q0Jb4lNK_sendMessage);
}

void Heavy_PhaseRing::cMsg_duVuL1m1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WoZdvGZa_sendMessage);
}

void Heavy_PhaseRing::cSystem_WoZdvGZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PeaVKrG0_sendMessage);
}

void Heavy_PhaseRing::cDelay_KrGni5Vg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KrGni5Vg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_W0bwZCG3, 0, m, &cDelay_W0bwZCG3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KrGni5Vg, 0, m, &cDelay_KrGni5Vg_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uwOlxGrC, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_W0bwZCG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_W0bwZCG3, m);
  cMsg_5zmcNhJ2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_GKs513SS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_PhlBgs6Q_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_43Jdpaeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UrViWSxY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_aZ7gPpdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kh1q9qtO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KrGni5Vg, 2, m, &cDelay_KrGni5Vg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_54W08sgE_sendMessage);
}

void Heavy_PhaseRing::cMsg_UrViWSxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_aZ7gPpdB, 0, m, &hTable_aZ7gPpdB_sendMessage);
}

void Heavy_PhaseRing::cBinop_PeaVKrG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_43Jdpaeu_sendMessage);
}

void Heavy_PhaseRing::cMsg_5zmcNhJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_aZ7gPpdB, 0, m, &hTable_aZ7gPpdB_sendMessage);
}

void Heavy_PhaseRing::cCast_54W08sgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KrGni5Vg, 0, m, &cDelay_KrGni5Vg_sendMessage);
}

void Heavy_PhaseRing::cMsg_Kh1q9qtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_W0bwZCG3, 2, m, &cDelay_W0bwZCG3_sendMessage);
}

void Heavy_PhaseRing::cMsg_PhlBgs6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uwOlxGrC, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_zlO6azOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jgvDOlP0, HV_BINOP_SUBTRACT, 0, m, &cBinop_jgvDOlP0_sendMessage);
}

void Heavy_PhaseRing::cMsg_olRM7fmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GTJP0R7v_sendMessage);
}

void Heavy_PhaseRing::cSystem_GTJP0R7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_H9SStyYp_sendMessage);
}

void Heavy_PhaseRing::cVar_XZh7uSpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fRZFvAyc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_vuKmSmq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vuKmSmq0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_N9WARvCi, 0, m, &cDelay_N9WARvCi_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ym0mC4Og, 0, m, &sTabread_ym0mC4Og_sendMessage);
}

void Heavy_PhaseRing::cDelay_N9WARvCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_N9WARvCi, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ym0mC4Og, 0, m, &sTabread_ym0mC4Og_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_N9WARvCi, 0, m, &cDelay_N9WARvCi_sendMessage);
}

void Heavy_PhaseRing::sTabread_ym0mC4Og_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6U6ziOK0, HV_BINOP_SUBTRACT, 0, m, &cBinop_6U6ziOK0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_W8EcRhtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u9Lpo23R, HV_BINOP_MAX, 0, m, &cBinop_u9Lpo23R_sendMessage);
}

void Heavy_PhaseRing::cBinop_H9SStyYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W8EcRhtg, HV_BINOP_MULTIPLY, 0, m, &cBinop_W8EcRhtg_sendMessage);
}

void Heavy_PhaseRing::cBinop_jgvDOlP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Zn6Acuzo_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ym0mC4Og, 0, m, &sTabread_ym0mC4Og_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_67vqk78r_sendMessage);
}

void Heavy_PhaseRing::cSystem_54OcApnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6U6ziOK0, HV_BINOP_SUBTRACT, 1, m, &cBinop_6U6ziOK0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_N9WARvCi, 2, m, &cDelay_N9WARvCi_sendMessage);
}

void Heavy_PhaseRing::cMsg_fRZFvAyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_54OcApnG_sendMessage);
}

void Heavy_PhaseRing::cMsg_Zn6Acuzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_vuKmSmq0, 0, m, &cDelay_vuKmSmq0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_N9WARvCi, 0, m, &cDelay_N9WARvCi_sendMessage);
}

void Heavy_PhaseRing::cMsg_u2BItKlf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_u9Lpo23R, HV_BINOP_MAX, 1, m, &cBinop_u9Lpo23R_sendMessage);
}

void Heavy_PhaseRing::cBinop_u9Lpo23R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jgvDOlP0, HV_BINOP_SUBTRACT, 1, m, &cBinop_jgvDOlP0_sendMessage);
}

void Heavy_PhaseRing::cCast_67vqk78r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vuKmSmq0, 0, m, &cDelay_vuKmSmq0_sendMessage);
}

void Heavy_PhaseRing::cBinop_aFO6K8cA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vuKmSmq0, 2, m, &cDelay_vuKmSmq0_sendMessage);
}

void Heavy_PhaseRing::cBinop_6U6ziOK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aFO6K8cA_sendMessage);
}

void Heavy_PhaseRing::cCast_FozhtIEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XZh7uSpw, 0, m, &cVar_XZh7uSpw_sendMessage);
  cMsg_olRM7fmL_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zlO6azOc, 0, m, &cTabhead_zlO6azOc_sendMessage);
}

void Heavy_PhaseRing::cMsg_udic6Ocg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W87jaC4A_sendMessage);
}

void Heavy_PhaseRing::cSystem_W87jaC4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oe4xMTzz_sendMessage);
}

void Heavy_PhaseRing::cDelay_pVuksFL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pVuksFL0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SktDr2XY, 0, m, &cDelay_SktDr2XY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pVuksFL0, 0, m, &cDelay_pVuksFL0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BPVNU90c, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_SktDr2XY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SktDr2XY, m);
  cMsg_MCN26w4a_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_78K0rfLM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ICtLEJ2L_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_vTb9Uyez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EqNUZGOf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_QRKZRUyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QpCjE9kZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pVuksFL0, 2, m, &cDelay_pVuksFL0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aKAuspjR_sendMessage);
}

void Heavy_PhaseRing::cMsg_EqNUZGOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_QRKZRUyO, 0, m, &hTable_QRKZRUyO_sendMessage);
}

void Heavy_PhaseRing::cBinop_oe4xMTzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_vTb9Uyez_sendMessage);
}

void Heavy_PhaseRing::cMsg_MCN26w4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_QRKZRUyO, 0, m, &hTable_QRKZRUyO_sendMessage);
}

void Heavy_PhaseRing::cCast_aKAuspjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pVuksFL0, 0, m, &cDelay_pVuksFL0_sendMessage);
}

void Heavy_PhaseRing::cMsg_QpCjE9kZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_SktDr2XY, 2, m, &cDelay_SktDr2XY_sendMessage);
}

void Heavy_PhaseRing::cMsg_ICtLEJ2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BPVNU90c, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_J01iXiyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4qI6MRiv, HV_BINOP_SUBTRACT, 0, m, &cBinop_4qI6MRiv_sendMessage);
}

void Heavy_PhaseRing::cMsg_8tygPEfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BqY8L1g6_sendMessage);
}

void Heavy_PhaseRing::cSystem_BqY8L1g6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2FBF3Xo2_sendMessage);
}

void Heavy_PhaseRing::cVar_boVHaGib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6bEKU9P2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_LD8J2YFe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LD8J2YFe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7DFT6Lzp, 0, m, &cDelay_7DFT6Lzp_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wffloDbf, 0, m, &sTabread_wffloDbf_sendMessage);
}

void Heavy_PhaseRing::cDelay_7DFT6Lzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7DFT6Lzp, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wffloDbf, 0, m, &sTabread_wffloDbf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7DFT6Lzp, 0, m, &cDelay_7DFT6Lzp_sendMessage);
}

void Heavy_PhaseRing::sTabread_wffloDbf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_GsrQ7Hko, HV_BINOP_SUBTRACT, 0, m, &cBinop_GsrQ7Hko_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Lx4zoyvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lc5nvkVq, HV_BINOP_MAX, 0, m, &cBinop_lc5nvkVq_sendMessage);
}

void Heavy_PhaseRing::cBinop_2FBF3Xo2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lx4zoyvJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Lx4zoyvJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_4qI6MRiv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2KdGkCne_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wffloDbf, 0, m, &sTabread_wffloDbf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gAQa99Uh_sendMessage);
}

void Heavy_PhaseRing::cSystem_lVd1xDez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GsrQ7Hko, HV_BINOP_SUBTRACT, 1, m, &cBinop_GsrQ7Hko_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7DFT6Lzp, 2, m, &cDelay_7DFT6Lzp_sendMessage);
}

void Heavy_PhaseRing::cMsg_6bEKU9P2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lVd1xDez_sendMessage);
}

void Heavy_PhaseRing::cMsg_2KdGkCne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LD8J2YFe, 0, m, &cDelay_LD8J2YFe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7DFT6Lzp, 0, m, &cDelay_7DFT6Lzp_sendMessage);
}

void Heavy_PhaseRing::cMsg_HiY0w8lv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_lc5nvkVq, HV_BINOP_MAX, 1, m, &cBinop_lc5nvkVq_sendMessage);
}

void Heavy_PhaseRing::cBinop_lc5nvkVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4qI6MRiv, HV_BINOP_SUBTRACT, 1, m, &cBinop_4qI6MRiv_sendMessage);
}

void Heavy_PhaseRing::cCast_gAQa99Uh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LD8J2YFe, 0, m, &cDelay_LD8J2YFe_sendMessage);
}

void Heavy_PhaseRing::cBinop_6WKO9IlR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LD8J2YFe, 2, m, &cDelay_LD8J2YFe_sendMessage);
}

void Heavy_PhaseRing::cBinop_GsrQ7Hko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6WKO9IlR_sendMessage);
}

void Heavy_PhaseRing::cCast_Bg1HArvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_boVHaGib, 0, m, &cVar_boVHaGib_sendMessage);
  cMsg_8tygPEfS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_J01iXiyW, 0, m, &cTabhead_J01iXiyW_sendMessage);
}

void Heavy_PhaseRing::cMsg_kuaHjDYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zi62G5LA_sendMessage);
}

void Heavy_PhaseRing::cSystem_zi62G5LA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vrgwc4XZ_sendMessage);
}

void Heavy_PhaseRing::cDelay_VQ1GiHuO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VQ1GiHuO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TgTgg8ud, 0, m, &cDelay_TgTgg8ud_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VQ1GiHuO, 0, m, &cDelay_VQ1GiHuO_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZN6mPLk9, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_TgTgg8ud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TgTgg8ud, m);
  cMsg_M9xaZxAv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_5cDPBton_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_qEUIMch3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_QqkDdXfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QkCJ5rkU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_gyyb06xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4SVx87qf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VQ1GiHuO, 2, m, &cDelay_VQ1GiHuO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QdOqLO0k_sendMessage);
}

void Heavy_PhaseRing::cMsg_QkCJ5rkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gyyb06xd, 0, m, &hTable_gyyb06xd_sendMessage);
}

void Heavy_PhaseRing::cBinop_vrgwc4XZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_QqkDdXfg_sendMessage);
}

void Heavy_PhaseRing::cMsg_M9xaZxAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gyyb06xd, 0, m, &hTable_gyyb06xd_sendMessage);
}

void Heavy_PhaseRing::cCast_QdOqLO0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VQ1GiHuO, 0, m, &cDelay_VQ1GiHuO_sendMessage);
}

void Heavy_PhaseRing::cMsg_4SVx87qf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_TgTgg8ud, 2, m, &cDelay_TgTgg8ud_sendMessage);
}

void Heavy_PhaseRing::cMsg_qEUIMch3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZN6mPLk9, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_U85d9Y5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AcgeRjWQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_AcgeRjWQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_4pOW8zgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OFWb0FhX_sendMessage);
}

void Heavy_PhaseRing::cSystem_OFWb0FhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1AGeOQFF_sendMessage);
}

void Heavy_PhaseRing::cVar_F7J7F0R3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PWdeRn7P_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_iKTpOozt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iKTpOozt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oIvGjAdZ, 0, m, &cDelay_oIvGjAdZ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X8V50qQF, 0, m, &sTabread_X8V50qQF_sendMessage);
}

void Heavy_PhaseRing::cDelay_oIvGjAdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oIvGjAdZ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X8V50qQF, 0, m, &sTabread_X8V50qQF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oIvGjAdZ, 0, m, &cDelay_oIvGjAdZ_sendMessage);
}

void Heavy_PhaseRing::sTabread_X8V50qQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oI1yMeLD, HV_BINOP_SUBTRACT, 0, m, &cBinop_oI1yMeLD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_yQX2pdQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Axop58DN, HV_BINOP_MAX, 0, m, &cBinop_Axop58DN_sendMessage);
}

void Heavy_PhaseRing::cBinop_1AGeOQFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQX2pdQG, HV_BINOP_MULTIPLY, 0, m, &cBinop_yQX2pdQG_sendMessage);
}

void Heavy_PhaseRing::cBinop_AcgeRjWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j2RCST1g_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X8V50qQF, 0, m, &sTabread_X8V50qQF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M1awWceA_sendMessage);
}

void Heavy_PhaseRing::cSystem_aUkn3My7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oI1yMeLD, HV_BINOP_SUBTRACT, 1, m, &cBinop_oI1yMeLD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oIvGjAdZ, 2, m, &cDelay_oIvGjAdZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_PWdeRn7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aUkn3My7_sendMessage);
}

void Heavy_PhaseRing::cMsg_j2RCST1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iKTpOozt, 0, m, &cDelay_iKTpOozt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oIvGjAdZ, 0, m, &cDelay_oIvGjAdZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_pbnHOacX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Axop58DN, HV_BINOP_MAX, 1, m, &cBinop_Axop58DN_sendMessage);
}

void Heavy_PhaseRing::cBinop_Axop58DN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AcgeRjWQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_AcgeRjWQ_sendMessage);
}

void Heavy_PhaseRing::cCast_M1awWceA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iKTpOozt, 0, m, &cDelay_iKTpOozt_sendMessage);
}

void Heavy_PhaseRing::cBinop_D9IjPohx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iKTpOozt, 2, m, &cDelay_iKTpOozt_sendMessage);
}

void Heavy_PhaseRing::cBinop_oI1yMeLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_D9IjPohx_sendMessage);
}

void Heavy_PhaseRing::cCast_bHnbd8t6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F7J7F0R3, 0, m, &cVar_F7J7F0R3_sendMessage);
  cMsg_4pOW8zgw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_U85d9Y5U, 0, m, &cTabhead_U85d9Y5U_sendMessage);
}

void Heavy_PhaseRing::cMsg_uY2ohx7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ecptDJ3Q_sendMessage);
}

void Heavy_PhaseRing::cSystem_ecptDJ3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_htyZAL2W_sendMessage);
}

void Heavy_PhaseRing::cDelay_DIxhgo7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DIxhgo7m, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dlz2MkiL, 0, m, &cDelay_dlz2MkiL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DIxhgo7m, 0, m, &cDelay_DIxhgo7m_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JHFXe0ee, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_dlz2MkiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dlz2MkiL, m);
  cMsg_3WO5qCF2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_hNZZx5jh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_qDBmwXzo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_3In2vq3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mCXk10i1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_PUvS8ivH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_myrgeqM9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DIxhgo7m, 2, m, &cDelay_DIxhgo7m_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KvdygVJc_sendMessage);
}

void Heavy_PhaseRing::cMsg_mCXk10i1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_PUvS8ivH, 0, m, &hTable_PUvS8ivH_sendMessage);
}

void Heavy_PhaseRing::cBinop_htyZAL2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_3In2vq3z_sendMessage);
}

void Heavy_PhaseRing::cMsg_3WO5qCF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_PUvS8ivH, 0, m, &hTable_PUvS8ivH_sendMessage);
}

void Heavy_PhaseRing::cCast_KvdygVJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DIxhgo7m, 0, m, &cDelay_DIxhgo7m_sendMessage);
}

void Heavy_PhaseRing::cMsg_myrgeqM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_dlz2MkiL, 2, m, &cDelay_dlz2MkiL_sendMessage);
}

void Heavy_PhaseRing::cMsg_qDBmwXzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JHFXe0ee, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_Z2O1qOoy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hT9yNgqG, HV_BINOP_SUBTRACT, 0, m, &cBinop_hT9yNgqG_sendMessage);
}

void Heavy_PhaseRing::cMsg_JVcCmfUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ImuIjd5w_sendMessage);
}

void Heavy_PhaseRing::cSystem_ImuIjd5w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UTeWMIMZ_sendMessage);
}

void Heavy_PhaseRing::cVar_j24waaS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FC5t5Hfm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_hw7smwev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hw7smwev, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KBZ4jugh, 0, m, &cDelay_KBZ4jugh_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dghLZh9A, 0, m, &sTabread_dghLZh9A_sendMessage);
}

void Heavy_PhaseRing::cDelay_KBZ4jugh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KBZ4jugh, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dghLZh9A, 0, m, &sTabread_dghLZh9A_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KBZ4jugh, 0, m, &cDelay_KBZ4jugh_sendMessage);
}

void Heavy_PhaseRing::sTabread_dghLZh9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kHjWJFAD, HV_BINOP_SUBTRACT, 0, m, &cBinop_kHjWJFAD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_VSa6jbkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_joaVrnsv, HV_BINOP_MAX, 0, m, &cBinop_joaVrnsv_sendMessage);
}

void Heavy_PhaseRing::cBinop_UTeWMIMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VSa6jbkK, HV_BINOP_MULTIPLY, 0, m, &cBinop_VSa6jbkK_sendMessage);
}

void Heavy_PhaseRing::cBinop_hT9yNgqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_osYrFYLK_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dghLZh9A, 0, m, &sTabread_dghLZh9A_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2zkBZtaK_sendMessage);
}

void Heavy_PhaseRing::cSystem_Jyt3SGIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kHjWJFAD, HV_BINOP_SUBTRACT, 1, m, &cBinop_kHjWJFAD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KBZ4jugh, 2, m, &cDelay_KBZ4jugh_sendMessage);
}

void Heavy_PhaseRing::cMsg_FC5t5Hfm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Jyt3SGIg_sendMessage);
}

void Heavy_PhaseRing::cMsg_osYrFYLK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hw7smwev, 0, m, &cDelay_hw7smwev_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KBZ4jugh, 0, m, &cDelay_KBZ4jugh_sendMessage);
}

void Heavy_PhaseRing::cMsg_8aQpXfHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_joaVrnsv, HV_BINOP_MAX, 1, m, &cBinop_joaVrnsv_sendMessage);
}

void Heavy_PhaseRing::cBinop_joaVrnsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hT9yNgqG, HV_BINOP_SUBTRACT, 1, m, &cBinop_hT9yNgqG_sendMessage);
}

void Heavy_PhaseRing::cCast_2zkBZtaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hw7smwev, 0, m, &cDelay_hw7smwev_sendMessage);
}

void Heavy_PhaseRing::cBinop_TjOVQ7L1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hw7smwev, 2, m, &cDelay_hw7smwev_sendMessage);
}

void Heavy_PhaseRing::cBinop_kHjWJFAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TjOVQ7L1_sendMessage);
}

void Heavy_PhaseRing::cCast_5fClXyDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_j24waaS7, 0, m, &cVar_j24waaS7_sendMessage);
  cMsg_JVcCmfUh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Z2O1qOoy, 0, m, &cTabhead_Z2O1qOoy_sendMessage);
}

void Heavy_PhaseRing::cMsg_VlhX8Pjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_F5EnhCPd_sendMessage);
}

void Heavy_PhaseRing::cSystem_F5EnhCPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gd09qgNy_sendMessage);
}

void Heavy_PhaseRing::cDelay_resvxUqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_resvxUqm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qx4ZOnQF, 0, m, &cDelay_Qx4ZOnQF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_resvxUqm, 0, m, &cDelay_resvxUqm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RFf1elrf, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_Qx4ZOnQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Qx4ZOnQF, m);
  cMsg_T8kcYOVR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_doJJvrW4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_QKTMAZpH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_CY3DMFwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uz8KBqqk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_3fLm6Dbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zbk00Iss_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_resvxUqm, 2, m, &cDelay_resvxUqm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FFy3FwkD_sendMessage);
}

void Heavy_PhaseRing::cMsg_uz8KBqqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3fLm6Dbi, 0, m, &hTable_3fLm6Dbi_sendMessage);
}

void Heavy_PhaseRing::cBinop_gd09qgNy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_CY3DMFwe_sendMessage);
}

void Heavy_PhaseRing::cMsg_T8kcYOVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3fLm6Dbi, 0, m, &hTable_3fLm6Dbi_sendMessage);
}

void Heavy_PhaseRing::cCast_FFy3FwkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_resvxUqm, 0, m, &cDelay_resvxUqm_sendMessage);
}

void Heavy_PhaseRing::cMsg_zbk00Iss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qx4ZOnQF, 2, m, &cDelay_Qx4ZOnQF_sendMessage);
}

void Heavy_PhaseRing::cMsg_QKTMAZpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RFf1elrf, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_FepUjPkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fmPY3BC2, HV_BINOP_SUBTRACT, 0, m, &cBinop_fmPY3BC2_sendMessage);
}

void Heavy_PhaseRing::cMsg_Dp2nEM35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Hdh9wnMo_sendMessage);
}

void Heavy_PhaseRing::cSystem_Hdh9wnMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pGl7ipzr_sendMessage);
}

void Heavy_PhaseRing::cVar_fCzNbENK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xWJ5O9UD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_nvFbreoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nvFbreoW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ces9BUQY, 0, m, &cDelay_ces9BUQY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cu3cZnNI, 0, m, &sTabread_cu3cZnNI_sendMessage);
}

void Heavy_PhaseRing::cDelay_ces9BUQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ces9BUQY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cu3cZnNI, 0, m, &sTabread_cu3cZnNI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ces9BUQY, 0, m, &cDelay_ces9BUQY_sendMessage);
}

void Heavy_PhaseRing::sTabread_cu3cZnNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SkisodUC, HV_BINOP_SUBTRACT, 0, m, &cBinop_SkisodUC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Ym4BrJJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jaLI1T6Y, HV_BINOP_MAX, 0, m, &cBinop_jaLI1T6Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_pGl7ipzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ym4BrJJo, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ym4BrJJo_sendMessage);
}

void Heavy_PhaseRing::cBinop_fmPY3BC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_je5PUZQb_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cu3cZnNI, 0, m, &sTabread_cu3cZnNI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Aiz20sYN_sendMessage);
}

void Heavy_PhaseRing::cSystem_w75TQRqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SkisodUC, HV_BINOP_SUBTRACT, 1, m, &cBinop_SkisodUC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ces9BUQY, 2, m, &cDelay_ces9BUQY_sendMessage);
}

void Heavy_PhaseRing::cMsg_xWJ5O9UD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_w75TQRqY_sendMessage);
}

void Heavy_PhaseRing::cMsg_je5PUZQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nvFbreoW, 0, m, &cDelay_nvFbreoW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ces9BUQY, 0, m, &cDelay_ces9BUQY_sendMessage);
}

void Heavy_PhaseRing::cMsg_UMpMoUOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_jaLI1T6Y, HV_BINOP_MAX, 1, m, &cBinop_jaLI1T6Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_jaLI1T6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fmPY3BC2, HV_BINOP_SUBTRACT, 1, m, &cBinop_fmPY3BC2_sendMessage);
}

void Heavy_PhaseRing::cCast_Aiz20sYN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nvFbreoW, 0, m, &cDelay_nvFbreoW_sendMessage);
}

void Heavy_PhaseRing::cBinop_6adMX1Tj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nvFbreoW, 2, m, &cDelay_nvFbreoW_sendMessage);
}

void Heavy_PhaseRing::cBinop_SkisodUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6adMX1Tj_sendMessage);
}

void Heavy_PhaseRing::cCast_3u0b3TWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fCzNbENK, 0, m, &cVar_fCzNbENK_sendMessage);
  cMsg_Dp2nEM35_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_FepUjPkp, 0, m, &cTabhead_FepUjPkp_sendMessage);
}

void Heavy_PhaseRing::cMsg_7VZ0lZNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fgsPjBYv_sendMessage);
}

void Heavy_PhaseRing::cSystem_fgsPjBYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4xEeEG3L_sendMessage);
}

void Heavy_PhaseRing::cDelay_HJ3zVYIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HJ3zVYIV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KNDSJSLf, 0, m, &cDelay_KNDSJSLf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HJ3zVYIV, 0, m, &cDelay_HJ3zVYIV_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3wiViRVW, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_KNDSJSLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KNDSJSLf, m);
  cMsg_Tx8nznZ3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Vk0un1iN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_pQrOiF9M_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_4I83wzXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oMT3SDVt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_qL0S8TQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vDKYgXkK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HJ3zVYIV, 2, m, &cDelay_HJ3zVYIV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UVOiffPS_sendMessage);
}

void Heavy_PhaseRing::cMsg_oMT3SDVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_qL0S8TQo, 0, m, &hTable_qL0S8TQo_sendMessage);
}

void Heavy_PhaseRing::cBinop_4xEeEG3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_4I83wzXG_sendMessage);
}

void Heavy_PhaseRing::cMsg_Tx8nznZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_qL0S8TQo, 0, m, &hTable_qL0S8TQo_sendMessage);
}

void Heavy_PhaseRing::cCast_UVOiffPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HJ3zVYIV, 0, m, &cDelay_HJ3zVYIV_sendMessage);
}

void Heavy_PhaseRing::cMsg_vDKYgXkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_KNDSJSLf, 2, m, &cDelay_KNDSJSLf_sendMessage);
}

void Heavy_PhaseRing::cMsg_pQrOiF9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3wiViRVW, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_CdZSZ8c9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XPj00sGH, 0, m, &cVar_XPj00sGH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KH4afGDD, 0, m, &cVar_KH4afGDD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8Q8fIgxJ, 0, m, &cVar_8Q8fIgxJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MxPYDdnH, 0, m, &cVar_MxPYDdnH_sendMessage);
}

void Heavy_PhaseRing::cVar_eW6f03YJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_Hl9PdzFK_sendMessage);
}

void Heavy_PhaseRing::cPack_t7KaHNbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KTHIp4Sv, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_KH4afGDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e9u3ntw9, HV_BINOP_MULTIPLY, 0, m, &cBinop_e9u3ntw9_sendMessage);
}

void Heavy_PhaseRing::cMsg_F12g0Fhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rEAyRV7K_sendMessage);
}

void Heavy_PhaseRing::cSystem_rEAyRV7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Mb753Z2T_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_e9u3ntw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_398clcKC_sendMessage);
}

void Heavy_PhaseRing::cBinop_gMygzci0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e9u3ntw9, HV_BINOP_MULTIPLY, 1, m, &cBinop_e9u3ntw9_sendMessage);
}

void Heavy_PhaseRing::cMsg_Mb753Z2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gMygzci0_sendMessage);
}

void Heavy_PhaseRing::cBinop_398clcKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5NfIsLR3_sendMessage);
}

void Heavy_PhaseRing::cBinop_5NfIsLR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_I8kJ1M1I_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VF6nDds8, m);
}

void Heavy_PhaseRing::cBinop_I8kJ1M1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nrehWPSJ, m);
}

void Heavy_PhaseRing::cVar_8Q8fIgxJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SFDvUQJo, HV_BINOP_MULTIPLY, 0, m, &cBinop_SFDvUQJo_sendMessage);
}

void Heavy_PhaseRing::cMsg_t04IXFSz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ho8YCJOp_sendMessage);
}

void Heavy_PhaseRing::cSystem_ho8YCJOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WoMlosu2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_SFDvUQJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ps42Aj3s_sendMessage);
}

void Heavy_PhaseRing::cBinop_B2c7TGKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SFDvUQJo, HV_BINOP_MULTIPLY, 1, m, &cBinop_SFDvUQJo_sendMessage);
}

void Heavy_PhaseRing::cMsg_WoMlosu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_B2c7TGKc_sendMessage);
}

void Heavy_PhaseRing::cBinop_ps42Aj3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_sf4UBWLI_sendMessage);
}

void Heavy_PhaseRing::cBinop_sf4UBWLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6jILBj6d_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Qm967ZSJ, m);
}

void Heavy_PhaseRing::cBinop_6jILBj6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1weslR2s, m);
}

void Heavy_PhaseRing::cVar_MxPYDdnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kosU7XqC, HV_BINOP_MULTIPLY, 0, m, &cBinop_kosU7XqC_sendMessage);
}

void Heavy_PhaseRing::cMsg_PKWMiD96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OhuuFUJW_sendMessage);
}

void Heavy_PhaseRing::cSystem_OhuuFUJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y9zsLYRR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_kosU7XqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_8VTHt7bm_sendMessage);
}

void Heavy_PhaseRing::cBinop_aRNK1yXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kosU7XqC, HV_BINOP_MULTIPLY, 1, m, &cBinop_kosU7XqC_sendMessage);
}

void Heavy_PhaseRing::cMsg_Y9zsLYRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_aRNK1yXO_sendMessage);
}

void Heavy_PhaseRing::cBinop_8VTHt7bm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rBLFAGu9_sendMessage);
}

void Heavy_PhaseRing::cBinop_rBLFAGu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9XjDBdBL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Jqg8EUnA, m);
}

void Heavy_PhaseRing::cBinop_9XjDBdBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7N6sgdaj, m);
}

void Heavy_PhaseRing::cBinop_2sMaXTVf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1GWe9r8A, 0, m, &cPack_1GWe9r8A_sendMessage);
}

void Heavy_PhaseRing::cMsg_TQN7nCwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_CdZSZ8c9, 0, m, &cVar_CdZSZ8c9_sendMessage);
}

void Heavy_PhaseRing::cBinop_Hl9PdzFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_t7KaHNbo, 0, m, &cPack_t7KaHNbo_sendMessage);
}

void Heavy_PhaseRing::cBinop_CLXTa6OV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dQU0SMhl, 0, m, &cPack_dQU0SMhl_sendMessage);
}

void Heavy_PhaseRing::cIf_v9Xga2Z8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Gah0Gqrp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_dOjLGXQQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_dOjLGXQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_aGRlSi05_sendMessage);
}

void Heavy_PhaseRing::cCast_jaNXEZga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_OwlUq2PP_sendMessage);
}

void Heavy_PhaseRing::cCast_tSUI6a0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_v9Xga2Z8, 0, m, &cIf_v9Xga2Z8_sendMessage);
}

void Heavy_PhaseRing::cMsg_Gah0Gqrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_QXOBBPyn, 0, m, &cVar_QXOBBPyn_sendMessage);
}

void Heavy_PhaseRing::cBinop_aGRlSi05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_ycOCfXTw_sendMessage);
}

void Heavy_PhaseRing::cBinop_ycOCfXTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lAb0HZEw_sendMessage);
}

void Heavy_PhaseRing::cBinop_lAb0HZEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QXOBBPyn, 0, m, &cVar_QXOBBPyn_sendMessage);
}

void Heavy_PhaseRing::cBinop_OwlUq2PP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_v9Xga2Z8, 1, m, &cIf_v9Xga2Z8_sendMessage);
}

void Heavy_PhaseRing::cBinop_9fhST7BR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jaNXEZga_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tSUI6a0x_sendMessage);
}

void Heavy_PhaseRing::cBinop_x8TxwQkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9fhST7BR_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_v15QyOrN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_BLNZpnsv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_BLNZpnsv_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ss2qV98Z, 1, m, &cDelay_ss2qV98Z_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o6Kantuf_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_ss2qV98Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ss2qV98Z, m);
  cMsg_cn1pUKGN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_BLNZpnsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ss2qV98Z, 0, m, &cDelay_ss2qV98Z_sendMessage);
}

void Heavy_PhaseRing::cCast_o6Kantuf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ss2qV98Z, 0, m, &cDelay_ss2qV98Z_sendMessage);
}

void Heavy_PhaseRing::cVar_86P2DOps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6eySD7Ik, 0, m, &cPack_6eySD7Ik_sendMessage);
}

void Heavy_PhaseRing::cVar_celc4kgG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_TkVtoESZ_sendMessage);
}

void Heavy_PhaseRing::cVar_KIVpJPJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_2j49kTyH_sendMessage);
}

void Heavy_PhaseRing::cPack_Zljc5kMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6eE1G0oF, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_nWIZM3hz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_g0NEi6F1_sendMessage);
}

void Heavy_PhaseRing::cBinop_ViJgmIVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_nWIZM3hz_sendMessage);
}

void Heavy_PhaseRing::cPack_3IaAYn5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zT0U5Nd2, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_0yZsJ2JY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_VDxCBk9I_sendMessage);
}

void Heavy_PhaseRing::cMsg_wNrKTelV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8opLGsmf_sendMessage);
}

void Heavy_PhaseRing::cSystem_8opLGsmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fQZqn0tp_sendMessage);
}

void Heavy_PhaseRing::cDelay_zUiEEujJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zUiEEujJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EyO9wt9S, 0, m, &cDelay_EyO9wt9S_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zUiEEujJ, 0, m, &cDelay_zUiEEujJ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_x6EaIm60, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_EyO9wt9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EyO9wt9S, m);
  cMsg_1VulDnKe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_BF4ZHPfE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_fSMnyszj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_1bbuICjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z1GIaFJx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_rLMfo5BU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RTGKyOux_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zUiEEujJ, 2, m, &cDelay_zUiEEujJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ePm5eEs1_sendMessage);
}

void Heavy_PhaseRing::cMsg_Z1GIaFJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rLMfo5BU, 0, m, &hTable_rLMfo5BU_sendMessage);
}

void Heavy_PhaseRing::cBinop_fQZqn0tp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_1bbuICjG_sendMessage);
}

void Heavy_PhaseRing::cMsg_1VulDnKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rLMfo5BU, 0, m, &hTable_rLMfo5BU_sendMessage);
}

void Heavy_PhaseRing::cCast_ePm5eEs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zUiEEujJ, 0, m, &cDelay_zUiEEujJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_RTGKyOux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_EyO9wt9S, 2, m, &cDelay_EyO9wt9S_sendMessage);
}

void Heavy_PhaseRing::cMsg_fSMnyszj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_x6EaIm60, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_a7g4gDK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2mjnyLV4_sendMessage);
}

void Heavy_PhaseRing::cSystem_2mjnyLV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WYkf5V9o_sendMessage);
}

void Heavy_PhaseRing::cVar_RlIm1VPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IIdgSYeR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_aIZF3iRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_4itgAfGD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dqMc9oLE, m);
}

void Heavy_PhaseRing::cBinop_WYkf5V9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xsBzyZiz, m);
}

void Heavy_PhaseRing::cMsg_IIdgSYeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aIZF3iRi_sendMessage);
}

void Heavy_PhaseRing::cBinop_4itgAfGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qtVatXXt, m);
}

void Heavy_PhaseRing::cMsg_vZuDsFXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iomZusZS_sendMessage);
}

void Heavy_PhaseRing::cSystem_iomZusZS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Q63Hy4Hb_sendMessage);
}

void Heavy_PhaseRing::cVar_hkZ0L2Kq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IqJkKm2s_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_lqbHmGBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_avSgtc2j_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_otoAoWKG, m);
}

void Heavy_PhaseRing::cBinop_Q63Hy4Hb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pGEdpUhu, m);
}

void Heavy_PhaseRing::cMsg_IqJkKm2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lqbHmGBv_sendMessage);
}

void Heavy_PhaseRing::cBinop_avSgtc2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xv2fJy9z, m);
}

void Heavy_PhaseRing::cBinop_cMklvmWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O5GPtYt9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_2hM8NHEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JbzUilbE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gax8wF9E_sendMessage);
}

void Heavy_PhaseRing::cCast_JbzUilbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cMklvmWL, HV_BINOP_DIVIDE, 1, m, &cBinop_cMklvmWL_sendMessage);
}

void Heavy_PhaseRing::cCast_gax8wF9E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cMklvmWL, HV_BINOP_DIVIDE, 0, m, &cBinop_cMklvmWL_sendMessage);
}

void Heavy_PhaseRing::cBinop_g0NEi6F1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NyW9zCYA_sendMessage);
}

void Heavy_PhaseRing::cBinop_TkVtoESZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_ViJgmIVI_sendMessage);
}

void Heavy_PhaseRing::cBinop_NyW9zCYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cMklvmWL, HV_BINOP_DIVIDE, 0, m, &cBinop_cMklvmWL_sendMessage);
}

void Heavy_PhaseRing::cBinop_VDxCBk9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3IaAYn5p, 0, m, &cPack_3IaAYn5p_sendMessage);
}

void Heavy_PhaseRing::cBinop_2j49kTyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_2hM8NHEh_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_Zljc5kMo, 0, m, &cPack_Zljc5kMo_sendMessage);
}

void Heavy_PhaseRing::cMsg_GLagd0ds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KIVpJPJ7, 0, m, &cVar_KIVpJPJ7_sendMessage);
}

void Heavy_PhaseRing::cMsg_JdC3Flvi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_0yZsJ2JY, 0, m, &cVar_0yZsJ2JY_sendMessage);
}

void Heavy_PhaseRing::cMsg_O5GPtYt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_L6Uz2u3Y, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_DoS6YuLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zcl1hGOM, HV_BINOP_MULTIPLY, 0, m, &cBinop_zcl1hGOM_sendMessage);
}

void Heavy_PhaseRing::cMsg_eq9NHATP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PfOVFfXA_sendMessage);
}

void Heavy_PhaseRing::cSystem_PfOVFfXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H9UmUwes_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_zcl1hGOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_QOl0perV_sendMessage);
}

void Heavy_PhaseRing::cBinop_ik4VcEWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zcl1hGOM, HV_BINOP_MULTIPLY, 1, m, &cBinop_zcl1hGOM_sendMessage);
}

void Heavy_PhaseRing::cMsg_H9UmUwes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ik4VcEWw_sendMessage);
}

void Heavy_PhaseRing::cBinop_QOl0perV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_k9ZKixAn_sendMessage);
}

void Heavy_PhaseRing::cBinop_k9ZKixAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MMvgj05c_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fRkdFzLs, m);
}

void Heavy_PhaseRing::cBinop_MMvgj05c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xIoTsUED, m);
}

void Heavy_PhaseRing::cVar_pLrzwnd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzjFmHtQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_TzjFmHtQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_MJ78nTIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3wWDZkDZ_sendMessage);
}

void Heavy_PhaseRing::cSystem_3wWDZkDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2vtIPyCe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_TzjFmHtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6OPEnJd9_sendMessage);
}

void Heavy_PhaseRing::cBinop_eEuSS1Oa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzjFmHtQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_TzjFmHtQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_2vtIPyCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_eEuSS1Oa_sendMessage);
}

void Heavy_PhaseRing::cBinop_6OPEnJd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_uGPkdaM8_sendMessage);
}

void Heavy_PhaseRing::cBinop_uGPkdaM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fLnEU3YO_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_oRWDO7FO, m);
}

void Heavy_PhaseRing::cBinop_fLnEU3YO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LmjaFRr7, m);
}

void Heavy_PhaseRing::cVar_D7DzEICZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pkRzYqMY, HV_BINOP_MULTIPLY, 0, m, &cBinop_pkRzYqMY_sendMessage);
}

void Heavy_PhaseRing::cMsg_hNT9FLtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BXBUjMul_sendMessage);
}

void Heavy_PhaseRing::cSystem_BXBUjMul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t8yC9kf5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_pkRzYqMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_bOnh5yRy_sendMessage);
}

void Heavy_PhaseRing::cBinop_cQouDDoT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pkRzYqMY, HV_BINOP_MULTIPLY, 1, m, &cBinop_pkRzYqMY_sendMessage);
}

void Heavy_PhaseRing::cMsg_t8yC9kf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_cQouDDoT_sendMessage);
}

void Heavy_PhaseRing::cBinop_bOnh5yRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RADbbZQk_sendMessage);
}

void Heavy_PhaseRing::cBinop_RADbbZQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ilg9TVCT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0htvQe1P, m);
}

void Heavy_PhaseRing::cBinop_ilg9TVCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_g12I6sjG, m);
}

void Heavy_PhaseRing::cMsg_BRDHS9W7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hlxK46Ry_sendMessage);
}

void Heavy_PhaseRing::cSystem_hlxK46Ry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GbVimtcB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_tVuBjZrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_oTaQmrPp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vhZQguXv, 0, m, &cIf_vhZQguXv_sendMessage);
}

void Heavy_PhaseRing::cIf_vhZQguXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VXj4obRS_sendMessage(_c, 0, m);
      cMsg_d9Xyxmw9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_7v9mPQy1_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_9FogAP4E_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_B8JPcRgV, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_oTaQmrPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vhZQguXv, 1, m, &cIf_vhZQguXv_sendMessage);
}

void Heavy_PhaseRing::cMsg_7v9mPQy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7aObWhFT_sendMessage);
}

void Heavy_PhaseRing::cBinop_7aObWhFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qV50ElgG, m);
}

void Heavy_PhaseRing::cBinop_9FogAP4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xtGLYjxa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_xtGLYjxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yER9ied1_sendMessage);
}

void Heavy_PhaseRing::cBinop_yER9ied1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NdYHZqGI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_NdYHZqGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Ny2V7FVo_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ny2V7FVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rCF2O5HX, m);
}

void Heavy_PhaseRing::cBinop_UWAkxt9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wwvIsUpJ, m);
}

void Heavy_PhaseRing::cMsg_GbVimtcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_UWAkxt9b_sendMessage);
}

void Heavy_PhaseRing::cMsg_VXj4obRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_9FogAP4E_sendMessage);
}

void Heavy_PhaseRing::cMsg_d9Xyxmw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qV50ElgG, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_B8JPcRgV, m);
}

void Heavy_PhaseRing::cBinop_baTMArn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pLrzwnd1, 0, m, &cVar_pLrzwnd1_sendMessage);
}

void Heavy_PhaseRing::cBinop_0fMJNx7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DoS6YuLp, 0, m, &cVar_DoS6YuLp_sendMessage);
}

void Heavy_PhaseRing::cBinop_mNDaTTZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D7DzEICZ, 0, m, &cVar_D7DzEICZ_sendMessage);
}

void Heavy_PhaseRing::cCast_UCvoJ6Ks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_opCZfXDh, m);
}

void Heavy_PhaseRing::cCast_sYJzsRQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_mNDaTTZL_sendMessage);
}

void Heavy_PhaseRing::cCast_i2DGvXZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_baTMArn8_sendMessage);
}

void Heavy_PhaseRing::cCast_fOqbIXAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_0fMJNx7d_sendMessage);
}

void Heavy_PhaseRing::cTabhead_EIuMrBwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EYOgrxt9, HV_BINOP_SUBTRACT, 0, m, &cBinop_EYOgrxt9_sendMessage);
}

void Heavy_PhaseRing::cMsg_6MtvyG2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zunRAKKz_sendMessage);
}

void Heavy_PhaseRing::cSystem_zunRAKKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_594qlgfY_sendMessage);
}

void Heavy_PhaseRing::cVar_4k5qqSle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H39XgrFZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_YitKmdmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YitKmdmR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NMpeHMNa, 0, m, &cDelay_NMpeHMNa_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kZbSpnoU, 0, m, &sTabread_kZbSpnoU_sendMessage);
}

void Heavy_PhaseRing::cDelay_NMpeHMNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NMpeHMNa, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kZbSpnoU, 0, m, &sTabread_kZbSpnoU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NMpeHMNa, 0, m, &cDelay_NMpeHMNa_sendMessage);
}

void Heavy_PhaseRing::sTabread_kZbSpnoU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_FTMLvNaW, HV_BINOP_SUBTRACT, 0, m, &cBinop_FTMLvNaW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_lkOYe2De_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zuVeZA7Z, HV_BINOP_MAX, 0, m, &cBinop_zuVeZA7Z_sendMessage);
}

void Heavy_PhaseRing::cBinop_594qlgfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lkOYe2De, HV_BINOP_MULTIPLY, 0, m, &cBinop_lkOYe2De_sendMessage);
}

void Heavy_PhaseRing::cBinop_EYOgrxt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4FazbDTY_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kZbSpnoU, 0, m, &sTabread_kZbSpnoU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WJNLpHqe_sendMessage);
}

void Heavy_PhaseRing::cSystem_MRKFTzRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FTMLvNaW, HV_BINOP_SUBTRACT, 1, m, &cBinop_FTMLvNaW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NMpeHMNa, 2, m, &cDelay_NMpeHMNa_sendMessage);
}

void Heavy_PhaseRing::cMsg_H39XgrFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MRKFTzRR_sendMessage);
}

void Heavy_PhaseRing::cMsg_4FazbDTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YitKmdmR, 0, m, &cDelay_YitKmdmR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NMpeHMNa, 0, m, &cDelay_NMpeHMNa_sendMessage);
}

void Heavy_PhaseRing::cMsg_y3N9HnLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_zuVeZA7Z, HV_BINOP_MAX, 1, m, &cBinop_zuVeZA7Z_sendMessage);
}

void Heavy_PhaseRing::cBinop_zuVeZA7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EYOgrxt9, HV_BINOP_SUBTRACT, 1, m, &cBinop_EYOgrxt9_sendMessage);
}

void Heavy_PhaseRing::cCast_WJNLpHqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YitKmdmR, 0, m, &cDelay_YitKmdmR_sendMessage);
}

void Heavy_PhaseRing::cBinop_77At2zxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YitKmdmR, 2, m, &cDelay_YitKmdmR_sendMessage);
}

void Heavy_PhaseRing::cBinop_FTMLvNaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_77At2zxh_sendMessage);
}

void Heavy_PhaseRing::cCast_lhGYiwp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4k5qqSle, 0, m, &cVar_4k5qqSle_sendMessage);
  cMsg_6MtvyG2p_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EIuMrBwv, 0, m, &cTabhead_EIuMrBwv_sendMessage);
}

void Heavy_PhaseRing::cTabhead_kladtYAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9nOPe9c9, HV_BINOP_SUBTRACT, 0, m, &cBinop_9nOPe9c9_sendMessage);
}

void Heavy_PhaseRing::cMsg_5CE4emeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CppTWVMr_sendMessage);
}

void Heavy_PhaseRing::cSystem_CppTWVMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ot5vVvoJ_sendMessage);
}

void Heavy_PhaseRing::cVar_Nz53AEGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TUztgaTE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_eLPt0H1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eLPt0H1G, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sALvnZzS, 0, m, &cDelay_sALvnZzS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VDlUKKBc, 0, m, &sTabread_VDlUKKBc_sendMessage);
}

void Heavy_PhaseRing::cDelay_sALvnZzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sALvnZzS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VDlUKKBc, 0, m, &sTabread_VDlUKKBc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sALvnZzS, 0, m, &cDelay_sALvnZzS_sendMessage);
}

void Heavy_PhaseRing::sTabread_VDlUKKBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ysT1vAxa, HV_BINOP_SUBTRACT, 0, m, &cBinop_ysT1vAxa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_jKY1dZT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3AyFN7mm, HV_BINOP_MAX, 0, m, &cBinop_3AyFN7mm_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ot5vVvoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jKY1dZT1, HV_BINOP_MULTIPLY, 0, m, &cBinop_jKY1dZT1_sendMessage);
}

void Heavy_PhaseRing::cBinop_9nOPe9c9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c143fqWI_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VDlUKKBc, 0, m, &sTabread_VDlUKKBc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cm92ctDz_sendMessage);
}

void Heavy_PhaseRing::cSystem_fsagNdZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ysT1vAxa, HV_BINOP_SUBTRACT, 1, m, &cBinop_ysT1vAxa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sALvnZzS, 2, m, &cDelay_sALvnZzS_sendMessage);
}

void Heavy_PhaseRing::cMsg_TUztgaTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fsagNdZQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_c143fqWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_eLPt0H1G, 0, m, &cDelay_eLPt0H1G_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sALvnZzS, 0, m, &cDelay_sALvnZzS_sendMessage);
}

void Heavy_PhaseRing::cMsg_8FqIvc3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_3AyFN7mm, HV_BINOP_MAX, 1, m, &cBinop_3AyFN7mm_sendMessage);
}

void Heavy_PhaseRing::cBinop_3AyFN7mm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9nOPe9c9, HV_BINOP_SUBTRACT, 1, m, &cBinop_9nOPe9c9_sendMessage);
}

void Heavy_PhaseRing::cCast_Cm92ctDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eLPt0H1G, 0, m, &cDelay_eLPt0H1G_sendMessage);
}

void Heavy_PhaseRing::cBinop_1pzxICkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eLPt0H1G, 2, m, &cDelay_eLPt0H1G_sendMessage);
}

void Heavy_PhaseRing::cBinop_ysT1vAxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1pzxICkE_sendMessage);
}

void Heavy_PhaseRing::cCast_em2aw4cm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Nz53AEGq, 0, m, &cVar_Nz53AEGq_sendMessage);
  cMsg_5CE4emeI_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kladtYAp, 0, m, &cTabhead_kladtYAp_sendMessage);
}

void Heavy_PhaseRing::cTabhead_ZitnlkJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c8d7sW2W, HV_BINOP_SUBTRACT, 0, m, &cBinop_c8d7sW2W_sendMessage);
}

void Heavy_PhaseRing::cMsg_SldyUoDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fv45jCM6_sendMessage);
}

void Heavy_PhaseRing::cSystem_fv45jCM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JNOBdB40_sendMessage);
}

void Heavy_PhaseRing::cVar_yHyoXIx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pHCoeomH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_bzzC5jIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bzzC5jIa, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kv2o9GOb, 0, m, &cDelay_Kv2o9GOb_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uBeiRDrW, 0, m, &sTabread_uBeiRDrW_sendMessage);
}

void Heavy_PhaseRing::cDelay_Kv2o9GOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Kv2o9GOb, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uBeiRDrW, 0, m, &sTabread_uBeiRDrW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kv2o9GOb, 0, m, &cDelay_Kv2o9GOb_sendMessage);
}

void Heavy_PhaseRing::sTabread_uBeiRDrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fBlVodfn, HV_BINOP_SUBTRACT, 0, m, &cBinop_fBlVodfn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_PDAtOdw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1oDbsHy7, HV_BINOP_MAX, 0, m, &cBinop_1oDbsHy7_sendMessage);
}

void Heavy_PhaseRing::cBinop_JNOBdB40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PDAtOdw7, HV_BINOP_MULTIPLY, 0, m, &cBinop_PDAtOdw7_sendMessage);
}

void Heavy_PhaseRing::cBinop_c8d7sW2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hBBX8Wij_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uBeiRDrW, 0, m, &sTabread_uBeiRDrW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4EUHfElx_sendMessage);
}

void Heavy_PhaseRing::cSystem_XMIhmCbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fBlVodfn, HV_BINOP_SUBTRACT, 1, m, &cBinop_fBlVodfn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kv2o9GOb, 2, m, &cDelay_Kv2o9GOb_sendMessage);
}

void Heavy_PhaseRing::cMsg_pHCoeomH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XMIhmCbl_sendMessage);
}

void Heavy_PhaseRing::cMsg_hBBX8Wij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bzzC5jIa, 0, m, &cDelay_bzzC5jIa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kv2o9GOb, 0, m, &cDelay_Kv2o9GOb_sendMessage);
}

void Heavy_PhaseRing::cMsg_IN2WWRTp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_1oDbsHy7, HV_BINOP_MAX, 1, m, &cBinop_1oDbsHy7_sendMessage);
}

void Heavy_PhaseRing::cBinop_1oDbsHy7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c8d7sW2W, HV_BINOP_SUBTRACT, 1, m, &cBinop_c8d7sW2W_sendMessage);
}

void Heavy_PhaseRing::cCast_4EUHfElx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bzzC5jIa, 0, m, &cDelay_bzzC5jIa_sendMessage);
}

void Heavy_PhaseRing::cBinop_g0smgPHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bzzC5jIa, 2, m, &cDelay_bzzC5jIa_sendMessage);
}

void Heavy_PhaseRing::cBinop_fBlVodfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_g0smgPHM_sendMessage);
}

void Heavy_PhaseRing::cCast_Zn5ckEHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yHyoXIx9, 0, m, &cVar_yHyoXIx9_sendMessage);
  cMsg_SldyUoDh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZitnlkJz, 0, m, &cTabhead_ZitnlkJz_sendMessage);
}

void Heavy_PhaseRing::cTabhead_xvYgYoT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ogld3fPD, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ogld3fPD_sendMessage);
}

void Heavy_PhaseRing::cMsg_8B9dOwXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LgKMJ5fS_sendMessage);
}

void Heavy_PhaseRing::cSystem_LgKMJ5fS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vyieWZQs_sendMessage);
}

void Heavy_PhaseRing::cVar_s8QlkCHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tTS6ooWZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_naNBRtFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_naNBRtFl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oJZNBWtV, 0, m, &cDelay_oJZNBWtV_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3VpwcPro, 0, m, &sTabread_3VpwcPro_sendMessage);
}

void Heavy_PhaseRing::cDelay_oJZNBWtV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oJZNBWtV, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3VpwcPro, 0, m, &sTabread_3VpwcPro_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oJZNBWtV, 0, m, &cDelay_oJZNBWtV_sendMessage);
}

void Heavy_PhaseRing::sTabread_3VpwcPro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jAJDaAGO, HV_BINOP_SUBTRACT, 0, m, &cBinop_jAJDaAGO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_UPqgy9nN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GkrnHhPi, HV_BINOP_MAX, 0, m, &cBinop_GkrnHhPi_sendMessage);
}

void Heavy_PhaseRing::cBinop_vyieWZQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UPqgy9nN, HV_BINOP_MULTIPLY, 0, m, &cBinop_UPqgy9nN_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ogld3fPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BQ9fTjwj_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3VpwcPro, 0, m, &sTabread_3VpwcPro_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wwlt1J00_sendMessage);
}

void Heavy_PhaseRing::cSystem_tXKXAOwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jAJDaAGO, HV_BINOP_SUBTRACT, 1, m, &cBinop_jAJDaAGO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oJZNBWtV, 2, m, &cDelay_oJZNBWtV_sendMessage);
}

void Heavy_PhaseRing::cMsg_tTS6ooWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tXKXAOwo_sendMessage);
}

void Heavy_PhaseRing::cMsg_BQ9fTjwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_naNBRtFl, 0, m, &cDelay_naNBRtFl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oJZNBWtV, 0, m, &cDelay_oJZNBWtV_sendMessage);
}

void Heavy_PhaseRing::cMsg_9vcsLnwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_GkrnHhPi, HV_BINOP_MAX, 1, m, &cBinop_GkrnHhPi_sendMessage);
}

void Heavy_PhaseRing::cBinop_GkrnHhPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ogld3fPD, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ogld3fPD_sendMessage);
}

void Heavy_PhaseRing::cCast_wwlt1J00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_naNBRtFl, 0, m, &cDelay_naNBRtFl_sendMessage);
}

void Heavy_PhaseRing::cBinop_cjkj4K9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_naNBRtFl, 2, m, &cDelay_naNBRtFl_sendMessage);
}

void Heavy_PhaseRing::cBinop_jAJDaAGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cjkj4K9N_sendMessage);
}

void Heavy_PhaseRing::cCast_YTPjCWsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s8QlkCHL, 0, m, &cVar_s8QlkCHL_sendMessage);
  cMsg_8B9dOwXC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_xvYgYoT8, 0, m, &cTabhead_xvYgYoT8_sendMessage);
}

void Heavy_PhaseRing::cMsg_Wgm8d0fa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5ct7FWEj_sendMessage);
}

void Heavy_PhaseRing::cSystem_5ct7FWEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yub5F9i0_sendMessage);
}

void Heavy_PhaseRing::cDelay_mkN7zfYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mkN7zfYi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kHyoTOQG, 0, m, &cDelay_kHyoTOQG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mkN7zfYi, 0, m, &cDelay_mkN7zfYi_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_43udeLsA, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_kHyoTOQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kHyoTOQG, m);
  cMsg_y7O7u5X8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_a6VxDtsQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_w4dBqoGt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_X7WX3Jm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N2Eiy83J_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_M1rYVYAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YsPpFW08_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mkN7zfYi, 2, m, &cDelay_mkN7zfYi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0ZStYYj2_sendMessage);
}

void Heavy_PhaseRing::cMsg_N2Eiy83J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_M1rYVYAE, 0, m, &hTable_M1rYVYAE_sendMessage);
}

void Heavy_PhaseRing::cBinop_yub5F9i0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_X7WX3Jm2_sendMessage);
}

void Heavy_PhaseRing::cMsg_y7O7u5X8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_M1rYVYAE, 0, m, &hTable_M1rYVYAE_sendMessage);
}

void Heavy_PhaseRing::cCast_0ZStYYj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mkN7zfYi, 0, m, &cDelay_mkN7zfYi_sendMessage);
}

void Heavy_PhaseRing::cMsg_YsPpFW08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kHyoTOQG, 2, m, &cDelay_kHyoTOQG_sendMessage);
}

void Heavy_PhaseRing::cMsg_w4dBqoGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_43udeLsA, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_l9SHvoPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PVRqldzv_sendMessage);
}

void Heavy_PhaseRing::cSystem_PVRqldzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WnjNtrfb_sendMessage);
}

void Heavy_PhaseRing::cDelay_0rYfKjAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0rYfKjAs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XkeusFgD, 0, m, &cDelay_XkeusFgD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0rYfKjAs, 0, m, &cDelay_0rYfKjAs_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mGVewA1Y, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_XkeusFgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XkeusFgD, m);
  cMsg_rXdrMJs6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_unyKlVvY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_HdV9u2dc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_C7pEMgnQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YhUvKvPB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_5XeJExYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nxdBtN40_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0rYfKjAs, 2, m, &cDelay_0rYfKjAs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qEGPYehU_sendMessage);
}

void Heavy_PhaseRing::cMsg_YhUvKvPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_5XeJExYj, 0, m, &hTable_5XeJExYj_sendMessage);
}

void Heavy_PhaseRing::cBinop_WnjNtrfb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_C7pEMgnQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_rXdrMJs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_5XeJExYj, 0, m, &hTable_5XeJExYj_sendMessage);
}

void Heavy_PhaseRing::cCast_qEGPYehU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0rYfKjAs, 0, m, &cDelay_0rYfKjAs_sendMessage);
}

void Heavy_PhaseRing::cMsg_nxdBtN40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XkeusFgD, 2, m, &cDelay_XkeusFgD_sendMessage);
}

void Heavy_PhaseRing::cMsg_HdV9u2dc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mGVewA1Y, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_RkuVKUEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hILUJFkn_sendMessage);
}

void Heavy_PhaseRing::cSystem_hILUJFkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_a3X1g4PQ_sendMessage);
}

void Heavy_PhaseRing::cDelay_i6z5I7dm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_i6z5I7dm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_e2W1oOj5, 0, m, &cDelay_e2W1oOj5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_i6z5I7dm, 0, m, &cDelay_i6z5I7dm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zN0I33gf, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_e2W1oOj5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_e2W1oOj5, m);
  cMsg_Nk5WHmya_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_sMBOLUTs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_em0skRws_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_kzSlO14O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4FJBjxVI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_B33IOwXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qBXM6wlr_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_i6z5I7dm, 2, m, &cDelay_i6z5I7dm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wpqt9KzU_sendMessage);
}

void Heavy_PhaseRing::cMsg_4FJBjxVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_B33IOwXy, 0, m, &hTable_B33IOwXy_sendMessage);
}

void Heavy_PhaseRing::cBinop_a3X1g4PQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_kzSlO14O_sendMessage);
}

void Heavy_PhaseRing::cMsg_Nk5WHmya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_B33IOwXy, 0, m, &hTable_B33IOwXy_sendMessage);
}

void Heavy_PhaseRing::cCast_wpqt9KzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_i6z5I7dm, 0, m, &cDelay_i6z5I7dm_sendMessage);
}

void Heavy_PhaseRing::cMsg_qBXM6wlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_e2W1oOj5, 2, m, &cDelay_e2W1oOj5_sendMessage);
}

void Heavy_PhaseRing::cMsg_em0skRws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zN0I33gf, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_fZseH6iV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K3YlKDrV_sendMessage);
}

void Heavy_PhaseRing::cSystem_K3YlKDrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XnfE3rlQ_sendMessage);
}

void Heavy_PhaseRing::cDelay_6cppwRCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6cppwRCN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JKg3cTs8, 0, m, &cDelay_JKg3cTs8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6cppwRCN, 0, m, &cDelay_6cppwRCN_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rT7B78Ix, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_JKg3cTs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JKg3cTs8, m);
  cMsg_ZkDYLexY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_IvCrXNT7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_z8HF8s9g_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_RtoQJKH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0dELEyKI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_ydIMUu9i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TaqEyxkR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6cppwRCN, 2, m, &cDelay_6cppwRCN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qXoaV6IY_sendMessage);
}

void Heavy_PhaseRing::cMsg_0dELEyKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ydIMUu9i, 0, m, &hTable_ydIMUu9i_sendMessage);
}

void Heavy_PhaseRing::cBinop_XnfE3rlQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_RtoQJKH3_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZkDYLexY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ydIMUu9i, 0, m, &hTable_ydIMUu9i_sendMessage);
}

void Heavy_PhaseRing::cCast_qXoaV6IY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6cppwRCN, 0, m, &cDelay_6cppwRCN_sendMessage);
}

void Heavy_PhaseRing::cMsg_TaqEyxkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_JKg3cTs8, 2, m, &cDelay_JKg3cTs8_sendMessage);
}

void Heavy_PhaseRing::cMsg_z8HF8s9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rT7B78Ix, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_7SAxiJf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_SwktKIJg_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_h51FeHWZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_F42QUHXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ovFgPnIy, HV_BINOP_POW, 0, m, &cBinop_ovFgPnIy_sendMessage);
}

void Heavy_PhaseRing::cBinop_ovFgPnIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_WqQkUkFt_sendMessage);
}

void Heavy_PhaseRing::cBinop_7DGQjZEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_KY1neVen_sendMessage);
}

void Heavy_PhaseRing::cCast_ZP4PszLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Cyg2GsBg_sendMessage);
}

void Heavy_PhaseRing::cCast_np8SGkbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7SAxiJf5, 0, m, &cIf_7SAxiJf5_sendMessage);
}

void Heavy_PhaseRing::cBinop_Cyg2GsBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7SAxiJf5, 1, m, &cIf_7SAxiJf5_sendMessage);
}

void Heavy_PhaseRing::cBinop_h51FeHWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_7DGQjZEc_sendMessage);
}

void Heavy_PhaseRing::cMsg_SwktKIJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_WqQkUkFt_sendMessage);
}

void Heavy_PhaseRing::cBinop_KY1neVen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ovFgPnIy, HV_BINOP_POW, 1, m, &cBinop_ovFgPnIy_sendMessage);
  cMsg_F42QUHXs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_oYibzZju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xjTgnxKo, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_ROrUWDcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PAnsX5zg, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_pg31pLqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5EZPD5qE_sendMessage);
}

void Heavy_PhaseRing::cBinop_5EZPD5qE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_AsbSFopY_sendMessage);
}

void Heavy_PhaseRing::cVar_pFdDqbIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iNkPXPDv, HV_BINOP_MULTIPLY, 0, m, &cBinop_iNkPXPDv_sendMessage);
}

void Heavy_PhaseRing::cMsg_DXK5dQ8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5tEAPSww_sendMessage);
}

void Heavy_PhaseRing::cSystem_5tEAPSww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LlMkcrJg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_iNkPXPDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_cwcsGbwj_sendMessage);
}

void Heavy_PhaseRing::cBinop_BCaFO5nL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iNkPXPDv, HV_BINOP_MULTIPLY, 1, m, &cBinop_iNkPXPDv_sendMessage);
}

void Heavy_PhaseRing::cMsg_LlMkcrJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BCaFO5nL_sendMessage);
}

void Heavy_PhaseRing::cBinop_cwcsGbwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5qBQFQmK_sendMessage);
}

void Heavy_PhaseRing::cBinop_5qBQFQmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XzhcPsxK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_M5ttx0Hr, m);
}

void Heavy_PhaseRing::cBinop_XzhcPsxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kDTd7ARj, m);
}

void Heavy_PhaseRing::cVar_JdvEXeF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZP4PszLi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_np8SGkbL_sendMessage);
}

void Heavy_PhaseRing::cVar_8Sv7xkSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_pg31pLqu_sendMessage);
}

void Heavy_PhaseRing::cVar_W9892EYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_Dt89O7jL_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_l17kefhp, 0, m, &cIf_l17kefhp_sendMessage);
}

void Heavy_PhaseRing::cVar_PY43sc3t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_MMY8ATfp_sendMessage);
}

void Heavy_PhaseRing::cIf_l17kefhp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_MEu59cpu_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_cTQu7TXa, 0, m, &cVar_cTQu7TXa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Dt89O7jL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_l17kefhp, 1, m, &cIf_l17kefhp_sendMessage);
}

void Heavy_PhaseRing::cBinop_MMY8ATfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Jv9GwnDw_sendMessage);
}

void Heavy_PhaseRing::cBinop_Jv9GwnDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cIMUacQS, 0, m, &cVar_cIMUacQS_sendMessage);
}

void Heavy_PhaseRing::cTabhead_sPzwrraR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xtcx3IQ0, HV_BINOP_SUBTRACT, 0, m, &cBinop_Xtcx3IQ0_sendMessage);
}

void Heavy_PhaseRing::cMsg_mhrjUVHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mnwg0fa6_sendMessage);
}

void Heavy_PhaseRing::cSystem_mnwg0fa6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_D1I58vHZ_sendMessage);
}

void Heavy_PhaseRing::cVar_Fu3LHd7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NF2azVWm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_8mYj7hrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8mYj7hrW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vCETmHlC, 0, m, &cDelay_vCETmHlC_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0wySjqiB, 0, m, &sTabread_0wySjqiB_sendMessage);
}

void Heavy_PhaseRing::cDelay_vCETmHlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vCETmHlC, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0wySjqiB, 0, m, &sTabread_0wySjqiB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vCETmHlC, 0, m, &cDelay_vCETmHlC_sendMessage);
}

void Heavy_PhaseRing::sTabread_0wySjqiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_PWiZC8Lq, HV_BINOP_SUBTRACT, 0, m, &cBinop_PWiZC8Lq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_8eGsjW2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9tKEt1so, HV_BINOP_MAX, 0, m, &cBinop_9tKEt1so_sendMessage);
}

void Heavy_PhaseRing::cBinop_D1I58vHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8eGsjW2u, HV_BINOP_MULTIPLY, 0, m, &cBinop_8eGsjW2u_sendMessage);
}

void Heavy_PhaseRing::cBinop_Xtcx3IQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cJvJgnEF_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0wySjqiB, 0, m, &sTabread_0wySjqiB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BLtqSX9s_sendMessage);
}

void Heavy_PhaseRing::cSystem_aLR0VO7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PWiZC8Lq, HV_BINOP_SUBTRACT, 1, m, &cBinop_PWiZC8Lq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vCETmHlC, 2, m, &cDelay_vCETmHlC_sendMessage);
}

void Heavy_PhaseRing::cMsg_NF2azVWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aLR0VO7J_sendMessage);
}

void Heavy_PhaseRing::cMsg_cJvJgnEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8mYj7hrW, 0, m, &cDelay_8mYj7hrW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vCETmHlC, 0, m, &cDelay_vCETmHlC_sendMessage);
}

void Heavy_PhaseRing::cMsg_qi260ApG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9tKEt1so, HV_BINOP_MAX, 1, m, &cBinop_9tKEt1so_sendMessage);
}

void Heavy_PhaseRing::cBinop_9tKEt1so_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xtcx3IQ0, HV_BINOP_SUBTRACT, 1, m, &cBinop_Xtcx3IQ0_sendMessage);
}

void Heavy_PhaseRing::cCast_BLtqSX9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8mYj7hrW, 0, m, &cDelay_8mYj7hrW_sendMessage);
}

void Heavy_PhaseRing::cBinop_wklEncDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8mYj7hrW, 2, m, &cDelay_8mYj7hrW_sendMessage);
}

void Heavy_PhaseRing::cBinop_PWiZC8Lq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wklEncDP_sendMessage);
}

void Heavy_PhaseRing::cCast_h5iWzEZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Fu3LHd7f, 0, m, &cVar_Fu3LHd7f_sendMessage);
  cMsg_mhrjUVHa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sPzwrraR, 0, m, &cTabhead_sPzwrraR_sendMessage);
}

void Heavy_PhaseRing::cMsg_rl1UneHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R743DJ3j_sendMessage);
}

void Heavy_PhaseRing::cSystem_R743DJ3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RhSb7DQm_sendMessage);
}

void Heavy_PhaseRing::cDelay_833OB0xe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_833OB0xe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CvItOc9j, 0, m, &cDelay_CvItOc9j_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_833OB0xe, 0, m, &cDelay_833OB0xe_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fXzbIy6j, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_CvItOc9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CvItOc9j, m);
  cMsg_uFNrTgFn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_orM6sBJr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_eFq7QIWC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_TzYSMNbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oEPC0hM4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_6MNDkIzt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YmbEROKI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_833OB0xe, 2, m, &cDelay_833OB0xe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2AjT2ROf_sendMessage);
}

void Heavy_PhaseRing::cMsg_oEPC0hM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6MNDkIzt, 0, m, &hTable_6MNDkIzt_sendMessage);
}

void Heavy_PhaseRing::cBinop_RhSb7DQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_TzYSMNbA_sendMessage);
}

void Heavy_PhaseRing::cMsg_uFNrTgFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6MNDkIzt, 0, m, &hTable_6MNDkIzt_sendMessage);
}

void Heavy_PhaseRing::cCast_2AjT2ROf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_833OB0xe, 0, m, &cDelay_833OB0xe_sendMessage);
}

void Heavy_PhaseRing::cMsg_YmbEROKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_CvItOc9j, 2, m, &cDelay_CvItOc9j_sendMessage);
}

void Heavy_PhaseRing::cMsg_eFq7QIWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fXzbIy6j, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_9J3vn407_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gYGyawHy, HV_BINOP_SUBTRACT, 0, m, &cBinop_gYGyawHy_sendMessage);
}

void Heavy_PhaseRing::cMsg_zdgcTjRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pDdEOjA6_sendMessage);
}

void Heavy_PhaseRing::cSystem_pDdEOjA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XQ3l9RqX_sendMessage);
}

void Heavy_PhaseRing::cVar_NyEn7IN9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0da0dNb7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_Bl0oubVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Bl0oubVU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iS7gmIZb, 0, m, &cDelay_iS7gmIZb_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nUbLFRYq, 0, m, &sTabread_nUbLFRYq_sendMessage);
}

void Heavy_PhaseRing::cDelay_iS7gmIZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iS7gmIZb, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nUbLFRYq, 0, m, &sTabread_nUbLFRYq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iS7gmIZb, 0, m, &cDelay_iS7gmIZb_sendMessage);
}

void Heavy_PhaseRing::sTabread_nUbLFRYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qKrSRncX, HV_BINOP_SUBTRACT, 0, m, &cBinop_qKrSRncX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_gXtGfBW9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NNf4yaZy, HV_BINOP_MAX, 0, m, &cBinop_NNf4yaZy_sendMessage);
}

void Heavy_PhaseRing::cBinop_XQ3l9RqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gXtGfBW9, HV_BINOP_MULTIPLY, 0, m, &cBinop_gXtGfBW9_sendMessage);
}

void Heavy_PhaseRing::cBinop_gYGyawHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mrl6ieqP_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nUbLFRYq, 0, m, &sTabread_nUbLFRYq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4j3iWLRO_sendMessage);
}

void Heavy_PhaseRing::cSystem_eQRw9gaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qKrSRncX, HV_BINOP_SUBTRACT, 1, m, &cBinop_qKrSRncX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iS7gmIZb, 2, m, &cDelay_iS7gmIZb_sendMessage);
}

void Heavy_PhaseRing::cMsg_0da0dNb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eQRw9gaE_sendMessage);
}

void Heavy_PhaseRing::cMsg_mrl6ieqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bl0oubVU, 0, m, &cDelay_Bl0oubVU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iS7gmIZb, 0, m, &cDelay_iS7gmIZb_sendMessage);
}

void Heavy_PhaseRing::cMsg_vgLNtj0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_NNf4yaZy, HV_BINOP_MAX, 1, m, &cBinop_NNf4yaZy_sendMessage);
}

void Heavy_PhaseRing::cBinop_NNf4yaZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gYGyawHy, HV_BINOP_SUBTRACT, 1, m, &cBinop_gYGyawHy_sendMessage);
}

void Heavy_PhaseRing::cCast_4j3iWLRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bl0oubVU, 0, m, &cDelay_Bl0oubVU_sendMessage);
}

void Heavy_PhaseRing::cBinop_6Qs00MCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bl0oubVU, 2, m, &cDelay_Bl0oubVU_sendMessage);
}

void Heavy_PhaseRing::cBinop_qKrSRncX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6Qs00MCn_sendMessage);
}

void Heavy_PhaseRing::cCast_CCQHNjNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NyEn7IN9, 0, m, &cVar_NyEn7IN9_sendMessage);
  cMsg_zdgcTjRO_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9J3vn407, 0, m, &cTabhead_9J3vn407_sendMessage);
}

void Heavy_PhaseRing::cMsg_U9PWyVVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZdZlx31C_sendMessage);
}

void Heavy_PhaseRing::cSystem_ZdZlx31C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4lhrOadJ_sendMessage);
}

void Heavy_PhaseRing::cDelay_yRc6Umav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yRc6Umav, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S1vMFU2c, 0, m, &cDelay_S1vMFU2c_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yRc6Umav, 0, m, &cDelay_yRc6Umav_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SewxLwmm, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_S1vMFU2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_S1vMFU2c, m);
  cMsg_gfj2yC0P_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_D7s730ry_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_2taNsgRG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_4flMYg7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2jO4QhsF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_VVfLeoyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x4k8x8gm_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yRc6Umav, 2, m, &cDelay_yRc6Umav_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dGRG2SOI_sendMessage);
}

void Heavy_PhaseRing::cMsg_2jO4QhsF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VVfLeoyT, 0, m, &hTable_VVfLeoyT_sendMessage);
}

void Heavy_PhaseRing::cBinop_4lhrOadJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_4flMYg7c_sendMessage);
}

void Heavy_PhaseRing::cMsg_gfj2yC0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VVfLeoyT, 0, m, &hTable_VVfLeoyT_sendMessage);
}

void Heavy_PhaseRing::cCast_dGRG2SOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yRc6Umav, 0, m, &cDelay_yRc6Umav_sendMessage);
}

void Heavy_PhaseRing::cMsg_x4k8x8gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_S1vMFU2c, 2, m, &cDelay_S1vMFU2c_sendMessage);
}

void Heavy_PhaseRing::cMsg_2taNsgRG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SewxLwmm, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_QhIIM1Wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8Wz2uWIB, HV_BINOP_SUBTRACT, 0, m, &cBinop_8Wz2uWIB_sendMessage);
}

void Heavy_PhaseRing::cMsg_mQykVerV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r6dDRD7c_sendMessage);
}

void Heavy_PhaseRing::cSystem_r6dDRD7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NsL8dlIq_sendMessage);
}

void Heavy_PhaseRing::cVar_gdktfi2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IwxVKRPX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_uoTQW5FF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uoTQW5FF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IudEQopu, 0, m, &cDelay_IudEQopu_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FkP35a8D, 0, m, &sTabread_FkP35a8D_sendMessage);
}

void Heavy_PhaseRing::cDelay_IudEQopu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IudEQopu, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FkP35a8D, 0, m, &sTabread_FkP35a8D_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IudEQopu, 0, m, &cDelay_IudEQopu_sendMessage);
}

void Heavy_PhaseRing::sTabread_FkP35a8D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_7UMrAnKg, HV_BINOP_SUBTRACT, 0, m, &cBinop_7UMrAnKg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_QvB1XFtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FpeK57c6, HV_BINOP_MAX, 0, m, &cBinop_FpeK57c6_sendMessage);
}

void Heavy_PhaseRing::cBinop_NsL8dlIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QvB1XFtG, HV_BINOP_MULTIPLY, 0, m, &cBinop_QvB1XFtG_sendMessage);
}

void Heavy_PhaseRing::cBinop_8Wz2uWIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kMhG6eQQ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FkP35a8D, 0, m, &sTabread_FkP35a8D_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lm5PLXse_sendMessage);
}

void Heavy_PhaseRing::cSystem_qmYJRTrc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7UMrAnKg, HV_BINOP_SUBTRACT, 1, m, &cBinop_7UMrAnKg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IudEQopu, 2, m, &cDelay_IudEQopu_sendMessage);
}

void Heavy_PhaseRing::cMsg_IwxVKRPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qmYJRTrc_sendMessage);
}

void Heavy_PhaseRing::cMsg_kMhG6eQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_uoTQW5FF, 0, m, &cDelay_uoTQW5FF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IudEQopu, 0, m, &cDelay_IudEQopu_sendMessage);
}

void Heavy_PhaseRing::cMsg_3ZAcFCbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_FpeK57c6, HV_BINOP_MAX, 1, m, &cBinop_FpeK57c6_sendMessage);
}

void Heavy_PhaseRing::cBinop_FpeK57c6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8Wz2uWIB, HV_BINOP_SUBTRACT, 1, m, &cBinop_8Wz2uWIB_sendMessage);
}

void Heavy_PhaseRing::cCast_lm5PLXse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uoTQW5FF, 0, m, &cDelay_uoTQW5FF_sendMessage);
}

void Heavy_PhaseRing::cBinop_cnkw6Qro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uoTQW5FF, 2, m, &cDelay_uoTQW5FF_sendMessage);
}

void Heavy_PhaseRing::cBinop_7UMrAnKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cnkw6Qro_sendMessage);
}

void Heavy_PhaseRing::cCast_oBP9Y31v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gdktfi2h, 0, m, &cVar_gdktfi2h_sendMessage);
  cMsg_mQykVerV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QhIIM1Wp, 0, m, &cTabhead_QhIIM1Wp_sendMessage);
}

void Heavy_PhaseRing::cMsg_SP87JvKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HTjqwMl3_sendMessage);
}

void Heavy_PhaseRing::cSystem_HTjqwMl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zQ4CvdMh_sendMessage);
}

void Heavy_PhaseRing::cDelay_Z7XkxSaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Z7XkxSaZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AYrgqUmr, 0, m, &cDelay_AYrgqUmr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z7XkxSaZ, 0, m, &cDelay_Z7XkxSaZ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8IOOxRRR, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_AYrgqUmr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AYrgqUmr, m);
  cMsg_cjzRwDjU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_PjiltRiy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ES80I7Y4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_een87TVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eix8MzVo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_0ArOQmiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L6cdWXtC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z7XkxSaZ, 2, m, &cDelay_Z7XkxSaZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A1x8SvAe_sendMessage);
}

void Heavy_PhaseRing::cMsg_eix8MzVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_0ArOQmiF, 0, m, &hTable_0ArOQmiF_sendMessage);
}

void Heavy_PhaseRing::cBinop_zQ4CvdMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_een87TVJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_cjzRwDjU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_0ArOQmiF, 0, m, &hTable_0ArOQmiF_sendMessage);
}

void Heavy_PhaseRing::cCast_A1x8SvAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z7XkxSaZ, 0, m, &cDelay_Z7XkxSaZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_L6cdWXtC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_AYrgqUmr, 2, m, &cDelay_AYrgqUmr_sendMessage);
}

void Heavy_PhaseRing::cMsg_ES80I7Y4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8IOOxRRR, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_7igCf9ZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4M5y7FJh, HV_BINOP_SUBTRACT, 0, m, &cBinop_4M5y7FJh_sendMessage);
}

void Heavy_PhaseRing::cMsg_6bPM3Zf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FGyq0Jcq_sendMessage);
}

void Heavy_PhaseRing::cSystem_FGyq0Jcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_96NgX2ni_sendMessage);
}

void Heavy_PhaseRing::cVar_rgmbpMPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0XBWcMPV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_sBvRVht6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sBvRVht6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dIBMKLNm, 0, m, &cDelay_dIBMKLNm_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZTn4TLVK, 0, m, &sTabread_ZTn4TLVK_sendMessage);
}

void Heavy_PhaseRing::cDelay_dIBMKLNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dIBMKLNm, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZTn4TLVK, 0, m, &sTabread_ZTn4TLVK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dIBMKLNm, 0, m, &cDelay_dIBMKLNm_sendMessage);
}

void Heavy_PhaseRing::sTabread_ZTn4TLVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_8TkYuhTJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_8TkYuhTJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_CZqidWcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cj78Oo2B, HV_BINOP_MAX, 0, m, &cBinop_cj78Oo2B_sendMessage);
}

void Heavy_PhaseRing::cBinop_96NgX2ni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CZqidWcr, HV_BINOP_MULTIPLY, 0, m, &cBinop_CZqidWcr_sendMessage);
}

void Heavy_PhaseRing::cBinop_4M5y7FJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eDpytzXc_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZTn4TLVK, 0, m, &sTabread_ZTn4TLVK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eYxLspQg_sendMessage);
}

void Heavy_PhaseRing::cSystem_T8dyOc96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8TkYuhTJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_8TkYuhTJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dIBMKLNm, 2, m, &cDelay_dIBMKLNm_sendMessage);
}

void Heavy_PhaseRing::cMsg_0XBWcMPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_T8dyOc96_sendMessage);
}

void Heavy_PhaseRing::cMsg_eDpytzXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sBvRVht6, 0, m, &cDelay_sBvRVht6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dIBMKLNm, 0, m, &cDelay_dIBMKLNm_sendMessage);
}

void Heavy_PhaseRing::cMsg_2wZdGV5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cj78Oo2B, HV_BINOP_MAX, 1, m, &cBinop_cj78Oo2B_sendMessage);
}

void Heavy_PhaseRing::cBinop_cj78Oo2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4M5y7FJh, HV_BINOP_SUBTRACT, 1, m, &cBinop_4M5y7FJh_sendMessage);
}

void Heavy_PhaseRing::cCast_eYxLspQg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sBvRVht6, 0, m, &cDelay_sBvRVht6_sendMessage);
}

void Heavy_PhaseRing::cBinop_ttOde7sm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sBvRVht6, 2, m, &cDelay_sBvRVht6_sendMessage);
}

void Heavy_PhaseRing::cBinop_8TkYuhTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ttOde7sm_sendMessage);
}

void Heavy_PhaseRing::cCast_0eawGhyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rgmbpMPk, 0, m, &cVar_rgmbpMPk_sendMessage);
  cMsg_6bPM3Zf8_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7igCf9ZW, 0, m, &cTabhead_7igCf9ZW_sendMessage);
}

void Heavy_PhaseRing::cMsg_lzoX3zdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Er432thC_sendMessage);
}

void Heavy_PhaseRing::cSystem_Er432thC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RoEQzRSf_sendMessage);
}

void Heavy_PhaseRing::cDelay_0qLR1EdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0qLR1EdC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0d36govI, 0, m, &cDelay_0d36govI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0qLR1EdC, 0, m, &cDelay_0qLR1EdC_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OHMVbHSM, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_0d36govI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0d36govI, m);
  cMsg_bKfmXZao_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_48ZpvecW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_U5HMj8sU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_lO2jYJQc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6UoqRrWH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_ltOQcVTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FTCZW4g8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0qLR1EdC, 2, m, &cDelay_0qLR1EdC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_va9SfIYJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_6UoqRrWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ltOQcVTD, 0, m, &hTable_ltOQcVTD_sendMessage);
}

void Heavy_PhaseRing::cBinop_RoEQzRSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_lO2jYJQc_sendMessage);
}

void Heavy_PhaseRing::cMsg_bKfmXZao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ltOQcVTD, 0, m, &hTable_ltOQcVTD_sendMessage);
}

void Heavy_PhaseRing::cCast_va9SfIYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0qLR1EdC, 0, m, &cDelay_0qLR1EdC_sendMessage);
}

void Heavy_PhaseRing::cMsg_FTCZW4g8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_0d36govI, 2, m, &cDelay_0d36govI_sendMessage);
}

void Heavy_PhaseRing::cMsg_U5HMj8sU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OHMVbHSM, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_vSVFcE5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n7iVOLm7, HV_BINOP_SUBTRACT, 0, m, &cBinop_n7iVOLm7_sendMessage);
}

void Heavy_PhaseRing::cMsg_BamErUFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VQvT9qTJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_VQvT9qTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4w4UMwyv_sendMessage);
}

void Heavy_PhaseRing::cVar_UIQzP1YQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pmMPxVPb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_Gt7R3eD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Gt7R3eD5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dm2fO2A8, 0, m, &cDelay_Dm2fO2A8_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hDmyyXGr, 0, m, &sTabread_hDmyyXGr_sendMessage);
}

void Heavy_PhaseRing::cDelay_Dm2fO2A8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Dm2fO2A8, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hDmyyXGr, 0, m, &sTabread_hDmyyXGr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dm2fO2A8, 0, m, &cDelay_Dm2fO2A8_sendMessage);
}

void Heavy_PhaseRing::sTabread_hDmyyXGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Ctacuj9q, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ctacuj9q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_JXPgZxpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ztGo0js0, HV_BINOP_MAX, 0, m, &cBinop_ztGo0js0_sendMessage);
}

void Heavy_PhaseRing::cBinop_4w4UMwyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JXPgZxpz, HV_BINOP_MULTIPLY, 0, m, &cBinop_JXPgZxpz_sendMessage);
}

void Heavy_PhaseRing::cBinop_n7iVOLm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0rrKGxv8_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hDmyyXGr, 0, m, &sTabread_hDmyyXGr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oDFbyWnm_sendMessage);
}

void Heavy_PhaseRing::cSystem_SWxwnDDo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ctacuj9q, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ctacuj9q_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dm2fO2A8, 2, m, &cDelay_Dm2fO2A8_sendMessage);
}

void Heavy_PhaseRing::cMsg_pmMPxVPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SWxwnDDo_sendMessage);
}

void Heavy_PhaseRing::cMsg_0rrKGxv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gt7R3eD5, 0, m, &cDelay_Gt7R3eD5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dm2fO2A8, 0, m, &cDelay_Dm2fO2A8_sendMessage);
}

void Heavy_PhaseRing::cMsg_2og0hsrB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ztGo0js0, HV_BINOP_MAX, 1, m, &cBinop_ztGo0js0_sendMessage);
}

void Heavy_PhaseRing::cBinop_ztGo0js0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n7iVOLm7, HV_BINOP_SUBTRACT, 1, m, &cBinop_n7iVOLm7_sendMessage);
}

void Heavy_PhaseRing::cCast_oDFbyWnm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gt7R3eD5, 0, m, &cDelay_Gt7R3eD5_sendMessage);
}

void Heavy_PhaseRing::cBinop_06saQvom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gt7R3eD5, 2, m, &cDelay_Gt7R3eD5_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ctacuj9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_06saQvom_sendMessage);
}

void Heavy_PhaseRing::cCast_zthtrNzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UIQzP1YQ, 0, m, &cVar_UIQzP1YQ_sendMessage);
  cMsg_BamErUFv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_vSVFcE5z, 0, m, &cTabhead_vSVFcE5z_sendMessage);
}

void Heavy_PhaseRing::cMsg_K1EBPFWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PuKZ5Dwc_sendMessage);
}

void Heavy_PhaseRing::cSystem_PuKZ5Dwc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LG3vVp6Z_sendMessage);
}

void Heavy_PhaseRing::cDelay_uHloocTA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uHloocTA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1sSo9hxv, 0, m, &cDelay_1sSo9hxv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uHloocTA, 0, m, &cDelay_uHloocTA_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7HZmQdfN, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_1sSo9hxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1sSo9hxv, m);
  cMsg_Kk4dqmcl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_7ZHAtT2G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_dUVwaCJD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_URePIkGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oLXPtbVB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_eDc8KrsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_72WZsJq0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uHloocTA, 2, m, &cDelay_uHloocTA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yq7Y21DY_sendMessage);
}

void Heavy_PhaseRing::cMsg_oLXPtbVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_eDc8KrsZ, 0, m, &hTable_eDc8KrsZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_LG3vVp6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_URePIkGN_sendMessage);
}

void Heavy_PhaseRing::cMsg_Kk4dqmcl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_eDc8KrsZ, 0, m, &hTable_eDc8KrsZ_sendMessage);
}

void Heavy_PhaseRing::cCast_yq7Y21DY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uHloocTA, 0, m, &cDelay_uHloocTA_sendMessage);
}

void Heavy_PhaseRing::cMsg_72WZsJq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_1sSo9hxv, 2, m, &cDelay_1sSo9hxv_sendMessage);
}

void Heavy_PhaseRing::cMsg_dUVwaCJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7HZmQdfN, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_U08NLIoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_75tWTASF, HV_BINOP_SUBTRACT, 0, m, &cBinop_75tWTASF_sendMessage);
}

void Heavy_PhaseRing::cMsg_8oMdrxDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JgZD7Agy_sendMessage);
}

void Heavy_PhaseRing::cSystem_JgZD7Agy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_K4SGG2AS_sendMessage);
}

void Heavy_PhaseRing::cVar_9LEXC4CG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CqTmHTvm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_CvX6UvW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CvX6UvW5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mAekHjvH, 0, m, &cDelay_mAekHjvH_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_pYPAozmb, 0, m, &sTabread_pYPAozmb_sendMessage);
}

void Heavy_PhaseRing::cDelay_mAekHjvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mAekHjvH, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_pYPAozmb, 0, m, &sTabread_pYPAozmb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mAekHjvH, 0, m, &cDelay_mAekHjvH_sendMessage);
}

void Heavy_PhaseRing::sTabread_pYPAozmb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_cWeFwL9x, HV_BINOP_SUBTRACT, 0, m, &cBinop_cWeFwL9x_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_UT9FC3gi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O5M7cENq, HV_BINOP_MAX, 0, m, &cBinop_O5M7cENq_sendMessage);
}

void Heavy_PhaseRing::cBinop_K4SGG2AS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UT9FC3gi, HV_BINOP_MULTIPLY, 0, m, &cBinop_UT9FC3gi_sendMessage);
}

void Heavy_PhaseRing::cBinop_75tWTASF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bW7Zkp4w_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_pYPAozmb, 0, m, &sTabread_pYPAozmb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TGwyXE59_sendMessage);
}

void Heavy_PhaseRing::cSystem_UsNBsm5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cWeFwL9x, HV_BINOP_SUBTRACT, 1, m, &cBinop_cWeFwL9x_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mAekHjvH, 2, m, &cDelay_mAekHjvH_sendMessage);
}

void Heavy_PhaseRing::cMsg_CqTmHTvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UsNBsm5t_sendMessage);
}

void Heavy_PhaseRing::cMsg_bW7Zkp4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CvX6UvW5, 0, m, &cDelay_CvX6UvW5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mAekHjvH, 0, m, &cDelay_mAekHjvH_sendMessage);
}

void Heavy_PhaseRing::cMsg_xEopCq12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_O5M7cENq, HV_BINOP_MAX, 1, m, &cBinop_O5M7cENq_sendMessage);
}

void Heavy_PhaseRing::cBinop_O5M7cENq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_75tWTASF, HV_BINOP_SUBTRACT, 1, m, &cBinop_75tWTASF_sendMessage);
}

void Heavy_PhaseRing::cCast_TGwyXE59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CvX6UvW5, 0, m, &cDelay_CvX6UvW5_sendMessage);
}

void Heavy_PhaseRing::cBinop_ELQ3CZCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CvX6UvW5, 2, m, &cDelay_CvX6UvW5_sendMessage);
}

void Heavy_PhaseRing::cBinop_cWeFwL9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ELQ3CZCe_sendMessage);
}

void Heavy_PhaseRing::cCast_2oLiQ7Tf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9LEXC4CG, 0, m, &cVar_9LEXC4CG_sendMessage);
  cMsg_8oMdrxDd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_U08NLIoz, 0, m, &cTabhead_U08NLIoz_sendMessage);
}

void Heavy_PhaseRing::cMsg_JUH7BNvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9UKr0kgc_sendMessage);
}

void Heavy_PhaseRing::cSystem_9UKr0kgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_us3dkvVp_sendMessage);
}

void Heavy_PhaseRing::cDelay_UjOnGLS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UjOnGLS1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vA08MII0, 0, m, &cDelay_vA08MII0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UjOnGLS1, 0, m, &cDelay_UjOnGLS1_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vCtUo5b0, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_vA08MII0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vA08MII0, m);
  cMsg_CMkb0ouK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_ot24EnXw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Jlrq3DcX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_7zqwqnN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RMxu9QD0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_nrttz5pW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kImItXAI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UjOnGLS1, 2, m, &cDelay_UjOnGLS1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XLyIGZ1A_sendMessage);
}

void Heavy_PhaseRing::cMsg_RMxu9QD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_nrttz5pW, 0, m, &hTable_nrttz5pW_sendMessage);
}

void Heavy_PhaseRing::cBinop_us3dkvVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_7zqwqnN7_sendMessage);
}

void Heavy_PhaseRing::cMsg_CMkb0ouK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_nrttz5pW, 0, m, &hTable_nrttz5pW_sendMessage);
}

void Heavy_PhaseRing::cCast_XLyIGZ1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UjOnGLS1, 0, m, &cDelay_UjOnGLS1_sendMessage);
}

void Heavy_PhaseRing::cMsg_kImItXAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vA08MII0, 2, m, &cDelay_vA08MII0_sendMessage);
}

void Heavy_PhaseRing::cMsg_Jlrq3DcX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vCtUo5b0, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_cTQu7TXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pFdDqbIX, 0, m, &cVar_pFdDqbIX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LfSsfqKi, 0, m, &cVar_LfSsfqKi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_myw2Dnre, 0, m, &cVar_myw2Dnre_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6H6YvLhW, 0, m, &cVar_6H6YvLhW_sendMessage);
}

void Heavy_PhaseRing::cVar_cIMUacQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_ylF9Bc7v_sendMessage);
}

void Heavy_PhaseRing::cPack_ZGM0XTa2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_jGXZkfC6, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_LfSsfqKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m9eKUUjV, HV_BINOP_MULTIPLY, 0, m, &cBinop_m9eKUUjV_sendMessage);
}

void Heavy_PhaseRing::cMsg_t8vDSasW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0aXJlXp8_sendMessage);
}

void Heavy_PhaseRing::cSystem_0aXJlXp8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ICJa6H5I_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_m9eKUUjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_QquOZMXF_sendMessage);
}

void Heavy_PhaseRing::cBinop_kY5gnXyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m9eKUUjV, HV_BINOP_MULTIPLY, 1, m, &cBinop_m9eKUUjV_sendMessage);
}

void Heavy_PhaseRing::cMsg_ICJa6H5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kY5gnXyX_sendMessage);
}

void Heavy_PhaseRing::cBinop_QquOZMXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xz8dPqgY_sendMessage);
}

void Heavy_PhaseRing::cBinop_xz8dPqgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FopepZPZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NKe9y2xE, m);
}

void Heavy_PhaseRing::cBinop_FopepZPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jWQfRG73, m);
}

void Heavy_PhaseRing::cVar_myw2Dnre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i6JZ0omC, HV_BINOP_MULTIPLY, 0, m, &cBinop_i6JZ0omC_sendMessage);
}

void Heavy_PhaseRing::cMsg_KEmnSRIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Na4E8ugL_sendMessage);
}

void Heavy_PhaseRing::cSystem_Na4E8ugL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JUyb2Nhq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_i6JZ0omC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IGgoi1Xh_sendMessage);
}

void Heavy_PhaseRing::cBinop_GiKbkkLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i6JZ0omC, HV_BINOP_MULTIPLY, 1, m, &cBinop_i6JZ0omC_sendMessage);
}

void Heavy_PhaseRing::cMsg_JUyb2Nhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_GiKbkkLH_sendMessage);
}

void Heavy_PhaseRing::cBinop_IGgoi1Xh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZpB3UZjt_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZpB3UZjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Wyv070cc_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Rs3LFxpv, m);
}

void Heavy_PhaseRing::cBinop_Wyv070cc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ipZ7hH4B, m);
}

void Heavy_PhaseRing::cVar_6H6YvLhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WyCMgGDM, HV_BINOP_MULTIPLY, 0, m, &cBinop_WyCMgGDM_sendMessage);
}

void Heavy_PhaseRing::cMsg_Gw6ZERkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UbHz8mJO_sendMessage);
}

void Heavy_PhaseRing::cSystem_UbHz8mJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Cd5vjdqj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_WyCMgGDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_PXWI53KP_sendMessage);
}

void Heavy_PhaseRing::cBinop_EgFexOGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WyCMgGDM, HV_BINOP_MULTIPLY, 1, m, &cBinop_WyCMgGDM_sendMessage);
}

void Heavy_PhaseRing::cMsg_Cd5vjdqj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_EgFexOGf_sendMessage);
}

void Heavy_PhaseRing::cBinop_PXWI53KP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tOdHav1A_sendMessage);
}

void Heavy_PhaseRing::cBinop_tOdHav1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_x9zDpqpf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JOAX3PId, m);
}

void Heavy_PhaseRing::cBinop_x9zDpqpf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JsdKSllh, m);
}

void Heavy_PhaseRing::cBinop_AsbSFopY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ROrUWDcm, 0, m, &cPack_ROrUWDcm_sendMessage);
}

void Heavy_PhaseRing::cMsg_MEu59cpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_cTQu7TXa, 0, m, &cVar_cTQu7TXa_sendMessage);
}

void Heavy_PhaseRing::cBinop_ylF9Bc7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ZGM0XTa2, 0, m, &cPack_ZGM0XTa2_sendMessage);
}

void Heavy_PhaseRing::cBinop_WqQkUkFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oYibzZju, 0, m, &cPack_oYibzZju_sendMessage);
}

void Heavy_PhaseRing::cMsg_NjeHkEFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_p6OclFD6_sendMessage);
}

void Heavy_PhaseRing::cSystem_p6OclFD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6pbH36Nx_sendMessage);
}

void Heavy_PhaseRing::cVar_luFtk7S7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a2vu5eZL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_huEfVaYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XaJOasgs_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_96PjJZmS, m);
}

void Heavy_PhaseRing::cBinop_6pbH36Nx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pF2wFGwx, m);
}

void Heavy_PhaseRing::cMsg_a2vu5eZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_huEfVaYi_sendMessage);
}

void Heavy_PhaseRing::cBinop_XaJOasgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GJVSvaYt, m);
}

void Heavy_PhaseRing::cVar_mJFYSDIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SjmJnjGD, HV_BINOP_MULTIPLY, 0, m, &cBinop_SjmJnjGD_sendMessage);
}

void Heavy_PhaseRing::cMsg_lcdZcMDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VTbkw7kk_sendMessage);
}

void Heavy_PhaseRing::cSystem_VTbkw7kk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lPlgD9YK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_SjmJnjGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_yaA46avC_sendMessage);
}

void Heavy_PhaseRing::cBinop_FrPSQRUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SjmJnjGD, HV_BINOP_MULTIPLY, 1, m, &cBinop_SjmJnjGD_sendMessage);
}

void Heavy_PhaseRing::cMsg_lPlgD9YK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_FrPSQRUL_sendMessage);
}

void Heavy_PhaseRing::cBinop_yaA46avC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_T2j0VYpT_sendMessage);
}

void Heavy_PhaseRing::cBinop_T2j0VYpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_P15aTh8u_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_DiER5g1K, m);
}

void Heavy_PhaseRing::cBinop_P15aTh8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8iBRt9CU, m);
}

void Heavy_PhaseRing::cBinop_2meIBOec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_rgaTLIdw_sendMessage);
}

void Heavy_PhaseRing::cBinop_rgaTLIdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_H4vyfMuo, m);
}

void Heavy_PhaseRing::cBinop_MynHKcqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Jjm2nthv_sendMessage);
}

void Heavy_PhaseRing::cBinop_Jjm2nthv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_7dzHFEq9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_u7w23OH5_sendMessage);
}

void Heavy_PhaseRing::cVar_VOeYVCJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_wVXSp7zg_sendMessage);
}

void Heavy_PhaseRing::cMsg_Dsu7WDLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Tcc5fTZL_sendMessage);
}

void Heavy_PhaseRing::cSystem_Tcc5fTZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h1Eivxwc, HV_BINOP_DIVIDE, 1, m, &cBinop_h1Eivxwc_sendMessage);
}

void Heavy_PhaseRing::cBinop_7dzHFEq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_x6Gt2Cnz_sendMessage);
}

void Heavy_PhaseRing::cBinop_x6Gt2Cnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SJ9BFOT1, m);
}

void Heavy_PhaseRing::cMsg_ToS1S5so_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_xEnXvN79_sendMessage);
}

void Heavy_PhaseRing::cBinop_xEnXvN79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MynHKcqh_sendMessage);
}

void Heavy_PhaseRing::cBinop_u7w23OH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_blGeibxy, m);
}

void Heavy_PhaseRing::cBinop_wVXSp7zg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_7Pk76oSR_sendMessage);
}

void Heavy_PhaseRing::cBinop_7Pk76oSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h1Eivxwc, HV_BINOP_DIVIDE, 0, m, &cBinop_h1Eivxwc_sendMessage);
}

void Heavy_PhaseRing::cBinop_h1Eivxwc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ToS1S5so_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_WAvBIGqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Xobgr61w_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_3z0QEWVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mKZotypk_sendMessage);
}

void Heavy_PhaseRing::cSystem_mKZotypk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NETN36gQ_sendMessage);
}

void Heavy_PhaseRing::cDelay_VxielVub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VxielVub, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pTfJAkaO, 0, m, &cDelay_pTfJAkaO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VxielVub, 0, m, &cDelay_VxielVub_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_38MffpdR, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_pTfJAkaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pTfJAkaO, m);
  cMsg_9h09t3kl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_9maVjeRN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_0BABc8xs_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_SJRCIgOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XevAJvTm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_hD8vCwux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QsR8CoXr_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VxielVub, 2, m, &cDelay_VxielVub_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_chgvTqWT_sendMessage);
}

void Heavy_PhaseRing::cMsg_XevAJvTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_hD8vCwux, 0, m, &hTable_hD8vCwux_sendMessage);
}

void Heavy_PhaseRing::cBinop_NETN36gQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_SJRCIgOW_sendMessage);
}

void Heavy_PhaseRing::cMsg_9h09t3kl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_hD8vCwux, 0, m, &hTable_hD8vCwux_sendMessage);
}

void Heavy_PhaseRing::cCast_chgvTqWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VxielVub, 0, m, &cDelay_VxielVub_sendMessage);
}

void Heavy_PhaseRing::cMsg_QsR8CoXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_pTfJAkaO, 2, m, &cDelay_pTfJAkaO_sendMessage);
}

void Heavy_PhaseRing::cMsg_0BABc8xs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_38MffpdR, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_MmAnhAM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_Xobgr61w_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Xobgr61w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_HdZ8RftR, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_6eySD7Ik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Uybn0hAd, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_34DcPMUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_v15QyOrN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_DlfCw5G7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6eySD7Ik, 0, m, &cPack_6eySD7Ik_sendMessage);
}

void Heavy_PhaseRing::cMsg_cn1pUKGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Uybn0hAd, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_jF8fobtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LEghi2TG, m);
}

void Heavy_PhaseRing::cMsg_9899CIUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2meIBOec_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_3adeEcX3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5z8Nlcy1, 0, m, &cSlice_5z8Nlcy1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pBFB6yRj, 0, m, &cRandom_pBFB6yRj_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_lPqxVuu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KkVU1EYB_sendMessage);
}

void Heavy_PhaseRing::cUnop_KkVU1EYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_YT8eCrys_sendMessage);
}

void Heavy_PhaseRing::cRandom_pBFB6yRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_lPqxVuu6_sendMessage);
}

void Heavy_PhaseRing::cSlice_5z8Nlcy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pBFB6yRj, 1, m, &cRandom_pBFB6yRj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_mJVCHi1D_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jmZ8Ebhm, 0, m, &cSlice_jmZ8Ebhm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qfLY97rt, 0, m, &cRandom_qfLY97rt_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_FcRlEETZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GZ54a30b_sendMessage);
}

void Heavy_PhaseRing::cUnop_GZ54a30b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XpkEdFcK, 0, m, &cPack_XpkEdFcK_sendMessage);
}

void Heavy_PhaseRing::cRandom_qfLY97rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_FcRlEETZ_sendMessage);
}

void Heavy_PhaseRing::cSlice_jmZ8Ebhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qfLY97rt, 1, m, &cRandom_qfLY97rt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_bEwczvOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ej6hfgGs_sendMessage);
}

void Heavy_PhaseRing::cPack_f2C6RCcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lPV7LxmL, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_4EmKHD5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ViOLes27_sendMessage);
}

void Heavy_PhaseRing::cBinop_H9k4foMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_4EmKHD5f_sendMessage);
}

void Heavy_PhaseRing::cPack_y8UlqmNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_7sgXNfJA, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_NATijDg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_QAWFkskD_sendMessage);
}

void Heavy_PhaseRing::cMsg_2GxJDtYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3qQvp6rz_sendMessage);
}

void Heavy_PhaseRing::cSystem_3qQvp6rz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FifUGUDr_sendMessage);
}

void Heavy_PhaseRing::cDelay_1upx28Gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1upx28Gm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NWQX60N7, 0, m, &cDelay_NWQX60N7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1upx28Gm, 0, m, &cDelay_1upx28Gm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bO6asmit, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_NWQX60N7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NWQX60N7, m);
  cMsg_AbdWVnng_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_YBlrqius_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3an6CDot_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_kGLO8HCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yhNRiwGg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_AfeJHjAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zb4XQWgz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1upx28Gm, 2, m, &cDelay_1upx28Gm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FkDp1EsY_sendMessage);
}

void Heavy_PhaseRing::cMsg_yhNRiwGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_AfeJHjAC, 0, m, &hTable_AfeJHjAC_sendMessage);
}

void Heavy_PhaseRing::cBinop_FifUGUDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_kGLO8HCe_sendMessage);
}

void Heavy_PhaseRing::cMsg_AbdWVnng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_AfeJHjAC, 0, m, &hTable_AfeJHjAC_sendMessage);
}

void Heavy_PhaseRing::cCast_FkDp1EsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1upx28Gm, 0, m, &cDelay_1upx28Gm_sendMessage);
}

void Heavy_PhaseRing::cMsg_zb4XQWgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_NWQX60N7, 2, m, &cDelay_NWQX60N7_sendMessage);
}

void Heavy_PhaseRing::cMsg_3an6CDot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bO6asmit, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_rojwloF1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JKX4npDA_sendMessage);
}

void Heavy_PhaseRing::cSystem_JKX4npDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QJW6LmGR_sendMessage);
}

void Heavy_PhaseRing::cVar_fFLErozG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7cgbb1wA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_W1L0YnJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_cLIa38Mh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LQt8CfLM, m);
}

void Heavy_PhaseRing::cBinop_QJW6LmGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_by1vll3K, m);
}

void Heavy_PhaseRing::cMsg_7cgbb1wA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W1L0YnJo_sendMessage);
}

void Heavy_PhaseRing::cBinop_cLIa38Mh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RtOlYvmY, m);
}

void Heavy_PhaseRing::cMsg_aDZCjSaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5NASOrdc_sendMessage);
}

void Heavy_PhaseRing::cSystem_5NASOrdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8cXKQh2L_sendMessage);
}

void Heavy_PhaseRing::cVar_No3ef98I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gGjbY0xA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_RwVRfoB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zyASn8kj_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7AraMLj0, m);
}

void Heavy_PhaseRing::cBinop_8cXKQh2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PzrJFW3F, m);
}

void Heavy_PhaseRing::cMsg_gGjbY0xA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RwVRfoB2_sendMessage);
}

void Heavy_PhaseRing::cBinop_zyASn8kj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eqaZ4nfi, m);
}

void Heavy_PhaseRing::cBinop_yGJd6fdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ngm81sLl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_ev7vzRho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_W6xonYBs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A105E6Ge_sendMessage);
}

void Heavy_PhaseRing::cCast_W6xonYBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yGJd6fdu, HV_BINOP_DIVIDE, 1, m, &cBinop_yGJd6fdu_sendMessage);
}

void Heavy_PhaseRing::cCast_A105E6Ge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yGJd6fdu, HV_BINOP_DIVIDE, 0, m, &cBinop_yGJd6fdu_sendMessage);
}

void Heavy_PhaseRing::cBinop_ViOLes27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sifVohnX_sendMessage);
}

void Heavy_PhaseRing::cBinop_LZDqAikt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_H9k4foMy_sendMessage);
}

void Heavy_PhaseRing::cBinop_sifVohnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yGJd6fdu, HV_BINOP_DIVIDE, 0, m, &cBinop_yGJd6fdu_sendMessage);
}

void Heavy_PhaseRing::cBinop_QAWFkskD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_y8UlqmNX, 0, m, &cPack_y8UlqmNX_sendMessage);
}

void Heavy_PhaseRing::cBinop_ej6hfgGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_ev7vzRho_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_f2C6RCcF, 0, m, &cPack_f2C6RCcF_sendMessage);
}

void Heavy_PhaseRing::cMsg_CcoNh8es_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_bEwczvOg, 0, m, &cVar_bEwczvOg_sendMessage);
}

void Heavy_PhaseRing::cMsg_fXX4bFdE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_NATijDg4, 0, m, &cVar_NATijDg4_sendMessage);
}

void Heavy_PhaseRing::cMsg_ngm81sLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_p05MInlQ, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_sA6cHLQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DvDXRjcY_sendMessage);
}

void Heavy_PhaseRing::cSystem_DvDXRjcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LPtmbH1h_sendMessage);
}

void Heavy_PhaseRing::cVar_Q06SCMde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tjzBxlcE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_ciVRl6fF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HOfGqXbl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_27qYBP8n, m);
}

void Heavy_PhaseRing::cBinop_LPtmbH1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AGSmbZFU, m);
}

void Heavy_PhaseRing::cMsg_tjzBxlcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ciVRl6fF_sendMessage);
}

void Heavy_PhaseRing::cBinop_HOfGqXbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5b1lNuYl, m);
}

void Heavy_PhaseRing::cVar_bUGY8CSu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MFQLXG4W, HV_BINOP_MULTIPLY, 0, m, &cBinop_MFQLXG4W_sendMessage);
}

void Heavy_PhaseRing::cMsg_UHbO3lRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_erH0zvCX_sendMessage);
}

void Heavy_PhaseRing::cSystem_erH0zvCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z3DXKRHb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_MFQLXG4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LIss93Dd_sendMessage);
}

void Heavy_PhaseRing::cBinop_Bc3BIhAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MFQLXG4W, HV_BINOP_MULTIPLY, 1, m, &cBinop_MFQLXG4W_sendMessage);
}

void Heavy_PhaseRing::cMsg_z3DXKRHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Bc3BIhAG_sendMessage);
}

void Heavy_PhaseRing::cBinop_LIss93Dd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_vFxftStw_sendMessage);
}

void Heavy_PhaseRing::cBinop_vFxftStw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qvyQY6yV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uR73kTj8, m);
}

void Heavy_PhaseRing::cBinop_qvyQY6yV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XLsvwfIe, m);
}

void Heavy_PhaseRing::cBinop_XIX629sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_DVMKHljt_sendMessage);
}

void Heavy_PhaseRing::cBinop_DVMKHljt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZaU6HlVU, m);
}

void Heavy_PhaseRing::cBinop_jkofRUV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7uXo0vMf_sendMessage);
}

void Heavy_PhaseRing::cBinop_7uXo0vMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_mLQKTXMJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7Bnx1RMR_sendMessage);
}

void Heavy_PhaseRing::cVar_fTot3fFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_WZO87XJB_sendMessage);
}

void Heavy_PhaseRing::cMsg_1CcIUJOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8L0UCKwX_sendMessage);
}

void Heavy_PhaseRing::cSystem_8L0UCKwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f4VdivFj, HV_BINOP_DIVIDE, 1, m, &cBinop_f4VdivFj_sendMessage);
}

void Heavy_PhaseRing::cBinop_mLQKTXMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_polnWyVY_sendMessage);
}

void Heavy_PhaseRing::cBinop_polnWyVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dfZLNOUp, m);
}

void Heavy_PhaseRing::cMsg_4JlDeobk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_GR7y0XoG_sendMessage);
}

void Heavy_PhaseRing::cBinop_GR7y0XoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jkofRUV5_sendMessage);
}

void Heavy_PhaseRing::cBinop_7Bnx1RMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_O3irMjca, m);
}

void Heavy_PhaseRing::cBinop_WZO87XJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Ual15OCU_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ual15OCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f4VdivFj, HV_BINOP_DIVIDE, 0, m, &cBinop_f4VdivFj_sendMessage);
}

void Heavy_PhaseRing::cBinop_f4VdivFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4JlDeobk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_mLzLidEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LP1JkKuJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_q0o1CWJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cYPtE6jH_sendMessage);
}

void Heavy_PhaseRing::cSystem_cYPtE6jH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sqP1IVDb_sendMessage);
}

void Heavy_PhaseRing::cDelay_M1Ej8jys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M1Ej8jys, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eCgU0hFE, 0, m, &cDelay_eCgU0hFE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M1Ej8jys, 0, m, &cDelay_M1Ej8jys_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6Pfb0x1G, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_eCgU0hFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eCgU0hFE, m);
  cMsg_r8nFhFzx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_RGwSFgyZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Fw7LKoQn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_BFdQdJzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p3pFA8p4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_7NDdVPeG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bH1GyKtR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M1Ej8jys, 2, m, &cDelay_M1Ej8jys_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tkAsnoH4_sendMessage);
}

void Heavy_PhaseRing::cMsg_p3pFA8p4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7NDdVPeG, 0, m, &hTable_7NDdVPeG_sendMessage);
}

void Heavy_PhaseRing::cBinop_sqP1IVDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_BFdQdJzv_sendMessage);
}

void Heavy_PhaseRing::cMsg_r8nFhFzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7NDdVPeG, 0, m, &hTable_7NDdVPeG_sendMessage);
}

void Heavy_PhaseRing::cCast_tkAsnoH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_M1Ej8jys, 0, m, &cDelay_M1Ej8jys_sendMessage);
}

void Heavy_PhaseRing::cMsg_bH1GyKtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_eCgU0hFE, 2, m, &cDelay_eCgU0hFE_sendMessage);
}

void Heavy_PhaseRing::cMsg_Fw7LKoQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6Pfb0x1G, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_ZfbQPvZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_LP1JkKuJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_LP1JkKuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3juLZgyV, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_Dk9ac1eE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_5ZnovGdn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_S4g868Ws_sendMessage);
}

void Heavy_PhaseRing::cSystem_S4g868Ws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t84jhfg6, HV_BINOP_MULTIPLY, 1, m, &cBinop_t84jhfg6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_v0mWRMwg, HV_BINOP_MULTIPLY, 1, m, &cBinop_v0mWRMwg_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_ZKSyWZjf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_jTKQUZO9_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_jTKQUZO9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VOe11Ycc_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_htVbaWgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_htVbaWgg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_htVbaWgg, 0, m, &cDelay_htVbaWgg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_w4ZZ3CoS, 0, m, &cVar_w4ZZ3CoS_sendMessage);
}

void Heavy_PhaseRing::cCast_VOe11Ycc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jTKQUZO9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_htVbaWgg, 0, m, &cDelay_htVbaWgg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_w4ZZ3CoS, 0, m, &cVar_w4ZZ3CoS_sendMessage);
}

void Heavy_PhaseRing::cMsg_0lV5azls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZE39HZjH_sendMessage);
}

void Heavy_PhaseRing::cSystem_ZE39HZjH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3Duf6xdW_sendMessage);
}

void Heavy_PhaseRing::cVar_NLRDvdDt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rrEaphQj, HV_BINOP_MULTIPLY, 0, m, &cBinop_rrEaphQj_sendMessage);
}

void Heavy_PhaseRing::cMsg_jTKQUZO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_htVbaWgg, 0, m, &cDelay_htVbaWgg_sendMessage);
}

void Heavy_PhaseRing::cBinop_gR8ul4iH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_htVbaWgg, 2, m, &cDelay_htVbaWgg_sendMessage);
}

void Heavy_PhaseRing::cBinop_3Duf6xdW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rrEaphQj, HV_BINOP_MULTIPLY, 1, m, &cBinop_rrEaphQj_sendMessage);
}

void Heavy_PhaseRing::cBinop_rrEaphQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_gR8ul4iH_sendMessage);
}

void Heavy_PhaseRing::cVar_w4ZZ3CoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eCtL9KgD, HV_BINOP_SUBTRACT, 0, m, &cBinop_eCtL9KgD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_cYtPwtrr_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_ONDCPYmD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W29vGiAH_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3AKC2LPc_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_W29vGiAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rFITZeXO, 0, m, &cVar_rFITZeXO_sendMessage);
}

void Heavy_PhaseRing::cCast_3AKC2LPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zn48jMqc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dYiulGDj_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_ykao3HV8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jId1gJHL, 0, m, &cSlice_jId1gJHL_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1Q7wlTbK, 0, m, &cSlice_1Q7wlTbK_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tzejvtl4_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sPxB0mKC, 0, m, &cSlice_sPxB0mKC_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_C8yJpD2a, 0, m, &cSlice_C8yJpD2a_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Yb4sKWMP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wdeWMxHQ_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_jId1gJHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_PEuNncZE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_PEuNncZE_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_1Q7wlTbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_siHRoVum_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vsYNa5tW_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_siHRoVum_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vsYNa5tW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_kjC99cs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EoI2EHvg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_T46AbCc1_sendMessage);
}

void Heavy_PhaseRing::cVar_Lrw3Ayun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zQK8yY2u_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_zQK8yY2u_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9rZ76Af2_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_t84jhfg6, HV_BINOP_MULTIPLY, 0, m, &cBinop_t84jhfg6_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_tOyMqrjw, HV_BINOP_DIVIDE, 1, m, &cBinop_tOyMqrjw_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_NLRDvdDt, 0, m, &cVar_NLRDvdDt_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_9rZ76Af2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MCqUgdV9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_URxMdMVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wXCszMHG, HV_BINOP_SUBTRACT, 1, m, &cBinop_wXCszMHG_sendMessage);
}

void Heavy_PhaseRing::cVar_sZ68RCdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rFITZeXO, 0, m, &cVar_rFITZeXO_sendMessage);
}

void Heavy_PhaseRing::cVar_rFITZeXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qTonpsYO, HV_BINOP_ADD, 0, m, &cBinop_qTonpsYO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PjliQphW, HV_BINOP_ADD, 0, m, &cBinop_PjliQphW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_haBknosn, 0, m, &cVar_haBknosn_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_LZDqAikt_sendMessage);
}

void Heavy_PhaseRing::cSlice_sPxB0mKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EoI2EHvg_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_T46AbCc1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_C8yJpD2a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4hp5XT1m_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ulleZ9qF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_NPU6dE4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_w4ZZ3CoS, 1, m, &cVar_w4ZZ3CoS_sendMessage);
}

void Heavy_PhaseRing::cBinop_v0mWRMwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NPU6dE4I_sendMessage);
}

void Heavy_PhaseRing::cBinop_t84jhfg6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ExyPUU7j_sendMessage);
}

void Heavy_PhaseRing::cBinop_ExyPUU7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eCtL9KgD, HV_BINOP_SUBTRACT, 1, m, &cBinop_eCtL9KgD_sendMessage);
}

void Heavy_PhaseRing::cBinop_eCtL9KgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_w4ZZ3CoS, 1, m, &cVar_w4ZZ3CoS_sendMessage);
}

void Heavy_PhaseRing::cMsg_ykRHMrO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_ZKSyWZjf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_oG0I6RHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_ZKSyWZjf_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PjliQphW, HV_BINOP_ADD, 1, m, &cBinop_PjliQphW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qTonpsYO, HV_BINOP_ADD, 1, m, &cBinop_qTonpsYO_sendMessage);
}

void Heavy_PhaseRing::cBinop_cYtPwtrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ONDCPYmD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_qTonpsYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rFITZeXO, 1, m, &cVar_rFITZeXO_sendMessage);
}

void Heavy_PhaseRing::cBinop_tOyMqrjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gbzC9vKI, HV_BINOP_DIVIDE, 1, m, &cBinop_gbzC9vKI_sendMessage);
}

void Heavy_PhaseRing::cBinop_gbzC9vKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PjliQphW, HV_BINOP_ADD, 1, m, &cBinop_PjliQphW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qTonpsYO, HV_BINOP_ADD, 1, m, &cBinop_qTonpsYO_sendMessage);
}

void Heavy_PhaseRing::cCast_T46AbCc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tOyMqrjw, HV_BINOP_DIVIDE, 0, m, &cBinop_tOyMqrjw_sendMessage);
}

void Heavy_PhaseRing::cCast_EoI2EHvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v0mWRMwg, HV_BINOP_MULTIPLY, 0, m, &cBinop_v0mWRMwg_sendMessage);
}

void Heavy_PhaseRing::cCast_4hp5XT1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sZ68RCdu, 1, m, &cVar_sZ68RCdu_sendMessage);
}

void Heavy_PhaseRing::cCast_ulleZ9qF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wXCszMHG, HV_BINOP_SUBTRACT, 0, m, &cBinop_wXCszMHG_sendMessage);
}

void Heavy_PhaseRing::cCast_dYiulGDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sZ68RCdu, 0, m, &cVar_sZ68RCdu_sendMessage);
}

void Heavy_PhaseRing::cCast_zn48jMqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oG0I6RHa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_PjliQphW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_URxMdMVG, 0, m, &cVar_URxMdMVG_sendMessage);
}

void Heavy_PhaseRing::cMsg_PEuNncZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_ZKSyWZjf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_wgvrSlHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kjC99cs3, 1, m, &cVar_kjC99cs3_sendMessage);
}

void Heavy_PhaseRing::cMsg_MCqUgdV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_t84jhfg6, HV_BINOP_MULTIPLY, 0, m, &cBinop_t84jhfg6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tOyMqrjw, HV_BINOP_DIVIDE, 1, m, &cBinop_tOyMqrjw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NLRDvdDt, 0, m, &cVar_NLRDvdDt_sendMessage);
}

void Heavy_PhaseRing::cCast_vsYNa5tW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tPJS6Yxp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PjliQphW, HV_BINOP_ADD, 0, m, &cBinop_PjliQphW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rFITZeXO, 1, m, &cVar_rFITZeXO_sendMessage);
}

void Heavy_PhaseRing::cCast_siHRoVum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PEuNncZE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_wXCszMHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gbzC9vKI, HV_BINOP_DIVIDE, 0, m, &cBinop_gbzC9vKI_sendMessage);
}

void Heavy_PhaseRing::cCast_tPJS6Yxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oG0I6RHa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_wdeWMxHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wgvrSlHA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_tzejvtl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kjC99cs3, 0, m, &cVar_kjC99cs3_sendMessage);
}

void Heavy_PhaseRing::cCast_Yb4sKWMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ykRHMrO7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_haBknosn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_E6bG38Mp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mF3pHvFB_sendMessage);
}

void Heavy_PhaseRing::cSystem_mF3pHvFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pz5YD5wS, HV_BINOP_MULTIPLY, 1, m, &cBinop_pz5YD5wS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WcZ6MSww, HV_BINOP_MULTIPLY, 1, m, &cBinop_WcZ6MSww_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_bnz3UzP2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_kFTlRUt5_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_kFTlRUt5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TvkMx5Yq_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_rygFSngc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rygFSngc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rygFSngc, 0, m, &cDelay_rygFSngc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eWvy9Q1s, 0, m, &cVar_eWvy9Q1s_sendMessage);
}

void Heavy_PhaseRing::cCast_TvkMx5Yq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kFTlRUt5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rygFSngc, 0, m, &cDelay_rygFSngc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eWvy9Q1s, 0, m, &cVar_eWvy9Q1s_sendMessage);
}

void Heavy_PhaseRing::cMsg_sUOE0z1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_twBaRZrO_sendMessage);
}

void Heavy_PhaseRing::cSystem_twBaRZrO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2D1Rfcd1_sendMessage);
}

void Heavy_PhaseRing::cVar_xVjvCi5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EFe6WgBx, HV_BINOP_MULTIPLY, 0, m, &cBinop_EFe6WgBx_sendMessage);
}

void Heavy_PhaseRing::cMsg_kFTlRUt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rygFSngc, 0, m, &cDelay_rygFSngc_sendMessage);
}

void Heavy_PhaseRing::cBinop_iy0qCHgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rygFSngc, 2, m, &cDelay_rygFSngc_sendMessage);
}

void Heavy_PhaseRing::cBinop_2D1Rfcd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EFe6WgBx, HV_BINOP_MULTIPLY, 1, m, &cBinop_EFe6WgBx_sendMessage);
}

void Heavy_PhaseRing::cBinop_EFe6WgBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_iy0qCHgb_sendMessage);
}

void Heavy_PhaseRing::cVar_eWvy9Q1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UNfvuQDt, HV_BINOP_SUBTRACT, 0, m, &cBinop_UNfvuQDt_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_PFhPLmSh_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_C5T00dbZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xUC7jkaD_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AyiM3bGL_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_xUC7jkaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lsMnydcQ, 0, m, &cVar_lsMnydcQ_sendMessage);
}

void Heavy_PhaseRing::cCast_AyiM3bGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4bcUsBQS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9tSSE477_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_1ldat1Sx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iuuLXMGP, 0, m, &cSlice_iuuLXMGP_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5LWBeD5J, 0, m, &cSlice_5LWBeD5J_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_znvHthJQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_t802OmXg, 0, m, &cSlice_t802OmXg_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_LBExNF64, 0, m, &cSlice_LBExNF64_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ig9ApbOz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2dFTN82I_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_iuuLXMGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_U0j0K123_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_U0j0K123_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_5LWBeD5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kV8DiCA5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U3PWx3ht_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kV8DiCA5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U3PWx3ht_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_oCsnNbis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0DHil20u_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_prm67PBH_sendMessage);
}

void Heavy_PhaseRing::cVar_1OURFzj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8aT54DOb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_8aT54DOb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hncjy6py_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pz5YD5wS, HV_BINOP_MULTIPLY, 0, m, &cBinop_pz5YD5wS_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_1Emj0Os4, HV_BINOP_DIVIDE, 1, m, &cBinop_1Emj0Os4_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_xVjvCi5o, 0, m, &cVar_xVjvCi5o_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_Hncjy6py_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W4cIbGOY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_SRH2aXPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ANHRDZ4N, HV_BINOP_SUBTRACT, 1, m, &cBinop_ANHRDZ4N_sendMessage);
}

void Heavy_PhaseRing::cVar_Aj5dyiA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lsMnydcQ, 0, m, &cVar_lsMnydcQ_sendMessage);
}

void Heavy_PhaseRing::cVar_lsMnydcQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8YejB9WL, HV_BINOP_ADD, 0, m, &cBinop_8YejB9WL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oaxbi6B6, HV_BINOP_ADD, 0, m, &cBinop_oaxbi6B6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Dk9ac1eE, 0, m, &cVar_Dk9ac1eE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cTNm0UNL, m);
}

void Heavy_PhaseRing::cSlice_t802OmXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0DHil20u_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_prm67PBH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_LBExNF64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_n9FEAXgM_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_goiK6Yjw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Nm73OqAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eWvy9Q1s, 1, m, &cVar_eWvy9Q1s_sendMessage);
}

void Heavy_PhaseRing::cBinop_WcZ6MSww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Nm73OqAs_sendMessage);
}

void Heavy_PhaseRing::cBinop_pz5YD5wS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7B8iGcJu_sendMessage);
}

void Heavy_PhaseRing::cBinop_7B8iGcJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UNfvuQDt, HV_BINOP_SUBTRACT, 1, m, &cBinop_UNfvuQDt_sendMessage);
}

void Heavy_PhaseRing::cBinop_UNfvuQDt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eWvy9Q1s, 1, m, &cVar_eWvy9Q1s_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZnvlPFIF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_bnz3UzP2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_AVkeHJTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_bnz3UzP2_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oaxbi6B6, HV_BINOP_ADD, 1, m, &cBinop_oaxbi6B6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8YejB9WL, HV_BINOP_ADD, 1, m, &cBinop_8YejB9WL_sendMessage);
}

void Heavy_PhaseRing::cBinop_PFhPLmSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_C5T00dbZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_8YejB9WL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lsMnydcQ, 1, m, &cVar_lsMnydcQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_1Emj0Os4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JKbBa80r, HV_BINOP_DIVIDE, 1, m, &cBinop_JKbBa80r_sendMessage);
}

void Heavy_PhaseRing::cBinop_JKbBa80r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oaxbi6B6, HV_BINOP_ADD, 1, m, &cBinop_oaxbi6B6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8YejB9WL, HV_BINOP_ADD, 1, m, &cBinop_8YejB9WL_sendMessage);
}

void Heavy_PhaseRing::cCast_prm67PBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1Emj0Os4, HV_BINOP_DIVIDE, 0, m, &cBinop_1Emj0Os4_sendMessage);
}

void Heavy_PhaseRing::cCast_0DHil20u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WcZ6MSww, HV_BINOP_MULTIPLY, 0, m, &cBinop_WcZ6MSww_sendMessage);
}

void Heavy_PhaseRing::cCast_goiK6Yjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ANHRDZ4N, HV_BINOP_SUBTRACT, 0, m, &cBinop_ANHRDZ4N_sendMessage);
}

void Heavy_PhaseRing::cCast_n9FEAXgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Aj5dyiA4, 1, m, &cVar_Aj5dyiA4_sendMessage);
}

void Heavy_PhaseRing::cCast_9tSSE477_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Aj5dyiA4, 0, m, &cVar_Aj5dyiA4_sendMessage);
}

void Heavy_PhaseRing::cCast_4bcUsBQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AVkeHJTT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_oaxbi6B6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SRH2aXPr, 0, m, &cVar_SRH2aXPr_sendMessage);
}

void Heavy_PhaseRing::cMsg_U0j0K123_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_bnz3UzP2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_vQXJFakw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_oCsnNbis, 1, m, &cVar_oCsnNbis_sendMessage);
}

void Heavy_PhaseRing::cMsg_W4cIbGOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pz5YD5wS, HV_BINOP_MULTIPLY, 0, m, &cBinop_pz5YD5wS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1Emj0Os4, HV_BINOP_DIVIDE, 1, m, &cBinop_1Emj0Os4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xVjvCi5o, 0, m, &cVar_xVjvCi5o_sendMessage);
}

void Heavy_PhaseRing::cCast_U3PWx3ht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n9NepIgc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oaxbi6B6, HV_BINOP_ADD, 0, m, &cBinop_oaxbi6B6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lsMnydcQ, 1, m, &cVar_lsMnydcQ_sendMessage);
}

void Heavy_PhaseRing::cCast_kV8DiCA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U0j0K123_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_ANHRDZ4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JKbBa80r, HV_BINOP_DIVIDE, 0, m, &cBinop_JKbBa80r_sendMessage);
}

void Heavy_PhaseRing::cCast_n9NepIgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AVkeHJTT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_2dFTN82I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vQXJFakw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_Ig9ApbOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZnvlPFIF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_znvHthJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oCsnNbis, 0, m, &cVar_oCsnNbis_sendMessage);
}

void Heavy_PhaseRing::cPack_ZhvVIc8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VTWbQbgJ, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_VDhFOKH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ykao3HV8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_XpkEdFcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1ldat1Sx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_QB5FqhwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_0xF7eWkU_sendMessage);
}

void Heavy_PhaseRing::cBinop_0xF7eWkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_VDhFOKH2, 0, m, &cPack_VDhFOKH2_sendMessage);
}

void Heavy_PhaseRing::cBinop_YT8eCrys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QB5FqhwG_sendMessage);
}

void Heavy_PhaseRing::cCast_fA50HyJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mJVCHi1D_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_5U89dJIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3adeEcX3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_9Rhep0yK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_XIX629sk_sendMessage);
}

void Heavy_PhaseRing::cVar_RPybZG23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y5vuTL2O_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EAFI4Rsr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qXeojbTz_sendMessage);
}

void Heavy_PhaseRing::cIf_1CqJK5oW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_UYu3o7lC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_XE3k3FJw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_kqUUAkO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBj5eBiZ, HV_BINOP_POW, 0, m, &cBinop_yBj5eBiZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_yBj5eBiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RYZ5ufup, 0, m, &cPack_RYZ5ufup_sendMessage);
}

void Heavy_PhaseRing::cBinop_xezN70a6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_cZdL9OTv_sendMessage);
}

void Heavy_PhaseRing::cCast_qXeojbTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1CqJK5oW, 0, m, &cIf_1CqJK5oW_sendMessage);
}

void Heavy_PhaseRing::cCast_EAFI4Rsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_FBWoOoXW_sendMessage);
}

void Heavy_PhaseRing::cBinop_FBWoOoXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1CqJK5oW, 1, m, &cIf_1CqJK5oW_sendMessage);
}

void Heavy_PhaseRing::cBinop_XE3k3FJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_xezN70a6_sendMessage);
}

void Heavy_PhaseRing::cMsg_UYu3o7lC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_RYZ5ufup, 0, m, &cPack_RYZ5ufup_sendMessage);
}

void Heavy_PhaseRing::cBinop_cZdL9OTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBj5eBiZ, HV_BINOP_POW, 1, m, &cBinop_yBj5eBiZ_sendMessage);
  cMsg_kqUUAkO3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_RYZ5ufup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mOJWbroJ, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_S4yUNy6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4OiutNiM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_y5vuTL2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_5ZbKHKEe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_5ZbKHKEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FpAOw40q_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_4OiutNiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PhvXooBG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_uZgsw1TH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eWfhqloB_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wDPelXSo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vKNMLNJk_sendMessage);
}

void Heavy_PhaseRing::cIf_64oDgDLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_0qa8Xes2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_347Ys5gN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_YMEOL7QA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yrDPxQe7, HV_BINOP_POW, 0, m, &cBinop_yrDPxQe7_sendMessage);
}

void Heavy_PhaseRing::cBinop_yrDPxQe7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hv7dTLCt, 0, m, &cPack_hv7dTLCt_sendMessage);
}

void Heavy_PhaseRing::cBinop_jtlBONbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_37rTQoys_sendMessage);
}

void Heavy_PhaseRing::cCast_vKNMLNJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_64oDgDLw, 0, m, &cIf_64oDgDLw_sendMessage);
}

void Heavy_PhaseRing::cCast_wDPelXSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_6EZih3QB_sendMessage);
}

void Heavy_PhaseRing::cBinop_6EZih3QB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_64oDgDLw, 1, m, &cIf_64oDgDLw_sendMessage);
}

void Heavy_PhaseRing::cBinop_347Ys5gN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_jtlBONbL_sendMessage);
}

void Heavy_PhaseRing::cMsg_0qa8Xes2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_hv7dTLCt, 0, m, &cPack_hv7dTLCt_sendMessage);
}

void Heavy_PhaseRing::cBinop_37rTQoys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yrDPxQe7, HV_BINOP_POW, 1, m, &cBinop_yrDPxQe7_sendMessage);
  cMsg_YMEOL7QA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_hv7dTLCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_7SwZS8xB, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_8oGAA6Ou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xO9GMoxD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_eWfhqloB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_O0rl6Rre_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_O0rl6Rre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XZmywEum_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_xO9GMoxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OSLmL3lX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_wPAy1Io4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_zVkB9mzf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_t6pnn23k_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_t6pnn23k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_vrKJqd7J_sendMessage);
}

void Heavy_PhaseRing::cCast_P4Gh8enV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ZTAzA9MI_sendMessage);
}

void Heavy_PhaseRing::cCast_7gOvv8ZV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wPAy1Io4, 0, m, &cIf_wPAy1Io4_sendMessage);
}

void Heavy_PhaseRing::cMsg_zVkB9mzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_y5vuTL2O_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EAFI4Rsr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qXeojbTz_sendMessage);
}

void Heavy_PhaseRing::cBinop_vrKJqd7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_ShwHSIFV_sendMessage);
}

void Heavy_PhaseRing::cBinop_ShwHSIFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oCaxiwzt_sendMessage);
}

void Heavy_PhaseRing::cBinop_oCaxiwzt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y5vuTL2O_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EAFI4Rsr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qXeojbTz_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZTAzA9MI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wPAy1Io4, 1, m, &cIf_wPAy1Io4_sendMessage);
}

void Heavy_PhaseRing::cBinop_R8fAU4kE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P4Gh8enV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7gOvv8ZV_sendMessage);
}

void Heavy_PhaseRing::cBinop_0f1BkZBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_R8fAU4kE_sendMessage);
}

void Heavy_PhaseRing::cIf_tUm53yHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fgKqeAfm_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_FTZzKlQr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_FTZzKlQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_fSAf2m80_sendMessage);
}

void Heavy_PhaseRing::cCast_IJMSIk8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_2XawoUdx_sendMessage);
}

void Heavy_PhaseRing::cCast_CHlelZ6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tUm53yHS, 0, m, &cIf_tUm53yHS_sendMessage);
}

void Heavy_PhaseRing::cMsg_fgKqeAfm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_eWfhqloB_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wDPelXSo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vKNMLNJk_sendMessage);
}

void Heavy_PhaseRing::cBinop_fSAf2m80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_Cv7BfnnW_sendMessage);
}

void Heavy_PhaseRing::cBinop_Cv7BfnnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DvViAkXd_sendMessage);
}

void Heavy_PhaseRing::cBinop_DvViAkXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eWfhqloB_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wDPelXSo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vKNMLNJk_sendMessage);
}

void Heavy_PhaseRing::cBinop_2XawoUdx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tUm53yHS, 1, m, &cIf_tUm53yHS_sendMessage);
}

void Heavy_PhaseRing::cBinop_J3flgiK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IJMSIk8c_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CHlelZ6O_sendMessage);
}

void Heavy_PhaseRing::cBinop_wiMWpej9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_J3flgiK1_sendMessage);
}

void Heavy_PhaseRing::cVar_r2EEnIRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q8P9zzrW_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hnLNPp1A_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1oz8fMCp_sendMessage);
}

void Heavy_PhaseRing::cIf_ztAeB2HP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_0nareAAH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_jIVCASbZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_Z2XdJIr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_f2AWJBR8, HV_BINOP_POW, 0, m, &cBinop_f2AWJBR8_sendMessage);
}

void Heavy_PhaseRing::cBinop_f2AWJBR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rpGo6UUj, 0, m, &cPack_rpGo6UUj_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZFSifr8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_gN3bB78T_sendMessage);
}

void Heavy_PhaseRing::cCast_1oz8fMCp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ztAeB2HP, 0, m, &cIf_ztAeB2HP_sendMessage);
}

void Heavy_PhaseRing::cCast_hnLNPp1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Qiy6bLol_sendMessage);
}

void Heavy_PhaseRing::cBinop_Qiy6bLol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ztAeB2HP, 1, m, &cIf_ztAeB2HP_sendMessage);
}

void Heavy_PhaseRing::cBinop_jIVCASbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_ZFSifr8o_sendMessage);
}

void Heavy_PhaseRing::cMsg_0nareAAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_rpGo6UUj, 0, m, &cPack_rpGo6UUj_sendMessage);
}

void Heavy_PhaseRing::cBinop_gN3bB78T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f2AWJBR8, HV_BINOP_POW, 1, m, &cBinop_f2AWJBR8_sendMessage);
  cMsg_Z2XdJIr7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_rpGo6UUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AA5gy14d, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_5Ki1cTP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FJBdYKQs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_q8P9zzrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_FStEwkSp_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_FStEwkSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BbkJgtRY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_FJBdYKQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yngnY8qR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_kfaNmKKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RkE29pZB_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BhRa9NX4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qbREOqYs_sendMessage);
}

void Heavy_PhaseRing::cIf_vuVtdIZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_qD4uJKar_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_IHWHkm2O_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_oDOXWdxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AVTWcZRQ, HV_BINOP_POW, 0, m, &cBinop_AVTWcZRQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_AVTWcZRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_M56f88bG, 0, m, &cPack_M56f88bG_sendMessage);
}

void Heavy_PhaseRing::cBinop_5XogAaET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_UIhy2ASE_sendMessage);
}

void Heavy_PhaseRing::cCast_qbREOqYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vuVtdIZA, 0, m, &cIf_vuVtdIZA_sendMessage);
}

void Heavy_PhaseRing::cCast_BhRa9NX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_03ikCxDP_sendMessage);
}

void Heavy_PhaseRing::cBinop_03ikCxDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vuVtdIZA, 1, m, &cIf_vuVtdIZA_sendMessage);
}

void Heavy_PhaseRing::cBinop_IHWHkm2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_5XogAaET_sendMessage);
}

void Heavy_PhaseRing::cMsg_qD4uJKar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_M56f88bG, 0, m, &cPack_M56f88bG_sendMessage);
}

void Heavy_PhaseRing::cBinop_UIhy2ASE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AVTWcZRQ, HV_BINOP_POW, 1, m, &cBinop_AVTWcZRQ_sendMessage);
  cMsg_oDOXWdxf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_M56f88bG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_CkNXZgdu, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_RjdZLC7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TMg1yocP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_RkE29pZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_EwBJEtCe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_EwBJEtCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TUCV2Tj3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_TMg1yocP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ptcoxQAM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_sUTqnFYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a5xgDvof_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QEmne711_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J2z23uKP_sendMessage);
}

void Heavy_PhaseRing::cIf_80nWHzBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_F8ck5vxz_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_0J6VO3FI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_34sYISjo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vbeCAGtU, HV_BINOP_POW, 0, m, &cBinop_vbeCAGtU_sendMessage);
}

void Heavy_PhaseRing::cBinop_vbeCAGtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FIxhQEG6, 0, m, &cPack_FIxhQEG6_sendMessage);
}

void Heavy_PhaseRing::cBinop_aTZwItR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_2COPizqQ_sendMessage);
}

void Heavy_PhaseRing::cCast_J2z23uKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_80nWHzBT, 0, m, &cIf_80nWHzBT_sendMessage);
}

void Heavy_PhaseRing::cCast_QEmne711_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_XC456McX_sendMessage);
}

void Heavy_PhaseRing::cBinop_XC456McX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_80nWHzBT, 1, m, &cIf_80nWHzBT_sendMessage);
}

void Heavy_PhaseRing::cBinop_0J6VO3FI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_aTZwItR1_sendMessage);
}

void Heavy_PhaseRing::cMsg_F8ck5vxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_FIxhQEG6, 0, m, &cPack_FIxhQEG6_sendMessage);
}

void Heavy_PhaseRing::cBinop_2COPizqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vbeCAGtU, HV_BINOP_POW, 1, m, &cBinop_vbeCAGtU_sendMessage);
  cMsg_34sYISjo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_FIxhQEG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_BMCnp3ik, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_2XHS8FIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_WDB6L9qJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_a5xgDvof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_VjwCoCeU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_VjwCoCeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sCqytfQh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_WDB6L9qJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6DrEvHhw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_g3hW58dk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_phjlgO4k, 0, m, &cIf_phjlgO4k_sendMessage);
}

void Heavy_PhaseRing::cSlice_HWN7DiDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ee5x892q_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ssjnPLtG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_QkTGDsYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_Lsm9iEtX, 0, m, &cIf_Lsm9iEtX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_Lsm9iEtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CJosk5VJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FDyJAV56_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_gM29ndnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_YncaOnmr, 2, m, &cPack_YncaOnmr_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_IrNYKeed, 1, m, &cPack_IrNYKeed_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_1xBytj6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_HWN7DiDW, 0, m, &cSlice_HWN7DiDW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QkTGDsYw, 0, m, &cSlice_QkTGDsYw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_ccNR9G8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_EDQoj5K8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_F8v0TK6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gIsj7aT2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1tfcGewq_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a7h0Iw77_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_71z5UQ7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3c5SCZIG, 1, m, &cIf_3c5SCZIG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_LGdCxQEv_sendMessage);
}

void Heavy_PhaseRing::cIf_3c5SCZIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_HWN7DiDW, 0, m, &cSlice_HWN7DiDW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QkTGDsYw, 0, m, &cSlice_QkTGDsYw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_IrNYKeed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1xBytj6g, 0, m, &cIf_1xBytj6g_sendMessage);
}

void Heavy_PhaseRing::cBinop_3PhCpocR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Lsm9iEtX, 1, m, &cIf_Lsm9iEtX_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_gM29ndnV, 1, m, &cIf_gM29ndnV_sendMessage);
}

void Heavy_PhaseRing::cCast_ssjnPLtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gM29ndnV, 0, m, &cIf_gM29ndnV_sendMessage);
}

void Heavy_PhaseRing::cCast_ee5x892q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_3PhCpocR_sendMessage);
}

void Heavy_PhaseRing::cMsg_YZtHttY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_71z5UQ7n, 1, m, &cVar_71z5UQ7n_sendMessage);
}

void Heavy_PhaseRing::cMsg_EDQoj5K8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_71z5UQ7n, 1, m, &cVar_71z5UQ7n_sendMessage);
}

void Heavy_PhaseRing::cCast_gIsj7aT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_71z5UQ7n, 0, m, &cVar_71z5UQ7n_sendMessage);
}

void Heavy_PhaseRing::cCast_1tfcGewq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IrNYKeed, 0, m, &cPack_IrNYKeed_sendMessage);
}

void Heavy_PhaseRing::cCast_a7h0Iw77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YZtHttY5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_LGdCxQEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1xBytj6g, 1, m, &cIf_1xBytj6g_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_Lb5ZcdqB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ur8AgDTI, 0, m, &cSlice_Ur8AgDTI_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jIOWyo9q, 0, m, &cSlice_jIOWyo9q_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qKivOSKT, 0, m, &cSlice_qKivOSKT_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VMcOjzdS, 0, m, &cSlice_VMcOjzdS_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_Ur8AgDTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_TB0B6sDp, 0, m, &cSlice_TB0B6sDp_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_1oOtrvBh, 0, m, &cSlice_1oOtrvBh_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_TB0B6sDp, 0, m, &cSlice_TB0B6sDp_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_1oOtrvBh, 0, m, &cSlice_1oOtrvBh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_jIOWyo9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_1REj9Ufc, 0, m, &cSlice_1REj9Ufc_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_JxMOWpkk, 0, m, &cSlice_JxMOWpkk_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_1REj9Ufc, 0, m, &cSlice_1REj9Ufc_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_JxMOWpkk, 0, m, &cSlice_JxMOWpkk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_qKivOSKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_LdSRsq9A, 0, m, &cSlice_LdSRsq9A_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_g0j3JeDk, 0, m, &cSlice_g0j3JeDk_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_LdSRsq9A, 0, m, &cSlice_LdSRsq9A_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_g0j3JeDk, 0, m, &cSlice_g0j3JeDk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_VMcOjzdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7K9E3PAI, 0, m, &cSlice_7K9E3PAI_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_nXPk7n3I, 0, m, &cSlice_nXPk7n3I_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7K9E3PAI, 0, m, &cSlice_7K9E3PAI_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_nXPk7n3I, 0, m, &cSlice_nXPk7n3I_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_mpI4QNBF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qsRasSHZ_sendMessage);
      break;
    }
    default: {
      cMsg_8DJjK38E_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_qsRasSHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s9Gz9vzo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_phjlgO4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ccNR9G8S, 0, m, &cSlice_ccNR9G8S_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_F8v0TK6O, 0, m, &cSlice_F8v0TK6O_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_3c5SCZIG, 0, m, &cIf_3c5SCZIG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_WHwpMS5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_dJHntoaw_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_phjlgO4k, 1, m, &cIf_phjlgO4k_sendMessage);
}

void Heavy_PhaseRing::cBinop_dJHntoaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WHwpMS5J, 1, m, &cVar_WHwpMS5J_sendMessage);
}

void Heavy_PhaseRing::cMsg_s9Gz9vzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_WHwpMS5J, 0, m, &cVar_WHwpMS5J_sendMessage);
}

void Heavy_PhaseRing::cMsg_8DJjK38E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_WHwpMS5J, 0, m, &cVar_WHwpMS5J_sendMessage);
}

void Heavy_PhaseRing::cPack_YncaOnmr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Lb5ZcdqB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_KV5AF9iJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YncaOnmr, 0, m, &cPack_YncaOnmr_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_aUzwi8ix_sendMessage);
}

void Heavy_PhaseRing::cBinop_aUzwi8ix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_FbdjWYV6_sendMessage);
}

void Heavy_PhaseRing::cBinop_FbdjWYV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KV5AF9iJ, 1, m, &cVar_KV5AF9iJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_BtNuB3Mc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_mpI4QNBF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_CJosk5VJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YncaOnmr, 1, m, &cPack_YncaOnmr_sendMessage);
}

void Heavy_PhaseRing::cCast_FDyJAV56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KV5AF9iJ, 0, m, &cVar_KV5AF9iJ_sendMessage);
}

void Heavy_PhaseRing::cSend_5n8Hn23c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TuqPBqrR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_0PxQBoCp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tWZbFbp0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_AcxLzwHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_hmDN3oQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_k6CoXMd6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_SanAMiCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_X4nk0d5C_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_k6CoXMd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Gifx0eEn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_X4nk0d5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_AQH7mRZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_y1sMA4oa_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_KnedFyXo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cReceive_HENPNznC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_duVuL1m1_sendMessage(_c, 0, m);
  cMsg_udic6Ocg_sendMessage(_c, 0, m);
  cMsg_kuaHjDYr_sendMessage(_c, 0, m);
  cMsg_uY2ohx7Q_sendMessage(_c, 0, m);
  cMsg_VlhX8Pjv_sendMessage(_c, 0, m);
  cMsg_7VZ0lZNJ_sendMessage(_c, 0, m);
  cMsg_rl1UneHE_sendMessage(_c, 0, m);
  cMsg_U9PWyVVY_sendMessage(_c, 0, m);
  cMsg_SP87JvKf_sendMessage(_c, 0, m);
  cMsg_lzoX3zdj_sendMessage(_c, 0, m);
  cMsg_K1EBPFWS_sendMessage(_c, 0, m);
  cMsg_JUH7BNvw_sendMessage(_c, 0, m);
  cMsg_TPAwYdYo_sendMessage(_c, 0, m);
  cMsg_mLEPgkdG_sendMessage(_c, 0, m);
  cMsg_m5H1PTtO_sendMessage(_c, 0, m);
  cMsg_htXq5Wqh_sendMessage(_c, 0, m);
  cMsg_tkoitAWo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XPj00sGH, 0, m, &cVar_XPj00sGH_sendMessage);
  cMsg_F12g0Fhd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KH4afGDD, 0, m, &cVar_KH4afGDD_sendMessage);
  cMsg_t04IXFSz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8Q8fIgxJ, 0, m, &cVar_8Q8fIgxJ_sendMessage);
  cMsg_PKWMiD96_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MxPYDdnH, 0, m, &cVar_MxPYDdnH_sendMessage);
  cMsg_wNrKTelV_sendMessage(_c, 0, m);
  cMsg_eq9NHATP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DoS6YuLp, 0, m, &cVar_DoS6YuLp_sendMessage);
  cMsg_MJ78nTIE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pLrzwnd1, 0, m, &cVar_pLrzwnd1_sendMessage);
  cMsg_hNT9FLtS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_D7DzEICZ, 0, m, &cVar_D7DzEICZ_sendMessage);
  cMsg_BRDHS9W7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tVuBjZrW, 0, m, &cVar_tVuBjZrW_sendMessage);
  cMsg_Wgm8d0fa_sendMessage(_c, 0, m);
  cMsg_l9SHvoPR_sendMessage(_c, 0, m);
  cMsg_RkuVKUEP_sendMessage(_c, 0, m);
  cMsg_fZseH6iV_sendMessage(_c, 0, m);
  cMsg_DXK5dQ8t_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pFdDqbIX, 0, m, &cVar_pFdDqbIX_sendMessage);
  cMsg_t8vDSasW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LfSsfqKi, 0, m, &cVar_LfSsfqKi_sendMessage);
  cMsg_KEmnSRIK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_myw2Dnre, 0, m, &cVar_myw2Dnre_sendMessage);
  cMsg_Gw6ZERkw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6H6YvLhW, 0, m, &cVar_6H6YvLhW_sendMessage);
  cMsg_lcdZcMDn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mJFYSDIG, 0, m, &cVar_mJFYSDIG_sendMessage);
  cMsg_Dsu7WDLP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VOeYVCJp, 0, m, &cVar_VOeYVCJp_sendMessage);
  cMsg_3z0QEWVB_sendMessage(_c, 0, m);
  cMsg_2GxJDtYh_sendMessage(_c, 0, m);
  cMsg_UHbO3lRt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bUGY8CSu, 0, m, &cVar_bUGY8CSu_sendMessage);
  cMsg_1CcIUJOk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fTot3fFS, 0, m, &cVar_fTot3fFS_sendMessage);
  cMsg_q0o1CWJ8_sendMessage(_c, 0, m);
  cMsg_0lV5azls_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NLRDvdDt, 0, m, &cVar_NLRDvdDt_sendMessage);
  cMsg_sUOE0z1X_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xVjvCi5o, 0, m, &cVar_xVjvCi5o_sendMessage);
  cMsg_OnnCgHDs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AVwH8FVU, 0, m, &cVar_AVwH8FVU_sendMessage);
  cMsg_nWxOcH9a_sendMessage(_c, 0, m);
  cMsg_yZk548xJ_sendMessage(_c, 0, m);
  cMsg_RLNzaHAY_sendMessage(_c, 0, m);
  cMsg_dE9kM7Ct_sendMessage(_c, 0, m);
  cMsg_3IltbDzQ_sendMessage(_c, 0, m);
  cMsg_LI6ItjUS_sendMessage(_c, 0, m);
  cMsg_xCZ6fCAD_sendMessage(_c, 0, m);
  cMsg_hPtYbyiR_sendMessage(_c, 0, m);
  cMsg_klBygAGg_sendMessage(_c, 0, m);
  cMsg_iyaogXMS_sendMessage(_c, 0, m);
  cMsg_A2uOzC7v_sendMessage(_c, 0, m);
  cMsg_7SK4q6xt_sendMessage(_c, 0, m);
  cMsg_W5p6L1Zp_sendMessage(_c, 0, m);
  cMsg_ip2GIbYk_sendMessage(_c, 0, m);
  cMsg_CEqTWvNu_sendMessage(_c, 0, m);
  cMsg_9LGFCW2x_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QXOBBPyn, 0, m, &cVar_QXOBBPyn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aiF97HwO, 0, m, &cVar_aiF97HwO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_neMgIJRF, 0, m, &cVar_neMgIJRF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ex8ouweF, 0, m, &cVar_Ex8ouweF_sendMessage);
  cMsg_GLagd0ds_sendMessage(_c, 0, m);
  cMsg_JdC3Flvi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JdvEXeF3, 0, m, &cVar_JdvEXeF3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8Sv7xkSj, 0, m, &cVar_8Sv7xkSj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_W9892EYu, 0, m, &cVar_W9892EYu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PY43sc3t, 0, m, &cVar_PY43sc3t_sendMessage);
  cMsg_MmAnhAM6_sendMessage(_c, 0, m);
  cMsg_CcoNh8es_sendMessage(_c, 0, m);
  cMsg_fXX4bFdE_sendMessage(_c, 0, m);
  cMsg_ZfbQPvZR_sendMessage(_c, 0, m);
  cMsg_5ZnovGdn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_URxMdMVG, 0, m, &cVar_URxMdMVG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Lrw3Ayun, 0, m, &cVar_Lrw3Ayun_sendMessage);
  cMsg_E6bG38Mp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SRH2aXPr, 0, m, &cVar_SRH2aXPr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1OURFzj7, 0, m, &cVar_1OURFzj7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oLk3LvF4, 0, m, &cVar_oLk3LvF4_sendMessage);
  cMsg_rKg4gXdu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Fr8DHrvr, 0, m, &cVar_Fr8DHrvr_sendMessage);
  cMsg_xBba5blE_sendMessage(_c, 0, m);
  cMsg_4qXQKdIh_sendMessage(_c, 0, m);
  cMsg_cTlD1QQK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_celc4kgG, 0, m, &cVar_celc4kgG_sendMessage);
  cMsg_jF8fobtR_sendMessage(_c, 0, m);
  cMsg_9899CIUu_sendMessage(_c, 0, m);
  cMsg_9Rhep0yK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RPybZG23, 0, m, &cVar_RPybZG23_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uZgsw1TH, 0, m, &cVar_uZgsw1TH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_r2EEnIRC, 0, m, &cVar_r2EEnIRC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kfaNmKKg, 0, m, &cVar_kfaNmKKg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sUTqnFYU, 0, m, &cVar_sUTqnFYU_sendMessage);
  cMsg_BtNuB3Mc_sendMessage(_c, 0, m);
  cSwitchcase_y1sMA4oa_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_KnedFyXo_onMessage(_c, NULL, 0, m, NULL);
  cMsg_uX0QHHzK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Yjke4BbL, 0, m, &cVar_Yjke4BbL_sendMessage);
  cMsg_1cVh67FZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DJsKyvZW, 0, m, &cTabhead_DJsKyvZW_sendMessage);
  cMsg_9CK2VThX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Hj03nxtc, 0, m, &cVar_Hj03nxtc_sendMessage);
  cMsg_Az6vd0lE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9Tb2rOGi, 0, m, &cTabhead_9Tb2rOGi_sendMessage);
  cMsg_Xphg4P4J_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ogPat2Qz, 0, m, &cVar_ogPat2Qz_sendMessage);
  cMsg_oP1U5t7E_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zniqSSRx, 0, m, &cTabhead_zniqSSRx_sendMessage);
  cMsg_PoKXTLjv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5VImFzOw, 0, m, &cVar_5VImFzOw_sendMessage);
  cMsg_pZxnaOU2_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BMwEKgwi, 0, m, &cTabhead_BMwEKgwi_sendMessage);
  cMsg_i7vqvBVK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5TZdf7Ge, 0, m, &cVar_5TZdf7Ge_sendMessage);
  cMsg_txoj0mEo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_q0Jb4lNK, 0, m, &cTabhead_q0Jb4lNK_sendMessage);
  cMsg_u2BItKlf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XZh7uSpw, 0, m, &cVar_XZh7uSpw_sendMessage);
  cMsg_olRM7fmL_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zlO6azOc, 0, m, &cTabhead_zlO6azOc_sendMessage);
  cMsg_HiY0w8lv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_boVHaGib, 0, m, &cVar_boVHaGib_sendMessage);
  cMsg_8tygPEfS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_J01iXiyW, 0, m, &cTabhead_J01iXiyW_sendMessage);
  cMsg_pbnHOacX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_F7J7F0R3, 0, m, &cVar_F7J7F0R3_sendMessage);
  cMsg_4pOW8zgw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_U85d9Y5U, 0, m, &cTabhead_U85d9Y5U_sendMessage);
  cMsg_8aQpXfHC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_j24waaS7, 0, m, &cVar_j24waaS7_sendMessage);
  cMsg_JVcCmfUh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Z2O1qOoy, 0, m, &cTabhead_Z2O1qOoy_sendMessage);
  cMsg_UMpMoUOR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fCzNbENK, 0, m, &cVar_fCzNbENK_sendMessage);
  cMsg_Dp2nEM35_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_FepUjPkp, 0, m, &cTabhead_FepUjPkp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RlIm1VPq, 0, m, &cVar_RlIm1VPq_sendMessage);
  cMsg_a7g4gDK6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hkZ0L2Kq, 0, m, &cVar_hkZ0L2Kq_sendMessage);
  cMsg_vZuDsFXg_sendMessage(_c, 0, m);
  cMsg_y3N9HnLj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4k5qqSle, 0, m, &cVar_4k5qqSle_sendMessage);
  cMsg_6MtvyG2p_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EIuMrBwv, 0, m, &cTabhead_EIuMrBwv_sendMessage);
  cMsg_8FqIvc3v_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Nz53AEGq, 0, m, &cVar_Nz53AEGq_sendMessage);
  cMsg_5CE4emeI_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kladtYAp, 0, m, &cTabhead_kladtYAp_sendMessage);
  cMsg_IN2WWRTp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yHyoXIx9, 0, m, &cVar_yHyoXIx9_sendMessage);
  cMsg_SldyUoDh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZitnlkJz, 0, m, &cTabhead_ZitnlkJz_sendMessage);
  cMsg_9vcsLnwu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_s8QlkCHL, 0, m, &cVar_s8QlkCHL_sendMessage);
  cMsg_8B9dOwXC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_xvYgYoT8, 0, m, &cTabhead_xvYgYoT8_sendMessage);
  cMsg_qi260ApG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Fu3LHd7f, 0, m, &cVar_Fu3LHd7f_sendMessage);
  cMsg_mhrjUVHa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sPzwrraR, 0, m, &cTabhead_sPzwrraR_sendMessage);
  cMsg_vgLNtj0i_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NyEn7IN9, 0, m, &cVar_NyEn7IN9_sendMessage);
  cMsg_zdgcTjRO_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9J3vn407, 0, m, &cTabhead_9J3vn407_sendMessage);
  cMsg_3ZAcFCbX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gdktfi2h, 0, m, &cVar_gdktfi2h_sendMessage);
  cMsg_mQykVerV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QhIIM1Wp, 0, m, &cTabhead_QhIIM1Wp_sendMessage);
  cMsg_2wZdGV5I_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rgmbpMPk, 0, m, &cVar_rgmbpMPk_sendMessage);
  cMsg_6bPM3Zf8_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7igCf9ZW, 0, m, &cTabhead_7igCf9ZW_sendMessage);
  cMsg_2og0hsrB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UIQzP1YQ, 0, m, &cVar_UIQzP1YQ_sendMessage);
  cMsg_BamErUFv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_vSVFcE5z, 0, m, &cTabhead_vSVFcE5z_sendMessage);
  cMsg_xEopCq12_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9LEXC4CG, 0, m, &cVar_9LEXC4CG_sendMessage);
  cMsg_8oMdrxDd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_U08NLIoz, 0, m, &cTabhead_U08NLIoz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_luFtk7S7, 0, m, &cVar_luFtk7S7_sendMessage);
  cMsg_NjeHkEFn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fFLErozG, 0, m, &cVar_fFLErozG_sendMessage);
  cMsg_rojwloF1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_No3ef98I, 0, m, &cVar_No3ef98I_sendMessage);
  cMsg_aDZCjSaK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Q06SCMde, 0, m, &cVar_Q06SCMde_sendMessage);
  cMsg_sA6cHLQd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_yq4lbNbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_fESLPaAW, 0, m, &cSlice_fESLPaAW_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_b9hIovkd, 0, m, &cSlice_b9hIovkd_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_HJdEfHnu, 0, m, &cSlice_HJdEfHnu_sendMessage);
}

void Heavy_PhaseRing::cReceive_TuqPBqrR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_g3hW58dk, 0, m, &cPack_g3hW58dk_sendMessage);
}

void Heavy_PhaseRing::cReceive_tWZbFbp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_g3hW58dk, 1, m, &cPack_g3hW58dk_sendMessage);
}

void Heavy_PhaseRing::cReceive_efxuoxRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_VglWAXiC_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_jZo0co7K, 0, m, &cIf_jZo0co7K_sendMessage);
}

void Heavy_PhaseRing::cReceive_kAkOWUc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_s9rxYej0_sendMessage);
}

void Heavy_PhaseRing::cReceive_IcCfKqei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uky0mP76, 0, m, &cPack_uky0mP76_sendMessage);
}

void Heavy_PhaseRing::cReceive_Z2WhtVyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_I7chejO7_sendMessage);
}

void Heavy_PhaseRing::cReceive_61ZJX2wL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cReceive_71nqDOQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wb8RjuuX_sendMessage);
}

void Heavy_PhaseRing::cReceive_M3BAfxSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DlfCw5G7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_34DcPMUv_sendMessage);
}

void Heavy_PhaseRing::cReceive_fGMqgrZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AQH7mRZA_sendMessage);
}

void Heavy_PhaseRing::cReceive_Gifx0eEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_B0CciSoD, 0, m, &cVar_B0CciSoD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lpwvnreK, 0, m, &cVar_lpwvnreK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6ImolnSq, 0, m, &cVar_6ImolnSq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AXliokcF, 0, m, &cVar_AXliokcF_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_0GAkseD5, 0, m, &cPack_0GAkseD5_sendMessage);
}

void Heavy_PhaseRing::cReceive_YvGfEJ1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FeSq78Cc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yhtWorUn, 0, m, &cVar_yhtWorUn_sendMessage);
}

void Heavy_PhaseRing::cReceive_YkqcS6vr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_eXVzX7zl, 0, m, &cPack_eXVzX7zl_sendMessage);
}

void Heavy_PhaseRing::cReceive_Z0OzQNyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tCGKna7s, 1, m, &cVar_tCGKna7s_sendMessage);
}

void Heavy_PhaseRing::cReceive_X8EaeImA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_A0kDY4YY, m);
}

void Heavy_PhaseRing::cReceive_3BDo215S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ewU5JghP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iCYW18fo, 0, m, &cVar_iCYW18fo_sendMessage);
}

void Heavy_PhaseRing::cReceive_sKEnmiHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tHKPUkqq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GA0byKO3, 0, m, &cVar_GA0byKO3_sendMessage);
}

void Heavy_PhaseRing::cReceive_DEga6JdK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SxmeRZcZ, 0, m, &cVar_SxmeRZcZ_sendMessage);
}

void Heavy_PhaseRing::cReceive_BHa2ZALi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WaMDSsYk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TKwvTsTZ_sendMessage);
}

void Heavy_PhaseRing::cReceive_jgRFFnY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1GjbBA4U_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zm14CA7m, 0, m, &cVar_zm14CA7m_sendMessage);
}

void Heavy_PhaseRing::cReceive_ZCJv7p8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gwsNKHJW, 0, m, &cPack_gwsNKHJW_sendMessage);
}

void Heavy_PhaseRing::cReceive_wkRWCbd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O90gOwiw, 1, m, &cVar_O90gOwiw_sendMessage);
}

void Heavy_PhaseRing::cReceive_9yXHCQi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ULDdb0X6, m);
}

void Heavy_PhaseRing::cReceive_c88i3DWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5G9vXvBm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Nk37ur1Y, 0, m, &cVar_Nk37ur1Y_sendMessage);
}

void Heavy_PhaseRing::cReceive_9CHaZ2S3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dnzqWiEO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JoKps3gy, 0, m, &cVar_JoKps3gy_sendMessage);
}

void Heavy_PhaseRing::cReceive_hy5Ok4HN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ku4kcs9M_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Jh0tlPo6, 0, m, &cVar_Jh0tlPo6_sendMessage);
}

void Heavy_PhaseRing::cReceive_aMvG38NC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cCvAVVBM, 0, m, &cPack_cCvAVVBM_sendMessage);
}

void Heavy_PhaseRing::cReceive_5e7VaWpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OTKaE5wW, 1, m, &cVar_OTKaE5wW_sendMessage);
}

void Heavy_PhaseRing::cReceive_YcH6dYxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_j9jpSXYK, m);
}

void Heavy_PhaseRing::cReceive_QkjQVfJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pPCzKJWX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hUmtzh86, 0, m, &cVar_hUmtzh86_sendMessage);
}

void Heavy_PhaseRing::cReceive_ZAYhlkdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_EbzD5B1H_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QvV1vCLR, 0, m, &cVar_QvV1vCLR_sendMessage);
}

void Heavy_PhaseRing::cReceive_Pa6oZDgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gznHaRdp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uLsZ590T, 0, m, &cVar_uLsZ590T_sendMessage);
}

void Heavy_PhaseRing::cReceive_rr1jbxmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9bkU2OkU, 0, m, &cPack_9bkU2OkU_sendMessage);
}

void Heavy_PhaseRing::cReceive_5irM8S1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C0FrBgZs, 1, m, &cVar_C0FrBgZs_sendMessage);
}

void Heavy_PhaseRing::cReceive_gMNUY4Fc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tIJ7HHY1, m);
}

void Heavy_PhaseRing::cReceive_X6s6Chi8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_WiHSg4RG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PK4N2nxj, 0, m, &cVar_PK4N2nxj_sendMessage);
}

void Heavy_PhaseRing::cReceive_8hJLCNQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_X5WJTuDb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_60z9JOad, 0, m, &cVar_60z9JOad_sendMessage);
}

void Heavy_PhaseRing::cReceive_2dq0lZZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_x8TxwQkj_sendMessage);
}

void Heavy_PhaseRing::cReceive_rTu1CCrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fA50HyJo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5U89dJIU_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_ZhvVIc8S, 0, m, &cPack_ZhvVIc8S_sendMessage);
}

void Heavy_PhaseRing::cReceive_FpAOw40q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S4yUNy6C, 0, m, &cVar_S4yUNy6C_sendMessage);
}

void Heavy_PhaseRing::cReceive_PhvXooBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EAFI4Rsr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qXeojbTz_sendMessage);
}

void Heavy_PhaseRing::cReceive_YK5iZytf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_0f1BkZBA_sendMessage);
}

void Heavy_PhaseRing::cReceive_XZmywEum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8oGAA6Ou, 0, m, &cVar_8oGAA6Ou_sendMessage);
}

void Heavy_PhaseRing::cReceive_OSLmL3lX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wDPelXSo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vKNMLNJk_sendMessage);
}

void Heavy_PhaseRing::cReceive_dJiywmSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_wiMWpej9_sendMessage);
}

void Heavy_PhaseRing::cReceive_BbkJgtRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5Ki1cTP4, 0, m, &cVar_5Ki1cTP4_sendMessage);
}

void Heavy_PhaseRing::cReceive_yngnY8qR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hnLNPp1A_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1oz8fMCp_sendMessage);
}

void Heavy_PhaseRing::cReceive_TUCV2Tj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RjdZLC7k, 0, m, &cVar_RjdZLC7k_sendMessage);
}

void Heavy_PhaseRing::cReceive_ptcoxQAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BhRa9NX4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qbREOqYs_sendMessage);
}

void Heavy_PhaseRing::cReceive_sCqytfQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2XHS8FIa, 0, m, &cVar_2XHS8FIa_sendMessage);
}

void Heavy_PhaseRing::cReceive_6DrEvHhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QEmne711_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J2z23uKP_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_EgPFXmsd, VOf(Bf0));
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
    __hv_line_f(&sLine_lMuc2LpX, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_JsbSoQr0, VOf(Bf0));
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
    __hv_line_f(&sLine_5dohWZaN, VOf(Bf5));
    __hv_varread_f(&sVarf_A0kDY4YY, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_7MY9FA4f, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_AZr3Sohn, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_tZkOHd5D, VOf(Bf3));
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
    __hv_line_f(&sLine_9TgWPYcF, VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_d6rQIE5W, VOf(Bf3));
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
    __hv_line_f(&sLine_E4GJw2Mv, VOf(Bf1));
    __hv_varread_f(&sVarf_ULDdb0X6, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_p6RLl9ed, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_row2Xprb, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_UGOv6nYl, VOf(Bf6));
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
    __hv_line_f(&sLine_vWrAVoai, VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_AtdoyN25, VOf(Bf6));
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
    __hv_line_f(&sLine_bQ4nxFJs, VOf(Bf3));
    __hv_varread_f(&sVarf_j9jpSXYK, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_3nVSm8o5, VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_4FWNfVUv, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_wuO8mb2C, VOf(Bf8));
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
    __hv_line_f(&sLine_VEngK9mt, VOf(Bf9));
    __hv_phasor_k_f(&sPhasor_C8Rogm34, VOf(Bf8));
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
    __hv_line_f(&sLine_Ef22l1vd, VOf(Bf6));
    __hv_varread_f(&sVarf_tIJ7HHY1, VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_TFJwJV7E, VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_WtRayAnr, VOf(Bf6));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_wpWPBc00, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_GxvvmjH4, VOf(Bf6));
    __hv_phasor_f(&sPhasor_24pqy2K1, VIf(Bf6), VOf(Bf6));
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
    __hv_line_f(&sLine_AKfwDSmu, VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_iZaLmucb, VOf(Bf6));
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
    __hv_line_f(&sLine_EtFH8KRx, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_Pw1OFfpO, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_el8eT63s, VOf(Bf11));
    __hv_rpole_f(&sRPole_CEgZamZ0, VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Rc4poccF, VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_G2Jqvbkg, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_CkNXZgdu, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf7));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_add_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_AA5gy14d, VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_mOJWbroJ, VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_tabread_f(&sTabread_ss8XATiQ, VOf(Bf7));
    __hv_varread_f(&sVarf_F4cXwsnx, VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_b3CKtgZY, VOf(Bf0));
    __hv_rpole_f(&sRPole_JrlWd5RU, VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf0));
    __hv_line_f(&sLine_KTHIp4Sv, VOf(Bf10));
    __hv_fma_f(VIf(Bf0), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_5aM0vGxX, VOf(Bf0));
    __hv_tabread_f(&sTabread_cu3cZnNI, VOf(Bf5));
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf9));
    __hv_tabread_f(&sTabread_dghLZh9A, VOf(Bf6));
    __hv_add_f(VIf(Bf9), VIf(Bf6), VOf(Bf1));
    __hv_tabread_f(&sTabread_X8V50qQF, VOf(Bf8));
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf2));
    __hv_tabread_f(&sTabread_wffloDbf, VOf(Bf12));
    __hv_add_f(VIf(Bf2), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_ym0mC4Og, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_uwOlxGrC, VIf(Bf15));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_BPVNU90c, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_ZN6mPLk9, VIf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_JHFXe0ee, VIf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_RFf1elrf, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_3wiViRVW, VIf(Bf3));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_Gcpr8fEh, VOf(Bf13));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_EcCksb3G, VOf(Bf7));
    __hv_varread_f(&sVarf_VF6nDds8, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_nrehWPSJ, VOf(Bf6));
    __hv_rpole_f(&sRPole_hjYVkrhe, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf7));
    __hv_tabread_f(&sTabread_Vy8XwgvI, VOf(Bf6));
    __hv_varread_f(&sVarf_Qm967ZSJ, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_1weslR2s, VOf(Bf9));
    __hv_rpole_f(&sRPole_hS5bKfed, VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_tabread_f(&sTabread_pEThncXJ, VOf(Bf9));
    __hv_varread_f(&sVarf_Jqg8EUnA, VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_7N6sgdaj, VOf(Bf8));
    __hv_rpole_f(&sRPole_WcBUSARq, VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf9));
    __hv_add_f(VIf(Bf7), VIf(Bf9), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_Zr3OBmyJ, VIf(Bf10));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf10));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf8));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_v4qRoaUZ, VIf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_h0WP7Mzj, VIf(Bf9));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_VPcgzzYi, VIf(Bf8));
    __hv_line_f(&sLine_ckD8PFEi, VOf(Bf8));
    __hv_mul_f(VIf(Bf14), VIf(Bf8), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf13));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_Uybn0hAd, VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_x6EaIm60, VIf(Bf6));
    __hv_line_f(&sLine_L6Uz2u3Y, VOf(Bf8));
    __hv_phasor_f(&sPhasor_e73hdcqQ, VIf(Bf8), VOf(Bf8));
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
    __hv_line_f(&sLine_6eE1G0oF, VOf(Bf1));
    __hv_line_f(&sLine_zT0U5Nd2, VOf(Bf0));
    __hv_fma_f(VIf(Bf8), VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabhead_f(&sTabhead_Nb0uyUxq, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_xsBzyZiz, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_qtVatXXt, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf7));
    __hv_varread_f(&sVarf_dqMc9oLE, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_NGpoj74r, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_v8aZLEL2, VIi(Bi0), VOf(Bf2));
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
    __hv_tabhead_f(&sTabhead_F4ljiYZF, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_pGEdpUhu, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_xv2fJy9z, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf8));
    __hv_varread_f(&sVarf_otoAoWKG, VOf(Bf0));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_4DfAhkcn, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_csNIpZav, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf16), VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_LEghi2TG, VOf(Bf2));
    __hv_tabhead_f(&sTabhead_rlkXvl73, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_pF2wFGwx, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_GJVSvaYt, VOf(Bf2));
    __hv_min_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_96PjJZmS, VOf(Bf2));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_A1osutGy, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_BifwfxeL, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf8), VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_blGeibxy, VOf(Bf17));
    __hv_rpole_f(&sRPole_G1Q7NZ0y, VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_lQDjeGyL, VIf(Bf17), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_SJ9BFOT1, VOf(Bf17));
    __hv_mul_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_H4vyfMuo, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf17));
    __hv_line_f(&sLine_HdZ8RftR, VOf(Bf8));
    __hv_varread_f(&sVarf_DiER5g1K, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_8iBRt9CU, VOf(Bf2));
    __hv_rpole_f(&sRPole_Wr9tEVsW, VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_38MffpdR, VIf(Bf2));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_opCZfXDh, VOf(Bf17));
    __hv_varread_f(&sVarf_wwvIsUpJ, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_B8JPcRgV, VOf(Bf2));
    __hv_min_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_qV50ElgG, VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_varread_f(&sVarf_rCF2O5HX, VOf(Bf2));
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
    __hv_cpole_f(&sCPole_DpBexXci, VIf(Bf2), VIf(ZERO), VIf(Bf0), VIf(Bf17), VOf(Bf17), VOf(Bf0));
    __hv_varread_f(&sVarf_fRkdFzLs, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_xIoTsUED, VOf(Bf17));
    __hv_rpole_f(&sRPole_SPayu0oI, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_oRWDO7FO, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_LmjaFRr7, VOf(Bf17));
    __hv_rpole_f(&sRPole_n3ZRQQPj, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_0htvQe1P, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_g12I6sjG, VOf(Bf17));
    __hv_rpole_f(&sRPole_8DgRBtoo, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_kZbSpnoU, VOf(Bf0));
    __hv_varread_f(&sVarf_M5ttx0Hr, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_kDTd7ARj, VOf(Bf8));
    __hv_rpole_f(&sRPole_PhiaDtVP, VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf8));
    __hv_line_f(&sLine_jGXZkfC6, VOf(Bf2));
    __hv_fma_f(VIf(Bf8), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_PAnsX5zg, VOf(Bf8));
    __hv_tabread_f(&sTabread_pYPAozmb, VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf12));
    __hv_tabread_f(&sTabread_hDmyyXGr, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_ZTn4TLVK, VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf18));
    __hv_tabread_f(&sTabread_FkP35a8D, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf9));
    __hv_tabread_f(&sTabread_nUbLFRYq, VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_fXzbIy6j, VIf(Bf5));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_SewxLwmm, VIf(Bf15));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_8IOOxRRR, VIf(Bf7));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_OHMVbHSM, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_7HZmQdfN, VIf(Bf6));
    __hv_tabwrite_f(&sTabwrite_vCtUo5b0, VIf(Bf17));
    __hv_add_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_0wySjqiB, VOf(Bf9));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_VDlUKKBc, VOf(Bf0));
    __hv_varread_f(&sVarf_NKe9y2xE, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_jWQfRG73, VOf(Bf16));
    __hv_rpole_f(&sRPole_GFly23yw, VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf0));
    __hv_tabread_f(&sTabread_uBeiRDrW, VOf(Bf16));
    __hv_varread_f(&sVarf_Rs3LFxpv, VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_ipZ7hH4B, VOf(Bf12));
    __hv_rpole_f(&sRPole_ztwtSFrv, VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf16));
    __hv_tabread_f(&sTabread_3VpwcPro, VOf(Bf12));
    __hv_varread_f(&sVarf_JOAX3PId, VOf(Bf6));
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_JsdKSllh, VOf(Bf7));
    __hv_rpole_f(&sRPole_MeomZkml, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf12), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf16), VIf(Bf8), VOf(Bf12));
    __hv_add_f(VIf(Bf0), VIf(Bf12), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_43udeLsA, VIf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf2));
    __hv_sub_f(VIf(Bf16), VIf(Bf8), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf7), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_mGVewA1Y, VIf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_zN0I33gf, VIf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_rT7B78Ix, VIf(Bf7));
    __hv_line_f(&sLine_xjTgnxKo, VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf16), VIf(Bf7), VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_VTWbQbgJ, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_bO6asmit, VIf(Bf10));
    __hv_line_f(&sLine_p05MInlQ, VOf(Bf10));
    __hv_phasor_f(&sPhasor_Zd5eAN7U, VIf(Bf10), VOf(Bf10));
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
    __hv_line_f(&sLine_lPV7LxmL, VOf(Bf2));
    __hv_line_f(&sLine_7sgXNfJA, VOf(Bf3));
    __hv_fma_f(VIf(Bf10), VIf(Bf2), VIf(Bf3), VOf(Bf0));
    __hv_tabhead_f(&sTabhead_ueE0lkxZ, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_by1vll3K, VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_RtOlYvmY, VOf(Bf0));
    __hv_min_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf9));
    __hv_varread_f(&sVarf_LQt8CfLM, VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_oJ2OntoU, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_fiDUreYE, VIi(Bi0), VOf(Bf0));
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
    __hv_tabhead_f(&sTabhead_ySl3IAMs, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf10), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_PzrJFW3F, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_eqaZ4nfi, VOf(Bf3));
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf10));
    __hv_varread_f(&sVarf_7AraMLj0, VOf(Bf3));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_g9i34wPG, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_yVxAWfh3, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf1), VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_cTNm0UNL, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_Ozvdazik, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_AGSmbZFU, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_5b1lNuYl, VOf(Bf0));
    __hv_min_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_27qYBP8n, VOf(Bf0));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_HIdKTKZO, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_LZGtpteI, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf10));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf10), VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_O3irMjca, VOf(Bf15));
    __hv_rpole_f(&sRPole_QoMjxTEE, VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_0dKfSLUi, VIf(Bf15), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_dfZLNOUp, VOf(Bf15));
    __hv_mul_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_ZaU6HlVU, VOf(Bf0));
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf15));
    __hv_line_f(&sLine_3juLZgyV, VOf(Bf10));
    __hv_varread_f(&sVarf_uR73kTj8, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_XLsvwfIe, VOf(Bf0));
    __hv_rpole_f(&sRPole_NQ0jUhW8, VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_6Pfb0x1G, VIf(Bf0));
    __hv_var_k_f(VOf(Bf0), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf14), VIf(Bf0), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_BMCnp3ik, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_7SwZS8xB, VOf(Bf11));
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

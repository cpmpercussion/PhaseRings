/** Copyright (c) 2026 Charles Martin. Generated from Pure Data by hvcc (https://github.com/Wasted-Audio/hvcc). */

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
  numBytes += sRPole_init(&sRPole_sIlLZ2Jb);
  numBytes += sDel1_init(&sDel1_nLdCSapK);
  numBytes += sSamphold_init(&sSamphold_EbNxg2RQ);
  numBytes += sDel1_init(&sDel1_AmBhvPw5);
  numBytes += sSamphold_init(&sSamphold_yGLdZF21);
  numBytes += sTabread_init(&sTabread_uoVitgdD, &hTable_qCRct5qM, false);
  numBytes += sTabread_init(&sTabread_nR7byq0M, &hTable_qCRct5qM, false);
  numBytes += sDel1_init(&sDel1_43JDE4a4);
  numBytes += sSamphold_init(&sSamphold_WiZ1kBrl);
  numBytes += sDel1_init(&sDel1_RhbxGUa8);
  numBytes += sSamphold_init(&sSamphold_6CIVD5wv);
  numBytes += sTabread_init(&sTabread_5KCCOz2X, &hTable_qCRct5qM, false);
  numBytes += sTabread_init(&sTabread_295w2nnC, &hTable_qCRct5qM, false);
  numBytes += sPhasor_k_init(&sPhasor_1D1xK21R, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_dbMqk2ue);
  numBytes += sDel1_init(&sDel1_tPNlaYOT);
  numBytes += sLine_init(&sLine_wxvWQs39);
  numBytes += sSample_init(&sSample_ntTgnqU2);
  numBytes += sLine_init(&sLine_bshnaGSq);
  numBytes += sTabread_init(&sTabread_9XM6QKta, &hTable_xEg61Afi, false);
  numBytes += sTabread_init(&sTabread_8ScqbFZc, &hTable_xEg61Afi, false);
  numBytes += sLine_init(&sLine_lC2ECPMD);
  numBytes += sLine_init(&sLine_Go9WbMt2);
  numBytes += sLine_init(&sLine_i32PJq3G);
  numBytes += sLine_init(&sLine_2JtmVX3L);
  numBytes += sLine_init(&sLine_U11ucE0N);
  numBytes += sTabread_init(&sTabread_d1DBYHps, &hTable_U3sU2Iw3, false);
  numBytes += sTabread_init(&sTabread_4S6pd9SU, &hTable_U3sU2Iw3, false);
  numBytes += sLine_init(&sLine_qWnocqeu);
  numBytes += sLine_init(&sLine_gfJzJeYK);
  numBytes += sLine_init(&sLine_zUdbyos4);
  numBytes += sLine_init(&sLine_mDDzoF84);
  numBytes += sLine_init(&sLine_Ok9RA0ft);
  numBytes += sTabread_init(&sTabread_4jFfPfJk, &hTable_0mdXHtxw, false);
  numBytes += sTabread_init(&sTabread_FVl715Ig, &hTable_0mdXHtxw, false);
  numBytes += sLine_init(&sLine_aQpkjbES);
  numBytes += sLine_init(&sLine_AxbOM8g4);
  numBytes += sLine_init(&sLine_nGnRmxH5);
  numBytes += sLine_init(&sLine_CJoqj8i6);
  numBytes += sLine_init(&sLine_BDU8QKHK);
  numBytes += sTabread_init(&sTabread_WMooWWa7, &hTable_jVvlKWLF, false);
  numBytes += sTabread_init(&sTabread_gu9QeQkc, &hTable_jVvlKWLF, false);
  numBytes += sLine_init(&sLine_tcjIz412);
  numBytes += sLine_init(&sLine_gmsgGRvV);
  numBytes += sLine_init(&sLine_93JHr555);
  numBytes += sLine_init(&sLine_M3QAuhSI);
  numBytes += sLine_init(&sLine_1KwlxQbV);
  numBytes += sLine_init(&sLine_oZmQ27Ed);
  numBytes += sLine_init(&sLine_hdNjQ4Sw);
  numBytes += sLine_init(&sLine_hzLthO4d);
  numBytes += sLine_init(&sLine_P3iOl8Jo);
  numBytes += sTabwrite_init(&sTabwrite_S3C7AJOw, &hTable_K7TEiO1b);
  numBytes += sLine_init(&sLine_3uIgCiqW);
  numBytes += sPhasor_init(&sPhasor_vS5B2jzl, sampleRate);
  numBytes += sLine_init(&sLine_v70FQxyK);
  numBytes += sLine_init(&sLine_0z4wRBQN);
  numBytes += sTabhead_init(&sTabhead_N5udHe0x, &hTable_K7TEiO1b);
  numBytes += sTabread_init(&sTabread_cNijK1bp, &hTable_K7TEiO1b, false);
  numBytes += sTabread_init(&sTabread_pFj9k7Th, &hTable_K7TEiO1b, false);
  numBytes += sTabhead_init(&sTabhead_58QuyfhE, &hTable_K7TEiO1b);
  numBytes += sTabread_init(&sTabread_71m0RMIc, &hTable_K7TEiO1b, false);
  numBytes += sTabread_init(&sTabread_6aN6yCYZ, &hTable_K7TEiO1b, false);
  numBytes += sTabhead_init(&sTabhead_WDmJfo2K, &hTable_eqIUvePK);
  numBytes += sTabread_init(&sTabread_E3sScKlT, &hTable_eqIUvePK, false);
  numBytes += sTabread_init(&sTabread_FXu1Jn8L, &hTable_eqIUvePK, false);
  numBytes += sRPole_init(&sRPole_nnOieFj3);
  numBytes += sDel1_init(&sDel1_LmksYKL2);
  numBytes += sLine_init(&sLine_Qoni9Jxq);
  numBytes += sRPole_init(&sRPole_iUpdm8EL);
  numBytes += sTabwrite_init(&sTabwrite_0t0DFWPC, &hTable_eqIUvePK);
  numBytes += sTabread_init(&sTabread_CeeGY1XF, &hTable_UjiZIBVs, true);
  numBytes += sRPole_init(&sRPole_bJ3hUtuB);
  numBytes += sLine_init(&sLine_SHoCFhFD);
  numBytes += sLine_init(&sLine_dJqq3XCk);
  numBytes += sTabread_init(&sTabread_skrQgTu2, &hTable_GNDU06Rg, true);
  numBytes += sTabread_init(&sTabread_OTRfYaXU, &hTable_jyI9ewhb, true);
  numBytes += sTabread_init(&sTabread_FTyvzgHR, &hTable_Ju3BKALx, true);
  numBytes += sTabread_init(&sTabread_H9bw0qaf, &hTable_OMXsco6t, true);
  numBytes += sTabread_init(&sTabread_Ugbd5hyq, &hTable_ht2IgTgH, true);
  numBytes += sTabwrite_init(&sTabwrite_mwTuQgYl, &hTable_gRCFkes3);
  numBytes += sTabwrite_init(&sTabwrite_Yk4nFHM7, &hTable_ht2IgTgH);
  numBytes += sTabwrite_init(&sTabwrite_ZvPOLZEn, &hTable_OMXsco6t);
  numBytes += sTabwrite_init(&sTabwrite_QgBfBLlZ, &hTable_Ju3BKALx);
  numBytes += sTabwrite_init(&sTabwrite_9t4zc6T8, &hTable_jyI9ewhb);
  numBytes += sTabwrite_init(&sTabwrite_ET7OwVWI, &hTable_GNDU06Rg);
  numBytes += sTabread_init(&sTabread_ZhvN7uYw, &hTable_gRCFkes3, true);
  numBytes += sTabread_init(&sTabread_6q3SWtFH, &hTable_D1GqFIK5, true);
  numBytes += sRPole_init(&sRPole_A4Xv7Zo1);
  numBytes += sTabread_init(&sTabread_jqylowgB, &hTable_knNOXmUv, true);
  numBytes += sRPole_init(&sRPole_PotX8x7U);
  numBytes += sTabread_init(&sTabread_Ep1qFV0s, &hTable_9xd8fRNK, true);
  numBytes += sRPole_init(&sRPole_HaFreODy);
  numBytes += sTabwrite_init(&sTabwrite_8v2c4aZz, &hTable_UjiZIBVs);
  numBytes += sTabwrite_init(&sTabwrite_o7YBXfC9, &hTable_D1GqFIK5);
  numBytes += sTabwrite_init(&sTabwrite_5cCbnJyF, &hTable_knNOXmUv);
  numBytes += sTabwrite_init(&sTabwrite_lMtm8tzT, &hTable_9xd8fRNK);
  numBytes += sLine_init(&sLine_Pbc8ILGk);
  numBytes += sLine_init(&sLine_roxhzoG3);
  numBytes += sTabwrite_init(&sTabwrite_gxG0BJ0g, &hTable_izH9V5L1);
  numBytes += sLine_init(&sLine_ntJBN5QW);
  numBytes += sPhasor_init(&sPhasor_CpE4540y, sampleRate);
  numBytes += sLine_init(&sLine_XV7Geksf);
  numBytes += sLine_init(&sLine_7KmBqBtm);
  numBytes += sTabhead_init(&sTabhead_1JVrFJZM, &hTable_izH9V5L1);
  numBytes += sTabread_init(&sTabread_9El8zARY, &hTable_izH9V5L1, false);
  numBytes += sTabread_init(&sTabread_Y9u7fvuc, &hTable_izH9V5L1, false);
  numBytes += sTabhead_init(&sTabhead_kYzgects, &hTable_izH9V5L1);
  numBytes += sTabread_init(&sTabread_fekFvy4U, &hTable_izH9V5L1, false);
  numBytes += sTabread_init(&sTabread_pWsD6Fxx, &hTable_izH9V5L1, false);
  numBytes += sTabhead_init(&sTabhead_PlgIfYRx, &hTable_hHg41gz0);
  numBytes += sTabread_init(&sTabread_BBesFFvl, &hTable_hHg41gz0, false);
  numBytes += sTabread_init(&sTabread_ClZpa9MR, &hTable_hHg41gz0, false);
  numBytes += sRPole_init(&sRPole_Lf9VbD70);
  numBytes += sDel1_init(&sDel1_RygAHqLZ);
  numBytes += sLine_init(&sLine_nVT6bU5D);
  numBytes += sRPole_init(&sRPole_GbSywDgp);
  numBytes += sTabwrite_init(&sTabwrite_4RQPOxik, &hTable_hHg41gz0);
  numBytes += sCPole_init(&sCPole_FeYd7row);
  numBytes += sRPole_init(&sRPole_h2bBvM6v);
  numBytes += sRPole_init(&sRPole_ucX2rnGk);
  numBytes += sRPole_init(&sRPole_ChaZ5mzW);
  numBytes += sTabread_init(&sTabread_0KuezqPO, &hTable_EBD5gUKK, true);
  numBytes += sRPole_init(&sRPole_nmWcpXyU);
  numBytes += sLine_init(&sLine_HLlHtEJM);
  numBytes += sLine_init(&sLine_GZaKiYhY);
  numBytes += sTabread_init(&sTabread_sjeac2xu, &hTable_UPXYUY4s, true);
  numBytes += sTabread_init(&sTabread_FVhGrixi, &hTable_BNW0HdKo, true);
  numBytes += sTabread_init(&sTabread_OFqKjXTX, &hTable_1m8RHnde, true);
  numBytes += sTabread_init(&sTabread_mlFLAfJ2, &hTable_k6Ho7LFE, true);
  numBytes += sTabread_init(&sTabread_SEzZpQLS, &hTable_EFJH7DGe, true);
  numBytes += sTabwrite_init(&sTabwrite_cXP0kBkY, &hTable_TSvwyWQf);
  numBytes += sTabwrite_init(&sTabwrite_J5tLNS4a, &hTable_EFJH7DGe);
  numBytes += sTabwrite_init(&sTabwrite_8MKKfEgy, &hTable_k6Ho7LFE);
  numBytes += sTabwrite_init(&sTabwrite_n1McHLWQ, &hTable_1m8RHnde);
  numBytes += sTabwrite_init(&sTabwrite_ZJbanhll, &hTable_BNW0HdKo);
  numBytes += sTabwrite_init(&sTabwrite_ZvnOmipx, &hTable_UPXYUY4s);
  numBytes += sTabread_init(&sTabread_Gc0cm6Ig, &hTable_TSvwyWQf, true);
  numBytes += sTabread_init(&sTabread_iO89QDof, &hTable_zllsqs6M, true);
  numBytes += sRPole_init(&sRPole_JWK4aDmI);
  numBytes += sTabread_init(&sTabread_HycPhAxU, &hTable_gGlQYkbV, true);
  numBytes += sRPole_init(&sRPole_ujRzsf9H);
  numBytes += sTabread_init(&sTabread_4OsSDFlz, &hTable_0njfSoys, true);
  numBytes += sRPole_init(&sRPole_8lUqnb0V);
  numBytes += sTabwrite_init(&sTabwrite_2jjdXLe3, &hTable_EBD5gUKK);
  numBytes += sTabwrite_init(&sTabwrite_xFsOokez, &hTable_zllsqs6M);
  numBytes += sTabwrite_init(&sTabwrite_ZD2F13PD, &hTable_gGlQYkbV);
  numBytes += sTabwrite_init(&sTabwrite_Ap00FIMe, &hTable_0njfSoys);
  numBytes += sLine_init(&sLine_QiB1pTIW);
  numBytes += sLine_init(&sLine_NbhbPUXc);
  numBytes += sLine_init(&sLine_tsOApumz);
  numBytes += cVar_init_s(&cVar_P88YlK88, "floatatom");
  numBytes += cVar_init_f(&cVar_kQoa8PP9, 98.0f);
  numBytes += cIf_init(&cIf_n0Ip2sbU, false);
  numBytes += cBinop_init(&cBinop_blZ4M306, 0.0f); // __pow
  numBytes += cPack_init(&cPack_yJNXRvEp, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_cG6hT3WO, 0.0f);
  numBytes += cRandom_init(&cRandom_sV02N5ph, 404800043);
  numBytes += cSlice_init(&cSlice_s8Pvrmn9, 1, 1);
  numBytes += cBinop_init(&cBinop_DLsO7KN5, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_ES6kMFhN, -1423054483);
  numBytes += cSlice_init(&cSlice_ShdpOGQ7, 1, 1);
  numBytes += cSlice_init(&cSlice_AqEcg7HI, 1, 1);
  numBytes += cSlice_init(&cSlice_WrxJZLUu, 0, 1);
  numBytes += cPack_init(&cPack_QGmewEDx, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_1RLZvANL, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_RuMXluFc, 0.0f);
  numBytes += cDelay_init(this, &cDelay_hyhjZKx1, 25.0f);
  numBytes += cVar_init_f(&cVar_ZHP3B7s8, 0.0f);
  numBytes += sVarf_init(&sVarf_EmKTdPIX, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_D8TlZlpG, 1.0f);
  numBytes += cVar_init_f(&cVar_2MpF5daW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XmhC29pA, 2.0f);
  numBytes += cPack_init(&cPack_QfFpVVhK, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_X3btkr4b, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_oj9KqRPB, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_Dsg543qk, 1.0f);
  numBytes += cVar_init_s(&cVar_tCw5oTqO, "floatatom");
  numBytes += cVar_init_f(&cVar_QvJMmxZr, 0.0f);
  numBytes += cVar_init_f(&cVar_NxC9tGxB, 1.0f);
  numBytes += cBinop_init(&cBinop_US9vdtNY, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_Q7S2u50f, 1, 1);
  numBytes += cSlice_init(&cSlice_VqTUo9Yg, 0, 1);
  numBytes += cVar_init_s(&cVar_qXi0I8E2, "1013_default");
  numBytes += cSlice_init(&cSlice_MxVInVIU, 1, 1);
  numBytes += sVarf_init(&sVarf_83HBdz9x, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_R127Hope, 1, 1);
  numBytes += cSlice_init(&cSlice_t64pF7TK, 0, 1);
  numBytes += cVar_init_s(&cVar_r9Fp2IuY, "floatatom");
  numBytes += cVar_init_s(&cVar_FXBdSD4F, "floatatom");
  numBytes += hTable_init(&hTable_xEg61Afi, 1000);
  numBytes += cSlice_init(&cSlice_JnoMtmrK, 1, 1);
  numBytes += cSlice_init(&cSlice_tsaPX2tq, 0, 1);
  numBytes += cVar_init_f(&cVar_5cMyjGtA, 0.0f);
  numBytes += cPack_init(&cPack_5MRRJafa, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_UKpQMG7B, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_UGVI9N2W, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_XM0v7KTR, 2099599366);
  numBytes += cSlice_init(&cSlice_ESafPGfa, 1, 1);
  numBytes += cBinop_init(&cBinop_RbQQ3r76, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_PwCC5M7f, -1725037840);
  numBytes += cSlice_init(&cSlice_a5QztG4z, 1, 1);
  numBytes += cSlice_init(&cSlice_xXeThES9, 1, 1);
  numBytes += cSlice_init(&cSlice_9RUinkdv, 0, 1);
  numBytes += cPack_init(&cPack_FWLkbOuG, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_9SirQ00V, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_F81RJd5r, 0.0f);
  numBytes += cDelay_init(this, &cDelay_27hs3a7c, 25.0f);
  numBytes += cVar_init_f(&cVar_t9PqkuTd, 0.0f);
  numBytes += sVarf_init(&sVarf_mtUHI40x, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YUmIDyGj, 1.0f);
  numBytes += cVar_init_f(&cVar_pc3WVmEH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rfOEJQvE, 2.0f);
  numBytes += cPack_init(&cPack_JyiTe2Xq, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_MLRsfLKe, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_qlGPg64h, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_XXiXO54d, 1.0f);
  numBytes += cVar_init_s(&cVar_Gqt66BBj, "floatatom");
  numBytes += cVar_init_f(&cVar_rJTmnT3h, 0.0f);
  numBytes += cVar_init_f(&cVar_eNy2dSLF, 1.0f);
  numBytes += cBinop_init(&cBinop_HVHhJbjN, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_3JCWLS5B, 1, 1);
  numBytes += cSlice_init(&cSlice_GBJQ6j0J, 0, 1);
  numBytes += cVar_init_s(&cVar_w2BCu1qI, "1051_default");
  numBytes += cSlice_init(&cSlice_dnIcq2Yc, 1, 1);
  numBytes += sVarf_init(&sVarf_dLeAuaZe, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_kvSn1A0I, 1, 1);
  numBytes += cSlice_init(&cSlice_6Xso5zkv, 0, 1);
  numBytes += cVar_init_s(&cVar_THWFUvhp, "floatatom");
  numBytes += cVar_init_s(&cVar_F8Qa31lk, "floatatom");
  numBytes += hTable_init(&hTable_U3sU2Iw3, 1000);
  numBytes += cSlice_init(&cSlice_ObW7Zmap, 1, 1);
  numBytes += cSlice_init(&cSlice_dbfBMFwJ, 0, 1);
  numBytes += cVar_init_f(&cVar_cEfn3tIf, 0.0f);
  numBytes += cPack_init(&cPack_1xGIIDOG, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_fBjFxI45, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_W7bXoNKU, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_h27hpwIo, -1880504996);
  numBytes += cSlice_init(&cSlice_pL2zi25Q, 1, 1);
  numBytes += cBinop_init(&cBinop_sxwm8QAk, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_Hva4Yho5, 1549632996);
  numBytes += cSlice_init(&cSlice_mXanyIJw, 1, 1);
  numBytes += cSlice_init(&cSlice_VmZTvyPU, 1, 1);
  numBytes += cSlice_init(&cSlice_Bbj83fS7, 0, 1);
  numBytes += cPack_init(&cPack_JFIYirYa, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_IjwcsqCR, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_X7BB0wu9, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1GwNIvSc, 25.0f);
  numBytes += cVar_init_f(&cVar_63kvqkqt, 0.0f);
  numBytes += sVarf_init(&sVarf_AlehJ60r, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_n0b26JwE, 1.0f);
  numBytes += cVar_init_f(&cVar_PLMaCEYq, 0.0f);
  numBytes += cDelay_init(this, &cDelay_atebVVSk, 2.0f);
  numBytes += cPack_init(&cPack_BWHF5MJh, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_hy0J4TgP, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_zbFWUIDP, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_KXLPSpMn, 1.0f);
  numBytes += cVar_init_s(&cVar_BlGafgTP, "floatatom");
  numBytes += cVar_init_f(&cVar_9klJnaqK, 0.0f);
  numBytes += cVar_init_f(&cVar_eUFAdLb8, 1.0f);
  numBytes += cBinop_init(&cBinop_pjH0kNfb, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_UXJNWzdj, 1, 1);
  numBytes += cSlice_init(&cSlice_skka8Zv0, 0, 1);
  numBytes += cVar_init_s(&cVar_PHKSKwVQ, "1089_default");
  numBytes += cSlice_init(&cSlice_vcICZ9mP, 1, 1);
  numBytes += sVarf_init(&sVarf_P78MKYz3, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_8o3gCmNK, 1, 1);
  numBytes += cSlice_init(&cSlice_xGE9d15I, 0, 1);
  numBytes += cVar_init_s(&cVar_Rotxd0t5, "floatatom");
  numBytes += cVar_init_s(&cVar_vLI3n0A5, "floatatom");
  numBytes += hTable_init(&hTable_0mdXHtxw, 1000);
  numBytes += cSlice_init(&cSlice_rLHxdbD2, 1, 1);
  numBytes += cSlice_init(&cSlice_YppFmsSB, 0, 1);
  numBytes += cVar_init_f(&cVar_sxfPugwM, 0.0f);
  numBytes += cPack_init(&cPack_oSONyWSg, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_TAAYF05M, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_ygGHsxHX, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_BO9UesL0, -326496255);
  numBytes += cSlice_init(&cSlice_NRgFdvLB, 1, 1);
  numBytes += cBinop_init(&cBinop_SX76QCve, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_fFSxOQSF, 1495532482);
  numBytes += cSlice_init(&cSlice_LKT351nG, 1, 1);
  numBytes += cSlice_init(&cSlice_rsDXauvo, 1, 1);
  numBytes += cSlice_init(&cSlice_aqLi8ka9, 0, 1);
  numBytes += cPack_init(&cPack_RU8KL3xi, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_erTMuVi7, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_vmGPbRTy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TDeEVUPs, 25.0f);
  numBytes += cVar_init_f(&cVar_EIEqZAe3, 0.0f);
  numBytes += sVarf_init(&sVarf_SO8l3Oh9, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_PWnKdFrp, 1.0f);
  numBytes += cVar_init_f(&cVar_vZz5B9N8, 0.0f);
  numBytes += cDelay_init(this, &cDelay_npkoKPBI, 2.0f);
  numBytes += cPack_init(&cPack_ru3uoepH, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_BgvIxzDi, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_7VIja7HJ, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_Ax4gUyRl, 1.0f);
  numBytes += cVar_init_s(&cVar_PzSV62m9, "floatatom");
  numBytes += cVar_init_f(&cVar_cDkZlO3V, 0.0f);
  numBytes += cVar_init_f(&cVar_p2f0YxUH, 1.0f);
  numBytes += cBinop_init(&cBinop_doxBZR3E, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_mcLw3GzN, 1, 1);
  numBytes += cSlice_init(&cSlice_9hUSzuwM, 0, 1);
  numBytes += cVar_init_s(&cVar_Y5ESACwB, "1127_default");
  numBytes += cSlice_init(&cSlice_iEBOIu7j, 1, 1);
  numBytes += sVarf_init(&sVarf_6bjjo3r0, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_Uz3pjaUt, 1, 1);
  numBytes += cSlice_init(&cSlice_udyLEGZq, 0, 1);
  numBytes += cVar_init_s(&cVar_Bj0HBwNQ, "floatatom");
  numBytes += cVar_init_s(&cVar_D4xAr9cd, "floatatom");
  numBytes += hTable_init(&hTable_jVvlKWLF, 1000);
  numBytes += cSlice_init(&cSlice_S0trZtkc, 1, 1);
  numBytes += cSlice_init(&cSlice_BWqIF8KM, 0, 1);
  numBytes += cVar_init_f(&cVar_eis14qJ6, 0.0f);
  numBytes += cPack_init(&cPack_c0UiJcg3, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_VOBxe9YO, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_Tgp3hZRK, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_cxUxo8lC, 98.0f);
  numBytes += cIf_init(&cIf_bmn7rqIG, false);
  numBytes += cBinop_init(&cBinop_tWVarhvR, 0.0f); // __pow
  numBytes += cPack_init(&cPack_rRC9jwKQ, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_dfBoi07G, 0.0f);
  numBytes += cVar_init_f(&cVar_MuBnRqAH, 100.0f);
  numBytes += cIf_init(&cIf_ULzDkSgu, false);
  numBytes += cBinop_init(&cBinop_0KuPH6CY, 0.0f); // __pow
  numBytes += cPack_init(&cPack_2MHE1Awc, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_uzABqCkY, 0.0f);
  numBytes += cIf_init(&cIf_VKwWbKEa, false);
  numBytes += cVar_init_f(&cVar_U6xpMsZB, 97.0f);
  numBytes += cIf_init(&cIf_eFBD3Jzu, false);
  numBytes += cBinop_init(&cBinop_yYKsYCbE, 0.0f); // __pow
  numBytes += cPack_init(&cPack_2gKaTTOz, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_0qOXdVy0, 0.0f);
  numBytes += cVar_init_f(&cVar_gKs7CXnN, 97.0f);
  numBytes += cIf_init(&cIf_nX5kkWYB, false);
  numBytes += cBinop_init(&cBinop_HvHsB6cJ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_SM02s3BG, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_NjaMqmg5, 0.0f);
  numBytes += cPack_init(&cPack_xdE3u1zg, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_wHN9EtAV, 1, 1);
  numBytes += cSlice_init(&cSlice_5elt9JrC, 0, 1);
  numBytes += cIf_init(&cIf_dLQC0HeD, false);
  numBytes += cIf_init(&cIf_yUW1B0b8, false);
  numBytes += cIf_init(&cIf_ugnvYM16, false);
  numBytes += cSlice_init(&cSlice_bxwxf15A, 1, 1);
  numBytes += cSlice_init(&cSlice_QWSprYon, 0, 1);
  numBytes += cVar_init_f(&cVar_WLApP4PJ, 0.0f);
  numBytes += cIf_init(&cIf_UOL4Bwwp, false);
  numBytes += cPack_init(&cPack_wsjhBdOP, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_Gr2pNEIp, 1, -1);
  numBytes += cSlice_init(&cSlice_3dM64Z4K, 1, -1);
  numBytes += cSlice_init(&cSlice_k39hE7Uk, 1, -1);
  numBytes += cSlice_init(&cSlice_P0MWQIwd, 1, -1);
  numBytes += cIf_init(&cIf_T9TD3aO9, false);
  numBytes += cVar_init_f(&cVar_33Ip8yHC, 1.0f);
  numBytes += cPack_init(&cPack_CdZamBkF, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_p66eTota, 0.0f);
  numBytes += hTable_init(&hTable_FXXLUP0G, 36000);
  numBytes += hTable_init(&hTable_ForqUfzu, 290000);
  numBytes += hTable_init(&hTable_7hwEo7ic, 288000);
  numBytes += hTable_init(&hTable_f3whMxOT, 66000);
  numBytes += hTable_init(&hTable_3zp5yu42, 25000);
  numBytes += hTable_init(&hTable_LnmM0L5E, 384000);
  numBytes += cSlice_init(&cSlice_9y3VeT1v, 2, 1);
  numBytes += cSlice_init(&cSlice_yjRf2i9Z, 1, 1);
  numBytes += cSlice_init(&cSlice_vyjGKfqy, 0, 1);
  numBytes += cVar_init_f(&cVar_C0sJXISA, 0.0f);
  numBytes += cIf_init(&cIf_8r2WS4Bo, false);
  numBytes += cIf_init(&cIf_0ehY9ZW2, false);
  numBytes += cIf_init(&cIf_d8awyjA6, false);
  numBytes += cIf_init(&cIf_X8wCeseb, false);
  numBytes += cIf_init(&cIf_jrCp3VKC, false);
  numBytes += cBinop_init(&cBinop_q4vUdAtL, 0.0f); // __eq
  numBytes += cRandom_init(&cRandom_ezM0nmHg, 380058527);
  numBytes += cSlice_init(&cSlice_mQ7p5DTk, 1, 1);
  numBytes += cRandom_init(&cRandom_f2xRGclQ, -19845458);
  numBytes += cSlice_init(&cSlice_uyb0fMum, 1, 1);
  numBytes += cRandom_init(&cRandom_0yY5gdVS, -1563743457);
  numBytes += cSlice_init(&cSlice_qNCqVpX0, 1, 1);
  numBytes += cVar_init_s(&cVar_gDEt4Mmh, "floatatom");
  numBytes += cPack_init(&cPack_CUl2rfqm, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_6dpfoX4X, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_OMuLjoBY, "floatatom");
  numBytes += cDelay_init(this, &cDelay_buv04Lr6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_LniaDFXE, 0.0f);
  numBytes += hTable_init(&hTable_K7TEiO1b, 256);
  numBytes += cVar_init_s(&cVar_CJXESJkC, "del-1228-del");
  numBytes += sVarf_init(&sVarf_I8Mf5LjP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ed1QnKWf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1LDhi1ch, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_BT9w3UQi, "del-1228-del");
  numBytes += sVarf_init(&sVarf_CXFokFf0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3dLSUVXI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7ATy5vzG, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_VfY5Xo0y, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_ZQ4urXOr, "del-1257-del1");
  numBytes += sVarf_init(&sVarf_tx7hrITJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YxdX9ZsG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KjAc0sTL, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_QNuYKa7Y, 10000.0f);
  numBytes += cBinop_init(&cBinop_ulHQ8uM4, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_FJaT9mYd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GOqgKqdf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_y6fM4WkY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_QRJf8WjN, 10.0f);
  numBytes += cBinop_init(&cBinop_sIymYMAf, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_pBglXIVS, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_pSJs2uvC, "floatatom");
  numBytes += sVarf_init(&sVarf_Crsreo61, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_VDIOx8jf, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ksLyjHSh, 0.0f);
  numBytes += hTable_init(&hTable_eqIUvePK, 256);
  numBytes += sVarf_init(&sVarf_MbFKhnD4, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_eV67LC8l, "floatatom");
  numBytes += cDelay_init(this, &cDelay_GNKz83J4, 0.0f);
  numBytes += cVar_init_f(&cVar_EXFnbPJ6, 20.0f);
  numBytes += cBinop_init(&cBinop_4o6masnk, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_UuaC7jLP, 0.0f);
  numBytes += cSlice_init(&cSlice_4scMjCeG, 1, -1);
  numBytes += cSlice_init(&cSlice_LRxFIiDR, 1, -1);
  numBytes += cVar_init_f(&cVar_MTkXttpv, 0.0f);
  numBytes += cVar_init_f(&cVar_f6GzgwOQ, 20.0f);
  numBytes += cVar_init_f(&cVar_LKwaZIHV, 0.0f);
  numBytes += cVar_init_f(&cVar_abD11DrU, 0.0f);
  numBytes += cVar_init_f(&cVar_Linntcwq, 0.0f);
  numBytes += cSlice_init(&cSlice_isVzY7aE, 1, 1);
  numBytes += cSlice_init(&cSlice_9EO51Rho, 0, 1);
  numBytes += cBinop_init(&cBinop_Hy0z9Ejg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_XnACu4g8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VL5qgaZv, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Twcld0nY, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Y6wiEZ4m, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_Btv0Rmwe, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_umtmiGU4, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_hDYqd8Cz, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_D8UH934p, "floatatom");
  numBytes += cPack_init(&cPack_mLkWrJdP, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_uudH95Vl, 0.0f);
  numBytes += cVar_init_f(&cVar_unCIxqAN, 20.0f);
  numBytes += cBinop_init(&cBinop_6ocse1Zh, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_R93qHwjB, 0.0f);
  numBytes += cSlice_init(&cSlice_mwvI0oFD, 1, -1);
  numBytes += cSlice_init(&cSlice_LxqvU5qK, 1, -1);
  numBytes += cVar_init_f(&cVar_PrgKIapZ, 0.0f);
  numBytes += cVar_init_f(&cVar_iipwD4Jl, 20.0f);
  numBytes += cVar_init_f(&cVar_mpCd3GTM, 0.0f);
  numBytes += cVar_init_f(&cVar_bUox8CFc, 0.0f);
  numBytes += cVar_init_f(&cVar_4fo7fOS6, 0.0f);
  numBytes += cSlice_init(&cSlice_vPuDt3So, 1, 1);
  numBytes += cSlice_init(&cSlice_zQzMYxP2, 0, 1);
  numBytes += cBinop_init(&cBinop_dbbRUgvO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_R4jHGI2A, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hBBjVAGG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_h0cTks0X, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dK1N1w9Y, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_suecRVFC, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_7huPXr0Z, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Dj1S2fBG, 0.0f); // __sub
  numBytes += cPack_init(&cPack_4QnWFvXF, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_KDnQfsTC, 2, 0.0f, 1000.0f);
  numBytes += cTabhead_init(&cTabhead_dQGV4TaD, &hTable_UjiZIBVs);
  numBytes += cVar_init_s(&cVar_5RS8xrjj, "del-1318-del1");
  numBytes += cDelay_init(this, &cDelay_JNZtsWii, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_I1kvxluK, 0.0f);
  numBytes += cBinop_init(&cBinop_ehufyXT3, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_FJNV0H6g, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_f9XpTJXV, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ve2xb27t, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_zkwkMx3i, &hTable_D1GqFIK5);
  numBytes += cVar_init_s(&cVar_8eGRysGs, "del-1318-del2");
  numBytes += cDelay_init(this, &cDelay_Wwm7gF6S, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_zuQbSjdT, 0.0f);
  numBytes += cBinop_init(&cBinop_CU47I9DA, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_4ExBDYEx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_114RcGBk, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Js6fpVvh, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_5YB6GLd8, &hTable_knNOXmUv);
  numBytes += cVar_init_s(&cVar_SUKx77xc, "del-1318-del3");
  numBytes += cDelay_init(this, &cDelay_oVT3ZNfW, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_n9ctqXcA, 0.0f);
  numBytes += cBinop_init(&cBinop_NsxL0LzL, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_R8pEqlxI, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_74Yd35IR, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_gfAr8rpm, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_YtVtkXvw, &hTable_9xd8fRNK);
  numBytes += cVar_init_s(&cVar_x74XdEp4, "del-1318-del4");
  numBytes += cDelay_init(this, &cDelay_khKRaQhX, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_Rxv8zB7v, 0.0f);
  numBytes += cBinop_init(&cBinop_U5abW7FX, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_HwFNqzoM, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_uyo4czoO, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_hplxNKla, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Tqwgio90, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4DwWMZo2, 0.0f);
  numBytes += hTable_init(&hTable_UjiZIBVs, 256);
  numBytes += cDelay_init(this, &cDelay_ZKYfhAra, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8oqcSq0s, 0.0f);
  numBytes += hTable_init(&hTable_D1GqFIK5, 256);
  numBytes += cDelay_init(this, &cDelay_c411uXj1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XbNkKRAM, 0.0f);
  numBytes += hTable_init(&hTable_knNOXmUv, 256);
  numBytes += cDelay_init(this, &cDelay_v8dA0fYx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_fxj5kpf4, 0.0f);
  numBytes += hTable_init(&hTable_9xd8fRNK, 256);
  numBytes += cIf_init(&cIf_vyOfrXzD, false);
  numBytes += cBinop_init(&cBinop_yCRLePmM, 0.0f); // __pow
  numBytes += cPack_init(&cPack_1QQab4Yq, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_BgmuUnR8, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_BBEk2wpJ, 22050.0f);
  numBytes += cBinop_init(&cBinop_aULWWp7J, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_jF1QO3XA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KwH7uPdq, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_72epLU0S, 95.0f);
  numBytes += cVar_init_f(&cVar_m3zpkrFO, 90.0f);
  numBytes += cVar_init_f(&cVar_qHNmWRHw, 6000.0f);
  numBytes += cVar_init_f(&cVar_9Lf5p4hx, 60.0f);
  numBytes += cIf_init(&cIf_WBJA7XDb, false);
  numBytes += cTabhead_init(&cTabhead_IdTyyQqV, &hTable_gRCFkes3);
  numBytes += cVar_init_s(&cVar_nA588aRO, "del-1318-ref6");
  numBytes += cDelay_init(this, &cDelay_rt118rBW, 13.645f);
  numBytes += cDelay_init(this, &cDelay_PQ2YbLFx, 0.0f);
  numBytes += cBinop_init(&cBinop_K5uJbQkI, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_RRVSYrRz, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3LsqehjA, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_IwsqXvWO, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_JGo6XOn3, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3CK3mcLI, 0.0f);
  numBytes += hTable_init(&hTable_gRCFkes3, 256);
  numBytes += cTabhead_init(&cTabhead_T5kxR6Bj, &hTable_ht2IgTgH);
  numBytes += cVar_init_s(&cVar_aJBko5Hj, "del-1318-ref5");
  numBytes += cDelay_init(this, &cDelay_bHRDsWLt, 16.364f);
  numBytes += cDelay_init(this, &cDelay_wfF6RhJO, 0.0f);
  numBytes += cBinop_init(&cBinop_8f0fjtST, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_41csDtlr, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_sxJT4RrV, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_SEEB5F0u, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_7JH0YH4s, 0.0f);
  numBytes += cDelay_init(this, &cDelay_a1AzfBlj, 0.0f);
  numBytes += hTable_init(&hTable_ht2IgTgH, 256);
  numBytes += cTabhead_init(&cTabhead_SorZQocM, &hTable_OMXsco6t);
  numBytes += cVar_init_s(&cVar_3fu5Vlkm, "del-1318-ref4");
  numBytes += cDelay_init(this, &cDelay_ccRbj4Le, 19.392f);
  numBytes += cDelay_init(this, &cDelay_Fzfjgn51, 0.0f);
  numBytes += cBinop_init(&cBinop_Dp3IGlxb, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_vmEytyx5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_oDRtib9r, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_R8ThyE2P, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_xMnAsw6c, 0.0f);
  numBytes += cDelay_init(this, &cDelay_KYK3PRY1, 0.0f);
  numBytes += hTable_init(&hTable_OMXsco6t, 256);
  numBytes += cTabhead_init(&cTabhead_7UcD3OfN, &hTable_Ju3BKALx);
  numBytes += cVar_init_s(&cVar_F9Z5vpqn, "del-1318-ref3");
  numBytes += cDelay_init(this, &cDelay_QnO70ba6, 25.796f);
  numBytes += cDelay_init(this, &cDelay_G8c3IoqM, 0.0f);
  numBytes += cBinop_init(&cBinop_iOQ900yN, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_IfokH60z, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_agKtreAN, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_kY9ptTMh, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_MDrUqwwF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_m8ZXNig2, 0.0f);
  numBytes += hTable_init(&hTable_Ju3BKALx, 256);
  numBytes += cTabhead_init(&cTabhead_H0Fjzoxy, &hTable_jyI9ewhb);
  numBytes += cVar_init_s(&cVar_fbBmbnAL, "del-1318-ref2");
  numBytes += cDelay_init(this, &cDelay_zTybHyKV, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_wT2pqzMd, 0.0f);
  numBytes += cBinop_init(&cBinop_WysZM2m4, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_aw9U5yzW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_tqVoNdlE, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_f9NnUgUT, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_gAlVUM6K, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1vG232Ml, 0.0f);
  numBytes += hTable_init(&hTable_jyI9ewhb, 256);
  numBytes += cTabhead_init(&cTabhead_faczOfG2, &hTable_GNDU06Rg);
  numBytes += cVar_init_s(&cVar_dLQB0ucx, "del-1318-ref1");
  numBytes += cDelay_init(this, &cDelay_Ju3PFahR, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_EVAHQijx, 0.0f);
  numBytes += cBinop_init(&cBinop_Za8djoPY, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_Xn2ywXmg, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_70MY1T46, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_m3hlRMCw, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_eDyvXre5, 0.0f);
  numBytes += cDelay_init(this, &cDelay_PD0RoIoA, 0.0f);
  numBytes += hTable_init(&hTable_GNDU06Rg, 256);
  numBytes += cVar_init_f(&cVar_Db5opZ2x, 0.0f);
  numBytes += cVar_init_f(&cVar_0BwSej3D, 0.0f);
  numBytes += cPack_init(&cPack_qss04jOS, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_amsna2uF, 22050.0f);
  numBytes += cBinop_init(&cBinop_P5pszdP0, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ajAz2Xlp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_un1g1d0O, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8y9geDsc, 22050.0f);
  numBytes += cBinop_init(&cBinop_dt76G4V4, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_u1QcfUtf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_E5Wh7Xmx, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8lbhnd7G, 22050.0f);
  numBytes += cBinop_init(&cBinop_egWLjvgg, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dEVXdxYr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_g0tWhXk8, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_0ZeYgSOW, 100.0f);
  numBytes += cIf_init(&cIf_CxlZnwxy, false);
  numBytes += cBinop_init(&cBinop_e4be25pe, 0.0f); // __pow
  numBytes += cPack_init(&cPack_4fS6tWh4, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_Rd9Febm6, 0.0f);
  numBytes += cIf_init(&cIf_lvDbudZ3, false);
  numBytes += cIf_init(&cIf_NQbHl05N, false);
  numBytes += cDelay_init(this, &cDelay_DJ7jWdDK, 50.0f);
  numBytes += cVar_init_f(&cVar_cUziBdZk, 0.0f);
  numBytes += cVar_init_f(&cVar_5qTMHlsd, 12.0f);
  numBytes += cVar_init_s(&cVar_WmKlvB2M, "floatatom");
  numBytes += cPack_init(&cPack_HndFaBJZ, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_G8N8CuMQ, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_GeUdY93B, "floatatom");
  numBytes += cDelay_init(this, &cDelay_HkLcu35D, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iBr59nYr, 0.0f);
  numBytes += hTable_init(&hTable_izH9V5L1, 256);
  numBytes += cVar_init_s(&cVar_WKLIB3Ca, "del-1436-del");
  numBytes += sVarf_init(&sVarf_MlqBeba3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MzWkkHz4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XambgzmC, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_gmdil0iA, "del-1436-del");
  numBytes += sVarf_init(&sVarf_ACIXjIeN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NjBW8hN8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_a20CXYUT, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_OzuKbb2I, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_dMA1tyZM, 4720.0f);
  numBytes += cBinop_init(&cBinop_CSPBZ6CA, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_K8OrsP83, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9PZteRv6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_7Pejvwqr, 4720.0f);
  numBytes += cBinop_init(&cBinop_umpQuX5h, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_0bHHyJCc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mHFwPA5F, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_uEfeo8q0, 4720.0f);
  numBytes += cBinop_init(&cBinop_9qNXuCGn, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XgTJfZbo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_D3D4NVp4, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YYpyunGO, 1.0f);
  numBytes += cIf_init(&cIf_yuMeOLBc, false);
  numBytes += sVarf_init(&sVarf_imVNHhRK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_e8utBies, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5bAz22ST, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_621nj69Q, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_c2Lajbd2, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_lip8PHSU, &hTable_EBD5gUKK);
  numBytes += cVar_init_s(&cVar_JC7RDpFG, "del-1499-del1");
  numBytes += cDelay_init(this, &cDelay_oxaYzgbx, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_lS4yK2IC, 0.0f);
  numBytes += cBinop_init(&cBinop_IqYjTyLS, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_X8KngXpR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_KvWEdvlg, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_xXxuz9dn, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_Ag3mRohw, &hTable_zllsqs6M);
  numBytes += cVar_init_s(&cVar_YbibKPT8, "del-1499-del2");
  numBytes += cDelay_init(this, &cDelay_vgaFXhFV, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_6G58XGZz, 0.0f);
  numBytes += cBinop_init(&cBinop_gBUmXEah, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_XVwqmGPf, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_awNBCJE9, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_eiES53H4, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_IRLU9bKn, &hTable_gGlQYkbV);
  numBytes += cVar_init_s(&cVar_2NsQs6DS, "del-1499-del3");
  numBytes += cDelay_init(this, &cDelay_tWwMGfPg, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_6xslk1wm, 0.0f);
  numBytes += cBinop_init(&cBinop_HOz7eEDf, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_5NIYjhwx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_PN9oSn9y, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_vwdn7hXf, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_w3zdsZey, &hTable_0njfSoys);
  numBytes += cVar_init_s(&cVar_AMOcZgQy, "del-1499-del4");
  numBytes += cDelay_init(this, &cDelay_ClBfXXqh, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_PZoAQCpd, 0.0f);
  numBytes += cBinop_init(&cBinop_eAKa7gqS, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_ocJRRYIA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_dLa8JeU6, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_y7rENONY, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_G5KIXWi6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Nqk7LzNm, 0.0f);
  numBytes += hTable_init(&hTable_EBD5gUKK, 256);
  numBytes += cDelay_init(this, &cDelay_7RCryH9t, 0.0f);
  numBytes += cDelay_init(this, &cDelay_z4fhpYVq, 0.0f);
  numBytes += hTable_init(&hTable_zllsqs6M, 256);
  numBytes += cDelay_init(this, &cDelay_V78qCKJf, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rFQhn4KZ, 0.0f);
  numBytes += hTable_init(&hTable_gGlQYkbV, 256);
  numBytes += cDelay_init(this, &cDelay_DpXrO0nD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_5A5uIZbN, 0.0f);
  numBytes += hTable_init(&hTable_0njfSoys, 256);
  numBytes += cIf_init(&cIf_yM4kQslW, false);
  numBytes += cBinop_init(&cBinop_UCGIgdXn, 0.0f); // __pow
  numBytes += cPack_init(&cPack_y3lwIlGP, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_cJweqtDh, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_suPlYIka, 22050.0f);
  numBytes += cBinop_init(&cBinop_Tbc6X95v, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_BqoFLV6h, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Vu0Gbx6C, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_UUjf7avV, 100.0f);
  numBytes += cVar_init_f(&cVar_7xCpfsq7, 95.0f);
  numBytes += cVar_init_f(&cVar_yXRGd0cC, 14400.0f);
  numBytes += cVar_init_f(&cVar_Gx4aU02O, 60.0f);
  numBytes += cIf_init(&cIf_DiGtfXlu, false);
  numBytes += cTabhead_init(&cTabhead_4ORVYUGP, &hTable_TSvwyWQf);
  numBytes += cVar_init_s(&cVar_82yyJGeu, "del-1499-ref6");
  numBytes += cDelay_init(this, &cDelay_qAeKnSSq, 13.645f);
  numBytes += cDelay_init(this, &cDelay_1hWTxvrp, 0.0f);
  numBytes += cBinop_init(&cBinop_gVkSqAtF, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_xckj5im7, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Du5ZRFVe, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Xe32SJXE, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_cp2YPzZ1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_F7eW95iB, 0.0f);
  numBytes += hTable_init(&hTable_TSvwyWQf, 256);
  numBytes += cTabhead_init(&cTabhead_6RNCBRML, &hTable_EFJH7DGe);
  numBytes += cVar_init_s(&cVar_feP8qnCF, "del-1499-ref5");
  numBytes += cDelay_init(this, &cDelay_zVMUbcoj, 16.364f);
  numBytes += cDelay_init(this, &cDelay_JosAUkZp, 0.0f);
  numBytes += cBinop_init(&cBinop_OIDUEHR3, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_YDtqRLyU, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_gxz0RHrZ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_XP3TJH8U, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_HPrFNYOX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_5j322E8l, 0.0f);
  numBytes += hTable_init(&hTable_EFJH7DGe, 256);
  numBytes += cTabhead_init(&cTabhead_KaWi584T, &hTable_k6Ho7LFE);
  numBytes += cVar_init_s(&cVar_sFUc7NUz, "del-1499-ref4");
  numBytes += cDelay_init(this, &cDelay_e3A24Ki6, 19.392f);
  numBytes += cDelay_init(this, &cDelay_u1HsFttz, 0.0f);
  numBytes += cBinop_init(&cBinop_9kjgZxiP, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_4LnHAoDe, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_nmouTQ1P, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_9STPkYSh, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_zaEzkwCB, 0.0f);
  numBytes += cDelay_init(this, &cDelay_hqVRWPjB, 0.0f);
  numBytes += hTable_init(&hTable_k6Ho7LFE, 256);
  numBytes += cTabhead_init(&cTabhead_C0bpdWpL, &hTable_1m8RHnde);
  numBytes += cVar_init_s(&cVar_GLAH01co, "del-1499-ref3");
  numBytes += cDelay_init(this, &cDelay_nbPF9k7B, 25.796f);
  numBytes += cDelay_init(this, &cDelay_CvcSI8EG, 0.0f);
  numBytes += cBinop_init(&cBinop_UdNBdH4k, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_Q6HHHvu4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_O44IK0SM, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_FwvGBn4S, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ehdxNZWr, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VNn55yTn, 0.0f);
  numBytes += hTable_init(&hTable_1m8RHnde, 256);
  numBytes += cTabhead_init(&cTabhead_sk1YC4aq, &hTable_BNW0HdKo);
  numBytes += cVar_init_s(&cVar_dv4BAS48, "del-1499-ref2");
  numBytes += cDelay_init(this, &cDelay_a6dgcpqc, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_uWY5i1Xh, 0.0f);
  numBytes += cBinop_init(&cBinop_1iLWgDSX, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_8B7E31oH, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_AXFPdx8r, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_qmZFtlFk, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_kqs6Eikw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_bNKAnsT2, 0.0f);
  numBytes += hTable_init(&hTable_BNW0HdKo, 256);
  numBytes += cTabhead_init(&cTabhead_XVbQNLss, &hTable_UPXYUY4s);
  numBytes += cVar_init_s(&cVar_UWNsV8I9, "del-1499-ref1");
  numBytes += cDelay_init(this, &cDelay_zfpBzzwV, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_Ob1Knuth, 0.0f);
  numBytes += cBinop_init(&cBinop_OePAB3OE, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_1kdhuNK0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_nrvZF5ud, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ex8u3LOs, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_hK8VZx75, 0.0f);
  numBytes += cDelay_init(this, &cDelay_uGVdQsNb, 0.0f);
  numBytes += hTable_init(&hTable_UPXYUY4s, 256);
  numBytes += cVar_init_f(&cVar_6TVGxqFV, 0.0f);
  numBytes += cVar_init_f(&cVar_nTRjtZkj, 0.0f);
  numBytes += cPack_init(&cPack_yNXZskit, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_3gNWLpcd, 22050.0f);
  numBytes += cBinop_init(&cBinop_LTq0SHfI, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8GxEbFmH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FgHRs1Po, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8hSZ5atB, 22050.0f);
  numBytes += cBinop_init(&cBinop_xRXrfe93, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_nwuLrGpd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9X9WfMo8, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_UZvGkNFA, 22050.0f);
  numBytes += cBinop_init(&cBinop_U8csdvVP, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Inz1DJ92, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bcbXDy3L, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_sDIrlZy1, "del-1598-del1");
  numBytes += sVarf_init(&sVarf_yx9aoQhm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TCYUEP7x, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_04t1k3yf, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_MrzvP1fe, 10000.0f);
  numBytes += cBinop_init(&cBinop_yvSQqpqN, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_mXs1tjpP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WnpXrliR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_CIfAqho5, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Yt4I3DAg, 10.0f);
  numBytes += cBinop_init(&cBinop_ABedMioP, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_AQQlL3Kp, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Zmh9Ky8O, "floatatom");
  numBytes += sVarf_init(&sVarf_SdHXwAEd, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_BtZgduHT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Uq7D9EVB, 0.0f);
  numBytes += hTable_init(&hTable_hHg41gz0, 256);
  numBytes += sVarf_init(&sVarf_0YNilGdW, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_bJ6sKTLp, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_i27S3Afp, 1.0f);
  numBytes += cPack_init(&cPack_tdzdbXhl, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_1DIoHZYk, -2111611266);
  numBytes += cSlice_init(&cSlice_zqS5U31f, 1, 1);
  numBytes += cRandom_init(&cRandom_N7Qejp4e, 2127148726);
  numBytes += cSlice_init(&cSlice_HNoi98Cd, 1, 1);
  numBytes += cRandom_init(&cRandom_pmTaIp7i, 544577565);
  numBytes += cSlice_init(&cSlice_U0JN00fT, 1, 1);
  numBytes += cPack_init(&cPack_ao10hM3f, 4, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_fs8m1gHm, "floatatom");
  numBytes += cVar_init_s(&cVar_G3TEjMA6, "floatatom");
  numBytes += cIf_init(&cIf_oReJkUSR, false);
  numBytes += cVar_init_s(&cVar_DgaFA6iv, "floatatom");
  numBytes += cBinop_init(&cBinop_J76rH5PV, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_5fDDzlNB, 72.07f); // __sub
  numBytes += cSlice_init(&cSlice_Wbz3KYD3, 1, -1);
  numBytes += cSlice_init(&cSlice_x0kpOebP, 1, -1);
  numBytes += cVar_init_f(&cVar_yRXZHbPZ, 5.0f);
  numBytes += cBinop_init(&cBinop_td7Dg6wA, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_6HB5v3Z4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_L37LQ8sN, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_iYys7GFK, 1, 1);
  numBytes += cSlice_init(&cSlice_54jHs6NK, 0, 1);
  numBytes += sVarf_init(&sVarf_rrJYS9uR, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_hW1pKyB9, 5.0f);
  numBytes += cBinop_init(&cBinop_QNARiVeS, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_MB2xpbcJ, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_9UaBccw8, 50.0f);
  numBytes += cVar_init_s(&cVar_NuaZQ17a, "floatatom");
  numBytes += cDelay_init(this, &cDelay_ncBvfC23, 350.0f);
  numBytes += cVar_init_s(&cVar_xuyHzrP1, "floatatom");
  numBytes += cVar_init_s(&cVar_nnyuIK2C, "floatatom");
  numBytes += cVar_init_s(&cVar_2jeh9K61, "floatatom");
  numBytes += cExpr_init(&cExpr_MIt8Afh5, &Heavy_SoundScraper::cExpr_MIt8Afh5_evaluate);
  numBytes += cVar_init_s(&cVar_eeJs2bQ2, "floatatom");
  numBytes += cVar_init_f(&cVar_cxmQt65o, 0.0f);
  numBytes += cVar_init_f(&cVar_1dxoRA5S, 0.0f);
  numBytes += cVar_init_s(&cVar_JhKOM2dn, "1674_default");
  numBytes += cSlice_init(&cSlice_7iiqPDLI, 1, 1);
  numBytes += sVarf_init(&sVarf_qYYi719y, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_9TPhzdwH, "1674_default");
  numBytes += cSlice_init(&cSlice_foxBpTq4, 1, 1);
  numBytes += sVarf_init(&sVarf_HVyGZZ9d, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KEKKW4od, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7C0lU7IQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wheB7zSH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8hmbsw4W, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2xZtm9Yc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eWFHyqTT, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_CHJr9DkN, 0.0f); // __div
  numBytes += hTable_init(&hTable_qCRct5qM, 10000);
  numBytes += sVarf_init(&sVarf_cMHihObf, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_SoundScraper::~Heavy_SoundScraper() {
  cPack_free(&cPack_yJNXRvEp);
  cPack_free(&cPack_QGmewEDx);
  cPack_free(&cPack_1RLZvANL);
  cPack_free(&cPack_QfFpVVhK);
  cPack_free(&cPack_X3btkr4b);
  cPack_free(&cPack_oj9KqRPB);
  hTable_free(&hTable_xEg61Afi);
  cPack_free(&cPack_5MRRJafa);
  cPack_free(&cPack_FWLkbOuG);
  cPack_free(&cPack_9SirQ00V);
  cPack_free(&cPack_JyiTe2Xq);
  cPack_free(&cPack_MLRsfLKe);
  cPack_free(&cPack_qlGPg64h);
  hTable_free(&hTable_U3sU2Iw3);
  cPack_free(&cPack_1xGIIDOG);
  cPack_free(&cPack_JFIYirYa);
  cPack_free(&cPack_IjwcsqCR);
  cPack_free(&cPack_BWHF5MJh);
  cPack_free(&cPack_hy0J4TgP);
  cPack_free(&cPack_zbFWUIDP);
  hTable_free(&hTable_0mdXHtxw);
  cPack_free(&cPack_oSONyWSg);
  cPack_free(&cPack_RU8KL3xi);
  cPack_free(&cPack_erTMuVi7);
  cPack_free(&cPack_ru3uoepH);
  cPack_free(&cPack_BgvIxzDi);
  cPack_free(&cPack_7VIja7HJ);
  hTable_free(&hTable_jVvlKWLF);
  cPack_free(&cPack_c0UiJcg3);
  cPack_free(&cPack_rRC9jwKQ);
  cPack_free(&cPack_2MHE1Awc);
  cPack_free(&cPack_2gKaTTOz);
  cPack_free(&cPack_SM02s3BG);
  cPack_free(&cPack_xdE3u1zg);
  cPack_free(&cPack_wsjhBdOP);
  cPack_free(&cPack_CdZamBkF);
  hTable_free(&hTable_FXXLUP0G);
  hTable_free(&hTable_ForqUfzu);
  hTable_free(&hTable_7hwEo7ic);
  hTable_free(&hTable_f3whMxOT);
  hTable_free(&hTable_3zp5yu42);
  hTable_free(&hTable_LnmM0L5E);
  cPack_free(&cPack_CUl2rfqm);
  cPack_free(&cPack_6dpfoX4X);
  hTable_free(&hTable_K7TEiO1b);
  hTable_free(&hTable_eqIUvePK);
  cPack_free(&cPack_mLkWrJdP);
  cPack_free(&cPack_4QnWFvXF);
  cPack_free(&cPack_KDnQfsTC);
  hTable_free(&hTable_UjiZIBVs);
  hTable_free(&hTable_D1GqFIK5);
  hTable_free(&hTable_knNOXmUv);
  hTable_free(&hTable_9xd8fRNK);
  cPack_free(&cPack_1QQab4Yq);
  cPack_free(&cPack_BgmuUnR8);
  hTable_free(&hTable_gRCFkes3);
  hTable_free(&hTable_ht2IgTgH);
  hTable_free(&hTable_OMXsco6t);
  hTable_free(&hTable_Ju3BKALx);
  hTable_free(&hTable_jyI9ewhb);
  hTable_free(&hTable_GNDU06Rg);
  cPack_free(&cPack_qss04jOS);
  cPack_free(&cPack_4fS6tWh4);
  cPack_free(&cPack_HndFaBJZ);
  cPack_free(&cPack_G8N8CuMQ);
  hTable_free(&hTable_izH9V5L1);
  hTable_free(&hTable_EBD5gUKK);
  hTable_free(&hTable_zllsqs6M);
  hTable_free(&hTable_gGlQYkbV);
  hTable_free(&hTable_0njfSoys);
  cPack_free(&cPack_y3lwIlGP);
  cPack_free(&cPack_cJweqtDh);
  hTable_free(&hTable_TSvwyWQf);
  hTable_free(&hTable_EFJH7DGe);
  hTable_free(&hTable_k6Ho7LFE);
  hTable_free(&hTable_1m8RHnde);
  hTable_free(&hTable_BNW0HdKo);
  hTable_free(&hTable_UPXYUY4s);
  cPack_free(&cPack_yNXZskit);
  hTable_free(&hTable_hHg41gz0);
  cPack_free(&cPack_bJ6sKTLp);
  cPack_free(&cPack_tdzdbXhl);
  cPack_free(&cPack_ao10hM3f);
  cExpr_free(&cExpr_MIt8Afh5);
  hTable_free(&hTable_qCRct5qM);
}

HvTable *Heavy_SoundScraper::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x58D371AD: return &hTable_xEg61Afi; // 1013_default
    case 0x565019FD: return &hTable_U3sU2Iw3; // 1051_default
    case 0x262582C8: return &hTable_0mdXHtxw; // 1089_default
    case 0x161BC6D4: return &hTable_jVvlKWLF; // 1127_default
    case 0x9BCAD111: return &hTable_FXXLUP0G; // bowl
    case 0x782CD90: return &hTable_ForqUfzu; // crotale
    case 0x53C964B5: return &hTable_7hwEo7ic; // gong
    case 0xAC13AE99: return &hTable_f3whMxOT; // marimba
    case 0x1FD931DF: return &hTable_3zp5yu42; // xylo
    case 0x6F52CA74: return &hTable_LnmM0L5E; // almglocken
    case 0xE52DB2F5: return &hTable_K7TEiO1b; // del-1228-del
    case 0x7877CEE7: return &hTable_eqIUvePK; // del-1257-del1
    case 0xE3492292: return &hTable_UjiZIBVs; // del-1318-del1
    case 0x2DF102BD: return &hTable_D1GqFIK5; // del-1318-del2
    case 0xEBD4F3B1: return &hTable_knNOXmUv; // del-1318-del3
    case 0x447E84A6: return &hTable_9xd8fRNK; // del-1318-del4
    case 0xE998EFF7: return &hTable_gRCFkes3; // del-1318-ref6
    case 0xD5FADC2B: return &hTable_ht2IgTgH; // del-1318-ref5
    case 0x56C3B41A: return &hTable_OMXsco6t; // del-1318-ref4
    case 0x6832F2BA: return &hTable_Ju3BKALx; // del-1318-ref3
    case 0x9EC1C279: return &hTable_jyI9ewhb; // del-1318-ref2
    case 0x4118789A: return &hTable_GNDU06Rg; // del-1318-ref1
    case 0x29E6AB85: return &hTable_izH9V5L1; // del-1436-del
    case 0xB9E5E01C: return &hTable_EBD5gUKK; // del-1499-del1
    case 0x63C2268: return &hTable_zllsqs6M; // del-1499-del2
    case 0xDBF320BC: return &hTable_gGlQYkbV; // del-1499-del3
    case 0x225643E: return &hTable_0njfSoys; // del-1499-del4
    case 0xB93A9FFB: return &hTable_TSvwyWQf; // del-1499-ref6
    case 0xAD23DE07: return &hTable_EFJH7DGe; // del-1499-ref5
    case 0x76D4D2B8: return &hTable_k6Ho7LFE; // del-1499-ref4
    case 0x93E20AE1: return &hTable_1m8RHnde; // del-1499-ref3
    case 0x48A066F: return &hTable_BNW0HdKo; // del-1499-ref2
    case 0x73942DD6: return &hTable_UPXYUY4s; // del-1499-ref1
    case 0x63F3A24F: return &hTable_hHg41gz0; // del-1598-del1
    case 0x93F54B3C: return &hTable_qCRct5qM; // 1674_default
    default: return nullptr;
  }
}

void Heavy_SoundScraper::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x676151E5: { // 1005-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jXHAScWH_sendMessage);
      break;
    }
    case 0x4518BA34: { // 1005-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C745Ey8d_sendMessage);
      break;
    }
    case 0xF2645EF2: { // 1013-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YeIx5fjK_sendMessage);
      break;
    }
    case 0x349D3D62: { // 1013-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GLg1BikG_sendMessage);
      break;
    }
    case 0x6AE0114A: { // 1013-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xC8JETB5_sendMessage);
      break;
    }
    case 0x14D190E8: { // 1013-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yVQgQJaP_sendMessage);
      break;
    }
    case 0xC268AA1B: { // 1013-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jZwhmra9_sendMessage);
      break;
    }
    case 0xE7AF8038: { // 1013-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zT2FOZe1_sendMessage);
      break;
    }
    case 0x64DCFC2F: { // 1013-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_f1WQ5DsQ_sendMessage);
      break;
    }
    case 0x76EF1A3A: { // 1051-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bEyWtO5T_sendMessage);
      break;
    }
    case 0x7AB5A036: { // 1051-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tTtgiER6_sendMessage);
      break;
    }
    case 0x729AEC23: { // 1051-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qZ3JIoVu_sendMessage);
      break;
    }
    case 0x78E1F133: { // 1051-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kNsP12v3_sendMessage);
      break;
    }
    case 0x6CE4754: { // 1051-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hJkSXKfR_sendMessage);
      break;
    }
    case 0xFD6A3B2A: { // 1051-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_64ga5gHB_sendMessage);
      break;
    }
    case 0x6CE9CED9: { // 1051-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JVeUJWhl_sendMessage);
      break;
    }
    case 0xFA29A439: { // 1089-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kqF2iJb4_sendMessage);
      break;
    }
    case 0xAA863EF6: { // 1089-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qADzeWFu_sendMessage);
      break;
    }
    case 0xAAA0A75E: { // 1089-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mQ5Hg5Ja_sendMessage);
      break;
    }
    case 0xCB432715: { // 1089-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wMehuFB6_sendMessage);
      break;
    }
    case 0xB7D5A2D4: { // 1089-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0ReGqyN9_sendMessage);
      break;
    }
    case 0xBBC64E67: { // 1089-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IwtHfQKo_sendMessage);
      break;
    }
    case 0x720CB109: { // 1089-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xXLSTEOJ_sendMessage);
      break;
    }
    case 0x49109026: { // 1127-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gkT7foyj_sendMessage);
      break;
    }
    case 0x1ED22B32: { // 1127-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4awM0p6i_sendMessage);
      break;
    }
    case 0xB70E01AA: { // 1127-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PPsVGZFP_sendMessage);
      break;
    }
    case 0x47F0CA40: { // 1127-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tGuNsXcY_sendMessage);
      break;
    }
    case 0x212E3ED2: { // 1127-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8ulyCInE_sendMessage);
      break;
    }
    case 0xD654287F: { // 1127-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XXwtG2Vj_sendMessage);
      break;
    }
    case 0x4B190B33: { // 1127-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qgvPM0Rv_sendMessage);
      break;
    }
    case 0x1345C8C4: { // 1165-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zd3gsUBS_sendMessage);
      break;
    }
    case 0x352D518B: { // 1165-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4eQaa9bD_sendMessage);
      break;
    }
    case 0x1B80BC63: { // 1173-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_boqSUwBQ_sendMessage);
      break;
    }
    case 0x85C9C328: { // 1173-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JsJfNXjF_sendMessage);
      break;
    }
    case 0x7FA13EC5: { // 1183-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GZJMvqdA_sendMessage);
      break;
    }
    case 0xD9AC1997: { // 1183-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MUee4EMg_sendMessage);
      break;
    }
    case 0xE3801E94: { // 1191-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MRKcW8UN_sendMessage);
      break;
    }
    case 0x4DA02B5A: { // 1191-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3CC5ZSf2_sendMessage);
      break;
    }
    case 0x8DC08092: { // 1417-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nPPo9706_sendMessage);
      break;
    }
    case 0xA51F5BFF: { // 1417-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ck2cgdMl_sendMessage);
      break;
    }
    case 0x382EB97A: { // 1626-bend
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pocdcvVX_sendMessage);
      break;
    }
    case 0xD613858: { // 1626-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_z2BKp8NE_sendMessage);
      break;
    }
    case 0x2952A082: { // 1626-level
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iXAU0KvM_sendMessage);
      break;
    }
    case 0xCC3056CB: { // 1626-loopstart
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Zb5wiYbE_sendMessage);
      break;
    }
    case 0x484C6410: { // 1626-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wYnLbVg1_sendMessage);
      break;
    }
    case 0x83CDC26B: { // 1626-reset
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LWmLvy6l_sendMessage);
      break;
    }
    case 0xD475E50C: { // 1626-sample
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tLqbGs8s_sendMessage);
      break;
    }
    case 0xAFE56AD8: { // 1626-sample-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9lzodGP2_sendMessage);
      break;
    }
    case 0x739592F2: { // 1626-start
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4Bg1IGqS_sendMessage);
      break;
    }
    case 0x31B2C381: { // 1626-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JHfuAaRa_sendMessage);
      break;
    }
    case 0xD2002891: { // 1626-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_27FnSQS6_sendMessage);
      break;
    }
    case 0xEA3AE85E: { // 1626-transposition
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4sNQqzIV_sendMessage);
      break;
    }
    case 0x692F7CB8: { // 1674-cents
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CwehpIRw_sendMessage);
      break;
    }
    case 0x72CEA287: { // 1674-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_P5xTlQQ7_sendMessage);
      break;
    }
    case 0xA99117E0: { // 1674-chunk-size-samples
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wmeKCgxw_sendMessage);
      break;
    }
    case 0xEA9C1FF4: { // 1674-read-point
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vO2eifRB_sendMessage);
      break;
    }
    case 0x995DB636: { // 1674-read-pt
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kcttVYug_sendMessage);
      break;
    }
    case 0xD40026D1: { // 1674-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_z3Cqh4cv_sendMessage);
      break;
    }
    case 0x2460F295: { // 1674-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_P1wqfoH7_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_21HfNB7F_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rBWLuHUi_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2ZOQk7NA_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_djyXofn4_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fY4XRZME_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VoKSYf6H_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_79w7CU3Z_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zzsxBujR_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mFTFJH8M_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_J0Vb6wxz_sendMessage);
      break;
    }
    case 0x7FFAC478: { // sampleNameFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KKZatrEy_sendMessage);
      break;
    }
    case 0x62D6FDDE: { // selectsound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_h3aSlJA7_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_omFdiCCN_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZRrTc8AD_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pOi4PYIs_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_f8qWjmIj_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yZlsZ9lz_sendMessage);
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


void Heavy_SoundScraper::cVar_P88YlK88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_kQoa8PP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_usx9wgqO_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xfwhosI2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UcPdeDQJ_sendMessage);
}

void Heavy_SoundScraper::cIf_n0Ip2sbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_QyKSTzbW_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_HX5pqxrT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_XWevhD6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_blZ4M306, HV_BINOP_POW, 0, m, &cBinop_blZ4M306_sendMessage);
}

void Heavy_SoundScraper::cBinop_blZ4M306_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_yJNXRvEp, 0, m, &cPack_yJNXRvEp_sendMessage);
}

void Heavy_SoundScraper::cBinop_TqnnUpDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_DAfevjhU_sendMessage);
}

void Heavy_SoundScraper::cCast_UcPdeDQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_n0Ip2sbU, 0, m, &cIf_n0Ip2sbU_sendMessage);
}

void Heavy_SoundScraper::cCast_xfwhosI2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_9k4bcJHN_sendMessage);
}

void Heavy_SoundScraper::cBinop_9k4bcJHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_n0Ip2sbU, 1, m, &cIf_n0Ip2sbU_sendMessage);
}

void Heavy_SoundScraper::cBinop_HX5pqxrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_TqnnUpDd_sendMessage);
}

void Heavy_SoundScraper::cMsg_QyKSTzbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_yJNXRvEp, 0, m, &cPack_yJNXRvEp_sendMessage);
}

void Heavy_SoundScraper::cBinop_DAfevjhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_blZ4M306, HV_BINOP_POW, 1, m, &cBinop_blZ4M306_sendMessage);
  cMsg_XWevhD6S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_yJNXRvEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hdNjQ4Sw, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_cG6hT3WO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TjLELM1q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_usx9wgqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_hIvLZWFg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_hIvLZWFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jXHAScWH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_TjLELM1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_C745Ey8d_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_AdD5MiE4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_s8Pvrmn9, 0, m, &cSlice_s8Pvrmn9_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sV02N5ph, 0, m, &cRandom_sV02N5ph_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_3RCiOUIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BwLuDfJj_sendMessage);
}

void Heavy_SoundScraper::cUnop_BwLuDfJj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_WwLqNQ3M_sendMessage);
}

void Heavy_SoundScraper::cRandom_sV02N5ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_3RCiOUIT_sendMessage);
}

void Heavy_SoundScraper::cSlice_s8Pvrmn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sV02N5ph, 1, m, &cRandom_sV02N5ph_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_yzGFDna7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGVI9N2W, HV_BINOP_DIVIDE, 0, m, &cBinop_UGVI9N2W_sendMessage);
}

void Heavy_SoundScraper::cBinop_6q6a2hKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Gbcpd976_sendMessage);
}

void Heavy_SoundScraper::cBinop_Gbcpd976_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DLsO7KN5, HV_BINOP_POW, 1, m, &cBinop_DLsO7KN5_sendMessage);
  cMsg_idZp4L4A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_DLsO7KN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_yzGFDna7_sendMessage);
}

void Heavy_SoundScraper::cMsg_idZp4L4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DLsO7KN5, HV_BINOP_POW, 0, m, &cBinop_DLsO7KN5_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_OydN7Sgm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ShdpOGQ7, 0, m, &cSlice_ShdpOGQ7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ES6kMFhN, 0, m, &cRandom_ES6kMFhN_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_5vOm4oMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2j9WVaCk_sendMessage);
}

void Heavy_SoundScraper::cUnop_2j9WVaCk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_virVQAcR_sendMessage);
}

void Heavy_SoundScraper::cRandom_ES6kMFhN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_5vOm4oMe_sendMessage);
}

void Heavy_SoundScraper::cSlice_ShdpOGQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ES6kMFhN, 1, m, &cRandom_ES6kMFhN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_AqEcg7HI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_VybjeB6B_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_WrxJZLUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_2sr1JP8T_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_qcQIZGaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1RLZvANL, 0, m, &cPack_1RLZvANL_sendMessage);
}

void Heavy_SoundScraper::cUnop_BDgtilBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QGmewEDx, 0, m, &cPack_QGmewEDx_sendMessage);
}

void Heavy_SoundScraper::cPack_QGmewEDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2JtmVX3L, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_1RLZvANL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_i32PJq3G, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_nl9qOpeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_qcQIZGaR_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_BDgtilBB_sendMessage);
}

void Heavy_SoundScraper::cMsg_iFGNLHAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_nl9qOpeQ_sendMessage);
}

void Heavy_SoundScraper::cCast_CYYm4Gw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_RuMXluFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u0d79Dry_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wMs992oF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CWtF3GWO_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_yQ4vOZ6L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ggLf9wgD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ggLf9wgD_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_hyhjZKx1, 1, m, &cDelay_hyhjZKx1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L34VkQRB_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_hyhjZKx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hyhjZKx1, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZHP3B7s8, 0, m, &cVar_ZHP3B7s8_sendMessage);
}

void Heavy_SoundScraper::cMsg_ggLf9wgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hyhjZKx1, 0, m, &cDelay_hyhjZKx1_sendMessage);
}

void Heavy_SoundScraper::cCast_L34VkQRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hyhjZKx1, 0, m, &cDelay_hyhjZKx1_sendMessage);
}

void Heavy_SoundScraper::cVar_ZHP3B7s8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a1VrOBZa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_xEEppRJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RuMXluFc, 0, m, &cVar_RuMXluFc_sendMessage);
}

void Heavy_SoundScraper::cSend_2JySjyYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_tMtwEjXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xC8JETB5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_VN5E2mZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_2JySjyYA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ECPhDJd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_tMtwEjXJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_6LfFY46n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_f1WQ5DsQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_14Kkq36C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_6LfFY46n_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_KuBAaLEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_f1WQ5DsQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_sRSlKOgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Go9WbMt2, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_a1VrOBZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_Go9WbMt2, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_wMs992oF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZHP3B7s8, 1, m, &cVar_ZHP3B7s8_sendMessage);
}

void Heavy_SoundScraper::cCast_u0d79Dry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sRSlKOgg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_CWtF3GWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yQ4vOZ6L_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_D8TlZlpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_YveSN5lM_sendMessage);
}

void Heavy_SoundScraper::cVar_2MpF5daW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_m29o2qhg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_xnzF5Z5Z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_7PhL66qs_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_7PhL66qs_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_XmhC29pA, 1, m, &cDelay_XmhC29pA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7owg7A04_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_XmhC29pA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XmhC29pA, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BZFJkidh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uE2q4YqU_sendMessage);
}

void Heavy_SoundScraper::cMsg_7PhL66qs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XmhC29pA, 0, m, &cDelay_XmhC29pA_sendMessage);
}

void Heavy_SoundScraper::cCast_7owg7A04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XmhC29pA, 0, m, &cDelay_XmhC29pA_sendMessage);
}

void Heavy_SoundScraper::cPack_QfFpVVhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XEQ5NN6b_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_X3btkr4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vft6WF5Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_oj9KqRPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w9rw6XpP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Dsg543qk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X3btkr4b, 0, m, &cPack_X3btkr4b_sendMessage);
}

void Heavy_SoundScraper::cVar_tCw5oTqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_QvJMmxZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_US9vdtNY, HV_BINOP_DIVIDE, 1, m, &cBinop_US9vdtNY_sendMessage);
}

void Heavy_SoundScraper::cVar_NxC9tGxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_US9vdtNY, HV_BINOP_DIVIDE, 0, m, &cBinop_US9vdtNY_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_m29o2qhg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mpe06db6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z7XMBdFU_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RWAJcXqe_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SWvdgca4_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_z7XMBdFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NxC9tGxB, 0, m, &cVar_NxC9tGxB_sendMessage);
}

void Heavy_SoundScraper::cCast_mpe06db6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QvJMmxZr, 0, m, &cVar_QvJMmxZr_sendMessage);
}

void Heavy_SoundScraper::cCast_RWAJcXqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QvJMmxZr, 0, m, &cVar_QvJMmxZr_sendMessage);
}

void Heavy_SoundScraper::cCast_SWvdgca4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NxC9tGxB, 0, m, &cVar_NxC9tGxB_sendMessage);
}

void Heavy_SoundScraper::cCast_uE2q4YqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Dsg543qk, 0, m, &cVar_Dsg543qk_sendMessage);
}

void Heavy_SoundScraper::cCast_BZFJkidh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2MpF5daW, 0, m, &cVar_2MpF5daW_sendMessage);
}

void Heavy_SoundScraper::cSend_juBN6qVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_GLg1BikG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_vft6WF5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YeIx5fjK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_XEQ5NN6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YeIx5fjK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_0FiZuVWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QfFpVVhK, 0, m, &cPack_QfFpVVhK_sendMessage);
}

void Heavy_SoundScraper::cCast_NmfCiFLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xnzF5Z5Z_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_YveSN5lM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oj9KqRPB, 0, m, &cPack_oj9KqRPB_sendMessage);
}

void Heavy_SoundScraper::cBinop_nr9IlXs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oj9KqRPB, 1, m, &cPack_oj9KqRPB_sendMessage);
}

void Heavy_SoundScraper::cMsg_w9rw6XpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_juBN6qVB_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_juBN6qVB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ACEf0Ky2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0FiZuVWN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NmfCiFLq_sendMessage);
}

void Heavy_SoundScraper::cCast_SYuff8vt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_OdPVkuVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2MpF5daW, 1, m, &cVar_2MpF5daW_sendMessage);
}

void Heavy_SoundScraper::cBinop_US9vdtNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D8TlZlpG, 0, m, &cVar_D8TlZlpG_sendMessage);
}

void Heavy_SoundScraper::cMsg_YPKDoUZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_nr9IlXs1_sendMessage);
}

void Heavy_SoundScraper::cSlice_Q7S2u50f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_xG061Uyk_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_VqTUo9Yg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SYuff8vt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OdPVkuVs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ACEf0Ky2_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_tCw5oTqO, 0, m, &cVar_tCw5oTqO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_dGDOkQjU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MxVInVIU, 0, m, &cSlice_MxVInVIU_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_qXi0I8E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dlNto3y2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Y8yhw6Bi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_m0CFmVJ3_sendMessage);
}

void Heavy_SoundScraper::cBinop_m0CFmVJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_83HBdz9x, m);
}

void Heavy_SoundScraper::cMsg_dlNto3y2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Y8yhw6Bi_sendMessage);
}

void Heavy_SoundScraper::cSlice_MxVInVIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_9XM6QKta, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_8ScqbFZc, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_qXi0I8E2, 0, m, &cVar_qXi0I8E2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_R127Hope_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aO9dEZUF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_t64pF7TK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_xM6h8NJi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_r9Fp2IuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_FXBdSD4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_xG061Uyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_dGDOkQjU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_xEg61Afi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_aO9dEZUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r9Fp2IuY, 0, m, &cVar_r9Fp2IuY_sendMessage);
}

void Heavy_SoundScraper::cBinop_xM6h8NJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FXBdSD4F, 0, m, &cVar_FXBdSD4F_sendMessage);
}

void Heavy_SoundScraper::cSlice_JnoMtmrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_nll3bNb6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_tsaPX2tq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y3Epgkx0_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_6q6a2hKa_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_5cMyjGtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5MRRJafa, 1, m, &cPack_5MRRJafa_sendMessage);
}

void Heavy_SoundScraper::cPack_5MRRJafa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZLZSdq0a_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HuByDpWc_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Q7S2u50f, 0, m, &cSlice_Q7S2u50f_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VqTUo9Yg, 0, m, &cSlice_VqTUo9Yg_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_gC24MltE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5MRRJafa, 0, m, &cPack_5MRRJafa_sendMessage);
}

void Heavy_SoundScraper::cCast_2FrcqQVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5cMyjGtA, 0, m, &cVar_5cMyjGtA_sendMessage);
}

void Heavy_SoundScraper::cBinop_WwLqNQ3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_31XDsfi8_sendMessage);
}

void Heavy_SoundScraper::cBinop_31XDsfi8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_nl9qOpeQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_nll3bNb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1FqpA9Ok_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_UKpQMG7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2FrcqQVe_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gC24MltE_sendMessage);
}

void Heavy_SoundScraper::cBinop_virVQAcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_cqBno6bd_sendMessage);
}

void Heavy_SoundScraper::cBinop_cqBno6bd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UKpQMG7B, HV_BINOP_MULTIPLY, 1, m, &cBinop_UKpQMG7B_sendMessage);
}

void Heavy_SoundScraper::cCast_Y3Epgkx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OydN7Sgm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ZLZSdq0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AdD5MiE4_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CYYm4Gw5_sendMessage);
}

void Heavy_SoundScraper::cCast_HuByDpWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xEEppRJ8_sendMessage);
}

void Heavy_SoundScraper::cSend_2sr1JP8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jZwhmra9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_VybjeB6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yVQgQJaP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_UGVI9N2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UKpQMG7B, HV_BINOP_MULTIPLY, 0, m, &cBinop_UKpQMG7B_sendMessage);
}

void Heavy_SoundScraper::cSend_1FqpA9Ok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zT2FOZe1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_73ZbUJGT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ESafPGfa, 0, m, &cSlice_ESafPGfa_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XM0v7KTR, 0, m, &cRandom_XM0v7KTR_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_JbDND3JT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PfKGWPZQ_sendMessage);
}

void Heavy_SoundScraper::cUnop_PfKGWPZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_zN48LFRI_sendMessage);
}

void Heavy_SoundScraper::cRandom_XM0v7KTR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_JbDND3JT_sendMessage);
}

void Heavy_SoundScraper::cSlice_ESafPGfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XM0v7KTR, 1, m, &cRandom_XM0v7KTR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_S8dK6Fca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W7bXoNKU, HV_BINOP_DIVIDE, 0, m, &cBinop_W7bXoNKU_sendMessage);
}

void Heavy_SoundScraper::cBinop_HWRSyjPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_a521S0uE_sendMessage);
}

void Heavy_SoundScraper::cBinop_a521S0uE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RbQQ3r76, HV_BINOP_POW, 1, m, &cBinop_RbQQ3r76_sendMessage);
  cMsg_rWFXhr4F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_RbQQ3r76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_S8dK6Fca_sendMessage);
}

void Heavy_SoundScraper::cMsg_rWFXhr4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RbQQ3r76, HV_BINOP_POW, 0, m, &cBinop_RbQQ3r76_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_z8szBFYZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_a5QztG4z, 0, m, &cSlice_a5QztG4z_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PwCC5M7f, 0, m, &cRandom_PwCC5M7f_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_A8S4bAO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_DC0Mzt6l_sendMessage);
}

void Heavy_SoundScraper::cUnop_DC0Mzt6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2LrusuWV_sendMessage);
}

void Heavy_SoundScraper::cRandom_PwCC5M7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_A8S4bAO6_sendMessage);
}

void Heavy_SoundScraper::cSlice_a5QztG4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PwCC5M7f, 1, m, &cRandom_PwCC5M7f_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_xXeThES9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_fLJDE0UE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_9RUinkdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_ELO1RLF7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_So72wrmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9SirQ00V, 0, m, &cPack_9SirQ00V_sendMessage);
}

void Heavy_SoundScraper::cUnop_u8RmBNQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FWLkbOuG, 0, m, &cPack_FWLkbOuG_sendMessage);
}

void Heavy_SoundScraper::cPack_FWLkbOuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mDDzoF84, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_9SirQ00V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zUdbyos4, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_cHFdV0em_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_So72wrmx_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_u8RmBNQA_sendMessage);
}

void Heavy_SoundScraper::cMsg_nP8wMzxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_cHFdV0em_sendMessage);
}

void Heavy_SoundScraper::cCast_sKGsfu0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_F81RJd5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H0eaa9P1_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aTNeC7OH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6chlMbtg_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_R9JHppLd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_7ItgkTae_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_7ItgkTae_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_27hs3a7c, 1, m, &cDelay_27hs3a7c_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ucgr4nPh_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_27hs3a7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_27hs3a7c, m);
  cVar_onMessage(_c, &Context(_c)->cVar_t9PqkuTd, 0, m, &cVar_t9PqkuTd_sendMessage);
}

void Heavy_SoundScraper::cMsg_7ItgkTae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_27hs3a7c, 0, m, &cDelay_27hs3a7c_sendMessage);
}

void Heavy_SoundScraper::cCast_ucgr4nPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_27hs3a7c, 0, m, &cDelay_27hs3a7c_sendMessage);
}

void Heavy_SoundScraper::cVar_t9PqkuTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dPJy69PP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_fgR3btBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F81RJd5r, 0, m, &cVar_F81RJd5r_sendMessage);
}

void Heavy_SoundScraper::cSend_BGeCSr0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_ZQDhR21Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qZ3JIoVu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_4DTd8I8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_BGeCSr0w_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ntv7LGRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_ZQDhR21Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_jAceznds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JVeUJWhl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KWIRudLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_jAceznds_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_3fTrkZps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JVeUJWhl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ut5s7V9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_gfJzJeYK, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_dPJy69PP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_gfJzJeYK, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_aTNeC7OH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t9PqkuTd, 1, m, &cVar_t9PqkuTd_sendMessage);
}

void Heavy_SoundScraper::cCast_6chlMbtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_R9JHppLd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_H0eaa9P1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ut5s7V9Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_YUmIDyGj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_K0y3kB8L_sendMessage);
}

void Heavy_SoundScraper::cVar_pc3WVmEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mGbSiPC7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_smacpQfj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Ur31UiTQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Ur31UiTQ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_rfOEJQvE, 1, m, &cDelay_rfOEJQvE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TWhbvhYV_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_rfOEJQvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rfOEJQvE, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2QZQCJHl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VgmYUuIj_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ur31UiTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rfOEJQvE, 0, m, &cDelay_rfOEJQvE_sendMessage);
}

void Heavy_SoundScraper::cCast_TWhbvhYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rfOEJQvE, 0, m, &cDelay_rfOEJQvE_sendMessage);
}

void Heavy_SoundScraper::cPack_JyiTe2Xq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_czPP3u69_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_MLRsfLKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_UaMa0yHH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_qlGPg64h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jsjNvbLI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_XXiXO54d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_MLRsfLKe, 0, m, &cPack_MLRsfLKe_sendMessage);
}

void Heavy_SoundScraper::cVar_Gqt66BBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_rJTmnT3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HVHhJbjN, HV_BINOP_DIVIDE, 1, m, &cBinop_HVHhJbjN_sendMessage);
}

void Heavy_SoundScraper::cVar_eNy2dSLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HVHhJbjN, HV_BINOP_DIVIDE, 0, m, &cBinop_HVHhJbjN_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_mGbSiPC7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FO8Dt2QA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_46tZT3Yy_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bZ112kOY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c3LXDwFb_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_46tZT3Yy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eNy2dSLF, 0, m, &cVar_eNy2dSLF_sendMessage);
}

void Heavy_SoundScraper::cCast_FO8Dt2QA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rJTmnT3h, 0, m, &cVar_rJTmnT3h_sendMessage);
}

void Heavy_SoundScraper::cCast_c3LXDwFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eNy2dSLF, 0, m, &cVar_eNy2dSLF_sendMessage);
}

void Heavy_SoundScraper::cCast_bZ112kOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rJTmnT3h, 0, m, &cVar_rJTmnT3h_sendMessage);
}

void Heavy_SoundScraper::cCast_2QZQCJHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pc3WVmEH, 0, m, &cVar_pc3WVmEH_sendMessage);
}

void Heavy_SoundScraper::cCast_VgmYUuIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XXiXO54d, 0, m, &cVar_XXiXO54d_sendMessage);
}

void Heavy_SoundScraper::cSend_co5RI9Bw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tTtgiER6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_UaMa0yHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bEyWtO5T_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_czPP3u69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bEyWtO5T_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_YEgX4rkA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JyiTe2Xq, 0, m, &cPack_JyiTe2Xq_sendMessage);
}

void Heavy_SoundScraper::cCast_0KBmnWwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_smacpQfj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_K0y3kB8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qlGPg64h, 0, m, &cPack_qlGPg64h_sendMessage);
}

void Heavy_SoundScraper::cBinop_cNW8A9SV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qlGPg64h, 1, m, &cPack_qlGPg64h_sendMessage);
}

void Heavy_SoundScraper::cMsg_jsjNvbLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_co5RI9Bw_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_co5RI9Bw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_40MQlxnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YEgX4rkA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0KBmnWwE_sendMessage);
}

void Heavy_SoundScraper::cCast_UdcnmF7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pc3WVmEH, 1, m, &cVar_pc3WVmEH_sendMessage);
}

void Heavy_SoundScraper::cCast_XzDRuImw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_HVHhJbjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YUmIDyGj, 0, m, &cVar_YUmIDyGj_sendMessage);
}

void Heavy_SoundScraper::cMsg_eLs2KpEW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_cNW8A9SV_sendMessage);
}

void Heavy_SoundScraper::cSlice_3JCWLS5B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_pL8KQnkL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_GBJQ6j0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XzDRuImw_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UdcnmF7O_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_40MQlxnr_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Gqt66BBj, 0, m, &cVar_Gqt66BBj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_sfQmj5qM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dnIcq2Yc, 0, m, &cSlice_dnIcq2Yc_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_w2BCu1qI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2O4a2uS8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_zD20SnyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_xdQDyiIY_sendMessage);
}

void Heavy_SoundScraper::cBinop_xdQDyiIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dLeAuaZe, m);
}

void Heavy_SoundScraper::cMsg_2O4a2uS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zD20SnyO_sendMessage);
}

void Heavy_SoundScraper::cSlice_dnIcq2Yc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_d1DBYHps, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_4S6pd9SU, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_w2BCu1qI, 0, m, &cVar_w2BCu1qI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_kvSn1A0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qbIeqPQ2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_6Xso5zkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_w0WsVIdR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_THWFUvhp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_F8Qa31lk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_pL8KQnkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_sfQmj5qM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_U3sU2Iw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_qbIeqPQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_THWFUvhp, 0, m, &cVar_THWFUvhp_sendMessage);
}

void Heavy_SoundScraper::cBinop_w0WsVIdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F8Qa31lk, 0, m, &cVar_F8Qa31lk_sendMessage);
}

void Heavy_SoundScraper::cSlice_ObW7Zmap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_IkVTvmEx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_dbfBMFwJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AWGsHCXc_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HWRSyjPW_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_cEfn3tIf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1xGIIDOG, 1, m, &cPack_1xGIIDOG_sendMessage);
}

void Heavy_SoundScraper::cPack_1xGIIDOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nKF75gdA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SQXYvNQ1_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_3JCWLS5B, 0, m, &cSlice_3JCWLS5B_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GBJQ6j0J, 0, m, &cSlice_GBJQ6j0J_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_S8iRYhxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1xGIIDOG, 0, m, &cPack_1xGIIDOG_sendMessage);
}

void Heavy_SoundScraper::cCast_9M1tleIM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cEfn3tIf, 0, m, &cVar_cEfn3tIf_sendMessage);
}

void Heavy_SoundScraper::cBinop_zN48LFRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_fA5zib6z_sendMessage);
}

void Heavy_SoundScraper::cBinop_fA5zib6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_cHFdV0em_sendMessage);
}

void Heavy_SoundScraper::cBinop_IkVTvmEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qtuPMuwz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_fBjFxI45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9M1tleIM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S8iRYhxz_sendMessage);
}

void Heavy_SoundScraper::cBinop_2LrusuWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_1AknRIRl_sendMessage);
}

void Heavy_SoundScraper::cBinop_1AknRIRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fBjFxI45, HV_BINOP_MULTIPLY, 1, m, &cBinop_fBjFxI45_sendMessage);
}

void Heavy_SoundScraper::cCast_AWGsHCXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_z8szBFYZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_SQXYvNQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fgR3btBI_sendMessage);
}

void Heavy_SoundScraper::cCast_nKF75gdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_73ZbUJGT_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sKGsfu0O_sendMessage);
}

void Heavy_SoundScraper::cSend_ELO1RLF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hJkSXKfR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_fLJDE0UE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kNsP12v3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_W7bXoNKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fBjFxI45, HV_BINOP_MULTIPLY, 0, m, &cBinop_fBjFxI45_sendMessage);
}

void Heavy_SoundScraper::cSend_qtuPMuwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_64ga5gHB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ZtYLniXB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pL2zi25Q, 0, m, &cSlice_pL2zi25Q_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_h27hpwIo, 0, m, &cRandom_h27hpwIo_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_mgaSXjGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7NRhY7S9_sendMessage);
}

void Heavy_SoundScraper::cUnop_7NRhY7S9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_3p99qu56_sendMessage);
}

void Heavy_SoundScraper::cRandom_h27hpwIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_mgaSXjGN_sendMessage);
}

void Heavy_SoundScraper::cSlice_pL2zi25Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_h27hpwIo, 1, m, &cRandom_h27hpwIo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_n7tVgG0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ygGHsxHX, HV_BINOP_DIVIDE, 0, m, &cBinop_ygGHsxHX_sendMessage);
}

void Heavy_SoundScraper::cBinop_3HvdSlka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_o5N2f0Xi_sendMessage);
}

void Heavy_SoundScraper::cBinop_o5N2f0Xi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sxwm8QAk, HV_BINOP_POW, 1, m, &cBinop_sxwm8QAk_sendMessage);
  cMsg_MwDw1Pzt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_sxwm8QAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_n7tVgG0c_sendMessage);
}

void Heavy_SoundScraper::cMsg_MwDw1Pzt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sxwm8QAk, HV_BINOP_POW, 0, m, &cBinop_sxwm8QAk_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_VXJqz4yz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mXanyIJw, 0, m, &cSlice_mXanyIJw_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Hva4Yho5, 0, m, &cRandom_Hva4Yho5_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_9afN70r4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_bNM7VlVQ_sendMessage);
}

void Heavy_SoundScraper::cUnop_bNM7VlVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tOUmc37n_sendMessage);
}

void Heavy_SoundScraper::cRandom_Hva4Yho5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_9afN70r4_sendMessage);
}

void Heavy_SoundScraper::cSlice_mXanyIJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Hva4Yho5, 1, m, &cRandom_Hva4Yho5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_VmZTvyPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_3WbPpLjs_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Bbj83fS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_iXrxQqiP_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_lFBSRdXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IjwcsqCR, 0, m, &cPack_IjwcsqCR_sendMessage);
}

void Heavy_SoundScraper::cUnop_JN8p5gvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JFIYirYa, 0, m, &cPack_JFIYirYa_sendMessage);
}

void Heavy_SoundScraper::cPack_JFIYirYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_CJoqj8i6, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_IjwcsqCR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nGnRmxH5, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_cUSzwsGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_lFBSRdXc_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_JN8p5gvt_sendMessage);
}

void Heavy_SoundScraper::cMsg_32sKD9sl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_cUSzwsGf_sendMessage);
}

void Heavy_SoundScraper::cCast_1Gh9yPdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_X7BB0wu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CkafdCxL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_A5Ck1t1Y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2STJH9bs_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_CHsE4OOc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_3bsCiix5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_3bsCiix5_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_1GwNIvSc, 1, m, &cDelay_1GwNIvSc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y3TdKmu1_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_1GwNIvSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1GwNIvSc, m);
  cVar_onMessage(_c, &Context(_c)->cVar_63kvqkqt, 0, m, &cVar_63kvqkqt_sendMessage);
}

void Heavy_SoundScraper::cMsg_3bsCiix5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1GwNIvSc, 0, m, &cDelay_1GwNIvSc_sendMessage);
}

void Heavy_SoundScraper::cCast_y3TdKmu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1GwNIvSc, 0, m, &cDelay_1GwNIvSc_sendMessage);
}

void Heavy_SoundScraper::cVar_63kvqkqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kZpFGCIk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_hKkPbFVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X7BB0wu9, 0, m, &cVar_X7BB0wu9_sendMessage);
}

void Heavy_SoundScraper::cSend_LzZvnDSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_9hen0kzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mQ5Hg5Ja_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_fT55MdV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_LzZvnDSn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_WiaTFC0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_9hen0kzr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_gyt14z2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xXLSTEOJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_X0RmzJZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_gyt14z2n_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_IjsSyyso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xXLSTEOJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_gppvQPoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_AxbOM8g4, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_kZpFGCIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_AxbOM8g4, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_2STJH9bs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CHsE4OOc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_CkafdCxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gppvQPoF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_A5Ck1t1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_63kvqkqt, 1, m, &cVar_63kvqkqt_sendMessage);
}

void Heavy_SoundScraper::cVar_n0b26JwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_N5mCm6Jb_sendMessage);
}

void Heavy_SoundScraper::cVar_PLMaCEYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_FoGsADj5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_2jQZKbUj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_bO92K039_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_bO92K039_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_atebVVSk, 1, m, &cDelay_atebVVSk_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qr5wL3BT_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_atebVVSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_atebVVSk, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ILwasIc6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jGCHcnBe_sendMessage);
}

void Heavy_SoundScraper::cMsg_bO92K039_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_atebVVSk, 0, m, &cDelay_atebVVSk_sendMessage);
}

void Heavy_SoundScraper::cCast_qr5wL3BT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_atebVVSk, 0, m, &cDelay_atebVVSk_sendMessage);
}

void Heavy_SoundScraper::cPack_BWHF5MJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZgP4TPFd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_hy0J4TgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AWZ4R8Ky_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_zbFWUIDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nbszN7on_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_KXLPSpMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hy0J4TgP, 0, m, &cPack_hy0J4TgP_sendMessage);
}

void Heavy_SoundScraper::cVar_BlGafgTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_9klJnaqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pjH0kNfb, HV_BINOP_DIVIDE, 1, m, &cBinop_pjH0kNfb_sendMessage);
}

void Heavy_SoundScraper::cVar_eUFAdLb8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pjH0kNfb, HV_BINOP_DIVIDE, 0, m, &cBinop_pjH0kNfb_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_FoGsADj5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CeOZGrJ6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fsQmCRCr_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X5pny8G4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PGbduITZ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_CeOZGrJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9klJnaqK, 0, m, &cVar_9klJnaqK_sendMessage);
}

void Heavy_SoundScraper::cCast_fsQmCRCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eUFAdLb8, 0, m, &cVar_eUFAdLb8_sendMessage);
}

void Heavy_SoundScraper::cCast_PGbduITZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eUFAdLb8, 0, m, &cVar_eUFAdLb8_sendMessage);
}

void Heavy_SoundScraper::cCast_X5pny8G4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9klJnaqK, 0, m, &cVar_9klJnaqK_sendMessage);
}

void Heavy_SoundScraper::cCast_ILwasIc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PLMaCEYq, 0, m, &cVar_PLMaCEYq_sendMessage);
}

void Heavy_SoundScraper::cCast_jGCHcnBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KXLPSpMn, 0, m, &cVar_KXLPSpMn_sendMessage);
}

void Heavy_SoundScraper::cSend_Y6OEtY2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qADzeWFu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_AWZ4R8Ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kqF2iJb4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ZgP4TPFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kqF2iJb4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_MyvCZATM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BWHF5MJh, 0, m, &cPack_BWHF5MJh_sendMessage);
}

void Heavy_SoundScraper::cCast_JTuFr8Gr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2jQZKbUj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_N5mCm6Jb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zbFWUIDP, 0, m, &cPack_zbFWUIDP_sendMessage);
}

void Heavy_SoundScraper::cBinop_8odFMANn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zbFWUIDP, 1, m, &cPack_zbFWUIDP_sendMessage);
}

void Heavy_SoundScraper::cMsg_nbszN7on_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_Y6OEtY2E_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_Y6OEtY2E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_xUfXBqk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PLMaCEYq, 1, m, &cVar_PLMaCEYq_sendMessage);
}

void Heavy_SoundScraper::cCast_Vj1t5fU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_fcDoIUfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MyvCZATM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JTuFr8Gr_sendMessage);
}

void Heavy_SoundScraper::cBinop_pjH0kNfb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n0b26JwE, 0, m, &cVar_n0b26JwE_sendMessage);
}

void Heavy_SoundScraper::cMsg_TLDrnzwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_8odFMANn_sendMessage);
}

void Heavy_SoundScraper::cSlice_UXJNWzdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_O7T9ZHsV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_skka8Zv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Vj1t5fU9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xUfXBqk9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fcDoIUfg_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_BlGafgTP, 0, m, &cVar_BlGafgTP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_TW9mXBo9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vcICZ9mP, 0, m, &cSlice_vcICZ9mP_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_PHKSKwVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HncsZsgH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_DyJpbQ5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_wQk8jo8s_sendMessage);
}

void Heavy_SoundScraper::cBinop_wQk8jo8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_P78MKYz3, m);
}

void Heavy_SoundScraper::cMsg_HncsZsgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DyJpbQ5x_sendMessage);
}

void Heavy_SoundScraper::cSlice_vcICZ9mP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_4jFfPfJk, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_FVl715Ig, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_PHKSKwVQ, 0, m, &cVar_PHKSKwVQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_8o3gCmNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5m0aykCv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_xGE9d15I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_sGLPmkib_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_Rotxd0t5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_vLI3n0A5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_O7T9ZHsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_TW9mXBo9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_0mdXHtxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_5m0aykCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Rotxd0t5, 0, m, &cVar_Rotxd0t5_sendMessage);
}

void Heavy_SoundScraper::cBinop_sGLPmkib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vLI3n0A5, 0, m, &cVar_vLI3n0A5_sendMessage);
}

void Heavy_SoundScraper::cSlice_rLHxdbD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_u6XY7zOo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_YppFmsSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Enw3mwXU_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_3HvdSlka_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_sxfPugwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oSONyWSg, 1, m, &cPack_oSONyWSg_sendMessage);
}

void Heavy_SoundScraper::cPack_oSONyWSg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yHGwJ4yU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nHIhjHY9_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_UXJNWzdj, 0, m, &cSlice_UXJNWzdj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_skka8Zv0, 0, m, &cSlice_skka8Zv0_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_f3tWsV78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sxfPugwM, 0, m, &cVar_sxfPugwM_sendMessage);
}

void Heavy_SoundScraper::cCast_YJA3k0is_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oSONyWSg, 0, m, &cPack_oSONyWSg_sendMessage);
}

void Heavy_SoundScraper::cBinop_3p99qu56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_wTSX8oe0_sendMessage);
}

void Heavy_SoundScraper::cBinop_wTSX8oe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_cUSzwsGf_sendMessage);
}

void Heavy_SoundScraper::cBinop_u6XY7zOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zyC3gkLa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_TAAYF05M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f3tWsV78_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YJA3k0is_sendMessage);
}

void Heavy_SoundScraper::cBinop_tOUmc37n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_ISN40EkT_sendMessage);
}

void Heavy_SoundScraper::cBinop_ISN40EkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TAAYF05M, HV_BINOP_MULTIPLY, 1, m, &cBinop_TAAYF05M_sendMessage);
}

void Heavy_SoundScraper::cCast_Enw3mwXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VXJqz4yz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_nHIhjHY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hKkPbFVY_sendMessage);
}

void Heavy_SoundScraper::cCast_yHGwJ4yU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZtYLniXB_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Gh9yPdu_sendMessage);
}

void Heavy_SoundScraper::cSend_iXrxQqiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0ReGqyN9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_3WbPpLjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wMehuFB6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ygGHsxHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TAAYF05M, HV_BINOP_MULTIPLY, 0, m, &cBinop_TAAYF05M_sendMessage);
}

void Heavy_SoundScraper::cSend_zyC3gkLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IwtHfQKo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_0rguPxSz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NRgFdvLB, 0, m, &cSlice_NRgFdvLB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BO9UesL0, 0, m, &cRandom_BO9UesL0_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_NjjJ1qsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vcbPLmRK_sendMessage);
}

void Heavy_SoundScraper::cUnop_vcbPLmRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_nrrmvEus_sendMessage);
}

void Heavy_SoundScraper::cRandom_BO9UesL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_NjjJ1qsL_sendMessage);
}

void Heavy_SoundScraper::cSlice_NRgFdvLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BO9UesL0, 1, m, &cRandom_BO9UesL0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_RVkACzgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tgp3hZRK, HV_BINOP_DIVIDE, 0, m, &cBinop_Tgp3hZRK_sendMessage);
}

void Heavy_SoundScraper::cBinop_mpQt8NmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_bNN6Tf1T_sendMessage);
}

void Heavy_SoundScraper::cBinop_bNN6Tf1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SX76QCve, HV_BINOP_POW, 1, m, &cBinop_SX76QCve_sendMessage);
  cMsg_5ZQ8caR2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_SX76QCve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_RVkACzgc_sendMessage);
}

void Heavy_SoundScraper::cMsg_5ZQ8caR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SX76QCve, HV_BINOP_POW, 0, m, &cBinop_SX76QCve_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_jzIoXoD1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LKT351nG, 0, m, &cSlice_LKT351nG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fFSxOQSF, 0, m, &cRandom_fFSxOQSF_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_7YfTLznb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GqW48JzF_sendMessage);
}

void Heavy_SoundScraper::cUnop_GqW48JzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eUBHLBIv_sendMessage);
}

void Heavy_SoundScraper::cRandom_fFSxOQSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_7YfTLznb_sendMessage);
}

void Heavy_SoundScraper::cSlice_LKT351nG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fFSxOQSF, 1, m, &cRandom_fFSxOQSF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_rsDXauvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_hJKbo70F_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_aqLi8ka9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_rJ1Lus3U_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_jdNTfcDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_erTMuVi7, 0, m, &cPack_erTMuVi7_sendMessage);
}

void Heavy_SoundScraper::cUnop_XXhORRF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RU8KL3xi, 0, m, &cPack_RU8KL3xi_sendMessage);
}

void Heavy_SoundScraper::cPack_RU8KL3xi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_M3QAuhSI, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_erTMuVi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_93JHr555, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_A4i1THC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_jdNTfcDj_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_XXhORRF0_sendMessage);
}

void Heavy_SoundScraper::cMsg_unhWdbYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_A4i1THC6_sendMessage);
}

void Heavy_SoundScraper::cCast_gFzuucVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_vmGPbRTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4CndyN5q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Hr4EHNbU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HmvVahls_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_C2mvdiXa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_PMn13XJL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_PMn13XJL_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TDeEVUPs, 1, m, &cDelay_TDeEVUPs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9E2EskJ8_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_TDeEVUPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TDeEVUPs, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EIEqZAe3, 0, m, &cVar_EIEqZAe3_sendMessage);
}

void Heavy_SoundScraper::cMsg_PMn13XJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TDeEVUPs, 0, m, &cDelay_TDeEVUPs_sendMessage);
}

void Heavy_SoundScraper::cCast_9E2EskJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TDeEVUPs, 0, m, &cDelay_TDeEVUPs_sendMessage);
}

void Heavy_SoundScraper::cVar_EIEqZAe3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k3F2D4B2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_eQjDUSKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vmGPbRTy, 0, m, &cVar_vmGPbRTy_sendMessage);
}

void Heavy_SoundScraper::cSend_2Elia1xi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_2KnRElvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PPsVGZFP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_4w4osUKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_2Elia1xi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_9PiB34cM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_2KnRElvk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_sHbViO9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qgvPM0Rv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_qhhOTZPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_sHbViO9Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_T4Qg5POX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qgvPM0Rv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_huJNk2RC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_gmsgGRvV, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_k3F2D4B2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_gmsgGRvV, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_4CndyN5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_huJNk2RC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Hr4EHNbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EIEqZAe3, 1, m, &cVar_EIEqZAe3_sendMessage);
}

void Heavy_SoundScraper::cCast_HmvVahls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_C2mvdiXa_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_PWnKdFrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_1MwK6lY1_sendMessage);
}

void Heavy_SoundScraper::cVar_vZz5B9N8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8SLYaktT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_hib3CwlI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_jAIR4JG0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_jAIR4JG0_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_npkoKPBI, 1, m, &cDelay_npkoKPBI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hXrdCqww_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_npkoKPBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_npkoKPBI, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uUP6ZoSA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_voXbEiL7_sendMessage);
}

void Heavy_SoundScraper::cMsg_jAIR4JG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_npkoKPBI, 0, m, &cDelay_npkoKPBI_sendMessage);
}

void Heavy_SoundScraper::cCast_hXrdCqww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_npkoKPBI, 0, m, &cDelay_npkoKPBI_sendMessage);
}

void Heavy_SoundScraper::cPack_ru3uoepH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_A2WdfRAj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_BgvIxzDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gvViKjVM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_7VIja7HJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IzLwKhMI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Ax4gUyRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BgvIxzDi, 0, m, &cPack_BgvIxzDi_sendMessage);
}

void Heavy_SoundScraper::cVar_PzSV62m9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_cDkZlO3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_doxBZR3E, HV_BINOP_DIVIDE, 1, m, &cBinop_doxBZR3E_sendMessage);
}

void Heavy_SoundScraper::cVar_p2f0YxUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_doxBZR3E, HV_BINOP_DIVIDE, 0, m, &cBinop_doxBZR3E_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_8SLYaktT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pVOcgkBD_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RWSg7DPw_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FfTo5gGv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8XMmFf4I_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_pVOcgkBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cDkZlO3V, 0, m, &cVar_cDkZlO3V_sendMessage);
}

void Heavy_SoundScraper::cCast_RWSg7DPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p2f0YxUH, 0, m, &cVar_p2f0YxUH_sendMessage);
}

void Heavy_SoundScraper::cCast_8XMmFf4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p2f0YxUH, 0, m, &cVar_p2f0YxUH_sendMessage);
}

void Heavy_SoundScraper::cCast_FfTo5gGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cDkZlO3V, 0, m, &cVar_cDkZlO3V_sendMessage);
}

void Heavy_SoundScraper::cCast_uUP6ZoSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vZz5B9N8, 0, m, &cVar_vZz5B9N8_sendMessage);
}

void Heavy_SoundScraper::cCast_voXbEiL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ax4gUyRl, 0, m, &cVar_Ax4gUyRl_sendMessage);
}

void Heavy_SoundScraper::cSend_A2eZywyE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4awM0p6i_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_gvViKjVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gkT7foyj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_A2WdfRAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gkT7foyj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_DLZ7TfNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ru3uoepH, 0, m, &cPack_ru3uoepH_sendMessage);
}

void Heavy_SoundScraper::cCast_HQN44zZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_hib3CwlI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_1MwK6lY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7VIja7HJ, 0, m, &cPack_7VIja7HJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_7ItYRwmh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7VIja7HJ, 1, m, &cPack_7VIja7HJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_IzLwKhMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_A2eZywyE_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_A2eZywyE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ViU0HthQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vZz5B9N8, 1, m, &cVar_vZz5B9N8_sendMessage);
}

void Heavy_SoundScraper::cCast_zZqDSfJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_zcEZF3iy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DLZ7TfNZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HQN44zZb_sendMessage);
}

void Heavy_SoundScraper::cBinop_doxBZR3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PWnKdFrp, 0, m, &cVar_PWnKdFrp_sendMessage);
}

void Heavy_SoundScraper::cMsg_XBocforE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_7ItYRwmh_sendMessage);
}

void Heavy_SoundScraper::cSlice_mcLw3GzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_pGw06XWN_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_9hUSzuwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zZqDSfJ4_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ViU0HthQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zcEZF3iy_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_PzSV62m9, 0, m, &cVar_PzSV62m9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_P0TGlPHn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iEBOIu7j, 0, m, &cSlice_iEBOIu7j_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_Y5ESACwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aq5k6YJl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_ti8EIzBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_eYLsrFTb_sendMessage);
}

void Heavy_SoundScraper::cBinop_eYLsrFTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6bjjo3r0, m);
}

void Heavy_SoundScraper::cMsg_aq5k6YJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ti8EIzBZ_sendMessage);
}

void Heavy_SoundScraper::cSlice_iEBOIu7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_WMooWWa7, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_gu9QeQkc, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_Y5ESACwB, 0, m, &cVar_Y5ESACwB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Uz3pjaUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZhrgCi8L_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_udyLEGZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_FXTjZi3s_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_Bj0HBwNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_D4xAr9cd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_pGw06XWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_P0TGlPHn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_jVvlKWLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_ZhrgCi8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bj0HBwNQ, 0, m, &cVar_Bj0HBwNQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_FXTjZi3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D4xAr9cd, 0, m, &cVar_D4xAr9cd_sendMessage);
}

void Heavy_SoundScraper::cSlice_S0trZtkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_e80hpKzQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_BWqIF8KM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7Z7lRjnV_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mpQt8NmT_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_eis14qJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_c0UiJcg3, 1, m, &cPack_c0UiJcg3_sendMessage);
}

void Heavy_SoundScraper::cPack_c0UiJcg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ez0zceQ1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WnheGOVY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mcLw3GzN, 0, m, &cSlice_mcLw3GzN_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9hUSzuwM, 0, m, &cSlice_9hUSzuwM_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_5cY77D5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eis14qJ6, 0, m, &cVar_eis14qJ6_sendMessage);
}

void Heavy_SoundScraper::cCast_N2AOmklH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_c0UiJcg3, 0, m, &cPack_c0UiJcg3_sendMessage);
}

void Heavy_SoundScraper::cBinop_nrrmvEus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_wo0zxpCN_sendMessage);
}

void Heavy_SoundScraper::cBinop_wo0zxpCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_A4i1THC6_sendMessage);
}

void Heavy_SoundScraper::cBinop_e80hpKzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MlU1a2AP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_VOBxe9YO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5cY77D5l_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N2AOmklH_sendMessage);
}

void Heavy_SoundScraper::cBinop_eUBHLBIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_rOA6xYmR_sendMessage);
}

void Heavy_SoundScraper::cBinop_rOA6xYmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VOBxe9YO, HV_BINOP_MULTIPLY, 1, m, &cBinop_VOBxe9YO_sendMessage);
}

void Heavy_SoundScraper::cCast_7Z7lRjnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jzIoXoD1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_Ez0zceQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0rguPxSz_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gFzuucVS_sendMessage);
}

void Heavy_SoundScraper::cCast_WnheGOVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eQjDUSKC_sendMessage);
}

void Heavy_SoundScraper::cSend_rJ1Lus3U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8ulyCInE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_hJKbo70F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tGuNsXcY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Tgp3hZRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VOBxe9YO, HV_BINOP_MULTIPLY, 0, m, &cBinop_VOBxe9YO_sendMessage);
}

void Heavy_SoundScraper::cSend_MlU1a2AP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XXwtG2Vj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_cxUxo8lC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5wu0Vabm_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lJUgKhGT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_L00kaZ3c_sendMessage);
}

void Heavy_SoundScraper::cIf_bmn7rqIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KYPKnTp0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_YsTocQZi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_Ic3j9VDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tWVarhvR, HV_BINOP_POW, 0, m, &cBinop_tWVarhvR_sendMessage);
}

void Heavy_SoundScraper::cBinop_tWVarhvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rRC9jwKQ, 0, m, &cPack_rRC9jwKQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_a7PkYuD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_aKNcPmVo_sendMessage);
}

void Heavy_SoundScraper::cCast_L00kaZ3c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_bmn7rqIG, 0, m, &cIf_bmn7rqIG_sendMessage);
}

void Heavy_SoundScraper::cCast_lJUgKhGT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ZyTyt4ck_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZyTyt4ck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_bmn7rqIG, 1, m, &cIf_bmn7rqIG_sendMessage);
}

void Heavy_SoundScraper::cBinop_YsTocQZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_a7PkYuD2_sendMessage);
}

void Heavy_SoundScraper::cMsg_KYPKnTp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_rRC9jwKQ, 0, m, &cPack_rRC9jwKQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_aKNcPmVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tWVarhvR, HV_BINOP_POW, 1, m, &cBinop_tWVarhvR_sendMessage);
  cMsg_Ic3j9VDO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_rRC9jwKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_NbhbPUXc, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_dfBoi07G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5wmUfhAW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_5wu0Vabm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_R0VYesQJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_R0VYesQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zd3gsUBS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_5wmUfhAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4eQaa9bD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_MuBnRqAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D6zI1srt_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bWRd61JO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U4p5j6KP_sendMessage);
}

void Heavy_SoundScraper::cIf_ULzDkSgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_CNxD1zPZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_etYsmeN5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_trDi4Vco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0KuPH6CY, HV_BINOP_POW, 0, m, &cBinop_0KuPH6CY_sendMessage);
}

void Heavy_SoundScraper::cBinop_0KuPH6CY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2MHE1Awc, 0, m, &cPack_2MHE1Awc_sendMessage);
}

void Heavy_SoundScraper::cBinop_Snf4jlMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_cl2i83f6_sendMessage);
}

void Heavy_SoundScraper::cCast_bWRd61JO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_KrJk0FNr_sendMessage);
}

void Heavy_SoundScraper::cCast_U4p5j6KP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ULzDkSgu, 0, m, &cIf_ULzDkSgu_sendMessage);
}

void Heavy_SoundScraper::cBinop_KrJk0FNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ULzDkSgu, 1, m, &cIf_ULzDkSgu_sendMessage);
}

void Heavy_SoundScraper::cBinop_etYsmeN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_Snf4jlMc_sendMessage);
}

void Heavy_SoundScraper::cMsg_CNxD1zPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_2MHE1Awc, 0, m, &cPack_2MHE1Awc_sendMessage);
}

void Heavy_SoundScraper::cBinop_cl2i83f6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0KuPH6CY, HV_BINOP_POW, 1, m, &cBinop_0KuPH6CY_sendMessage);
  cMsg_trDi4Vco_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_2MHE1Awc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tsOApumz, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_uzABqCkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YU0BIPtQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_D6zI1srt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_ncuIyzrb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ncuIyzrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_boqSUwBQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_YU0BIPtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JsJfNXjF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_VKwWbKEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_deKZfbFX_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_5MUo1SUM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_5MUo1SUM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_59BALFnY_sendMessage);
}

void Heavy_SoundScraper::cCast_0VroGo2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VKwWbKEa, 0, m, &cIf_VKwWbKEa_sendMessage);
}

void Heavy_SoundScraper::cCast_0UqvnMpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_sIxLrexB_sendMessage);
}

void Heavy_SoundScraper::cMsg_deKZfbFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_D6zI1srt_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bWRd61JO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U4p5j6KP_sendMessage);
}

void Heavy_SoundScraper::cBinop_59BALFnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_OykIOuYM_sendMessage);
}

void Heavy_SoundScraper::cBinop_OykIOuYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tisbtVNs_sendMessage);
}

void Heavy_SoundScraper::cBinop_tisbtVNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D6zI1srt_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bWRd61JO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U4p5j6KP_sendMessage);
}

void Heavy_SoundScraper::cBinop_sIxLrexB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VKwWbKEa, 1, m, &cIf_VKwWbKEa_sendMessage);
}

void Heavy_SoundScraper::cBinop_8s9wSqpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0UqvnMpU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0VroGo2H_sendMessage);
}

void Heavy_SoundScraper::cBinop_bMHWSeyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8s9wSqpO_sendMessage);
}

void Heavy_SoundScraper::cVar_U6xpMsZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XWzirYph_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kSE94tU5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cDiro0CY_sendMessage);
}

void Heavy_SoundScraper::cIf_eFBD3Jzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_m0coJrMx_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_dk9kxT9k_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_H2zlGepr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yYKsYCbE, HV_BINOP_POW, 0, m, &cBinop_yYKsYCbE_sendMessage);
}

void Heavy_SoundScraper::cBinop_yYKsYCbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2gKaTTOz, 0, m, &cPack_2gKaTTOz_sendMessage);
}

void Heavy_SoundScraper::cBinop_8Yoi5gCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_1iilIFzE_sendMessage);
}

void Heavy_SoundScraper::cCast_cDiro0CY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eFBD3Jzu, 0, m, &cIf_eFBD3Jzu_sendMessage);
}

void Heavy_SoundScraper::cCast_kSE94tU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_gmt92Y5M_sendMessage);
}

void Heavy_SoundScraper::cBinop_gmt92Y5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eFBD3Jzu, 1, m, &cIf_eFBD3Jzu_sendMessage);
}

void Heavy_SoundScraper::cBinop_dk9kxT9k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_8Yoi5gCD_sendMessage);
}

void Heavy_SoundScraper::cMsg_m0coJrMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_2gKaTTOz, 0, m, &cPack_2gKaTTOz_sendMessage);
}

void Heavy_SoundScraper::cBinop_1iilIFzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yYKsYCbE, HV_BINOP_POW, 1, m, &cBinop_yYKsYCbE_sendMessage);
  cMsg_H2zlGepr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_2gKaTTOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_1KwlxQbV, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_0qOXdVy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7HynxYQ8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_XWzirYph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_mnGR0RG9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_mnGR0RG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_GZJMvqdA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_7HynxYQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MUee4EMg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_gKs7CXnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rp4koTH0_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K7RtLeBm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5yW0dB7j_sendMessage);
}

void Heavy_SoundScraper::cIf_nX5kkWYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_g8e9Lp0u_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ftEKwb1B_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_kaH6PNHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HvHsB6cJ, HV_BINOP_POW, 0, m, &cBinop_HvHsB6cJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_HvHsB6cJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SM02s3BG, 0, m, &cPack_SM02s3BG_sendMessage);
}

void Heavy_SoundScraper::cBinop_L76wWNrJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_5W2pueJ4_sendMessage);
}

void Heavy_SoundScraper::cCast_K7RtLeBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_A5pgOPC4_sendMessage);
}

void Heavy_SoundScraper::cCast_5yW0dB7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nX5kkWYB, 0, m, &cIf_nX5kkWYB_sendMessage);
}

void Heavy_SoundScraper::cBinop_A5pgOPC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nX5kkWYB, 1, m, &cIf_nX5kkWYB_sendMessage);
}

void Heavy_SoundScraper::cBinop_ftEKwb1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_L76wWNrJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_g8e9Lp0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_SM02s3BG, 0, m, &cPack_SM02s3BG_sendMessage);
}

void Heavy_SoundScraper::cBinop_5W2pueJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HvHsB6cJ, HV_BINOP_POW, 1, m, &cBinop_HvHsB6cJ_sendMessage);
  cMsg_kaH6PNHF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_SM02s3BG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_oZmQ27Ed, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_NjaMqmg5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PLTrJnHK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Rp4koTH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_zYiZQhsw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_zYiZQhsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MRKcW8UN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_PLTrJnHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3CC5ZSf2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_xdE3u1zg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_T9TD3aO9, 0, m, &cIf_T9TD3aO9_sendMessage);
}

void Heavy_SoundScraper::cSlice_wHN9EtAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_94UDEjl8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XBmNmhMi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_5elt9JrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_dLQC0HeD, 0, m, &cIf_dLQC0HeD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_dLQC0HeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YAkrLhr0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lt9WSnKJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_yUW1B0b8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_CdZamBkF, 2, m, &cPack_CdZamBkF_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_wsjhBdOP, 1, m, &cPack_wsjhBdOP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_ugnvYM16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_wHN9EtAV, 0, m, &cSlice_wHN9EtAV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5elt9JrC, 0, m, &cSlice_5elt9JrC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_bxwxf15A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_v3GAdTJa_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_QWSprYon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cx4ATUfj_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CrRx71Sp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gUL0x3jB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_WLApP4PJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UOL4Bwwp, 1, m, &cIf_UOL4Bwwp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_zfbVCXBB_sendMessage);
}

void Heavy_SoundScraper::cIf_UOL4Bwwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_wHN9EtAV, 0, m, &cSlice_wHN9EtAV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5elt9JrC, 0, m, &cSlice_5elt9JrC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_wsjhBdOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ugnvYM16, 0, m, &cIf_ugnvYM16_sendMessage);
}

void Heavy_SoundScraper::cBinop_ExW91wVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dLQC0HeD, 1, m, &cIf_dLQC0HeD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_yUW1B0b8, 1, m, &cIf_yUW1B0b8_sendMessage);
}

void Heavy_SoundScraper::cCast_94UDEjl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_ExW91wVC_sendMessage);
}

void Heavy_SoundScraper::cCast_XBmNmhMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yUW1B0b8, 0, m, &cIf_yUW1B0b8_sendMessage);
}

void Heavy_SoundScraper::cMsg_HgnSmMqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_WLApP4PJ, 1, m, &cVar_WLApP4PJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_v3GAdTJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_WLApP4PJ, 1, m, &cVar_WLApP4PJ_sendMessage);
}

void Heavy_SoundScraper::cCast_cx4ATUfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WLApP4PJ, 0, m, &cVar_WLApP4PJ_sendMessage);
}

void Heavy_SoundScraper::cCast_gUL0x3jB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HgnSmMqd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_CrRx71Sp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wsjhBdOP, 0, m, &cPack_wsjhBdOP_sendMessage);
}

void Heavy_SoundScraper::cBinop_zfbVCXBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ugnvYM16, 1, m, &cIf_ugnvYM16_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_jBGEzjXD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Gr2pNEIp, 0, m, &cSlice_Gr2pNEIp_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3dM64Z4K, 0, m, &cSlice_3dM64Z4K_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_k39hE7Uk, 0, m, &cSlice_k39hE7Uk_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_P0MWQIwd, 0, m, &cSlice_P0MWQIwd_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_Gr2pNEIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_JnoMtmrK, 0, m, &cSlice_JnoMtmrK_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_tsaPX2tq, 0, m, &cSlice_tsaPX2tq_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_JnoMtmrK, 0, m, &cSlice_JnoMtmrK_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_tsaPX2tq, 0, m, &cSlice_tsaPX2tq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_3dM64Z4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ObW7Zmap, 0, m, &cSlice_ObW7Zmap_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dbfBMFwJ, 0, m, &cSlice_dbfBMFwJ_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ObW7Zmap, 0, m, &cSlice_ObW7Zmap_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dbfBMFwJ, 0, m, &cSlice_dbfBMFwJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_k39hE7Uk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_rLHxdbD2, 0, m, &cSlice_rLHxdbD2_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_YppFmsSB, 0, m, &cSlice_YppFmsSB_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_rLHxdbD2, 0, m, &cSlice_rLHxdbD2_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_YppFmsSB, 0, m, &cSlice_YppFmsSB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_P0MWQIwd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_S0trZtkc, 0, m, &cSlice_S0trZtkc_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_BWqIF8KM, 0, m, &cSlice_BWqIF8KM_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_S0trZtkc, 0, m, &cSlice_S0trZtkc_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_BWqIF8KM, 0, m, &cSlice_BWqIF8KM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_jOZsiZWR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DdnHdZNc_sendMessage);
      break;
    }
    default: {
      cMsg_yau8mBtw_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_DdnHdZNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sxGzdqNd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_T9TD3aO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bxwxf15A, 0, m, &cSlice_bxwxf15A_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QWSprYon, 0, m, &cSlice_QWSprYon_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_UOL4Bwwp, 0, m, &cIf_UOL4Bwwp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_33Ip8yHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_MutVd17B_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_T9TD3aO9, 1, m, &cIf_T9TD3aO9_sendMessage);
}

void Heavy_SoundScraper::cBinop_MutVd17B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_33Ip8yHC, 1, m, &cVar_33Ip8yHC_sendMessage);
}

void Heavy_SoundScraper::cMsg_sxGzdqNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_33Ip8yHC, 0, m, &cVar_33Ip8yHC_sendMessage);
}

void Heavy_SoundScraper::cMsg_yau8mBtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_33Ip8yHC, 0, m, &cVar_33Ip8yHC_sendMessage);
}

void Heavy_SoundScraper::cPack_CdZamBkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jBGEzjXD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_p66eTota_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CdZamBkF, 0, m, &cPack_CdZamBkF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_339pYCDe_sendMessage);
}

void Heavy_SoundScraper::cBinop_339pYCDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_BduspTl7_sendMessage);
}

void Heavy_SoundScraper::cBinop_BduspTl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p66eTota, 1, m, &cVar_p66eTota_sendMessage);
}

void Heavy_SoundScraper::cMsg_S2E6vUIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_jOZsiZWR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_lt9WSnKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p66eTota, 0, m, &cVar_p66eTota_sendMessage);
}

void Heavy_SoundScraper::cCast_YAkrLhr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CdZamBkF, 1, m, &cPack_CdZamBkF_sendMessage);
}

void Heavy_SoundScraper::hTable_FXXLUP0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_ForqUfzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_7hwEo7ic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_f3whMxOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_3zp5yu42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_LnmM0L5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_9y3VeT1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_PXJfC0hd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_yjRf2i9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_X8wCeseb, 0, m, &cIf_X8wCeseb_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_0ehY9ZW2, 0, m, &cIf_0ehY9ZW2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_vyjGKfqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_jrCp3VKC, 0, m, &cIf_jrCp3VKC_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_d8awyjA6, 0, m, &cIf_d8awyjA6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_C0sJXISA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_D5EMuAsg_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8r2WS4Bo, 0, m, &cIf_8r2WS4Bo_sendMessage);
}

void Heavy_SoundScraper::cUnop_fzu7ZaoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_kU4Ok8rw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_q4vUdAtL, HV_BINOP_EQ, 1, m, &cBinop_q4vUdAtL_sendMessage);
}

void Heavy_SoundScraper::cUnop_g3lPN8d5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_kU4Ok8rw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_q4vUdAtL, HV_BINOP_EQ, 1, m, &cBinop_q4vUdAtL_sendMessage);
}

void Heavy_SoundScraper::cIf_8r2WS4Bo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_g3lPN8d5_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_fzu7ZaoX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_D5EMuAsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8r2WS4Bo, 1, m, &cIf_8r2WS4Bo_sendMessage);
}

void Heavy_SoundScraper::cIf_0ehY9ZW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Ch1q60fa_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_d8awyjA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_jihDEXij_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_X8wCeseb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Ch1q60fa_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_jrCp3VKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_jihDEXij_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_PXJfC0hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q4vUdAtL, HV_BINOP_EQ, 0, m, &cBinop_q4vUdAtL_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_fgBn0EZV_sendMessage);
}

void Heavy_SoundScraper::cBinop_kU4Ok8rw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pEcpJhUF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gdpryK2h_sendMessage);
}

void Heavy_SoundScraper::cBinop_q4vUdAtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CW3HSB3a_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4nFCsqpG_sendMessage);
}

void Heavy_SoundScraper::cCast_4nFCsqpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jrCp3VKC, 1, m, &cIf_jrCp3VKC_sendMessage);
}

void Heavy_SoundScraper::cCast_CW3HSB3a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0ehY9ZW2, 1, m, &cIf_0ehY9ZW2_sendMessage);
}

void Heavy_SoundScraper::cCast_gdpryK2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_d8awyjA6, 1, m, &cIf_d8awyjA6_sendMessage);
}

void Heavy_SoundScraper::cCast_pEcpJhUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_X8wCeseb, 1, m, &cIf_X8wCeseb_sendMessage);
}

void Heavy_SoundScraper::cBinop_fgBn0EZV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2xM89tQ1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_jihDEXij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_79w7CU3Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Ch1q60fa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yZlsZ9lz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_2xM89tQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_8a3gsJdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_h3aSlJA7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_7cJ6QGYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cSend_8a3gsJdp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_dTkbaS81_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LzaDO0zC_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zKg3u4AN_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CPN48ikl_sendMessage);
      break;
    }
    case 0x40A00000: { // "5.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eQiWVBDG_sendMessage);
      break;
    }
    case 0x40C00000: { // "6.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H7EeutBO_sendMessage);
      break;
    }
    case 0x40E00000: { // "7.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lye3Mugy_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_LzaDO0zC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jySFOE5M_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_zKg3u4AN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3L0Rqeq5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_CPN48ikl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J0mmPfw4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_eQiWVBDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9pk9xwi1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_H7EeutBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A0ArLXf5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Lye3Mugy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VDmul0C0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_c1Dwz3nJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mQ7p5DTk, 0, m, &cSlice_mQ7p5DTk_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ezM0nmHg, 0, m, &cRandom_ezM0nmHg_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_xKfc0Xnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Ld3l1wmO_sendMessage);
}

void Heavy_SoundScraper::cUnop_Ld3l1wmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_0tLKVLrS_sendMessage);
}

void Heavy_SoundScraper::cRandom_ezM0nmHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_xKfc0Xnl_sendMessage);
}

void Heavy_SoundScraper::cSlice_mQ7p5DTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ezM0nmHg, 1, m, &cRandom_ezM0nmHg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_A0ArLXf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "marimba");
  msg_setFloat(m, 1, 264.0f);
  cSend_R3v6ylvj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_VDmul0C0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "xylo");
  msg_setFloat(m, 1, 2116.9f);
  cSend_R3v6ylvj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_9pk9xwi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "bowl");
  msg_setFloat(m, 1, 705.52f);
  cSend_R3v6ylvj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_3L0Rqeq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "gong");
  msg_setFloat(m, 1, 179.88f);
  cSend_R3v6ylvj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_R3v6ylvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KKZatrEy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_J0mmPfw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "crotale");
  msg_setFloat(m, 1, 1058.39f);
  cSend_R3v6ylvj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_0tLKVLrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_dTkbaS81_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_jySFOE5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "almglocken");
  msg_setFloat(m, 1, 262.6f);
  cSend_R3v6ylvj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_WnBSBah7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uyb0fMum, 0, m, &cSlice_uyb0fMum_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_f2xRGclQ, 0, m, &cRandom_f2xRGclQ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_gxk13Df8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3IleC1R7_sendMessage);
}

void Heavy_SoundScraper::cUnop_3IleC1R7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_XhWwERMj_sendMessage);
}

void Heavy_SoundScraper::cRandom_f2xRGclQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_gxk13Df8_sendMessage);
}

void Heavy_SoundScraper::cSlice_uyb0fMum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_f2xRGclQ, 1, m, &cRandom_f2xRGclQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_WhT0w6MT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qNCqVpX0, 0, m, &cSlice_qNCqVpX0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0yY5gdVS, 0, m, &cRandom_0yY5gdVS_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Xu349zRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_0W1RpkiS_sendMessage);
}

void Heavy_SoundScraper::cUnop_0W1RpkiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4QnWFvXF, 0, m, &cPack_4QnWFvXF_sendMessage);
}

void Heavy_SoundScraper::cRandom_0yY5gdVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_Xu349zRX_sendMessage);
}

void Heavy_SoundScraper::cSlice_qNCqVpX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0yY5gdVS, 1, m, &cRandom_0yY5gdVS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_gDEt4Mmh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_nDIRU3jc_sendMessage);
}

void Heavy_SoundScraper::cPack_CUl2rfqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_v70FQxyK, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_6If8kyt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VTpacLA0_sendMessage);
}

void Heavy_SoundScraper::cBinop_sJrmRSWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_6If8kyt8_sendMessage);
}

void Heavy_SoundScraper::cPack_6dpfoX4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0z4wRBQN, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_OMuLjoBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_x4LYGiXh_sendMessage);
}

void Heavy_SoundScraper::cMsg_7vKni9D0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4a2qSsNB_sendMessage);
}

void Heavy_SoundScraper::cSystem_4a2qSsNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GdyGMVv0_sendMessage);
}

void Heavy_SoundScraper::cDelay_buv04Lr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_buv04Lr6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LniaDFXE, 0, m, &cDelay_LniaDFXE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_buv04Lr6, 0, m, &cDelay_buv04Lr6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_S3C7AJOw, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_LniaDFXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LniaDFXE, m);
  cMsg_H2nHsy6h_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Ex4tkd1K_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_io0bHNfV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_SoUl0wya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UlUuh0R7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_K7TEiO1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ClpP6XTb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_buv04Lr6, 2, m, &cDelay_buv04Lr6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l8arz65T_sendMessage);
}

void Heavy_SoundScraper::cMsg_UlUuh0R7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_K7TEiO1b, 0, m, &hTable_K7TEiO1b_sendMessage);
}

void Heavy_SoundScraper::cBinop_GdyGMVv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_SoUl0wya_sendMessage);
}

void Heavy_SoundScraper::cMsg_H2nHsy6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_K7TEiO1b, 0, m, &hTable_K7TEiO1b_sendMessage);
}

void Heavy_SoundScraper::cCast_l8arz65T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_buv04Lr6, 0, m, &cDelay_buv04Lr6_sendMessage);
}

void Heavy_SoundScraper::cMsg_ClpP6XTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_LniaDFXE, 2, m, &cDelay_LniaDFXE_sendMessage);
}

void Heavy_SoundScraper::cMsg_io0bHNfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_S3C7AJOw, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_fz5kpT03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7YLYc2KN_sendMessage);
}

void Heavy_SoundScraper::cSystem_7YLYc2KN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_H8xrqHIj_sendMessage);
}

void Heavy_SoundScraper::cVar_CJXESJkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AXXmLFYP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_uXQFeul0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_EEKVkajC_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_I8Mf5LjP, m);
}

void Heavy_SoundScraper::cBinop_H8xrqHIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ed1QnKWf, m);
}

void Heavy_SoundScraper::cMsg_AXXmLFYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uXQFeul0_sendMessage);
}

void Heavy_SoundScraper::cBinop_EEKVkajC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1LDhi1ch, m);
}

void Heavy_SoundScraper::cMsg_lUoJWmAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3bmALw6X_sendMessage);
}

void Heavy_SoundScraper::cSystem_3bmALw6X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5AZ7I9Kd_sendMessage);
}

void Heavy_SoundScraper::cVar_BT9w3UQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xXa8qGMJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_1ixbveIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_xQ4H3WIN_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_CXFokFf0, m);
}

void Heavy_SoundScraper::cBinop_5AZ7I9Kd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3dLSUVXI, m);
}

void Heavy_SoundScraper::cMsg_xXa8qGMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1ixbveIq_sendMessage);
}

void Heavy_SoundScraper::cBinop_xQ4H3WIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7ATy5vzG, m);
}

void Heavy_SoundScraper::cBinop_VfY5Xo0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cykIj3V8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_gBlKvZbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Nl4olXs6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6cjiCH24_sendMessage);
}

void Heavy_SoundScraper::cCast_Nl4olXs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VfY5Xo0y, HV_BINOP_DIVIDE, 1, m, &cBinop_VfY5Xo0y_sendMessage);
}

void Heavy_SoundScraper::cCast_6cjiCH24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VfY5Xo0y, HV_BINOP_DIVIDE, 0, m, &cBinop_VfY5Xo0y_sendMessage);
}

void Heavy_SoundScraper::cBinop_VTpacLA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VGjtJxw5_sendMessage);
}

void Heavy_SoundScraper::cBinop_Wa63AMRG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_sJrmRSWk_sendMessage);
}

void Heavy_SoundScraper::cBinop_VGjtJxw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VfY5Xo0y, HV_BINOP_DIVIDE, 0, m, &cBinop_VfY5Xo0y_sendMessage);
}

void Heavy_SoundScraper::cBinop_x4LYGiXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6dpfoX4X, 0, m, &cPack_6dpfoX4X_sendMessage);
}

void Heavy_SoundScraper::cBinop_nDIRU3jc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_gBlKvZbW_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_CUl2rfqm, 0, m, &cPack_CUl2rfqm_sendMessage);
}

void Heavy_SoundScraper::cMsg_RvHW7WXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_gDEt4Mmh, 0, m, &cVar_gDEt4Mmh_sendMessage);
}

void Heavy_SoundScraper::cMsg_hRO6FoxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_OMuLjoBY, 0, m, &cVar_OMuLjoBY_sendMessage);
}

void Heavy_SoundScraper::cMsg_cykIj3V8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3uIgCiqW, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_lvxwxi5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_80USCqfS_sendMessage);
}

void Heavy_SoundScraper::cSystem_80USCqfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZrdTEXF6_sendMessage);
}

void Heavy_SoundScraper::cVar_ZQ4urXOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JSSl0JOC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Y8DjpItt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hxijb8Gv_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tx7hrITJ, m);
}

void Heavy_SoundScraper::cBinop_ZrdTEXF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YxdX9ZsG, m);
}

void Heavy_SoundScraper::cMsg_JSSl0JOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Y8DjpItt_sendMessage);
}

void Heavy_SoundScraper::cBinop_hxijb8Gv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KjAc0sTL, m);
}

void Heavy_SoundScraper::cVar_QNuYKa7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulHQ8uM4, HV_BINOP_MULTIPLY, 0, m, &cBinop_ulHQ8uM4_sendMessage);
}

void Heavy_SoundScraper::cMsg_sLibtJlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_afHPECxW_sendMessage);
}

void Heavy_SoundScraper::cSystem_afHPECxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fSf8dkFc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ulHQ8uM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_XdVr0sV8_sendMessage);
}

void Heavy_SoundScraper::cBinop_mmR6CfOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulHQ8uM4, HV_BINOP_MULTIPLY, 1, m, &cBinop_ulHQ8uM4_sendMessage);
}

void Heavy_SoundScraper::cMsg_fSf8dkFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mmR6CfOK_sendMessage);
}

void Heavy_SoundScraper::cBinop_XdVr0sV8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_H9d4FDpR_sendMessage);
}

void Heavy_SoundScraper::cBinop_H9d4FDpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2U2NdsEk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GOqgKqdf, m);
}

void Heavy_SoundScraper::cBinop_2U2NdsEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FJaT9mYd, m);
}

void Heavy_SoundScraper::cBinop_iCN9Mccu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_exayuh5j_sendMessage);
}

void Heavy_SoundScraper::cBinop_exayuh5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MbFKhnD4, m);
}

void Heavy_SoundScraper::cBinop_IiCOr2Xp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7V99gSBD_sendMessage);
}

void Heavy_SoundScraper::cBinop_7V99gSBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TRUWF22E_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nm3aq80C_sendMessage);
}

void Heavy_SoundScraper::cVar_QRJf8WjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_PtcZpjJg_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZGHaGDyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9Hry6oOn_sendMessage);
}

void Heavy_SoundScraper::cSystem_9Hry6oOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sIymYMAf, HV_BINOP_DIVIDE, 1, m, &cBinop_sIymYMAf_sendMessage);
}

void Heavy_SoundScraper::cBinop_TRUWF22E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_LS8KOaGq_sendMessage);
}

void Heavy_SoundScraper::cBinop_LS8KOaGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pBglXIVS, m);
}

void Heavy_SoundScraper::cMsg_UxYV6xkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_bicqVM9a_sendMessage);
}

void Heavy_SoundScraper::cBinop_bicqVM9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IiCOr2Xp_sendMessage);
}

void Heavy_SoundScraper::cBinop_nm3aq80C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_y6fM4WkY, m);
}

void Heavy_SoundScraper::cBinop_PtcZpjJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_XTNBrC2Y_sendMessage);
}

void Heavy_SoundScraper::cBinop_XTNBrC2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sIymYMAf, HV_BINOP_DIVIDE, 0, m, &cBinop_sIymYMAf_sendMessage);
}

void Heavy_SoundScraper::cBinop_sIymYMAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UxYV6xkw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_pSJs2uvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qc4o281H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_H7QOyM7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FuJYWhj7_sendMessage);
}

void Heavy_SoundScraper::cSystem_FuJYWhj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1jj56Nwe_sendMessage);
}

void Heavy_SoundScraper::cDelay_VDIOx8jf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VDIOx8jf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ksLyjHSh, 0, m, &cDelay_ksLyjHSh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VDIOx8jf, 0, m, &cDelay_VDIOx8jf_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0t0DFWPC, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_ksLyjHSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ksLyjHSh, m);
  cMsg_HCg7fGT4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_dKUgvknW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4IyhhJNQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_DIIQdm6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8lA7p9PQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_eqIUvePK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AhnqTeUh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VDIOx8jf, 2, m, &cDelay_VDIOx8jf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R86jjlhJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_8lA7p9PQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_eqIUvePK, 0, m, &hTable_eqIUvePK_sendMessage);
}

void Heavy_SoundScraper::cBinop_1jj56Nwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_DIIQdm6f_sendMessage);
}

void Heavy_SoundScraper::cMsg_HCg7fGT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_eqIUvePK, 0, m, &hTable_eqIUvePK_sendMessage);
}

void Heavy_SoundScraper::cCast_R86jjlhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VDIOx8jf, 0, m, &cDelay_VDIOx8jf_sendMessage);
}

void Heavy_SoundScraper::cMsg_AhnqTeUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ksLyjHSh, 2, m, &cDelay_ksLyjHSh_sendMessage);
}

void Heavy_SoundScraper::cMsg_4IyhhJNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0t0DFWPC, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_pNzOTgSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_qc4o281H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_qc4o281H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Qoni9Jxq, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_eV67LC8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_Kej92S4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7hD93HXN_sendMessage);
}

void Heavy_SoundScraper::cSystem_7hD93HXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XnACu4g8, HV_BINOP_MULTIPLY, 1, m, &cBinop_XnACu4g8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hy0z9Ejg, HV_BINOP_MULTIPLY, 1, m, &cBinop_Hy0z9Ejg_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_huNJMFJj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_6aJCKu3w_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_6aJCKu3w_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WUXUUHF4_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_GNKz83J4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GNKz83J4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GNKz83J4, 0, m, &cDelay_GNKz83J4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UuaC7jLP, 0, m, &cVar_UuaC7jLP_sendMessage);
}

void Heavy_SoundScraper::cCast_WUXUUHF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6aJCKu3w_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GNKz83J4, 0, m, &cDelay_GNKz83J4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UuaC7jLP, 0, m, &cVar_UuaC7jLP_sendMessage);
}

void Heavy_SoundScraper::cMsg_is01xl3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BBrQGMLD_sendMessage);
}

void Heavy_SoundScraper::cSystem_BBrQGMLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Cr4bZG4U_sendMessage);
}

void Heavy_SoundScraper::cVar_EXFnbPJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4o6masnk, HV_BINOP_MULTIPLY, 0, m, &cBinop_4o6masnk_sendMessage);
}

void Heavy_SoundScraper::cMsg_6aJCKu3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GNKz83J4, 0, m, &cDelay_GNKz83J4_sendMessage);
}

void Heavy_SoundScraper::cBinop_foLcHMv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GNKz83J4, 2, m, &cDelay_GNKz83J4_sendMessage);
}

void Heavy_SoundScraper::cBinop_Cr4bZG4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4o6masnk, HV_BINOP_MULTIPLY, 1, m, &cBinop_4o6masnk_sendMessage);
}

void Heavy_SoundScraper::cBinop_4o6masnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_foLcHMv4_sendMessage);
}

void Heavy_SoundScraper::cVar_UuaC7jLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VL5qgaZv, HV_BINOP_SUBTRACT, 0, m, &cBinop_VL5qgaZv_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_ZRH5z4jX_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_GuFDlEXI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kdXj8y8y_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WbGlgypw_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_kdXj8y8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Linntcwq, 0, m, &cVar_Linntcwq_sendMessage);
}

void Heavy_SoundScraper::cCast_WbGlgypw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xBpHk0K7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fYqBKe6T_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_PNWzdVMH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4scMjCeG, 0, m, &cSlice_4scMjCeG_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LRxFIiDR, 0, m, &cSlice_LRxFIiDR_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wv4Ni47N_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_isVzY7aE, 0, m, &cSlice_isVzY7aE_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_9EO51Rho, 0, m, &cSlice_9EO51Rho_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qJMrzYOu_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XFSdWh2s_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_4scMjCeG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Q0ECMkbq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Q0ECMkbq_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_LRxFIiDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2kEwnsMM_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rn73nlbK_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2kEwnsMM_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rn73nlbK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_MTkXttpv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xKim325P_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xr27wD3q_sendMessage);
}

void Heavy_SoundScraper::cVar_f6GzgwOQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZxxvAQw2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_ZxxvAQw2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J4fieqLy_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XnACu4g8, HV_BINOP_MULTIPLY, 0, m, &cBinop_XnACu4g8_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_Y6wiEZ4m, HV_BINOP_DIVIDE, 1, m, &cBinop_Y6wiEZ4m_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_EXFnbPJ6, 0, m, &cVar_EXFnbPJ6_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_J4fieqLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FdRRY7WT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_LKwaZIHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hDYqd8Cz, HV_BINOP_SUBTRACT, 1, m, &cBinop_hDYqd8Cz_sendMessage);
}

void Heavy_SoundScraper::cVar_abD11DrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Linntcwq, 0, m, &cVar_Linntcwq_sendMessage);
}

void Heavy_SoundScraper::cVar_Linntcwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Twcld0nY, HV_BINOP_ADD, 0, m, &cBinop_Twcld0nY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_umtmiGU4, HV_BINOP_ADD, 0, m, &cBinop_umtmiGU4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_D8UH934p, 0, m, &cVar_D8UH934p_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_Wa63AMRG_sendMessage);
}

void Heavy_SoundScraper::cSlice_isVzY7aE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xKim325P_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xr27wD3q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_9EO51Rho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TMuiNgqa_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yOOjC8Ej_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_uWsjcj15_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UuaC7jLP, 1, m, &cVar_UuaC7jLP_sendMessage);
}

void Heavy_SoundScraper::cBinop_Hy0z9Ejg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uWsjcj15_sendMessage);
}

void Heavy_SoundScraper::cBinop_XnACu4g8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Q0Hn4ip8_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q0Hn4ip8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VL5qgaZv, HV_BINOP_SUBTRACT, 1, m, &cBinop_VL5qgaZv_sendMessage);
}

void Heavy_SoundScraper::cBinop_VL5qgaZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UuaC7jLP, 1, m, &cVar_UuaC7jLP_sendMessage);
}

void Heavy_SoundScraper::cMsg_QomSUlfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_huNJMFJj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_kMvy4qPe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_huNJMFJj_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_umtmiGU4, HV_BINOP_ADD, 1, m, &cBinop_umtmiGU4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Twcld0nY, HV_BINOP_ADD, 1, m, &cBinop_Twcld0nY_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZRH5z4jX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GuFDlEXI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_Twcld0nY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Linntcwq, 1, m, &cVar_Linntcwq_sendMessage);
}

void Heavy_SoundScraper::cBinop_Y6wiEZ4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Btv0Rmwe, HV_BINOP_DIVIDE, 1, m, &cBinop_Btv0Rmwe_sendMessage);
}

void Heavy_SoundScraper::cBinop_Btv0Rmwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_umtmiGU4, HV_BINOP_ADD, 1, m, &cBinop_umtmiGU4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Twcld0nY, HV_BINOP_ADD, 1, m, &cBinop_Twcld0nY_sendMessage);
}

void Heavy_SoundScraper::cCast_xr27wD3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y6wiEZ4m, HV_BINOP_DIVIDE, 0, m, &cBinop_Y6wiEZ4m_sendMessage);
}

void Heavy_SoundScraper::cCast_xKim325P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hy0z9Ejg, HV_BINOP_MULTIPLY, 0, m, &cBinop_Hy0z9Ejg_sendMessage);
}

void Heavy_SoundScraper::cCast_TMuiNgqa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_abD11DrU, 1, m, &cVar_abD11DrU_sendMessage);
}

void Heavy_SoundScraper::cCast_yOOjC8Ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hDYqd8Cz, HV_BINOP_SUBTRACT, 0, m, &cBinop_hDYqd8Cz_sendMessage);
}

void Heavy_SoundScraper::cCast_fYqBKe6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_abD11DrU, 0, m, &cVar_abD11DrU_sendMessage);
}

void Heavy_SoundScraper::cCast_xBpHk0K7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kMvy4qPe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_umtmiGU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LKwaZIHV, 0, m, &cVar_LKwaZIHV_sendMessage);
}

void Heavy_SoundScraper::cMsg_Q0ECMkbq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_huNJMFJj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_tIj7r7m8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_MTkXttpv, 1, m, &cVar_MTkXttpv_sendMessage);
}

void Heavy_SoundScraper::cMsg_FdRRY7WT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XnACu4g8, HV_BINOP_MULTIPLY, 0, m, &cBinop_XnACu4g8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y6wiEZ4m, HV_BINOP_DIVIDE, 1, m, &cBinop_Y6wiEZ4m_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EXFnbPJ6, 0, m, &cVar_EXFnbPJ6_sendMessage);
}

void Heavy_SoundScraper::cCast_2kEwnsMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q0ECMkbq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Rn73nlbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_88XESy0E_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_umtmiGU4, HV_BINOP_ADD, 0, m, &cBinop_umtmiGU4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Linntcwq, 1, m, &cVar_Linntcwq_sendMessage);
}

void Heavy_SoundScraper::cBinop_hDYqd8Cz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Btv0Rmwe, HV_BINOP_DIVIDE, 0, m, &cBinop_Btv0Rmwe_sendMessage);
}

void Heavy_SoundScraper::cCast_88XESy0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kMvy4qPe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_XFSdWh2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tIj7r7m8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Wv4Ni47N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MTkXttpv, 0, m, &cVar_MTkXttpv_sendMessage);
}

void Heavy_SoundScraper::cCast_qJMrzYOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QomSUlfR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_D8UH934p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cPack_mLkWrJdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PNWzdVMH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_PuPzarXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KmusErRP_sendMessage);
}

void Heavy_SoundScraper::cSystem_KmusErRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R4jHGI2A, HV_BINOP_MULTIPLY, 1, m, &cBinop_R4jHGI2A_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dbbRUgvO, HV_BINOP_MULTIPLY, 1, m, &cBinop_dbbRUgvO_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Iw4pXhmz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_K5xJoyg7_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_K5xJoyg7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LdMTapXz_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_uudH95Vl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uudH95Vl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uudH95Vl, 0, m, &cDelay_uudH95Vl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_R93qHwjB, 0, m, &cVar_R93qHwjB_sendMessage);
}

void Heavy_SoundScraper::cCast_LdMTapXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K5xJoyg7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uudH95Vl, 0, m, &cDelay_uudH95Vl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_R93qHwjB, 0, m, &cVar_R93qHwjB_sendMessage);
}

void Heavy_SoundScraper::cMsg_BGaKQQ15_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Try2izXR_sendMessage);
}

void Heavy_SoundScraper::cSystem_Try2izXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AjZa5aGO_sendMessage);
}

void Heavy_SoundScraper::cVar_unCIxqAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ocse1Zh, HV_BINOP_MULTIPLY, 0, m, &cBinop_6ocse1Zh_sendMessage);
}

void Heavy_SoundScraper::cMsg_K5xJoyg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_uudH95Vl, 0, m, &cDelay_uudH95Vl_sendMessage);
}

void Heavy_SoundScraper::cBinop_BpQsSRNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uudH95Vl, 2, m, &cDelay_uudH95Vl_sendMessage);
}

void Heavy_SoundScraper::cBinop_AjZa5aGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ocse1Zh, HV_BINOP_MULTIPLY, 1, m, &cBinop_6ocse1Zh_sendMessage);
}

void Heavy_SoundScraper::cBinop_6ocse1Zh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_BpQsSRNB_sendMessage);
}

void Heavy_SoundScraper::cVar_R93qHwjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hBBjVAGG, HV_BINOP_SUBTRACT, 0, m, &cBinop_hBBjVAGG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_yXml4Mw5_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Saq7v8P9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4ocnm1uF_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L2ytN34A_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_4ocnm1uF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4fo7fOS6, 0, m, &cVar_4fo7fOS6_sendMessage);
}

void Heavy_SoundScraper::cCast_L2ytN34A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6Eh1EuQJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ADJXdWsH_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_kb2x5xY2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mwvI0oFD, 0, m, &cSlice_mwvI0oFD_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LxqvU5qK, 0, m, &cSlice_LxqvU5qK_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UlLqisQY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vPuDt3So, 0, m, &cSlice_vPuDt3So_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zQzMYxP2, 0, m, &cSlice_zQzMYxP2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ch63B3Ka_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k4FOojDL_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_mwvI0oFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_t4UUwjDK_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_t4UUwjDK_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_LxqvU5qK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PVU2Onc8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_blWSa2UA_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PVU2Onc8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_blWSa2UA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_PrgKIapZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ufCaOMGn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rsI4Qnfw_sendMessage);
}

void Heavy_SoundScraper::cVar_iipwD4Jl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9MJYDcgD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_9MJYDcgD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jmEcnCUL_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_R4jHGI2A, HV_BINOP_MULTIPLY, 0, m, &cBinop_R4jHGI2A_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_dK1N1w9Y, HV_BINOP_DIVIDE, 1, m, &cBinop_dK1N1w9Y_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_unCIxqAN, 0, m, &cVar_unCIxqAN_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_jmEcnCUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TkRs59Id_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_mpCd3GTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dj1S2fBG, HV_BINOP_SUBTRACT, 1, m, &cBinop_Dj1S2fBG_sendMessage);
}

void Heavy_SoundScraper::cVar_bUox8CFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4fo7fOS6, 0, m, &cVar_4fo7fOS6_sendMessage);
}

void Heavy_SoundScraper::cVar_4fo7fOS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h0cTks0X, HV_BINOP_ADD, 0, m, &cBinop_h0cTks0X_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7huPXr0Z, HV_BINOP_ADD, 0, m, &cBinop_7huPXr0Z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eV67LC8l, 0, m, &cVar_eV67LC8l_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Crsreo61, m);
}

void Heavy_SoundScraper::cSlice_vPuDt3So_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ufCaOMGn_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rsI4Qnfw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_zQzMYxP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lh2AEeqX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QFiNaiVN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_I6noH61L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R93qHwjB, 1, m, &cVar_R93qHwjB_sendMessage);
}

void Heavy_SoundScraper::cBinop_dbbRUgvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_I6noH61L_sendMessage);
}

void Heavy_SoundScraper::cBinop_R4jHGI2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_p6JohmSE_sendMessage);
}

void Heavy_SoundScraper::cBinop_p6JohmSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hBBjVAGG, HV_BINOP_SUBTRACT, 1, m, &cBinop_hBBjVAGG_sendMessage);
}

void Heavy_SoundScraper::cBinop_hBBjVAGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R93qHwjB, 1, m, &cVar_R93qHwjB_sendMessage);
}

void Heavy_SoundScraper::cMsg_RLlYivOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Iw4pXhmz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_HXT9ZhaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Iw4pXhmz_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7huPXr0Z, HV_BINOP_ADD, 1, m, &cBinop_7huPXr0Z_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_h0cTks0X, HV_BINOP_ADD, 1, m, &cBinop_h0cTks0X_sendMessage);
}

void Heavy_SoundScraper::cBinop_yXml4Mw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Saq7v8P9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_h0cTks0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4fo7fOS6, 1, m, &cVar_4fo7fOS6_sendMessage);
}

void Heavy_SoundScraper::cBinop_dK1N1w9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_suecRVFC, HV_BINOP_DIVIDE, 1, m, &cBinop_suecRVFC_sendMessage);
}

void Heavy_SoundScraper::cBinop_suecRVFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7huPXr0Z, HV_BINOP_ADD, 1, m, &cBinop_7huPXr0Z_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_h0cTks0X, HV_BINOP_ADD, 1, m, &cBinop_h0cTks0X_sendMessage);
}

void Heavy_SoundScraper::cCast_rsI4Qnfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dK1N1w9Y, HV_BINOP_DIVIDE, 0, m, &cBinop_dK1N1w9Y_sendMessage);
}

void Heavy_SoundScraper::cCast_ufCaOMGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dbbRUgvO, HV_BINOP_MULTIPLY, 0, m, &cBinop_dbbRUgvO_sendMessage);
}

void Heavy_SoundScraper::cCast_QFiNaiVN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dj1S2fBG, HV_BINOP_SUBTRACT, 0, m, &cBinop_Dj1S2fBG_sendMessage);
}

void Heavy_SoundScraper::cCast_lh2AEeqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bUox8CFc, 1, m, &cVar_bUox8CFc_sendMessage);
}

void Heavy_SoundScraper::cCast_6Eh1EuQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HXT9ZhaX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ADJXdWsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bUox8CFc, 0, m, &cVar_bUox8CFc_sendMessage);
}

void Heavy_SoundScraper::cBinop_7huPXr0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mpCd3GTM, 0, m, &cVar_mpCd3GTM_sendMessage);
}

void Heavy_SoundScraper::cMsg_t4UUwjDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Iw4pXhmz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_6EtW4ttO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_PrgKIapZ, 1, m, &cVar_PrgKIapZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_TkRs59Id_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R4jHGI2A, HV_BINOP_MULTIPLY, 0, m, &cBinop_R4jHGI2A_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dK1N1w9Y, HV_BINOP_DIVIDE, 1, m, &cBinop_dK1N1w9Y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_unCIxqAN, 0, m, &cVar_unCIxqAN_sendMessage);
}

void Heavy_SoundScraper::cCast_blWSa2UA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VdkgLJiV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7huPXr0Z, HV_BINOP_ADD, 0, m, &cBinop_7huPXr0Z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4fo7fOS6, 1, m, &cVar_4fo7fOS6_sendMessage);
}

void Heavy_SoundScraper::cCast_PVU2Onc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t4UUwjDK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Dj1S2fBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_suecRVFC, HV_BINOP_DIVIDE, 0, m, &cBinop_suecRVFC_sendMessage);
}

void Heavy_SoundScraper::cCast_VdkgLJiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HXT9ZhaX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ch63B3Ka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RLlYivOm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UlLqisQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PrgKIapZ, 0, m, &cVar_PrgKIapZ_sendMessage);
}

void Heavy_SoundScraper::cCast_k4FOojDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6EtW4ttO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_4QnWFvXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kb2x5xY2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_KDnQfsTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_P3iOl8Jo, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_xBabYogm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_ePzcMwde_sendMessage);
}

void Heavy_SoundScraper::cBinop_ePzcMwde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mLkWrJdP, 0, m, &cPack_mLkWrJdP_sendMessage);
}

void Heavy_SoundScraper::cBinop_XhWwERMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xBabYogm_sendMessage);
}

void Heavy_SoundScraper::cCast_z0f4Okkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WnBSBah7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_xytZiYk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WhT0w6MT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_e9Yfg7N2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iCN9Mccu_sendMessage);
}

void Heavy_SoundScraper::cTabhead_dQGV4TaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FJNV0H6g, HV_BINOP_SUBTRACT, 0, m, &cBinop_FJNV0H6g_sendMessage);
}

void Heavy_SoundScraper::cMsg_ot9VaF3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R6DlmHcx_sendMessage);
}

void Heavy_SoundScraper::cSystem_R6DlmHcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_R864DHrc_sendMessage);
}

void Heavy_SoundScraper::cVar_5RS8xrjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pQ7WKUn7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_JNZtsWii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JNZtsWii, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_I1kvxluK, 0, m, &cDelay_I1kvxluK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CeeGY1XF, 0, m, &sTabread_CeeGY1XF_sendMessage);
}

void Heavy_SoundScraper::cDelay_I1kvxluK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_I1kvxluK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CeeGY1XF, 0, m, &sTabread_CeeGY1XF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_I1kvxluK, 0, m, &cDelay_I1kvxluK_sendMessage);
}

void Heavy_SoundScraper::sTabread_CeeGY1XF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ve2xb27t, HV_BINOP_SUBTRACT, 0, m, &cBinop_ve2xb27t_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ehufyXT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f9XpTJXV, HV_BINOP_MAX, 0, m, &cBinop_f9XpTJXV_sendMessage);
}

void Heavy_SoundScraper::cBinop_R864DHrc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ehufyXT3, HV_BINOP_MULTIPLY, 0, m, &cBinop_ehufyXT3_sendMessage);
}

void Heavy_SoundScraper::cBinop_FJNV0H6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JRgNSOU0_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CeeGY1XF, 0, m, &sTabread_CeeGY1XF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d7IVIyeu_sendMessage);
}

void Heavy_SoundScraper::cSystem_zW0LfZyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ve2xb27t, HV_BINOP_SUBTRACT, 1, m, &cBinop_ve2xb27t_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_I1kvxluK, 2, m, &cDelay_I1kvxluK_sendMessage);
}

void Heavy_SoundScraper::cMsg_pQ7WKUn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zW0LfZyd_sendMessage);
}

void Heavy_SoundScraper::cMsg_JRgNSOU0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JNZtsWii, 0, m, &cDelay_JNZtsWii_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_I1kvxluK, 0, m, &cDelay_I1kvxluK_sendMessage);
}

void Heavy_SoundScraper::cMsg_cly0v3xs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_f9XpTJXV, HV_BINOP_MAX, 1, m, &cBinop_f9XpTJXV_sendMessage);
}

void Heavy_SoundScraper::cBinop_f9XpTJXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FJNV0H6g, HV_BINOP_SUBTRACT, 1, m, &cBinop_FJNV0H6g_sendMessage);
}

void Heavy_SoundScraper::cCast_d7IVIyeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JNZtsWii, 0, m, &cDelay_JNZtsWii_sendMessage);
}

void Heavy_SoundScraper::cBinop_sPjW03Pt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JNZtsWii, 2, m, &cDelay_JNZtsWii_sendMessage);
}

void Heavy_SoundScraper::cBinop_ve2xb27t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sPjW03Pt_sendMessage);
}

void Heavy_SoundScraper::cCast_vtNsEbWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5RS8xrjj, 0, m, &cVar_5RS8xrjj_sendMessage);
  cMsg_ot9VaF3R_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_dQGV4TaD, 0, m, &cTabhead_dQGV4TaD_sendMessage);
}

void Heavy_SoundScraper::cTabhead_zkwkMx3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4ExBDYEx, HV_BINOP_SUBTRACT, 0, m, &cBinop_4ExBDYEx_sendMessage);
}

void Heavy_SoundScraper::cMsg_KuN70eS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TB8WLsOp_sendMessage);
}

void Heavy_SoundScraper::cSystem_TB8WLsOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bjuAy48b_sendMessage);
}

void Heavy_SoundScraper::cVar_8eGRysGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CJTbIuOo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_Wwm7gF6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Wwm7gF6S, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zuQbSjdT, 0, m, &cDelay_zuQbSjdT_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6q3SWtFH, 0, m, &sTabread_6q3SWtFH_sendMessage);
}

void Heavy_SoundScraper::cDelay_zuQbSjdT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zuQbSjdT, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6q3SWtFH, 0, m, &sTabread_6q3SWtFH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zuQbSjdT, 0, m, &cDelay_zuQbSjdT_sendMessage);
}

void Heavy_SoundScraper::sTabread_6q3SWtFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Js6fpVvh, HV_BINOP_SUBTRACT, 0, m, &cBinop_Js6fpVvh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_CU47I9DA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_114RcGBk, HV_BINOP_MAX, 0, m, &cBinop_114RcGBk_sendMessage);
}

void Heavy_SoundScraper::cBinop_bjuAy48b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CU47I9DA, HV_BINOP_MULTIPLY, 0, m, &cBinop_CU47I9DA_sendMessage);
}

void Heavy_SoundScraper::cBinop_4ExBDYEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M4BGBRGt_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6q3SWtFH, 0, m, &sTabread_6q3SWtFH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SJlHtZ8K_sendMessage);
}

void Heavy_SoundScraper::cSystem_oZaWLP22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Js6fpVvh, HV_BINOP_SUBTRACT, 1, m, &cBinop_Js6fpVvh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zuQbSjdT, 2, m, &cDelay_zuQbSjdT_sendMessage);
}

void Heavy_SoundScraper::cMsg_CJTbIuOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oZaWLP22_sendMessage);
}

void Heavy_SoundScraper::cMsg_M4BGBRGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wwm7gF6S, 0, m, &cDelay_Wwm7gF6S_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zuQbSjdT, 0, m, &cDelay_zuQbSjdT_sendMessage);
}

void Heavy_SoundScraper::cMsg_sdlWGwW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_114RcGBk, HV_BINOP_MAX, 1, m, &cBinop_114RcGBk_sendMessage);
}

void Heavy_SoundScraper::cBinop_114RcGBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4ExBDYEx, HV_BINOP_SUBTRACT, 1, m, &cBinop_4ExBDYEx_sendMessage);
}

void Heavy_SoundScraper::cCast_SJlHtZ8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wwm7gF6S, 0, m, &cDelay_Wwm7gF6S_sendMessage);
}

void Heavy_SoundScraper::cBinop_g7opZu55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wwm7gF6S, 2, m, &cDelay_Wwm7gF6S_sendMessage);
}

void Heavy_SoundScraper::cBinop_Js6fpVvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_g7opZu55_sendMessage);
}

void Heavy_SoundScraper::cCast_Ave7rSyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8eGRysGs, 0, m, &cVar_8eGRysGs_sendMessage);
  cMsg_KuN70eS7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zkwkMx3i, 0, m, &cTabhead_zkwkMx3i_sendMessage);
}

void Heavy_SoundScraper::cTabhead_5YB6GLd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8pEqlxI, HV_BINOP_SUBTRACT, 0, m, &cBinop_R8pEqlxI_sendMessage);
}

void Heavy_SoundScraper::cMsg_aHonXJtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ch81CtFG_sendMessage);
}

void Heavy_SoundScraper::cSystem_ch81CtFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IlVvA5ox_sendMessage);
}

void Heavy_SoundScraper::cVar_SUKx77xc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_12tj923E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_oVT3ZNfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oVT3ZNfW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n9ctqXcA, 0, m, &cDelay_n9ctqXcA_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jqylowgB, 0, m, &sTabread_jqylowgB_sendMessage);
}

void Heavy_SoundScraper::cDelay_n9ctqXcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n9ctqXcA, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jqylowgB, 0, m, &sTabread_jqylowgB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n9ctqXcA, 0, m, &cDelay_n9ctqXcA_sendMessage);
}

void Heavy_SoundScraper::sTabread_jqylowgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gfAr8rpm, HV_BINOP_SUBTRACT, 0, m, &cBinop_gfAr8rpm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_NsxL0LzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_74Yd35IR, HV_BINOP_MAX, 0, m, &cBinop_74Yd35IR_sendMessage);
}

void Heavy_SoundScraper::cBinop_IlVvA5ox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NsxL0LzL, HV_BINOP_MULTIPLY, 0, m, &cBinop_NsxL0LzL_sendMessage);
}

void Heavy_SoundScraper::cBinop_R8pEqlxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5NPDdsmR_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jqylowgB, 0, m, &sTabread_jqylowgB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kj0tzA8V_sendMessage);
}

void Heavy_SoundScraper::cSystem_NAYE13hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gfAr8rpm, HV_BINOP_SUBTRACT, 1, m, &cBinop_gfAr8rpm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n9ctqXcA, 2, m, &cDelay_n9ctqXcA_sendMessage);
}

void Heavy_SoundScraper::cMsg_12tj923E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NAYE13hg_sendMessage);
}

void Heavy_SoundScraper::cMsg_5NPDdsmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_oVT3ZNfW, 0, m, &cDelay_oVT3ZNfW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n9ctqXcA, 0, m, &cDelay_n9ctqXcA_sendMessage);
}

void Heavy_SoundScraper::cMsg_2UcNJOw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_74Yd35IR, HV_BINOP_MAX, 1, m, &cBinop_74Yd35IR_sendMessage);
}

void Heavy_SoundScraper::cBinop_74Yd35IR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8pEqlxI, HV_BINOP_SUBTRACT, 1, m, &cBinop_R8pEqlxI_sendMessage);
}

void Heavy_SoundScraper::cCast_kj0tzA8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oVT3ZNfW, 0, m, &cDelay_oVT3ZNfW_sendMessage);
}

void Heavy_SoundScraper::cBinop_U6LJsX4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oVT3ZNfW, 2, m, &cDelay_oVT3ZNfW_sendMessage);
}

void Heavy_SoundScraper::cBinop_gfAr8rpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_U6LJsX4v_sendMessage);
}

void Heavy_SoundScraper::cCast_lqNzAew2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SUKx77xc, 0, m, &cVar_SUKx77xc_sendMessage);
  cMsg_aHonXJtZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5YB6GLd8, 0, m, &cTabhead_5YB6GLd8_sendMessage);
}

void Heavy_SoundScraper::cTabhead_YtVtkXvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HwFNqzoM, HV_BINOP_SUBTRACT, 0, m, &cBinop_HwFNqzoM_sendMessage);
}

void Heavy_SoundScraper::cMsg_0tmq3dMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3lJ882Xv_sendMessage);
}

void Heavy_SoundScraper::cSystem_3lJ882Xv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_le1A1JYY_sendMessage);
}

void Heavy_SoundScraper::cVar_x74XdEp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rYDR5Pxn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_khKRaQhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_khKRaQhX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rxv8zB7v, 0, m, &cDelay_Rxv8zB7v_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ep1qFV0s, 0, m, &sTabread_Ep1qFV0s_sendMessage);
}

void Heavy_SoundScraper::cDelay_Rxv8zB7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Rxv8zB7v, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ep1qFV0s, 0, m, &sTabread_Ep1qFV0s_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rxv8zB7v, 0, m, &cDelay_Rxv8zB7v_sendMessage);
}

void Heavy_SoundScraper::sTabread_Ep1qFV0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hplxNKla, HV_BINOP_SUBTRACT, 0, m, &cBinop_hplxNKla_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_U5abW7FX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uyo4czoO, HV_BINOP_MAX, 0, m, &cBinop_uyo4czoO_sendMessage);
}

void Heavy_SoundScraper::cBinop_le1A1JYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U5abW7FX, HV_BINOP_MULTIPLY, 0, m, &cBinop_U5abW7FX_sendMessage);
}

void Heavy_SoundScraper::cBinop_HwFNqzoM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uDTpNmEd_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ep1qFV0s, 0, m, &sTabread_Ep1qFV0s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NpSWgQpc_sendMessage);
}

void Heavy_SoundScraper::cSystem_FiwbxHKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hplxNKla, HV_BINOP_SUBTRACT, 1, m, &cBinop_hplxNKla_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rxv8zB7v, 2, m, &cDelay_Rxv8zB7v_sendMessage);
}

void Heavy_SoundScraper::cMsg_rYDR5Pxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FiwbxHKx_sendMessage);
}

void Heavy_SoundScraper::cMsg_uDTpNmEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_khKRaQhX, 0, m, &cDelay_khKRaQhX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rxv8zB7v, 0, m, &cDelay_Rxv8zB7v_sendMessage);
}

void Heavy_SoundScraper::cMsg_TR0PKnnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_uyo4czoO, HV_BINOP_MAX, 1, m, &cBinop_uyo4czoO_sendMessage);
}

void Heavy_SoundScraper::cBinop_uyo4czoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HwFNqzoM, HV_BINOP_SUBTRACT, 1, m, &cBinop_HwFNqzoM_sendMessage);
}

void Heavy_SoundScraper::cCast_NpSWgQpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_khKRaQhX, 0, m, &cDelay_khKRaQhX_sendMessage);
}

void Heavy_SoundScraper::cBinop_vLyxwENu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_khKRaQhX, 2, m, &cDelay_khKRaQhX_sendMessage);
}

void Heavy_SoundScraper::cBinop_hplxNKla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vLyxwENu_sendMessage);
}

void Heavy_SoundScraper::cCast_VQuEwHKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x74XdEp4, 0, m, &cVar_x74XdEp4_sendMessage);
  cMsg_0tmq3dMd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YtVtkXvw, 0, m, &cTabhead_YtVtkXvw_sendMessage);
}

void Heavy_SoundScraper::cMsg_hp1kt2lq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BgbosChV_sendMessage);
}

void Heavy_SoundScraper::cSystem_BgbosChV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Shc1rEZ6_sendMessage);
}

void Heavy_SoundScraper::cDelay_Tqwgio90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Tqwgio90, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4DwWMZo2, 0, m, &cDelay_4DwWMZo2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tqwgio90, 0, m, &cDelay_Tqwgio90_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8v2c4aZz, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_4DwWMZo2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4DwWMZo2, m);
  cMsg_LeJDFe2r_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_inAEjoTZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_lNyqSALg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_eEwYxP1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lG9QBnsf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_UjiZIBVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4pLBDRc6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tqwgio90, 2, m, &cDelay_Tqwgio90_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6DV31LLU_sendMessage);
}

void Heavy_SoundScraper::cMsg_lG9QBnsf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_UjiZIBVs, 0, m, &hTable_UjiZIBVs_sendMessage);
}

void Heavy_SoundScraper::cBinop_Shc1rEZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_eEwYxP1m_sendMessage);
}

void Heavy_SoundScraper::cMsg_LeJDFe2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_UjiZIBVs, 0, m, &hTable_UjiZIBVs_sendMessage);
}

void Heavy_SoundScraper::cCast_6DV31LLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tqwgio90, 0, m, &cDelay_Tqwgio90_sendMessage);
}

void Heavy_SoundScraper::cMsg_4pLBDRc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_4DwWMZo2, 2, m, &cDelay_4DwWMZo2_sendMessage);
}

void Heavy_SoundScraper::cMsg_lNyqSALg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8v2c4aZz, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_skvSkBjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bFjHiG4M_sendMessage);
}

void Heavy_SoundScraper::cSystem_bFjHiG4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IIyW1IAb_sendMessage);
}

void Heavy_SoundScraper::cDelay_ZKYfhAra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZKYfhAra, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8oqcSq0s, 0, m, &cDelay_8oqcSq0s_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZKYfhAra, 0, m, &cDelay_ZKYfhAra_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_o7YBXfC9, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_8oqcSq0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8oqcSq0s, m);
  cMsg_CPbqDH1e_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_amVeaFQh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_D5bD0FSj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_kcGb6NPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fMTCmPJ4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_D1GqFIK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TxYeLUJF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZKYfhAra, 2, m, &cDelay_ZKYfhAra_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jVRNamuj_sendMessage);
}

void Heavy_SoundScraper::cMsg_fMTCmPJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_D1GqFIK5, 0, m, &hTable_D1GqFIK5_sendMessage);
}

void Heavy_SoundScraper::cBinop_IIyW1IAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_kcGb6NPh_sendMessage);
}

void Heavy_SoundScraper::cMsg_CPbqDH1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_D1GqFIK5, 0, m, &hTable_D1GqFIK5_sendMessage);
}

void Heavy_SoundScraper::cCast_jVRNamuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZKYfhAra, 0, m, &cDelay_ZKYfhAra_sendMessage);
}

void Heavy_SoundScraper::cMsg_TxYeLUJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8oqcSq0s, 2, m, &cDelay_8oqcSq0s_sendMessage);
}

void Heavy_SoundScraper::cMsg_D5bD0FSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_o7YBXfC9, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_SkpIln9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1iVuObmz_sendMessage);
}

void Heavy_SoundScraper::cSystem_1iVuObmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xoI9XCsp_sendMessage);
}

void Heavy_SoundScraper::cDelay_c411uXj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c411uXj1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XbNkKRAM, 0, m, &cDelay_XbNkKRAM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c411uXj1, 0, m, &cDelay_c411uXj1_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5cCbnJyF, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_XbNkKRAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XbNkKRAM, m);
  cMsg_smqD4bFn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Ja7sffJ1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_qWFBFa4Q_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_ghaJl5WZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2qm1bYjo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_knNOXmUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bB2YPlrd_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c411uXj1, 2, m, &cDelay_c411uXj1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rAozFoXd_sendMessage);
}

void Heavy_SoundScraper::cMsg_2qm1bYjo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_knNOXmUv, 0, m, &hTable_knNOXmUv_sendMessage);
}

void Heavy_SoundScraper::cBinop_xoI9XCsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_ghaJl5WZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_smqD4bFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_knNOXmUv, 0, m, &hTable_knNOXmUv_sendMessage);
}

void Heavy_SoundScraper::cCast_rAozFoXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_c411uXj1, 0, m, &cDelay_c411uXj1_sendMessage);
}

void Heavy_SoundScraper::cMsg_bB2YPlrd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XbNkKRAM, 2, m, &cDelay_XbNkKRAM_sendMessage);
}

void Heavy_SoundScraper::cMsg_qWFBFa4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5cCbnJyF, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_mc0UUh1K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lkV6JfMQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_lkV6JfMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_x6OdPoaN_sendMessage);
}

void Heavy_SoundScraper::cDelay_v8dA0fYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_v8dA0fYx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fxj5kpf4, 0, m, &cDelay_fxj5kpf4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_v8dA0fYx, 0, m, &cDelay_v8dA0fYx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lMtm8tzT, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_fxj5kpf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fxj5kpf4, m);
  cMsg_a26Z5tvJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_zx8zHelX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_8ucehz6k_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_XCgwa9Aq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WkbnE5Pb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_9xd8fRNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NXyjZg5h_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_v8dA0fYx, 2, m, &cDelay_v8dA0fYx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kcaP7AzO_sendMessage);
}

void Heavy_SoundScraper::cMsg_WkbnE5Pb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_9xd8fRNK, 0, m, &hTable_9xd8fRNK_sendMessage);
}

void Heavy_SoundScraper::cBinop_x6OdPoaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_XCgwa9Aq_sendMessage);
}

void Heavy_SoundScraper::cMsg_a26Z5tvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_9xd8fRNK, 0, m, &hTable_9xd8fRNK_sendMessage);
}

void Heavy_SoundScraper::cCast_kcaP7AzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_v8dA0fYx, 0, m, &cDelay_v8dA0fYx_sendMessage);
}

void Heavy_SoundScraper::cMsg_NXyjZg5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_fxj5kpf4, 2, m, &cDelay_fxj5kpf4_sendMessage);
}

void Heavy_SoundScraper::cMsg_8ucehz6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lMtm8tzT, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_vyOfrXzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_bHJeEd7c_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_34bV3DKd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_OYYw29Lk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yCRLePmM, HV_BINOP_POW, 0, m, &cBinop_yCRLePmM_sendMessage);
}

void Heavy_SoundScraper::cBinop_yCRLePmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_n7VHcbnE_sendMessage);
}

void Heavy_SoundScraper::cBinop_hW7Yak19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Uvr0b5Kq_sendMessage);
}

void Heavy_SoundScraper::cCast_ZOosEr1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ss6FCvhr_sendMessage);
}

void Heavy_SoundScraper::cCast_O7xsCUgk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vyOfrXzD, 0, m, &cIf_vyOfrXzD_sendMessage);
}

void Heavy_SoundScraper::cBinop_ss6FCvhr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vyOfrXzD, 1, m, &cIf_vyOfrXzD_sendMessage);
}

void Heavy_SoundScraper::cBinop_34bV3DKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_hW7Yak19_sendMessage);
}

void Heavy_SoundScraper::cMsg_bHJeEd7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_n7VHcbnE_sendMessage);
}

void Heavy_SoundScraper::cBinop_Uvr0b5Kq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yCRLePmM, HV_BINOP_POW, 1, m, &cBinop_yCRLePmM_sendMessage);
  cMsg_OYYw29Lk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_1QQab4Yq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Pbc8ILGk, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_BgmuUnR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_dJqq3XCk, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_CV96GQwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lcn5J4Qj_sendMessage);
}

void Heavy_SoundScraper::cBinop_lcn5J4Qj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_y6xQWbu1_sendMessage);
}

void Heavy_SoundScraper::cVar_BBEk2wpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aULWWp7J, HV_BINOP_MULTIPLY, 0, m, &cBinop_aULWWp7J_sendMessage);
}

void Heavy_SoundScraper::cMsg_C6lDkyb8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HsxZ6PmR_sendMessage);
}

void Heavy_SoundScraper::cSystem_HsxZ6PmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aVf4U3lI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_aULWWp7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2tUhEmEO_sendMessage);
}

void Heavy_SoundScraper::cBinop_It6zmK2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aULWWp7J, HV_BINOP_MULTIPLY, 1, m, &cBinop_aULWWp7J_sendMessage);
}

void Heavy_SoundScraper::cMsg_aVf4U3lI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_It6zmK2y_sendMessage);
}

void Heavy_SoundScraper::cBinop_2tUhEmEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8Q0mZqIU_sendMessage);
}

void Heavy_SoundScraper::cBinop_8Q0mZqIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TudshPKQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KwH7uPdq, m);
}

void Heavy_SoundScraper::cBinop_TudshPKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jF1QO3XA, m);
}

void Heavy_SoundScraper::cVar_72epLU0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZOosEr1w_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O7xsCUgk_sendMessage);
}

void Heavy_SoundScraper::cVar_m3zpkrFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_CV96GQwh_sendMessage);
}

void Heavy_SoundScraper::cVar_qHNmWRHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_EIMx7ZM6_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WBJA7XDb, 0, m, &cIf_WBJA7XDb_sendMessage);
}

void Heavy_SoundScraper::cVar_9Lf5p4hx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_UXdPVewn_sendMessage);
}

void Heavy_SoundScraper::cIf_WBJA7XDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_GCbf97Ye_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Db5opZ2x, 0, m, &cVar_Db5opZ2x_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_EIMx7ZM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WBJA7XDb, 1, m, &cIf_WBJA7XDb_sendMessage);
}

void Heavy_SoundScraper::cBinop_UXdPVewn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EDkLxmY1_sendMessage);
}

void Heavy_SoundScraper::cBinop_EDkLxmY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0BwSej3D, 0, m, &cVar_0BwSej3D_sendMessage);
}

void Heavy_SoundScraper::cTabhead_IdTyyQqV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RRVSYrRz, HV_BINOP_SUBTRACT, 0, m, &cBinop_RRVSYrRz_sendMessage);
}

void Heavy_SoundScraper::cMsg_zezIwlEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ugrBX9i9_sendMessage);
}

void Heavy_SoundScraper::cSystem_ugrBX9i9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OICs0ozy_sendMessage);
}

void Heavy_SoundScraper::cVar_nA588aRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bMu0uEf6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_rt118rBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rt118rBW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PQ2YbLFx, 0, m, &cDelay_PQ2YbLFx_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZhvN7uYw, 0, m, &sTabread_ZhvN7uYw_sendMessage);
}

void Heavy_SoundScraper::cDelay_PQ2YbLFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PQ2YbLFx, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZhvN7uYw, 0, m, &sTabread_ZhvN7uYw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PQ2YbLFx, 0, m, &cDelay_PQ2YbLFx_sendMessage);
}

void Heavy_SoundScraper::sTabread_ZhvN7uYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IwsqXvWO, HV_BINOP_SUBTRACT, 0, m, &cBinop_IwsqXvWO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_K5uJbQkI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3LsqehjA, HV_BINOP_MAX, 0, m, &cBinop_3LsqehjA_sendMessage);
}

void Heavy_SoundScraper::cBinop_OICs0ozy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K5uJbQkI, HV_BINOP_MULTIPLY, 0, m, &cBinop_K5uJbQkI_sendMessage);
}

void Heavy_SoundScraper::cBinop_RRVSYrRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dEgUWUZ6_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZhvN7uYw, 0, m, &sTabread_ZhvN7uYw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kTsI70vp_sendMessage);
}

void Heavy_SoundScraper::cSystem_K67DfmiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IwsqXvWO, HV_BINOP_SUBTRACT, 1, m, &cBinop_IwsqXvWO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PQ2YbLFx, 2, m, &cDelay_PQ2YbLFx_sendMessage);
}

void Heavy_SoundScraper::cMsg_bMu0uEf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K67DfmiX_sendMessage);
}

void Heavy_SoundScraper::cMsg_dEgUWUZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rt118rBW, 0, m, &cDelay_rt118rBW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PQ2YbLFx, 0, m, &cDelay_PQ2YbLFx_sendMessage);
}

void Heavy_SoundScraper::cMsg_RcPAoHsW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_3LsqehjA, HV_BINOP_MAX, 1, m, &cBinop_3LsqehjA_sendMessage);
}

void Heavy_SoundScraper::cBinop_3LsqehjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RRVSYrRz, HV_BINOP_SUBTRACT, 1, m, &cBinop_RRVSYrRz_sendMessage);
}

void Heavy_SoundScraper::cCast_kTsI70vp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rt118rBW, 0, m, &cDelay_rt118rBW_sendMessage);
}

void Heavy_SoundScraper::cBinop_yb290CWA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rt118rBW, 2, m, &cDelay_rt118rBW_sendMessage);
}

void Heavy_SoundScraper::cBinop_IwsqXvWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yb290CWA_sendMessage);
}

void Heavy_SoundScraper::cCast_6vYsCIBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nA588aRO, 0, m, &cVar_nA588aRO_sendMessage);
  cMsg_zezIwlEy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IdTyyQqV, 0, m, &cTabhead_IdTyyQqV_sendMessage);
}

void Heavy_SoundScraper::cMsg_xWilxKpb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YCwFuLBW_sendMessage);
}

void Heavy_SoundScraper::cSystem_YCwFuLBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IGpjuta1_sendMessage);
}

void Heavy_SoundScraper::cDelay_JGo6XOn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JGo6XOn3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3CK3mcLI, 0, m, &cDelay_3CK3mcLI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JGo6XOn3, 0, m, &cDelay_JGo6XOn3_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mwTuQgYl, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_3CK3mcLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3CK3mcLI, m);
  cMsg_rZWefaXe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ZN7aVB1v_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LQtMHxTZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_9V8ggwOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FJ4lwpEV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_gRCFkes3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dpvZnjU6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JGo6XOn3, 2, m, &cDelay_JGo6XOn3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NX84YVdw_sendMessage);
}

void Heavy_SoundScraper::cMsg_FJ4lwpEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gRCFkes3, 0, m, &hTable_gRCFkes3_sendMessage);
}

void Heavy_SoundScraper::cBinop_IGpjuta1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_9V8ggwOP_sendMessage);
}

void Heavy_SoundScraper::cMsg_rZWefaXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gRCFkes3, 0, m, &hTable_gRCFkes3_sendMessage);
}

void Heavy_SoundScraper::cCast_NX84YVdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JGo6XOn3, 0, m, &cDelay_JGo6XOn3_sendMessage);
}

void Heavy_SoundScraper::cMsg_dpvZnjU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_3CK3mcLI, 2, m, &cDelay_3CK3mcLI_sendMessage);
}

void Heavy_SoundScraper::cMsg_LQtMHxTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mwTuQgYl, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_T5kxR6Bj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_41csDtlr, HV_BINOP_SUBTRACT, 0, m, &cBinop_41csDtlr_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZWSrqO8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1tPutImt_sendMessage);
}

void Heavy_SoundScraper::cSystem_1tPutImt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yjKwmYcL_sendMessage);
}

void Heavy_SoundScraper::cVar_aJBko5Hj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BFX96LqF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_bHRDsWLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bHRDsWLt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wfF6RhJO, 0, m, &cDelay_wfF6RhJO_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ugbd5hyq, 0, m, &sTabread_Ugbd5hyq_sendMessage);
}

void Heavy_SoundScraper::cDelay_wfF6RhJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wfF6RhJO, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ugbd5hyq, 0, m, &sTabread_Ugbd5hyq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wfF6RhJO, 0, m, &cDelay_wfF6RhJO_sendMessage);
}

void Heavy_SoundScraper::sTabread_Ugbd5hyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SEEB5F0u, HV_BINOP_SUBTRACT, 0, m, &cBinop_SEEB5F0u_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_8f0fjtST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sxJT4RrV, HV_BINOP_MAX, 0, m, &cBinop_sxJT4RrV_sendMessage);
}

void Heavy_SoundScraper::cBinop_yjKwmYcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8f0fjtST, HV_BINOP_MULTIPLY, 0, m, &cBinop_8f0fjtST_sendMessage);
}

void Heavy_SoundScraper::cBinop_41csDtlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BG4MGt9m_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ugbd5hyq, 0, m, &sTabread_Ugbd5hyq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s8ymCwun_sendMessage);
}

void Heavy_SoundScraper::cSystem_BK0F4tTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SEEB5F0u, HV_BINOP_SUBTRACT, 1, m, &cBinop_SEEB5F0u_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wfF6RhJO, 2, m, &cDelay_wfF6RhJO_sendMessage);
}

void Heavy_SoundScraper::cMsg_BFX96LqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BK0F4tTk_sendMessage);
}

void Heavy_SoundScraper::cMsg_BG4MGt9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bHRDsWLt, 0, m, &cDelay_bHRDsWLt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wfF6RhJO, 0, m, &cDelay_wfF6RhJO_sendMessage);
}

void Heavy_SoundScraper::cMsg_IUpm8iCp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_sxJT4RrV, HV_BINOP_MAX, 1, m, &cBinop_sxJT4RrV_sendMessage);
}

void Heavy_SoundScraper::cBinop_sxJT4RrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_41csDtlr, HV_BINOP_SUBTRACT, 1, m, &cBinop_41csDtlr_sendMessage);
}

void Heavy_SoundScraper::cCast_s8ymCwun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bHRDsWLt, 0, m, &cDelay_bHRDsWLt_sendMessage);
}

void Heavy_SoundScraper::cBinop_PyTEWkAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bHRDsWLt, 2, m, &cDelay_bHRDsWLt_sendMessage);
}

void Heavy_SoundScraper::cBinop_SEEB5F0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PyTEWkAp_sendMessage);
}

void Heavy_SoundScraper::cCast_DKIXSzMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aJBko5Hj, 0, m, &cVar_aJBko5Hj_sendMessage);
  cMsg_ZWSrqO8N_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_T5kxR6Bj, 0, m, &cTabhead_T5kxR6Bj_sendMessage);
}

void Heavy_SoundScraper::cMsg_s8T6WkLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ruoXSHqU_sendMessage);
}

void Heavy_SoundScraper::cSystem_ruoXSHqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_l7yplPqv_sendMessage);
}

void Heavy_SoundScraper::cDelay_7JH0YH4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7JH0YH4s, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_a1AzfBlj, 0, m, &cDelay_a1AzfBlj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7JH0YH4s, 0, m, &cDelay_7JH0YH4s_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Yk4nFHM7, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_a1AzfBlj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_a1AzfBlj, m);
  cMsg_XoM7YC3e_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_kdvyBf72_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_oBeWhd0w_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_R1zytifr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7UEHKhfU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_ht2IgTgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ko2XHkRy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7JH0YH4s, 2, m, &cDelay_7JH0YH4s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_15RE7BtB_sendMessage);
}

void Heavy_SoundScraper::cMsg_7UEHKhfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ht2IgTgH, 0, m, &hTable_ht2IgTgH_sendMessage);
}

void Heavy_SoundScraper::cBinop_l7yplPqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_R1zytifr_sendMessage);
}

void Heavy_SoundScraper::cMsg_XoM7YC3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ht2IgTgH, 0, m, &hTable_ht2IgTgH_sendMessage);
}

void Heavy_SoundScraper::cCast_15RE7BtB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7JH0YH4s, 0, m, &cDelay_7JH0YH4s_sendMessage);
}

void Heavy_SoundScraper::cMsg_ko2XHkRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_a1AzfBlj, 2, m, &cDelay_a1AzfBlj_sendMessage);
}

void Heavy_SoundScraper::cMsg_oBeWhd0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Yk4nFHM7, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_SorZQocM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vmEytyx5, HV_BINOP_SUBTRACT, 0, m, &cBinop_vmEytyx5_sendMessage);
}

void Heavy_SoundScraper::cMsg_F1O4oH77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YUUd1eeD_sendMessage);
}

void Heavy_SoundScraper::cSystem_YUUd1eeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sLf0rT5z_sendMessage);
}

void Heavy_SoundScraper::cVar_3fu5Vlkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1OsKshIb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_ccRbj4Le_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ccRbj4Le, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fzfjgn51, 0, m, &cDelay_Fzfjgn51_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_H9bw0qaf, 0, m, &sTabread_H9bw0qaf_sendMessage);
}

void Heavy_SoundScraper::cDelay_Fzfjgn51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Fzfjgn51, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_H9bw0qaf, 0, m, &sTabread_H9bw0qaf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fzfjgn51, 0, m, &cDelay_Fzfjgn51_sendMessage);
}

void Heavy_SoundScraper::sTabread_H9bw0qaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_R8ThyE2P, HV_BINOP_SUBTRACT, 0, m, &cBinop_R8ThyE2P_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Dp3IGlxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oDRtib9r, HV_BINOP_MAX, 0, m, &cBinop_oDRtib9r_sendMessage);
}

void Heavy_SoundScraper::cBinop_sLf0rT5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dp3IGlxb, HV_BINOP_MULTIPLY, 0, m, &cBinop_Dp3IGlxb_sendMessage);
}

void Heavy_SoundScraper::cBinop_vmEytyx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uNw0ssa3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_H9bw0qaf, 0, m, &sTabread_H9bw0qaf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JDAwkBAU_sendMessage);
}

void Heavy_SoundScraper::cSystem_OibO7lFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8ThyE2P, HV_BINOP_SUBTRACT, 1, m, &cBinop_R8ThyE2P_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fzfjgn51, 2, m, &cDelay_Fzfjgn51_sendMessage);
}

void Heavy_SoundScraper::cMsg_1OsKshIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OibO7lFH_sendMessage);
}

void Heavy_SoundScraper::cMsg_uNw0ssa3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ccRbj4Le, 0, m, &cDelay_ccRbj4Le_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fzfjgn51, 0, m, &cDelay_Fzfjgn51_sendMessage);
}

void Heavy_SoundScraper::cMsg_BYchpieP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_oDRtib9r, HV_BINOP_MAX, 1, m, &cBinop_oDRtib9r_sendMessage);
}

void Heavy_SoundScraper::cBinop_oDRtib9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vmEytyx5, HV_BINOP_SUBTRACT, 1, m, &cBinop_vmEytyx5_sendMessage);
}

void Heavy_SoundScraper::cCast_JDAwkBAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ccRbj4Le, 0, m, &cDelay_ccRbj4Le_sendMessage);
}

void Heavy_SoundScraper::cBinop_o9FD0fX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ccRbj4Le, 2, m, &cDelay_ccRbj4Le_sendMessage);
}

void Heavy_SoundScraper::cBinop_R8ThyE2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_o9FD0fX2_sendMessage);
}

void Heavy_SoundScraper::cCast_zAzXWWUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3fu5Vlkm, 0, m, &cVar_3fu5Vlkm_sendMessage);
  cMsg_F1O4oH77_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SorZQocM, 0, m, &cTabhead_SorZQocM_sendMessage);
}

void Heavy_SoundScraper::cMsg_e9tDrxrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ygw0U2MZ_sendMessage);
}

void Heavy_SoundScraper::cSystem_ygw0U2MZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vb9GQ8Cw_sendMessage);
}

void Heavy_SoundScraper::cDelay_xMnAsw6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xMnAsw6c, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KYK3PRY1, 0, m, &cDelay_KYK3PRY1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xMnAsw6c, 0, m, &cDelay_xMnAsw6c_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZvPOLZEn, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_KYK3PRY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KYK3PRY1, m);
  cMsg_PT2XdG6o_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_O8d0MTsV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mcDGgY21_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Eg8MBJ9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IvzUrhoH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_OMXsco6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2fUJhxCA_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xMnAsw6c, 2, m, &cDelay_xMnAsw6c_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XpBKNEDH_sendMessage);
}

void Heavy_SoundScraper::cMsg_IvzUrhoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_OMXsco6t, 0, m, &hTable_OMXsco6t_sendMessage);
}

void Heavy_SoundScraper::cBinop_vb9GQ8Cw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_Eg8MBJ9Y_sendMessage);
}

void Heavy_SoundScraper::cMsg_PT2XdG6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_OMXsco6t, 0, m, &hTable_OMXsco6t_sendMessage);
}

void Heavy_SoundScraper::cCast_XpBKNEDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xMnAsw6c, 0, m, &cDelay_xMnAsw6c_sendMessage);
}

void Heavy_SoundScraper::cMsg_2fUJhxCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_KYK3PRY1, 2, m, &cDelay_KYK3PRY1_sendMessage);
}

void Heavy_SoundScraper::cMsg_mcDGgY21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZvPOLZEn, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_7UcD3OfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IfokH60z, HV_BINOP_SUBTRACT, 0, m, &cBinop_IfokH60z_sendMessage);
}

void Heavy_SoundScraper::cMsg_2kHR0Wxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_j8O8uPZZ_sendMessage);
}

void Heavy_SoundScraper::cSystem_j8O8uPZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_noGLhoZh_sendMessage);
}

void Heavy_SoundScraper::cVar_F9Z5vpqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jePvFvw3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_QnO70ba6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QnO70ba6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G8c3IoqM, 0, m, &cDelay_G8c3IoqM_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FTyvzgHR, 0, m, &sTabread_FTyvzgHR_sendMessage);
}

void Heavy_SoundScraper::cDelay_G8c3IoqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_G8c3IoqM, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FTyvzgHR, 0, m, &sTabread_FTyvzgHR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G8c3IoqM, 0, m, &cDelay_G8c3IoqM_sendMessage);
}

void Heavy_SoundScraper::sTabread_FTyvzgHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kY9ptTMh, HV_BINOP_SUBTRACT, 0, m, &cBinop_kY9ptTMh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_iOQ900yN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_agKtreAN, HV_BINOP_MAX, 0, m, &cBinop_agKtreAN_sendMessage);
}

void Heavy_SoundScraper::cBinop_noGLhoZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iOQ900yN, HV_BINOP_MULTIPLY, 0, m, &cBinop_iOQ900yN_sendMessage);
}

void Heavy_SoundScraper::cBinop_IfokH60z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_77QiZX5c_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FTyvzgHR, 0, m, &sTabread_FTyvzgHR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HIILRCsb_sendMessage);
}

void Heavy_SoundScraper::cSystem_ELajcElF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kY9ptTMh, HV_BINOP_SUBTRACT, 1, m, &cBinop_kY9ptTMh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G8c3IoqM, 2, m, &cDelay_G8c3IoqM_sendMessage);
}

void Heavy_SoundScraper::cMsg_jePvFvw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ELajcElF_sendMessage);
}

void Heavy_SoundScraper::cMsg_77QiZX5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QnO70ba6, 0, m, &cDelay_QnO70ba6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G8c3IoqM, 0, m, &cDelay_G8c3IoqM_sendMessage);
}

void Heavy_SoundScraper::cMsg_SRzLcMvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_agKtreAN, HV_BINOP_MAX, 1, m, &cBinop_agKtreAN_sendMessage);
}

void Heavy_SoundScraper::cBinop_agKtreAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IfokH60z, HV_BINOP_SUBTRACT, 1, m, &cBinop_IfokH60z_sendMessage);
}

void Heavy_SoundScraper::cCast_HIILRCsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QnO70ba6, 0, m, &cDelay_QnO70ba6_sendMessage);
}

void Heavy_SoundScraper::cBinop_GcnUCOPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QnO70ba6, 2, m, &cDelay_QnO70ba6_sendMessage);
}

void Heavy_SoundScraper::cBinop_kY9ptTMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GcnUCOPd_sendMessage);
}

void Heavy_SoundScraper::cCast_pcnShbAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F9Z5vpqn, 0, m, &cVar_F9Z5vpqn_sendMessage);
  cMsg_2kHR0Wxo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7UcD3OfN, 0, m, &cTabhead_7UcD3OfN_sendMessage);
}

void Heavy_SoundScraper::cMsg_xr1MvIVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fFoFYA78_sendMessage);
}

void Heavy_SoundScraper::cSystem_fFoFYA78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nFo4oPaL_sendMessage);
}

void Heavy_SoundScraper::cDelay_MDrUqwwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MDrUqwwF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m8ZXNig2, 0, m, &cDelay_m8ZXNig2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MDrUqwwF, 0, m, &cDelay_MDrUqwwF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QgBfBLlZ, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_m8ZXNig2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_m8ZXNig2, m);
  cMsg_alusuvbF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_gNIewwAs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_aE1450tM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_mQvdQV85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pm8jyA0U_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_Ju3BKALx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MOUy3fBa_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MDrUqwwF, 2, m, &cDelay_MDrUqwwF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rRfPctue_sendMessage);
}

void Heavy_SoundScraper::cMsg_pm8jyA0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Ju3BKALx, 0, m, &hTable_Ju3BKALx_sendMessage);
}

void Heavy_SoundScraper::cBinop_nFo4oPaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_mQvdQV85_sendMessage);
}

void Heavy_SoundScraper::cMsg_alusuvbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Ju3BKALx, 0, m, &hTable_Ju3BKALx_sendMessage);
}

void Heavy_SoundScraper::cCast_rRfPctue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MDrUqwwF, 0, m, &cDelay_MDrUqwwF_sendMessage);
}

void Heavy_SoundScraper::cMsg_MOUy3fBa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_m8ZXNig2, 2, m, &cDelay_m8ZXNig2_sendMessage);
}

void Heavy_SoundScraper::cMsg_aE1450tM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QgBfBLlZ, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_H0Fjzoxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aw9U5yzW, HV_BINOP_SUBTRACT, 0, m, &cBinop_aw9U5yzW_sendMessage);
}

void Heavy_SoundScraper::cMsg_A7tKvd8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Mxm002JC_sendMessage);
}

void Heavy_SoundScraper::cSystem_Mxm002JC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_O82bqpg1_sendMessage);
}

void Heavy_SoundScraper::cVar_fbBmbnAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V7U4cH5Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_zTybHyKV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zTybHyKV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wT2pqzMd, 0, m, &cDelay_wT2pqzMd_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OTRfYaXU, 0, m, &sTabread_OTRfYaXU_sendMessage);
}

void Heavy_SoundScraper::cDelay_wT2pqzMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wT2pqzMd, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OTRfYaXU, 0, m, &sTabread_OTRfYaXU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wT2pqzMd, 0, m, &cDelay_wT2pqzMd_sendMessage);
}

void Heavy_SoundScraper::sTabread_OTRfYaXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_f9NnUgUT, HV_BINOP_SUBTRACT, 0, m, &cBinop_f9NnUgUT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_WysZM2m4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tqVoNdlE, HV_BINOP_MAX, 0, m, &cBinop_tqVoNdlE_sendMessage);
}

void Heavy_SoundScraper::cBinop_O82bqpg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WysZM2m4, HV_BINOP_MULTIPLY, 0, m, &cBinop_WysZM2m4_sendMessage);
}

void Heavy_SoundScraper::cBinop_aw9U5yzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xi8gdkwg_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OTRfYaXU, 0, m, &sTabread_OTRfYaXU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1RrIf12Z_sendMessage);
}

void Heavy_SoundScraper::cSystem_dtTvOoOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f9NnUgUT, HV_BINOP_SUBTRACT, 1, m, &cBinop_f9NnUgUT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wT2pqzMd, 2, m, &cDelay_wT2pqzMd_sendMessage);
}

void Heavy_SoundScraper::cMsg_V7U4cH5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dtTvOoOO_sendMessage);
}

void Heavy_SoundScraper::cMsg_xi8gdkwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zTybHyKV, 0, m, &cDelay_zTybHyKV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wT2pqzMd, 0, m, &cDelay_wT2pqzMd_sendMessage);
}

void Heavy_SoundScraper::cMsg_o57rUdpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_tqVoNdlE, HV_BINOP_MAX, 1, m, &cBinop_tqVoNdlE_sendMessage);
}

void Heavy_SoundScraper::cBinop_tqVoNdlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aw9U5yzW, HV_BINOP_SUBTRACT, 1, m, &cBinop_aw9U5yzW_sendMessage);
}

void Heavy_SoundScraper::cCast_1RrIf12Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zTybHyKV, 0, m, &cDelay_zTybHyKV_sendMessage);
}

void Heavy_SoundScraper::cBinop_7Y6gNK6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zTybHyKV, 2, m, &cDelay_zTybHyKV_sendMessage);
}

void Heavy_SoundScraper::cBinop_f9NnUgUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7Y6gNK6i_sendMessage);
}

void Heavy_SoundScraper::cCast_oHPT31J6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fbBmbnAL, 0, m, &cVar_fbBmbnAL_sendMessage);
  cMsg_A7tKvd8f_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_H0Fjzoxy, 0, m, &cTabhead_H0Fjzoxy_sendMessage);
}

void Heavy_SoundScraper::cMsg_HLrKBv6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ucKDBv0V_sendMessage);
}

void Heavy_SoundScraper::cSystem_ucKDBv0V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xdT8ZmrY_sendMessage);
}

void Heavy_SoundScraper::cDelay_gAlVUM6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gAlVUM6K, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1vG232Ml, 0, m, &cDelay_1vG232Ml_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gAlVUM6K, 0, m, &cDelay_gAlVUM6K_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9t4zc6T8, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_1vG232Ml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1vG232Ml, m);
  cMsg_l7mtZFuX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_KOu6lvO4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Zq4iFEm7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_9jDggFAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OpvUJ8iB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_jyI9ewhb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UJn8mVue_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gAlVUM6K, 2, m, &cDelay_gAlVUM6K_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CbpfGJEX_sendMessage);
}

void Heavy_SoundScraper::cMsg_OpvUJ8iB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jyI9ewhb, 0, m, &hTable_jyI9ewhb_sendMessage);
}

void Heavy_SoundScraper::cBinop_xdT8ZmrY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_9jDggFAW_sendMessage);
}

void Heavy_SoundScraper::cMsg_l7mtZFuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jyI9ewhb, 0, m, &hTable_jyI9ewhb_sendMessage);
}

void Heavy_SoundScraper::cCast_CbpfGJEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gAlVUM6K, 0, m, &cDelay_gAlVUM6K_sendMessage);
}

void Heavy_SoundScraper::cMsg_UJn8mVue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_1vG232Ml, 2, m, &cDelay_1vG232Ml_sendMessage);
}

void Heavy_SoundScraper::cMsg_Zq4iFEm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9t4zc6T8, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_faczOfG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xn2ywXmg, HV_BINOP_SUBTRACT, 0, m, &cBinop_Xn2ywXmg_sendMessage);
}

void Heavy_SoundScraper::cMsg_qgEK1ib3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4lUQgYWi_sendMessage);
}

void Heavy_SoundScraper::cSystem_4lUQgYWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_A6uQjFG2_sendMessage);
}

void Heavy_SoundScraper::cVar_dLQB0ucx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vupYxXln_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_Ju3PFahR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ju3PFahR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EVAHQijx, 0, m, &cDelay_EVAHQijx_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_skrQgTu2, 0, m, &sTabread_skrQgTu2_sendMessage);
}

void Heavy_SoundScraper::cDelay_EVAHQijx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EVAHQijx, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_skrQgTu2, 0, m, &sTabread_skrQgTu2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EVAHQijx, 0, m, &cDelay_EVAHQijx_sendMessage);
}

void Heavy_SoundScraper::sTabread_skrQgTu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_m3hlRMCw, HV_BINOP_SUBTRACT, 0, m, &cBinop_m3hlRMCw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Za8djoPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_70MY1T46, HV_BINOP_MAX, 0, m, &cBinop_70MY1T46_sendMessage);
}

void Heavy_SoundScraper::cBinop_A6uQjFG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Za8djoPY, HV_BINOP_MULTIPLY, 0, m, &cBinop_Za8djoPY_sendMessage);
}

void Heavy_SoundScraper::cBinop_Xn2ywXmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ryoiKoWC_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_skrQgTu2, 0, m, &sTabread_skrQgTu2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AZSP0dhW_sendMessage);
}

void Heavy_SoundScraper::cSystem_k3HWyJ7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m3hlRMCw, HV_BINOP_SUBTRACT, 1, m, &cBinop_m3hlRMCw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EVAHQijx, 2, m, &cDelay_EVAHQijx_sendMessage);
}

void Heavy_SoundScraper::cMsg_vupYxXln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k3HWyJ7t_sendMessage);
}

void Heavy_SoundScraper::cMsg_ryoiKoWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ju3PFahR, 0, m, &cDelay_Ju3PFahR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EVAHQijx, 0, m, &cDelay_EVAHQijx_sendMessage);
}

void Heavy_SoundScraper::cMsg_kYS0xSrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_70MY1T46, HV_BINOP_MAX, 1, m, &cBinop_70MY1T46_sendMessage);
}

void Heavy_SoundScraper::cBinop_70MY1T46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xn2ywXmg, HV_BINOP_SUBTRACT, 1, m, &cBinop_Xn2ywXmg_sendMessage);
}

void Heavy_SoundScraper::cCast_AZSP0dhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ju3PFahR, 0, m, &cDelay_Ju3PFahR_sendMessage);
}

void Heavy_SoundScraper::cBinop_DJHQiZKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ju3PFahR, 2, m, &cDelay_Ju3PFahR_sendMessage);
}

void Heavy_SoundScraper::cBinop_m3hlRMCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DJHQiZKh_sendMessage);
}

void Heavy_SoundScraper::cCast_48GCiCsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dLQB0ucx, 0, m, &cVar_dLQB0ucx_sendMessage);
  cMsg_qgEK1ib3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_faczOfG2, 0, m, &cTabhead_faczOfG2_sendMessage);
}

void Heavy_SoundScraper::cMsg_oHe59qJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6XAdaqXq_sendMessage);
}

void Heavy_SoundScraper::cSystem_6XAdaqXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6jj9JXcR_sendMessage);
}

void Heavy_SoundScraper::cDelay_eDyvXre5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eDyvXre5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PD0RoIoA, 0, m, &cDelay_PD0RoIoA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eDyvXre5, 0, m, &cDelay_eDyvXre5_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ET7OwVWI, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_PD0RoIoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PD0RoIoA, m);
  cMsg_SzqvZIaq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_7juT7Zsy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_qInaOCxQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Mk0K3fcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FEbhpG1d_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_GNDU06Rg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fc97YJH8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eDyvXre5, 2, m, &cDelay_eDyvXre5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AC2u0mOP_sendMessage);
}

void Heavy_SoundScraper::cMsg_FEbhpG1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GNDU06Rg, 0, m, &hTable_GNDU06Rg_sendMessage);
}

void Heavy_SoundScraper::cBinop_6jj9JXcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_Mk0K3fcE_sendMessage);
}

void Heavy_SoundScraper::cMsg_SzqvZIaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GNDU06Rg, 0, m, &hTable_GNDU06Rg_sendMessage);
}

void Heavy_SoundScraper::cCast_AC2u0mOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eDyvXre5, 0, m, &cDelay_eDyvXre5_sendMessage);
}

void Heavy_SoundScraper::cMsg_Fc97YJH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_PD0RoIoA, 2, m, &cDelay_PD0RoIoA_sendMessage);
}

void Heavy_SoundScraper::cMsg_qInaOCxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ET7OwVWI, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_Db5opZ2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BBEk2wpJ, 0, m, &cVar_BBEk2wpJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_amsna2uF, 0, m, &cVar_amsna2uF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8y9geDsc, 0, m, &cVar_8y9geDsc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8lbhnd7G, 0, m, &cVar_8lbhnd7G_sendMessage);
}

void Heavy_SoundScraper::cVar_0BwSej3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_VdGSxuNS_sendMessage);
}

void Heavy_SoundScraper::cPack_qss04jOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_SHoCFhFD, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_amsna2uF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P5pszdP0, HV_BINOP_MULTIPLY, 0, m, &cBinop_P5pszdP0_sendMessage);
}

void Heavy_SoundScraper::cMsg_qkvtpNXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_esFRBxTo_sendMessage);
}

void Heavy_SoundScraper::cSystem_esFRBxTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vlQshKIz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_P5pszdP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fGzVk3Aq_sendMessage);
}

void Heavy_SoundScraper::cBinop_1iTXrsvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P5pszdP0, HV_BINOP_MULTIPLY, 1, m, &cBinop_P5pszdP0_sendMessage);
}

void Heavy_SoundScraper::cMsg_vlQshKIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1iTXrsvj_sendMessage);
}

void Heavy_SoundScraper::cBinop_fGzVk3Aq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UgMHBj9B_sendMessage);
}

void Heavy_SoundScraper::cBinop_UgMHBj9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_elGQKR3i_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_un1g1d0O, m);
}

void Heavy_SoundScraper::cBinop_elGQKR3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ajAz2Xlp, m);
}

void Heavy_SoundScraper::cVar_8y9geDsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dt76G4V4, HV_BINOP_MULTIPLY, 0, m, &cBinop_dt76G4V4_sendMessage);
}

void Heavy_SoundScraper::cMsg_kXm6ZoYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Jo4r2S1T_sendMessage);
}

void Heavy_SoundScraper::cSystem_Jo4r2S1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NPE9Y1cb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_dt76G4V4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_y9IWMv3a_sendMessage);
}

void Heavy_SoundScraper::cBinop_YriLvpXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dt76G4V4, HV_BINOP_MULTIPLY, 1, m, &cBinop_dt76G4V4_sendMessage);
}

void Heavy_SoundScraper::cMsg_NPE9Y1cb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YriLvpXe_sendMessage);
}

void Heavy_SoundScraper::cBinop_y9IWMv3a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_YtWdMOzu_sendMessage);
}

void Heavy_SoundScraper::cBinop_YtWdMOzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qmLvW1Pm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_E5Wh7Xmx, m);
}

void Heavy_SoundScraper::cBinop_qmLvW1Pm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_u1QcfUtf, m);
}

void Heavy_SoundScraper::cVar_8lbhnd7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_egWLjvgg, HV_BINOP_MULTIPLY, 0, m, &cBinop_egWLjvgg_sendMessage);
}

void Heavy_SoundScraper::cMsg_OToyrAqI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RaMOdOhl_sendMessage);
}

void Heavy_SoundScraper::cSystem_RaMOdOhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uMMl3FIg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_egWLjvgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Plkhs6Ug_sendMessage);
}

void Heavy_SoundScraper::cBinop_8wADmAEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_egWLjvgg, HV_BINOP_MULTIPLY, 1, m, &cBinop_egWLjvgg_sendMessage);
}

void Heavy_SoundScraper::cMsg_uMMl3FIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8wADmAEi_sendMessage);
}

void Heavy_SoundScraper::cBinop_Plkhs6Ug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6j2e1CXF_sendMessage);
}

void Heavy_SoundScraper::cBinop_6j2e1CXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Vw79KTBm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_g0tWhXk8, m);
}

void Heavy_SoundScraper::cBinop_Vw79KTBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dEVXdxYr, m);
}

void Heavy_SoundScraper::cBinop_y6xQWbu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BgmuUnR8, 0, m, &cPack_BgmuUnR8_sendMessage);
}

void Heavy_SoundScraper::cMsg_GCbf97Ye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Db5opZ2x, 0, m, &cVar_Db5opZ2x_sendMessage);
}

void Heavy_SoundScraper::cBinop_VdGSxuNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qss04jOS, 0, m, &cPack_qss04jOS_sendMessage);
}

void Heavy_SoundScraper::cBinop_n7VHcbnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1QQab4Yq, 0, m, &cPack_1QQab4Yq_sendMessage);
}

void Heavy_SoundScraper::cVar_0ZeYgSOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MGF4voKT_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F1ErnitC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1nCZbteS_sendMessage);
}

void Heavy_SoundScraper::cIf_CxlZnwxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_JNUVRswL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_oHDvU8lp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_AcnNwqyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_e4be25pe, HV_BINOP_POW, 0, m, &cBinop_e4be25pe_sendMessage);
}

void Heavy_SoundScraper::cBinop_e4be25pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4fS6tWh4, 0, m, &cPack_4fS6tWh4_sendMessage);
}

void Heavy_SoundScraper::cBinop_3Z9hDECI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Y02xRi75_sendMessage);
}

void Heavy_SoundScraper::cCast_1nCZbteS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CxlZnwxy, 0, m, &cIf_CxlZnwxy_sendMessage);
}

void Heavy_SoundScraper::cCast_F1ErnitC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ejuLvDV7_sendMessage);
}

void Heavy_SoundScraper::cBinop_ejuLvDV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CxlZnwxy, 1, m, &cIf_CxlZnwxy_sendMessage);
}

void Heavy_SoundScraper::cBinop_oHDvU8lp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_3Z9hDECI_sendMessage);
}

void Heavy_SoundScraper::cMsg_JNUVRswL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_4fS6tWh4, 0, m, &cPack_4fS6tWh4_sendMessage);
}

void Heavy_SoundScraper::cBinop_Y02xRi75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e4be25pe, HV_BINOP_POW, 1, m, &cBinop_e4be25pe_sendMessage);
  cMsg_AcnNwqyh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_4fS6tWh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hzLthO4d, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_Rd9Febm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IfOmzliH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_MGF4voKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_tsbjO0XS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_tsbjO0XS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nPPo9706_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_IfOmzliH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ck2cgdMl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_lvDbudZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_2wUnQ4yZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_K2VbpgVx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_K2VbpgVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_JKPxsWCa_sendMessage);
}

void Heavy_SoundScraper::cCast_ddXbLh0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lvDbudZ3, 0, m, &cIf_lvDbudZ3_sendMessage);
}

void Heavy_SoundScraper::cCast_Rq5fgyAi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Qyeyo9vb_sendMessage);
}

void Heavy_SoundScraper::cMsg_2wUnQ4yZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_72epLU0S, 0, m, &cVar_72epLU0S_sendMessage);
}

void Heavy_SoundScraper::cBinop_JKPxsWCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_Dt92KM9P_sendMessage);
}

void Heavy_SoundScraper::cBinop_Dt92KM9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_H1vNxITQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_H1vNxITQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_72epLU0S, 0, m, &cVar_72epLU0S_sendMessage);
}

void Heavy_SoundScraper::cBinop_Qyeyo9vb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lvDbudZ3, 1, m, &cIf_lvDbudZ3_sendMessage);
}

void Heavy_SoundScraper::cBinop_x3Frj9l1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rq5fgyAi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ddXbLh0m_sendMessage);
}

void Heavy_SoundScraper::cBinop_m8MNnt5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_x3Frj9l1_sendMessage);
}

void Heavy_SoundScraper::cIf_NQbHl05N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_4EyCRMLa_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_48zdLGVR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_48zdLGVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_oVMI1FRi_sendMessage);
}

void Heavy_SoundScraper::cCast_MIZ6q09w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_G7oxvjU6_sendMessage);
}

void Heavy_SoundScraper::cCast_SJNQsvi6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NQbHl05N, 0, m, &cIf_NQbHl05N_sendMessage);
}

void Heavy_SoundScraper::cMsg_4EyCRMLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_MGF4voKT_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F1ErnitC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1nCZbteS_sendMessage);
}

void Heavy_SoundScraper::cBinop_oVMI1FRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_NgKtoYfJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_NgKtoYfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BTbr7h46_sendMessage);
}

void Heavy_SoundScraper::cBinop_BTbr7h46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MGF4voKT_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F1ErnitC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1nCZbteS_sendMessage);
}

void Heavy_SoundScraper::cBinop_G7oxvjU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NQbHl05N, 1, m, &cIf_NQbHl05N_sendMessage);
}

void Heavy_SoundScraper::cBinop_wOeZz9JP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MIZ6q09w_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SJNQsvi6_sendMessage);
}

void Heavy_SoundScraper::cBinop_hBZB7NQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wOeZz9JP_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_2nqKerbG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_KSgLsq0H_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_KSgLsq0H_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_DJ7jWdDK, 1, m, &cDelay_DJ7jWdDK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xYN8kJZv_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_DJ7jWdDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DJ7jWdDK, m);
  cMsg_8N4Rs3VZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KSgLsq0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DJ7jWdDK, 0, m, &cDelay_DJ7jWdDK_sendMessage);
}

void Heavy_SoundScraper::cCast_xYN8kJZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DJ7jWdDK, 0, m, &cDelay_DJ7jWdDK_sendMessage);
}

void Heavy_SoundScraper::cVar_cUziBdZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bJ6sKTLp, 0, m, &cPack_bJ6sKTLp_sendMessage);
}

void Heavy_SoundScraper::cVar_5qTMHlsd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_64v8TjFn_sendMessage);
}

void Heavy_SoundScraper::cVar_WmKlvB2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_KH7IJ4Nr_sendMessage);
}

void Heavy_SoundScraper::cPack_HndFaBJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_XV7Geksf, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_YFZTwRRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_1MejHyLZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_8GNttB9v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_YFZTwRRD_sendMessage);
}

void Heavy_SoundScraper::cPack_G8N8CuMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_7KmBqBtm, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_GeUdY93B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_wBFdGVAp_sendMessage);
}

void Heavy_SoundScraper::cMsg_Uxzpehuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PB0ogJOv_sendMessage);
}

void Heavy_SoundScraper::cSystem_PB0ogJOv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6Hw42f0O_sendMessage);
}

void Heavy_SoundScraper::cDelay_HkLcu35D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HkLcu35D, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iBr59nYr, 0, m, &cDelay_iBr59nYr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HkLcu35D, 0, m, &cDelay_HkLcu35D_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gxG0BJ0g, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_iBr59nYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iBr59nYr, m);
  cMsg_hK0yn8jP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_H2VOeTSJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_rSxZu4l6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_cIpnwIxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZVT4Y3lP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_izH9V5L1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bCztvQvT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HkLcu35D, 2, m, &cDelay_HkLcu35D_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_edHTVi0C_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZVT4Y3lP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_izH9V5L1, 0, m, &hTable_izH9V5L1_sendMessage);
}

void Heavy_SoundScraper::cBinop_6Hw42f0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_cIpnwIxi_sendMessage);
}

void Heavy_SoundScraper::cMsg_hK0yn8jP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_izH9V5L1, 0, m, &hTable_izH9V5L1_sendMessage);
}

void Heavy_SoundScraper::cCast_edHTVi0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HkLcu35D, 0, m, &cDelay_HkLcu35D_sendMessage);
}

void Heavy_SoundScraper::cMsg_bCztvQvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_iBr59nYr, 2, m, &cDelay_iBr59nYr_sendMessage);
}

void Heavy_SoundScraper::cMsg_rSxZu4l6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gxG0BJ0g, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_CHXavIij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sC9hBPDw_sendMessage);
}

void Heavy_SoundScraper::cSystem_sC9hBPDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_05X7j4t3_sendMessage);
}

void Heavy_SoundScraper::cVar_WKLIB3Ca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4bjEsNER_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_tKWGGaBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_uBvjbBHF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_MlqBeba3, m);
}

void Heavy_SoundScraper::cBinop_05X7j4t3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MzWkkHz4, m);
}

void Heavy_SoundScraper::cMsg_4bjEsNER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tKWGGaBc_sendMessage);
}

void Heavy_SoundScraper::cBinop_uBvjbBHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XambgzmC, m);
}

void Heavy_SoundScraper::cMsg_jo5slCdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_d4ei5FxJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_d4ei5FxJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1qSFel6D_sendMessage);
}

void Heavy_SoundScraper::cVar_gmdil0iA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NqlCEssq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_7uDHjxR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ud4Pwyiv_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ACIXjIeN, m);
}

void Heavy_SoundScraper::cBinop_1qSFel6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NjBW8hN8, m);
}

void Heavy_SoundScraper::cMsg_NqlCEssq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7uDHjxR3_sendMessage);
}

void Heavy_SoundScraper::cBinop_ud4Pwyiv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_a20CXYUT, m);
}

void Heavy_SoundScraper::cBinop_OzuKbb2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PQ25QXqM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_4b0T46Nh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BxNpvQR4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MAbmZHDR_sendMessage);
}

void Heavy_SoundScraper::cCast_BxNpvQR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OzuKbb2I, HV_BINOP_DIVIDE, 1, m, &cBinop_OzuKbb2I_sendMessage);
}

void Heavy_SoundScraper::cCast_MAbmZHDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OzuKbb2I, HV_BINOP_DIVIDE, 0, m, &cBinop_OzuKbb2I_sendMessage);
}

void Heavy_SoundScraper::cBinop_1MejHyLZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jsWreGVC_sendMessage);
}

void Heavy_SoundScraper::cBinop_64v8TjFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_8GNttB9v_sendMessage);
}

void Heavy_SoundScraper::cBinop_jsWreGVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OzuKbb2I, HV_BINOP_DIVIDE, 0, m, &cBinop_OzuKbb2I_sendMessage);
}

void Heavy_SoundScraper::cBinop_wBFdGVAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_G8N8CuMQ, 0, m, &cPack_G8N8CuMQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_KH7IJ4Nr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_4b0T46Nh_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_HndFaBJZ, 0, m, &cPack_HndFaBJZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_UrmGU4xo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_WmKlvB2M, 0, m, &cVar_WmKlvB2M_sendMessage);
}

void Heavy_SoundScraper::cMsg_NHzhWmsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_GeUdY93B, 0, m, &cVar_GeUdY93B_sendMessage);
}

void Heavy_SoundScraper::cMsg_PQ25QXqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ntJBN5QW, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_dMA1tyZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CSPBZ6CA, HV_BINOP_MULTIPLY, 0, m, &cBinop_CSPBZ6CA_sendMessage);
}

void Heavy_SoundScraper::cMsg_RDOLxSHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7ObkBedK_sendMessage);
}

void Heavy_SoundScraper::cSystem_7ObkBedK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rKCE2jSx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_CSPBZ6CA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_v9qduiEx_sendMessage);
}

void Heavy_SoundScraper::cBinop_2czFSVXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CSPBZ6CA, HV_BINOP_MULTIPLY, 1, m, &cBinop_CSPBZ6CA_sendMessage);
}

void Heavy_SoundScraper::cMsg_rKCE2jSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_2czFSVXR_sendMessage);
}

void Heavy_SoundScraper::cBinop_v9qduiEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VrHEwimp_sendMessage);
}

void Heavy_SoundScraper::cBinop_VrHEwimp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TNRh0iYf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9PZteRv6, m);
}

void Heavy_SoundScraper::cBinop_TNRh0iYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_K8OrsP83, m);
}

void Heavy_SoundScraper::cVar_7Pejvwqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_umpQuX5h, HV_BINOP_MULTIPLY, 0, m, &cBinop_umpQuX5h_sendMessage);
}

void Heavy_SoundScraper::cMsg_g2eeSLAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_btukILwp_sendMessage);
}

void Heavy_SoundScraper::cSystem_btukILwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MIsNt5s4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_umpQuX5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_XzuNFul8_sendMessage);
}

void Heavy_SoundScraper::cBinop_HTX6rQCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_umpQuX5h, HV_BINOP_MULTIPLY, 1, m, &cBinop_umpQuX5h_sendMessage);
}

void Heavy_SoundScraper::cMsg_MIsNt5s4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HTX6rQCi_sendMessage);
}

void Heavy_SoundScraper::cBinop_XzuNFul8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3M3ZuX2k_sendMessage);
}

void Heavy_SoundScraper::cBinop_3M3ZuX2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_kLI8jSib_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mHFwPA5F, m);
}

void Heavy_SoundScraper::cBinop_kLI8jSib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0bHHyJCc, m);
}

void Heavy_SoundScraper::cVar_uEfeo8q0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9qNXuCGn, HV_BINOP_MULTIPLY, 0, m, &cBinop_9qNXuCGn_sendMessage);
}

void Heavy_SoundScraper::cMsg_2O6jlEJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9BWdbf8K_sendMessage);
}

void Heavy_SoundScraper::cSystem_9BWdbf8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qZjh0YSG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_9qNXuCGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_naNIAba4_sendMessage);
}

void Heavy_SoundScraper::cBinop_5DUJqmBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9qNXuCGn, HV_BINOP_MULTIPLY, 1, m, &cBinop_9qNXuCGn_sendMessage);
}

void Heavy_SoundScraper::cMsg_qZjh0YSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5DUJqmBV_sendMessage);
}

void Heavy_SoundScraper::cBinop_naNIAba4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_V2zfWbVy_sendMessage);
}

void Heavy_SoundScraper::cBinop_V2zfWbVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9SNRjl8w_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_D3D4NVp4, m);
}

void Heavy_SoundScraper::cBinop_9SNRjl8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XgTJfZbo, m);
}

void Heavy_SoundScraper::cMsg_25ar8EoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DiAHWsW6_sendMessage);
}

void Heavy_SoundScraper::cSystem_DiAHWsW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ePJ029HQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_YYpyunGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_6BxU2kpt_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_yuMeOLBc, 0, m, &cIf_yuMeOLBc_sendMessage);
}

void Heavy_SoundScraper::cIf_yuMeOLBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_a353oKMS_sendMessage(_c, 0, m);
      cMsg_TOHZFy6o_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_CqKgaFsk_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_lHN86Wmx_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_621nj69Q, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_6BxU2kpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yuMeOLBc, 1, m, &cIf_yuMeOLBc_sendMessage);
}

void Heavy_SoundScraper::cMsg_CqKgaFsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XSbbLPAB_sendMessage);
}

void Heavy_SoundScraper::cBinop_XSbbLPAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_e8utBies, m);
}

void Heavy_SoundScraper::cBinop_lHN86Wmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CvO3NRNc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_CvO3NRNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_GJ8LOl9l_sendMessage);
}

void Heavy_SoundScraper::cBinop_GJ8LOl9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nsosJcdz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_nsosJcdz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_COvPaYYi_sendMessage);
}

void Heavy_SoundScraper::cBinop_COvPaYYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5bAz22ST, m);
}

void Heavy_SoundScraper::cBinop_RzLDGBjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_imVNHhRK, m);
}

void Heavy_SoundScraper::cMsg_ePJ029HQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_RzLDGBjt_sendMessage);
}

void Heavy_SoundScraper::cMsg_a353oKMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_lHN86Wmx_sendMessage);
}

void Heavy_SoundScraper::cMsg_TOHZFy6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_e8utBies, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_621nj69Q, m);
}

void Heavy_SoundScraper::cBinop_ItzH7eUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7Pejvwqr, 0, m, &cVar_7Pejvwqr_sendMessage);
}

void Heavy_SoundScraper::cBinop_d3XtGPjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dMA1tyZM, 0, m, &cVar_dMA1tyZM_sendMessage);
}

void Heavy_SoundScraper::cBinop_TThRoFqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uEfeo8q0, 0, m, &cVar_uEfeo8q0_sendMessage);
}

void Heavy_SoundScraper::cCast_YvwOzUmQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_c2Lajbd2, m);
}

void Heavy_SoundScraper::cCast_1yMcwv8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_ItzH7eUo_sendMessage);
}

void Heavy_SoundScraper::cCast_fcMdkyGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_d3XtGPjs_sendMessage);
}

void Heavy_SoundScraper::cCast_mAQf5Qkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_TThRoFqU_sendMessage);
}

void Heavy_SoundScraper::cTabhead_lip8PHSU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X8KngXpR, HV_BINOP_SUBTRACT, 0, m, &cBinop_X8KngXpR_sendMessage);
}

void Heavy_SoundScraper::cMsg_kB36p1p9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FqUbIQMT_sendMessage);
}

void Heavy_SoundScraper::cSystem_FqUbIQMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_15WBXVQm_sendMessage);
}

void Heavy_SoundScraper::cVar_JC7RDpFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0K5olznQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_oxaYzgbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oxaYzgbx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lS4yK2IC, 0, m, &cDelay_lS4yK2IC_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0KuezqPO, 0, m, &sTabread_0KuezqPO_sendMessage);
}

void Heavy_SoundScraper::cDelay_lS4yK2IC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lS4yK2IC, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0KuezqPO, 0, m, &sTabread_0KuezqPO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lS4yK2IC, 0, m, &cDelay_lS4yK2IC_sendMessage);
}

void Heavy_SoundScraper::sTabread_0KuezqPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xXxuz9dn, HV_BINOP_SUBTRACT, 0, m, &cBinop_xXxuz9dn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_IqYjTyLS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KvWEdvlg, HV_BINOP_MAX, 0, m, &cBinop_KvWEdvlg_sendMessage);
}

void Heavy_SoundScraper::cBinop_15WBXVQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IqYjTyLS, HV_BINOP_MULTIPLY, 0, m, &cBinop_IqYjTyLS_sendMessage);
}

void Heavy_SoundScraper::cBinop_X8KngXpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_luXPWj01_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0KuezqPO, 0, m, &sTabread_0KuezqPO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v8nNQTo9_sendMessage);
}

void Heavy_SoundScraper::cSystem_OQDLDTFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xXxuz9dn, HV_BINOP_SUBTRACT, 1, m, &cBinop_xXxuz9dn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lS4yK2IC, 2, m, &cDelay_lS4yK2IC_sendMessage);
}

void Heavy_SoundScraper::cMsg_0K5olznQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OQDLDTFm_sendMessage);
}

void Heavy_SoundScraper::cMsg_luXPWj01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_oxaYzgbx, 0, m, &cDelay_oxaYzgbx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lS4yK2IC, 0, m, &cDelay_lS4yK2IC_sendMessage);
}

void Heavy_SoundScraper::cMsg_TeeMipVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_KvWEdvlg, HV_BINOP_MAX, 1, m, &cBinop_KvWEdvlg_sendMessage);
}

void Heavy_SoundScraper::cBinop_KvWEdvlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X8KngXpR, HV_BINOP_SUBTRACT, 1, m, &cBinop_X8KngXpR_sendMessage);
}

void Heavy_SoundScraper::cCast_v8nNQTo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oxaYzgbx, 0, m, &cDelay_oxaYzgbx_sendMessage);
}

void Heavy_SoundScraper::cBinop_QAz5OUDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oxaYzgbx, 2, m, &cDelay_oxaYzgbx_sendMessage);
}

void Heavy_SoundScraper::cBinop_xXxuz9dn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QAz5OUDw_sendMessage);
}

void Heavy_SoundScraper::cCast_WutHQmLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JC7RDpFG, 0, m, &cVar_JC7RDpFG_sendMessage);
  cMsg_kB36p1p9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lip8PHSU, 0, m, &cTabhead_lip8PHSU_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Ag3mRohw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XVwqmGPf, HV_BINOP_SUBTRACT, 0, m, &cBinop_XVwqmGPf_sendMessage);
}

void Heavy_SoundScraper::cMsg_pHd8l796_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X2WGNkro_sendMessage);
}

void Heavy_SoundScraper::cSystem_X2WGNkro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mNj5wr8L_sendMessage);
}

void Heavy_SoundScraper::cVar_YbibKPT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aGwLU81f_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_vgaFXhFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vgaFXhFV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6G58XGZz, 0, m, &cDelay_6G58XGZz_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_iO89QDof, 0, m, &sTabread_iO89QDof_sendMessage);
}

void Heavy_SoundScraper::cDelay_6G58XGZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6G58XGZz, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_iO89QDof, 0, m, &sTabread_iO89QDof_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6G58XGZz, 0, m, &cDelay_6G58XGZz_sendMessage);
}

void Heavy_SoundScraper::sTabread_iO89QDof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eiES53H4, HV_BINOP_SUBTRACT, 0, m, &cBinop_eiES53H4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_gBUmXEah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_awNBCJE9, HV_BINOP_MAX, 0, m, &cBinop_awNBCJE9_sendMessage);
}

void Heavy_SoundScraper::cBinop_mNj5wr8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gBUmXEah, HV_BINOP_MULTIPLY, 0, m, &cBinop_gBUmXEah_sendMessage);
}

void Heavy_SoundScraper::cBinop_XVwqmGPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UeVp9YDS_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_iO89QDof, 0, m, &sTabread_iO89QDof_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PeCmlXS9_sendMessage);
}

void Heavy_SoundScraper::cSystem_EMoMgFW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eiES53H4, HV_BINOP_SUBTRACT, 1, m, &cBinop_eiES53H4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6G58XGZz, 2, m, &cDelay_6G58XGZz_sendMessage);
}

void Heavy_SoundScraper::cMsg_aGwLU81f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EMoMgFW5_sendMessage);
}

void Heavy_SoundScraper::cMsg_UeVp9YDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_vgaFXhFV, 0, m, &cDelay_vgaFXhFV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6G58XGZz, 0, m, &cDelay_6G58XGZz_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZMA6rgu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_awNBCJE9, HV_BINOP_MAX, 1, m, &cBinop_awNBCJE9_sendMessage);
}

void Heavy_SoundScraper::cBinop_awNBCJE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XVwqmGPf, HV_BINOP_SUBTRACT, 1, m, &cBinop_XVwqmGPf_sendMessage);
}

void Heavy_SoundScraper::cCast_PeCmlXS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vgaFXhFV, 0, m, &cDelay_vgaFXhFV_sendMessage);
}

void Heavy_SoundScraper::cBinop_8KWwc9gO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vgaFXhFV, 2, m, &cDelay_vgaFXhFV_sendMessage);
}

void Heavy_SoundScraper::cBinop_eiES53H4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8KWwc9gO_sendMessage);
}

void Heavy_SoundScraper::cCast_ciAwOVhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YbibKPT8, 0, m, &cVar_YbibKPT8_sendMessage);
  cMsg_pHd8l796_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ag3mRohw, 0, m, &cTabhead_Ag3mRohw_sendMessage);
}

void Heavy_SoundScraper::cTabhead_IRLU9bKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5NIYjhwx, HV_BINOP_SUBTRACT, 0, m, &cBinop_5NIYjhwx_sendMessage);
}

void Heavy_SoundScraper::cMsg_m6GUWcSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_e84rv3vm_sendMessage);
}

void Heavy_SoundScraper::cSystem_e84rv3vm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5w1A4bFK_sendMessage);
}

void Heavy_SoundScraper::cVar_2NsQs6DS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Xr8jWZoG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_tWwMGfPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tWwMGfPg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6xslk1wm, 0, m, &cDelay_6xslk1wm_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HycPhAxU, 0, m, &sTabread_HycPhAxU_sendMessage);
}

void Heavy_SoundScraper::cDelay_6xslk1wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6xslk1wm, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HycPhAxU, 0, m, &sTabread_HycPhAxU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6xslk1wm, 0, m, &cDelay_6xslk1wm_sendMessage);
}

void Heavy_SoundScraper::sTabread_HycPhAxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vwdn7hXf, HV_BINOP_SUBTRACT, 0, m, &cBinop_vwdn7hXf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_HOz7eEDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PN9oSn9y, HV_BINOP_MAX, 0, m, &cBinop_PN9oSn9y_sendMessage);
}

void Heavy_SoundScraper::cBinop_5w1A4bFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HOz7eEDf, HV_BINOP_MULTIPLY, 0, m, &cBinop_HOz7eEDf_sendMessage);
}

void Heavy_SoundScraper::cBinop_5NIYjhwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I3M4wCyS_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HycPhAxU, 0, m, &sTabread_HycPhAxU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_muEU4LbQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_jr0eG0UT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vwdn7hXf, HV_BINOP_SUBTRACT, 1, m, &cBinop_vwdn7hXf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6xslk1wm, 2, m, &cDelay_6xslk1wm_sendMessage);
}

void Heavy_SoundScraper::cMsg_Xr8jWZoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jr0eG0UT_sendMessage);
}

void Heavy_SoundScraper::cMsg_I3M4wCyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tWwMGfPg, 0, m, &cDelay_tWwMGfPg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6xslk1wm, 0, m, &cDelay_6xslk1wm_sendMessage);
}

void Heavy_SoundScraper::cMsg_yZkwKmlW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_PN9oSn9y, HV_BINOP_MAX, 1, m, &cBinop_PN9oSn9y_sendMessage);
}

void Heavy_SoundScraper::cBinop_PN9oSn9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5NIYjhwx, HV_BINOP_SUBTRACT, 1, m, &cBinop_5NIYjhwx_sendMessage);
}

void Heavy_SoundScraper::cCast_muEU4LbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tWwMGfPg, 0, m, &cDelay_tWwMGfPg_sendMessage);
}

void Heavy_SoundScraper::cBinop_7SFe775K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tWwMGfPg, 2, m, &cDelay_tWwMGfPg_sendMessage);
}

void Heavy_SoundScraper::cBinop_vwdn7hXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7SFe775K_sendMessage);
}

void Heavy_SoundScraper::cCast_hVX8FmHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2NsQs6DS, 0, m, &cVar_2NsQs6DS_sendMessage);
  cMsg_m6GUWcSa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IRLU9bKn, 0, m, &cTabhead_IRLU9bKn_sendMessage);
}

void Heavy_SoundScraper::cTabhead_w3zdsZey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ocJRRYIA, HV_BINOP_SUBTRACT, 0, m, &cBinop_ocJRRYIA_sendMessage);
}

void Heavy_SoundScraper::cMsg_BQS3GUs0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DOZSfWxK_sendMessage);
}

void Heavy_SoundScraper::cSystem_DOZSfWxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WQ4UPuYp_sendMessage);
}

void Heavy_SoundScraper::cVar_AMOcZgQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wT0t23Cy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_ClBfXXqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ClBfXXqh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PZoAQCpd, 0, m, &cDelay_PZoAQCpd_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4OsSDFlz, 0, m, &sTabread_4OsSDFlz_sendMessage);
}

void Heavy_SoundScraper::cDelay_PZoAQCpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PZoAQCpd, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4OsSDFlz, 0, m, &sTabread_4OsSDFlz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PZoAQCpd, 0, m, &cDelay_PZoAQCpd_sendMessage);
}

void Heavy_SoundScraper::sTabread_4OsSDFlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_y7rENONY, HV_BINOP_SUBTRACT, 0, m, &cBinop_y7rENONY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_eAKa7gqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dLa8JeU6, HV_BINOP_MAX, 0, m, &cBinop_dLa8JeU6_sendMessage);
}

void Heavy_SoundScraper::cBinop_WQ4UPuYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eAKa7gqS, HV_BINOP_MULTIPLY, 0, m, &cBinop_eAKa7gqS_sendMessage);
}

void Heavy_SoundScraper::cBinop_ocJRRYIA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9hWkoPTB_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_4OsSDFlz, 0, m, &sTabread_4OsSDFlz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0zKiVO9d_sendMessage);
}

void Heavy_SoundScraper::cSystem_6Afebmgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y7rENONY, HV_BINOP_SUBTRACT, 1, m, &cBinop_y7rENONY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PZoAQCpd, 2, m, &cDelay_PZoAQCpd_sendMessage);
}

void Heavy_SoundScraper::cMsg_wT0t23Cy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6Afebmgy_sendMessage);
}

void Heavy_SoundScraper::cMsg_9hWkoPTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ClBfXXqh, 0, m, &cDelay_ClBfXXqh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PZoAQCpd, 0, m, &cDelay_PZoAQCpd_sendMessage);
}

void Heavy_SoundScraper::cMsg_V2MDCi6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_dLa8JeU6, HV_BINOP_MAX, 1, m, &cBinop_dLa8JeU6_sendMessage);
}

void Heavy_SoundScraper::cBinop_dLa8JeU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ocJRRYIA, HV_BINOP_SUBTRACT, 1, m, &cBinop_ocJRRYIA_sendMessage);
}

void Heavy_SoundScraper::cCast_0zKiVO9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ClBfXXqh, 0, m, &cDelay_ClBfXXqh_sendMessage);
}

void Heavy_SoundScraper::cBinop_VsHzTarL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ClBfXXqh, 2, m, &cDelay_ClBfXXqh_sendMessage);
}

void Heavy_SoundScraper::cBinop_y7rENONY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VsHzTarL_sendMessage);
}

void Heavy_SoundScraper::cCast_BWiCU0mu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AMOcZgQy, 0, m, &cVar_AMOcZgQy_sendMessage);
  cMsg_BQS3GUs0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_w3zdsZey, 0, m, &cTabhead_w3zdsZey_sendMessage);
}

void Heavy_SoundScraper::cMsg_TqdyvEYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IGZTZw45_sendMessage);
}

void Heavy_SoundScraper::cSystem_IGZTZw45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IBlv2jkT_sendMessage);
}

void Heavy_SoundScraper::cDelay_G5KIXWi6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_G5KIXWi6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nqk7LzNm, 0, m, &cDelay_Nqk7LzNm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G5KIXWi6, 0, m, &cDelay_G5KIXWi6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2jjdXLe3, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_Nqk7LzNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Nqk7LzNm, m);
  cMsg_YxhCeepR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_30uBXPBw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_KvRw5ScV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_JeVqRvEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tBnA5O4U_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_EBD5gUKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xL1dPfkg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G5KIXWi6, 2, m, &cDelay_G5KIXWi6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RdYrCqYE_sendMessage);
}

void Heavy_SoundScraper::cMsg_tBnA5O4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EBD5gUKK, 0, m, &hTable_EBD5gUKK_sendMessage);
}

void Heavy_SoundScraper::cBinop_IBlv2jkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_JeVqRvEQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_YxhCeepR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EBD5gUKK, 0, m, &hTable_EBD5gUKK_sendMessage);
}

void Heavy_SoundScraper::cCast_RdYrCqYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_G5KIXWi6, 0, m, &cDelay_G5KIXWi6_sendMessage);
}

void Heavy_SoundScraper::cMsg_xL1dPfkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nqk7LzNm, 2, m, &cDelay_Nqk7LzNm_sendMessage);
}

void Heavy_SoundScraper::cMsg_KvRw5ScV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2jjdXLe3, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Kr7BGMXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ffqvNi5m_sendMessage);
}

void Heavy_SoundScraper::cSystem_ffqvNi5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_b90UxGbT_sendMessage);
}

void Heavy_SoundScraper::cDelay_7RCryH9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7RCryH9t, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z4fhpYVq, 0, m, &cDelay_z4fhpYVq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7RCryH9t, 0, m, &cDelay_7RCryH9t_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xFsOokez, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_z4fhpYVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z4fhpYVq, m);
  cMsg_RTSCWlCa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Gcwd2ffx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_eZLLuNfY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_LVC7SwUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KGklmqNK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_zllsqs6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6vvmeCQA_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7RCryH9t, 2, m, &cDelay_7RCryH9t_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JQtrzZmH_sendMessage);
}

void Heavy_SoundScraper::cMsg_KGklmqNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_zllsqs6M, 0, m, &hTable_zllsqs6M_sendMessage);
}

void Heavy_SoundScraper::cBinop_b90UxGbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_LVC7SwUj_sendMessage);
}

void Heavy_SoundScraper::cMsg_RTSCWlCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_zllsqs6M, 0, m, &hTable_zllsqs6M_sendMessage);
}

void Heavy_SoundScraper::cCast_JQtrzZmH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7RCryH9t, 0, m, &cDelay_7RCryH9t_sendMessage);
}

void Heavy_SoundScraper::cMsg_6vvmeCQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_z4fhpYVq, 2, m, &cDelay_z4fhpYVq_sendMessage);
}

void Heavy_SoundScraper::cMsg_eZLLuNfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xFsOokez, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Itju55S4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lOUpRIcD_sendMessage);
}

void Heavy_SoundScraper::cSystem_lOUpRIcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Yz10lUi9_sendMessage);
}

void Heavy_SoundScraper::cDelay_V78qCKJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V78qCKJf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rFQhn4KZ, 0, m, &cDelay_rFQhn4KZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V78qCKJf, 0, m, &cDelay_V78qCKJf_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZD2F13PD, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_rFQhn4KZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rFQhn4KZ, m);
  cMsg_V4loUY0a_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_rD777lPM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4dHEajYn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_eYBZF9p6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p7Da0X3s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_gGlQYkbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1kULbuu1_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V78qCKJf, 2, m, &cDelay_V78qCKJf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hM52ku2P_sendMessage);
}

void Heavy_SoundScraper::cMsg_p7Da0X3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gGlQYkbV, 0, m, &hTable_gGlQYkbV_sendMessage);
}

void Heavy_SoundScraper::cBinop_Yz10lUi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_eYBZF9p6_sendMessage);
}

void Heavy_SoundScraper::cMsg_V4loUY0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gGlQYkbV, 0, m, &hTable_gGlQYkbV_sendMessage);
}

void Heavy_SoundScraper::cCast_hM52ku2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_V78qCKJf, 0, m, &cDelay_V78qCKJf_sendMessage);
}

void Heavy_SoundScraper::cMsg_1kULbuu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rFQhn4KZ, 2, m, &cDelay_rFQhn4KZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_4dHEajYn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZD2F13PD, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_nds2eIEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_30Ovf6Xl_sendMessage);
}

void Heavy_SoundScraper::cSystem_30Ovf6Xl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wfDyef1z_sendMessage);
}

void Heavy_SoundScraper::cDelay_DpXrO0nD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DpXrO0nD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5A5uIZbN, 0, m, &cDelay_5A5uIZbN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DpXrO0nD, 0, m, &cDelay_DpXrO0nD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Ap00FIMe, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_5A5uIZbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5A5uIZbN, m);
  cMsg_sKreWTvI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_UBFsP2S8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_FMIENS9H_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_x3p7HJvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YrNlc6Ei_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_0njfSoys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EGyhlLJp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DpXrO0nD, 2, m, &cDelay_DpXrO0nD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oN5oOgbp_sendMessage);
}

void Heavy_SoundScraper::cMsg_YrNlc6Ei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_0njfSoys, 0, m, &hTable_0njfSoys_sendMessage);
}

void Heavy_SoundScraper::cBinop_wfDyef1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_x3p7HJvd_sendMessage);
}

void Heavy_SoundScraper::cMsg_sKreWTvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_0njfSoys, 0, m, &hTable_0njfSoys_sendMessage);
}

void Heavy_SoundScraper::cCast_oN5oOgbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DpXrO0nD, 0, m, &cDelay_DpXrO0nD_sendMessage);
}

void Heavy_SoundScraper::cMsg_EGyhlLJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_5A5uIZbN, 2, m, &cDelay_5A5uIZbN_sendMessage);
}

void Heavy_SoundScraper::cMsg_FMIENS9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Ap00FIMe, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_yM4kQslW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_GPON4faV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_p5HZ4k8q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_LPCaupwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UCGIgdXn, HV_BINOP_POW, 0, m, &cBinop_UCGIgdXn_sendMessage);
}

void Heavy_SoundScraper::cBinop_UCGIgdXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_1GG2Z3qI_sendMessage);
}

void Heavy_SoundScraper::cBinop_vMKRZSa8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_edo5sNxg_sendMessage);
}

void Heavy_SoundScraper::cCast_neCeRDfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_GGaU3esj_sendMessage);
}

void Heavy_SoundScraper::cCast_WlkCCoh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yM4kQslW, 0, m, &cIf_yM4kQslW_sendMessage);
}

void Heavy_SoundScraper::cBinop_GGaU3esj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yM4kQslW, 1, m, &cIf_yM4kQslW_sendMessage);
}

void Heavy_SoundScraper::cBinop_p5HZ4k8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_vMKRZSa8_sendMessage);
}

void Heavy_SoundScraper::cMsg_GPON4faV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_1GG2Z3qI_sendMessage);
}

void Heavy_SoundScraper::cBinop_edo5sNxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UCGIgdXn, HV_BINOP_POW, 1, m, &cBinop_UCGIgdXn_sendMessage);
  cMsg_LPCaupwH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_y3lwIlGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QiB1pTIW, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_cJweqtDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_GZaKiYhY, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_oOyylhVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rJ6ZnPG4_sendMessage);
}

void Heavy_SoundScraper::cBinop_rJ6ZnPG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_fMloNi7D_sendMessage);
}

void Heavy_SoundScraper::cVar_suPlYIka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tbc6X95v, HV_BINOP_MULTIPLY, 0, m, &cBinop_Tbc6X95v_sendMessage);
}

void Heavy_SoundScraper::cMsg_n0zhc1Is_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eHXbRBJX_sendMessage);
}

void Heavy_SoundScraper::cSystem_eHXbRBJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aTikMP36_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Tbc6X95v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_X5VZ2ig0_sendMessage);
}

void Heavy_SoundScraper::cBinop_oUtJuHxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tbc6X95v, HV_BINOP_MULTIPLY, 1, m, &cBinop_Tbc6X95v_sendMessage);
}

void Heavy_SoundScraper::cMsg_aTikMP36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_oUtJuHxv_sendMessage);
}

void Heavy_SoundScraper::cBinop_X5VZ2ig0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_m4HpLG3u_sendMessage);
}

void Heavy_SoundScraper::cBinop_m4HpLG3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ql2fUbwN_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Vu0Gbx6C, m);
}

void Heavy_SoundScraper::cBinop_ql2fUbwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BqoFLV6h, m);
}

void Heavy_SoundScraper::cVar_UUjf7avV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_neCeRDfH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WlkCCoh0_sendMessage);
}

void Heavy_SoundScraper::cVar_7xCpfsq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_oOyylhVZ_sendMessage);
}

void Heavy_SoundScraper::cVar_yXRGd0cC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_zVJ2W2at_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_DiGtfXlu, 0, m, &cIf_DiGtfXlu_sendMessage);
}

void Heavy_SoundScraper::cVar_Gx4aU02O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_KuhEt9VN_sendMessage);
}

void Heavy_SoundScraper::cIf_DiGtfXlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_v9NVSQ6o_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_6TVGxqFV, 0, m, &cVar_6TVGxqFV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_zVJ2W2at_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DiGtfXlu, 1, m, &cIf_DiGtfXlu_sendMessage);
}

void Heavy_SoundScraper::cBinop_KuhEt9VN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZIuUopzG_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZIuUopzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nTRjtZkj, 0, m, &cVar_nTRjtZkj_sendMessage);
}

void Heavy_SoundScraper::cTabhead_4ORVYUGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xckj5im7, HV_BINOP_SUBTRACT, 0, m, &cBinop_xckj5im7_sendMessage);
}

void Heavy_SoundScraper::cMsg_U9tHtUSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DSmPFOa1_sendMessage);
}

void Heavy_SoundScraper::cSystem_DSmPFOa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_S9XXQ2Hi_sendMessage);
}

void Heavy_SoundScraper::cVar_82yyJGeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M92ewp8E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_qAeKnSSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qAeKnSSq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1hWTxvrp, 0, m, &cDelay_1hWTxvrp_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Gc0cm6Ig, 0, m, &sTabread_Gc0cm6Ig_sendMessage);
}

void Heavy_SoundScraper::cDelay_1hWTxvrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1hWTxvrp, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Gc0cm6Ig, 0, m, &sTabread_Gc0cm6Ig_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1hWTxvrp, 0, m, &cDelay_1hWTxvrp_sendMessage);
}

void Heavy_SoundScraper::sTabread_Gc0cm6Ig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Xe32SJXE, HV_BINOP_SUBTRACT, 0, m, &cBinop_Xe32SJXE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_gVkSqAtF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Du5ZRFVe, HV_BINOP_MAX, 0, m, &cBinop_Du5ZRFVe_sendMessage);
}

void Heavy_SoundScraper::cBinop_S9XXQ2Hi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gVkSqAtF, HV_BINOP_MULTIPLY, 0, m, &cBinop_gVkSqAtF_sendMessage);
}

void Heavy_SoundScraper::cBinop_xckj5im7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Imr9IHEl_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Gc0cm6Ig, 0, m, &sTabread_Gc0cm6Ig_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4DaYWIse_sendMessage);
}

void Heavy_SoundScraper::cSystem_A3JPW73z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xe32SJXE, HV_BINOP_SUBTRACT, 1, m, &cBinop_Xe32SJXE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1hWTxvrp, 2, m, &cDelay_1hWTxvrp_sendMessage);
}

void Heavy_SoundScraper::cMsg_M92ewp8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A3JPW73z_sendMessage);
}

void Heavy_SoundScraper::cMsg_Imr9IHEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qAeKnSSq, 0, m, &cDelay_qAeKnSSq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1hWTxvrp, 0, m, &cDelay_1hWTxvrp_sendMessage);
}

void Heavy_SoundScraper::cMsg_JEirfwee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Du5ZRFVe, HV_BINOP_MAX, 1, m, &cBinop_Du5ZRFVe_sendMessage);
}

void Heavy_SoundScraper::cBinop_Du5ZRFVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xckj5im7, HV_BINOP_SUBTRACT, 1, m, &cBinop_xckj5im7_sendMessage);
}

void Heavy_SoundScraper::cCast_4DaYWIse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qAeKnSSq, 0, m, &cDelay_qAeKnSSq_sendMessage);
}

void Heavy_SoundScraper::cBinop_kxV4MDls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qAeKnSSq, 2, m, &cDelay_qAeKnSSq_sendMessage);
}

void Heavy_SoundScraper::cBinop_Xe32SJXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kxV4MDls_sendMessage);
}

void Heavy_SoundScraper::cCast_jEhqoHyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_82yyJGeu, 0, m, &cVar_82yyJGeu_sendMessage);
  cMsg_U9tHtUSH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4ORVYUGP, 0, m, &cTabhead_4ORVYUGP_sendMessage);
}

void Heavy_SoundScraper::cMsg_vFBT7bJR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xCMEtemB_sendMessage);
}

void Heavy_SoundScraper::cSystem_xCMEtemB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_a3LjbT1B_sendMessage);
}

void Heavy_SoundScraper::cDelay_cp2YPzZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cp2YPzZ1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_F7eW95iB, 0, m, &cDelay_F7eW95iB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cp2YPzZ1, 0, m, &cDelay_cp2YPzZ1_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cXP0kBkY, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_F7eW95iB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_F7eW95iB, m);
  cMsg_hBvuhsgM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_i6x6h7j7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_GNnNCnir_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_IAdFSsBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l7loGgVC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_TSvwyWQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vgpk4lUz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cp2YPzZ1, 2, m, &cDelay_cp2YPzZ1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Yc05tM4b_sendMessage);
}

void Heavy_SoundScraper::cMsg_l7loGgVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TSvwyWQf, 0, m, &hTable_TSvwyWQf_sendMessage);
}

void Heavy_SoundScraper::cBinop_a3LjbT1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_IAdFSsBf_sendMessage);
}

void Heavy_SoundScraper::cMsg_hBvuhsgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TSvwyWQf, 0, m, &hTable_TSvwyWQf_sendMessage);
}

void Heavy_SoundScraper::cCast_Yc05tM4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cp2YPzZ1, 0, m, &cDelay_cp2YPzZ1_sendMessage);
}

void Heavy_SoundScraper::cMsg_Vgpk4lUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_F7eW95iB, 2, m, &cDelay_F7eW95iB_sendMessage);
}

void Heavy_SoundScraper::cMsg_GNnNCnir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cXP0kBkY, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_6RNCBRML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YDtqRLyU, HV_BINOP_SUBTRACT, 0, m, &cBinop_YDtqRLyU_sendMessage);
}

void Heavy_SoundScraper::cMsg_F027C2WA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DsMYyOrq_sendMessage);
}

void Heavy_SoundScraper::cSystem_DsMYyOrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hei6upmO_sendMessage);
}

void Heavy_SoundScraper::cVar_feP8qnCF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HenCwI6z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_zVMUbcoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zVMUbcoj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JosAUkZp, 0, m, &cDelay_JosAUkZp_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SEzZpQLS, 0, m, &sTabread_SEzZpQLS_sendMessage);
}

void Heavy_SoundScraper::cDelay_JosAUkZp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JosAUkZp, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SEzZpQLS, 0, m, &sTabread_SEzZpQLS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JosAUkZp, 0, m, &cDelay_JosAUkZp_sendMessage);
}

void Heavy_SoundScraper::sTabread_SEzZpQLS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XP3TJH8U, HV_BINOP_SUBTRACT, 0, m, &cBinop_XP3TJH8U_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_OIDUEHR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gxz0RHrZ, HV_BINOP_MAX, 0, m, &cBinop_gxz0RHrZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_hei6upmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OIDUEHR3, HV_BINOP_MULTIPLY, 0, m, &cBinop_OIDUEHR3_sendMessage);
}

void Heavy_SoundScraper::cBinop_YDtqRLyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YOSKuR6l_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SEzZpQLS, 0, m, &sTabread_SEzZpQLS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mnNkughP_sendMessage);
}

void Heavy_SoundScraper::cSystem_Boq0S8cO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XP3TJH8U, HV_BINOP_SUBTRACT, 1, m, &cBinop_XP3TJH8U_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JosAUkZp, 2, m, &cDelay_JosAUkZp_sendMessage);
}

void Heavy_SoundScraper::cMsg_HenCwI6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Boq0S8cO_sendMessage);
}

void Heavy_SoundScraper::cMsg_YOSKuR6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zVMUbcoj, 0, m, &cDelay_zVMUbcoj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JosAUkZp, 0, m, &cDelay_JosAUkZp_sendMessage);
}

void Heavy_SoundScraper::cMsg_CROnPuWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_gxz0RHrZ, HV_BINOP_MAX, 1, m, &cBinop_gxz0RHrZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_gxz0RHrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YDtqRLyU, HV_BINOP_SUBTRACT, 1, m, &cBinop_YDtqRLyU_sendMessage);
}

void Heavy_SoundScraper::cCast_mnNkughP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zVMUbcoj, 0, m, &cDelay_zVMUbcoj_sendMessage);
}

void Heavy_SoundScraper::cBinop_TEgQn1rH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zVMUbcoj, 2, m, &cDelay_zVMUbcoj_sendMessage);
}

void Heavy_SoundScraper::cBinop_XP3TJH8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TEgQn1rH_sendMessage);
}

void Heavy_SoundScraper::cCast_40kC6owF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_feP8qnCF, 0, m, &cVar_feP8qnCF_sendMessage);
  cMsg_F027C2WA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6RNCBRML, 0, m, &cTabhead_6RNCBRML_sendMessage);
}

void Heavy_SoundScraper::cMsg_K2zeRRxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6SbteOdV_sendMessage);
}

void Heavy_SoundScraper::cSystem_6SbteOdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PRYMHN2T_sendMessage);
}

void Heavy_SoundScraper::cDelay_HPrFNYOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HPrFNYOX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5j322E8l, 0, m, &cDelay_5j322E8l_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HPrFNYOX, 0, m, &cDelay_HPrFNYOX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_J5tLNS4a, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_5j322E8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5j322E8l, m);
  cMsg_jrvijRCZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Sm3uDmm2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ovvxJ8eI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_1vebkVzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2e5kRktQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_EFJH7DGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9Qq7xueQ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HPrFNYOX, 2, m, &cDelay_HPrFNYOX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TGMEvKwW_sendMessage);
}

void Heavy_SoundScraper::cMsg_2e5kRktQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EFJH7DGe, 0, m, &hTable_EFJH7DGe_sendMessage);
}

void Heavy_SoundScraper::cBinop_PRYMHN2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_1vebkVzm_sendMessage);
}

void Heavy_SoundScraper::cMsg_jrvijRCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EFJH7DGe, 0, m, &hTable_EFJH7DGe_sendMessage);
}

void Heavy_SoundScraper::cCast_TGMEvKwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HPrFNYOX, 0, m, &cDelay_HPrFNYOX_sendMessage);
}

void Heavy_SoundScraper::cMsg_9Qq7xueQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_5j322E8l, 2, m, &cDelay_5j322E8l_sendMessage);
}

void Heavy_SoundScraper::cMsg_ovvxJ8eI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_J5tLNS4a, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_KaWi584T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4LnHAoDe, HV_BINOP_SUBTRACT, 0, m, &cBinop_4LnHAoDe_sendMessage);
}

void Heavy_SoundScraper::cMsg_r4EqlreD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hNBz67yz_sendMessage);
}

void Heavy_SoundScraper::cSystem_hNBz67yz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HV5MFUGU_sendMessage);
}

void Heavy_SoundScraper::cVar_sFUc7NUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_flR2v5Hr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_e3A24Ki6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_e3A24Ki6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u1HsFttz, 0, m, &cDelay_u1HsFttz_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mlFLAfJ2, 0, m, &sTabread_mlFLAfJ2_sendMessage);
}

void Heavy_SoundScraper::cDelay_u1HsFttz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_u1HsFttz, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mlFLAfJ2, 0, m, &sTabread_mlFLAfJ2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u1HsFttz, 0, m, &cDelay_u1HsFttz_sendMessage);
}

void Heavy_SoundScraper::sTabread_mlFLAfJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9STPkYSh, HV_BINOP_SUBTRACT, 0, m, &cBinop_9STPkYSh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_9kjgZxiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nmouTQ1P, HV_BINOP_MAX, 0, m, &cBinop_nmouTQ1P_sendMessage);
}

void Heavy_SoundScraper::cBinop_HV5MFUGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9kjgZxiP, HV_BINOP_MULTIPLY, 0, m, &cBinop_9kjgZxiP_sendMessage);
}

void Heavy_SoundScraper::cBinop_4LnHAoDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UNhi7NBb_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mlFLAfJ2, 0, m, &sTabread_mlFLAfJ2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RZF7lHfU_sendMessage);
}

void Heavy_SoundScraper::cSystem_HfnmSCor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9STPkYSh, HV_BINOP_SUBTRACT, 1, m, &cBinop_9STPkYSh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u1HsFttz, 2, m, &cDelay_u1HsFttz_sendMessage);
}

void Heavy_SoundScraper::cMsg_flR2v5Hr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HfnmSCor_sendMessage);
}

void Heavy_SoundScraper::cMsg_UNhi7NBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_e3A24Ki6, 0, m, &cDelay_e3A24Ki6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u1HsFttz, 0, m, &cDelay_u1HsFttz_sendMessage);
}

void Heavy_SoundScraper::cMsg_pVzGQa3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_nmouTQ1P, HV_BINOP_MAX, 1, m, &cBinop_nmouTQ1P_sendMessage);
}

void Heavy_SoundScraper::cBinop_nmouTQ1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4LnHAoDe, HV_BINOP_SUBTRACT, 1, m, &cBinop_4LnHAoDe_sendMessage);
}

void Heavy_SoundScraper::cCast_RZF7lHfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_e3A24Ki6, 0, m, &cDelay_e3A24Ki6_sendMessage);
}

void Heavy_SoundScraper::cBinop_rExP2QdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_e3A24Ki6, 2, m, &cDelay_e3A24Ki6_sendMessage);
}

void Heavy_SoundScraper::cBinop_9STPkYSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rExP2QdA_sendMessage);
}

void Heavy_SoundScraper::cCast_dGC8iKKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sFUc7NUz, 0, m, &cVar_sFUc7NUz_sendMessage);
  cMsg_r4EqlreD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_KaWi584T, 0, m, &cTabhead_KaWi584T_sendMessage);
}

void Heavy_SoundScraper::cMsg_w8alRW5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_f96OD9es_sendMessage);
}

void Heavy_SoundScraper::cSystem_f96OD9es_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_87tyowqm_sendMessage);
}

void Heavy_SoundScraper::cDelay_zaEzkwCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zaEzkwCB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hqVRWPjB, 0, m, &cDelay_hqVRWPjB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zaEzkwCB, 0, m, &cDelay_zaEzkwCB_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8MKKfEgy, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_hqVRWPjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hqVRWPjB, m);
  cMsg_oMNG5SUJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_AXLtIhSI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Lm565F0i_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Ly2zRVJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LgODFXpN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_k6Ho7LFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x1WC2Etu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zaEzkwCB, 2, m, &cDelay_zaEzkwCB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aUXYEkX0_sendMessage);
}

void Heavy_SoundScraper::cMsg_LgODFXpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_k6Ho7LFE, 0, m, &hTable_k6Ho7LFE_sendMessage);
}

void Heavy_SoundScraper::cBinop_87tyowqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_Ly2zRVJX_sendMessage);
}

void Heavy_SoundScraper::cMsg_oMNG5SUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_k6Ho7LFE, 0, m, &hTable_k6Ho7LFE_sendMessage);
}

void Heavy_SoundScraper::cCast_aUXYEkX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zaEzkwCB, 0, m, &cDelay_zaEzkwCB_sendMessage);
}

void Heavy_SoundScraper::cMsg_x1WC2Etu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_hqVRWPjB, 2, m, &cDelay_hqVRWPjB_sendMessage);
}

void Heavy_SoundScraper::cMsg_Lm565F0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8MKKfEgy, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_C0bpdWpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q6HHHvu4, HV_BINOP_SUBTRACT, 0, m, &cBinop_Q6HHHvu4_sendMessage);
}

void Heavy_SoundScraper::cMsg_YTkIVEjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ITk8gYzc_sendMessage);
}

void Heavy_SoundScraper::cSystem_ITk8gYzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lJzrxwwT_sendMessage);
}

void Heavy_SoundScraper::cVar_GLAH01co_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dDBuFrcA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_nbPF9k7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nbPF9k7B, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CvcSI8EG, 0, m, &cDelay_CvcSI8EG_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OFqKjXTX, 0, m, &sTabread_OFqKjXTX_sendMessage);
}

void Heavy_SoundScraper::cDelay_CvcSI8EG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CvcSI8EG, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OFqKjXTX, 0, m, &sTabread_OFqKjXTX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CvcSI8EG, 0, m, &cDelay_CvcSI8EG_sendMessage);
}

void Heavy_SoundScraper::sTabread_OFqKjXTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_FwvGBn4S, HV_BINOP_SUBTRACT, 0, m, &cBinop_FwvGBn4S_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_UdNBdH4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O44IK0SM, HV_BINOP_MAX, 0, m, &cBinop_O44IK0SM_sendMessage);
}

void Heavy_SoundScraper::cBinop_lJzrxwwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UdNBdH4k, HV_BINOP_MULTIPLY, 0, m, &cBinop_UdNBdH4k_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q6HHHvu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JxibKXYK_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OFqKjXTX, 0, m, &sTabread_OFqKjXTX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OY5LJ7vt_sendMessage);
}

void Heavy_SoundScraper::cSystem_PlPuPSad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FwvGBn4S, HV_BINOP_SUBTRACT, 1, m, &cBinop_FwvGBn4S_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CvcSI8EG, 2, m, &cDelay_CvcSI8EG_sendMessage);
}

void Heavy_SoundScraper::cMsg_dDBuFrcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PlPuPSad_sendMessage);
}

void Heavy_SoundScraper::cMsg_JxibKXYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nbPF9k7B, 0, m, &cDelay_nbPF9k7B_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CvcSI8EG, 0, m, &cDelay_CvcSI8EG_sendMessage);
}

void Heavy_SoundScraper::cMsg_QCX2QHiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_O44IK0SM, HV_BINOP_MAX, 1, m, &cBinop_O44IK0SM_sendMessage);
}

void Heavy_SoundScraper::cBinop_O44IK0SM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q6HHHvu4, HV_BINOP_SUBTRACT, 1, m, &cBinop_Q6HHHvu4_sendMessage);
}

void Heavy_SoundScraper::cCast_OY5LJ7vt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nbPF9k7B, 0, m, &cDelay_nbPF9k7B_sendMessage);
}

void Heavy_SoundScraper::cBinop_uTZOShhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nbPF9k7B, 2, m, &cDelay_nbPF9k7B_sendMessage);
}

void Heavy_SoundScraper::cBinop_FwvGBn4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uTZOShhs_sendMessage);
}

void Heavy_SoundScraper::cCast_s9rPggU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GLAH01co, 0, m, &cVar_GLAH01co_sendMessage);
  cMsg_YTkIVEjl_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_C0bpdWpL, 0, m, &cTabhead_C0bpdWpL_sendMessage);
}

void Heavy_SoundScraper::cMsg_5wYZtQS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DbazxfVM_sendMessage);
}

void Heavy_SoundScraper::cSystem_DbazxfVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2OrlCoju_sendMessage);
}

void Heavy_SoundScraper::cDelay_ehdxNZWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ehdxNZWr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNn55yTn, 0, m, &cDelay_VNn55yTn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ehdxNZWr, 0, m, &cDelay_ehdxNZWr_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_n1McHLWQ, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_VNn55yTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VNn55yTn, m);
  cMsg_lrPi5VY9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_yLDzJets_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_7vx2P73b_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_ez12qhDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y0C8QEDa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_1m8RHnde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JbH7ooTT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ehdxNZWr, 2, m, &cDelay_ehdxNZWr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aooOGN6f_sendMessage);
}

void Heavy_SoundScraper::cMsg_Y0C8QEDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_1m8RHnde, 0, m, &hTable_1m8RHnde_sendMessage);
}

void Heavy_SoundScraper::cBinop_2OrlCoju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_ez12qhDk_sendMessage);
}

void Heavy_SoundScraper::cMsg_lrPi5VY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_1m8RHnde, 0, m, &hTable_1m8RHnde_sendMessage);
}

void Heavy_SoundScraper::cCast_aooOGN6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ehdxNZWr, 0, m, &cDelay_ehdxNZWr_sendMessage);
}

void Heavy_SoundScraper::cMsg_JbH7ooTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNn55yTn, 2, m, &cDelay_VNn55yTn_sendMessage);
}

void Heavy_SoundScraper::cMsg_7vx2P73b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_n1McHLWQ, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_sk1YC4aq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8B7E31oH, HV_BINOP_SUBTRACT, 0, m, &cBinop_8B7E31oH_sendMessage);
}

void Heavy_SoundScraper::cMsg_aT7xszWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lBQYnqMo_sendMessage);
}

void Heavy_SoundScraper::cSystem_lBQYnqMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_w9j3ltJe_sendMessage);
}

void Heavy_SoundScraper::cVar_dv4BAS48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CYW4zoAQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_a6dgcpqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_a6dgcpqc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uWY5i1Xh, 0, m, &cDelay_uWY5i1Xh_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FVhGrixi, 0, m, &sTabread_FVhGrixi_sendMessage);
}

void Heavy_SoundScraper::cDelay_uWY5i1Xh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uWY5i1Xh, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FVhGrixi, 0, m, &sTabread_FVhGrixi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uWY5i1Xh, 0, m, &cDelay_uWY5i1Xh_sendMessage);
}

void Heavy_SoundScraper::sTabread_FVhGrixi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qmZFtlFk, HV_BINOP_SUBTRACT, 0, m, &cBinop_qmZFtlFk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_1iLWgDSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AXFPdx8r, HV_BINOP_MAX, 0, m, &cBinop_AXFPdx8r_sendMessage);
}

void Heavy_SoundScraper::cBinop_w9j3ltJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1iLWgDSX, HV_BINOP_MULTIPLY, 0, m, &cBinop_1iLWgDSX_sendMessage);
}

void Heavy_SoundScraper::cBinop_8B7E31oH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hJfQNJrT_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FVhGrixi, 0, m, &sTabread_FVhGrixi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Iobb7CP5_sendMessage);
}

void Heavy_SoundScraper::cSystem_5Y9VKgO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qmZFtlFk, HV_BINOP_SUBTRACT, 1, m, &cBinop_qmZFtlFk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uWY5i1Xh, 2, m, &cDelay_uWY5i1Xh_sendMessage);
}

void Heavy_SoundScraper::cMsg_CYW4zoAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5Y9VKgO8_sendMessage);
}

void Heavy_SoundScraper::cMsg_hJfQNJrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_a6dgcpqc, 0, m, &cDelay_a6dgcpqc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uWY5i1Xh, 0, m, &cDelay_uWY5i1Xh_sendMessage);
}

void Heavy_SoundScraper::cMsg_if7m9U6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_AXFPdx8r, HV_BINOP_MAX, 1, m, &cBinop_AXFPdx8r_sendMessage);
}

void Heavy_SoundScraper::cBinop_AXFPdx8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8B7E31oH, HV_BINOP_SUBTRACT, 1, m, &cBinop_8B7E31oH_sendMessage);
}

void Heavy_SoundScraper::cCast_Iobb7CP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_a6dgcpqc, 0, m, &cDelay_a6dgcpqc_sendMessage);
}

void Heavy_SoundScraper::cBinop_K1cfVBJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_a6dgcpqc, 2, m, &cDelay_a6dgcpqc_sendMessage);
}

void Heavy_SoundScraper::cBinop_qmZFtlFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_K1cfVBJo_sendMessage);
}

void Heavy_SoundScraper::cCast_cqvLINgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dv4BAS48, 0, m, &cVar_dv4BAS48_sendMessage);
  cMsg_aT7xszWC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sk1YC4aq, 0, m, &cTabhead_sk1YC4aq_sendMessage);
}

void Heavy_SoundScraper::cMsg_mrXWW6Oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SRMruPf0_sendMessage);
}

void Heavy_SoundScraper::cSystem_SRMruPf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iokmg0Ck_sendMessage);
}

void Heavy_SoundScraper::cDelay_kqs6Eikw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kqs6Eikw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bNKAnsT2, 0, m, &cDelay_bNKAnsT2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kqs6Eikw, 0, m, &cDelay_kqs6Eikw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZJbanhll, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_bNKAnsT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bNKAnsT2, m);
  cMsg_5ZzvGtSJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_buv0BBIZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_lo2xMvO4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_slCqtvbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VtkxMWvY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_BNW0HdKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tXzD6PCo_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kqs6Eikw, 2, m, &cDelay_kqs6Eikw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DJqZM8f1_sendMessage);
}

void Heavy_SoundScraper::cMsg_VtkxMWvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_BNW0HdKo, 0, m, &hTable_BNW0HdKo_sendMessage);
}

void Heavy_SoundScraper::cBinop_iokmg0Ck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_slCqtvbo_sendMessage);
}

void Heavy_SoundScraper::cMsg_5ZzvGtSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_BNW0HdKo, 0, m, &hTable_BNW0HdKo_sendMessage);
}

void Heavy_SoundScraper::cCast_DJqZM8f1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kqs6Eikw, 0, m, &cDelay_kqs6Eikw_sendMessage);
}

void Heavy_SoundScraper::cMsg_tXzD6PCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_bNKAnsT2, 2, m, &cDelay_bNKAnsT2_sendMessage);
}

void Heavy_SoundScraper::cMsg_lo2xMvO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZJbanhll, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_XVbQNLss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1kdhuNK0, HV_BINOP_SUBTRACT, 0, m, &cBinop_1kdhuNK0_sendMessage);
}

void Heavy_SoundScraper::cMsg_IbvCsCFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_52pbv8lH_sendMessage);
}

void Heavy_SoundScraper::cSystem_52pbv8lH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_op8bXWOy_sendMessage);
}

void Heavy_SoundScraper::cVar_UWNsV8I9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WHXx6bQp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_zfpBzzwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zfpBzzwV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ob1Knuth, 0, m, &cDelay_Ob1Knuth_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_sjeac2xu, 0, m, &sTabread_sjeac2xu_sendMessage);
}

void Heavy_SoundScraper::cDelay_Ob1Knuth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ob1Knuth, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_sjeac2xu, 0, m, &sTabread_sjeac2xu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ob1Knuth, 0, m, &cDelay_Ob1Knuth_sendMessage);
}

void Heavy_SoundScraper::sTabread_sjeac2xu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ex8u3LOs, HV_BINOP_SUBTRACT, 0, m, &cBinop_ex8u3LOs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_OePAB3OE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nrvZF5ud, HV_BINOP_MAX, 0, m, &cBinop_nrvZF5ud_sendMessage);
}

void Heavy_SoundScraper::cBinop_op8bXWOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OePAB3OE, HV_BINOP_MULTIPLY, 0, m, &cBinop_OePAB3OE_sendMessage);
}

void Heavy_SoundScraper::cBinop_1kdhuNK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M3MJ3u14_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_sjeac2xu, 0, m, &sTabread_sjeac2xu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2rT2viSB_sendMessage);
}

void Heavy_SoundScraper::cSystem_ZQcLnsQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ex8u3LOs, HV_BINOP_SUBTRACT, 1, m, &cBinop_ex8u3LOs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ob1Knuth, 2, m, &cDelay_Ob1Knuth_sendMessage);
}

void Heavy_SoundScraper::cMsg_WHXx6bQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZQcLnsQ3_sendMessage);
}

void Heavy_SoundScraper::cMsg_M3MJ3u14_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zfpBzzwV, 0, m, &cDelay_zfpBzzwV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ob1Knuth, 0, m, &cDelay_Ob1Knuth_sendMessage);
}

void Heavy_SoundScraper::cMsg_Sa3XAs8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_nrvZF5ud, HV_BINOP_MAX, 1, m, &cBinop_nrvZF5ud_sendMessage);
}

void Heavy_SoundScraper::cBinop_nrvZF5ud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1kdhuNK0, HV_BINOP_SUBTRACT, 1, m, &cBinop_1kdhuNK0_sendMessage);
}

void Heavy_SoundScraper::cCast_2rT2viSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zfpBzzwV, 0, m, &cDelay_zfpBzzwV_sendMessage);
}

void Heavy_SoundScraper::cBinop_Nao281ts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zfpBzzwV, 2, m, &cDelay_zfpBzzwV_sendMessage);
}

void Heavy_SoundScraper::cBinop_ex8u3LOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Nao281ts_sendMessage);
}

void Heavy_SoundScraper::cCast_kvBQjCVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UWNsV8I9, 0, m, &cVar_UWNsV8I9_sendMessage);
  cMsg_IbvCsCFp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_XVbQNLss, 0, m, &cTabhead_XVbQNLss_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZmwbGB1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0KX2F8nM_sendMessage);
}

void Heavy_SoundScraper::cSystem_0KX2F8nM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_g1EKGXHy_sendMessage);
}

void Heavy_SoundScraper::cDelay_hK8VZx75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hK8VZx75, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uGVdQsNb, 0, m, &cDelay_uGVdQsNb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hK8VZx75, 0, m, &cDelay_hK8VZx75_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZvnOmipx, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_uGVdQsNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uGVdQsNb, m);
  cMsg_jq243l1d_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_lljN4JHP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_JtwxVBCY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_9NrXHST7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ELVKdAMk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_UPXYUY4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5sAu9CKH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hK8VZx75, 2, m, &cDelay_hK8VZx75_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EsaJXSRA_sendMessage);
}

void Heavy_SoundScraper::cMsg_ELVKdAMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_UPXYUY4s, 0, m, &hTable_UPXYUY4s_sendMessage);
}

void Heavy_SoundScraper::cBinop_g1EKGXHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_9NrXHST7_sendMessage);
}

void Heavy_SoundScraper::cMsg_jq243l1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_UPXYUY4s, 0, m, &hTable_UPXYUY4s_sendMessage);
}

void Heavy_SoundScraper::cCast_EsaJXSRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hK8VZx75, 0, m, &cDelay_hK8VZx75_sendMessage);
}

void Heavy_SoundScraper::cMsg_5sAu9CKH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_uGVdQsNb, 2, m, &cDelay_uGVdQsNb_sendMessage);
}

void Heavy_SoundScraper::cMsg_JtwxVBCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZvnOmipx, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_6TVGxqFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_suPlYIka, 0, m, &cVar_suPlYIka_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3gNWLpcd, 0, m, &cVar_3gNWLpcd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8hSZ5atB, 0, m, &cVar_8hSZ5atB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UZvGkNFA, 0, m, &cVar_UZvGkNFA_sendMessage);
}

void Heavy_SoundScraper::cVar_nTRjtZkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_3Zpu9jLY_sendMessage);
}

void Heavy_SoundScraper::cPack_yNXZskit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HLlHtEJM, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_3gNWLpcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LTq0SHfI, HV_BINOP_MULTIPLY, 0, m, &cBinop_LTq0SHfI_sendMessage);
}

void Heavy_SoundScraper::cMsg_VQO1FR5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qeEsybKc_sendMessage);
}

void Heavy_SoundScraper::cSystem_qeEsybKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_doeOhqs7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_LTq0SHfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NXfQ0KYZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_UwA58t6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LTq0SHfI, HV_BINOP_MULTIPLY, 1, m, &cBinop_LTq0SHfI_sendMessage);
}

void Heavy_SoundScraper::cMsg_doeOhqs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_UwA58t6d_sendMessage);
}

void Heavy_SoundScraper::cBinop_NXfQ0KYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZTUIGpYA_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZTUIGpYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_uFgVmZ9l_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FgHRs1Po, m);
}

void Heavy_SoundScraper::cBinop_uFgVmZ9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8GxEbFmH, m);
}

void Heavy_SoundScraper::cVar_8hSZ5atB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xRXrfe93, HV_BINOP_MULTIPLY, 0, m, &cBinop_xRXrfe93_sendMessage);
}

void Heavy_SoundScraper::cMsg_ql5hdw6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OBiU5QHQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_OBiU5QHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HcTLaXfe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_xRXrfe93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2ikVpdFi_sendMessage);
}

void Heavy_SoundScraper::cBinop_MvyXeFE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xRXrfe93, HV_BINOP_MULTIPLY, 1, m, &cBinop_xRXrfe93_sendMessage);
}

void Heavy_SoundScraper::cMsg_HcTLaXfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MvyXeFE9_sendMessage);
}

void Heavy_SoundScraper::cBinop_2ikVpdFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Q9jgMMhs_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q9jgMMhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mtkVr6Ji_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9X9WfMo8, m);
}

void Heavy_SoundScraper::cBinop_mtkVr6Ji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nwuLrGpd, m);
}

void Heavy_SoundScraper::cVar_UZvGkNFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8csdvVP, HV_BINOP_MULTIPLY, 0, m, &cBinop_U8csdvVP_sendMessage);
}

void Heavy_SoundScraper::cMsg_qBU4bkwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jqfexB1s_sendMessage);
}

void Heavy_SoundScraper::cSystem_jqfexB1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QbkNjjzz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_U8csdvVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_FRmCqiJG_sendMessage);
}

void Heavy_SoundScraper::cBinop_inDZTLbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8csdvVP, HV_BINOP_MULTIPLY, 1, m, &cBinop_U8csdvVP_sendMessage);
}

void Heavy_SoundScraper::cMsg_QbkNjjzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_inDZTLbG_sendMessage);
}

void Heavy_SoundScraper::cBinop_FRmCqiJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LvZNWnUr_sendMessage);
}

void Heavy_SoundScraper::cBinop_LvZNWnUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_7ERe2c0d_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bcbXDy3L, m);
}

void Heavy_SoundScraper::cBinop_7ERe2c0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Inz1DJ92, m);
}

void Heavy_SoundScraper::cBinop_fMloNi7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cJweqtDh, 0, m, &cPack_cJweqtDh_sendMessage);
}

void Heavy_SoundScraper::cMsg_v9NVSQ6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_6TVGxqFV, 0, m, &cVar_6TVGxqFV_sendMessage);
}

void Heavy_SoundScraper::cBinop_3Zpu9jLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_yNXZskit, 0, m, &cPack_yNXZskit_sendMessage);
}

void Heavy_SoundScraper::cBinop_1GG2Z3qI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_y3lwIlGP, 0, m, &cPack_y3lwIlGP_sendMessage);
}

void Heavy_SoundScraper::cMsg_BqQhlelZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HBy3ach3_sendMessage);
}

void Heavy_SoundScraper::cSystem_HBy3ach3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Vi6Z7amY_sendMessage);
}

void Heavy_SoundScraper::cVar_sDIrlZy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7rxPw4Y3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Hdtz07Sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mrExntyr_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_yx9aoQhm, m);
}

void Heavy_SoundScraper::cBinop_Vi6Z7amY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TCYUEP7x, m);
}

void Heavy_SoundScraper::cMsg_7rxPw4Y3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Hdtz07Sg_sendMessage);
}

void Heavy_SoundScraper::cBinop_mrExntyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_04t1k3yf, m);
}

void Heavy_SoundScraper::cVar_MrzvP1fe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yvSQqpqN, HV_BINOP_MULTIPLY, 0, m, &cBinop_yvSQqpqN_sendMessage);
}

void Heavy_SoundScraper::cMsg_4WZ2XsQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ui7regKb_sendMessage);
}

void Heavy_SoundScraper::cSystem_Ui7regKb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6bjyiCS6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_yvSQqpqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1OfILrK7_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZiKy3TUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yvSQqpqN, HV_BINOP_MULTIPLY, 1, m, &cBinop_yvSQqpqN_sendMessage);
}

void Heavy_SoundScraper::cMsg_6bjyiCS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ZiKy3TUd_sendMessage);
}

void Heavy_SoundScraper::cBinop_1OfILrK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AjxYYmko_sendMessage);
}

void Heavy_SoundScraper::cBinop_AjxYYmko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_W4qyK2Om_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WnpXrliR, m);
}

void Heavy_SoundScraper::cBinop_W4qyK2Om_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mXs1tjpP, m);
}

void Heavy_SoundScraper::cBinop_DjzEPJit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_SLs1hcet_sendMessage);
}

void Heavy_SoundScraper::cBinop_SLs1hcet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0YNilGdW, m);
}

void Heavy_SoundScraper::cBinop_0yv4zwbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_y5rDJenn_sendMessage);
}

void Heavy_SoundScraper::cBinop_y5rDJenn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qssA85h0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FUTgyHll_sendMessage);
}

void Heavy_SoundScraper::cVar_Yt4I3DAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XzkSNDcw_sendMessage);
}

void Heavy_SoundScraper::cMsg_wohpdIfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_atf679n8_sendMessage);
}

void Heavy_SoundScraper::cSystem_atf679n8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ABedMioP, HV_BINOP_DIVIDE, 1, m, &cBinop_ABedMioP_sendMessage);
}

void Heavy_SoundScraper::cBinop_qssA85h0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_CMUIva5t_sendMessage);
}

void Heavy_SoundScraper::cBinop_CMUIva5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AQQlL3Kp, m);
}

void Heavy_SoundScraper::cMsg_Vxzxi3Ew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_jIslV0Sl_sendMessage);
}

void Heavy_SoundScraper::cBinop_jIslV0Sl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0yv4zwbG_sendMessage);
}

void Heavy_SoundScraper::cBinop_FUTgyHll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CIfAqho5, m);
}

void Heavy_SoundScraper::cBinop_XzkSNDcw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_lPebDTc4_sendMessage);
}

void Heavy_SoundScraper::cBinop_lPebDTc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ABedMioP, HV_BINOP_DIVIDE, 0, m, &cBinop_ABedMioP_sendMessage);
}

void Heavy_SoundScraper::cBinop_ABedMioP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vxzxi3Ew_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Zmh9Ky8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FfK6nAzH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_WRd326pC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nK6pj6dG_sendMessage);
}

void Heavy_SoundScraper::cSystem_nK6pj6dG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HKbhTX2j_sendMessage);
}

void Heavy_SoundScraper::cDelay_BtZgduHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BtZgduHT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uq7D9EVB, 0, m, &cDelay_Uq7D9EVB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BtZgduHT, 0, m, &cDelay_BtZgduHT_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4RQPOxik, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_Uq7D9EVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Uq7D9EVB, m);
  cMsg_BaZ5jyx2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_P8Jpot3i_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_nIiYegY2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_wiKmV4x4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_APpImcju_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_hHg41gz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OFIuOikR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BtZgduHT, 2, m, &cDelay_BtZgduHT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zjsNe9cG_sendMessage);
}

void Heavy_SoundScraper::cMsg_APpImcju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_hHg41gz0, 0, m, &hTable_hHg41gz0_sendMessage);
}

void Heavy_SoundScraper::cBinop_HKbhTX2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_wiKmV4x4_sendMessage);
}

void Heavy_SoundScraper::cMsg_BaZ5jyx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_hHg41gz0, 0, m, &hTable_hHg41gz0_sendMessage);
}

void Heavy_SoundScraper::cCast_zjsNe9cG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BtZgduHT, 0, m, &cDelay_BtZgduHT_sendMessage);
}

void Heavy_SoundScraper::cMsg_OFIuOikR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uq7D9EVB, 2, m, &cDelay_Uq7D9EVB_sendMessage);
}

void Heavy_SoundScraper::cMsg_nIiYegY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4RQPOxik, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_PgLACPP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_FfK6nAzH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_FfK6nAzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_nVT6bU5D, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_bJ6sKTLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_roxhzoG3, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_LnjMRBWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bJ6sKTLp, 0, m, &cPack_bJ6sKTLp_sendMessage);
}

void Heavy_SoundScraper::cCast_FEQVgfOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2nqKerbG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_8N4Rs3VZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_roxhzoG3, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_SeHD7rgF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SdHXwAEd, m);
}

void Heavy_SoundScraper::cMsg_8319JZ6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_DjzEPJit_sendMessage);
}

void Heavy_SoundScraper::cVar_i27S3Afp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_oik2R9ZN_sendMessage);
}

void Heavy_SoundScraper::cBinop_oik2R9ZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_i27S3Afp, 1, m, &cVar_i27S3Afp_sendMessage);
}

void Heavy_SoundScraper::cPack_tdzdbXhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wxvWQs39, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_0DaaiWYU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zqS5U31f, 0, m, &cSlice_zqS5U31f_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1DIoHZYk, 0, m, &cRandom_1DIoHZYk_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_XoaHFD8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2XTXNvAo_sendMessage);
}

void Heavy_SoundScraper::cUnop_2XTXNvAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 25.0f, 0, m, &cBinop_OrdnHkpp_sendMessage);
}

void Heavy_SoundScraper::cRandom_1DIoHZYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 30.0f, 0, m, &cBinop_XoaHFD8T_sendMessage);
}

void Heavy_SoundScraper::cSlice_zqS5U31f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1DIoHZYk, 1, m, &cRandom_1DIoHZYk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_xWcLAogL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HNoi98Cd, 0, m, &cSlice_HNoi98Cd_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_N7Qejp4e, 0, m, &cRandom_N7Qejp4e_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_J5iS50Yb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yDHSEggZ_sendMessage);
}

void Heavy_SoundScraper::cUnop_yDHSEggZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_swZQevab_sendMessage);
}

void Heavy_SoundScraper::cRandom_N7Qejp4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_J5iS50Yb_sendMessage);
}

void Heavy_SoundScraper::cSlice_HNoi98Cd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_N7Qejp4e, 1, m, &cRandom_N7Qejp4e_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_OIWHaYIr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_U0JN00fT, 0, m, &cSlice_U0JN00fT_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pmTaIp7i, 0, m, &cRandom_pmTaIp7i_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_FpcAS52d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7kMu5Oku_sendMessage);
}

void Heavy_SoundScraper::cUnop_7kMu5Oku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_g7DA97DB_sendMessage);
}

void Heavy_SoundScraper::cRandom_pmTaIp7i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_FpcAS52d_sendMessage);
}

void Heavy_SoundScraper::cSlice_U0JN00fT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pmTaIp7i, 1, m, &cRandom_pmTaIp7i_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_ao10hM3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_RESET");
}

void Heavy_SoundScraper::cBinop_OrdnHkpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_l9gIQtK1_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_ao10hM3f, 1, m, &cPack_ao10hM3f_sendMessage);
}

void Heavy_SoundScraper::cBinop_swZQevab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Ouk4YjOP_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_ao10hM3f, 0, m, &cPack_ao10hM3f_sendMessage);
}

void Heavy_SoundScraper::cBinop_g7DA97DB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zkqNuUiD_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_ao10hM3f, 2, m, &cPack_ao10hM3f_sendMessage);
}

void Heavy_SoundScraper::cCast_7o0MqMan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xWcLAogL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_wpikwnLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i6ZXTbz3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_LlvbaZFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OIWHaYIr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_A4z1AaHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0DaaiWYU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_i6ZXTbz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_PPU8NcSf_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_ao10hM3f, 3, m, &cPack_ao10hM3f_sendMessage);
}

void Heavy_SoundScraper::cSend_PPU8NcSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pocdcvVX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_zkqNuUiD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_z2BKp8NE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Ouk4YjOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_l9gIQtK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Zb5wiYbE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_fs8m1gHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_hK250Od3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_G3TEjMA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X2mPgFtP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rfJwRNkF_sendMessage);
}

void Heavy_SoundScraper::cIf_oReJkUSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KYrfVUXS_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_dM2OQRKK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_cjEMqQvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_4GLG8Bxe_sendMessage);
}

void Heavy_SoundScraper::cBinop_dM2OQRKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_cjEMqQvJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_4GLG8Bxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_4AcD4zoj_sendMessage);
}

void Heavy_SoundScraper::cBinop_4AcD4zoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DgaFA6iv, 0, m, &cVar_DgaFA6iv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5fDDzlNB, HV_BINOP_SUBTRACT, 1, m, &cBinop_5fDDzlNB_sendMessage);
}

void Heavy_SoundScraper::cCast_rfJwRNkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oReJkUSR, 0, m, &cIf_oReJkUSR_sendMessage);
}

void Heavy_SoundScraper::cCast_X2mPgFtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_RPtQ6qCH_sendMessage);
}

void Heavy_SoundScraper::cBinop_RPtQ6qCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oReJkUSR, 1, m, &cIf_oReJkUSR_sendMessage);
}

void Heavy_SoundScraper::cMsg_KYrfVUXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_DgaFA6iv, 0, m, &cVar_DgaFA6iv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5fDDzlNB, HV_BINOP_SUBTRACT, 1, m, &cBinop_5fDDzlNB_sendMessage);
}

void Heavy_SoundScraper::cVar_DgaFA6iv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_CJHOTIlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5fDDzlNB, HV_BINOP_SUBTRACT, 0, m, &cBinop_5fDDzlNB_sendMessage);
}

void Heavy_SoundScraper::cBinop_J76rH5PV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fs8m1gHm, 0, m, &cVar_fs8m1gHm_sendMessage);
}

void Heavy_SoundScraper::cBinop_0motB9BQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J76rH5PV, HV_BINOP_ADD, 1, m, &cBinop_J76rH5PV_sendMessage);
}

void Heavy_SoundScraper::cBinop_5fDDzlNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J76rH5PV, HV_BINOP_ADD, 0, m, &cBinop_J76rH5PV_sendMessage);
}

void Heavy_SoundScraper::cSend_hK250Od3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4sNQqzIV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_S1pQbBnr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Wbz3KYD3, 0, m, &cSlice_Wbz3KYD3_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_x0kpOebP, 0, m, &cSlice_x0kpOebP_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_Wbz3KYD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jdk4FSMA_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jdk4FSMA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_x0kpOebP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nLxeyp4e_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wbqzOUi2_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nLxeyp4e_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wbqzOUi2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_yRXZHbPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_td7Dg6wA, HV_BINOP_MULTIPLY, 0, m, &cBinop_td7Dg6wA_sendMessage);
}

void Heavy_SoundScraper::cMsg_emCcMRGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I1FZCUXp_sendMessage);
}

void Heavy_SoundScraper::cSystem_I1FZCUXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FbBpOZ9I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_td7Dg6wA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MzZeQoIz_sendMessage);
}

void Heavy_SoundScraper::cBinop_BEn123Sl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_td7Dg6wA, HV_BINOP_MULTIPLY, 1, m, &cBinop_td7Dg6wA_sendMessage);
}

void Heavy_SoundScraper::cMsg_FbBpOZ9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BEn123Sl_sendMessage);
}

void Heavy_SoundScraper::cBinop_MzZeQoIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nGJkE3ki_sendMessage);
}

void Heavy_SoundScraper::cBinop_nGJkE3ki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SE6b5f8F_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_L37LQ8sN, m);
}

void Heavy_SoundScraper::cBinop_SE6b5f8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6HB5v3Z4, m);
}

void Heavy_SoundScraper::cSlice_iYys7GFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_sxYwFgRm_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_54jHs6NK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_UBIaoMTE_sendMessage(_c, 0, m);
      cPrint_onMessage(_c, m, "SCRAPER_TAB");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_kFlPSj9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_XcxgCpw9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_XcxgCpw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4sNQqzIV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_hUzKPG3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_z2BKp8NE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_mhyRp3nN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5.0f);
  cSend_hUzKPG3d_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_tBUFnhyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_lW6znSuA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_lW6znSuA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_MEfPgKL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_JC21MnOK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_JC21MnOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iXAU0KvM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ltb93JPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_k6R6KzfG_sendMessage);
}

void Heavy_SoundScraper::cBinop_k6R6KzfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Ql4a689R_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_M3YvtzFN_sendMessage);
}

void Heavy_SoundScraper::cVar_hW1pKyB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_b1FbL4dA_sendMessage);
}

void Heavy_SoundScraper::cMsg_r6kVAZ3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lNfhZEdH_sendMessage);
}

void Heavy_SoundScraper::cSystem_lNfhZEdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QNARiVeS, HV_BINOP_DIVIDE, 1, m, &cBinop_QNARiVeS_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ql4a689R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_9M6vHs3j_sendMessage);
}

void Heavy_SoundScraper::cBinop_9M6vHs3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MB2xpbcJ, m);
}

void Heavy_SoundScraper::cMsg_w8yz22Rb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_CX18PXvr_sendMessage);
}

void Heavy_SoundScraper::cBinop_CX18PXvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ltb93JPS_sendMessage);
}

void Heavy_SoundScraper::cBinop_M3YvtzFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rrJYS9uR, m);
}

void Heavy_SoundScraper::cBinop_b1FbL4dA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_hKZdvSxL_sendMessage);
}

void Heavy_SoundScraper::cBinop_hKZdvSxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QNARiVeS, HV_BINOP_DIVIDE, 0, m, &cBinop_QNARiVeS_sendMessage);
}

void Heavy_SoundScraper::cBinop_QNARiVeS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w8yz22Rb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sSample_ntTgnqU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NuaZQ17a, 0, m, &cVar_NuaZQ17a_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_CzEZSBhn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_eobOCr67_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_eobOCr67_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_9UaBccw8, 1, m, &cDelay_9UaBccw8_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pS6R2ozf_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_9UaBccw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9UaBccw8, m);
  sSample_onMessage(_c, &Context(_c)->sSample_ntTgnqU2, 1, m);
}

void Heavy_SoundScraper::cMsg_eobOCr67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9UaBccw8, 0, m, &cDelay_9UaBccw8_sendMessage);
}

void Heavy_SoundScraper::cCast_pS6R2ozf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9UaBccw8, 0, m, &cDelay_9UaBccw8_sendMessage);
}

void Heavy_SoundScraper::cVar_NuaZQ17a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_SIG");
}

void Heavy_SoundScraper::cCast_ZfcPIIcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sSample_onMessage(_c, &Context(_c)->sSample_ntTgnqU2, 1, m);
}

void Heavy_SoundScraper::cSwitchcase_4ICjeQZ1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_yfG9Dukc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_yfG9Dukc_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ncBvfC23, 1, m, &cDelay_ncBvfC23_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zk7q3pe0_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ncBvfC23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ncBvfC23, m);
  sSample_onMessage(_c, &Context(_c)->sSample_ntTgnqU2, 1, m);
}

void Heavy_SoundScraper::cMsg_yfG9Dukc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ncBvfC23, 0, m, &cDelay_ncBvfC23_sendMessage);
}

void Heavy_SoundScraper::cCast_zk7q3pe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ncBvfC23, 0, m, &cDelay_ncBvfC23_sendMessage);
}

void Heavy_SoundScraper::cVar_xuyHzrP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_7X24UL3w_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aEVQJPoh_sendMessage);
}

void Heavy_SoundScraper::cVar_nnyuIK2C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_uj8sfhN3_sendMessage);
}

void Heavy_SoundScraper::cVar_2jeh9K61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_MIt8Afh5, 0, m, &cExpr_MIt8Afh5_sendMessage);
}

void Heavy_SoundScraper::cExpr_MIt8Afh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CHJr9DkN, HV_BINOP_DIVIDE, 0, m, &cBinop_CHJr9DkN_sendMessage);
}

float Heavy_SoundScraper::cExpr_MIt8Afh5_evaluate(const float* args) {
  	return hv_pow_f(2 , ((float)(args[0]))/1200);
}

void Heavy_SoundScraper::cVar_eeJs2bQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_1D1xK21R, 0, m);
}

void Heavy_SoundScraper::cMsg_qcv4t4wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_VqOZBLhJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_lGSNnDjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_FXq03Ta5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_w28okjXH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cSend_kly1Hu2E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_VqOZBLhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CwehpIRw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_FXq03Ta5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vO2eifRB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_kly1Hu2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_z3Cqh4cv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_cxmQt65o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xuyHzrP1, 0, m, &cVar_xuyHzrP1_sendMessage);
}

void Heavy_SoundScraper::cVar_1dxoRA5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nnyuIK2C, 0, m, &cVar_nnyuIK2C_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_dTZ3e48c_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7iiqPDLI, 0, m, &cSlice_7iiqPDLI_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_JhKOM2dn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9CmosvOC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_CSQlI2HE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_alleDIxy_sendMessage);
}

void Heavy_SoundScraper::cBinop_alleDIxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qYYi719y, m);
}

void Heavy_SoundScraper::cMsg_9CmosvOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CSQlI2HE_sendMessage);
}

void Heavy_SoundScraper::cSlice_7iiqPDLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_5KCCOz2X, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_295w2nnC, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_JhKOM2dn, 0, m, &cVar_JhKOM2dn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_LqFhqRk9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_foxBpTq4, 0, m, &cSlice_foxBpTq4_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_9TPhzdwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CcPiXsgh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_zmvyZvIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_qyNFNuDw_sendMessage);
}

void Heavy_SoundScraper::cBinop_qyNFNuDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HVyGZZ9d, m);
}

void Heavy_SoundScraper::cMsg_CcPiXsgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zmvyZvIC_sendMessage);
}

void Heavy_SoundScraper::cSlice_foxBpTq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_uoVitgdD, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_nR7byq0M, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_9TPhzdwH, 0, m, &cVar_9TPhzdwH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_wsRgaukn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CHJr9DkN, HV_BINOP_DIVIDE, 1, m, &cBinop_CHJr9DkN_sendMessage);
}

void Heavy_SoundScraper::cCast_BwWAss9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CHJr9DkN, HV_BINOP_DIVIDE, 0, m, &cBinop_CHJr9DkN_sendMessage);
}

void Heavy_SoundScraper::cBinop_CHJr9DkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eeJs2bQ2, 0, m, &cVar_eeJs2bQ2_sendMessage);
}

void Heavy_SoundScraper::cBinop_7X24UL3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Dl2sC3Z8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_uj8sfhN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KNJUYomR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_aEVQJPoh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VwoHNpNj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_VwoHNpNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_P5xTlQQ7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Dl2sC3Z8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wmeKCgxw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_KNJUYomR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kcttVYug_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KyIzKSMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_LqFhqRk9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_cSR9wmrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_P1wqfoH7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_d1lC6xha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_dTZ3e48c_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_qCRct5qM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_ttWHC1YK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wYnLbVg1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_uE80CN7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iXAU0KvM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_JX82k3JS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tLqbGs8s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_qLq3AJEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LWmLvy6l_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_pPXEUIBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pocdcvVX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_aurBsvsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_60oBGCLw_sendMessage);
}

void Heavy_SoundScraper::cBinop_60oBGCLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tdzdbXhl, 0, m, &cPack_tdzdbXhl_sendMessage);
}

void Heavy_SoundScraper::cSend_ymariczw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LWmLvy6l_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_rYqqExye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4Bg1IGqS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_VSlK4799_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JHfuAaRa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_jdk4FSMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rYqqExye_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_YbzUDAnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_cMHihObf, m);
}

void Heavy_SoundScraper::cMsg_a9UAPDqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_cMHihObf, m);
}

void Heavy_SoundScraper::cSend_UBIaoMTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_27FnSQS6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_sxYwFgRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9lzodGP2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_wbqzOUi2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VSlK4799_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_nLxeyp4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ymariczw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_bDuH753f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nnyuIK2C, 0, m, &cVar_nnyuIK2C_sendMessage);
}

void Heavy_SoundScraper::cBinop_yIPsPp0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xuyHzrP1, 0, m, &cVar_xuyHzrP1_sendMessage);
}

void Heavy_SoundScraper::cBinop_hNhrrJDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_MIt8Afh5, 0, m, &cExpr_MIt8Afh5_sendMessage);
}

void Heavy_SoundScraper::cReceive_79w7CU3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_xdE3u1zg, 0, m, &cPack_xdE3u1zg_sendMessage);
}

void Heavy_SoundScraper::cReceive_yZlsZ9lz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_xdE3u1zg, 1, m, &cPack_xdE3u1zg_sendMessage);
}

void Heavy_SoundScraper::cReceive_KKZatrEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SET_TABLE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_AqEcg7HI, 0, m, &cSlice_AqEcg7HI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_WrxJZLUu, 0, m, &cSlice_WrxJZLUu_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_xXeThES9, 0, m, &cSlice_xXeThES9_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9RUinkdv, 0, m, &cSlice_9RUinkdv_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VmZTvyPU, 0, m, &cSlice_VmZTvyPU_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Bbj83fS7, 0, m, &cSlice_Bbj83fS7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_rsDXauvo, 0, m, &cSlice_rsDXauvo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_aqLi8ka9, 0, m, &cSlice_aqLi8ka9_sendMessage);
  cSend_JX82k3JS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_pOi4PYIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uE80CN7z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_f8qWjmIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ttWHC1YK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_ZRrTc8AD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_i27S3Afp, 0, m, &cVar_i27S3Afp_sendMessage);
  cSwitchcase_S1pQbBnr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_omFdiCCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pPXEUIBG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_mFTFJH8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qLq3AJEg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_21HfNB7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vFBT7bJR_sendMessage(_c, 0, m);
  cMsg_K2zeRRxm_sendMessage(_c, 0, m);
  cMsg_w8alRW5Z_sendMessage(_c, 0, m);
  cMsg_5wYZtQS2_sendMessage(_c, 0, m);
  cMsg_mrXWW6Oq_sendMessage(_c, 0, m);
  cMsg_ZmwbGB1s_sendMessage(_c, 0, m);
  cMsg_7vKni9D0_sendMessage(_c, 0, m);
  cMsg_sLibtJlM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QNuYKa7Y, 0, m, &cVar_QNuYKa7Y_sendMessage);
  cMsg_ZGHaGDyp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QRJf8WjN, 0, m, &cVar_QRJf8WjN_sendMessage);
  cMsg_H7QOyM7d_sendMessage(_c, 0, m);
  cMsg_is01xl3b_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EXFnbPJ6, 0, m, &cVar_EXFnbPJ6_sendMessage);
  cMsg_BGaKQQ15_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_unCIxqAN, 0, m, &cVar_unCIxqAN_sendMessage);
  cMsg_xWilxKpb_sendMessage(_c, 0, m);
  cMsg_s8T6WkLl_sendMessage(_c, 0, m);
  cMsg_e9tDrxrW_sendMessage(_c, 0, m);
  cMsg_xr1MvIVR_sendMessage(_c, 0, m);
  cMsg_HLrKBv6b_sendMessage(_c, 0, m);
  cMsg_oHe59qJb_sendMessage(_c, 0, m);
  cMsg_Uxzpehuk_sendMessage(_c, 0, m);
  cMsg_RDOLxSHd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dMA1tyZM, 0, m, &cVar_dMA1tyZM_sendMessage);
  cMsg_g2eeSLAO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7Pejvwqr, 0, m, &cVar_7Pejvwqr_sendMessage);
  cMsg_2O6jlEJn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uEfeo8q0, 0, m, &cVar_uEfeo8q0_sendMessage);
  cMsg_25ar8EoD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YYpyunGO, 0, m, &cVar_YYpyunGO_sendMessage);
  cMsg_TqdyvEYb_sendMessage(_c, 0, m);
  cMsg_Kr7BGMXX_sendMessage(_c, 0, m);
  cMsg_Itju55S4_sendMessage(_c, 0, m);
  cMsg_nds2eIEn_sendMessage(_c, 0, m);
  cMsg_n0zhc1Is_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_suPlYIka, 0, m, &cVar_suPlYIka_sendMessage);
  cMsg_VQO1FR5e_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3gNWLpcd, 0, m, &cVar_3gNWLpcd_sendMessage);
  cMsg_ql5hdw6S_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8hSZ5atB, 0, m, &cVar_8hSZ5atB_sendMessage);
  cMsg_qBU4bkwg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UZvGkNFA, 0, m, &cVar_UZvGkNFA_sendMessage);
  cMsg_4WZ2XsQd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MrzvP1fe, 0, m, &cVar_MrzvP1fe_sendMessage);
  cMsg_wohpdIfv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Yt4I3DAg, 0, m, &cVar_Yt4I3DAg_sendMessage);
  cMsg_WRd326pC_sendMessage(_c, 0, m);
  cMsg_YPKDoUZJ_sendMessage(_c, 0, m);
  cMsg_eLs2KpEW_sendMessage(_c, 0, m);
  cMsg_TLDrnzwP_sendMessage(_c, 0, m);
  cMsg_XBocforE_sendMessage(_c, 0, m);
  cMsg_RvHW7WXs_sendMessage(_c, 0, m);
  cMsg_hRO6FoxW_sendMessage(_c, 0, m);
  cMsg_pNzOTgSf_sendMessage(_c, 0, m);
  cMsg_Kej92S4u_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LKwaZIHV, 0, m, &cVar_LKwaZIHV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_f6GzgwOQ, 0, m, &cVar_f6GzgwOQ_sendMessage);
  cMsg_PuPzarXF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mpCd3GTM, 0, m, &cVar_mpCd3GTM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iipwD4Jl, 0, m, &cVar_iipwD4Jl_sendMessage);
  cMsg_hp1kt2lq_sendMessage(_c, 0, m);
  cMsg_skvSkBjX_sendMessage(_c, 0, m);
  cMsg_SkpIln9e_sendMessage(_c, 0, m);
  cMsg_mc0UUh1K_sendMessage(_c, 0, m);
  cMsg_C6lDkyb8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BBEk2wpJ, 0, m, &cVar_BBEk2wpJ_sendMessage);
  cMsg_qkvtpNXn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_amsna2uF, 0, m, &cVar_amsna2uF_sendMessage);
  cMsg_kXm6ZoYy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8y9geDsc, 0, m, &cVar_8y9geDsc_sendMessage);
  cMsg_OToyrAqI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8lbhnd7G, 0, m, &cVar_8lbhnd7G_sendMessage);
  cMsg_UrmGU4xo_sendMessage(_c, 0, m);
  cMsg_NHzhWmsA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UUjf7avV, 0, m, &cVar_UUjf7avV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7xCpfsq7, 0, m, &cVar_7xCpfsq7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yXRGd0cC, 0, m, &cVar_yXRGd0cC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Gx4aU02O, 0, m, &cVar_Gx4aU02O_sendMessage);
  cMsg_PgLACPP9_sendMessage(_c, 0, m);
  cMsg_qcv4t4wp_sendMessage(_c, 0, m);
  cMsg_lGSNnDjg_sendMessage(_c, 0, m);
  cMsg_w28okjXH_sendMessage(_c, 0, m);
  cMsg_iFGNLHAu_sendMessage(_c, 0, m);
  cMsg_VN5E2mZ2_sendMessage(_c, 0, m);
  cMsg_ECPhDJd6_sendMessage(_c, 0, m);
  cMsg_14Kkq36C_sendMessage(_c, 0, m);
  cMsg_nP8wMzxG_sendMessage(_c, 0, m);
  cMsg_4DTd8I8e_sendMessage(_c, 0, m);
  cMsg_ntv7LGRI_sendMessage(_c, 0, m);
  cMsg_KWIRudLd_sendMessage(_c, 0, m);
  cMsg_32sKD9sl_sendMessage(_c, 0, m);
  cMsg_fT55MdV6_sendMessage(_c, 0, m);
  cMsg_WiaTFC0N_sendMessage(_c, 0, m);
  cMsg_X0RmzJZb_sendMessage(_c, 0, m);
  cMsg_unhWdbYx_sendMessage(_c, 0, m);
  cMsg_4w4osUKC_sendMessage(_c, 0, m);
  cMsg_9PiB34cM_sendMessage(_c, 0, m);
  cMsg_qhhOTZPP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_C0sJXISA, 0, m, &cVar_C0sJXISA_sendMessage);
  cMsg_e9Yfg7N2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_72epLU0S, 0, m, &cVar_72epLU0S_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_m3zpkrFO, 0, m, &cVar_m3zpkrFO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qHNmWRHw, 0, m, &cVar_qHNmWRHw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9Lf5p4hx, 0, m, &cVar_9Lf5p4hx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0ZeYgSOW, 0, m, &cVar_0ZeYgSOW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5qTMHlsd, 0, m, &cVar_5qTMHlsd_sendMessage);
  cMsg_SeHD7rgF_sendMessage(_c, 0, m);
  cMsg_8319JZ6R_sendMessage(_c, 0, m);
  cMsg_emCcMRGE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yRXZHbPZ, 0, m, &cVar_yRXZHbPZ_sendMessage);
  cMsg_kFlPSj9Z_sendMessage(_c, 0, m);
  cMsg_mhyRp3nN_sendMessage(_c, 0, m);
  cMsg_tBUFnhyV_sendMessage(_c, 0, m);
  cMsg_MEfPgKL7_sendMessage(_c, 0, m);
  cMsg_r6kVAZ3x_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hW1pKyB9, 0, m, &cVar_hW1pKyB9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kQoa8PP9, 0, m, &cVar_kQoa8PP9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cxUxo8lC, 0, m, &cVar_cxUxo8lC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MuBnRqAH, 0, m, &cVar_MuBnRqAH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_U6xpMsZB, 0, m, &cVar_U6xpMsZB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gKs7CXnN, 0, m, &cVar_gKs7CXnN_sendMessage);
  cMsg_S2E6vUIB_sendMessage(_c, 0, m);
  cMsg_7cJ6QGYY_sendMessage(_c, 0, m);
  cSend_qLq3AJEg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qXi0I8E2, 0, m, &cVar_qXi0I8E2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_w2BCu1qI, 0, m, &cVar_w2BCu1qI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PHKSKwVQ, 0, m, &cVar_PHKSKwVQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Y5ESACwB, 0, m, &cVar_Y5ESACwB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CJXESJkC, 0, m, &cVar_CJXESJkC_sendMessage);
  cMsg_fz5kpT03_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BT9w3UQi, 0, m, &cVar_BT9w3UQi_sendMessage);
  cMsg_lUoJWmAG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZQ4urXOr, 0, m, &cVar_ZQ4urXOr_sendMessage);
  cMsg_lvxwxi5v_sendMessage(_c, 0, m);
  cMsg_cly0v3xs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5RS8xrjj, 0, m, &cVar_5RS8xrjj_sendMessage);
  cMsg_ot9VaF3R_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_dQGV4TaD, 0, m, &cTabhead_dQGV4TaD_sendMessage);
  cMsg_sdlWGwW8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8eGRysGs, 0, m, &cVar_8eGRysGs_sendMessage);
  cMsg_KuN70eS7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zkwkMx3i, 0, m, &cTabhead_zkwkMx3i_sendMessage);
  cMsg_2UcNJOw8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SUKx77xc, 0, m, &cVar_SUKx77xc_sendMessage);
  cMsg_aHonXJtZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5YB6GLd8, 0, m, &cTabhead_5YB6GLd8_sendMessage);
  cMsg_TR0PKnnU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_x74XdEp4, 0, m, &cVar_x74XdEp4_sendMessage);
  cMsg_0tmq3dMd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YtVtkXvw, 0, m, &cTabhead_YtVtkXvw_sendMessage);
  cMsg_RcPAoHsW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nA588aRO, 0, m, &cVar_nA588aRO_sendMessage);
  cMsg_zezIwlEy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IdTyyQqV, 0, m, &cTabhead_IdTyyQqV_sendMessage);
  cMsg_IUpm8iCp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aJBko5Hj, 0, m, &cVar_aJBko5Hj_sendMessage);
  cMsg_ZWSrqO8N_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_T5kxR6Bj, 0, m, &cTabhead_T5kxR6Bj_sendMessage);
  cMsg_BYchpieP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3fu5Vlkm, 0, m, &cVar_3fu5Vlkm_sendMessage);
  cMsg_F1O4oH77_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SorZQocM, 0, m, &cTabhead_SorZQocM_sendMessage);
  cMsg_SRzLcMvn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_F9Z5vpqn, 0, m, &cVar_F9Z5vpqn_sendMessage);
  cMsg_2kHR0Wxo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7UcD3OfN, 0, m, &cTabhead_7UcD3OfN_sendMessage);
  cMsg_o57rUdpN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fbBmbnAL, 0, m, &cVar_fbBmbnAL_sendMessage);
  cMsg_A7tKvd8f_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_H0Fjzoxy, 0, m, &cTabhead_H0Fjzoxy_sendMessage);
  cMsg_kYS0xSrs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dLQB0ucx, 0, m, &cVar_dLQB0ucx_sendMessage);
  cMsg_qgEK1ib3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_faczOfG2, 0, m, &cTabhead_faczOfG2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WKLIB3Ca, 0, m, &cVar_WKLIB3Ca_sendMessage);
  cMsg_CHXavIij_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gmdil0iA, 0, m, &cVar_gmdil0iA_sendMessage);
  cMsg_jo5slCdG_sendMessage(_c, 0, m);
  cMsg_TeeMipVv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JC7RDpFG, 0, m, &cVar_JC7RDpFG_sendMessage);
  cMsg_kB36p1p9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lip8PHSU, 0, m, &cTabhead_lip8PHSU_sendMessage);
  cMsg_ZMA6rgu9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YbibKPT8, 0, m, &cVar_YbibKPT8_sendMessage);
  cMsg_pHd8l796_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ag3mRohw, 0, m, &cTabhead_Ag3mRohw_sendMessage);
  cMsg_yZkwKmlW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2NsQs6DS, 0, m, &cVar_2NsQs6DS_sendMessage);
  cMsg_m6GUWcSa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IRLU9bKn, 0, m, &cTabhead_IRLU9bKn_sendMessage);
  cMsg_V2MDCi6F_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AMOcZgQy, 0, m, &cVar_AMOcZgQy_sendMessage);
  cMsg_BQS3GUs0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_w3zdsZey, 0, m, &cTabhead_w3zdsZey_sendMessage);
  cMsg_JEirfwee_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_82yyJGeu, 0, m, &cVar_82yyJGeu_sendMessage);
  cMsg_U9tHtUSH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4ORVYUGP, 0, m, &cTabhead_4ORVYUGP_sendMessage);
  cMsg_CROnPuWr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_feP8qnCF, 0, m, &cVar_feP8qnCF_sendMessage);
  cMsg_F027C2WA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6RNCBRML, 0, m, &cTabhead_6RNCBRML_sendMessage);
  cMsg_pVzGQa3j_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sFUc7NUz, 0, m, &cVar_sFUc7NUz_sendMessage);
  cMsg_r4EqlreD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_KaWi584T, 0, m, &cTabhead_KaWi584T_sendMessage);
  cMsg_QCX2QHiK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GLAH01co, 0, m, &cVar_GLAH01co_sendMessage);
  cMsg_YTkIVEjl_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_C0bpdWpL, 0, m, &cTabhead_C0bpdWpL_sendMessage);
  cMsg_if7m9U6S_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dv4BAS48, 0, m, &cVar_dv4BAS48_sendMessage);
  cMsg_aT7xszWC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sk1YC4aq, 0, m, &cTabhead_sk1YC4aq_sendMessage);
  cMsg_Sa3XAs8q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UWNsV8I9, 0, m, &cVar_UWNsV8I9_sendMessage);
  cMsg_IbvCsCFp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_XVbQNLss, 0, m, &cTabhead_XVbQNLss_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sDIrlZy1, 0, m, &cVar_sDIrlZy1_sendMessage);
  cMsg_BqQhlelZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JhKOM2dn, 0, m, &cVar_JhKOM2dn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9TPhzdwH, 0, m, &cVar_9TPhzdwH_sendMessage);
}

void Heavy_SoundScraper::cReceive_jXHAScWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cG6hT3WO, 0, m, &cVar_cG6hT3WO_sendMessage);
}

void Heavy_SoundScraper::cReceive_C745Ey8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xfwhosI2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UcPdeDQJ_sendMessage);
}

void Heavy_SoundScraper::cReceive_jZwhmra9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5cMyjGtA, 1, m, &cVar_5cMyjGtA_sendMessage);
}

void Heavy_SoundScraper::cReceive_yVQgQJaP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGVI9N2W, HV_BINOP_DIVIDE, 1, m, &cBinop_UGVI9N2W_sendMessage);
}

void Heavy_SoundScraper::cReceive_zT2FOZe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KuBAaLEp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_xC8JETB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RuMXluFc, 1, m, &cVar_RuMXluFc_sendMessage);
}

void Heavy_SoundScraper::cReceive_f1WQ5DsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EmKTdPIX, m);
}

void Heavy_SoundScraper::cReceive_GLg1BikG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_bshnaGSq, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_R127Hope, 0, m, &cSlice_R127Hope_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_t64pF7TK, 0, m, &cSlice_t64pF7TK_sendMessage);
}

void Heavy_SoundScraper::cReceive_YeIx5fjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lC2ECPMD, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_hJkSXKfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cEfn3tIf, 1, m, &cVar_cEfn3tIf_sendMessage);
}

void Heavy_SoundScraper::cReceive_kNsP12v3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W7bXoNKU, HV_BINOP_DIVIDE, 1, m, &cBinop_W7bXoNKU_sendMessage);
}

void Heavy_SoundScraper::cReceive_64ga5gHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3fTrkZps_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_qZ3JIoVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F81RJd5r, 1, m, &cVar_F81RJd5r_sendMessage);
}

void Heavy_SoundScraper::cReceive_JVeUJWhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mtUHI40x, m);
}

void Heavy_SoundScraper::cReceive_tTtgiER6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_U11ucE0N, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_kvSn1A0I, 0, m, &cSlice_kvSn1A0I_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_6Xso5zkv, 0, m, &cSlice_6Xso5zkv_sendMessage);
}

void Heavy_SoundScraper::cReceive_bEyWtO5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qWnocqeu, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_0ReGqyN9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sxfPugwM, 1, m, &cVar_sxfPugwM_sendMessage);
}

void Heavy_SoundScraper::cReceive_wMehuFB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ygGHsxHX, HV_BINOP_DIVIDE, 1, m, &cBinop_ygGHsxHX_sendMessage);
}

void Heavy_SoundScraper::cReceive_IwtHfQKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IjsSyyso_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_mQ5Hg5Ja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X7BB0wu9, 1, m, &cVar_X7BB0wu9_sendMessage);
}

void Heavy_SoundScraper::cReceive_xXLSTEOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AlehJ60r, m);
}

void Heavy_SoundScraper::cReceive_qADzeWFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Ok9RA0ft, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_8o3gCmNK, 0, m, &cSlice_8o3gCmNK_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_xGE9d15I, 0, m, &cSlice_xGE9d15I_sendMessage);
}

void Heavy_SoundScraper::cReceive_kqF2iJb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_aQpkjbES, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_8ulyCInE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eis14qJ6, 1, m, &cVar_eis14qJ6_sendMessage);
}

void Heavy_SoundScraper::cReceive_tGuNsXcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tgp3hZRK, HV_BINOP_DIVIDE, 1, m, &cBinop_Tgp3hZRK_sendMessage);
}

void Heavy_SoundScraper::cReceive_XXwtG2Vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_T4Qg5POX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_PPsVGZFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vmGPbRTy, 1, m, &cVar_vmGPbRTy_sendMessage);
}

void Heavy_SoundScraper::cReceive_qgvPM0Rv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SO8l3Oh9, m);
}

void Heavy_SoundScraper::cReceive_4awM0p6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_BDU8QKHK, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_Uz3pjaUt, 0, m, &cSlice_Uz3pjaUt_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_udyLEGZq, 0, m, &cSlice_udyLEGZq_sendMessage);
}

void Heavy_SoundScraper::cReceive_gkT7foyj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tcjIz412, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_zd3gsUBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dfBoi07G, 0, m, &cVar_dfBoi07G_sendMessage);
}

void Heavy_SoundScraper::cReceive_4eQaa9bD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lJUgKhGT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_L00kaZ3c_sendMessage);
}

void Heavy_SoundScraper::cReceive_boqSUwBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uzABqCkY, 0, m, &cVar_uzABqCkY_sendMessage);
}

void Heavy_SoundScraper::cReceive_JsJfNXjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bWRd61JO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U4p5j6KP_sendMessage);
}

void Heavy_SoundScraper::cReceive_fY4XRZME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_bMHWSeyp_sendMessage);
}

void Heavy_SoundScraper::cReceive_GZJMvqdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0qOXdVy0, 0, m, &cVar_0qOXdVy0_sendMessage);
}

void Heavy_SoundScraper::cReceive_MUee4EMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kSE94tU5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cDiro0CY_sendMessage);
}

void Heavy_SoundScraper::cReceive_MRKcW8UN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NjaMqmg5, 0, m, &cVar_NjaMqmg5_sendMessage);
}

void Heavy_SoundScraper::cReceive_3CC5ZSf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K7RtLeBm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5yW0dB7j_sendMessage);
}

void Heavy_SoundScraper::cReceive_rBWLuHUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_9y3VeT1v, 0, m, &cSlice_9y3VeT1v_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yjRf2i9Z, 0, m, &cSlice_yjRf2i9Z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vyjGKfqy, 0, m, &cSlice_vyjGKfqy_sendMessage);
}

void Heavy_SoundScraper::cReceive_h3aSlJA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_dTkbaS81_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_2ZOQk7NA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_c1Dwz3nJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_djyXofn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xytZiYk8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z0f4Okkm_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_KDnQfsTC, 0, m, &cPack_KDnQfsTC_sendMessage);
}

void Heavy_SoundScraper::cReceive_VoKSYf6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LnjMRBWl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FEQVgfOx_sendMessage);
}

void Heavy_SoundScraper::cReceive_J0Vb6wxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_m8MNnt5b_sendMessage);
}

void Heavy_SoundScraper::cReceive_nPPo9706_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Rd9Febm6, 0, m, &cVar_Rd9Febm6_sendMessage);
}

void Heavy_SoundScraper::cReceive_ck2cgdMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F1ErnitC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1nCZbteS_sendMessage);
}

void Heavy_SoundScraper::cReceive_zzsxBujR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_hBZB7NQE_sendMessage);
}

void Heavy_SoundScraper::cReceive_wYnLbVg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5fDDzlNB, HV_BINOP_SUBTRACT, 0, m, &cBinop_5fDDzlNB_sendMessage);
}

void Heavy_SoundScraper::cReceive_iXAU0KvM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_aurBsvsZ_sendMessage);
  cPrint_onMessage(_c, m, "SCRAPER_LEVEL");
  cVar_onMessage(_c, &Context(_c)->cVar_P88YlK88, 0, m, &cVar_P88YlK88_sendMessage);
}

void Heavy_SoundScraper::cReceive_tLqbGs8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_iYys7GFK, 0, m, &cSlice_iYys7GFK_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_54jHs6NK, 0, m, &cSlice_54jHs6NK_sendMessage);
}

void Heavy_SoundScraper::cReceive_LWmLvy6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wpikwnLF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LlvbaZFY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A4z1AaHD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7o0MqMan_sendMessage);
}

void Heavy_SoundScraper::cReceive_pocdcvVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_0motB9BQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CJHOTIlx_sendMessage);
}

void Heavy_SoundScraper::cReceive_z2BKp8NE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_yIPsPp0W_sendMessage);
}

void Heavy_SoundScraper::cReceive_Zb5wiYbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_bDuH753f_sendMessage);
}

void Heavy_SoundScraper::cReceive_4sNQqzIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_TRANSPOSITION");
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_hNhrrJDB_sendMessage);
}

void Heavy_SoundScraper::cReceive_9lzodGP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_G3TEjMA6, 0, m, &cVar_G3TEjMA6_sendMessage);
}

void Heavy_SoundScraper::cReceive_4Bg1IGqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YbzUDAnI_sendMessage(_c, 0, m);
  cSwitchcase_CzEZSBhn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_JHfuAaRa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a9UAPDqE_sendMessage(_c, 0, m);
  cSwitchcase_4ICjeQZ1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_27FnSQS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cSR9wmrZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_CwehpIRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2jeh9K61, 0, m, &cVar_2jeh9K61_sendMessage);
}

void Heavy_SoundScraper::cReceive_vO2eifRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1dxoRA5S, 0, m, &cVar_1dxoRA5S_sendMessage);
}

void Heavy_SoundScraper::cReceive_z3Cqh4cv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cxmQt65o, 0, m, &cVar_cxmQt65o_sendMessage);
}

void Heavy_SoundScraper::cReceive_P5xTlQQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wsRgaukn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BwWAss9H_sendMessage);
}

void Heavy_SoundScraper::cReceive_wmeKCgxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KEKKW4od, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7C0lU7IQ, m);
}

void Heavy_SoundScraper::cReceive_kcttVYug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wheB7zSH, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8hmbsw4W, m);
}

void Heavy_SoundScraper::cReceive_P1wqfoH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KyIzKSMA_sendMessage(_c, 0, m);
  cMsg_d1lC6xha_sendMessage(_c, 0, m);
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
    __hv_varread_f(&sVarf_cMHihObf, VOf(Bf0));
    __hv_varread_f(&sVarf_L37LQ8sN, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_6HB5v3Z4, VOf(Bf0));
    __hv_rpole_f(&sRPole_sIlLZ2Jb, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_KEKKW4od, VOf(Bf1));
    __hv_varread_f(&sVarf_2xZtm9Yc, VOf(Bf2));
    __hv_del1_f(&sDel1_nLdCSapK, VIf(Bf2), VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_EbNxg2RQ, VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_2xZtm9Yc, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_wheB7zSH, VOf(Bf1));
    __hv_varread_f(&sVarf_2xZtm9Yc, VOf(Bf3));
    __hv_del1_f(&sDel1_AmBhvPw5, VIf(Bf3), VOf(Bf4));
    __hv_lt_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_yGLdZF21, VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_HVyGZZ9d, VOf(Bf2));
    __hv_min_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_uoVitgdD, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_nR7byq0M, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_2xZtm9Yc, VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf8), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_7C0lU7IQ, VOf(Bf7));
    __hv_varread_f(&sVarf_eWFHyqTT, VOf(Bf1));
    __hv_del1_f(&sDel1_43JDE4a4, VIf(Bf1), VOf(Bf9));
    __hv_lt_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_samphold_f(&sSamphold_WiZ1kBrl, VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_eWFHyqTT, VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_8hmbsw4W, VOf(Bf7));
    __hv_varread_f(&sVarf_eWFHyqTT, VOf(Bf9));
    __hv_del1_f(&sDel1_RhbxGUa8, VIf(Bf9), VOf(Bf6));
    __hv_lt_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_samphold_f(&sSamphold_6CIVD5wv, VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_qYYi719y, VOf(Bf1));
    __hv_min_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf6));
    __hv_max_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_5KCCOz2X, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_295w2nnC, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf7), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_eWFHyqTT, VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf5), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf3), VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_phasor_k_f(&sPhasor_1D1xK21R, VOf(Bf8));
    __hv_varwrite_f(&sVarf_2xZtm9Yc, VIf(Bf8));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf8));
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_varwrite_f(&sVarf_eWFHyqTT, VIf(Bf8));
    __hv_varread_f(&sVarf_rrJYS9uR, VOf(Bf8));
    __hv_rpole_f(&sRPole_dbMqk2ue, VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_tPNlaYOT, VIf(Bf8), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_MB2xpbcJ, VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_wxvWQs39, VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_ntTgnqU2, VIf(Bf8), &sSample_ntTgnqU2_sendMessage);
    __hv_line_f(&sLine_bshnaGSq, VOf(Bf8));
    __hv_varread_f(&sVarf_83HBdz9x, VOf(Bf10));
    __hv_min_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_9XM6QKta, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_8ScqbFZc, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf3));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_lC2ECPMD, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_Go9WbMt2, VOf(Bf9));
    __hv_varread_f(&sVarf_EmKTdPIX, VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_i32PJq3G, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_2JtmVX3L, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_U11ucE0N, VOf(Bf3));
    __hv_varread_f(&sVarf_dLeAuaZe, VOf(Bf8));
    __hv_min_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_d1DBYHps, VIi(Bi1), VOf(Bf4));
    __hv_tabread_if(&sTabread_4S6pd9SU, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_qWnocqeu, VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_gfJzJeYK, VOf(Bf7));
    __hv_varread_f(&sVarf_mtUHI40x, VOf(Bf4));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_zUdbyos4, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_mDDzoF84, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_Ok9RA0ft, VOf(Bf10));
    __hv_varread_f(&sVarf_P78MKYz3, VOf(Bf4));
    __hv_min_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_4jFfPfJk, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_FVl715Ig, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf3), VIf(Bf11), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_aQpkjbES, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_AxbOM8g4, VOf(Bf11));
    __hv_varread_f(&sVarf_AlehJ60r, VOf(Bf3));
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_nGnRmxH5, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_CJoqj8i6, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_BDU8QKHK, VOf(Bf8));
    __hv_varread_f(&sVarf_6bjjo3r0, VOf(Bf3));
    __hv_min_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_WMooWWa7, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_gu9QeQkc, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf10), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_tcjIz412, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_gmsgGRvV, VOf(Bf2));
    __hv_varread_f(&sVarf_SO8l3Oh9, VOf(Bf10));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_93JHr555, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_M3QAuhSI, VOf(Bf2));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_1KwlxQbV, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_oZmQ27Ed, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf0));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf11));
    __hv_line_f(&sLine_hdNjQ4Sw, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf0));
    __hv_mul_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_hzLthO4d, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_P3iOl8Jo, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_S3C7AJOw, VIf(Bf2));
    __hv_line_f(&sLine_3uIgCiqW, VOf(Bf2));
    __hv_phasor_f(&sPhasor_vS5B2jzl, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf11));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf5), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf1), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf10), VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf11), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_v70FQxyK, VOf(Bf5));
    __hv_line_f(&sLine_0z4wRBQN, VOf(Bf11));
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf11), VOf(Bf6));
    __hv_tabhead_f(&sTabhead_N5udHe0x, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf10), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_ed1QnKWf, VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_1LDhi1ch, VOf(Bf6));
    __hv_min_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf10));
    __hv_varread_f(&sVarf_I8Mf5LjP, VOf(Bf6));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_cNijK1bp, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_pFj9k7Th, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf13), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf14), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf4), VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf14), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf12), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf15), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf10), VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_tabhead_f(&sTabhead_58QuyfhE, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_3dLSUVXI, VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_7ATy5vzG, VOf(Bf11));
    __hv_min_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf2));
    __hv_varread_f(&sVarf_CXFokFf0, VOf(Bf11));
    __hv_zero_f(VOf(Bf13));
    __hv_lt_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_and_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_cast_fi(VIf(Bf13), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_71m0RMIc, VIi(Bi1), VOf(Bf13));
    __hv_tabread_if(&sTabread_6aN6yCYZ, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf13));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf13), VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_Crsreo61, VOf(Bf6));
    __hv_tabhead_f(&sTabhead_WDmJfo2K, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf14), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_YxdX9ZsG, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_KjAc0sTL, VOf(Bf6));
    __hv_min_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf14));
    __hv_varread_f(&sVarf_tx7hrITJ, VOf(Bf6));
    __hv_zero_f(VOf(Bf2));
    __hv_lt_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_and_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_E3sScKlT, VIi(Bi1), VOf(Bf2));
    __hv_tabread_if(&sTabread_FXu1Jn8L, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf2), VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_y6fM4WkY, VOf(Bf14));
    __hv_rpole_f(&sRPole_nnOieFj3, VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_LmksYKL2, VIf(Bf14), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_pBglXIVS, VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_MbFKhnD4, VOf(Bf6));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf14));
    __hv_line_f(&sLine_Qoni9Jxq, VOf(Bf2));
    __hv_varread_f(&sVarf_GOqgKqdf, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_FJaT9mYd, VOf(Bf6));
    __hv_rpole_f(&sRPole_iUpdm8EL, VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf11), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_0t0DFWPC, VIf(Bf6));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_tabread_f(&sTabread_CeeGY1XF, VOf(Bf14));
    __hv_varread_f(&sVarf_KwH7uPdq, VOf(Bf2));
    __hv_mul_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_jF1QO3XA, VOf(Bf11));
    __hv_rpole_f(&sRPole_bJ3hUtuB, VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf11), VIf(Bf14), VOf(Bf11));
    __hv_line_f(&sLine_SHoCFhFD, VOf(Bf2));
    __hv_fma_f(VIf(Bf11), VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_dJqq3XCk, VOf(Bf11));
    __hv_tabread_f(&sTabread_skrQgTu2, VOf(Bf1));
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf13));
    __hv_tabread_f(&sTabread_OTRfYaXU, VOf(Bf5));
    __hv_add_f(VIf(Bf13), VIf(Bf5), VOf(Bf10));
    __hv_tabread_f(&sTabread_FTyvzgHR, VOf(Bf15));
    __hv_add_f(VIf(Bf10), VIf(Bf15), VOf(Bf12));
    __hv_tabread_f(&sTabread_H9bw0qaf, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf9));
    __hv_tabread_f(&sTabread_Ugbd5hyq, VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_mwTuQgYl, VIf(Bf16));
    __hv_sub_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_Yk4nFHM7, VIf(Bf4));
    __hv_sub_f(VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_ZvPOLZEn, VIf(Bf15));
    __hv_sub_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_QgBfBLlZ, VIf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_9t4zc6T8, VIf(Bf1));
    __hv_tabwrite_f(&sTabwrite_ET7OwVWI, VIf(Bf3));
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_tabread_f(&sTabread_ZhvN7uYw, VOf(Bf9));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_tabread_f(&sTabread_6q3SWtFH, VOf(Bf14));
    __hv_varread_f(&sVarf_un1g1d0O, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_ajAz2Xlp, VOf(Bf5));
    __hv_rpole_f(&sRPole_A4Xv7Zo1, VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf14), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf14));
    __hv_tabread_f(&sTabread_jqylowgB, VOf(Bf5));
    __hv_varread_f(&sVarf_E5Wh7Xmx, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_u1QcfUtf, VOf(Bf13));
    __hv_rpole_f(&sRPole_PotX8x7U, VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf5), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_tabread_f(&sTabread_Ep1qFV0s, VOf(Bf13));
    __hv_varread_f(&sVarf_g0tWhXk8, VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_dEVXdxYr, VOf(Bf15));
    __hv_rpole_f(&sRPole_HaFreODy, VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf13), VOf(Bf15));
    __hv_fma_f(VIf(Bf15), VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf5), VIf(Bf11), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_8v2c4aZz, VIf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf15));
    __hv_add_f(VIf(Bf2), VIf(Bf15), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_o7YBXfC9, VIf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_5cCbnJyF, VIf(Bf13));
    __hv_sub_f(VIf(Bf2), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_lMtm8tzT, VIf(Bf15));
    __hv_line_f(&sLine_Pbc8ILGk, VOf(Bf15));
    __hv_mul_f(VIf(Bf8), VIf(Bf15), VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_roxhzoG3, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_gxG0BJ0g, VIf(Bf3));
    __hv_line_f(&sLine_ntJBN5QW, VOf(Bf15));
    __hv_phasor_f(&sPhasor_CpE4540y, VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf5));
    __hv_sub_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf13), VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf14), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_XV7Geksf, VOf(Bf1));
    __hv_line_f(&sLine_7KmBqBtm, VOf(Bf5));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf5), VOf(Bf4));
    __hv_tabhead_f(&sTabhead_1JVrFJZM, VOf(Bf14));
    __hv_var_k_f_r(VOf(Bf13), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_MzWkkHz4, VOf(Bf14));
    __hv_mul_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_XambgzmC, VOf(Bf4));
    __hv_min_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf13));
    __hv_varread_f(&sVarf_MlqBeba3, VOf(Bf4));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_9El8zARY, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_Y9u7fvuc, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf11));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf11), VIf(Bf13), VIf(Bf4), VOf(Bf4));
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
    __hv_mul_f(VIf(Bf14), VIf(Bf13), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf17), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf11), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf2), VIf(Bf17), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf18), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf13), VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_tabhead_f(&sTabhead_kYzgects, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_NjBW8hN8, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_a20CXYUT, VOf(Bf5));
    __hv_min_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf15));
    __hv_varread_f(&sVarf_ACIXjIeN, VOf(Bf5));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_fekFvy4U, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_pWsD6Fxx, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf16), VIf(Bf5), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf16), VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf10), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_SdHXwAEd, VOf(Bf4));
    __hv_tabhead_f(&sTabhead_PlgIfYRx, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_TCYUEP7x, VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_04t1k3yf, VOf(Bf4));
    __hv_min_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf17));
    __hv_varread_f(&sVarf_yx9aoQhm, VOf(Bf4));
    __hv_zero_f(VOf(Bf15));
    __hv_lt_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_cast_fi(VIf(Bf15), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_BBesFFvl, VIi(Bi1), VOf(Bf15));
    __hv_tabread_if(&sTabread_ClZpa9MR, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf15));
    __hv_sub_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf15), VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_CIfAqho5, VOf(Bf17));
    __hv_rpole_f(&sRPole_Lf9VbD70, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_RygAHqLZ, VIf(Bf17), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_AQQlL3Kp, VOf(Bf17));
    __hv_mul_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_0YNilGdW, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf17));
    __hv_line_f(&sLine_nVT6bU5D, VOf(Bf15));
    __hv_varread_f(&sVarf_WnpXrliR, VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_mXs1tjpP, VOf(Bf4));
    __hv_rpole_f(&sRPole_GbSywDgp, VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_4RQPOxik, VIf(Bf4));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_c2Lajbd2, VOf(Bf17));
    __hv_varread_f(&sVarf_imVNHhRK, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_621nj69Q, VOf(Bf4));
    __hv_min_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_e8utBies, VOf(Bf15));
    __hv_mul_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf3));
    __hv_varread_f(&sVarf_5bAz22ST, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf15), VIf(Bf3), VOf(Bf15));
    __hv_cos_f(VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_zero_f(VOf(Bf3));
    __hv_gt_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_sqrt_f(VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_cpole_f(&sCPole_FeYd7row, VIf(Bf4), VIf(ZERO), VIf(Bf5), VIf(Bf17), VOf(Bf17), VOf(Bf5));
    __hv_varread_f(&sVarf_9PZteRv6, VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_K8OrsP83, VOf(Bf17));
    __hv_rpole_f(&sRPole_h2bBvM6v, VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_mHFwPA5F, VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_0bHHyJCc, VOf(Bf17));
    __hv_rpole_f(&sRPole_ucX2rnGk, VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_D3D4NVp4, VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_XgTJfZbo, VOf(Bf17));
    __hv_rpole_f(&sRPole_ChaZ5mzW, VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_0KuezqPO, VOf(Bf5));
    __hv_varread_f(&sVarf_Vu0Gbx6C, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_BqoFLV6h, VOf(Bf15));
    __hv_rpole_f(&sRPole_nmWcpXyU, VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf5), VOf(Bf15));
    __hv_line_f(&sLine_HLlHtEJM, VOf(Bf4));
    __hv_fma_f(VIf(Bf15), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_GZaKiYhY, VOf(Bf15));
    __hv_tabread_f(&sTabread_sjeac2xu, VOf(Bf3));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf10));
    __hv_tabread_f(&sTabread_FVhGrixi, VOf(Bf16));
    __hv_add_f(VIf(Bf10), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_OFqKjXTX, VOf(Bf13));
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf18));
    __hv_tabread_f(&sTabread_mlFLAfJ2, VOf(Bf12));
    __hv_add_f(VIf(Bf18), VIf(Bf12), VOf(Bf2));
    __hv_tabread_f(&sTabread_SEzZpQLS, VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_cXP0kBkY, VIf(Bf14));
    __hv_sub_f(VIf(Bf18), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_J5tLNS4a, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_8MKKfEgy, VIf(Bf13));
    __hv_sub_f(VIf(Bf10), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_n1McHLWQ, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_ZJbanhll, VIf(Bf3));
    __hv_tabwrite_f(&sTabwrite_ZvnOmipx, VIf(Bf17));
    __hv_add_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_Gc0cm6Ig, VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_iO89QDof, VOf(Bf5));
    __hv_varread_f(&sVarf_FgHRs1Po, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_8GxEbFmH, VOf(Bf16));
    __hv_rpole_f(&sRPole_JWK4aDmI, VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf5), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf5));
    __hv_tabread_f(&sTabread_HycPhAxU, VOf(Bf16));
    __hv_varread_f(&sVarf_9X9WfMo8, VOf(Bf3));
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_nwuLrGpd, VOf(Bf10));
    __hv_rpole_f(&sRPole_ujRzsf9H, VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf10), VIf(Bf16), VOf(Bf10));
    __hv_fma_f(VIf(Bf10), VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf16));
    __hv_tabread_f(&sTabread_4OsSDFlz, VOf(Bf10));
    __hv_varread_f(&sVarf_bcbXDy3L, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Inz1DJ92, VOf(Bf13));
    __hv_rpole_f(&sRPole_8lUqnb0V, VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf10), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf16), VIf(Bf15), VOf(Bf10));
    __hv_add_f(VIf(Bf5), VIf(Bf10), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_2jjdXLe3, VIf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf2), VOf(Bf4));
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf13));
    __hv_add_f(VIf(Bf4), VIf(Bf13), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_xFsOokez, VIf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_ZD2F13PD, VIf(Bf10));
    __hv_sub_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_Ap00FIMe, VIf(Bf13));
    __hv_line_f(&sLine_QiB1pTIW, VOf(Bf13));
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf2));
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf16));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf8), VIf(Bf17), VOf(Bf8));
    __hv_add_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_NbhbPUXc, VOf(Bf9));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_tsOApumz, VOf(Bf7));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf8), VIf(O0), VOf(O0));

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
